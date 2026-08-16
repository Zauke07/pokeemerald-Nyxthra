#ifdef __INTELLISENSE__
const struct SpeciesInfo gSpeciesInfoGen2[] =
{
#endif

#if P_FAMILY_CHIKORITA
    [SPECIES_CHIKORITA] =
    {
        .baseHP        = 45,
        .baseAttack    = 49,
        .baseDefense   = 65,
        .baseSpeed     = 45,
        .baseSpAttack  = 49,
        .baseSpDefense = 65,
        .types = { TYPE_GRASS, TYPE_GRASS },
        .catchRate = 45,
        .expYield = 64,
        .evYield_SpDefense = 1,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_MONSTER, EGG_GROUP_GRASS },
        .abilities = { ABILITY_OVERGROW, ABILITY_NONE, ABILITY_LEAF_GUARD },
        .bodyColor = BODY_COLOR_GREEN,
        .speciesName = _("Endivie"),
        .cryId = CRY_CHIKORITA,
        .natDexNum = NATIONAL_DEX_CHIKORITA,
        .categoryName = _("Laub"),
        .height = 9,
        .weight = 64,
        .description = POKEDEX_DESC_STRING(
            "Ein süßer Duft geht von dem Blatt\n"
            "auf seinem Kopf aus. Es ist ruhig\n"
            "und liegt gerne in der Sonne."),
        .pokemonScale = 512,
        .pokemonOffset = 20,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Chikorita, 48, 48),
        .frontPicYOffset = 10,
        .frontAnimFrames = sAnims_Chikorita,
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(Chikorita, 56, 48),
        .backPicYOffset = 10,
        .backAnimId = BACK_ANIM_CONCAVE_ARC_SMALL,
        PALETTES(Chikorita),
        ICON(Chikorita, 1),
        .footprint = gMonFootprint_Chikorita,
        LEARNSETS(Chikorita),
        .evolutions = EVOLUTION({EVO_LEVEL, 16, SPECIES_BAYLEEF}),
    },

    [SPECIES_BAYLEEF] =
    {
        .baseHP        = 60,
        .baseAttack    = 62,
        .baseDefense   = 80,
        .baseSpeed     = 60,
        .baseSpAttack  = 63,
        .baseSpDefense = 80,
        .types = { TYPE_GRASS, TYPE_GRASS },
        .catchRate = 45,
        .expYield = 142,
        .evYield_Defense = 1,
        .evYield_SpDefense = 1,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_MONSTER, EGG_GROUP_GRASS },
        .abilities = { ABILITY_OVERGROW, ABILITY_NONE, ABILITY_LEAF_GUARD },
        .bodyColor = BODY_COLOR_GREEN,
        .speciesName = _("Lorblatt"),
        .cryId = CRY_BAYLEEF,
        .natDexNum = NATIONAL_DEX_BAYLEEF,
        .categoryName = _("Laub"),
        .height = 12,
        .weight = 158,
        .description = POKEDEX_DESC_STRING(
            "Die Knospen an seinem Hals geben ein\n"
            "würziges Aroma ab, das andere aufheitert."),
        .pokemonScale = 296,
        .pokemonOffset = 4,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Bayleef, 48, 64),
        .frontPicYOffset = 3,
        .frontAnimFrames = sAnims_Bayleef,
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(Bayleef, 64, 56),
        .backPicYOffset = 5,
        .backAnimId = BACK_ANIM_H_SLIDE,
        PALETTES(Bayleef),
        ICON(Bayleef, 1),
        .footprint = gMonFootprint_Bayleef,
        LEARNSETS(Bayleef),
        .evolutions = EVOLUTION({EVO_LEVEL, 32, SPECIES_MEGANIUM}),
    },

    [SPECIES_MEGANIUM] =
    {
        .baseHP        = 80,
        .baseAttack    = 82,
        .baseDefense   = 100,
        .baseSpeed     = 80,
        .baseSpAttack  = 83,
        .baseSpDefense = 100,
        .types = { TYPE_GRASS, TYPE_GRASS },
        .catchRate = 45,
        .expYield = 236,
        .evYield_Defense = 1,
        .evYield_SpDefense = 2,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_MONSTER, EGG_GROUP_GRASS },
        .abilities = { ABILITY_OVERGROW, ABILITY_NONE, ABILITY_LEAF_GUARD },
        .bodyColor = BODY_COLOR_GREEN,
        .speciesName = _("Meganie"),
        .cryId = CRY_MEGANIUM,
        .natDexNum = NATIONAL_DEX_MEGANIUM,
        .categoryName = _("Kräuter"),
        .height = 18,
        .weight = 1005,
        .description = POKEDEX_DESC_STRING(
            "Meganie kann mit seinem Atem abgestorbene\n"
            "Gräser und Pflanzen reanimieren. Sie sind\n"
            "dann gesund."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 277,
        .trainerOffset = 1,
        FRONT_PIC(Meganium, 48, 64),
        FRONT_PIC_FEMALE(Meganium, 48, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_Meganium,
        .frontAnimId = ANIM_GROW_VIBRATE,
        BACK_PIC(Meganium, 56, 64),
        BACK_PIC_FEMALE(Meganium, 56, 64),
        .backPicYOffset = 2,
        .backAnimId = BACK_ANIM_V_SHAKE,
        PALETTES(Meganium),
        ICON(Meganium, 1),
        .footprint = gMonFootprint_Meganium,
        LEARNSETS(Meganium),
    },
#endif //P_FAMILY_CHIKORITA

#if P_FAMILY_CYNDAQUIL
    [SPECIES_CYNDAQUIL] =
    {
        .baseHP        = 39,
        .baseAttack    = 52,
        .baseDefense   = 43,
        .baseSpeed     = 65,
        .baseSpAttack  = 60,
        .baseSpDefense = 50,
        .types = { TYPE_FIRE, TYPE_FIRE },
        .catchRate = 45,
        .expYield = 62,
        .evYield_Speed = 1,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD },
        .abilities = { ABILITY_BLAZE, ABILITY_NONE, ABILITY_FLASH_FIRE },
        .bodyColor = BODY_COLOR_YELLOW,
        .speciesName = _("Feurigel"),
        .cryId = CRY_CYNDAQUIL,
        .natDexNum = NATIONAL_DEX_CYNDAQUIL,
        .categoryName = _("Feuermaus"),
        .height = 5,
        .weight = 79,
        .description = POKEDEX_DESC_STRING(
            "Erschrickt sich dieses scheue Pokémon,\n"
            "lodern die Flammen auf seinem Rücken\n"
            "kräftiger."),
        .pokemonScale = 539,
        .pokemonOffset = 21,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Cyndaquil, 48, 40),
        .frontPicYOffset = 14,
        .frontAnimFrames = sAnims_Cyndaquil,
        .frontAnimId = ANIM_V_STRETCH,
        BACK_PIC(Cyndaquil, 64, 64),
        .backPicYOffset = 3,
        .backAnimId = BACK_ANIM_CONCAVE_ARC_SMALL,
        PALETTES(Cyndaquil),
        ICON(Cyndaquil, 3),
        .footprint = gMonFootprint_Cyndaquil,
        LEARNSETS(Cyndaquil),
        .evolutions = EVOLUTION({EVO_LEVEL, 14, SPECIES_QUILAVA}),
    },

    [SPECIES_QUILAVA] =
    {
        .baseHP        = 58,
        .baseAttack    = 64,
        .baseDefense   = 58,
        .baseSpeed     = 80,
        .baseSpAttack  = 80,
        .baseSpDefense = 65,
        .types = { TYPE_FIRE, TYPE_FIRE },
        .catchRate = 45,
        .expYield = 142,
        .evYield_Speed = 1,
        .evYield_SpAttack = 1,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD },
        .abilities = { ABILITY_BLAZE, ABILITY_NONE, ABILITY_FLASH_FIRE },
        .bodyColor = BODY_COLOR_YELLOW,
        .speciesName = _("Igelavar"),
        .cryId = CRY_QUILAVA,
        .natDexNum = NATIONAL_DEX_QUILAVA,
        .categoryName = _("Vulkan"),
        .height = 9,
        .weight = 190,
        .description = POKEDEX_DESC_STRING(
            "Vor dem Kampf dreht es dem Feind\n"
            "den Rücken zu, um ihm zu zeigen,\n"
            "wie Furcht erregend sein Feuer\n"
            "lodert."),
        .pokemonScale = 329,
        .pokemonOffset = 11,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Quilava, 64, 48),
        .frontPicYOffset = 9,
        .frontAnimFrames = sAnims_Quilava,
        .frontAnimId = ANIM_H_STRETCH,
        BACK_PIC(Quilava, 64, 64),
        .backPicYOffset = 0,
        .backAnimId = BACK_ANIM_JOLT_RIGHT,
        PALETTES(Quilava),
        ICON(Quilava, 3),
        .footprint = gMonFootprint_Quilava,
        LEARNSETS(Quilava),
        .evolutions = EVOLUTION({EVO_LEVEL, 36, SPECIES_TYPHLOSION},
                                {EVO_NONE, 0, SPECIES_TYPHLOSION_HISUI}),
    },

#define TYPHLOSION_MISC_INFO                                            \
        .catchRate = 45,                                                \
        .expYield = 240,                                                \
        .evYield_SpAttack = 3,                                          \
        .genderRatio = PERCENT_FEMALE(12.5),                            \
        .eggCycles = 20,                                                \
        .friendship = STANDARD_FRIENDSHIP,                              \
        .growthRate = GROWTH_MEDIUM_SLOW,                               \
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD },              \
        .bodyColor = BODY_COLOR_YELLOW,                                 \
        .speciesName = _("Igelavar"),                                 \
        .cryId = CRY_TYPHLOSION,                                        \
        .natDexNum = NATIONAL_DEX_TYPHLOSION,                           \
        .footprint = gMonFootprint_Typhlosion,                          \
        .formSpeciesIdTable = sTyphlosionFormSpeciesIdTable

    [SPECIES_TYPHLOSION] =
    {
        TYPHLOSION_MISC_INFO,
        .baseHP        = 78,
        .baseAttack    = 84,
        .baseDefense   = 78,
        .baseSpeed     = 100,
        .baseSpAttack  = 109,
        .baseSpDefense = 85,
        .types = { TYPE_FIRE, TYPE_FIRE },
        .abilities = { ABILITY_BLAZE, ABILITY_NONE, ABILITY_FLASH_FIRE },
        .categoryName = _("Vulkan"),
        .height = 17,
        .weight = 795,
        .description = POKEDEX_DESC_STRING(
            "Es verfügt über eine verheerende\n"
            "Geheimattacke. Es reibt sein Fell, um\n"
            "Explosionen zu erzeugen."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 268,
        .trainerOffset = 1,
        FRONT_PIC(Typhlosion, 56, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_Typhlosion,
        .frontAnimId = ANIM_V_SHAKE,
        .frontAnimDelay = 20,
        BACK_PIC(Typhlosion, 64, 64),
        .backPicYOffset = 3,
        .backAnimId = BACK_ANIM_SHAKE_GLOW_RED,
        PALETTES(Typhlosion),
        ICON(Typhlosion, 3),
        LEARNSETS(Typhlosion),
    },

#if P_HISUIAN_FORMS
    [SPECIES_TYPHLOSION_HISUI] =
    {
        TYPHLOSION_MISC_INFO,
        .baseHP        = 73,
        .baseAttack    = 84,
        .baseDefense   = 78,
        .baseSpeed     = 95,
        .baseSpAttack  = 119,
        .baseSpDefense = 85,
        .types = { TYPE_FIRE, TYPE_GHOST },
        .abilities = { ABILITY_BLAZE, ABILITY_NONE, ABILITY_FRISK },
        .categoryName = _("Vulkan"),
        .height = 16,
        .weight = 698,
        .description = POKEDEX_DESC_STRING(
            "Wenn sein Zorn den Zenit\n"
            "übersteigt, wird es so heiß, dass\n"
            "alles, was es berührt, in Flammen\n"
            "aufgeht."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 268,
        .trainerOffset = 1,
        FRONT_PIC(TyphlosionHisuian, 48, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_TyphlosionHisuian,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(TyphlosionHisuian, 64, 56),
        .backPicYOffset = 2,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(TyphlosionHisuian),
        ICON(TyphlosionHisuian, 1),
        LEARNSETS(TyphlosionHisuian),
        .isHisuianForm = TRUE,
    },
#endif //P_HISUIAN_FORMS
#endif //P_FAMILY_CYNDAQUIL

#if P_FAMILY_TOTODILE
    [SPECIES_TOTODILE] =
    {
        .baseHP        = 50,
        .baseAttack    = 65,
        .baseDefense   = 64,
        .baseSpeed     = 43,
        .baseSpAttack  = 44,
        .baseSpDefense = 48,
        .types = { TYPE_WATER, TYPE_WATER },
        .catchRate = 45,
        .expYield = 63,
        .evYield_Attack = 1,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_MONSTER, EGG_GROUP_WATER_1 },
        .abilities = { ABILITY_TORRENT, ABILITY_NONE, ABILITY_SHEER_FORCE },
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Karnimani"),
        .cryId = CRY_TOTODILE,
        .natDexNum = NATIONAL_DEX_TOTODILE,
        .categoryName = _("Großmaul"),
        .height = 6,
        .weight = 95,
        .description = POKEDEX_DESC_STRING(
            "Es ist klein, aber zäh und stark.\n"
            "Es zögert nicht, jeden anzugreifen,\n"
            "wenn dieser ihm zu nahe kommt."),
        .pokemonScale = 487,
        .pokemonOffset = 20,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Totodile, 40, 40),
        .frontPicYOffset = 14,
        .frontAnimFrames = sAnims_Totodile,
        .frontAnimId = ANIM_H_JUMPS,
        BACK_PIC(Totodile, 56, 48),
        .backPicYOffset = 10,
        .backAnimId = BACK_ANIM_JOLT_RIGHT,
        PALETTES(Totodile),
        ICON(Totodile, 0),
        .footprint = gMonFootprint_Totodile,
        LEARNSETS(Totodile),
        .evolutions = EVOLUTION({EVO_LEVEL, 18, SPECIES_CROCONAW}),
    },

    [SPECIES_CROCONAW] =
    {
        .baseHP        = 65,
        .baseAttack    = 80,
        .baseDefense   = 80,
        .baseSpeed     = 58,
        .baseSpAttack  = 59,
        .baseSpDefense = 63,
        .types = { TYPE_WATER, TYPE_WATER },
        .catchRate = 45,
        .expYield = 142,
        .evYield_Attack = 1,
        .evYield_Defense = 1,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_MONSTER, EGG_GROUP_WATER_1 },
        .abilities = { ABILITY_TORRENT, ABILITY_NONE, ABILITY_SHEER_FORCE },
        .bodyColor = BODY_COLOR_BLUE,
        .noFlip = TRUE,
        .speciesName = _("Tyracroc"),
        .cryId = CRY_CROCONAW,
        .natDexNum = NATIONAL_DEX_CROCONAW,
        .categoryName = _("Großmaul"),
        .height = 11,
        .weight = 250,
        .description = POKEDEX_DESC_STRING(
            "Hat es einmal zugebissen, lässt es erst\n"
            "los, wenn es seine Zähne verliert, die\n"
            "schnell nachwachsen."),
        .pokemonScale = 378,
        .pokemonOffset = 13,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Croconaw, 48, 56),
        .frontPicYOffset = 5,
        .frontAnimFrames = sAnims_Croconaw,
        .frontAnimId = ANIM_H_SHAKE,
        BACK_PIC(Croconaw, 56, 64),
        .backPicYOffset = 2,
        .backAnimId = BACK_ANIM_JOLT_RIGHT,
        PALETTES(Croconaw),
        ICON(Croconaw, 0),
        .footprint = gMonFootprint_Croconaw,
        LEARNSETS(Croconaw),
        .evolutions = EVOLUTION({EVO_LEVEL, 30, SPECIES_FERALIGATR}),
    },

    [SPECIES_FERALIGATR] =
    {
        .baseHP        = 85,
        .baseAttack    = 105,
        .baseDefense   = 100,
        .baseSpeed     = 78,
        .baseSpAttack  = 79,
        .baseSpDefense = 83,
        .types = { TYPE_WATER, TYPE_WATER },
        .catchRate = 45,
        .expYield = 239,
        .evYield_Attack = 2,
        .evYield_Defense = 1,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_MONSTER, EGG_GROUP_WATER_1 },
        .abilities = { ABILITY_TORRENT, ABILITY_NONE, ABILITY_SHEER_FORCE },
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Impergator"),
        .cryId = CRY_FERALIGATR,
        .natDexNum = NATIONAL_DEX_FERALIGATR,
        .categoryName = _("Großmaul"),
        .height = 23,
        .weight = 888,
        .description = POKEDEX_DESC_STRING(
            "Eigentlich bewegt es sich langsam,\n"
            "doch seine Beute greift es\n"
            "blitzschnell an."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 342,
        .trainerOffset = 7,
        FRONT_PIC(Feraligatr, 64, 64),
        .frontPicYOffset = 1,
        .frontAnimFrames = sAnims_Feraligatr,
        .frontAnimId = ANIM_H_SHAKE,
        .frontAnimDelay = 5,
        BACK_PIC(Feraligatr, 56, 64),
        .backPicYOffset = 2,
        .backAnimId = BACK_ANIM_V_SHAKE,
        PALETTES(Feraligatr),
        ICON(Feraligatr, 0),
        .footprint = gMonFootprint_Feraligatr,
        LEARNSETS(Feraligatr),
    },
#endif //P_FAMILY_TOTODILE

#if P_FAMILY_SENTRET
    [SPECIES_SENTRET] =
    {
        .baseHP        = 35,
        .baseAttack    = 46,
        .baseDefense   = 34,
        .baseSpeed     = 20,
        .baseSpAttack  = 35,
        .baseSpDefense = 45,
        .types = { TYPE_NORMAL, TYPE_NORMAL },
        .catchRate = 255,
        .expYield = 43,
        .evYield_Attack = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD },
        .abilities = { ABILITY_RUN_AWAY, ABILITY_KEEN_EYE, ABILITY_FRISK },
        .bodyColor = BODY_COLOR_BROWN,
        .speciesName = _("Wiesor"),
        .cryId = CRY_SENTRET,
        .natDexNum = NATIONAL_DEX_SENTRET,
        .categoryName = _("Späher"),
        .height = 8,
        .weight = 60,
        .description = POKEDEX_DESC_STRING(
            "Es stellt sich auf den Schweif, um weiter\n"
            "zu blicken. Erspäht es einen Feind,\n"
            "schreit es laut auf."),
        .pokemonScale = 439,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Sentret, 40, 64),
        .frontPicYOffset = 2,
        .frontAnimFrames = sAnims_Sentret,
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(Sentret, 48, 64),
        .backPicYOffset = 0,
        .backAnimId = BACK_ANIM_CONCAVE_ARC_SMALL,
        PALETTES(Sentret),
        ICON(Sentret, 2),
        .footprint = gMonFootprint_Sentret,
        LEARNSETS(Sentret),
        .evolutions = EVOLUTION({EVO_LEVEL, 15, SPECIES_FURRET}),
    },

    [SPECIES_FURRET] =
    {
        .baseHP        = 85,
        .baseAttack    = 76,
        .baseDefense   = 64,
        .baseSpeed     = 90,
        .baseSpAttack  = 45,
        .baseSpDefense = 55,
        .types = { TYPE_NORMAL, TYPE_NORMAL },
        .catchRate = 90,
        .expYield = 145,
        .evYield_Speed = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD },
        .abilities = { ABILITY_RUN_AWAY, ABILITY_KEEN_EYE, ABILITY_FRISK },
        .bodyColor = BODY_COLOR_BROWN,
        .speciesName = _("Wiesenior"),
        .cryId = CRY_FURRET,
        .natDexNum = NATIONAL_DEX_FURRET,
        .categoryName = _("Langleib"),
        .height = 18,
        .weight = 325,
        .description = POKEDEX_DESC_STRING(
            "Sein Nest ist seinem schmalen und dünnen\n"
            "Körper angepasst. Kein anderes Pokémon\n"
            "kommt hinein."),
        .pokemonScale = 346,
        .pokemonOffset = 11,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Furret, 48, 56),
        .frontPicYOffset = 4,
        .frontAnimFrames = sAnims_Furret,
        .frontAnimId = ANIM_H_JUMPS_V_STRETCH,
        BACK_PIC(Furret, 64, 56),
        .backPicYOffset = 6,
        .backAnimId = BACK_ANIM_CONCAVE_ARC_LARGE,
        PALETTES(Furret),
        ICON(Furret, 2),
        .footprint = gMonFootprint_Furret,
        LEARNSETS(Furret),
    },
#endif //P_FAMILY_SENTRET

#if P_FAMILY_HOOTHOOT
    [SPECIES_HOOTHOOT] =
    {
        .baseHP        = 60,
        .baseAttack    = 30,
        .baseDefense   = 30,
        .baseSpeed     = 50,
        .baseSpAttack  = 36,
        .baseSpDefense = 56,
        .types = { TYPE_NORMAL, TYPE_FLYING },
        .catchRate = 255,
        .expYield = 52,
        .evYield_HP = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_FLYING, EGG_GROUP_FLYING },
        .abilities = { ABILITY_INSOMNIA, ABILITY_KEEN_EYE, ABILITY_TINTED_LENS },
        .bodyColor = BODY_COLOR_BROWN,
        .speciesName = _("Hoothoot"),
        .cryId = CRY_HOOTHOOT,
        .natDexNum = NATIONAL_DEX_HOOTHOOT,
        .categoryName = _("Eulen"),
        .height = 7,
        .weight = 212,
        .description = POKEDEX_DESC_STRING(
            "Es neigt seinen Kopf tagein, tagaus in\n"
            "einem festgelegten Rhythmus. Früher\n"
            "verwendete man es als Uhr."),
        .pokemonScale = 380,
        .pokemonOffset = -2,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Hoothoot, 40, 40),
        .frontPicYOffset = 12,
        .frontAnimFrames = sAnims_Hoothoot,
        .frontAnimId = ANIM_V_SLIDE_SLOW,
        BACK_PIC(Hoothoot, 56, 64),
        .backPicYOffset = 4,
        .backAnimId = BACK_ANIM_CONVEX_DOUBLE_ARC,
        PALETTES(Hoothoot),
        ICON(Hoothoot, 2),
        .footprint = gMonFootprint_Hoothoot,
        LEARNSETS(Hoothoot),
        .evolutions = EVOLUTION({EVO_LEVEL, 20, SPECIES_NOCTOWL}),
    },

    [SPECIES_NOCTOWL] =
    {
        .baseHP        = 100,
        .baseAttack    = 50,
        .baseDefense   = 50,
        .baseSpeed     = 70,
        .baseSpAttack  = P_UPDATED_STATS >= GEN_7 ? 86 : 76,
        .baseSpDefense = 96,
        .types = { TYPE_NORMAL, TYPE_FLYING },
        .catchRate = 90,
        .expYield = 158,
        .evYield_HP = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_FLYING, EGG_GROUP_FLYING },
        .abilities = { ABILITY_INSOMNIA, ABILITY_KEEN_EYE, ABILITY_TINTED_LENS },
        .bodyColor = BODY_COLOR_BROWN,
        .speciesName = _("Noctuh"),
        .cryId = CRY_NOCTOWL,
        .natDexNum = NATIONAL_DEX_NOCTOWL,
        .categoryName = _("Eulen"),
        .height = 16,
        .weight = 408,
        .description = POKEDEX_DESC_STRING(
            "Muss es nachdenken, dreht es seinen Kopf\n"
            "um 180 Grad, um so seinen Intellekt zu\n"
            "schärfen."),
        .pokemonScale = 278,
        .pokemonOffset = 3,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Noctowl, 40, 64),
        .frontPicYOffset = 2,
        .frontAnimFrames = sAnims_Noctowl,
        .frontAnimId = ANIM_V_STRETCH,
        BACK_PIC(Noctowl, 48, 64),
        .backPicYOffset = 3,
        .backAnimId = BACK_ANIM_TRIANGLE_DOWN,
        PALETTES(Noctowl),
        ICON(Noctowl, 2),
        .footprint = gMonFootprint_Noctowl,
        LEARNSETS(Noctowl),
    },
#endif //P_FAMILY_HOOTHOOT

#if P_FAMILY_LEDYBA
    [SPECIES_LEDYBA] =
    {
        .baseHP        = 40,
        .baseAttack    = 20,
        .baseDefense   = 30,
        .baseSpeed     = 55,
        .baseSpAttack  = 40,
        .baseSpDefense = 80,
        .types = { TYPE_BUG, TYPE_FLYING },
        .catchRate = 255,
        .expYield = 53,
        .evYield_SpDefense = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_FAST,
        .eggGroups = { EGG_GROUP_BUG, EGG_GROUP_BUG },
        .abilities = { ABILITY_SWARM, ABILITY_EARLY_BIRD, ABILITY_RATTLED },
        .bodyColor = BODY_COLOR_RED,
        .speciesName = _("Ledyba"),
        .cryId = CRY_LEDYBA,
        .natDexNum = NATIONAL_DEX_LEDYBA,
        .categoryName = _("Fünf-Punkt"),
        .height = 10,
        .weight = 108,
        .description = POKEDEX_DESC_STRING(
            "Dieses Pokémon reagiert sehr empfindlich\n"
            "auf Kälte. Im warmen Klima Alolas strotzt\n"
            "es nur so vor Lebensfreude."),
        .pokemonScale = 256,
        .pokemonOffset = 4,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Ledyba, 48, 48),
        FRONT_PIC_FEMALE(Ledyba, 48, 48),
        .frontPicYOffset = 10,
        .frontAnimFrames = sAnims_Ledyba,
        .frontAnimId = ANIM_V_JUMPS_SMALL,
        BACK_PIC(Ledyba, 56, 48),
        BACK_PIC_FEMALE(Ledyba, 56, 48),
        .backPicYOffset = 8,
        .backAnimId = BACK_ANIM_V_SHAKE_H_SLIDE,
        PALETTES(Ledyba),
        ICON(Ledyba, 0),
        .footprint = gMonFootprint_Ledyba,
        LEARNSETS(Ledyba),
        .evolutions = EVOLUTION({EVO_LEVEL, 18, SPECIES_LEDIAN}),
    },

    [SPECIES_LEDIAN] =
    {
        .baseHP        = 55,
        .baseAttack    = 35,
        .baseDefense   = 50,
        .baseSpeed     = 85,
        .baseSpAttack  = 55,
        .baseSpDefense = 110,
        .types = { TYPE_BUG, TYPE_FLYING },
        .catchRate = 90,
        .expYield = 137,
        .evYield_SpDefense = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_FAST,
        .eggGroups = { EGG_GROUP_BUG, EGG_GROUP_BUG },
        .abilities = { ABILITY_SWARM, ABILITY_EARLY_BIRD, ABILITY_IRON_FIST },
        .bodyColor = BODY_COLOR_RED,
        .speciesName = _("Ledian"),
        .cryId = CRY_LEDIAN,
        .natDexNum = NATIONAL_DEX_LEDIAN,
        .categoryName = _("Fünf-Punkt"),
        .height = 14,
        .weight = 356,
        .description = POKEDEX_DESC_STRING(
            "Leuchten die Sterne am Nachthimmel,\n"
            "schwirrt es umher und verstreut\n"
            "einen strahlenden, leuchtenden\n"
            "Puder."),
        .pokemonScale = 256,
        .pokemonOffset = 2,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Ledian, 48, 56),
        FRONT_PIC_FEMALE(Ledian, 48, 56),
        .frontPicYOffset = 6,
        .frontAnimFrames = sAnims_Ledian,
        .frontAnimId = ANIM_V_SLIDE_WOBBLE,
        .enemyMonElevation = 10,
        BACK_PIC(Ledian, 64, 64),
        BACK_PIC_FEMALE(Ledian, 64, 64),
        .backPicYOffset = 3,
        .backAnimId = BACK_ANIM_CONVEX_DOUBLE_ARC,
        PALETTES(Ledian),
        ICON(Ledian, 0),
        .footprint = gMonFootprint_Ledian,
        LEARNSETS(Ledian),
    },
