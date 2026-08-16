#include "global.h"
#include "constants/abilities.h"
#include "constants/items.h"
#include "constants/moves.h"
#include "constants/pokemon.h"
#include "item.h"
#include "move.h"
#include "pokemon.h"
#include "random.h"
#include "randomizer.h"

#define RANDOMIZER_ALL_FLAGS (RANDOMIZER_FLAG_WILD \
                           | RANDOMIZER_FLAG_TRAINER \
                           | RANDOMIZER_FLAG_STARTER \
                           | RANDOMIZER_FLAG_EVOLUTION \
                           | RANDOMIZER_FLAG_FIELD_ITEM \
                           | RANDOMIZER_FLAG_GIFT \
                           | RANDOMIZER_FLAG_STATIC \
                           | RANDOMIZER_FLAG_STATIC_KEEP_LEGENDS)

#define RANDOMIZER_ALL_EXTRA_FLAGS (RANDOMIZER_FLAG_MOVE_PP \
                                  | RANDOMIZER_FLAG_MOVE_POWER \
                                  | RANDOMIZER_FLAG_BASE_STATS \
                                  | RANDOMIZER_FLAG_LEARNSET \
                                  | RANDOMIZER_FLAG_ABILITIES \
                                  | RANDOMIZER_FLAG_TMHM \
                                  | RANDOMIZER_FLAG_UNIVERSAL_TMHM)

static u32 MixHash32(u32 value)
{
    value ^= value >> 16;
    value *= 0x7FEB352D;
    value ^= value >> 15;
    value *= 0x846CA68B;
    value ^= value >> 16;
    return value;
}

static u32 GetItemRandomizerHash(u16 item, enum RandomizerMode mode, u32 context)
{
    u32 hash = gSaveBlock2Ptr->optionsRandomizerSeed;

    hash ^= (u32)(mode + 1) * 0x9E3779B9;
    hash ^= (u32)item * 0x85EBCA6B;
    hash ^= MixHash32(context ^ 0xC2B2AE35);
    return MixHash32(hash);
}

static bool32 HasPlaceholderItemDescription(u16 itemId)
{
    const u8 *description = GetItemDescription(itemId);

    return description == NULL || description[0] == '?';
}

static bool32 IsRandomizerActive(void)
{
    u8 enabled;
    u8 flags;
    u8 extraFlags;

    if (gSaveBlock2Ptr == NULL)
        return FALSE;

    enabled = gSaveBlock2Ptr->optionsRandomizerEnabled;
    flags = gSaveBlock2Ptr->optionsRandomizerFlags;
    extraFlags = gSaveBlock2Ptr->optionsRandomizerExtraFlags;

    if (enabled != TRUE)
        return FALSE;

    if ((flags & ~RANDOMIZER_ALL_FLAGS) != 0)
        return FALSE;

    if ((extraFlags & ~(RANDOMIZER_ALL_EXTRA_FLAGS >> 8)) != 0)
        return FALSE;

    if ((flags == 0 && extraFlags == 0) || gSaveBlock2Ptr->optionsRandomizerSeed == 0)
        return FALSE;

    return TRUE;
}

static u8 GetRandomizerExtraFlags(void)
{
    u8 extraFlags;

    if (!IsRandomizerActive())
        return 0;

    extraFlags = gSaveBlock2Ptr->optionsRandomizerExtraFlags;
    if ((extraFlags & ~(RANDOMIZER_ALL_EXTRA_FLAGS >> 8)) != 0)
        return 0;

    return extraFlags;
}

static bool32 IsExtraFlagEnabled(u16 extraFlag)
{
    return (GetRandomizerExtraFlags() & (extraFlag >> 8)) != 0;
}

static u32 GetMoveRandomizerHash(u16 move, u32 salt)
{
    u32 hash = gSaveBlock2Ptr->optionsRandomizerSeed;

    hash ^= (u32)move * 0x9E3779B9;
    hash ^= salt;
    return MixHash32(hash);
}

