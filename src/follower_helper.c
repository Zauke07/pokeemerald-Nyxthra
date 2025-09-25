#include "global.h"
#include "data.h"
#include "event_scripts.h"
#include "follower_helper.h"
#include "overworld.h"
#include "rtc.h"
#include "constants/battle.h"
#include "constants/followers.h"
#include "constants/metatile_behaviors.h"
#include "constants/pokemon.h"
#include "constants/region_map_sections.h"
#include "constants/songs.h"
#include "constants/weather.h"

#define TYPE_NOT_TYPE1 NUMBER_OF_MON_TYPES

// difficult conditional messages follow
static const u8 sCondMsg00[] = _("{STR_VAR_1} tanzt fröhlich.");
static const u8 sCondMsg01[] = _("{STR_VAR_1} tanzt wunderschön.");
static const u8* const sCelebiTexts[] = {sCondMsg00, sCondMsg01, NULL};

static const u8 sCondMsg02[] = _("{STR_VAR_1} spuckt Feuer und ruft laut.");
static const u8 sCondMsg03[] = _("{STR_VAR_1} erzeugt energisch\nFeuer!");
static const u8 sCondMsg04[] = _("{STR_VAR_1} spuckt Flammen!");
static const u8 sCondMsg05[] = _("{STR_VAR_1} atmet heftig\nFeuer!");
static const u8* const sFireTexts[] = {sCondMsg02, sCondMsg03, sCondMsg04, sCondMsg05, NULL};

static const u8 sCondMsg06[] = _("{STR_VAR_1} starrt direkt zur\nPokémon-LIGA.");
static const u8 sCondMsg07[] = _("Dein Pokémon starrt gespannt auf\nden Berggipfel.");
static const u8 sCondMsg08[] = _("Schnüffel schnüffel, irgendwas riecht gut!");
static const u8 sCondMsg09[] = _("Dein Pokémon schaut sich\nunruhig die Regale an.");
static const u8 sCondMsg10[] = _("{STR_VAR_1} starrt intensiv auf\ndie Regale.");
static const u8* const sShopTexts[] = {sCondMsg09, sCondMsg10, NULL};

static const u8 sCondMsg11[] = _("{STR_VAR_1} fokussiert sich mit\neinem scharfen Blick!");
static const u8 sCondMsg12[] = _("{STR_VAR_1} interessiert sich sehr\nfür die Fahrräder.");
static const u8 sCondMsg13[] = _("{STR_VAR_1} möchte gerne die\nMaschinen anfassen!");
static const u8 sCondMsg14[] = _("{STR_VAR_1} wiegt sich mit dem\nSchaukeln des Boots.");
static const u8 sCondMsg15[] = _("{STR_VAR_1} tanzt im Rhythmus\ndes Schiffes.");
static const u8 sCondMsg16[] = _("{STR_VAR_1} will das Boot noch\nnicht verlassen!");
static const u8* const sBoatTexts[] = {sCondMsg14, sCondMsg15, sCondMsg16, NULL};

static const u8 sCondMsg17[] = _("{STR_VAR_1} lauscht dem Geräusch\nder Maschinen.");
static const u8* const sMachineTexts[] = {sCondMsg13, sCondMsg17, NULL};

static const u8 sCondMsg18[] = _("Waah! Dein Pokémon hat plötzlich\nmit Wasser gespritzt!");
static const u8 sCondMsg19[] = _("Dein Pokémon wirbelt Sand in die Luft!");
static const u8 sCondMsg20[] = _("{STR_VAR_1} spielt herum und\nzupft an Grashalmen.");
static const u8 sCondMsg21[] = _("Dein Pokémon schaut sich glücklich\ndeine Fußspuren an!");
static const u8 sCondMsg22[] = _("{STR_VAR_1} wirkt nervös und\netwas klaustrophobisch.");
static const u8 sCondMsg23[] = _("{STR_VAR_1} ist vorsichtig wegen des\nengen Raumes!");
static const u8* const sElevatorTexts[] = {sCondMsg22, sCondMsg23, NULL};

