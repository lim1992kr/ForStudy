"""지표 계산 및 자동 해석 문장 생성."""
from __future__ import annotations

from dataclasses import dataclass
from math import asin, cos, radians, sin, sqrt
from typing import Dict, List, Optional

from .log_parser import ParsedLog
from .utils import RunConfig


@dataclass
class FlightMetrics:
    total_flight_time_s: Optional[float]
    total_distance_km: Optional[float]
    battery_consumed_mah: Optional[float]
    max_altitude_m: Optional[float]
    max_roll_deg: Optional[float]
    min_pitch_deg: Optional[float]
    max_pitch_deg: Optional[float]
    min_voltage_v: Optional[float]
    max_current_a: Optional[float]
    anomalies: List[str]



def haversine_km(lat1: float, lon1: float, lat2: float, lon2: float) -> float:
    r = 6371.0
    d_lat = radians(lat2 - lat1)
    d_lon = radians(lon2 - lon1)
    a = sin(d_lat / 2) ** 2 + cos(radians(lat1)) * cos(radians(lat2)) * sin(d_lon / 2) ** 2
    c = 2 * asin(sqrt(a))
    return r * c



def compute_flight_metrics(parsed: ParsedLog, cfg: RunConfig) -> FlightMetrics:
    time = parsed.time_s
    alt = parsed.altitude_m
    roll = parsed.roll_deg
    pitch = parsed.pitch_deg
    volt = parsed.volt_v
    curr = parsed.curr_a
    currtot = parsed.currtot_mah

    total_time = (max(time) - min(time)) if len(time) >= 2 else None

    total_dist = None
    if len(parsed.gps_lat) >= 2 and len(parsed.gps_lat) == len(parsed.gps_lng):
        dist = 0.0
        for i in range(1, len(parsed.gps_lat)):
            dist += haversine_km(parsed.gps_lat[i - 1], parsed.gps_lng[i - 1], parsed.gps_lat[i], parsed.gps_lng[i])
        total_dist = dist

    battery = None
    if currtot:
        battery = max(currtot) - min(currtot)
    elif parsed.battery_instances:
        total = 0.0
        has_data = False
        for inst in parsed.battery_instances.values():
            series = inst.get("currtot", [])
            if series:
                total += max(series) - min(series)
                has_data = True
        battery = total if has_data else None

    anomalies: List[str] = []
    if roll and max(abs(x) for x in roll) > cfg.roll_warning_deg:
        anomalies.append(f"Roll 경고 기준({cfg.roll_warning_deg}°) 초과")
    if pitch and max(abs(x) for x in pitch) > cfg.pitch_warning_deg:
        anomalies.append(f"Pitch 경고 기준({cfg.pitch_warning_deg}°) 초과")
    if volt and min(volt) < cfg.voltage_warning_v:
        anomalies.append(f"최저 전압이 경고 기준({cfg.voltage_warning_v}V) 미만")
    if curr and max(curr) > cfg.current_warning_a:
        anomalies.append(f"최대 전류가 경고 기준({cfg.current_warning_a}A) 초과")

    for ev in parsed.events[:5]:
        anomalies.append(f"이벤트({ev['type']}) 확인 필요: t={ev['t']:.1f}s")

    return FlightMetrics(
        total_flight_time_s=total_time,
        total_distance_km=total_dist,
        battery_consumed_mah=battery,
        max_altitude_m=max(alt) if alt else None,
        max_roll_deg=max(abs(x) for x in roll) if roll else None,
        min_pitch_deg=min(pitch) if pitch else None,
        max_pitch_deg=max(pitch) if pitch else None,
        min_voltage_v=min(volt) if volt else None,
        max_current_a=max(curr) if curr else None,
        anomalies=anomalies,
    )



def generate_summaries(parsed: ParsedLog, metrics: FlightMetrics, cfg: RunConfig) -> Dict[str, str]:
    alt_text = (
        f"고도 평균 {sum(parsed.altitude_m)/len(parsed.altitude_m):.1f}m, 최대 {metrics.max_altitude_m:.1f}m 확인."
        if parsed.altitude_m and metrics.max_altitude_m is not None
        else "고도 데이터 없음."
    )

    roll_text = "Roll 데이터 없음."
    if parsed.roll_deg and metrics.max_roll_deg is not None:
        if metrics.max_roll_deg > cfg.roll_warning_deg:
            roll_text = f"최대 Roll {metrics.max_roll_deg:.1f}°로 기준({cfg.roll_warning_deg}°) 초과, 확인 필요."
        else:
            roll_text = f"최대 Roll {metrics.max_roll_deg:.1f}°로 기준 이내."

    pitch_text = "Pitch 데이터 없음."
    if parsed.pitch_deg and metrics.min_pitch_deg is not None and metrics.max_pitch_deg is not None:
        need_check = max(abs(metrics.min_pitch_deg), abs(metrics.max_pitch_deg)) > cfg.pitch_warning_deg
        suffix = "기준 초과 구간 확인 필요." if need_check else "기준 이내 범위."
        pitch_text = f"Pitch 범위 {metrics.min_pitch_deg:.1f}° ~ {metrics.max_pitch_deg:.1f}°. {suffix}"

    volt_text = "전압 데이터 없음."
    if metrics.min_voltage_v is not None:
        if metrics.min_voltage_v < cfg.voltage_warning_v:
            volt_text = f"최소 전압 {metrics.min_voltage_v:.2f}V로 경고 기준({cfg.voltage_warning_v}V) 미만, 확인 필요."
        else:
            volt_text = f"최소 전압 {metrics.min_voltage_v:.2f}V 확인(기준 이상)."

    curr_text = "전류 데이터 없음."
    if metrics.max_current_a is not None:
        if metrics.max_current_a > cfg.current_warning_a:
            curr_text = f"최대 전류 {metrics.max_current_a:.1f}A로 경고 기준({cfg.current_warning_a}A) 초과, 확인 필요."
        else:
            curr_text = f"최대 전류 {metrics.max_current_a:.1f}A 확인(기준 이내)."

    return {
        "altitude": alt_text,
        "roll": roll_text,
        "pitch": pitch_text,
        "voltage": volt_text,
        "current": curr_text,
    }
