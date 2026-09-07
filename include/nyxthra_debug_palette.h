#ifndef GUARD_NYXTHRA_DEBUG_PALETTE_H
#define GUARD_NYXTHRA_DEBUG_PALETTE_H

// Nyxthra debug tool - see src/nyxthra_debug_palette.c for details.
// For the DP_Gentleman/DP_Barry/DP_PokeKid palette-corruption investigation.
void Nyxthra_DebugShowObjectIdentity(void);
void Nyxthra_DebugShowWatchdogGentleman(void);
void Nyxthra_RecordCreateSpriteWithTagCall(void);
void Nyxthra_DebugShowTableEntryCheck(void);

// Called from sprite.c's CreateSpriteAt whenever the paletteNum lookup for
// a non-TAG_NONE tag comes up empty right at sprite-creation time.
void Nyxthra_RecordCreateSpriteTagMiss(u16 tag);

#endif // GUARD_NYXTHRA_DEBUG_PALETTE_H
