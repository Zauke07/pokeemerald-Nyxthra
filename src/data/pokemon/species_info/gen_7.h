#ifdef __INTELLISENSE__
const struct SpeciesInfo gSpeciesInfoGen7[] =
{
#endif

#if P_FAMILY_ROWLET
    [SPECIES_ROWLET] =
    {
        .baseHP        = 68,
        .baseAttack    = 55,
        .baseDefense   = 55,
        .baseSpeed     = 42,
        .baseSpAttack  = 50,
        .baseSpDefense = 50,
        .types = { TYPE_GRASS, TYPE_FLYING },
        .catchRate = 45,
        .expYield = 64,
        .evYield_HP = 1,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_FLYING, EGG_GROUP_FLYING },
        .abilities = { ABILITY_OVERGROW, ABILITY_NONE, ABILITY_LONG_REACH },
        .bodyColor = BODY_COLOR_BROWN,
        .speciesName = _("Bauz"),
        .cryId = CRY_ROWLET,
        .natDexNum = NATIONAL_DEX_ROWLET,
        .categoryName = _("Laubflügel"),
        .height = 3,
        .weight = 15,
        .description = POKEDEX_DESC_STRING(
            "Ein wachsames und nachtaktives\n"
            "Pokémon. Tagsüber sammelt es per\n"
            "Photosynthese Kräfte, um fit für\n"
            "die Nacht zu sein."),
        .pokemonScale = 530,
        .pokemonOffset = 13,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Rowlet, 31, 37),
        .frontPicYOffset = 12,
        .frontAnimFrames = sAnims_Rowlet,
        .frontAnimId = ANIM_CIRCULAR_STRETCH_TWICE,
        BACK_PIC(Rowlet, 43, 36),
        .backPicYOffset = 15,
        .backAnimId = BACK_ANIM_CONCAVE_ARC_SMALL,
        PALETTES(Rowlet),
        ICON(Rowlet, 0),
        .footprint = gMonFootprint_Rowlet,
        LEARNSETS(Rowlet),
        .evolutions = EVOLUTION({EVO_LEVEL, 17, SPECIES_DARTRIX}),
    },

    [SPECIES_DARTRIX] =
    {
        .baseHP        = 78,
        .baseAttack    = 75,
        .baseDefense   = 75,
        .baseSpeed     = 52,
        .baseSpAttack  = 70,
        .baseSpDefense = 70,
        .types = { TYPE_GRASS, TYPE_FLYING },
        .catchRate = 45,
        .expYield = 147,
        .evYield_HP = 2,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_FLYING, EGG_GROUP_FLYING },
        .abilities = { ABILITY_OVERGROW, ABILITY_NONE, ABILITY_LONG_REACH },
        .bodyColor = BODY_COLOR_BROWN,
        .noFlip = TRUE,
        .speciesName = _("Arboretoss"),
        .cryId = CRY_DARTRIX,
        .natDexNum = NATIONAL_DEX_DARTRIX,
        .categoryName = _("Flügelklingen"),
        .height = 7,
        .weight = 160,
        .description = POKEDEX_DESC_STRING(
            "Die Pflege seines Gefieders versäumt es\n"
            "nie. So bewahrt es nicht nur ein\n"
            "gepflegtes Äußeres, sondern auch die\n"
            "Schärfe seiner Federn."),
        .pokemonScale = 365,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Dartrix, 34, 47),
        .frontPicYOffset = 8,
        .frontAnimFrames = sAnims_Dartrix,
        .frontAnimId = ANIM_V_STRETCH,
        BACK_PIC(Dartrix, 56, 54),
        .backPicYOffset = 4,
        .backAnimId = BACK_ANIM_V_STRETCH,
        PALETTES(Dartrix),
        ICON(Dartrix, 1),
        .footprint = gMonFootprint_Dartrix,
        LEARNSETS(Dartrix),
        .evolutions = EVOLUTION({EVO_LEVEL, 34, SPECIES_DECIDUEYE},
                                {EVO_NONE, 0, SPECIES_DECIDUEYE_HISUI}),
    },

#define DECIDUEYE_MISC_INFO                                     \
        .catchRate = 45,                                        \
        .expYield = 239,                                        \
        .evYield_Attack = 3,                                    \
        .genderRatio = PERCENT_FEMALE(12.5),                    \
        .eggCycles = 15,                                        \
        .friendship = STANDARD_FRIENDSHIP,                      \
        .growthRate = GROWTH_MEDIUM_SLOW,                       \
        .eggGroups = { EGG_GROUP_FLYING, EGG_GROUP_FLYING },    \
        .bodyColor = BODY_COLOR_BROWN,                          \
        .speciesName = _("Arboretoss"),                          \
        .cryId = CRY_DECIDUEYE,                                 \
        .natDexNum = NATIONAL_DEX_DECIDUEYE,                    \
        .categoryName = _("Flügelklingen"),                       \
        .height = 16,                                           \
        .pokemonScale = 259,                                    \
        .pokemonOffset = 1,                                     \
        .trainerScale = 296,                                    \
        .trainerOffset = 1,                                     \
        .footprint = gMonFootprint_Decidueye,                   \
        .formSpeciesIdTable = sDecidueyeFormSpeciesIdTable

    [SPECIES_DECIDUEYE] =
    {
        DECIDUEYE_MISC_INFO,
        .baseHP        = 78,
        .baseAttack    = 107,
        .baseDefense   = 75,
        .baseSpeed     = 70,
        .baseSpAttack  = 100,
        .baseSpDefense = 100,
        .types = { TYPE_GRASS, TYPE_GHOST },
        .abilities = { ABILITY_OVERGROW, ABILITY_NONE, ABILITY_LONG_REACH },
        .weight = 366,
        .description = POKEDEX_DESC_STRING(
            "Dieses Pokémon kann die Federn\n"
            "seiner Flügel wie Pfeile\n"
            "verschießen. Dabei ist es so\n"
            "präzise, dass es einen Kiesel auf\n"
            "100 m durchbohrt."),
        FRONT_PIC(Decidueye, 45, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_Decidueye,
        .frontAnimId = ANIM_SHRINK_GROW_VIBRATE_FAST,
        BACK_PIC(Decidueye, 46, 62),
        .backPicYOffset = 0,
        .backAnimId = BACK_ANIM_SHRINK_GROW_VIBRATE,
        PALETTES(Decidueye),
        ICON(Decidueye, 1),
        LEARNSETS(Decidueye),
    },

#if P_HISUIAN_FORMS
    [SPECIES_DECIDUEYE_HISUI] =
    {
        DECIDUEYE_MISC_INFO,
        .baseHP        = 88,
        .baseAttack    = 112,
        .baseDefense   = 80,
        .baseSpeed     = 60,
        .baseSpAttack  = 95,
        .baseSpDefense = 95,
        .types = { TYPE_GRASS, TYPE_FIGHTING },
        .abilities = { ABILITY_OVERGROW, ABILITY_NONE, ABILITY_SCRAPPY },
        .weight = 370,
        .description = POKEDEX_DESC_STRING(
            "Dieses Pokémon kann die Federn\n"
            "seiner Flügel wie Pfeile\n"
            "verschießen. Dabei ist es so\n"
            "präzise, dass es einen Kiesel auf\n"
            "100 m durchbohrt."),
        FRONT_PIC(DecidueyeHisuian, 64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_DecidueyeHisuian,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(DecidueyeHisuian, 64, 64),
        .backPicYOffset = 0,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(DecidueyeHisuian),
        ICON(DecidueyeHisuian, 0),
        LEARNSETS(DecidueyeHisuian),
        .isHisuianForm = TRUE,
    },
#endif //P_HISUIAN_FORMS
#endif //P_FAMILY_ROWLET

#if P_FAMILY_LITTEN
    [SPECIES_LITTEN] =
    {
        .baseHP        = 45,
        .baseAttack    = 65,
        .baseDefense   = 40,
        .baseSpeed     = 70,
        .baseSpAttack  = 60,
        .baseSpDefense = 40,
        .types = { TYPE_FIRE, TYPE_FIRE },
        .catchRate = 45,
        .expYield = 64,
        .evYield_Speed = 1,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD },
        .abilities = { ABILITY_BLAZE, ABILITY_NONE, ABILITY_INTIMIDATE },
        .bodyColor = BODY_COLOR_RED,
        .speciesName = _("Flamiau"),
        .cryId = CRY_LITTEN,
        .natDexNum = NATIONAL_DEX_LITTEN,
        .categoryName = _("Feuerkatzen"),
        .height = 4,
        .weight = 43,
        .description = POKEDEX_DESC_STRING(
            "Es zeigt nie seine Gefühle und ist am\n"
            "liebsten allein. Sein Zutrauen zu\n"
            "gewinnen, kann einige Zeit in Anspruch\n"
            "nehmen."),
        .pokemonScale = 491,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Litten, 48, 40),
        .frontPicYOffset = 12,
        .frontAnimFrames = sAnims_Litten,
        .frontAnimId = ANIM_H_STRETCH,
        BACK_PIC(Litten, 64, 48),
        .backPicYOffset = 11,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(Litten),
        ICON(Litten, 0),
        .footprint = gMonFootprint_Litten,
        LEARNSETS(Litten),
        .evolutions = EVOLUTION({EVO_LEVEL, 17, SPECIES_TORRACAT}),
    },

    [SPECIES_TORRACAT] =
    {
        .baseHP        = 65,
        .baseAttack    = 85,
        .baseDefense   = 50,
        .baseSpeed     = 90,
        .baseSpAttack  = 80,
        .baseSpDefense = 50,
        .types = { TYPE_FIRE, TYPE_FIRE },
        .catchRate = 45,
        .expYield = 147,
        .evYield_Speed = 2,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD },
        .abilities = { ABILITY_BLAZE, ABILITY_NONE, ABILITY_INTIMIDATE },
        .bodyColor = BODY_COLOR_RED,
        .speciesName = _("Miezunder"),
        .cryId = CRY_TORRACAT,
        .natDexNum = NATIONAL_DEX_TORRACAT,
        .categoryName = _("Feuerkatzen"),
        .height = 7,
        .weight = 250,
        .description = POKEDEX_DESC_STRING(
            "Es trägt ein feuriges Glöckchen um\n"
            "den Hals. Immer, wenn es Flammen\n"
            "ausstößt, ertönt ein helles Läuten."),
        .pokemonScale = 365,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Torracat, 56, 64),
        .frontPicYOffset = 2,
        .frontAnimFrames = sAnims_Torracat,
        .frontAnimId = ANIM_V_STRETCH,
        BACK_PIC(Torracat, 64, 56),
        .backPicYOffset = 7,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(Torracat),
        ICON(Torracat, 0),
        .footprint = gMonFootprint_Torracat,
        LEARNSETS(Torracat),
        .evolutions = EVOLUTION({EVO_LEVEL, 34, SPECIES_INCINEROAR}),
    },

    [SPECIES_INCINEROAR] =
    {
        .baseHP        = 95,
        .baseAttack    = 115,
        .baseDefense   = 90,
        .baseSpeed     = 60,
        .baseSpAttack  = 80,
        .baseSpDefense = 90,
        .types = { TYPE_FIRE, TYPE_DARK },
        .catchRate = 45,
        .expYield = 239,
        .evYield_Attack = 3,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD },
        .abilities = { ABILITY_BLAZE, ABILITY_NONE, ABILITY_INTIMIDATE },
        .bodyColor = BODY_COLOR_RED,
        .speciesName = _("Fuegro"),
        .cryId = CRY_INCINEROAR,
        .natDexNum = NATIONAL_DEX_INCINEROAR,
        .categoryName = _("Fieslings"),
        .height = 18,
        .weight = 830,
        .description = POKEDEX_DESC_STRING(
            "Entbrennt sein Kampfeswille, lodern die\n"
            "Flammen um seine Hüfte noch heftiger auf."),
        .pokemonScale = 267,
        .pokemonOffset = 2,
        .trainerScale = 286,
        .trainerOffset = 1,
        FRONT_PIC(Incineroar, 64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_Incineroar,
        .frontAnimId = ANIM_V_SHAKE,
        BACK_PIC(Incineroar, 64, 56),
        .backPicYOffset = 4,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(Incineroar),
        ICON(Incineroar, 0),
        .footprint = gMonFootprint_Incineroar,
        LEARNSETS(Incineroar),
    },
#endif //P_FAMILY_LITTEN

#if P_FAMILY_POPPLIO
    [SPECIES_POPPLIO] =
    {
        .baseHP        = 50,
        .baseAttack    = 54,
        .baseDefense   = 54,
        .baseSpeed     = 40,
        .baseSpAttack  = 66,
        .baseSpDefense = 56,
        .types = { TYPE_WATER, TYPE_WATER },
        .catchRate = 45,
        .expYield = 64,
        .evYield_SpAttack = 1,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_WATER_1, EGG_GROUP_FIELD },
        .abilities = { ABILITY_TORRENT, ABILITY_NONE, ABILITY_LIQUID_VOICE },
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Robball"),
        .cryId = CRY_POPPLIO,
        .natDexNum = NATIONAL_DEX_POPPLIO,
        .categoryName = _("Seehund"),
        .height = 4,
        .weight = 75,
        .description = POKEDEX_DESC_STRING(
            "Es kontrolliert Wasserblasen. Um eine\n"
            "große Blase zu erschaffen, muss es\n"
            "unermüdlich üben."),
        .pokemonScale = 491,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Popplio, 40, 48),
        .frontPicYOffset = 11,
        .frontAnimFrames = sAnims_Popplio,
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE_SLOW,
        BACK_PIC(Popplio, 48, 48),
        .backPicYOffset = 11,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(Popplio),
        ICON(Popplio, 0),
        .footprint = gMonFootprint_Popplio,
        LEARNSETS(Popplio),
        .evolutions = EVOLUTION({EVO_LEVEL, 17, SPECIES_BRIONNE}),
    },

    [SPECIES_BRIONNE] =
    {
        .baseHP        = 60,
        .baseAttack    = 69,
        .baseDefense   = 69,
        .baseSpeed     = 50,
        .baseSpAttack  = 91,
        .baseSpDefense = 81,
        .types = { TYPE_WATER, TYPE_WATER },
        .catchRate = 45,
        .expYield = 147,
        .evYield_SpAttack = 2,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_WATER_1, EGG_GROUP_FIELD },
        .abilities = { ABILITY_TORRENT, ABILITY_NONE, ABILITY_LIQUID_VOICE },
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Marikeck"),
        .cryId = CRY_BRIONNE,
        .natDexNum = NATIONAL_DEX_BRIONNE,
        .categoryName = _("Popsternchen"),
        .height = 6,
        .weight = 175,
        .description = POKEDEX_DESC_STRING(
            "Dieser begnadete Tänzer erzeugt\n"
            "beim Tanzen eine Wasserblase nach\n"
            "der anderen und greift damit seine\n"
            "Feinde an."),
        .pokemonScale = 422,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Brionne, 48, 56),
        .frontPicYOffset = 6,
        .frontAnimFrames = sAnims_Brionne,
        .frontAnimId = ANIM_SHRINK_GROW,
        BACK_PIC(Brionne, 48, 56),
        .backPicYOffset = 9,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(Brionne),
        ICON(Brionne, 0),
        .footprint = gMonFootprint_Brionne,
        LEARNSETS(Brionne),
        .evolutions = EVOLUTION({EVO_LEVEL, 34, SPECIES_PRIMARINA}),
    },

    [SPECIES_PRIMARINA] =
    {
        .baseHP        = 80,
        .baseAttack    = 74,
        .baseDefense   = 74,
        .baseSpeed     = 60,
        .baseSpAttack  = 126,
        .baseSpDefense = 116,
        .types = { TYPE_WATER, TYPE_FAIRY },
        .catchRate = 45,
        .expYield = 239,
        .evYield_SpAttack = 3,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_WATER_1, EGG_GROUP_FIELD },
        .abilities = { ABILITY_TORRENT, ABILITY_NONE, ABILITY_LIQUID_VOICE },
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Primarene"),
        .cryId = CRY_PRIMARINA,
        .natDexNum = NATIONAL_DEX_PRIMARINA,
        .categoryName = _("Solisten"),
        .height = 18,
        .weight = 440,
        .description = POKEDEX_DESC_STRING(
            "Es kontrolliert Wasserblasen, indem es\n"
            "Schallwellen aus seinem Mund ausstößt, die\n"
            "wie klarer Gesang klingen."),
        .pokemonScale = 267,
        .pokemonOffset = 2,
        .trainerScale = 286,
        .trainerOffset = 1,
        FRONT_PIC(Primarina, 64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_Primarina,
        .frontAnimId = ANIM_SHAKE_GLOW_BLUE_SLOW,
        BACK_PIC(Primarina, 64, 64),
        .backPicYOffset = 0,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(Primarina),
        ICON(Primarina, 0),
        .footprint = gMonFootprint_Primarina,
        LEARNSETS(Primarina),
    },
#endif //P_FAMILY_POPPLIO

#if P_FAMILY_PIKIPEK
    [SPECIES_PIKIPEK] =
    {
        .baseHP        = 35,
        .baseAttack    = 75,
        .baseDefense   = 30,
        .baseSpeed     = 65,
        .baseSpAttack  = 30,
        .baseSpDefense = 30,
        .types = { TYPE_NORMAL, TYPE_FLYING },
        .catchRate = 255,
        .expYield = 53,
        .evYield_Attack = 1,
        .itemRare = ITEM_ORAN_BERRY,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_FLYING, EGG_GROUP_FLYING },
        .abilities = { ABILITY_KEEN_EYE, ABILITY_SKILL_LINK, ABILITY_PICKUP },
        .bodyColor = BODY_COLOR_BLACK,
        .speciesName = _("Peppeck"),
        .cryId = CRY_PIKIPEK,
        .natDexNum = NATIONAL_DEX_PIKIPEK,
        .categoryName = _("Specht"),
        .height = 3,
        .weight = 12,
        .description = POKEDEX_DESC_STRING(
            "Dieses Pokémon ernährt sich von Beeren.\n"
            "Die Samen verschießt es später als\n"
            "Munition aus seinem Schnabel."),
        .pokemonScale = 530,
        .pokemonOffset = 13,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Pikipek, 29, 40),
        .frontPicYOffset = 10,
        .frontAnimFrames = sAnims_Pikipek,
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(Pikipek, 48, 48),
        .backPicYOffset = 8,
        .backAnimId = BACK_ANIM_SHRINK_GROW,
        PALETTES(Pikipek),
        ICON(Pikipek, 2),
        .footprint = gMonFootprint_Pikipek,
        LEARNSETS(Pikipek),
        .evolutions = EVOLUTION({EVO_LEVEL, 14, SPECIES_TRUMBEAK}),
    },

    [SPECIES_TRUMBEAK] =
    {
        .baseHP        = 55,
        .baseAttack    = 85,
        .baseDefense   = 50,
        .baseSpeed     = 75,
        .baseSpAttack  = 40,
        .baseSpDefense = 50,
        .types = { TYPE_NORMAL, TYPE_FLYING },
        .catchRate = 120,
        .expYield = 124,
        .evYield_Attack = 2,
        .itemRare = ITEM_SITRUS_BERRY,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_FLYING, EGG_GROUP_FLYING },
        .abilities = { ABILITY_KEEN_EYE, ABILITY_SKILL_LINK, ABILITY_PICKUP },
        .bodyColor = BODY_COLOR_BLACK,
        .speciesName = _("Trompeck"),
        .cryId = CRY_TRUMBEAK,
        .natDexNum = NATIONAL_DEX_TRUMBEAK,
        .categoryName = _("Trompete"),
        .height = 6,
        .weight = 148,
        .description = POKEDEX_DESC_STRING(
            "Indem es seine Schnabelspitze verformt,\n"
            "kann es mehr als 100 verschiedene Rufe\n"
            "ausstoßen."),
        .pokemonScale = 422,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Trumbeak, 44, 53),
        .frontPicYOffset = 4,
        .frontAnimFrames = sAnims_Trumbeak,
        .frontAnimId = ANIM_H_STRETCH,
        BACK_PIC(Trumbeak, 56, 56),
        .backPicYOffset = 6,
        .backAnimId = BACK_ANIM_H_STRETCH,
        PALETTES(Trumbeak),
        ICON(Trumbeak, 0),
        .footprint = gMonFootprint_Trumbeak,
        LEARNSETS(Trumbeak),
        .evolutions = EVOLUTION({EVO_LEVEL, 28, SPECIES_TOUCANNON}),
    },

    [SPECIES_TOUCANNON] =
    {
        .baseHP        = 80,
        .baseAttack    = 120,
        .baseDefense   = 75,
        .baseSpeed     = 60,
        .baseSpAttack  = 75,
        .baseSpDefense = 75,
        .types = { TYPE_NORMAL, TYPE_FLYING },
        .catchRate = 45,
        .expYield = 218,
        .evYield_Attack = 3,
        .itemRare = ITEM_RAWST_BERRY,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_FLYING, EGG_GROUP_FLYING },
        .abilities = { ABILITY_KEEN_EYE, ABILITY_SKILL_LINK, ABILITY_SHEER_FORCE },
        .bodyColor = BODY_COLOR_BLACK,
        .speciesName = _("Tukanon"),
        .cryId = CRY_TOUCANNON,
        .natDexNum = NATIONAL_DEX_TOUCANNON,
        .categoryName = _("Kanone"),
        .height = 11,
        .weight = 260,
        .description = POKEDEX_DESC_STRING(
            "Erhitzt vor jedem Kampf seinen\n"
            "Schnabel auf über 100 Grad C. Dadurch\n"
            "erleiden Gepiesackte schwere\n"
            "Verbrennungen."),
        .pokemonScale = 320,
        .pokemonOffset = 7,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Toucannon, 59, 59),
        .frontPicYOffset = 2,
        .frontAnimFrames = sAnims_Toucannon,
        .frontAnimId = ANIM_SHAKE_GLOW_RED_SLOW,
        BACK_PIC(Toucannon, 64, 56),
        .backPicYOffset = 6,
        .backAnimId = BACK_ANIM_SHRINK_GROW_VIBRATE,
        PALETTES(Toucannon),
        ICON(Toucannon, 0),
        .footprint = gMonFootprint_Toucannon,
        LEARNSETS(Toucannon),
    },
#endif //P_FAMILY_PIKIPEK

