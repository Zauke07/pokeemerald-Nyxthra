#include "global.h"
#include "challenge_mode.h"
#include "event_data.h"
#include "overworld.h"
#include "random.h"
#include "save.h"
#include "constants/maps.h"
#include "constants/map_types.h"
#include "constants/region_map_sections.h"
#include "data/map_group_count.h"

#define CHALLENGE_MAX_ELIGIBLE_WARPS 2048

struct ChallengeWarpKey
{
    u16 mapGroup;
    u8 mapNum;
    u8 warpId;
};

extern const struct MapHeader *const *const gMapGroups[];

static EWRAM_DATA struct ChallengeWarpKey sEligibleWarps[CHALLENGE_MAX_ELIGIBLE_WARPS] = {0};
static EWRAM_DATA u16 sPairIndex[CHALLENGE_MAX_ELIGIBLE_WARPS] = {0};
static EWRAM_DATA u16 sShuffledList[CHALLENGE_MAX_ELIGIBLE_WARPS] = {0};
static EWRAM_DATA u16 sEligibleWarpCount = 0;
static EWRAM_DATA bool8 sWarpPairsReady = FALSE;
static EWRAM_DATA u32 sWarpPairSeed = 0;

static bool8 IsValidWarpSpawn(const struct MapHeader *mapHeader, u8 warpId)
{
    const struct WarpEvent *warp;

    if (mapHeader == NULL
     || mapHeader->mapLayout == NULL
     || mapHeader->events == NULL
     || mapHeader->events->warps == NULL)
        return FALSE;

    if (mapHeader->mapLayout->width <= 0 || mapHeader->mapLayout->height <= 0)
        return FALSE;

    if (warpId >= mapHeader->events->warpCount)
        return FALSE;

    warp = &mapHeader->events->warps[warpId];
    if (warp->x < 0 || warp->y < 0)
        return FALSE;
    if (warp->x >= mapHeader->mapLayout->width || warp->y >= mapHeader->mapLayout->height)
        return FALSE;

    return TRUE;
}

static bool8 AreTwinWarpEvents(const struct WarpEvent *a, const struct WarpEvent *b)
{
    s16 dx;
    s16 dy;

    if (a->mapGroup != b->mapGroup
     || a->mapNum != b->mapNum
     || a->warpId != b->warpId
     || a->elevation != b->elevation)
        return FALSE;

    dx = (s16)a->x - (s16)b->x;
    dy = (s16)a->y - (s16)b->y;
    if (dx < 0)
        dx = -dx;
    if (dy < 0)
        dy = -dy;

    // Same doorway split into two adjacent warp tiles.
    return (dx + dy) == 1;
}

static u8 GetCanonicalWarpId(const struct MapHeader *mapHeader, u8 warpId)
{
    u16 i;
    u8 canonicalWarpId = warpId;
    const struct WarpEvent *warp;

    if (mapHeader == NULL || mapHeader->events == NULL || mapHeader->events->warps == NULL)
        return warpId;
    if (warpId >= mapHeader->events->warpCount)
        return warpId;

    warp = &mapHeader->events->warps[warpId];
    for (i = 0; i < mapHeader->events->warpCount; i++)
    {
        if (i == warpId)
            continue;
        if (AreTwinWarpEvents(warp, &mapHeader->events->warps[i]) && i < canonicalWarpId)
            canonicalWarpId = i;
    }

    return canonicalWarpId;
}

static bool8 IsChallengeModeActive(void)
{
    if (gSaveBlock2Ptr == NULL)
        return FALSE;

    return (gSaveBlock2Ptr->optionsChallengeFlags & CHALLENGE_MODE_FLAG_DOOR_WARP_RANDOM) != 0;
}

u16 IsDoorWarpRandomizerActiveSpecial(void)
{
    return IsChallengeModeActive();
}

