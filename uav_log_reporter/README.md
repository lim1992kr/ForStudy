# UAV Log Reporter (CLI)

ArduPilot DataFlash `.BIN` 로그를 분석해 그래프 PNG와 Word(`.docx`) 비행 로그 분석 보고서를 자동 생성하는 Python CLI 도구입니다.

## 설치 방법

```bash
cd uav_log_reporter
python -m venv .venv
source .venv/bin/activate  # Windows: .venv\\Scripts\\activate
pip install -r requirements.txt
```

## 실행 방법

### 1) 실제 BIN 로그 사용
```bash
python main.py --bin "logs/Flight10.BIN" --flight 10 --day 5 --date "26.04.23" --purpose "검증비행"
```

### 2) Mock 데이터로 파이프라인 점검
```bash
python main.py --mock --flight 10 --day 5 --date "26.04.23" --purpose "검증비행"
```

## 필요한 Python 패키지

- pymavlink
- matplotlib
- python-docx
- PyYAML
- numpy

## 입력 파일 형식

- ArduPilot DataFlash `.BIN`
- 주요 메시지(가능한 경우): `ATT`, `CTUN/BARO`, `BAT`, `GPS`, `MODE`, `ERR/EV/MSG/EKF*`

## 출력 파일 위치

- 그래프: `outputs/plots/flight_<번호>/`
- 보고서: `outputs/reports/Flight_<번호>_Log_Analysis.docx`

## 현재 한계

- BIN 로그 포맷/기체별 메시지 필드 차이가 커서 일부 로그에서는 필드 매핑 추가가 필요합니다.
- 현재는 단일 실행 기준 분석이며, 다중 비행 자동 배치 처리 기능은 포함하지 않았습니다.
- 이벤트/모드 해석은 우선 수집 중심으로 구성되어 세부 의미 해석은 "확인 필요"로 표기할 수 있습니다.

## 향후 웹앱 확장 계획

- `src/` 모듈(파서/지표/그래프/보고서)을 그대로 재사용해 FastAPI 백엔드 API로 래핑
- React 프론트엔드에서 파일 업로드 및 보고서 다운로드
- 다중 로그 비교 뷰, 임계값 UI 설정, 비행별 히스토리 관리 기능 추가

## 프로젝트 구조

```text
uav_log_reporter/
├─ README.md
├─ requirements.txt
├─ main.py
├─ config.yaml
├─ src/
│  ├─ log_parser.py
│  ├─ metrics.py
│  ├─ plotter.py
│  ├─ report_writer.py
│  └─ utils.py
├─ outputs/
│  ├─ plots/
│  └─ reports/
└─ sample/
   └─ README.md
```
