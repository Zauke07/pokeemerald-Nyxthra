#include "constants/moves.h"

#if I_USE_EVO_HELD_ITEMS_FROM_BAG == TRUE
    #define EVO_HELD_ITEM_TYPE ITEM_USE_PARTY_MENU
    #define EVO_HELD_ITEM_FIELD_FUNC ItemUseOutOfBattle_EvolutionStone
#else
    #define EVO_HELD_ITEM_TYPE ITEM_USE_BAG_MENU
    #define EVO_HELD_ITEM_FIELD_FUNC ItemUseOutOfBattle_CannotUse
#endif

#define GEM_BOOST_PARAM ((I_GEM_BOOST_POWER >= GEN_6) ? 30 : 50)
#define TYPE_BOOST_PARAM ((I_TYPE_BOOST_POWER >= GEN_4) ? 20 : 10) // For non Pokémon-specific type-boosting held items.
#define POWER_ITEM_BOOST ((I_POWER_ITEM_BOOST >= GEN_7) ? 8 : 4)

#define X_ITEM_STAGES ((B_X_ITEMS_BUFF >= GEN_7) ? 2 : 1)

#define TREASURE_FACTOR ((I_SELL_VALUE_FRACTION >= GEN_9) ? 2 : 1)

// Shared Item Description entries

static const u8 sFullHealDesc[]       = _("Beseitigt alle\n"
                                          "Statusprobleme\n"
                                          "eines Pokémon.");

static const u8 sPokeDollDesc[]       = _("Ermöglicht Flucht\n"
                                          "im Kampf gegen\n"
                                          "wilde POKéMON.");

static const u8 sMaxReviveDesc[]      = _("Belebt POKéMON\n"
                                          "und füllt KP voll-\n"
                                          "ständig wieder auf.");

static const u8 sHealthFeatherDesc[]  = _("Ein item, der den \n"
                                          "KP-Basiswert eines\n"
                                          "Pokémon erhöht.");

static const u8 sMuscleFeatherDesc[]  = _("Ein item, der den \n"
                                          "Angriffs-Basiswert\n"
                                          "eines Pokémon erhöht.");

static const u8 sResistFeatherDesc[]  = _("Ein item, der den \n"
                                          "Vert.-Basiswert\n"
                                          "eines Pokémon erhöht.");

static const u8 sGeniusFeatherDesc[]  = _("Ein item, der den \n"
                                          "SP. Angr.-Basiswert\n"
                                          "eines Pokémon erhöht.");

static const u8 sCleverFeatherDesc[]  = _("Ein item, der den \n"
                                          "SP. Vert.-Basiswert\n"
                                          "eines Pokémon erhöht.");

static const u8 sSwiftFeatherDesc[]   = _("Ein item, der den \n"
                                          "Init.-Basiswert\n"
                                          "eines Pokémon erhöht.");

static const u8 sBigMushroomDesc[]    = _("Ein seltener\n"
                                          "Pilz von \n"
                                          "hohem Wert.");

static const u8 sShardsDesc[]         = _("Scherbe eines\n"
                                          "antiken Relikts\n"
                                          "von geringem Wert.");

static const u8 sRootFossilDesc[]     = _("Fossil eines ural-\n"
                                          "ten POKéMON, das in\n"
                                          "der Tiefsee lebte.");

static const u8 sFossilizedFishDesc[] = _("Ein Fossil eines\n"
                                          "alten, im Meer\n"
                                          "lebendes Pokémon.");

static const u8 sBeadMailDesc[]       = _("BRIEF mit Abbildung\n"
                                          "des POKéMON, das\n"
                                          "ihn trägt.");

static const u8 sEvolutionStoneDesc[] = _("Löst bei bestimm-\n"
                                          "ten POKéMON die\n"
                                          "Entwicklung aus.");

static const u8 sNectarDesc[]         = _("Blütennektar, der die\n"
                                          "Form bestimmter\n"
                                          "Pokémon verändert.");

static const u8 sCharizarditeDesc[]   = _("Dieser Stein löst\n"
                                          "bei Glurak die Mega\n"
                                          "Entw. im Kampf aus.");

static const u8 sMewtwoniteDesc[]     = _("Dieser Stein löst\n"
                                          "bei Mewtu die Mega\n"
                                          "Entw. im Kampf aus.");

static const u8 sSeaIncenseDesc[]     = _("Item Tragen\n"
                                          "verstärkt Wasser-\n"
                                          "Attacken.");

static const u8 sOddIncenseDesc[]     = _("Item Tragen\n"
                                          "verstärkt Psycho-\n"
                                          "Attacken.");

static const u8 sRockIncenseDesc[]    = _("Item Tragen\n"
                                          "verstärkt gestein-\n"
                                          "Attacken.");

static const u8 sFullIncenseDesc[]    = _("Item Tragen\n"
                                          "macht den träger\n"
                                          "benommen und langsam.");

static const u8 sRoseIncenseDesc[]    = _("Item Tragen\n"
                                          "verstärkt pflanz.-\n"
                                          "Attacken.");

static const u8 sLuckIncenseDesc[]    = _("Doppeltes Geld\n"
                                          "im Kampf wenn\n"
                                          "träger mit kämpft.");

static const u8 sPureIncenseDesc[]    = _("Item Tragen, reduz-\n"
                                          "iert wilde Pokémon\n"
                                          "wenn träger an 1 stelle.");

static const u8 sKingsRockDesc[]      = _("Item Tragen kann\n"
                                          "Gegner zurück-\n"
                                          "weichen lassen.");

static const u8 sFigyBerryDesc[]      = _("Item Tragen füllt\n"
                                          "im Kampf KP auf, be-\n"
                                          "wirkt evtl. Verwirr.");

static const u8 sQuestionMarksDesc[]  = _("?????");

static const u8 sKeyToRoomDesc[]      = _("Schlüssel zur Tür\n"
                                          "einer Kabine auf\n"
                                          "dem SCHIFFSWRACK.");

static const u8 sTeraShardDesc[]      = _("Diese Splitter können\n"
                                          "entstehen, wenn Tera-\n"
                                          "PKMN ohnmächtig werden.");

static const u8 sGenericMulchDesc[]   = _("Ein Dünger, der für\n"
                                          "den lokalen Boden\n"
                                          "ungeeignet ist.");

