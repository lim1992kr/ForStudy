"""ArduPilot DataFlash BIN 파서."""
from __future__ import annotations

from dataclasses import dataclass, field
from pathlib import Path
from typing import Any, Dict, List, Optional

try:
    import pandas as pd  # type: ignore
except ImportError:  # pragma: no cover
    pd = None


@dataclass
class ParsedLog:
    """파싱 결과 컨테이너."""

    frames: Dict[str, Any] = field(default_factory=dict)

    time_s: List[float] = field(default_factory=list)
    altitude_m: List[float] = field(default_factory=list)
    roll_deg: List[float] = field(default_factory=list)
    pitch_deg: List[float] = field(default_factory=list)
    volt_v: List[float] = field(default_factory=list)
    curr_a: List[float] = field(default_factory=list)
    currtot_mah: List[float] = field(default_factory=list)
    gps_lat: List[float] = field(default_factory=list)
    gps_lng: List[float] = field(default_factory=list)
    gps_time_s: List[float] = field(default_factory=list)
    events: List[Dict[str, Any]] = field(default_factory=list)
    mode_changes: List[Dict[str, Any]] = field(default_factory=list)
    battery_instances: Dict[int, Dict[str, List[float]]] = field(default_factory=dict)


TARGET_MESSAGES = ["ATT", "BAT", "CTUN", "BARO", "GPS", "MODE", "ERR", "MSG"]


class EmptyFrame:
    """pandas 미설치 환경에서 빈 DataFrame 대체체."""

    empty = True
    columns: List[str] = []



def _to_row(msg: Any) -> Dict[str, Any]:
    if hasattr(msg, "to_dict"):
        row = msg.to_dict()
    else:
        row = {k: getattr(msg, k) for k in dir(msg) if not k.startswith("_")}
    row["_type"] = msg.get_type()
    return row



def _extract_numeric(df: Any, col: str) -> List[float]:
    if pd is None:
        return []
    if df.empty or col not in df.columns:
        return []
    return pd.to_numeric(df[col], errors="coerce").dropna().tolist()



def _extract_elapsed(df: Any) -> List[float]:
    return _extract_numeric(df, "elapsed_sec")



def _choose_altitude(ctun_df: Any, baro_df: Any) -> List[float]:
    if pd is None:
        return []
    if not ctun_df.empty and "Alt" in ctun_df.columns:
        return _extract_numeric(ctun_df, "Alt")
    if not baro_df.empty and "Alt" in baro_df.columns:
        return _extract_numeric(baro_df, "Alt")
    return []