#endif //P_FAMILY_LEDYBA

#if P_FAMILY_SPINARAK
    [SPECIES_SPINARAK] =
    {
        .baseHP        = 40,
        .baseAttack    = 60,
        .baseDefense   = 40,
        .baseSpeed     = 30,
        .baseSpAttack  = 40,
        .baseSpDefense = 40,
        .types = { TYPE_BUG, TYPE_POISON },
        .catchRate = 255,
        .expYield = 50,
        .evYield_Attack = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_FAST,
        .eggGroups = { EGG_GROUP_BUG, EGG_GROUP_BUG },
        .abilities = { ABILITY_SWARM, ABILITY_INSOMNIA, ABILITY_SNIPER },
        .bodyColor = BODY_COLOR_GREEN,
        .speciesName = _("Webarak"),
        .cryId = CRY_SPINARAK,
        .natDexNum = NATIONAL_DEX_SPINARAK,
        .categoryName = _("Fadenwurf"),
        .height = 5,
        .weight = 85,
        .description = POKEDEX_DESC_STRING(
            "Es spinnt ein Netz aus feinem, aber\n"
            "reißfestem Faden. Dann wartet es\n"
            "auf Beute, die im Netz zappelt."),
        .pokemonScale = 414,
        .pokemonOffset = 21,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Spinarak, 48, 32),
        .frontPicYOffset = 16,
        .frontAnimFrames = sAnims_Spinarak,
        .frontAnimId = ANIM_CIRCLE_C_CLOCKWISE_SLOW,
        BACK_PIC(Spinarak, 64, 32),
        .backPicYOffset = 16,
        .backAnimId = BACK_ANIM_V_SHAKE_H_SLIDE,
        PALETTES(Spinarak),
        ICON(Spinarak, 1),
        .footprint = gMonFootprint_Spinarak,
        LEARNSETS(Spinarak),
        .evolutions = EVOLUTION({EVO_LEVEL, 22, SPECIES_ARIADOS}),
    },

    [SPECIES_ARIADOS] =
    {
        .baseHP        = 70,
        .baseAttack    = 90,
        .baseDefense   = 70,
        .baseSpeed     = 40,
        .baseSpAttack  = 60,
        .baseSpDefense = P_UPDATED_STATS >= GEN_7 ? 70 : 60,
        .types = { TYPE_BUG, TYPE_POISON },
        .catchRate = 90,
        .expYield = 140,
        .evYield_Attack = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_FAST,
        .eggGroups = { EGG_GROUP_BUG, EGG_GROUP_BUG },
        .abilities = { ABILITY_SWARM, ABILITY_INSOMNIA, ABILITY_SNIPER },
        .bodyColor = BODY_COLOR_RED,
        .speciesName = _("Ariados"),
        .cryId = CRY_ARIADOS,
        .natDexNum = NATIONAL_DEX_ARIADOS,
        .categoryName = _("Langbein"),
        .height = 11,
        .weight = 335,
        .description = POKEDEX_DESC_STRING(
            "Da es Fäden sowohl mit dem\n"
            "Hinterleib als auch mit dem Mund\n"
            "spinnt, verwechselt man die beiden\n"
            "leicht."),
        .pokemonScale = 316,
        .pokemonOffset = 8,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Ariados, 64, 56),
        .frontPicYOffset = 7,
        .frontAnimFrames = sAnims_Ariados,
        .frontAnimId = ANIM_H_SHAKE,
        BACK_PIC(Ariados, 64, 48),
        .backPicYOffset = 9,
        .backAnimId = BACK_ANIM_H_SLIDE,
        PALETTES(Ariados),
        ICON(Ariados, 0),
        .footprint = gMonFootprint_Ariados,
        LEARNSETS(Ariados),
    },
#endif //P_FAMILY_SPINARAK

#if P_FAMILY_CHINCHOU
    [SPECIES_CHINCHOU] =
    {
        .baseHP        = 75,
        .baseAttack    = 38,
        .baseDefense   = 38,
        .baseSpeed     = 67,
        .baseSpAttack  = 56,
        .baseSpDefense = 56,
        .types = { TYPE_WATER, TYPE_ELECTRIC },
        .catchRate = 190,
        .expYield = 66,
        .evYield_HP = 1,
        .itemRare = ITEM_DEEP_SEA_SCALE,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_WATER_2, EGG_GROUP_WATER_2 },
        .abilities = { ABILITY_VOLT_ABSORB, ABILITY_ILLUMINATE, ABILITY_WATER_ABSORB },
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Lampi"),
        .cryId = CRY_CHINCHOU,
        .natDexNum = NATIONAL_DEX_CHINCHOU,
        .categoryName = _("Angler"),
        .height = 5,
        .weight = 120,
        .description = POKEDEX_DESC_STRING(
            "Am Meeresgrund kann es sich nur\n"
            "durch ständiges Flackern seiner\n"
            "Lichter der Umgebung kundtun."),
        .pokemonScale = 424,
        .pokemonOffset = -2,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Chinchou, 64, 48),
        .frontPicYOffset = 12,
        .frontAnimFrames = sAnims_Chinchou,
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE_SLOW,
        BACK_PIC(Chinchou, 64, 48),
        .backPicYOffset = 11,
        .backAnimId = BACK_ANIM_V_STRETCH,
        PALETTES(Chinchou),
        ICON(Chinchou, 2),
        .footprint = gMonFootprint_Chinchou,
        LEARNSETS(Chinchou),
        .evolutions = EVOLUTION({EVO_LEVEL, 27, SPECIES_LANTURN}),
    },

    [SPECIES_LANTURN] =
    {
        .baseHP        = 125,
        .baseAttack    = 58,
        .baseDefense   = 58,
        .baseSpeed     = 67,
        .baseSpAttack  = 76,
        .baseSpDefense = 76,
        .types = { TYPE_WATER, TYPE_ELECTRIC },
        .catchRate = 75,
        .expYield = 161,
        .evYield_HP = 2,
        .itemRare = ITEM_DEEP_SEA_SCALE,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_WATER_2, EGG_GROUP_WATER_2 },
        .abilities = { ABILITY_VOLT_ABSORB, ABILITY_ILLUMINATE, ABILITY_WATER_ABSORB },
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Lanturn"),
        .cryId = CRY_LANTURN,
        .natDexNum = NATIONAL_DEX_LANTURN,
        .categoryName = _("Leuchten"),
        .height = 12,
        .weight = 225,
        .description = POKEDEX_DESC_STRING(
            "Lanturns Licht kann aus großen\n"
            "Tiefen heraufscheinen. Man nennt es\n"
            "auch "Tiefseestern"."),
        .pokemonScale = 269,
        .pokemonOffset = 6,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Lanturn, 64, 48),
        .frontPicYOffset = 11,
        .frontAnimFrames = sAnims_Lanturn,
        .frontAnimId = ANIM_V_SLIDE_WOBBLE_SMALL,
        BACK_PIC(Lanturn, 64, 56),
        .backPicYOffset = 6,
        .backAnimId = BACK_ANIM_SHAKE_FLASH_YELLOW,
        PALETTES(Lanturn),
        ICON(Lanturn, 0),
        .footprint = gMonFootprint_Lanturn,
        LEARNSETS(Lanturn),
    },
#endif //P_FAMILY_CHINCHOU

#if P_FAMILY_TOGEPI
#define TOGEPI_FAMILY_TYPE (P_UPDATED_TYPES >= GEN_6 ? TYPE_FAIRY : TYPE_NORMAL)

    [SPECIES_TOGEPI] =
    {
        .baseHP        = 35,
        .baseAttack    = 20,
        .baseDefense   = 65,
        .baseSpeed     = 20,
        .baseSpAttack  = 40,
        .baseSpDefense = 65,
        .types = { TOGEPI_FAMILY_TYPE, TOGEPI_FAMILY_TYPE },
        .catchRate = 190,
        .expYield = 49,
        .evYield_SpDefense = 1,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 10,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_FAST,
        .eggGroups = { EGG_GROUP_NO_EGGS_DISCOVERED, EGG_GROUP_NO_EGGS_DISCOVERED },
        .abilities = { ABILITY_HUSTLE, ABILITY_SERENE_GRACE, ABILITY_SUPER_LUCK },
        .bodyColor = BODY_COLOR_WHITE,
        .speciesName = _("Togepi"),
        .cryId = CRY_TOGEPI,
        .natDexNum = NATIONAL_DEX_TOGEPI,
        .categoryName = _("Zackenball"),
        .height = 3,
        .weight = 15,
        .description = POKEDEX_DESC_STRING(
            "Es gilt als Glücksbringer. Man sagt, seine\n"
            "Schale sei voll von purer Freude."),
        .pokemonScale = 507,
        .pokemonOffset = 23,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Togepi, 24, 32),
        .frontPicYOffset = 16,
        .frontAnimFrames = sAnims_Togepi,
        .frontAnimId = ANIM_V_JUMPS_BIG,
        BACK_PIC(Togepi, 48, 40),
        .backPicYOffset = 12,
        .backAnimId = BACK_ANIM_DIP_RIGHT_SIDE,
        PALETTES(Togepi),
        ICON(Togepi, 0),
        .footprint = gMonFootprint_Togepi,
        LEARNSETS(Togepi),
        .evolutions = EVOLUTION({EVO_FRIENDSHIP, 0, SPECIES_TOGETIC}),
    },

    [SPECIES_TOGETIC] =
    {
        .baseHP        = 55,
        .baseAttack    = 40,
        .baseDefense   = 85,
        .baseSpeed     = 40,
        .baseSpAttack  = 80,
        .baseSpDefense = 105,
        .types = { TOGEPI_FAMILY_TYPE, TYPE_FLYING },
        .catchRate = 75,
        .expYield = 142,
        .evYield_SpDefense = 2,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 10,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_FAST,
        .eggGroups = { EGG_GROUP_FLYING, EGG_GROUP_FAIRY },
        .abilities = { ABILITY_HUSTLE, ABILITY_SERENE_GRACE, ABILITY_SUPER_LUCK },
        .bodyColor = BODY_COLOR_WHITE,
        .speciesName = _("Togetic"),
        .cryId = CRY_TOGETIC,
        .natDexNum = NATIONAL_DEX_TOGETIC,
        .categoryName = _("Freuden"),
        .height = 6,
        .weight = 32,
        .description = POKEDEX_DESC_STRING(
            "Es wird entmutigt, wenn es unter\n"
            "unfreundlichen Menschen ist. Es\n"
            "kann ohne Flügel niedrig schweben."),
        .pokemonScale = 424,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Togetic, 32, 48),
        .frontPicYOffset = 8,
        .frontAnimFrames = sAnims_Togetic,
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(Togetic, 56, 56),
        .backPicYOffset = 6,
        .backAnimId = BACK_ANIM_CONVEX_DOUBLE_ARC,
        PALETTES(Togetic),
        ICON(Togetic, 0),
        .footprint = gMonFootprint_Togetic,
        LEARNSETS(Togetic),
        .evolutions = EVOLUTION({EVO_ITEM, ITEM_SHINY_STONE, SPECIES_TOGEKISS}),
    },

#if P_GEN_4_CROSS_EVOS
    [SPECIES_TOGEKISS] =
    {
        .baseHP        = 85,
        .baseAttack    = 50,
        .baseDefense   = 95,
        .baseSpeed     = 80,
        .baseSpAttack  = 120,
        .baseSpDefense = 115,
        #if P_UPDATED_TYPES >= GEN_6
            .types = { TOGEPI_FAMILY_TYPE, TYPE_FLYING },
        #else
            .types = { TYPE_NORMAL, TYPE_FLYING },
        #endif
        .catchRate = 30,
        .expYield = 245,
        .evYield_SpAttack = 2,
        .evYield_SpDefense = 1,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 10,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_FAST,
        .eggGroups = { EGG_GROUP_FLYING, EGG_GROUP_FAIRY },
        .abilities = { ABILITY_HUSTLE, ABILITY_SERENE_GRACE, ABILITY_SUPER_LUCK },
        .bodyColor = BODY_COLOR_WHITE,
        .noFlip = TRUE,
        .speciesName = _("Togekiss"),
        .cryId = CRY_TOGEKISS,
        .natDexNum = NATIONAL_DEX_TOGEKISS,
        .categoryName = _("Jubilierer"),
        .height = 15,
        .weight = 380,
        .description = POKEDEX_DESC_STRING(
            "Es heißt, Togekiss erscheine in\n"
            "friedlichen Zeiten und verteile alle\n"
            "möglichen Wohltaten."),
        .pokemonScale = 268,
        .pokemonOffset = 2,
        .trainerScale = 271,
        .trainerOffset = 0,
        FRONT_PIC(Togekiss, 64, 56),
        .frontPicYOffset = 10,
        .frontAnimFrames = sAnims_Togekiss,
        .frontAnimId = ANIM_SWING_CONVEX,
        .enemyMonElevation = 14,
        BACK_PIC(Togekiss, 64, 48),
        .backPicYOffset = 10,
        .backAnimId = BACK_ANIM_CONCAVE_ARC_LARGE,
        PALETTES(Togekiss),
        ICON(Togekiss, 2),
        .footprint = gMonFootprint_Togekiss,
        LEARNSETS(Togekiss),
    },
#endif //P_GEN_4_CROSS_EVOS
#endif //P_FAMILY_TOGEPI

#if P_FAMILY_NATU
    [SPECIES_NATU] =
    {
        .baseHP        = 40,
        .baseAttack    = 50,
        .baseDefense   = 45,
        .baseSpeed     = 70,
        .baseSpAttack  = 70,
        .baseSpDefense = 45,
        .types = { TYPE_PSYCHIC, TYPE_FLYING },
        .catchRate = 190,
        .expYield = 64,
        .evYield_SpAttack = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_FLYING, EGG_GROUP_FLYING },
        .abilities = { ABILITY_SYNCHRONIZE, ABILITY_EARLY_BIRD, ABILITY_MAGIC_BOUNCE },
        .bodyColor = BODY_COLOR_GREEN,
        .speciesName = _("Natu"),
        .cryId = CRY_NATU,
        .natDexNum = NATIONAL_DEX_NATU,
        .categoryName = _("Kleinvogel"),
        .height = 2,
        .weight = 20,
        .description = POKEDEX_DESC_STRING(
            "Es ist ein hervorragender Kletterer.\n"
            "Besonders gern steigt es auf Bäume und\n"
            "frisst die jungen Triebe ab."),
        .pokemonScale = 610,
        .pokemonOffset = 25,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Natu, 32, 32),
        .frontPicYOffset = 17,
        .frontAnimFrames = sAnims_Natu,
        .frontAnimId = ANIM_H_JUMPS,
        .frontAnimDelay = 30,
        BACK_PIC(Natu, 40, 40),
        .backPicYOffset = 15,
        .backAnimId = BACK_ANIM_CONCAVE_ARC_SMALL,
        PALETTES(Natu),
        ICON(Natu, 1),
        .footprint = gMonFootprint_Natu,
        LEARNSETS(Natu),
        .evolutions = EVOLUTION({EVO_LEVEL, 25, SPECIES_XATU}),
    },

    [SPECIES_XATU] =
    {
        .baseHP        = 65,
        .baseAttack    = 75,
        .baseDefense   = 70,
        .baseSpeed     = 95,
        .baseSpAttack  = 95,
        .baseSpDefense = 70,
        .types = { TYPE_PSYCHIC, TYPE_FLYING },
        .catchRate = 75,
        .expYield = 165,
        .evYield_Speed = 1,
        .evYield_SpAttack = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_FLYING, EGG_GROUP_FLYING },
        .abilities = { ABILITY_SYNCHRONIZE, ABILITY_EARLY_BIRD, ABILITY_MAGIC_BOUNCE },
        .bodyColor = BODY_COLOR_GREEN,
        .speciesName = _("Xatu"),
        .cryId = CRY_XATU,
        .natDexNum = NATIONAL_DEX_XATU,
        .categoryName = _("Mystik"),
        .height = 15,
        .weight = 150,
        .description = POKEDEX_DESC_STRING(
            "Man sagt, es sei so still und in sich\n"
            "gekehrt, weil es die Zukunft und die\n"
            "Vergangenheit parallel sieht."),
        .pokemonScale = 256,
        .pokemonOffset = 6,
        .trainerScale = 318,
        .trainerOffset = 4,
        FRONT_PIC(Xatu, 40, 56),
        FRONT_PIC_FEMALE(Xatu, 40, 56),
        .frontPicYOffset = 5,
        .frontAnimFrames = sAnims_Xatu,
        .frontAnimId = ANIM_GROW_VIBRATE,
        BACK_PIC(Xatu, 64, 56),
        .backPicYOffset = 6,
        .backAnimId = BACK_ANIM_SHRINK_GROW_VIBRATE,
        PALETTES(Xatu),
        ICON(Xatu, 1),
        .footprint = gMonFootprint_Xatu,
        LEARNSETS(Xatu),
    },
#endif //P_FAMILY_NATU

#if P_FAMILY_MAREEP
    [SPECIES_MAREEP] =
    {
        .baseHP        = 55,
        .baseAttack    = 40,
        .baseDefense   = 40,
        .baseSpeed     = 35,
        .baseSpAttack  = 65,
        .baseSpDefense = 45,
        .types = { TYPE_ELECTRIC, TYPE_ELECTRIC },
        .catchRate = 235,
        .expYield = 56,
        .evYield_SpAttack = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_MONSTER, EGG_GROUP_FIELD },
        .abilities = { ABILITY_STATIC, ABILITY_NONE, ABILITY_PLUS },
        .bodyColor = BODY_COLOR_WHITE,
        .speciesName = _("Voltilamm"),
        .cryId = CRY_MAREEP,
        .natDexNum = NATIONAL_DEX_MAREEP,
        .categoryName = _("Wolle"),
        .height = 6,
        .weight = 78,
        .description = POKEDEX_DESC_STRING(
            "Sein weiches Fell wird doppelt so\n"
            "dick, wenn sich Elektrizität\n"
            "aufbaut."),
        .pokemonScale = 379,
        .pokemonOffset = 18,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Mareep, 40, 48),
        .frontPicYOffset = 12,
        .frontAnimFrames = sAnims_Mareep,
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .frontAnimDelay = 50,
        BACK_PIC(Mareep, 56, 40),
        .backPicYOffset = 15,
        .backAnimId = BACK_ANIM_CONCAVE_ARC_SMALL,
        PALETTES(Mareep),
        ICON(Mareep, 0),
        .footprint = gMonFootprint_Mareep,
        LEARNSETS(Mareep),
        .formSpeciesIdTable = sMareepFormSpeciesIdTable,
        .formChangeTable = sMareepFormChangeTable,
        .evolutions = EVOLUTION({EVO_LEVEL, 15, SPECIES_FLAAFFY}),
    },

    [SPECIES_FLAAFFY] =
    {
        .baseHP        = 70,
        .baseAttack    = 55,
        .baseDefense   = 55,
        .baseSpeed     = 45,
        .baseSpAttack  = 80,
        .baseSpDefense = 60,
        .types = { TYPE_ELECTRIC, TYPE_ELECTRIC },
        .catchRate = 120,
        .expYield = 128,
        .evYield_SpAttack = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_MONSTER, EGG_GROUP_FIELD },
        .abilities = { ABILITY_STATIC, ABILITY_NONE, ABILITY_PLUS },
        .bodyColor = BODY_COLOR_PINK,
        .speciesName = _("Waaty"),
        .cryId = CRY_FLAAFFY,
        .natDexNum = NATIONAL_DEX_FLAAFFY,
        .categoryName = _("Wolle"),
        .height = 8,
        .weight = 133,
        .description = POKEDEX_DESC_STRING(
            "Sein flauschiges Fell speichert\n"
            "Elektrizität. Seine Gummihaut\n"
            "schützt es vor Stromstößen."),
        .pokemonScale = 372,
        .pokemonOffset = 15,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Flaaffy, 48, 48),
        .frontPicYOffset = 9,
        .frontAnimFrames = sAnims_Flaaffy,
        .frontAnimId = ANIM_V_STRETCH,
        BACK_PIC(Flaaffy, 48, 56),
        .backPicYOffset = 7,
        .backAnimId = BACK_ANIM_DIP_RIGHT_SIDE,
        PALETTES(Flaaffy),
        ICON(Flaaffy, 0),
        .footprint = gMonFootprint_Flaaffy,
        LEARNSETS(Flaaffy),
        .evolutions = EVOLUTION({EVO_LEVEL, 30, SPECIES_AMPHAROS}),
    },

#define AMPHAROS_MISC_INFO                                  \
        .catchRate = 45,                                    \
        .evYield_SpAttack = 3,                              \
        .genderRatio = PERCENT_FEMALE(50),                  \
        .eggCycles = 20,                                    \
        .friendship = STANDARD_FRIENDSHIP,                  \
        .growthRate = GROWTH_MEDIUM_SLOW,                   \
        .eggGroups = { EGG_GROUP_MONSTER, EGG_GROUP_FIELD },\
        .bodyColor = BODY_COLOR_YELLOW,                     \
        .speciesName = _("Waaty"),                       \
        .natDexNum = NATIONAL_DEX_AMPHAROS,                 \
        .categoryName = _("Wolle"),                         \
        .height = 14,                                       \
        .weight = 615,                                      \
        .pokemonScale = 256,                                \
        .pokemonOffset = 4,                                 \
        .trainerScale = 256,                                \
        .trainerOffset = 0,                                 \
        .footprint = gMonFootprint_Ampharos,                \
        LEARNSETS(Ampharos),                                \
        .formSpeciesIdTable = sAmpharosFormSpeciesIdTable,  \
        .formChangeTable = sAmpharosFormChangeTable

#define AMPHAROS_DEFENSE (P_UPDATED_STATS >= GEN_6 ? 85 : 75)

    [SPECIES_AMPHAROS] =
    {
        AMPHAROS_MISC_INFO,
        .baseHP        = 90,
        .baseAttack    = 75,
        .baseDefense   = AMPHAROS_DEFENSE,
        .baseSpeed     = 55,
        .baseSpAttack  = 115,
        .baseSpDefense = 90,
        .types = { TYPE_ELECTRIC, TYPE_ELECTRIC },
        .expYield = 230,
        .abilities = { ABILITY_STATIC, ABILITY_NONE, ABILITY_PLUS },
        .cryId = CRY_AMPHAROS,
        .description = POKEDEX_DESC_STRING(
            "Seine Schweifspitze ist so hell,\n"
            "dass viele Verschollene es als\n"
            "Orientierungspunkt nutzen."),
        FRONT_PIC(Ampharos, 56, 64),
        .frontPicYOffset = 2,
        .frontAnimFrames = sAnims_Ampharos,
        .frontAnimId = ANIM_FLASH_YELLOW,
        .frontAnimDelay = 10,
        BACK_PIC(Ampharos, 56, 64),
        .backPicYOffset = 3,
        .backAnimId = BACK_ANIM_SHAKE_FLASH_YELLOW,
        PALETTES(Ampharos),
        ICON(Ampharos, 0),
    },

#if P_MEGA_EVOLUTIONS
    [SPECIES_AMPHAROS_MEGA] =
    {
        AMPHAROS_MISC_INFO,
        .baseHP        = 90,
        .baseAttack    = 95,
        .baseDefense   = AMPHAROS_DEFENSE + 20,
        .baseSpeed     = 45,
        .baseSpAttack  = 165,
        .baseSpDefense = 110,
        .types = { TYPE_ELECTRIC, TYPE_DRAGON },
        .expYield = 275,
        .abilities = { ABILITY_MOLD_BREAKER, ABILITY_MOLD_BREAKER, ABILITY_MOLD_BREAKER },
        .cryId = CRY_AMPHAROS_MEGA,
        .description = POKEDEX_DESC_STRING(
            "Seine Schweifspitze ist so hell,\n"
            "dass viele Verschollene es als\n"
            "Orientierungspunkt nutzen."),
        FRONT_PIC(AmpharosMega, 64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_AmpharosMega,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(AmpharosMega, 64, 64),
        .backPicYOffset = 0,
        .backAnimId = BACK_ANIM_SHAKE_FLASH_YELLOW,
        PALETTES(AmpharosMega),
        ICON(AmpharosMega, 0),
        .isMegaEvolution = TRUE,
    },

    [SPECIES_PIKIN_MEGA] =
    {
        .catchRate = 45,
        .evYield_SpAttack = 3,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_MONSTER, EGG_GROUP_FIELD },
        .bodyColor = BODY_COLOR_YELLOW,
        .speciesName = _("Voltilamm"),
        .natDexNum = NATIONAL_DEX_MAREEP,
        .categoryName = _("Wolle"),
        .height = 14,
        .weight = 615,
        .pokemonScale = 256,
        .pokemonOffset = 4,
        .trainerScale = 256,
        .trainerOffset = 0,
        .footprint = gMonFootprint_Mareep,
        LEARNSETS(Mareep),
        .formSpeciesIdTable = sMareepFormSpeciesIdTable,
        .formChangeTable = sMareepFormChangeTable,
        .baseHP        = 90,
        .baseAttack    = 95,
        .baseDefense   = AMPHAROS_DEFENSE + 20,
        .baseSpeed     = 45,
        .baseSpAttack  = 165,
        .baseSpDefense = 110,
        .types = { TYPE_ELECTRIC, TYPE_FLYING },
        .expYield = 275,
        .abilities = { ABILITY_DRIZZLE, ABILITY_DRIZZLE, ABILITY_DRIZZLE },
        .cryId = CRY_MAREEP,
        .description = POKEDEX_DESC_STRING(
            "Sein weiches Fell wird doppelt so dick,\n"
            "wenn sich Elektrizität aufbaut."),
        FRONT_PIC(PikinMega, 64, 64),
        .frontPicYOffset = 16,
        .enemyMonElevation = 16,
        //.frontAnimFrames = sAnims_PikinMega,
        .frontAnimFrames = sAnims_Mareep,
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .frontAnimDelay = 50,
        BACK_PIC(PikinMega, 64, 64),
        .backPicYOffset = 15,
        .backAnimId = BACK_ANIM_CONCAVE_ARC_SMALL,
        PALETTES(PikinMega),
        ICON(PikinMega, 0),
        .isMegaEvolution = TRUE,
    },