static const u8 sCondMsg24[] = _("Ein kalter Wind weht plötzlich vorbei!");
static const u8 sCondMsg25[] = _("Dein Pokémon ist fast ausgerutscht!");
static const u8 sCondMsg26[] = _("Dein Pokémon scheint überrascht,\nEis zu berühren.");
static const u8* const sColdTexts[] = {sCondMsg24, sCondMsg25, sCondMsg26, NULL};

static const u8 sCondMsg27[] = _("Dein Pokémon hat ein Blütenblatt\nim Gesicht!");
static const u8 sCondMsg28[] = _("{STR_VAR_1} knurrt leise.");
static const u8 sCondMsg29[] = _("{STR_VAR_1} zittert vor Angst.");
static const u8 sCondMsg30[] = _("{STR_VAR_1} wirkt irgendwie traurig…");
static const u8* const sFearTexts[] = {sCondMsg29, sCondMsg30, NULL};

static const u8 sCondMsg31[] = _("{STR_VAR_1} sucht Schutz im Gras\nvor dem Regen.");
static const u8 sCondMsg32[] = _("{STR_VAR_1} scheint sehr kalt zu sein.");
static const u8 sCondMsg33[] = _("{STR_VAR_1} starrt aufs Meer hinaus.");
static const u8 sCondMsg34[] = _("Dein Pokémon starrt fasziniert aufs Meer!");
static const u8 sCondMsg35[] = _("{STR_VAR_1} beobachtet das\naufgewühlte Meer.");
static const u8* const sSeaTexts[] = {sCondMsg33, sCondMsg34, sCondMsg35, NULL};

static const u8 sCondMsg36[] = _("{STR_VAR_1} lauscht dem\nWasserfallrauschen.");
static const u8 sCondMsg37[] = _("{STR_VAR_1} freut sich über den Regen!");
static const u8 sCondMsg38[] = _("{STR_VAR_1} schaut sein Spiegelbild\nim Wasser an.");
static const u8 sCondMsg39[] = _("{STR_VAR_1} entspannt sich beim\nGeräusch raschelnder Blätter…");
static const u8 sCondMsg40[] = _("{STR_VAR_1} nagt am Eis.");
static const u8 sCondMsg41[] = _("{STR_VAR_1} berührt das Eis.");
static const u8* const sIceTexts[] = {sCondMsg26, sCondMsg40, sCondMsg41, NULL};

static const u8 sCondMsg42[] = _("{STR_VAR_1}’s Verbrennung sieht\nschmerzhaft aus!");
static const u8 sCondMsg43[] = _("{STR_VAR_1} freut sich über die\nfrische Luft!");
static const u8 sCondMsg44[] = _("{STR_VAR_1} blickt nach oben\nin den Himmel.");
static const u8* const sDayTexts[] = {sCondMsg43, sCondMsg44, NULL};

static const u8 sCondMsg45[] = _("Dein Pokémon schaut verzaubert\nin den Nachthimmel!");
static const u8 sCondMsg46[] = _("Dein Pokémon blickt fröhlich zum\nsternenklaren Himmel!");
static const u8* const sNightTexts[] = {sCondMsg45, sCondMsg46, NULL};
static const u8 sCondMsg50[] = _("{STR_VAR_1} is disturbed by the\nabnormal weather!");

