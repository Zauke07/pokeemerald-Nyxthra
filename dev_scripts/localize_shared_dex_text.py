import sys
import subprocess
import shutil
from pathlib import Path

from deep_translator import GoogleTranslator


ROOT = Path(__file__).resolve().parents[1]
if str(ROOT) not in sys.path:
    sys.path.insert(0, str(ROOT))

from dev_scripts.localize_species_text import fit_description_lines, normalize_whitespace

TARGET = ROOT / "src" / "data" / "pokemon" / "species_info" / "shared_dex_text.h"
translator = GoogleTranslator(source="en", target="de")


def extract_text(lines):
    return normalize_whitespace(" ".join(extract_parts(lines)))


def extract_parts(lines):
    parts = []
    for line in lines:
        stripped = line.strip()
        if not stripped.startswith('"'):
            continue
        if stripped.endswith('");'):
            text = stripped[:-3]
        else:
            text = stripped.strip(',')
        text = text[1:-1]
        parts.append(text.replace("\\n", " "))
    return parts


def translate_text(text):
    translated = translator.translate(text)
    translated = normalize_whitespace(translated)
    translated = translated.replace("Pokemon", "Pokémon").replace("pokemon", "Pokémon")
    return translated


def main():
    source_text = None
    relative_target = TARGET.relative_to(ROOT).as_posix()
    git_executable = shutil.which("git")
    if git_executable is not None:
        git_result = subprocess.run(
            [git_executable, "show", f"HEAD:{relative_target}"],
            cwd=ROOT,
            capture_output=True,
            text=True,
            encoding="utf-8",
        )
        if git_result.returncode == 0:
            source_text = git_result.stdout

    if source_text is None:
        source_text = TARGET.read_text(encoding="utf-8")

    lines = source_text.splitlines(keepends=True)
    output = []
    index = 0
    changes = 0

    while index < len(lines):
        line = lines[index]
        output.append(line)
        if line.startswith("const u8 ") and line.rstrip().endswith("= _("):
            index += 1
            block_lines = []
            while index < len(lines):
                block_lines.append(lines[index])
                if lines[index].strip().endswith(");"):
                    break
                index += 1

            parts = extract_parts(block_lines)
            if len(parts) > 4:
                translated_lines = parts[:4]
            else:
                original_text = normalize_whitespace(" ".join(parts))
                translated_text = translate_text(original_text)
                translated_lines = fit_description_lines(translated_text)
            indent = "    "
            for body_line in translated_lines[:-1]:
                output.append(f'{indent}"{body_line}\\n"\n')
            output.append(f'{indent}"{translated_lines[-1]}"\n')
            output.append(");\n")
            changes += 1
        index += 1

    TARGET.write_text("".join(output), encoding="utf-8")
    print(f"total_changes={changes}")


if __name__ == "__main__":
    main()