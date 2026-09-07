#include "global.h"
#include "event_data.h"
#include "event_object_movement.h"
#include "palette.h"
#include "sprite.h"
#include "string_util.h"
#include "nyxthra_debug_palette.h"
#include "constants/characters.h"
#include "constants/event_objects.h"

// Nyxthra debug tool: show objectEventId, spriteId, graphicsId for the
// talked-to NPC, and the player's own spriteId/objectEventId for
// comparison - confirms we're actually looking at the right sprite.
void Nyxthra_DebugShowObjectIdentity(void)
{
    u8 objectEventId;
    struct ObjectEvent *objectEvent;
    u8 tmp[6];

    gStringVar1[0] = EOS;
    gStringVar2[0] = EOS;
    gStringVar3[0] = EOS;

    if (TryGetObjectEventIdByLocalIdAndMap(gSpecialVar_LastTalked,
                                            gSaveBlock1Ptr->location.mapNum,
                                            gSaveBlock1Ptr->location.mapGroup,
                                            &objectEventId))
    {
        StringCopy(gStringVar1, COMPOUND_STRING("nicht gefunden"));
        return;
    }

    objectEvent = &gObjectEvents[objectEventId];

    ConvertIntToDecimalStringN(gStringVar1, objectEventId, STR_CONV_MODE_LEFT_ALIGN, 2);
    StringAppend(gStringVar1, COMPOUND_STRING(" spr:"));
    ConvertIntToDecimalStringN(tmp, objectEvent->spriteId, STR_CONV_MODE_LEFT_ALIGN, 3);
    StringAppend(gStringVar1, tmp);

    ConvertIntToHexStringN(gStringVar2, objectEvent->graphicsId, STR_CONV_MODE_LEFT_ALIGN, 4);

    ConvertIntToDecimalStringN(gStringVar3, gPlayerAvatar.objectEventId, STR_CONV_MODE_LEFT_ALIGN, 2);
    StringAppend(gStringVar3, COMPOUND_STRING(" spr:"));
    ConvertIntToDecimalStringN(tmp, gPlayerAvatar.spriteId, STR_CONV_MODE_LEFT_ALIGN, 3);
    StringAppend(gStringVar3, tmp);
}

static struct {
    u16 tag;
    u16 count;
    u8 reserved;
    u16 slotTags[16];
} sNyxthraLastCreateSpriteMiss = {0, 0, 0, {0}};

void Nyxthra_RecordCreateSpriteTagMiss(u16 tag)
{
    u8 i;
    sNyxthraLastCreateSpriteMiss.tag = tag;
    sNyxthraLastCreateSpriteMiss.count++;
    sNyxthraLastCreateSpriteMiss.reserved = gReservedSpritePaletteCount;
    for (i = 0; i < 16; i++)
        sNyxthraLastCreateSpriteMiss.slotTags[i] = GetSpritePaletteTagByPaletteNum(i);
}

static u32 sNyxthraTotalCreateSpriteWithTagCalls = 0;

void Nyxthra_RecordCreateSpriteWithTagCall(void)
{
    sNyxthraTotalCreateSpriteWithTagCalls++;
}

// Nyxthra debug tool: for DP_Gentleman specifically, shows how many times
// the watchdog has force-reloaded him, the resulting slot, and - crucially
// - Faded/Unfaded/ROM color samples (index 9) *immediately after* the
// forced reload completed. His real index-9 color (from the compiled
// .gbapal) is 0x45EF. ROM wrong would mean the ROM constant itself is
// corrupted; ROM correct but Unfaded wrong would mean the copy itself
// failed; Unfaded correct but Faded wrong means something touches only
// the display copy afterward (fade/blend code, not the loader).
void Nyxthra_DebugShowWatchdogGentleman(void)
{
    u16 attempts, lastSlot, lastColor, romColor, unfadedColor;
    u8 tmp[6];
    Nyxthra_GetWatchdogPerTagInfo(0, &attempts, &lastSlot, &lastColor);
    romColor = Nyxthra_GetWatchdogGentlemanRomColor();
    unfadedColor = Nyxthra_GetWatchdogGentlemanUnfadedColor();
    ConvertIntToDecimalStringN(gStringVar1, attempts, STR_CONV_MODE_LEFT_ALIGN, 5);
    ConvertIntToDecimalStringN(gStringVar2, lastSlot, STR_CONV_MODE_LEFT_ALIGN, 2);
    ConvertIntToHexStringN(gStringVar3, lastColor, STR_CONV_MODE_LEFT_ALIGN, 4);
    StringAppend(gStringVar3, COMPOUND_STRING("/"));
    ConvertIntToHexStringN(tmp, unfadedColor, STR_CONV_MODE_LEFT_ALIGN, 4);
    StringAppend(gStringVar3, tmp);
    StringAppend(gStringVar3, COMPOUND_STRING("/"));
    ConvertIntToHexStringN(tmp, romColor, STR_CONV_MODE_LEFT_ALIGN, 4);
    StringAppend(gStringVar3, tmp);
}

// Nyxthra debug tool: looks up Gentleman's tag in sObjectEventSpritePalettes
// the same way the loader does, then reads color 9 THROUGH the table
// entry's own data pointer and checks whether that pointer actually equals
// &gObjectEventPal_DP_Gentleman. If the color read this way is already
// wrong (not 0x45EF) or the pointer doesn't match, the table entry itself
// resolves to the wrong array despite the source line naming the right
// one. If both are correct here, the corruption happens strictly inside
// the copy call itself for this specific load.
void Nyxthra_DebugShowTableEntryCheck(void)
{
    u16 index;
    u16 colorThroughTable;
    bool8 pointerMatches;
    u16 tagAtIndex;

    Nyxthra_DebugCheckTableEntry(OBJ_EVENT_PAL_TAG_DP_GENTLEMAN, &index, &colorThroughTable, &pointerMatches, &tagAtIndex);

    ConvertIntToDecimalStringN(gStringVar1, index, STR_CONV_MODE_LEFT_ALIGN, 4);
    // Raw tag actually stored at that index, read live from the running
    // table - should be 0x1284 if the match is genuine.
    ConvertIntToHexStringN(gStringVar2, tagAtIndex, STR_CONV_MODE_LEFT_ALIGN, 4);
    ConvertIntToHexStringN(gStringVar3, colorThroughTable, STR_CONV_MODE_LEFT_ALIGN, 4);
    StringAppend(gStringVar3, COMPOUND_STRING(" "));
    StringAppend(gStringVar3, pointerMatches ? COMPOUND_STRING("JA") : COMPOUND_STRING("NEIN"));
}