static bool8 IsExcludedChallengeWarpMap(u8 mapGroup, u8 mapNum)
{
    const struct MapHeader *mapHeader;

    // Hard exclusion: never randomize Littleroot/truck/test-lab maps, regardless of map section data.
    if ((mapGroup == MAP_GROUP(MAP_LITTLEROOT_TOWN) && mapNum == MAP_NUM(MAP_LITTLEROOT_TOWN))
     || (mapGroup == MAP_GROUP(MAP_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F) && mapNum == MAP_NUM(MAP_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F))
     || (mapGroup == MAP_GROUP(MAP_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F) && mapNum == MAP_NUM(MAP_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F))
     || (mapGroup == MAP_GROUP(MAP_LITTLEROOT_TOWN_MAYS_HOUSE_1F) && mapNum == MAP_NUM(MAP_LITTLEROOT_TOWN_MAYS_HOUSE_1F))
     || (mapGroup == MAP_GROUP(MAP_LITTLEROOT_TOWN_MAYS_HOUSE_2F) && mapNum == MAP_NUM(MAP_LITTLEROOT_TOWN_MAYS_HOUSE_2F))
     || (mapGroup == MAP_GROUP(MAP_LITTLEROOT_TOWN_PROFESSOR_BIRCHS_LAB) && mapNum == MAP_NUM(MAP_LITTLEROOT_TOWN_PROFESSOR_BIRCHS_LAB))
     || (mapGroup == MAP_GROUP(MAP_TESTLABOR) && mapNum == MAP_NUM(MAP_TESTLABOR))
     || (mapGroup == MAP_GROUP(MAP_TESTLABOR_FIELDMOVES) && mapNum == MAP_NUM(MAP_TESTLABOR_FIELDMOVES))
     || (mapGroup == MAP_GROUP(MAP_TESTLABOR_UNTERWASSER) && mapNum == MAP_NUM(MAP_TESTLABOR_UNTERWASSER))
     || (mapGroup == MAP_GROUP(MAP_INSIDE_OF_TRUCK) && mapNum == MAP_NUM(MAP_INSIDE_OF_TRUCK))
    || (mapGroup == MAP_GROUP(MAP_TRAINER_HILL_ENTRANCE) && mapNum == MAP_NUM(MAP_TRAINER_HILL_ENTRANCE))
    || (mapGroup == MAP_GROUP(MAP_TRAINER_HILL_1F) && mapNum == MAP_NUM(MAP_TRAINER_HILL_1F))
    || (mapGroup == MAP_GROUP(MAP_TRAINER_HILL_2F) && mapNum == MAP_NUM(MAP_TRAINER_HILL_2F))
    || (mapGroup == MAP_GROUP(MAP_TRAINER_HILL_3F) && mapNum == MAP_NUM(MAP_TRAINER_HILL_3F))
    || (mapGroup == MAP_GROUP(MAP_TRAINER_HILL_4F) && mapNum == MAP_NUM(MAP_TRAINER_HILL_4F))
    || (mapGroup == MAP_GROUP(MAP_TRAINER_HILL_ROOF) && mapNum == MAP_NUM(MAP_TRAINER_HILL_ROOF))
    || (mapGroup == MAP_GROUP(MAP_TRAINER_HILL_ELEVATOR) && mapNum == MAP_NUM(MAP_TRAINER_HILL_ELEVATOR))
     || (mapGroup == MAP_GROUP(MAP_EVER_GRANDE_CITY_HALL_OF_FAME) && mapNum == MAP_NUM(MAP_EVER_GRANDE_CITY_HALL_OF_FAME))
     || (mapGroup == MAP_GROUP(MAP_POKEMON_LEAGUE_HALL_OF_FAME) && mapNum == MAP_NUM(MAP_POKEMON_LEAGUE_HALL_OF_FAME))
     // Link/union rooms: require wireless/IR hardware state
     || (mapGroup == MAP_GROUP(MAP_UNION_ROOM) && mapNum == MAP_NUM(MAP_UNION_ROOM))
     || (mapGroup == MAP_GROUP(MAP_TRADE_CENTER) && mapNum == MAP_NUM(MAP_TRADE_CENTER))
     || (mapGroup == MAP_GROUP(MAP_RECORD_CORNER) && mapNum == MAP_NUM(MAP_RECORD_CORNER))
     || (mapGroup == MAP_GROUP(MAP_BATTLE_COLOSSEUM_2P) && mapNum == MAP_NUM(MAP_BATTLE_COLOSSEUM_2P))
     || (mapGroup == MAP_GROUP(MAP_BATTLE_COLOSSEUM_4P) && mapNum == MAP_NUM(MAP_BATTLE_COLOSSEUM_4P))
     || (mapGroup == MAP_GROUP(MAP_UNION_ROOM_FRLG) && mapNum == MAP_NUM(MAP_UNION_ROOM_FRLG))
     || (mapGroup == MAP_GROUP(MAP_TRADE_CENTER_FRLG) && mapNum == MAP_NUM(MAP_TRADE_CENTER_FRLG))
     || (mapGroup == MAP_GROUP(MAP_RECORD_CORNER_FRLG) && mapNum == MAP_NUM(MAP_RECORD_CORNER_FRLG))
     || (mapGroup == MAP_GROUP(MAP_BATTLE_COLOSSEUM_2P_FRLG) && mapNum == MAP_NUM(MAP_BATTLE_COLOSSEUM_2P_FRLG))
     || (mapGroup == MAP_GROUP(MAP_BATTLE_COLOSSEUM_4P_FRLG) && mapNum == MAP_NUM(MAP_BATTLE_COLOSSEUM_4P_FRLG))
     // Battle rooms: battle state machine breaks when entered without valid challenge context
     || (mapGroup == MAP_GROUP(MAP_BATTLE_FRONTIER_BATTLE_TOWER_BATTLE_ROOM) && mapNum == MAP_NUM(MAP_BATTLE_FRONTIER_BATTLE_TOWER_BATTLE_ROOM))
     || (mapGroup == MAP_GROUP(MAP_BATTLE_FRONTIER_BATTLE_PALACE_BATTLE_ROOM) && mapNum == MAP_NUM(MAP_BATTLE_FRONTIER_BATTLE_PALACE_BATTLE_ROOM)))
        return TRUE;

    if (mapGroup >= MAP_GROUPS_COUNT || mapNum >= MAP_GROUP_COUNT[mapGroup])
        return FALSE;

    mapHeader = gMapGroups[mapGroup][mapNum];
    if (mapHeader == NULL)
        return FALSE;

    return mapHeader->regionMapSectionId == MAPSEC_LITTLEROOT_TOWN
        || mapHeader->regionMapSectionId == MAPSEC_INSIDE_OF_TRUCK;
}