// See the struct definition in follower_helper.h for more info
const struct FollowerMsgInfoExtended gFollowerConditionalMessages[COND_MSG_COUNT] =
{
    [COND_MSG_CELEBI] =
    {
        .text = (u8*)sCelebiTexts,
        .textSpread = 1,
        .script = EventScript_FollowerDance,
        .emotion = FOLLOWER_EMOTION_NEUTRAL,
        .conditions =
        {
            MATCH_SPECIES(SPECIES_CELEBI),
        },
    },
    [COND_MSG_FIRE] =
    {
        .text = (u8*)sFireTexts,
        .textSpread = 1,
        .emotion = FOLLOWER_EMOTION_NEUTRAL,
        .conditions =
        {
            MATCH_TYPES(TYPE_FIRE, TYPE_FIRE),
        },
    },
    [COND_MSG_EVER_GRANDE] =
    {
        .text = sCondMsg06,
        .script = EventScript_FollowerFaceUp,
        .emotion = FOLLOWER_EMOTION_HAPPY,
        .conditions =
        {
            MATCH_MAP(MAP_EVER_GRANDE_CITY),
        },
    },
    [COND_MSG_ROUTE_112] =
    {
        .text = sCondMsg07,
        .emotion = FOLLOWER_EMOTION_HAPPY,
        .conditions =
        {
            MATCH_MAP(MAP_ROUTE112),
        },
    },
    [COND_MSG_DAY_CARE] =
    {
        .text = sCondMsg08,
        .script = EventScript_FollowerNostalgia,
        .emotion = FOLLOWER_EMOTION_NEUTRAL,
        .conditions =
        {
            MATCH_MAP(MAP_ROUTE117_POKEMON_DAY_CARE)
        },
    },
    [COND_MSG_MART] =
    {
        .text = (u8*)sShopTexts,
        .textSpread = 1,
        .script = EventScript_FollowerLookAround,
        .emotion = FOLLOWER_EMOTION_NEUTRAL,
        .conditions =
        {
            MATCH_MUSIC(MUS_POKE_MART)
        },
    },
    [COND_MSG_VICTORY_ROAD] =
    {
        .text = sCondMsg11,
        .emotion = FOLLOWER_EMOTION_PENSIVE,
        .conditions =
        {
            MATCH_MUSIC(MUS_VICTORY_ROAD)
        },
    },
    [COND_MSG_BIKE_SHOP] =
    {
        .text = sCondMsg12,
        .emotion = FOLLOWER_EMOTION_PENSIVE,
        .conditions =
        {
            MATCH_MAP(MAP_MAUVILLE_CITY_BIKE_SHOP)
        },
    },
    [COND_MSG_MACHINES] =
    {
        .text = (u8*)sMachineTexts,
        .textSpread = 1,
        .emotion = FOLLOWER_EMOTION_MUSIC,
        .orFlag = 1, // match any of these maps
        .conditions =
        {
            MATCH_MAP(MAP_NEW_MAUVILLE_INSIDE),
            MATCH_MAP(MAP_SLATEPORT_CITY_STERNS_SHIPYARD_1F),
            MATCH_MAP(MAP_SLATEPORT_CITY_STERNS_SHIPYARD_2F),
        },
    },
    [COND_MSG_SAILING] =
    {
        .text = (u8*)sBoatTexts,
        .textSpread = 1,
        .emotion = FOLLOWER_EMOTION_MUSIC,
        .script = EventScript_FollowerLookAround,
        .conditions =
        {
            MATCH_MUSIC(MUS_SAILING),
        },
    },
    [COND_MSG_PUDDLE] =
    {
        .text = sCondMsg18,
        .script = EventScript_FollowerHopping,
        .emotion = FOLLOWER_EMOTION_MUSIC,
        .conditions =
        {
            MATCH_ON_MB(MB_SHALLOW_WATER, MB_PUDDLE),
        },
    },
    [COND_MSG_SAND] =
    {
        .text = sCondMsg19,
        .emotion = FOLLOWER_EMOTION_MUSIC,
        .conditions =
        {
            MATCH_ON_MB(MB_SAND, MB_DEEP_SAND),
        },
    },
    [COND_MSG_GRASS] =
    {
        .text = sCondMsg20,
        .emotion = FOLLOWER_EMOTION_MUSIC,
        .conditions =
        {
            MATCH_ON_MB(MB_TALL_GRASS, MB_LONG_GRASS),
        },
    },
    [COND_MSG_FOOTPRINTS] =
    {
        .text = sCondMsg21,
        .emotion = FOLLOWER_EMOTION_MUSIC,
        .conditions =
        {
            MATCH_ON_MB(MB_SAND, MB_FOOTPRINTS),
        },
    },
    [COND_MSG_ELEVATOR] =
    {
        .text = (u8*)sElevatorTexts,
        .textSpread = 1,
        .emotion = FOLLOWER_EMOTION_SURPRISE,
        .conditions =
        {
            MATCH_MAP(MAP_LILYCOVE_CITY_DEPARTMENT_STORE_ELEVATOR),
        },
    },
    [COND_MSG_ICE_ROOM] =
    {
        .text = (u8*)sColdTexts,
        .textSpread = 1,
        .emotion = FOLLOWER_EMOTION_SURPRISE,
        .conditions =
        {
            MATCH_MAP(MAP_SHOAL_CAVE_LOW_TIDE_ICE_ROOM),
        },
    },
    [COND_MSG_ROUTE_117] =
    {
        .text = sCondMsg27,
        .emotion = FOLLOWER_EMOTION_SURPRISE,
        .conditions =
        {
            MATCH_MAP(MAP_ROUTE117),
        },
    },
    [COND_MSG_DRAGON_GROWL] =
    {
        .text = sCondMsg28,
        .emotion = FOLLOWER_EMOTION_UPSET,
        .conditions =
        {
            MATCH_TYPES(TYPE_DRAGON, TYPE_DRAGON),
            MATCH_MAPSEC(MAPSEC_SKY_PILLAR),
        },
    },
    [COND_MSG_FEAR] =
    {
        .text = (u8*)sFearTexts,
        .textSpread = 1,
        .emotion = FOLLOWER_EMOTION_UPSET,
        .conditions =
        {
            MATCH_NOT_TYPES(TYPE_GHOST, TYPE_GHOST),
            MATCH_MAPSEC(MAPSEC_MT_PYRE),
            MATCH_MUSIC(MUS_MT_PYRE),
        },
    },
    [COND_MSG_FIRE_RAIN] =
    {
        .text = sCondMsg31,
        .emotion = FOLLOWER_EMOTION_UPSET,
        .conditions =
        {
            MATCH_TYPES(TYPE_FIRE, TYPE_FIRE),
            MATCH_WEATHER(WEATHER_RAIN, WEATHER_RAIN_THUNDERSTORM),
        },
    },
    [COND_MSG_FROZEN] =
    {
        .text = sCondMsg32,
        .emotion = FOLLOWER_EMOTION_UPSET,
        .conditions =
        {
           MATCH_STATUS(STATUS1_FREEZE),
        },
    },
    [COND_MSG_SEASIDE] =
    {
        .text = (u8*)sSeaTexts,
        .textSpread = 1,
        .script = EventScript_FollowerFaceResult,
        .emotion = FOLLOWER_EMOTION_MUSIC,
        .conditions =
        {
            MATCH_NEAR_MB(MB_OCEAN_WATER, 5),
        },
    },
    [COND_MSG_WATERFALL] =
    {
        .text = sCondMsg36,
        .script = EventScript_FollowerFaceResult,
        .emotion = FOLLOWER_EMOTION_MUSIC,
        .conditions =
        {
            MATCH_NEAR_MB(MB_WATERFALL, 5),
        },
    },
    [COND_MSG_RAIN] =
    {
        .text = sCondMsg37,
        .emotion = FOLLOWER_EMOTION_MUSIC,
        .conditions =
        {
        MATCH_NOT_TYPES(TYPE_FIRE, TYPE_FIRE),
        MATCH_WEATHER(WEATHER_RAIN, WEATHER_RAIN_THUNDERSTORM)
    }
    },
    [COND_MSG_REFLECTION] =
    {
        .text = sCondMsg38,
        .script = EventScript_FollowerFaceResult,
        .emotion = FOLLOWER_EMOTION_PENSIVE,
        .conditions =
        {
            MATCH_NEAR_MB(MB_POND_WATER, 1),
        },
    },
    [COND_MSG_LEAVES] =
    {
        .text = sCondMsg39,
        .emotion = FOLLOWER_EMOTION_PENSIVE,
        .conditions =
        {
            MATCH_MAPSEC(MAPSEC_PETALBURG_WOODS),
        },
    },
    [COND_MSG_ICE] =
    {
        .text = (u8*)sIceTexts,
        .textSpread = 1,
        .script = EventScript_FollowerFaceResult,
        .emotion = FOLLOWER_EMOTION_PENSIVE,
        .conditions =
        {
            MATCH_NEAR_MB(MB_ICE, 1),
        },
    },
    [COND_MSG_BURN] =
    {
        .text = sCondMsg42,
        .emotion = FOLLOWER_EMOTION_SAD,
        .conditions =
        {
            MATCH_STATUS(STATUS1_BURN),
        },
    },
    [COND_MSG_DAY] =
    {
        .text = (u8*)sDayTexts,
        .textSpread = 1,
        .emotion = FOLLOWER_EMOTION_MUSIC,
        .conditions =
        {
            MATCH_TIME_OF_DAY(TIME_DAY),
        },
    },
    [COND_MSG_NIGHT] =
    {
        .text = (u8*)sNightTexts,
        .textSpread = 1,
        .emotion = FOLLOWER_EMOTION_MUSIC,
        .conditions =
        {
            MATCH_TIME_OF_DAY(TIME_NIGHT),
        },
    },
    [COND_MSG_ABNORMAL_WEATHER] =
    {
        .text = sCondMsg50,
        .emotion = FOLLOWER_EMOTION_SURPRISE,
        .conditions =
        {
            MATCH_MUSIC(MUS_ABNORMAL_WEATHER),
            MATCH_NOT_SPECIES(SPECIES_KYOGRE),
            MATCH_NOT_SPECIES(SPECIES_GROUDON),
            MATCH_NOT_SPECIES(SPECIES_RAYQUAZA),
        }
    },
};