#if P_FAMILY_YUNGOOS
    [SPECIES_YUNGOOS] =
    {
        .baseHP        = 48,
        .baseAttack    = 70,
        .baseDefense   = 30,
        .baseSpeed     = 45,
        .baseSpAttack  = 30,
        .baseSpDefense = 30,
        .types = { TYPE_NORMAL, TYPE_NORMAL },
        .catchRate = 255,
        .expYield = 51,
        .evYield_Attack = 1,
        .itemRare = ITEM_PECHA_BERRY,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD },
        .abilities = { ABILITY_STAKEOUT, ABILITY_STRONG_JAW, ABILITY_ADAPTABILITY },
        .bodyColor = BODY_COLOR_BROWN,
        .speciesName = _("Mangunior"),
        .cryId = CRY_YUNGOOS,
        .natDexNum = NATIONAL_DEX_YUNGOOS,
        .categoryName = _("Patrouille"),
        .height = 4,
        .weight = 60,
        .description = POKEDEX_DESC_STRING(
            "Die Futtersuche treibt es unaufhörlich\n"
            "umher, doch sobald die Sonne untergeht,\n"
            "wird es von Müdigkeit überfallen und\n"
            "schläft sofort ein."),
        .pokemonScale = 491,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Yungoos, 64, 40),
        .frontPicYOffset = 12,
        .frontAnimFrames = sAnims_Yungoos,
        .frontAnimId = ANIM_V_STRETCH,
        BACK_PIC(Yungoos, 48, 40),
        .backPicYOffset = 14,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(Yungoos),
        ICON(Yungoos, 2),
        .footprint = gMonFootprint_Yungoos,
        LEARNSETS(Yungoos),
        .evolutions = EVOLUTION({EVO_LEVEL_DAY, 20, SPECIES_GUMSHOOS}),
    },

    [SPECIES_GUMSHOOS] =
    {
        .baseHP        = 88,
        .baseAttack    = 110,
        .baseDefense   = 60,
        .baseSpeed     = 45,
        .baseSpAttack  = 55,
        .baseSpDefense = 60,
        .types = { TYPE_NORMAL, TYPE_NORMAL },
        .catchRate = 127,
        .expYield = 146,
        .evYield_Attack = 2,
        .itemRare = ITEM_PECHA_BERRY,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD },
        .abilities = { ABILITY_STAKEOUT, ABILITY_STRONG_JAW, ABILITY_ADAPTABILITY },
        .bodyColor = BODY_COLOR_BROWN,
        .speciesName = _("Manguspektor"),
        .cryId = CRY_GUMSHOOS,
        .natDexNum = NATIONAL_DEX_GUMSHOOS,
        .categoryName = _("Beschattung"),
        .height = 7,
        .weight = 142,
        .description = POKEDEX_DESC_STRING(
            "Findet es Spuren potenzieller\n"
            "Beute, legt es sich sofort auf die\n"
            "Lauer. Spätestens bei\n"
            "Sonnenuntergang nickt es aber ein."),
        .pokemonScale = 365,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Gumshoos, 56, 56),
        .frontPicYOffset = 5,
        .frontAnimFrames = sAnims_Gumshoos,
        .frontAnimId = ANIM_H_SHAKE,
        BACK_PIC(Gumshoos, 48, 56),
        .backPicYOffset = 7,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(Gumshoos),
        ICON(Gumshoos, 2),
        .footprint = gMonFootprint_Gumshoos,
        LEARNSETS(Gumshoos),
    },
#endif //P_FAMILY_YUNGOOS

#if P_FAMILY_GRUBBIN
    [SPECIES_GRUBBIN] =
    {
        .baseHP        = 47,
        .baseAttack    = 62,
        .baseDefense   = 45,
        .baseSpeed     = 46,
        .baseSpAttack  = 55,
        .baseSpDefense = 45,
        .types = { TYPE_BUG, TYPE_BUG },
        .catchRate = 255,
        .expYield = 60,
        .evYield_Attack = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_BUG, EGG_GROUP_BUG },
        .abilities = { ABILITY_SWARM, ABILITY_NONE },
        .bodyColor = BODY_COLOR_GRAY,
        .speciesName = _("Mabula"),
        .cryId = CRY_GRUBBIN,
        .natDexNum = NATIONAL_DEX_GRUBBIN,
        .categoryName = _("Larven"),
        .height = 4,
        .weight = 44,
        .description = POKEDEX_DESC_STRING(
            "Mit seinem großen Kiefer gräbt es sich\n"
            "seinen Bau im Waldboden. Zu seinen\n"
            "Leibspeisen gehört süßer Baumsaft."),
        .pokemonScale = 491,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Grubbin, 48, 32),
        .frontPicYOffset = 17,
        .frontAnimFrames = sAnims_Grubbin,
        .frontAnimId = ANIM_H_SLIDE,
        BACK_PIC(Grubbin, 64, 32),
        .backPicYOffset = 16,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(Grubbin),
        ICON(Grubbin, 0),
        .footprint = gMonFootprint_Grubbin,
        LEARNSETS(Grubbin),
        .evolutions = EVOLUTION({EVO_LEVEL, 20, SPECIES_CHARJABUG}),
    },

    [SPECIES_CHARJABUG] =
    {
        .baseHP        = 57,
        .baseAttack    = 82,
        .baseDefense   = 95,
        .baseSpeed     = 36,
        .baseSpAttack  = 55,
        .baseSpDefense = 75,
        .types = { TYPE_BUG, TYPE_ELECTRIC },
        .catchRate = 120,
        .expYield = 140,
        .evYield_Defense = 2,
        .itemRare = ITEM_CELL_BATTERY,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_BUG, EGG_GROUP_BUG },
        .abilities = { ABILITY_BATTERY, ABILITY_NONE },
        .bodyColor = BODY_COLOR_GREEN,
        .speciesName = _("Akkup"),
        .cryId = CRY_CHARJABUG,
        .natDexNum = NATIONAL_DEX_CHARJABUG,
        .categoryName = _("Batterie"),
        .height = 5,
        .weight = 105,
        .description = POKEDEX_DESC_STRING(
            "Beim Verdauen der Nahrung entsteht\n"
            "elektrische Energie, die es in seinem\n"
            "Strombeutel speichert."),
        .pokemonScale = 432,
        .pokemonOffset = 13,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Charjabug, 40, 40),
        .frontPicYOffset = 14,
        .frontAnimFrames = sAnims_Charjabug,
        .frontAnimId = ANIM_SHAKE_FLASH_YELLOW_SLOW,
        BACK_PIC(Charjabug, 64, 40),
        .backPicYOffset = 15,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(Charjabug),
        ICON(Charjabug, 1),
        .footprint = gMonFootprint_Charjabug,
        LEARNSETS(Charjabug),
        .evolutions = EVOLUTION({EVO_MAPSEC, MAPSEC_NEW_MAUVILLE, SPECIES_VIKAVOLT},
                                {EVO_ITEM, ITEM_THUNDER_STONE, SPECIES_VIKAVOLT}),
    },

    [SPECIES_VIKAVOLT] =
    {
        .baseHP        = 77,
        .baseAttack    = 70,
        .baseDefense   = 90,
        .baseSpeed     = 43,
        .baseSpAttack  = 145,
        .baseSpDefense = 75,
        .types = { TYPE_BUG, TYPE_ELECTRIC },
        .catchRate = 45,
        .expYield = 225,
        .evYield_SpAttack = 3,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_BUG, EGG_GROUP_BUG },
        .abilities = { ABILITY_LEVITATE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Donarion"),
        .cryId = CRY_VIKAVOLT,
        .natDexNum = NATIONAL_DEX_VIKAVOLT,
        .categoryName = _("Kneifkäfer"),
        .height = 15,
        .weight = 450,
        .description = POKEDEX_DESC_STRING(
            "Wenn es ein Akkup als Reservebatterie\n"
            "trägt, kann es im Flug eine Salve aus\n"
            "extrem starken Elektrostrahlen abfeuern."),
        .pokemonScale = 268,
        .pokemonOffset = 2,
        .trainerScale = 271,
        .trainerOffset = 0,
        FRONT_PIC(Vikavolt, 64, 56),
        .frontPicYOffset = 3,
        .frontAnimFrames = sAnims_Vikavolt,
        .frontAnimId = ANIM_BOUNCE_ROTATE_TO_SIDES,
        .enemyMonElevation = 8,
        BACK_PIC(Vikavolt, 64, 56),
        .backPicYOffset = 7,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(Vikavolt),
        ICON(Vikavolt, 0),
        .footprint = gMonFootprint_Vikavolt,
        LEARNSETS(Vikavolt),
    },
#endif //P_FAMILY_GRUBBIN

#if P_FAMILY_CRABRAWLER
    [SPECIES_CRABRAWLER] =
    {
        .baseHP        = 47,
        .baseAttack    = 82,
        .baseDefense   = 57,
        .baseSpeed     = 63,
        .baseSpAttack  = 42,
        .baseSpDefense = 47,
        .types = { TYPE_FIGHTING, TYPE_FIGHTING },
        .catchRate = 225,
        .expYield = 68,
        .evYield_Attack = 1,
        .itemRare = ITEM_ASPEAR_BERRY,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_WATER_3, EGG_GROUP_WATER_3 },
        .abilities = { ABILITY_HYPER_CUTTER, ABILITY_IRON_FIST, ABILITY_ANGER_POINT },
        .bodyColor = BODY_COLOR_PURPLE,
        .speciesName = _("Krabbox"),
        .cryId = CRY_CRABRAWLER,
        .natDexNum = NATIONAL_DEX_CRABRAWLER,
        .categoryName = _("Boxkampf"),
        .height = 6,
        .weight = 70,
        .description = POKEDEX_DESC_STRING(
            "Schützt mit den Scheren seine\n"
            "Schwachstellen und bereitet einen\n"
            "Gegenschlag vor. Verliert es, bläst\n"
            "es Trübsal."),
        .pokemonScale = 422,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Crabrawler, 64, 56),
        .frontPicYOffset = 7,
        .frontAnimFrames = sAnims_Crabrawler,
        .frontAnimId = ANIM_V_SHAKE,
        BACK_PIC(Crabrawler, 64, 48),
        .backPicYOffset = 9,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(Crabrawler),
        ICON(Crabrawler, 2),
        .footprint = gMonFootprint_Crabrawler,
        LEARNSETS(Crabrawler),
        .evolutions = EVOLUTION({EVO_SPECIFIC_MAP, MAP_NONE, SPECIES_CRABOMINABLE},
                                {EVO_ITEM, ITEM_ICE_STONE, SPECIES_CRABOMINABLE}),
    },

    [SPECIES_CRABOMINABLE] =
    {
        .baseHP        = 97,
        .baseAttack    = 132,
        .baseDefense   = 77,
        .baseSpeed     = 43,
        .baseSpAttack  = 62,
        .baseSpDefense = 67,
        .types = { TYPE_FIGHTING, TYPE_ICE },
        .catchRate = 60,
        .expYield = 167,
        .evYield_Attack = 2,
        .itemRare = ITEM_CHERI_BERRY,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_WATER_3, EGG_GROUP_WATER_3 },
        .abilities = { ABILITY_HYPER_CUTTER, ABILITY_IRON_FIST, ABILITY_ANGER_POINT },
        .bodyColor = BODY_COLOR_WHITE,
        .speciesName = _("Krawell"),
        .cryId = CRY_CRABOMINABLE,
        .natDexNum = NATIONAL_DEX_CRABOMINABLE,
        .categoryName = _("Fellkrabbe"),
        .height = 17,
        .weight = 1800,
        .description = POKEDEX_DESC_STRING(
            "Schlägt erst einmal wahllos zu. Kommt es\n"
            "hart auf hart, stößt es seine Scheren ab\n"
            "und verschießt sie wie Raketen."),
        .pokemonScale = 259,
        .pokemonOffset = 0,
        .trainerScale = 290,
        .trainerOffset = 1,
        FRONT_PIC(Crabominable, 64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_Crabominable,
        .frontAnimId = ANIM_SHRINK_GROW_VIBRATE_FAST,
        BACK_PIC(Crabominable, 64, 64),
        .backPicYOffset = 3,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(Crabominable),
        ICON(Crabominable, 2),
        .footprint = gMonFootprint_Crabominable,
        LEARNSETS(Crabominable),
    },
#endif //P_FAMILY_CRABRAWLER

#if P_FAMILY_ORICORIO
#define ORICORIO_MISC_INFO                                      \
        .baseHP        = 75,                                    \
        .baseAttack    = 70,                                    \
        .baseDefense   = 70,                                    \
        .baseSpeed     = 93,                                    \
        .baseSpAttack  = 98,                                    \
        .baseSpDefense = 70,                                    \
        .catchRate = 45,                                        \
        .expYield = 167,                                        \
        .evYield_SpAttack = 2,                                  \
        .itemRare = ITEM_HONEY,                                 \
        .genderRatio = PERCENT_FEMALE(75),                      \
        .eggCycles = 20,                                        \
        .friendship = STANDARD_FRIENDSHIP,                      \
        .growthRate = GROWTH_MEDIUM_FAST,                       \
        .eggGroups = { EGG_GROUP_FLYING, EGG_GROUP_FLYING },    \
        .abilities = { ABILITY_DANCER, ABILITY_NONE },          \
        .speciesName = _("Krawell"),                           \
        .natDexNum = NATIONAL_DEX_ORICORIO,                     \
        .categoryName = _("Fellkrabbe"),                           \
        .height = 6,                                            \
        .weight = 34,                                           \
        .pokemonScale = 422,                                    \
        .pokemonOffset = 12,                                    \
        .trainerScale = 256,                                    \
        .trainerOffset = 0,                                     \
        .frontAnimFrames = sAnims_Oricorio,                     \
        .backPicYOffset = 0,                                    \
        .footprint = gMonFootprint_Oricorio,                    \
        LEARNSETS(Oricorio),                                    \
        .formSpeciesIdTable = sOricorioFormSpeciesIdTable,      \
        .formChangeTable = sOricorioFormChangeTable
        //.backAnimId = BACK_ANIM_NONE,                       \

    [SPECIES_ORICORIO_BAILE] =
    {
        ORICORIO_MISC_INFO,
        .types = { TYPE_FIRE, TYPE_FLYING },
        .bodyColor = BODY_COLOR_RED,
        .cryId = CRY_ORICORIO_BAILE,
        .description = POKEDEX_DESC_STRING(
            "Schlägt es mit den Flügeln, gibt es\n"
            "Zunder! Mit eleganten\n"
            "Ausfallschritten lässt es dann\n"
            "Feuer auf seine Gegner herabregnen."),
        FRONT_PIC(OricorioBaile, 56, 64),
        .frontPicYOffset = 2,
        .frontAnimId = ANIM_CONCAVE_ARC_SMALL,
        BACK_PIC(OricorioBaile, 64, 64),
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(OricorioBaile),
        ICON(OricorioBaile, 0),
    },

    [SPECIES_ORICORIO_POM_POM] =
    {
        ORICORIO_MISC_INFO,
        .types = { TYPE_ELECTRIC, TYPE_FLYING },
        .bodyColor = BODY_COLOR_YELLOW,
        .cryId = CRY_ORICORIO_POM_POM,
        .description = POKEDEX_DESC_STRING(
            "Schlägt es mit den Flügeln, gibt es\n"
            "Zunder! Mit eleganten\n"
            "Ausfallschritten lässt es dann\n"
            "Feuer auf seine Gegner herabregnen."),
        FRONT_PIC(OricorioPomPom, 56, 56),
        .frontPicYOffset = 5,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(OricorioPomPom, 64, 64),
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(OricorioPomPom),
        ICON(OricorioPomPom, 1),
    },

    [SPECIES_ORICORIO_PAU] =
    {
        ORICORIO_MISC_INFO,
        .types = { TYPE_PSYCHIC, TYPE_FLYING },
        .bodyColor = BODY_COLOR_PINK,
        .cryId = CRY_ORICORIO_PAU,
        .description = POKEDEX_DESC_STRING(
            "Schlägt es mit den Flügeln, gibt es\n"
            "Zunder! Mit eleganten\n"
            "Ausfallschritten lässt es dann\n"
            "Feuer auf seine Gegner herabregnen."),
        FRONT_PIC(OricorioPau, 56, 64),
        .frontPicYOffset = 3,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(OricorioPau, 64, 64),
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(OricorioPau),
        ICON(OricorioPau, 1),
    },

    [SPECIES_ORICORIO_SENSU] =
    {
        ORICORIO_MISC_INFO,
        .types = { TYPE_GHOST, TYPE_FLYING },
        .bodyColor = BODY_COLOR_PURPLE,
        .cryId = CRY_ORICORIO_SENSU,
        .description = POKEDEX_DESC_STRING(
            "Schlägt es mit den Flügeln, gibt es\n"
            "Zunder! Mit eleganten\n"
            "Ausfallschritten lässt es dann\n"
            "Feuer auf seine Gegner herabregnen."),
        FRONT_PIC(OricorioSensu, 64, 56),
        .frontPicYOffset = 4,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(OricorioSensu, 64, 64),
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(OricorioSensu),
        ICON(OricorioSensu, 0),
    },
#endif //P_FAMILY_ORICORIO

#if P_FAMILY_CUTIEFLY
    [SPECIES_CUTIEFLY] =
    {
        .baseHP        = 40,
        .baseAttack    = 45,
        .baseDefense   = 40,
        .baseSpeed     = 84,
        .baseSpAttack  = 55,
        .baseSpDefense = 40,
        .types = { TYPE_BUG, TYPE_FAIRY },
        .catchRate = 190,
        .expYield = 61,
        .evYield_Speed = 1,
        .itemRare = ITEM_HONEY,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_BUG, EGG_GROUP_FAIRY },
        .abilities = { ABILITY_HONEY_GATHER, ABILITY_SHIELD_DUST, ABILITY_SWEET_VEIL },
        .bodyColor = BODY_COLOR_YELLOW,
        .speciesName = _("Wommel"),
        .cryId = CRY_CUTIEFLY,
        .natDexNum = NATIONAL_DEX_CUTIEFLY,
        .categoryName = _("Hummelfliegen"),
        .height = 1,
        .weight = 2,
        .description = POKEDEX_DESC_STRING(
            "Über den Köpfen von Menschen, deren Auren\n"
            "denen von Blumen gleichen, finden sich\n"
            "zahlreich Wommel ein."),
        .pokemonScale = 682,
        .pokemonOffset = 24,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Cutiefly, 33, 35),
        .frontPicYOffset = 16,
        .frontAnimFrames = sAnims_Cutiefly,
        .frontAnimId = ANIM_H_SLIDE_WOBBLE,
        .enemyMonElevation = 10,
        BACK_PIC(Cutiefly, 56, 48),
        .backPicYOffset = 15,
        .backAnimId = BACK_ANIM_CONCAVE_ARC_LARGE,
        PALETTES(Cutiefly),
        ICON(Cutiefly, 2),
        .footprint = gMonFootprint_Cutiefly,
        LEARNSETS(Cutiefly),
        .evolutions = EVOLUTION({EVO_LEVEL, 25, SPECIES_RIBOMBEE}),
    },

    [SPECIES_RIBOMBEE] =
    {
        .baseHP        = 60,
        .baseAttack    = 55,
        .baseDefense   = 60,
        .baseSpeed     = 124,
        .baseSpAttack  = 95,
        .baseSpDefense = 70,
        .types = { TYPE_BUG, TYPE_FAIRY },
        .catchRate = 75,
        .expYield = 162,
        .evYield_Speed = 2,
        .itemRare = ITEM_HONEY,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_BUG, EGG_GROUP_FAIRY },
        .abilities = { ABILITY_HONEY_GATHER, ABILITY_SHIELD_DUST, ABILITY_SWEET_VEIL },
        .bodyColor = BODY_COLOR_YELLOW,
        .speciesName = _("Bandelby"),
        .cryId = CRY_RIBOMBEE,
        .natDexNum = NATIONAL_DEX_RIBOMBEE,
        .categoryName = _("Hummelfliegen"),
        .height = 2,
        .weight = 5,
        .description = POKEDEX_DESC_STRING(
            "Es kann anhand der Luftfeuchtigkeit und\n"
            "der Windrichtung das Wetter vorhersagen.\n"
            "Es zeigt sich nur bei klarem Wetter."),
        .pokemonScale = 682,
        .pokemonOffset = 24,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Ribombee, 32, 47),
        .frontPicYOffset = 5,
        .frontAnimFrames = sAnims_Ribombee,
        .frontAnimId = ANIM_CONVEX_DOUBLE_ARC_TWICE,
        .enemyMonElevation = 6,
        BACK_PIC(Ribombee, 56, 48),
        .backPicYOffset = 11,
        .backAnimId = BACK_ANIM_CONVEX_DOUBLE_ARC,
        PALETTES(Ribombee),
        ICON(Ribombee, 2),
        .footprint = gMonFootprint_Ribombee,
        LEARNSETS(Ribombee),
    },
#endif //P_FAMILY_CUTIEFLY

#if P_FAMILY_ROCKRUFF
#define ROCKRUFF_MISC_INFO                                      \
        .baseHP        = 45,                                    \
        .baseAttack    = 65,                                    \
        .baseDefense   = 40,                                    \
        .baseSpeed     = 60,                                    \
        .baseSpAttack  = 30,                                    \
        .baseSpDefense = 40,                                    \
        .types = { TYPE_ROCK, TYPE_ROCK },                      \
        .catchRate = 190,                                       \
        .expYield = 56,                                         \
        .evYield_Attack = 1,                                    \
        .genderRatio = PERCENT_FEMALE(50),                      \
        .eggCycles = 15,                                        \
        .friendship = STANDARD_FRIENDSHIP,                      \
        .growthRate = GROWTH_MEDIUM_FAST,                       \
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD },      \
        .bodyColor = BODY_COLOR_BROWN,                          \
        .speciesName = _("Bandelby"),                           \
        .cryId = CRY_ROCKRUFF,                                  \
        .natDexNum = NATIONAL_DEX_ROCKRUFF,                     \
        .categoryName = _("Hummelfliegen"),                             \
        .height = 5,                                            \
        .weight = 92,                                           \
        .description = gRockruffPokedexText,                    \
        .pokemonScale = 432,                                    \
        .pokemonOffset = 13,                                    \
        .trainerScale = 256,                                    \
        .trainerOffset = 0,                                     \
        .frontPicYOffset = 11,                                  \
        .frontAnimFrames = sAnims_Rockruff,                     \
        .frontAnimId = ANIM_V_STRETCH,                          \
        .backPicYOffset = 7,                                    \
        PALETTES(Rockruff),                                     \
        ICON(Rockruff, 2),                                      \
        .footprint = gMonFootprint_Rockruff,                    \
        LEARNSETS(Rockruff),                                    \
        .formSpeciesIdTable = sRockruffFormSpeciesIdTable

    [SPECIES_ROCKRUFF] =
    {
        ROCKRUFF_MISC_INFO,
        .abilities = { ABILITY_KEEN_EYE, ABILITY_VITAL_SPIRIT, ABILITY_STEADFAST },
        FRONT_PIC(Rockruff, 37, 39),
        BACK_PIC(Rockruff, 64, 56),
        .backAnimId = BACK_ANIM_V_STRETCH,
        .evolutions = EVOLUTION({EVO_LEVEL_DAY, 25, SPECIES_LYCANROC_MIDDAY},
                                {EVO_LEVEL_NIGHT, 25, SPECIES_LYCANROC_MIDNIGHT}),
    },

    [SPECIES_ROCKRUFF_OWN_TEMPO] =
    {
        ROCKRUFF_MISC_INFO,
        .abilities = { ABILITY_OWN_TEMPO, ABILITY_NONE, ABILITY_NONE },
        FRONT_PIC(Rockruff, 40, 48),
        BACK_PIC(Rockruff, 64, 56),
        //.backAnimId = BACK_ANIM_NONE,
        .evolutions = EVOLUTION({EVO_LEVEL_DUSK, 25, SPECIES_LYCANROC_DUSK}),
    },