static void GetRandomizedSpeciesBaseStats(u16 species, u8 randomizedStats[NUM_STATS])
{
    u8 statValues[NUM_STATS];
    u8 i;

    species = SanitizeSpeciesId(species);
    statValues[STAT_HP] = gSpeciesInfo[species].baseHP;
    statValues[STAT_ATK] = gSpeciesInfo[species].baseAttack;
    statValues[STAT_DEF] = gSpeciesInfo[species].baseDefense;
    statValues[STAT_SPEED] = gSpeciesInfo[species].baseSpeed;
    statValues[STAT_SPATK] = gSpeciesInfo[species].baseSpAttack;
    statValues[STAT_SPDEF] = gSpeciesInfo[species].baseSpDefense;

    for (i = 0; i < NUM_STATS; i++)
    {
        u32 hash = MixHash32(gSaveBlock2Ptr->optionsRandomizerSeed ^ ((u32)species << 16) ^ (i * 0x45D9F3B));
        u8 swapIndex = i + (hash % (NUM_STATS - i));
        u8 temp = statValues[i];

        statValues[i] = statValues[swapIndex];
        statValues[swapIndex] = temp;
    }

    for (i = 0; i < NUM_STATS; i++)
        randomizedStats[i] = statValues[i];
}

static bool32 IsRandomizedMoveAllowed(u16 move)
{
    return move != MOVE_NONE && move < MOVES_COUNT && move != MOVE_STRUGGLE;
}

static bool32 IsHiddenMachineMove(u16 move)
{
    switch (move)
    {
    case MOVE_CUT:
    case MOVE_FLY:
    case MOVE_SURF:
    case MOVE_STRENGTH:
    case MOVE_FLASH:
    case MOVE_ROCK_SMASH:
    case MOVE_WATERFALL:
    case MOVE_DIVE:
        return TRUE;
    default:
        return FALSE;
    }
}

static bool32 IsAbilityRandomizable(enum Ability ability)
{
    switch (ability)
    {
    case ABILITY_NONE:
    case ABILITY_MULTITYPE:
    case ABILITY_SHIELDS_DOWN:
    case ABILITY_SCHOOLING:
    case ABILITY_DISGUISE:
    case ABILITY_BATTLE_BOND:
    case ABILITY_POWER_CONSTRUCT:
    case ABILITY_RKS_SYSTEM:
    case ABILITY_INTREPID_SWORD:
    case ABILITY_DAUNTLESS_SHIELD:
    case ABILITY_GULP_MISSILE:
    case ABILITY_ICE_FACE:
    case ABILITY_HUNGER_SWITCH:
    case ABILITY_AS_ONE_ICE_RIDER:
    case ABILITY_AS_ONE_SHADOW_RIDER:
    case ABILITY_ZERO_TO_HERO:
    case ABILITY_COMMANDER:
    case ABILITY_ORICHALCUM_PULSE:
    case ABILITY_HADRON_ENGINE:
    case ABILITY_EMBODY_ASPECT_TEAL_MASK:
    case ABILITY_EMBODY_ASPECT_HEARTHFLAME_MASK:
    case ABILITY_EMBODY_ASPECT_WELLSPRING_MASK:
    case ABILITY_EMBODY_ASPECT_CORNERSTONE_MASK:
    case ABILITY_TERA_SHIFT:
    case ABILITY_TERAFORM_ZERO:
        return FALSE;
    default:
        return ability > ABILITY_NONE && ability < ABILITIES_COUNT;
    }
}

static void GetRandomizedSpeciesAbilities(u16 species, enum Ability randomizedAbilities[NUM_ABILITY_SLOTS])
{
    u8 slot;

    species = SanitizeSpeciesId(species);
    for (slot = 0; slot < NUM_ABILITY_SLOTS; slot++)
    {
        enum Ability originalAbility = gSpeciesInfo[species].abilities[slot];
        u32 hash;
        u16 candidate;
        u16 tries;

        if (!IsAbilityRandomizable(originalAbility))
        {
            randomizedAbilities[slot] = originalAbility;
            continue;
        }

        hash = gSaveBlock2Ptr->optionsRandomizerSeed;
        hash ^= (u32)species * 0x9E3779B9;
        hash ^= (u32)(slot + 1) * 0x85EBCA6B;
        hash = MixHash32(hash);
        candidate = (hash % (ABILITIES_COUNT - 1)) + 1;

        for (tries = 0; tries < ABILITIES_COUNT; tries++)
        {
            bool32 duplicate = FALSE;
            u8 previousSlot;

            if (candidate >= ABILITIES_COUNT)
                candidate = ABILITY_STENCH;

            if (!IsAbilityRandomizable(candidate))
            {
                candidate++;
                continue;
            }

            for (previousSlot = 0; previousSlot < slot; previousSlot++)
            {
                if (randomizedAbilities[previousSlot] == candidate)
                {
                    duplicate = TRUE;
                    break;
                }
            }

            if (!duplicate)
                break;

            candidate++;
        }

        randomizedAbilities[slot] = candidate;
    }
}