static bool8 IsAllowedChallengeMap(const struct MapHeader *mapHeader)
{
    if (mapHeader == NULL)
        return FALSE;

    if (mapHeader->mapLayout == NULL
     || mapHeader->events == NULL
     || mapHeader->events->warps == NULL)
        return FALSE;

    if (mapHeader->mapLayout->width <= 0 || mapHeader->mapLayout->height <= 0)
        return FALSE;

    if (mapHeader->regionMapSectionId == MAPSEC_NONE
     || mapHeader->regionMapSectionId == MAPSEC_DYNAMIC)
        return FALSE;

    // Keep random pool on regular overworld map types to avoid unstable special/link maps.
    if (mapHeader->mapType == MAP_TYPE_NONE
     || mapHeader->mapType == MAP_TYPE_UNKNOWN
     || mapHeader->mapType == MAP_TYPE_SECRET_BASE)
        return FALSE;

    return TRUE;
}

static bool8 IsEligibleWarp(const struct MapHeader *sourceMapHeader, u8 sourceMapGroup, u8 sourceMapNum, u8 sourceWarpId)
{
    const struct WarpEvent *sourceWarp;
    const struct MapHeader *destMapHeader;

    if (sourceMapHeader == NULL || sourceMapHeader->events == NULL || sourceMapHeader->events->warps == NULL)
        return FALSE;
    if (sourceWarpId >= sourceMapHeader->events->warpCount)
        return FALSE;
    if (IsExcludedChallengeWarpMap(sourceMapGroup, sourceMapNum))
        return FALSE;

    if (!IsAllowedChallengeMap(sourceMapHeader))
        return FALSE;

    sourceWarp = &sourceMapHeader->events->warps[sourceWarpId];
    if (!IsValidWarpSpawn(sourceMapHeader, sourceWarpId))
        return FALSE;

    // Warps that rely on MAP_DYNAMIC are the main source of invalid fallback returns.
    if (sourceWarp->mapNum == MAP_NUM(MAP_DYNAMIC))
        return FALSE;

    if (sourceWarp->mapGroup >= MAP_GROUPS_COUNT || sourceWarp->mapNum >= MAP_GROUP_COUNT[sourceWarp->mapGroup])
        return FALSE;

    destMapHeader = gMapGroups[sourceWarp->mapGroup][sourceWarp->mapNum];
    if (destMapHeader == NULL || destMapHeader->events == NULL || destMapHeader->events->warps == NULL)
        return FALSE;

    if (!IsAllowedChallengeMap(destMapHeader))
        return FALSE;

    if (IsExcludedChallengeWarpMap(sourceWarp->mapGroup, sourceWarp->mapNum))
        return FALSE;

    // Ensure destination spawn warp exists and is also a fixed map warp.
    if (!IsValidWarpSpawn(destMapHeader, sourceWarp->warpId))
        return FALSE;
    if (destMapHeader->events->warps[sourceWarp->warpId].mapNum == MAP_NUM(MAP_DYNAMIC))
        return FALSE;

    return TRUE;
}