#endif //P_MEGA_EVOLUTIONS
#endif //P_FAMILY_MAREEP

#if P_FAMILY_MARILL
#if P_GEN_3_CROSS_EVOS
    [SPECIES_AZURILL] =
    {
        .baseHP        = 50,
        .baseAttack    = 20,
        .baseDefense   = 40,
        .baseSpeed     = 20,
        .baseSpAttack  = 20,
        .baseSpDefense = 40,
    #if P_UPDATED_TYPES >= GEN_6
        .types = { TYPE_NORMAL, TYPE_FAIRY },
    #else
        .types = { TYPE_NORMAL, TYPE_NORMAL },
    #endif
        .catchRate = 150,
        .expYield = 38,
        .evYield_HP = 1,
        .genderRatio = PERCENT_FEMALE(75),
        .eggCycles = 10,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_FAST,
        .eggGroups = { EGG_GROUP_NO_EGGS_DISCOVERED, EGG_GROUP_NO_EGGS_DISCOVERED },
        .abilities = { ABILITY_THICK_FAT, ABILITY_HUGE_POWER, ABILITY_SAP_SIPPER },
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Azurill"),
        .cryId = CRY_AZURILL,
        .natDexNum = NATIONAL_DEX_AZURILL,
        .categoryName = _("Gepunktet"),
        .height = 2,
        .weight = 20,
        .description = POKEDEX_DESC_STRING(
            "Dieses Pokémon lebt am Wasser. An\n"
            "Land bewegt es sich schnell, indem\n"
            "es auf seinem großen Schweif hüpft."),
        .pokemonScale = 603,
        .pokemonOffset = 23,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Azurill, 48, 48),
        .frontPicYOffset = 11,
        .frontAnimFrames = sAnims_Azurill,
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(Azurill, 64, 56),
        .backPicYOffset = 6,
        .backAnimId = BACK_ANIM_CONCAVE_ARC_LARGE,
        PALETTES(Azurill),
        ICON(Azurill, 0),
        .footprint = gMonFootprint_Azurill,
        LEARNSETS(Azurill),
        .evolutions = EVOLUTION({EVO_FRIENDSHIP, 0, SPECIES_MARILL}),
    },
#endif //P_GEN_3_CROSS_EVOS

    [SPECIES_MARILL] =
    {
        .baseHP        = 70,
        .baseAttack    = 20,
        .baseDefense   = 50,
        .baseSpeed     = 40,
        .baseSpAttack  = 20,
        .baseSpDefense = 50,
    #if P_UPDATED_TYPES >= GEN_6
        .types = { TYPE_WATER, TYPE_FAIRY },
    #else
        .types = { TYPE_WATER, TYPE_WATER },
    #endif
        .catchRate = 190,
        .expYield = 88,
        .evYield_HP = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 10,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_FAST,
        .eggGroups = { EGG_GROUP_WATER_1, EGG_GROUP_FAIRY },
        .abilities = { ABILITY_THICK_FAT, ABILITY_HUGE_POWER, ABILITY_SAP_SIPPER },
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Marill"),
        .cryId = CRY_MARILL,
        .natDexNum = NATIONAL_DEX_MARILL,
        .categoryName = _("Aquamaus"),
        .height = 4,
        .weight = 85,
        .description = POKEDEX_DESC_STRING(
            "Seine Schweifspitze ist mit Öl gefüllt,\n"
            "das leichter als Wasser ist, sodass es\n"
            "nicht untergeht."),
        .pokemonScale = 476,
        .pokemonOffset = 20,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Marill, 56, 40),
        .frontPicYOffset = 14,
        .frontAnimFrames = sAnims_Marill,
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(Marill, 64, 40),
        .backPicYOffset = 13,
        .backAnimId = BACK_ANIM_CONCAVE_ARC_SMALL,
        PALETTES(Marill),
        ICON(Marill, 0),
        .footprint = gMonFootprint_Marill,
        LEARNSETS(Marill),
        .evolutions = EVOLUTION({EVO_LEVEL, 18, SPECIES_AZUMARILL}),
    },

    [SPECIES_AZUMARILL] =
    {
        .baseHP        = 100,
        .baseAttack    = 50,
        .baseDefense   = 80,
        .baseSpeed     = 50,
        .baseSpAttack  = P_UPDATED_STATS >= GEN_6 ? 60 : 50,
        .baseSpDefense = 80,
    #if P_UPDATED_TYPES >= GEN_6
        .types = { TYPE_WATER, TYPE_FAIRY },
    #else
        .types = { TYPE_WATER, TYPE_WATER },
    #endif
        .catchRate = 75,
        .expYield = 189,
        .evYield_HP = 3,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 10,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_FAST,
        .eggGroups = { EGG_GROUP_WATER_1, EGG_GROUP_FAIRY },
        .abilities = { ABILITY_THICK_FAT, ABILITY_HUGE_POWER, ABILITY_SAP_SIPPER },
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Azumarill"),
        .cryId = CRY_AZUMARILL,
        .natDexNum = NATIONAL_DEX_AZUMARILL,
        .categoryName = _("Aquahasen"),
        .height = 8,
        .weight = 285,
        .description = POKEDEX_DESC_STRING(
            "Seine langen Ohren sind\n"
            "hervorragende Sensoren. Mit ihnen\n"
            "kann es Bewegungen im Fluss\n"
            "wahrnehmen."),
        .pokemonScale = 448,
        .pokemonOffset = 16,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Azumarill, 56, 64),
        .frontPicYOffset = 6,
        .frontAnimFrames = sAnims_Azumarill,
        .frontAnimId = ANIM_SHRINK_GROW,
        BACK_PIC(Azumarill, 64, 64),
        .backPicYOffset = 3,
        .backAnimId = BACK_ANIM_DIP_RIGHT_SIDE,
        PALETTES(Azumarill),
        ICON(Azumarill, 0),
        .footprint = gMonFootprint_Azumarill,
        LEARNSETS(Azumarill),
    },
#endif //P_FAMILY_MARILL

#if P_FAMILY_SUDOWOODO
#if P_GEN_4_CROSS_EVOS
    [SPECIES_BONSLY] =
    {
        .baseHP        = 50,
        .baseAttack    = 80,
        .baseDefense   = 95,
        .baseSpeed     = 10,
        .baseSpAttack  = 10,
        .baseSpDefense = 45,
        .types = { TYPE_ROCK, TYPE_ROCK },
        .catchRate = 255,
        .expYield = 58,
        .evYield_Defense = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_NO_EGGS_DISCOVERED, EGG_GROUP_NO_EGGS_DISCOVERED },
        .abilities = { ABILITY_STURDY, ABILITY_ROCK_HEAD, ABILITY_RATTLED },
        .bodyColor = BODY_COLOR_BROWN,
        .speciesName = _("Mobai"),
        .cryId = CRY_BONSLY,
        .natDexNum = NATIONAL_DEX_BONSLY,
        .categoryName = _("Bonsai"),
        .height = 5,
        .weight = 150,
        .description = POKEDEX_DESC_STRING(
            "Es bevorzugt trockene Gebiete. Es\n"
            "gibt über die Augen Wasser ab, um\n"
            "den Wasserhaushalt zu regulieren."),
        .pokemonScale = 432,
        .pokemonOffset = 13,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Bonsly, 32, 48),
        .frontPicYOffset = 9,
        .frontAnimFrames = sAnims_Bonsly,
        .frontAnimId = ANIM_BOUNCE_ROTATE_TO_SIDES,
        BACK_PIC(Bonsly, 40, 64),
        .backPicYOffset = 6,
        .backAnimId = BACK_ANIM_H_VIBRATE,
        PALETTES(Bonsly),
        ICON(Bonsly, 1),
        .footprint = gMonFootprint_Bonsly,
        LEARNSETS(Bonsly),
        .evolutions = EVOLUTION({EVO_MOVE, MOVE_MIMIC, SPECIES_SUDOWOODO}),
    },
#endif //P_GEN_4_CROSS_EVOS

    [SPECIES_SUDOWOODO] =
    {
        .baseHP        = 70,
        .baseAttack    = 100,
        .baseDefense   = 115,
        .baseSpeed     = 30,
        .baseSpAttack  = 30,
        .baseSpDefense = 65,
        .types = { TYPE_ROCK, TYPE_ROCK },
        .catchRate = 65,
        .expYield = 144,
        .evYield_Defense = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_MINERAL, EGG_GROUP_MINERAL },
        .abilities = { ABILITY_STURDY, ABILITY_ROCK_HEAD, ABILITY_RATTLED },
        .bodyColor = BODY_COLOR_BROWN,
        .speciesName = _("Mogelbaum"),
        .cryId = CRY_SUDOWOODO,
        .natDexNum = NATIONAL_DEX_SUDOWOODO,
        .categoryName = _("Imitations"),
        .height = 12,
        .weight = 380,
        .description = POKEDEX_DESC_STRING(
            "Es tarnt sich als Baum, um nicht\n"
            "angegriffen zu werden. Es hasst Wasser,\n"
            "darum läuft es bei Regen weg."),
        .pokemonScale = 305,
        .pokemonOffset = 8,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Sudowoodo, 48, 56),
        FRONT_PIC_FEMALE(Sudowoodo, 48, 56),
        .frontPicYOffset = 7,
        .frontAnimFrames = sAnims_Sudowoodo,
        .frontAnimId = ANIM_H_SLIDE_SLOW,
        BACK_PIC(Sudowoodo, 48, 56),
        BACK_PIC_FEMALE(Sudowoodo, 48, 56),
        .backPicYOffset = 5,
        .backAnimId = BACK_ANIM_H_SLIDE,
        PALETTES(Sudowoodo),
        ICON(Sudowoodo, 1),
        .footprint = gMonFootprint_Sudowoodo,
        LEARNSETS(Sudowoodo),
    },
#endif //P_FAMILY_SUDOWOODO

#if P_FAMILY_HOPPIP
    [SPECIES_HOPPIP] =
    {
        .baseHP        = 35,
        .baseAttack    = 35,
        .baseDefense   = 40,
        .baseSpeed     = 50,
        .baseSpAttack  = 35,
        .baseSpDefense = 55,
        .types = { TYPE_GRASS, TYPE_FLYING },
        .catchRate = 255,
        .expYield = 50,
        .evYield_SpDefense = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_FAIRY, EGG_GROUP_GRASS },
        .abilities = { ABILITY_CHLOROPHYLL, ABILITY_LEAF_GUARD, ABILITY_INFILTRATOR },
        .bodyColor = BODY_COLOR_PINK,
        .speciesName = _("Hoppspross"),
        .cryId = CRY_HOPPIP,
        .natDexNum = NATIONAL_DEX_HOPPIP,
        .categoryName = _("Löwenzahn"),
        .height = 4,
        .weight = 5,
        .description = POKEDEX_DESC_STRING(
            "Es reitet auf dem Wind. Man sagt, wenn\n"
            "sich Hoppspross versammeln, kommt der\n"
            "Frühling bald."),
        .pokemonScale = 562,
        .pokemonOffset = -7,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Hoppip, 64, 56),
        .frontPicYOffset = 14,
        .frontAnimFrames = sAnims_Hoppip,
        .frontAnimId = ANIM_V_SLIDE_WOBBLE,
        .enemyMonElevation = 15,
        BACK_PIC(Hoppip, 64, 48),
        .backPicYOffset = 8,
        .backAnimId = BACK_ANIM_CONVEX_DOUBLE_ARC,
        PALETTES(Hoppip),
        ICON(Hoppip, 1),
        .footprint = gMonFootprint_Hoppip,
        LEARNSETS(Hoppip),
        .evolutions = EVOLUTION({EVO_LEVEL, 18, SPECIES_SKIPLOOM}),
    },

    [SPECIES_SKIPLOOM] =
    {
        .baseHP        = 55,
        .baseAttack    = 45,
        .baseDefense   = 50,
        .baseSpeed     = 80,
        .baseSpAttack  = 45,
        .baseSpDefense = 65,
        .types = { TYPE_GRASS, TYPE_FLYING },
        .catchRate = 120,
        .expYield = 119,
        .evYield_Speed = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_FAIRY, EGG_GROUP_GRASS },
        .abilities = { ABILITY_CHLOROPHYLL, ABILITY_LEAF_GUARD, ABILITY_INFILTRATOR },
        .bodyColor = BODY_COLOR_GREEN,
        .speciesName = _("Hubelupf"),
        .cryId = CRY_SKIPLOOM,
        .natDexNum = NATIONAL_DEX_SKIPLOOM,
        .categoryName = _("Löwenzahn"),
        .height = 6,
        .weight = 10,
        .description = POKEDEX_DESC_STRING(
            "Es öffnet seine Blüte, um Sonnenlicht\n"
            "aufzunehmen. Es schwebt in der Luft, um\n"
            "der Sonne näher zu sein."),
        .pokemonScale = 387,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Skiploom, 40, 40),
        .frontPicYOffset = 15,
        .frontAnimFrames = sAnims_Skiploom,
        .frontAnimId = ANIM_RISING_WOBBLE,
        .enemyMonElevation = 15,
        BACK_PIC(Skiploom, 64, 56),
        .backPicYOffset = 4,
        .backAnimId = BACK_ANIM_CONVEX_DOUBLE_ARC,
        PALETTES(Skiploom),
        ICON(Skiploom, 1),
        .footprint = gMonFootprint_Skiploom,
        LEARNSETS(Skiploom),
        .evolutions = EVOLUTION({EVO_LEVEL, 27, SPECIES_JUMPLUFF}),
    },

    [SPECIES_JUMPLUFF] =
    {
        .baseHP        = 75,
        .baseAttack    = 55,
        .baseDefense   = 70,
        .baseSpeed     = 110,
        .baseSpAttack  = 55,
        .baseSpDefense = P_UPDATED_STATS >= GEN_6 ? 95 : 85,
        .types = { TYPE_GRASS, TYPE_FLYING },
        .catchRate = 45,
        .expYield = 207,
        .evYield_Speed = 3,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_FAIRY, EGG_GROUP_GRASS },
        .abilities = { ABILITY_CHLOROPHYLL, ABILITY_LEAF_GUARD, ABILITY_INFILTRATOR },
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Papungha"),
        .cryId = CRY_JUMPLUFF,
        .natDexNum = NATIONAL_DEX_JUMPLUFF,
        .categoryName = _("Löwenzahn"),
        .height = 8,
        .weight = 30,
        .description = POKEDEX_DESC_STRING(
            "Die Baumwollsamen, die Papungha verstreut,\n"
            "machen Allergikern das Leben schwer."),
        .pokemonScale = 418,
        .pokemonOffset = -4,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Jumpluff, 64, 56),
        .frontPicYOffset = 9,
        .frontAnimFrames = sAnims_Jumpluff,
        .frontAnimId = ANIM_V_SLIDE_WOBBLE_SMALL,
        .enemyMonElevation = 9,
        BACK_PIC(Jumpluff, 56, 64),
        .backPicYOffset = 3,
        .backAnimId = BACK_ANIM_CONVEX_DOUBLE_ARC,
        PALETTES(Jumpluff),
        ICON(Jumpluff, 2),
        .footprint = gMonFootprint_Jumpluff,
        LEARNSETS(Jumpluff),
    },
#endif //P_FAMILY_HOPPIP

#if P_FAMILY_AIPOM
    [SPECIES_AIPOM] =
    {
        .baseHP        = 55,
        .baseAttack    = 70,
        .baseDefense   = 55,
        .baseSpeed     = 85,
        .baseSpAttack  = 40,
        .baseSpDefense = 55,
        .types = { TYPE_NORMAL, TYPE_NORMAL },
        .catchRate = 45,
        .expYield = 72,
        .evYield_Speed = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_FAST,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD },
        .abilities = { ABILITY_RUN_AWAY, ABILITY_PICKUP, ABILITY_SKILL_LINK },
        .bodyColor = BODY_COLOR_PURPLE,
        .speciesName = _("Griffel"),
        .cryId = CRY_AIPOM,
        .natDexNum = NATIONAL_DEX_AIPOM,
        .categoryName = _("Langschweif"),
        .height = 8,
        .weight = 115,
        .description = POKEDEX_DESC_STRING(
            "Es lebt in den Kronen großer Bäume.\n"
            "Es hüpft von Ast zu Ast und\n"
            "balanciert mit seinem Schweif."),
        .pokemonScale = 363,
        .pokemonOffset = 6,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Aipom, 32, 64),
        FRONT_PIC_FEMALE(Aipom, 32, 64),
        .frontPicYOffset = 1,
        .frontAnimFrames = sAnims_Aipom,
        .frontAnimId = ANIM_H_JUMPS_V_STRETCH,
        BACK_PIC(Aipom, 64, 64),
        BACK_PIC_FEMALE(Aipom, 64, 64),
        .backPicYOffset = 3,
        .backAnimId = BACK_ANIM_CONCAVE_ARC_LARGE,
        PALETTES(Aipom),
        ICON(Aipom, 2),
        .footprint = gMonFootprint_Aipom,
        LEARNSETS(Aipom),
        .evolutions = EVOLUTION({EVO_MOVE, MOVE_DOUBLE_HIT, SPECIES_AMBIPOM}),
    },

#if P_GEN_4_CROSS_EVOS
    [SPECIES_AMBIPOM] =
    {
        .baseHP        = 75,
        .baseAttack    = 100,
        .baseDefense   = 66,
        .baseSpeed     = 115,
        .baseSpAttack  = 60,
        .baseSpDefense = 66,
        .types = { TYPE_NORMAL, TYPE_NORMAL },
        .catchRate = 45,
        .expYield = 169,
        .evYield_Speed = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = 100,
        .growthRate = GROWTH_FAST,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD },
        .abilities = { ABILITY_TECHNICIAN, ABILITY_PICKUP, ABILITY_SKILL_LINK },
        .bodyColor = BODY_COLOR_PURPLE,
        .speciesName = _("Ambidiffel"),
        .cryId = CRY_AMBIPOM,
        .natDexNum = NATIONAL_DEX_AMBIPOM,
        .categoryName = _("Langschweif"),
        .height = 12,
        .weight = 203,
        .description = POKEDEX_DESC_STRING(
            "Sie leben in großen Kolonien und\n"
            "verbinden ihre Schweife in\n"
            "Freundschaft."),
        .pokemonScale = 282,
        .pokemonOffset = 3,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Ambipom, 64, 64),
        FRONT_PIC_FEMALE(Ambipom, 64, 64),
        .frontPicYOffset = 1,
        .frontAnimFrames = sAnims_Ambipom,
        .frontAnimId = ANIM_BACK_AND_LUNGE,
        BACK_PIC(Ambipom, 64, 64),
        BACK_PIC_FEMALE(Ambipom, 64, 64),
        .backPicYOffset = 3,
        .backAnimId = BACK_ANIM_CONCAVE_ARC_LARGE,
        PALETTES(Ambipom),
        ICON(Ambipom, 2),
        .footprint = gMonFootprint_Ambipom,
        LEARNSETS(Ambipom),
    },
#endif //P_GEN_4_CROSS_EVOS
#endif //P_FAMILY_AIPOM

#if P_FAMILY_SUNKERN
    [SPECIES_SUNKERN] =
    {
        .baseHP        = 30,
        .baseAttack    = 30,
        .baseDefense   = 30,
        .baseSpeed     = 30,
        .baseSpAttack  = 30,
        .baseSpDefense = 30,
        .types = { TYPE_GRASS, TYPE_GRASS },
        .catchRate = 235,
        .expYield = 36,
        .evYield_SpAttack = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_GRASS, EGG_GROUP_GRASS },
        .abilities = { ABILITY_CHLOROPHYLL, ABILITY_SOLAR_POWER, ABILITY_EARLY_BIRD },
        .bodyColor = BODY_COLOR_YELLOW,
        .speciesName = _("Sonnkern"),
        .cryId = CRY_SUNKERN,
        .natDexNum = NATIONAL_DEX_SUNKERN,
        .categoryName = _("Samen"),
        .height = 3,
        .weight = 18,
        .description = POKEDEX_DESC_STRING(
            "Es ernährt sich ausschließlich von den\n"
            "Tautropfen, die von den Blättern über ihm\n"
            "hinabfallen."),
        .pokemonScale = 541,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Sunkern, 32, 40),
        .frontPicYOffset = 17,
        .frontAnimFrames = sAnims_Sunkern,
        .frontAnimId = ANIM_H_JUMPS,
        BACK_PIC(Sunkern, 48, 48),
        .backPicYOffset = 10,
        .backAnimId = BACK_ANIM_DIP_RIGHT_SIDE,
        PALETTES(Sunkern),
        ICON(Sunkern, 1),
        .footprint = gMonFootprint_Sunkern,
        LEARNSETS(Sunkern),
        .evolutions = EVOLUTION({EVO_ITEM, ITEM_SUN_STONE, SPECIES_SUNFLORA}),
    },

    [SPECIES_SUNFLORA] =
    {
        .baseHP        = 75,
        .baseAttack    = 75,
        .baseDefense   = 55,
        .baseSpeed     = 30,
        .baseSpAttack  = 105,
        .baseSpDefense = 85,
        .types = { TYPE_GRASS, TYPE_GRASS },
        .catchRate = 120,
        .expYield = 149,
        .evYield_SpAttack = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_GRASS, EGG_GROUP_GRASS },
        .abilities = { ABILITY_CHLOROPHYLL, ABILITY_SOLAR_POWER, ABILITY_EARLY_BIRD },
        .bodyColor = BODY_COLOR_YELLOW,
        .speciesName = _("Sonnflora"),
        .cryId = CRY_SUNFLORA,
        .natDexNum = NATIONAL_DEX_SUNFLORA,
        .categoryName = _("Sonne"),
        .height = 8,
        .weight = 85,
        .description = POKEDEX_DESC_STRING(
            "Warmes Sonnenlicht gibt ihm Energie. Daher\n"
            "wandert es stets dem Sonnenlicht\n"
            "hinterher."),
        .pokemonScale = 444,
        .pokemonOffset = 15,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Sunflora, 40, 48),
        .frontPicYOffset = 8,
        .frontAnimFrames = sAnims_Sunflora,
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(Sunflora, 56, 56),
        .backPicYOffset = 7,
        .backAnimId = BACK_ANIM_H_SLIDE,
        PALETTES(Sunflora),
        ICON(Sunflora, 1),
        .footprint = gMonFootprint_Sunflora,
        LEARNSETS(Sunflora),
    },
#endif //P_FAMILY_SUNKERN

#if P_FAMILY_YANMA
    [SPECIES_YANMA] =
    {
        .baseHP        = 65,
        .baseAttack    = 65,
        .baseDefense   = 45,
        .baseSpeed     = 95,
        .baseSpAttack  = 75,
        .baseSpDefense = 45,
        .types = { TYPE_BUG, TYPE_FLYING },
        .catchRate = 75,
        .expYield = 78,
        .evYield_Speed = 1,
        .itemRare = ITEM_WIDE_LENS,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_BUG, EGG_GROUP_BUG },
        .abilities = { ABILITY_SPEED_BOOST, ABILITY_COMPOUND_EYES, ABILITY_FRISK },
        .bodyColor = BODY_COLOR_RED,
        .speciesName = _("Yanma"),
        .cryId = CRY_YANMA,
        .natDexNum = NATIONAL_DEX_YANMA,
        .categoryName = _("Libelle"),
        .height = 12,
        .weight = 380,
        .description = POKEDEX_DESC_STRING(
            "Schlägt es schnell mit den Flügeln,\n"
            "erzeugt es Schockwellen, durch die sogar\n"
            "Fenster zerbersten."),
        .pokemonScale = 274,
        .pokemonOffset = -1,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Yanma, 64, 40),
        .frontPicYOffset = 14,
        .frontAnimFrames = sAnims_Yanma,
        .frontAnimId = ANIM_FIGURE_8,
        .enemyMonElevation = 13,
        BACK_PIC(Yanma, 64, 64),
        .backPicYOffset = 0,
        .backAnimId = BACK_ANIM_CONVEX_DOUBLE_ARC,
        PALETTES(Yanma),
        ICON(Yanma, 1),
        .footprint = gMonFootprint_Yanma,
        LEARNSETS(Yanma),
        .evolutions = EVOLUTION({EVO_MOVE, MOVE_ANCIENT_POWER, SPECIES_YANMEGA}),
    },

#if P_GEN_4_CROSS_EVOS
    [SPECIES_YANMEGA] =
    {
        .baseHP        = 86,
        .baseAttack    = 76,
        .baseDefense   = 86,
        .baseSpeed     = 95,
        .baseSpAttack  = 116,
        .baseSpDefense = 56,
        .types = { TYPE_BUG, TYPE_FLYING },
        .catchRate = 30,
        .expYield = 180,
        .evYield_Attack = 2,
        .itemRare = ITEM_WIDE_LENS,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_BUG, EGG_GROUP_BUG },
        .abilities = { ABILITY_SPEED_BOOST, ABILITY_TINTED_LENS, ABILITY_FRISK },
        .bodyColor = BODY_COLOR_GREEN,
        .speciesName = _("Yanmega"),
        .cryId = CRY_YANMEGA,
        .natDexNum = NATIONAL_DEX_YANMEGA,
        .categoryName = _("Agrion"),
        .height = 19,
        .weight = 515,
        .description = POKEDEX_DESC_STRING(
            "Es kann mühelos einen Erwachsenen\n"
            "umhertragen. Die Federn an seinem\n"
            "Hinterteil stabilisieren seinen Flug."),
        .pokemonScale = 256,
        .pokemonOffset = 1,
        .trainerScale = 326,
        .trainerOffset = 4,
        FRONT_PIC(Yanmega, 64, 56),
        .frontPicYOffset = 5,
        .frontAnimFrames = sAnims_Yanmega,
        .frontAnimId = ANIM_H_VIBRATE,
        .enemyMonElevation = 6,
        BACK_PIC(Yanmega, 64, 56),
        .backPicYOffset = 6,
        .backAnimId = BACK_ANIM_H_VIBRATE,
        PALETTES(Yanmega),
        ICON(Yanmega, 1),
        .footprint = gMonFootprint_Yanmega,
        LEARNSETS(Yanmega),
    },
#endif //P_GEN_4_CROSS_EVOS
#endif //P_FAMILY_YANMA