// Pool of "unconditional" follower messages
const struct FollowerMessagePool gFollowerBasicMessages[FOLLOWER_EMOTION_LENGTH] =
{
    [FOLLOWER_EMOTION_HAPPY]    = {gFollowerHappyMessages,    EventScript_FollowerGeneric, FOLLOWER_HAPPY_MESSAGE_COUNT},
    [FOLLOWER_EMOTION_NEUTRAL]  = {gFollowerNeutralMessages,  EventScript_FollowerGeneric, FOLLOWER_NEUTRAL_MESSAGE_COUNT},
    [FOLLOWER_EMOTION_SAD]      = {gFollowerSadMessages,      EventScript_FollowerGeneric, FOLLOWER_SAD_MESSAGE_COUNT},
    [FOLLOWER_EMOTION_UPSET]    = {gFollowerUpsetMessages,    EventScript_FollowerGeneric, FOLLOWER_UPSET_MESSAGE_COUNT},
    [FOLLOWER_EMOTION_ANGRY]    = {gFollowerAngryMessages,    EventScript_FollowerGeneric, FOLLOWER_ANGRY_MESSAGE_COUNT},
    [FOLLOWER_EMOTION_PENSIVE]  = {gFollowerPensiveMessages,  EventScript_FollowerGeneric, FOLLOWER_PENSIVE_MESSAGE_COUNT},
    [FOLLOWER_EMOTION_LOVE]     = {gFollowerLoveMessages,     EventScript_FollowerGeneric, FOLLOWER_LOVE_MESSAGE_COUNT},
    [FOLLOWER_EMOTION_SURPRISE] = {gFollowerSurpriseMessages, EventScript_FollowerGeneric, FOLLOWER_SURPRISE_MESSAGE_COUNT},
    [FOLLOWER_EMOTION_CURIOUS]  = {gFollowerCuriousMessages,  EventScript_FollowerGeneric, FOLLOWER_CURIOUS_MESSAGE_COUNT},
    [FOLLOWER_EMOTION_MUSIC]    = {gFollowerMusicMessages,    EventScript_FollowerGeneric, FOLLOWER_MUSIC_MESSAGE_COUNT},
    [FOLLOWER_EMOTION_POISONED] = {gFollowerPoisonedMessages, EventScript_FollowerGeneric, FOLLOWER_POISONED_MESSAGE_COUNT},
};