static u32 NextShuffleRand(u32 *state)
{
    *state = (*state * 1103515245u) + 12345u;
    return *state;
}

static void BuildWarpPairs(void)
{
    u16 i;
    u32 shuffleState;

    if (gSaveBlock2Ptr == NULL)
        return;

    sEligibleWarpCount = 0;
    for (u16 group = 0; group < MAP_GROUPS_COUNT; group++)
    {
        for (u16 map = 0; map < MAP_GROUP_COUNT[group]; map++)
        {
            const struct MapHeader *mapHeader = gMapGroups[group][map];
            if (mapHeader == NULL || mapHeader->events == NULL || mapHeader->events->warps == NULL)
                continue;

            for (u16 warpId = 0; warpId < mapHeader->events->warpCount; warpId++)
            {
                u8 canonicalWarpId = GetCanonicalWarpId(mapHeader, warpId);

                if (warpId != canonicalWarpId)
                    continue;

                if (!IsEligibleWarp(mapHeader, group, map, canonicalWarpId))
                    continue;

                if (sEligibleWarpCount >= CHALLENGE_MAX_ELIGIBLE_WARPS)
                    break;

                sEligibleWarps[sEligibleWarpCount].mapGroup = group;
                sEligibleWarps[sEligibleWarpCount].mapNum = map;
                sEligibleWarps[sEligibleWarpCount].warpId = canonicalWarpId;
                sShuffledList[sEligibleWarpCount] = sEligibleWarpCount; // Nutzt jetzt sShuffledList!
                sEligibleWarpCount++;
            }

            if (sEligibleWarpCount >= CHALLENGE_MAX_ELIGIBLE_WARPS)
                break;
        }

        if (sEligibleWarpCount >= CHALLENGE_MAX_ELIGIBLE_WARPS)
            break;
    }

    if (sEligibleWarpCount == 0)
    {
        sWarpPairsReady = TRUE;
        sWarpPairSeed = gSaveBlock2Ptr->optionsRandomizerSeed;
        return;
    }

    shuffleState = gSaveBlock2Ptr->optionsRandomizerSeed;
    if (shuffleState == 0)
        shuffleState = 1;

    // 1. Zuerst die sShuffledList mischen (sPairIndex bleibt unangetastet!)
    for (i = sEligibleWarpCount - 1; i > 0; i--)
    {
        u16 j = NextShuffleRand(&shuffleState) % (i + 1);
        u16 temp = sShuffledList[i];
        sShuffledList[i] = sShuffledList[j];
        sShuffledList[j] = temp;
    }

    // 2. Jetzt die gemischten Pärchen SICHER in sPairIndex eintragen
    for (i = 0; i + 1 < sEligibleWarpCount; i += 2)
    {
        u16 a = sShuffledList[i];
        u16 b = sShuffledList[i + 1];
        sPairIndex[a] = b;
        sPairIndex[b] = a;
    }

    // Falls es eine ungerade Anzahl an Türen gibt, zeigt die letzte auf sich selbst
    if ((sEligibleWarpCount & 1) != 0)
    {
        u16 last = sShuffledList[sEligibleWarpCount - 1];
        sPairIndex[last] = last;
    }

    sWarpPairsReady = TRUE;
    sWarpPairSeed = gSaveBlock2Ptr->optionsRandomizerSeed;
}

