#include "global.h"
#include "pokemon.h"
#include "strings.h"
#include "nyxthra_flashback.h"
#include "nyxthra_flashback_internal.h"
#include "constants/maps.h"
#include "constants/moves.h"
#include "constants/species.h"
#include "constants/items.h"

extern const u8 NyxthraFlashback_EventScript_Clip1[];
extern const u8 NyxthraFlashback_EventScript_Evolution[];
extern const u8 NyxthraFlashback_EventScript_Gym4[];
extern const u8 NyxthraFlashback_EventScript_Gym8[];
extern const u8 NyxthraFlashback_EventScript_Marc[];
extern const u8 NyxthraFlashback_EventScript_Adrian[];
extern const u8 NyxthraFlashback_EventScript_Antonia[];
extern const u8 NyxthraFlashback_EventScript_Wassili[];
extern const u8 NyxthraFlashback_EventScript_Groudon[];
extern const u8 NyxthraFlashback_EventScript_Kyogre[];
extern const u8 NyxthraFlashback_EventScript_Rayquaza[];
extern const u8 NyxthraFlashback_EventScript_Regirock[];
extern const u8 NyxthraFlashback_EventScript_Regice[];
extern const u8 NyxthraFlashback_EventScript_Registeel[];

void Flashback_GiveMoves(struct Pokemon *mon, u16 m0, u16 m1, u16 m2, u16 m3)
{
    SetMonMoveSlot(mon, m0, 0);
    SetMonMoveSlot(mon, m1, 1);
    SetMonMoveSlot(mon, m2, 2);
    SetMonMoveSlot(mon, m3, 3);
}

static void GivePlayerMon(enum Species species, u8 level, u16 m0, u16 m1, u16 m2, u16 m3)
{
    struct Pokemon *mon = &gParties[B_TRAINER_PLAYER][0];
    u32 i;

    ZeroPlayerPartyMons();
    for (i = 1; i < PARTY_SIZE; i++)
        ZeroMonData(&gParties[B_TRAINER_PLAYER][i]);
    CreateMon(mon, species, level, 0, OTID_STRUCT_PLAYER_ID);
    CalculateMonStats(mon);
    Flashback_GiveMoves(mon, m0, m1, m2, m3);
    gPartiesCount[B_TRAINER_PLAYER] = 1;
}

static void ClearOppParty(void)
{
    u32 i;
    for (i = 0; i < PARTY_SIZE; i++)
        ZeroMonData(&gParties[B_TRAINER_OPPONENT_A][i]);
}

static void AddOpp(u32 slot, enum Species species, u8 level, u8 iv, u16 item, u16 m0, u16 m1, u16 m2, u16 m3)
{
    struct Pokemon *mon = &gParties[B_TRAINER_OPPONENT_A][slot];
    CreateMonWithIVs(mon, species, level, 0, OTID_STRUCT_RANDOM_NO_SHINY, iv);
    Flashback_GiveMoves(mon, m0, m1, m2, m3);
    if (item != ITEM_NONE)
        SetMonData(mon, MON_DATA_HELD_ITEM, &item);
}