#if P_FAMILY_WOOPER
#define WOOPER_MISC_INFO                                                        \
        .baseHP        = 55,                                                    \
        .baseAttack    = 45,                                                    \
        .baseDefense   = 45,                                                    \
        .baseSpeed     = 15,                                                    \
        .baseSpAttack  = 25,                                                    \
        .baseSpDefense = 25,                                                    \
        .catchRate = 255,                                                       \
        .expYield = 42,                                                         \
        .evYield_HP = 1,                                                        \
        .genderRatio = PERCENT_FEMALE(50),                                      \
        .eggCycles = 20,                                                        \
        .friendship = STANDARD_FRIENDSHIP,                                      \
        .growthRate = GROWTH_MEDIUM_FAST,                                       \
        .eggGroups = { EGG_GROUP_WATER_1, EGG_GROUP_FIELD },                    \
        .speciesName = _("Yanmega"),                                             \
        .cryId = CRY_WOOPER,                                                    \
        .natDexNum = NATIONAL_DEX_WOOPER,                                       \
        .height = 4,                                                            \
        .pokemonScale = 479,                                                    \
        .pokemonOffset = 21,                                                    \
        .trainerScale = 256,                                                    \
        .trainerOffset = 0,                                                     \
        .footprint = gMonFootprint_Wooper,                                      \
        .formSpeciesIdTable = sWooperFormSpeciesIdTable

    [SPECIES_WOOPER] =
    {
        WOOPER_MISC_INFO,
        .types = { TYPE_WATER, TYPE_GROUND },
        .abilities = { ABILITY_DAMP, ABILITY_WATER_ABSORB, ABILITY_UNAWARE },
        .bodyColor = BODY_COLOR_BLUE,
        .categoryName = _("Fisch"),
        .weight = 85,
        .description = POKEDEX_DESC_STRING(
            "Wenn es am Abend kühler wird, kommen sie\n"
            "an Land, um nach Nahrung zu suchen."),
        FRONT_PIC(Wooper, 40, 32),
        FRONT_PIC_FEMALE(Wooper, 40, 32),
        .frontPicYOffset = 16,
        .frontAnimFrames = sAnims_Wooper,
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(Wooper, 64, 40),
        BACK_PIC_FEMALE(Wooper, 64, 40),
        .backPicYOffset = 12,
        .backAnimId = BACK_ANIM_V_STRETCH,
        PALETTES(Wooper),
        ICON(Wooper, 0),
        LEARNSETS(Wooper),
        .evolutions = EVOLUTION({EVO_LEVEL, 20, SPECIES_QUAGSIRE}),
    },

    [SPECIES_QUAGSIRE] =
    {
        .baseHP        = 95,
        .baseAttack    = 85,
        .baseDefense   = 85,
        .baseSpeed     = 35,
        .baseSpAttack  = 65,
        .baseSpDefense = 65,
        .types = { TYPE_WATER, TYPE_GROUND },
        .catchRate = 90,
        .expYield = 151,
        .evYield_HP = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_WATER_1, EGG_GROUP_FIELD },
        .abilities = { ABILITY_DAMP, ABILITY_WATER_ABSORB, ABILITY_UNAWARE },
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Morlord"),
        .cryId = CRY_QUAGSIRE,
        .natDexNum = NATIONAL_DEX_QUAGSIRE,
        .categoryName = _("Fisch"),
        .height = 14,
        .weight = 750,
        .description = POKEDEX_DESC_STRING(
            "Es ist sehr unbekümmert und stört sich\n"
            "nicht daran, wenn es während des\n"
            "Schwimmens an Boote oder Felsen stößt."),
        .pokemonScale = 256,
        .pokemonOffset = 4,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Quagsire, 64, 56),
        FRONT_PIC_FEMALE(Quagsire, 64, 56),
        .frontPicYOffset = 5,
        .frontAnimFrames = sAnims_Quagsire,
        .frontAnimId = ANIM_H_STRETCH,
        BACK_PIC(Quagsire, 64, 56),
        BACK_PIC_FEMALE(Quagsire, 64, 56),
        .backPicYOffset = 5,
        .backAnimId = BACK_ANIM_H_SLIDE,
        PALETTES(Quagsire),
        ICON(Quagsire, 0),
        .footprint = gMonFootprint_Quagsire,
        LEARNSETS(Quagsire),
    },

#if P_PALDEAN_FORMS
    [SPECIES_WOOPER_PALDEAN] =
    {
        WOOPER_MISC_INFO,
        .types = { TYPE_POISON, TYPE_GROUND },
        .abilities = { ABILITY_POISON_POINT, ABILITY_WATER_ABSORB, ABILITY_UNAWARE },
        .bodyColor = BODY_COLOR_BROWN,
        .isPaldeanForm = TRUE,
        .categoryName = _("Fisch"),
        .weight = 110,
        .description = POKEDEX_DESC_STRING(
            "Dieses Pokémon lebt in Eiswasser.\n"
            "Wird es an Land kalt, verlässt es\n"
            "das Wasser und sucht nach Futter."),
        FRONT_PIC(WooperPaldean, 40, 32),
        .frontPicYOffset = 16,
        .frontAnimFrames = sAnims_WooperPaldean,
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(WooperPaldean, 64, 40),
        .backPicYOffset = 12,
        .backAnimId = BACK_ANIM_V_STRETCH,
        PALETTES(WooperPaldean),
        ICON(WooperPaldean, 0),
        LEARNSETS(WooperPaldean),
        .evolutions = EVOLUTION({EVO_LEVEL, 20, SPECIES_CLODSIRE}),
    },

    [SPECIES_CLODSIRE] =
    {
        .baseHP        = 130,
        .baseAttack    = 75,
        .baseDefense   = 60,
        .baseSpeed     = 20,
        .baseSpAttack  = 45,
        .baseSpDefense = 100,
        .types = { TYPE_POISON, TYPE_GROUND },
        .catchRate = 90,
        .expYield = 151,
        .evYield_HP = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_WATER_1, EGG_GROUP_FIELD },
        .abilities = { ABILITY_POISON_POINT, ABILITY_WATER_ABSORB, ABILITY_UNAWARE },
        .bodyColor = BODY_COLOR_BROWN,
        .speciesName = _("Suelord"),
        .cryId = CRY_CLODSIRE,
        .natDexNum = NATIONAL_DEX_CLODSIRE,
        .categoryName = _("Dornfisch"),
        .height = 18,
        .weight = 2230,
        .description = POKEDEX_DESC_STRING(
            "Wenn dieses Pokémon angegriffen wird,\n"
            "revanchiert es sich, indem es dicke\n"
            "Stacheln aus seinem Körper streckt. Es ist\n"
            "ein riskanter Schritt"),
        .pokemonScale = 356,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Clodsire, 64, 64),
        .frontPicYOffset = 8,
        .frontAnimFrames = sAnims_Clodsire,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(Clodsire, 64, 64),
        .backPicYOffset = 15,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(Clodsire),
        ICON(Clodsire, 0),
        //.footprint = gMonFootprint_Clodsire,
        LEARNSETS(Clodsire),
    },
#endif //P_PALDEAN_FORMS
#endif //P_FAMILY_WOOPER

#if P_FAMILY_MURKROW
    [SPECIES_MURKROW] =
    {
        .baseHP        = 60,
        .baseAttack    = 85,
        .baseDefense   = 42,
        .baseSpeed     = 91,
        .baseSpAttack  = 85,
        .baseSpDefense = 42,
        .types = { TYPE_DARK, TYPE_FLYING },
        .catchRate = 30,
        .expYield = 81,
        .evYield_Speed = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = 35,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_FLYING, EGG_GROUP_FLYING },
        .abilities = { ABILITY_INSOMNIA, ABILITY_SUPER_LUCK, ABILITY_PRANKSTER },
        .bodyColor = BODY_COLOR_BLACK,
        .speciesName = _("Kramurx"),
        .cryId = CRY_MURKROW,
        .natDexNum = NATIONAL_DEX_MURKROW,
        .categoryName = _("Finsternis"),
        .height = 5,
        .weight = 21,
        .description = POKEDEX_DESC_STRING(
            "Es versteckt jeden schimmernden\n"
            "Gegenstand. Kramurx und Mauzi\n"
            "rauben sich gegenseitig die Beute."),
        .pokemonScale = 401,
        .pokemonOffset = -8,
        .trainerScale = 256,
        .trainerOffset = 1,
        FRONT_PIC(Murkrow, 48, 40),
        FRONT_PIC_FEMALE(Murkrow, 48, 40),
        .frontPicYOffset = 15,
        .frontAnimFrames = sAnims_Murkrow,
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .enemyMonElevation = 12,
        BACK_PIC(Murkrow, 40, 56),
        BACK_PIC_FEMALE(Murkrow, 40, 56),
        .backPicYOffset = 10,
        .backAnimId = BACK_ANIM_CONCAVE_ARC_SMALL,
        PALETTES(Murkrow),
        ICON(Murkrow, 2),
        .footprint = gMonFootprint_Murkrow,
        LEARNSETS(Murkrow),
        .evolutions = EVOLUTION({EVO_ITEM, ITEM_DUSK_STONE, SPECIES_HONCHKROW}),
    },

#if P_GEN_4_CROSS_EVOS
    [SPECIES_HONCHKROW] =
    {
        .baseHP        = 100,
        .baseAttack    = 125,
        .baseDefense   = 52,
        .baseSpeed     = 71,
        .baseSpAttack  = 105,
        .baseSpDefense = 52,
        .types = { TYPE_DARK, TYPE_FLYING },
        .catchRate = 30,
        .expYield = 177,
        .evYield_Attack = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = 35,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_FLYING, EGG_GROUP_FLYING },
        .abilities = { ABILITY_INSOMNIA, ABILITY_SUPER_LUCK, ABILITY_MOXIE },
        .bodyColor = BODY_COLOR_BLACK,
        .speciesName = _("Kramshef"),
        .cryId = CRY_HONCHKROW,
        .natDexNum = NATIONAL_DEX_HONCHKROW,
        .categoryName = _("Anführer"),
        .height = 9,
        .weight = 273,
        .description = POKEDEX_DESC_STRING(
            "Ein nachtaktives Pokémon, das sich in\n"
            "Schwärmen mit Kramurx durch die Nacht\n"
            "bewegt."),
        .pokemonScale = 338,
        .pokemonOffset = 8,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Honchkrow, 64, 56),
        .frontPicYOffset = 6,
        .frontAnimFrames = sAnims_Honchkrow,
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE_SLOW,
        BACK_PIC(Honchkrow, 64, 48),
        .backPicYOffset = 8,
        .backAnimId = BACK_ANIM_H_STRETCH,
        PALETTES(Honchkrow),
        ICON(Honchkrow, 2),
        .footprint = gMonFootprint_Honchkrow,
        LEARNSETS(Honchkrow),
    },
#endif //P_GEN_4_CROSS_EVOS
#endif //P_FAMILY_MURKROW

#if P_FAMILY_MISDREAVUS
    [SPECIES_MISDREAVUS] =
    {
        .baseHP        = 60,
        .baseAttack    = 60,
        .baseDefense   = 60,
        .baseSpeed     = 85,
        .baseSpAttack  = 85,
        .baseSpDefense = 85,
        .types = { TYPE_GHOST, TYPE_GHOST },
        .catchRate = 45,
        .expYield = 87,
        .evYield_SpDefense = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 25,
        .friendship = 35,
        .growthRate = GROWTH_FAST,
        .eggGroups = { EGG_GROUP_AMORPHOUS, EGG_GROUP_AMORPHOUS },
        .abilities = { ABILITY_LEVITATE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_GRAY,
        .speciesName = _("Traunfugil"),
        .cryId = CRY_MISDREAVUS,
        .natDexNum = NATIONAL_DEX_MISDREAVUS,
        .categoryName = _("Kreischer"),
        .height = 7,
        .weight = 10,
        .description = POKEDEX_DESC_STRING(
            "Es liebt Streiche und erschreckt nachts\n"
            "Menschen, indem es heult oder ihnen im\n"
            "Dunkeln auflauert."),
        .pokemonScale = 407,
        .pokemonOffset = -8,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Misdreavus, 48, 48),
        .frontPicYOffset = 13,
        .frontAnimFrames = sAnims_Misdreavus,
        .frontAnimId = ANIM_V_SLIDE_WOBBLE,
        .enemyMonElevation = 12,
        BACK_PIC(Misdreavus, 56, 48),
        .backPicYOffset = 9,
        .backAnimId = BACK_ANIM_H_VIBRATE,
        PALETTES(Misdreavus),
        ICON(Misdreavus, 0),
        .footprint = gMonFootprint_Misdreavus,
        LEARNSETS(Misdreavus),
        .evolutions = EVOLUTION({EVO_ITEM, ITEM_DUSK_STONE, SPECIES_MISMAGIUS}),
    },

#if P_GEN_4_CROSS_EVOS
    [SPECIES_MISMAGIUS] =
    {
        .baseHP        = 60,
        .baseAttack    = 60,
        .baseDefense   = 60,
        .baseSpeed     = 105,
        .baseSpAttack  = 105,
        .baseSpDefense = 105,
        .types = { TYPE_GHOST, TYPE_GHOST },
        .catchRate = 45,
        .expYield = 173,
        .evYield_SpAttack = 1,
        .evYield_SpDefense = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 25,
        .friendship = 35,
        .growthRate = GROWTH_FAST,
        .eggGroups = { EGG_GROUP_AMORPHOUS, EGG_GROUP_AMORPHOUS },
        .abilities = { ABILITY_LEVITATE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_PURPLE,
        .speciesName = _("Traunmagil"),
        .cryId = CRY_MISMAGIUS,
        .natDexNum = NATIONAL_DEX_MISMAGIUS,
        .categoryName = _("Magisch"),
        .height = 9,
        .weight = 44,
        .description = POKEDEX_DESC_STRING(
            "Es spricht Beschwörungen. Viele\n"
            "lösen Schmerzen aus, manche aber\n"
            "bringen Glück."),
        .pokemonScale = 338,
        .pokemonOffset = 8,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Mismagius, 56, 64),
        .frontPicYOffset = 3,
        .frontAnimFrames = sAnims_Mismagius,
        .frontAnimId = ANIM_H_SLIDE_WOBBLE,
        .enemyMonElevation = 3,
        BACK_PIC(Mismagius, 56, 64),
        .backPicYOffset = 3,
        .backAnimId = BACK_ANIM_CONVEX_DOUBLE_ARC,
        PALETTES(Mismagius),
        ICON(Mismagius, 2),
        .footprint = gMonFootprint_Mismagius,
        LEARNSETS(Mismagius),
    },
#endif //P_GEN_4_CROSS_EVOS
#endif //P_FAMILY_MISDREAVUS

#if P_FAMILY_UNOWN
#define UNOWN_MISC_INFO(letter)                                         \
        .baseHP        = 48,                                            \
        .baseAttack    = 72,                                            \
        .baseDefense   = 48,                                            \
        .baseSpeed     = 48,                                            \
        .baseSpAttack  = 72,                                            \
        .baseSpDefense = 48,                                            \
        .types = { TYPE_PSYCHIC, TYPE_PSYCHIC },                        \
        .catchRate = 225,                                               \
        .expYield = 118,                                                \
        .evYield_Attack = 1,                                            \
        .evYield_SpAttack = 1,                                          \
        .genderRatio = MON_GENDERLESS,                                  \
        .eggCycles = 40,                                                \
        .friendship = STANDARD_FRIENDSHIP,                              \
        .growthRate = GROWTH_MEDIUM_FAST,                               \
        .eggGroups = { EGG_GROUP_NO_EGGS_DISCOVERED, EGG_GROUP_NO_EGGS_DISCOVERED },\
        .abilities = { ABILITY_LEVITATE, ABILITY_NONE },                \
        .bodyColor = BODY_COLOR_BLACK,                                  \
        .speciesName = _("Traunmagil"),                                      \
        .cryId = CRY_UNOWN,                                             \
        .natDexNum = NATIONAL_DEX_UNOWN,                                \
        .categoryName = _("Magisch"),                                    \
        .height = 5,                                                    \
        .weight = 50,                                                   \
        .description = gUnownPokedexText,                               \
        .pokemonScale = 411,                                            \
        .pokemonOffset = 2,                                             \
        .trainerScale = 256,                                            \
        .trainerOffset = 0,                                             \
        .frontPicYOffset = 16,                                          \
        .frontAnimFrames = sAnims_Unown,                                \
        .frontAnimId = ANIM_ZIGZAG_FAST,                                \
        .enemyMonElevation = 8,                                         \
        .backAnimId = BACK_ANIM_SHRINK_GROW_VIBRATE,                    \
        PALETTES(Unown),                                                \
        ICON(Unown ##letter, 0),                                        \
        .footprint = gMonFootprint_Unown,                               \
        LEARNSETS(Unown),                                               \
        .formSpeciesIdTable = sUnownFormSpeciesIdTable

    [SPECIES_UNOWN] =
    {
        UNOWN_MISC_INFO(A),
        FRONT_PIC(UnownA, 24, 40),
        BACK_PIC(UnownA, 24, 48),
        .backPicYOffset = 8,
    },

    [SPECIES_UNOWN_B] =
    {
        UNOWN_MISC_INFO(B),
        .noFlip = TRUE,
        FRONT_PIC(UnownB, 24, 32),
        BACK_PIC(UnownB, 40, 48),
        .backPicYOffset = 9,
    },

    [SPECIES_UNOWN_C] =
    {
        UNOWN_MISC_INFO(C),
        .noFlip = TRUE,
        FRONT_PIC(UnownC, 32, 32),
        BACK_PIC(UnownC, 48, 56),
        .backPicYOffset = 6,
    },

    [SPECIES_UNOWN_D] =
    {
        UNOWN_MISC_INFO(D),
        .noFlip = TRUE,
        FRONT_PIC(UnownD, 32, 32),
        BACK_PIC(UnownD, 40, 48),
        .backPicYOffset = 8,
    },

    [SPECIES_UNOWN_E] =
    {
        UNOWN_MISC_INFO(E),
        .noFlip = TRUE,
        FRONT_PIC(UnownE, 32, 32),
        BACK_PIC(UnownE, 40, 48),
        .backPicYOffset = 10,
    },

    [SPECIES_UNOWN_F] =
    {
        UNOWN_MISC_INFO(F),
        .noFlip = TRUE,
        FRONT_PIC(UnownF, 32, 32),
        BACK_PIC(UnownF, 48, 48),
        .backPicYOffset = 10,
    },

    [SPECIES_UNOWN_G] =
    {
        UNOWN_MISC_INFO(G),
        .noFlip = TRUE,
        FRONT_PIC(UnownG, 24, 40),
        BACK_PIC(UnownG, 40, 56),
        .backPicYOffset = 5,
    },

    [SPECIES_UNOWN_H] =
    {
        UNOWN_MISC_INFO(H),
        .noFlip = TRUE,
        FRONT_PIC(UnownH, 32, 32),
        BACK_PIC(UnownH, 48, 48),
        .backPicYOffset = 8,
    },

    [SPECIES_UNOWN_I] =
    {
        UNOWN_MISC_INFO(I),
        FRONT_PIC(UnownI, 24, 32),
        BACK_PIC(UnownI, 24, 56),
        .backPicYOffset = 7,
    },

    [SPECIES_UNOWN_J] =
    {
        UNOWN_MISC_INFO(J),
        .noFlip = TRUE,
        FRONT_PIC(UnownJ, 24, 32),
        BACK_PIC(UnownJ, 32, 48),
        .backPicYOffset = 9,
    },

    [SPECIES_UNOWN_K] =
    {
        UNOWN_MISC_INFO(K),
        .noFlip = TRUE,
        FRONT_PIC(UnownK, 32, 32),
        BACK_PIC(UnownK, 40, 56),
        .backPicYOffset = 7,
    },

    [SPECIES_UNOWN_L] =
    {
        UNOWN_MISC_INFO(L),
        .noFlip = TRUE,
        FRONT_PIC(UnownL, 24, 32),
        BACK_PIC(UnownL, 32, 48),
        .backPicYOffset = 10,
    },

    [SPECIES_UNOWN_M] =
    {
        UNOWN_MISC_INFO(M),
        FRONT_PIC(UnownM, 32, 32),
        BACK_PIC(UnownM, 48, 40),
        .backPicYOffset = 13,
    },

    [SPECIES_UNOWN_N] =
    {
        UNOWN_MISC_INFO(N),
        .noFlip = TRUE,
        FRONT_PIC(UnownN, 32, 24),
        BACK_PIC(UnownN, 48, 40),
        .backPicYOffset = 13,
    },

    [SPECIES_UNOWN_O] =
    {
        UNOWN_MISC_INFO(O),
        FRONT_PIC(UnownO, 32, 32),
        BACK_PIC(UnownO, 48, 48),
        .backPicYOffset = 8,
    },

    [SPECIES_UNOWN_P] =
    {
        UNOWN_MISC_INFO(P),
        .noFlip = TRUE,
        FRONT_PIC(UnownP, 24, 32),
        BACK_PIC(UnownP, 32, 48),
        .backPicYOffset = 10,
    },

    [SPECIES_UNOWN_Q] =
    {
        UNOWN_MISC_INFO(Q),
        .noFlip = TRUE,
        FRONT_PIC(UnownQ, 32, 24),
        BACK_PIC(UnownQ, 40, 40),
        .backPicYOffset = 15,
    },

    [SPECIES_UNOWN_R] =
    {
        UNOWN_MISC_INFO(R),
        .noFlip = TRUE,
        FRONT_PIC(UnownR, 24, 32),
        BACK_PIC(UnownR, 32, 40),
        .backPicYOffset = 12,
    },

    [SPECIES_UNOWN_S] =
    {
        UNOWN_MISC_INFO(S),
        .noFlip = TRUE,
        FRONT_PIC(UnownS, 32, 40),
        BACK_PIC(UnownS, 40, 56),
        .backPicYOffset = 4,
    },

    [SPECIES_UNOWN_T] =
    {
        UNOWN_MISC_INFO(T),
        FRONT_PIC(UnownT, 24, 32),
        BACK_PIC(UnownT, 32, 40),
        .backPicYOffset = 13,
    },

    [SPECIES_UNOWN_U] =
    {
        UNOWN_MISC_INFO(U),
        FRONT_PIC(UnownU, 32, 32),
        BACK_PIC(UnownU, 48, 40),
        .backPicYOffset = 13,
    },

    [SPECIES_UNOWN_V] =
    {
        UNOWN_MISC_INFO(V),
        .noFlip = TRUE,
        FRONT_PIC(UnownV, 32, 32),
        BACK_PIC(UnownV, 40, 48),
        .backPicYOffset = 11,
    },

    [SPECIES_UNOWN_W] =
    {
        UNOWN_MISC_INFO(W),
        FRONT_PIC(UnownW, 32, 32),
        BACK_PIC(UnownW, 40, 40),
        .backPicYOffset = 13,
    },

    [SPECIES_UNOWN_X] =
    {
        UNOWN_MISC_INFO(X),
        FRONT_PIC(UnownX, 24, 24),
        BACK_PIC(UnownX, 40, 40),
        .backPicYOffset = 15,
    },

    [SPECIES_UNOWN_Y] =
    {
        UNOWN_MISC_INFO(Y),
        FRONT_PIC(UnownY, 24, 32),
        BACK_PIC(UnownY, 32, 48),
        .backPicYOffset = 10,
    },

    [SPECIES_UNOWN_Z] =
    {
        UNOWN_MISC_INFO(Z),
        .noFlip = TRUE,
        FRONT_PIC(UnownZ, 24, 32),
        BACK_PIC(UnownZ, 32, 48),
        .backPicYOffset = 10,
    },

    [SPECIES_UNOWN_EMARK] =
    {
        UNOWN_MISC_INFO(ExclamationMark),
        FRONT_PIC(UnownExclamationMark, 24, 40),
        BACK_PIC(UnownExclamationMark, 24, 56),
        .backPicYOffset = 6,
    },

    [SPECIES_UNOWN_QMARK] =
    {
        UNOWN_MISC_INFO(QuestionMark),
        .noFlip = TRUE,
        FRONT_PIC(UnownQuestionMark, 24, 40),
        BACK_PIC(UnownQuestionMark, 32, 56),
        .backPicYOffset = 6,
    },
#endif //P_FAMILY_UNOWN

#if P_FAMILY_WOBBUFFET
#if P_GEN_3_CROSS_EVOS
    [SPECIES_WYNAUT] =
    {
        .baseHP        = 95,
        .baseAttack    = 23,
        .baseDefense   = 48,
        .baseSpeed     = 23,
        .baseSpAttack  = 23,
        .baseSpDefense = 48,
        .types = { TYPE_PSYCHIC, TYPE_PSYCHIC },
        .catchRate = 125,
        .expYield = 52,
        .evYield_HP = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_NO_EGGS_DISCOVERED, EGG_GROUP_NO_EGGS_DISCOVERED },
        .abilities = { ABILITY_SHADOW_TAG, ABILITY_NONE, ABILITY_TELEPATHY },
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Isso"),
        .cryId = CRY_WYNAUT,
        .natDexNum = NATIONAL_DEX_WYNAUT,
        .categoryName = _("Strahlekind"),
        .height = 6,
        .weight = 140,
        .description = POKEDEX_DESC_STRING(
            "Es wird stärker, indem es andere ständig\n"
            "anrempelt. Es liebt Süßigkeiten."),
        .pokemonScale = 484,
        .pokemonOffset = 19,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Wynaut, 48, 40),
        .frontPicYOffset = 12,
        .frontAnimFrames = sAnims_Wynaut,
        .frontAnimId = ANIM_H_JUMPS_V_STRETCH,
        .frontAnimDelay = 15,
        BACK_PIC(Wynaut, 48, 48),
        .backPicYOffset = 11,
        .backAnimId = BACK_ANIM_CONCAVE_ARC_SMALL,
        PALETTES(Wynaut),
        ICON(Wynaut, 0),
        .footprint = gMonFootprint_Wynaut,
        LEARNSETS(Wynaut),
        .evolutions = EVOLUTION({EVO_LEVEL, 15, SPECIES_WOBBUFFET}),
    },
