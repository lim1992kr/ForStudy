"""Word(.docx) 보고서 작성 모듈."""
from __future__ import annotations

import xml.sax.saxutils as sx
import zipfile
from pathlib import Path
from typing import Dict



def _add_info_table_docx(doc, info: Dict[str, str]) -> None:
    table = doc.add_table(rows=0, cols=2)
    table.style = "Light Grid Accent 1"
    for k, v in info.items():
        row = table.add_row().cells
        row[0].text = k
        row[1].text = v



def _write_minimal_docx(output_docx: Path, title: str, lines: list[str]) -> None:
    """python-docx 미설치 시 최소 DOCX 생성."""
    content_types = """<?xml version='1.0' encoding='UTF-8' standalone='yes'?>
<Types xmlns='http://schemas.openxmlformats.org/package/2006/content-types'>
  <Default Extension='rels' ContentType='application/vnd.openxmlformats-package.relationships+xml'/>
  <Default Extension='xml' ContentType='application/xml'/>
  <Override PartName='/word/document.xml' ContentType='application/vnd.openxmlformats-officedocument.wordprocessingml.document.main+xml'/>
</Types>"""
    rels = """<?xml version='1.0' encoding='UTF-8' standalone='yes'?>
<Relationships xmlns='http://schemas.openxmlformats.org/package/2006/relationships'>
  <Relationship Id='rId1' Type='http://schemas.openxmlformats.org/officeDocument/2006/relationships/officeDocument' Target='word/document.xml'/>
</Relationships>"""

    paras = [title] + lines
    pxml = "".join(f"<w:p><w:r><w:t>{sx.escape(p)}</w:t></w:r></w:p>" for p in paras)
    document = f"""<?xml version='1.0' encoding='UTF-8' standalone='yes'?>
<w:document xmlns:wpc='http://schemas.microsoft.com/office/word/2010/wordprocessingCanvas'
 xmlns:mc='http://schemas.openxmlformats.org/markup-compatibility/2006'
 xmlns:o='urn:schemas-microsoft-com:office:office'
 xmlns:r='http://schemas.openxmlformats.org/officeDocument/2006/relationships'
 xmlns:m='http://schemas.openxmlformats.org/officeDocument/2006/math'
 xmlns:v='urn:schemas-microsoft-com:vml'
 xmlns:wp14='http://schemas.microsoft.com/office/word/2010/wordprocessingDrawing'
 xmlns:wp='http://schemas.openxmlformats.org/drawingml/2006/wordprocessingDrawing'
 xmlns:w10='urn:schemas-microsoft-com:office:word'
 xmlns:w='http://schemas.openxmlformats.org/wordprocessingml/2006/main'>
  <w:body>{pxml}<w:sectPr/></w:body>
</w:document>"""

    with zipfile.ZipFile(output_docx, "w", zipfile.ZIP_DEFLATED) as zf:
        zf.writestr("[Content_Types].xml", content_types)
        zf.writestr("_rels/.rels", rels)
        zf.writestr("word/document.xml", document)



def write_report(
    output_docx: Path,
    day_no: int,
    date_str: str,
    flight_no: int,
    purpose: str,
    basic_info: Dict[str, str],
    plot_paths: Dict[str, Path],
    summaries: Dict[str, str],
    special_notes: str,
) -> None:
    output_docx.parent.mkdir(parents=True, exist_ok=True)

    info = {
        "1. 비행회차": f"Flight #{flight_no}",
        "2. 비행 목적": purpose,
        "3. 총 비행시간": basic_info.get("total_time", "계산 불가"),
        "4. 총 비행거리": basic_info.get("total_distance", "계산 불가"),
        "5. 배터리 소모": basic_info.get("battery", "데이터 없음"),
        "6. 비행특이사항": special_notes,
    }

    try:
        from docx import Document  # type: ignore
        from docx.shared import Inches  # type: ignore

        doc = Document()
        doc.add_heading(f"Day #{day_no} _ {date_str}", level=1)
        p = doc.add_paragraph()
        run = p.add_run(f"FLIGHT #{flight_no}")
        run.bold = True

        doc.add_paragraph("[비행 기본정보]")
        _add_info_table_docx(doc, info)

        section_info = [
            ("1) 고도", "altitude"),
            ("2) Roll", "roll"),
            ("3) Pitch", "pitch"),
            ("4) 배터리(Voltage)", "voltage"),
            ("5) 배터리(Current)", "current"),
        ]

        for title, key in section_info:
            doc.add_paragraph()
            h = doc.add_paragraph(title)
            h.runs[0].bold = True

            img = plot_paths.get(key)
            if img and img.exists():
                doc.add_picture(str(img), width=Inches(6.6))
            else:
                doc.add_paragraph("[그래프 데이터 없음]")
            doc.add_paragraph(f"<{summaries.get(key, '데이터 없음')}>")

        doc.save(output_docx)
    except ImportError:
        lines = [f"FLIGHT #{flight_no}", "[비행 기본정보]"] + [f"{k}: {v}" for k, v in info.items()]
        lines += [f"{k}: {v}" for k, v in summaries.items()]
        _write_minimal_docx(output_docx, f"Day #{day_no} _ {date_str}", lines)
