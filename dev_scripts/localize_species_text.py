import json
import re
import sys
import textwrap
import time
from threading import Lock
from pathlib import Path
from deep_translator import GoogleTranslator
from urllib.error import HTTPError, URLError
from urllib.request import Request, urlopen


ROOT = Path(__file__).resolve().parents[1]
SPECIES_DIR = ROOT / "src" / "data" / "pokemon" / "species_info"
CACHE_PATH = ROOT / "dev_scripts" / "species_text_cache.json"
POKEAPI_URL = "https://pokeapi.co/api/v2/pokemon-species/{dex}/"
USER_AGENT = "Mozilla/5.0 (Windows NT 10.0; Win64; x64) CopilotSpeciesText/1.0"
translator = GoogleTranslator(source="en", target="de")
translation_lock = Lock()

SPECIES_FILES = [
    *(SPECIES_DIR / f"gen_{index}.h" for index in range(1, 10)),
    *(SPECIES_DIR / f"gen_{index}_families.h" for index in range(1, 10)),
]
DEX_PATTERN = re.compile(r"\.natDexNum = (NATIONAL_DEX_[A-Z0-9_]+),")
CATEGORY_PATTERN = re.compile(r'^(?P<indent>\s*)\.categoryName = _\("(?P<category>.*?)"\),\s*$')
DESCRIPTION_START_PATTERN = re.compile(r'^(?P<indent>\s*)\.description = (?P<macro>POKEDEX_DESC_STRING|COMPOUND_STRING)\(\s*$')
SPECIES_START_PATTERN = re.compile(r'^\s*\[SPECIES_[A-Z0-9_]+\]\s*=')


def load_cache():
    if CACHE_PATH.exists():
        return json.loads(CACHE_PATH.read_text(encoding="utf-8"))
    return {}


def save_cache(cache):
    CACHE_PATH.write_text(json.dumps(cache, ensure_ascii=False, indent=2, sort_keys=True), encoding="utf-8")


def fetch_species_entry(dex_num, cache, fallback_source=None):
    key = str(dex_num)
    if key in cache:
        return cache[key]

    request = Request(POKEAPI_URL.format(dex=dex_num), headers={"User-Agent": USER_AGENT})
    for attempt in range(3):
        try:
            with urlopen(request, timeout=30) as response:
                payload = json.load(response)
            break
        except (HTTPError, URLError, TimeoutError) as exc:
            if attempt == 2:
                raise RuntimeError(f"PokeAPI fetch failed for dex {dex_num}: {exc}") from exc
            time.sleep(1.5 * (attempt + 1))

    german_genera = [entry["genus"] for entry in payload["genera"] if entry["language"]["name"] == "de"]
    german_flavor = []
    for entry in payload["flavor_text_entries"]:
        if entry["language"]["name"] != "de":
            continue
        text = normalize_whitespace(entry["flavor_text"])
        if text not in german_flavor:
            german_flavor.append(text)

    category = strip_pokemon_suffix(german_genera[0]) if german_genera else None
    description = choose_description(german_flavor) if german_flavor else None

    if fallback_source is None:
        fallback_source = {}

    if not category:
        category = translate_text(fallback_source.get("category", "")) or fallback_source.get("category", "")
    if not description:
        description = translate_text(fallback_source.get("description", "")) or fallback_source.get("description", "")

    if not category or not description:
        raise RuntimeError(f"Missing localized text for dex {dex_num}")

    result = {
        "category": category,
        "description": description,
    }
    cache[key] = result
    return result


def strip_pokemon_suffix(category):
    if category.endswith("-Pokémon"):
        return category[: -len("-Pokémon")]
    if category.endswith(" Pokémon"):
        return category[: -len(" Pokémon")]
    return category


def normalize_whitespace(text):
    return " ".join(text.replace("\f", " ").replace("\n", " ").split())


def translate_text(text):
    text = normalize_whitespace(text)
    if not text:
        return ""

    for attempt in range(3):
        try:
            with translation_lock:
                translated = translator.translate(text)
            translated = normalize_whitespace(translated)
            translated = translated.replace("Pokemon", "Pokémon").replace("pokemon", "Pokémon")
            return translated
        except Exception as exc:
            if attempt == 2:
                raise RuntimeError(f"Translation failed: {exc}") from exc
            time.sleep(1.5 * (attempt + 1))