static s16 FindWarpKeyIndex(u8 sourceMapGroup, u8 sourceMapNum, u8 sourceWarpId)
{
    for (u16 i = 0; i < sEligibleWarpCount; i++)
    {
        if (sEligibleWarps[i].mapGroup == sourceMapGroup
         && sEligibleWarps[i].mapNum == sourceMapNum
         && sEligibleWarps[i].warpId == sourceWarpId)
            return i;
    }

    return -1;
}

void ChallengeMode_DisableDoorWarpRandom(void)
{
    if (gSaveBlock2Ptr == NULL)
        return;

    gSaveBlock2Ptr->optionsChallengeFlags &= ~CHALLENGE_MODE_FLAG_DOOR_WARP_RANDOM;
    sWarpPairsReady = FALSE;
    sEligibleWarpCount = 0;
    sWarpPairSeed = 0;
}

void ChallengeMode_EnableDoorWarpRandom(void)
{
    u32 seed;

    if (gSaveBlock2Ptr == NULL)
        return;

    ChallengeMode_DisableDoorWarpRandom();

    // Reuse the active randomizer seed when available; otherwise create one.
    seed = gSaveBlock2Ptr->optionsRandomizerSeed;
    if (seed == 0)
    {
        seed = ((u32)Random() << 16) | Random();
        if (seed == 0)
            seed = 1;
        gSaveBlock2Ptr->optionsRandomizerSeed = seed;
    }

    gSaveBlock2Ptr->optionsChallengeFlags |= CHALLENGE_MODE_FLAG_DOOR_WARP_RANDOM;

    sWarpPairsReady = FALSE;
    sEligibleWarpCount = 0;
    sWarpPairSeed = 0;
}

bool8 ChallengeMode_GetWarpDestinationOverride(u8 sourceMapGroup, u8 sourceMapNum, u8 sourceWarpId,
                                               u8 *destMapGroup, u8 *destMapNum, u8 *destWarpId)
{
    s16 sourceIndex;
    u16 destIndex;
    const struct MapHeader *sourceMapHeader;
    const struct MapHeader *destMapHeader;

    if (!IsChallengeModeActive())
        return FALSE;

    if (gSaveBlock2Ptr->optionsRandomizerSeed == 0)
        return FALSE;

    if (IsExcludedChallengeWarpMap(sourceMapGroup, sourceMapNum))
        return FALSE;

    if (!sWarpPairsReady || sWarpPairSeed != gSaveBlock2Ptr->optionsRandomizerSeed)
        BuildWarpPairs();

    if (!sWarpPairsReady || sEligibleWarpCount == 0)
        return FALSE;

    if (sourceMapGroup >= MAP_GROUPS_COUNT || sourceMapNum >= MAP_GROUP_COUNT[sourceMapGroup])
        return FALSE;

    sourceMapHeader = gMapGroups[sourceMapGroup][sourceMapNum];
    if (sourceMapHeader == NULL)
        return FALSE;

    sourceWarpId = GetCanonicalWarpId(sourceMapHeader, sourceWarpId);

    sourceIndex = FindWarpKeyIndex(sourceMapGroup, sourceMapNum, sourceWarpId);
    if (sourceIndex < 0)
        return FALSE;

    destIndex = sPairIndex[sourceIndex];
    if (destIndex >= sEligibleWarpCount)
        return FALSE;

    if (IsExcludedChallengeWarpMap(sEligibleWarps[destIndex].mapGroup, sEligibleWarps[destIndex].mapNum))
        return FALSE;

    if (sEligibleWarps[destIndex].mapGroup >= MAP_GROUPS_COUNT
     || sEligibleWarps[destIndex].mapNum >= MAP_GROUP_COUNT[sEligibleWarps[destIndex].mapGroup])
        return FALSE;

    destMapHeader = gMapGroups[sEligibleWarps[destIndex].mapGroup][sEligibleWarps[destIndex].mapNum];
    if (!IsAllowedChallengeMap(destMapHeader))
        return FALSE;
    if (!IsValidWarpSpawn(destMapHeader, sEligibleWarps[destIndex].warpId))
        return FALSE;

    *destMapGroup = sEligibleWarps[destIndex].mapGroup;
    *destMapNum = sEligibleWarps[destIndex].mapNum;
    *destWarpId = sEligibleWarps[destIndex].warpId;
    return TRUE;
}