#endif //P_GEN_3_CROSS_EVOS

    [SPECIES_WOBBUFFET] =
    {
        .baseHP        = 190,
        .baseAttack    = 33,
        .baseDefense   = 58,
        .baseSpeed     = 33,
        .baseSpAttack  = 33,
        .baseSpDefense = 58,
        .types = { TYPE_PSYCHIC, TYPE_PSYCHIC },
        .catchRate = 45,
        .expYield = 142,
        .evYield_HP = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_AMORPHOUS, EGG_GROUP_AMORPHOUS },
        .abilities = { ABILITY_SHADOW_TAG, ABILITY_NONE, ABILITY_TELEPATHY },
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Woingenau"),
        .cryId = CRY_WOBBUFFET,
        .natDexNum = NATIONAL_DEX_WOBBUFFET,
        .categoryName = _("Gedulds"),
        .height = 13,
        .weight = 285,
        .description = POKEDEX_DESC_STRING(
            "Es hasst Licht und Schläge. Wird es\n"
            "angegriffen, pumpt es sich auf, um\n"
            "einen Gegenschlag vorzubereiten."),
        .pokemonScale = 274,
        .pokemonOffset = 4,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Wobbuffet, 64, 56),
        FRONT_PIC_FEMALE(Wobbuffet, 64, 56),
        .frontPicYOffset = 5,
        .frontAnimFrames = sAnims_Wobbuffet,
        .frontAnimId = ANIM_GROW_VIBRATE,
        BACK_PIC(Wobbuffet, 56, 56),
        BACK_PIC_FEMALE(Wobbuffet, 56, 56),
        .backPicYOffset = 10,
        .backAnimId = BACK_ANIM_V_STRETCH,
        PALETTES(Wobbuffet),
        ICON(Wobbuffet, 0),
    #if P_CUSTOM_GENDER_DIFF_ICONS == TRUE
        ICON_FEMALE(Wobbuffet, 0),
    #endif
        .footprint = gMonFootprint_Wobbuffet,
        LEARNSETS(Wobbuffet),
        .formSpeciesIdTable = sWobbuffetFormSpeciesIdTable,
        .formChangeTable = sWobbuffetFormChangeTable
    },

    [SPECIES_WOBBUFFET_PUNCHING] = 
    {
        .baseHP        = 190,
        .baseAttack    = 115,
        .baseDefense   = 10,
        .baseSpeed     = 79,
        .baseSpAttack  = 1,
        .baseSpDefense = 10,
        //.baseAttack    = 100,
        //.baseDefense   = 10,
        //.baseSpeed     = 90,
        //.baseSpAttack  = 5,
        //.baseSpDefense = 10,
        .types = { TYPE_PSYCHIC, TYPE_FIGHTING },
        .catchRate = 45,
        .expYield = 142,
        .evYield_HP = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_AMORPHOUS, EGG_GROUP_AMORPHOUS },
        .abilities = { ABILITY_STANCE_CHANGE, ABILITY_NONE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Woingenau"),
        .cryId = CRY_WOBBUFFET,
        .natDexNum = NATIONAL_DEX_WOBBUFFET,
        .categoryName = _("Gedulds"),
        .height = 13,
        .weight = 285,
        .description = POKEDEX_DESC_STRING(
            "Es hasst Licht und Schläge. Wird es\n"
            "angegriffen, pumpt es sich auf, um\n"
            "einen Gegenschlag vorzubereiten."),
        .pokemonScale = 274,
        .pokemonOffset = 4,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(WobbuffetPunching, 64, 56),
        FRONT_PIC_FEMALE(WobbuffetPunching, 64, 56),
        .frontPicYOffset = 5,
        .frontAnimFrames = sAnims_Wobbuffet,
        .frontAnimId = ANIM_GROW_VIBRATE,
        BACK_PIC(WobbuffetPunching, 56, 56),
        BACK_PIC_FEMALE(WobbuffetPunching, 56, 56),
        .backPicYOffset = 10,
        .backAnimId = BACK_ANIM_V_STRETCH,
        PALETTES(WobbuffetPunching),
        ICON(WobbuffetPunching, 0),
    #if P_CUSTOM_GENDER_DIFF_ICONS == TRUE
        ICON_FEMALE(WobbuffetPunching, 0),
    #endif
        .footprint = gMonFootprint_Wobbuffet,
        LEARNSETS(Wobbuffet),
        .formSpeciesIdTable = sWobbuffetFormSpeciesIdTable,
        .formChangeTable = sWobbuffetFormChangeTable
    },
#endif //P_FAMILY_WOBBUFFET

#if P_FAMILY_GIRAFARIG
    [SPECIES_GIRAFARIG] =
    {
        .baseHP        = 70,
        .baseAttack    = 80,
        .baseDefense   = 65,
        .baseSpeed     = 85,
        .baseSpAttack  = 90,
        .baseSpDefense = 65,
        .types = { TYPE_NORMAL, TYPE_PSYCHIC },
        .catchRate = 60,
        .expYield = 159,
        .evYield_SpAttack = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD },
        .abilities = { ABILITY_INNER_FOCUS, ABILITY_EARLY_BIRD, ABILITY_SAP_SIPPER },
        .bodyColor = BODY_COLOR_YELLOW,
        .speciesName = _("Girafarig"),
        .cryId = CRY_GIRAFARIG,
        .natDexNum = NATIONAL_DEX_GIRAFARIG,
        .categoryName = _("Langhals"),
        .height = 15,
        .weight = 415,
        .description = POKEDEX_DESC_STRING(
            "Während es schläft, hält sein\n"
            "Schweif Wache. Dieser benötigt\n"
            "keinen Schlaf."),
        .pokemonScale = 281,
        .pokemonOffset = 1,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Girafarig, 56, 64),
        FRONT_PIC_FEMALE(Girafarig, 56, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_Girafarig,
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(Girafarig, 64, 64),
        BACK_PIC_FEMALE(Girafarig, 64, 64),
        .backPicYOffset = 1,
        .backAnimId = BACK_ANIM_SHRINK_GROW_VIBRATE,
        PALETTES(Girafarig),
        ICON(Girafarig, 1),
        .footprint = gMonFootprint_Girafarig,
        LEARNSETS(Girafarig),
        .evolutions = EVOLUTION({EVO_MOVE, MOVE_TWIN_BEAM, SPECIES_FARIGIRAF}),
    },

#if P_GEN_9_CROSS_EVOS
    [SPECIES_FARIGIRAF] =
    {
        .baseHP        = 120,
        .baseAttack    = 90,
        .baseDefense   = 70,
        .baseSpeed     = 60,
        .baseSpAttack  = 110,
        .baseSpDefense = 70,
        .types = { TYPE_NORMAL, TYPE_PSYCHIC },
        .catchRate = 45,
        .expYield = 260,
        .evYield_HP = 3,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD },
        .abilities = { ABILITY_CUD_CHEW, ABILITY_ARMOR_TAIL, ABILITY_SAP_SIPPER },
        .bodyColor = BODY_COLOR_BROWN,
        .speciesName = _("Farigiraf"),
        .cryId = CRY_FARIGIRAF,
        .natDexNum = NATIONAL_DEX_FARIGIRAF,
        .categoryName = _("Langhals"),
        .height = 32,
        .weight = 1600,
        .description = POKEDEX_DESC_STRING(
            "Da nun die Gehirnwellen von Kopf und\n"
            "Schwanz synchronisiert sind, beträgt die\n"
            "psychische Kraft dieses Pokémon 10"),
        .pokemonScale = 356,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Farigiraf, 64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_Farigiraf,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(Farigiraf, 64, 64),
        .backPicYOffset = 0,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(Farigiraf),
        ICON(Farigiraf, 1),
        //.footprint = gMonFootprint_Farigiraf,
        LEARNSETS(Farigiraf),
    },
#endif //P_GEN_9_CROSS_EVOS
#endif //P_FAMILY_GIRAFARIG

#if P_FAMILY_PINECO
    [SPECIES_PINECO] =
    {
        .baseHP        = 50,
        .baseAttack    = 65,
        .baseDefense   = 90,
        .baseSpeed     = 15,
        .baseSpAttack  = 35,
        .baseSpDefense = 35,
        .types = { TYPE_BUG, TYPE_BUG },
        .catchRate = 190,
        .expYield = 58,
        .evYield_Defense = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_BUG, EGG_GROUP_BUG },
        .abilities = { ABILITY_STURDY, ABILITY_NONE, ABILITY_OVERCOAT },
        .bodyColor = BODY_COLOR_GRAY,
        .speciesName = _("Tannza"),
        .cryId = CRY_PINECO,
        .natDexNum = NATIONAL_DEX_PINECO,
        .categoryName = _("Beutelwurm"),
        .height = 6,
        .weight = 72,
        .description = POKEDEX_DESC_STRING(
            "Es sieht aus wie ein Tannenzapfen. Seine\n"
            "Schale schützt es vor Vogel-Pokémon, die\n"
            "an ihm picken wollen."),
        .pokemonScale = 445,
        .pokemonOffset = 2,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Pineco, 40, 40),
        .frontPicYOffset = 12,
        .frontAnimFrames = sAnims_Pineco,
        .frontAnimId = ANIM_SWING_CONCAVE,
        BACK_PIC(Pineco, 56, 40),
        .backPicYOffset = 13,
        .backAnimId = BACK_ANIM_H_SHAKE,
        PALETTES(Pineco),
        ICON(Pineco, 0),
        .footprint = gMonFootprint_Pineco,
        LEARNSETS(Pineco),
        .evolutions = EVOLUTION({EVO_LEVEL, 31, SPECIES_FORRETRESS}),
    },

    [SPECIES_FORRETRESS] =
    {
        .baseHP        = 75,
        .baseAttack    = 90,
        .baseDefense   = 140,
        .baseSpeed     = 40,
        .baseSpAttack  = 60,
        .baseSpDefense = 60,
        .types = { TYPE_BUG, TYPE_STEEL },
        .catchRate = 75,
        .expYield = 163,
        .evYield_Defense = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_BUG, EGG_GROUP_BUG },
        .abilities = { ABILITY_STURDY, ABILITY_NONE, ABILITY_OVERCOAT },
        .bodyColor = BODY_COLOR_PURPLE,
        .speciesName = _("Forstellka"),
        .cryId = CRY_FORRETRESS,
        .natDexNum = NATIONAL_DEX_FORRETRESS,
        .categoryName = _("Beutelwurm"),
        .height = 12,
        .weight = 1258,
        .description = POKEDEX_DESC_STRING(
            "Dieses Pokémon ist von einer\n"
            "Stahlhülle umgeben. Seine\n"
            "stechenden Augen sind alles, was\n"
            "man von ihm sieht."),
        .pokemonScale = 293,
        .pokemonOffset = 5,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Forretress, 64, 48),
        .frontPicYOffset = 8,
        .frontAnimFrames = sAnims_Forretress,
        .frontAnimId = ANIM_V_SHAKE,
        BACK_PIC(Forretress, 64, 32),
        .backPicYOffset = 16,
        .backAnimId = BACK_ANIM_V_SHAKE,
        PALETTES(Forretress),
        ICON(Forretress, 2),
        .footprint = gMonFootprint_Forretress,
        LEARNSETS(Forretress),
    },
#endif //P_FAMILY_PINECO

#if P_FAMILY_DUNSPARCE
    [SPECIES_DUNSPARCE] =
    {
        .baseHP        = 100,
        .baseAttack    = 70,
        .baseDefense   = 70,
        .baseSpeed     = 45,
        .baseSpAttack  = 65,
        .baseSpDefense = 65,
        .types = { TYPE_NORMAL, TYPE_NORMAL },
        .catchRate = 190,
        .expYield = 145,
        .evYield_HP = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD },
        .abilities = { ABILITY_SERENE_GRACE, ABILITY_RUN_AWAY, ABILITY_RATTLED },
        .bodyColor = BODY_COLOR_YELLOW,
        .speciesName = _("Dummisel"),
        .cryId = CRY_DUNSPARCE,
        .natDexNum = NATIONAL_DEX_DUNSPARCE,
        .categoryName = _("Schlangen"),
        .height = 15,
        .weight = 140,
        .description = POKEDEX_DESC_STRING(
            "Es gräbt sich mit seinem Schweif in die\n"
            "Erde und baut ein labyrinthartiges Nest.\n"
            "Es kann kaum fliegen."),
        .pokemonScale = 316,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Dunsparce, 48, 48),
        .frontPicYOffset = 9,
        .frontAnimFrames = sAnims_Dunsparce,
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .frontAnimDelay = 10,
        BACK_PIC(Dunsparce, 56, 32),
        .backPicYOffset = 17,
        .backAnimId = BACK_ANIM_TRIANGLE_DOWN,
        PALETTES(Dunsparce),
        ICON(Dunsparce, 0),
        .footprint = gMonFootprint_Dunsparce,
        LEARNSETS(Dunsparce),
        .evolutions = EVOLUTION({EVO_MOVE_TWO_SEGMENT, MOVE_HYPER_DRILL, SPECIES_DUDUNSPARCE_TWO_SEGMENT},
                                {EVO_MOVE_THREE_SEGMENT, MOVE_HYPER_DRILL, SPECIES_DUDUNSPARCE_THREE_SEGMENT}),
    },

#if P_GEN_9_CROSS_EVOS
#define DUDUNSPARCE_MISC_INFO(segments)                                             \
        .baseHP        = 125,                                                       \
        .baseAttack    = 100,                                                       \
        .baseDefense   = 80,                                                        \
        .baseSpeed     = 55,                                                        \
        .baseSpAttack  = 85,                                                        \
        .baseSpDefense = 75,                                                        \
        .types = { TYPE_NORMAL, TYPE_NORMAL },                                      \
        .catchRate = 45,                                                            \
        .expYield = 182,                                                            \
        .evYield_HP = 2,                                                            \
        .genderRatio = PERCENT_FEMALE(50),                                          \
        .eggCycles = 20,                                                            \
        .friendship = STANDARD_FRIENDSHIP,                                          \
        .growthRate = GROWTH_MEDIUM_FAST,                                           \
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD },                          \
        .abilities = { ABILITY_SERENE_GRACE, ABILITY_RUN_AWAY, ABILITY_RATTLED },   \
        .bodyColor = BODY_COLOR_YELLOW,                                             \
        .speciesName = _("Dummisel"),                                             \
        .cryId = CRY_DUDUNSPARCE,                                                   \
        .natDexNum = NATIONAL_DEX_DUDUNSPARCE,                                      \
        .categoryName = _("Schlangen"),                                            \
        .pokemonScale = 356,                                                        \
        .pokemonOffset = 17,                                                        \
        .trainerScale = 256,                                                        \
        .trainerOffset = 0,                                                         \
        FRONT_PIC(Dudunsparce ##segments##Segment, 64, 64),                         \
        .frontPicYOffset = 10,                                                      \
        .frontAnimFrames = sAnims_Dudunsparce,                                      \
        BACK_PIC(Dudunsparce ##segments##Segment, 64, 64),                          \
        .backPicYOffset = 11,                                                       \
        PALETTES(Dudunsparce),                                                      \
        ICON(Dudunsparce, 0),                                                       \
        LEARNSETS(Dudunsparce),                                                     \
        .formSpeciesIdTable = sDudunsparceFormSpeciesIdTable
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        //.backAnimId = BACK_ANIM_NONE,
        //.footprint = gMonFootprint_Dudunsparce,

    [SPECIES_DUDUNSPARCE_TWO_SEGMENT] =
    {
        DUDUNSPARCE_MISC_INFO(Two),
        .height = 36,
        .weight = 392,
        .description = POKEDEX_DESC_STRING(
            "This Pokémon uses its hard tail to\n"
            "make its nest by boring holes into\n"
            "bedrock deep underground. The nest\n"
            "can reach lengths of over six miles."),
    },

    [SPECIES_DUDUNSPARCE_THREE_SEGMENT] =
    {
        DUDUNSPARCE_MISC_INFO(Three),
        .height = 45,
        .weight = 474,
        .description = POKEDEX_DESC_STRING(
            "A recent study uncovered that the\n"
            "number of segments a\n"
            "Dudunsparce's body has is determined by the\n"
            "Pokémon's genes."),
    },
#endif //P_GEN_9_CROSS_EVOS
#endif //P_FAMILY_DUNSPARCE

#if P_FAMILY_GLIGAR
    [SPECIES_GLIGAR] =
    {
        .baseHP        = 65,
        .baseAttack    = 75,
        .baseDefense   = 105,
        .baseSpeed     = 85,
        .baseSpAttack  = 35,
        .baseSpDefense = 65,
        .types = { TYPE_GROUND, TYPE_FLYING },
        .catchRate = 60,
        .expYield = 86,
        .evYield_Defense = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_BUG, EGG_GROUP_BUG },
        .abilities = { ABILITY_HYPER_CUTTER, ABILITY_SAND_VEIL, ABILITY_IMMUNITY },
        .bodyColor = BODY_COLOR_PURPLE,
        .speciesName = _("Skorgla"),
        .cryId = CRY_GLIGAR,
        .natDexNum = NATIONAL_DEX_GLIGAR,
        .categoryName = _("Flugskorpi"),
        .height = 11,
        .weight = 648,
        .description = POKEDEX_DESC_STRING(
            "Es fliegt direkt auf das Gesicht seiner\n"
            "Feinde zu und injiziert ihnen eine\n"
            "Überdosis Gift."),
        .pokemonScale = 350,
        .pokemonOffset = -1,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Gligar, 56, 56),
        FRONT_PIC_FEMALE(Gligar, 56, 56),
        .frontPicYOffset = 4,
        .frontAnimFrames = sAnims_Gligar,
        .frontAnimId = ANIM_SHRINK_GROW,
        .enemyMonElevation = 8,
        BACK_PIC(Gligar, 64, 64),
        BACK_PIC_FEMALE(Gligar, 64, 64),
        .backPicYOffset = 2,
        .backAnimId = BACK_ANIM_SHRINK_GROW,
        PALETTES(Gligar),
        ICON(Gligar, 0),
        .footprint = gMonFootprint_Gligar,
        LEARNSETS(Gligar),
        .evolutions = EVOLUTION({EVO_ITEM_HOLD_NIGHT, ITEM_RAZOR_FANG, SPECIES_GLISCOR},
                                {EVO_ITEM_NIGHT, ITEM_RAZOR_FANG, SPECIES_GLISCOR}),
    },

#if P_GEN_4_CROSS_EVOS
    [SPECIES_GLISCOR] =
    {
        .baseHP        = 75,
        .baseAttack    = 95,
        .baseDefense   = 125,
        .baseSpeed     = 95,
        .baseSpAttack  = 45,
        .baseSpDefense = 75,
        .types = { TYPE_GROUND, TYPE_FLYING },
        .catchRate = 30,
        .expYield = 179,
        .evYield_Defense = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_BUG, EGG_GROUP_BUG },
        .abilities = { ABILITY_HYPER_CUTTER, ABILITY_SAND_VEIL, ABILITY_POISON_HEAL },
        .bodyColor = BODY_COLOR_PURPLE,
        .speciesName = _("Skorgro"),
        .cryId = CRY_GLISCOR,
        .natDexNum = NATIONAL_DEX_GLISCOR,
        .categoryName = _("Zahnskorpi"),
        .height = 20,
        .weight = 425,
        .description = POKEDEX_DESC_STRING(
            "Es hängt kopfüber von einem Ast und\n"
            "beobachtet seine Beute. Bei\n"
            "Gelegenheit stürzt es sich auf sie."),
        .pokemonScale = 261,
        .pokemonOffset = 1,
        .trainerScale = 334,
        .trainerOffset = 4,
        FRONT_PIC(Gliscor, 64, 56),
        .frontPicYOffset = 7,
        .frontAnimFrames = sAnims_Gliscor,
        .frontAnimId = ANIM_SWING_CONVEX,
        .enemyMonElevation = 9,
        BACK_PIC(Gliscor, 64, 48),
        .backPicYOffset = 11,
        .backAnimId = BACK_ANIM_V_STRETCH,
        PALETTES(Gliscor),
        ICON(Gliscor, 2),
        .footprint = gMonFootprint_Gliscor,
        LEARNSETS(Gliscor),
    },
#endif //P_GEN_4_CROSS_EVOS
#endif //P_FAMILY_GLIGAR

#if P_FAMILY_SNUBBULL
    [SPECIES_SNUBBULL] =
    {
        .baseHP        = 60,
        .baseAttack    = 80,
        .baseDefense   = 50,
        .baseSpeed     = 30,
        .baseSpAttack  = 40,
        .baseSpDefense = 40,
        #if P_UPDATED_TYPES >= GEN_6
            .types = { TYPE_FAIRY, TYPE_FAIRY },
        #else
            .types = { TYPE_NORMAL, TYPE_NORMAL },
        #endif
        .catchRate = 190,
        .expYield = 60,
        .evYield_Attack = 1,
        .genderRatio = PERCENT_FEMALE(75),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_FAST,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FAIRY },
        .abilities = { ABILITY_INTIMIDATE, ABILITY_RUN_AWAY, ABILITY_RATTLED },
        .bodyColor = BODY_COLOR_PINK,
        .speciesName = _("Snubbull"),
        .cryId = CRY_SNUBBULL,
        .natDexNum = NATIONAL_DEX_SNUBBULL,
        .categoryName = _("Fee"),
        .height = 6,
        .weight = 78,
        .description = POKEDEX_DESC_STRING(
            "Kleine Pokémon fliehen beim Anblick seines\n"
            "Gesichts. Frauen aber finden es niedlich."),
        .pokemonScale = 465,
        .pokemonOffset = 19,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Snubbull, 40, 40),
        .frontPicYOffset = 12,
        .frontAnimFrames = sAnims_Snubbull,
        .frontAnimId = ANIM_V_STRETCH,
        BACK_PIC(Snubbull, 56, 40),
        .backPicYOffset = 12,
        .backAnimId = BACK_ANIM_JOLT_RIGHT,
        PALETTES(Snubbull),
        ICON(Snubbull, 0),
        .footprint = gMonFootprint_Snubbull,
        LEARNSETS(Snubbull),
        .evolutions = EVOLUTION({EVO_LEVEL, 23, SPECIES_GRANBULL}),
    },

    [SPECIES_GRANBULL] =
    {
        .baseHP        = 90,
        .baseAttack    = 120,
        .baseDefense   = 75,
        .baseSpeed     = 45,
        .baseSpAttack  = 60,
        .baseSpDefense = 60,
        #if P_UPDATED_TYPES >= GEN_6
            .types = { TYPE_FAIRY, TYPE_FAIRY },
        #else
            .types = { TYPE_NORMAL, TYPE_NORMAL },
        #endif
        .catchRate = 75,
        .expYield = 158,
        .evYield_Attack = 2,
        .genderRatio = PERCENT_FEMALE(75),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_FAST,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FAIRY },
        .abilities = { ABILITY_INTIMIDATE, ABILITY_QUICK_FEET, ABILITY_RATTLED },
        .bodyColor = BODY_COLOR_PURPLE,
        .speciesName = _("Granbull"),
        .cryId = CRY_GRANBULL,
        .natDexNum = NATIONAL_DEX_GRANBULL,
        .categoryName = _("Fee"),
        .height = 14,
        .weight = 487,
        .description = POKEDEX_DESC_STRING(
            "Sein Unterkiefer ist sehr stark. Da es\n"
            "jedoch den Kampf scheut, kommt es nur\n"
            "selten dazu, dies zu demonstrieren."),
        .pokemonScale = 256,
        .pokemonOffset = 4,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Granbull, 56, 56),
        .frontPicYOffset = 4,
        .frontAnimFrames = sAnims_Granbull,
        .frontAnimId = ANIM_V_SHAKE,
        BACK_PIC(Granbull, 56, 48),
        .backPicYOffset = 8,
        .backAnimId = BACK_ANIM_V_SHAKE,
        PALETTES(Granbull),
        ICON(Granbull, 2),
        .footprint = gMonFootprint_Granbull,
        LEARNSETS(Granbull),
    },
#endif //P_FAMILY_SNUBBULL

#if P_FAMILY_QWILFISH
#define QWILFISH_MISC_INFO                                                              \
        .baseHP        = 65,                                                            \
        .baseAttack    = 95,                                                            \
        .baseDefense   = P_UPDATED_STATS >= GEN_7 ? 85 : 75,                            \
        .baseSpeed     = 85,                                                            \
        .baseSpAttack  = 55,                                                            \
        .baseSpDefense = 55,                                                            \
        .catchRate = 45,                                                                \
        .expYield = 88,                                                                 \
        .evYield_Attack = 1,                                                            \
        .itemRare = ITEM_POISON_BARB,                                                   \
        .genderRatio = PERCENT_FEMALE(50),                                              \
        .eggCycles = 20,                                                                \
        .friendship = STANDARD_FRIENDSHIP,                                              \
        .growthRate = GROWTH_MEDIUM_FAST,                                               \
        .eggGroups = { EGG_GROUP_WATER_2, EGG_GROUP_WATER_2 },                          \
        .abilities = { ABILITY_POISON_POINT, ABILITY_SWIFT_SWIM, ABILITY_INTIMIDATE },  \
        .speciesName = _("Granbull"),                                                   \
        .cryId = CRY_QWILFISH,                                                          \
        .natDexNum = NATIONAL_DEX_QWILFISH,                                             \
        .categoryName = _("Fee"),                                                   \
        .height = 5,                                                                    \
        .weight = 39,                                                                   \
        .pokemonScale = 430,                                                            \
        .pokemonOffset = 0,                                                             \
        .trainerScale = 256,                                                            \
        .trainerOffset = 0,                                                             \
        .footprint = gMonFootprint_Qwilfish,                                            \
        .formSpeciesIdTable = sQwilfishFormSpeciesIdTable

    [SPECIES_QWILFISH] =
    {
        QWILFISH_MISC_INFO,
        .types = { TYPE_WATER, TYPE_POISON },
        .bodyColor = BODY_COLOR_GRAY,
        .description = POKEDEX_DESC_STRING(
            "Um seine Giftstacheln abzufeuern,\n"
            "muss es seinen Körper aufpumpen,\n"
            "indem es 10 l trinkt."),
        FRONT_PIC(Qwilfish, 40, 48),
        .frontPicYOffset = 8,
        .frontAnimFrames = sAnims_Qwilfish,
        .frontAnimId = ANIM_GROW_IN_STAGES,
        .frontAnimDelay = 39,
        BACK_PIC(Qwilfish, 56, 56),
        .backPicYOffset = 6,
        .backAnimId = BACK_ANIM_GROW_STUTTER,
        PALETTES(Qwilfish),
        ICON(Qwilfish, 0),
        LEARNSETS(Qwilfish),
    },

#if P_HISUIAN_FORMS
    [SPECIES_QWILFISH_HISUI] =
    {
        QWILFISH_MISC_INFO,
        .types = { TYPE_DARK, TYPE_POISON },
        .bodyColor = BODY_COLOR_BLACK,
        .description = POKEDEX_DESC_STRING(
            "Um seine Giftstacheln abzufeuern,\n"
            "muss es seinen Körper aufpumpen,\n"
            "indem es 10 l trinkt."),
        FRONT_PIC(QwilfishHisuian, 48, 40),
        .frontPicYOffset = 16,
        .frontAnimFrames = sAnims_QwilfishHisuian,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .enemyMonElevation = 9,
        BACK_PIC(QwilfishHisuian, 56, 56),
        .backPicYOffset = 8,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(QwilfishHisuian),
        ICON(QwilfishHisuian, 1),
        LEARNSETS(QwilfishHisuian),
        .isHisuianForm = TRUE,
        .evolutions = EVOLUTION({EVO_MOVE, MOVE_BARB_BARRAGE, SPECIES_OVERQWIL}),
    },

    [SPECIES_OVERQWIL] =
    {
        .baseHP        = 85,
        .baseAttack    = 115,
        .baseDefense   = 95,
        .baseSpeed     = 85,
        .baseSpAttack  = 65,
        .baseSpDefense = 65,
        .types = { TYPE_DARK, TYPE_POISON },
        .catchRate = 45,
        .expYield = 179,
        .evYield_Attack = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_WATER_2, EGG_GROUP_WATER_2 },
        .abilities = { ABILITY_POISON_POINT, ABILITY_SWIFT_SWIM, ABILITY_INTIMIDATE },
        .bodyColor = BODY_COLOR_BLACK,
        .speciesName = _("Myriador"),
        .cryId = CRY_OVERQWIL,
        .natDexNum = NATIONAL_DEX_OVERQWIL,
        .categoryName = _("Tausenddorn"),
        .height = 25,
        .weight = 605,
        .description = POKEDEX_DESC_STRING(
            "Seine lanzenförmigen Stacheln und sein\n"
            "wildes Temperament haben ihm den\n"
            "Spitznamen Sea Fiend eingebracht."),
        .pokemonScale = 257,
        .pokemonOffset = 10,
        .trainerScale = 423,
        .trainerOffset = 8,
        FRONT_PIC(Overqwil, 64, 64),
        .frontPicYOffset = 2,
        .frontAnimFrames = sAnims_Overqwil,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(Overqwil, 64, 56),
        .backPicYOffset = 7,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(Overqwil),
        ICON(Overqwil, 2),
        //.footprint = gMonFootprint_Overqwil,
        LEARNSETS(Overqwil),
    },