#define LYCANROC_MISC_INFO                                  \
        .types = { TYPE_ROCK, TYPE_ROCK },                  \
        .catchRate = 90,                                    \
        .expYield = 170,                                    \
        .evYield_Attack = 2,                                \
        .genderRatio = PERCENT_FEMALE(50),                  \
        .eggCycles = 15,                                    \
        .friendship = STANDARD_FRIENDSHIP,                  \
        .growthRate = GROWTH_MEDIUM_FAST,                   \
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD },  \
        .speciesName = _("Wuffels"),                       \
        .natDexNum = NATIONAL_DEX_LYCANROC,                 \
        .categoryName = _("Welpen"),                          \
        .weight = 250,                                      \
        .pokemonScale = 366,                                \
        .pokemonOffset = 7,                                 \
        .trainerScale = 257,                                \
        .trainerOffset = 0,                                 \
        BACK_PIC(LycanrocMidday, 64, 56),                   \
        .footprint = gMonFootprint_Lycanroc,                \
        .formSpeciesIdTable = sLycanrocFormSpeciesIdTable

    [SPECIES_LYCANROC_MIDDAY] =
    {
        LYCANROC_MISC_INFO,
        .baseHP        = 75,
        .baseAttack    = 115,
        .baseDefense   = 65,
        .baseSpeed     = 112,
        .baseSpAttack  = 55,
        .baseSpDefense = 65,
        .abilities = { ABILITY_KEEN_EYE, ABILITY_SAND_RUSH, ABILITY_STEADFAST },
        .bodyColor = BODY_COLOR_BROWN,
        .cryId = CRY_LYCANROC_MIDDAY,
        .height = 8,
        .description = POKEDEX_DESC_STRING(
            "Irritiert seine Feinde mit\n"
            "schnellen Bewegungen. Als Waffen\n"
            "hat es nicht nur Krallen und Hauer,\n"
            "sondern auch die spitzen Felsen\n"
            "seiner Mähne."),
        FRONT_PIC(LycanrocMidday, 57, 53),
        .frontPicYOffset = 5,
        .frontAnimFrames = sAnims_LycanrocMidday,
        .frontAnimId = ANIM_V_SHAKE,
        .backPicYOffset = 7,
        .backAnimId = BACK_ANIM_V_SHAKE,
        PALETTES(LycanrocMidday),
        ICON(LycanrocMidday, 2),
        LEARNSETS(LycanrocMidday),
    },

    [SPECIES_LYCANROC_MIDNIGHT] =
    {
        LYCANROC_MISC_INFO,
        .baseHP        = 85,
        .baseAttack    = 115,
        .baseDefense   = 75,
        .baseSpeed     = 82,
        .baseSpAttack  = 55,
        .baseSpDefense = 75,
        .abilities = { ABILITY_KEEN_EYE, ABILITY_VITAL_SPIRIT, ABILITY_NO_GUARD },
        .bodyColor = BODY_COLOR_RED,
        .cryId = CRY_LYCANROC_MIDNIGHT,
        .height = 11,
        .description = POKEDEX_DESC_STRING(
            "Irritiert seine Feinde mit\n"
            "schnellen Bewegungen. Als Waffen\n"
            "hat es nicht nur Krallen und Hauer,\n"
            "sondern auch die spitzen Felsen\n"
            "seiner Mähne."),
        FRONT_PIC(LycanrocMidnight, 56, 61),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_LycanrocMidnight,
        .frontAnimId = ANIM_SHRINK_GROW_VIBRATE_SLOW,
        .backPicYOffset = 7,
        .backAnimId = BACK_ANIM_SHRINK_GROW_VIBRATE,
        PALETTES(LycanrocMidnight),
        ICON(LycanrocMidnight, 0),
        LEARNSETS(LycanrocMidnight),
    },

    [SPECIES_LYCANROC_DUSK] =
    {
        LYCANROC_MISC_INFO,
        .baseHP        = 75,
        .baseAttack    = 117,
        .baseDefense   = 65,
        .baseSpeed     = 110,
        .baseSpAttack  = 55,
        .baseSpDefense = 65,
        .abilities = { ABILITY_TOUGH_CLAWS, ABILITY_NONE },
        .bodyColor = BODY_COLOR_BROWN,
        .cryId = CRY_LYCANROC_DUSK,
        .height = 8,
        .description = POKEDEX_DESC_STRING(
            "Irritiert seine Feinde mit\n"
            "schnellen Bewegungen. Als Waffen\n"
            "hat es nicht nur Krallen und Hauer,\n"
            "sondern auch die spitzen Felsen\n"
            "seiner Mähne."),
        FRONT_PIC(LycanrocDusk, 57, 58),
        .frontPicYOffset = 6,
        .frontAnimFrames = sAnims_LycanrocDusk,
        .frontAnimId = ANIM_V_SHAKE,
        .backPicYOffset = 5,
        .backAnimId = BACK_ANIM_V_SHAKE,
        PALETTES(LycanrocDusk),
        ICON(LycanrocDusk, 0),
        LEARNSETS(LycanrocDusk),
    },
#endif //P_FAMILY_ROCKRUFF

#if P_FAMILY_WISHIWASHI
#define WISHIWASHI_MISC_INFO                                    \
        .types = { TYPE_WATER, TYPE_WATER },                    \
        .catchRate = 60,                                        \
        .expYield = 61,                                         \
        .evYield_HP = 1,                                        \
        .genderRatio = PERCENT_FEMALE(50),                      \
        .eggCycles = 15,                                        \
        .friendship = STANDARD_FRIENDSHIP,                      \
        .growthRate = GROWTH_FAST,                              \
        .eggGroups = { EGG_GROUP_WATER_2, EGG_GROUP_WATER_2 },  \
        .abilities = { ABILITY_SCHOOLING, ABILITY_NONE },       \
        .bodyColor = BODY_COLOR_BLUE,                           \
        .speciesName = _("Wolwerock"),                         \
        .natDexNum = NATIONAL_DEX_WISHIWASHI,                   \
        .categoryName = _("Wolfs"),                         \
        .pokemonScale = 682,                                    \
        .pokemonOffset = 24,                                    \
        .trainerScale = 256,                                    \
        .trainerOffset = 0,                                     \
        .footprint = gMonFootprint_Wishiwashi,                  \
        LEARNSETS(Wishiwashi),                                  \
        .formSpeciesIdTable = sWishiwashiFormSpeciesIdTable,    \
        .formChangeTable = sWishiwashiFormChangeTable

    [SPECIES_WISHIWASHI_SOLO] =
    {
        WISHIWASHI_MISC_INFO,
        .baseHP        = 45,
        .baseAttack    = 20,
        .baseDefense   = 20,
        .baseSpeed     = 40,
        .baseSpAttack  = 25,
        .baseSpDefense = 25,
        .cryId = CRY_WISHIWASHI_SOLO,
        .height = 2,
        .weight = 3,
        .description = POKEDEX_DESC_STRING(
            "Gerät es in Not, tränen seine\n"
            "Augen. Ihr Glänzen lockt\n"
            "Artgenossen an, mit denen es dann\n"
            "im Verbund den Feind angreift."),
        FRONT_PIC(WishiwashiSolo, 40, 24),
        .frontPicYOffset = 20,
        .frontAnimFrames = sAnims_WishiwashiSolo,
        .frontAnimId = ANIM_V_SLIDE_WOBBLE_SMALL,
        .enemyMonElevation = 12,
        BACK_PIC(WishiwashiSolo, 56, 32),
        .backPicYOffset = 18,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(WishiwashiSolo),
        ICON(WishiwashiSolo, 2),
    },

    [SPECIES_WISHIWASHI_SCHOOL] =
    {
        WISHIWASHI_MISC_INFO,
        .baseHP        = 45,
        .baseAttack    = 140,
        .baseDefense   = 130,
        .baseSpeed     = 30,
        .baseSpAttack  = 140,
        .baseSpDefense = 135,
        .cryId = CRY_WISHIWASHI_SCHOOL,
        .height = 82,
        .weight = 786,
        .description = POKEDEX_DESC_STRING(
            "Gerät es in Not, tränen seine\n"
            "Augen. Ihr Glänzen lockt\n"
            "Artgenossen an, mit denen es dann\n"
            "im Verbund den Feind angreift."),
        FRONT_PIC(WishiwashiSchool, 64, 64),
        .frontPicYOffset = 4,
        .frontAnimFrames = sAnims_WishiwashiSchool,
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE, //Todo
        BACK_PIC(WishiwashiSchool, 64, 56),
        .backPicYOffset = 5,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(WishiwashiSchool),
        ICON(WishiwashiSchool, 0),
    },
#endif //P_FAMILY_WISHIWASHI

#if P_FAMILY_MAREANIE
    [SPECIES_MAREANIE] =
    {
        .baseHP        = 50,
        .baseAttack    = 53,
        .baseDefense   = 62,
        .baseSpeed     = 45,
        .baseSpAttack  = 43,
        .baseSpDefense = 52,
        .types = { TYPE_POISON, TYPE_WATER },
        .catchRate = 190,
        .expYield = 61,
        .evYield_Defense = 1,
        .itemRare = ITEM_POISON_BARB,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_WATER_1, EGG_GROUP_WATER_1 },
        .abilities = { ABILITY_MERCILESS, ABILITY_LIMBER, ABILITY_REGENERATOR },
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Garstella"),
        .cryId = CRY_MAREANIE,
        .natDexNum = NATIONAL_DEX_MAREANIE,
        .categoryName = _("Quäl-Stern"),
        .height = 4,
        .weight = 80,
        .description = POKEDEX_DESC_STRING(
            "Im Gegensatz zu den Garstella in Alola\n"
            "haben die der Galar-Region noch nicht\n"
            "bemerkt, wie köstlich die Arme von\n"
            "Corasonn sind."),
        .pokemonScale = 491,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Mareanie, 48, 40),
        .frontPicYOffset = 14,
        .frontAnimFrames = sAnims_Mareanie,
        .frontAnimId = ANIM_GLOW_PURPLE,
        BACK_PIC(Mareanie, 64, 48),
        .backPicYOffset = 15,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(Mareanie),
        ICON(Mareanie, 2),
        .footprint = gMonFootprint_Mareanie,
        LEARNSETS(Mareanie),
        .evolutions = EVOLUTION({EVO_LEVEL, 38, SPECIES_TOXAPEX}),
    },

    [SPECIES_TOXAPEX] =
    {
        .baseHP        = 50,
        .baseAttack    = 63,
        .baseDefense   = 152,
        .baseSpeed     = 35,
        .baseSpAttack  = 53,
        .baseSpDefense = 142,
        .types = { TYPE_POISON, TYPE_WATER },
        .catchRate = 75,
        .expYield = 173,
        .evYield_Defense = 2,
        .itemRare = ITEM_POISON_BARB,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_WATER_1, EGG_GROUP_WATER_1 },
        .abilities = { ABILITY_MERCILESS, ABILITY_LIMBER, ABILITY_REGENERATOR },
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Aggrostella"),
        .cryId = CRY_TOXAPEX,
        .natDexNum = NATIONAL_DEX_TOXAPEX,
        .categoryName = _("Quäl-Stern"),
        .height = 7,
        .weight = 145,
        .description = POKEDEX_DESC_STRING(
            "Kriecht mit seinen zwölf Beinen\n"
            "über den Meeresboden. Es\n"
            "hinterlässt oft etliche Überreste\n"
            "von Corasonn."),
        .pokemonScale = 365,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Toxapex, 64, 64),
        .frontPicYOffset = 2,
        .frontAnimFrames = sAnims_Toxapex,
        .frontAnimId = ANIM_SHAKE_GLOW_PURPLE_SLOW,
        BACK_PIC(Toxapex, 64, 56),
        .backPicYOffset = 8,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(Toxapex),
        ICON(Toxapex, 0),
        .footprint = gMonFootprint_Toxapex,
        LEARNSETS(Toxapex),
    },
#endif //P_FAMILY_MAREANIE

#if P_FAMILY_MUDBRAY
    [SPECIES_MUDBRAY] =
    {
        .baseHP        = 70,
        .baseAttack    = 100,
        .baseDefense   = 70,
        .baseSpeed     = 45,
        .baseSpAttack  = 45,
        .baseSpDefense = 55,
        .types = { TYPE_GROUND, TYPE_GROUND },
        .catchRate = 190,
        .expYield = 77,
        .evYield_Attack = 1,
        .itemRare = ITEM_LIGHT_CLAY,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD },
        .abilities = { ABILITY_OWN_TEMPO, ABILITY_STAMINA, ABILITY_INNER_FOCUS },
        .bodyColor = BODY_COLOR_BROWN,
        .speciesName = _("Pampuli"),
        .cryId = CRY_MUDBRAY,
        .natDexNum = NATIONAL_DEX_MUDBRAY,
        .categoryName = _("Packesel"),
        .height = 10,
        .weight = 1100,
        .description = POKEDEX_DESC_STRING(
            "Der ganze Schlamm an seinen Füßen\n"
            "sorgt für die nötige Bodenhaftung,\n"
            "die es für seinen kraftvollen Lauf\n"
            "braucht."),
        .pokemonScale = 305,
        .pokemonOffset = 7,
        .trainerScale = 257,
        .trainerOffset = 0,
        FRONT_PIC(Mudbray, 48, 56),
        .frontPicYOffset = 7,
        .frontAnimFrames = sAnims_Mudbray,
        .frontAnimId = ANIM_V_SHAKE,
        BACK_PIC(Mudbray, 64, 56),
        .backPicYOffset = 8,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(Mudbray),
        ICON(Mudbray, 2),
        .footprint = gMonFootprint_Mudbray,
        LEARNSETS(Mudbray),
        .evolutions = EVOLUTION({EVO_LEVEL, 30, SPECIES_MUDSDALE}),
    },

    [SPECIES_MUDSDALE] =
    {
        .baseHP        = 100,
        .baseAttack    = 125,
        .baseDefense   = 100,
        .baseSpeed     = 35,
        .baseSpAttack  = 55,
        .baseSpDefense = 85,
        .types = { TYPE_GROUND, TYPE_GROUND },
        .catchRate = 60,
        .expYield = 175,
        .evYield_Attack = 2,
        .itemRare = ITEM_LIGHT_CLAY,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD },
        .abilities = { ABILITY_OWN_TEMPO, ABILITY_STAMINA, ABILITY_INNER_FOCUS },
        .bodyColor = BODY_COLOR_BROWN,
        .speciesName = _("Pampross"),
        .cryId = CRY_MUDSDALE,
        .natDexNum = NATIONAL_DEX_MUDSDALE,
        .categoryName = _("Zugpferd"),
        .height = 25,
        .weight = 9200,
        .description = POKEDEX_DESC_STRING(
            "Sein wohl bester Angriff ist ein heftiger,\n"
            "schlammiger Tritt. Damit kann es auch\n"
            "große Laster mühelos verschrotten."),
        .pokemonScale = 257,
        .pokemonOffset = 10,
        .trainerScale = 423,
        .trainerOffset = 8,
        FRONT_PIC(Mudsdale, 64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_Mudsdale,
        .frontAnimId = ANIM_V_SHAKE_TWICE,
        BACK_PIC(Mudsdale, 64, 56),
        .backPicYOffset = 5,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(Mudsdale),
        ICON(Mudsdale, 0),
        .footprint = gMonFootprint_Mudsdale,
        LEARNSETS(Mudsdale),
    },
#endif //P_FAMILY_MUDBRAY

#if P_FAMILY_DEWPIDER
    [SPECIES_DEWPIDER] =
    {
        .baseHP        = 38,
        .baseAttack    = 40,
        .baseDefense   = 52,
        .baseSpeed     = 27,
        .baseSpAttack  = 40,
        .baseSpDefense = 72,
        .types = { TYPE_WATER, TYPE_BUG },
        .catchRate = 200,
        .expYield = 54,
        .evYield_SpDefense = 1,
        .itemRare = ITEM_MYSTIC_WATER,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_WATER_1, EGG_GROUP_BUG },
        .abilities = { ABILITY_WATER_BUBBLE, ABILITY_NONE, ABILITY_WATER_ABSORB },
        .bodyColor = BODY_COLOR_GREEN,
        .speciesName = _("Araqua"),
        .cryId = CRY_DEWPIDER,
        .natDexNum = NATIONAL_DEX_DEWPIDER,
        .categoryName = _("Wasserblasen"),
        .height = 3,
        .weight = 40,
        .description = POKEDEX_DESC_STRING(
            "Die Futtersuche treibt es an Land.\n"
            "Eine Wasserblase versorgt es mit\n"
            "Atemluft und schützt zugleich\n"
            "seinen weichen Kopf."),
        .pokemonScale = 530,
        .pokemonOffset = 13,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Dewpider, 32, 48),
        .frontPicYOffset = 13,
        .frontAnimFrames = sAnims_Dewpider,
        .frontAnimId = ANIM_SHRINK_GROW,
        BACK_PIC(Dewpider, 40, 48),
        .backPicYOffset = 8,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(Dewpider),
        ICON(Dewpider, 0),
        .footprint = gMonFootprint_Dewpider,
        LEARNSETS(Dewpider),
        .evolutions = EVOLUTION({EVO_LEVEL, 22, SPECIES_ARAQUANID}),
    },

    [SPECIES_ARAQUANID] =
    {
        .baseHP        = 68,
        .baseAttack    = 70,
        .baseDefense   = 92,
        .baseSpeed     = 42,
        .baseSpAttack  = 50,
        .baseSpDefense = 132,
        .types = { TYPE_WATER, TYPE_BUG },
        .catchRate = 100,
        .expYield = 159,
        .evYield_SpDefense = 2,
        .itemRare = ITEM_MYSTIC_WATER,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_WATER_1, EGG_GROUP_BUG },
        .abilities = { ABILITY_WATER_BUBBLE, ABILITY_NONE, ABILITY_WATER_ABSORB },
        .bodyColor = BODY_COLOR_GREEN,
        .speciesName = _("Aranestro"),
        .cryId = CRY_ARAQUANID,
        .natDexNum = NATIONAL_DEX_ARAQUANID,
        .categoryName = _("Wasserblasen"),
        .height = 18,
        .weight = 820,
        .description = POKEDEX_DESC_STRING(
            "Es verteilt mit seiner Wasserblase\n"
            "Kopfstöße. Kleine Pokémon werden\n"
            "dabei hineingezogen und ertrinken."),
        .pokemonScale = 267,
        .pokemonOffset = 2,
        .trainerScale = 286,
        .trainerOffset = 1,
        FRONT_PIC(Araquanid, 64, 64),
        .frontPicYOffset = 2,
        .frontAnimFrames = sAnims_Araquanid,
        .frontAnimId = ANIM_H_SHAKE,
        BACK_PIC(Araquanid, 64, 48),
        .backPicYOffset = 12,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(Araquanid),
        ICON(Araquanid, 2),
        .footprint = gMonFootprint_Araquanid,
        LEARNSETS(Araquanid),
    },
#endif //P_FAMILY_DEWPIDER

#if P_FAMILY_FOMANTIS
    [SPECIES_FOMANTIS] =
    {
        .baseHP        = 40,
        .baseAttack    = 55,
        .baseDefense   = 35,
        .baseSpeed     = 35,
        .baseSpAttack  = 50,
        .baseSpDefense = 35,
        .types = { TYPE_GRASS, TYPE_GRASS },
        .catchRate = 190,
        .expYield = 50,
        .evYield_Attack = 1,
        .itemRare = ITEM_MIRACLE_SEED,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_GRASS, EGG_GROUP_GRASS },
        .abilities = { ABILITY_LEAF_GUARD, ABILITY_NONE, ABILITY_CONTRARY },
        .bodyColor = BODY_COLOR_PINK,
        .speciesName = _("Imantis"),
        .cryId = CRY_FOMANTIS,
        .natDexNum = NATIONAL_DEX_FOMANTIS,
        .categoryName = _("Grassichel"),
        .height = 3,
        .weight = 15,
        .description = POKEDEX_DESC_STRING(
            "Es liebt Sonnenlicht. Gönnt es sich\n"
            "regelmäßig Sonnenbäder, blüht es in\n"
            "prächtigen, satten Farben auf."),
        .pokemonScale = 530,
        .pokemonOffset = 13,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Fomantis, 40, 48),
        .frontPicYOffset = 11,
        .frontAnimFrames = sAnims_Fomantis,
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE_SLOW,
        BACK_PIC(Fomantis, 40, 56),
        .backPicYOffset = 5,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(Fomantis),
        ICON(Fomantis, 1),
        .footprint = gMonFootprint_Fomantis,
        LEARNSETS(Fomantis),
        .evolutions = EVOLUTION({EVO_LEVEL_DAY, 34, SPECIES_LURANTIS}),
    },

    [SPECIES_LURANTIS] =
    {
        .baseHP        = 70,
        .baseAttack    = 105,
        .baseDefense   = 90,
        .baseSpeed     = 45,
        .baseSpAttack  = 80,
        .baseSpDefense = 90,
        .types = { TYPE_GRASS, TYPE_GRASS },
        .catchRate = 75,
        .expYield = 168,
        .evYield_Attack = 2,
        .itemRare = ITEM_MIRACLE_SEED,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_GRASS, EGG_GROUP_GRASS },
        .abilities = { ABILITY_LEAF_GUARD, ABILITY_NONE, ABILITY_CONTRARY },
        .bodyColor = BODY_COLOR_PINK,
        .speciesName = _("Mantidea"),
        .cryId = CRY_LURANTIS,
        .natDexNum = NATIONAL_DEX_LURANTIS,
        .categoryName = _("Blumensichel"),
        .height = 9,
        .weight = 185,
        .description = POKEDEX_DESC_STRING(
            "Kann aus seinen sichelförmigen Blättern\n"
            "einen Strahl abschießen, der selbst eine\n"
            "Eisenplatte zerschneidet."),
        .pokemonScale = 338,
        .pokemonOffset = 8,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Lurantis, 48, 64),
        .frontPicYOffset = 2,
        .frontAnimFrames = sAnims_Lurantis,
        .frontAnimId = ANIM_GROW_VIBRATE,
        BACK_PIC(Lurantis, 56, 64),
        .backPicYOffset = 1,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(Lurantis),
        ICON(Lurantis, 1),
        .footprint = gMonFootprint_Lurantis,
        LEARNSETS(Lurantis),
    },
#endif //P_FAMILY_FOMANTIS