def choose_description(entries):
    scored = []
    for entry in entries:
        wrapped = wrap_description(entry)
        if wrapped is None:
            continue
        max_len = max(len(line) for line in wrapped)
        score = (len(wrapped), max_len, len(entry))
        scored.append((score, entry))
    if scored:
        scored.sort(key=lambda item: item[0])
        return scored[0][1]
    return min(entries, key=len)


def wrap_description(text):
    wrapper = textwrap.TextWrapper(width=42, break_long_words=False, break_on_hyphens=False)
    return fit_description_lines(text, wrapper)


def fit_description_lines(text, wrapper=None):
    if wrapper is None:
        wrapper = textwrap.TextWrapper(width=42, break_long_words=False, break_on_hyphens=False)

    candidates = [
        text,
        text.replace("In den seltenen Fällen, in denen", "Wenn")
            .replace("In seltenen Fällen", "Selten")
            .replace("Dieses Pokémon", "Es")
            .replace("Dieses POKéMON", "Es")
            .replace("Pokémon", "Pokémon")
            .replace("wird ihre wahre Kraft freigesetzt", "entfaltet sich ihre wahre Kraft"),
    ]

    for candidate in candidates:
        lines = wrapper.wrap(candidate)
        if len(lines) <= 4:
            return lines

    words = candidates[-1].split()
    while words:
        candidate = " ".join(words) + "…"
        lines = wrapper.wrap(candidate)
        if len(lines) <= 4:
            return lines
        words.pop()

    return ["…"]


def format_description_block(text, indent, macro_name):
    wrapper = textwrap.TextWrapper(width=42, break_long_words=False, break_on_hyphens=False)
    lines = fit_description_lines(text, wrapper)

    body = "\n".join(f'{indent}    "{escape_c_string(line)}\\n"' for line in lines[:-1])
    tail = f'{indent}    "{escape_c_string(lines[-1])}"'
    if body:
        body = body + "\n" + tail
    else:
        body = tail
    return f"{indent}.description = {macro_name}(\n{body}),"


def escape_c_string(text):
    return text.replace("\\", "\\\\").replace('"', '\\"')


def extract_description_text(desc_body):
    parts = re.findall(r'"([^"\\]*(?:\\.[^"\\]*)*)"', desc_body)
    return normalize_whitespace(" ".join(part.replace("\\n", " ") for part in parts))


def parse_entries(lines):
    entries = []
    current_dex = None

    for index, line in enumerate(lines):
        dex_match = DEX_PATTERN.search(line)
        if dex_match:
            current_dex = dex_match.group(1)
            continue

        if current_dex is None:
            continue

        category_match = CATEGORY_PATTERN.match(line)
        if not category_match:
            continue

        desc_index = index + 1
        while desc_index < len(lines) and not DESCRIPTION_START_PATTERN.match(lines[desc_index]):
            if SPECIES_START_PATTERN.match(lines[desc_index]):
                break
            desc_index += 1
        if desc_index >= len(lines):
            continue

        description_start = DESCRIPTION_START_PATTERN.match(lines[desc_index])
        if description_start is None:
            continue

        desc_end = desc_index + 1
        while desc_end < len(lines):
            if lines[desc_end].strip().endswith('),'):
                break
            desc_end += 1
        if desc_end >= len(lines):
            continue

        entries.append(
            {
                "dex_token": current_dex,
                "category_index": index,
                "category_indent": category_match.group("indent"),
                "category": category_match.group("category"),
                "desc_start": desc_index,
                "desc_end": desc_end,
                "desc_indent": description_start.group("indent"),
                "macro": description_start.group("macro"),
                "desc_body": "".join(lines[desc_index + 1 : desc_end + 1]),
            }
        )
        current_dex = None

    return entries


