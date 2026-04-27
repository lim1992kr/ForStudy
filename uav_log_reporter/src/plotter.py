"""그래프 생성 모듈."""
from __future__ import annotations

import struct
import zlib
from pathlib import Path
from typing import Dict, List

from .log_parser import ParsedLog
from .utils import RunConfig



def _write_placeholder_png(path: Path, width: int = 640, height: int = 240) -> None:
    """matplotlib 미설치 시 사용할 단색 PNG 생성기."""

    def chunk(tag: bytes, data: bytes) -> bytes:
        return struct.pack(">I", len(data)) + tag + data + struct.pack(">I", zlib.crc32(tag + data) & 0xFFFFFFFF)

    raw = b"".join(b"\x00" + b"\xEE\xEE\xEE" * width for _ in range(height))
    png = b"\x89PNG\r\n\x1a\n"
    png += chunk(b"IHDR", struct.pack(">IIBBBBB", width, height, 8, 2, 0, 0, 0))
    png += chunk(b"IDAT", zlib.compress(raw, 9))
    png += chunk(b"IEND", b"")
    path.write_bytes(png)



def _save_single_plot(
    x: List[float],
    y: List[float],
    title: str,
    ylabel: str,
    out_path: Path,
    cfg: RunConfig,
    mode_changes: List[dict] | None = None,
) -> None:
    try:
        import matplotlib.pyplot as plt  # type: ignore
    except ImportError:
        _write_placeholder_png(out_path)
        return

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