def parse_bin_log(bin_path: Path, print_available_messages: bool = True) -> ParsedLog:
    """BIN 파일 파싱.

    참고: 실로그 파싱에는 pandas + pymavlink가 필요하다.
    """
    if not bin_path.exists():
        raise FileNotFoundError(f"BIN 로그 파일을 찾을 수 없습니다: {bin_path}")
    if pd is None:
        raise ImportError("pandas가 설치되어 있지 않아 BIN 파싱을 수행할 수 없습니다.")

    try:
        from pymavlink import mavutil
    except ImportError as e:
        raise ImportError("pymavlink가 설치되어 있지 않습니다. requirements.txt를 설치해주세요.") from e

    rows_by_type: Dict[str, List[Dict[str, Any]]] = {}
    available_types: set[str] = set()

    mlog = mavutil.mavlink_connection(str(bin_path), dialect="ardupilotmega")

    while True:
        msg = mlog.recv_match(blocking=False)
        if msg is None:
            break
        mtype = msg.get_type()
        available_types.add(mtype)
        if mtype in TARGET_MESSAGES:
            rows_by_type.setdefault(mtype, []).append(_to_row(msg))

    if print_available_messages:
        listed = ", ".join(sorted(available_types)) if available_types else "(없음)"
        print(f"[INFO] 로그에서 확인된 메시지 타입: {listed}")

    frames: Dict[str, Any] = {}
    for key in TARGET_MESSAGES:
        df = pd.DataFrame(rows_by_type.get(key, []))
        if df.empty:
            df["elapsed_sec"] = pd.Series(dtype="float64")
        elif "TimeUS" in df.columns and not df["TimeUS"].dropna().empty:
            base = float(df["TimeUS"].dropna().iloc[0])
            df["elapsed_sec"] = (pd.to_numeric(df["TimeUS"], errors="coerce") - base) / 1_000_000.0
        else:
            df["elapsed_sec"] = pd.Series([pd.NA] * len(df), dtype="float64")
        frames[key] = df

    parsed = ParsedLog(frames=frames)
    att_df, bat_df, ctun_df, baro_df = frames["ATT"], frames["BAT"], frames["CTUN"], frames["BARO"]
    gps_df, mode_df, err_df, msg_df = frames["GPS"], frames["MODE"], frames["ERR"], frames["MSG"]

    parsed.time_s = _extract_elapsed(att_df)
    parsed.roll_deg = _extract_numeric(att_df, "Roll")
    parsed.pitch_deg = _extract_numeric(att_df, "Pitch")
    parsed.altitude_m = _choose_altitude(ctun_df, baro_df)

    parsed.volt_v = _extract_numeric(bat_df, "Volt")
    parsed.curr_a = _extract_numeric(bat_df, "Curr")
    parsed.currtot_mah = _extract_numeric(bat_df, "CurrTot")

    if not bat_df.empty:
        if "Instance" in bat_df.columns:
            for inst_val, sub in bat_df.groupby("Instance"):
                inst = int(inst_val) if pd.notna(inst_val) else 0
                parsed.battery_instances[inst] = {
                    "volt": _extract_numeric(sub, "Volt"),
                    "curr": _extract_numeric(sub, "Curr"),
                    "currtot": _extract_numeric(sub, "CurrTot"),
                }
        else:
            parsed.battery_instances[0] = {"volt": parsed.volt_v, "curr": parsed.curr_a, "currtot": parsed.currtot_mah}

    if not gps_df.empty:
        parsed.gps_time_s = _extract_elapsed(gps_df)
        lat_list = _extract_numeric(gps_df, "Lat")
        lng_list = _extract_numeric(gps_df, "Lng")
        parsed.gps_lat = [v / 1e7 if abs(v) > 180 else v for v in lat_list]
        parsed.gps_lng = [v / 1e7 if abs(v) > 180 else v for v in lng_list]

    if not mode_df.empty:
        mode_col = next((c for c in ["Mode", "ModeNum", "mode"] if c in mode_df.columns), None)
        for _, row in mode_df.iterrows():
            t = row.get("elapsed_sec", pd.NA)
            mode_v = row.get(mode_col, "UNKNOWN") if mode_col else "UNKNOWN"
            parsed.mode_changes.append({"t": float(t) if pd.notna(t) else 0.0, "mode": str(mode_v)})

    for _, row in err_df.iterrows():
        t = row.get("elapsed_sec", pd.NA)
        parsed.events.append({"t": float(t) if pd.notna(t) else 0.0, "type": "ERR", "raw": str(dict(row))})
    for _, row in msg_df.iterrows():
        t = row.get("elapsed_sec", pd.NA)
        parsed.events.append({"t": float(t) if pd.notna(t) else 0.0, "type": "MSG", "raw": str(dict(row))})

    return parsed



def create_mock_parsed_log(duration_s: int = 900) -> ParsedLog:
    """개발/디버깅용 mock 데이터 생성.

    pandas 미설치 환경도 지원한다.
    """
    import math

    frames = {k: (pd.DataFrame() if pd is not None else EmptyFrame()) for k in TARGET_MESSAGES}
    parsed = ParsedLog(frames=frames)

    for i in range(duration_s):
        t = float(i)
        parsed.time_s.append(t)
        parsed.altitude_m.append(98 + 4 * math.sin(i / 120))
        parsed.roll_deg.append(10 * math.sin(i / 30) + (32 if i % 280 == 0 else 0))
        parsed.pitch_deg.append(6 * math.sin(i / 35))
        parsed.volt_v.append(40.0 - i * 0.004)
        parsed.curr_a.append(22 + 10 * abs(math.sin(i / 18)))
        parsed.currtot_mah.append(i * 8.0)

    base_lat, base_lng = 37.0, 127.0
    for i in range(0, duration_s, 2):
        parsed.gps_lat.append(base_lat + i * 0.00001)
        parsed.gps_lng.append(base_lng + i * 0.00001)
        parsed.gps_time_s.append(float(i))

    parsed.mode_changes = [{"t": 0.0, "mode": "QSTABILIZE"}, {"t": 120.0, "mode": "FBWA"}, {"t": 650.0, "mode": "QHOVER"}]
    parsed.events = [{"t": 300.0, "type": "MSG", "raw": "Mock event"}]
    parsed.battery_instances = {0: {"volt": parsed.volt_v, "curr": parsed.curr_a, "currtot": parsed.currtot_mah}}
    return parsed