#endif //P_HISUIAN_FORMS
#endif //P_FAMILY_QWILFISH

#if P_FAMILY_SHUCKLE
    [SPECIES_SHUCKLE] =
    {
        .baseHP        = 20,
        .baseAttack    = 10,
        .baseDefense   = 230,
        .baseSpeed     = 5,
        .baseSpAttack  = 10,
        .baseSpDefense = 230,
        .types = { TYPE_BUG, TYPE_ROCK },
        .catchRate = 190,
        .expYield = 177,
        .evYield_Defense = 1,
        .evYield_SpDefense = 1,
        .itemCommon = ITEM_BERRY_JUICE,
        .itemRare = ITEM_BERRY_JUICE,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_BUG, EGG_GROUP_BUG },
        .abilities = { ABILITY_STURDY, ABILITY_GLUTTONY, ABILITY_CONTRARY },
        .bodyColor = BODY_COLOR_YELLOW,
        .speciesName = _("Pottrott"),
        .cryId = CRY_SHUCKLE,
        .natDexNum = NATIONAL_DEX_SHUCKLE,
        .categoryName = _("Schimmel"),
        .height = 6,
        .weight = 205,
        .description = POKEDEX_DESC_STRING(
            "In seinem topfförmigen Panzer\n"
            "gelagerte Beeren verwandeln sich im\n"
            "Nu zu einem dickflüssigen Saft."),
        .pokemonScale = 485,
        .pokemonOffset = 18,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Shuckle, 56, 48),
        .frontPicYOffset = 8,
        .frontAnimFrames = sAnims_Shuckle,
        .frontAnimId = ANIM_SWING_CONCAVE,
        BACK_PIC(Shuckle, 48, 48),
        .backPicYOffset = 11,
        .backAnimId = BACK_ANIM_DIP_RIGHT_SIDE,
        PALETTES(Shuckle),
        ICON(Shuckle, 1),
        .footprint = gMonFootprint_Shuckle,
        LEARNSETS(Shuckle),
    },
#endif //P_FAMILY_SHUCKLE

#if P_FAMILY_HERACROSS
#define HERACROSS_MISC_INFO                                 \
        .types = { TYPE_BUG, TYPE_FIGHTING },               \
        .catchRate = 45,                                    \
        .evYield_Attack = 2,                                \
        .genderRatio = PERCENT_FEMALE(50),                  \
        .eggCycles = 25,                                    \
        .friendship = STANDARD_FRIENDSHIP,                  \
        .growthRate = GROWTH_SLOW,                          \
        .eggGroups = { EGG_GROUP_BUG, EGG_GROUP_BUG },      \
        .bodyColor = BODY_COLOR_BLUE,                       \
        .speciesName = _("Pottrott"),                      \
        .natDexNum = NATIONAL_DEX_HERACROSS,                \
        .categoryName = _("Schimmel"),                   \
        .footprint = gMonFootprint_Heracross,               \
        LEARNSETS(Heracross),                               \
        .formSpeciesIdTable = sHeracrossFormSpeciesIdTable, \
        .formChangeTable = sHeracrossFormChangeTable

    [SPECIES_HERACROSS] =
    {
        HERACROSS_MISC_INFO,
        .baseHP        = 80,
        .baseAttack    = 125,
        .baseDefense   = 75,
        .baseSpeed     = 85,
        .baseSpAttack  = 40,
        .baseSpDefense = 95,
        .expYield = 175,
        .abilities = { ABILITY_SWARM, ABILITY_GUTS, ABILITY_MOXIE },
        .cryId = CRY_HERACROSS,
        .height = 15,
        .weight = 540,
        .description = POKEDEX_DESC_STRING(
            "Dieses kräftige Pokémon rammt sein\n"
            "stolzes Horn unter den Rumpf des\n"
            "Gegners und wirft ihn um."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Heracross, 64, 64),
        FRONT_PIC_FEMALE(Heracross, 64, 64),
        .frontPicYOffset = 1,
        .frontAnimFrames = sAnims_Heracross,
        .frontAnimId = ANIM_V_STRETCH,
        BACK_PIC(Heracross, 48, 64),
        BACK_PIC_FEMALE(Heracross, 48, 64),
        .backPicYOffset = 2,
        .backAnimId = BACK_ANIM_JOLT_RIGHT,
        PALETTES(Heracross),
        ICON(Heracross, 0),
    },

#if P_MEGA_EVOLUTIONS
    [SPECIES_HERACROSS_MEGA] =
    {
        HERACROSS_MISC_INFO,
        .baseHP        = 80,
        .baseAttack    = 185,
        .baseDefense   = 115,
        .baseSpeed     = 75,
        .baseSpAttack  = 40,
        .baseSpDefense = 105,
        .expYield = 210,
        .abilities = { ABILITY_SKILL_LINK, ABILITY_SKILL_LINK, ABILITY_SKILL_LINK },
        .cryId = CRY_HERACROSS_MEGA,
        .height = 17,
        .weight = 625,
        .description = POKEDEX_DESC_STRING(
            "Dieses kräftige Pokémon rammt sein\n"
            "stolzes Horn unter den Rumpf des\n"
            "Gegners und wirft ihn um."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(HeracrossMega, 64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_HeracrossMega,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(HeracrossMega, 56, 64),
        .backPicYOffset = 0,
        .backAnimId = BACK_ANIM_JOLT_RIGHT,
        PALETTES(HeracrossMega),
        ICON(HeracrossMega, 0),
        .isMegaEvolution = TRUE,
    },
#endif //P_MEGA_EVOLUTIONS
#endif //P_FAMILY_HERACROSS

#if P_FAMILY_SNEASEL
#define SNEASEL_MISC_INFO                                   \
        .baseHP        = 55,                                \
        .baseAttack    = 95,                                \
        .baseDefense   = 55,                                \
        .baseSpeed     = 115,                               \
        .baseSpAttack  = 35,                                \
        .baseSpDefense = 75,                                \
        .catchRate = 60,                                    \
        .expYield = 86,                                     \
        .evYield_Speed = 1,                                 \
        .itemRare = ITEM_QUICK_CLAW,                        \
        .genderRatio = PERCENT_FEMALE(50),                  \
        .eggCycles = 20,                                    \
        .friendship = 35,                                   \
        .growthRate = GROWTH_MEDIUM_SLOW,                   \
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD },  \
        .noFlip = TRUE,                                     \
        .speciesName = _("Skaraborn"),                        \
        .cryId = CRY_SNEASEL,                               \
        .natDexNum = NATIONAL_DEX_SNEASEL,                  \
        .categoryName = _("Einzelhorn"),                    \
        .height = 9,                                        \
        .pokemonScale = 413,                                \
        .pokemonOffset = -3,                                \
        .trainerScale = 256,                                \
        .trainerOffset = 0,                                 \
        .footprint = gMonFootprint_Sneasel,                 \
        .formSpeciesIdTable = sSneaselFormSpeciesIdTable

    [SPECIES_SNEASEL] =
    {
        SNEASEL_MISC_INFO,
        .types = { TYPE_DARK, TYPE_ICE },
        .abilities = { ABILITY_INNER_FOCUS, ABILITY_KEEN_EYE, ABILITY_PICKPOCKET },
        .bodyColor = BODY_COLOR_BLACK,
        .weight = 280,
        .description = POKEDEX_DESC_STRING(
            "Es ernährt sich von Eiern, die es\n"
            "aus Nestern stiehlt. Beute greift\n"
            "es mit seinen scharfen Krallen an."),
        FRONT_PIC(Sneasel, 56, 48),
        FRONT_PIC_FEMALE(Sneasel, 56, 48),
        .frontPicYOffset = 8,
        .frontAnimFrames = sAnims_Sneasel,
        .frontAnimId = ANIM_H_JUMPS,
        BACK_PIC(Sneasel, 64, 64),
        BACK_PIC_FEMALE(Sneasel, 64, 64),
        .backPicYOffset = 3,
        .backAnimId = BACK_ANIM_TRIANGLE_DOWN,
        PALETTES(Sneasel),
        ICON(Sneasel, 0),
        LEARNSETS(Sneasel),
        .evolutions = EVOLUTION({EVO_ITEM_HOLD_NIGHT, ITEM_RAZOR_CLAW, SPECIES_WEAVILE},
                                {EVO_ITEM_NIGHT, ITEM_RAZOR_CLAW, SPECIES_WEAVILE}),
    },

#if P_GEN_4_CROSS_EVOS
    [SPECIES_WEAVILE] =
    {
        .baseHP        = 70,
        .baseAttack    = 120,
        .baseDefense   = 65,
        .baseSpeed     = 125,
        .baseSpAttack  = 45,
        .baseSpDefense = 85,
        .types = { TYPE_DARK, TYPE_ICE },
        .catchRate = 45,
        .expYield = 179,
        .evYield_Attack = 1,
        .evYield_Speed = 1,
        .itemRare = ITEM_QUICK_CLAW,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = 35,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD },
        .abilities = { ABILITY_PRESSURE, ABILITY_NONE, ABILITY_PICKPOCKET },
        .bodyColor = BODY_COLOR_BLACK,
        .speciesName = _("Snibunna"),
        .cryId = CRY_WEAVILE,
        .natDexNum = NATIONAL_DEX_WEAVILE,
        .categoryName = _("Stichklauen"),
        .height = 11,
        .weight = 340,
        .description = POKEDEX_DESC_STRING(
            "Es lebt in schneereichen Gebieten.\n"
            "Snibunna senden einander Signale,\n"
            "indem sie Zeichen in Rinde ritzen."),
        .pokemonScale = 320,
        .pokemonOffset = 7,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Weavile, 56, 56),
        FRONT_PIC_FEMALE(Weavile, 56, 56),
        .frontPicYOffset = 4,
        .frontAnimFrames = sAnims_Weavile,
        .frontAnimId = ANIM_H_VIBRATE,
        BACK_PIC(Weavile, 64, 64),
        BACK_PIC_FEMALE(Weavile, 64, 64),
        .backPicYOffset = 6,
        .backAnimId = BACK_ANIM_JOLT_RIGHT,
        PALETTES(Weavile),
        ICON(Weavile, 0),
        .footprint = gMonFootprint_Weavile,
        LEARNSETS(Weavile),
    },
#endif //P_GEN_4_CROSS_EVOS

#if P_HISUIAN_FORMS
    [SPECIES_SNEASEL_HISUI] =
    {
        SNEASEL_MISC_INFO,
        .types = { TYPE_FIGHTING, TYPE_POISON },
        .abilities = { ABILITY_INNER_FOCUS, ABILITY_KEEN_EYE, ABILITY_PICKPOCKET },
        .bodyColor = BODY_COLOR_GRAY,
        .weight = 270,
        .description = POKEDEX_DESC_STRING(
            "Es ernährt sich von Eiern, die es\n"
            "aus Nestern stiehlt. Beute greift\n"
            "es mit seinen scharfen Krallen an."),
        FRONT_PIC(SneaselHisuian, 56, 56),
        FRONT_PIC_FEMALE(SneaselHisuian, 56, 56),
        .frontPicYOffset = 8,
        .frontAnimFrames = sAnims_SneaselHisuian,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(SneaselHisuian, 56, 64),
        BACK_PIC_FEMALE(SneaselHisuian, 56, 64),
        .backPicYOffset = 3,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(SneaselHisuian),
        ICON(SneaselHisuian, 0),
        LEARNSETS(SneaselHisuian),
        .isHisuianForm = TRUE,
        .evolutions = EVOLUTION({EVO_ITEM_HOLD_DAY, ITEM_RAZOR_CLAW, SPECIES_SNEASLER},
                                {EVO_ITEM_DAY, ITEM_RAZOR_CLAW, SPECIES_SNEASLER}),
    },

    [SPECIES_SNEASLER] =
    {
        .baseHP        = 80,
        .baseAttack    = 130,
        .baseDefense   = 60,
        .baseSpeed     = 120,
        .baseSpAttack  = 40,
        .baseSpDefense = 80,
        .types = { TYPE_FIGHTING, TYPE_POISON },
        .catchRate = 20,
        .expYield = 102,
        .evYield_Attack = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD },
        .abilities = { ABILITY_PRESSURE, ABILITY_UNBURDEN, ABILITY_POISON_TOUCH },
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Snieboss"),
        .cryId = CRY_SNEASLER,
        .natDexNum = NATIONAL_DEX_SNEASLER,
        .categoryName = _("Kletterei"),
        .height = 13,
        .weight = 430,
        .description = POKEDEX_DESC_STRING(
            "Aufgrund seines bösartigen Giftes und\n"
            "seiner beeindruckenden körperlichen Stärke\n"
            "konnte keine andere Art hoffen, es im\n"
            "gefrorenen Hochland zu übertreffen. Es"),
        .pokemonScale = 272,
        .pokemonOffset = 3,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Sneasler, 64, 64),
        .frontPicYOffset = 1,
        .frontAnimFrames = sAnims_Sneasler,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(Sneasler, 64, 64),
        .backPicYOffset = 0,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(Sneasler),
        ICON(Sneasler, 2),
        //.footprint = gMonFootprint_Sneasler,
        LEARNSETS(Sneasler),
    },
#endif //P_HISUIAN_FORMS
#endif //P_FAMILY_SNEASEL

#if P_FAMILY_TEDDIURSA
    [SPECIES_TEDDIURSA] =
    {
        .baseHP        = 60,
        .baseAttack    = 80,
        .baseDefense   = 50,
        .baseSpeed     = 40,
        .baseSpAttack  = 50,
        .baseSpDefense = 50,
        .types = { TYPE_NORMAL, TYPE_NORMAL },
        .catchRate = 120,
        .expYield = 66,
        .evYield_Attack = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD },
        .abilities = { ABILITY_PICKUP, ABILITY_QUICK_FEET, ABILITY_HONEY_GATHER },
        .bodyColor = BODY_COLOR_BROWN,
        .noFlip = TRUE,
        .speciesName = _("Teddiursa"),
        .cryId = CRY_TEDDIURSA,
        .natDexNum = NATIONAL_DEX_TEDDIURSA,
        .categoryName = _("Kleinbär"),
        .height = 6,
        .weight = 88,
        .description = POKEDEX_DESC_STRING(
            "Steht der Winter vor der Türe, hortet es\n"
            "Nahrung an vielen verschiedenen, nur ihm\n"
            "bekannten Orten."),
        .pokemonScale = 455,
        .pokemonOffset = 19,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Teddiursa, 40, 40),
        .frontPicYOffset = 12,
        .frontAnimFrames = sAnims_Teddiursa,
        .frontAnimId = ANIM_V_STRETCH,
        BACK_PIC(Teddiursa, 48, 48),
        .backPicYOffset = 10,
        .backAnimId = BACK_ANIM_DIP_RIGHT_SIDE,
        PALETTES(Teddiursa),
        ICON(Teddiursa, 0),
        .footprint = gMonFootprint_Teddiursa,
        LEARNSETS(Teddiursa),
        .evolutions = EVOLUTION({EVO_LEVEL, 30, SPECIES_URSARING}),
    },

    [SPECIES_URSARING] =
    {
        .baseHP        = 90,
        .baseAttack    = 130,
        .baseDefense   = 75,
        .baseSpeed     = 55,
        .baseSpAttack  = 75,
        .baseSpDefense = 75,
        .types = { TYPE_NORMAL, TYPE_NORMAL },
        .catchRate = 60,
        .expYield = 175,
        .evYield_Attack = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD },
        .abilities = { ABILITY_GUTS, ABILITY_QUICK_FEET, ABILITY_UNNERVE },
        .bodyColor = BODY_COLOR_BROWN,
        .speciesName = _("Ursaring"),
        .cryId = CRY_URSARING,
        .natDexNum = NATIONAL_DEX_URSARING,
        .categoryName = _("Schläfer"),
        .height = 18,
        .weight = 1258,
        .description = POKEDEX_DESC_STRING(
            "Trotz seines riesigen Körpers ist es ein\n"
            "guter Kletterer. Es frisst und schläft in\n"
            "Baumkronen."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Ursaring, 64, 64),
        FRONT_PIC_FEMALE(Ursaring, 64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_Ursaring,
        .frontAnimId = ANIM_H_SHAKE,
        BACK_PIC(Ursaring, 56, 64),
        BACK_PIC_FEMALE(Ursaring, 56, 64),
        .backPicYOffset = 2,
        .backAnimId = BACK_ANIM_V_SHAKE,
        PALETTES(Ursaring),
        ICON(Ursaring, 2),
        .footprint = gMonFootprint_Ursaring,
        LEARNSETS(Ursaring),
        .evolutions = EVOLUTION({EVO_ITEM_NIGHT, ITEM_PEAT_BLOCK, SPECIES_URSALUNA},
                                {EVO_NONE, 0, SPECIES_URSALUNA_BLOODMOON}),
    },

#if P_GEN_8_CROSS_EVOS
#define URSALUNA_MISC_INFO                                  \
        .expYield = 275,                                    \
        .types = { TYPE_GROUND, TYPE_NORMAL },              \
        .eggCycles = 20,                                    \
        .friendship = STANDARD_FRIENDSHIP,                  \
        .growthRate = GROWTH_MEDIUM_FAST,                   \
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD },  \
        .bodyColor = BODY_COLOR_BROWN,                      \
        .speciesName = _("Ursaring"),                       \
        .cryId = CRY_URSALUNA,                              \
        .natDexNum = NATIONAL_DEX_URSALUNA,                 \
        .categoryName = _("Schläfer"),                          \
        .formSpeciesIdTable = sUrsalunaFormSpeciesIdTable

    [SPECIES_URSALUNA] =
    {
        URSALUNA_MISC_INFO,
        .baseHP        = 130,
        .baseAttack    = 140,
        .baseDefense   = 105,
        .baseSpeed     = 50,
        .baseSpAttack  = 45,
        .baseSpDefense = 80,
        .catchRate = 20,
        .evYield_Attack = 3,
        .genderRatio = PERCENT_FEMALE(50),
        .abilities = { ABILITY_GUTS, ABILITY_BULLETPROOF, ABILITY_UNNERVE },
        .height = 24,
        .weight = 2900,
        .description = POKEDEX_DESC_STRING(
            "Swampy terrain gives Ursaluna its burly\n"
            "physique and newfound capacity to\n"
            "manipulate peat at will."),
        .pokemonScale = 256,
        .pokemonOffset = 3,
        .trainerScale = 369,
        .trainerOffset = 7,
        FRONT_PIC(Ursaluna, 56, 56),
        .frontPicYOffset = 2,
        .frontAnimFrames = sAnims_Ursaluna,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(Ursaluna, 64, 40),
        .backPicYOffset = 14,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(Ursaluna),
        ICON(Ursaluna, 2),
        //.footprint = gMonFootprint_Ursaluna,
        LEARNSETS(Ursaluna),
    },

    [SPECIES_URSALUNA_BLOODMOON] =
    {
        URSALUNA_MISC_INFO,
        .baseHP        = 113,
        .baseAttack    = 70,
        .baseDefense   = 120,
        .baseSpeed     = 52,
        .baseSpAttack  = 135,
        .baseSpDefense = 65,
        .catchRate = 5,
        .evYield_SpAttack = 3,
        .genderRatio = MON_MALE,
        .abilities = { ABILITY_MINDS_EYE, ABILITY_NONE },
        .height = 27,
        .weight = 3330,
        .description = POKEDEX_DESC_STRING(
            "It crossed the sea and drifted\n"
            "ashore in a new land. Surviving in this\n"
            "place led it to take on a unique\n"
            "appearance and gain special powers."),
        .pokemonScale = 256,
        .pokemonOffset = 3,
        .trainerScale = 369,
        .trainerOffset = 7,
        FRONT_PIC(UrsalunaBloodmoon, 64, 64),
        //.frontPicYOffset = 0,
        .frontAnimFrames = sAnims_UrsalunaBloodmoon,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(UrsalunaBloodmoon, 64, 40),
        .backPicYOffset = 3,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(UrsalunaBloodmoon),
        ICON(UrsalunaBloodmoon, 2),
        //.footprint = gMonFootprint_UrsalunaBloodmoon,
        LEARNSETS(UrsalunaBloodmoon),
    },
#endif //P_GEN_8_CROSS_EVOS
#endif //P_FAMILY_TEDDIURSA

#if P_FAMILY_SLUGMA
    [SPECIES_SLUGMA] =
    {
        .baseHP        = 40,
        .baseAttack    = 40,
        .baseDefense   = 40,
        .baseSpeed     = 20,
        .baseSpAttack  = 70,
        .baseSpDefense = 40,
        .types = { TYPE_FIRE, TYPE_FIRE },
        .catchRate = 190,
        .expYield = 50,
        .evYield_SpAttack = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_AMORPHOUS, EGG_GROUP_AMORPHOUS },
        .abilities = { ABILITY_MAGMA_ARMOR, ABILITY_FLAME_BODY, ABILITY_WEAK_ARMOR },
        .bodyColor = BODY_COLOR_RED,
        .speciesName = _("Schneckmag"),
        .cryId = CRY_SLUGMA,
        .natDexNum = NATIONAL_DEX_SLUGMA,
        .categoryName = _("Lava"),
        .height = 7,
        .weight = 350,
        .description = POKEDEX_DESC_STRING(
            "Sein Körper besteht aus Magma. Bleibt es\n"
            "nicht ständig in Bewegung, kühlt es aus\n"
            "und verhärtet sich."),
        .pokemonScale = 329,
        .pokemonOffset = 15,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Slugma, 32, 48),
        .frontPicYOffset = 12,
        .frontAnimFrames = sAnims_Slugma,
        .frontAnimId = ANIM_V_STRETCH,
        BACK_PIC(Slugma, 64, 56),
        .backPicYOffset = 6,
        .backAnimId = BACK_ANIM_SHAKE_GLOW_RED,
        PALETTES(Slugma),
        ICON(Slugma, 0),
        .footprint = gMonFootprint_Slugma,
        LEARNSETS(Slugma),
        .evolutions = EVOLUTION({EVO_LEVEL, 38, SPECIES_MAGCARGO}),
    },

    [SPECIES_MAGCARGO] =
    {
        .baseHP        = P_UPDATED_STATS >= GEN_7 ? 60 : 50,
        .baseAttack    = 50,
        .baseDefense   = 120,
        .baseSpeed     = 30,
        .baseSpAttack  = P_UPDATED_STATS >= GEN_7 ? 90 : 80,
        .baseSpDefense = 80,
        .types = { TYPE_FIRE, TYPE_ROCK },
        .catchRate = 75,
        .expYield = 151,
        .evYield_Defense = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_AMORPHOUS, EGG_GROUP_AMORPHOUS },
        .abilities = { ABILITY_MAGMA_ARMOR, ABILITY_FLAME_BODY, ABILITY_WEAK_ARMOR },
        .bodyColor = BODY_COLOR_RED,
        .noFlip = TRUE,
        .speciesName = _("Magcargo"),
        .cryId = CRY_MAGCARGO,
        .natDexNum = NATIONAL_DEX_MAGCARGO,
        .categoryName = _("Lava"),
        .height = 8,
        .weight = 550,
        .description = POKEDEX_DESC_STRING(
            "Sein Körper ist heißer als Lava und wogt\n"
            "stets. Manchmal schießen Flammen aus\n"
            "seinem Haus."),
        .pokemonScale = 332,
        .pokemonOffset = 15,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Magcargo, 56, 64),
        .frontPicYOffset = 6,
        .frontAnimFrames = sAnims_Magcargo,
        .frontAnimId = ANIM_V_STRETCH,
        BACK_PIC(Magcargo, 64, 56),
        .backPicYOffset = 7,
        .backAnimId = BACK_ANIM_SHAKE_GLOW_RED,
        PALETTES(Magcargo),
        ICON(Magcargo, 0),
        .footprint = gMonFootprint_Magcargo,
        LEARNSETS(Magcargo),
    },
#endif //P_FAMILY_SLUGMA

#if P_FAMILY_SWINUB
    [SPECIES_SWINUB] =
    {
        .baseHP        = 50,
        .baseAttack    = 50,
        .baseDefense   = 40,
        .baseSpeed     = 50,
        .baseSpAttack  = 30,
        .baseSpDefense = 30,
        .types = { TYPE_ICE, TYPE_GROUND },
        .catchRate = 225,
        .expYield = 50,
        .evYield_Attack = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD },
        .abilities = { ABILITY_OBLIVIOUS, ABILITY_SNOW_CLOAK, ABILITY_THICK_FAT },
        .bodyColor = BODY_COLOR_BROWN,
        .speciesName = _("Quiekel"),
        .cryId = CRY_SWINUB,
        .natDexNum = NATIONAL_DEX_SWINUB,
        .categoryName = _("Ferkel"),
        .height = 4,
        .weight = 65,
        .description = POKEDEX_DESC_STRING(
            "Auf Nahrungssuche schnüffelt es am\n"
            "Boden entlang. Es entdeckt dabei\n"
            "manchmal auch heiße Quellen."),
        .pokemonScale = 324,
        .pokemonOffset = 20,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Swinub, 40, 32),
        .frontPicYOffset = 18,
        .frontAnimFrames = sAnims_Swinub,
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(Swinub, 56, 40),
        .backPicYOffset = 15,
        .backAnimId = BACK_ANIM_V_SHAKE_H_SLIDE,
        PALETTES(Swinub),
        ICON(Swinub, 2),
        .footprint = gMonFootprint_Swinub,
        LEARNSETS(Swinub),
        .evolutions = EVOLUTION({EVO_LEVEL, 33, SPECIES_PILOSWINE}),
    },

    [SPECIES_PILOSWINE] =
    {
        .baseHP        = 100,
        .baseAttack    = 100,
        .baseDefense   = 80,
        .baseSpeed     = 50,
        .baseSpAttack  = 60,
        .baseSpDefense = 60,
        .types = { TYPE_ICE, TYPE_GROUND },
        .catchRate = 75,
        .expYield = 158,
        .evYield_HP = 1,
        .evYield_Attack = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD },
        .abilities = { ABILITY_OBLIVIOUS, ABILITY_SNOW_CLOAK, ABILITY_THICK_FAT },
        .bodyColor = BODY_COLOR_BROWN,
        .speciesName = _("Keifel"),
        .cryId = CRY_PILOSWINE,
        .natDexNum = NATIONAL_DEX_PILOSWINE,
        .categoryName = _("Schwein"),
        .height = 11,
        .weight = 558,
        .description = POKEDEX_DESC_STRING(
            "Da sein haariges Fell seine Sicht enorm\n"
            "beeinträchtigt, greift es ständig an, um\n"
            "den Gegner zu treffen."),
        .pokemonScale = 306,
        .pokemonOffset = 10,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Piloswine, 48, 56),
        FRONT_PIC_FEMALE(Piloswine, 48, 56),
        .frontPicYOffset = 8,
        .frontAnimFrames = sAnims_Piloswine,
        .frontAnimId = ANIM_H_SHAKE,
        BACK_PIC(Piloswine, 64, 48),
        BACK_PIC_FEMALE(Piloswine, 64, 48),
        .backPicYOffset = 8,
        .backAnimId = BACK_ANIM_H_SHAKE,
        PALETTES(Piloswine),
        ICON(Piloswine, 2),
        .footprint = gMonFootprint_Piloswine,
        LEARNSETS(Piloswine),
        .evolutions = EVOLUTION({EVO_MOVE, MOVE_ANCIENT_POWER, SPECIES_MAMOSWINE}),
    },

