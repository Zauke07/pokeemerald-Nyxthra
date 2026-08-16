#ifndef GUARD_RANDOMIZER_H
#define GUARD_RANDOMIZER_H

#include "global.h"
#include "constants/abilities.h"

enum RandomizerMode
{
    RANDOMIZER_MODE_WILD,
    RANDOMIZER_MODE_TRAINER,
    RANDOMIZER_MODE_STARTER,
    RANDOMIZER_MODE_EVOLUTION,
    RANDOMIZER_MODE_FIELD_ITEM,
    RANDOMIZER_MODE_GIFT,
    RANDOMIZER_MODE_STATIC,
    RANDOMIZER_MODE_TMHM,
};

enum
{
    RANDOMIZER_FLAG_WILD      = (1 << 0),
    RANDOMIZER_FLAG_TRAINER   = (1 << 1),
    RANDOMIZER_FLAG_STARTER   = (1 << 2),
    RANDOMIZER_FLAG_EVOLUTION = (1 << 3),
    RANDOMIZER_FLAG_FIELD_ITEM = (1 << 4),
    RANDOMIZER_FLAG_GIFT      = (1 << 5),
    RANDOMIZER_FLAG_STATIC    = (1 << 6),
    RANDOMIZER_FLAG_STATIC_KEEP_LEGENDS = (1 << 7),
    RANDOMIZER_FLAG_MOVE_PP   = (1 << 8),
    RANDOMIZER_FLAG_MOVE_POWER = (1 << 9),
    RANDOMIZER_FLAG_BASE_STATS = (1 << 10),
    RANDOMIZER_FLAG_LEARNSET = (1 << 11),
    RANDOMIZER_FLAG_ABILITIES = (1 << 12),
    RANDOMIZER_FLAG_TMHM = (1 << 13),
    RANDOMIZER_FLAG_UNIVERSAL_TMHM = (1 << 14),
};

#define RANDOMIZER_BASE_FLAGS_MASK  0x00FF
#define RANDOMIZER_EXTRA_FLAGS_MASK 0x7F00

u16 Randomizer_GetSpecies(u16 originalSpecies, enum RandomizerMode mode);
u16 Randomizer_GetItem(u16 originalItem, enum RandomizerMode mode);
u16 Randomizer_GetContextualItem(u16 originalItem, enum RandomizerMode mode, u32 context);
u16 Randomizer_GetMove(u16 originalMove, enum RandomizerMode mode);
bool32 Randomizer_IsUniversalTmHmCompatibilityEnabled(void);
u32 Randomizer_GetMovePower(u16 originalMove, u32 originalPower);
u32 Randomizer_GetMovePP(u16 originalMove, u32 originalPP);
u16 Randomizer_GetLevelUpMove(u16 species, u16 level, u16 slot, u16 originalMove);
enum Ability Randomizer_GetAbility(u16 species, u8 slot, enum Ability originalAbility);
u16 Randomizer_GetStaticSpecies(u16 originalSpecies);
u32 Randomizer_GetSpeciesBaseStatValue(u16 species, u8 statIndex, u32 originalValue);
bool32 Randomizer_IsAllowedRandomizedItem(u16 itemId);
u16 Randomizer_GetAllowedItem(u16 originalItem, enum RandomizerMode mode);
u16 Randomizer_GetAllowedContextualItem(u16 originalItem, enum RandomizerMode mode, u32 context);
u16 Randomizer_GetShopItem(u16 originalItem, u16 slot);

#endif // GUARD_RANDOMIZER_H