static bool32 IsModeEnabled(enum RandomizerMode mode)
{
    u8 flags;

    if (!IsRandomizerActive())
        return FALSE;

    flags = gSaveBlock2Ptr->optionsRandomizerFlags;

    switch (mode)
    {
    case RANDOMIZER_MODE_WILD:
        return (flags & RANDOMIZER_FLAG_WILD) != 0;
    case RANDOMIZER_MODE_TRAINER:
        return (flags & RANDOMIZER_FLAG_TRAINER) != 0;
    case RANDOMIZER_MODE_STARTER:
        return (flags & RANDOMIZER_FLAG_STARTER) != 0;
    case RANDOMIZER_MODE_EVOLUTION:
        return (flags & RANDOMIZER_FLAG_EVOLUTION) != 0;
    case RANDOMIZER_MODE_FIELD_ITEM:
        return (flags & RANDOMIZER_FLAG_FIELD_ITEM) != 0;
    case RANDOMIZER_MODE_GIFT:
        return (flags & RANDOMIZER_FLAG_GIFT) != 0;
    case RANDOMIZER_MODE_STATIC:
        return (flags & RANDOMIZER_FLAG_STATIC) != 0;
    case RANDOMIZER_MODE_TMHM:
        return IsExtraFlagEnabled(RANDOMIZER_FLAG_TMHM);
    default:
        return FALSE;
    }
}

static u16 GetFullyRandomEnabledSpecies(void)
{
    u16 species;
    u16 tries;
    u32 hash;

    hash = gSaveBlock2Ptr->optionsRandomizerSeed ^ Random();
    hash = MixHash32(hash);
    species = (hash % (NUM_SPECIES - 1)) + 1;

    for (tries = 0; tries < NUM_SPECIES; tries++)
    {
        if (IsSpeciesEnabled(species) && species != SPECIES_EGG)
            return species;

        species++;
        if (species >= NUM_SPECIES)
            species = SPECIES_NONE + 1;
    }

    return SPECIES_BULBASAUR;
}

static bool32 IsFullRandomSpeciesMode(enum RandomizerMode mode)
{
    switch (mode)
    {
    case RANDOMIZER_MODE_WILD:
    case RANDOMIZER_MODE_TRAINER:
    case RANDOMIZER_MODE_EVOLUTION:
    case RANDOMIZER_MODE_GIFT:
    case RANDOMIZER_MODE_STATIC:
        return TRUE;
    default:
        return FALSE;
    }
}

static bool32 IsItemProtectedFromRandomizer(u16 itemId)
{
    if (itemId == ITEM_NONE || itemId >= ITEMS_COUNT)
        return TRUE;

    if (GetItemPocket(itemId) == POCKET_KEY_ITEMS)
        return TRUE;

    if (itemId >= ITEM_HM_CUT && itemId <= ITEM_HM_DIVE)
        return TRUE;

    return FALSE;
}

static u16 GetFullyRandomAllowedItem(void)
{
    u16 itemId;
    u16 tries;
    u32 hash;

    hash = gSaveBlock2Ptr->optionsRandomizerSeed ^ Random();
    hash = MixHash32(hash);
    itemId = (hash % (ITEMS_COUNT - 1)) + 1;

    for (tries = 0; tries < ITEMS_COUNT; tries++)
    {
        if (!IsItemProtectedFromRandomizer(itemId))
            return itemId;

        itemId++;
        if (itemId >= ITEMS_COUNT)
            itemId = ITEM_NONE + 1;
    }

    return ITEM_POTION;
}

bool32 Randomizer_IsUniversalTmHmCompatibilityEnabled(void)
{
    return IsExtraFlagEnabled(RANDOMIZER_FLAG_UNIVERSAL_TMHM);
}

u16 Randomizer_GetSpecies(u16 originalSpecies, enum RandomizerMode mode)
{
    u16 species;
    u32 hash;

    if (!IsModeEnabled(mode))
        return originalSpecies;

    // Full-random modes roll a new enabled species per call instead of static 1:1 mapping.
    if (IsFullRandomSpeciesMode(mode))
        return GetFullyRandomEnabledSpecies();

    species = SanitizeSpeciesId(originalSpecies);
    if (species == SPECIES_NONE || species == SPECIES_EGG)
        return originalSpecies;

    hash = gSaveBlock2Ptr->optionsRandomizerSeed;
    hash ^= (u32)(mode + 1) * 0x9E3779B9;
    hash ^= (u32)species * 0x85EBCA6B;
    hash = MixHash32(hash);

    species = (hash % (NUM_SPECIES - 1)) + 1;
    while (!IsSpeciesEnabled(species) || species == SPECIES_EGG)
    {
        species++;
        if (species >= NUM_SPECIES)
            species = SPECIES_NONE + 1;
    }

    return species;
}

