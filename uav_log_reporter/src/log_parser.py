"""ArduPilot DataFlash BIN 파서.

요구사항 반영:
- pymavlink로 DataFlash BIN을 읽고 메시지별 DataFrame 생성
- TimeUS 기준 elapsed_sec 생성
- ATT/BAT/CTUN/BARO/GPS/MODE/ERR/MSG 추출
- 메시지 없을 때 빈 DataFrame 반환
- 사용 가능한 메시지 타입 목록 콘솔 출력
"""
from __future__ import annotations

from dataclasses import dataclass, field
from pathlib import Path
from typing import Any, Dict, List, Optional

import pandas as pd


@dataclass
class ParsedLog:
    """파싱 결과 컨테이너.

    - frames: 메시지별 원본 DataFrame
    - 나머지 리스트 필드: 기존 metrics/plotter와의 호환성을 위한 추출 결과
    """

    frames: Dict[str, pd.DataFrame] = field(default_factory=dict)

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



def _to_row(msg: Any) -> Dict[str, Any]:
    """mavlink message -> dict 변환 (안전)."""
    if hasattr(msg, "to_dict"):
        row = msg.to_dict()
    else:
        row = {k: getattr(msg, k) for k in dir(msg) if not k.startswith("_")}
    row["_type"] = msg.get_type()
    return row



def _ensure_elapsed(df: pd.DataFrame) -> pd.DataFrame:
    """TimeUS 기반 elapsed_sec 컬럼 추가."""
    if df.empty:
        df["elapsed_sec"] = pd.Series(dtype="float64")
        return df

    if "TimeUS" in df.columns:
        base = df["TimeUS"].dropna().iloc[0] if not df["TimeUS"].dropna().empty else None
        if base is not None:
            df["elapsed_sec"] = (pd.to_numeric(df["TimeUS"], errors="coerce") - float(base)) / 1_000_000.0
            return df

    # TimeUS가 없는 메시지는 elapsed_sec를 NaN으로 두고 후단에서 보정
    df["elapsed_sec"] = pd.Series([pd.NA] * len(df), dtype="float64")
    return df



def _extract_numeric(df: pd.DataFrame, col: str) -> List[float]:
    if df.empty or col not in df.columns:
        return []
    series = pd.to_numeric(df[col], errors="coerce").dropna()
    return series.tolist()



def _extract_elapsed(df: pd.DataFrame) -> List[float]:
    if df.empty or "elapsed_sec" not in df.columns:
        return []
    series = pd.to_numeric(df["elapsed_sec"], errors="coerce").dropna()
    return series.tolist()



def _choose_altitude(ctun_df: pd.DataFrame, baro_df: pd.DataFrame) -> List[float]:
    if not ctun_df.empty and "Alt" in ctun_df.columns:
        return _extract_numeric(ctun_df, "Alt")
    if not baro_df.empty and "Alt" in baro_df.columns:
        return _extract_numeric(baro_df, "Alt")
    return []