def process_file(path, cache):
    lines = path.read_text(encoding="utf-8").splitlines(keepends=True)
    entries = parse_entries(lines)
    changed = 0

    for entry in reversed(entries):
        dex_num = dex_name_to_number(entry["dex_token"])
        fallback_source = {
            "category": entry["category"],
            "description": extract_description_text(entry["desc_body"]),
        }
        localized = fetch_species_entry(dex_num, cache, fallback_source)

        new_category_line = f'{entry["category_indent"]}.categoryName = _("{escape_c_string(localized["category"])}"),\n'
        new_description_block = format_description_block(localized["description"], entry["desc_indent"], entry["macro"]).splitlines(keepends=True)
        new_description_lines = [line if line.endswith("\n") else f"{line}\n" for line in new_description_block]

        old_category_line = lines[entry["category_index"]]
        old_description_text = extract_description_text(entry["desc_body"])
        if old_category_line == new_category_line and normalize_whitespace(old_description_text) == normalize_whitespace(localized["description"]):
            continue

        lines[entry["category_index"]] = new_category_line
        lines[entry["desc_start"] : entry["desc_end"] + 1] = new_description_lines
        changed += 1

    if changed:
        path.write_text("".join(lines), encoding="utf-8")
    return changed


def collect_dex_numbers(paths):
    dex_numbers = set()
    for path in paths:
        lines = path.read_text(encoding="utf-8").splitlines(keepends=True)
        for entry in parse_entries(lines):
            dex_numbers.add(dex_name_to_number(entry["dex_token"]))
    dex_numbers.discard(0)
    return sorted(dex_numbers)


def collect_fallback_sources(paths):
    sources = {}
    for path in paths:
        lines = path.read_text(encoding="utf-8").splitlines(keepends=True)
        for entry in parse_entries(lines):
            dex_num = dex_name_to_number(entry["dex_token"])
            if dex_num == 0 or dex_num in sources:
                continue
            sources[dex_num] = {
                "category": entry["category"],
                "description": extract_description_text(entry["desc_body"]),
            }
    return sources


def warm_cache(dex_numbers, cache, fallback_sources):
    missing = [dex_num for dex_num in dex_numbers if str(dex_num) not in cache]
    if not missing:
        return

    print(f"fetching_missing={len(missing)}")
    for index, dex_num in enumerate(missing, start=1):
        result = fetch_species_entry(dex_num, cache, fallback_sources.get(dex_num, {}))
        cache[str(dex_num)] = result
        if index % 10 == 0 or index == len(missing):
            print(f"fetched={index}/{len(missing)}")
            save_cache(cache)


def dex_name_to_number(dex_token):
    name = dex_token.removeprefix("NATIONAL_DEX_")
    if name == "NONE":
        return 0
    if not hasattr(dex_name_to_number, "mapping"):
        dex_name_to_number.mapping = build_dex_mapping()
    return dex_name_to_number.mapping[dex_token]


def build_dex_mapping():
    text = (ROOT / "include" / "constants" / "pokedex.h").read_text(encoding="utf-8")
    mapping = {}
    value = 0
    in_enum = False
    for raw_line in text.splitlines():
        line = raw_line.split("//", 1)[0].strip()
        if line == "enum NationalDexOrder":
            in_enum = True
            continue
        if not in_enum:
            continue
        if line == "{":
            continue
        if line == "};":
            break
        if not line:
            continue
        token = line.rstrip(",")
        if "=" in token:
            name, rhs = (part.strip() for part in token.split("=", 1))
            value = int(rhs, 0)
            token = name
        mapping[token] = value
        value += 1
    return mapping


def main():
    cache = load_cache()
    if len(sys.argv) > 1:
        paths = [ROOT / argument for argument in sys.argv[1:]]
    else:
        paths = SPECIES_FILES

    dex_numbers = collect_dex_numbers(paths)
    fallback_sources = collect_fallback_sources(paths)
    warm_cache(dex_numbers, cache, fallback_sources)

    total_changes = 0
    for path in paths:
        total_changes += process_file(path, cache)
    save_cache(cache)
    print(f"total_changes={total_changes}")


if __name__ == "__main__":
    try:
        main()
    except Exception as exc:
        print(str(exc), file=sys.stderr)
        raise