#if P_GEN_4_CROSS_EVOS
    [SPECIES_MAMOSWINE] =
    {
        .baseHP        = 110,
        .baseAttack    = 130,
        .baseDefense   = 80,
        .baseSpeed     = 80,
        .baseSpAttack  = 70,
        .baseSpDefense = 60,
        .types = { TYPE_ICE, TYPE_GROUND },
        .catchRate = 50,
        .expYield = 239,
        .evYield_Attack = 3,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD },
        .abilities = { ABILITY_OBLIVIOUS, ABILITY_SNOW_CLOAK, ABILITY_THICK_FAT },
        .bodyColor = BODY_COLOR_BROWN,
        .speciesName = _("Mamutel"),
        .cryId = CRY_MAMOSWINE,
        .natDexNum = NATIONAL_DEX_MAMOSWINE,
        .categoryName = _("Doppelstoßzahn"),
        .height = 25,
        .weight = 2910,
        .description = POKEDEX_DESC_STRING(
            "Die beeindruckenden Stoßzähne dieser\n"
            "Pokémon sind aus Eis. Nach der Eiszeit\n"
            "nahm ihre Population ab."),
        .pokemonScale = 257,
        .pokemonOffset = 6,
        .trainerScale = 423,
        .trainerOffset = 8,
        FRONT_PIC(Mamoswine, 64, 56),
        FRONT_PIC_FEMALE(Mamoswine, 64, 56),
        .frontPicYOffset = 4,
        .frontAnimFrames = sAnims_Mamoswine,
        .frontAnimId = ANIM_BACK_AND_LUNGE,
        BACK_PIC(Mamoswine, 64, 56),
        .backPicYOffset = 6,
        .backAnimId = BACK_ANIM_V_SHAKE_LOW,
        PALETTES(Mamoswine),
        ICON(Mamoswine, 2),
        .footprint = gMonFootprint_Mamoswine,
        LEARNSETS(Mamoswine),
    },
#endif //P_GEN_4_CROSS_EVOS
#endif //P_FAMILY_SWINUB

#if P_FAMILY_CORSOLA
#define CORSOLA_HP       (P_UPDATED_STATS >= GEN_7 ? 65 : 55)
#define CORSOLA_DEFENSES (P_UPDATED_STATS >= GEN_7 ? 95 : 85)

#define CORSOLA_MISC_INFO                                       \
        .catchRate = 60,                                        \
        .expYield = 144,                                        \
        .evYield_SpDefense = 1,                                 \
        .genderRatio = PERCENT_FEMALE(75),                      \
        .eggCycles = 20,                                        \
        .friendship = STANDARD_FRIENDSHIP,                      \
        .growthRate = GROWTH_FAST,                              \
        .eggGroups = { EGG_GROUP_WATER_1, EGG_GROUP_WATER_3 },  \
        .speciesName = _("Mamutel"),                            \
        .cryId = CRY_CORSOLA,                                   \
        .natDexNum = NATIONAL_DEX_CORSOLA,                      \
        .categoryName = _("Doppelstoßzahn"),                             \
        .height = 6,                                            \
        .pokemonScale = 410,                                    \
        .pokemonOffset = 15,                                    \
        .trainerScale = 256,                                    \
        .trainerOffset = 0,                                     \
        .footprint = gMonFootprint_Corsola,                     \
        .formSpeciesIdTable = sCorsolaFormSpeciesIdTable

    [SPECIES_CORSOLA] =
    {
        CORSOLA_MISC_INFO,
        .baseHP        = CORSOLA_HP,
        .baseAttack    = 55,
        .baseDefense   = CORSOLA_DEFENSES,
        .baseSpeed     = 35,
        .baseSpAttack  = 65,
        .baseSpDefense = CORSOLA_DEFENSES,
        .types = { TYPE_WATER, TYPE_ROCK },
        .evYield_Defense = 1,
        .itemRare = ITEM_LUMINOUS_MOSS,
        .abilities = { ABILITY_HUSTLE, ABILITY_NATURAL_CURE, ABILITY_REGENERATOR },
        .bodyColor = BODY_COLOR_PINK,
        .weight = 50,
        .description = POKEDEX_DESC_STRING(
            "Es häutet sich ständig und wächst.\n"
            "Seine Kopfspitze wurde als Schatz\n"
            "der Schönheit ausgezeichnet."),
        FRONT_PIC(Corsola, 48, 40),
        .frontPicYOffset = 12,
        .frontAnimFrames = sAnims_Corsola,
        .frontAnimId = ANIM_H_SLIDE,
        BACK_PIC(Corsola, 56, 48),
        .backPicYOffset = 8,
        .backAnimId = BACK_ANIM_H_SLIDE,
        PALETTES(Corsola),
        ICON(Corsola, 0),
        LEARNSETS(Corsola),
    },

#if P_GALARIAN_FORMS
    [SPECIES_CORSOLA_GALAR] =
    {
        CORSOLA_MISC_INFO,
        .baseHP        = CORSOLA_HP - 5,
        .baseAttack    = 55,
        .baseDefense   = CORSOLA_DEFENSES + 5,
        .baseSpeed     = 30,
        .baseSpAttack  = 65,
        .baseSpDefense = CORSOLA_DEFENSES + 5,
        .types = { TYPE_GHOST, TYPE_GHOST },
        .abilities = { ABILITY_WEAK_ARMOR, ABILITY_NONE, ABILITY_CURSED_BODY },
        .bodyColor = BODY_COLOR_WHITE,
        .weight = 5,
        .description = POKEDEX_DESC_STRING(
            "Es häutet sich ständig und wächst.\n"
            "Seine Kopfspitze wurde als Schatz\n"
            "der Schönheit ausgezeichnet."),
        FRONT_PIC(CorsolaGalarian, 48, 48),
        .frontPicYOffset = 11,
        .frontAnimFrames = sAnims_CorsolaGalarian,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(CorsolaGalarian, 56, 48),
        .backPicYOffset = 8,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(CorsolaGalarian),
        ICON(CorsolaGalarian, 0),
        LEARNSETS(CorsolaGalarian),
        .isGalarianForm = TRUE,
        .evolutions = EVOLUTION({EVO_LEVEL, 38, SPECIES_CURSOLA}),
    },

    [SPECIES_CURSOLA] =
    {
        .baseHP        = 60,
        .baseAttack    = 95,
        .baseDefense   = 50,
        .baseSpeed     = 30,
        .baseSpAttack  = 145,
        .baseSpDefense = 130,
        .types = { TYPE_GHOST, TYPE_GHOST },
        .catchRate = 30,
        .expYield = 179,
        .evYield_SpAttack = 2,
        .genderRatio = PERCENT_FEMALE(75),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_FAST,
        .eggGroups = { EGG_GROUP_WATER_1, EGG_GROUP_WATER_3 },
        .abilities = { ABILITY_WEAK_ARMOR, ABILITY_NONE, ABILITY_PERISH_BODY },
        .bodyColor = BODY_COLOR_WHITE,
        .speciesName = _("Gorgasonn"),
        .cryId = CRY_CURSOLA,
        .natDexNum = NATIONAL_DEX_CURSOLA,
        .categoryName = _("Korallen"),
        .height = 10,
        .weight = 4,
        .description = POKEDEX_DESC_STRING(
            "Vor dem geisterhaften Ektoplasma, das\n"
            "seine Seele umhüllt, ist Vorsicht geboten.\n"
            "Berührt man es, erstarrt man wie zu Stein."),
        .pokemonScale = 305,
        .pokemonOffset = 7,
        .trainerScale = 257,
        .trainerOffset = 0,
        FRONT_PIC(Cursola, 64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_Cursola,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(Cursola, 64, 56),
        .backPicYOffset = 5,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(Cursola),
        ICON(Cursola, 0),
        .footprint = gMonFootprint_Cursola,
        LEARNSETS(Cursola),
    },
#endif //P_GALARIAN_FORMS
#endif //P_FAMILY_CORSOLA

#if P_FAMILY_REMORAID
    [SPECIES_REMORAID] =
    {
        .baseHP        = 35,
        .baseAttack    = 65,
        .baseDefense   = 35,
        .baseSpeed     = 65,
        .baseSpAttack  = 65,
        .baseSpDefense = 35,
        .types = { TYPE_WATER, TYPE_WATER },
        .catchRate = 190,
        .expYield = 60,
        .evYield_SpAttack = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_WATER_1, EGG_GROUP_WATER_2 },
        .abilities = { ABILITY_HUSTLE, ABILITY_SNIPER, ABILITY_MOODY },
        .bodyColor = BODY_COLOR_GRAY,
        .speciesName = _("Remoraid"),
        .cryId = CRY_REMORAID,
        .natDexNum = NATIONAL_DEX_REMORAID,
        .categoryName = _("Hochdruck"),
        .height = 6,
        .weight = 120,
        .description = POKEDEX_DESC_STRING(
            "Selbst aus 100 m Entfernung treffen die\n"
            "Wassersalven, die es mit seinem Maul\n"
            "abfeuert, ihr Ziel."),
        .pokemonScale = 316,
        .pokemonOffset = 4,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Remoraid, 40, 48),
        .frontPicYOffset = 11,
        .frontAnimFrames = sAnims_Remoraid,
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE_SLOW,
        BACK_PIC(Remoraid, 56, 40),
        .backPicYOffset = 12,
        .backAnimId = BACK_ANIM_H_SLIDE,
        PALETTES(Remoraid),
        ICON(Remoraid, 0),
        .footprint = gMonFootprint_Remoraid,
        LEARNSETS(Remoraid),
        .evolutions = EVOLUTION({EVO_LEVEL, 25, SPECIES_OCTILLERY}),
    },

    [SPECIES_OCTILLERY] =
    {
        .baseHP        = 75,
        .baseAttack    = 105,
        .baseDefense   = 75,
        .baseSpeed     = 45,
        .baseSpAttack  = 105,
        .baseSpDefense = 75,
        .types = { TYPE_WATER, TYPE_WATER },
        .catchRate = 75,
        .expYield = 168,
        .evYield_Attack = 1,
        .evYield_SpAttack = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_WATER_1, EGG_GROUP_WATER_2 },
        .abilities = { ABILITY_SUCTION_CUPS, ABILITY_SNIPER, ABILITY_MOODY },
        .bodyColor = BODY_COLOR_RED,
        .speciesName = _("Octillery"),
        .cryId = CRY_OCTILLERY,
        .natDexNum = NATIONAL_DEX_OCTILLERY,
        .categoryName = _("Hochdruck"),
        .height = 9,
        .weight = 285,
        .description = POKEDEX_DESC_STRING(
            "Beim Beutefang setzt es seine Tentakel\n"
            "ein. Es zermalmt seine Beute mit seinem\n"
            "steinharten Kopf."),
        .pokemonScale = 296,
        .pokemonOffset = 3,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Octillery, 56, 48),
        FRONT_PIC_FEMALE(Octillery, 56, 48),
        .frontPicYOffset = 8,
        .frontAnimFrames = sAnims_Octillery,
        .frontAnimId = ANIM_V_STRETCH,
        .frontAnimDelay = 20,
        BACK_PIC(Octillery, 64, 56),
        BACK_PIC_FEMALE(Octillery, 64, 56),
        .backPicYOffset = 8,
        .backAnimId = BACK_ANIM_SHRINK_GROW,
        PALETTES(Octillery),
        ICON(Octillery, 0),
        .footprint = gMonFootprint_Octillery,
        LEARNSETS(Octillery),
    },
#endif //P_FAMILY_REMORAID

#if P_FAMILY_DELIBIRD
    [SPECIES_DELIBIRD] =
    {
        .baseHP        = 45,
        .baseAttack    = 55,
        .baseDefense   = 45,
        .baseSpeed     = 75,
        .baseSpAttack  = 65,
        .baseSpDefense = 45,
        .types = { TYPE_ICE, TYPE_FLYING },
        .catchRate = 45,
        .expYield = 116,
        .evYield_Speed = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_FAST,
        .eggGroups = { EGG_GROUP_WATER_1, EGG_GROUP_FIELD },
        .abilities = { ABILITY_VITAL_SPIRIT, ABILITY_HUSTLE, ABILITY_INSOMNIA },
        .bodyColor = BODY_COLOR_RED,
        .speciesName = _("Botogel"),
        .cryId = CRY_DELIBIRD,
        .natDexNum = NATIONAL_DEX_DELIBIRD,
        .categoryName = _("Lieferanten"),
        .height = 9,
        .weight = 160,
        .description = POKEDEX_DESC_STRING(
            "Im eingerollten Schweif\n"
            "transportiert es Futter, das es mit\n"
            "denen teilt, die sich verlaufen\n"
            "haben."),
        .pokemonScale = 293,
        .pokemonOffset = 11,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Delibird, 48, 56),
        .frontPicYOffset = 7,
        .frontAnimFrames = sAnims_Delibird,
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(Delibird, 56, 56),
        .backPicYOffset = 6,
        .backAnimId = BACK_ANIM_TRIANGLE_DOWN,
        PALETTES(Delibird),
        ICON(Delibird, 1),
        .footprint = gMonFootprint_Delibird,
        LEARNSETS(Delibird),
    },
#endif //P_FAMILY_DELIBIRD

#if P_FAMILY_MANTINE
#if P_GEN_4_CROSS_EVOS
    [SPECIES_MANTYKE] =
    {
        .baseHP        = 45,
        .baseAttack    = 20,
        .baseDefense   = 50,
        .baseSpeed     = 50,
        .baseSpAttack  = 60,
        .baseSpDefense = 120,
        .types = { TYPE_WATER, TYPE_FLYING },
        .catchRate = 25,
        .expYield = 69,
        .evYield_SpDefense = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 25,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_NO_EGGS_DISCOVERED, EGG_GROUP_NO_EGGS_DISCOVERED },
        .abilities = { ABILITY_SWIFT_SWIM, ABILITY_WATER_ABSORB, ABILITY_WATER_VEIL },
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Mantirps"),
        .cryId = CRY_MANTYKE,
        .natDexNum = NATIONAL_DEX_MANTYKE,
        .categoryName = _("Flugrochen"),
        .height = 10,
        .weight = 650,
        .description = POKEDEX_DESC_STRING(
            "Da es nah an der Meeresoberfläche\n"
            "schwimmt, kann man sein Rückenmuster von\n"
            "Schiffen aus erspähen."),
        .pokemonScale = 305,
        .pokemonOffset = 7,
        .trainerScale = 257,
        .trainerOffset = 0,
        FRONT_PIC(Mantyke, 48, 48),
        .frontPicYOffset = 12,
        .frontAnimFrames = sAnims_Mantyke,
        .frontAnimId = ANIM_TWIST_TWICE,
        BACK_PIC(Mantyke, 64, 56),
        .backPicYOffset = 6,
        .backAnimId = BACK_ANIM_CONVEX_DOUBLE_ARC,
        PALETTES(Mantyke),
        ICON(Mantyke, 0),
        .footprint = gMonFootprint_Mantyke,
        LEARNSETS(Mantyke),
        .evolutions = EVOLUTION({EVO_SPECIFIC_MON_IN_PARTY, SPECIES_REMORAID, SPECIES_MANTINE}),
    },
#endif //P_GEN_4_CROSS_EVOS

    [SPECIES_MANTINE] =
    {
        .baseHP        = P_UPDATED_STATS >= GEN_7 ? 85 : 65,
        .baseAttack    = 40,
        .baseDefense   = 70,
        .baseSpeed     = 70,
        .baseSpAttack  = 80,
        .baseSpDefense = 140,
        .types = { TYPE_WATER, TYPE_FLYING },
        .catchRate = 25,
        .expYield = 170,
        .evYield_SpDefense = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 25,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_WATER_1, EGG_GROUP_WATER_1 },
        .abilities = { ABILITY_SWIFT_SWIM, ABILITY_WATER_ABSORB, ABILITY_WATER_VEIL },
        .bodyColor = BODY_COLOR_PURPLE,
        .speciesName = _("Mantax"),
        .cryId = CRY_MANTINE,
        .natDexNum = NATIONAL_DEX_MANTINE,
        .categoryName = _("Flugrochen"),
        .height = 21,
        .weight = 2200,
        .description = POKEDEX_DESC_STRING(
            "Zieht elegant durch die Meere und\n"
            "ignoriert dabei Remoraid, die an seinen\n"
            "Flossen haften."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 342,
        .trainerOffset = 7,
        FRONT_PIC(Mantine, 64, 56),
        .frontPicYOffset = 9,
        .frontAnimFrames = sAnims_Mantine,
        .frontAnimId = ANIM_SWING_CONVEX,
        .enemyMonElevation = 6,
        BACK_PIC(Mantine, 64, 64),
        .backPicYOffset = 2,
        .backAnimId = BACK_ANIM_H_SLIDE,
        PALETTES(Mantine),
        ICON(Mantine, 2),
        .footprint = gMonFootprint_Mantine,
        LEARNSETS(Mantine),
    },
#endif //P_FAMILY_MANTINE

#if P_FAMILY_SKARMORY
    [SPECIES_SKARMORY] =
    {
        .baseHP        = 65,
        .baseAttack    = 80,
        .baseDefense   = 140,
        .baseSpeed     = 70,
        .baseSpAttack  = 40,
        .baseSpDefense = 70,
        .types = { TYPE_STEEL, TYPE_FLYING },
        .catchRate = 25,
        .expYield = 163,
        .evYield_Defense = 2,
        .itemRare = ITEM_METAL_COAT,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 25,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_FLYING, EGG_GROUP_FLYING },
        .abilities = { ABILITY_KEEN_EYE, ABILITY_STURDY, ABILITY_WEAK_ARMOR },
        .bodyColor = BODY_COLOR_GRAY,
        .speciesName = _("Panzaeron"),
        .cryId = CRY_SKARMORY,
        .natDexNum = NATIONAL_DEX_SKARMORY,
        .categoryName = _("Flugstahl"),
        .height = 17,
        .weight = 505,
        .description = POKEDEX_DESC_STRING(
            "Es wird komplett von einer eisenharten\n"
            "Rüstung geschützt. Wenn es fliegt,\n"
            "erreicht es bis zu 300 km/h."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 271,
        .trainerOffset = 1,
        FRONT_PIC(Skarmory, 64, 64),
        .frontPicYOffset = 1,
        .frontAnimFrames = sAnims_Skarmory,
        .frontAnimId = ANIM_V_SHAKE,
        BACK_PIC(Skarmory, 48, 64),
        .backPicYOffset = 1,
        .backAnimId = BACK_ANIM_JOLT_RIGHT,
        PALETTES(Skarmory),
        ICON(Skarmory, 0),
        .footprint = gMonFootprint_Skarmory,
        LEARNSETS(Skarmory),
    },
#endif //P_FAMILY_SKARMORY

#if P_FAMILY_HOUNDOUR
    [SPECIES_HOUNDOUR] =
    {
        .baseHP        = 45,
        .baseAttack    = 60,
        .baseDefense   = 30,
        .baseSpeed     = 65,
        .baseSpAttack  = 80,
        .baseSpDefense = 50,
        .types = { TYPE_DARK, TYPE_FIRE },
        .catchRate = 120,
        .expYield = 66,
        .evYield_SpAttack = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = 35,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD },
        .abilities = { ABILITY_EARLY_BIRD, ABILITY_FLASH_FIRE, ABILITY_UNNERVE },
        .bodyColor = BODY_COLOR_BLACK,
        .speciesName = _("Hunduster"),
        .cryId = CRY_HOUNDOUR,
        .natDexNum = NATIONAL_DEX_HOUNDOUR,
        .categoryName = _("Hades"),
        .height = 6,
        .weight = 108,
        .description = POKEDEX_DESC_STRING(
            "Sie treiben ihre Beute in die Enge und\n"
            "orientieren sich dabei anhand ihres\n"
            "Bellens, das nur sie verstehen."),
        .pokemonScale = 393,
        .pokemonOffset = 16,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Houndour, 40, 48),
        .frontPicYOffset = 9,
        .frontAnimFrames = sAnims_Houndour,
        .frontAnimId = ANIM_V_STRETCH,
        BACK_PIC(Houndour, 40, 48),
        .backPicYOffset = 10,
        .backAnimId = BACK_ANIM_V_SHAKE,
        PALETTES(Houndour),
        ICON(Houndour, 0),
        .footprint = gMonFootprint_Houndour,
        LEARNSETS(Houndour),
        .evolutions = EVOLUTION({EVO_LEVEL, 24, SPECIES_HOUNDOOM}),
    },

#define HOUNDOOM_MISC_INFO                                  \
        .types = { TYPE_DARK, TYPE_FIRE },                  \
        .catchRate = 45,                                    \
        .evYield_SpAttack = 2,                              \
        .genderRatio = PERCENT_FEMALE(50),                  \
        .eggCycles = 20,                                    \
        .friendship = 35,                                   \
        .growthRate = GROWTH_SLOW,                          \
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD },  \
        .bodyColor = BODY_COLOR_BLACK,                      \
        .speciesName = _("Hunduster"),                       \
        .natDexNum = NATIONAL_DEX_HOUNDOOM,                 \
        .categoryName = _("Hades"),                          \
        .footprint = gMonFootprint_Houndoom,                \
        LEARNSETS(Houndoom),                                \
        .formSpeciesIdTable = sHoundoomFormSpeciesIdTable,  \
        .formChangeTable = sHoundoomFormChangeTable

    [SPECIES_HOUNDOOM] =
    {
        HOUNDOOM_MISC_INFO,
        .baseHP        = 75,
        .baseAttack    = 90,
        .baseDefense   = 50,
        .baseSpeed     = 95,
        .baseSpAttack  = 110,
        .baseSpDefense = 80,
        .expYield = 175,
        .abilities = { ABILITY_EARLY_BIRD, ABILITY_FLASH_FIRE, ABILITY_UNNERVE },
        .cryId = CRY_HOUNDOOM,
        .height = 14,
        .weight = 350,
        .description = POKEDEX_DESC_STRING(
            "In alten Zeiten glaubte man, das\n"
            "Heulen dieses Pokémon sei der Ruf\n"
            "des Todes."),
        .pokemonScale = 256,
        .pokemonOffset = 4,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Houndoom, 64, 64),
        FRONT_PIC_FEMALE(Houndoom, 64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_Houndoom,
        .frontAnimId = ANIM_V_SHAKE,
        BACK_PIC(Houndoom, 64, 56),
        BACK_PIC_FEMALE(Houndoom, 64, 56),
        .backPicYOffset = 6,
        .backAnimId = BACK_ANIM_V_SHAKE,
        PALETTES(Houndoom),
        ICON(Houndoom, 0),
    },

#if P_MEGA_EVOLUTIONS
    [SPECIES_HOUNDOOM_MEGA] =
    {
        HOUNDOOM_MISC_INFO,
        .baseHP        = 75,
        .baseAttack    = 90,
        .baseDefense   = 90,
        .baseSpeed     = 115,
        .baseSpAttack  = 140,
        .baseSpDefense = 90,
        .expYield = 210,
        .abilities = { ABILITY_SOLAR_POWER, ABILITY_SOLAR_POWER, ABILITY_SOLAR_POWER },
        .cryId = CRY_HOUNDOOM_MEGA,
        .height = 19,
        .weight = 495,
        .description = POKEDEX_DESC_STRING(
            "In alten Zeiten glaubte man, das\n"
            "Heulen dieses Pokémon sei der Ruf\n"
            "des Todes."),
        .pokemonScale = 256,
        .pokemonOffset = 4,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(HoundoomMega, 64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_HoundoomMega,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(HoundoomMega, 64, 64),
        .backPicYOffset = 0,
        .backAnimId = BACK_ANIM_V_SHAKE,
        PALETTES(HoundoomMega),
        ICON(HoundoomMega, 0),
        .isMegaEvolution = TRUE,
    },
#endif //P_MEGA_EVOLUTIONS
#endif //P_FAMILY_HOUNDOUR

#if P_FAMILY_PHANPY
    [SPECIES_PHANPY] =
    {
        .baseHP        = 90,
        .baseAttack    = 60,
        .baseDefense   = 60,
        .baseSpeed     = 40,
        .baseSpAttack  = 40,
        .baseSpDefense = 40,
        .types = { TYPE_GROUND, TYPE_GROUND },
        .catchRate = 120,
        .expYield = 66,
        .evYield_HP = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD },
        .abilities = { ABILITY_PICKUP, ABILITY_NONE, ABILITY_SAND_VEIL },
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Phanpy"),
        .cryId = CRY_PHANPY,
        .natDexNum = NATIONAL_DEX_PHANPY,
        .categoryName = _("Langrüssel"),
        .height = 5,
        .weight = 335,
        .description = POKEDEX_DESC_STRING(
            "Als Zeichen seiner Zuneigung stupst\n"
            "es dich mit dem Rüssel, was dich\n"
            "aber buchstäblich umwerfen könnte."),
        .pokemonScale = 465,
        .pokemonOffset = 21,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Phanpy, 40, 32),
        .frontPicYOffset = 16,
        .frontAnimFrames = sAnims_Phanpy,
        .frontAnimId = ANIM_H_JUMPS_V_STRETCH,
        BACK_PIC(Phanpy, 56, 40),
        .backPicYOffset = 12,
        .backAnimId = BACK_ANIM_JOLT_RIGHT,
        PALETTES(Phanpy),
        ICON(Phanpy, 0),
        .footprint = gMonFootprint_Phanpy,
        LEARNSETS(Phanpy),
        .evolutions = EVOLUTION({EVO_LEVEL, 25, SPECIES_DONPHAN}),
    },

    [SPECIES_DONPHAN] =
    {
        .baseHP        = 90,
        .baseAttack    = 120,
        .baseDefense   = 120,
        .baseSpeed     = 50,
        .baseSpAttack  = 60,
        .baseSpDefense = 60,
        .types = { TYPE_GROUND, TYPE_GROUND },
        .catchRate = 60,
        .expYield = 175,
        .evYield_Attack = 1,
        .evYield_Defense = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD },
        .abilities = { ABILITY_STURDY, ABILITY_NONE, ABILITY_SAND_VEIL },
        .bodyColor = BODY_COLOR_GRAY,
        .speciesName = _("Donphan"),
        .cryId = CRY_DONPHAN,
        .natDexNum = NATIONAL_DEX_DONPHAN,
        .categoryName = _("Panzer"),
        .height = 11,
        .weight = 1200,
        .description = POKEDEX_DESC_STRING(
            "Je größer und länger die Stoßzähne, desto\n"
            "höher ist ihr Rang in der Herde, doch das\n"
            "dauert lange."),
        .pokemonScale = 313,
        .pokemonOffset = 9,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Donphan, 64, 48),
        FRONT_PIC_FEMALE(Donphan, 64, 48),
        .frontPicYOffset = 9,
        .frontAnimFrames = sAnims_Donphan,
        .frontAnimId = ANIM_ROTATE_UP_SLAM_DOWN,
        BACK_PIC(Donphan, 64, 48),
        BACK_PIC_FEMALE(Donphan, 64, 48),
        .backPicYOffset = 9,
        .backAnimId = BACK_ANIM_V_SHAKE_LOW,
        PALETTES(Donphan),
        ICON(Donphan, 0),
        .footprint = gMonFootprint_Donphan,
        LEARNSETS(Donphan),
    },