u16 Randomizer_GetItem(u16 originalItem, enum RandomizerMode mode)
{
    return Randomizer_GetContextualItem(originalItem, mode, 0);
}

u16 Randomizer_GetContextualItem(u16 originalItem, enum RandomizerMode mode, u32 context)
{
    u16 item;
    u32 hash;

    if (!IsModeEnabled(mode))
        return originalItem;

    item = originalItem;
    if (item == ITEM_NONE || item >= ITEMS_COUNT)
        return originalItem;

    if (IsItemProtectedFromRandomizer(item))
        return originalItem;

    if (mode == RANDOMIZER_MODE_WILD
     || mode == RANDOMIZER_MODE_TRAINER
     || mode == RANDOMIZER_MODE_FIELD_ITEM
     || mode == RANDOMIZER_MODE_GIFT)
    {
        (void)context;
        return GetFullyRandomAllowedItem();
    }

    hash = GetItemRandomizerHash(item, mode, context);

    item = (hash % (ITEMS_COUNT - 1)) + 1;
    return item;
}

u16 Randomizer_GetMove(u16 originalMove, enum RandomizerMode mode)
{
    u16 move;
    u32 hash;
    u16 tries;

    if (!IsModeEnabled(mode))
        return originalMove;

    move = originalMove;
    if (move == MOVE_NONE || move >= MOVES_COUNT)
        return originalMove;

    hash = gSaveBlock2Ptr->optionsRandomizerSeed;
    hash ^= (u32)(mode + 1) * 0x9E3779B9;
    hash ^= (u32)move * 0x85EBCA6B;
    hash = MixHash32(hash);

    move = (hash % (MOVES_COUNT - 1)) + 1;

    for (tries = 0; tries < MOVES_COUNT; tries++)
    {
        if (move >= MOVES_COUNT)
            move = MOVE_POUND;

        if (move != MOVE_STRUGGLE
         && !(mode == RANDOMIZER_MODE_TMHM && IsHiddenMachineMove(move)))
            return move;

        move++;
    }

    return originalMove;
}

u32 Randomizer_GetMovePower(u16 originalMove, u32 originalPower)
{
    u32 hash;
    u32 minPower;
    u32 maxPower;

    if (!IsExtraFlagEnabled(RANDOMIZER_FLAG_MOVE_POWER))
        return originalPower;

    if (!IsRandomizedMoveAllowed(originalMove) || originalPower <= 1)
        return originalPower;

    hash = GetMoveRandomizerHash(originalMove, 0xA5A5F00D);
    minPower = max(10u, originalPower / 2);
    maxPower = min(250u, max(minPower, originalPower + max(10u, originalPower / 2)));
    return minPower + (hash % (maxPower - minPower + 1));
}

u32 Randomizer_GetMovePP(u16 originalMove, u32 originalPP)
{
    u32 hash;
    u32 minPP;
    u32 maxPP;

    if (!IsExtraFlagEnabled(RANDOMIZER_FLAG_MOVE_PP))
        return originalPP;

    if (!IsRandomizedMoveAllowed(originalMove) || originalPP == 0)
        return originalPP;

    hash = GetMoveRandomizerHash(originalMove, 0x5A5A0FF1);
    minPP = max(5u, originalPP / 2);
    maxPP = min(40u, max(minPP, originalPP + max(3u, originalPP / 2)));
    return minPP + (hash % (maxPP - minPP + 1));
}

u16 Randomizer_GetLevelUpMove(u16 species, u16 level, u16 slot, u16 originalMove)
{
    u32 hash;
    u16 move;
    u16 tries;

    if (!IsExtraFlagEnabled(RANDOMIZER_FLAG_LEARNSET))
        return originalMove;

    if (!IsRandomizedMoveAllowed(originalMove))
        return originalMove;

    species = SanitizeSpeciesId(species);
    if (species == SPECIES_NONE || species == SPECIES_EGG)
        return originalMove;

    hash = gSaveBlock2Ptr->optionsRandomizerSeed;
    hash ^= (u32)species * 0x9E3779B9;
    hash ^= (u32)level * 0x85EBCA6B;
    hash ^= (u32)(slot + 1) * 0xC2B2AE35;
    hash ^= (u32)originalMove * 0x27D4EB2D;
    hash = MixHash32(hash);
    move = (hash % (MOVES_COUNT - 1)) + 1;

    for (tries = 0; tries < MOVES_COUNT; tries++)
    {
        if (IsRandomizedMoveAllowed(move))
            return move;

        move++;
        if (move >= MOVES_COUNT)
            move = MOVE_POUND;
    }

    return originalMove;
}