#if P_FAMILY_MORELULL
    [SPECIES_MORELULL] =
    {
        .baseHP        = 40,
        .baseAttack    = 35,
        .baseDefense   = 55,
        .baseSpeed     = 15,
        .baseSpAttack  = 65,
        .baseSpDefense = 75,
        .types = { TYPE_GRASS, TYPE_FAIRY },
        .catchRate = 190,
        .expYield = 57,
        .evYield_SpDefense = 1,
        .itemCommon = ITEM_TINY_MUSHROOM,
        .itemRare = ITEM_BIG_MUSHROOM,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_GRASS, EGG_GROUP_GRASS },
        .abilities = { ABILITY_ILLUMINATE, ABILITY_EFFECT_SPORE, ABILITY_RAIN_DISH },
        .bodyColor = BODY_COLOR_PURPLE,
        .speciesName = _("Bubungus"),
        .cryId = CRY_MORELULL,
        .natDexNum = NATIONAL_DEX_MORELULL,
        .categoryName = _("Lumineszenz"),
        .height = 2,
        .weight = 15,
        .description = POKEDEX_DESC_STRING(
            "Es streut blinkende Sporen aus.\n"
            "Jeder, der dieses Licht sieht,\n"
            "schläft fest ein."),
        .pokemonScale = 682,
        .pokemonOffset = 24,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Morelull, 24, 48),
        .frontPicYOffset = 10,
        .frontAnimFrames = sAnims_Morelull,
        .frontAnimId = ANIM_SHAKE_FLASH_YELLOW,
        BACK_PIC(Morelull, 40, 48),
        .backPicYOffset = 9,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(Morelull),
        ICON(Morelull, 0),
        .footprint = gMonFootprint_Morelull,
        LEARNSETS(Morelull),
        .evolutions = EVOLUTION({EVO_LEVEL, 24, SPECIES_SHIINOTIC}),
    },

    [SPECIES_SHIINOTIC] =
    {
        .baseHP        = 60,
        .baseAttack    = 45,
        .baseDefense   = 80,
        .baseSpeed     = 30,
        .baseSpAttack  = 90,
        .baseSpDefense = 100,
        .types = { TYPE_GRASS, TYPE_FAIRY },
        .catchRate = 75,
        .expYield = 142,
        .evYield_SpDefense = 2,
        .itemCommon = ITEM_TINY_MUSHROOM,
        .itemRare = ITEM_BIG_MUSHROOM,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_GRASS, EGG_GROUP_GRASS },
        .abilities = { ABILITY_ILLUMINATE, ABILITY_EFFECT_SPORE, ABILITY_RAIN_DISH },
        .bodyColor = BODY_COLOR_PURPLE,
        .speciesName = _("Lamellux"),
        .cryId = CRY_SHIINOTIC,
        .natDexNum = NATIONAL_DEX_SHIINOTIC,
        .categoryName = _("Lumineszenz"),
        .height = 10,
        .weight = 115,
        .description = POKEDEX_DESC_STRING(
            "Kommt es zwischen ihm und Parasek zu\n"
            "Revierkämpfen, ist hinterher die gesamte\n"
            "Umgebung mit Sporen bedeckt."),
        .pokemonScale = 305,
        .pokemonOffset = 7,
        .trainerScale = 257,
        .trainerOffset = 0,
        FRONT_PIC(Shiinotic, 56, 56),
        .frontPicYOffset = 4,
        .frontAnimFrames = sAnims_Shiinotic,
        .frontAnimId = ANIM_SHAKE_GLOW_WHITE_SLOW,
        BACK_PIC(Shiinotic, 64, 48),
        .backPicYOffset = 8,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(Shiinotic),
        ICON(Shiinotic, 1),
        .footprint = gMonFootprint_Shiinotic,
        LEARNSETS(Shiinotic),
    },
#endif //P_FAMILY_MORELULL

#if P_FAMILY_SALANDIT
    [SPECIES_SALANDIT] =
    {
        .baseHP        = 48,
        .baseAttack    = 44,
        .baseDefense   = 40,
        .baseSpeed     = 77,
        .baseSpAttack  = 71,
        .baseSpDefense = 40,
        .types = { TYPE_POISON, TYPE_FIRE },
        .catchRate = 120,
        .expYield = 64,
        .evYield_Speed = 1,
        .itemRare = ITEM_SMOKE_BALL,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_MONSTER, EGG_GROUP_DRAGON },
        .abilities = { ABILITY_CORROSION, ABILITY_NONE, ABILITY_OBLIVIOUS },
        .bodyColor = BODY_COLOR_BLACK,
        .speciesName = _("Molunk"),
        .cryId = CRY_SALANDIT,
        .natDexNum = NATIONAL_DEX_SALANDIT,
        .categoryName = _("Giftechsen"),
        .height = 6,
        .weight = 48,
        .description = POKEDEX_DESC_STRING(
            "Durch Verbrennung von\n"
            "Körperflüssigkeit erzeugt es ein\n"
            "Gas, das Feinde schwindelig und so\n"
            "zu leichten Zielen macht."),
        .pokemonScale = 422,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Salandit, 56, 40),
        .frontPicYOffset = 12,
        .frontAnimFrames = sAnims_Salandit,
        .frontAnimId = ANIM_GLOW_RED,
        BACK_PIC(Salandit, 56, 40),
        .backPicYOffset = 12,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(Salandit),
        ICON(Salandit, 2),
        .footprint = gMonFootprint_Salandit,
        LEARNSETS(Salandit),
        .evolutions = EVOLUTION({EVO_LEVEL_FEMALE, 33, SPECIES_SALAZZLE}),
    },

    [SPECIES_SALAZZLE] =
    {
        .baseHP        = 68,
        .baseAttack    = 64,
        .baseDefense   = 60,
        .baseSpeed     = 117,
        .baseSpAttack  = 111,
        .baseSpDefense = 60,
        .types = { TYPE_POISON, TYPE_FIRE },
        .catchRate = 45,
        .expYield = 168,
        .evYield_Speed = 2,
        .itemRare = ITEM_SMOKE_BALL,
        .genderRatio = MON_FEMALE,
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_MONSTER, EGG_GROUP_DRAGON },
        .abilities = { ABILITY_CORROSION, ABILITY_NONE, ABILITY_OBLIVIOUS },
        .bodyColor = BODY_COLOR_BLACK,
        .speciesName = _("Amfira"),
        .cryId = CRY_SALAZZLE,
        .natDexNum = NATIONAL_DEX_SALAZZLE,
        .categoryName = _("Giftechsen"),
        .height = 12,
        .weight = 222,
        .description = POKEDEX_DESC_STRING(
            "Ihr Giftgas enthält viele Pheromone.\n"
            "Verdünnt man es, lässt sich daraus ein\n"
            "sinnliches Parfüm herstellen."),
        .pokemonScale = 282,
        .pokemonOffset = 4,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Salazzle, 64, 64),
        .frontPicYOffset = 1,
        .frontAnimFrames = sAnims_Salazzle,
        .frontAnimId = ANIM_GROW_VIBRATE,
        BACK_PIC(Salazzle, 48, 64),
        .backPicYOffset = 3,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(Salazzle),
        ICON(Salazzle, 0),
        .footprint = gMonFootprint_Salazzle,
        LEARNSETS(Salazzle),
    },
#endif //P_FAMILY_SALANDIT

#if P_FAMILY_STUFFUL
    [SPECIES_STUFFUL] =
    {
        .baseHP        = 70,
        .baseAttack    = 75,
        .baseDefense   = 50,
        .baseSpeed     = 50,
        .baseSpAttack  = 45,
        .baseSpDefense = 50,
        .types = { TYPE_NORMAL, TYPE_FIGHTING },
        .catchRate = 140,
        .expYield = 68,
        .evYield_Attack = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD },
        .abilities = { ABILITY_FLUFFY, ABILITY_KLUTZ, ABILITY_CUTE_CHARM },
        .bodyColor = BODY_COLOR_PINK,
        .speciesName = _("Velursi"),
        .cryId = CRY_STUFFUL,
        .natDexNum = NATIONAL_DEX_STUFFUL,
        .categoryName = _("Wildfang"),
        .height = 5,
        .weight = 68,
        .description = POKEDEX_DESC_STRING(
            "Es sieht sehr süß aus, aber wehe,\n"
            "es wird wütend. Mit seinen Armen\n"
            "wirbelnd haut es selbst den\n"
            "stärksten Wrestler um."),
        .pokemonScale = 432,
        .pokemonOffset = 13,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Stufful, 48, 48),
        .frontPicYOffset = 10,
        .frontAnimFrames = sAnims_Stufful,
        .frontAnimId = ANIM_V_SHAKE,
        BACK_PIC(Stufful, 56, 40),
        .backPicYOffset = 12,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(Stufful),
        ICON(Stufful, 0),
        .footprint = gMonFootprint_Stufful,
        LEARNSETS(Stufful),
        .evolutions = EVOLUTION({EVO_LEVEL, 27, SPECIES_BEWEAR}),
    },

    [SPECIES_BEWEAR] =
    {
        .baseHP        = 120,
        .baseAttack    = 125,
        .baseDefense   = 80,
        .baseSpeed     = 60,
        .baseSpAttack  = 55,
        .baseSpDefense = 60,
        .types = { TYPE_NORMAL, TYPE_FIGHTING },
        .catchRate = 70,
        .expYield = 175,
        .evYield_Attack = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD },
        .abilities = { ABILITY_FLUFFY, ABILITY_KLUTZ, ABILITY_UNNERVE },
        .bodyColor = BODY_COLOR_PINK,
        .speciesName = _("Kosturso"),
        .cryId = CRY_BEWEAR,
        .natDexNum = NATIONAL_DEX_BEWEAR,
        .categoryName = _("Kraftarme"),
        .height = 21,
        .weight = 1350,
        .description = POKEDEX_DESC_STRING(
            "Dieses Pokémon verfügt über immense\n"
            "Muskelkraft und ist äußerst\n"
            "gefährlich. Sein Habitat ist\n"
            "generell Sperrgebiet."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 365,
        .trainerOffset = 7,
        FRONT_PIC(Bewear, 56, 64),
        .frontPicYOffset = 1,
        .frontAnimFrames = sAnims_Bewear,
        .frontAnimId = ANIM_H_STRETCH,
        BACK_PIC(Bewear, 64, 64),
        .backPicYOffset = 2,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(Bewear),
        ICON(Bewear, 0),
        .footprint = gMonFootprint_Bewear,
        LEARNSETS(Bewear),
    },
#endif //P_FAMILY_STUFFUL

#if P_FAMILY_BOUNSWEET
    [SPECIES_BOUNSWEET] =
    {
        .baseHP        = 42,
        .baseAttack    = 30,
        .baseDefense   = 38,
        .baseSpeed     = 32,
        .baseSpAttack  = 30,
        .baseSpDefense = 38,
        .types = { TYPE_GRASS, TYPE_GRASS },
        .catchRate = 235,
        .expYield = 42,
        .evYield_HP = 1,
        .itemRare = ITEM_GRASSY_SEED,
        .genderRatio = MON_FEMALE,
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_GRASS, EGG_GROUP_GRASS },
        .abilities = { ABILITY_LEAF_GUARD, ABILITY_OBLIVIOUS, ABILITY_SWEET_VEIL },
        .bodyColor = BODY_COLOR_PURPLE,
        .speciesName = _("Frubberl"),
        .cryId = CRY_BOUNSWEET,
        .natDexNum = NATIONAL_DEX_BOUNSWEET,
        .categoryName = _("Obst"),
        .height = 3,
        .weight = 32,
        .description = POKEDEX_DESC_STRING(
            "Der fruchtig süße Duft, der von seinem\n"
            "Körper ausgeht, lässt Vogel-Pokémon das\n"
            "Wasser im Schnabel zusammenlaufen."),
        .pokemonScale = 530,
        .pokemonOffset = 13,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Bounsweet, 32, 40),
        .frontPicYOffset = 16,
        .frontAnimFrames = sAnims_Bounsweet,
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(Bounsweet, 48, 40),
        .backPicYOffset = 14,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(Bounsweet),
        ICON(Bounsweet, 1),
        .footprint = gMonFootprint_Bounsweet,
        LEARNSETS(Bounsweet),
        .evolutions = EVOLUTION({EVO_LEVEL, 18, SPECIES_STEENEE}),
    },

    [SPECIES_STEENEE] =
    {
        .baseHP        = 52,
        .baseAttack    = 40,
        .baseDefense   = 48,
        .baseSpeed     = 62,
        .baseSpAttack  = 40,
        .baseSpDefense = 48,
        .types = { TYPE_GRASS, TYPE_GRASS },
        .catchRate = 120,
        .expYield = 102,
        .evYield_Speed = 2,
        .itemRare = ITEM_GRASSY_SEED,
        .genderRatio = MON_FEMALE,
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_GRASS, EGG_GROUP_GRASS },
        .abilities = { ABILITY_LEAF_GUARD, ABILITY_OBLIVIOUS, ABILITY_SWEET_VEIL },
        .bodyColor = BODY_COLOR_PURPLE,
        .noFlip = TRUE,
        .speciesName = _("Frubaila"),
        .cryId = CRY_STEENEE,
        .natDexNum = NATIONAL_DEX_STEENEE,
        .categoryName = _("Obst"),
        .height = 7,
        .weight = 82,
        .description = POKEDEX_DESC_STRING(
            "Es dreht sich tänzerisch um sich selbst\n"
            "und verströmt einen süßen Duft, der jeden\n"
            "glücklich macht, der ihn riecht."),
        .pokemonScale = 365,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Steenee, 48, 56),
        .frontPicYOffset = 7,
        .frontAnimFrames = sAnims_Steenee,
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(Steenee, 56, 56),
        .backPicYOffset = 8,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(Steenee),
        ICON(Steenee, 1),
        .footprint = gMonFootprint_Steenee,
        LEARNSETS(Steenee),
        .evolutions = EVOLUTION({EVO_MOVE, MOVE_STOMP, SPECIES_TSAREENA}),
    },

    [SPECIES_TSAREENA] =
    {
        .baseHP        = 72,
        .baseAttack    = 120,
        .baseDefense   = 98,
        .baseSpeed     = 72,
        .baseSpAttack  = 50,
        .baseSpDefense = 98,
        .types = { TYPE_GRASS, TYPE_GRASS },
        .catchRate = 45,
        .expYield = 230,
        .evYield_Attack = 3,
        .itemCommon = ITEM_GRASSY_SEED,
        .genderRatio = MON_FEMALE,
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_GRASS, EGG_GROUP_GRASS },
        .abilities = { ABILITY_LEAF_GUARD, ABILITY_QUEENLY_MAJESTY, ABILITY_SWEET_VEIL },
        .bodyColor = BODY_COLOR_PURPLE,
        .noFlip = TRUE,
        .speciesName = _("Fruyal"),
        .cryId = CRY_TSAREENA,
        .natDexNum = NATIONAL_DEX_TSAREENA,
        .categoryName = _("Obst"),
        .height = 12,
        .weight = 214,
        .description = POKEDEX_DESC_STRING(
            "Seine langen Beine und sein grausames Herz\n"
            "werden gefürchtet. Es tritt ohne Gnade auf\n"
            "seine Gegner ein."),
        .pokemonScale = 282,
        .pokemonOffset = 4,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Tsareena, 56, 64),
        .frontPicYOffset = 1,
        .frontAnimFrames = sAnims_Tsareena,
        .frontAnimId = ANIM_SHRINK_GROW,
        BACK_PIC(Tsareena, 56, 56),
        .backPicYOffset = 6,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(Tsareena),
        ICON(Tsareena, 1),
        .footprint = gMonFootprint_Tsareena,
        LEARNSETS(Tsareena),
    },
#endif //P_FAMILY_BOUNSWEET

#if P_FAMILY_COMFEY
    [SPECIES_COMFEY] =
    {
        .baseHP        = 51,
        .baseAttack    = 52,
        .baseDefense   = 90,
        .baseSpeed     = 100,
        .baseSpAttack  = 82,
        .baseSpDefense = 110,
        .types = { TYPE_FAIRY, TYPE_FAIRY },
        .catchRate = 60,
        .expYield = 170,
        .evYield_SpDefense = 2,
        .itemRare = ITEM_MISTY_SEED,
        .genderRatio = PERCENT_FEMALE(75),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_FAST,
        .eggGroups = { EGG_GROUP_GRASS, EGG_GROUP_GRASS },
        .abilities = { ABILITY_FLOWER_VEIL, ABILITY_TRIAGE, ABILITY_NATURAL_CURE },
        .bodyColor = BODY_COLOR_GREEN,
        .noFlip = TRUE,
        .speciesName = _("Curelei"),
        .cryId = CRY_COMFEY,
        .natDexNum = NATIONAL_DEX_COMFEY,
        .categoryName = _("Blumenkranz"),
        .height = 1,
        .weight = 3,
        .description = POKEDEX_DESC_STRING(
            "Dieses Pokémon riecht äußerst angenehm. Da\n"
            "jedes Curelei andere Blumen trägt,\n"
            "unterscheiden sie sich in ihrem Duft."),
        .pokemonScale = 682,
        .pokemonOffset = 24,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Comfey, 48, 48),
        .frontPicYOffset = 9,
        .frontAnimFrames = sAnims_Comfey,
        .frontAnimId = ANIM_H_SLIDE_WOBBLE,
        .enemyMonElevation = 8,
        BACK_PIC(Comfey, 64, 56),
        .backPicYOffset = 11,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(Comfey),
        ICON(Comfey, 1),
        .footprint = gMonFootprint_Comfey,
        LEARNSETS(Comfey),
    },
#endif //P_FAMILY_COMFEY

#if P_FAMILY_ORANGURU
    [SPECIES_ORANGURU] =
    {
        .baseHP        = 90,
        .baseAttack    = 60,
        .baseDefense   = 80,
        .baseSpeed     = 60,
        .baseSpAttack  = 90,
        .baseSpDefense = 110,
        .types = { TYPE_NORMAL, TYPE_PSYCHIC },
        .catchRate = 45,
        .expYield = 172,
        .evYield_SpDefense = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD },
        .abilities = { ABILITY_INNER_FOCUS, ABILITY_TELEPATHY, ABILITY_SYMBIOSIS },
        .bodyColor = BODY_COLOR_WHITE,
        .speciesName = _("Kommandutan"),
        .cryId = CRY_ORANGURU,
        .natDexNum = NATIONAL_DEX_ORANGURU,
        .categoryName = _("Weisheits"),
        .height = 15,
        .weight = 760,
        .description = POKEDEX_DESC_STRING(
            "Kommandutan kommen nicht gut miteinander\n"
            "aus. Ständig wetteifern sie, wer von ihnen\n"
            "wohl am klügsten sei."),
        .pokemonScale = 268,
        .pokemonOffset = 2,
        .trainerScale = 271,
        .trainerOffset = 0,
        FRONT_PIC(Oranguru, 56, 56),
        .frontPicYOffset = 5,
        .frontAnimFrames = sAnims_Oranguru,
        .frontAnimId = ANIM_SHRINK_GROW_SLOW,
        BACK_PIC(Oranguru, 64, 48),
        .backPicYOffset = 12,
        .backAnimId = BACK_ANIM_H_SLIDE,
        PALETTES(Oranguru),
        ICON(Oranguru, 0),
        .footprint = gMonFootprint_Oranguru,
        LEARNSETS(Oranguru),
    },
#endif //P_FAMILY_ORANGURU

#if P_FAMILY_PASSIMIAN
    [SPECIES_PASSIMIAN] =
    {
        .baseHP        = 100,
        .baseAttack    = 120,
        .baseDefense   = 90,
        .baseSpeed     = 80,
        .baseSpAttack  = 40,
        .baseSpDefense = 60,
        .types = { TYPE_FIGHTING, TYPE_FIGHTING },
        .catchRate = 45,
        .expYield = 172,
        .evYield_Attack = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD },
        .abilities = { ABILITY_RECEIVER, ABILITY_NONE, ABILITY_DEFIANT },
        .bodyColor = BODY_COLOR_WHITE,
        .speciesName = _("Quartermak"),
        .cryId = CRY_PASSIMIAN,
        .natDexNum = NATIONAL_DEX_PASSIMIAN,
        .categoryName = _("Teamwork"),
        .height = 20,
        .weight = 828,
        .description = POKEDEX_DESC_STRING(
            "Bei der Beerensuche stellen sie ihre\n"
            "Legendäre Teamfähigkeit unter Beweis,\n"
            "indem sie als Gruppe die Befehle des\n"
            "Anführers befolgen."),
        .pokemonScale = 261,
        .pokemonOffset = 1,
        .trainerScale = 334,
        .trainerOffset = 4,
        FRONT_PIC(Passimian, 57, 60),
        .frontPicYOffset = 2,
        .frontAnimFrames = sAnims_Passimian,
        .frontAnimId = ANIM_H_SHAKE,
        BACK_PIC(Passimian, 51, 52),
        .backPicYOffset = 7,
        .backAnimId = BACK_ANIM_H_SHAKE,
        PALETTES(Passimian),
        ICON(Passimian, 1),
        .footprint = gMonFootprint_Passimian,
        LEARNSETS(Passimian),
    },
#endif //P_FAMILY_PASSIMIAN

#if P_FAMILY_WIMPOD
    [SPECIES_WIMPOD] =
    {
        .baseHP        = 25,
        .baseAttack    = 35,
        .baseDefense   = 40,
        .baseSpeed     = 80,
        .baseSpAttack  = 20,
        .baseSpDefense = 30,
        .types = { TYPE_BUG, TYPE_WATER },
        .catchRate = 90,
        .expYield = 46,
        .evYield_Speed = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_BUG, EGG_GROUP_WATER_3 },
        .abilities = { ABILITY_WIMP_OUT, ABILITY_NONE },
        .bodyColor = BODY_COLOR_GRAY,
        .speciesName = _("Reißlaus"),
        .cryId = CRY_WIMPOD,
        .natDexNum = NATIONAL_DEX_WIMPOD,
        .categoryName = _("Laufschritt"),
        .height = 5,
        .weight = 120,
        .description = POKEDEX_DESC_STRING(
            "Dieses Pokémon ist ein wahrer\n"
            "Drückeberger. Sobald sich ihm etwas\n"
            "nähert, strampelt es flink mit seinen\n"
            "Beinchen und nimmt Reißaus."),
        .pokemonScale = 432,
        .pokemonOffset = 13,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Wimpod, 40, 40),
        .frontPicYOffset = 14,
        .frontAnimFrames = sAnims_Wimpod,
        .frontAnimId = ANIM_V_SHAKE_H_SLIDE_FAST,
        BACK_PIC(Wimpod, 64, 48),
        .backPicYOffset = 10,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(Wimpod),
        ICON(Wimpod, 2),
        .footprint = gMonFootprint_Wimpod,
        LEARNSETS(Wimpod),
        .evolutions = EVOLUTION({EVO_LEVEL, 30, SPECIES_GOLISOPOD}),
    },

    [SPECIES_GOLISOPOD] =
    {
        .baseHP        = 75,
        .baseAttack    = 125,
        .baseDefense   = 140,
        .baseSpeed     = 40,
        .baseSpAttack  = 60,
        .baseSpDefense = 90,
        .types = { TYPE_BUG, TYPE_WATER },
        .catchRate = 45,
        .expYield = 186,
        .evYield_Defense = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_BUG, EGG_GROUP_WATER_3 },
        .abilities = { ABILITY_EMERGENCY_EXIT, ABILITY_NONE },
        .bodyColor = BODY_COLOR_GRAY,
        .speciesName = _("Tectass"),
        .cryId = CRY_GOLISOPOD,
        .natDexNum = NATIONAL_DEX_GOLISOPOD,
        .categoryName = _("Rüstungs"),
        .height = 20,
        .weight = 1080,
        .description = POKEDEX_DESC_STRING(
            "Mithilfe seiner riesigen,\n"
            "glitzernden Klauen zerteilt es\n"
            "selbst Luft und Salzwasser mit\n"
            "einem Hieb."),
        .pokemonScale = 261,
        .pokemonOffset = 1,
        .trainerScale = 334,
        .trainerOffset = 4,
        FRONT_PIC(Golisopod, 64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_Golisopod,
        .frontAnimId = ANIM_SHRINK_GROW_VIBRATE_FAST,
        BACK_PIC(Golisopod, 64, 48),
        .backPicYOffset = 9,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(Golisopod),
        ICON(Golisopod, 2),
        .footprint = gMonFootprint_Golisopod,
        LEARNSETS(Golisopod),
    },