static const struct FlashbackClipDesc sClips[FLASHBACK_CLIP_COUNT] = {
    [FLASHBACK_CLIP_ROUTE101] = {
        .map = MAP_FLASHBACK_ROUTE101, .x = 10, .y = 19,
        .script = NyxthraFlashback_EventScript_Clip1, .hasBattle = TRUE,
        .startPlayerMove = MOVE_WATER_GUN, .startOppMove = MOVE_ROCK_TOMB,
        .finishPlayerMove = MOVE_WATER_GUN, .finishOppMove = MOVE_ROCK_TOMB,
    },
    [FLASHBACK_CLIP_EVOLUTION] = {
        .map = MAP_FLASHBACK_LAVARIDGE_GYM, .x = 13, .y = 16,
        .script = NyxthraFlashback_EventScript_Evolution, .hasBattle = FALSE,
    },
    [FLASHBACK_CLIP_GYM4] = {
        .map = MAP_FLASHBACK_LAVARIDGE_GYM, .x = 13, .y = 12,
        .script = NyxthraFlashback_EventScript_Gym4, .hasBattle = TRUE,
        .startPlayerMove = MOVE_WATER_GUN, .startOppMove = MOVE_OVERHEAT,
        .finishPlayerMove = MOVE_WATER_GUN, .finishOppMove = MOVE_OVERHEAT,
    },
    [FLASHBACK_CLIP_GYM8] = {
        .map = MAP_FLASHBACK_SOOTOPOLIS_GYM, .x = 8, .y = 5,
        .script = NyxthraFlashback_EventScript_Gym8, .hasBattle = TRUE,
        .startPlayerMove = MOVE_SURF, .startOppMove = MOVE_WATER_PULSE,
        .finishPlayerMove = MOVE_ICE_BEAM, .finishOppMove = MOVE_WATER_PULSE,
    },
    [FLASHBACK_CLIP_MARC] = {
        .map = MAP_FLASHBACK_MAGMA_HIDEOUT, .x = 16, .y = 24,
        .script = NyxthraFlashback_EventScript_Marc, .hasBattle = TRUE,
        .startPlayerMove = MOVE_SURF, .startOppMove = MOVE_TAKE_DOWN,
        .finishPlayerMove = MOVE_SURF, .finishOppMove = MOVE_EARTHQUAKE,
    },
    [FLASHBACK_CLIP_ADRIAN] = {
        .map = MAP_FLASHBACK_SEAFLOOR_CAVERN, .x = 9, .y = 45,
        .script = NyxthraFlashback_EventScript_Adrian, .hasBattle = TRUE,
        .startPlayerMove = MOVE_SURF, .startOppMove = MOVE_TAKE_DOWN,
        .finishPlayerMove = MOVE_SURF, .finishOppMove = MOVE_SLASH,
    },
    [FLASHBACK_CLIP_ANTONIA] = {
        .map = MAP_FLASHBACK_PHOEBES_ROOM, .x = 6, .y = 8,
        .script = NyxthraFlashback_EventScript_Antonia, .hasBattle = TRUE,
        .startPlayerMove = MOVE_EARTHQUAKE, .startOppMove = MOVE_SHADOW_PUNCH,
        .finishPlayerMove = MOVE_EARTHQUAKE, .finishOppMove = MOVE_SHADOW_BALL,
    },
    [FLASHBACK_CLIP_WASSILI] = {
        .map = MAP_FLASHBACK_CHAMPIONS_ROOM, .x = 6, .y = 8,
        .script = NyxthraFlashback_EventScript_Wassili, .hasBattle = TRUE,
        .startPlayerMove = MOVE_ICE_BEAM, .startOppMove = MOVE_WATER_SPOUT,
        .finishPlayerMove = MOVE_EARTHQUAKE, .finishOppMove = MOVE_SURF,
    },
    [FLASHBACK_CLIP_GROUDON] = {
        .map = MAP_FLASHBACK_TERRA_CAVE, .x = 17, .y = 25,
        .script = NyxthraFlashback_EventScript_Groudon, .hasBattle = FALSE,
    },
    [FLASHBACK_CLIP_KYOGRE] = {
        .map = MAP_FLASHBACK_MARINE_CAVE, .x = 9, .y = 25,
        .script = NyxthraFlashback_EventScript_Kyogre, .hasBattle = FALSE,
    },
    [FLASHBACK_CLIP_RAYQUAZA] = {
        .map = MAP_FLASHBACK_SKY_PILLAR, .x = 14, .y = 10,
        .script = NyxthraFlashback_EventScript_Rayquaza, .hasBattle = FALSE,
    },
    [FLASHBACK_CLIP_REGIROCK] = {
        .map = MAP_FLASHBACK_DESERT_RUINS, .x = 8, .y = 10,
        .script = NyxthraFlashback_EventScript_Regirock, .hasBattle = FALSE,
    },
    [FLASHBACK_CLIP_REGICE] = {
        .map = MAP_FLASHBACK_ISLAND_CAVE, .x = 8, .y = 10,
        .script = NyxthraFlashback_EventScript_Regice, .hasBattle = FALSE,
    },
    [FLASHBACK_CLIP_REGISTEEL] = {
        .map = MAP_FLASHBACK_ANCIENT_TOMB, .x = 8, .y = 10,
        .script = NyxthraFlashback_EventScript_Registeel, .hasBattle = FALSE,
    },
};

const struct FlashbackClipDesc *Flashback_GetClipDesc(u8 clip)
{
    if (clip >= FLASHBACK_CLIP_COUNT)
        clip = FLASHBACK_CLIP_ROUTE101;
    return &sClips[clip];
}

