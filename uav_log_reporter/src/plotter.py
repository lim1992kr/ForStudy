"""그래프 생성 모듈."""
from __future__ import annotations

from pathlib import Path
from typing import Dict, List

import matplotlib.pyplot as plt

from .log_parser import ParsedLog
from .utils import RunConfig



def _save_single_plot(
    x: List[float],
    y: List[float],
    title: str,
    ylabel: str,
    out_path: Path,
    cfg: RunConfig,
    mode_changes: List[dict] | None = None,
) -> None:
    plt.style.use(cfg.plot_style)
    fig, ax = plt.subplots(figsize=(10, 3.8))

    if x and y:
        n = min(len(x), len(y))
        ax.plot(x[:n], y[:n], linewidth=1.2)
        if mode_changes:
            for m in mode_changes:
                t = m.get("t")
                if t is not None:
                    ax.axvline(t, linestyle="--", linewidth=0.8, alpha=0.6)
    else:
        ax.text(0.5, 0.5, "데이터 없음", ha="center", va="center", fontsize=12)

    ax.set_title(title)
    ax.set_xlabel("비행 시작 후 경과시간 (s)")
    ax.set_ylabel(ylabel)
    ax.grid(True, alpha=0.3)
    fig.tight_layout()
    fig.savefig(out_path, dpi=cfg.plot_dpi)
    plt.close(fig)



def generate_plots(parsed: ParsedLog, out_dir: Path, cfg: RunConfig) -> Dict[str, Path]:
    """요구된 5개 PNG 그래프 생성."""
    out_dir.mkdir(parents=True, exist_ok=True)

    plot_paths = {
        "altitude": out_dir / "altitude.png",
        "roll": out_dir / "roll.png",
        "pitch": out_dir / "pitch.png",
        "voltage": out_dir / "voltage.png",
        "current": out_dir / "current.png",
    }

    _save_single_plot(parsed.time_s, parsed.altitude_m, "Altitude", "Altitude (m)", plot_paths["altitude"], cfg, parsed.mode_changes)
    _save_single_plot(parsed.time_s, parsed.roll_deg, "Roll", "Roll (deg)", plot_paths["roll"], cfg, parsed.mode_changes)
    _save_single_plot(parsed.time_s, parsed.pitch_deg, "Pitch", "Pitch (deg)", plot_paths["pitch"], cfg, parsed.mode_changes)
    _save_single_plot(parsed.time_s, parsed.volt_v, "Battery Voltage", "Voltage (V)", plot_paths["voltage"], cfg, parsed.mode_changes)
    _save_single_plot(parsed.time_s, parsed.curr_a, "Battery Current", "Current (A)", plot_paths["current"], cfg, parsed.mode_changes)

    return plot_paths