#endif //P_FAMILY_WIMPOD

#if P_FAMILY_SANDYGAST
    [SPECIES_SANDYGAST] =
    {
        .baseHP        = 55,
        .baseAttack    = 55,
        .baseDefense   = 80,
        .baseSpeed     = 15,
        .baseSpAttack  = 70,
        .baseSpDefense = 45,
        .types = { TYPE_GHOST, TYPE_GROUND },
        .catchRate = 140,
        .expYield = 64,
        .evYield_Defense = 1,
        .itemRare = ITEM_SPELL_TAG,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_AMORPHOUS, EGG_GROUP_AMORPHOUS },
        .abilities = { ABILITY_WATER_COMPACTION, ABILITY_NONE, ABILITY_SAND_VEIL },
        .bodyColor = BODY_COLOR_BROWN,
        .speciesName = _("Sankabuh"),
        .cryId = CRY_SANDYGAST,
        .natDexNum = NATIONAL_DEX_SANDYGAST,
        .categoryName = _("Sandhaufen"),
        .height = 5,
        .weight = 700,
        .description = POKEDEX_DESC_STRING(
            "Die Schaufel auf seinem Kopf ist sein\n"
            "größter Schatz. Versucht ein Kind, sich\n"
            "seine Schaufel zurückzuholen, gibt es\n"
            "diese nicht kampflos auf."),
        .pokemonScale = 432,
        .pokemonOffset = 13,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Sandygast, 48, 48),
        .frontPicYOffset = 11,
        .frontAnimFrames = sAnims_Sandygast,
        .frontAnimId = ANIM_CIRCULAR_STRETCH_TWICE,
        BACK_PIC(Sandygast, 40, 48),
        .backPicYOffset = 11,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(Sandygast),
        ICON(Sandygast, 1),
        .footprint = gMonFootprint_Sandygast,
        LEARNSETS(Sandygast),
        .evolutions = EVOLUTION({EVO_LEVEL, 42, SPECIES_PALOSSAND}),
    },

    [SPECIES_PALOSSAND] =
    {
        .baseHP        = 85,
        .baseAttack    = 75,
        .baseDefense   = 110,
        .baseSpeed     = 35,
        .baseSpAttack  = 100,
        .baseSpDefense = 75,
        .types = { TYPE_GHOST, TYPE_GROUND },
        .catchRate = 60,
        .expYield = 168,
        .evYield_Defense = 2,
        .itemRare = ITEM_SPELL_TAG,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_AMORPHOUS, EGG_GROUP_AMORPHOUS },
        .abilities = { ABILITY_WATER_COMPACTION, ABILITY_NONE, ABILITY_SAND_VEIL },
        .bodyColor = BODY_COLOR_BROWN,
        .speciesName = _("Colossand"),
        .cryId = CRY_PALOSSAND,
        .natDexNum = NATIONAL_DEX_PALOSSAND,
        .categoryName = _("Sandschloss"),
        .height = 13,
        .weight = 2500,
        .description = POKEDEX_DESC_STRING(
            "Unter seiner Sandburg liegen zahlreiche\n"
            "Knochen qualvoll Verstorbener, denen die\n"
            "Lebenskraft ausgesaugt wurde."),
        .pokemonScale = 272,
        .pokemonOffset = 3,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Palossand, 64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_Palossand,
        .frontAnimId = ANIM_H_VIBRATE,
        BACK_PIC(Palossand, 64, 64),
        .backPicYOffset = 2,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(Palossand),
        ICON(Palossand, 2),
        .footprint = gMonFootprint_Palossand,
        LEARNSETS(Palossand),
    },
#endif //P_FAMILY_SANDYGAST

#if P_FAMILY_PYUKUMUKU
    [SPECIES_PYUKUMUKU] =
    {
        .baseHP        = 55,
        .baseAttack    = 60,
        .baseDefense   = 130,
        .baseSpeed     = 5,
        .baseSpAttack  = 30,
        .baseSpDefense = 130,
        .types = { TYPE_WATER, TYPE_WATER },
        .catchRate = 60,
        .expYield = 144,
        .evYield_SpDefense = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_FAST,
        .eggGroups = { EGG_GROUP_WATER_1, EGG_GROUP_WATER_1 },
        .abilities = { ABILITY_INNARDS_OUT, ABILITY_NONE, ABILITY_UNAWARE },
        .bodyColor = BODY_COLOR_BLACK,
        .speciesName = _("Gufa"),
        .cryId = CRY_PYUKUMUKU,
        .natDexNum = NATIONAL_DEX_PYUKUMUKU,
        .categoryName = _("Seegurken"),
        .height = 3,
        .weight = 12,
        .description = POKEDEX_DESC_STRING(
            "Es lebt häufig an Stränden. Seine\n"
            "Schleimschicht eignet sich nach jedem\n"
            "Sonnenbad optimal zur Hautpflege."),
        .pokemonScale = 530,
        .pokemonOffset = 13,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Pyukumuku, 40, 40),
        .frontPicYOffset = 15,
        .frontAnimFrames = sAnims_Pyukumuku,
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(Pyukumuku, 48, 32),
        .backPicYOffset = 16,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(Pyukumuku),
        ICON(Pyukumuku, 0),
        .footprint = gMonFootprint_Pyukumuku,
        LEARNSETS(Pyukumuku),
    },
#endif //P_FAMILY_PYUKUMUKU

#if P_FAMILY_TYPE_NULL
    [SPECIES_TYPE_NULL] =
    {
        .baseHP        = 95,
        .baseAttack    = 95,
        .baseDefense   = 95,
        .baseSpeed     = 59,
        .baseSpAttack  = 95,
        .baseSpDefense = 95,
        .types = { TYPE_NORMAL, TYPE_NORMAL },
        .catchRate = 3,
        .expYield = 107,
        .evYield_HP = 2,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_NO_EGGS_DISCOVERED, EGG_GROUP_NO_EGGS_DISCOVERED },
        .abilities = { ABILITY_BATTLE_ARMOR, ABILITY_NONE },
        .bodyColor = BODY_COLOR_GRAY,
        .isLegendary = TRUE,
        .speciesName = _("Typ:Null"),
        .cryId = CRY_TYPE_NULL,
        .natDexNum = NATIONAL_DEX_TYPE_NULL,
        .categoryName = _("Modifikations"),
        .height = 19,
        .weight = 1205,
        .description = POKEDEX_DESC_STRING(
            "Seine schwere Maske unterdrückt\n"
            "seine wahre Macht. In ihm\n"
            "schlummern nämlich besondere\n"
            "Kräfte."),
        .pokemonScale = 256,
        .pokemonOffset = 1,
        .trainerScale = 326,
        .trainerOffset = 4,
        FRONT_PIC(TypeNull, 64, 64),
        .frontPicYOffset = 2,
        .frontAnimFrames = sAnims_TypeNull,
        .frontAnimId = ANIM_H_SHAKE,
        BACK_PIC(TypeNull, 56, 64),
        .backPicYOffset = 1,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(TypeNull),
        ICON(TypeNull, 0),
        .footprint = gMonFootprint_Type_Null,
        LEARNSETS(TypeNull),
        .evolutions = EVOLUTION({EVO_FRIENDSHIP, 0, SPECIES_SILVALLY_NORMAL}),
    },

#define SILVALLY_SPECIES_INFO(type, palette)                                            \
    {                                                                                   \
        .baseHP        = 95,                                                            \
        .baseAttack    = 95,                                                            \
        .baseDefense   = 95,                                                            \
        .baseSpeed     = 95,                                                            \
        .baseSpAttack  = 95,                                                            \
        .baseSpDefense = 95,                                                            \
        .types = { type, type },                                                        \
        .catchRate = 3,                                                                 \
        .expYield = 257,                                                                \
        .evYield_HP = 3,                                                                \
        .genderRatio = MON_GENDERLESS,                                                  \
        .eggCycles = 120,                                                               \
        .friendship = 0,                                                                \
        .growthRate = GROWTH_SLOW,                                                      \
        .eggGroups = { EGG_GROUP_NO_EGGS_DISCOVERED, EGG_GROUP_NO_EGGS_DISCOVERED },    \
        .abilities = { ABILITY_RKS_SYSTEM, ABILITY_NONE },                              \
        .bodyColor = BODY_COLOR_GRAY,                                                   \
        .isLegendary = TRUE,                                                            \
        .speciesName = _("Typ:Null"),                                                   \
        .cryId = CRY_SILVALLY,                                                          \
        .natDexNum = NATIONAL_DEX_SILVALLY,                                             \
        .categoryName = _("Modular"),                                                   \
        .height = 23,                                                                   \
        .weight = 1005,                                                                 \
        .description = (type == TYPE_NORMAL                                             \
            ? gSilvallyNormalPokedexText                                                \
            : gSilvallyMemoryPokedexText),                                              \
        .pokemonScale = 256,                                                            \
        .pokemonOffset = 0,                                                             \
        .trainerScale = 342,                                                            \
        .trainerOffset = 7,                                                             \
        FRONT_PIC(Silvally, 64, 64),                                                    \
        .frontPicYOffset = 0,                                                           \
        .frontAnimFrames = sAnims_Silvally,                                             \
        .frontAnimId = ANIM_V_SHAKE,                                                    \
        BACK_PIC(Silvally, 56, 64),                                                     \
        .backPicYOffset = 0,                                                            \
        PALETTES(palette),                                                              \
        ICON(Silvally, 0),                                                              \
        .footprint = gMonFootprint_Silvally,                                            \
        LEARNSETS(Silvally),                                                            \
        .formSpeciesIdTable = sSilvallyFormSpeciesIdTable,                              \
        .formChangeTable = sSilvallyFormChangeTable,                                    \
   }
        //.backAnimId = BACK_ANIM_NONE,

    [SPECIES_SILVALLY_NORMAL]   = SILVALLY_SPECIES_INFO(TYPE_NORMAL, SilvallyNormal),
    [SPECIES_SILVALLY_FIGHTING] = SILVALLY_SPECIES_INFO(TYPE_FIGHTING, SilvallyFighting),
    [SPECIES_SILVALLY_FLYING]   = SILVALLY_SPECIES_INFO(TYPE_FLYING, SilvallyFlying),
    [SPECIES_SILVALLY_POISON]   = SILVALLY_SPECIES_INFO(TYPE_POISON, SilvallyPoison),
    [SPECIES_SILVALLY_GROUND]   = SILVALLY_SPECIES_INFO(TYPE_GROUND, SilvallyGround),
    [SPECIES_SILVALLY_ROCK]     = SILVALLY_SPECIES_INFO(TYPE_ROCK, SilvallyRock),
    [SPECIES_SILVALLY_BUG]      = SILVALLY_SPECIES_INFO(TYPE_BUG, SilvallyBug),
    [SPECIES_SILVALLY_GHOST]    = SILVALLY_SPECIES_INFO(TYPE_GHOST, SilvallyGhost),
    [SPECIES_SILVALLY_STEEL]    = SILVALLY_SPECIES_INFO(TYPE_STEEL, SilvallySteel),
    [SPECIES_SILVALLY_FIRE]     = SILVALLY_SPECIES_INFO(TYPE_FIRE, SilvallyFire),
    [SPECIES_SILVALLY_WATER]    = SILVALLY_SPECIES_INFO(TYPE_WATER, SilvallyWater),
    [SPECIES_SILVALLY_GRASS]    = SILVALLY_SPECIES_INFO(TYPE_GRASS, SilvallyGrass),
    [SPECIES_SILVALLY_ELECTRIC] = SILVALLY_SPECIES_INFO(TYPE_ELECTRIC, SilvallyElectric),
    [SPECIES_SILVALLY_PSYCHIC]  = SILVALLY_SPECIES_INFO(TYPE_PSYCHIC, SilvallyPsychic),
    [SPECIES_SILVALLY_ICE]      = SILVALLY_SPECIES_INFO(TYPE_ICE, SilvallyIce),
    [SPECIES_SILVALLY_DRAGON]   = SILVALLY_SPECIES_INFO(TYPE_DRAGON, SilvallyDragon),
    [SPECIES_SILVALLY_DARK]     = SILVALLY_SPECIES_INFO(TYPE_DARK, SilvallyDark),
    [SPECIES_SILVALLY_FAIRY]    = SILVALLY_SPECIES_INFO(TYPE_FAIRY, SilvallyFairy),
#endif //P_FAMILY_TYPE_NULL

#if P_FAMILY_MINIOR
#define MINIOR_MISC_INFO(color)                                 \
        .types = { TYPE_ROCK, TYPE_FLYING },                    \
        .catchRate = 30,                                        \
        .expYield = 154,                                        \
        .evYield_Defense = 1,                                   \
        .evYield_SpDefense = 1,                                 \
        .itemRare = ITEM_STAR_PIECE,                            \
        .genderRatio = MON_GENDERLESS,                          \
        .eggCycles = 25,                                        \
        .friendship = STANDARD_FRIENDSHIP,                      \
        .growthRate = GROWTH_MEDIUM_SLOW,                       \
        .eggGroups = { EGG_GROUP_MINERAL, EGG_GROUP_MINERAL },  \
        .abilities = { ABILITY_SHIELDS_DOWN, ABILITY_NONE },    \
        .bodyColor = color,                                     \
        .noFlip = TRUE,                                         \
        .speciesName = _("Amigento"),                             \
        .cryId = CRY_MINIOR,                                    \
        .natDexNum = NATIONAL_DEX_MINIOR,                       \
        .categoryName = _("Modifikations"),                            \
        .height = 3,                                            \
        .pokemonScale = 530,                                    \
        .pokemonOffset = 13,                                    \
        .trainerScale = 256,                                    \
        .trainerOffset = 0,                                     \
        .footprint = gMonFootprint_Minior,                      \
        LEARNSETS(Minior),                                      \
        .formSpeciesIdTable = sMiniorFormSpeciesIdTable

#define MINIOR_METEOR_SPECIES_INFO(Form)                        \
    {                                                           \
        .baseHP        = 60,                                    \
        .baseAttack    = 60,                                    \
        .baseDefense   = 100,                                   \
        .baseSpeed     = 60,                                    \
        .baseSpAttack  = 60,                                    \
        .baseSpDefense = 100,                                   \
        .weight = 400,                                          \
        FRONT_PIC(MiniorMeteor, 48, 40),                        \
        .frontPicYOffset = 14,                                  \
        .frontAnimFrames = sAnims_MiniorMeteor,                 \
        .frontAnimId = ANIM_TUMBLING_FRONT_FLIP_TWICE,          \
        .enemyMonElevation = 17,                                \
        BACK_PIC(MiniorMeteor, 56, 40),                         \
        .backPicYOffset = 14,                                   \
        PALETTES(MiniorMeteor),                                 \
        ICON(MiniorMeteor, 0),                                  \
        .formChangeTable = sMinior ##Form##FormChangeTable,     \
        MINIOR_MISC_INFO(BODY_COLOR_BROWN),                     \
    }
    //.backAnimId = BACK_ANIM_NONE,

#define MINIOR_CORE_SPECIES_INFO(Form, color, iconPal)          \
    {                                                           \
        .baseHP        = 60,                                    \
        .baseAttack    = 100,                                   \
        .baseDefense   = 60,                                    \
        .baseSpeed     = 120,                                   \
        .baseSpAttack  = 100,                                   \
        .baseSpDefense = 60,                                    \
        .weight = 3,                                            \
        .description = gMiniorCorePokedexText,                  \
        FRONT_PIC(MiniorCore, 48, 40),                          \
        .frontPicYOffset = 16,                                  \
        .frontAnimFrames = sAnims_MiniorMeteor,                 \
        .frontAnimId = ANIM_TUMBLING_FRONT_FLIP_TWICE,          \
        .enemyMonElevation = 17,                                \
        BACK_PIC(MiniorCore, 56, 40),                           \
        .backPicYOffset = 15,                                   \
        .palette = gMonPalette_MiniorCore##Form,                \
        .shinyPalette = gMonShinyPalette_MiniorCore,            \
        ICON(MiniorCore##Form, iconPal),                        \
        .formChangeTable = sMinior ##Form##FormChangeTable,     \
        MINIOR_MISC_INFO(color),                                \
    }
    //.backAnimId = BACK_ANIM_NONE,

    [SPECIES_MINIOR_METEOR_RED]    = MINIOR_METEOR_SPECIES_INFO(Red),
    [SPECIES_MINIOR_METEOR_ORANGE] = MINIOR_METEOR_SPECIES_INFO(Orange),
    [SPECIES_MINIOR_METEOR_YELLOW] = MINIOR_METEOR_SPECIES_INFO(Yellow),
    [SPECIES_MINIOR_METEOR_GREEN]  = MINIOR_METEOR_SPECIES_INFO(Green),
    [SPECIES_MINIOR_METEOR_BLUE]   = MINIOR_METEOR_SPECIES_INFO(Blue),
    [SPECIES_MINIOR_METEOR_INDIGO] = MINIOR_METEOR_SPECIES_INFO(Indigo),
    [SPECIES_MINIOR_METEOR_VIOLET] = MINIOR_METEOR_SPECIES_INFO(Violet),
    [SPECIES_MINIOR_CORE_RED]      = MINIOR_CORE_SPECIES_INFO(Red,    BODY_COLOR_RED,    0),
    [SPECIES_MINIOR_CORE_ORANGE]   = MINIOR_CORE_SPECIES_INFO(Orange, BODY_COLOR_RED,    0),
    [SPECIES_MINIOR_CORE_YELLOW]   = MINIOR_CORE_SPECIES_INFO(Yellow, BODY_COLOR_YELLOW, 0),
    [SPECIES_MINIOR_CORE_GREEN]    = MINIOR_CORE_SPECIES_INFO(Green,  BODY_COLOR_GREEN,  1),
    [SPECIES_MINIOR_CORE_BLUE]     = MINIOR_CORE_SPECIES_INFO(Blue,   BODY_COLOR_BLUE,   0),
    [SPECIES_MINIOR_CORE_INDIGO]   = MINIOR_CORE_SPECIES_INFO(Indigo, BODY_COLOR_BLUE,   0),
    [SPECIES_MINIOR_CORE_VIOLET]   = MINIOR_CORE_SPECIES_INFO(Violet, BODY_COLOR_PURPLE, 2),
#endif //P_FAMILY_MINIOR

#if P_FAMILY_KOMALA
    [SPECIES_KOMALA] =
    {
        .baseHP        = 65,
        .baseAttack    = 115,
        .baseDefense   = 65,
        .baseSpeed     = 65,
        .baseSpAttack  = 75,
        .baseSpDefense = 95,
        .types = { TYPE_NORMAL, TYPE_NORMAL },
        .catchRate = 45,
        .expYield = 168,
        .evYield_Attack = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD },
        .abilities = { ABILITY_COMATOSE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Koalelu"),
        .cryId = CRY_KOMALA,
        .natDexNum = NATIONAL_DEX_KOMALA,
        .categoryName = _("Halbschlaf"),
        .height = 4,
        .weight = 199,
        .description = POKEDEX_DESC_STRING(
            "Den Baumstumpf bekam es zu seiner Geburt\n"
            "von seinen Eltern. Fasst es Zutrauen,\n"
            "klammert es sich aber auch am Arm seines\n"
            "Trainers fest."),
        .pokemonScale = 491,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Komala, 48, 40),
        .frontPicYOffset = 12,
        .frontAnimFrames = sAnims_Komala,
        .frontAnimId = ANIM_H_DIP,
        BACK_PIC(Komala, 64, 48),
        .backPicYOffset = 9,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(Komala),
        ICON(Komala, 2),
        .footprint = gMonFootprint_Komala,
        LEARNSETS(Komala),
    },
#endif //P_FAMILY_KOMALA

#if P_FAMILY_TURTONATOR
    [SPECIES_TURTONATOR] =
    {
        .baseHP        = 60,
        .baseAttack    = 78,
        .baseDefense   = 135,
        .baseSpeed     = 36,
        .baseSpAttack  = 91,
        .baseSpDefense = 85,
        .types = { TYPE_FIRE, TYPE_DRAGON },
        .catchRate = 70,
        .expYield = 170,
        .evYield_Defense = 2,
        .itemRare = ITEM_CHARCOAL,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_MONSTER, EGG_GROUP_DRAGON },
        .abilities = { ABILITY_SHELL_ARMOR, ABILITY_NONE },
        .bodyColor = BODY_COLOR_RED,
        .speciesName = _("Tortunator"),
        .cryId = CRY_TURTONATOR,
        .natDexNum = NATIONAL_DEX_TURTONATOR,
        .categoryName = _("Knallkröten"),
        .height = 20,
        .weight = 2120,
        .description = POKEDEX_DESC_STRING(
            "Sein Panzer ist mit einer explosiven\n"
            "Schicht überzogen. Gegnerische Angriffe\n"
            "quittiert es mit gewaltigen Explosionen."),
        .pokemonScale = 261,
        .pokemonOffset = 1,
        .trainerScale = 334,
        .trainerOffset = 4,
        FRONT_PIC(Turtonator, 64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_Turtonator,
        .frontAnimId = ANIM_SHAKE_GLOW_RED,
        BACK_PIC(Turtonator, 64, 56),
        .backPicYOffset = 9,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(Turtonator),
        ICON(Turtonator, 0),
        .footprint = gMonFootprint_Turtonator,
        LEARNSETS(Turtonator),
    },
#endif //P_FAMILY_TURTONATOR