void Flashback_GiveClipPlayerParty(u8 clip)
{
    switch (clip)
    {
    case FLASHBACK_CLIP_GYM4:
        // Abweichung: Sumpex schon in der 4. Arena, wie gewünscht.
        GivePlayerMon(SPECIES_SWAMPERT, 28, MOVE_WATER_GUN, MOVE_MUD_SHOT, MOVE_TAKE_DOWN, MOVE_MUD_SLAP);
        break;
    case FLASHBACK_CLIP_MARC:
        GivePlayerMon(SPECIES_SWAMPERT, 40, MOVE_SURF, MOVE_MUD_SHOT, MOVE_TAKE_DOWN, MOVE_ICE_BEAM);
        break;
    case FLASHBACK_CLIP_ADRIAN:
        GivePlayerMon(SPECIES_SWAMPERT, 44, MOVE_SURF, MOVE_MUD_SHOT, MOVE_TAKE_DOWN, MOVE_ICE_BEAM);
        break;
    case FLASHBACK_CLIP_GYM8:
        GivePlayerMon(SPECIES_SWAMPERT, 46, MOVE_SURF, MOVE_EARTHQUAKE, MOVE_ICE_BEAM, MOVE_MUD_SHOT);
        break;
    case FLASHBACK_CLIP_ANTONIA:
        GivePlayerMon(SPECIES_SWAMPERT, 52, MOVE_EARTHQUAKE, MOVE_SURF, MOVE_ICE_BEAM, MOVE_MUDDY_WATER);
        break;
    case FLASHBACK_CLIP_WASSILI:
        GivePlayerMon(SPECIES_SWAMPERT, 58, MOVE_EARTHQUAKE, MOVE_SURF, MOVE_ICE_BEAM, MOVE_MUDDY_WATER);
        break;
    default:
        GivePlayerMon(SPECIES_MARSHTOMP, 16, MOVE_WATER_GUN, MOVE_MUD_SHOT, MOVE_MUD_SLAP, MOVE_TACKLE);
        break;
    }
}