#endif //P_FAMILY_PHANPY

#if P_FAMILY_STANTLER
    [SPECIES_STANTLER] =
    {
        .baseHP        = 73,
        .baseAttack    = 95,
        .baseDefense   = 62,
        .baseSpeed     = 85,
        .baseSpAttack  = 85,
        .baseSpDefense = 65,
        .types = { TYPE_NORMAL, TYPE_NORMAL },
        .catchRate = 45,
        .expYield = 163,
        .evYield_Attack = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD },
        .abilities = { ABILITY_INTIMIDATE, ABILITY_FRISK, ABILITY_SAP_SIPPER },
        .bodyColor = BODY_COLOR_BROWN,
        .speciesName = _("Damhirplex"),
        .cryId = CRY_STANTLER,
        .natDexNum = NATIONAL_DEX_STANTLER,
        .categoryName = _("Vielender"),
        .height = 14,
        .weight = 712,
        .description = POKEDEX_DESC_STRING(
            "Sein gebogenes Geweih generiert via\n"
            "Luftänderung einen Raum, in dem die\n"
            "Wirklichkeit verzerrt wird."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Stantler, 48, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_Stantler,
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(Stantler, 64, 64),
        .backPicYOffset = 1,
        .backAnimId = BACK_ANIM_DIP_RIGHT_SIDE,
        PALETTES(Stantler),
        ICON(Stantler, 2),
        .footprint = gMonFootprint_Stantler,
        LEARNSETS(Stantler),
        .evolutions = EVOLUTION({EVO_MOVE, MOVE_PSYSHIELD_BASH, SPECIES_WYRDEER}),
    },

#if P_GEN_8_CROSS_EVOS
    [SPECIES_WYRDEER] =
    {
        .baseHP        = 103,
        .baseAttack    = 105,
        .baseDefense   = 72,
        .baseSpeed     = 65,
        .baseSpAttack  = 105,
        .baseSpDefense = 75,
        .types = { TYPE_NORMAL, TYPE_PSYCHIC },
        .catchRate = 45,
        .expYield = 263,
        .evYield_Attack = 1,
        .evYield_SpAttack = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD },
        .abilities = { ABILITY_INTIMIDATE, ABILITY_FRISK, ABILITY_SAP_SIPPER },
        .bodyColor = BODY_COLOR_GRAY,
        .speciesName = _("Damythir"),
        .cryId = CRY_WYRDEER,
        .natDexNum = NATIONAL_DEX_WYRDEER,
        .categoryName = _("Vielender"),
        .height = 18,
        .weight = 951,
        .description = POKEDEX_DESC_STRING(
            "Die schwarzen Kugeln erstrahlen in einem\n"
            "unheimlichen Licht, wenn sie unsichtbare\n"
            "Barrieren errichten. Das vom Bart\n"
            "abgeworfene Fell speichert die Wärme"),
        .pokemonScale = 267,
        .pokemonOffset = 2,
        .trainerScale = 286,
        .trainerOffset = 1,
        FRONT_PIC(Wyrdeer, 64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_Wyrdeer,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(Wyrdeer, 64, 64),
        .backPicYOffset = 0,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(Wyrdeer),
        ICON(Wyrdeer, 2),
        //.footprint = gMonFootprint_Wyrdeer,
        LEARNSETS(Wyrdeer),
    },
#endif //P_GEN_8_CROSS_EVOS
#endif //P_FAMILY_STANTLER

#if P_FAMILY_SMEARGLE
    [SPECIES_SMEARGLE] =
    {
        .baseHP        = 55,
        .baseAttack    = 20,
        .baseDefense   = 35,
        .baseSpeed     = 75,
        .baseSpAttack  = 20,
        .baseSpDefense = 45,
        .types = { TYPE_NORMAL, TYPE_NORMAL },
        .catchRate = 45,
        .expYield = 88,
        .evYield_Speed = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_FAST,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD },
        .abilities = { ABILITY_OWN_TEMPO, ABILITY_TECHNICIAN, ABILITY_MOODY },
        .bodyColor = BODY_COLOR_WHITE,
        .speciesName = _("Farbeagle"),
        .cryId = CRY_SMEARGLE,
        .natDexNum = NATIONAL_DEX_SMEARGLE,
        .categoryName = _("Maler"),
        .height = 12,
        .weight = 580,
        .description = POKEDEX_DESC_STRING(
            "Ist es erwachsen, lässt es sich gern von\n"
            "seinen Kameraden Fußabdrücke auf den\n"
            "Rücken setzen."),
        .pokemonScale = 287,
        .pokemonOffset = 5,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Smeargle, 64, 56),
        .frontPicYOffset = 6,
        .frontAnimFrames = sAnims_Smeargle,
        .frontAnimId = ANIM_H_JUMPS_V_STRETCH,
        BACK_PIC(Smeargle, 56, 48),
        .backPicYOffset = 9,
        .backAnimId = BACK_ANIM_H_SLIDE,
        PALETTES(Smeargle),
        ICON(Smeargle, 1),
        .footprint = gMonFootprint_Smeargle,
        LEARNSETS(Smeargle),
    },
#endif //P_FAMILY_SMEARGLE

#if P_FAMILY_MILTANK
    [SPECIES_MILTANK] =
    {
        .baseHP        = 95,
        .baseAttack    = 80,
        .baseDefense   = 105,
        .baseSpeed     = 100,
        .baseSpAttack  = 40,
        .baseSpDefense = 70,
        .types = { TYPE_NORMAL, TYPE_NORMAL },
        .catchRate = 45,
        .expYield = 172,
        .evYield_Defense = 2,
        .itemCommon = ITEM_MOOMOO_MILK,
        .itemRare = ITEM_MOOMOO_MILK,
        .genderRatio = MON_FEMALE,
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD },
        .abilities = { ABILITY_THICK_FAT, ABILITY_SCRAPPY, ABILITY_SAP_SIPPER },
        .bodyColor = BODY_COLOR_PINK,
        .speciesName = _("Miltank"),
        .cryId = CRY_MILTANK,
        .natDexNum = NATIONAL_DEX_MILTANK,
        .categoryName = _("Milchkuh"),
        .height = 12,
        .weight = 755,
        .description = POKEDEX_DESC_STRING(
            "Wenn es gerade ein Junges hat, dann\n"
            "enthält seine Milch mehr Nährstoffe\n"
            "als gewöhnlich."),
        .pokemonScale = 280,
        .pokemonOffset = 5,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Miltank, 64, 48),
        .frontPicYOffset = 8,
        .frontAnimFrames = sAnims_Miltank,
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE_SLOW,
        BACK_PIC(Miltank, 64, 56),
        .backPicYOffset = 6,
        .backAnimId = BACK_ANIM_H_SLIDE,
        PALETTES(Miltank),
        ICON(Miltank, 0),
        .footprint = gMonFootprint_Miltank,
        LEARNSETS(Miltank),
    },
#endif //P_FAMILY_MILTANK

#if P_FAMILY_RAIKOU
    [SPECIES_RAIKOU] =
    {
        .baseHP        = 90,
        .baseAttack    = 85,
        .baseDefense   = 75,
        .baseSpeed     = 115,
        .baseSpAttack  = 115,
        .baseSpDefense = 100,
        .types = { TYPE_ELECTRIC, TYPE_ELECTRIC },
        .catchRate = 3,
        .expYield = 261,
        .evYield_Speed = 2,
        .evYield_SpAttack = 1,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 80,
        .friendship = 35,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_NO_EGGS_DISCOVERED, EGG_GROUP_NO_EGGS_DISCOVERED },
        #if P_UPDATED_ABILITIES >= GEN_7
            .abilities = { ABILITY_PRESSURE, ABILITY_NONE, ABILITY_INNER_FOCUS },
        #else
            .abilities = { ABILITY_PRESSURE, ABILITY_NONE, ABILITY_VOLT_ABSORB },
        #endif
        .bodyColor = BODY_COLOR_YELLOW,
        .isLegendary = TRUE,
        .speciesName = _("Raikou"),
        .cryId = CRY_RAIKOU,
        .natDexNum = NATIONAL_DEX_RAIKOU,
        .categoryName = _("Donner"),
        .height = 19,
        .weight = 1780,
        .description = POKEDEX_DESC_STRING(
            "Dieses aggressive Pokémon speichert\n"
            "Energie in seinem Körper und entlädt sie,\n"
            "wenn es über das Land streift."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 345,
        .trainerOffset = 7,
        FRONT_PIC(Raikou, 64, 56),
        .frontPicYOffset = 5,
        .frontAnimFrames = sAnims_Raikou,
        .frontAnimId = ANIM_V_STRETCH,
        BACK_PIC(Raikou, 64, 56),
        .backPicYOffset = 6,
        .backAnimId = BACK_ANIM_SHAKE_FLASH_YELLOW,
        PALETTES(Raikou),
        ICON(Raikou, 2),
        .footprint = gMonFootprint_Raikou,
        LEARNSETS(Raikou),
    },
#endif //P_FAMILY_RAIKOU

#if P_FAMILY_ENTEI
    [SPECIES_ENTEI] =
    {
        .baseHP        = 115,
        .baseAttack    = 115,
        .baseDefense   = 85,
        .baseSpeed     = 100,
        .baseSpAttack  = 90,
        .baseSpDefense = 75,
        .types = { TYPE_FIRE, TYPE_FIRE },
        .catchRate = 3,
        .expYield = 261,
        .evYield_HP = 1,
        .evYield_Attack = 2,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 80,
        .friendship = 35,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_NO_EGGS_DISCOVERED, EGG_GROUP_NO_EGGS_DISCOVERED },
        #if P_UPDATED_ABILITIES >= GEN_7
            .abilities = { ABILITY_PRESSURE, ABILITY_NONE, ABILITY_INNER_FOCUS },
        #else
            .abilities = { ABILITY_PRESSURE, ABILITY_NONE, ABILITY_FLASH_FIRE },
        #endif
        .bodyColor = BODY_COLOR_BROWN,
        .isLegendary = TRUE,
        .speciesName = _("Entei"),
        .cryId = CRY_ENTEI,
        .natDexNum = NATIONAL_DEX_ENTEI,
        .categoryName = _("Vulkan"),
        .height = 21,
        .weight = 1980,
        .description = POKEDEX_DESC_STRING(
            "Man sagt, wenn es brüllt, bricht irgendwo\n"
            "in der Welt ein Vulkan aus."),
        .pokemonScale = 259,
        .pokemonOffset = 0,
        .trainerScale = 345,
        .trainerOffset = 7,
        FRONT_PIC(Entei, 64, 64),
        .frontPicYOffset = 2,
        .frontAnimFrames = sAnims_Entei,
        .frontAnimId = ANIM_GROW_VIBRATE,
        BACK_PIC(Entei, 64, 48),
        .backPicYOffset = 11,
        .backAnimId = BACK_ANIM_SHAKE_GLOW_RED,
        PALETTES(Entei),
        ICON(Entei, 2),
        .footprint = gMonFootprint_Entei,
        LEARNSETS(Entei),
    },
#endif //P_FAMILY_ENTEI

#if P_FAMILY_SUICUNE
    [SPECIES_SUICUNE] =
    {
        .baseHP        = 100,
        .baseAttack    = 75,
        .baseDefense   = 115,
        .baseSpeed     = 85,
        .baseSpAttack  = 90,
        .baseSpDefense = 115,
        .types = { TYPE_WATER, TYPE_WATER },
        .catchRate = 3,
        .expYield = 261,
        .evYield_Defense = 1,
        .evYield_SpDefense = 2,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 80,
        .friendship = 35,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_NO_EGGS_DISCOVERED, EGG_GROUP_NO_EGGS_DISCOVERED },
        #if P_UPDATED_ABILITIES >= GEN_7
            .abilities = { ABILITY_PRESSURE, ABILITY_NONE, ABILITY_INNER_FOCUS },
        #else
            .abilities = { ABILITY_PRESSURE, ABILITY_NONE, ABILITY_WATER_ABSORB },
        #endif
        .bodyColor = BODY_COLOR_BLUE,
        .isLegendary = TRUE,
        .speciesName = _("Suicune"),
        .cryId = CRY_SUICUNE,
        .natDexNum = NATIONAL_DEX_SUICUNE,
        .categoryName = _("Polarlicht"),
        .height = 20,
        .weight = 1870,
        .description = POKEDEX_DESC_STRING(
            "Man sagt, es sei die Wiedergeburt des\n"
            "Nordwindes. Es kann verschmutztes Wasser\n"
            "im Nu reinigen."),
        .pokemonScale = 269,
        .pokemonOffset = 0,
        .trainerScale = 345,
        .trainerOffset = 7,
        FRONT_PIC(Suicune, 64, 64),
        .frontPicYOffset = 3,
        .frontAnimFrames = sAnims_Suicune,
        .frontAnimId = ANIM_V_SHAKE,
        BACK_PIC(Suicune, 64, 64),
        .backPicYOffset = 3,
        .backAnimId = BACK_ANIM_SHAKE_GLOW_BLUE,
        PALETTES(Suicune),
        ICON(Suicune, 2),
        .footprint = gMonFootprint_Suicune,
        LEARNSETS(Suicune),
    },
#endif //P_FAMILY_SUICUNE

#if P_FAMILY_LARVITAR
    [SPECIES_LARVITAR] =
    {
        .baseHP        = 50,
        .baseAttack    = 64,
        .baseDefense   = 50,
        .baseSpeed     = 41,
        .baseSpAttack  = 45,
        .baseSpDefense = 50,
        .types = { TYPE_ROCK, TYPE_GROUND },
        .catchRate = 45,
        .expYield = 60,
        .evYield_Attack = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 40,
        .friendship = 35,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_MONSTER, EGG_GROUP_MONSTER },
        .abilities = { ABILITY_GUTS, ABILITY_NONE, ABILITY_SAND_VEIL },
        .bodyColor = BODY_COLOR_GREEN,
        .speciesName = _("Larvitar"),
        .cryId = CRY_LARVITAR,
        .natDexNum = NATIONAL_DEX_LARVITAR,
        .categoryName = _("Felshaut"),
        .height = 6,
        .weight = 720,
        .description = POKEDEX_DESC_STRING(
            "Es wächst durch die Nährstoffe im Boden.\n"
            "Wenn es ungefähr einen ganzen Berg Erde\n"
            "gefressen hat, verpuppt es sich."),
        .pokemonScale = 472,
        .pokemonOffset = 18,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Larvitar, 40, 48),
        .frontPicYOffset = 10,
        .frontAnimFrames = sAnims_Larvitar,
        .frontAnimId = ANIM_V_JUMPS_SMALL,
        BACK_PIC(Larvitar, 56, 64),
        .backPicYOffset = 8,
        .backAnimId = BACK_ANIM_V_SHAKE_LOW,
        PALETTES(Larvitar),
        ICON(Larvitar, 1),
        .footprint = gMonFootprint_Larvitar,
        LEARNSETS(Larvitar),
        .evolutions = EVOLUTION({EVO_LEVEL, 30, SPECIES_PUPITAR}),
    },

    [SPECIES_PUPITAR] =
    {
        .baseHP        = 70,
        .baseAttack    = 84,
        .baseDefense   = 70,
        .baseSpeed     = 51,
        .baseSpAttack  = 65,
        .baseSpDefense = 70,
        .types = { TYPE_ROCK, TYPE_GROUND },
        .catchRate = 45,
        .expYield = 144,
        .evYield_Attack = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 40,
        .friendship = 35,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_MONSTER, EGG_GROUP_MONSTER },
        .abilities = { ABILITY_SHED_SKIN, ABILITY_NONE },
        .bodyColor = BODY_COLOR_GRAY,
        .speciesName = _("Pupitar"),
        .cryId = CRY_PUPITAR,
        .natDexNum = NATIONAL_DEX_PUPITAR,
        .categoryName = _("Hartschalen"),
        .height = 12,
        .weight = 1520,
        .description = POKEDEX_DESC_STRING(
            "Trotz seiner harten Schale kann es sich\n"
            "frei bewegen. Es ist flink und äußerst\n"
            "zerstörerisch."),
        .pokemonScale = 292,
        .pokemonOffset = 8,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Pupitar, 40, 48),
        .frontPicYOffset = 11,
        .frontAnimFrames = sAnims_Pupitar,
        .frontAnimId = ANIM_H_SHAKE,
        BACK_PIC(Pupitar, 48, 56),
        .backPicYOffset = 9,
        .backAnimId = BACK_ANIM_V_SHAKE,
        PALETTES(Pupitar),
        ICON(Pupitar, 2),
        .footprint = gMonFootprint_Pupitar,
        LEARNSETS(Pupitar),
        .evolutions = EVOLUTION({EVO_LEVEL, 55, SPECIES_TYRANITAR}),
    },

#define TYRANITAR_MISC_INFO                                     \
        .types = { TYPE_ROCK, TYPE_DARK },                      \
        .catchRate = 45,                                        \
        .evYield_Attack = 3,                                    \
        .genderRatio = PERCENT_FEMALE(50),                      \
        .eggCycles = 40,                                        \
        .friendship = 35,                                       \
        .growthRate = GROWTH_SLOW,                              \
        .eggGroups = { EGG_GROUP_MONSTER, EGG_GROUP_MONSTER },  \
        .bodyColor = BODY_COLOR_GREEN,                          \
        .speciesName = _("Pupitar"),                          \
        .natDexNum = NATIONAL_DEX_TYRANITAR,                    \
        .categoryName = _("Hartschalen"),                             \
        .footprint = gMonFootprint_Tyranitar,                   \
        LEARNSETS(Tyranitar),                                   \
        .formSpeciesIdTable = sTyranitarFormSpeciesIdTable,     \
        .formChangeTable = sTyranitarFormChangeTable

    [SPECIES_TYRANITAR] =
    {
        TYRANITAR_MISC_INFO,
        .baseHP        = 100,
        .baseAttack    = 134,
        .baseDefense   = 110,
        .baseSpeed     = 61,
        .baseSpAttack  = 95,
        .baseSpDefense = 100,
        .expYield = 270,
        .abilities = { ABILITY_SAND_STREAM, ABILITY_NONE, ABILITY_UNNERVE },
        .cryId = CRY_TYRANITAR,
        .height = 20,
        .weight = 2020,
        .description = POKEDEX_DESC_STRING(
            "Es besitzt so viel Kraft, dass es\n"
            "mit nur einer Hand die Erde beben\n"
            "lassen und Berge zerbröckeln kann."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 345,
        .trainerOffset = 7,
        FRONT_PIC(Tyranitar, 64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_Tyranitar,
        .frontAnimId = ANIM_V_SHAKE,
        .frontAnimDelay = 10,
        BACK_PIC(Tyranitar, 64, 64),
        .backPicYOffset = 1,
        .backAnimId = BACK_ANIM_V_SHAKE_LOW,
        PALETTES(Tyranitar),
        ICON(Tyranitar, 4),
    },

#if P_MEGA_EVOLUTIONS
    [SPECIES_TYRANITAR_MEGA] =
    {
        TYRANITAR_MISC_INFO,
        .baseHP        = 100,
        .baseAttack    = 164,
        .baseDefense   = 150,
        .baseSpeed     = 71,
        .baseSpAttack  = 95,
        .baseSpDefense = 120,
        .expYield = 315,
        .abilities = { ABILITY_SAND_STREAM, ABILITY_SAND_STREAM, ABILITY_SAND_STREAM },
        .cryId = CRY_TYRANITAR_MEGA,
        .height = 25,
        .weight = 2550,
        .description = POKEDEX_DESC_STRING(
            "Es besitzt so viel Kraft, dass es\n"
            "mit nur einer Hand die Erde beben\n"
            "lassen und Berge zerbröckeln kann."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 345,
        .trainerOffset = 7,
        FRONT_PIC(TyranitarMega, 64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_TyranitarMega,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(TyranitarMega, 64, 64),
        .backPicYOffset = 0,
        .backAnimId = BACK_ANIM_V_SHAKE_LOW,
        PALETTES(TyranitarMega),
        ICON(TyranitarMega, 1),
        .isMegaEvolution = TRUE,
    },
#endif //P_MEGA_EVOLUTIONS
#endif //P_FAMILY_LARVITAR

#if P_FAMILY_LUGIA
    [SPECIES_LUGIA] =
    {
        .baseHP        = 106,
        .baseAttack    = 90,
        .baseDefense   = 130,
        .baseSpeed     = 110,
        .baseSpAttack  = 90,
        .baseSpDefense = 154,
        .types = { TYPE_PSYCHIC, TYPE_FLYING },
        .catchRate = 3,
        .expYield = 306,
        .evYield_SpDefense = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_NO_EGGS_DISCOVERED, EGG_GROUP_NO_EGGS_DISCOVERED },
        .abilities = { ABILITY_PRESSURE, ABILITY_NONE, ABILITY_MULTISCALE },
        .bodyColor = BODY_COLOR_WHITE,
        .isLegendary = TRUE,
        .speciesName = _("Lugia"),
        .cryId = CRY_LUGIA,
        .natDexNum = NATIONAL_DEX_LUGIA,
        .categoryName = _("Taucher"),
        .height = 52,
        .weight = 2160,
        .description = POKEDEX_DESC_STRING(
            "Man berichtet, es sei der Wächter der\n"
            "Meere und man habe es im Herzen eines\n"
            "tosenden Sturmes gesehen."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 721,
        .trainerOffset = 19,
        FRONT_PIC(Lugia, 64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_Lugia,
        .frontAnimId = ANIM_GROW_IN_STAGES,
        .frontAnimDelay = 20,
        .enemyMonElevation = 6,
        BACK_PIC(Lugia, 64, 64),
        .backPicYOffset = 0,
        .backAnimId = BACK_ANIM_SHAKE_GLOW_BLUE,
        PALETTES(Lugia),
        ICON(Lugia, 0),
        .footprint = gMonFootprint_Lugia,
        LEARNSETS(Lugia),
    },
#endif //P_FAMILY_LUGIA

#if P_FAMILY_HO_OH
    [SPECIES_HO_OH] =
    {
        .baseHP        = 106,
        .baseAttack    = 130,
        .baseDefense   = 90,
        .baseSpeed     = 90,
        .baseSpAttack  = 110,
        .baseSpDefense = 154,
        .types = { TYPE_FIRE, TYPE_FLYING },
        .catchRate = 3,
        .expYield = 306,
        .evYield_SpDefense = 3,
        .itemCommon = ITEM_SACRED_ASH,
        .itemRare   = ITEM_SACRED_ASH,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_NO_EGGS_DISCOVERED, EGG_GROUP_NO_EGGS_DISCOVERED },
        .abilities = { ABILITY_PRESSURE, ABILITY_NONE, ABILITY_REGENERATOR },
        .bodyColor = BODY_COLOR_RED,
        .isLegendary = TRUE,
        .speciesName = _("Ho-Oh"),
        .cryId = CRY_HO_OH,
        .natDexNum = NATIONAL_DEX_HO_OH,
        .categoryName = _("Regenbogen"),
        .height = 38,
        .weight = 1990,
        .description = POKEDEX_DESC_STRING(
            "Sein Körper soll in sieben Farben\n"
            "leuchten. Im Flug zieht es einen\n"
            "Regenbogen hinter sich her."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 610,
        .trainerOffset = 17,
        FRONT_PIC(HoOh, 64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_HoOh,
        .frontAnimId = ANIM_GROW_VIBRATE,
        .enemyMonElevation = 6,
        BACK_PIC(HoOh, 64, 64),
        .backPicYOffset = 2,
        .backAnimId = BACK_ANIM_SHAKE_GLOW_RED,
        PALETTES(HoOh),
        ICON(HoOh, 1),
        .footprint = gMonFootprint_HoOh,
        LEARNSETS(HoOh),
    },
#endif //P_FAMILY_HO_OH

#if P_FAMILY_CELEBI
    [SPECIES_CELEBI] =
    {
        .baseHP        = 100,
        .baseAttack    = 100,
        .baseDefense   = 100,
        .baseSpeed     = 100,
        .baseSpAttack  = 100,
        .baseSpDefense = 100,
        .types = { TYPE_PSYCHIC, TYPE_GRASS },
        .catchRate = 45,
        .expYield = 270,
        .evYield_HP = 3,
        .itemCommon = ITEM_LUM_BERRY,
        .itemRare = ITEM_LUM_BERRY,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 100,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_NO_EGGS_DISCOVERED, EGG_GROUP_NO_EGGS_DISCOVERED },
        .abilities = { ABILITY_NATURAL_CURE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_GREEN,
        .isMythical = TRUE,
        .speciesName = _("Celebi"),
        .cryId = CRY_CELEBI,
        .natDexNum = NATIONAL_DEX_CELEBI,
        .categoryName = _("Zeitreise"),
        .height = 6,
        .weight = 50,
        .description = POKEDEX_DESC_STRING(
            "Es kann durch die Zeit reisen, aber es\n"
            "erscheint nur zu friedlichen Zeiten."),
        .pokemonScale = 393,
        .pokemonOffset = -10,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Celebi, 40, 40),
        .frontPicYOffset = 12,
        .frontAnimFrames = sAnims_Celebi,
        .frontAnimId = ANIM_H_SLIDE_WOBBLE,
        .enemyMonElevation = 15,
        BACK_PIC(Celebi, 48, 56),
        .backPicYOffset = 7,
        .backAnimId = BACK_ANIM_SHAKE_GLOW_GREEN,
        PALETTES(Celebi),
        ICON(Celebi, 1),
        .footprint = gMonFootprint_Celebi,
        LEARNSETS(Celebi),
    },
#endif //P_FAMILY_CELEBI

#ifdef __INTELLISENSE__
};
#endif