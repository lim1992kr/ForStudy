"""UAV DataFlash BIN 로그 분석 CLI 엔트리포인트."""
from __future__ import annotations

import argparse
from pathlib import Path

from src.log_parser import create_mock_parsed_log, parse_bin_log
from src.metrics import compute_flight_metrics, generate_summaries
from src.plotter import generate_plots
from src.report_writer import write_report
from src.utils import ensure_dirs, format_float, load_config, sec_to_kor_time



def build_arg_parser() -> argparse.ArgumentParser:
    parser = argparse.ArgumentParser(description="ArduPilot BIN 로그 기반 UAV 비행 보고서 생성기")
    parser.add_argument("--bin", dest="bin_path", type=str, help="ArduPilot .BIN 로그 파일 경로")
    parser.add_argument("--flight", type=int, required=True, help="Flight 번호")
    parser.add_argument("--day", type=int, required=True, help="Day 번호")
    parser.add_argument("--date", type=str, required=True, help="비행일자 (예: 26.04.23)")
    parser.add_argument("--purpose", type=str, default=None, help='비행 목적 (기본: "검증비행")')
    parser.add_argument("--config", type=str, default="config.yaml", help="설정 파일 경로")
    parser.add_argument("--mock", action="store_true", help="mock 데이터로 파이프라인 테스트")
    return parser



def main() -> None:
    args = build_arg_parser().parse_args()

    root = Path(__file__).resolve().parent
    config = load_config(root / args.config)
    purpose = args.purpose or config.default_purpose

    plots_dir = root / "outputs" / "plots" / f"flight_{args.flight}"
    reports_dir = root / "outputs" / "reports"
    ensure_dirs(plots_dir, reports_dir)

    if args.mock:
        parsed = create_mock_parsed_log()
    else:
        if not args.bin_path:
            raise SystemExit("오류: --bin 인자가 필요합니다. (또는 --mock 사용)")
        parsed = parse_bin_log(Path(args.bin_path))

    metrics = compute_flight_metrics(parsed, config)
    summaries = generate_summaries(parsed, metrics, config)
    plot_paths = generate_plots(parsed, plots_dir, config)

    special = "없음"
    if metrics.anomalies:
        special = "; ".join(metrics.anomalies[:5])

    basic_info = {
        "total_time": sec_to_kor_time(metrics.total_flight_time_s),
        "total_distance": format_float(metrics.total_distance_km, " km", 3)
        if metrics.total_distance_km is not None
        else "계산 불가",
        "battery": format_float(metrics.battery_consumed_mah, " mAh", 0),
    }

    output_docx = reports_dir / f"Flight_{args.flight}_Log_Analysis.docx"
    write_report(
        output_docx=output_docx,
        day_no=args.day,
        date_str=args.date,
        flight_no=args.flight,
        purpose=purpose,
        basic_info=basic_info,
        plot_paths=plot_paths,
        summaries=summaries,
        special_notes=special,
    )

    print("보고서 생성 완료:", output_docx)


if __name__ == "__main__":
    main()
