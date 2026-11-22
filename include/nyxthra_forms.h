#ifndef GUARD_NYXTHRA_FORMS_H
#define GUARD_NYXTHRA_FORMS_H

// Nyxthra-Formen: seltener als Shiny, nur für Legendäre, Mysteriöse,
// Starter (inkl. Entwicklungen) und Pseudo-Legendäre.
// Eine Art bekommt erst dann eine Nyxthra-Form, wenn in
// src/nyxthra_forms.c eine freigegebene Palette eingetragen ist.

// Shiny: SHINY_ODDS 16 von 65536 = 1/4096. Nyxthra: 1/16384 (4x seltener).
#define NYXTHRA_ODDS 16384

// Wird statt TRUE/FALSE als "isShiny" an die Paletten-Funktionen übergeben.
#define NYXTHRA_PAL_VARIANT 2

struct Pokemon;
struct BoxPokemon;
struct ScriptContext;

extern bool8 gNyxthraForceNext;

bool32 Nyxthra_IsEligibleSpecies(u32 species);
const u16 *Nyxthra_GetPalette(u32 species);
bool32 Nyxthra_HasForm(u32 species);
bool32 Nyxthra_RollForSpecies(u32 species);
void Nyxthra_SetSeen(u32 species);
bool32 Nyxthra_IsSeen(u32 species);
bool32 Nyxthra_IsMonNyxthra(struct Pokemon *mon);
u32 GetMonPaletteVariant(struct Pokemon *mon);
u32 GetBoxMonPaletteVariant(struct BoxPokemon *boxMon);
void Nyxthra_MarkOpponentsSeen(void);
bool32 Nyxthra_AnyOpponentIsNyxthra(void);
void Nyxthra_DebugForceNext(struct ScriptContext *ctx);

#endif // GUARD_NYXTHRA_FORMS_H