void Flashback_GiveClipOpponentParty(u8 clip)
{
    ClearOppParty();
    switch (clip)
    {
    case FLASHBACK_CLIP_GYM4:
        // pret/pokeemerald sParty_Flannery1
        AddOpp(0, SPECIES_NUMEL, 24, 24, ITEM_NONE, MOVE_OVERHEAT, MOVE_TAKE_DOWN, MOVE_MAGNITUDE, MOVE_SUNNY_DAY);
        AddOpp(1, SPECIES_SLUGMA, 24, 24, ITEM_NONE, MOVE_OVERHEAT, MOVE_SMOG, MOVE_LIGHT_SCREEN, MOVE_SUNNY_DAY);
        AddOpp(2, SPECIES_CAMERUPT, 26, 30, ITEM_NONE, MOVE_OVERHEAT, MOVE_TACKLE, MOVE_SUNNY_DAY, MOVE_ATTRACT);
        AddOpp(3, SPECIES_TORKOAL, 29, 30, ITEM_WHITE_HERB, MOVE_OVERHEAT, MOVE_SUNNY_DAY, MOVE_BODY_SLAM, MOVE_ATTRACT);
        gPartiesCount[B_TRAINER_OPPONENT_A] = 4;
        break;
    case FLASHBACK_CLIP_GYM8:
        // pret/pokeemerald sParty_Juan1
        AddOpp(0, SPECIES_LUVDISC, 41, 24, ITEM_NONE, MOVE_WATER_PULSE, MOVE_ATTRACT, MOVE_SWEET_KISS, MOVE_FLAIL);
        AddOpp(1, SPECIES_WHISCASH, 41, 24, ITEM_NONE, MOVE_RAIN_DANCE, MOVE_WATER_PULSE, MOVE_AMNESIA, MOVE_EARTHQUAKE);
        AddOpp(2, SPECIES_SEALEO, 43, 24, ITEM_NONE, MOVE_ENCORE, MOVE_BODY_SLAM, MOVE_AURORA_BEAM, MOVE_WATER_PULSE);
        AddOpp(3, SPECIES_CRAWDAUNT, 43, 24, ITEM_NONE, MOVE_WATER_PULSE, MOVE_CRABHAMMER, MOVE_TAUNT, MOVE_LEER);
        AddOpp(4, SPECIES_KINGDRA, 46, 30, ITEM_CHESTO_BERRY, MOVE_WATER_PULSE, MOVE_DOUBLE_TEAM, MOVE_ICE_BEAM, MOVE_REST);
        gPartiesCount[B_TRAINER_OPPONENT_A] = 5;
        break;
    case FLASHBACK_CLIP_MARC:
        // pret/pokeemerald Maxie (Magma Hideout)
        AddOpp(0, SPECIES_MIGHTYENA, 37, 24, ITEM_NONE, MOVE_ROAR, MOVE_SWAGGER, MOVE_SCARY_FACE, MOVE_TAKE_DOWN);
        AddOpp(1, SPECIES_CROBAT, 38, 24, ITEM_NONE, MOVE_BITE, MOVE_WING_ATTACK, MOVE_CONFUSE_RAY, MOVE_AIR_CUTTER);
        AddOpp(2, SPECIES_CAMERUPT, 39, 24, ITEM_NONE, MOVE_TAKE_DOWN, MOVE_AMNESIA, MOVE_ROCK_SLIDE, MOVE_EARTHQUAKE);
        gPartiesCount[B_TRAINER_OPPONENT_A] = 3;
        break;
    case FLASHBACK_CLIP_ADRIAN:
        // pret/pokeemerald sParty_Archie
        AddOpp(0, SPECIES_MIGHTYENA, 41, 24, ITEM_NONE, MOVE_ROAR, MOVE_SWAGGER, MOVE_SCARY_FACE, MOVE_TAKE_DOWN);
        AddOpp(1, SPECIES_CROBAT, 41, 24, ITEM_NONE, MOVE_BITE, MOVE_WING_ATTACK, MOVE_CONFUSE_RAY, MOVE_AIR_CUTTER);
        AddOpp(2, SPECIES_SHARPEDO, 43, 24, ITEM_NONE, MOVE_SCREECH, MOVE_SLASH, MOVE_TAUNT, MOVE_SWAGGER);
        gPartiesCount[B_TRAINER_OPPONENT_A] = 3;
        break;
    case FLASHBACK_CLIP_ANTONIA:
        // pret/pokeemerald sParty_Phoebe
        AddOpp(0, SPECIES_DUSCLOPS, 48, 30, ITEM_NONE, MOVE_SHADOW_PUNCH, MOVE_CONFUSE_RAY, MOVE_CURSE, MOVE_PROTECT);
        AddOpp(1, SPECIES_BANETTE, 49, 30, ITEM_NONE, MOVE_SHADOW_BALL, MOVE_GRUDGE, MOVE_WILL_O_WISP, MOVE_FEINT_ATTACK);
        AddOpp(2, SPECIES_SABLEYE, 50, 30, ITEM_NONE, MOVE_SHADOW_BALL, MOVE_DOUBLE_TEAM, MOVE_NIGHT_SHADE, MOVE_FEINT_ATTACK);
        AddOpp(3, SPECIES_BANETTE, 49, 30, ITEM_NONE, MOVE_SHADOW_BALL, MOVE_PSYCHIC, MOVE_THUNDERBOLT, MOVE_FACADE);
        AddOpp(4, SPECIES_DUSCLOPS, 51, 31, ITEM_SITRUS_BERRY, MOVE_SHADOW_BALL, MOVE_ICE_BEAM, MOVE_ROCK_SLIDE, MOVE_EARTHQUAKE);
        gPartiesCount[B_TRAINER_OPPONENT_A] = 5;
        break;
    case FLASHBACK_CLIP_WASSILI:
        // pret/pokeemerald sParty_Wallace (Champ, nicht 8. Arena)
        AddOpp(0, SPECIES_WAILORD, 57, 31, ITEM_NONE, MOVE_RAIN_DANCE, MOVE_WATER_SPOUT, MOVE_DOUBLE_EDGE, MOVE_BLIZZARD);
        AddOpp(1, SPECIES_TENTACRUEL, 55, 31, ITEM_NONE, MOVE_TOXIC, MOVE_HYDRO_PUMP, MOVE_SLUDGE_BOMB, MOVE_ICE_BEAM);
        AddOpp(2, SPECIES_LUDICOLO, 56, 31, ITEM_NONE, MOVE_GIGA_DRAIN, MOVE_SURF, MOVE_LEECH_SEED, MOVE_DOUBLE_TEAM);
        AddOpp(3, SPECIES_WHISCASH, 56, 31, ITEM_NONE, MOVE_EARTHQUAKE, MOVE_SURF, MOVE_AMNESIA, MOVE_HYPER_BEAM);
        AddOpp(4, SPECIES_GYARADOS, 56, 31, ITEM_NONE, MOVE_DRAGON_DANCE, MOVE_EARTHQUAKE, MOVE_HYPER_BEAM, MOVE_SURF);
        AddOpp(5, SPECIES_MILOTIC, 58, 31, ITEM_SITRUS_BERRY, MOVE_RECOVER, MOVE_SURF, MOVE_ICE_BEAM, MOVE_TOXIC);
        gPartiesCount[B_TRAINER_OPPONENT_A] = 6;
        break;
    default:
        // Felizia, originales Smaragd-Team
        AddOpp(0, SPECIES_GEODUDE, 12, 12, ITEM_NONE, MOVE_TACKLE, MOVE_DEFENSE_CURL, MOVE_ROCK_THROW, MOVE_ROCK_TOMB);
        AddOpp(1, SPECIES_GEODUDE, 12, 12, ITEM_NONE, MOVE_TACKLE, MOVE_DEFENSE_CURL, MOVE_ROCK_THROW, MOVE_ROCK_TOMB);
        AddOpp(2, SPECIES_NOSEPASS, 15, 24, ITEM_ORAN_BERRY, MOVE_BLOCK, MOVE_HARDEN, MOVE_TACKLE, MOVE_ROCK_TOMB);
        gPartiesCount[B_TRAINER_OPPONENT_A] = 3;
        break;
    }
}