const struct Item gItemsInfo[] =
{
    [ITEM_NONE] =
    {
        .name = _("????????"),
        .price = 0,
        .description = sQuestionMarksDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

// Poké Balls

    [ITEM_POKE_BALL] =
    {
        .name = _("PokéBall"),
        .price = 200,
        .description = COMPOUND_STRING(
            "Damit fängst\n"
            "du wilde\n"
            "POKéMON."),
        .pocket = POCKET_POKE_BALLS,
        .type = ITEM_USE_BAG_MENU,
        .battleUsage = EFFECT_ITEM_THROW_BALL,
        .secondaryId = ITEM_POKE_BALL - FIRST_BALL,
    },

    [ITEM_GREAT_BALL] =
    {
        .name = _("Superball"),
        .price = 600,
        .description = COMPOUND_STRING(
            "BALL mit guter Er-\n"
            "folgsquote. Besser\n"
            "als ein POKéBALL."),
        .pocket = POCKET_POKE_BALLS,
        .type = ITEM_USE_BAG_MENU,
        .battleUsage = EFFECT_ITEM_THROW_BALL,
        .secondaryId = ITEM_GREAT_BALL - FIRST_BALL,
    },

    [ITEM_ULTRA_BALL] =
    {
        .name = _("Hyperball"),
        .price = (I_PRICE >= GEN_7) ? 800 : 1200,
        .description = COMPOUND_STRING(
            "BALL mit hoher Er-\n"
            "folgsquote. Besser\n"
            "als ein SUPERBALL."),
        .pocket = POCKET_POKE_BALLS,
        .type = ITEM_USE_BAG_MENU,
        .battleUsage = EFFECT_ITEM_THROW_BALL,
        .secondaryId = ITEM_ULTRA_BALL - FIRST_BALL,
    },

    [ITEM_MASTER_BALL] =
    {
        .name = _("Meisterball"),
        .price = 0,
        .description = COMPOUND_STRING(
            "Der beste BALL.\n"
            "Fängt das POKéMON\n"
            "garantiert."),
        .pocket = POCKET_POKE_BALLS,
        .type = ITEM_USE_BAG_MENU,
        .battleUsage = EFFECT_ITEM_THROW_BALL,
        .secondaryId = ITEM_MASTER_BALL - FIRST_BALL,
    },

    [ITEM_PREMIER_BALL] =
    {
        .name = _("Premierball"),
        .price = (I_PRICE >= GEN_7) ? 20 : 200,
        .description = COMPOUND_STRING(
            "Seltener BALL, als\n"
            "Reminiszenz an ir-\n"
            "gendein Ereignis."),
        .pocket = POCKET_POKE_BALLS,
        .type = ITEM_USE_BAG_MENU,
        .battleUsage = EFFECT_ITEM_THROW_BALL,
        .secondaryId = ITEM_PREMIER_BALL - FIRST_BALL,
    },

    [ITEM_HEAL_BALL] =
    {
        .name = _("Heilball"),
        .price = 300,
        .description = COMPOUND_STRING(
            "A remedial Ball\n"
            "that restores\n"
            "caught Pokémon."),
        .pocket = POCKET_POKE_BALLS,
        .type = ITEM_USE_BAG_MENU,
        .battleUsage = EFFECT_ITEM_THROW_BALL,
        .secondaryId = ITEM_HEAL_BALL - FIRST_BALL,
    },

    [ITEM_NET_BALL] =
    {
        .name = _("Netzball"),
        .price = 1000,
        .description = COMPOUND_STRING(
        "BALL fängt POKéMON\n"
        "des Typs WASSER\n"
        "und KÄFER besser."),
        .pocket = POCKET_POKE_BALLS,
        .type = ITEM_USE_BAG_MENU,
        .battleUsage = EFFECT_ITEM_THROW_BALL,
        .secondaryId = ITEM_NET_BALL - FIRST_BALL,
    },

    [ITEM_NEST_BALL] =
    {
        .name = _("Nestball"),
        .price = 1000,
        .description = COMPOUND_STRING(
            "BALL mit höherer\n"
            "Erfolgsquote bei\n"
            "schwachen POKéMON."),
        .pocket = POCKET_POKE_BALLS,
        .type = ITEM_USE_BAG_MENU,
        .battleUsage = EFFECT_ITEM_THROW_BALL,
        .secondaryId = ITEM_NEST_BALL - FIRST_BALL,
    },

    [ITEM_DIVE_BALL] =
    {
        .name = _("Tauchball"),
        .price = 1000,
        .description = COMPOUND_STRING(
            "BALL fängt besser\n"
            "POKéMON auf\n"
            "dem Meeresgrund."),
        .pocket = POCKET_POKE_BALLS,
        .type = ITEM_USE_BAG_MENU,
        .battleUsage = EFFECT_ITEM_THROW_BALL,
        .secondaryId = ITEM_DIVE_BALL - FIRST_BALL,
    },

    [ITEM_DUSK_BALL] =
    {
        .name = _("Finsterball"),
        .price = 1000,
        .description = COMPOUND_STRING(
            "An dunklen\n"
            "Orten ist er\n"
            "am Effektivsten."),
        .pocket = POCKET_POKE_BALLS,
        .type = ITEM_USE_BAG_MENU,
        .battleUsage = EFFECT_ITEM_THROW_BALL,
        .secondaryId = ITEM_DUSK_BALL - FIRST_BALL,
    },

    [ITEM_TIMER_BALL] =
    {
        .name = _("Timerball"),
        .price = 1000,
        .description = COMPOUND_STRING(
            "BALL wird effekti-\n"
            "ver, je länger der\n"
            "Kampf dauert."),
        .pocket = POCKET_POKE_BALLS,
        .type = ITEM_USE_BAG_MENU,
        .battleUsage = EFFECT_ITEM_THROW_BALL,
        .secondaryId = ITEM_TIMER_BALL - FIRST_BALL,
    },

    [ITEM_QUICK_BALL] =
    {
        .name = _("Flottball"),
        .price = 1000,
        .description = COMPOUND_STRING(
            "Klappt am besten\n"
            "bei beginn eines\n"
            "Kampfes."),
        .pocket = POCKET_POKE_BALLS,
        .type = ITEM_USE_BAG_MENU,
        .battleUsage = EFFECT_ITEM_THROW_BALL,
        .secondaryId = ITEM_QUICK_BALL - FIRST_BALL,
    },

    [ITEM_REPEAT_BALL] =
    {
        .name = _("Wiederball"),
        .price = 1000,
        .description = COMPOUND_STRING(
            "BALL fängt besser\n"
            "bereits gefangene\n"
            "POKéMON."),
        .pocket = POCKET_POKE_BALLS,
        .type = ITEM_USE_BAG_MENU,
        .battleUsage = EFFECT_ITEM_THROW_BALL,
        .secondaryId = ITEM_REPEAT_BALL - FIRST_BALL,
    },

    [ITEM_LUXURY_BALL] =
    {
        .name = _("Luxusball"),
        .price = (I_PRICE >= GEN_8) ? 3000 : 1000,
        .description = COMPOUND_STRING(
            "Behaglicher BALL,\n"
            "der POKéMON\n"
            "freundlicher macht."),
        .pocket = POCKET_POKE_BALLS,
        .type = ITEM_USE_BAG_MENU,
        .battleUsage = EFFECT_ITEM_THROW_BALL,
        .secondaryId = ITEM_LUXURY_BALL - FIRST_BALL,
    },

    [ITEM_LEVEL_BALL] =
    {
        .name = _("Levelball"),
        .price = (I_PRICE >= GEN_7) ? 0 : 300,
        .description = COMPOUND_STRING(
            "Perfekter Ball\n"
            "für Schwache\n"
            "Pokémon."),
        .pocket = POCKET_POKE_BALLS,
        .type = ITEM_USE_BAG_MENU,
        .battleUsage = EFFECT_ITEM_THROW_BALL,
        .secondaryId = ITEM_LEVEL_BALL - FIRST_BALL,
    },

    [ITEM_LURE_BALL] =
    {
        .name = _("Köderball"),
        .price = (I_PRICE >= GEN_7) ? 0 : 300,
        .description = COMPOUND_STRING(
            "Perfekter Ball\n"
            "für Pokémon, die\n"
            "an einer Angel hängen."),
        .pocket = POCKET_POKE_BALLS,
        .type = ITEM_USE_BAG_MENU,
        .battleUsage = EFFECT_ITEM_THROW_BALL,
        .secondaryId = ITEM_LURE_BALL - FIRST_BALL,
    },

    [ITEM_MOON_BALL] =
    {
        .name = _("Mondball"),
        .price = (I_PRICE >= GEN_7) ? 0 : 300,
        .description = COMPOUND_STRING(
            "Eignet sich gut für\n"
            "Pokémon die sich mit\n"
            "Mondstein entwickeln."),
        .pocket = POCKET_POKE_BALLS,
        .type = ITEM_USE_BAG_MENU,
        .battleUsage = EFFECT_ITEM_THROW_BALL,
        .secondaryId = ITEM_MOON_BALL - FIRST_BALL,
    },

    [ITEM_FRIEND_BALL] =
    {
        .name = _("Freundesball"),
        .price = (I_PRICE >= GEN_7) ? 0 : 300,
        .description = COMPOUND_STRING(
            "Ein Ball, der die \n"
            "Sympathie eines Pokémon\n"
            "schneller ansteigen lässt."),
        .pocket = POCKET_POKE_BALLS,
        .type = ITEM_USE_BAG_MENU,
        .battleUsage = EFFECT_ITEM_THROW_BALL,
        .secondaryId = ITEM_FRIEND_BALL - FIRST_BALL,
    },

    [ITEM_LOVE_BALL] =
    {
        .name = _("Sympaball"),
        .price = (I_PRICE >= GEN_7) ? 0 : 300,
        .description = COMPOUND_STRING(
            "Fängt anderes\n"
            "geschlecht besser \n"
            "als dein eigenes."),
        .pocket = POCKET_POKE_BALLS,
        .type = ITEM_USE_BAG_MENU,
        .battleUsage = EFFECT_ITEM_THROW_BALL,
        .secondaryId = ITEM_LOVE_BALL - FIRST_BALL,
    },

    [ITEM_FAST_BALL] =
    {
        .name = _("Turboball"),
        .price = (I_PRICE >= GEN_7) ? 0 : 300,
        .description = COMPOUND_STRING(
            "Pokémon die schnell\n"
            "weglaufen, lassen sich\n"
            "leichter fangen."),
        .pocket = POCKET_POKE_BALLS,
        .type = ITEM_USE_BAG_MENU,
        .battleUsage = EFFECT_ITEM_THROW_BALL,
        .secondaryId = ITEM_FAST_BALL - FIRST_BALL,
    },

    [ITEM_HEAVY_BALL] =
    {
        .name = _("Schwerball"),
        .price = (I_PRICE >= GEN_7) ? 0 : 300,
        .description = COMPOUND_STRING(
            "Mit diesem Ball\n"
            "fängst du schwere\n"
            "Pokémon."),
        .pocket = POCKET_POKE_BALLS,
        .type = ITEM_USE_BAG_MENU,
        .battleUsage = EFFECT_ITEM_THROW_BALL,
        .secondaryId = ITEM_HEAVY_BALL - FIRST_BALL,
    },

    [ITEM_DREAM_BALL] =
    {
        .name = _("Traumball"),
        .price = 0,
        .description = COMPOUND_STRING(
        #if B_DREAM_BALL_MODIFIER >= GEN_8
            "Ein Ball, mit dem sich \n"
            "schlafende Pokémon\n"
            "leichter fangen lassen."),
        #else
            "A Poké Ball used in\n"
            "the Entree Forest."),
        #endif
        .pocket = POCKET_POKE_BALLS,
        .type = ITEM_USE_BAG_MENU,
        .battleUsage = EFFECT_ITEM_THROW_BALL,
        .secondaryId = ITEM_DREAM_BALL - FIRST_BALL,
    },

    [ITEM_SAFARI_BALL] =
    {
        .name = _("Safariball"),
        .price = 0,
        .description = COMPOUND_STRING(
            "Ein BALL, der nur\n"
            "in der SAFARI-ZONE\n"
            "eingesetzt wird."),
        .pocket = POCKET_POKE_BALLS,
        .type = ITEM_USE_BAG_MENU,
        .battleUsage = EFFECT_ITEM_THROW_BALL,
        .secondaryId = ITEM_SAFARI_BALL - FIRST_BALL,
    },

    [ITEM_SPORT_BALL] =
    {
        .name = _("Turnierball"),
        .price = (I_PRICE < GEN_3 || I_PRICE >= GEN_9) ? 0 : 300,
        .description = COMPOUND_STRING(
            "Ein Ball, der beim\n"
            "Käferturnier der Johto-\n"
            "Region eingesetzt wird."),
        .pocket = POCKET_POKE_BALLS,
        .type = ITEM_USE_BAG_MENU,
        .battleUsage = EFFECT_ITEM_THROW_BALL,
        .secondaryId = ITEM_SPORT_BALL - FIRST_BALL,
    },

    [ITEM_PARK_BALL] =
    {
        .name = _("Parkball"),
        .price = 0,
        .description = COMPOUND_STRING(
            "Ein Spezieller Ball,\n"
            "für den Freunde Park."),
        .pocket = POCKET_POKE_BALLS,
        .type = ITEM_USE_BAG_MENU,
        .battleUsage = EFFECT_ITEM_THROW_BALL,
        .secondaryId = ITEM_PARK_BALL - FIRST_BALL,
    },

    [ITEM_BEAST_BALL] =
    {
        .name = _("Ultraball"),
        .price = 0,
        .description = COMPOUND_STRING(
            "Ein Ball designed zum\n"
            "Fangen von Ultrabestien."),
        .pocket = POCKET_POKE_BALLS,
        .type = ITEM_USE_BAG_MENU,
        .battleUsage = EFFECT_ITEM_THROW_BALL,
        .secondaryId = ITEM_BEAST_BALL - FIRST_BALL,
    },

    [ITEM_CHERISH_BALL] =
    {
        .name = _("Jubelball"),
        .price = 0,
        .description = COMPOUND_STRING(
            "Ein seltener Ball, der\n"
            "als Reminiszenz an irgendein\n"
            "Ereignis hergestellt wurde."),
        .pocket = POCKET_POKE_BALLS,
        .type = ITEM_USE_BAG_MENU,
        .battleUsage = EFFECT_ITEM_THROW_BALL,
        .secondaryId = ITEM_CHERISH_BALL - FIRST_BALL,
    },

// Medicine

    [ITEM_POTION] =
    {
        .name = _("Trank"),
        .price = (I_PRICE >= GEN_7) ? 200 : 300,
        .holdEffectParam = 20,
        .description = COMPOUND_STRING(
            "Füllt die KP eines\n"
            "POKéMON um\n"
            "20 Punkte auf."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_RESTORE_HP,
        .effect = gItemEffect_Potion,
        .flingPower = 30,
    },

    [ITEM_SUPER_POTION] =
    {
        .name = _("Super Trank"),
        .price = 700,
        .holdEffectParam = 60,
        .description = COMPOUND_STRING(
            "Füllt die KP eines\n"
            "POKéMON um\n"
        #if I_HEALTH_RECOVERY >= GEN_7
            "60 Punkte auf."),
        #else
            "50 Punkte auf."),
        #endif
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_RESTORE_HP,
        .effect = gItemEffect_SuperPotion,
        .flingPower = 30,
    },

    [ITEM_HYPER_POTION] =
    {
        .name = _("Hyper Trank"),
        .price = (I_PRICE >= GEN_2 || I_PRICE <= GEN_6) ? 1200 : 1500,
        .holdEffectParam = 120,
        .description = COMPOUND_STRING(
            "Füllt die KP eines\n"
            "POKéMON um\n"
        #if I_HEALTH_RECOVERY >= GEN_7
            "120 Punkte auf."),
        #else
            "200 Punkte auf."),
        #endif
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_RESTORE_HP,
        .effect = gItemEffect_HyperPotion,
        .flingPower = 30,
    },

    [ITEM_MAX_POTION] =
    {
        .name = _("Top-Trank"),
        .price = 2500,
        .holdEffectParam = 255,
        .description = COMPOUND_STRING(
            "Füllt die KP\n"
            "vollständig auf."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_RESTORE_HP,
        .effect = gItemEffect_MaxPotion,
        .flingPower = 30,
    },

    [ITEM_FULL_RESTORE] =
    {
        .name = _("Top-Genesung"),
        .price = 3000,
        .holdEffectParam = 255,
        .description = COMPOUND_STRING(
            "Stellt KP und\n"
            "Status eines\n"
            "POKéMON wieder her."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_HEAL_AND_CURE_STATUS,
        .effect = gItemEffect_FullRestore,
        .flingPower = 30,
    },

    [ITEM_REVIVE] =
    {
        .name = _("Beleber"),
        .price = (I_PRICE >= GEN_7) ? 2000 : 1500,
        .description = COMPOUND_STRING(
            "Belebt POKéMON\n"
            "und füllt die KP zur\n"
            "Hälfte wieder auf."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_REVIVE,
        .effect = gItemEffect_Revive,
        .flingPower = 30,
    },

    [ITEM_MAX_REVIVE] =
    {
        .name = _("Top-Beleber"),
        .price = 4000,
        .description = sMaxReviveDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_REVIVE,
        .effect = gItemEffect_MaxRevive,
        .flingPower = 30,
    },

    [ITEM_FRESH_WATER] =
    {
        .name = _("Saskia Wasser"),
        .price = 200,
        .holdEffectParam = 30,
        .description = COMPOUND_STRING(
            "Lidl lohnt sich weil,\n"
            "das Wasser die KP um\n"
        #if I_HEALTH_RECOVERY >= GEN_7
            "30 Punkte auffüllt."),
        #else
            "50 Punkte auffüllt."),
        #endif
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_RESTORE_HP,
        .effect = gItemEffect_FreshWater,
        .flingPower = 30,
    },

    [ITEM_SODA_POP] =
    {
        .name = _("Sprudel"),
        .price = 300,
        .holdEffectParam = 50,
        .description = COMPOUND_STRING(
            "Ein Mineralwasser,\n"
            "das die KP um\n"
        #if I_HEALTH_RECOVERY >= GEN_7
            "50 Punkte auffüllt."),
        #else
            "60 Punkte auffüllt."),
        #endif
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_RESTORE_HP,
        .effect = gItemEffect_SodaPop,
        .flingPower = 30,
    },

    [ITEM_LEMONADE] =
    {
        .name = _("Limonade"),
        .price = (I_PRICE >= GEN_7) ? 400 : 350,
        .holdEffectParam = 70,
#if I_HEALTH_RECOVERY >= GEN_7
        .description = COMPOUND_STRING(
            "Ein süßes Getränk,\n"
            "das die KP um 70\n"
            "Punkte auffüllt."),
#else
        .description = COMPOUND_STRING(
            "Ein süßes Getränk,\n"
            "das die KP um 80\n"
            "Punkte auffüllt."),
#endif
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_RESTORE_HP,
        .effect = gItemEffect_Lemonade,
        .flingPower = 30,
    },

    [ITEM_MOOMOO_MILK] =
    {
        .name = _("Kuhmuh-Milch"),
        .pluralName = _("Kuhmuh-Milch"),
        .price = (I_PRICE >= GEN_7) ? 600 : 500,
        .holdEffectParam = 100,
        .description = COMPOUND_STRING(
            "Vitaminreiche Milch,\n"
            "die die KP um 100\n"
            "Punkte auffüllt."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_RESTORE_HP,
        .effect = gItemEffect_MoomooMilk,
        .flingPower = 30,
    },

    [ITEM_ENERGY_POWDER] =
    {
        .name = _("Energiestaub"),
        .pluralName = _("Energiestaub"),
        .price = 500,
        .description = COMPOUND_STRING(
            "Ein bitteres Pulver,\n"
            "das die KP um\n"
        #if I_HEALTH_RECOVERY >= GEN_7
            "60 Punkte auffüllt."),
        #else
            "50 Punkte auffüllt."),
        #endif
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_RESTORE_HP,
        .effect = gItemEffect_EnergyPowder,
        .flingPower = 30,
    },

    [ITEM_ENERGY_ROOT] =
    {
        .name = _("Redbull"),
        .price = (I_PRICE >= GEN_7) ? 1200 : 800,
        .description = COMPOUND_STRING(
            "Das beste Energy getränk\n"
            "welches die KP um\n"
        #if I_HEALTH_RECOVERY >= GEN_7
            "120 Punkte auffüllt."),
        #else
            "200 Punkte auffüllt."),
        #endif
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_RESTORE_HP,
        .effect = gItemEffect_EnergyRoot,
        .flingPower = 30,
    },

    [ITEM_HEAL_POWDER] =
    {
        .name = _("Heilpuder"),
        .pluralName = _("Heilpuder"),
        .price = (I_PRICE >= GEN_7) ? 300 : 450,
        .description = COMPOUND_STRING(
            "Ein bitteres Pulver,\n"
            "das alle Statuspro-\n"
            "bleme heilt."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_CURE_STATUS,
        .effect = gItemEffect_HealPowder,
        .flingPower = 30,
    },

    [ITEM_REVIVAL_HERB] =
    {
        .name = _("Vitalkraut"),
        .price = 2800,
        .description = COMPOUND_STRING(
            "Ein bitteres Kraut,\n"
            "das besiegte\n"
            "POKéMON belebt."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_REVIVE,
        .effect = gItemEffect_RevivalHerb,
        .flingPower = 30,
    },

    [ITEM_ANTIDOTE] =
    {
        .name = _("Gegengift"),
        .price = (I_PRICE >= GEN_7) ? 200 : 100,
        .description = COMPOUND_STRING(
            "Heilt Vergiftungen\n"
            "bei Pokémon."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_CURE_STATUS,
        .effect = gItemEffect_Antidote,
        .flingPower = 30,
    },

    [ITEM_PARALYZE_HEAL] =
    {
        .name = _("Para-Heiler"),
        .price = (I_PRICE == GEN_7) ? 300 : 200,
        .description = COMPOUND_STRING(
            "Heilt Paralyse\n"
            "bei Pokémon."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_CURE_STATUS,
        .effect = gItemEffect_ParalyzeHeal,
        .flingPower = 30,
    },

    [ITEM_BURN_HEAL] =
    {
        .name = _("Feuerheiler"),
        .price = (I_PRICE == GEN_7) ? 300 : ((I_PRICE <= GEN_7) ? 250 : 200),
        .description = COMPOUND_STRING(
            "Heilt Verbrennun-\n"
            "gen bei Pokémon."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_CURE_STATUS,
        .effect = gItemEffect_BurnHeal,
        .flingPower = 30,
    },

    [ITEM_ICE_HEAL] =
    {
        .name = _("Eisheiler"),
        .price = (I_PRICE == GEN_7) ? 100 : ((I_PRICE <= GEN_7) ? 250 : 200),
        .description = COMPOUND_STRING(
            "Taut Pokémon\n"
            "wieder auf."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_CURE_STATUS,
        .effect = gItemEffect_IceHeal,
        .flingPower = 30,
    },

    [ITEM_AWAKENING] =
    {
        .name = _("iPhone Wecker"),
        .price = (I_PRICE >= GEN_2 && I_PRICE <= GEN_6) ? 250 : ((I_PRICE == GEN_7) ? 100 : 200),
        .description = COMPOUND_STRING(
            "Weckt schlafendes\n"
            "Pokémon auf."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_CURE_STATUS,
        .effect = gItemEffect_Awakening,
        .flingPower = 30,
    },

    [ITEM_FULL_HEAL] =
    {
        .name = _("Hyperheiler"),
        .price = (I_PRICE >= GEN_7) ? 400 : 600,
        .description = sFullHealDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_CURE_STATUS,
        .effect = gItemEffect_FullHeal,
        .flingPower = 30,
    },

    [ITEM_ETHER] =
    {
        .name = _("Äther"),
        .price = (I_PRICE >= GEN_2) ? 1200 : 1,
        .holdEffectParam = 10,
        .description = COMPOUND_STRING(
            "Füllt AP einer aus-\n"
            "gewählten Attacke\n"
            "um 10 Punkte auf."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU_MOVES,
        .fieldUseFunc = ItemUseOutOfBattle_PPRecovery,
        .battleUsage = EFFECT_ITEM_RESTORE_PP,
        .effect = gItemEffect_Ether,
        .flingPower = 30,
    },

    [ITEM_MAX_ETHER] =
    {
        .name = _("Top-Äther"),
        .price = (I_PRICE >= GEN_2) ? 2000 : 1,
        .holdEffectParam = 255,
        .description = COMPOUND_STRING(
            "Füllt AP einer aus-\n"
            "gewählten Attacke\n"
            "vollständig auf."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU_MOVES,
        .fieldUseFunc = ItemUseOutOfBattle_PPRecovery,
        .battleUsage = EFFECT_ITEM_RESTORE_PP,
        .effect = gItemEffect_MaxEther,
        .flingPower = 30,
    },

    [ITEM_ELIXIR] =
    {
        .name = _("Elixir"),
        .price = (I_PRICE >= GEN_2) ? 3000 : 1,
        .holdEffectParam = 10,
        .description = COMPOUND_STRING(
            "Füllt alle AP\n"
            "um 10 Punkte auf."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_PPRecovery,
        .battleUsage = EFFECT_ITEM_RESTORE_PP,
        .effect = gItemEffect_Elixir,
        .flingPower = 30,
    },

    [ITEM_MAX_ELIXIR] =
    {
        .name = _("Top-Elixir"),
        .price = (I_PRICE >= GEN_2) ? 4500 : 1,
        .holdEffectParam = 255,
        .description = COMPOUND_STRING(
            "Füllt alle AP eines\n"
            "POKéMON voll-\n"
            "ständig auf."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_PPRecovery,
        .battleUsage = EFFECT_ITEM_RESTORE_PP,
        .effect = gItemEffect_MaxElixir,
        .flingPower = 30,
    },

    [ITEM_BERRY_JUICE] =
    {
        .name = _("Beerensaft"),
        .pluralName = _("Beerensäfte"),
        .price = 100,
        .holdEffect = HOLD_EFFECT_RESTORE_HP,
        .holdEffectParam = 20,
        .description = COMPOUND_STRING(
            "Reiner Fruchtsaft,\n"
            "der die KP um\n"
            "20 Punkte auffüllt."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_RESTORE_HP,
        .effect = gItemEffect_Potion,
        .flingPower = 30,
    },

    [ITEM_SACRED_ASH] =
    {
        .name = _("Zauberasche"),
        .pluralName = _("Zauberasche"),
        .price = (I_PRICE >= GEN_7) ? 50000 : 200,
        .description = COMPOUND_STRING(
            "Belebt und\n"
            "erfrischt alle\n"
            "besiegten Pokémon."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_SacredAsh,
        .effect = gItemEffect_SacredAsh,
        .flingPower = 30,
    },

    [ITEM_SWEET_HEART] =
    {
        .name = _("Herzkonfekt"),
        .price = (I_PRICE >= GEN_7) ? 3000 : 100,
        .holdEffectParam = 20,
        .description = COMPOUND_STRING(
            "Ein süßer Schokosnack,\n"
            "der die KP um\n"
            "20 Punkte auffüllt."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_RESTORE_HP,
        .effect = gItemEffect_Potion,
        .flingPower = 30,
    },

    [ITEM_MAX_HONEY] =
    {
        .name = _("Dyna-Honig"),
        .pluralName = _("Dyna-Honig"),
        .price = 8000,
        .description = sMaxReviveDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_REVIVE,
        .effect = gItemEffect_MaxRevive,
        .flingPower = 30,
    },

// Regional Specialties

    [ITEM_PEWTER_CRUNCHIES] =
    {
        .name = _("MarmoriaKrack"),
        .pluralName = _("MarmoriaKracker"),
        .price = 250,
        .description = sFullHealDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_CURE_STATUS,
        .effect = gItemEffect_FullHeal,
        .flingPower = 30,
    },

    [ITEM_RAGE_CANDY_BAR] =
    {
        .name = _("Wutkeks"),
        .price = (I_PRICE >= GEN_7) ? 350 : 300,
        .description = sFullHealDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_CURE_STATUS,
        .effect = gItemEffect_FullHeal,
        .flingPower = 30,
    },

    [ITEM_LAVA_COOKIE] =
    {
        .name = _("Lava Kekse"),
        .price = (I_PRICE >= GEN_7) ? 350 : 200,
        .description = COMPOUND_STRING(
            "Eine regionale Spe-\n"
            "zialität. Heilt alle\n"
            "Statusprobleme."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_CURE_STATUS,
        .effect = gItemEffect_FullHeal,
        .flingPower = 30,
    },

    [ITEM_OLD_GATEAU] =
    {
        .name = _("Spezialität"),
        .pluralName = _("Spezialitäten"),
        .price = (I_PRICE >= GEN_7) ? 350 : 200,
        .description = sFullHealDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_CURE_STATUS,
        .effect = gItemEffect_FullHeal,
        .flingPower = 30,
    },

    [ITEM_CASTELIACONE] =
    {
        .name = _("Stratos-Eis"),
        .price = (I_PRICE >= GEN_7) ? 350 : 100,
        .description = sFullHealDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_CURE_STATUS,
        .effect = gItemEffect_FullHeal,
        .flingPower = 30,
    },

    [ITEM_LUMIOSE_GALETTE] =
    {
        .name = _("Illum-Galette"),
        .price = (I_PRICE >= GEN_7) ? 350 : 200,
        .description = sFullHealDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_CURE_STATUS,
        .effect = gItemEffect_FullHeal,
        .flingPower = 30,
    },

    [ITEM_SHALOUR_SABLE] =
    {
        .name = _("YantaraSablé"),
        .price = (I_PRICE >= GEN_7) ? 350 : 200,
        .description = sFullHealDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_CURE_STATUS,
        .effect = gItemEffect_FullHeal,
        .flingPower = 30,
    },

    [ITEM_BIG_MALASADA] =
    {
        .name = _("Max-Malasada"),
        .price = 350,
        .description = sFullHealDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_CURE_STATUS,
        .effect = gItemEffect_FullHeal,
        .flingPower = 30,
    },

// Vitamins

    [ITEM_HP_UP] =
    {
        .name = _("KP-Plus"),
        .price = (I_PRICE >= GEN_7) ? 10000 : 9800,
        .description = COMPOUND_STRING(
            "Hebt die KP\n"
            "eines Pokémon."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .effect = gItemEffect_HPUp,
        .flingPower = 30,
    },

    [ITEM_PROTEIN] =
    {
        .name = _("Protein"),
        .price = (I_PRICE >= GEN_7) ? 10000 : 9800,
        .description = COMPOUND_STRING(
            "Hebt den\n"
            "ANGR.-Wert\n"
            "eines Pokémon."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .effect = gItemEffect_Protein,
        .flingPower = 30,
    },

    [ITEM_IRON] =
    {
        .name = _("Eisen"),
        .price = (I_PRICE >= GEN_7) ? 10000 : 9800,
        .description = COMPOUND_STRING(
            "Hebt den\n"
            "VERT.-Wert\n"
            "eines Pokémon."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .effect = gItemEffect_Iron,
        .flingPower = 30,
    },

    [ITEM_CALCIUM] =
    {
        .name = _("Kalzium"),
        .price = (I_PRICE >= GEN_7) ? 10000 : 9800,
        .description = COMPOUND_STRING(
            "Hebt den\n"
            "SP. ANGR.-Wert\n"
            "eines Pokémon."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .effect = gItemEffect_Calcium,
        .flingPower = 30,
    },

    [ITEM_ZINC] =
    {
        .name = _("Zink"),
        .price = (I_PRICE >= GEN_7) ? 10000 : 9800,
        .description = COMPOUND_STRING(
            "Hebt den\n"
            "SP. VERT.-Wert\n"
            "eines Pokémon."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .effect = gItemEffect_Zinc,
        .flingPower = 30,
    },

    [ITEM_CARBOS] =
    {
        .name = _("Carbon"),
        .pluralName = _("Carbon"),
        .price = (I_PRICE >= GEN_7) ? 10000 : 9800,
        .description = COMPOUND_STRING(
            "Hebt den\n"
            "INIT.-Wert\n"
            "eines Pokémon."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .effect = gItemEffect_Carbos,
        .flingPower = 30,
    },

    [ITEM_PP_UP] =
    {
        .name = _("AP-Plus"),
        .price = (I_PRICE == GEN_1) ? 1 : ((I_PRICE >= GEN_7) ? 10000 : 9800),
        .description = COMPOUND_STRING(
            "Hebt die maximale\n"
            "Anzahl der AP\n"
            "einer Attacke."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_PPUp,
        .effect = gItemEffect_PPUp,
        .flingPower = 30,
    },

    [ITEM_PP_MAX] =
    {
        .name = _("Ap-Top"),
        .pluralName = _("AP-Top"),
        .price = (I_PRICE >= GEN_7) ? 10000 : 9800,
        .description = COMPOUND_STRING(
            "Maximiert die\n"
            "Anzahl der AP\n"
            "einer Attacke."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_PPUp,
        .effect = gItemEffect_PPMax,
        .flingPower = 30,
    },

// EV Feathers

    [ITEM_HEALTH_FEATHER] =
    {
        .name = _("Heilfeder"),
        .price = (I_PRICE >= GEN_7) ? 300 : 3000,
        .description = sHealthFeatherDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .effect = gItemEffect_HpFeather,
        .flingPower = 20,
    },

    [ITEM_MUSCLE_FEATHER] =
    {
        .name = _("Kraftfeder"),
        .price = (I_PRICE >= GEN_7) ? 300 : 3000,
        .description = sMuscleFeatherDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .effect = gItemEffect_AtkFeather,
        .flingPower = 20,
    },

    [ITEM_RESIST_FEATHER] =
    {
        .name = _("Abwehrfeder"),
        .price = (I_PRICE >= GEN_7) ? 300 : 3000,
        .description = sResistFeatherDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .effect = gItemEffect_DefFeather,
        .flingPower = 20,
    },

    [ITEM_GENIUS_FEATHER] =
    {
        .name = _("Geniefeder"),
        .price = (I_PRICE >= GEN_7) ? 300 : 3000,
        .description = sGeniusFeatherDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .effect = gItemEffect_SpatkFeather,
        .flingPower = 20,
    },

    [ITEM_CLEVER_FEATHER] =
    {
        .name = _("Espritfeder"),
        .price = (I_PRICE >= GEN_7) ? 300 : 3000,
        .description = sCleverFeatherDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .effect = gItemEffect_SpdefFeather,
        .flingPower = 20,
    },

    [ITEM_SWIFT_FEATHER] =
    {
        .name = _("Flinkfeder"),
        .price = (I_PRICE >= GEN_7) ? 300 : 3000,
        .description = sSwiftFeatherDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .effect = gItemEffect_SpeedFeather,
        .flingPower = 20,
    },

// Ability Modifiers

    [ITEM_ABILITY_CAPSULE] =
    {
        .name = _("Fäigk.Kapsel"),
        .price = (I_PRICE < GEN_7) ? 1000 : ((I_PRICE < GEN_9) ? 10000 : 100000),
        .holdEffectParam = 0,
        .description = COMPOUND_STRING(
            "Ändert die Fähigkeit\n"
            "eines Pokémon."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_AbilityCapsule,
    },

    [ITEM_ABILITY_PATCH] =
    {
        .name = _("Fäigk.Pflast"),
        .pluralName = _("Fäigk.Pflast"),
        .price = (I_PRICE >= GEN_9) ? 250000 : 20,
        .holdEffectParam = 0,
        .description = COMPOUND_STRING(
            "Verwandelt die Fähig-\n"
            "keit eines Pokémon in\n"
            "eine seltene Fähigkeit."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_AbilityPatch,
    },

// Mints

    [ITEM_LONELY_MINT] =
    {
        .name = _("Solo-Minze"),
        .price = (I_PRICE >= GEN_9) ? 20000 : 20,
        .description = COMPOUND_STRING(
            "Kann man riechen. Er-\n"
            "höht den Angriff, ver-\n"
            "ringert aber die Vert."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Mint,
        .secondaryId = NATURE_LONELY,
        .flingPower = 10,
    },

    [ITEM_ADAMANT_MINT] =
    {
        .name = _("Hart-Minze"),
        .price = (I_PRICE >= GEN_9) ? 20000 : 20,
        .description = COMPOUND_STRING(
            "Kann man riechen. Er-\n"
            "höht den Angr., verrin-\n"
            "gert aber die SP.Ang."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Mint,
        .secondaryId = NATURE_ADAMANT,
        .flingPower = 10,
    },

    [ITEM_NAUGHTY_MINT] =
    {
        .name = _("Frech-Minze"),
        .price = (I_PRICE >= GEN_9) ? 20000 : 20,
        .description = COMPOUND_STRING(
            "Kann man riechen. Er-\n"
            "höht den Angr., verrin-\n"
            "gert aber die SP.Vert."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Mint,
        .secondaryId = NATURE_NAUGHTY,
        .flingPower = 10,
    },

    [ITEM_BRAVE_MINT] =
    {
        .name = _("Mutig-Minze"),
        .price = (I_PRICE >= GEN_9) ? 20000 : 20,
        .description = COMPOUND_STRING(
            "Kann man riechen. Er-\n"
            "höht den Angr., verrin-\n"
            "gert aber die Init."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Mint,
        .secondaryId = NATURE_BRAVE,
        .flingPower = 10,
    },

    [ITEM_BOLD_MINT] =
    {
        .name = _("Kühn-Minze"),
        .price = (I_PRICE >= GEN_9) ? 20000 : 20,
        .description = COMPOUND_STRING(
            "Kann man riechen. Er-\n"
            "höht die Vert., verrin-\n"
            "gert aber den Angr."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Mint,
        .secondaryId = NATURE_BOLD,
        .flingPower = 10,
    },

    [ITEM_IMPISH_MINT] =
    {
        .name = _("Pfiffig-Minze"),
        .price = (I_PRICE >= GEN_9) ? 20000 : 20,
        .description = COMPOUND_STRING(
            "Kann man riechen. Er-\n"
            "höht die Vert., verrin-\n"
            "gert aber den SP. Angr."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Mint,
        .secondaryId = NATURE_IMPISH,
        .flingPower = 10,
    },

    [ITEM_LAX_MINT] =
    {
        .name = _("Lasch-Minze"),
        .price = (I_PRICE >= GEN_9) ? 20000 : 20,
        .description = COMPOUND_STRING(
            "Kann man riechen. Er-\n"
            "höht die Vert., verrin-\n"
            "gert aber die SP. Vert."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Mint,
        .secondaryId = NATURE_LAX,
        .flingPower = 10,
    },

    [ITEM_RELAXED_MINT] =
    {
        .name = _("Locker-Minze"),
        .price = (I_PRICE >= GEN_9) ? 20000 : 20,
        .description = COMPOUND_STRING(
            "Kann man riechen. Er-\n"
            "höht die Vert., verrin-\n"
            "gert aber die Init."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Mint,
        .secondaryId = NATURE_RELAXED,
        .flingPower = 10,
    },

    [ITEM_MODEST_MINT] =
    {
        .name = _("Mäßig-Minze"),
        .price = (I_PRICE >= GEN_9) ? 20000 : 20,
        .description = COMPOUND_STRING(
            "Kann man riechen. Er-\n"
            "höht die Angr., verrin-\n"
            "gert aber den Angr."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Mint,
        .secondaryId = NATURE_MODEST,
        .flingPower = 10,
    },

    [ITEM_MILD_MINT] =
    {
        .name = _("Mild-Minze"),
        .price = (I_PRICE >= GEN_9) ? 20000 : 20,
        .description = COMPOUND_STRING(
            "Kann man riechen. Er-\n"
            "höht die Angr., verrin-\n"
            "gert aber die Vert."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Mint,
        .secondaryId = NATURE_MILD,
        .flingPower = 10,
    },

    [ITEM_RASH_MINT] =
    {
        .name = _("Hitzig-Minze"),
        .price = (I_PRICE >= GEN_9) ? 20000 : 20,
        .description = COMPOUND_STRING(
            "Kann man riechen. Er-\n"
            "höht die SP. Angr., ver-\n"
            "ringert aber die SP.Vert."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Mint,
        .secondaryId = NATURE_RASH,
        .flingPower = 10,
    },

    [ITEM_QUIET_MINT] =
    {
        .name = _("Ruhig-Minze"),
        .price = (I_PRICE >= GEN_9) ? 20000 : 20,
        .description = COMPOUND_STRING(
            "Kann man riechen. Er-\n"
            "höht die SP. Angr., ver-\n"
            "ringert aber die Init."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Mint,
        .secondaryId = NATURE_QUIET,
        .flingPower = 10,
    },

    [ITEM_CALM_MINT] =
    {
        .name = _("Still-Minze"),
        .price = (I_PRICE >= GEN_9) ? 20000 : 20,
        .description = COMPOUND_STRING(
            "Kann man riechen. Er-\n"
            "höht die SP. Vert., ver-\n"
            "ringert aber den Angr."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Mint,
        .secondaryId = NATURE_CALM,
        .flingPower = 10,
    },

    [ITEM_GENTLE_MINT] =
    {
        .name = _("Zart-Minze"),
        .price = (I_PRICE >= GEN_9) ? 20000 : 20,
        .description = COMPOUND_STRING(
            "Kann man riechen. Er-\n"
            "höht die SP. Vert., ver-\n"
            "ringert aber den Vert."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Mint,
        .secondaryId = NATURE_GENTLE,
        .flingPower = 10,
    },

    [ITEM_CAREFUL_MINT] =
    {
        .name = _("Sacht-Minze"),
        .price = (I_PRICE >= GEN_9) ? 20000 : 20,
        .description = COMPOUND_STRING(
            "Kann man riechen. Er-\n"
            "höht die SP. Vert., ver-\n"
            "ringert aber den SP.Angr."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Mint,
        .secondaryId = NATURE_CAREFUL,
        .flingPower = 10,
    },

    [ITEM_SASSY_MINT] =
    {
        .name = _("Forsch-Minze"),
        .price = (I_PRICE >= GEN_9) ? 20000 : 20,
        .description = COMPOUND_STRING(
            "Kann man riechen. Er-\n"
            "höht die SP. Vert., ver-\n"
            "ringert aber die Init."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Mint,
        .secondaryId = NATURE_SASSY,
        .flingPower = 10,
    },

    [ITEM_TIMID_MINT] =
    {
        .name = _("Scheu-Minze"),
        .price = (I_PRICE >= GEN_9) ? 20000 : 20,
        .description = COMPOUND_STRING(
            "Kann man riechen. Er-\n"
            "höht die Init, ver-\n"
            "ringert aber den Angr."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Mint,
        .secondaryId = NATURE_TIMID,
        .flingPower = 10,
    },

    [ITEM_HASTY_MINT] =
    {
        .name = _("Hastig-Minze"),
        .price = (I_PRICE >= GEN_9) ? 20000 : 20,
        .description = COMPOUND_STRING(
            "Kann man riechen. Er-\n"
            "höht die Init, ver-\n"
            "ringert aber die Vert."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Mint,
        .secondaryId = NATURE_HASTY,
        .flingPower = 10,
    },

    [ITEM_JOLLY_MINT] =
    {
        .name = _("Froh-Minze"),
        .price = (I_PRICE >= GEN_9) ? 20000 : 20,
        .description = COMPOUND_STRING(
            "Kann man riechen. Er-\n"
            "höht die Init, ver-\n"
            "ringert aber den Sp.Angr."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Mint,
        .secondaryId = NATURE_JOLLY,
        .flingPower = 10,
    },

    [ITEM_NAIVE_MINT] =
    {
        .name = _("Naiv Minze"),
        .price = (I_PRICE >= GEN_9) ? 20000 : 20,
        .description = COMPOUND_STRING(
            "Kann man riechen. Er-\n"
            "höht die Init, ver-\n"
            "ringert aber die Sp.Vert."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Mint,
        .secondaryId = NATURE_NAIVE,
        .flingPower = 10,
    },

    [ITEM_SERIOUS_MINT] =
    {
        .name = _("Ernst-Minze"),
        .price = (I_PRICE >= GEN_9) ? 20000 : 20,
        .description = COMPOUND_STRING(
            "Kann man riechen. Stei-\n"
            "gert alle Werte\n"
            "gleichmäßig."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Mint,
        .secondaryId = NATURE_SERIOUS,
        .flingPower = 10,
    },

// Candy

    [ITEM_RARE_CANDY] =
    {
        .name = _("Sonderbonbon"),
        .pluralName = _("Sonderbonbons"),
        .price = (I_PRICE >= GEN_7) ? 10000 : 4800,
        .description = COMPOUND_STRING(
            "Hebt den Level\n"
            "eines POKéMON\n"
            "um eins an."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_RareCandy,
        .effect = gItemEffect_RareCandy,
        .flingPower = 30,
    },

    [ITEM_EXP_CANDY_XS] =
    {
        .name = _("EP-Bonbon XS"),
        .pluralName = _("EP-Bonbons XS"),
        .price = 20,
        .holdEffectParam = EXP_100,
        .description = COMPOUND_STRING(
            "Gibt eine sehr kleine\n"
            "Menge an EP. zu einem\n"
            "einzelnen Pokémon."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_RareCandy,
        .effect = gItemEffect_RareCandy,
        .flingPower = 30,
    },

    [ITEM_EXP_CANDY_S] =
    {
        .name = _("EP-Bonbon S"),
        .pluralName = _("EP-Bonbons S"),
        .price = 240,
        .holdEffectParam = EXP_800,
        .description = COMPOUND_STRING(
            "Gibt eine kleine\n"
            "Menge an EP. zu einem\n"
            "einzelnen Pokémon."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_RareCandy,
        .effect = gItemEffect_RareCandy,
        .flingPower = 30,
    },

    [ITEM_EXP_CANDY_M] =
    {
        .name = _("EP-Bonbon M"),
        .pluralName = _("EP-Bonbons M"),
        .price = 1000,
        .holdEffectParam = EXP_3000,
        .description = COMPOUND_STRING(
            "Gibt eine moderate\n"
            "Menge an EP. zu einem\n"
            "einzelnen Pokémon."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_RareCandy,
        .effect = gItemEffect_RareCandy,
        .flingPower = 30,
    },

    [ITEM_EXP_CANDY_L] =
    {
        .name = _("EP-Bonbon L"),
        .pluralName = _("EP-Bonbons L"),
        .price = 3000,
        .holdEffectParam = EXP_10000,
        .description = COMPOUND_STRING(
            "Gibt eine große\n"
            "Menge an EP. zu einem\n"
            "einzelnen Pokémon."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_RareCandy,
        .effect = gItemEffect_RareCandy,
        .flingPower = 30,
    },

    [ITEM_EXP_CANDY_XL] =
    {
        .name = _("EP-Bonbon XL"),
        .pluralName = _("EP-Bonbons XL"),
        .price = 10000,
        .holdEffectParam = EXP_30000,
        .description = COMPOUND_STRING(
            "Gibt eine sehr große\n"
            "Menge an EP. zu einem\n"
            "einzelnen Pokémon."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_RareCandy,
        .effect = gItemEffect_RareCandy,
        .flingPower = 30,
    },

    [ITEM_DYNAMAX_CANDY] =
    {
        .name = _("DynamaxBonbon"),
        .pluralName = _("DynamaxBonbons"),
        .price = 0,
        .description = COMPOUND_STRING(
            "Erhöht das Dynamax-\n"
            "Level eines einzelnen\n"
            "Pokémon um eins."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_DynamaxCandy,
        .flingPower = 30,
    },

// Medicinal Flutes

    [ITEM_BLUE_FLUTE] =
    {
        .name = _("Blaue Flöte"),
        .price = (I_PRICE >= GEN_7) ? 20 : 100,
        .description = COMPOUND_STRING(
            "Eine gläserne Flöte,\n"
            "die schlafende\n"
            "POKéMON aufweckt."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_CURE_STATUS,
        .effect = gItemEffect_Awakening,
        .flingPower = 30,
    },

    [ITEM_YELLOW_FLUTE] =
    {
        .name = _("Gelbe Flöte"),
        .price = (I_PRICE >= GEN_7) ? 20 : 300,
        .description = COMPOUND_STRING(
            "Eine gläserne Flöte,\n"
            "die verwirrte\n"
            "POKéMON heilt."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .battleUsage = EFFECT_ITEM_CURE_STATUS,
        .effect = gItemEffect_YellowFlute,
        .flingPower = 30,
    },

    [ITEM_RED_FLUTE] =
    {
        .name = _("Rote Flöte"),
        .price = (I_PRICE >= GEN_7) ? 20 : 200,
        .description = COMPOUND_STRING(
            "Eine gläserne Flöte,\n"
            "die POKéMON von\n"
            "Anziehung heilt."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .battleUsage = EFFECT_ITEM_CURE_STATUS,
        .effect = gItemEffect_RedFlute,
        .flingPower = 30,
    },

// Encounter-modifying Flutes

    [ITEM_BLACK_FLUTE] =
    {
        .name = _("SchwarzFlöte"),
        .price = (I_PRICE >= GEN_7) ? 20 : 400,
        .holdEffectParam = 50,
        .description = COMPOUND_STRING(
            "Eine gläserne Flöte,\n"
            "die wilde\n"
            "POKéMON abhält."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_BlackWhiteFlute,
        .flingPower = 30,
    },

    [ITEM_WHITE_FLUTE] =
    {
        .name = _("Weiße Flöte"),
        .price = (I_PRICE >= GEN_7) ? 20 : 500,
        .holdEffectParam = 150,
        .description = COMPOUND_STRING(
            "Eine gläserne Flöte,\n"
            "die wilde\n"
            "POKéMON anzieht."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_BlackWhiteFlute,
        .flingPower = 30,
    },

// Encounter Modifiers

    [ITEM_REPEL] =
    {
        .name = _("Schutz"),
        .price = (I_PRICE >= GEN_7) ? 400 : 350,
        .holdEffectParam = 100,
        .description = COMPOUND_STRING(
            "Hält 100 Schritte\n"
            "lang schwache,\n"
            "wilde POKéMON ab."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Repel,
        .flingPower = 30,
    },

    [ITEM_SUPER_REPEL] =
    {
        .name = _("Superschutz"),
        .price = (I_PRICE >= GEN_7) ? 700 : 500,
        .holdEffectParam = 200,
        .description = COMPOUND_STRING(
            "Hält 200 Schritte\n"
            "lang schwache,\n"
            "wilde POKéMON ab."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Repel,
        .flingPower = 30,
    },

    [ITEM_MAX_REPEL] =
    {
        .name = _("Top-Schutz"),
        .price = (I_PRICE >= GEN_7) ? 900 : 700,
        .holdEffectParam = 250,
        .description = COMPOUND_STRING(
            "Hält 250 Schritte\n"
            "lang schwache,\n"
            "wilde POKéMON ab."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Repel,
        .flingPower = 30,
    },

    [ITEM_LURE] =
    {
        .name = _("Lockparfüm"),
        .price = 400,
        .holdEffectParam = 100,
        .description = COMPOUND_STRING(
            "Erhöht die Wahrschein-\n"
            "lichkeit, dass Pokémon\n"
            "100 Schritte lang ersch."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Lure,
        .secondaryId = 0,
        .flingPower = 30,
    },

    [ITEM_SUPER_LURE] =
    {
        .name = _("SuperLockparf"),
        .price = 700,
        .holdEffectParam = 200,
        .description = COMPOUND_STRING(
            "Erhöht die Wahrschein-\n"
            "lichkeit, dass Pokémon\n"
            "200 Schritte lang ersch."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Lure,
        .secondaryId = 0,
        .flingPower = 30,
    },

    [ITEM_MAX_LURE] =
    {
        .name = _("Top-Lockparf"),
        .price = 900,
        .holdEffectParam = 250,
        .description = COMPOUND_STRING(
            "Erhöht die Wahrschein-\n"
            "lichkeit, dass Pokémon\n"
            "250 Schritte lang ersch."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Lure,
        .secondaryId = 0,
        .flingPower = 30,
    },

    [ITEM_ESCAPE_ROPE] =
    {
        .name = _("Fluchtseil"),
        .description = COMPOUND_STRING(
            "Ermöglicht die\n"
            "Flucht aus Höhlen\n"
            "oder Ähnlichem."),
        #if I_KEY_ESCAPE_ROPE >= GEN_8
            .price = 0,
            .importance = 1,
            .pocket = POCKET_KEY_ITEMS,
        #else
            .price = (I_PRICE >= GEN_7) ? 1000 : 550,
            .pocket = POCKET_ITEMS,
        #endif
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_EscapeRope,
        .flingPower = 30,
    },

// X Items

    [ITEM_X_ATTACK] =
    {
        .name = _("X-Angriff"),
        .price = (I_PRICE >= GEN_7) ? 1000 : 500,
        .holdEffectParam = X_ITEM_STAGES,
        .description = COMPOUND_STRING(
        #if B_X_ITEMS_BUFF >= GEN_7
            "Hebt den\n"
            "Angr.-Wert\n"
            "für einen Kampf."),
        #else
            "Hebt den\n"
            "ANGR.-Wert\n"
            "für einen Kampf."),
        #endif
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .battleUsage = EFFECT_ITEM_INCREASE_STAT,
        .effect = gItemEffect_XAttack,
        .flingPower = 30,
    },

    [ITEM_X_DEFENSE] =
    {
        .name = _("X-Abwehr"),
        .price = (I_PRICE >= GEN_7) ? 2000 : 550,
        .holdEffectParam = X_ITEM_STAGES,
        .description = COMPOUND_STRING(
        #if B_X_ITEMS_BUFF >= GEN_7
            "Hebt den\n"
            "Vert.-Wert\n"
            "für einen Kampf."),
        #else
            "Raises the stat\n"
            "Defense during one\n"
            "battle."),
        #endif
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .battleUsage = EFFECT_ITEM_INCREASE_STAT,
        .effect = gItemEffect_XDefense,
        .flingPower = 30,
    },

    [ITEM_X_SP_ATK] =
    {
        .name = _("X Sp. Angriff"),
        .price = (I_PRICE >= GEN_7) ? 1000 : 350,
        .holdEffectParam = X_ITEM_STAGES,
        .description = COMPOUND_STRING(
        #if B_X_ITEMS_BUFF >= GEN_7
            "Hebt den\n"
            "SP. Angr.-Wert\n"
            "für einen Kampf."),
        #else
            "Raises the stat\n"
            "Sp. Atk during one\n"
            "battle."),
        #endif
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .battleUsage = EFFECT_ITEM_INCREASE_STAT,
        .effect = gItemEffect_XSpecialAttack,
        .flingPower = 30,
    },

    [ITEM_X_SP_DEF] =
    {
        .name = _("X Sp.Abwehr"),
        .price = (I_PRICE >= GEN_7) ? 2000 : 350,
        .holdEffectParam = X_ITEM_STAGES,
        .description = COMPOUND_STRING(
        #if B_X_ITEMS_BUFF >= GEN_7
            "Hebt den\n"
            "SP. Vert.-Wert\n"
            "für einen Kampf."),
        #else
            "Raises the stat\n"
            "Sp. Def during one\n"
            "battle."),
        #endif
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .battleUsage = EFFECT_ITEM_INCREASE_STAT,
        .effect = gItemEffect_XSpecialDefense,
        .flingPower = 30,
    },

    [ITEM_X_SPEED] =
    {
        .name = _("X-Tempo"),
        .price = (I_PRICE >= GEN_7) ? 1000 : 350,
        .holdEffectParam = X_ITEM_STAGES,
        .description = COMPOUND_STRING(
        #if B_X_ITEMS_BUFF >= GEN_7
            "Hebt den\n"
            "Init.-Wert\n"
            "für einen Kampf."),
        #else
            "Raises the stat\n"
            "Speed during one\n"
            "battle."),
        #endif
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .battleUsage = EFFECT_ITEM_INCREASE_STAT,
        .effect = gItemEffect_XSpeed,
        .flingPower = 30,
    },

    [ITEM_X_ACCURACY] =
    {
        .name = _("X-Treffer"),
        .pluralName = _("X-Treffer"),
        .price = (I_PRICE >= GEN_7) ? 1000 : 950,
        .holdEffectParam = X_ITEM_STAGES,
            .description = COMPOUND_STRING(
        #if B_X_ITEMS_BUFF >= GEN_7
            "Hebt die\n"
            "Genauigkeit\n"
            "für einen Kampf."),
        #else
            "Raises accuracy\n"
            "of attack moves\n"
            "during one battle."),
        #endif
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .battleUsage = EFFECT_ITEM_INCREASE_STAT,
        .effect = gItemEffect_XAccuracy,
        .flingPower = 30,
    },

    [ITEM_DIRE_HIT] =
    {
        .name = _("Angriffplus"),
        .price = (I_PRICE >= GEN_7) ? 1000 : 650,
        .description = COMPOUND_STRING(
            "Hebt die\n"
            "Volltrefferquote\n"
            "für einen Kampf."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .battleUsage = EFFECT_ITEM_SET_FOCUS_ENERGY,
        .effect = gItemEffect_DireHit,
        .flingPower = 30,
    },

    [ITEM_GUARD_SPEC] =
    {
        .name = _("Megablock."),
        .pluralName = _("Megablock"),
        .price = (I_PRICE >= GEN_7) ? 1500 : 700,
        .description = COMPOUND_STRING(
            "Statusänderung\n"
            "wird für einen\n"
            "Kampf verhindert."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .battleUsage = EFFECT_ITEM_SET_MIST,
        .effect = gItemEffect_GuardSpec,
        .flingPower = 30,
    },

    [ITEM_POKE_DOLL] =
    {
        .name = _("Poképuppe"),
        .price = (I_PRICE < GEN_7) ? 1000 : ((I_PRICE == GEN_7) ? 100 : 300),
        .description = sPokeDollDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .battleUsage = EFFECT_ITEM_ESCAPE,
        .flingPower = 30,
    },

    [ITEM_FLUFFY_TAIL] =
    {
        .name = _("Eneco-Route"),
        .price = (I_PRICE >= GEN_7) ? 100 : 1000,
        .description = sPokeDollDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .battleUsage = EFFECT_ITEM_ESCAPE,
        .flingPower = 30,
    },

    [ITEM_POKE_TOY] =
    {
        .name = _("Pokéwedel"),
        .price = (I_PRICE >= GEN_7) ? 100 : 1000,
        .description = sPokeDollDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .battleUsage = EFFECT_ITEM_ESCAPE,
        .flingPower = 30,
    },

    [ITEM_MAX_MUSHROOMS] =
    {
        .name = _("Maxipilz"),
        .pluralName = _("Maxipilze"),
        .price = 8000,
        .description = COMPOUND_STRING(
            "Erhöht jeden Wert\n"
            "während eines Kampfes\n"
            "um eine stufe."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .battleUsage = EFFECT_ITEM_INCREASE_ALL_STATS,
        .flingPower = 30,
    },

// Treasures

    [ITEM_BOTTLE_CAP] =
    {
        .name = _("Silberkorken"),
        .price = (I_PRICE >= GEN_9) ? 20000 : 5000,
        .description = COMPOUND_STRING(
            "Ein wunderschöner Flaschen-\n"
            "verschluss der einen\n"
            "silbernen Glanz ausstrahlt."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
    },

    [ITEM_GOLD_BOTTLE_CAP] =
    {
        .name = _("Gold korken"),
        .price = (I_PRICE >= GEN_9) ? 60000 : 10000,
        .description = COMPOUND_STRING(
            "Ein wunderschöner Flaschen-\n"
            "verschluss der einen\n"
            "Goldenen Glanz ausstrahlt."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
    },

    [ITEM_NUGGET] =
    {
        .name = _("Nugget"),
        .price = 10000 * TREASURE_FACTOR,
        .description = COMPOUND_STRING(
            "Ein Barren aus pu-\n"
            "rem Gold, der von\n"
            "großem Wert ist."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
    },

    [ITEM_BIG_NUGGET] =
    {
        .name = _("Riesennugget"),
        .price = (I_PRICE >= GEN_7) ? (40000 * TREASURE_FACTOR) : 20000,
        .description = COMPOUND_STRING(
            "Ein großer Goldklumpen,\n"
            "der zu einem hohen Preis\n"
            "Verkauft werden kann."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 130,
    },

    [ITEM_TINY_MUSHROOM] =
    {
        .name = _("Minipilz"),
        .price = 500 * TREASURE_FACTOR,
        .description = COMPOUND_STRING(
            "Ein gemeiner\n"
            "Pilz von \n"
            "geringem Wert."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
    },

    [ITEM_BIG_MUSHROOM] =
    {
        .name = _("Riesenpilz"),
        .price = 5000 * TREASURE_FACTOR,
        .description = sBigMushroomDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
    },

    [ITEM_BALM_MUSHROOM] =
    {
        .name = _("Duftpilz"),
        .price = (I_PRICE >= GEN_7) ? 15000 * TREASURE_FACTOR: 12500,
        .description = sBigMushroomDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
    },

    [ITEM_PEARL] =
    {
        .name = _("Perle"),
        .price = (I_PRICE >= GEN_7) ? 2000 * TREASURE_FACTOR: 1400,
        .description = COMPOUND_STRING(
            "Eine hübsche Perle\n"
            "von geringem Wert."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
    },

    [ITEM_BIG_PEARL] =
    {
        .name = _("Riesenperle"),
        .price = (I_PRICE >= GEN_7) ? 8000 * TREASURE_FACTOR: 7500,
        .description = COMPOUND_STRING(
            "Schöne, große Per-\n"
            "le, die einen hohen\n"
            "Preis erzielen kann."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
    },

    [ITEM_PEARL_STRING] =
    {
        .name = _("Triperle"),
        .price = (I_PRICE >= GEN_8) ? 15000 * TREASURE_FACTOR: ((I_PRICE == GEN_7) ? 30000 : 15000),
        .description = COMPOUND_STRING(
            "Sehr große Perlen, die\n"
            "zu einem hohen Preis\n"
            "verkauft werden würden."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
    },

    [ITEM_STARDUST] =
    {
        .name = _("Sternenstaub"),
        .pluralName = _("Sternenstaub"),
        .price = (I_PRICE >= GEN_7) ? 3000 * TREASURE_FACTOR: 2000,
        .description = COMPOUND_STRING(
            "Schöner, roter\n"
            "Sand, der von\n"
            "großem Wert ist."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
    },

    [ITEM_STAR_PIECE] =
    {
        .name = _("Sternenstück"),
        .price = (I_PRICE >= GEN_7) ? 12000 * TREASURE_FACTOR: 9800,
        .description = COMPOUND_STRING(
            "Roter Edelstein,\n"
            "der einen hohen\n"
            "Preis erzielen kann."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
    },

    [ITEM_COMET_SHARD] =
    {
        .name = _("Kometstück"),
        .price = (I_PRICE <= GEN_5) ? 0 : ((I_PRICE == GEN_6) ? 30000 : ((I_PRICE == GEN_7) ? 60000 : 25000 * TREASURE_FACTOR)),
        .description = COMPOUND_STRING(
            "Ein Kometensplitter, der\n"
            "der aus dem All herabfiel.\n"
            "Er ist von großem Wert."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
    },

    [ITEM_SHOAL_SALT] =
    {
        .name = _("Küstensalz"),
        .pluralName = _("Küstensalz"),
        .price = 20,
        .description = COMPOUND_STRING(
            "Salz, das sich tief\n"
            "in der KÜSTEN- \n"
            "HÖHLE befand."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
    },

    [ITEM_SHOAL_SHELL] =
    {
        .name = _("Küstenschale"),
        .price = 20,
        .description = COMPOUND_STRING(
            "Muschelschale, die\n"
            "sich in der KÜSTEN- \n"
            "HÖHLE befand."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
    },

    [ITEM_RED_SHARD] =
    {
        .name = _("Purpurstück"),
        .price = (I_PRICE >= GEN_7) ? 1000 : 200,
        .description = sShardsDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
    },

    [ITEM_BLUE_SHARD] =
    {
        .name = _("Indigostück"),
        .price = (I_PRICE >= GEN_7) ? 1000 : 200,
        .description = sShardsDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
    },

    [ITEM_YELLOW_SHARD] =
    {
        .name = _("Gelbstück"),
        .price = (I_PRICE >= GEN_7) ? 1000 : 200,
        .description = sShardsDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
    },

    [ITEM_GREEN_SHARD] =
    {
        .name = _("Grünstück"),
        .price = (I_PRICE >= GEN_7) ? 1000 : 200,
        .description = sShardsDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
    },

    [ITEM_HEART_SCALE] =
    {
        .name = _("Herzschuppe"),
        .price = 100,
        .description = COMPOUND_STRING(
            "Hübsche Schuppe,\n"
            "höchst begehrt\n"
            "bei Sammlern."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
    },

    [ITEM_HONEY] =
    {
        .name = _("Honig"),
        .pluralName = _("Honig"),
        .price = (I_PRICE < GEN_5) ? 100 : ((I_PRICE < GEN_8) ? 300 : 900),
        .description = COMPOUND_STRING(
            "Der Duft dieses Honigs\n"
            "lockt wilde Pokémon\n"
            "beim einsatz an."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Honey,
        .flingPower = 30,
    },

    [ITEM_RARE_BONE] =
    {
        .name = _("Steinknochen"),
        .price = (I_PRICE >= GEN_7) ? 5000 * TREASURE_FACTOR: 10000,
        .description = COMPOUND_STRING(
            "Dieser Knochen erfreut\n"
            "jeden Pokémon-Archäologen.\n"
            "Er ist von hohem Wert."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 100,
    },

    [ITEM_ODD_KEYSTONE] =
    {
        .name = _("Spiritkern"),
        .price = 2100,
        .description = COMPOUND_STRING(
            "Ein wichtiges Item, mit\n"
            "dem ein Steinturm\n"
            "repariert werden kann."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
    },

    [ITEM_PRETTY_FEATHER] =
    {
        .name = _("Prachtfeder"),
        .price = (I_PRICE >= GEN_7) ? 1000 * TREASURE_FACTOR: 200,
        .description = COMPOUND_STRING(
            "Eine ganz normale\n"
            "Feder, die rein gar\n"
            "nichts bewirkt."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 20,
    },

    [ITEM_RELIC_COPPER] =
    {
        .name = _("Alter Heller"),
        .price = 0,
        .description = COMPOUND_STRING(
            "Eine alte Kupfermünze.\n"
            "Die Währung einer gut 3000\n"
            "Jahre alten Kultur."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
    },

    [ITEM_RELIC_SILVER] =
    {
        .name = _("Alter Taler"),
        .price = 0,
        .description = COMPOUND_STRING(
            "Eine alte Silbermünze.\n"
            "Die Währung einer gut 3000\n"
            "Jahre alten Kultur."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
    },

    [ITEM_RELIC_GOLD] =
    {
        .name = _("Alter Dukat"),
        .price = 0,
        .description = COMPOUND_STRING(
            "Eine alte Goldmünze.\n"
            "Die Währung einer gut 3000\n"
            "Jahre alten Kultur."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
    },

    [ITEM_RELIC_VASE] =
    {
        .name = _("Alte Vase"),
        .price = 0,
        .description = COMPOUND_STRING(
            "Eine Vase, angefertigt\n"
            "voneiner gut 3000 Jahre\n"
            "alten Kultur. Viel wert."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
    },

    [ITEM_RELIC_BAND] =
    {
        .name = _("Alter Reif"),
        .price = 0,
        .description = COMPOUND_STRING(
            "Ein Armreif, angefertigt\n"
            "voneiner gut 3000 Jahre\n"
            "alten Kultur. Viel wert."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
    },

    [ITEM_RELIC_STATUE] =
    {
        .name = _("Alte Statue"),
        .price = 0,
        .description = COMPOUND_STRING(
            "Eine Armreif, angefertigt\n"
            "voneiner gut 3000 Jahre\n"
            "alten Kultur. Viel wert."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
    },

    [ITEM_RELIC_CROWN] =
    {
        .name = _("Alte Krone"),
        .price = 0,
        .description = COMPOUND_STRING(
            "Eine Krone, angefertigt\n"
            "voneiner gut 3000 Jahre\n"
            "alten Kultur. Viel wert."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
    },

    [ITEM_STRANGE_SOUVENIR] =
    {
        .name = _("Skur.skulptur"),
        .price = (I_PRICE >= GEN_7) ? 3000 : 10,
        .description = COMPOUND_STRING(
            "Ein Ornament, das\n"
            "ein Pokémon aus\n"
            "Alola darstellt."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
    },

// Fossils

    [ITEM_HELIX_FOSSIL] =
    {
        .name = _("Helixfossil"),
        .description = COMPOUND_STRING(
            "Ein Fossil eines\n"
            "Pokémon das am\n"
            "Meeresgrund lebte."),
        #if I_KEY_FOSSILS >= GEN_4
            .price = (I_PRICE >= GEN_7) ? 7000: 1000,
            .pocket = POCKET_ITEMS,
        #else
            .price = 0,
            .importance = 1,
            .pocket = POCKET_KEY_ITEMS,
        #endif
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 100,
    },

    [ITEM_DOME_FOSSIL] =
    {
        .name = _("Domfossil"),
        .description = COMPOUND_STRING(
            "Ein Fossil eines\n"
            "Pokémon das am\n"
            "Meeresgrund lebte."),
        #if I_KEY_FOSSILS >= GEN_4
            .price = (I_PRICE >= GEN_7) ? 7000: 1000,
            .pocket = POCKET_ITEMS,
        #else
            .price = 0,
            .importance = 1,
            .pocket = POCKET_KEY_ITEMS,
        #endif
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 100,
    },

    [ITEM_OLD_AMBER] =
    {
        .name = _("Altbernstein"),
        .description = COMPOUND_STRING(
            "Ein Stein mit\n"
            "der Gene eines\n"
            "Altes Pokémon."),
        #if I_KEY_FOSSILS >= GEN_4
            .price = 1000,
            .pocket = POCKET_ITEMS,
        #else
            .price = 0,
            .importance = 1,
            .pocket = POCKET_KEY_ITEMS,
        #endif
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 100,
    },

    [ITEM_ROOT_FOSSIL] =
    {
        .name = _("Wurzelfossil"),
        .description = sRootFossilDesc,
        #if I_KEY_FOSSILS >= GEN_4
            .price = (I_PRICE >= GEN_7) ? 7000: 1000,
            .pocket = POCKET_ITEMS,
        #else
            .price = 0,
            .importance = 1,
            .pocket = POCKET_KEY_ITEMS,
        #endif
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 100,
    },

    [ITEM_CLAW_FOSSIL] =
    {
        .name = _("Klauenfossil"),
        .description = sRootFossilDesc,
        #if I_KEY_FOSSILS >= GEN_4
            .price = (I_PRICE >= GEN_7) ? 7000: 1000,
            .pocket = POCKET_ITEMS,
        #else
            .price = 0,
            .importance = 1,
            .pocket = POCKET_KEY_ITEMS,
        #endif
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 100,
    },

    [ITEM_ARMOR_FOSSIL] =
    {
        .name = _("Panzerfossil"),
        .price = (I_PRICE >= GEN_7) ? 7000: 1000,
        .description = COMPOUND_STRING(
            "Das Fossil eines uralten\n "
            "Pokémon, das an Land lebte.\n"
            "Sieht wie ein Schlüsselbein aus."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 100,
    },

    [ITEM_SKULL_FOSSIL] =
    {
        .name = _("Kopffossil"),
        .price = (I_PRICE >= GEN_7) ? 7000: 1000,
        .description = COMPOUND_STRING(
            "Das Fossil eines uralten\n "
            "Pokémon, das an Land lebte.\n"
            "Sieht wie ein Schädel aus."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 100,
    },

    [ITEM_COVER_FOSSIL] =
    {
        .name = _("Schildfossil"),
        .price = (I_PRICE >= GEN_7) ? 7000: 1000,
        .description = COMPOUND_STRING(
            "Das Fossil eines uralten\n "
            "Pokémon, das  in der Tiefsee\n"
            "lebte. Sieht wie ein Rücken aus."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 100,
    },

    [ITEM_PLUME_FOSSIL] =
    {
        .name = _("Federfossil"),
        .price = (I_PRICE >= GEN_7) ? 7000: 1000,
        .description = COMPOUND_STRING(
            "Das Fossil eines uralten\n "
            "Pokémon,  von dem man annimmt,\n"
            "es sei der Urahn der Vogel-Pokémon."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 100,
    },

    [ITEM_JAW_FOSSIL] =
    {
        .name = _("Kieferfossil"),
        .price = (I_PRICE >= GEN_7) ? 7000: 1000,
        .description = COMPOUND_STRING(
            "Das Fossil eines uralten\n "
            "Pokémon, das  an Land lebte.\n"
            "Sieht wie ein Kieferknochen aus."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 100,
    },

    [ITEM_SAIL_FOSSIL] =
    {
        .name = _("Flossenfossil"),
        .price = (I_PRICE >= GEN_7) ? 7000: 1000,
        .description = COMPOUND_STRING(
            "Das Fossil eines uralten\n "
            "Pokémon, das  an Land lebte.\n"
            "Sieht wie ein Flosse aus."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 100,
    },

    [ITEM_FOSSILIZED_BIRD] =
    {
        .name = _("Vogelfossil"),
        .price = 5000,
        .description = COMPOUND_STRING(
            "Ein Fossil eines\n"
            "uralt, Himmel-\n"
            "aufsteigendes Pokémon."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 100,
    },

    [ITEM_FOSSILIZED_FISH] =
    {
        .name = _("Fischfossil"),
        .pluralName = _("Fischfossilen"),
        .price = 5000,
        .description = sFossilizedFishDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 100,
    },

    [ITEM_FOSSILIZED_DRAKE] =
    {
        .name = _("Drachenfossil"),
        .price = 5000,
        .description = COMPOUND_STRING(
            "Ein Fossil eines\n"
            "uralt, Landumher-\n"
            "streifendes Pokémon."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 100,
    },

    [ITEM_FOSSILIZED_DINO] =
    {
        .name = _("Paddelfossil"),
        .price = 5000,
        .description = sFossilizedFishDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 100,
    },

// Mulch

    [ITEM_GROWTH_MULCH] =
    {
        .name = _("Wachsmulch"),
        .pluralName = _("Wachsmulch"),
        .price = 200,
#if OW_BERRY_MULCH_USAGE == TRUE
        .description = COMPOUND_STRING(
            "Ein Dünger, der das\n"
            "Wachstum von Beeren\n"
            "beschleunigt."),
#else
        .description = sGenericMulchDesc,
#endif
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = ITEM_TO_MULCH(ITEM_GROWTH_MULCH),
        .flingPower = 30,
    },

    [ITEM_DAMP_MULCH] =
    {
        .name = _("Feuchtmulch"),
        .pluralName = _("Feuchtmulch"),
        .price = 200,
#if OW_BERRY_MULCH_USAGE == TRUE
        .description = COMPOUND_STRING(
            "Ein Dünger, der das\n"
            "Wachstum von Beeren\n"
            "verlangsamt."),
#else
        .description = sGenericMulchDesc,
#endif
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = ITEM_TO_MULCH(ITEM_DAMP_MULCH),
        .flingPower = 30,
    },

    [ITEM_STABLE_MULCH] =
    {
        .name = _("Stabilmulch"),
        .pluralName = _("Stabilmulch"),
        .price = 200,
#if OW_BERRY_MULCH_USAGE == TRUE
        .description = COMPOUND_STRING(
            "Ein Dünger, für\n"
            "mehr Lebensdauer\n"
            "von Beerenbäumen."),
#else
        .description = sGenericMulchDesc,
#endif
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = ITEM_TO_MULCH(ITEM_STABLE_MULCH),
        .flingPower = 30,
    },

    [ITEM_GOOEY_MULCH] =
    {
        .name = _("Neumulch"),
        .pluralName = _("Neumulch"),
        .price = 200,
#if OW_BERRY_MULCH_USAGE == TRUE
        .description = COMPOUND_STRING(
            "Ein Dünger, für\n"
            "mehr Beerenwachstum\n"
            "nach dem Herbst."),
#else
        .description = sGenericMulchDesc,
#endif
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = ITEM_TO_MULCH(ITEM_GOOEY_MULCH),
        .flingPower = 30,
    },

    [ITEM_RICH_MULCH] =
    {
        .name = _("Sprießmulch"),
        .pluralName = _("Sprießmulch"),
        .price = 200,
#if OW_BERRY_MULCH_USAGE == TRUE
        .description = COMPOUND_STRING(
            "Ein Dünger, der die\n"
            "Anzahl der geernteten\n"
            "Beeren erhöht."),
#else
        .description = sGenericMulchDesc,
#endif
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = ITEM_TO_MULCH(ITEM_RICH_MULCH),
        .flingPower = 30,
    },

    [ITEM_SURPRISE_MULCH] =
    {
        .name = _("Wundermulch"),
        .pluralName = _("Wundermulch"),
        .price = 200,
#if OW_BERRY_MULCH_USAGE == TRUE
        .description = COMPOUND_STRING(
            "Ein Dünger, der die\n"
            "Wahrscheinlichkeit von\n"
            "Beerenmutationen erhöht."),
#else
        .description = sGenericMulchDesc,
#endif
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = ITEM_TO_MULCH(ITEM_SURPRISE_MULCH),
        .flingPower = 30,
    },

    [ITEM_BOOST_MULCH] =
    {
        .name = _("Wuchermulch"),
        .pluralName = _("Wuchermulch"),
        .price = 200,
#if OW_BERRY_MULCH_USAGE == TRUE
        .description = COMPOUND_STRING(
            "Ein Dünger, der die\n"
            "Trocknungsgeschwindigkeit\n"
            "weicher Böden erhöht."),
#else
        .description = sGenericMulchDesc,
#endif
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = ITEM_TO_MULCH(ITEM_BOOST_MULCH),
        .flingPower = 30,
    },

    [ITEM_AMAZE_MULCH] =
    {
        .name = _("Ultramulch"),
        .pluralName = _("Ultramulch"),
        .price = 200,
#if OW_BERRY_MULCH_USAGE == TRUE
        .description = COMPOUND_STRING(
            "Ein Dünger, der sowohl\n"
            "überraschend als\n"
            "auch stärkend ist."),
#else
        .description = sGenericMulchDesc,
#endif
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = ITEM_TO_MULCH(ITEM_AMAZE_MULCH),
        .flingPower = 30,
    },

// Apricorns

    [ITEM_RED_APRICORN] =
    {
        .name = _("Aprikoko Rot"),
        .price = (I_PRICE == GEN_4) ? 0 : ((I_PRICE >= GEN_5 && I_PRICE <= GEN_7) ? 20 : 200),
        .description = COMPOUND_STRING(
            "Eine rote Aprikoko.\n"
            "Besitzt einen stechen-\n"
            "den Geruch."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_BLUE_APRICORN] =
    {
        .name = _("Aprikoko Blau"),
        .price = (I_PRICE == GEN_4) ? 0 : ((I_PRICE >= GEN_5 && I_PRICE <= GEN_7) ? 20 : 200),
        .description = COMPOUND_STRING(
            "Eine blaue Aprikoko.\n"
            "Ein frischer Geruch\n"
            "geht von ihr aus."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_YELLOW_APRICORN] =
    {
        .name = _("Aprikoko Gelb"),
        .price = (I_PRICE == GEN_4) ? 0 : ((I_PRICE >= GEN_5 && I_PRICE <= GEN_7) ? 20 : 200),
        .description = COMPOUND_STRING(
            "Eine Gelbe Aprikoko.\n"
            "Sie riecht ein wenig\n"
            "unreif."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_GREEN_APRICORN] =
    {
        .name = _("Aprikoko Grün"),
        .price = (I_PRICE == GEN_4) ? 0 : ((I_PRICE >= GEN_5 && I_PRICE <= GEN_7) ? 20 : 200),
        .description = COMPOUND_STRING(
            "Eine Grüne Aprikoko.\n"
            "Sie verströmt einen\n"
            "seltsam aromatischen Duft."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_PINK_APRICORN] =
    {
        .name = _("Aprikoko Pink"),
        .price = (I_PRICE == GEN_4) ? 0 : ((I_PRICE >= GEN_5 && I_PRICE <= GEN_7) ? 20 : 200),
        .description = COMPOUND_STRING(
            "Eine  pinkfarbene Aprikoko.\n"
            "Sie duftet süß und\n"
            "appetitanregend."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_WHITE_APRICORN] =
    {
        .name = _("Aprikoko Weiß"),
        .price = (I_PRICE == GEN_4) ? 0 : ((I_PRICE >= GEN_5 && I_PRICE <= GEN_7) ? 20 : 200),
        .description = COMPOUND_STRING(
            "Eine weiße Aprikoko.\n"
            "Riecht nach überhaupt\n"
            "nichts."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_BLACK_APRICORN] =
    {
        .name = _("AprikokoSchw"),
        .price = (I_PRICE == GEN_4) ? 0 : ((I_PRICE >= GEN_5 && I_PRICE <= GEN_7) ? 20 : 200),
        .description = COMPOUND_STRING(
            "Eine schwarze Aprikoko.\n"
            "Sie riecht irgendwie\n"
            "unbeschreiblich."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_WISHING_PIECE] =
    {
        .name = _("Wunschbrocken"),
        .price = 20,
        .description = COMPOUND_STRING(
            "Wirf es in eine {PKMN}-\n"
            "Höhle, um Dynamax-\n"
            "Pokémon anzulocken."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse, // Todo
        .flingPower = 50,
    },

    [ITEM_GALARICA_TWIG] =
    {
        .name = _("GalanusZweig"),
        .price = 20 * TREASURE_FACTOR,
        .description = COMPOUND_STRING(
            "Ein Zweig eines\n"
            "Baumes in Galar\n"
            "namens Galarica."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
    },

    [ITEM_ARMORITE_ORE] =
    {
        .name = _("Rüstungserz"),
        .pluralName = _("Rüstungserz"),
        .price = 20,
        .description = COMPOUND_STRING(
            "Ein seltenes Erz. Kann auf\n"
            "der Isle of Armor in Galar\n"
            "gefunden werden."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
    },

    [ITEM_DYNITE_ORE] =
    {
        .name = _("Dyna-Erz"),
        .pluralName = _("Dyna-Erz"),
        .price = 20,
        .description = COMPOUND_STRING(
            "Ein geheimnisvolles Erz.\n"
            "Es kann in Galars Max\n"
            "Lair gefunden werden."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
    },

// Mail

    [ITEM_ORANGE_MAIL] =
    {
        .name = _("Zigzachsbrief"),
        .pluralName = _("Zigzachsbriefe"),
        .price = 50,
        .description = COMPOUND_STRING(
            "BRIEF (Tragen) mit \n"
            "ZIGZACHS-\n"
            "Aufdruck."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_MAIL,
        .fieldUseFunc = ItemUseOutOfBattle_Mail,
        .secondaryId = ITEM_TO_MAIL(ITEM_ORANGE_MAIL),
    },

    [ITEM_HARBOR_MAIL] =
    {
        .name = _("Hafenbrief"),
        .pluralName = _("Harfenbriefe"),
        .price = 50,
        .description = COMPOUND_STRING(
            "BRIEF (Tragen) mit \n"
            "WINGULL-\n"
            "Aufdruck."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_MAIL,
        .fieldUseFunc = ItemUseOutOfBattle_Mail,
        .secondaryId = ITEM_TO_MAIL(ITEM_HARBOR_MAIL),
    },

    [ITEM_GLITTER_MAIL] =
    {
        .name = _("Glitzerbrief"),
        .pluralName = _("Glitzerbriefe"),
        .price = 50,
        .description = COMPOUND_STRING(
            "BRIEF (Tragen) mit \n"
            "PIKACHU-\n"
            "Aufdruck."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_MAIL,
        .fieldUseFunc = ItemUseOutOfBattle_Mail,
        .secondaryId = ITEM_TO_MAIL(ITEM_GLITTER_MAIL),
    },

    [ITEM_MECH_MAIL] =
    {
        .name = _("Eilbrief"),
        .pluralName = _("Eilbriefe"),
        .price = 50,
        .description = COMPOUND_STRING(
            "BRIEF (Tragen) mit \n"
            "MAGNETILO-\n"
            "Aufdruck."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_MAIL,
        .fieldUseFunc = ItemUseOutOfBattle_Mail,
        .secondaryId = ITEM_TO_MAIL(ITEM_MECH_MAIL),
    },

    [ITEM_WOOD_MAIL] =
    {
        .name = _("Waldbrief"),
        .pluralName = _("Waldbriefe"),
        .price = 50,
        .description = COMPOUND_STRING(
            "BRIEF (Tragen) mit \n"
            "BUMMELZ-\n"
            "Aufdruck."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_MAIL,
        .fieldUseFunc = ItemUseOutOfBattle_Mail,
        .secondaryId = ITEM_TO_MAIL(ITEM_WOOD_MAIL),
    },

    [ITEM_WAVE_MAIL] =
    {
        .name = _("Wellenbrief"),
        .pluralName = _("Wellenbriefe"),
        .price = 50,
        .description = COMPOUND_STRING(
            "BRIEF (Tragen) mit \n"
            "Wailmer-\n"
            "Aufdruck."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_MAIL,
        .fieldUseFunc = ItemUseOutOfBattle_Mail,
        .secondaryId = ITEM_TO_MAIL(ITEM_WAVE_MAIL),
    },

    [ITEM_BEAD_MAIL] =
    {
        .name = _("Perlenbrief"),
        .pluralName = _("Perlenbriefe"),
        .price = 50,
        .description = sBeadMailDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_MAIL,
        .fieldUseFunc = ItemUseOutOfBattle_Mail,
        .secondaryId = ITEM_TO_MAIL(ITEM_BEAD_MAIL),
    },

    [ITEM_SHADOW_MAIL] =
    {
        .name = _("Dunkelbrief"),
        .pluralName = _("Dunkelbriefe"),
        .price = 50,
        .description = COMPOUND_STRING(
            "BRIEF (Tragen) mit \n"
            "Zwirrlicht-\n"
            "Aufdruck."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_MAIL,
        .fieldUseFunc = ItemUseOutOfBattle_Mail,
        .secondaryId = ITEM_TO_MAIL(ITEM_SHADOW_MAIL),
    },

    [ITEM_TROPIC_MAIL] =
    {
        .name = _("Tropenbrief"),
        .pluralName = _("Tropenbriefe"),
        .price = 50,
        .description = COMPOUND_STRING(
            "BRIEF (Tragen) mit \n"
            "Blubella-\n"
            "Aufdruck."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_MAIL,
        .fieldUseFunc = ItemUseOutOfBattle_Mail,
        .secondaryId = ITEM_TO_MAIL(ITEM_TROPIC_MAIL),
    },

    [ITEM_DREAM_MAIL] =
    {
        .name = _("Traumbrief"),
        .pluralName = _("Traumbriefe"),
        .price = 50,
        .description = sBeadMailDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_MAIL,
        .fieldUseFunc = ItemUseOutOfBattle_Mail,
        .secondaryId = ITEM_TO_MAIL(ITEM_DREAM_MAIL),
    },

    [ITEM_FAB_MAIL] =
    {
        .name = _("Edelbrief"),
        .pluralName = _("Edelbriefe"),
        .price = 50,
        .description = COMPOUND_STRING(
            "BRIEF (Tragen) mit \n"
            "edlem Aufdruck."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_MAIL,
        .fieldUseFunc = ItemUseOutOfBattle_Mail,
        .secondaryId = ITEM_TO_MAIL(ITEM_FAB_MAIL),
    },

    [ITEM_RETRO_MAIL] =
    {
        .name = _("Retrobrief"),
        .pluralName = _("Retrobriefe"),
        .price = 50,
        .description = COMPOUND_STRING(
            "BRIEF mit den Ab-\n"
            "bildungen dreier\n"
            "POKéMON-Gesichter."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_MAIL,
        .fieldUseFunc = ItemUseOutOfBattle_Mail,
        .secondaryId = ITEM_TO_MAIL(ITEM_RETRO_MAIL),
    },

// Evolution Items

    [ITEM_FIRE_STONE] =
    {
        .name = _("Feuerstein"),
        .price = (I_PRICE >= GEN_7) ? 3000 : 2100,
        .description = sEvolutionStoneDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
        .effect = gItemEffect_EvoItem,
        .flingPower = 30,
    },

    [ITEM_WATER_STONE] =
    {
        .name = _("Wasserstein"),
        .price = (I_PRICE >= GEN_7) ? 3000 : 2100,
        .description = sEvolutionStoneDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
        .effect = gItemEffect_EvoItem,
        .flingPower = 30,
    },

    [ITEM_THUNDER_STONE] =
    {
        .name = _("Donnerstein"),
        .price = (I_PRICE >= GEN_7) ? 3000 : 2100,
        .description = sEvolutionStoneDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
        .effect = gItemEffect_EvoItem,
        .flingPower = 30,
    },

    [ITEM_LEAF_STONE] =
    {
        .name = _("Blattstein"),
        .price = (I_PRICE >= GEN_7) ? 3000 : 2100,
        .description = sEvolutionStoneDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
        .effect = gItemEffect_EvoItem,
        .flingPower = 30,
    },

    [ITEM_ICE_STONE] =
    {
        .name = _("Eisstein"),
        .price = (I_PRICE >= GEN_7) ? 3000 : 2100,
        .description = sEvolutionStoneDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
        .effect = gItemEffect_EvoItem,
        .flingPower = 30,
    },

    [ITEM_SUN_STONE] =
    {
        .name = _("Sonnenstein"),
        .price = (I_PRICE >= GEN_7) ? 3000 : 2100,
        .description = sEvolutionStoneDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
        .effect = gItemEffect_EvoItem,
        .flingPower = 30,
    },

    [ITEM_MOON_STONE] =
    {
        .name = _("Mondstein"),
        .price = (I_PRICE >= GEN_7) ? 3000 : 2100,
        .description = sEvolutionStoneDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
        .effect = gItemEffect_EvoItem,
        .flingPower = 30,
    },

    [ITEM_SHINY_STONE] =
    {
        .name = _("Leuchtstein"),
        .price = (I_PRICE >= GEN_7) ? 3000 : 2100,
        .description = sEvolutionStoneDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
        .effect = gItemEffect_EvoItem,
        .flingPower = 30,
    },

    [ITEM_DUSK_STONE] =
    {
        .name = _("Finsterstein"),
        .price = (I_PRICE >= GEN_7) ? 3000 : 2100,
        .description = sEvolutionStoneDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
        .effect = gItemEffect_EvoItem,
        .flingPower = 80,
    },

    [ITEM_DAWN_STONE] =
    {
        .name = _("Funkelstein"),
        .price = (I_PRICE >= GEN_7) ? 3000 : 2100,
        .description = sEvolutionStoneDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
        .effect = gItemEffect_EvoItem,
        .flingPower = 80,
    },

    [ITEM_SWEET_APPLE] =
    {
        .name = _("Süßer Apfel"),
        .price = 2200,
        .description = COMPOUND_STRING(
            "Dieser sonderbare Apfel\n"
            "löst bei bestimmten Poké-\n"
            "mon die Entwicklung aus."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
        .effect = gItemEffect_EvoItem,
        .flingPower = 30,
    },

    [ITEM_TART_APPLE] =
    {
        .name = _("Saurer Apfel"),
        .price = 2200,
        .description = COMPOUND_STRING(
            "Dieser sonderbare Apfel\n"
            "löst bei bestimmten Poké-\n"
            "mon die Entwicklung aus."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
        .effect = gItemEffect_EvoItem,
        .flingPower = 30,
    },

    [ITEM_CRACKED_POT] =
    {
        .name = _("Rissige Kanne"),
        .price = 1600,
        .description = COMPOUND_STRING(
            "Eine zerbrochene Tee-\n"
            "kanne, die die Entwicklung\n"
            "bestimmter Pokémon fördert."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
        .effect = gItemEffect_EvoItem,
        .flingPower = 80,
    },

    [ITEM_CHIPPED_POT] =
    {
        .name = _("Loch Kanne"),
        .price = 38000,
        .description = COMPOUND_STRING(
            "Eine Löchlige Teekanne\n"
            "die die Entwicklung\n"
            "bestimmter Pokémon fördert."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
        .effect = gItemEffect_EvoItem,
        .flingPower = 80,
    },

    [ITEM_GALARICA_CUFF] =
    {
        .name = _("GalanussReif"),
        .price = (I_PRICE >= GEN_9) ? 3000 : 6000,
        .description = COMPOUND_STRING(
            "Eine Manschette von Galar\n"
            "die dafür sorgt, dass sich\n"
            "bestimmte Pokémon weiterentwi."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
        .effect = gItemEffect_EvoItem,
        .flingPower = 30,
    },

    [ITEM_GALARICA_WREATH] =
    {
        .name = _("GalanusKranz"),
        .pluralName = _("GalanusKranz"),
        .price = (I_PRICE >= GEN_9) ? 3000 : 6000,
        .description = COMPOUND_STRING(
            "Ein Kranz aus Galar.\n"
            "Lässt einige Pokémon\n"
            "weiterentwickeln."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
        .effect = gItemEffect_EvoItem,
        .flingPower = 30,
    },

    [ITEM_DRAGON_SCALE] =
    {
        .name = _("Drachenschu"),
        .price = (I_PRICE >= GEN_7) ? 2000 * TREASURE_FACTOR : 2100,
        .holdEffect = HOLD_EFFECT_DRAGON_SCALE,
        .holdEffectParam = 10,
        .description = COMPOUND_STRING(
            "Eine seltsame Schuppe, die\n"
            "von Pokémon vom\n"
            "Drache gehalten wird."),
        .pocket = POCKET_ITEMS,
        .type = EVO_HELD_ITEM_TYPE,
        .fieldUseFunc = EVO_HELD_ITEM_FIELD_FUNC,
        .effect = gItemEffect_EvoItem,
        .flingPower = 30,
    },

    [ITEM_UPGRADE] =
    {
        .name = _("Upgrade"),
        .price = (I_PRICE >= GEN_7) ? 2000 * TREASURE_FACTOR : 2100,
        .holdEffect = HOLD_EFFECT_UPGRADE,
        .description = COMPOUND_STRING(
            "Eine mysteriöse\n"
            "Box der SILPH CO."),
        .pocket = POCKET_ITEMS,
        .type = EVO_HELD_ITEM_TYPE,
        .fieldUseFunc = EVO_HELD_ITEM_FIELD_FUNC,
        .effect = gItemEffect_EvoItem,
        .flingPower = 30,
    },

    [ITEM_PROTECTOR] =
    {
        .name = _("Schützer"),
        .price = (I_PRICE >= GEN_7) ? 2000 * TREASURE_FACTOR : 2100,
        .description = COMPOUND_STRING(
            "Eine Art Schutzvorrichtung.\n"
            "Das Lieblingsstück\n"
            "eines bestimmten Pokémon."),
        .pocket = POCKET_ITEMS,
        .type = EVO_HELD_ITEM_TYPE,
        .fieldUseFunc = EVO_HELD_ITEM_FIELD_FUNC,
        .effect = gItemEffect_EvoItem,
        .flingPower = 80,
    },

    [ITEM_ELECTIRIZER] =
    {
        .name = _("Stromisierer"),
        .price = (I_PRICE >= GEN_7) ? 2000 * TREASURE_FACTOR : 2100,
        .description = COMPOUND_STRING(
            "Das Lieblingsstück eines\n"
            "bestimmten Pokémon."),
        .pocket = POCKET_ITEMS,
        .type = EVO_HELD_ITEM_TYPE,
        .fieldUseFunc = EVO_HELD_ITEM_FIELD_FUNC,
        .effect = gItemEffect_EvoItem,
        .flingPower = 80,
    },

    [ITEM_MAGMARIZER] =
    {
        .name = _("Magmaisierer"),
        .price = (I_PRICE >= GEN_7) ? 2000 * TREASURE_FACTOR : 2100,
        .description = COMPOUND_STRING(
            "Eine Schachtel voller Magma-\n"
            "energie. Das Lieblingsstück\n"
            "einesbestimmten Pokémon."),
        .pocket = POCKET_ITEMS,
        .type = EVO_HELD_ITEM_TYPE,
        .fieldUseFunc = EVO_HELD_ITEM_FIELD_FUNC,
        .effect = gItemEffect_EvoItem,
        .flingPower = 80,
    },

    [ITEM_DUBIOUS_DISC] =
    {
        .name = _("Dubiosdisc"),
        .price = (I_PRICE >= GEN_7) ? 2000 * TREASURE_FACTOR : 2100,
        .description = COMPOUND_STRING(
            "Eine Scheibe voller selt-\n"
            "samer Daten. Ihr Ursprung\n"
            "ist unbekannt."),
        .pocket = POCKET_ITEMS,
        .type = EVO_HELD_ITEM_TYPE,
        .fieldUseFunc = EVO_HELD_ITEM_FIELD_FUNC,
        .effect = gItemEffect_EvoItem,
        .flingPower = 50,
    },

    [ITEM_REAPER_CLOTH] =
    {
        .name = _("Düsterumhang"),
        .pluralName = _("Düsterumhänge"),
        .price = (I_PRICE >= GEN_7) ? 2000 * TREASURE_FACTOR : 2100,
        .description = COMPOUND_STRING(
            "Ein Stoffumhang voller geist-\n"
            "iger Energie. Das Lieblingsstück\n"
            "eines bestimmten Pokémon."),
        .pocket = POCKET_ITEMS,
        .type = EVO_HELD_ITEM_TYPE,
        .fieldUseFunc = EVO_HELD_ITEM_FIELD_FUNC,
        .effect = gItemEffect_EvoItem,
        .flingPower = 10,
    },

    [ITEM_PRISM_SCALE] =
    {
        .name = _("Schönschuppe"),
        .price = (I_PRICE >= GEN_9) ? 3000 : ((I_PRICE >= GEN_7) ? 2000 : 500),
        .description = COMPOUND_STRING(
            "Eine seltsame Schuppe\n"
            "durch die sich bestimmte\n"
            "Pokémon entwickeln."),
        .pocket = POCKET_ITEMS,
        .type = EVO_HELD_ITEM_TYPE,
        .fieldUseFunc = EVO_HELD_ITEM_FIELD_FUNC,
        .effect = gItemEffect_EvoItem,
        .flingPower = 30,
    },

    [ITEM_WHIPPED_DREAM] =
    {
        .name = _("Sahnehäubchen"),
        .pluralName = _("Sahnehäubchen"),
        .price = (I_PRICE >= GEN_7) ? 2000 * TREASURE_FACTOR : 2100,
        .description = COMPOUND_STRING(
            "Ein lockeres und süßliches\n"
            "Sahnehäubchen das bei einer\n"
            "bestimmten {PKMN}-Art beliebt ist."),
        .pocket = POCKET_ITEMS,
        .type = EVO_HELD_ITEM_TYPE,
        .fieldUseFunc = EVO_HELD_ITEM_FIELD_FUNC,
        .effect = gItemEffect_EvoItem,
        .flingPower = 80,
    },

    [ITEM_SACHET] =
    {
        .name = _("Duftbeutel"),
        .price = (I_PRICE >= GEN_7) ? 2000 * TREASURE_FACTOR : 2100,
        .description = COMPOUND_STRING(
            "Ein Beutel gefüllt mit\n"
            "Parfüms, die ein bestimmt-\n"
            "es Pokémon liebt."),
        .pocket = POCKET_ITEMS,
        .type = EVO_HELD_ITEM_TYPE,
        .fieldUseFunc = EVO_HELD_ITEM_FIELD_FUNC,
        .effect = gItemEffect_EvoItem,
        .flingPower = 80,
    },

    [ITEM_OVAL_STONE] =
    {
        .name = _("Ovaler Stein"),
        .price = (I_PRICE >= GEN_7) ? 2000 : 2100,
        .description = COMPOUND_STRING(
            "Dieser besondere, eiförmige\n"
            "Stein hilft manchen Pokémon\n"
            "bei ihrer Entwicklung."),
        .pocket = POCKET_ITEMS,
        .type = EVO_HELD_ITEM_TYPE,
        .fieldUseFunc = EVO_HELD_ITEM_FIELD_FUNC,
        .effect = gItemEffect_EvoItem,
        .flingPower = 80,
    },

    [ITEM_STRAWBERRY_SWEET] =
    {
        .name = _("ZuckerErdb."),
        .price = 500 * TREASURE_FACTOR,
        .description = COMPOUND_STRING(
            "Erdbeerförmige Süßigkeit\n"
            "die bei Hokumil\n"
            "beliebt ist."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

    [ITEM_LOVE_SWEET] =
    {
        .name = _("Zucker-Herz"),
        .price = 500 * TREASURE_FACTOR,
        .description = COMPOUND_STRING(
            "Zuckerwerk in Form eines\n"
            "Herzchens. Beliebt bei\n"
            "Hokumil."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

    [ITEM_BERRY_SWEET] =
    {
        .name = _("Zucker-Beere"),
        .price = 500 * TREASURE_FACTOR,
        .description = COMPOUND_STRING(
            "Zuckerwerk in Form einer\n"
            "Beere. Beliebt bei\n"
            "Hokumil."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

    [ITEM_CLOVER_SWEET] =
    {
        .name = _("ZuckKleblatt"),
        .price = 500 * TREASURE_FACTOR,
        .description = COMPOUND_STRING(
            "Zuckerwerk in Form eines\n"
            "Kleeblattes. Beliebt bei\n"
            "Hokumil."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

    [ITEM_FLOWER_SWEET] =
    {
        .name = _("Zucker-Blume"),
        .price = 500 * TREASURE_FACTOR,
        .description = COMPOUND_STRING(
            "Zuckerwerk in Form einer\n"
            "Blume. Beliebt bei\n"
            "Hokumil."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

    [ITEM_STAR_SWEET] =
    {
        .name = _("Zucker-Stern"),
        .price = 500 * TREASURE_FACTOR,
        .description = COMPOUND_STRING(
            "Zuckerwerk in Form eines\n"
            "Sterns. Beliebt bei\n"
            "Hokumil."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

    [ITEM_RIBBON_SWEET] =
    {
        .name = _("ZuckSchleife"),
        .price = 500 * TREASURE_FACTOR,
        .description = COMPOUND_STRING(
            "Zuckerwerk in Form einer\n"
            "Schleife. Beliebt bei\n"
            "Hokumil."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

    [ITEM_EVERSTONE] =
    {
        .name = _("Ewigstein"),
        .price = (I_PRICE >= GEN_7) ? 3000 : 200,
        .holdEffect = HOLD_EFFECT_PREVENT_EVOLVE,
        .description = COMPOUND_STRING(
            "Wundersamer Stein\n"
            "zum Tragen. Bewirkt\n"
            "Entwicklungsstopp."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
    },

// Nectars

    [ITEM_RED_NECTAR] =
    {
        .name = _("Rot Nektar"),
        .price = 300,
        .holdEffectParam = 0,
        .description = sNectarDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_FormChange_ConsumedOnUse,
        .flingPower = 10,
    },

    [ITEM_YELLOW_NECTAR] =
    {
        .name = _("Gelb Nektar"),
        .price = 300,
        .holdEffectParam = 0,
        .description = sNectarDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_FormChange_ConsumedOnUse,
        .flingPower = 10,
    },

    [ITEM_PINK_NECTAR] =
    {
        .name = _("Pink Nektar"),
        .price = 300,
        .holdEffectParam = 0,
        .description = sNectarDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_FormChange_ConsumedOnUse,
        .flingPower = 10,
    },

    [ITEM_PURPLE_NECTAR] =
    {
        .name = _("Lila Nektar"),
        .price = 300,
        .holdEffectParam = 0,
        .description = sNectarDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_FormChange_ConsumedOnUse,
        .flingPower = 10,
    },

// Plates

    [ITEM_FLAME_PLATE] =
    {
        .name = _("Feuertafel"),
        .price = 1000,
        .holdEffect = HOLD_EFFECT_PLATE,
        .holdEffectParam = 20,
        .description = COMPOUND_STRING(
            "Ein Item zum Tragen.\n"
            "Diese Steintafel verstärkt\n"
            "Attacken vom Typ Feuer."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_FIRE,
        .flingPower = 90,
    },

    [ITEM_SPLASH_PLATE] =
    {
        .name = _("Wassertafel"),
        .price = 1000,
        .holdEffect = HOLD_EFFECT_PLATE,
        .holdEffectParam = 20,
        .description = COMPOUND_STRING(
            "Ein Item zum Tragen.\n"
            "Diese Steintafel verstärkt\n"
            "Attacken vom Typ Wasser."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_WATER,
        .flingPower = 90,
    },

    [ITEM_ZAP_PLATE] =
    {
        .name = _("Blitztafel"),
        .price = 1000,
        .holdEffect = HOLD_EFFECT_PLATE,
        .holdEffectParam = 20,
        .description = COMPOUND_STRING(
            "Ein Item zum Tragen.\n"
            "Diese Steintafel verstärkt\n"
            "Attacken vom Typ Elektro."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_ELECTRIC,
        .flingPower = 90,
    },

    [ITEM_MEADOW_PLATE] =
    {
        .name = _("Pflanzentafel"),
        .price = 1000,
        .holdEffect = HOLD_EFFECT_PLATE,
        .holdEffectParam = 20,
        .description = COMPOUND_STRING(
            "Ein Item zum Tragen.\n"
            "Diese Steintafel verstärkt\n"
            "Attacken vom Typ Pflanze."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_GRASS,
        .flingPower = 90,
    },

    [ITEM_ICICLE_PLATE] =
    {
        .name = _("Eistafel"),
        .price = 1000,
        .holdEffect = HOLD_EFFECT_PLATE,
        .holdEffectParam = 20,
        .description = COMPOUND_STRING(
            "Ein Item zum Tragen.\n"
            "Diese Steintafel verstärkt\n"
            "Attacken vom Typ Eis."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_ICE,
        .flingPower = 90,
    },

    [ITEM_FIST_PLATE] =
    {
        .name = _("Kampftafel"),
        .price = 1000,
        .holdEffect = HOLD_EFFECT_PLATE,
        .holdEffectParam = 20,
        .description = COMPOUND_STRING(
            "Ein Item zum Tragen.\n"
            "Diese Steintafel verstärkt\n"
            "Attacken vom Typ Kampf."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_FIGHTING,
        .flingPower = 90,
    },

    [ITEM_TOXIC_PLATE] =
    {
        .name = _("Gifttafel"),
        .price = 1000,
        .holdEffect = HOLD_EFFECT_PLATE,
        .holdEffectParam = 20,
        .description = COMPOUND_STRING(
            "Ein Item zum Tragen.\n"
            "Diese Steintafel verstärkt\n"
            "Attacken vom Typ Gift."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_POISON,
        .flingPower = 90,
    },

    [ITEM_EARTH_PLATE] =
    {
        .name = _("Bodentafel"),
        .price = 1000,
        .holdEffect = HOLD_EFFECT_PLATE,
        .holdEffectParam = 20,
        .description = COMPOUND_STRING(
            "Ein Item zum Tragen.\n"
            "Diese Steintafel verstärkt\n"
            "Attacken vom Typ Boden."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_GROUND,
        .flingPower = 90,
    },

    [ITEM_SKY_PLATE] =
    {
        .name = _("Flugtafel"),
        .price = 1000,
        .holdEffect = HOLD_EFFECT_PLATE,
        .holdEffectParam = 20,
        .description = COMPOUND_STRING(
            "Ein Item zum Tragen.\n"
            "Diese Steintafel verstärkt\n"
            "Attacken vom Typ Flug."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_FLYING,
        .flingPower = 90,
    },

    [ITEM_MIND_PLATE] =
    {
        .name = _("Psychotafel"),
        .price = 1000,
        .holdEffect = HOLD_EFFECT_PLATE,
        .holdEffectParam = 20,
        .description = COMPOUND_STRING(
            "Ein Item zum Tragen.\n"
            "Diese Steintafel verstärkt\n"
            "Attacken vom Typ Psycho."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_PSYCHIC,
        .flingPower = 90,
    },

    [ITEM_INSECT_PLATE] =
    {
        .name = _("Käfertafel"),
        .price = 1000,
        .holdEffect = HOLD_EFFECT_PLATE,
        .holdEffectParam = 20,
        .description = COMPOUND_STRING(
            "Ein Item zum Tragen.\n"
            "Diese Steintafel verstärkt\n"
            "Attacken vom Typ Käfer."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_BUG,
        .flingPower = 90,
    },

    [ITEM_STONE_PLATE] =
    {
        .name = _("Gesteintafel"),
        .price = 1000,
        .holdEffect = HOLD_EFFECT_PLATE,
        .holdEffectParam = 20,
        .description = COMPOUND_STRING(
            "Ein Item zum Tragen.\n"
            "Diese Steintafel verstärkt\n"
            "Attacken vom Typ Gestein."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_ROCK,
        .flingPower = 90,
    },

    [ITEM_SPOOKY_PLATE] =
    {
        .name = _("Geisttafel"),
        .price = 1000,
        .holdEffect = HOLD_EFFECT_PLATE,
        .holdEffectParam = 20,
        .description = COMPOUND_STRING(
            "Ein Item zum Tragen.\n"
            "Diese Steintafel verstärkt\n"
            "Attacken vom Typ Geist."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_GHOST,
        .flingPower = 90,
    },

    [ITEM_DRACO_PLATE] =
    {
        .name = _("Drachentafel"),
        .price = 1000,
        .holdEffect = HOLD_EFFECT_PLATE,
        .holdEffectParam = 20,
        .description = COMPOUND_STRING(
            "Ein Item zum Tragen.\n"
            "Diese Steintafel verstärkt\n"
            "Attacken vom Typ Drache."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_DRAGON,
        .flingPower = 90,
    },

    [ITEM_DREAD_PLATE] =
    {
        .name = _("Unlichttafel"),
        .price = 1000,
        .holdEffect = HOLD_EFFECT_PLATE,
        .holdEffectParam = 20,
        .description = COMPOUND_STRING(
            "Ein Item zum Tragen.\n"
            "Diese Steintafel verstärkt\n"
            "Attacken vom Typ Unlicht."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_DARK,
        .flingPower = 90,
    },

    [ITEM_IRON_PLATE] =
    {
        .name = _("Stahltafel"),
        .price = 1000,
        .holdEffect = HOLD_EFFECT_PLATE,
        .holdEffectParam = 20,
        .description = COMPOUND_STRING(
            "Ein Item zum Tragen.\n"
            "Diese Steintafel verstärkt\n"
            "Attacken vom Typ Stahl."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_STEEL,
        .flingPower = 90,
    },

    [ITEM_PIXIE_PLATE] =
    {
        .name = _("Feentafel"),
        .price = 1000,
        .holdEffect = HOLD_EFFECT_PLATE,
        .holdEffectParam = 20,
        .description = COMPOUND_STRING(
            "Ein Item zum Tragen.\n"
            "Diese Steintafel verstärkt\n"
            "Attacken vom Typ Fee."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_FAIRY,
        .flingPower = 90,
    },

// Drives

    [ITEM_DOUSE_DRIVE] =
    {
        .name = _("Aquamodul"),
        .price = (I_PRICE >= GEN_7) ? 0 : 1000,
        .holdEffect = HOLD_EFFECT_DRIVE,
        .description = COMPOUND_STRING(
            "Wandelt Genesect's Attacke\n"
            "Techblaster in den Typ\n"
            "Wasser um."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_WATER,
        .flingPower = 70,
    },

    [ITEM_SHOCK_DRIVE] =
    {
        .name = _("Elekromodul"),
        .price = (I_PRICE >= GEN_7) ? 0 : 1000,
        .holdEffect = HOLD_EFFECT_DRIVE,
        .description = COMPOUND_STRING(
            "Wandelt Genesect's Attacke\n"
            "Techblaster in den Typ\n"
            "Elektro um."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_ELECTRIC,
        .flingPower = 70,
    },

    [ITEM_BURN_DRIVE] =
    {
        .name = _("Feuermodul"),
        .price = (I_PRICE >= GEN_7) ? 0 : 1000,
        .holdEffect = HOLD_EFFECT_DRIVE,
        .description = COMPOUND_STRING(
            "Wandelt Genesect's Attacke\n"
            "Techblaster in den Typ\n"
            "Feeur um."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_FIRE,
        .flingPower = 70,
    },

    [ITEM_CHILL_DRIVE] =
    {
        .name = _("Eismodul"),
        .price = (I_PRICE >= GEN_7) ? 0 : 1000,
        .holdEffect = HOLD_EFFECT_DRIVE,
        .description = COMPOUND_STRING(
            "Wandelt Genesect's Attacke\n"
            "Techblaster in den Typ\n"
            "Eis um."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_ICE,
        .flingPower = 70,
    },

// Memories

    [ITEM_FIRE_MEMORY] =
    {
        .name = _("Feuer-Disc"),
        .pluralName = _("Feuer-Disc's"),
        .price = 1000,
        .holdEffect = HOLD_EFFECT_MEMORY,
        .holdEffectParam = 0,
        .description = COMPOUND_STRING(
            "Eine Disc mit Daten zum Typ\n"
            "Feuer. Sie wechselt\n"
            "Amigento's typ."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_FIRE,
        .flingPower = 50,
    },

    [ITEM_WATER_MEMORY] =
    {
        .name = _("Wasser-Disc"),
        .pluralName = _("Wasser-Disc's"),
        .price = 1000,
        .holdEffect = HOLD_EFFECT_MEMORY,
        .holdEffectParam = 0,
        .description = COMPOUND_STRING(
            "Eine Disc mit Daten zum Typ\n"
            "Wasser. Sie wechselt\n"
            "Amigento's typ."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_WATER,
        .flingPower = 50,
    },

    [ITEM_ELECTRIC_MEMORY] =
    {
        .name = _("Eletro-Disc"),
        .pluralName = _("Electrc-Disc's"),
        .price = 1000,
        .holdEffect = HOLD_EFFECT_MEMORY,
        .holdEffectParam = 0,
        .description = COMPOUND_STRING(
            "Eine Disc mit Daten zum Typ\n"
            "Elektro. Sie wechselt\n"
            "Amigento's typ."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_ELECTRIC,
        .flingPower = 50,
    },

    [ITEM_GRASS_MEMORY] =
    {
        .name = _("Pflanze-Disc"),
        .pluralName = _("Pflanze-Disc's"),
        .price = 1000,
        .holdEffect = HOLD_EFFECT_MEMORY,
        .holdEffectParam = 0,
        .description = COMPOUND_STRING(
            "Eine Disc mit Daten zum Typ\n"
            "Pflanze. Sie wechselt\n"
            "Amigento's typ."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_GRASS,
        .flingPower = 50,
    },

    [ITEM_ICE_MEMORY] =
    {
        .name = _("Eis-Disc"),
        .pluralName = _("Eis-Disc's"),
        .price = 1000,
        .holdEffect = HOLD_EFFECT_MEMORY,
        .holdEffectParam = 0,
        .description = COMPOUND_STRING(
            "Eine Disc mit Daten zum Typ\n"
            "Eis. Sie wechselt\n"
            "Amigento's typ."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_ICE,
        .flingPower = 50,
    },

    [ITEM_FIGHTING_MEMORY] =
    {
        .name = _("Kampf-Disc"),
        .pluralName = _("Kampf-Disc's"),
        .price = 1000,
        .holdEffect = HOLD_EFFECT_MEMORY,
        .holdEffectParam = 0,
        .description = COMPOUND_STRING(
            "Eine Disc mit Daten zum Typ\n"
            "Kampf. Sie wechselt\n"
            "Amigento's typ."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_FIGHTING,
        .flingPower = 50,
    },

    [ITEM_POISON_MEMORY] =
    {
        .name = _("Gift-Disc"),
        .pluralName = _("Gift-Disc's"),
        .price = 1000,
        .holdEffect = HOLD_EFFECT_MEMORY,
        .holdEffectParam = 0,
        .description = COMPOUND_STRING(
            "Eine Disc mit Daten zum Typ\n"
            "Gift. Sie wechselt\n"
            "Amigento's typ."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_POISON,
        .flingPower = 50,
    },

    [ITEM_GROUND_MEMORY] =
    {
        .name = _("Boden-Disc"),
        .pluralName = _("Boden-Disc's"),
        .price = 1000,
        .holdEffect = HOLD_EFFECT_MEMORY,
        .holdEffectParam = 0,
        .description = COMPOUND_STRING(
            "Eine Disc mit Daten zum Typ\n"
            "Boden. Sie wechselt\n"
            "Amigento's typ."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_GROUND,
        .flingPower = 50,
    },

    [ITEM_FLYING_MEMORY] =
    {
        .name = _("Flug-Disc"),
        .pluralName = _("Flug-Disc's"),
        .price = 1000,
        .holdEffect = HOLD_EFFECT_MEMORY,
        .holdEffectParam = 0,
        .description = COMPOUND_STRING(
            "Eine Disc mit Daten zum Typ\n"
            "Flug. Sie wechselt\n"
            "Amigento's typ."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_FLYING,
        .flingPower = 50,
    },

    [ITEM_PSYCHIC_MEMORY] =
    {
        .name = _("Psycho-Disc"),
        .pluralName = _("Psycho-Disc's"),
        .price = 1000,
        .holdEffect = HOLD_EFFECT_MEMORY,
        .holdEffectParam = 0,
        .description = COMPOUND_STRING(
            "Eine Disc mit Daten zum Typ\n"
            "Psycho. Sie wechselt\n"
            "Amigento's typ."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_PSYCHIC,
        .flingPower = 50,
    },

    [ITEM_BUG_MEMORY] =
    {
        .name = _("Käfer-Disc"),
        .pluralName = _("Käfer-Disc's"),
        .price = 1000,
        .holdEffect = HOLD_EFFECT_MEMORY,
        .holdEffectParam = 0,
        .description = COMPOUND_STRING(
            "Eine Disc mit Daten zum Typ\n"
            "Käfer. Sie wechselt\n"
            "Amigento's typ."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_BUG,
        .flingPower = 50,
    },

    [ITEM_ROCK_MEMORY] =
    {
        .name = _("Gestein-Disc"),
        .pluralName = _("Gestein-Disc's"),
        .price = 1000,
        .holdEffect = HOLD_EFFECT_MEMORY,
        .holdEffectParam = 0,
        .description = COMPOUND_STRING(
            "Eine Disc mit Daten zum Typ\n"
            "Gestein. Sie wechselt\n"
            "Amigento's typ."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_ROCK,
        .flingPower = 50,
    },

    [ITEM_GHOST_MEMORY] =
    {
        .name = _("Geist-Disc"),
        .pluralName = _("Geist-Disc's"),
        .price = 1000,
        .holdEffect = HOLD_EFFECT_MEMORY,
        .holdEffectParam = 0,
        .description = COMPOUND_STRING(
            "Eine Disc mit Daten zum Typ\n"
            "Geist. Sie wechselt\n"
            "Amigento's typ."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_GHOST,
        .flingPower = 50,
    },

    [ITEM_DRAGON_MEMORY] =
    {
        .name = _("Drache-Disc"),
        .pluralName = _("Drache-Disc's"),
        .price = 1000,
        .holdEffect = HOLD_EFFECT_MEMORY,
        .holdEffectParam = 0,
        .description = COMPOUND_STRING(
            "Eine Disc mit Daten zum Typ\n"
            "Drache. Sie wechselt\n"
            "Amigento's typ."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_DRAGON,
        .flingPower = 50,
    },

    [ITEM_DARK_MEMORY] =
    {
        .name = _("Unlicht-Disc"),
        .pluralName = _("Unlicht-Disc's"),
        .price = 1000,
        .holdEffect = HOLD_EFFECT_MEMORY,
        .holdEffectParam = 0,
        .description = COMPOUND_STRING(
            "Eine Disc mit Daten zum Typ\n"
            "Unlicht. Sie wechselt\n"
            "Amigento's typ."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_DARK,
        .flingPower = 50,
    },

    [ITEM_STEEL_MEMORY] =
    {
        .name = _("Stahl-Disc"),
        .pluralName = _("Stahl-Disc's"),
        .price = 1000,
        .holdEffect = HOLD_EFFECT_MEMORY,
        .holdEffectParam = 0,
        .description = COMPOUND_STRING(
            "Eine Disc mit Daten zum Typ\n"
            "Stahl. Sie wechselt\n"
            "Amigento's typ."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_STEEL,
        .flingPower = 50,
    },

    [ITEM_FAIRY_MEMORY] =
    {
        .name = _("Fee-Disc"),
        .pluralName = _("Fee-Disc's"),
        .price = 1000,
        .holdEffect = HOLD_EFFECT_MEMORY,
        .holdEffectParam = 0,
        .description = COMPOUND_STRING(
            "Eine Disc mit Daten zum Typ\n"
            "Fee. Sie wechselt\n"
            "Amigento's typ."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_FAIRY,
        .flingPower = 50,
    },

    [ITEM_RUSTED_SWORD] =
    {
        .name = _("RostSchwert"),
        .price = 0,
        .description = COMPOUND_STRING(
            "Ein rostiges Schwert. Ein\n"
            "Held nutzte es, um eine\n"
            "Katastrophe zu verhindern."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_RUSTED_SHIELD] =
    {
        .name = _("RostSchild"),
        .price = 0,
        .description = COMPOUND_STRING(
            "Ein rostiger Schild. Ein\n"
            "Held nutzte es, um eine\n"
            "Katastrophe zu verhindern."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

// Colored Orbs

    [ITEM_RED_ORB] =
    {
        .name = _("Rot Edelstein"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_PRIMAL_ORB,
        .description = COMPOUND_STRING(
            "Rot glühende Kugel,\n"
            "die eine uralte Macht\n"
            "bergen soll."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_BLUE_ORB] =
    {
        .name = _("BlauEdelstein"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_PRIMAL_ORB,
        .description = COMPOUND_STRING(
            "Blau glühende Kugel,\n"
            "die eine uralte Macht\n"
            "bergen soll."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

// Mega Stones

    [ITEM_VENUSAURITE] =
    {
        .name = _("Venusaurite"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "Dieser Stein löst\n"
            "Venusaur die Mega\n"
            "Entw. im Kampf aus."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
    },

    [ITEM_CHARIZARDITE_X] =
    {
        .name = _("Gluraknit X"),
        .pluralName = _("Gluraknit X"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = sCharizarditeDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
    },

    [ITEM_CHARIZARDITE_Y] =
    {
        .name = _("Gluraknit Y"),
        .pluralName = _("Gluraknit Y"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = sCharizarditeDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
    },

    [ITEM_BLASTOISINITE] =
    {
        .name = _("Turtoknit"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "Dieser Stein löst\n"
            "bei Turtok die Mega\n"
            "Entw. im Kampf aus."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
    },

    [ITEM_BEEDRILLITE] =
    {
        .name = _("Bibornit"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "Dieser Stein löst\n"
            "bei Bibor die Mega\n"
            "Entw. im Kampf aus."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
    },

    [ITEM_PIDGEOTITE] =
    {
        .name = _("Taubossnit"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "Dieser Stein löst\n"
            "bei Tauboss die Mega\n"
            "Entw. im Kampf aus."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
    },

    [ITEM_ALAKAZITE] =
    {
        .name = _("Simsalanit"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "Dieser Stein löst\n"
            "bei Simsala die Mega\n"
            "Entw. im Kampf aus."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
    },

    [ITEM_SLOWBRONITE] =
    {
        .name = _("Lahmusnit"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "Dieser Stein löst\n"
            "bei Lahmus die Mega\n"
            "Entw. im Kampf aus."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
    },

    [ITEM_GENGARITE] =
    {
        .name = _("Gengarite"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "Dieser Stein löst\n"
            "Gengar die Mega\n"
            "Entw. im Kampf aus."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
    },

    [ITEM_KANGASKHANITE] =
    {
        .name = _("Gengarnit"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "Dieser Stein löst\n"
            "bei Gengar die Mega\n"
            "Entw. im Kampf aus."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
    },

    [ITEM_PINSIRITE] =
    {
        .name = _("Pinsirit"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "Dieser Stein löst\n"
            "bei Pinsir die Mega\n"
            "Entw. im Kampf aus."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
    },

    [ITEM_GYARADOSITE] =
    {
        .name = _("Garadosit"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "Dieser Stein löst\n"
            "bei Garados die Mega\n"
            "Entw. im Kampf aus."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
    },

    [ITEM_AERODACTYLITE] =
    {
        .name = _("Aerodactylit"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "Dieser Stein löst\n"
            "bei Aerodactyl die Mega\n"
            "Entw. im Kampf aus."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
    },

    [ITEM_MEWTWONITE_X] =
    {
        .name = _("Mewtunit X"),
        .pluralName = _("Mewtunit X"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = sMewtwoniteDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
    },

    [ITEM_MEWTWONITE_Y] =
    {
        .name = _("Mewtunit Y"),
        .pluralName = _("Mewtunit Y"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = sMewtwoniteDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
    },

    [ITEM_AMPHAROSITE] =
    {
        .name = _("Ampharosnit"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "Dieser Stein löst\n"
            "bei Ampharos die Mega\n"
            "Entw. im Kampf aus."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
    },

    [ITEM_STEELIXITE] =
    {
        .name = _("Stahlosnit"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "Dieser Stein löst\n"
            "bei Stahlos die Mega\n"
            "Entw. im Kampf aus."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
    },

    [ITEM_SCIZORITE] =
    {
        .name = _("Scheroxnit"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "Dieser Stein löst\n"
            "bei Scherox die Mega\n"
            "Entw. im Kampf aus."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
    },

    [ITEM_HERACRONITE] =
    {
        .name = _("Skarabornit"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "Dieser Stein löst\n"
            "bei Skarabor die Mega\n"
            "Entw. im Kampf aus."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
    },

    [ITEM_HOUNDOOMINITE] =
    {
        .name = _("Hundemonit"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "Dieser Stein löst\n"
            "bei Hundemon die Mega\n"
            "Entw. im Kampf aus."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
    },

    [ITEM_TYRANITARITE] =
    {
        .name = _("Despotarnit"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "Dieser Stein löst\n"
            "bei Despotar die Mega\n"
            "Entw. im Kampf aus."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
    },

    [ITEM_SCEPTILITE] =
    {
        .name = _("Gewaldronit"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "Dieser Stein löst\n"
            "bei Gewaldro die Mega\n"
            "Entw. im Kampf aus."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
    },

    [ITEM_BLAZIKENITE] =
    {
        .name = _("Lohgocknit"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "Dieser Stein löst\n"
            "bei Lohgock die Mega\n"
            "Entw. im Kampf aus."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
    },

    [ITEM_SWAMPERTITE] =
    {
        .name = _("Sumpexnit"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "Dieser Stein löst\n"
            "bei Sumpex die Mega\n"
            "Entw. im Kampf aus."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
    },

    [ITEM_GARDEVOIRITE] =
    {
        .name = _("Guardevoirnit"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "Dieser Stein löst\n"
            "bei Guardevoir die Mega\n"
            "Entw. im Kampf aus."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
    },

    [ITEM_SABLENITE] =
    {
        .name = _("Zobirisnit"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "Dieser Stein löst\n"
            "bei Zobris die Mega\n"
            "Entw. im Kampf aus."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
    },

    [ITEM_MAWILITE] =
    {
        .name = _("Flunkifernit"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "Dieser Stein löst\n"
            "bei Flunkifer die Mega\n"
            "Entw. im Kampf aus."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
    },

    [ITEM_AGGRONITE] =
    {
        .name = _("Stollossnit"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "Dieser Stein löst\n"
            "bei Stollos die Mega\n"
            "Entw. im Kampf aus."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
    },

    [ITEM_MEDICHAMITE] =
    {
        .name = _("Meditalisnit"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "Dieser Stein löst\n"
            "bei Meditalis die Mega\n"
            "Entw. im Kampf aus."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
    },

    [ITEM_MANECTITE] =
    {
        .name = _("Voltensonit"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "Dieser Stein löst\n"
            "bei Voltenso die Mega\n"
            "Entw. im Kampf aus."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
    },

    [ITEM_SHARPEDONITE] =
    {
        .name = _("Tohaidonit"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "Dieser Stein löst\n"
            "bei Tohaido die Mega\n"
            "Entw. im Kampf aus."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
    },

    [ITEM_CAMERUPTITE] =
    {
        .name = _("Cameruptnit"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "Dieser Stein löst\n"
            "bei Camerupt die Mega\n"
            "Entw. im Kampf aus."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
    },

    [ITEM_ALTARIANITE] =
    {
        .name = _("Altarianit"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "Dieser Stein löst\n"
            "bei Altaria die Mega\n"
            "Entw. im Kampf aus."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
    },

    [ITEM_BANETTITE] =
    {
        .name = _("Banetteonit"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "Dieser Stein löst\n"
            "bei Banette die Mega\n"
            "Entw. im Kampf aus."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
    },

    [ITEM_ABSOLITE] =
    {
        .name = _("Absolit"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "Dieser Stein löst\n"
            "bei Absol die Mega\n"
            "Entw. im Kampf aus."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
    },

    [ITEM_GLALITITE] =
    {
        .name = _("Firnontornit"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "Dieser Stein löst\n"
            "bei Firnontor die Mega\n"
            "Entw. im Kampf aus."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
    },

    [ITEM_SALAMENCITE] =
    {
        .name = _("Brutalandanit"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "Dieser Stein löst\n"
            "bei Brutalanda die Mega\n"
            "Entw. im Kampf aus."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
    },

    [ITEM_METAGROSSITE] =
    {
        .name = _("Metagrossit"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "Dieser Stein löst\n"
            "bei Metagross die Mega\n"
            "Entw. im Kampf aus."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
    },

    [ITEM_LATIASITE] =
    {
        .name = _("Latiasit"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "Dieser Stein löst\n"
            "bei Latias die Mega\n"
            "Entw. im Kampf aus."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
    },

    [ITEM_LATIOSITE] =
    {
        .name = _("Latiosit"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "Dieser Stein löst\n"
            "bei Latios die Mega\n"
            "Entw. im Kampf aus."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
    },

    [ITEM_LOPUNNITE] =
    {
        .name = _("Schlapornit"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "Dieser Stein löst\n"
            "bei Schlaporni die Mega\n"
            "Entw. im Kampf aus."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
    },

    [ITEM_GARCHOMPITE] =
    {
        .name = _("Knakracknit"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "Dieser Stein löst\n"
            "bei Knakrack die Mega\n"
            "Entw. im Kampf aus."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
    },

    [ITEM_LUCARIONITE] =
    {
        .name = _("Lucarionit"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "Dieser Stein löst\n"
            "bei Lucario die Mega\n"
            "Entw. im Kampf aus."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
    },

    [ITEM_ABOMASITE] =
    {
        .name = _("Rexblisarnit"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "Dieser Stein löst\n"
            "bei Rexblisar die Mega\n"
            "Entw. im Kampf aus."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
    },

    [ITEM_GALLADITE] =
    {
        .name = _("Galagladinit"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "Dieser Stein löst\n"
            "bei Galagladi die Mega\n"
            "Entw. im Kampf aus."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
    },

    [ITEM_AUDINITE] =
    {
        .name = _("Ohrdochnit"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "Dieser Stein löst\n"
            "bei Ohrdoch die Mega\n"
            "Entw. im Kampf aus."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
    },

    [ITEM_DIANCITE] =
    {
        .name = _("Diancienit"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "Dieser Stein löst\n"
            "bei Diancie die Mega\n"
            "Entw. im Kampf aus."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
    },

// Gems

    [ITEM_NORMAL_GEM] =
    {
        .name = _("Normaljuwel"),
        .price = (I_PRICE >= GEN_9) ? 15000 : ((I_PRICE >= GEN_7) ? 4000 : 200),
        .holdEffect = HOLD_EFFECT_GEMS,
        .holdEffectParam = GEM_BOOST_PARAM,
        .description = COMPOUND_STRING(
            "Erhöht die Kraft vom\n"
            "Typ Normal."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_NORMAL,
    },

    [ITEM_FIRE_GEM] =
    {
        .name = _("Feuerjuwel"),
        .price = (I_PRICE >= GEN_9) ? 15000 : ((I_PRICE >= GEN_7) ? 4000 : 200),
        .holdEffect = HOLD_EFFECT_GEMS,
        .holdEffectParam = GEM_BOOST_PARAM,
        .description = COMPOUND_STRING(
            "Erhöht die Kraft vom\n"
            "Typ Feuer."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_FIRE,
    },

    [ITEM_WATER_GEM] =
    {
        .name = _("Wasserjuwel"),
        .price = (I_PRICE >= GEN_9) ? 15000 : ((I_PRICE >= GEN_7) ? 4000 : 200),
        .holdEffect = HOLD_EFFECT_GEMS,
        .holdEffectParam = GEM_BOOST_PARAM,
        .description = COMPOUND_STRING(
            "Erhöht die Kraft vom\n"
            "Typ Wasser."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_WATER,
    },

    [ITEM_ELECTRIC_GEM] =
    {
        .name = _("Elektrojuwel"),
        .price = (I_PRICE >= GEN_9) ? 15000 : ((I_PRICE >= GEN_7) ? 4000 : 200),
        .holdEffect = HOLD_EFFECT_GEMS,
        .holdEffectParam = GEM_BOOST_PARAM,
        .description = COMPOUND_STRING(
            "Erhöht die Kraft vom\n"
            "Typ Elektro."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_ELECTRIC,
    },

    [ITEM_GRASS_GEM] =
    {
        .name = _("Pflanzenjuwel"),
        .price = (I_PRICE >= GEN_9) ? 15000 : ((I_PRICE >= GEN_7) ? 4000 : 200),
        .holdEffect = HOLD_EFFECT_GEMS,
        .holdEffectParam = GEM_BOOST_PARAM,
        .description = COMPOUND_STRING(
            "Erhöht die Kraft vom\n"
            "Typ Pflanze"),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_GRASS,
    },

    [ITEM_ICE_GEM] =
    {
        .name = _("Eisjuwel"),
        .price = (I_PRICE >= GEN_9) ? 15000 : ((I_PRICE >= GEN_7) ? 4000 : 200),
        .holdEffect = HOLD_EFFECT_GEMS,
        .holdEffectParam = GEM_BOOST_PARAM,
        .description = COMPOUND_STRING(
            "Erhöht die Kraft vom\n"
            "Typ Eis."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_ICE,
    },

    [ITEM_FIGHTING_GEM] =
    {
        .name = _("Kampfjuwel"),
        .price = (I_PRICE >= GEN_9) ? 15000 : ((I_PRICE >= GEN_7) ? 4000 : 200),
        .holdEffect = HOLD_EFFECT_GEMS,
        .holdEffectParam = GEM_BOOST_PARAM,
        .description = COMPOUND_STRING(
            "Erhöht die Kraft vom\n"
            "Typ Kampf."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_FIGHTING,
    },

    [ITEM_POISON_GEM] =
    {
        .name = _("Giftjuwel"),
        .price = (I_PRICE >= GEN_9) ? 15000 : ((I_PRICE >= GEN_7) ? 4000 : 200),
        .holdEffect = HOLD_EFFECT_GEMS,
        .holdEffectParam = GEM_BOOST_PARAM,
        .description = COMPOUND_STRING(
            "Erhöht die Kraft vom\n"
            "Typ Gift."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_POISON,
    },

    [ITEM_GROUND_GEM] =
    {
        .name = _("Bodenjuwel"),
        .price = (I_PRICE >= GEN_9) ? 15000 : ((I_PRICE >= GEN_7) ? 4000 : 200),
        .holdEffect = HOLD_EFFECT_GEMS,
        .holdEffectParam = GEM_BOOST_PARAM,
        .description = COMPOUND_STRING(
            "Erhöht die Kraft vom\n"
            "Typ Boden."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_GROUND,
    },

    [ITEM_FLYING_GEM] =
    {
        .name = _("Flugjuwel"),
        .price = (I_PRICE >= GEN_9) ? 15000 : ((I_PRICE >= GEN_7) ? 4000 : 200),
        .holdEffect = HOLD_EFFECT_GEMS,
        .holdEffectParam = GEM_BOOST_PARAM,
        .description = COMPOUND_STRING(
            "Erhöht die Kraft vom\n"
            "Typ Flug."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_FLYING,
    },

    [ITEM_PSYCHIC_GEM] =
    {
        .name = _("Psychojuwel"),
        .price = (I_PRICE >= GEN_9) ? 15000 : ((I_PRICE >= GEN_7) ? 4000 : 200),
        .holdEffect = HOLD_EFFECT_GEMS,
        .holdEffectParam = GEM_BOOST_PARAM,
        .description = COMPOUND_STRING(
            "Erhöht die Kraft vom\n"
            "Typ Psycho."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_PSYCHIC,
    },

    [ITEM_BUG_GEM] =
    {
        .name = _("Käferjuwel"),
        .price = (I_PRICE >= GEN_9) ? 15000 : ((I_PRICE >= GEN_7) ? 4000 : 200),
        .holdEffect = HOLD_EFFECT_GEMS,
        .holdEffectParam = GEM_BOOST_PARAM,
        .description = COMPOUND_STRING(
            "Erhöht die Kraft vom\n"
            "Typ Käfer."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_BUG,
    },

    [ITEM_ROCK_GEM] =
    {
        .name = _("Gesteinjuwel"),
        .price = (I_PRICE >= GEN_9) ? 15000 : ((I_PRICE >= GEN_7) ? 4000 : 200),
        .holdEffect = HOLD_EFFECT_GEMS,
        .holdEffectParam = GEM_BOOST_PARAM,
        .description = COMPOUND_STRING(
            "Erhöht die Kraft vom\n"
            "Typ Gestein."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_ROCK,
    },

    [ITEM_GHOST_GEM] =
    {
        .name = _("Geistjuwel"),
        .price = (I_PRICE >= GEN_9) ? 15000 : ((I_PRICE >= GEN_7) ? 4000 : 200),
        .holdEffect = HOLD_EFFECT_GEMS,
        .holdEffectParam = GEM_BOOST_PARAM,
        .description = COMPOUND_STRING(
            "Erhöht die Kraft vom\n"
            "Typ Geist."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_GHOST,
    },

    [ITEM_DRAGON_GEM] =
    {
        .name = _("Drachenjuwel"),
        .price = (I_PRICE >= GEN_9) ? 15000 : ((I_PRICE >= GEN_7) ? 4000 : 200),
        .holdEffect = HOLD_EFFECT_GEMS,
        .holdEffectParam = GEM_BOOST_PARAM,
        .description = COMPOUND_STRING(
            "Erhöht die Kraft vom\n"
            "Typ Drache."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_DRAGON,
    },

    [ITEM_DARK_GEM] =
    {
        .name = _("Unlichtjuwel"),
        .price = (I_PRICE >= GEN_9) ? 15000 : ((I_PRICE >= GEN_7) ? 4000 : 200),
        .holdEffect = HOLD_EFFECT_GEMS,
        .holdEffectParam = GEM_BOOST_PARAM,
        .description = COMPOUND_STRING(
            "Erhöht die Kraft vom\n"
            "Typ Unlicht."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_DARK,
    },

    [ITEM_STEEL_GEM] =
    {
        .name = _("Stahljuwel"),
        .price = (I_PRICE >= GEN_9) ? 15000 : ((I_PRICE >= GEN_7) ? 4000 : 200),
        .holdEffect = HOLD_EFFECT_GEMS,
        .holdEffectParam = GEM_BOOST_PARAM,
        .description = COMPOUND_STRING(
            "Erhöht die Kraft vom\n"
            "Typ Stahl."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_STEEL,
    },

    [ITEM_FAIRY_GEM] =
    {
        .name = _("Feenjuwel"),
        .price = (I_PRICE >= GEN_9) ? 15000 : ((I_PRICE >= GEN_7) ? 4000 : 200),
        .holdEffect = HOLD_EFFECT_GEMS,
        .holdEffectParam = GEM_BOOST_PARAM,
        .description = COMPOUND_STRING(
            "Erhöht die Kraft vom\n"
            "Typ Fee."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_FAIRY,
    },

// Z-Crystals

    [ITEM_NORMALIUM_Z] =
    {
        .name = _("Normium Z"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
        .description = COMPOUND_STRING(
            "Stuft Normal-\n"
            "typ Attacken zu\n"
            "Z-Attacken auf."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_NORMAL
    },

    [ITEM_FIRIUM_Z] =
    {
        .name = _("Pyrium Z"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
        .description = COMPOUND_STRING(
            "Stuft Feuer-\n"
            "typ Attacken zu\n"
            "Z-Attacken auf."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_FIRE
    },

    [ITEM_WATERIUM_Z] =
    {
        .name = _("Aquium Z"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
        .description = COMPOUND_STRING(
            "Stuft Wasser-\n"
            "typ Attacken zu\n"
            "Z-Attacken auf."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_WATER
    },

    [ITEM_ELECTRIUM_Z] =
    {
        .name = _("Voltium Z"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
        .description = COMPOUND_STRING(
            "Stuft Elektro-\n"
            "typ Attacken zu\n"
            "Z-Attacken auf."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_ELECTRIC
    },

    [ITEM_GRASSIUM_Z] =
    {
        .name = _("Botanium Z"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
        .description = COMPOUND_STRING(
            "Stuft Pflanzen-\n"
            "typ Attacken zu\n"
            "Z-Attacken auf."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_GRASS
    },

    [ITEM_ICIUM_Z] =
    {
        .name = _("Glacium Z"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
        .description = COMPOUND_STRING(
            "Stuft Eis-\n"
            "typ Attacken zu\n"
            "Z-Attacken auf."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_ICE
    },

    [ITEM_FIGHTINIUM_Z] =
    {
        .name = _("Battalium Z"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
        .description = COMPOUND_STRING(
            "Stuft Kampf-\n"
            "typ Attacken zu\n"
            "Z-Attacken auf."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_FIGHTING
    },

    [ITEM_POISONIUM_Z] =
    {
        .name = _("Toxium Z"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
        .description = COMPOUND_STRING(
            "Stuft Gift-\n"
            "typ Attacken zu\n"
            "Z-Attacken auf."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_POISON
    },

    [ITEM_GROUNDIUM_Z] =
    {
        .name = _("Terrium Z"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
        .description = COMPOUND_STRING(
            "Stuft Boden-\n"
            "typ Attacken zu\n"
            "Z-Attacken auf."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_GROUND
    },

    [ITEM_FLYINIUM_Z] =
    {
        .name = _("Areium Z"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
        .description = COMPOUND_STRING(
            "Stuft Flug-\n"
            "typ Attacken zu\n"
            "Z-Attacken auf."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_FLYING
    },

    [ITEM_PSYCHIUM_Z] =
    {
        .name = _("Psium Z"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
        .description = COMPOUND_STRING(
            "Stuft Psycho-\n"
            "typ Attacken zu\n"
            "Z-Attacken auf."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_PSYCHIC
    },

    [ITEM_BUGINIUM_Z] =
    {
        .name = _("Insectium Z"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
        .description = COMPOUND_STRING(
            "Stuft Käfer-\n"
            "typ Attacken zu\n"
            "Z-Attacken auf."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_BUG
    },

    [ITEM_ROCKIUM_Z] =
    {
        .name = _("Petrium Z"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
        .description = COMPOUND_STRING(
            "Stuft Gestein-\n"
            "typ Attacken zu\n"
            "Z-Attacken auf."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_ROCK
    },

    [ITEM_GHOSTIUM_Z] =
    {
        .name = _("Phantomium Z"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
        .description = COMPOUND_STRING(
            "Stuft Geist-\n"
            "typ Attacken zu\n"
            "Z-Attacken auf."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_GHOST
    },

    [ITEM_DRAGONIUM_Z] =
    {
        .name = _("Dracium Z"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
        .description = COMPOUND_STRING(
            "Stuft Drachen-\n"
            "typ Attacken zu\n"
            "Z-Attacken auf."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_DRAGON
    },

    [ITEM_DARKINIUM_Z] =
    {
        .name = _("Noctium Z"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
        .description = COMPOUND_STRING(
            "Stuft Unlicht-\n"
            "typ Attacken zu\n"
            "Z-Attacken auf."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_DARK
    },

    [ITEM_STEELIUM_Z] =
    {
        .name = _("Metallium Z"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
        .description = COMPOUND_STRING(
            "Stuft Stahl-\n"
            "typ Attacken zu\n"
            "Z-Attacken auf."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_STEEL
    },

    [ITEM_FAIRIUM_Z] =
    {
        .name = _("Sylphium Z"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
        .description = COMPOUND_STRING(
            "Stuft Fee-\n"
            "typ Attacken zu\n"
            "Z-Attacken auf."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_FAIRY
    },

    [ITEM_PIKANIUM_Z] =
    {
        .name = _("Pikachium Z"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
        .description = COMPOUND_STRING(
            "Stuft Pikachu's\n"
            "Volt-Tackle\n"
            "zu Z-Attacke um."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 255  // signature z move
    },

    [ITEM_EEVIUM_Z] =
    {
        .name = _("Evolium Z"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
        .description = COMPOUND_STRING(
            "Stuft Evoli's\n"
            "Zuflucht Attacke\n"
            "zu Z-Attacke um."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 255  // signature z move
    },

    [ITEM_SNORLIUM_Z] =
    {
        .name = _("Relaxonium Z"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
        .description = COMPOUND_STRING(
            "Stuft Relaxo's\n"
            "Gigastoß Attacke\n"
            "zu Z-Attacke um."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 255  // signature z move
    },

    [ITEM_MEWNIUM_Z] =
    {
        .name = _("Mewnium Z"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
        .description = COMPOUND_STRING(
            "Stuft Mew's\n"
            "Attacke Psychokinese \n"
            "zu Z-Attacke um."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 255  // signature z move
    },

    [ITEM_DECIDIUM_Z] =
    {
        .name = _("SilvarroniumZ"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
        .description = COMPOUND_STRING(
            "Stuft Silvarros\n"
            "Attacke Schattenfessel\n"
            "zu Z-Attacke um."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 255  // signature z move
    },

    [ITEM_INCINIUM_Z] =
    {
        .name = _("Fuegronium Z"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
        .description = COMPOUND_STRING(
            "Stuft Fuegros\n"
            "Attacke Dark Lariat\n"
            "zu Z-Attacke um."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 255  // signature z move
    },

    [ITEM_PRIMARIUM_Z] =
    {
        .name = _("Primarenium Z"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
        .description = COMPOUND_STRING(
            "Stuft Primarenes\n"
            "Schaumserenade\n"
            "zu Z-Attacke um."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 255  // signature z move
    },

    [ITEM_LYCANIUM_Z] =
    {
        .name = _("WolwerockiumZ"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
        .description = COMPOUND_STRING(
            "Stuft Wolwerocks\n"
            "Steinkante\n"
            "zu Z-Attacke um."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 255  // signature z move
    },

    [ITEM_MIMIKIUM_Z] =
    {
        .name = _("Mimigmium Z"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
        .description = COMPOUND_STRING(
            "Stuft Mimigmas\n"
            "Knuddler\n"
            "zu Z-Attacke um."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 255  // signature z move
    },

    [ITEM_KOMMONIUM_Z] =
    {
        .name = _("GrandirasiumZ"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
        .description = COMPOUND_STRING(
            "Stuft Grandiras'\n"
            "Schuppenrasseln\n"
            "zu Z-Attacke um."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 255  // signature z move
    },

    [ITEM_TAPUNIUM_Z] =
    {
        .name = _("Kapium Z"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
        .description = COMPOUND_STRING(
            "Stuft Kapu-Attacke\n"
            "Naturzorn\n"
            "zu Z-Attacke um."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 255  //signature z move
    },

    [ITEM_SOLGANIUM_Z] =
    {
        .name = _("Solgalium Z"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
        .description = COMPOUND_STRING(
            "Stuft Solgaleos\n"
            "Stahlgestirn\n"
            "zu Z-Attacke um."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 255  // signature z move
    },

    [ITEM_LUNALIUM_Z] =
    {
        .name = _("Lunalium Z"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
        .description = COMPOUND_STRING(
            "Stuft Lunalas\n"
            "Schattenstrahl\n"
            "zu Z-Attacke um."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 255  // signature z move
    },

    [ITEM_MARSHADIUM_Z] =
    {
        .name = _("MarshadowniuZ"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
        .description = COMPOUND_STRING(
            "Stuft Marshadows\n"
            "Diebesschatten\n"
            "zu Z-Attacke um."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 255  // signature z move
    },

    [ITEM_ALORAICHIUM_Z] =
    {
        .name = _("A-RaichuniumZ"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
        .description = COMPOUND_STRING(
            "Stuft Alola-Raichu's\n"
            "Donnerblitz\n"
            "zu Z-Attacke um."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 255  // signature z move
    },

    [ITEM_PIKASHUNIUM_Z] =
    {
        .name = _("AshPikachiumZ"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
        .description = COMPOUND_STRING(
            "Stuft Pikachu mit\n"
            "Kappe's Donnerblitz\n"
            "zu Z-Attacke um."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 255  // signature z move
    },

    [ITEM_ULTRANECROZIUM_Z] =
    {
        .name = _("U-Necronium Z"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
        .description = COMPOUND_STRING(
            "Ein Kristall, der verschmol-\n"
            "zenes Necrozma in eine\n"
            "neue Form verwandelt."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 255  //signature z move
    },

// Species-specific Held Items

    [ITEM_LIGHT_BALL] =
    {
        .name = _("Kugelblitz"),
        .price = (I_PRICE >= GEN_7) ? 1000 : 100,
        .holdEffect = HOLD_EFFECT_LIGHT_BALL,
        .description = COMPOUND_STRING(
            "Item (Tragen)\n"
            "erhöht PIKACHUS\n"
            "SP. ANGR."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
    },

    [ITEM_LEEK] =
    {
        .name = _("Lauchstange"),
        .price = (I_PRICE >= GEN_7) ? 1000 : 200,
        .holdEffect = HOLD_EFFECT_LEEK,
        .description = COMPOUND_STRING(
            "Item (Tragen) erhöht\n"
            "Volltrefferquote von\n"
            "Porenta."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 60,
    },

    [ITEM_THICK_CLUB] =
    {
        .name = _("Kampfknochen"),
        .price = (I_PRICE >= GEN_7) ? 1000 : 500,
        .holdEffect = HOLD_EFFECT_THICK_CLUB,
        .description = COMPOUND_STRING(
            "Irgendeine Art\n"
            "Knochen von\n"
            "geringem Wert."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 90,
    },

    [ITEM_LUCKY_PUNCH] =
    {
        .name = _("Lucky Punch"),
        .pluralName = _("Lucky Punches"),
        .price = (I_PRICE >= GEN_7) ? 1000 : 10,
        .holdEffect = HOLD_EFFECT_LUCKY_PUNCH,
        .description = COMPOUND_STRING(
            "Item (Tragen)\n"
            "erhöht CHANEIRAS\n"
            "Volltrefferquote."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 40,
    },

    [ITEM_METAL_POWDER] =
    {
        .name = _("Metalstaub"),
        .pluralName = _("Metalstaub"),
        .price = (I_PRICE >= GEN_7) ? 1000 : 10,
        .holdEffect = HOLD_EFFECT_METAL_POWDER,
        .description = COMPOUND_STRING(
            "Item (Tragen)\n"
            "erhöht VERT.-Wert\n"
            "von DITTO."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

    [ITEM_QUICK_POWDER] =
    {
        .name = _("Flottstaub"),
        .pluralName = _("Flottstaub"),
        .price = (I_PRICE >= GEN_7) ? 1000 : 10,
        .holdEffect = HOLD_EFFECT_QUICK_POWDER,
        .description = COMPOUND_STRING(
            "Item (Tragen)\n"
            "erhöht Init.-Wert\n"
            "von DITTO."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

    [ITEM_DEEP_SEA_SCALE] =
    {
        .name = _("Abyssplatte"),
        .price = (I_PRICE >= GEN_7) ? 2000 : 200,
        .holdEffect = HOLD_EFFECT_DEEP_SEA_SCALE,
        .description = COMPOUND_STRING(
            "Item (Tragen) hebt\n"
            "SP. VERT. von\n"
            "PERLU."),
        .pocket = POCKET_ITEMS,
        .type = EVO_HELD_ITEM_TYPE,
        .fieldUseFunc = EVO_HELD_ITEM_FIELD_FUNC,
        .effect = gItemEffect_EvoItem,
        .flingPower = 30,
    },

    [ITEM_DEEP_SEA_TOOTH] =
    {
        .name = _("Abysszahn"),
        .pluralName = _("Abysszähne"),
        .price = (I_PRICE >= GEN_7) ? 2000 : 200,
        .holdEffect = HOLD_EFFECT_DEEP_SEA_TOOTH,
        .description = COMPOUND_STRING(
            "Item (Tragen) hebt\n"
            "SP. ANGR. von\n"
            "PERLU."),
        .pocket = POCKET_ITEMS,
        .type = EVO_HELD_ITEM_TYPE,
        .fieldUseFunc = EVO_HELD_ITEM_FIELD_FUNC,
        .effect = gItemEffect_EvoItem,
        .flingPower = 90,
    },

    [ITEM_SOUL_DEW] =
    {
        .name = _("Seelentau"),
        .price = (I_PRICE >= GEN_7) ? 0 : 200,
        .holdEffect = HOLD_EFFECT_SOUL_DEW,
        .holdEffectParam = B_SOUL_DEW_BOOST >= GEN_7 ? 20 : 50,
        .description = COMPOUND_STRING(
        #if B_SOUL_DEW_BOOST >= GEN_7
            "Stärkt Latios' &\n"
            "Latias' Psycho and\n"
            "Drachen-Attacken."),
        #else
            "Hold item: raises\n"
            "Sp. Atk & Sp. Def of\n"
            "Latios & Latias."),
        #endif
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
    },

    [ITEM_ADAMANT_ORB] =
    {
        .name = _("Adamant Orb"),
        .price = (I_PRICE >= GEN_7) ? 0 : 10000,
        .holdEffect = HOLD_EFFECT_ADAMANT_ORB,
        .holdEffectParam = 20,
        .description = COMPOUND_STRING(
            "Verstärkt Dialga's\n"
            "Drachen und Stahl\n"
            "Attacken."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 60,
    },

    [ITEM_LUSTROUS_ORB] =
    {
        .name = _("Weiß Orb"),
        .price = (I_PRICE >= GEN_7) ? 0 : 10000,
        .holdEffect = HOLD_EFFECT_LUSTROUS_ORB,
        .holdEffectParam = 20,
        .description = COMPOUND_STRING(
            "Verstärkt Palkias's\n"
            "Drachen und Wasser\n"
            "Attacken."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 60,
    },

    [ITEM_GRISEOUS_ORB] =
    {
        .name = _("Platinum Orb"),
        .price = (I_PRICE >= GEN_7) ? 0 : 10000,
        .holdEffect = HOLD_EFFECT_GRISEOUS_ORB,
        .holdEffectParam = 20,
        .description = COMPOUND_STRING(
            "Verstärkt Girantina's\n"
            "Drachen und Geist\n"
            "Attacken."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 60,
    },

// Incenses

    [ITEM_SEA_INCENSE] =
    {
        .name = _("Seerauch"),
        .price = (I_PRICE >= GEN_7) ? 2000 : 9600,
        .holdEffect = HOLD_EFFECT_WATER_POWER,
        .holdEffectParam = 20,
        .description = sSeaIncenseDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

    [ITEM_LAX_INCENSE] =
    {
        .name = _("Laxrauch"),
        .price = (I_PRICE >= GEN_7) ? 5000 : 9600,
        .holdEffect = HOLD_EFFECT_EVASION_UP,
        .holdEffectParam = 10,
        .description = COMPOUND_STRING(
            "Item Tragen\n"
            "senkt Genauigkeit\n"
            "des Gegners."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

    [ITEM_ODD_INCENSE] =
    {
        .name = _("Schrägrauch"),
        .price = (I_PRICE >= GEN_7) ? 2000 : 9600,
        .holdEffect = HOLD_EFFECT_PSYCHIC_POWER,
        .holdEffectParam = 20,
        .description = sOddIncenseDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

    [ITEM_ROCK_INCENSE] =
    {
        .name = _("Steinrauch"),
        .price = (I_PRICE >= GEN_7) ? 2000 : 9600,
        .holdEffect = HOLD_EFFECT_ROCK_POWER,
        .holdEffectParam = 20,
        .description = sRockIncenseDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

    [ITEM_FULL_INCENSE] =
    {
        .name = _("Lahmrauch"),
        .price = (I_PRICE >= GEN_7) ? 5000 : 9600,
        .holdEffect = HOLD_EFFECT_LAGGING_TAIL,
        .holdEffectParam = 5,
        .description = sFullIncenseDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

    [ITEM_WAVE_INCENSE] =
    {
        .name = _("Wellenrauch"),
        .price = (I_PRICE >= GEN_7) ? 2000 : 9600,
        .holdEffect = HOLD_EFFECT_WATER_POWER,
        .holdEffectParam = 20,
        .description = sSeaIncenseDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

    [ITEM_ROSE_INCENSE] =
    {
        .name = _("Rosenrauch"),
        .price = (I_PRICE >= GEN_7) ? 2000 : 9600,
        .holdEffect = HOLD_EFFECT_GRASS_POWER,
        .holdEffectParam = 20,
        .description = sRoseIncenseDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

    [ITEM_LUCK_INCENSE] =
    {
        .name = _("Glücksrauch"),
        .price = (I_PRICE >= GEN_7) ? 11000 : 9600,
        .holdEffect = HOLD_EFFECT_DOUBLE_PRIZE,
        .description = sLuckIncenseDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

    [ITEM_PURE_INCENSE] =
    {
        .name = _("Scheuchrauch"),
        .price = (I_PRICE >= GEN_7) ? 6000 : 9600,
        .holdEffect = HOLD_EFFECT_REPEL,
        .description = sPureIncenseDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

// Contest Scarves

    [ITEM_RED_SCARF] =
    {
        .name = _("Roter Schal"),
        .pluralName = _("Roter Schal"),
        .price = 100,
        .description = COMPOUND_STRING(
            "Item (Tragen) hebt\n"
            "COOL.-Wert für den\n"
            "WETTBEWERB."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

    [ITEM_BLUE_SCARF] =
    {
        .name = _("Blauer Schal"),
        .pluralName = _("Blauer Schal"),
        .price = 100,
        .description = COMPOUND_STRING(
            "Item (Tragen) hebt\n"
            "SCHÖN.-Wert für den\n"
            "WETTBEWERB."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

    [ITEM_PINK_SCARF] =
    {
        .name = _("Pinker Schal"),
        .pluralName = _("Pinker Schal"),
        .price = 100,
        .description = COMPOUND_STRING(
            "Item (Tragen) hebt\n"
            "ANMUT-Wert für den\n"
            "WETTBEWERB."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

    [ITEM_GREEN_SCARF] =
    {
        .name = _("Grüner Schal"),
        .pluralName = _("Grüner Schal"),
        .price = 100,
        .description = COMPOUND_STRING(
            "Item (Tragen) hebt\n"
            "KLUG.-Wert für den\n"
            "WETTBEWERB."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

    [ITEM_YELLOW_SCARF] =
    {
        .name = _("Gelber schal"),
        .pluralName = _("Gelber Schal"),
        .price = 100,
        .description = COMPOUND_STRING(
            "Item (Tragen) hebt\n"
            "STÄRKE-Wert für\n"
            "den WETTBEWERB."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

// EV Gain Modifiers

    [ITEM_MACHO_BRACE] =
    {
        .name = _("Machoband"),
        .price = 3000,
        .holdEffect = HOLD_EFFECT_MACHO_BRACE,
        .description = COMPOUND_STRING(
            "Item (Tragen) för-\n"
            "dert Wachstum,\n"
            "aber senkt INIT."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 60,
    },

    [ITEM_POWER_WEIGHT] =
    {
        .name = _("Machtgewicht"),
        .price = (I_PRICE >= GEN_9) ? 10000 : 3000,
        .holdEffect = HOLD_EFFECT_POWER_ITEM,
        .holdEffectParam = POWER_ITEM_BOOST,
        .description = COMPOUND_STRING(
            "Ein Item zum Tragen. Erhöht\n"
            "bei Levelaufstieg die,\n"
            "max. KP senkt aber die init."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = STAT_HP,
        .flingPower = 70,
    },

    [ITEM_POWER_BRACER] =
    {
        .name = _("Machtreif"),
        .price = (I_PRICE >= GEN_9) ? 10000 : 3000,
        .holdEffect = HOLD_EFFECT_POWER_ITEM,
        .holdEffectParam = POWER_ITEM_BOOST,
        .description = COMPOUND_STRING(
            "Ein Item zum Tragen. Erhöht\n"
            "bei Levelaufstieg den,\n"
            "Angriff senkt aber die init."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = STAT_ATK,
        .flingPower = 70,
    },

    [ITEM_POWER_BELT] =
    {
        .name = _("Machtgurt"),
        .price = (I_PRICE >= GEN_9) ? 10000 : 3000,
        .holdEffect = HOLD_EFFECT_POWER_ITEM,
        .holdEffectParam = POWER_ITEM_BOOST,
        .description = COMPOUND_STRING(
            "Ein Item zum Tragen. Erhöht\n"
            "bei Levelaufstieg die,\n"
            "Vert. senkt aber die init."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = STAT_DEF,
        .flingPower = 70,
    },

    [ITEM_POWER_LENS] =
    {
        .name = _("Machtlinse"),
        .pluralName = _("Power Lenses"),
        .price = (I_PRICE >= GEN_9) ? 10000 : 3000,
        .holdEffect = HOLD_EFFECT_POWER_ITEM,
        .holdEffectParam = POWER_ITEM_BOOST,
        .description = COMPOUND_STRING(
            "Ein Item zum Tragen. Erhöht\n"
            "bei Levelaufstieg den SP.\n"
            "Angriff senkt aber die init."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = STAT_SPATK,
        .flingPower = 70,
    },

    [ITEM_POWER_BAND] =
    {
        .name = _("Machtband"),
        .price = (I_PRICE >= GEN_9) ? 10000 : 3000,
        .holdEffect = HOLD_EFFECT_POWER_ITEM,
        .holdEffectParam = POWER_ITEM_BOOST,
        .description = COMPOUND_STRING(
            "Ein Item zum Tragen. Erhöht\n"
            "bei Levelaufstieg die SP.\n"
            "Vert. senkt aber die init."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = STAT_SPDEF,
        .flingPower = 70,
    },

    [ITEM_POWER_ANKLET] =
    {
        .name = _("Machtkette"),
        .price = (I_PRICE >= GEN_9) ? 10000 : 3000,
        .holdEffect = HOLD_EFFECT_POWER_ITEM,
        .holdEffectParam = POWER_ITEM_BOOST,
        .description = COMPOUND_STRING(
            "Ein Item zum Tragen. Erhöht\n"
            "bei Levelaufstieg die Init-\n"
            "iative-Wert, senkt aber die init."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = STAT_SPEED,
        .flingPower = 70,
    },

// Type-boosting Held Items

    [ITEM_SILK_SCARF] =
    {
        .name = _("Seidenschal"),
        .pluralName = _("Seidenschal"),
        .price = (I_PRICE >= GEN_9) ? 3000 : ((I_PRICE >= GEN_7) ? 1000 : 100),
        .holdEffect = HOLD_EFFECT_NORMAL_POWER,
        .holdEffectParam = TYPE_BOOST_PARAM,
        .description = COMPOUND_STRING(
            "Item (Tragen)\n"
            "verstärkt NORMAL-\n"
            "Attacken."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

    [ITEM_CHARCOAL] =
    {
        .name = _("Holzkohle"),
        .price = (I_PRICE >= GEN_9) ? 3000 : ((I_PRICE >= GEN_7) ? 1000 : 9800),
        .holdEffect = HOLD_EFFECT_FIRE_POWER,
        .holdEffectParam = TYPE_BOOST_PARAM,
        .description = COMPOUND_STRING(
            "Item (Tragen)\n"
            "verstärkt Feuer-\n"
            "Attacken."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
    },

    [ITEM_MYSTIC_WATER] =
    {
        .name = _("Zauberwasser"),
        .pluralName = _("Zauberwasser"),
        .price = (I_PRICE >= GEN_9) ? 3000 : ((I_PRICE >= GEN_7) ? 1000 : 100),
        .holdEffect = HOLD_EFFECT_WATER_POWER,
        .holdEffectParam = TYPE_BOOST_PARAM,
        .description = COMPOUND_STRING(
            "Item (Tragen)\n"
            "verstärkt Wasser-\n"
            "Attacken."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
    },

    [ITEM_MAGNET] =
    {
        .name = _("Magnet"),
        .price = (I_PRICE >= GEN_9) ? 3000 : ((I_PRICE >= GEN_7) ? 1000 : 100),
        .holdEffect = HOLD_EFFECT_ELECTRIC_POWER,
        .holdEffectParam = TYPE_BOOST_PARAM,
        .description = COMPOUND_STRING(
            "Item (Tragen)\n"
            "verstärkt Elektro-\n"
            "Attacken."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
    },

    [ITEM_MIRACLE_SEED] =
    {
        .name = _("Wundersaat"),
        .price = (I_PRICE >= GEN_9) ? 3000 : ((I_PRICE >= GEN_7) ? 1000 : 100),
        .holdEffect = HOLD_EFFECT_GRASS_POWER,
        .holdEffectParam = TYPE_BOOST_PARAM,
        .description = sRoseIncenseDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
    },

    [ITEM_NEVER_MELT_ICE] =
    {
        .name = _("Ewiges Eis"),
        .pluralName = _("Ewiges Eis"),
        .price = (I_PRICE >= GEN_9) ? 3000 : ((I_PRICE >= GEN_7) ? 1000 : 100),
        .holdEffect = HOLD_EFFECT_ICE_POWER,
        .holdEffectParam = TYPE_BOOST_PARAM,
        .description = COMPOUND_STRING(
            "Item (Tragen)\n"
            "verstärkt Eis-\n"
            "Attacken."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
    },

    [ITEM_BLACK_BELT] =
    {
        .name = _("Schwarzgurt"),
        .price = (I_PRICE >= GEN_9) ? 3000 : ((I_PRICE >= GEN_7) ? 1000 : 100),
        .holdEffect = HOLD_EFFECT_FIGHTING_POWER,
        .holdEffectParam = TYPE_BOOST_PARAM,
        .description = COMPOUND_STRING(
            "Item (Tragen)\n"
            "verstärkt Kampf-\n"
            "Attacken."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
    },

    [ITEM_POISON_BARB] =
    {
        .name = _("Giftsich"),
        .price = (I_PRICE >= GEN_9) ? 3000 : ((I_PRICE >= GEN_7) ? 1000 : 100),
        .holdEffect = HOLD_EFFECT_POISON_POWER,
        .holdEffectParam = TYPE_BOOST_PARAM,
        .description = COMPOUND_STRING(
            "Item (Tragen)\n"
            "verstärkt Gift-\n"
            "Attacken."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 70,
    },

    [ITEM_SOFT_SAND] =
    {
        .name = _("Pudersand"),
        .pluralName = _("Pudersand"),
        .price = (I_PRICE >= GEN_9) ? 3000 : ((I_PRICE >= GEN_7) ? 1000 : 100),
        .holdEffect = HOLD_EFFECT_GROUND_POWER,
        .holdEffectParam = TYPE_BOOST_PARAM,
        .description = COMPOUND_STRING(
            "Item (Tragen)\n"
            "verstärkt Boden-\n"
            "Attacken."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

    [ITEM_SHARP_BEAK] =
    {
        .name = _("Hackattack"),
        .price = (I_PRICE >= GEN_9) ? 3000 : ((I_PRICE >= GEN_7) ? 1000 : 100),
        .holdEffect = HOLD_EFFECT_FLYING_POWER,
        .holdEffectParam = TYPE_BOOST_PARAM,
        .description = COMPOUND_STRING(
            "Item (Tragen)\n"
            "verstärkt Flug-\n"
            "Attacken."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 50,
    },

    [ITEM_TWISTED_SPOON] =
    {
        .name = _("Krummlöffel"),
        .price = (I_PRICE >= GEN_9) ? 3000 : ((I_PRICE >= GEN_7) ? 1000 : 100),
        .holdEffect = HOLD_EFFECT_PSYCHIC_POWER,
        .holdEffectParam = TYPE_BOOST_PARAM,
        .description = sOddIncenseDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
    },

    [ITEM_SILVER_POWDER] =
    {
        .name = _("Silberstaub"),
        .pluralName = _("Silberstaub"),
        .price = (I_PRICE >= GEN_9) ? 3000 : ((I_PRICE >= GEN_7) ? 1000 : 100),
        .holdEffect = HOLD_EFFECT_BUG_POWER,
        .holdEffectParam = TYPE_BOOST_PARAM,
        .description = COMPOUND_STRING(
            "Item (Tragen)\n"
            "verstärkt Käfer-\n"
            "Attacken."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

    [ITEM_HARD_STONE] =
    {
        .name = _("Granitstein"),
        .price = (I_PRICE >= GEN_9) ? 3000 : ((I_PRICE >= GEN_7) ? 1000 : 100),
        .holdEffect = HOLD_EFFECT_ROCK_POWER,
        .holdEffectParam = TYPE_BOOST_PARAM,
        .description = sRockIncenseDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 100,
    },

    [ITEM_SPELL_TAG] =
    {
        .name = _("Bannsticker"),
        .price = (I_PRICE >= GEN_9) ? 3000 : ((I_PRICE >= GEN_7) ? 1000 : 100),
        .holdEffect = HOLD_EFFECT_GHOST_POWER,
        .holdEffectParam = TYPE_BOOST_PARAM,
        .description = COMPOUND_STRING(
            "Item (Tragen)\n"
            "verstärkt Geist-\n"
            "Attacken."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
    },

    [ITEM_DRAGON_FANG] =
    {
        .name = _("Drachenzahn"),
        .price = (I_PRICE >= GEN_9) ? 3000 : ((I_PRICE >= GEN_7) ? 1000 : 100),
        .holdEffect = HOLD_EFFECT_DRAGON_POWER,
        .holdEffectParam = TYPE_BOOST_PARAM,
        .description = COMPOUND_STRING(
            "Item (Tragen)\n"
            "verstärkt Drachen-\n"
            "Attacken."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 70,
    },

    [ITEM_BLACK_GLASSES] =
    {
        .name = _("Schattenglas"),
        .pluralName = _("Schattengläser"),
        .price = (I_PRICE >= GEN_9) ? 3000 : ((I_PRICE >= GEN_7) ? 1000 : 100),
        .holdEffect = HOLD_EFFECT_DARK_POWER,
        .holdEffectParam = TYPE_BOOST_PARAM,
        .description = COMPOUND_STRING(
            "Item (Tragen)\n"
            "verstärkt Unlicht-\n"
            "Attacken."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
    },

    [ITEM_METAL_COAT] =
    {
        .name = _("Metallmantel"),
        .price = (I_PRICE >= GEN_9) ? 3000 : ((I_PRICE >= GEN_7) ? 2000 : 100),
        .holdEffect = HOLD_EFFECT_STEEL_POWER,
        .holdEffectParam = TYPE_BOOST_PARAM,
        .description = COMPOUND_STRING(
            "Item (Tragen)\n"
            "verstärkt Stahl-\n"
            "Attacken."),
        .pocket = POCKET_ITEMS,
        .type = EVO_HELD_ITEM_TYPE,
        .fieldUseFunc = EVO_HELD_ITEM_FIELD_FUNC,
        .effect = gItemEffect_EvoItem,
        .flingPower = 30,
    },

// Choice Items

    [ITEM_CHOICE_BAND] =
    {
        .name = _("Wahlband"),
        .price = (I_PRICE >= GEN_9) ? 100000 : ((I_PRICE >= GEN_7) ? 4000 : 100),
        .holdEffect = HOLD_EFFECT_CHOICE_BAND,
        .description = COMPOUND_STRING(
            "Stärkt eine Atta-\n"
            "cke. Aber nur diese\n"
            "ist einsetzbar."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

    [ITEM_CHOICE_SPECS] =
    {
        .name = _("Wahlbrille"),
        .pluralName = _("Wahlbrillen"),
        .price = (I_PRICE >= GEN_9) ? 100000 : ((I_PRICE >= GEN_7) ? 4000 : 100),
        .holdEffect = HOLD_EFFECT_CHOICE_SPECS,
        .description = COMPOUND_STRING(
            "Die Brille erhöht den Sp.-\n"
            "Angriff, erlaubt aber\n"
            "nur eine Attackenart."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

    [ITEM_CHOICE_SCARF] =
    {
        .name = _("Wahlschal"),
        .pluralName = _("Wahlschals"),
        .price = (I_PRICE >= GEN_9) ? 100000 : ((I_PRICE >= GEN_7) ? 4000 : 100),
        .holdEffect = HOLD_EFFECT_CHOICE_SCARF,
        .description = COMPOUND_STRING(
            "Der Schal erhöht den Init.\n"
            "Wert, erlaubt aber\n"
            "nur eine Attackenart."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

// Status Orbs

    [ITEM_FLAME_ORB] =
    {
        .name = _("Heiß-Orb"),
        .price = (I_PRICE >= GEN_9) ? 15000 : ((I_PRICE >= GEN_7) ? 4000 : 200),
        .holdEffect = HOLD_EFFECT_FLAME_ORB,
        .description = COMPOUND_STRING(
            "Dieser bizarre Orb fügt\n"
            "seinem Träger\n"
            "Verbrennungen zu."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
    },

    [ITEM_TOXIC_ORB] =
    {
        .name = _("Toxik-Orb"),
        .price = (I_PRICE >= GEN_9) ? 15000 : ((I_PRICE >= GEN_7) ? 4000 : 200),
        .holdEffect = HOLD_EFFECT_TOXIC_ORB,
        .description = COMPOUND_STRING(
            "Dieser bizarre Orb fügt\n"
            "vergiftet seinen Träger\n"
            "im Kampf schwer."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
    },

// Weather Rocks

    [ITEM_DAMP_ROCK] =
    {
        .name = _("Nassbrocken"),
        .price = (I_PRICE >= GEN_9) ? 8000 : ((I_PRICE >= GEN_7) ? 4000 : 200),
        .holdEffect = HOLD_EFFECT_DAMP_ROCK,
        .description = COMPOUND_STRING(
            "Ein Item zum Tragen.\n"
            "Verlängert die Dauer\n"
            "von Regentanz."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 60,
    },

    [ITEM_HEAT_ROCK] =
    {
        .name = _("Heißbrocken"),
        .price = (I_PRICE >= GEN_9) ? 8000 : ((I_PRICE >= GEN_7) ? 4000 : 200),
        .holdEffect = HOLD_EFFECT_HEAT_ROCK,
        .description = COMPOUND_STRING(
            "Ein Item zum Tragen.\n"
            "Verlängert die Dauer\n"
            "von Sonnentag."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 60,
    },

    [ITEM_SMOOTH_ROCK] =
    {
        .name = _("Glattbrocken"),
        .price = (I_PRICE >= GEN_9) ? 8000 : ((I_PRICE >= GEN_7) ? 4000 : 200),
        .holdEffect = HOLD_EFFECT_SMOOTH_ROCK,
        .description = COMPOUND_STRING(
            "Ein Item zum Tragen.\n"
            "Verlängert die Dauer\n"
            "von Sandsturm."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

    [ITEM_ICY_ROCK] =
    {
        .name = _("Eisbrocken"),
        .price = (I_PRICE >= GEN_9) ? 8000 : ((I_PRICE >= GEN_7) ? 4000 : 200),
        .holdEffect = HOLD_EFFECT_ICY_ROCK,
        .description = COMPOUND_STRING(
            "Ein Item zum Tragen.\n"
            "Verlängert die Dauer\n"
            "von Hagelsturm."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 40,
    },

// Terrain Seeds

    [ITEM_ELECTRIC_SEED] =
    {
        .name = _("Elektro-Samen"),
        .price = (I_PRICE >= GEN_9) ? 20000 : 4000,
        .holdEffect = HOLD_EFFECT_SEEDS,
        .holdEffectParam = HOLD_EFFECT_PARAM_ELECTRIC_TERRAIN,
        .description = COMPOUND_STRING(
            "Erhöht die Vert. auf\n"
            "Elektrofeld,\n"
            "aber nur einmal."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

    [ITEM_PSYCHIC_SEED] =
    {
        .name = _("Psycho-samen"),
        .price = (I_PRICE >= GEN_9) ? 20000 : 4000,
        .holdEffect = HOLD_EFFECT_SEEDS,
        .holdEffectParam = HOLD_EFFECT_PARAM_PSYCHIC_TERRAIN,
        .description = COMPOUND_STRING(
            "Erhöht die SP.Vert. auf\n"
            "Psychofeld,\n"
            "aber nur einmal."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

    [ITEM_MISTY_SEED] =
    {
        .name = _("Nebel-Samen"),
        .price = (I_PRICE >= GEN_9) ? 20000 : 4000,
        .holdEffect = HOLD_EFFECT_SEEDS,
        .holdEffectParam = HOLD_EFFECT_PARAM_MISTY_TERRAIN,
        .description = COMPOUND_STRING(
            "Erhöht die SP.Vert. auf\n"
            "Nebelfeld,\n"
            "aber nur einmal."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

    [ITEM_GRASSY_SEED] =
    {
        .name = _("Pflanzensamen"),
        .price = (I_PRICE >= GEN_9) ? 20000 : 4000,
        .holdEffect = HOLD_EFFECT_SEEDS,
        .holdEffectParam = HOLD_EFFECT_PARAM_GRASSY_TERRAIN,
        .description = COMPOUND_STRING(
            "Erhöht die Vert. auf\n"
            "Grasfeld,\n"
            "aber nur einmal."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

// Type-activated Stat Modifiers

    [ITEM_ABSORB_BULB] =
    {
        .name = _("Knolle"),
        .price = (I_PRICE >= GEN_9) ? 5000 : ((I_PRICE >= GEN_7) ? 4000 : 200),
        .holdEffect = HOLD_EFFECT_ABSORB_BULB,
        .holdEffectParam = 0,
        .description = COMPOUND_STRING(
            "Erhöht den Spez.-Angr.\n"
            "des Trägers, wenn ihn\n"
            "eine Wasserattacke trifft."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
    },

    [ITEM_CELL_BATTERY] =
    {
        .name = _("Akku"),
        .pluralName = _("Akkus"),
        .price = (I_PRICE >= GEN_9) ? 5000 : ((I_PRICE >= GEN_7) ? 4000 : 200),
        .holdEffect = HOLD_EFFECT_CELL_BATTERY,
        .holdEffectParam = 0,
        .description = COMPOUND_STRING(
            "Erhöht den Angriff\n"
            "des Trägers, wenn ihn\n"
            "eine Eletroattacke trifft."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
    },

    [ITEM_LUMINOUS_MOSS] =
    {
        .name = _("Leuchtmoos"),
        .pluralName = _("Leuchtmoos"),
        .price = (I_PRICE >= GEN_9) ? 5000 : ((I_PRICE >= GEN_7) ? 4000 : 1000),
        .holdEffect = HOLD_EFFECT_LUMINOUS_MOSS,
        .holdEffectParam = 0,
        .description = COMPOUND_STRING(
            "Erhöht die SP. Vert.\n"
            "des Trägers, wenn ihn\n"
            "eine Wasserattacke trifft."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
    },

    [ITEM_SNOWBALL] =
    {
        .name = _("Schneeball"),
        .price = (I_PRICE >= GEN_9) ? 5000 : ((I_PRICE >= GEN_7) ? 4000 : 200),
        .holdEffect = HOLD_EFFECT_SNOWBALL,
        .holdEffectParam = 0,
        .description = COMPOUND_STRING(
            "Erhöht den Angriff\n"
            "des Trägers, wenn ihn\n"
            "eine Eisattacke trifft."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
    },

// Misc. Held Items

    [ITEM_BRIGHT_POWDER] =
    {
        .name = _("Blendpuder"),
        .pluralName = _("Blendpuder"),
        .price = (I_PRICE >= GEN_9) ? 30000 : ((I_PRICE >= GEN_7) ? 4000 : 10),
        .holdEffect = HOLD_EFFECT_EVASION_UP,
        .holdEffectParam = 10,
        .description = COMPOUND_STRING(
            "Item (Tragen)\n"
            "senkt die Genauig-\n"
            "keit des Gegners."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

    [ITEM_WHITE_HERB] =
    {
        .name = _("Schlohkraut"),
        .price = (I_PRICE >= GEN_9) ? 20000 : ((I_PRICE >= GEN_7) ? 4000 : 100),
        .holdEffect = HOLD_EFFECT_RESTORE_STATS,
        .description = COMPOUND_STRING(
            "Item (Tragen) hebt\n"
            "jede Statusverän-\n"
            "derung auf."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

    [ITEM_EXP_SHARE] =
    {
        .name = _("EP-Teiler"),
        .holdEffect = HOLD_EFFECT_EXP_SHARE,
        #if I_EXP_SHARE_ITEM >= GEN_6
            .price = 0,
            .description = COMPOUND_STRING(
                "Dieses Gerät teilt die\n"
                "EP an alle Pokémon\n"
                "im Team auf."),
        #else
            .price = 3000,
            .description = COMPOUND_STRING(
                "Item (Tragen) teilt\n"
                "die Kampf-EP."),
        #endif
        .pocket = I_EXP_SHARE_ITEM >= GEN_6 ? POCKET_KEY_ITEMS : POCKET_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_ExpShare,
        .flingPower = 30,
    },

    [ITEM_QUICK_CLAW] =
    {
        .name = _("Flinkklaue"),
        .price = (I_PRICE >= GEN_9) ? 8000 : ((I_PRICE >= GEN_7) ? 4000 : 100),
        .holdEffect = HOLD_EFFECT_QUICK_CLAW,
        .holdEffectParam = 20,
        .description = COMPOUND_STRING(
            "Item (Tragen) hebt\n"
            "die Erstschlag-\n"
            "quote."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
    },

    [ITEM_SOOTHE_BELL] =
    {
        .name = _("Sanftglocke"),
        .price = (I_PRICE >= GEN_9) ? 5000 : ((I_PRICE >= GEN_7) ? 4000 : 100),
        .holdEffect = HOLD_EFFECT_FRIENDSHIP_UP,
        .description = COMPOUND_STRING(
            "Item (Tragen) be-\n"
            "sänftigt und för-\n"
            "dert Sympathie."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

    [ITEM_MENTAL_HERB] =
    {
        .name = _("Mentalkraut"),
        .price = (I_PRICE >= GEN_9) ? 10000 : ((I_PRICE >= GEN_7) ? 4000 : 100),
        .holdEffect = HOLD_EFFECT_MENTAL_HERB,
        .description = COMPOUND_STRING(
        #if B_MENTAL_HERB >= GEN_5
            "Befreit Pokémon von\n"
            "Bewegungsbindungs-\n"
            "effekten."),
        #else
            "Item (Tragen) er-\n"
            "löst POKéMON von\n"
            "der Anziehung."),
        #endif
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

    [ITEM_KINGS_ROCK] =
    {
        .name = _("King-Stein"),
        .price = (I_PRICE >= GEN_9) ? 10000 : ((I_PRICE >= GEN_7) ? 5000 : 100),
        .holdEffect = HOLD_EFFECT_FLINCH,
        .holdEffectParam = 10,
        .description = sKingsRockDesc,
        .pocket = POCKET_ITEMS,
        .type = EVO_HELD_ITEM_TYPE,
        .fieldUseFunc = EVO_HELD_ITEM_FIELD_FUNC,
        .effect = gItemEffect_EvoItem,
        .flingPower = 30,
    },

    [ITEM_AMULET_COIN] =
    {
        .name = _("Münzamulett"),
        .price = (I_PRICE >= GEN_9) ? 30000 : ((I_PRICE >= GEN_7) ? 10000 : 100),
        .holdEffect = HOLD_EFFECT_DOUBLE_PRIZE,
        .description = sLuckIncenseDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
    },

    [ITEM_CLEANSE_TAG] =
    {
        .name = _("Schutzband"),
        .price = (I_PRICE >= GEN_7) ? 5000 : 200,
        .holdEffect = HOLD_EFFECT_REPEL,
        .description = sPureIncenseDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
    },

    [ITEM_SMOKE_BALL] =
    {
        .name = _("Rauchball"),
        .price = (I_PRICE >= GEN_9) ? 15000 : ((I_PRICE >= GEN_7) ? 4000 : 200),
        .holdEffect = HOLD_EFFECT_CAN_ALWAYS_RUN,
        .description = COMPOUND_STRING(
            "Item (Tragen) er-\n"
            "möglicht Flucht vor\n"
            "wilden POKéMON."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
    },

    [ITEM_FOCUS_BAND] =
    {
        .name = _("Fokusband"),
        .price = (I_PRICE >= GEN_9) ? 10000 : ((I_PRICE >= GEN_7) ? 4000 : 200),
        .holdEffect = HOLD_EFFECT_FOCUS_BAND,
        .holdEffectParam = 10,
        .description = COMPOUND_STRING(
            "Item (Tragen) kann\n"
            "manchmal K.O.\n"
            "verhindern."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

    [ITEM_LUCKY_EGG] =
    {
        .name = _("Glücks-Ei"),
        .price = (I_PRICE >= GEN_7) ? 10000 : 200,
        .holdEffect = HOLD_EFFECT_LUCKY_EGG,
        .description = COMPOUND_STRING(
            "Item (Tragen)\n"
            "erhöht im Kampf er-\n"
            "haltene Extra-EP."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
    },

    [ITEM_SCOPE_LENS] =
    {
        .name = _("Scope Linses"),
        .pluralName = _("Scope Linse"),
        .price = (I_PRICE >= GEN_9) ? 15000 : ((I_PRICE >= GEN_7) ? 4000 : 100),
        .holdEffect = HOLD_EFFECT_SCOPE_LENS,
        .description = COMPOUND_STRING(
            "Item (Tragen)\n"
            "erhöht die\n"
            "Volltrefferquote."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
    },

    [ITEM_LEFTOVERS] =
    {
        .name = _("Überreste"),
        .pluralName = _("Überreste"),
        .price = (I_PRICE >= GEN_9) ? 20000 : ((I_PRICE >= GEN_7) ? 4000 : 200),
        .holdEffect = HOLD_EFFECT_LEFTOVERS,
        .holdEffectParam = 10,
        .description = COMPOUND_STRING(
            "Item (Tragen) füllt\n"
            "im Kampf langsam\n"
            "KP wieder auf."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

    [ITEM_SHELL_BELL] =
    {
        .name = _("Seegesang"),
        .price = (I_PRICE >= GEN_9) ? 20000 : ((I_PRICE >= GEN_7) ? 4000 : 200),
        .holdEffect = HOLD_EFFECT_SHELL_BELL,
        .holdEffectParam = 8,
        .description = COMPOUND_STRING(
            "Item (Tragen) füllt\n"
            "im Kampf langsam \n"
            "KP wieder auf."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
    },

    [ITEM_WIDE_LENS] =
    {
        .name = _("Großlinse"),
        .pluralName = _("Großlinsen"),
        .price = (I_PRICE >= GEN_9) ? 20000 : ((I_PRICE >= GEN_7) ? 4000 : 200),
        .holdEffect = HOLD_EFFECT_WIDE_LENS,
        .holdEffectParam = 10,
        .description = COMPOUND_STRING(
            "Ein Item zum Tragen.\n"
            "Dieses Vergrößerungsglas\n"
            "erhöht die Genauigkeit etwas."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

    [ITEM_MUSCLE_BAND] =
    {
        .name = _("Muskelband"),
        .price = (I_PRICE >= GEN_9) ? 8000 : ((I_PRICE >= GEN_7) ? 4000 : 200),
        .holdEffect = HOLD_EFFECT_MUSCLE_BAND,
        .holdEffectParam = 10,
        .description = COMPOUND_STRING(
            "Ein Item zum Tragen.\n"
            "Dieses Stirnband verstärkt\n"
            "physische Attacken etwas."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

    [ITEM_WISE_GLASSES] =
    {
        .name = _("Schlaubrille"),
        .pluralName = _("Schlaubrillen"),
        .price = (I_PRICE >= GEN_9) ? 8000 : ((I_PRICE >= GEN_7) ? 4000 : 200),
        .holdEffect = HOLD_EFFECT_WISE_GLASSES,
        .holdEffectParam = 10,
        .description = COMPOUND_STRING(
            "Ein Item zum Tragen.\n"
            "Diese dicke Brille verstärkt\n"
            "auf Sp.-Ang. basierende Att."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

    [ITEM_EXPERT_BELT] =
    {
        .name = _("Expertengurt"),
        .price = (I_PRICE >= GEN_9) ? 30000 : ((I_PRICE >= GEN_7) ? 4000 : 200),
        .holdEffect = HOLD_EFFECT_EXPERT_BELT,
        .holdEffectParam = 20,
        .description = COMPOUND_STRING(
            "Ein Item zum Tragen.\n"
            "Dieser alte Gürtel\n"
            "verstärkt sehr effektive Att."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

    [ITEM_LIGHT_CLAY] =
    {
        .name = _("Lichtlehm"),
        .pluralName = _("Lichtlehm"),
        .price = (I_PRICE >= GEN_9) ? 20000 : ((I_PRICE >= GEN_7) ? 4000 : 200),
        .holdEffect = HOLD_EFFECT_LIGHT_CLAY,
        .description = COMPOUND_STRING(
            "Ein Item zum Tragen.\n"
            "Verlängert die dauer von\n"
            "Lichtschild, Reflektor usw."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
    },

    [ITEM_LIFE_ORB] =
    {
        .name = _("Leben-Orb"),
        .price = (I_PRICE >= GEN_9) ? 50000 : ((I_PRICE >= GEN_7) ? 4000 : 200),
        .holdEffect = HOLD_EFFECT_LIFE_ORB,
        .description = COMPOUND_STRING(
            "Verstärkt Attacken, aber\n"
            "jede Attacke kostet\n"
            "den Träger KP."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
    },

    [ITEM_POWER_HERB] =
    {
        .name = _("Energiekraut"),
        .price = (I_PRICE >= GEN_9) ? 30000 : ((I_PRICE >= GEN_7) ? 4000 : 100),
        .holdEffect = HOLD_EFFECT_POWER_HERB,
        .description = COMPOUND_STRING(
            "Einmaliges Item das\n"
            "Aufladeattaken sofort\n"
            "einsetzen kann."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

    [ITEM_FOCUS_SASH] =
    {
        .name = _("Fokusgurt"),
        .pluralName = _("Fokusgurte"),
        .price = (I_PRICE >= GEN_9) ? 50000 : ((I_PRICE >= GEN_7) ? 4000 : 200),
        .holdEffect = HOLD_EFFECT_FOCUS_SASH,
        .description = COMPOUND_STRING(
            "Bei vollen KP reduziert\n"
            "eine K.O.-Attacke\n"
            "die KP nur auf 1."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

    [ITEM_ZOOM_LENS] =
    {
        .name = _("Zoomlinse"),
        .pluralName = _("Zoomlinsen"),
        .price = (I_PRICE >= GEN_9) ? 10000 : ((I_PRICE >= GEN_7) ? 4000 : 200),
        .holdEffect = HOLD_EFFECT_ZOOM_LENS,
        .holdEffectParam = 20,
        .description = COMPOUND_STRING(
            "Agiert der Gegner zuerst\n"
            "erhöht sich die\n"
            "Genauigkeit des Trägers."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

    [ITEM_METRONOME] =
    {
        .name = _("Metronom"),
        .price = (I_PRICE >= GEN_9) ? 15000 : ((I_PRICE >= GEN_7) ? 4000 : 200),
        .holdEffect = HOLD_EFFECT_METRONOME,
        .holdEffectParam = 20,
        .description = COMPOUND_STRING(
            "Verstärkt eine Attacke\n"
            "je öfter sie ununter-\n"
            "brochen ausgeführt wird."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
    },

    [ITEM_IRON_BALL] =
    {
        .name = _("Eisenkugel"),
        .price = (I_PRICE >= GEN_9) ? 20000 : ((I_PRICE >= GEN_7) ? 4000 : 200),
        .holdEffect = HOLD_EFFECT_IRON_BALL,
        .description = COMPOUND_STRING(
            "Reduziert die Geschwindigk.\n"
            "und lässt Flugtypen\n"
            "von Boten Att. treffen."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 130,
    },

    [ITEM_LAGGING_TAIL] =
    {
        .name = _("Schwerschweif"),
        .price = (I_PRICE >= GEN_9) ? 20000 : ((I_PRICE >= GEN_7) ? 4000 : 200),
        .holdEffect = HOLD_EFFECT_LAGGING_TAIL,
        .description = sFullIncenseDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

    [ITEM_DESTINY_KNOT] =
    {
        .name = _("Fatumknoten"),
        .price = (I_PRICE >= GEN_9) ? 20000 : ((I_PRICE >= GEN_7) ? 4000 : 200),
        .holdEffect = HOLD_EFFECT_DESTINY_KNOT,
        .description = COMPOUND_STRING(
            "Wird der Träger vernarrt\n"
            "gilt dies auch für\n"
            "den Gegner."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

    [ITEM_BLACK_SLUDGE] =
    {
        .name = _("Giftschleim"),
        .pluralName = _("Giftschleim"),
        .price = (I_PRICE >= GEN_9) ? 10000 : ((I_PRICE >= GEN_7) ? 4000 : 200),
        .holdEffect = HOLD_EFFECT_BLACK_SLUDGE,
        .description = COMPOUND_STRING(
            "Stellt langsam KP von\n"
            "Gittypen wieder her.\n"
            "Schädigt andere."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
    },

    [ITEM_GRIP_CLAW] =
    {
        .name = _("Griffklaue"),
        .price = (I_PRICE >= GEN_9) ? 10000 : ((I_PRICE >= GEN_7) ? 4000 : 200),
        .holdEffect = HOLD_EFFECT_GRIP_CLAW,
        .description = COMPOUND_STRING(
            "Verlängert die Dauer\n"
            "von Klammergriff,\n"
            "Wickel usw."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 90,
    },

    [ITEM_STICKY_BARB] =
    {
        .name = _("Klettdorn"),
        .price = (I_PRICE >= GEN_9) ? 10000 : ((I_PRICE >= GEN_7) ? 4000 : 200),
        .holdEffect = HOLD_EFFECT_STICKY_BARB,
        .description = COMPOUND_STRING(
            "Schadet dem Träger in jeder\n"
            "Runde kann aber an Angreifern\n"
            "haften bleiben, die ihn berühren."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
    },

    [ITEM_SHED_SHELL] =
    {
        .name = _("Wechselhülle"),
        .price = (I_PRICE >= GEN_9) ? 20000 : ((I_PRICE >= GEN_7) ? 4000 : 100),
        .holdEffect = HOLD_EFFECT_SHED_SHELL,
        .description = COMPOUND_STRING(
            "ermöglicht den Austausch\n"
            "des Trägers gegen ein\n"
            "wartendes Pokémon."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

    [ITEM_BIG_ROOT] =
    {
        .name = _("Großwurzel"),
        .price = (I_PRICE >= GEN_9) ? 10000 : ((I_PRICE >= GEN_7) ? 4000 : 200),
        .holdEffect = HOLD_EFFECT_BIG_ROOT,
        .holdEffectParam = 30,
        .description = COMPOUND_STRING(
            "Ein Item zum Tragen.\n"
            "Verstärkt KP-\n"
            "stehlende Attacken."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

    [ITEM_RAZOR_CLAW] =
    {
        .name = _("Scharfklaue"),
        .price = (I_PRICE >= GEN_9) ? 15000 : ((I_PRICE >= GEN_7) ? 5000 : 2100),
        .holdEffect = HOLD_EFFECT_SCOPE_LENS,
        .description = COMPOUND_STRING(
            "Die scharfe Klaue erhöht\n"
            "die Volltrefferquote\n"
            "des Trägers."),
        .pocket = POCKET_ITEMS,
        .type = EVO_HELD_ITEM_TYPE,
        .fieldUseFunc = EVO_HELD_ITEM_FIELD_FUNC,
        .effect = gItemEffect_EvoItem,
        .flingPower = 80,
    },

    [ITEM_RAZOR_FANG] =
    {
        .name = _("Scharfzahn"),
        .price = (I_PRICE >= GEN_9) ? 15000 : ((I_PRICE >= GEN_7) ? 5000 : 2100),
        .holdEffect = HOLD_EFFECT_FLINCH,
        .holdEffectParam = 10,
        .description = sKingsRockDesc,
        .pocket = POCKET_ITEMS,
        .type = EVO_HELD_ITEM_TYPE,
        .fieldUseFunc = EVO_HELD_ITEM_FIELD_FUNC,
        .effect = gItemEffect_EvoItem,
        .flingPower = 30,
    },

    [ITEM_EVIOLITE] =
    {
        .name = _("Evolith"),
        .price = (I_PRICE >= GEN_9) ? 50000 : ((I_PRICE >= GEN_7) ? 4000 : 200),
        .holdEffect = HOLD_EFFECT_EVIOLITE,
        .holdEffectParam = 50,
        .description = COMPOUND_STRING(
            "Die Vert. u. Spez.-Vert. von\n"
            "Pokémon wird erhöht, die sich\n"
            "noch entwickeln können."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 40,
    },

    [ITEM_FLOAT_STONE] =
    {
        .name = _("Leichtstein"),
        .price = (I_PRICE >= GEN_9) ? 10000 : ((I_PRICE >= GEN_7) ? 4000 : 200),
        .holdEffect = HOLD_EFFECT_FLOAT_STONE,
        .description = COMPOUND_STRING(
            "Ein federleichter Stein,\n"
            "der das Gewicht des\n"
            "Trägers verringert."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
    },

    [ITEM_ROCKY_HELMET] =
    {
        .name = _("Beulenhelm"),
        .price = (I_PRICE >= GEN_9) ? 50000 : ((I_PRICE >= GEN_7) ? 4000 : 200),
        .holdEffect = HOLD_EFFECT_ROCKY_HELMET,
        .holdEffectParam = 0,
        .description = COMPOUND_STRING(
            "Fügt einem Angreifer Schaden\n"
            "zu, wenn dieser den Träger\n"
            "berührt."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 60,
    },

    [ITEM_AIR_BALLOON] =
    {
        .name = _("Luftballon"),
        .price = (I_PRICE >= GEN_9) ? 15000 : ((I_PRICE >= GEN_7) ? 4000 : 200),
        .holdEffect = HOLD_EFFECT_AIR_BALLOON,
        .holdEffectParam = 0,
        .description = COMPOUND_STRING(
            "Träger fängt es an zu\n"
            "schweben. Wird es ge-\n"
            "troffen, platzt das Item."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

    [ITEM_RED_CARD] =
    {
        .name = _("Rote Karte"),
        .price = (I_PRICE >= GEN_9) ? 3000 : ((I_PRICE >= GEN_7) ? 4000 : 200),
        .holdEffect = HOLD_EFFECT_RED_CARD,
        .holdEffectParam = 0,
        .description = COMPOUND_STRING(
            "Wird der Träger getroffen,\n"
            "wird der Angreifer des\n"
            "Platzes verwiesen."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

    [ITEM_RING_TARGET] =
    {
        .name = _("Zielscheibe"),
        .price = (I_PRICE >= GEN_9) ? 10000 : ((I_PRICE >= GEN_7) ? 4000 : 200),
        .holdEffect = HOLD_EFFECT_RING_TARGET,
        .holdEffectParam = 0,
        .description = COMPOUND_STRING(
            "Attacken die keine Wirkung\n"
            "hätten, landen auf\n"
            "dem Träger."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

    [ITEM_BINDING_BAND] =
    {
        .name = _("Klammerband"),
        .price = (I_PRICE >= GEN_9) ? 20000 : ((I_PRICE >= GEN_7) ? 4000 : 200),
        .holdEffect = HOLD_EFFECT_BINDING_BAND,
        .description = COMPOUND_STRING(
            "Ein Band, das die Stärke\n"
            "aller Klammerattacken\n"
            "des Trägers erhöht."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
    },

    [ITEM_EJECT_BUTTON] =
    {
        .name = _("Fluchtknopf"),
        .price = (I_PRICE >= GEN_9) ? 30000 : ((I_PRICE >= GEN_7) ? 4000 : 200),
        .holdEffect = HOLD_EFFECT_EJECT_BUTTON,
        .holdEffectParam = 0,
        .description = COMPOUND_STRING(
            "Träger wird bei treffer\n"
            "mit einem Pokémon aus\n"
            "dem Team ausgetauscht."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
    },

    [ITEM_WEAKNESS_POLICY] =
    {
        .name = _("Schwchschutz"),
        .pluralName = _("Schwächenschutz"),
        .price = (I_PRICE >= GEN_9) ? 50000 : 1000,
        .holdEffect = HOLD_EFFECT_WEAKNESS_POLICY,
        .holdEffectParam = 0,
        .description = COMPOUND_STRING(
            "Wenn er von einer supereff.\n"
            "Att. getroffen wird, erhöhen\n"
            "sich Angr. und Sp. Angr."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
    },

    [ITEM_ASSAULT_VEST] =
    {
        .name = _("Offensivweste"),
        .price = (I_PRICE >= GEN_9) ? 50000 : 1000,
        .holdEffect = HOLD_EFFECT_ASSAULT_VEST,
        .holdEffectParam = 50,
        .description = COMPOUND_STRING(
            "Erhöht Sp. Vert. aber\n"
            "verhindert die verwen-\n"
            "dung von Status Att."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
    },

    [ITEM_SAFETY_GOGGLES] =
    {
        .name = _("Schutzbrille"),
        .pluralName = _("Schutzbrillen"),
        .price = (I_PRICE >= GEN_9) ? 20000 : ((I_PRICE >= GEN_7) ? 4000 : 1000),
        .holdEffect = HOLD_EFFECT_SAFETY_GOGGLES,
        .description = COMPOUND_STRING(
            "Schützt vor Wetter und\n"
            "Pulver Attacken."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
    },

    [ITEM_ADRENALINE_ORB] =
    {
        .name = _("Zitter-Orb"),
        .price = (I_PRICE >= GEN_9) ? 5000 : ((I_PRICE >= GEN_8) ? 4000 : 300),
        .holdEffect = HOLD_EFFECT_ADRENALINE_ORB,
        .description = COMPOUND_STRING(
            "Erhöht bei Pokémon, die\n"
            "unter dem Einfluss von\n"
            "Bedroher stehen, die Init."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
    },

    [ITEM_TERRAIN_EXTENDER] =
    {
        .name = _("Feldbeschicht"),
        .price = (I_PRICE >= GEN_9) ? 15000 : 4000,
        .holdEffect = HOLD_EFFECT_TERRAIN_EXTENDER,
        .description = COMPOUND_STRING(
            "Hat der Träger durch eine Att.\n"
            "oder eine Fähigk. ein Feld\n"
            "erzeugt, wird diese verlängert."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 60,
    },

    [ITEM_PROTECTIVE_PADS] =
    {
        .name = _("Schutzpolster"),
        .pluralName = _("Schutzpolster"),
        .price = (I_PRICE >= GEN_9) ? 15000 : 4000,
        .holdEffect = HOLD_EFFECT_PROTECTIVE_PADS,
        .description = COMPOUND_STRING(
            "Schützt den Halter vor\n"
            "Effekten die mit Kontakt\n"
            "ausgelöst werden."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
    },

    [ITEM_THROAT_SPRAY] =
    {
        .name = _("Halsspray"),
        .price = (I_PRICE >= GEN_9) ? 20000 : 4000,
        .holdEffect = HOLD_EFFECT_THROAT_SPRAY,
        .description = COMPOUND_STRING(
            "Erhöht bei Einsatz\n"
            "einer Lärm-Attacke\n"
            "den Spezial-Angriff."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
    },

    [ITEM_EJECT_PACK] =
    {
        .name = _("Fluchttasche"),
        .price = (I_PRICE >= GEN_9) ? 30000 : 4000,
        .holdEffect = HOLD_EFFECT_EJECT_PACK,
        .description = COMPOUND_STRING(
            "Erleidet der Träger eine\n"
            "Senkung seiner Statuswerte,\n"
            "wird er ausgewechselt."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 50,
    },

    [ITEM_HEAVY_DUTY_BOOTS] =
    {
        .name = _("Plateauschuhe"),
        .pluralName = _("Plateauschuhe"),
        .price = (I_PRICE >= GEN_9) ? 20000 : 4000,
        .holdEffect = HOLD_EFFECT_HEAVY_DUTY_BOOTS,
        .description = COMPOUND_STRING(
            "Träger wird nicht mehr durch\n"
            "Fallen und andere Objekte be-\n"
            "einträchtigt, die am Boden liegen."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
    },

    [ITEM_BLUNDER_POLICY] =
    {
        .name = _("Fehlschutz"),
        .pluralName = _("Fehlschutz"),
        .price = (I_PRICE >= GEN_9) ? 30000 : 4000,
        .holdEffect = HOLD_EFFECT_BLUNDER_POLICY,
        .description = COMPOUND_STRING(
            "Erhöht die Init., wenn der\n"
            "wenn der Benutzer aufgrund der\n"
            "Genauigk. einen Fehler macht."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
    },

    [ITEM_ROOM_SERVICE] =
    {
        .name = _("Bizarroservic"),
        .price = (I_PRICE >= GEN_9) ? 20000 : 4000,
        .holdEffect = HOLD_EFFECT_ROOM_SERVICE,
        .description = COMPOUND_STRING(
            "Senkt die Initiative\n"
            "des Trägers, wenn\n"
            "Bizarroraum wirkt."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 100,
    },

    [ITEM_UTILITY_UMBRELLA] =
    {
        .name = _("Alzweckschirm"),
        .price = (I_PRICE >= GEN_9) ? 15000 : 4000,
        .holdEffect = HOLD_EFFECT_UTILITY_UMBRELLA,
        .description = COMPOUND_STRING(
            "Der Träger ist gegen\n"
            "diverse Wetterphänomene\n"
            "geschützt."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 60,
    },

// Berries

    [ITEM_CHERI_BERRY] =
    {
        .name = _("Amreanabeere"),
        .pluralName = _("Amreanabeeren"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_CURE_PAR,
        .description = COMPOUND_STRING(
            "Item (Tragen) be-\n"
            "wirkt Selbstheilung\n"
            "bei Paralyse."),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_CURE_STATUS,
        .effect = gItemEffect_ParalyzeHeal,
        .flingPower = 10,
    },

    [ITEM_CHESTO_BERRY] =
    {
        .name = _("Maronbeere"),
        .pluralName = _("Maronbeeren"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_CURE_SLP,
        .description = COMPOUND_STRING(
            "Item (Tragen)\n"
            "weckt schlafendes\n"
            "POKéMON im Kampf."),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_CURE_STATUS,
        .effect = gItemEffect_Awakening,
        .flingPower = 10,
    },

    [ITEM_PECHA_BERRY] =
    {
        .name = _("Pirsifbeere"),
        .pluralName = _("Pirsifbeeren"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_CURE_PSN,
        .description = COMPOUND_STRING(
            "Item (Tragen) be-\n"
            "wirkt Selbstheilung\n"
            "bei Vergiftung."),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_CURE_STATUS,
        .effect = gItemEffect_Antidote,
        .flingPower = 10,
    },

    [ITEM_RAWST_BERRY] =
    {
        .name = _("Fragiabeere"),
        .pluralName = _("Fragiabeeren"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_CURE_BRN,
        .description = COMPOUND_STRING(
            "Item (Tragen) be-\n"
            "wirkt Selbstheilung\n"
            "bei Verbrennung."),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_CURE_STATUS,
        .effect = gItemEffect_BurnHeal,
        .flingPower = 10,
    },

    [ITEM_ASPEAR_BERRY] =
    {
        .name = _("Wilbirbeere"),
        .pluralName = _("Wilbirbeeren"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_CURE_FRZ,
        .description = COMPOUND_STRING(
            "Item (Tragen) be-\n"
            "wirkt Selbstheilung\n"
            "bei Frost."),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_CURE_STATUS,
        .effect = gItemEffect_IceHeal,
        .flingPower = 10,
    },

    [ITEM_LEPPA_BERRY] =
    {
        .name = _("Jonagobeere"),
        .pluralName = _("Jonagobeeren"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_RESTORE_PP,
        .holdEffectParam = 10,
        .description = COMPOUND_STRING(
            "Item (Tragen) füllt\n"
            "AP im Kampf um\n"
            "10 Punkte auf."),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_PARTY_MENU_MOVES,
        .fieldUseFunc = ItemUseOutOfBattle_PPRecovery,
        .battleUsage = EFFECT_ITEM_RESTORE_PP,
        .effect = gItemEffect_LeppaBerry,
        .flingPower = 10,
    },

    [ITEM_ORAN_BERRY] =
    {
        .name = _("Sienelbeere"),
        .pluralName = _("Sienelbeeren"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_RESTORE_HP,
        .holdEffectParam = 10,
        .description = COMPOUND_STRING(
            "Item (Tragen) füllt\n"
            "KP im Kampf um\n"
            "10 Punkte auf."),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_RESTORE_HP,
        .effect = gItemEffect_OranBerry,
        .flingPower = 10,
    },

    [ITEM_PERSIM_BERRY] =
    {
        .name = _("Persimbeere"),
        .pluralName = _("Persimbeeren"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_CURE_CONFUSION,
        .description = COMPOUND_STRING(
            "Item (Tragen) be-\n"
            "wirkt Selbstheilung\n"
            "bei Verwirrung."),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .battleUsage = EFFECT_ITEM_CURE_STATUS,
        .effect = gItemEffect_PersimBerry,
        .flingPower = 10,
    },

    [ITEM_LUM_BERRY] =
    {
        .name = _("Prunusbeere"),
        .pluralName = _("Prunusbeeren"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_CURE_STATUS,
        .description = COMPOUND_STRING(
            "Item (Tragen) be-\n"
            "wirkt Selbstheilung\n"
            "bei Statusproblem."),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_CURE_STATUS,
        .effect = gItemEffect_FullHeal,
        .flingPower = 10,
    },

    [ITEM_SITRUS_BERRY] =
    {
        .name = _("Tsitrubeere"),
        .pluralName = _("Tsitrubeeren"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        #if I_SITRUS_BERRY_HEAL >= GEN_4
            .holdEffect = HOLD_EFFECT_RESTORE_PCT_HP,
            .holdEffectParam = 25,
            .description = COMPOUND_STRING(
                "Item (Tragen) füllt\n"
                "im Kampf langsam\n"
                "KP auf."),
        #else
            .holdEffect = HOLD_EFFECT_RESTORE_HP,
            .holdEffectParam = 30,
            .description = COMPOUND_STRING(
                "A hold item that\n"
                "restores 30 HP in\n"
                "battle."),
        #endif
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_RESTORE_HP,
        .effect = gItemEffect_SitrusBerry,
        .flingPower = 10,
    },

    [ITEM_FIGY_BERRY] =
    {
        .name = _("Giefebeere"),
        .pluralName = _("Giefebeeren"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_CONFUSE_SPICY,
        .holdEffectParam = CONFUSE_BERRY_HEAL_FRACTION,
        .description = sFigyBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

    [ITEM_WIKI_BERRY] =
    {
        .name = _("Wikibeere"),
        .pluralName = _("Wikibeeren"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_CONFUSE_DRY,
        .holdEffectParam = CONFUSE_BERRY_HEAL_FRACTION,
        .description = sFigyBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

    [ITEM_MAGO_BERRY] =
    {
        .name = _("Magobeere"),
        .pluralName = _("Magobeeren"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_CONFUSE_SWEET,
        .holdEffectParam = CONFUSE_BERRY_HEAL_FRACTION,
        .description = sFigyBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

    [ITEM_AGUAV_BERRY] =
    {
        .name = _("Gauvebeere"),
        .pluralName = _("Gauvebeeren"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_CONFUSE_BITTER,
        .holdEffectParam = CONFUSE_BERRY_HEAL_FRACTION,
        .description = sFigyBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

    [ITEM_IAPAPA_BERRY] =
    {
        .name = _("Yapabeere"),
        .pluralName = _("Yapabeeren"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_CONFUSE_SOUR,
        .holdEffectParam = CONFUSE_BERRY_HEAL_FRACTION,
        .description = sFigyBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

    [ITEM_RAZZ_BERRY] =
    {
        .name = _("Himmihbeere"),
        .pluralName = _("Himmihbeeren"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .description = COMPOUND_STRING(
            "Säe {POKEBLOCK}-Zutat\n"
            "in Lehmboden, damit\n"
            "HIMMIH wächst."),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

    [ITEM_BLUK_BERRY] =
    {
        .name = _("Morbbeere"),
        .pluralName = _("Morbbeeren"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .description = COMPOUND_STRING(
            "Säe {POKEBLOCK}-Zutat\n"
            "in Lehmboden, damit\n"
            "MORB wächst."),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

    [ITEM_NANAB_BERRY] =
    {
        .name = _("Nanabbeere"),
        .pluralName = _("Nanabbeeren"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .description = COMPOUND_STRING(
            "Säe {POKEBLOCK}-Zutat\n"
            "in Lehmboden, damit\n"
            "NANAB wächst."),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

    [ITEM_WEPEAR_BERRY] =
    {
        .name = _("Nirbebeere"),
        .pluralName = _("Nirbebeeren"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .description = COMPOUND_STRING(
            "Säe {POKEBLOCK}-Zutat\n"
            "in Lehmboden, damit\n"
            "NIRBE wächst."),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

    [ITEM_PINAP_BERRY] =
    {
        .name = _("Sananabeere"),
        .pluralName = _("Sananabeeren"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .description = COMPOUND_STRING(
            "Säe {POKEBLOCK}-Zutat\n"
            "in Lehmboden, damit\n"
            "SANANA wächst."),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

    [ITEM_POMEG_BERRY] =
    {
        .name = _("Granabeere"),
        .pluralName = _("Granabeeren"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .description = COMPOUND_STRING(
            "Macht Pokémon zutraul-\n"
            "icher aber verringert\n"
            "die Basis KP."),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_ReduceEV,
        .effect = gItemEffect_PomegBerry,
        .flingPower = 10,
    },

    [ITEM_KELPSY_BERRY] =
    {
        .name = _("Setangbeere"),
        .pluralName = _("Setangbeeren"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .description = COMPOUND_STRING(
            "Macht Pokémon zutraul-\n"
            "icher aber verringert\n"
            "die Basis Attacke."),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_ReduceEV,
        .effect = gItemEffect_KelpsyBerry,
        .flingPower = 10,
    },

    [ITEM_QUALOT_BERRY] =
    {
        .name = _("Qualotbeere"),
        .pluralName = _("Qualotbeeren"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .description = COMPOUND_STRING(
            "Macht Pokémon zutraul-\n"
            "icher aber verringert\n"
            "die Basis Verteidigung."),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_ReduceEV,
        .effect = gItemEffect_QualotBerry,
        .flingPower = 10,
    },

    [ITEM_HONDEW_BERRY] =
    {
        .name = _("Honmelbeere"),
        .pluralName = _("Honmelbeeren"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .description = COMPOUND_STRING(
            "Macht Pokémon zutraul-\n"
            "icher aber verringert\n"
            "die Basis SP. Att."),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_ReduceEV,
        .effect = gItemEffect_HondewBerry,
        .flingPower = 10,
    },

    [ITEM_GREPA_BERRY] =
    {
        .name = _("Labrusbeere"),
        .pluralName = _("Labrusbeeren"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .description = COMPOUND_STRING(
            "Macht Pokémon zutraul-\n"
            "icher aber verringert\n"
            "die Basis SP. Vert."),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_ReduceEV,
        .effect = gItemEffect_GrepaBerry,
        .flingPower = 10,
    },

    [ITEM_TAMATO_BERRY] =
    {
        .name = _("Tamotbeere"),
        .pluralName = _("Tamotbeeren"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .description = COMPOUND_STRING(
            "Macht Pokémon zutraul-\n"
            "icher aber verringert\n"
            "die Basis Init."),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_ReduceEV,
        .effect = gItemEffect_TamatoBerry,
        .flingPower = 10,
    },

    [ITEM_CORNN_BERRY] =
    {
        .name = _("Saimbeere"),
        .pluralName = _("Saimbeeren"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .description = COMPOUND_STRING(
            "Säe {POKEBLOCK}-Zutat\n"
            "in Lehmboden, damit\n"
            "SAIM wächst."),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

    [ITEM_MAGOST_BERRY] =
    {
        .name = _("Magostbeere"),
        .pluralName = _("Magostbeeren"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .description = COMPOUND_STRING(
            "Säe {POKEBLOCK}-Zutat\n"
            "in Lehmboden, damit\n"
            "MAGOST wächst."),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

    [ITEM_RABUTA_BERRY] =
    {
        .name = _("Rabutabeere"),
        .pluralName = _("Rabutabeeren"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .description = COMPOUND_STRING(
            "Säe {POKEBLOCK}-Zutat\n"
            "in Lehmboden, damit\n"
            "RABUTA wächst."),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

    [ITEM_NOMEL_BERRY] =
    {
        .name = _("Tronzibeere"),
        .pluralName = _("Tronzibeeren"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .description = COMPOUND_STRING(
            "Säe {POKEBLOCK}-Zutat\n"
            "in Lehmboden, damit\n"
            "TRONZI wächst."),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

    [ITEM_SPELON_BERRY] =
    {
        .name = _("Kiwanbeere"),
        .pluralName = _("Kiwanbeere"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .description = COMPOUND_STRING(
            "Säe {POKEBLOCK}-Zutat\n"
            "in Lehmboden, damit\n"
            "KIWAN wächst."),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

    [ITEM_PAMTRE_BERRY] =
    {
        .name = _("Pallmbeere"),
        .pluralName = _("Pallmbeeren"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .description = COMPOUND_STRING(
            "Säe {POKEBLOCK}-Zutat\n"
            "in Lehmboden, damit\n"
            "PALLM wächst."),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

    [ITEM_WATMEL_BERRY] =
    {
        .name = _("Wasmelbeere"),
        .pluralName = _("Wasmelbeeren"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .description = COMPOUND_STRING(
            "Säe {POKEBLOCK}-Zutat\n"
            "in Lehmboden, damit\n"
            "WASMEL wächst."),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

    [ITEM_DURIN_BERRY] =
    {
        .name = _("Durinbeere"),
        .pluralName = _("Durinbeeren"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .description = COMPOUND_STRING(
            "Säe {POKEBLOCK}-Zutat\n"
            "in Lehmboden, damit\n"
            "DURIN wächst."),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

    [ITEM_BELUE_BERRY] =
    {
        .name = _("Myrtilbeere"),
        .pluralName = _("Myrtilbeeren"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .description = COMPOUND_STRING(
            "Säe {POKEBLOCK}-Zutat\n"
            "in Lehmboden, damit\n"
            "MYRTIL wächst."),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

    [ITEM_CHILAN_BERRY] =
    {
        .name = _("Latchibeere"),
        .pluralName = _("Latchibeeren"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_RESIST_BERRY,
        .holdEffectParam = TYPE_NORMAL,
        .description = COMPOUND_STRING(
            "Item zum Tragen.\n"
            "Schwächt Normal\n"
            "Attacken."),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

    [ITEM_OCCA_BERRY] =
    {
        .name = _("Koakobeere"),
        .pluralName = _("Koakobeeren"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_RESIST_BERRY,
        .holdEffectParam = TYPE_FIRE,
        .description = COMPOUND_STRING(
            "Item zum Tragen.\n"
            "Schwächt sehr Effektive\n"
            "gegnerische Feueratt."),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

    [ITEM_PASSHO_BERRY] =
    {
        .name = _("Foepasbeere"),
        .pluralName = _("Foepasbeeren"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_RESIST_BERRY,
        .holdEffectParam = TYPE_WATER,
        .description = COMPOUND_STRING(
            "Item zum Tragen.\n"
            "Schwächt sehr Effektive\n"
            "gegnerische Wasseratt."),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

    [ITEM_WACAN_BERRY] =
    {
        .name = _("Kerzalbeere"),
        .pluralName = _("Kerzalbeeren"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_RESIST_BERRY,
        .holdEffectParam = TYPE_ELECTRIC,
        .description = COMPOUND_STRING(
            "Item zum Tragen.\n"
            "Schwächt sehr Effektive\n"
            "gegnerische Eletroatt."),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

    [ITEM_RINDO_BERRY] =
    {
        .name = _("Grindobeere"),
        .pluralName = _("Grindobeeren"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_RESIST_BERRY,
        .holdEffectParam = TYPE_GRASS,
        .description = COMPOUND_STRING(
            "Item zum Tragen.\n"
            "Schwächt sehr Effektive\n"
            "gegnerische Pflanzenatt."),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

    [ITEM_YACHE_BERRY] =
    {
        .name = _("Kiroyabeere"),
        .pluralName = _("Kiroyabeeren"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_RESIST_BERRY,
        .holdEffectParam = TYPE_ICE,
        .description = COMPOUND_STRING(
            "Item zum Tragen.\n"
            "Schwächt sehr Effektive\n"
            "gegnerische Eisatt."),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

    [ITEM_CHOPLE_BERRY] =
    {
        .name = _("Rospelbeere"),
        .pluralName = _("Rospelbeeren"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_RESIST_BERRY,
        .holdEffectParam = TYPE_FIGHTING,
        .description = COMPOUND_STRING(
            "Item zum Tragen.\n"
            "Schwächt sehr Effektive\n"
            "gegnerische Kampfatt."),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

    [ITEM_KEBIA_BERRY] =
    {
        .name = _("Grarzbeere"),
        .pluralName = _("Grarzbeeren"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_RESIST_BERRY,
        .holdEffectParam = TYPE_POISON,
        .description = COMPOUND_STRING(
            "Item zum Tragen.\n"
            "Schwächt sehr Effektive\n"
            "gegnerische Giftatt."),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

    [ITEM_SHUCA_BERRY] =
    {
        .name = _("Schukebeere"),
        .pluralName = _("Schukebeeren"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_RESIST_BERRY,
        .holdEffectParam = TYPE_GROUND,
        .description = COMPOUND_STRING(
            "Item zum Tragen.\n"
            "Schwächt sehr Effektive\n"
            "gegnerische Bodenatt."),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

    [ITEM_COBA_BERRY] =
    {
        .name = _("Kobabeere"),
        .pluralName = _("Kobabeeren"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_RESIST_BERRY,
        .holdEffectParam = TYPE_FLYING,
        .description = COMPOUND_STRING(
            "Item zum Tragen.\n"
            "Schwächt sehr Effektive\n"
            "gegnerische Flugatt."),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

    [ITEM_PAYAPA_BERRY] =
    {
        .name = _("Pyapabeere"),
        .pluralName = _("Pyapabeeren"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_RESIST_BERRY,
        .holdEffectParam = TYPE_PSYCHIC,
        .description = COMPOUND_STRING(
            "Item zum Tragen.\n"
            "Schwächt sehr Effektive\n"
            "gegnerische Psychoatt."),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

    [ITEM_TANGA_BERRY] =
    {
        .name = _("Tanigabeere"),
        .pluralName = _("Tanigabeeren"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_RESIST_BERRY,
        .holdEffectParam = TYPE_BUG,
        .description = COMPOUND_STRING(
            "Item zum Tragen.\n"
            "Schwächt sehr Effektive\n"
            "gegnerische Käferatt."),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

    [ITEM_CHARTI_BERRY] =
    {
        .name = _("Chiaribeere"),
        .pluralName = _("Chiaribeeren"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_RESIST_BERRY,
        .holdEffectParam = TYPE_ROCK,
        .description = COMPOUND_STRING(
            "Item zum Tragen.\n"
            "Schwächt sehr Effektive\n"
            "gegnerische Gesteinatt."),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

    [ITEM_KASIB_BERRY] =
    {
        .name = _("Zitarzbeere"),
        .pluralName = _("Zitarzbeeren"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_RESIST_BERRY,
        .holdEffectParam = TYPE_GHOST,
        .description = COMPOUND_STRING(
            "Item zum Tragen.\n"
            "Schwächt sehr Effektive\n"
            "gegnerische Geistatt."),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

    [ITEM_HABAN_BERRY] =
    {
        .name = _("Terirobeere"),
        .pluralName = _("Terirobeeren"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_RESIST_BERRY,
        .holdEffectParam = TYPE_DRAGON,
        .description = COMPOUND_STRING(
            "Item zum Tragen.\n"
            "Schwächt sehr Effektive\n"
            "gegnerische Drachenatt."),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

    [ITEM_COLBUR_BERRY] =
    {
        .name = _("Burleobeere"),
        .pluralName = _("Burleobeeren"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_RESIST_BERRY,
        .holdEffectParam = TYPE_DARK,
        .description = COMPOUND_STRING(
            "Item zum Tragen.\n"
            "Schwächt sehr Effektive\n"
            "gegnerische Unlichtatt."),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

    [ITEM_BABIRI_BERRY] =
    {
        .name = _("Babiribeere"),
        .pluralName = _("Babiribeeren"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_RESIST_BERRY,
        .holdEffectParam = TYPE_STEEL,
        .description = COMPOUND_STRING(
            "Item zum Tragen.\n"
            "Schwächt sehr Effektive\n"
            "gegnerische Stahlatt."),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

    [ITEM_ROSELI_BERRY] =
    {
        .name = _("Hibisbeere"),
        .pluralName = _("Hibisbeeren"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_RESIST_BERRY,
        .holdEffectParam = TYPE_FAIRY,
        .description = COMPOUND_STRING(
            "Item zum Tragen.\n"
            "Schwächt sehr Effektive\n"
            "gegnerische Feenatt."),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

    [ITEM_LIECHI_BERRY] =
    {
        .name = _("Lydzibeere"),
        .pluralName = _("Lydzibeeren"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_ATTACK_UP,
        .holdEffectParam = 4,
        .description = COMPOUND_STRING(
            "Item (Tragen) hebt\n"
            "ANGR.-Wert in einer\n"
            "Notlage."),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

    [ITEM_GANLON_BERRY] =
    {
        .name = _("Linganbeere"),
        .pluralName = _("Linganbeeren"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_DEFENSE_UP,
        .holdEffectParam = 4,
        .description = COMPOUND_STRING(
            "Item (Tragen) hebt\n"
            "VERT.-Wert in einer\n"
            "Notlage."),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

    [ITEM_SALAC_BERRY] =
    {
        .name = _("Salkabeere"),
        .pluralName = _("Salkabeeren"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_SPEED_UP,
        .holdEffectParam = 4,
        .description = COMPOUND_STRING(
            "Item (Tragen) hebt\n"
            "INIT.-Wert in einer\n"
            "Notlage."),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

    [ITEM_PETAYA_BERRY] =
    {
        .name = _("Tahaybeere"),
        .pluralName = _("Tahaybeeren"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_SP_ATTACK_UP,
        .holdEffectParam = 4,
        .description = COMPOUND_STRING(
            "Item (Tragen) hebt\n"
            "SP. ANGR.-Wert\n"
            "in einer Notlage."),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

    [ITEM_APICOT_BERRY] =
    {
        .name = _("Apikobeere"),
        .pluralName = _("Apikobeeren"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_SP_DEFENSE_UP,
        .holdEffectParam = 4,
        .description = COMPOUND_STRING(
            "Item (Tragen) hebt\n"
            "SP. VERT.-Wert\n"
            "in einer Notlage."),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

    [ITEM_LANSAT_BERRY] =
    {
        .name = _("Lansatbeere"),
        .pluralName = _("Lansatbeeren"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_CRITICAL_UP,
        .holdEffectParam = 4,
        .description = COMPOUND_STRING(
            "Item (Tragen) hebt\n"
            "Volltrefferquote\n"
            "in einer Notlage."),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

    [ITEM_STARF_BERRY] =
    {
        .name = _("Krambobeere"),
        .pluralName = _("Krambobeeren"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_RANDOM_STAT_UP,
        .holdEffectParam = 4,
        .description = COMPOUND_STRING(
            "Item (Tragen) hebt\n"
            "einen Statuswert\n"
            "in einer Notlage."),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

    [ITEM_ENIGMA_BERRY] =
    {
        .name = _("Enigmabeere"),
        .pluralName = _("Enigmabeeren"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_ENIGMA_BERRY,
        .description = COMPOUND_STRING(
            "Wenn Träger von einer\n"
            "Sehr Effektiven Att.\n"
            "getroffen wird, heilt etwas KP."),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

    [ITEM_MICLE_BERRY] =
    {
        .name = _("Wunfrubeere"),
        .pluralName = _("Wunfrubeeren"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_MICLE_BERRY,
        .holdEffectParam = 4,
        .description = COMPOUND_STRING(
            "Item (Tragen) hebt\n"
            "die Genauigkeit\n"
            "in einer Notlage."),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

    [ITEM_CUSTAP_BERRY] =
    {
        .name = _("Eipfelbeere"),
        .pluralName = _("Eipfelbeeren"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_CUSTAP_BERRY,
        .holdEffectParam = 4,
        .description = COMPOUND_STRING(
            "Item (Tragen) hebt\n"
            "die Erstschlagquote\n"
            "in einer Notlage."),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

    [ITEM_JABOCA_BERRY] =
    {
        .name = _("Jabocabeere"),
        .pluralName = _("Jabocabeeren"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_JABOCA_BERRY,
        .description = COMPOUND_STRING(
            "Verletzt gegner wenn\n"
            "Träger von einer Physi-\n"
            "schen Att. getroffen wird."),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

    [ITEM_ROWAP_BERRY] =
    {
        .name = _("Roselbeere"),
        .pluralName = _("Roselbeeren"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_ROWAP_BERRY,
        .description = COMPOUND_STRING(
            "Verletzt gegner wenn\n"
            "Träger von einer Spezial-\n"
            "Att. getroffen wird."),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

    [ITEM_KEE_BERRY] =
    {
        .name = _("Akibeere"),
        .pluralName = _("Akibeeren"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_KEE_BERRY,
        .description = COMPOUND_STRING(
            "Erhöht Vert. wenn\n"
            "Träger von einer Physi-\n"
            "schen Att. getroffen wird."),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

    [ITEM_MARANGA_BERRY] =
    {
        .name = _("Tarabeere"),
        .pluralName = _("Tarabeeren"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_MARANGA_BERRY,
        .description = COMPOUND_STRING(
            "Erhöht SP. Vert. wenn\n"
            "Träger von einer Spezial-\n"
            "Att. getroffen wird."),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

    [ITEM_ENIGMA_BERRY_E_READER] =
    {
        .name = _("Enigmabeere"),
        .pluralName = _("Enigmabeeren"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .description = COMPOUND_STRING(
            "Säe {POKEBLOCK}-Zutat\n"
            "in Lehmboden, damit\n"
            "Mysterium wächst."),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU, // Type handled by ItemUseOutOfBattle_EnigmaBerry
        .fieldUseFunc = ItemUseOutOfBattle_EnigmaBerry,
        .battleUsage = EFFECT_ITEM_ENIGMA_BERRY_EREADER,
        .flingPower = 10,
    },

// TMs/HMs. They don't have a set flingPower, as that's handled by GetFlingPowerFromItemId.

    [ITEM_TM_FOCUS_PUNCH] =
    {
        .name = _("TM01"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "Stark. POKéMON er-\n"
            "schrickt vielleicht\n"
            "bei gegn. Attacke."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_FOCUS_PUNCH,
    },

    [ITEM_TM_DRAGON_CLAW] =
    {
        .name = _("TM02"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "Gegner wird mit\n"
            "langen, scharfen\n"
            "Krallen attackiert."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_DRAGON_CLAW,
    },

    [ITEM_TM_WATER_PULSE] =
    {
        .name = _("TM03"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "Eine Ultraschall-\n"
            "welle, die den Geg-\n"
            "ner verwirren kann."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_WATER_PULSE,
    },

    [ITEM_TM_CALM_MIND] =
    {
        .name = _("TM04"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "Verstärkt SP. ANGR.\n"
            "und SP. VERT. durch\n"
            "Konzentration."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_CALM_MIND,
    },

    [ITEM_TM_ROAR] =
    {
        .name = _("TM05"),
        .price = 1000,
        .description = COMPOUND_STRING(
            "Brüller schlägt Geg-\n"
            "ner in die Flucht \n"
            "und beendet Kampf."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_ROAR,
    },

    [ITEM_TM_TOXIC] =
    {
        .name = _("TM06"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "Vergiftet den Geg-\n"
            "ner und schadet \n"
            "ihm zunehmend."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_TOXIC,
    },

    [ITEM_TM_HAIL] =
    {
        .name = _("TM07"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "Hagelsturm schadet\n"
            "allen POKéMON außer\n"
            "denen des Typs EIS."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_HAIL,
    },

    [ITEM_TM_BULK_UP] =
    {
        .name = _("TM08"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "Stärkt den Körper.\n"
            "So steigt ANGR.-\n"
            "und VERT.-Wert."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_BULK_UP,
    },

    [ITEM_TM_BULLET_SEED] =
    {
        .name = _("TM09"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "Bepflanzt den\n"
            "Gegner mit 2 bis 5\n"
            "Samen auf einmal."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_BULLET_SEED,
    },

    [ITEM_TM_HIDDEN_POWER] =
    {
        .name = _("TM10"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "Die Stärke dieser\n"
            "Attacke hängt vom \n"
            "jew. POKéMON ab."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_HIDDEN_POWER,
    },

    [ITEM_TM_SUNNY_DAY] =
    {
        .name = _("TM11"),
        .price = 2000,
        .description = COMPOUND_STRING(
            "Verstärkt FEUER-\n"
            "Attacken über \n"
            "5 Runden."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_SUNNY_DAY,
    },

    [ITEM_TM_TAUNT] =
    {
        .name = _("TM12"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "Reizt Geg. so, dass\n"
            "er nur Angriffs-\n"
            "attacken einsetzt."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_TAUNT,
    },

    [ITEM_TM_ICE_BEAM] =
    {
        .name = _("TM13"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "Eisig kalter Strahl,\n"
            "der den Gegner\n"
        #if B_USE_FROSTBITE == TRUE
            "einfrieren kann."),
        #else
            "freeze the foe."),
        #endif
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_ICE_BEAM,
    },

    [ITEM_TM_BLIZZARD] =
    {
        .name = _("TM14"),
        .price = 5500,
        .description = COMPOUND_STRING(
            "Eis- und Schnee- \n"
            "Attacke, die Gegner\n"
        #if B_USE_FROSTBITE == TRUE
            "einfrieren kann."),
        #else
            "may freeze the foe."),
        #endif
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_BLIZZARD,
    },

    [ITEM_TM_HYPER_BEAM] =
    {
        .name = _("TM15"),
        .price = 7500,
        .description = COMPOUND_STRING(
            "Stark, muss sich\n"
            "aber in der nächs-\n"
            "ten Runde aufladen."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_HYPER_BEAM,
    },

    [ITEM_TM_LIGHT_SCREEN] =
    {
        .name = _("TM16"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "Wand aus Licht, die\n"
            "Senkung des SP.\n"
            "ANGR. verringert."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_LIGHT_SCREEN,
    },

    [ITEM_TM_PROTECT] =
    {
        .name = _("TM17"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "Schützt, könnte\n"
            "aber bei häufigem\n"
            "Einsatz versagen."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_PROTECT,
    },

    [ITEM_TM_RAIN_DANCE] =
    {
        .name = _("TM18"),
        .price = 2000,
        .description = COMPOUND_STRING(
            "Verstärkt WASSER-\n"
            "Attacken über\n"
            "5 Runden."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_RAIN_DANCE,
    },

    [ITEM_TM_GIGA_DRAIN] =
    {
        .name = _("TM19"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "Füllt KP um die Hälf-\n"
            "te der zugefügten\n"
            "Schadenspunkte."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_GIGA_DRAIN,
    },

    [ITEM_TM_SAFEGUARD] =
    {
        .name = _("TM20"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "Mystische Macht\n"
            "verhindert Status-\n"
            "veränderungen."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_SAFEGUARD,
    },

    [ITEM_TM_FRUSTRATION] =
    {
        .name = _("TM21"),
        .price = 1000,
        .description = COMPOUND_STRING(
            "Je unbeliebter der\n"
            "Trainer, desto grö-\n"
            "ßer die Wirkung."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_FRUSTRATION,
    },

    [ITEM_TM_SOLAR_BEAM] =
    {
        .name = _("TM22"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "Erst wird Sonnen-\n"
            "licht absorbiert,\n"
            "dann erfolgt Angr."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_SOLAR_BEAM,
    },

    [ITEM_TM_IRON_TAIL] =
    {
        .name = _("TM23"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "Schlag mit harter\n"
            "Rute. Kann gleichz.\n"
            "VERT.-Wert senken."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_IRON_TAIL,
    },

    [ITEM_TM_THUNDERBOLT] =
    {
        .name = _("TM24"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "Starke Elektro-\n"
            "Attacke kann\n"
            "Paralyse bewirken."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_THUNDERBOLT,
    },

    [ITEM_TM_THUNDER] =
    {
        .name = _("TM25"),
        .price = 5500,
        .description = COMPOUND_STRING(
            "Mächtiger Donner-\n"
            "schlag, der Paraly-\n"
            "se bewirken kann."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_THUNDER,
    },

    [ITEM_TM_EARTHQUAKE] =
    {
        .name = _("TM26"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "Starkes Beben hat\n"
            "keinen Einfluss auf\n"
            "fliegende Gegner."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_EARTHQUAKE,
    },

    [ITEM_TM_RETURN] =
    {
        .name = _("TM27"),
        .price = 1000,
        .description = COMPOUND_STRING(
            "Je beliebter der\n"
            "Trainer, desto grö-\n"
            "ßer die Wirkung."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_RETURN,
    },

    [ITEM_TM_DIG] =
    {
        .name = _("TM28"),
        .price = 2000,
        .description = COMPOUND_STRING(
            "Erst gräbt sich An-\n"
            "greifer ein, dann\n"
            "erfolgt Angriff."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_DIG,
    },

    [ITEM_TM_PSYCHIC] =
    {
        .name = _("TM29"),
        .price = 2000,
        .description = COMPOUND_STRING(
            "Starke PSYCHO-At-\n"
            "tacke, die SP. VERT.\n"
            "senken kann."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_PSYCHIC,
    },

    [ITEM_TM_SHADOW_BALL] =
    {
        .name = _("TM30"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "Dunkler Klumpen,\n"
            "der SP. VERT.\n"
            "senken kann."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_SHADOW_BALL,
    },

    [ITEM_TM_BRICK_BREAK] =
    {
        .name = _("TM31"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "Zerstört Barrieren\n"
            "wie SCHUTZSCHILD,\n"
            "fügt Schaden zu."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_BRICK_BREAK,
    },

    [ITEM_TM_DOUBLE_TEAM] =
    {
        .name = _("TM32"),
        .price = 2000,
        .description = COMPOUND_STRING(
            "Virtueller Doppel-\n"
            "gänger erhöht\n"
            "den Flucht-Wert."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_DOUBLE_TEAM,
    },

    [ITEM_TM_REFLECT] =
    {
        .name = _("TM33"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "Wand aus Licht, die\n"
            "physische Atta-\n"
            "cken schwächt."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_REFLECT,
    },

    [ITEM_TM_SHOCK_WAVE] =
    {
        .name = _("TM34"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "Fügt Gegner einen\n"
            "Stromschlag zu,\n"
            "der nie verfehlt."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_SHOCK_WAVE,
    },

    [ITEM_TM_FLAMETHROWER] =
    {
        .name = _("TM35"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "Entfesselt Feuer-\n"
            "strahl, der Gegner\n"
            "verbrennen kann."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_FLAMETHROWER,
    },

    [ITEM_TM_SLUDGE_BOMB] =
    {
        .name = _("TM36"),
        .price = 1000,
        .description = COMPOUND_STRING(
            "Bewirft Gegner mit\n"
            "Matsch, der ihn\n"
            "vergiften kann."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_SLUDGE_BOMB,
    },

    [ITEM_TM_SANDSTORM] =
    {
        .name = _("TM37"),
        .price = 2000,
        .description = COMPOUND_STRING(
            "Sandsturm trifft\n"
            "etliche Runden lang\n"
            "die Kämpfenden."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_SANDSTORM,
    },

    [ITEM_TM_FIRE_BLAST] =
    {
        .name = _("TM38"),
        .price = 5500,
        .description = COMPOUND_STRING(
            "Kraftvolle FEUER-\n"
            "Attacke, die Gegner\n"
            "verbrennen kann."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_FIRE_BLAST,
    },

    [ITEM_TM_ROCK_TOMB] =
    {
        .name = _("TM39"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "Stoppt GESTEIN-\n"
            "Attacken. Kann\n"
            "INIT.-Wert senken."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_ROCK_TOMB,
    },

    [ITEM_TM_AERIAL_ACE] =
    {
        .name = _("TM40"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "Eine extrem schnel-\n"
            "le Attacke, die\n"
            "unausweichlich ist."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_AERIAL_ACE,
    },

    [ITEM_TM_TORMENT] =
    {
        .name = _("TM41"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "Blockiert gerade\n"
            "verwendete Atta-\n"
            "cke des Gegners."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_TORMENT,
    },

    [ITEM_TM_FACADE] =
    {
        .name = _("TM42"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "Stärkt ANGR.-Wert\n"
            "bei Gift, Brand oder\n"
            "Paralyse."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_FACADE,
    },

    [ITEM_TM_SECRET_POWER] =
    {
        .name = _("TM43"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "Die Umgebung\n"
            "beeinflusst die Art\n"
            "der Attacke."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_SECRET_POWER,
    },

    [ITEM_TM_REST] =
    {
        .name = _("TM44"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "POKéMON schläft\n"
            "2 Runden. Füllt KP\n"
            "und heilt Status."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_REST,
    },

    [ITEM_TM_ATTRACT] =
    {
        .name = _("TM45"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "Erschwert Angriff\n"
            "auf Gegner des an-\n"
            "deren Geschlechts."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_ATTRACT,
    },

    [ITEM_TM_THIEF] =
    {
        .name = _("TM46"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "Beim Angriff wird\n"
            "Item des Gegners\n"
            "evtl. gestohlen."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_THIEF,
    },

    [ITEM_TM_STEEL_WING] =
    {
        .name = _("TM47"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "Den Gegner\n"
            "treffen stählerne\n"
            "Flügelschläge."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_STEEL_WING,
    },

    [ITEM_TM_SKILL_SWAP] =
    {
        .name = _("TM48"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "Austausch der\n"
            "Fähigkeiten bei der\n"
            "nächsten Attacke."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_SKILL_SWAP,
    },

    [ITEM_TM_SNATCH] =
    {
        .name = _("TM49"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "Stiehlt die\n"
            "Effekte der gegne-\n"
            "rischen Attacke."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_SNATCH,
    },

    [ITEM_TM_OVERHEAT] =
    {
        .name = _("TM50"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "Höchste Kraft,\n"
            "aber senkt SP.\n"
            "ANGR. enorm."),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_OVERHEAT,
    },

    [ITEM_TM51] =
    {
        .name = _("TM51"),
        .price = 3000,
        .description = sQuestionMarksDesc, // Todo
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_NONE, // Todo
    },

    [ITEM_TM52] =
    {
        .name = _("TM52"),
        .price = 3000,
        .description = sQuestionMarksDesc, // Todo
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_NONE, // Todo
    },

    [ITEM_TM53] =
    {
        .name = _("TM53"),
        .price = 3000,
        .description = sQuestionMarksDesc, // Todo
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_NONE, // Todo
    },

    [ITEM_TM54] =
    {
        .name = _("TM54"),
        .price = 3000,
        .description = sQuestionMarksDesc, // Todo
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_NONE, // Todo
    },

    [ITEM_TM55] =
    {
        .name = _("TM55"),
        .price = 3000,
        .description = sQuestionMarksDesc, // Todo
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_NONE, // Todo
    },

    [ITEM_TM56] =
    {
        .name = _("TM56"),
        .price = 3000,
        .description = sQuestionMarksDesc, // Todo
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_NONE, // Todo
    },

    [ITEM_TM57] =
    {
        .name = _("TM57"),
        .price = 3000,
        .description = sQuestionMarksDesc, // Todo
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_NONE, // Todo
    },

    [ITEM_TM58] =
    {
        .name = _("TM58"),
        .price = 3000,
        .description = sQuestionMarksDesc, // Todo
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_NONE, // Todo
    },

    [ITEM_TM59] =
    {
        .name = _("TM59"),
        .price = 3000,
        .description = sQuestionMarksDesc, // Todo
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_NONE, // Todo
    },

    [ITEM_TM60] =
    {
        .name = _("TM60"),
        .price = 3000,
        .description = sQuestionMarksDesc, // Todo
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_NONE, // Todo
    },

    [ITEM_TM61] =
    {
        .name = _("TM61"),
        .price = 3000,
        .description = sQuestionMarksDesc, // Todo
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_NONE, // Todo
    },

    [ITEM_TM62] =
    {
        .name = _("TM62"),
        .price = 3000,
        .description = sQuestionMarksDesc, // Todo
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_NONE, // Todo
    },

    [ITEM_TM63] =
    {
        .name = _("TM63"),
        .price = 3000,
        .description = sQuestionMarksDesc, // Todo
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_NONE, // Todo
    },

    [ITEM_TM64] =
    {
        .name = _("TM64"),
        .price = 3000,
        .description = sQuestionMarksDesc, // Todo
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_NONE, // Todo
    },

    [ITEM_TM65] =
    {
        .name = _("TM65"),
        .price = 3000,
        .description = sQuestionMarksDesc, // Todo
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_NONE, // Todo
    },

    [ITEM_TM66] =
    {
        .name = _("TM66"),
        .price = 3000,
        .description = sQuestionMarksDesc, // Todo
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_NONE, // Todo
    },

    [ITEM_TM67] =
    {
        .name = _("TM67"),
        .price = 3000,
        .description = sQuestionMarksDesc, // Todo
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_NONE, // Todo
    },

    [ITEM_TM68] =
    {
        .name = _("TM68"),
        .price = 3000,
        .description = sQuestionMarksDesc, // Todo
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_NONE, // Todo
    },

    [ITEM_TM69] =
    {
        .name = _("TM69"),
        .price = 3000,
        .description = sQuestionMarksDesc, // Todo
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_NONE, // Todo
    },

    [ITEM_TM70] =
    {
        .name = _("TM70"),
        .price = 3000,
        .description = sQuestionMarksDesc, // Todo
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_NONE, // Todo
    },

    [ITEM_TM71] =
    {
        .name = _("TM71"),
        .price = 3000,
        .description = sQuestionMarksDesc, // Todo
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_NONE, // Todo
    },

    [ITEM_TM72] =
    {
        .name = _("TM72"),
        .price = 3000,
        .description = sQuestionMarksDesc, // Todo
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_NONE, // Todo
    },

    [ITEM_TM73] =
    {
        .name = _("TM73"),
        .price = 3000,
        .description = sQuestionMarksDesc, // Todo
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_NONE, // Todo
    },

    [ITEM_TM74] =
    {
        .name = _("TM74"),
        .price = 3000,
        .description = sQuestionMarksDesc, // Todo
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_NONE, // Todo
    },

    [ITEM_TM75] =
    {
        .name = _("TM75"),
        .price = 3000,
        .description = sQuestionMarksDesc, // Todo
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_NONE, // Todo
    },

    [ITEM_TM76] =
    {
        .name = _("TM76"),
        .price = 3000,
        .description = sQuestionMarksDesc, // Todo
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_NONE, // Todo
    },

    [ITEM_TM77] =
    {
        .name = _("TM77"),
        .price = 3000,
        .description = sQuestionMarksDesc, // Todo
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_NONE, // Todo
    },

    [ITEM_TM78] =
    {
        .name = _("TM78"),
        .price = 3000,
        .description = sQuestionMarksDesc, // Todo
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_NONE, // Todo
    },

    [ITEM_TM79] =
    {
        .name = _("TM79"),
        .price = 3000,
        .description = sQuestionMarksDesc, // Todo
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_NONE, // Todo
    },

    [ITEM_TM80] =
    {
        .name = _("TM80"),
        .price = 3000,
        .description = sQuestionMarksDesc, // Todo
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_NONE, // Todo
    },

    [ITEM_TM81] =
    {
        .name = _("TM81"),
        .price = 3000,
        .description = sQuestionMarksDesc, // Todo
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_NONE, // Todo
    },

    [ITEM_TM82] =
    {
        .name = _("TM82"),
        .price = 3000,
        .description = sQuestionMarksDesc, // Todo
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_NONE, // Todo
    },

    [ITEM_TM83] =
    {
        .name = _("TM83"),
        .price = 3000,
        .description = sQuestionMarksDesc, // Todo
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_NONE, // Todo
    },

    [ITEM_TM84] =
    {
        .name = _("TM84"),
        .price = 3000,
        .description = sQuestionMarksDesc, // Todo
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_NONE, // Todo
    },

    [ITEM_TM85] =
    {
        .name = _("TM85"),
        .price = 3000,
        .description = sQuestionMarksDesc, // Todo
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_NONE, // Todo
    },

    [ITEM_TM86] =
    {
        .name = _("TM86"),
        .price = 3000,
        .description = sQuestionMarksDesc, // Todo
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_NONE, // Todo
    },

    [ITEM_TM87] =
    {
        .name = _("TM87"),
        .price = 3000,
        .description = sQuestionMarksDesc, // Todo
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_NONE, // Todo
    },

    [ITEM_TM88] =
    {
        .name = _("TM88"),
        .price = 3000,
        .description = sQuestionMarksDesc, // Todo
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_NONE, // Todo
    },

    [ITEM_TM89] =
    {
        .name = _("TM89"),
        .price = 3000,
        .description = sQuestionMarksDesc, // Todo
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_NONE, // Todo
    },

    [ITEM_TM90] =
    {
        .name = _("TM90"),
        .price = 3000,
        .description = sQuestionMarksDesc, // Todo
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_NONE, // Todo
    },

    [ITEM_TM91] =
    {
        .name = _("TM91"),
        .price = 3000,
        .description = sQuestionMarksDesc, // Todo
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_NONE, // Todo
    },

    [ITEM_TM92] =
    {
        .name = _("TM92"),
        .price = 3000,
        .description = sQuestionMarksDesc, // Todo
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_NONE, // Todo
    },

    [ITEM_TM93] =
    {
        .name = _("TM93"),
        .price = 3000,
        .description = sQuestionMarksDesc, // Todo
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_NONE, // Todo
    },

    [ITEM_TM94] =
    {
        .name = _("TM94"),
        .price = 3000,
        .description = sQuestionMarksDesc, // Todo
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_NONE, // Todo
    },

    [ITEM_TM95] =
    {
        .name = _("TM95"),
        .price = 3000,
        .description = sQuestionMarksDesc, // Todo
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_NONE, // Todo
    },

    [ITEM_TM96] =
    {
        .name = _("TM96"),
        .price = 3000,
        .description = sQuestionMarksDesc, // Todo
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_NONE, // Todo
    },

    [ITEM_TM97] =
    {
        .name = _("TM97"),
        .price = 3000,
        .description = sQuestionMarksDesc, // Todo
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_NONE, // Todo
    },

    [ITEM_TM98] =
    {
        .name = _("TM98"),
        .price = 3000,
        .description = sQuestionMarksDesc, // Todo
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_NONE, // Todo
    },

    [ITEM_TM99] =
    {
        .name = _("TM99"),
        .price = 3000,
        .description = sQuestionMarksDesc, // Todo
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_NONE, // Todo
    },

    [ITEM_TM100] =
    {
        .name = _("TM100"),
        .price = 3000,
        .description = sQuestionMarksDesc, // Todo
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_NONE, // Todo
    },

    [ITEM_HM_CUT] =
    {
        .name = _("VM01"),
        .price = 0,
        .description = COMPOUND_STRING(
            "Gegner wird mit\n"
            "klingenscharfen\n"
            "Krallen attackiert."),
        .importance = 1,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_CUT,
    },

    [ITEM_HM_FLY] =
    {
        .name = _("VM02"),
        .price = 0,
        .description = COMPOUND_STRING(
            "PKMN fliegt hoch,\n"
            "dann erfolgt rasan-\n"
            "ter Luftangriff."),
        .importance = 1,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_FLY,
    },

    [ITEM_HM_SURF] =
    {
        .name = _("VM03"),
        .price = 0,
        .description = COMPOUND_STRING(
            "Eine riesige Flut-\n"
            "welle ergießt sich\n"
            "über dem Gegner."),
        .importance = 1,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_SURF,
    },

    [ITEM_HM_STRENGTH] =
    {
        .name = _("VM04"),
        .price = 0,
        .description = COMPOUND_STRING(
            "Den Gegner trifft \n"
            "ein energiegelade-\n"
            "ner Kraftschlag."),
        .importance = 1,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_STRENGTH,
    },

    [ITEM_HM_FLASH] =
    {
        .name = _("VM05"),
        .price = 0,
        .description = COMPOUND_STRING(
            "Ein gleißender\n"
            "Lichtstrahl, der\n"
            "Genau. senken kann."),
        .importance = 1,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_FLASH,
    },

    [ITEM_HM_ROCK_SMASH] =
    {
        .name = _("VM06"),
        .price = 0,
        .description = COMPOUND_STRING(
            "Steinbrecherische\n"
            "Attacke, die VERT.-\n"
            "Wert senken kann."),
        .importance = 1,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_ROCK_SMASH,
    },

    [ITEM_HM_WATERFALL] =
    {
        .name = _("VM07"),
        .price = 0,
        .description = COMPOUND_STRING(
            "Mächtige Attacke,\n"
            "die Wasserfälle\n"
            "bezwingbar macht."),
        .importance = 1,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_WATERFALL,
    },

    [ITEM_HM_DIVE] =
    {
        .name = _("VM08"),
        .price = 0,
        .description = COMPOUND_STRING(
            "PKMN taucht ab,\n"
            "dann erfolgt An-\n"
            "griff aus der Tiefe."),
        .importance = 1,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
        .secondaryId = MOVE_DIVE,
    },


// Charms

    [ITEM_OVAL_CHARM] =
    {
        .name = _("Ovalpin"),
        .price = 0,
        .importance = 1,
        .description = COMPOUND_STRING(
            "Erhöht die Chance\n"
            "im Hort Eier\n"
            "zu finden."),
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_SHINY_CHARM] =
    {
        .name = _("Schillerpin"),
        .price = 0,
        .importance = 1,
        .description = COMPOUND_STRING(
            "Dieser Schillerpin\n"
            "erhöht die Chance, Shiny\n"
            "Pokémon zu begegnen."),
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_CATCHING_CHARM] =
    {
        .name = _("Superfangpin"),
        .price = 0,
        .importance = 1,
        .description = COMPOUND_STRING(
            "Erhöht die Chance\n"
            "einen Superfang\n"
            "hinzulegen."),
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_EXP_CHARM] =
    {
        .name = _("EP. Pin"),
        .price = 0,
        .importance = 1,
        .description = COMPOUND_STRING(
            "Dieser EP. Pin erhöht\n"
            "die EP nach einem Kampf\n"
            "für deine Pokémon."),
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

// Form-changing Key Items

    [ITEM_ROTOM_CATALOG] =
    {
        .name = _("Rotom-Katalog"),
        .price = 0,
        .importance = 1,
        .description = COMPOUND_STRING(
            "Ein Katalog voller\n"
            "Geräte, die Rotom\n"
            "gefallen."),
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_RotomCatalog,
    },

    [ITEM_GRACIDEA] =
    {
        .name = _("Gracidea"),
        .price = 0,
        .importance = 1,
        .description = COMPOUND_STRING(
            "Als Zeichen der Dankbarkeit\n"
            "werden daraus gebastelte\n"
            "Blumensträuße angeboten."),
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_FormChange,
    },

    [ITEM_REVEAL_GLASS] =
    {
        .name = _("Wahrspiegel"),
        .pluralName = _("Wahrspiegel"),
        .price = 0,
        .importance = 1,
        .description = COMPOUND_STRING(
            "Dieser Spiegel Verwandelt\n"
            "Pokémon wieder zurück\n"
            "in ihre Originalform."),
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_FormChange,
    },

    [ITEM_DNA_SPLICERS] =
    {
        .name = _("DNS-Keil"),
        .pluralName = _("DNS-Keil"),
        .price = 0,
        .importance = 1,
        .description = COMPOUND_STRING(
            "Ein Keil der Kyurem\n"
            "und ein bestimmtes\n"
            "Pokémon verschmilzt."),
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Fusion,
    },

    [ITEM_ZYGARDE_CUBE] =
    {
        .name = _("ZygardeWürfel"),
        .price = 0,
        .importance = 1,
        .description = COMPOUND_STRING(
            "Ein Item zur Aufbe-\n"
            "wahrung von Zygarde-\n"
            "Kernen und Zellen."),
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_ZygardeCube,
    },

    [ITEM_PRISON_BOTTLE] =
    {
        .name = _("Banngefäß"),
        .price = 0,
        .importance = 1,
        .description = COMPOUND_STRING(
            "Eine Flasche, mit der\n"
            "vor langer Zeit ein bestim-\n"
            "mtes Pokémon versiegelt wurde."),
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_FormChange,
    },

    [ITEM_N_SOLARIZER] =
    {
        .name = _("Necrosol"),
        .price = 0,
        .importance = 1,
        .description = COMPOUND_STRING(
            "Ein Gerät zum Verschmelzen\n"
            "und Teilen von Necrozma\n"
            "mithilfe eines Solgaleo."),
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Fusion,
    },

    [ITEM_N_LUNARIZER] =
    {
        .name = _("Necrolun"),
        .price = 0,
        .importance = 1,
        .description = COMPOUND_STRING(
            "Ein Gerät zum Verschmelzen\n"
            "und Teilen von Necrozma\n"
            "mithilfe eines Lunala."),
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Fusion,
    },

    [ITEM_REINS_OF_UNITY] =
    {
        .name = _("Zügeld.Bundes"),
        .pluralName = _("ZügeldesBundes"),
        .price = 0,
        .importance = 1,
        .description = COMPOUND_STRING(
            "Zügel, die Calyrex mit\n"
            "seinem geliebten\n"
            "Ross vereinen."),
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Fusion,
    },

// Battle Mechanic Key Items

    [ITEM_MEGA_RING] =
    {
        .name = _("Mega-Ring"),
        .price = 0,
        .importance = 1,
        .description = COMPOUND_STRING(
            "Ermöglicht {PKMN} die\n"
            "ihren Mega-Stein halten,\n"
            "eine Mega-Entwicklung."),
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_Z_POWER_RING] =
    {
        .name = _("Z-Kraftring"),
        .price = 0,
        .importance = 1,
        .description = COMPOUND_STRING(
            "Ein seltsamer Ring\n"
            "der die Verwendung\n"
            "von Z-Att. ermöglicht."),
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_DYNAMAX_BAND] =
    {
        .name = _("Dynamax Band"),
        .price = 0,
        .description = COMPOUND_STRING(
            "Ein Band mit einem\n"
            "Wunschstern, der\n"
            "Dynamaxing ermöglicht."),
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

// Misc. Key Items

    [ITEM_BICYCLE] =
    {
        .name = _("Fahrrad"),
        .price = 0,
        .description = COMPOUND_STRING(
            "Ein Klapprad, mit dem\n"
            "man schneller ist\n"
            "als zu Fuß."),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_MACH_BIKE] =
    {
        .name = _("Eilrad"),
        .price = 0,
        .description = COMPOUND_STRING(
            "Klapprad, das dop-\n"
            "pelt so schnell ist\n"
            "wie ein Fußgänger."),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Bike,
        .secondaryId = MACH_BIKE,
    },

    [ITEM_ACRO_BIKE] =
    {
        .name = _("Kunstrad"),
        .price = 0,
        .description = COMPOUND_STRING(
            "Klapprad ermög-\n"
            "licht Sprünge und\n"
            "Wheelies."),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Bike,
        .secondaryId = ACRO_BIKE,
    },

    [ITEM_OLD_ROD] =
    {
        .name = _("Angel"),
        .price = 0,
        .description = COMPOUND_STRING(
            "Damit kannst du in\n"
            "jedem Gewässer\n"
            "POKéMON angeln."),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Rod,
        .secondaryId = OLD_ROD,
    },

    [ITEM_GOOD_ROD] =
    {
        .name = _("Profiangel"),
        .price = 0,
        .description = COMPOUND_STRING(
            "Eine recht gute\n"
            "Angel zum\n"
            "POKéMON-Fischen."),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Rod,
        .secondaryId = GOOD_ROD,
    },

    [ITEM_SUPER_ROD] =
    {
        .name = _("Superangel"),
        .price = 0,
        .description = COMPOUND_STRING(
            "Die beste Angel,\n"
            "um nach POKéMON\n"
            "zu fischen."),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Rod,
        .secondaryId = SUPER_ROD,
    },

    [ITEM_DOWSING_MACHINE] =
    {
        .name = _("Itemradar"),
        .price = 0,
        .description = COMPOUND_STRING(
            "Ein Gerät, das ver-\n"
            "borgene Items via \n"
            "Schallwellen ortet."),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Itemfinder,
    },

    [ITEM_TOWN_MAP] =
    {
        .name = _("Karte"),
        .price = 0,
        .description = COMPOUND_STRING(
            "Kann stets\n"
            "aufgerufen werden.\n"
            "Zeigt Standort."),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_VS_SEEKER] =
    {
        .name = _("Kampffahnder"),
        .price = 0,
        .description = COMPOUND_STRING(
            "Gerät, das rückkampf-\n"
            "willige Trainer\n"
            "anzeigt."),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_FIELD,
#if I_VS_SEEKER_CHARGING != 0
        .fieldUseFunc = FieldUseFunc_VsSeeker,
#else
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
#endif
    },

    [ITEM_TM_CASE] =
    {
        .name = _("TM-Box"),
        .price = 0,
        .description = COMPOUND_STRING(
            "Box, in der VMs\n"
            "und TMs aufbewahrt\n"
            "werden."),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_BERRY_POUCH] =
    {
        .name = _("Beerentüte"),
        .pluralName = _("Beerentüten"),
        .price = 0,
        .description = COMPOUND_STRING(
            "Tüte, in der\n"
            "Beeren aufbewahrt\n"
            "werden."),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_POKEMON_BOX_LINK] =
    {
        .name = _("Pokémon-Box"),
        .price = 0,
        .description = COMPOUND_STRING(
            "Dieses Gerät gewährt\n"
            "Zugriff auf das {PKMN}\n"
            "Lagerungssystem."),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_PokemonBoxLink,
    },

    [ITEM_COIN_CASE] =
    {
        .name = _("Münzkorb"),
        .price = 0,
        .description = COMPOUND_STRING(
            "Kann bis zu 9.999\n"
            "Münzen aufnehmen."),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CoinCase,
    },

    [ITEM_POWDER_JAR] =
    {
        .name = _("Puderdöschen"),
        .price = 0,
        .description = COMPOUND_STRING(
            "Glas für Beeren-\n"
            "puter der\n"
            "Beerenmühle."),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_PowderJar,
    },

    [ITEM_WAILMER_PAIL] =
    {
        .name = _("Wailmerkanne"),
        .price = 0,
        .description = COMPOUND_STRING(
            "Ein Gegenstand zum\n"
            "Gießen von Pflan-\n"
            "zen wie Beeren."),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_WailmerPail,
    },

    [ITEM_POKE_RADAR] =
    {
        .name = _("Poké Radar"),
        .price = 0,
        .description = COMPOUND_STRING(
            "Spürt Pokémon im hohen\n"
            "Gras auf. Die Batterie\n"
            "wird beim Reisen geladen."),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse, // Todo
    },

    [ITEM_POKEBLOCK_CASE] =
    {
        .name = _("{POKEBLOCK} Box"),
        .price = 0,
        .description = COMPOUND_STRING(
            "Box für {POKEBLOCK},\n"
            "die im BEERENMIXER\n"
            "hergestellt werden."),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_PBLOCK_CASE,
        .fieldUseFunc = ItemUseOutOfBattle_PokeblockCase,
    },

    [ITEM_SOOT_SACK] =
    {
        .name = _("Aschetasche"),
        .price = 0,
        .description = COMPOUND_STRING(
            "Beutel zum Sammeln\n"
            "und Aufbewahren\n"
            "von Vulkanasche."),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_POKE_FLUTE] =
    {
        .name = _("Pokéflöte"),
        .price = 0,
        .description = COMPOUND_STRING(
            "Flöte, deren Klang\n"
            "jedes schlafende\n"
            "Pokémon aufweckt."),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_FAME_CHECKER] =
    {
        .name = _("Ruhmesdatei"),
        .price = 0,
        .description = COMPOUND_STRING(
            "Gerät, das Infos über\n"
            "wichtige Personen speichert."),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_TEACHY_TV] =
    {
        .name = _("Lehrkanal"),
        .price = 0,
        .description = COMPOUND_STRING(
            "Sendung, die dem\n"
            "Anfänger-Trainer\n"
            "Tipps gibt."),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

// Story Key Items

    [ITEM_SS_TICKET] =
    {
        .name = _("Bootsticket"),
        .price = 0,
        .description = COMPOUND_STRING(
            "Ein Ticket zur\n"
            "Fahrt auf\n"
            "einer Fähre."),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_EON_TICKET] =
    {
        .name = _("Äon Ticket"),
        .price = 0,
        .description = COMPOUND_STRING(
            "Bootsticket zu\n"
            "einer fernen Insel\n"
            "im Süden."),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 1,
    },

    [ITEM_MYSTIC_TICKET] =
    {
        .name = _("Geheimticket"),
        .price = 0,
        .description = COMPOUND_STRING(
            "Fahrkarte für das\n"
            "Schiff zum\n"
            "Nabelfelsen."),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_AURORA_TICKET] =
    {
        .name = _("Auroraticket"),
        .price = 0,
        .description = COMPOUND_STRING(
            "Fahrkarte für das\n"
            "Schiff zum\n"
            "Entstehungsinsel."),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_OLD_SEA_MAP] =
    {
        .name = _("Alte Karte"),
        .price = 0,
        .description = COMPOUND_STRING(
            "Alte Seekarte!\n"
            "Zeigt den Weg\n"
            "zu einer Insel."),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_LETTER] =
    {
        .name = _("Brief"),
        .price = 0,
        .description = COMPOUND_STRING(
            "Brief an TROY\n"
            "vom PRÄSIDENTEN\n"
            "der DEVON CORP."),
        .importance = 2,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_DEVON_PARTS] =
    {
        .name = _("Devon Waren"),
        .pluralName = _("Devon Waren"),
        .price = 0,
        .description = COMPOUND_STRING(
            "Päckchen, das Ma-\n"
            "schinenteile von\n"
            "DEVON enthält."),
        .importance = 2,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_GO_GOGGLES] =
    {
        .name = _("Wüstenglas"),
        .pluralName = _("Wüstengläser"),
        .price = 0,
        .description = COMPOUND_STRING(
            "Schicke Brille, die\n"
            "die Augen vor Sand-\n"
            "stürmen schützt."),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_DEVON_SCOPE] =
    {
        .name = _("Devon Scope"),
        .price = 0,
        .description = COMPOUND_STRING(
            "Gerät von DEVON, \n"
            "das unsichtbare\n"
            "POKéMON entlarvt."),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_BASEMENT_KEY] =
    {
        .name = _("Kelleröffner"),
        .price = 0,
        .description = COMPOUND_STRING(
            "Schlüssel für NEU\n"
            "MALVENFROH unter\n"
            "MALVENFROH CITY."),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_SCANNER] =
    {
        .name = _("Scanner"),
        .price = 0,
        .description = COMPOUND_STRING(
            "Ein Gerät, das\n"
            "im SCHIFFSWRACK\n"
            "gefunden wurde."),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_STORAGE_KEY] =
    {
        .name = _("L.-Schlüssel"),
        .price = 0,
        .description = COMPOUND_STRING(
            "Schlüssel zum\n"
            "Lagerraum auf\n"
            "dem SCHIFFSWRACK."),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_KEY_TO_ROOM_1] =
    {
        .name = _("K1 Schlüssel"),
        .pluralName = _("K1 Schlüssel"),
        .price = 0,
        .description = sKeyToRoomDesc,
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_KEY_TO_ROOM_2] =
    {
        .name = _("K2 Schlüssel"),
        .pluralName = _("K2 Schlüssel"),
        .price = 0,
        .description = sKeyToRoomDesc,
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_KEY_TO_ROOM_4] =
    {
        .name = _("K4 Schlüssel"),
        .pluralName = _("K4 Schlüssel"),
        .price = 0,
        .description = sKeyToRoomDesc,
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_KEY_TO_ROOM_6] =
    {
        .name = _("K6 Schlüssel"),
        .pluralName = _("K6 Schlüssel"),
        .price = 0,
        .description = sKeyToRoomDesc,
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_METEORITE] =
    {
        .name = _("Meteorit"),
        .price = 0,
        .description = COMPOUND_STRING(
            "Meteorit. Fundort:\n"
            "METEORFÄLLE."),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_FormChange,
    },

    [ITEM_MAGMA_EMBLEM] =
    {
        .name = _("Magmaemblem"),
        .price = 0,
        .description = COMPOUND_STRING(
            "Emblem in der Form\n"
            "von Team Magmas\n"
            "Abzeichen."),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_CONTEST_PASS] =
    {
        .name = _("Wettb.-Karte"),
        .pluralName = _("Wettb.-Karten"),
        .price = 0,
        .description = COMPOUND_STRING(
            "Ausweis zur Teil-\n"
            "nahme an POKéMON- \n"
            "WETTBEWERBEN."),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_PARCEL] =
    {
        .name = _("Paket"),
        .price = 0,
        .description = COMPOUND_STRING(
            "Ein Paket für Prof.\n"
            "Eich aus einem Pokémon\n"
            "Supermarkt."),
        .importance = 2,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_SECRET_KEY] =
    {
        .name = _("Geheimschl."),
        .price = 0,
        .description = COMPOUND_STRING(
            "Der Schlüssel zum\n"
            "Eingang der Arena\n"
            "au der Zinnoberinsel."),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_BIKE_VOUCHER] =
    {
        .name = _("Rad-Coupon"),
        .price = 0,
        .description = COMPOUND_STRING(
            "Gutschein für ein\n"
            "FAHRRAD im LADEN in\n"
            "AZURIA CITY"),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_GOLD_TEETH] =
    {
        .name = _("GoldenGebiss"),
        .pluralName = _("GoldenGebiss"),
        .price = 0,
        .description = COMPOUND_STRING(
            "Verlorenes Gebiss des\n"
            "Wärters in der\n"
            "Safari-Zone."),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_CARD_KEY] =
    {
        .name = _("Schlüsselkart"),
        .price = 0,
        .description = COMPOUND_STRING(
            "Ein kartenartiger Schlüssel\n"
            "der im Büro von\n"
            "Silph Co. verwendet wird."),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_LIFT_KEY] =
    {
        .name = _("Aufzugschlü."),
        .price = 0,
        .description = COMPOUND_STRING(
            "Schlüssel für Aufzug\n"
            "im Versteck von\n"
            "Team Rocket."),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_SILPH_SCOPE] =
    {
        .name = _("Silph Scope"),
        .price = 0,
        .description = COMPOUND_STRING(
            "Linse, mit der\n"
            "unsichtbare Pokémon\n"
            "sichtbar werden."),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_TRI_PASS] =
    {
        .name = _("Tri-Pass"),
        .pluralName = _("Tri-Passes"),
        .price = 0,
        .description = COMPOUND_STRING(
            "Pass für die Fähren\n"
            "zwischen EILAND Eins\n"
            "Zwei und Drei."),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_RAINBOW_PASS] =
    {
        .name = _("Bunt-Pass"),
        .pluralName = _("Bunt-Pässe"),
        .price = 0,
        .description = COMPOUND_STRING(
            "Pass für die Fähren\n"
            "zwischen ORANIA\n"
            "SEVII EILANDEN."),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_TEA] =
    {
        .name = _("Te"),
        .pluralName = _("Tee"),
        .price = 0,
        .description = COMPOUND_STRING(
            "Tee der von\n"
            "einer Alten Dame\n"
            "zubereitet wird."),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_RUBY] =
    {
        .name = _("Rubin"),
        .pluralName = _("Rubine"),
        .price = 0,
        .description = COMPOUND_STRING(
            "Rotes Juwel, das\n"
            "Leidenschaft\n"
            "symbolisiert."),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_SAPPHIRE] =
    {
        .name = _("Saphir"),
        .price = 0,
        .description = COMPOUND_STRING(
            "Blaues Juwel, das\n"
            "Ehrlichkeit\n"
            "symbolisiert."),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_ABILITY_SHIELD] =
    {
        .name = _("Fähigk.Schild"),
        .price = 20000,
        .holdEffect = HOLD_EFFECT_ABILITY_SHIELD,
        .description = COMPOUND_STRING(
            "Fähigk. änderungen für\n"
            "den Träger des Items\n"
            "werden verhindert."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
    },

// GEN 9 ITEMS

    [ITEM_CLEAR_AMULET] =
    {
        .name = _("Neutralshmuck"),
        .price = 30000,
        .holdEffect = HOLD_EFFECT_CLEAR_AMULET,
        .description = COMPOUND_STRING(
            "Absenken der werte für\n"
            "den Träger des Items\n"
            "werden verhindert."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
    },

    [ITEM_PUNCHING_GLOVE] =
    {
        .name = _("Boxhandschuh"),
        .price = 15000,
        .holdEffect = HOLD_EFFECT_PUNCHING_GLOVE,
        .description = COMPOUND_STRING(
            "Verstärkt Schlagattacken\n"
            "und entfernt\n"
            "deren Kontakt."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
    },

    [ITEM_COVERT_CLOAK] =
    {
        .name = _("Tarnumhang"),
        .price = 20000,
        .holdEffect = HOLD_EFFECT_COVERT_CLOAK,
        .description = COMPOUND_STRING(
            "Schützt den Träger vor\n"
            "sekundären Attacken-\n"
            "effekte."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
    },

    [ITEM_LOADED_DICE] =
    {
        .name = _("GezinktWürfel"),
        .pluralName = _("GezinktWürfel"),
        .price = 20000,
        .holdEffect = HOLD_EFFECT_LOADED_DICE,
        .description = COMPOUND_STRING(
            "Würfelt hohe Zahlen.\n"
            "Multihit-Schläge\n"
            "treffen öfter."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
    },

    [ITEM_AUSPICIOUS_ARMOR] =
    {
        .name = _("Glorienrüstun"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "Von glückverheißenden\n"
            "Wünschen bewohnte Rüst-\n"
            "ung. Verursacht Entwick."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
        .effect = gItemEffect_EvoItem,
        .flingPower = 30,
    },

    [ITEM_BOOSTER_ENERGY] =
    {
        .name = _("Energiekapsel"),
        .pluralName = _("Energiekapsel"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_BOOSTER_ENERGY,
        .description = COMPOUND_STRING(
            "Eingekapselte Energie\n"
            "verleiht Pokémon\n"
            "bestimmte Fähigkeiten."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
    },

    [ITEM_BIG_BAMBOO_SHOOT] =
    {
        .name = _("Riebambuspros"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "Ein großer und seltener\n"
            "Bambusspross. Am besten\n"
            "an Feinschmecker verkauft."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
    },

    [ITEM_GIMMIGHOUL_COIN] =
    {
        .name = _("GierspenstMün"),
        .price = 400,
        .description = COMPOUND_STRING(
            "Gierspenst hortet\n"
            "und schätzt diese\n"
            "seltsamen Münzen."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_LEADERS_CREST] =
    {
        .name = _("Anführersymb."),
        .price = 3000,
        .description = COMPOUND_STRING(
            "Eine Art Scherbe\n"
            "einer alten Klinge.\n"
            "Von Caesurio gehalten."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_MALICIOUS_ARMOR] =
    {
        .name = _("Fluchrüstung"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "Von böswilligem Willen\n"
            "bewohnte Rüstung.\n"
            "Verursacht Entwicklung."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
        .effect = gItemEffect_EvoItem,
        .flingPower = 30,
    },

    [ITEM_MIRROR_HERB] =
    {
        .name = _("Kopierkraut"),
        .price = 30000,
        .holdEffect = HOLD_EFFECT_MIRROR_HERB,
        .description = COMPOUND_STRING(
            "Spiegelt die Werterhöhung\n"
            "eines Gegners wider\n"
            "jedoch nur einmal."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
    },

    [ITEM_SCROLL_OF_DARKNESS] =
    {
        .name = _("Unli-Schrift"),
        .pluralName = _("Unli-Schrift"),
        .price = 0,
        .description = COMPOUND_STRING(
            "Eine eigenartige Schrift-\n"
            "rolle mit Geheimnissen\n"
            "des dunklen Pfades."),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
        .effect = gItemEffect_EvoItem,
    },

    [ITEM_SCROLL_OF_WATERS] =
    {
        .name = _("WasserSchrift"),
        .pluralName = _("WasserSchrift"),
        .price = 0,
        .description = COMPOUND_STRING(
            "Eine eigenartige Schrift-\n"
            "rolle mit Geheimnissen\n"
            "des Wasserweges."),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
        .effect = gItemEffect_EvoItem,
    },

    [ITEM_TERA_ORB] =
    {
        .name = _("Tera Orb"),
        .price = 0,
        .description = COMPOUND_STRING(
            "Ladungen können verw.\n"
            "werden, um eine Tera-\n"
            "stallisation auszulösen."),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_TINY_BAMBOO_SHOOT] =
    {
        .name = _("Minbambuspros"),
        .price = 750,
        .description = COMPOUND_STRING(
            "Ein kleiner und seltener\n"
            "Bambusspross. Am besten\n"
            "an Feinschmecker verkauft."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
    },

    [ITEM_BUG_TERA_SHARD] =
    {
        .name = _("TeraStk.Käfer"),
        .price = 0,
        .description = sTeraShardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_DARK_TERA_SHARD] =
    {
        .name = _("Tera stk.Unli"),
        .price = 0,
        .description = sTeraShardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_DRAGON_TERA_SHARD] =
    {
        .name = _("TeraStkDrache"),
        .price = 0,
        .description = sTeraShardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_ELECTRIC_TERA_SHARD] =
    {
        .name = _("TerastkElectr"),
        .price = 0,
        .description = sTeraShardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_FAIRY_TERA_SHARD] =
    {
        .name = _("Tera stk. Fee"),
        .price = 0,
        .description = sTeraShardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_FIGHTING_TERA_SHARD] =
    {
        .name = _("Terastk Kampf"),
        .price = 0,
        .description = sTeraShardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_FIRE_TERA_SHARD] =
    {
        .name = _("TeraStk Feuer"),
        .price = 0,
        .description = sTeraShardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_FLYING_TERA_SHARD] =
    {
        .name = _("Tera Stk Flug"),
        .price = 0,
        .description = sTeraShardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_GHOST_TERA_SHARD] =
    {
        .name = _("TeraStk Geist"),
        .price = 0,
        .description = sTeraShardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_GRASS_TERA_SHARD] =
    {
        .name = _("TeraStkPflanz"),
        .price = 0,
        .description = sTeraShardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_GROUND_TERA_SHARD] =
    {
        .name = _("TeraStk Boden"),
        .price = 0,
        .description = sTeraShardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_ICE_TERA_SHARD] =
    {
        .name = _("Tera Stk. Eis"),
        .price = 0,
        .description = sTeraShardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_NORMAL_TERA_SHARD] =
    {
        .name = _("TeraStkNormal"),
        .price = 0,
        .description = sTeraShardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_POISON_TERA_SHARD] =
    {
        .name = _("Tera Stk Gift"),
        .price = 0,
        .description = sTeraShardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_PSYCHIC_TERA_SHARD] =
    {
        .name = _("TeraStkPsycho"),
        .price = 0,
        .description = sTeraShardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_ROCK_TERA_SHARD] =
    {
        .name = _("TeraStkGestei"),
        .price = 0,
        .description = sTeraShardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_STEEL_TERA_SHARD] =
    {
        .name = _("TeraStk Stahl"),
        .price = 0,
        .description = sTeraShardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_WATER_TERA_SHARD] =
    {
        .name = _("TeraStkWasser"),
        .price = 0,
        .description = sTeraShardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_ADAMANT_CRYSTAL] =
    {
        .name = _("Adamantkrist."),
        .price = 0,
        .description = COMPOUND_STRING(
            "Ein großer, leuchtender\n"
            "Edelstein, der Dialga's\n"
            "Form ändern lässt."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 60,
    },

    [ITEM_GRISEOUS_CORE] =
    {
        .name = _("Platin krist."),
        .price = 0,
        .description = COMPOUND_STRING(
            "Ein großer, leuchtender\n"
            "Edelstein, der Giratina's\n"
            "Form ändern lässt."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 60,
    },

    [ITEM_LUSTROUS_GLOBE] =
    {
        .name = _("Weißkristall"),
        .price = 0,
        .description = COMPOUND_STRING(
            "Ein großer, leuchtender\n"
            "Edelstein, der Palkia's\n"
            "Form ändern lässt."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 60,
    },

    [ITEM_BLACK_AUGURITE] =
    {
        .name = _("Schwarzaugit"),
        .price = 8000,
        .description = COMPOUND_STRING(
            "Ein schwarzer Stein, der\n"
            "einige Pokémon zur\n"
            "Weiterentwicklung bringt."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
        .effect = gItemEffect_EvoItem,
        .flingPower = 30,
    },

    [ITEM_LINKING_CORD] =
    {
        .name = _("Verbindschnur"),
        .price = 8000,
        .description = COMPOUND_STRING(
            "Eine mysteriöse Schnur,\n"
            "die einige Pokémon zur\n"
            "Weiterentwicklung bringt."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
        .effect = gItemEffect_EvoItem,
        .flingPower = 30,
    },

    [ITEM_PEAT_BLOCK] =
    {
        .name = _("Torfblock"),
        .price = 10000,
        .description = COMPOUND_STRING(
            "Ein Materialblock, der\n"
            "einige Pokémon zur\n"
            "Weiterentwicklung bringt."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
        .effect = gItemEffect_EvoItem,
        .flingPower = 30,
    },

    [ITEM_BERSERK_GENE] =
    {
        .name = _("Berserk-Gen"),
        .price = 20,
        .holdEffect = HOLD_EFFECT_BERSERK_GENE,
        .description = COMPOUND_STRING(
            "Verstärkt den Angriff\n"
            "deutlich, sorgt aber für\n"
            "dauerhafte Verwirrung."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

    [ITEM_FAIRY_FEATHER] =
    {
        .name = _("Feendaune"),
        .price = 1000,
        .holdEffect = HOLD_EFFECT_FAIRY_POWER,
        .holdEffectParam = TYPE_BOOST_PARAM,
        .description = COMPOUND_STRING(
            "Ein Item zum Tragen, der\n"
            "die Kraft von Attacken\n"
            "vom Typ Fee erhöht."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
    },

    [ITEM_SYRUPY_APPLE] =
    {
        .name = _("SaftigerApfel"),
        .price = 2200,
        .description = COMPOUND_STRING(
            "Ein sehr saftiger Apfel\n"
            "der die Entwicklung\n"
            "bestimmter Pokémon fördert."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
        .effect = gItemEffect_EvoItem,
        .flingPower = 30,
    },

    [ITEM_UNREMARKABLE_TEACUP] =
    {
        .name = _("SimplTeschale"),
        .price = 1600,
        .description = COMPOUND_STRING(
            "Eine zerbrochene Teetasse\n"
            "die die Entwicklung\n"
            "bestimmter Pokémon fördert."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
        .effect = gItemEffect_EvoItem,
        .flingPower = 80,
    },

    [ITEM_MASTERPIECE_TEACUP] =
    {
        .name = _("EdleTeeschale"),
        .price = 38000,
        .description = COMPOUND_STRING(
            "Eine angeschlagene Teetasse\n"
            "die die Entwicklung\n"
            "bestimmter Pokémon fördert."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
        .effect = gItemEffect_EvoItem,
        .flingPower = 80,
    },

    [ITEM_CORNERSTONE_MASK] =
    {
        .name = _("Fundamentmask"),
        .price = 0,
        .description = COMPOUND_STRING(
            "Ermöglicht Ogerpon, den\n"
            "Gesteinstyp im\n"
            "Kampf zu verwenden."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_WELLSPRING_MASK] =
    {
        .name = _("Brunnenmaske"),
        .price = 0,
        .description = COMPOUND_STRING(
            "Ermöglicht Ogerpon,\n"
            "den Wassertyp im\n"
            "Kampf zu verwenden."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_HEARTHFLAME_MASK] =
    {
        .name = _("Ofenmaske"),
        .price = 0,
        .description = COMPOUND_STRING(
            "Ermöglicht Ogerpon,\n"
            "den Feuertyp im\n"
            "Kampf zu verwenden."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_HEALTH_MOCHI] =
    {
        .name = _("Heil-Mochi"),
        .pluralName = _("heil-Mochi"),
        .price = 500,
        .description = sHealthFeatherDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .effect = gItemEffect_HpMochi,
        .flingPower = 30,
    },

    [ITEM_MUSCLE_MOCHI] =
    {
        .name = _("Kraft-Mochi"),
        .pluralName = _("Kraft-Mochi"),
        .price = 500,
        .description = sMuscleFeatherDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .effect = gItemEffect_AtkMochi,
        .flingPower = 30,
    },

    [ITEM_RESIST_MOCHI] =
    {
        .name = _("Abwehr-Mochi"),
        .pluralName = _("Abwehr-Mochi"),
        .price = 500,
        .description = sResistFeatherDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .effect = gItemEffect_DefMochi,
        .flingPower = 30,
    },

    [ITEM_GENIUS_MOCHI] =
    {
        .name = _("Genie-Mochi"),
        .pluralName = _("Genie-Mochi"),
        .price = 500,
        .description = sGeniusFeatherDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .effect = gItemEffect_SpatkMochi,
        .flingPower = 30,
    },

    [ITEM_CLEVER_MOCHI] =
    {
        .name = _("Esprit-Mochi"),
        .pluralName = _("Esprit-Mochi"),
        .price = 500,
        .description = sCleverFeatherDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .effect = gItemEffect_SpdefMochi,
        .flingPower = 30,
    },

    [ITEM_SWIFT_MOCHI] =
    {
        .name = _("Flink-Mochi"),
        .pluralName = _("Flink-Mochi"),
        .price = 500,
        .description = sSwiftFeatherDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .effect = gItemEffect_SpeedMochi,
        .flingPower = 30,
    },

    [ITEM_FRESH_START_MOCHI] =
    {
        .name = _("NeuanfanMochi"),
        .pluralName = _("NeuanfangMochi"),
        .price = 300,
        .description = COMPOUND_STRING(
            "Ein mit Beeren gefüllter\n"
            "Mochi, der alle Basispkt.\n"
            "eines Pokémon zurücksetzt."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_ResetEVs,
        .effect = gItemEffect_ResetMochi,
        .flingPower = 30,
    },

    [ITEM_GLIMMERING_CHARM] =
    {
        .name = _("Glitzerpin"),
        .price = 0,
        .importance = 1,
        .description = COMPOUND_STRING(
            "Ein Glücksbringer, durch\n"
            "den man in Tera-Raids\n"
            "mehr Tera-Stücke erhält."),
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_METAL_ALLOY] =
    {
        .name = _("Legirungmetal"),
        .price = 6000,
        .description = COMPOUND_STRING(
            "Ein besonderes Metall,\n"
            "das die Entwicklung be-\n"
            "stimmter Pokémon ermöglicht."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
        .effect = gItemEffect_EvoItem,
    },

    [ITEM_STELLAR_TERA_SHARD] =
    {
        .name = _("TeraStkStella"),
        .price = 0,
        .description = sTeraShardDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_JUBILIFE_MUFFIN] =
    {
        .name = _("Jubelmuffin"),
        .price = 250,
        .description = sFullHealDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_CURE_STATUS,
        .flingPower = 30,
    },

    [ITEM_REMEDY] =
    {
        .name = _("Arznei"),
        .price = 150,
        .description = COMPOUND_STRING(
            "Ein bitteres Pulver\n"
            "das die KP um 20\n"
            "Punkte wiederherstellt."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_RESTORE_HP,
        .effect = gItemEffect_Remedy,
        .flingPower = 30,
    },

    [ITEM_FINE_REMEDY] =
    {
        .name = _("Superarznei"),
        .price = 150,
        .description = COMPOUND_STRING(
            "Ein bitteres Pulver\n"
            "das die KP um 60\n"
        #if I_HEALTH_RECOVERY >= GEN_7
            "Punkte wiederherstellt."),
        #else
            "by 50 Punkte auf."),
        #endif
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_RESTORE_HP,
        .effect = gItemEffect_FineRemedy,
        .flingPower = 30,
    },

    [ITEM_SUPERB_REMEDY] =
    {
        .name = _("Hyperarznei"),
        .price = 750,
        .description = COMPOUND_STRING(
            "Ein bitteres Pulver\n"
            "das die KP um 120\n"
        #if I_HEALTH_RECOVERY >= GEN_7
            "Punkte wiederherstellt."),
        #else
            "by 200 Punkte auf."),
        #endif
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_RESTORE_HP,
        .effect = gItemEffect_SuperbRemedy,
        .flingPower = 30,
    },

    [ITEM_AUX_EVASION] =
    {
        .name = _("Ausweichvitam"),
        .price = 800,
        .holdEffectParam = X_ITEM_STAGES,
        .description = COMPOUND_STRING(
        #if B_X_ITEMS_BUFF >= GEN_7
            "Erhöht die Ausweich-\n"
            "fähigkeit während eines\n"
            "Gefechts deutlich."),
        #else
            "Raises evasiveness\n"
            "during one battle."),
        #endif
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        //.effect = currently missing
    },

    [ITEM_AUX_GUARD] =
    {
        .name = _("Defensivvitam"),
        .price = 400,
        .holdEffectParam = X_ITEM_STAGES,
        .description = COMPOUND_STRING(
        #if B_X_ITEMS_BUFF >= GEN_7
            "Erhöht die Vertei-\n"
            "digung während\n"
            "eines Kampfes deutlich."),
        #else
            "Raises defenses\n"
            "during one battle."),
        #endif
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        //.effect = currently missing
    },

    [ITEM_AUX_POWER] =
    {
        .name = _("Offensivvitam"),
        .price = 400,
        .holdEffectParam = X_ITEM_STAGES,
        .description = COMPOUND_STRING(
        #if B_X_ITEMS_BUFF >= GEN_7
            "Erhöht die Angriffe\n"
            "während eines\n"
            "Gefechts deutlich."),
        #else
            "Raises offenses\n"
            "during one battle."),
        #endif
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        //.effect = currently missing
    },

    [ITEM_AUX_POWERGUARD] =
    {
        .name = _("Kombivitamine"),
        .price = 1200,
        .holdEffectParam = X_ITEM_STAGES,
        .description = COMPOUND_STRING(
        #if B_X_ITEMS_BUFF >= GEN_7
            "Erhöht Angriffs- und\n"
            "Verteidigungswerte während\n"
            "eines Kampfes deutlich."),
        #else
            "Raises offenses\n"
            "and defenses during\n"
            "one battle."),
        #endif
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        //.effect = currently missing
    },

    [ITEM_CHOICE_DUMPLING] =
    {
        .name = _("Walreishappen"),
        .price = 1200,
        .description = sQuestionMarksDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        //.effect = currently missing
    },

    [ITEM_SWAP_SNACK] =
    {
        .name = _("Umkerbratling"),
        .price = 1200,
        .description = sQuestionMarksDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        //.effect = currently missing
    },

    [ITEM_TWICE_SPICED_RADISH] =
    {
        .name = _("Doppelrettich"),
        .price = 1600,
        .description = sQuestionMarksDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        //.effect = currently missing
    },

    [ITEM_POKESHI_DOLL] =
    {
        .name = _("Poké-Kokeshi"),
        .price = 2000,
        .description = COMPOUND_STRING(
            "Ein Holzspielzeug in\n"
            "der Form eines Pokémon.\n"
            "Es kann verkauft werden."),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },
};
