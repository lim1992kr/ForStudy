"""공용 유틸리티 함수 모음."""
from __future__ import annotations

from dataclasses import dataclass
from pathlib import Path
from typing import Any, Dict, Optional

try:
    import yaml  # type: ignore
except ImportError:  # pragma: no cover - 환경 의존
    yaml = None


@dataclass
class RunConfig:
    """설정 값 컨테이너."""

    roll_warning_deg: float = 35
    pitch_warning_deg: float = 25
    voltage_warning_v: float = 34.0
    current_warning_a: float = 100
    default_purpose: str = "검증비행"
    plot_dpi: int = 140
    plot_style: str = "seaborn-v0_8-whitegrid"



def _simple_yaml_fallback(text: str) -> Dict[str, Any]:
    """PyYAML이 없을 때 최소한의 key/value YAML 파서.

    주의: 본 파서는 현재 프로젝트의 단순 config.yaml 구조만 지원한다.
    """
    result: Dict[str, Any] = {}
    current_section: Optional[str] = None
    for raw in text.splitlines():
        line = raw.strip()
        if not line or line.startswith("#"):
            continue

        if not raw.startswith(" ") and line.endswith(":"):
            current_section = line[:-1]
            result[current_section] = {}
            continue

        if ":" in line and current_section:
            k, v = line.split(":", 1)
            value = v.strip().strip('"').strip("'")
            if value.replace(".", "", 1).isdigit():
                value = float(value) if "." in value else int(value)
            result[current_section][k.strip()] = value
    return result



def load_config(config_path: Path) -> RunConfig:
    """YAML 설정 로드. 누락 시 기본값 유지."""
    if not config_path.exists():
        return RunConfig()

    with config_path.open("r", encoding="utf-8") as f:
        text = f.read()

    if yaml is not None:
        raw: Dict[str, Any] = yaml.safe_load(text) or {}
    else:
        raw = _simple_yaml_fallback(text)

    thresholds = raw.get("thresholds", {})
    report_cfg = raw.get("report", {})
    plot_cfg = raw.get("plot", {})

    return RunConfig(
        roll_warning_deg=thresholds.get("roll_warning_deg", 35),
        pitch_warning_deg=thresholds.get("pitch_warning_deg", 25),
        voltage_warning_v=thresholds.get("voltage_warning_v", 34.0),
        current_warning_a=thresholds.get("current_warning_a", 100),
        default_purpose=report_cfg.get("default_purpose", "검증비행"),
        plot_dpi=plot_cfg.get("dpi", 140),
        plot_style=plot_cfg.get("style", "seaborn-v0_8-whitegrid"),
    )



def ensure_dirs(*paths: Path) -> None:
    """출력 폴더 생성."""
    for p in paths:
        p.mkdir(parents=True, exist_ok=True)



def sec_to_kor_time(seconds: Optional[float]) -> str:
    """초 -> "N분 M초" 문자열."""
    if seconds is None:
        return "계산 불가"
    total = int(round(seconds))
    minute, sec = divmod(total, 60)
    hour, minute = divmod(minute, 60)
    if hour > 0:
        return f"{hour}시간 {minute}분 {sec}초"
    return f"{minute}분 {sec}초"



def format_float(value: Optional[float], unit: str = "", precision: int = 3) -> str:
    """부동소수 포맷."""
    if value is None:
        return "데이터 없음"
    return f"{value:.{precision}f}{unit}"
