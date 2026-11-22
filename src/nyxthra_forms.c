#include "global.h"
#include "battle.h"
#include "event_data.h"
#include "pokemon.h"
#include "random.h"
#include "script.h"
#include "nyxthra_flashback.h"
#include "nyxthra_forms.h"
#include "constants/flags.h"
#include "constants/species.h"

// Debug: die nächste passende Begegnung wird garantiert eine Nyxthra-Form.
// Liegt nur im RAM, wird also nicht gespeichert.
EWRAM_DATA bool8 gNyxthraForceNext = FALSE;

// ---------------------------------------------------------------------------
// Paletten. Nur vom Ersteller freigegebene Entwürfe hier eintragen!
// ---------------------------------------------------------------------------
static const u16 sNyxthraPalette_Kyogre[] = INCGFX_U16("graphics/pokemon/kyogre/nyxthra.pal", ".gbapal"); // „Abgrund“

struct NyxthraForm
{
    u16 species;
    u16 seenFlag;      // eigener Flag pro Eintrag, damit die Reihenfolge egal ist
    const u16 *palette;
};

// Neue Form hinzufügen: Palette oben einbinden und hier eine Zeile mit
// einem freien FLAG_NYXTHRA_SEEN_xx ergänzen. Mehr ist nicht nötig.
// Groudon und Rayquaza folgen nach der Discord-Abstimmung (28.11.).
static const struct NyxthraForm sNyxthraForms[] =
{
    { SPECIES_KYOGRE, FLAG_NYXTHRA_SEEN_00, sNyxthraPalette_Kyogre },
};

static const struct NyxthraForm *FindForm(u32 species)
{
    u32 i;
    for (i = 0; i < ARRAY_COUNT(sNyxthraForms); i++)
    {
        if (sNyxthraForms[i].species == species)
            return &sNyxthraForms[i];
    }
    return NULL;
}

// Nationaldex-Bereiche: Starter (mit Entwicklungen) und Pseudo-Legendäre.
static const u16 sEligibleDexRanges[][2] =
{
    // Starter Gen 1–9
    {   1,   9 }, { 152, 160 }, { 252, 260 }, { 387, 395 }, { 495, 503 },
    { 650, 658 }, { 722, 730 }, { 810, 818 }, { 906, 914 },
    // Pseudo-Legendäre
    { 147, 149 }, { 246, 248 }, { 371, 373 }, { 374, 376 }, { 443, 445 },
    { 633, 635 }, { 704, 706 }, { 782, 784 }, { 885, 887 }, { 996, 998 },
};

bool32 Nyxthra_IsEligibleSpecies(u32 species)
{
    u32 i, dexNum;

    if (species == SPECIES_NONE || species >= NUM_SPECIES)
        return FALSE;
    if (gSpeciesInfo[species].isRestrictedLegendary
     || gSpeciesInfo[species].isSubLegendary
     || gSpeciesInfo[species].isMythical)
        return TRUE;

    dexNum = gSpeciesInfo[species].natDexNum;
    for (i = 0; i < ARRAY_COUNT(sEligibleDexRanges); i++)
    {
        if (dexNum >= sEligibleDexRanges[i][0] && dexNum <= sEligibleDexRanges[i][1])
            return TRUE;
    }
    return FALSE;
}

const u16 *Nyxthra_GetPalette(u32 species)
{
    const struct NyxthraForm *form = FindForm(species);
    if (form == NULL || !Nyxthra_IsEligibleSpecies(species))
        return NULL;
    return form->palette;
}

bool32 Nyxthra_HasForm(u32 species)
{
    return Nyxthra_GetPalette(species) != NULL;
}

bool32 Nyxthra_RollForSpecies(u32 species)
{
    if (!Nyxthra_HasForm(species))
        return FALSE;
    // Die Traum-Clips sollen immer die normalen Farben zeigen.
    if (NyxthraFlashback_IsActive())
        return FALSE;
    if (gNyxthraForceNext)
    {
        gNyxthraForceNext = FALSE;
        return TRUE;
    }
    return (Random32() % NYXTHRA_ODDS) == 0;
}

void Nyxthra_SetSeen(u32 species)
{
    const struct NyxthraForm *form = FindForm(species);
    if (form != NULL)
        FlagSet(form->seenFlag);
}

bool32 Nyxthra_IsSeen(u32 species)
{
    const struct NyxthraForm *form = FindForm(species);
    if (form == NULL || !Nyxthra_HasForm(species))
        return FALSE;
    return FlagGet(form->seenFlag);
}

bool32 Nyxthra_IsMonNyxthra(struct Pokemon *mon)
{
    return GetMonData(mon, MON_DATA_IS_NYXTHRA)
        && Nyxthra_HasForm(GetMonData(mon, MON_DATA_SPECIES));
}

u32 GetBoxMonPaletteVariant(struct BoxPokemon *boxMon)
{
    if (GetBoxMonData(boxMon, MON_DATA_IS_NYXTHRA)
     && Nyxthra_HasForm(GetBoxMonData(boxMon, MON_DATA_SPECIES)))
        return NYXTHRA_PAL_VARIANT;
    return GetBoxMonData(boxMon, MON_DATA_IS_SHINY) ? TRUE : FALSE;
}

u32 GetMonPaletteVariant(struct Pokemon *mon)
{
    return GetBoxMonPaletteVariant(&mon->box);
}

bool32 Nyxthra_AnyOpponentIsNyxthra(void)
{
    u32 battler;
    for (battler = 0; battler < gBattlersCount; battler++)
    {
        if (IsOnPlayerSide(battler))
            continue;
        if (Nyxthra_IsMonNyxthra(GetBattlerMon(battler)))
            return TRUE;
    }
    return FALSE;
}

void Nyxthra_MarkOpponentsSeen(void)
{
    u32 battler;
    for (battler = 0; battler < gBattlersCount; battler++)
    {
        struct Pokemon *mon;
        if (IsOnPlayerSide(battler))
            continue;
        mon = GetBattlerMon(battler);
        if (Nyxthra_IsMonNyxthra(mon))
            Nyxthra_SetSeen(GetMonData(mon, MON_DATA_SPECIES));
    }
}

// Debug-Menü (callnative)
void Nyxthra_DebugForceNext(struct ScriptContext *ctx)
{
    gNyxthraForceNext = TRUE;
}