def parse_bin_log(bin_path: Path, print_available_messages: bool = True) -> ParsedLog:
    """BIN 파일 파싱 (실로그 전용)."""
    if not bin_path.exists():
        raise FileNotFoundError(f"BIN 로그 파일을 찾을 수 없습니다: {bin_path}")

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

    # 요구 메시지는 없더라도 빈 DataFrame 생성
    frames: Dict[str, pd.DataFrame] = {}
    for key in TARGET_MESSAGES:
        df = pd.DataFrame(rows_by_type.get(key, []))
        df = _ensure_elapsed(df)
        frames[key] = df

    parsed = ParsedLog(frames=frames)

    att_df = frames["ATT"]
    bat_df = frames["BAT"]
    ctun_df = frames["CTUN"]
    baro_df = frames["BARO"]
    gps_df = frames["GPS"]
    mode_df = frames["MODE"]
    err_df = frames["ERR"]
    msg_df = frames["MSG"]

    # ATT
    parsed.time_s = _extract_elapsed(att_df)
    parsed.roll_deg = _extract_numeric(att_df, "Roll")
    parsed.pitch_deg = _extract_numeric(att_df, "Pitch")

    # 고도(CTUN 우선, 없으면 BARO)
    parsed.altitude_m = _choose_altitude(ctun_df, baro_df)

    # BAT
    parsed.volt_v = _extract_numeric(bat_df, "Volt")
    parsed.curr_a = _extract_numeric(bat_df, "Curr")
    parsed.currtot_mah = _extract_numeric(bat_df, "CurrTot")

    if not bat_df.empty:
        inst_col = "Instance" if "Instance" in bat_df.columns else None
        if inst_col:
            for inst_val, sub in bat_df.groupby(inst_col):
                inst = int(inst_val) if pd.notna(inst_val) else 0
                parsed.battery_instances[inst] = {
                    "volt": _extract_numeric(sub, "Volt"),
                    "curr": _extract_numeric(sub, "Curr"),
                    "currtot": _extract_numeric(sub, "CurrTot"),
                }
        else:
            parsed.battery_instances[0] = {
                "volt": parsed.volt_v,
                "curr": parsed.curr_a,
                "currtot": parsed.currtot_mah,
            }

    # GPS
    if not gps_df.empty:
        parsed.gps_time_s = _extract_elapsed(gps_df)
        lat_list = _extract_numeric(gps_df, "Lat")
        lng_list = _extract_numeric(gps_df, "Lng")
        parsed.gps_lat = [v / 1e7 if abs(v) > 180 else v for v in lat_list]
        parsed.gps_lng = [v / 1e7 if abs(v) > 180 else v for v in lng_list]

    # MODE
    if not mode_df.empty:
        mode_val_col: Optional[str] = None
        for col in ["Mode", "ModeNum", "mode"]:
            if col in mode_df.columns:
                mode_val_col = col
                break

        for _, row in mode_df.iterrows():
            t = row.get("elapsed_sec", pd.NA)
            mode_v = row.get(mode_val_col, "UNKNOWN") if mode_val_col else "UNKNOWN"
            parsed.mode_changes.append({"t": float(t) if pd.notna(t) else 0.0, "mode": str(mode_v)})

    # ERR/MSG -> events
    for _, row in err_df.iterrows():
        t = row.get("elapsed_sec", pd.NA)
        parsed.events.append({"t": float(t) if pd.notna(t) else 0.0, "type": "ERR", "raw": str(dict(row))})

    for _, row in msg_df.iterrows():
        t = row.get("elapsed_sec", pd.NA)
        parsed.events.append({"t": float(t) if pd.notna(t) else 0.0, "type": "MSG", "raw": str(dict(row))})

    return parsed



def create_mock_parsed_log(duration_s: int = 900) -> ParsedLog:
    """개발/디버깅용 mock 데이터 생성."""
    import math

    parsed = ParsedLog(frames={k: pd.DataFrame() for k in TARGET_MESSAGES})
    for i in range(duration_s):
        t = float(i)
        parsed.time_s.append(t)
        parsed.altitude_m.append(98 + 4 * math.sin(i / 120))
        parsed.roll_deg.append(10 * math.sin(i / 30) + (32 if i % 280 == 0 else 0))
        parsed.pitch_deg.append(6 * math.sin(i / 35))
        parsed.volt_v.append(40.0 - i * 0.004)
        parsed.curr_a.append(22 + 10 * abs(math.sin(i / 18)))
        parsed.currtot_mah.append(i * 8.0)

    base_lat, base_lng = 37.0000, 127.0000
    for i in range(0, duration_s, 2):
        parsed.gps_lat.append(base_lat + i * 0.00001)
        parsed.gps_lng.append(base_lng + i * 0.00001)
        parsed.gps_time_s.append(float(i))

    parsed.mode_changes = [{"t": 0.0, "mode": "QSTABILIZE"}, {"t": 120.0, "mode": "FBWA"}, {"t": 650.0, "mode": "QHOVER"}]
    parsed.events = [{"t": 300.0, "type": "MSG", "raw": "Mock event"}]
    parsed.battery_instances = {0: {"volt": parsed.volt_v, "curr": parsed.curr_a, "currtot": parsed.currtot_mah}}
    return parsed