#if P_FAMILY_TOGEDEMARU
    [SPECIES_TOGEDEMARU] =
    {
        .baseHP        = 65,
        .baseAttack    = 98,
        .baseDefense   = 63,
        .baseSpeed     = 96,
        .baseSpAttack  = 40,
        .baseSpDefense = 73,
        .types = { TYPE_ELECTRIC, TYPE_STEEL },
        .catchRate = 180,
        .expYield = 152,
        .evYield_Attack = 2,
        .itemRare = ITEM_ELECTRIC_SEED,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 10,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FAIRY },
        .abilities = { ABILITY_IRON_BARBS, ABILITY_LIGHTNING_ROD, ABILITY_STURDY },
        .bodyColor = BODY_COLOR_GRAY,
        .speciesName = _("Togedemaru"),
        .cryId = CRY_TOGEDEMARU,
        .natDexNum = NATIONAL_DEX_TOGEDEMARU,
        .categoryName = _("Einigler"),
        .height = 3,
        .weight = 33,
        .description = POKEDEX_DESC_STRING(
            "Bei Gefahr rollt es sich zusammen, stellt\n"
            "seine Rückenstacheln auf und schießt\n"
            "willkürlich mit Elektrizität um sich."),
        .pokemonScale = 530,
        .pokemonOffset = 13,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Togedemaru, 40, 40),
        .frontPicYOffset = 9,
        .frontAnimFrames = sAnims_Togedemaru,
        .frontAnimId = ANIM_FLASH_YELLOW,
        BACK_PIC(Togedemaru, 64, 48),
        .backPicYOffset = 13,
        .backAnimId = BACK_ANIM_GROW_STUTTER,
        PALETTES(Togedemaru),
        ICON(Togedemaru, 2),
        .footprint = gMonFootprint_Togedemaru,
        LEARNSETS(Togedemaru),
    },
#endif //P_FAMILY_TOGEDEMARU

#if P_FAMILY_MIMIKYU
#define MIMIKYU_MISC_INFO                                           \
        .baseHP        = 55,                                        \
        .baseAttack    = 90,                                        \
        .baseDefense   = 80,                                        \
        .baseSpeed     = 96,                                        \
        .baseSpAttack  = 50,                                        \
        .baseSpDefense = 105,                                       \
        .types = { TYPE_GHOST, TYPE_FAIRY },                        \
        .catchRate = 45,                                            \
        .expYield = 167,                                            \
        .evYield_SpDefense = 2,                                     \
        .itemRare = ITEM_CHESTO_BERRY,                              \
        .genderRatio = PERCENT_FEMALE(50),                          \
        .eggCycles = 20,                                            \
        .friendship = STANDARD_FRIENDSHIP,                          \
        .growthRate = GROWTH_MEDIUM_FAST,                           \
        .eggGroups = { EGG_GROUP_AMORPHOUS, EGG_GROUP_AMORPHOUS },  \
        .abilities = { ABILITY_DISGUISE, ABILITY_NONE },            \
        .bodyColor = BODY_COLOR_YELLOW,                             \
        .speciesName = _("Togedemaru"),                                \
        .cryId = CRY_MIMIKYU,                                       \
        .natDexNum = NATIONAL_DEX_MIMIKYU,                          \
        .categoryName = _("Einigler"),                              \
        .height = 2,                                                \
        .weight = 7,                                                \
        .pokemonScale = 682,                                        \
        .pokemonOffset = 24,                                        \
        .trainerScale = 256,                                        \
        .trainerOffset = 0,                                         \
        .footprint = gMonFootprint_Mimikyu,                         \
        LEARNSETS(Mimikyu),                                         \
        .formSpeciesIdTable = sMimikyuFormSpeciesIdTable,           \
        .formChangeTable = sMimikyuFormChangeTable

    [SPECIES_MIMIKYU_DISGUISED] =
    {
        MIMIKYU_MISC_INFO,
        .description = POKEDEX_DESC_STRING(
            "Niemand weiß, wie es wirklich\n"
            "aussieht. Ein Forscher, der unter\n"
            "seinen Lumpen blickte, soll sich\n"
            "buchstäblich zu Tode erschreckt\n"
            "haben."),
        FRONT_PIC(MimikyuDisguised, 48, 40),
        .frontPicYOffset = 12,
        .frontAnimFrames = sAnims_MimikyuDisguised,
        .frontAnimId = ANIM_DEEP_V_SQUISH_AND_BOUNCE,
        BACK_PIC(MimikyuDisguised, 56, 56),
        .backPicYOffset = 7,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(MimikyuDisguised),
        ICON(MimikyuDisguised, 1),
    },

    [SPECIES_MIMIKYU_BUSTED] =
    {
        MIMIKYU_MISC_INFO,
        .description = POKEDEX_DESC_STRING(
            "Niemand weiß, wie es wirklich\n"
            "aussieht. Ein Forscher, der unter\n"
            "seinen Lumpen blickte, soll sich\n"
            "buchstäblich zu Tode erschreckt\n"
            "haben."),
        FRONT_PIC(MimikyuBusted, 48, 40),
        .frontPicYOffset = 12,
        .frontAnimFrames = sAnims_MimikyuBusted,
        .frontAnimId = ANIM_DEEP_V_SQUISH_AND_BOUNCE,
        BACK_PIC(MimikyuBusted, 64, 40),
        .backPicYOffset = 15,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(MimikyuBusted),
        ICON(MimikyuBusted, 1),
    },
#endif //P_FAMILY_MIMIKYU

#if P_FAMILY_BRUXISH
    [SPECIES_BRUXISH] =
    {
        .baseHP        = 68,
        .baseAttack    = 105,
        .baseDefense   = 70,
        .baseSpeed     = 92,
        .baseSpAttack  = 70,
        .baseSpDefense = 70,
        .types = { TYPE_WATER, TYPE_PSYCHIC },
        .catchRate = 80,
        .expYield = 166,
        .evYield_Attack = 2,
        .itemRare = ITEM_RAZOR_FANG,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_WATER_2, EGG_GROUP_WATER_2 },
        .abilities = { ABILITY_DAZZLING, ABILITY_STRONG_JAW, ABILITY_WONDER_SKIN },
        .bodyColor = BODY_COLOR_PINK,
        .speciesName = _("Knirfish"),
        .cryId = CRY_BRUXISH,
        .natDexNum = NATIONAL_DEX_BRUXISH,
        .categoryName = _("Knirschzahn"),
        .height = 9,
        .weight = 190,
        .description = POKEDEX_DESC_STRING(
            "Wenn es über den Fortsatz an seinem\n"
            "Kopf Psycho-Kräfte freisetzt,\n"
            "ertönt in seiner Umgebung ein\n"
            "unangenehmes Zähneknirschen."),
        .pokemonScale = 338,
        .pokemonOffset = 8,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Bruxish, 56, 40),
        .frontPicYOffset = 15,
        .frontAnimFrames = sAnims_Bruxish,
        .frontAnimId = ANIM_RISING_WOBBLE,
        BACK_PIC(Bruxish, 64, 48),
        .backPicYOffset = 14,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(Bruxish),
        ICON(Bruxish, 0),
        .footprint = gMonFootprint_Bruxish,
        LEARNSETS(Bruxish),
    },
#endif //P_FAMILY_BRUXISH

#if P_FAMILY_DRAMPA
    [SPECIES_DRAMPA] =
    {
        .baseHP        = 78,
        .baseAttack    = 60,
        .baseDefense   = 85,
        .baseSpeed     = 36,
        .baseSpAttack  = 135,
        .baseSpDefense = 91,
        .types = { TYPE_NORMAL, TYPE_DRAGON },
        .catchRate = 70,
        .expYield = 170,
        .evYield_SpAttack = 2,
        .itemRare = ITEM_PERSIM_BERRY,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_MONSTER, EGG_GROUP_DRAGON },
        .abilities = { ABILITY_BERSERK, ABILITY_SAP_SIPPER, ABILITY_CLOUD_NINE },
        .bodyColor = BODY_COLOR_WHITE,
        .speciesName = _("Sen-Long"),
        .cryId = CRY_DRAMPA,
        .natDexNum = NATIONAL_DEX_DRAMPA,
        .categoryName = _("Gelassenheits"),
        .height = 30,
        .weight = 1850,
        .description = POKEDEX_DESC_STRING(
            "Es besucht so manche Stadt und spielt mit\n"
            "den Kindern. Mütter können beruhigt sein,\n"
            "da es die Kinder auch in brenzligen\n"
            "Situationen beschützt."),
        .pokemonScale = 275,
        .pokemonOffset = 7,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Drampa, 64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_Drampa,
        .frontAnimId = ANIM_V_SHAKE_TWICE,
        BACK_PIC(Drampa, 64, 56),
        .backPicYOffset = 5,
        .backAnimId = BACK_ANIM_H_SLIDE,
        PALETTES(Drampa),
        ICON(Drampa, 0),
        .footprint = gMonFootprint_Drampa,
        LEARNSETS(Drampa),
    },
#endif //P_FAMILY_DRAMPA

#if P_FAMILY_DHELMISE
    [SPECIES_DHELMISE] =
    {
        .baseHP        = 70,
        .baseAttack    = 131,
        .baseDefense   = 100,
        .baseSpeed     = 40,
        .baseSpAttack  = 86,
        .baseSpDefense = 90,
        .types = { TYPE_GHOST, TYPE_GRASS },
        .catchRate = 25,
        .expYield = 181,
        .evYield_Attack = 2,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 25,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_MINERAL, EGG_GROUP_MINERAL },
        .abilities = { ABILITY_STEELWORKER, ABILITY_NONE },
        .bodyColor = BODY_COLOR_GREEN,
        .noFlip = TRUE,
        .speciesName = _("Moruda"),
        .cryId = CRY_DHELMISE,
        .natDexNum = NATIONAL_DEX_DHELMISE,
        .categoryName = _("Seetang"),
        .height = 39,
        .weight = 2100,
        .description = POKEDEX_DESC_STRING(
            "Dieses Geister-Pokémon entstand, als sich\n"
            "vom Meeresgrund stammendes Seegras auf\n"
            "Bruchstücken eines Schiffswracks\n"
            "ablagerte."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 510,
        .trainerOffset = 11,
        FRONT_PIC(Dhelmise, 48, 64),
        .frontPicYOffset = 1,
        .frontAnimFrames = sAnims_Dhelmise,
        .frontAnimId = ANIM_SWING_CONVEX,
        .enemyMonElevation = 2,
        BACK_PIC(Dhelmise, 64, 64),
        .backPicYOffset = 3,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(Dhelmise),
        ICON(Dhelmise, 1),
        .footprint = gMonFootprint_Dhelmise,
        LEARNSETS(Dhelmise),
    },
#endif //P_FAMILY_DHELMISE

#if P_FAMILY_JANGMO_O
    [SPECIES_JANGMO_O] =
    {
        .baseHP        = 45,
        .baseAttack    = 55,
        .baseDefense   = 65,
        .baseSpeed     = 45,
        .baseSpAttack  = 45,
        .baseSpDefense = 45,
        .types = { TYPE_DRAGON, TYPE_DRAGON },
        .catchRate = 45,
        .expYield = 60,
        .evYield_Defense = 1,
        .itemRare = ITEM_RAZOR_CLAW,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 40,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_DRAGON, EGG_GROUP_DRAGON },
        .abilities = { ABILITY_BULLETPROOF, ABILITY_SOUNDPROOF, ABILITY_OVERCOAT },
        .bodyColor = BODY_COLOR_GRAY,
        .speciesName = _("Miniras"),
        .cryId = CRY_JANGMO_O,
        .natDexNum = NATIONAL_DEX_JANGMO_O,
        .categoryName = _("Schuppentier"),
        .height = 6,
        .weight = 297,
        .description = POKEDEX_DESC_STRING(
            "Es lebt auf Bergen, auf die sich kein\n"
            "Mensch wagt. Indem es gegen andere Miniras\n"
            "kämpft, wird es stetig stärker."),
        .pokemonScale = 422,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(JangmoO, 36, 43),
        .frontPicYOffset = 9,
        .frontAnimFrames = sAnims_Jangmo_O,
        .frontAnimId = ANIM_H_STRETCH,
        BACK_PIC(JangmoO, 42, 56),
        .backPicYOffset = 5,
        .backAnimId = BACK_ANIM_GROW_STUTTER,
        PALETTES(JangmoO),
        ICON(JangmoO, 2),
        .footprint = gMonFootprint_JangmoO,
        LEARNSETS(JangmoO),
        .evolutions = EVOLUTION({EVO_LEVEL, 35, SPECIES_HAKAMO_O}),
    },

    [SPECIES_HAKAMO_O] =
    {
        .baseHP        = 55,
        .baseAttack    = 75,
        .baseDefense   = 90,
        .baseSpeed     = 65,
        .baseSpAttack  = 65,
        .baseSpDefense = 70,
        .types = { TYPE_DRAGON, TYPE_FIGHTING },
        .catchRate = 45,
        .expYield = 147,
        .evYield_Defense = 2,
        .itemRare = ITEM_RAZOR_CLAW,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 40,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_DRAGON, EGG_GROUP_DRAGON },
        .abilities = { ABILITY_BULLETPROOF, ABILITY_SOUNDPROOF, ABILITY_OVERCOAT },
        .bodyColor = BODY_COLOR_GRAY,
        .speciesName = _("Mediras"),
        .cryId = CRY_HAKAMO_O,
        .natDexNum = NATIONAL_DEX_HAKAMO_O,
        .categoryName = _("Schuppentier"),
        .height = 12,
        .weight = 470,
        .description = POKEDEX_DESC_STRING(
            "Seine Schuppen wachsen sehr schnell nach.\n"
            "Jede neue Schuppe ist härter und schärfer\n"
            "als die vorherige."),
        .pokemonScale = 282,
        .pokemonOffset = 4,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(HakamoO, 53, 61),
        .frontPicYOffset = 1,
        .frontAnimFrames = sAnims_Hakamo_O,
        .frontAnimId = ANIM_H_STRETCH,
        BACK_PIC(HakamoO, 49, 56),
        .backPicYOffset = 5,
        .backAnimId = BACK_ANIM_H_STRETCH,
        PALETTES(HakamoO),
        ICON(HakamoO, 2),
        .footprint = gMonFootprint_HakamoO,
        LEARNSETS(HakamoO),
        .evolutions = EVOLUTION({EVO_LEVEL, 45, SPECIES_KOMMO_O}),
    },

    [SPECIES_KOMMO_O] =
    {
        .baseHP        = 75,
        .baseAttack    = 110,
        .baseDefense   = 125,
        .baseSpeed     = 85,
        .baseSpAttack  = 100,
        .baseSpDefense = 105,
        .types = { TYPE_DRAGON, TYPE_FIGHTING },
        .catchRate = 45,
        .expYield = 270,
        .evYield_Defense = 3,
        .itemCommon = ITEM_RAZOR_CLAW,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 40,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_DRAGON, EGG_GROUP_DRAGON },
        .abilities = { ABILITY_BULLETPROOF, ABILITY_SOUNDPROOF, ABILITY_OVERCOAT },
        .bodyColor = BODY_COLOR_GRAY,
        .speciesName = _("Grandiras"),
        .cryId = CRY_KOMMO_O,
        .natDexNum = NATIONAL_DEX_KOMMO_O,
        .categoryName = _("Schuppentier"),
        .height = 16,
        .weight = 782,
        .description = POKEDEX_DESC_STRING(
            "In Ruinen finden sich uralte Abbildungen\n"
            "von Kriegern, die Rüstungen aus\n"
            "Grandiras-Schuppen tragen."),
        .pokemonScale = 259,
        .pokemonOffset = 1,
        .trainerScale = 296,
        .trainerOffset = 1,
        FRONT_PIC(KommoO, 63, 63),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_Kommo_O,
        .frontAnimId = ANIM_SHRINK_GROW_VIBRATE_FAST,
        BACK_PIC(KommoO, 60, 60),
        .backPicYOffset = 2,
        .backAnimId = BACK_ANIM_SHRINK_GROW_VIBRATE,
        PALETTES(KommoO),
        ICON(KommoO, 2),
        .footprint = gMonFootprint_KommoO,
        LEARNSETS(KommoO),
    },
#endif //P_FAMILY_JANGMO_O

#if P_FAMILY_TAPU_KOKO
    [SPECIES_TAPU_KOKO] =
    {
        .baseHP        = 70,
        .baseAttack    = 115,
        .baseDefense   = 85,
        .baseSpeed     = 130,
        .baseSpAttack  = 95,
        .baseSpDefense = 75,
        .types = { TYPE_ELECTRIC, TYPE_FAIRY },
        .catchRate = 3,
        .expYield = 257,
        .evYield_Speed = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_NO_EGGS_DISCOVERED, EGG_GROUP_NO_EGGS_DISCOVERED },
        .abilities = { ABILITY_ELECTRIC_SURGE, ABILITY_NONE, ABILITY_TELEPATHY },
        .bodyColor = BODY_COLOR_YELLOW,
        .isLegendary = TRUE,
        .speciesName = _("Kapu-Riki"),
        .cryId = CRY_TAPU_KOKO,
        .natDexNum = NATIONAL_DEX_TAPU_KOKO,
        .categoryName = _("Schutzpatron"),
        .height = 18,
        .weight = 205,
        .description = POKEDEX_DESC_STRING(
            "Der neugierige und lebhafte\n"
            "Schutzpatron von Mele-Mele. Es kann\n"
            "Gewitterwolken rufen und Blitze in\n"
            "seinem Körper speichern."),
        .pokemonScale = 267,
        .pokemonOffset = 2,
        .trainerScale = 286,
        .trainerOffset = 1,
        FRONT_PIC(TapuKoko, 64, 64),
        .frontPicYOffset = 1,
        .frontAnimFrames = sAnims_TapuKoko,
        .frontAnimId = ANIM_TRIANGLE_DOWN_TWICE,
        .enemyMonElevation = 9,
        BACK_PIC(TapuKoko, 64, 64),
        .backPicYOffset = 2,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(TapuKoko),
        ICON(TapuKoko, 0),
        .footprint = gMonFootprint_Tapu_Koko,
        LEARNSETS(TapuKoko),
    },
#endif //P_FAMILY_TAPU_KOKO

#if P_FAMILY_TAPU_LELE
    [SPECIES_TAPU_LELE] =
    {
        .baseHP        = 70,
        .baseAttack    = 85,
        .baseDefense   = 75,
        .baseSpeed     = 95,
        .baseSpAttack  = 130,
        .baseSpDefense = 115,
        .types = { TYPE_PSYCHIC, TYPE_FAIRY },
        .catchRate = 3,
        .expYield = 257,
        .evYield_SpAttack = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_NO_EGGS_DISCOVERED, EGG_GROUP_NO_EGGS_DISCOVERED },
        .abilities = { ABILITY_PSYCHIC_SURGE, ABILITY_NONE, ABILITY_TELEPATHY },
        .bodyColor = BODY_COLOR_PINK,
        .isLegendary = TRUE,
        .speciesName = _("Kapu-Fala"),
        .cryId = CRY_TAPU_LELE,
        .natDexNum = NATIONAL_DEX_TAPU_LELE,
        .categoryName = _("Schutzpatron"),
        .height = 12,
        .weight = 186,
        .description = POKEDEX_DESC_STRING(
            "Der arglose, doch unbarmherzige\n"
            "Schutzpatron von Akala. Seine\n"
            "Energie zieht es aus dem lieblichen\n"
            "Duft von Blumen."),
        .pokemonScale = 282,
        .pokemonOffset = 4,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(TapuLele, 48, 56),
        .frontPicYOffset = 6,
        .frontAnimFrames = sAnims_TapuLele,
        .frontAnimId = ANIM_V_SLIDE_WOBBLE_SMALL,
        .enemyMonElevation = 8,
        BACK_PIC(TapuLele, 56, 56),
        .backPicYOffset = 6,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(TapuLele),
        ICON(TapuLele, 0),
        .footprint = gMonFootprint_Tapu_Lele,
        LEARNSETS(TapuLele),
    },
#endif //P_FAMILY_TAPU_LELE

#if P_FAMILY_TAPU_BULU
    [SPECIES_TAPU_BULU] =
    {
        .baseHP        = 70,
        .baseAttack    = 130,
        .baseDefense   = 115,
        .baseSpeed     = 75,
        .baseSpAttack  = 85,
        .baseSpDefense = 95,
        .types = { TYPE_GRASS, TYPE_FAIRY },
        .catchRate = 3,
        .expYield = 257,
        .evYield_Attack = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_NO_EGGS_DISCOVERED, EGG_GROUP_NO_EGGS_DISCOVERED },
        .abilities = { ABILITY_GRASSY_SURGE, ABILITY_NONE, ABILITY_TELEPATHY },
        .bodyColor = BODY_COLOR_RED,
        .isLegendary = TRUE,
        .speciesName = _("Kapu-Toro"),
        .cryId = CRY_TAPU_BULU,
        .natDexNum = NATIONAL_DEX_TAPU_BULU,
        .categoryName = _("Schutzpatron"),
        .height = 19,
        .weight = 455,
        .description = POKEDEX_DESC_STRING(
            "Obwohl man es als Schutzpatron bezeichnet,\n"
            "verfügt es über die nötige Härte, um seine\n"
            "Feinde erbarmungslos zu vernichten."),
        .pokemonScale = 256,
        .pokemonOffset = 1,
        .trainerScale = 326,
        .trainerOffset = 4,
        FRONT_PIC(TapuBulu, 56, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_TapuBulu,
        .frontAnimId = ANIM_V_SHAKE_TWICE,
        .enemyMonElevation = 5,
        BACK_PIC(TapuBulu, 64, 64),
        .backPicYOffset = 1,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(TapuBulu),
        ICON(TapuBulu, 2),
        .footprint = gMonFootprint_Tapu_Bulu,
        LEARNSETS(TapuBulu),
    },
#endif //P_FAMILY_TAPU_BULU

#if P_FAMILY_TAPU_FINI
    [SPECIES_TAPU_FINI] =
    {
        .baseHP        = 70,
        .baseAttack    = 75,
        .baseDefense   = 115,
        .baseSpeed     = 85,
        .baseSpAttack  = 95,
        .baseSpDefense = 130,
        .types = { TYPE_WATER, TYPE_FAIRY },
        .catchRate = 3,
        .expYield = 257,
        .evYield_SpDefense = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_NO_EGGS_DISCOVERED, EGG_GROUP_NO_EGGS_DISCOVERED },
        .abilities = { ABILITY_MISTY_SURGE, ABILITY_NONE, ABILITY_TELEPATHY },
        .bodyColor = BODY_COLOR_PURPLE,
        .isLegendary = TRUE,
        .speciesName = _("Kapu-Kime"),
        .cryId = CRY_TAPU_FINI,
        .natDexNum = NATIONAL_DEX_TAPU_FINI,
        .categoryName = _("Schutzpatron"),
        .height = 13,
        .weight = 212,
        .description = POKEDEX_DESC_STRING(
            "Es führt Gegner mit dichtem Nebel\n"
            "in die Irre und schickt sie so in\n"
            "ihren Untergang. Seine Energie\n"
            "gewinnt es aus der Meeresströmung."),
        .pokemonScale = 272,
        .pokemonOffset = 3,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(TapuFini, 56, 64),
        .frontPicYOffset = 2,
        .frontAnimFrames = sAnims_TapuFini,
        .frontAnimId = ANIM_SHAKE_GLOW_BLUE_SLOW,
        .frontAnimDelay = 5,
        .enemyMonElevation = 6,
        BACK_PIC(TapuFini, 64, 56),
        .backPicYOffset = 4,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(TapuFini),
        ICON(TapuFini, 0),
        .footprint = gMonFootprint_Tapu_Fini,
        LEARNSETS(TapuFini),
    },