enum Ability Randomizer_GetAbility(u16 species, u8 slot, enum Ability originalAbility)
{
    enum Ability randomizedAbilities[NUM_ABILITY_SLOTS];

    if (!IsExtraFlagEnabled(RANDOMIZER_FLAG_ABILITIES))
        return originalAbility;

    if (slot >= NUM_ABILITY_SLOTS)
        return originalAbility;

    species = SanitizeSpeciesId(species);
    if (species == SPECIES_NONE || species == SPECIES_EGG)
        return originalAbility;

    GetRandomizedSpeciesAbilities(species, randomizedAbilities);
    return randomizedAbilities[slot];
}

static bool32 IsLegendaryOrMythicalSpecies(u16 species)
{
    const struct SpeciesInfo *speciesInfo;

    species = SanitizeSpeciesId(species);
    if (species == SPECIES_NONE || species == SPECIES_EGG)
        return FALSE;

    speciesInfo = &gSpeciesInfo[species];
    return speciesInfo->isRestrictedLegendary || speciesInfo->isSubLegendary || speciesInfo->isMythical;
}

u16 Randomizer_GetStaticSpecies(u16 originalSpecies)
{
    if ((gSaveBlock2Ptr->optionsRandomizerFlags & RANDOMIZER_FLAG_STATIC_KEEP_LEGENDS)
        && IsLegendaryOrMythicalSpecies(originalSpecies))
    {
        return originalSpecies;
    }

    return Randomizer_GetSpecies(originalSpecies, RANDOMIZER_MODE_STATIC);
}

u32 Randomizer_GetSpeciesBaseStatValue(u16 species, u8 statIndex, u32 originalValue)
{
    u8 randomizedStats[NUM_STATS];

    if (!IsExtraFlagEnabled(RANDOMIZER_FLAG_BASE_STATS))
        return originalValue;

    species = SanitizeSpeciesId(species);
    if (species == SPECIES_NONE || species == SPECIES_EGG || statIndex >= NUM_STATS)
        return originalValue;

    GetRandomizedSpeciesBaseStats(species, randomizedStats);
    return randomizedStats[statIndex];
}

bool32 Randomizer_IsAllowedRandomizedItem(u16 itemId)
{
    if (itemId == ITEM_NONE || itemId >= ITEMS_COUNT)
        return FALSE;

    if (GetItemPocket(itemId) == POCKET_KEY_ITEMS)
        return FALSE;

    if (itemId >= ITEM_HM_CUT && itemId <= ITEM_HM_DIVE)
        return FALSE;

    if (GetItemName(itemId) == gQuestionMarksItemName)
        return FALSE;

    if (HasPlaceholderItemDescription(itemId))
        return FALSE;

    return TRUE;
}

u16 Randomizer_GetAllowedItem(u16 originalItem, enum RandomizerMode mode)
{
    return Randomizer_GetAllowedContextualItem(originalItem, mode, 0);
}

u16 Randomizer_GetAllowedContextualItem(u16 originalItem, enum RandomizerMode mode, u32 context)
{
    u16 itemId;
    u16 tries;

    if (!Randomizer_IsAllowedRandomizedItem(originalItem))
        return originalItem;

    itemId = Randomizer_GetContextualItem(originalItem, mode, context);
    if (Randomizer_IsAllowedRandomizedItem(itemId))
        return itemId;

    for (tries = 0; tries < ITEMS_COUNT; tries++)
    {
        itemId++;
        if (itemId >= ITEMS_COUNT)
            itemId = ITEM_NONE + 1;

        if (Randomizer_IsAllowedRandomizedItem(itemId))
            return itemId;
    }

    return originalItem;
}

u16 Randomizer_GetShopItem(u16 originalItem, u16 slot)
{
    u32 context = slot;

    if (originalItem == ITEM_NONE || originalItem >= ITEMS_COUNT)
        return originalItem;

    if (GetItemPocket(originalItem) == POCKET_POKE_BALLS)
        return originalItem;

    if (gSaveBlock1Ptr != NULL)
    {
        context ^= ((u32)gSaveBlock1Ptr->location.mapGroup << 24);
        context ^= ((u32)gSaveBlock1Ptr->location.mapNum << 16);
    }

    return Randomizer_GetAllowedContextualItem(originalItem, RANDOMIZER_MODE_FIELD_ITEM, context);
}