#endif //P_FAMILY_TAPU_FINI

#if P_FAMILY_COSMOG
    [SPECIES_COSMOG] =
    {
        .baseHP        = 43,
        .baseAttack    = 29,
        .baseDefense   = 31,
        .baseSpeed     = 37,
        .baseSpAttack  = 29,
        .baseSpDefense = 31,
        .types = { TYPE_PSYCHIC, TYPE_PSYCHIC },
        .catchRate = 45,
        .expYield = 40,
        .evYield_HP = 1,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_NO_EGGS_DISCOVERED, EGG_GROUP_NO_EGGS_DISCOVERED },
        .abilities = { ABILITY_UNAWARE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_BLUE,
        .isLegendary = TRUE,
        .speciesName = _("Cosmog"),
        .cryId = CRY_COSMOG,
        .natDexNum = NATIONAL_DEX_COSMOG,
        .categoryName = _("Nebula"),
        .height = 2,
        .weight = 1,
        .description = POKEDEX_DESC_STRING(
            "Sein Körper besteht aus flüchtigem\n"
            "Gas. Es wächst durch das Sammeln\n"
            "von Staub aus der Luft."),
        .pokemonScale = 682,
        .pokemonOffset = 24,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Cosmog, 56, 48),
        .frontPicYOffset = 10,
        .frontAnimFrames = sAnims_Cosmog,
        .frontAnimId = ANIM_H_JUMPS_V_STRETCH,
        .enemyMonElevation = 7,
        BACK_PIC(Cosmog, 64, 48),
        .backPicYOffset = 10,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(Cosmog),
        ICON(Cosmog, 2),
        .footprint = gMonFootprint_Cosmog,
        LEARNSETS(Cosmog),
        .evolutions = EVOLUTION({EVO_LEVEL, 43, SPECIES_COSMOEM}),
    },

    [SPECIES_COSMOEM] =
    {
        .baseHP        = 43,
        .baseAttack    = 29,
        .baseDefense   = 131,
        .baseSpeed     = 37,
        .baseSpAttack  = 29,
        .baseSpDefense = 131,
        .types = { TYPE_PSYCHIC, TYPE_PSYCHIC },
        .catchRate = 45,
        .expYield = 140,
        .evYield_Defense = 1,
        .evYield_SpDefense = 1,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_NO_EGGS_DISCOVERED, EGG_GROUP_NO_EGGS_DISCOVERED },
        .abilities = { ABILITY_STURDY, ABILITY_NONE },
        .bodyColor = BODY_COLOR_BLUE,
        .isLegendary = TRUE,
        .speciesName = _("Cosmovum"),
        .cryId = CRY_COSMOEM,
        .natDexNum = NATIONAL_DEX_COSMOEM,
        .categoryName = _("Urgestirns"),
        .height = 1,
        .weight = 9999,
        .description = POKEDEX_DESC_STRING(
            "Es nimmt Licht in sich auf und wächst so\n"
            "immer weiter. Seine goldene Schale ist\n"
            "überraschend hart."),
        .pokemonScale = 682,
        .pokemonOffset = 24,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Cosmoem, 48, 48),
        .frontPicYOffset = 9,
        .frontAnimFrames = sAnims_Cosmoem,
        .frontAnimId = ANIM_RISING_WOBBLE,
        .enemyMonElevation = 3,
        BACK_PIC(Cosmoem, 64, 40),
        .backPicYOffset = 17,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(Cosmoem),
        ICON(Cosmoem, 0),
        .footprint = gMonFootprint_Cosmoem,
        LEARNSETS(Cosmoem),
        .evolutions = EVOLUTION({EVO_LEVEL_DAY, 53, SPECIES_SOLGALEO},
                                {EVO_LEVEL_NIGHT, 53, SPECIES_LUNALA}),
    },

    [SPECIES_SOLGALEO] =
    {
        .baseHP        = 137,
        .baseAttack    = 137,
        .baseDefense   = 107,
        .baseSpeed     = 97,
        .baseSpAttack  = 113,
        .baseSpDefense = 89,
        .types = { TYPE_PSYCHIC, TYPE_STEEL },
        .catchRate = 45,
        .expYield = 306,
        .evYield_Attack = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_NO_EGGS_DISCOVERED, EGG_GROUP_NO_EGGS_DISCOVERED },
        .abilities = { ABILITY_FULL_METAL_BODY, ABILITY_NONE },
        .bodyColor = BODY_COLOR_WHITE,
        .isLegendary = TRUE,
        .speciesName = _("Solgaleo"),
        .cryId = CRY_SOLGALEO,
        .natDexNum = NATIONAL_DEX_SOLGALEO,
        .categoryName = _("Sonnenkreis"),
        .height = 34,
        .weight = 2300,
        .description = POKEDEX_DESC_STRING(
            "Einst wurde es â€žSonnenverschlingerâ€œ\n"
            "genannt. Es strahlt unerschöpfliche\n"
            "Lichtenergie aus."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 405,
        .trainerOffset = 8,
        FRONT_PIC(Solgaleo, 64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_Solgaleo,
        .frontAnimId = ANIM_GROW_VIBRATE,
        BACK_PIC(Solgaleo, 64, 64),
        .backPicYOffset = 3,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(Solgaleo),
        ICON(Solgaleo, 0),
        .footprint = gMonFootprint_Solgaleo,
        LEARNSETS(Solgaleo),
    },

    [SPECIES_LUNALA] =
    {
        .baseHP        = 137,
        .baseAttack    = 113,
        .baseDefense   = 89,
        .baseSpeed     = 97,
        .baseSpAttack  = 137,
        .baseSpDefense = 107,
        .types = { TYPE_PSYCHIC, TYPE_GHOST },
        .catchRate = 45,
        .expYield = 306,
        .evYield_SpAttack = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_NO_EGGS_DISCOVERED, EGG_GROUP_NO_EGGS_DISCOVERED },
        .abilities = { ABILITY_SHADOW_SHIELD, ABILITY_NONE },
        .bodyColor = BODY_COLOR_PURPLE,
        .isLegendary = TRUE,
        .speciesName = _("Lunala"),
        .cryId = CRY_LUNALA,
        .natDexNum = NATIONAL_DEX_LUNALA,
        .categoryName = _("Mondscheiben"),
        .height = 40,
        .weight = 1200,
        .description = POKEDEX_DESC_STRING(
            "Ihm wurde der Name â€žMondbringerâ€œ\n"
            "verliehen. Solange es lebt, wandelt es\n"
            "jedes Licht in Energie um."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 411,
        .trainerOffset = 5,
        FRONT_PIC(Lunala, 64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_Lunala,
        .frontAnimId = ANIM_CIRCULAR_VIBRATE,
        .enemyMonElevation = 6,
        BACK_PIC(Lunala, 64, 64),
        .backPicYOffset = 2,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(Lunala),
        ICON(Lunala, 2),
        .footprint = gMonFootprint_Lunala,
        LEARNSETS(Lunala),
    },
#endif //P_FAMILY_COSMOG

#if P_FAMILY_NIHILEGO
    [SPECIES_NIHILEGO] =
    {
        .baseHP        = 109,
        .baseAttack    = 53,
        .baseDefense   = 47,
        .baseSpeed     = 103,
        .baseSpAttack  = 127,
        .baseSpDefense = 131,
        .types = { TYPE_ROCK, TYPE_POISON },
        .catchRate = 45,
        .expYield = 257,
        .evYield_SpDefense = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_NO_EGGS_DISCOVERED, EGG_GROUP_NO_EGGS_DISCOVERED },
        .abilities = { ABILITY_BEAST_BOOST, ABILITY_NONE },
        .bodyColor = BODY_COLOR_WHITE,
        .isUltraBeast = TRUE,
        .speciesName = _("Anego"),
        .cryId = CRY_NIHILEGO,
        .natDexNum = NATIONAL_DEX_NIHILEGO,
        .categoryName = _("Parasiten"),
        .height = 12,
        .weight = 555,
        .description = POKEDEX_DESC_STRING(
            "Anego kam durch eine Ultrapforte in diese\n"
            "Welt. Es scheint ein Parasit zu sein, der\n"
            "Pokémon und Menschen befällt."),
        .pokemonScale = 282,
        .pokemonOffset = 4,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Nihilego, 48, 64),
        .frontPicYOffset = 3,
        .frontAnimFrames = sAnims_Nihilego,
        .frontAnimId = ANIM_CIRCULAR_STRETCH_TWICE,
        .enemyMonElevation = 6,
        BACK_PIC(Nihilego, 64, 48),
        .backPicYOffset = 9,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(Nihilego),
        ICON(Nihilego, 0),
        .footprint = gMonFootprint_Nihilego,
        LEARNSETS(Nihilego),
    },
#endif //P_FAMILY_NIHILEGO

#if P_FAMILY_BUZZWOLE
    [SPECIES_BUZZWOLE] =
    {
        .baseHP        = 107,
        .baseAttack    = 139,
        .baseDefense   = 139,
        .baseSpeed     = 79,
        .baseSpAttack  = 53,
        .baseSpDefense = 53,
        .types = { TYPE_BUG, TYPE_FIGHTING },
        .catchRate = 45,
        .expYield = 257,
        .evYield_Attack = 1,
        .evYield_Defense = 2,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_NO_EGGS_DISCOVERED, EGG_GROUP_NO_EGGS_DISCOVERED },
        .abilities = { ABILITY_BEAST_BOOST, ABILITY_NONE },
        .bodyColor = BODY_COLOR_RED,
        .isUltraBeast = TRUE,
        .speciesName = _("Masskito"),
        .cryId = CRY_BUZZWOLE,
        .natDexNum = NATIONAL_DEX_BUZZWOLE,
        .categoryName = _("Ausdehnungs"),
        .height = 24,
        .weight = 3336,
        .description = POKEDEX_DESC_STRING(
            "Diese Ultrabestie stellt gerne ihre extrem\n"
            "angeschwollenen Muskeln stolz zur Schau."),
        .pokemonScale = 256,
        .pokemonOffset = 3,
        .trainerScale = 369,
        .trainerOffset = 7,
        FRONT_PIC(Buzzwole, 64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_Buzzwole,
        .frontAnimId = ANIM_SHRINK_GROW_VIBRATE_FAST,
        BACK_PIC(Buzzwole, 64, 56),
        .backPicYOffset = 14,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(Buzzwole),
        ICON(Buzzwole, 0),
        .footprint = gMonFootprint_Buzzwole,
        LEARNSETS(Buzzwole),
    },
#endif //P_FAMILY_BUZZWOLE

#if P_FAMILY_PHEROMOSA
    [SPECIES_PHEROMOSA] =
    {
        .baseHP        = 71,
        .baseAttack    = 137,
        .baseDefense   = 37,
        .baseSpeed     = 151,
        .baseSpAttack  = 137,
        .baseSpDefense = 37,
        .types = { TYPE_BUG, TYPE_FIGHTING },
        .catchRate = 45,
        .expYield = 257,
        .evYield_Speed = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_NO_EGGS_DISCOVERED, EGG_GROUP_NO_EGGS_DISCOVERED },
        .abilities = { ABILITY_BEAST_BOOST, ABILITY_NONE },
        .bodyColor = BODY_COLOR_WHITE,
        .isUltraBeast = TRUE,
        .speciesName = _("Schabelle"),
        .cryId = CRY_PHEROMOSA,
        .natDexNum = NATIONAL_DEX_PHEROMOSA,
        .categoryName = _("Eleganz"),
        .height = 18,
        .weight = 250,
        .description = POKEDEX_DESC_STRING(
            "Diese bedrohliche Ultrabestie wurde\n"
            "dabei beobachtet, wie sie mit\n"
            "ungeheuerlicher Geschwindigkeit\n"
            "über die Erde hinwegfegt."),
        .pokemonScale = 267,
        .pokemonOffset = 2,
        .trainerScale = 286,
        .trainerOffset = 1,
        FRONT_PIC(Pheromosa, 56, 64),
        .frontPicYOffset = 1,
        .frontAnimFrames = sAnims_Pheromosa,
        .frontAnimId = ANIM_SHRINK_GROW,
        BACK_PIC(Pheromosa, 64, 64),
        .backPicYOffset = 2,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(Pheromosa),
        ICON(Pheromosa, 2),
        .footprint = gMonFootprint_Pheromosa,
        LEARNSETS(Pheromosa),
    },
#endif //P_FAMILY_PHEROMOSA

#if P_FAMILY_XURKITREE
    [SPECIES_XURKITREE] =
    {
        .baseHP        = 83,
        .baseAttack    = 89,
        .baseDefense   = 71,
        .baseSpeed     = 83,
        .baseSpAttack  = 173,
        .baseSpDefense = 71,
        .types = { TYPE_ELECTRIC, TYPE_ELECTRIC },
        .catchRate = 45,
        .expYield = 257,
        .evYield_SpAttack = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_NO_EGGS_DISCOVERED, EGG_GROUP_NO_EGGS_DISCOVERED },
        .abilities = { ABILITY_BEAST_BOOST, ABILITY_NONE },
        .bodyColor = BODY_COLOR_BLACK,
        .isUltraBeast = TRUE,
        .speciesName = _("Voltriant"),
        .cryId = CRY_XURKITREE,
        .natDexNum = NATIONAL_DEX_XURKITREE,
        .categoryName = _("Illuminations"),
        .height = 38,
        .weight = 1000,
        .description = POKEDEX_DESC_STRING(
            "Eine geheimnisvolle Ultrabestie,\n"
            "aus deren Körper furchterregende\n"
            "Mengen an elektrischer Energie\n"
            "strömen."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 610,
        .trainerOffset = 17,
        FRONT_PIC(Xurkitree, 64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_Xurkitree,
        .frontAnimId = ANIM_SHAKE_FLASH_YELLOW_FAST,
        BACK_PIC(Xurkitree, 64, 64),
        .backPicYOffset = 2,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(Xurkitree),
        ICON(Xurkitree, 0),
        .footprint = gMonFootprint_Xurkitree,
        LEARNSETS(Xurkitree),
    },
#endif //P_FAMILY_XURKITREE

#if P_FAMILY_CELESTEELA
    [SPECIES_CELESTEELA] =
    {
        .baseHP        = 97,
        .baseAttack    = 101,
        .baseDefense   = 103,
        .baseSpeed     = 61,
        .baseSpAttack  = 107,
        .baseSpDefense = 101,
        .types = { TYPE_STEEL, TYPE_FLYING },
        .catchRate = 45,
        .expYield = 257,
        .evYield_Attack = 1,
        .evYield_Defense = 1,
        .evYield_SpAttack = 1,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_NO_EGGS_DISCOVERED, EGG_GROUP_NO_EGGS_DISCOVERED },
        .abilities = { ABILITY_BEAST_BOOST, ABILITY_NONE },
        .bodyColor = BODY_COLOR_GREEN,
        .isUltraBeast = TRUE,
        .speciesName = _("Kaguron"),
        .cryId = CRY_CELESTEELA,
        .natDexNum = NATIONAL_DEX_CELESTEELA,
        .categoryName = _("Raketenstart"),
        .height = 92,
        .weight = 9999,
        .description = POKEDEX_DESC_STRING(
            "Eine der gefährlichen Ultrabestien. In\n"
            "ihren riesigen Armen wurden hohe\n"
            "Energiemengen nachgewiesen."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 516,
        .trainerOffset = 13,
        FRONT_PIC(Celesteela, 64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_Celesteela,
        .frontAnimId = ANIM_GROW_STUTTER_SLOW,
        BACK_PIC(Celesteela, 64, 64),
        .backPicYOffset = 0,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(Celesteela),
        ICON(Celesteela, 0),
        .footprint = gMonFootprint_Celesteela,
        LEARNSETS(Celesteela),
    },
#endif //P_FAMILY_CELESTEELA

#if P_FAMILY_KARTANA
    [SPECIES_KARTANA] =
    {
        .baseHP        = 59,
        .baseAttack    = 181,
        .baseDefense   = 131,
        .baseSpeed     = 109,
        .baseSpAttack  = 59,
        .baseSpDefense = 31,
        .types = { TYPE_GRASS, TYPE_STEEL },
        .catchRate = 45,
        .expYield = 257,
        .evYield_Attack = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_NO_EGGS_DISCOVERED, EGG_GROUP_NO_EGGS_DISCOVERED },
        .abilities = { ABILITY_BEAST_BOOST, ABILITY_NONE },
        .bodyColor = BODY_COLOR_WHITE,
        .isUltraBeast = TRUE,
        .speciesName = _("Katagami"),
        .cryId = CRY_KARTANA,
        .natDexNum = NATIONAL_DEX_KARTANA,
        .categoryName = _("Schwertkunst"),
        .height = 3,
        .weight = 1,
        .description = POKEDEX_DESC_STRING(
            "Der Körper dieser Ultrabestie ist dünn wie\n"
            "Papier und so scharfkantig wie eine\n"
            "geschliffene Klinge."),
        .pokemonScale = 530,
        .pokemonOffset = 13,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Kartana, 64, 64),
        .frontPicYOffset = 2,
        .frontAnimFrames = sAnims_Kartana,
        .frontAnimId = ANIM_H_VIBRATE,
        .enemyMonElevation = 3,
        BACK_PIC(Kartana, 64, 48),
        .backPicYOffset = 11,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(Kartana),
        ICON(Kartana, 0),
        .footprint = gMonFootprint_Kartana,
        LEARNSETS(Kartana),
    },
#endif //P_FAMILY_KARTANA

#if P_FAMILY_GUZZLORD
    [SPECIES_GUZZLORD] =
    {
        .baseHP        = 223,
        .baseAttack    = 101,
        .baseDefense   = 53,
        .baseSpeed     = 43,
        .baseSpAttack  = 97,
        .baseSpDefense = 53,
        .types = { TYPE_DARK, TYPE_DRAGON },
        .catchRate = 45,
        .expYield = 257,
        .evYield_HP = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_NO_EGGS_DISCOVERED, EGG_GROUP_NO_EGGS_DISCOVERED },
        .abilities = { ABILITY_BEAST_BOOST, ABILITY_NONE },
        .bodyColor = BODY_COLOR_BLACK,
        .isUltraBeast = TRUE,
        .speciesName = _("Schlingking"),
        .cryId = CRY_GUZZLORD,
        .natDexNum = NATIONAL_DEX_GUZZLORD,
        .categoryName = _("Gaumenfolter"),
        .height = 55,
        .weight = 8880,
        .description = POKEDEX_DESC_STRING(
            "Eine Ultrabestie, die einigen\n"
            "Berichten zufolge ganze Berge\n"
            "vertilgt und selbst mehrstöckige\n"
            "Gebäude verschlingen kann."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 721,
        .trainerOffset = 19,
        FRONT_PIC(Guzzlord, 64, 64),
        .frontPicYOffset = 3,
        .frontAnimFrames = sAnims_Guzzlord,
        .frontAnimId = ANIM_SHRINK_GROW_VIBRATE_FAST,
        BACK_PIC(Guzzlord, 64, 56),
        .backPicYOffset = 10,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(Guzzlord),
        ICON(Guzzlord, 0),
        .footprint = gMonFootprint_Guzzlord,
        LEARNSETS(Guzzlord),
    },
#endif //P_FAMILY_GUZZLORD

#if P_FAMILY_NECROZMA
#define NECROZMA_MISC_INFO                                                              \
        .genderRatio = MON_GENDERLESS,                                                  \
        .eggCycles = 120,                                                               \
        .friendship = 0,                                                                \
        .growthRate = GROWTH_SLOW,                                                      \
        .eggGroups = { EGG_GROUP_NO_EGGS_DISCOVERED, EGG_GROUP_NO_EGGS_DISCOVERED },    \
        .noFlip = TRUE,                                                                 \
        .speciesName = _("Schlingking"),                                                   \
        .natDexNum = NATIONAL_DEX_NECROZMA,                                             \
        .categoryName = _("Gaumenfolter"),                                                     \
        .pokemonScale = 256,                                                            \
        .pokemonOffset = 3,                                                             \
        .trainerScale = 369,                                                            \
        .trainerOffset = 7,                                                             \
        .footprint = gMonFootprint_Necrozma,                                            \
        LEARNSETS(Necrozma),                                                            \
        .formSpeciesIdTable = sNecrozmaFormSpeciesIdTable,                              \
        .isLegendary = TRUE

    [SPECIES_NECROZMA] =
    {
        NECROZMA_MISC_INFO,
        .baseHP        = 97,
        .baseAttack    = 107,
        .baseDefense   = 101,
        .baseSpeed     = 79,
        .baseSpAttack  = 127,
        .baseSpDefense = 89,
        .types = { TYPE_PSYCHIC, TYPE_PSYCHIC },
        .catchRate = 255,
        .expYield = 270,
        .evYield_Attack = 1,
        .evYield_SpAttack = 2,
        .abilities = { ABILITY_PRISM_ARMOR, ABILITY_NONE },
        .bodyColor = BODY_COLOR_BLACK,
        .cryId = CRY_NECROZMA,
        .height = 24,
        .weight = 2300,
        .description = POKEDEX_DESC_STRING(
            "Diese einer Ultrabestie ähnelnde\n"
            "Kreatur ist wohl vor Urzeiten aus\n"
            "einer anderen Welt gekommen und\n"
            "ruhte lange Zeit unter der Erde."),
        FRONT_PIC(Necrozma, 64, 64),
        .frontPicYOffset = 2,
        .frontAnimFrames = sAnims_Necrozma,
        .frontAnimId = ANIM_GROW_VIBRATE,
        .enemyMonElevation = 6,
        BACK_PIC(Necrozma, 64, 64),
        .backPicYOffset = 4,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(Necrozma),
        ICON(Necrozma, 0),
    },

#if P_FUSION_FORMS
    [SPECIES_NECROZMA_DUSK_MANE] =
    {
        NECROZMA_MISC_INFO,
        .baseHP        = 97,
        .baseAttack    = 157,
        .baseDefense   = 127,
        .baseSpeed     = 77,
        .baseSpAttack  = 113,
        .baseSpDefense = 109,
        .types = { TYPE_PSYCHIC, TYPE_STEEL },
        .catchRate = 255,
        .expYield = 306,
        .evYield_Attack = 3,
        .abilities = { ABILITY_PRISM_ARMOR, ABILITY_NONE },
        .bodyColor = BODY_COLOR_YELLOW,
        .cryId = CRY_NECROZMA_DUSK_MANE,
        .height = 38,
        .weight = 4600,
        .description = POKEDEX_DESC_STRING(
            "Diese einer Ultrabestie ähnelnde\n"
            "Kreatur ist wohl vor Urzeiten aus\n"
            "einer anderen Welt gekommen und\n"
            "ruhte lange Zeit unter der Erde."),
        FRONT_PIC(NecrozmaDuskMane, 64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_Necrozma,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(NecrozmaDuskMane, 64, 64),
        .backPicYOffset = 1,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(NecrozmaDuskMane),
        ICON(NecrozmaDuskMane, 0),
        .cannotBeTraded = TRUE,
        .formChangeTable = sNecrozmaDuskManeFormChangeTable,
    },

    [SPECIES_NECROZMA_DAWN_WINGS] =
    {
        NECROZMA_MISC_INFO,
        .baseHP        = 97,
        .baseAttack    = 113,
        .baseDefense   = 109,
        .baseSpeed     = 77,
        .baseSpAttack  = 157,
        .baseSpDefense = 127,
        .types = { TYPE_PSYCHIC, TYPE_GHOST },
        .catchRate = 255,
        .expYield = 306,
        .evYield_SpAttack = 3,
        .abilities = { ABILITY_PRISM_ARMOR, ABILITY_NONE },
        .bodyColor = BODY_COLOR_BLUE,
        .cryId = CRY_NECROZMA_DAWN_WINGS,
        .height = 42,
        .weight = 3500,
        .description = POKEDEX_DESC_STRING(
            "Diese einer Ultrabestie ähnelnde\n"
            "Kreatur ist wohl vor Urzeiten aus\n"
            "einer anderen Welt gekommen und\n"
            "ruhte lange Zeit unter der Erde."),
        FRONT_PIC(NecrozmaDawnWings, 64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_Necrozma,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .enemyMonElevation = 6,
        BACK_PIC(NecrozmaDawnWings, 64, 64),
        .backPicYOffset = 2,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(NecrozmaDawnWings),
        ICON(NecrozmaDawnWings, 0),
        .cannotBeTraded = TRUE,
        .formChangeTable = sNecrozmaDawnWingsFormChangeTable,
    },

#if P_ULTRA_BURST_FORMS
    [SPECIES_NECROZMA_ULTRA] =
    {
        NECROZMA_MISC_INFO,
        .baseHP        = 97,
        .baseAttack    = 167,
        .baseDefense   = 97,
        .baseSpeed     = 129,
        .baseSpAttack  = 167,
        .baseSpDefense = 97,
        .types = { TYPE_PSYCHIC, TYPE_DRAGON },
        .catchRate = 255,
        .expYield = 339,
        .evYield_Attack = 1,
        .evYield_Speed = 1,
        .evYield_SpAttack = 1,
        .abilities = { ABILITY_NEUROFORCE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_YELLOW,
        .cryId = CRY_NECROZMA_ULTRA,
        .height = 75,
        .weight = 2300,
        .description = POKEDEX_DESC_STRING(
            "Diese einer Ultrabestie ähnelnde\n"
            "Kreatur ist wohl vor Urzeiten aus\n"
            "einer anderen Welt gekommen und\n"
            "ruhte lange Zeit unter der Erde."),
        FRONT_PIC(NecrozmaUltra, 64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_Necrozma,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .enemyMonElevation = 5,
        BACK_PIC(NecrozmaUltra, 64, 64),
        .backPicYOffset = 3,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(NecrozmaUltra),
        ICON(NecrozmaUltra, 2),
        .cannotBeTraded = TRUE,
        .isUltraBurst = TRUE,
    },
#endif //P_ULTRA_BURST_FORMS
#endif //P_FUSION_FORMS
#endif //P_FAMILY_NECROZMA

#if P_FAMILY_MAGEARNA
#define MAGEARNA_MISC_INFO(Form)                                                        \
        .baseHP        = 80,                                                            \
        .baseAttack    = 95,                                                            \
        .baseDefense   = 115,                                                           \
        .baseSpeed     = 65,                                                            \
        .baseSpAttack  = 130,                                                           \
        .baseSpDefense = 115,                                                           \
        .types = { TYPE_STEEL, TYPE_FAIRY },                                            \
        .catchRate = 3,                                                                 \
        .expYield = 270,                                                                \
        .evYield_SpAttack = 3,                                                          \
        .genderRatio = MON_GENDERLESS,                                                  \
        .eggCycles = 120,                                                               \
        .friendship = 0,                                                                \
        .growthRate = GROWTH_SLOW,                                                      \
        .eggGroups = { EGG_GROUP_NO_EGGS_DISCOVERED, EGG_GROUP_NO_EGGS_DISCOVERED },    \
        .abilities = { ABILITY_SOUL_HEART, ABILITY_NONE },                              \
        .speciesName = _("Necrozma"),                                                   \
        .cryId = CRY_MAGEARNA,                                                          \
        .natDexNum = NATIONAL_DEX_MAGEARNA,                                             \
        .categoryName = _("Prisma"),                                                \
        .height = 10,                                                                   \
        .weight = 805,                                                                  \
        .pokemonScale = 305,                                                            \
        .pokemonOffset = 7,                                                             \
        .trainerScale = 257,                                                            \
        .trainerOffset = 0,                                                             \
        FRONT_PIC(Form, 56, 64),                                                        \
        .frontPicYOffset = 0,                                                           \
        .frontAnimFrames = sAnims_Magearna,                                             \
        .frontAnimId = ANIM_H_SLIDE_SLOW,                                               \
        BACK_PIC(Form, 64, 56),                                                         \
        .backPicYOffset = 4,                                                            \
        PALETTES(Form),                                                                 \
        ICON(Form, 0),                                                                  \
        .footprint = gMonFootprint_Magearna,                                            \
        LEARNSETS(Magearna),                                                            \
        .formSpeciesIdTable = sMagearnaFormSpeciesIdTable,                              \
        .isMythical = TRUE
    //.backAnimId = BACK_ANIM_NONE,

    [SPECIES_MAGEARNA] =
    {
        MAGEARNA_MISC_INFO(Magearna),
        .bodyColor = BODY_COLOR_GRAY,
        .description = POKEDEX_DESC_STRING(
            "Dieses Pokémon wurde vor über 500\n"
            "Jahren künstlich erschaffen. Es\n"
            "versteht die Sprache der Menschen,\n"
            "ohne sie selbst zu sprechen."),
    },
    [SPECIES_MAGEARNA_ORIGINAL_COLOR] =
    {
        MAGEARNA_MISC_INFO(MagearnaOriginalColor),
        .bodyColor = BODY_COLOR_RED,
        .description = POKEDEX_DESC_STRING(
            "Dieses Pokémon wurde vor über 500\n"
            "Jahren künstlich erschaffen. Es\n"
            "versteht die Sprache der Menschen,\n"
            "ohne sie selbst zu sprechen."),
    },
#endif //P_FAMILY_MAGEARNA

#if P_FAMILY_MARSHADOW
    [SPECIES_MARSHADOW] =
    {
        .baseHP        = 90,
        .baseAttack    = 125,
        .baseDefense   = 80,
        .baseSpeed     = 125,
        .baseSpAttack  = 90,
        .baseSpDefense = 90,
        .types = { TYPE_FIGHTING, TYPE_GHOST },
        .catchRate = 3,
        .expYield = 270,
        .evYield_Attack = 2,
        .evYield_Speed = 1,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_NO_EGGS_DISCOVERED, EGG_GROUP_NO_EGGS_DISCOVERED },
        .abilities = { ABILITY_TECHNICIAN, ABILITY_NONE },
        .bodyColor = BODY_COLOR_GRAY,
        .noFlip = TRUE,
        .speciesName = _("Marshadow"),
        .cryId = CRY_MARSHADOW,
        .natDexNum = NATIONAL_DEX_MARSHADOW,
        .categoryName = _("Dunkelwesen"),
        .height = 7,
        .weight = 222,
        .description = POKEDEX_DESC_STRING(
            "Da es in der Lage ist, mit jedem Schatten\n"
            "zu verschmelzen, ist es lange Zeit\n"
            "unentdeckt geblieben."),
        .pokemonScale = 365,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Marshadow, 32, 56),
        .frontPicYOffset = 9,
        .frontAnimFrames = sAnims_Marshadow,
        .frontAnimId = ANIM_V_SHAKE,
        BACK_PIC(Marshadow, 40, 56),
        .backPicYOffset = 6,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(Marshadow),
        ICON(Marshadow, 0),
        .footprint = gMonFootprint_Marshadow,
        LEARNSETS(Marshadow),
        .isMythical = TRUE,
    },
#endif //P_FAMILY_MARSHADOW

#if P_FAMILY_POIPOLE
    [SPECIES_POIPOLE] =
    {
        .baseHP        = 67,
        .baseAttack    = 73,
        .baseDefense   = 67,
        .baseSpeed     = 73,
        .baseSpAttack  = 73,
        .baseSpDefense = 67,
        .types = { TYPE_POISON, TYPE_POISON },
        .catchRate = 45,
        .expYield = 189,
        .evYield_Speed = 1,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_NO_EGGS_DISCOVERED, EGG_GROUP_NO_EGGS_DISCOVERED },
        .abilities = { ABILITY_BEAST_BOOST, ABILITY_NONE },
        .bodyColor = BODY_COLOR_PURPLE,
        .isUltraBeast = TRUE,
        .speciesName = _("Venicro"),
        .cryId = CRY_POIPOLE,
        .natDexNum = NATIONAL_DEX_POIPOLE,
        .categoryName = _("Giftdorn"),
        .height = 6,
        .weight = 18,
        .description = POKEDEX_DESC_STRING(
            "Diese Ultrabestie wird in der Welt,\n"
            "aus der sie kommt, so gemocht, dass\n"
            "sie oft als Partner für Reisen\n"
            "gewählt wird."),
        .pokemonScale = 422,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Poipole, 40, 56),
        .frontPicYOffset = 8,
        .frontAnimFrames = sAnims_Poipole,
        .frontAnimId = ANIM_SHAKE_GLOW_PURPLE_SLOW,
        .enemyMonElevation = 9,
        BACK_PIC(Poipole, 48, 56),
        .backPicYOffset = 6,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(Poipole),
        ICON(Poipole, 0),
        .footprint = gMonFootprint_Poipole,
        LEARNSETS(Poipole),
        .evolutions = EVOLUTION({EVO_MOVE, MOVE_DRAGON_PULSE, SPECIES_NAGANADEL}),
    },

    [SPECIES_NAGANADEL] =
    {
        .baseHP        = 73,
        .baseAttack    = 73,
        .baseDefense   = 73,
        .baseSpeed     = 121,
        .baseSpAttack  = 127,
        .baseSpDefense = 73,
        .types = { TYPE_POISON, TYPE_DRAGON },
        .catchRate = 45,
        .expYield = 243,
        .evYield_SpAttack = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_NO_EGGS_DISCOVERED, EGG_GROUP_NO_EGGS_DISCOVERED },
        .abilities = { ABILITY_BEAST_BOOST, ABILITY_NONE },
        .bodyColor = BODY_COLOR_PURPLE,
        .isUltraBeast = TRUE,
        .speciesName = _("Agoyon"),
        .cryId = CRY_NAGANADEL,
        .natDexNum = NATIONAL_DEX_NAGANADEL,
        .categoryName = _("Giftdorn"),
        .height = 36,
        .weight = 1500,
        .description = POKEDEX_DESC_STRING(
            "Diese Ultrabestie verschießt aus ihren\n"
            "Giftstacheln ein leuchtendes,\n"
            "dickflüssiges Gift."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 405,
        .trainerOffset = 8,
        FRONT_PIC(Naganadel, 64, 64),
        .frontPicYOffset = 1,
        .frontAnimFrames = sAnims_Naganadel,
        .frontAnimId = ANIM_TRIANGLE_DOWN_TWICE,
        .enemyMonElevation = 7,
        BACK_PIC(Naganadel, 64, 56),
        .backPicYOffset = 6,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(Naganadel),
        ICON(Naganadel, 0),
        .footprint = gMonFootprint_Naganadel,
        LEARNSETS(Naganadel),
    },
#endif //P_FAMILY_POIPOLE

#if P_FAMILY_STAKATAKA
    [SPECIES_STAKATAKA] =
    {
        .baseHP        = 61,
        .baseAttack    = 131,
        .baseDefense   = 211,
        .baseSpeed     = 13,
        .baseSpAttack  = 53,
        .baseSpDefense = 101,
        .types = { TYPE_ROCK, TYPE_STEEL },
        .catchRate = 30,
        .expYield = 257,
        .evYield_Defense = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_NO_EGGS_DISCOVERED, EGG_GROUP_NO_EGGS_DISCOVERED },
        .abilities = { ABILITY_BEAST_BOOST, ABILITY_NONE },
        .bodyColor = BODY_COLOR_GRAY,
        .noFlip = TRUE,
        .isUltraBeast = TRUE,
        .speciesName = _("Muramura"),
        .cryId = CRY_STAKATAKA,
        .natDexNum = NATIONAL_DEX_STAKATAKA,
        .categoryName = _("Steinmauer"),
        .height = 55,
        .weight = 8200,
        .description = POKEDEX_DESC_STRING(
            "Diese Kreatur kam durch eine\n"
            "Ultrapforte. Sie besteht\n"
            "anscheinend aus mehreren\n"
            "aufeinandergestapelten Wesen."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 721,
        .trainerOffset = 19,
        FRONT_PIC(Stakataka, 64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_Stakataka,
        .frontAnimId = ANIM_GROW_VIBRATE,
        BACK_PIC(Stakataka, 64, 48),
        .backPicYOffset = 12,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(Stakataka),
        ICON(Stakataka, 0),
        .footprint = gMonFootprint_Stakataka,
        LEARNSETS(Stakataka),
    },
#endif //P_FAMILY_STAKATAKA

#if P_FAMILY_BLACEPHALON
    [SPECIES_BLACEPHALON] =
    {
        .baseHP        = 53,
        .baseAttack    = 127,
        .baseDefense   = 53,
        .baseSpeed     = 107,
        .baseSpAttack  = 151,
        .baseSpDefense = 79,
        .types = { TYPE_FIRE, TYPE_GHOST },
        .catchRate = 30,
        .expYield = 257,
        .evYield_SpAttack = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_NO_EGGS_DISCOVERED, EGG_GROUP_NO_EGGS_DISCOVERED },
        .abilities = { ABILITY_BEAST_BOOST, ABILITY_NONE },
        .bodyColor = BODY_COLOR_WHITE,
        .noFlip = TRUE,
        .isUltraBeast = TRUE,
        .speciesName = _("Kopplosio"),
        .cryId = CRY_BLACEPHALON,
        .natDexNum = NATIONAL_DEX_BLACEPHALON,
        .categoryName = _("Feuerwerks"),
        .height = 18,
        .weight = 130,
        .description = POKEDEX_DESC_STRING(
            "Eine Ultrabestie, die durch eine\n"
            "Ultrapforte kam. Sie erschreckt ihre\n"
            "Gegner mit Explosionen und raubt ihnen\n"
            "dann ihre Lebenskraft."),
        .pokemonScale = 267,
        .pokemonOffset = 2,
        .trainerScale = 286,
        .trainerOffset = 1,
        FRONT_PIC(Blacephalon, 56, 64),
        .frontPicYOffset = 1,
        .frontAnimFrames = sAnims_Blacephalon,
        .frontAnimId = ANIM_SHAKE_GLOW_RED,
        BACK_PIC(Blacephalon, 64, 48),
        .backPicYOffset = 9,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(Blacephalon),
        ICON(Blacephalon, 0),
        .footprint = gMonFootprint_Blacephalon,
        LEARNSETS(Blacephalon),
    },
#endif //P_FAMILY_BLACEPHALON

#if P_FAMILY_ZERAORA
    [SPECIES_ZERAORA] =
    {
        .baseHP        = 88,
        .baseAttack    = 112,
        .baseDefense   = 75,
        .baseSpeed     = 143,
        .baseSpAttack  = 102,
        .baseSpDefense = 80,
        .types = { TYPE_ELECTRIC, TYPE_ELECTRIC },
        .catchRate = 3,
        .expYield = 270,
        .evYield_Speed = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_NO_EGGS_DISCOVERED, EGG_GROUP_NO_EGGS_DISCOVERED },
        .abilities = { ABILITY_VOLT_ABSORB, ABILITY_NONE },
        .bodyColor = BODY_COLOR_YELLOW,
        .isMythical = TRUE,
        .speciesName = _("Zeraora"),
        .cryId = CRY_ZERAORA,
        .natDexNum = NATIONAL_DEX_ZERAORA,
        .categoryName = _("Blitzsturm"),
        .height = 15,
        .weight = 445,
        .description = POKEDEX_DESC_STRING(
            "Schnell wie der Blitz nähert es sich\n"
            "seinen Feinden, um sie dann mit seinen\n"
            "scharfen Klauen in Stücke zu reißen."),
        .pokemonScale = 268,
        .pokemonOffset = 2,
        .trainerScale = 271,
        .trainerOffset = 0,
        FRONT_PIC(Zeraora, 64, 56),
        .frontPicYOffset = 4,
        .frontAnimFrames = sAnims_Zeraora,
        .frontAnimId = ANIM_V_STRETCH,
        BACK_PIC(Zeraora, 64, 56),
        .backPicYOffset = 11,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(Zeraora),
        ICON(Zeraora, 0),
        .footprint = gMonFootprint_Zeraora,
        LEARNSETS(Zeraora),
    },
#endif //P_FAMILY_ZERAORA

#if P_FAMILY_MELTAN
    [SPECIES_MELTAN] =
    {
        .baseHP        = 46,
        .baseAttack    = 65,
        .baseDefense   = 65,
        .baseSpeed     = 34,
        .baseSpAttack  = 55,
        .baseSpDefense = 35,
        .types = { TYPE_STEEL, TYPE_STEEL },
        .catchRate = 3,
        .expYield = 135,
        .evYield_Attack = 1,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_NO_EGGS_DISCOVERED, EGG_GROUP_NO_EGGS_DISCOVERED },
        .abilities = { ABILITY_MAGNET_PULL, ABILITY_NONE },
        .bodyColor = BODY_COLOR_GRAY,
        .isMythical = TRUE,
        .speciesName = _("Meltan"),
        .cryId = CRY_MELTAN,
        .natDexNum = NATIONAL_DEX_MELTAN,
        .categoryName = _("Mutter"),
        .height = 2,
        .weight = 80,
        .description = POKEDEX_DESC_STRING(
            "Es schmilzt Metall ein und frisst es. In\n"
            "seinem Körper wandelt es das flüssig\n"
            "gewordene Metall in Energie um."),
        .pokemonScale = 682,
        .pokemonOffset = 24,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Meltan, 32, 48),
        .frontPicYOffset = 11,
        .frontAnimFrames = sAnims_Meltan,
        .frontAnimId = ANIM_GROW_STUTTER_SLOW,
        BACK_PIC(Meltan, 40, 40),
        .backPicYOffset = 12,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(Meltan),
        ICON(Meltan, 2),
        .footprint = gMonFootprint_Meltan,
        LEARNSETS(Meltan),
    },

#define MELMETAL_MISC_INFO                                                              \
        .baseHP        = 135,                                                           \
        .baseAttack    = 143,                                                           \
        .baseDefense   = 143,                                                           \
        .baseSpeed     = 34,                                                            \
        .baseSpAttack  = 80,                                                            \
        .baseSpDefense = 65,                                                            \
        .types = { TYPE_STEEL, TYPE_STEEL },                                            \
        .catchRate = 3,                                                                 \
        .expYield = 270,                                                                \
        .evYield_Attack = 3,                                                            \
        .genderRatio = MON_GENDERLESS,                                                  \
        .eggCycles = 120,                                                               \
        .friendship = 0,                                                                \
        .growthRate = GROWTH_SLOW,                                                      \
        .eggGroups = { EGG_GROUP_NO_EGGS_DISCOVERED, EGG_GROUP_NO_EGGS_DISCOVERED },    \
        .abilities = { ABILITY_IRON_FIST, ABILITY_NONE },                               \
        .bodyColor = BODY_COLOR_GRAY,                                                   \
        .speciesName = _("Meltan"),                                                   \
        .cryId = CRY_MELMETAL,                                                          \
        .natDexNum = NATIONAL_DEX_MELMETAL,                                             \
        .categoryName = _("Mutter"),                                                   \
        .pokemonScale = 257,                                                            \
        .pokemonOffset = 10,                                                            \
        .trainerScale = 423,                                                            \
        .trainerOffset = 8,                                                             \
        .footprint = gMonFootprint_Melmetal,                                            \
        LEARNSETS(Melmetal),                                                            \
        .formSpeciesIdTable = sMelmetalFormSpeciesIdTable,                              \
        .formChangeTable = sMelmetalFormChangeTable,                                    \
        .isMythical = TRUE

    [SPECIES_MELMETAL] =
    {
        MELMETAL_MISC_INFO,
        .height = 25,
        .weight = 800,
        .description = POKEDEX_DESC_STRING(
            "Einst wurde es für seine Fähigkeit\n"
            "verehrt, Eisen erschaffen zu\n"
            "können. Nach 3 000 Jahren ist es\n"
            "aus einem unerfindlichen Grund\n"
            "wieder erwacht."),
        FRONT_PIC(Melmetal, 64, 56),
        .frontPicYOffset = 4,
        .frontAnimFrames = sAnims_Melmetal,
        .frontAnimId = ANIM_GROW_VIBRATE,
        BACK_PIC(Melmetal, 64, 40),
        .backPicYOffset = 13,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(Melmetal),
        ICON(Melmetal, 2),
    },

#if P_GIGANTAMAX_FORMS
    [SPECIES_MELMETAL_GIGANTAMAX] =
    {
        MELMETAL_MISC_INFO,
        .isGigantamax = TRUE,
        .height = 250,
        .weight = 0,
        .description = POKEDEX_DESC_STRING(
            "Einst wurde es für seine Fähigkeit\n"
            "verehrt, Eisen erschaffen zu\n"
            "können. Nach 3 000 Jahren ist es\n"
            "aus einem unerfindlichen Grund\n"
            "wieder erwacht."),
        FRONT_PIC(MelmetalGigantamax, 64, 64),
        .frontPicYOffset = 1,
        .frontAnimFrames = sAnims_MelmetalGigantamax,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(MelmetalGigantamax, 64, 64),
        .backPicYOffset = 14,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(MelmetalGigantamax),
        ICON(MelmetalGigantamax, 0),
    },
#endif //P_GIGANTAMAX_FORMS
#endif //P_FAMILY_MELTAN

#ifdef __INTELLISENSE__
};
#endif