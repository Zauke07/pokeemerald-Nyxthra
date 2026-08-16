#ifdef __INTELLISENSE__
const struct SpeciesInfo gSpeciesInfoGen5[] =
{
#endif

#if P_FAMILY_VICTINI
    [SPECIES_VICTINI] =
    {
        .baseHP        = 100,
        .baseAttack    = 100,
        .baseDefense   = 100,
        .baseSpeed     = 100,
        .baseSpAttack  = 100,
        .baseSpDefense = 100,
        .types = { TYPE_PSYCHIC, TYPE_FIRE },
        .catchRate = 3,
        .expYield = 270,
        .evYield_HP = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 100,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_NO_EGGS_DISCOVERED, EGG_GROUP_NO_EGGS_DISCOVERED },
        .abilities = { ABILITY_VICTORY_STAR, ABILITY_NONE },
        .bodyColor = BODY_COLOR_YELLOW,
        .isMythical = TRUE,
        .speciesName = _("Victini"),
        .cryId = CRY_VICTINI,
        .natDexNum = NATIONAL_DEX_VICTINI,
        .categoryName = _("Triumph"),
        .height = 4,
        .weight = 40,
        .description = POKEDEX_DESC_STRING(
            "Ein siegverheißendes Pokémon. Man\n"
            "sagt, Trainer, die ein Victini in\n"
            "ihrem Team haben, seien\n"
            "unschlagbar."),
        .pokemonScale = 491,
        .pokemonOffset = 16,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Victini, 48, 56),
        .frontPicYOffset = 10,
        .frontAnimFrames = sAnims_Victini,
        .frontAnimId = ANIM_H_JUMPS,
        BACK_PIC(Victini, 40, 64),
        .backPicYOffset = 7,
        .backAnimId = BACK_ANIM_H_SHAKE,
        PALETTES(Victini),
        ICON(Victini, 0),
        .footprint = gMonFootprint_Victini,
        LEARNSETS(Victini),
    },
#endif //P_FAMILY_VICTINI

#if P_FAMILY_SNIVY
    [SPECIES_SNIVY] =
    {
        .baseHP        = 45,
        .baseAttack    = 45,
        .baseDefense   = 55,
        .baseSpeed     = 63,
        .baseSpAttack  = 45,
        .baseSpDefense = 55,
        .types = { TYPE_GRASS, TYPE_GRASS },
        .catchRate = 45,
        .expYield = 62,
        .evYield_Speed = 1,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_GRASS },
        .abilities = { ABILITY_OVERGROW, ABILITY_NONE, ABILITY_CONTRARY },
        .bodyColor = BODY_COLOR_GREEN,
        .speciesName = _("Serpifeu"),
        .cryId = CRY_SNIVY,
        .natDexNum = NATIONAL_DEX_SNIVY,
        .categoryName = _("Grasschlange"),
        .height = 6,
        .weight = 81,
        .description = POKEDEX_DESC_STRING(
            "Im Sonnenlicht erhöht sich das\n"
            "Tempo seiner Bewegungen. Es ist mit\n"
            "seinen Schlingen geschickter als\n"
            "mit den Händen."),
        .pokemonScale = 422,
        .pokemonOffset = 15,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Snivy, 48, 40),
        .frontPicYOffset = 12,
        .frontAnimFrames = sAnims_Snivy,
        .frontAnimId = ANIM_V_STRETCH,
        BACK_PIC(Snivy, 56, 48),
        .backPicYOffset = 11,
        .backAnimId = BACK_ANIM_H_SLIDE,
        PALETTES(Snivy),
        ICON(Snivy, 1),
        .footprint = gMonFootprint_Snivy,
        LEARNSETS(Snivy),
        .evolutions = EVOLUTION({EVO_LEVEL, 17, SPECIES_SERVINE}),
    },

    [SPECIES_SERVINE] =
    {
        .baseHP        = 60,
        .baseAttack    = 60,
        .baseDefense   = 75,
        .baseSpeed     = 83,
        .baseSpAttack  = 60,
        .baseSpDefense = 75,
        .types = { TYPE_GRASS, TYPE_GRASS },
        .catchRate = 45,
        .expYield = 145,
        .evYield_Speed = 2,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_GRASS },
        .abilities = { ABILITY_OVERGROW, ABILITY_NONE, ABILITY_CONTRARY },
        .bodyColor = BODY_COLOR_GREEN,
        .speciesName = _("Efoserp"),
        .cryId = CRY_SERVINE,
        .natDexNum = NATIONAL_DEX_SERVINE,
        .categoryName = _("Grasschlange"),
        .height = 8,
        .weight = 160,
        .description = POKEDEX_DESC_STRING(
            "Es achtet stets auf Reinlichkeit, da es\n"
            "mit schmutzigen Blättern keine\n"
            "Photosynthese betreiben kann."),
        .pokemonScale = 366,
        .pokemonOffset = 9,
        .trainerScale = 257,
        .trainerOffset = 0,
        FRONT_PIC(Servine, 48, 56),
        .frontPicYOffset = 7,
        .frontAnimFrames = sAnims_Servine,
        .frontAnimId = ANIM_V_STRETCH,
        BACK_PIC(Servine, 48, 64),
        .backPicYOffset = 5,
        .backAnimId = BACK_ANIM_TRIANGLE_DOWN,
        PALETTES(Servine),
        ICON(Servine, 1),
        .footprint = gMonFootprint_Servine,
        LEARNSETS(Servine),
        .evolutions = EVOLUTION({EVO_LEVEL, 36, SPECIES_SERPERIOR}),
    },

    [SPECIES_SERPERIOR] =
    {
        .baseHP        = 75,
        .baseAttack    = 75,
        .baseDefense   = 95,
        .baseSpeed     = 113,
        .baseSpAttack  = 75,
        .baseSpDefense = 95,
        .types = { TYPE_GRASS, TYPE_GRASS },
        .catchRate = 45,
        .expYield = 238,
        .evYield_Speed = 3,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_GRASS },
        .abilities = { ABILITY_OVERGROW, ABILITY_NONE, ABILITY_CONTRARY },
        .bodyColor = BODY_COLOR_GREEN,
        .speciesName = _("Serpiroyal"),
        .cryId = CRY_SERPERIOR,
        .natDexNum = NATIONAL_DEX_SERPERIOR,
        .categoryName = _("Hoheit"),
        .height = 33,
        .weight = 630,
        .description = POKEDEX_DESC_STRING(
            "Bringt Gegner mit einem einzigen kühlen\n"
            "Blick zum Erstarren. In seinem Inneren\n"
            "verstärkt es die Energie der Sonne."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 405,
        .trainerOffset = 8,
        FRONT_PIC(Serperior, 64, 56),
        .frontPicYOffset = 4,
        .frontAnimFrames = sAnims_Serperior,
        .frontAnimId = ANIM_CIRCULAR_STRETCH_TWICE,
        BACK_PIC(Serperior, 64, 64),
        .backPicYOffset = 1,
        .backAnimId = BACK_ANIM_V_STRETCH,
        PALETTES(Serperior),
        ICON(Serperior, 1),
        .footprint = gMonFootprint_Serperior,
        LEARNSETS(Serperior),
    },
#endif //P_FAMILY_SNIVY

#if P_FAMILY_TEPIG
    [SPECIES_TEPIG] =
    {
        .baseHP        = 65,
        .baseAttack    = 63,
        .baseDefense   = 45,
        .baseSpeed     = 45,
        .baseSpAttack  = 45,
        .baseSpDefense = 45,
        .types = { TYPE_FIRE, TYPE_FIRE },
        .catchRate = 45,
        .expYield = 62,
        .evYield_HP = 1,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD },
        .abilities = { ABILITY_BLAZE, ABILITY_NONE, ABILITY_THICK_FAT },
        .bodyColor = BODY_COLOR_RED,
        .speciesName = _("Floink"),
        .cryId = CRY_TEPIG,
        .natDexNum = NATIONAL_DEX_TEPIG,
        .categoryName = _("Feuerferkel"),
        .height = 5,
        .weight = 99,
        .description = POKEDEX_DESC_STRING(
            "Weicht flink gegnerischen Angriffen\n"
            "aus und schießt Flammen aus dem\n"
            "Rüssel, mit denen es gern auch mal\n"
            "Nüsse röstet."),
        .pokemonScale = 432,
        .pokemonOffset = 15,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Tepig, 40, 48),
        .frontPicYOffset = 15,
        .frontAnimFrames = sAnims_Tepig,
        .frontAnimId = ANIM_H_SLIDE,
        BACK_PIC(Tepig, 48, 56),
        .backPicYOffset = 8,
        .backAnimId = BACK_ANIM_CONCAVE_ARC_SMALL,
        PALETTES(Tepig),
        ICON(Tepig, 0),
        .footprint = gMonFootprint_Tepig,
        LEARNSETS(Tepig),
        .evolutions = EVOLUTION({EVO_LEVEL, 17, SPECIES_PIGNITE}),
    },

    [SPECIES_PIGNITE] =
    {
        .baseHP        = 90,
        .baseAttack    = 93,
        .baseDefense   = 55,
        .baseSpeed     = 55,
        .baseSpAttack  = 70,
        .baseSpDefense = 55,
        .types = { TYPE_FIRE, TYPE_FIGHTING },
        .catchRate = 45,
        .expYield = 146,
        .evYield_Attack = 2,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD },
        .abilities = { ABILITY_BLAZE, ABILITY_NONE, ABILITY_THICK_FAT },
        .bodyColor = BODY_COLOR_RED,
        .speciesName = _("Ferkokel"),
        .cryId = CRY_PIGNITE,
        .natDexNum = NATIONAL_DEX_PIGNITE,
        .categoryName = _("Feuerferkel"),
        .height = 10,
        .weight = 555,
        .description = POKEDEX_DESC_STRING(
            "Lodert das Feuer in ihm auf, bewegt es\n"
            "sich geschmeidiger und schneller. Bei\n"
            "Gefahr lässt es ordentlich Dampf ab."),
        .pokemonScale = 305,
        .pokemonOffset = 8,
        .trainerScale = 257,
        .trainerOffset = 0,
        FRONT_PIC(Pignite, 56, 56),
        .frontPicYOffset = 8,
        .frontAnimFrames = sAnims_Pignite,
        .frontAnimId = ANIM_V_STRETCH,
        BACK_PIC(Pignite, 64, 64),
        .backPicYOffset = 9,
        .backAnimId = BACK_ANIM_GROW_STUTTER,
        PALETTES(Pignite),
        ICON(Pignite, 0),
        .footprint = gMonFootprint_Pignite,
        LEARNSETS(Pignite),
        .evolutions = EVOLUTION({EVO_LEVEL, 36, SPECIES_EMBOAR}),
    },

    [SPECIES_EMBOAR] =
    {
        .baseHP        = 110,
        .baseAttack    = 123,
        .baseDefense   = 65,
        .baseSpeed     = 65,
        .baseSpAttack  = 100,
        .baseSpDefense = 65,
        .types = { TYPE_FIRE, TYPE_FIGHTING },
        .catchRate = 45,
        .expYield = 238,
        .evYield_Attack = 3,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD },
        .abilities = { ABILITY_BLAZE, ABILITY_NONE, ABILITY_RECKLESS },
        .bodyColor = BODY_COLOR_RED,
        .noFlip = TRUE,
        .speciesName = _("Flambirex"),
        .cryId = CRY_EMBOAR,
        .natDexNum = NATIONAL_DEX_EMBOAR,
        .categoryName = _("Feuerschwein"),
        .height = 16,
        .weight = 1500,
        .description = POKEDEX_DESC_STRING(
            "Es trägt einen Backenbart aus Feuer und\n"
            "beherrscht Kampftechniken, die ebenso\n"
            "wuchtig wie schnell sind."),
        .pokemonScale = 259,
        .pokemonOffset = 1,
        .trainerScale = 296,
        .trainerOffset = 1,
        FRONT_PIC(Emboar, 64, 64),
        .frontPicYOffset = 1,
        .frontAnimFrames = sAnims_Emboar,
        .frontAnimId = ANIM_DEEP_V_SQUISH_AND_BOUNCE,
        BACK_PIC(Emboar, 64, 64),
        .backPicYOffset = 6,
        .backAnimId = BACK_ANIM_SHAKE_GLOW_RED,
        PALETTES(Emboar),
        ICON(Emboar, 0),
        .footprint = gMonFootprint_Emboar,
        LEARNSETS(Emboar),
    },
#endif //P_FAMILY_TEPIG

#if P_FAMILY_OSHAWOTT
    [SPECIES_OSHAWOTT] =
    {
        .baseHP        = 55,
        .baseAttack    = 55,
        .baseDefense   = 45,
        .baseSpeed     = 45,
        .baseSpAttack  = 63,
        .baseSpDefense = 45,
        .types = { TYPE_WATER, TYPE_WATER },
        .catchRate = 45,
        .expYield = 62,
        .evYield_SpAttack = 1,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD },
        .abilities = { ABILITY_TORRENT, ABILITY_NONE, ABILITY_SHELL_ARMOR },
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Ottaro"),
        .cryId = CRY_OSHAWOTT,
        .natDexNum = NATIONAL_DEX_OSHAWOTT,
        .categoryName = _("Otter"),
        .height = 5,
        .weight = 59,
        .description = POKEDEX_DESC_STRING(
            "Die Muschel an seinem Bauch dient\n"
            "ihm nicht nur als Waffe, sondern\n"
            "auch als Messer, mit dem es Beeren\n"
            "aufschneidet."),
        .pokemonScale = 432,
        .pokemonOffset = 15,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Oshawott, 32, 40),
        .frontPicYOffset = 14,
        .frontAnimFrames = sAnims_Oshawott,
        .frontAnimId = ANIM_H_JUMPS,
        BACK_PIC(Oshawott, 40, 48),
        .backPicYOffset = 14,
        .backAnimId = BACK_ANIM_CONCAVE_ARC_SMALL,
        PALETTES(Oshawott),
        ICON(Oshawott, 0),
        .footprint = gMonFootprint_Oshawott,
        LEARNSETS(Oshawott),
        .evolutions = EVOLUTION({EVO_LEVEL, 17, SPECIES_DEWOTT}),
    },

    [SPECIES_DEWOTT] =
    {
        .baseHP        = 75,
        .baseAttack    = 75,
        .baseDefense   = 60,
        .baseSpeed     = 60,
        .baseSpAttack  = 83,
        .baseSpDefense = 60,
        .types = { TYPE_WATER, TYPE_WATER },
        .catchRate = 45,
        .expYield = 145,
        .evYield_SpAttack = 2,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD },
        .abilities = { ABILITY_TORRENT, ABILITY_NONE, ABILITY_SHELL_ARMOR },
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Zwottronin"),
        .cryId = CRY_DEWOTT,
        .natDexNum = NATIONAL_DEX_DEWOTT,
        .categoryName = _("Schulung"),
        .height = 8,
        .weight = 245,
        .description = POKEDEX_DESC_STRING(
            "Es eignet sich durch strenges\n"
            "Training elegant ineinander\n"
            "übergehende Attacken mit seinen\n"
            "zwei Muscheln an."),
        .pokemonScale = 366,
        .pokemonOffset = 9,
        .trainerScale = 257,
        .trainerOffset = 0,
        FRONT_PIC(Dewott, 40, 56),
        .frontPicYOffset = 7,
        .frontAnimFrames = sAnims_Dewott,
        .frontAnimId = ANIM_H_VIBRATE,
        BACK_PIC(Dewott, 56, 64),
        .backPicYOffset = 5,
        .backAnimId = BACK_ANIM_CONCAVE_ARC_LARGE,
        PALETTES(Dewott),
        ICON(Dewott, 0),
        .footprint = gMonFootprint_Dewott,
        LEARNSETS(Dewott),
        .evolutions = EVOLUTION({EVO_LEVEL, 36, SPECIES_SAMUROTT},
                                {EVO_NONE, 0, SPECIES_SAMUROTT_HISUI}),
    },

#define SAMUROTT_MISC_INFO                                                  \
        .catchRate = 45,                                                    \
        .expYield = 238,                                                    \
        .genderRatio = PERCENT_FEMALE(12.5),                                \
        .eggCycles = 20,                                                    \
        .friendship = STANDARD_FRIENDSHIP,                                  \
        .growthRate = GROWTH_MEDIUM_SLOW,                                   \
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD },                  \
        .bodyColor = BODY_COLOR_BLUE,                                       \
        .speciesName = _("Zwottronin"),                                       \
        .cryId = CRY_SAMUROTT,                                              \
        .natDexNum = NATIONAL_DEX_SAMUROTT,                                 \
        .categoryName = _("Schulung"),                                    \
        .height = 15,                                                       \
        .pokemonScale = 268,                                                \
        .pokemonOffset = 2,                                                 \
        .trainerScale = 271,                                                \
        .trainerOffset = 0,                                                 \
        .footprint = gMonFootprint_Samurott,                                \
        .formSpeciesIdTable = sSamurottFormSpeciesIdTable

    [SPECIES_SAMUROTT] =
    {
        SAMUROTT_MISC_INFO,
        .baseHP        = 95,
        .baseAttack    = 100,
        .baseDefense   = 85,
        .baseSpeed     = 70,
        .baseSpAttack  = 108,
        .baseSpDefense = 70,
        .types = { TYPE_WATER, TYPE_WATER },
        .evYield_SpAttack = 3,
        .abilities = { ABILITY_TORRENT, ABILITY_NONE, ABILITY_SHELL_ARMOR },
        .weight = 946,
        .description = POKEDEX_DESC_STRING(
            "Ehe man sichs versieht, hat es\n"
            "schon das Langschwert aus seinen\n"
            "Vorderbeinen gezogen und seinen\n"
            "Gegner besiegt."),
        FRONT_PIC(Samurott, 64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_Samurott,
        .frontAnimId = ANIM_V_SHAKE,
        BACK_PIC(Samurott, 64, 56),
        .backPicYOffset = 8,
        .backAnimId = BACK_ANIM_SHAKE_GLOW_BLUE,
        PALETTES(Samurott),
        ICON(Samurott, 2),
        LEARNSETS(Samurott),
    },

#if P_HISUIAN_FORMS
    [SPECIES_SAMUROTT_HISUI] =
    {
        SAMUROTT_MISC_INFO,
        .baseHP        = 90,
        .baseAttack    = 108,
        .baseDefense   = 80,
        .baseSpeed     = 85,
        .baseSpAttack  = 100,
        .baseSpDefense = 65,
        .types = { TYPE_WATER, TYPE_DARK },
        .evYield_Attack = 3,
        .abilities = { ABILITY_TORRENT, ABILITY_NONE, ABILITY_SHARPNESS },
        .weight = 582,
        .description = POKEDEX_DESC_STRING(
            "Ehe man sichs versieht, hat es\n"
            "schon das Langschwert aus seinen\n"
            "Vorderbeinen gezogen und seinen\n"
            "Gegner besiegt."),
        FRONT_PIC(SamurottHisuian, 64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_SamurottHisuian,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(SamurottHisuian, 64, 64),
        .backPicYOffset = 8,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(SamurottHisuian),
        ICON(SamurottHisuian, 0),
        LEARNSETS(SamurottHisuian),
        .isHisuianForm = TRUE,
    },
#endif //P_HISUIAN_FORMS
#endif //P_FAMILY_OSHAWOTT

#if P_FAMILY_PATRAT
    [SPECIES_PATRAT] =
    {
        .baseHP        = 45,
        .baseAttack    = 55,
        .baseDefense   = 39,
        .baseSpeed     = 42,
        .baseSpAttack  = 35,
        .baseSpDefense = 39,
        .types = { TYPE_NORMAL, TYPE_NORMAL },
        .catchRate = 255,
        .expYield = 51,
        .evYield_Attack = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD },
        .abilities = { ABILITY_RUN_AWAY, ABILITY_KEEN_EYE, ABILITY_ANALYTIC },
        .bodyColor = BODY_COLOR_BROWN,
        .speciesName = _("Nagelotz"),
        .cryId = CRY_PATRAT,
        .natDexNum = NATIONAL_DEX_PATRAT,
        .categoryName = _("Späher"),
        .height = 5,
        .weight = 116,
        .description = POKEDEX_DESC_STRING(
            "Eines dieser vorsichtigen Pokémon steht\n"
            "immer vor ihrem Bau Wache. Nähert sich\n"
            "jedoch ein Feind von hinten, ist es aus."),
        .pokemonScale = 432,
        .pokemonOffset = 14,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Patrat, 48, 40),
        .frontPicYOffset = 12,
        .frontAnimFrames = sAnims_Patrat,
        .frontAnimId = ANIM_V_STRETCH,
        BACK_PIC(Patrat, 64, 40),
        .backPicYOffset = 12,
        .backAnimId = BACK_ANIM_H_SLIDE,
        PALETTES(Patrat),
        ICON(Patrat, 2),
        .footprint = gMonFootprint_Patrat,
        LEARNSETS(Patrat),
        .evolutions = EVOLUTION({EVO_LEVEL, 20, SPECIES_WATCHOG}),
    },

    [SPECIES_WATCHOG] =
    {
        .baseHP        = 60,
        .baseAttack    = 85,
        .baseDefense   = 69,
        .baseSpeed     = 77,
        .baseSpAttack  = 60,
        .baseSpDefense = 69,
        .types = { TYPE_NORMAL, TYPE_NORMAL },
        .catchRate = 255,
        .expYield = 147,
        .evYield_Attack = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD },
        .abilities = { ABILITY_ILLUMINATE, ABILITY_KEEN_EYE, ABILITY_ANALYTIC },
        .bodyColor = BODY_COLOR_BROWN,
        .speciesName = _("Kukmarda"),
        .cryId = CRY_WATCHOG,
        .natDexNum = NATIONAL_DEX_WATCHOG,
        .categoryName = _("Wachsamkeit"),
        .height = 11,
        .weight = 270,
        .description = POKEDEX_DESC_STRING(
            "Es kann mit einer körpereigenen\n"
            "Substanz seine Augen und seinen\n"
            "Torso aufleuchten lassen, um Gegner\n"
            "zu erschrecken."),
        .pokemonScale = 320,
        .pokemonOffset = 7,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Watchog, 32, 64),
        .frontPicYOffset = 2,
        .frontAnimFrames = sAnims_Watchog,
        .frontAnimId = ANIM_V_STRETCH,
        BACK_PIC(Watchog, 56, 64),
        .backPicYOffset = 2,
        .backAnimId = BACK_ANIM_JOLT_RIGHT,
        PALETTES(Watchog),
        ICON(Watchog, 2),
        .footprint = gMonFootprint_Watchog,
        LEARNSETS(Watchog),
    },
#endif //P_FAMILY_PATRAT

#if P_FAMILY_LILLIPUP
    [SPECIES_LILLIPUP] =
    {
        .baseHP        = 45,
        .baseAttack    = 60,
        .baseDefense   = 45,
        .baseSpeed     = 55,
        .baseSpAttack  = 25,
        .baseSpDefense = 45,
        .types = { TYPE_NORMAL, TYPE_NORMAL },
        .catchRate = 255,
        .expYield = 55,
        .evYield_Attack = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD },
        .abilities = { ABILITY_VITAL_SPIRIT, ABILITY_PICKUP, ABILITY_RUN_AWAY },
        .bodyColor = BODY_COLOR_BROWN,
        .speciesName = _("Yorkleff"),
        .cryId = CRY_LILLIPUP,
        .natDexNum = NATIONAL_DEX_LILLIPUP,
        .categoryName = _("Welpen"),
        .height = 4,
        .weight = 41,
        .description = POKEDEX_DESC_STRING(
            "Das Fell auf seinem Gesicht fungiert als\n"
            "Radar, mit dem es Gegner aufspürt."),
        .pokemonScale = 491,
        .pokemonOffset = 15,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Lillipup, 32, 40),
        .frontPicYOffset = 12,
        .frontAnimFrames = sAnims_Lillipup,
        .frontAnimId = ANIM_H_JUMPS,
        BACK_PIC(Lillipup, 48, 48),
        .backPicYOffset = 12,
        .backAnimId = BACK_ANIM_CONCAVE_ARC_SMALL,
        PALETTES(Lillipup),
        ICON(Lillipup, 2),
        .footprint = gMonFootprint_Lillipup,
        LEARNSETS(Lillipup),
        .evolutions = EVOLUTION({EVO_LEVEL, 16, SPECIES_HERDIER}),
    },

    [SPECIES_HERDIER] =
    {
        .baseHP        = 65,
        .baseAttack    = 80,
        .baseDefense   = 65,
        .baseSpeed     = 60,
        .baseSpAttack  = 35,
        .baseSpDefense = 65,
        .types = { TYPE_NORMAL, TYPE_NORMAL },
        .catchRate = 120,
        .expYield = 130,
        .evYield_Attack = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD },
        .abilities = { ABILITY_INTIMIDATE, ABILITY_SAND_RUSH, ABILITY_SCRAPPY },
        .bodyColor = BODY_COLOR_GRAY,
        .speciesName = _("Terribark"),
        .cryId = CRY_HERDIER,
        .natDexNum = NATIONAL_DEX_HERDIER,
        .categoryName = _("Treuhund"),
        .height = 9,
        .weight = 147,
        .description = POKEDEX_DESC_STRING(
            "Das dunkle Fell, das es wie ein Mantel\n"
            "umgibt, ist äußerst widerstandsfähig und\n"
            "mindert den Schaden durch Attacken."),
        .pokemonScale = 338,
        .pokemonOffset = 9,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Herdier, 48, 48),
        .frontPicYOffset = 8,
        .frontAnimFrames = sAnims_Herdier,
        .frontAnimId = ANIM_H_STRETCH,
        BACK_PIC(Herdier, 48, 56),
        .backPicYOffset = 10,
        .backAnimId = BACK_ANIM_H_SHAKE,
        PALETTES(Herdier),
        ICON(Herdier, 2),
        .footprint = gMonFootprint_Herdier,
        LEARNSETS(Herdier),
        .evolutions = EVOLUTION({EVO_LEVEL, 32, SPECIES_STOUTLAND}),
    },

    [SPECIES_STOUTLAND] =
    {
        .baseHP        = 85,
        .baseAttack    = P_UPDATED_STATS >= GEN_6 ? 110 : 100,
        .baseDefense   = 90,
        .baseSpeed     = 80,
        .baseSpAttack  = 45,
        .baseSpDefense = 90,
        .types = { TYPE_NORMAL, TYPE_NORMAL },
        .catchRate = 45,
        .expYield = 225,
        .evYield_Attack = 3,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD },
        .abilities = { ABILITY_INTIMIDATE, ABILITY_SAND_RUSH, ABILITY_SCRAPPY },
        .bodyColor = BODY_COLOR_GRAY,
        .speciesName = _("Bissbark"),
        .cryId = CRY_STOUTLAND,
        .natDexNum = NATIONAL_DEX_STOUTLAND,
        .categoryName = _("Großmut"),
        .height = 12,
        .weight = 610,
        .description = POKEDEX_DESC_STRING(
            "Da es klug ist und keine Gefahr besteht,\n"
            "dass es Menschen angreift, geben Eltern\n"
            "ihre Kinder in seine Obhut."),
        .pokemonScale = 282,
        .pokemonOffset = 4,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Stoutland, 64, 64),
        .frontPicYOffset = 1,
        .frontAnimFrames = sAnims_Stoutland,
        .frontAnimId = ANIM_H_SLIDE,
        BACK_PIC(Stoutland, 64, 64),
        .backPicYOffset = 2,
        .backAnimId = BACK_ANIM_V_STRETCH,
        PALETTES(Stoutland),
        ICON(Stoutland, 2),
        .footprint = gMonFootprint_Stoutland,
        LEARNSETS(Stoutland),
    },
#endif //P_FAMILY_LILLIPUP

#if P_FAMILY_PURRLOIN
    [SPECIES_PURRLOIN] =
    {
        .baseHP        = 41,
        .baseAttack    = 50,
        .baseDefense   = 37,
        .baseSpeed     = 66,
        .baseSpAttack  = 50,
        .baseSpDefense = 37,
        .types = { TYPE_DARK, TYPE_DARK },
        .catchRate = 255,
        .expYield = 56,
        .evYield_Speed = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD },
        .abilities = { ABILITY_LIMBER, ABILITY_UNBURDEN, ABILITY_PRANKSTER },
        .bodyColor = BODY_COLOR_PURPLE,
        .speciesName = _("Felilou"),
        .cryId = CRY_PURRLOIN,
        .natDexNum = NATIONAL_DEX_PURRLOIN,
        .categoryName = _("Schelm"),
        .height = 4,
        .weight = 101,
        .description = POKEDEX_DESC_STRING(
            "Es stibitzt den Leuten spaßeshalber ihr\n"
            "Hab und Gut, doch dank seiner reizenden\n"
            "Natur kann ihm niemand lang böse sein."),
        .pokemonScale = 491,
        .pokemonOffset = 15,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Purrloin, 48, 48),
        .frontPicYOffset = 11,
        .frontAnimFrames = sAnims_Purrloin,
        .frontAnimId = ANIM_GROW_VIBRATE,
        BACK_PIC(Purrloin, 56, 48),
        .backPicYOffset = 9,
        .backAnimId = BACK_ANIM_V_STRETCH,
        PALETTES(Purrloin),
        ICON(Purrloin, 0),
        .footprint = gMonFootprint_Purrloin,
        LEARNSETS(Purrloin),
        .evolutions = EVOLUTION({EVO_LEVEL, 20, SPECIES_LIEPARD}),
    },

    [SPECIES_LIEPARD] =
    {
        .baseHP        = 64,
        .baseAttack    = 88,
        .baseDefense   = 50,
        .baseSpeed     = 106,
        .baseSpAttack  = 88,
        .baseSpDefense = 50,
        .types = { TYPE_DARK, TYPE_DARK },
        .catchRate = 90,
        .expYield = 156,
        .evYield_Speed = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD },
        .abilities = { ABILITY_LIMBER, ABILITY_UNBURDEN, ABILITY_PRANKSTER },
        .bodyColor = BODY_COLOR_PURPLE,
        .speciesName = _("Kleoparda"),
        .cryId = CRY_LIEPARD,
        .natDexNum = NATIONAL_DEX_LIEPARD,
        .categoryName = _("Gefühlskälte"),
        .height = 11,
        .weight = 375,
        .description = POKEDEX_DESC_STRING(
            "Verbirgt seine Aura und nähert sich seinem\n"
            "Gegner völlig unbemerkt von hinten, um ihm\n"
            "den Garaus zu machen."),
        .pokemonScale = 320,
        .pokemonOffset = 7,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Liepard, 64, 64),
        .frontPicYOffset = 4,
        .frontAnimFrames = sAnims_Liepard,
        .frontAnimId = ANIM_GROW_VIBRATE,
        BACK_PIC(Liepard, 56, 48),
        .backPicYOffset = 9,
        .backAnimId = BACK_ANIM_H_STRETCH,
        PALETTES(Liepard),
        ICON(Liepard, 0),
        .footprint = gMonFootprint_Liepard,
        LEARNSETS(Liepard),
    },
#endif //P_FAMILY_PURRLOIN

#if P_FAMILY_PANSAGE
    [SPECIES_PANSAGE] =
    {
        .baseHP        = 50,
        .baseAttack    = 53,
        .baseDefense   = 48,
        .baseSpeed     = 64,
        .baseSpAttack  = 53,
        .baseSpDefense = 48,
        .types = { TYPE_GRASS, TYPE_GRASS },
        .catchRate = 190,
        .expYield = 63,
        .evYield_Speed = 1,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD },
        .abilities = { ABILITY_GLUTTONY, ABILITY_NONE, ABILITY_OVERGROW },
        .bodyColor = BODY_COLOR_GREEN,
        .speciesName = _("Vegimak"),
        .cryId = CRY_PANSAGE,
        .natDexNum = NATIONAL_DEX_PANSAGE,
        .categoryName = _("Grasaffe"),
        .height = 6,
        .weight = 105,
        .description = POKEDEX_DESC_STRING(
            "Schwächelnden Pokémon gibt es ein\n"
            "paar der Kräuter auf seinem Kopf ab\n"
            "und hilft ihnen so wieder auf die\n"
            "Beine."),
        .pokemonScale = 422,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Pansage, 40, 48),
        .frontPicYOffset = 11,
        .frontAnimFrames = sAnims_Pansage,
        .frontAnimId = ANIM_CIRCULAR_STRETCH_TWICE,
        BACK_PIC(Pansage, 48, 48),
        .backPicYOffset = 9,
        .backAnimId = BACK_ANIM_CONCAVE_ARC_LARGE,
        PALETTES(Pansage),
        ICON(Pansage, 1),
        .footprint = gMonFootprint_Pansage,
        LEARNSETS(Pansage),
        .evolutions = EVOLUTION({EVO_ITEM, ITEM_LEAF_STONE, SPECIES_SIMISAGE}),
    },

    [SPECIES_SIMISAGE] =
    {
        .baseHP        = 75,
        .baseAttack    = 98,
        .baseDefense   = 63,
        .baseSpeed     = 101,
        .baseSpAttack  = 98,
        .baseSpDefense = 63,
        .types = { TYPE_GRASS, TYPE_GRASS },
        .catchRate = 75,
        .expYield = 174,
        .evYield_Speed = 2,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD },
        .abilities = { ABILITY_GLUTTONY, ABILITY_NONE, ABILITY_OVERGROW },
        .bodyColor = BODY_COLOR_GREEN,
        .speciesName = _("Vegichita"),
        .cryId = CRY_SIMISAGE,
        .natDexNum = NATIONAL_DEX_SIMISAGE,
        .categoryName = _("Stachelaffe"),
        .height = 11,
        .weight = 305,
        .description = POKEDEX_DESC_STRING(
            "Wer sich mit diesem\n"
            "temperamentvollen Pokémon anlegt,\n"
            "bekommt seinen mit Dornen\n"
            "bestückten Schweif zu spüren."),
        .pokemonScale = 320,
        .pokemonOffset = 7,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Simisage, 64, 64),
        .frontPicYOffset = 1,
        .frontAnimFrames = sAnims_Simisage,
        .frontAnimId = ANIM_GROW_VIBRATE,
        BACK_PIC(Simisage, 56, 64),
        .backPicYOffset = 6,
        .backAnimId = BACK_ANIM_V_SHAKE_H_SLIDE,
        PALETTES(Simisage),
        ICON(Simisage, 1),
        .footprint = gMonFootprint_Simisage,
        LEARNSETS(Simisage),
    },
#endif //P_FAMILY_PANSAGE

#if P_FAMILY_PANSEAR
    [SPECIES_PANSEAR] =
    {
        .baseHP        = 50,
        .baseAttack    = 53,
        .baseDefense   = 48,
        .baseSpeed     = 64,
        .baseSpAttack  = 53,
        .baseSpDefense = 48,
        .types = { TYPE_FIRE, TYPE_FIRE },
        .catchRate = 190,
        .expYield = 63,
        .evYield_Speed = 1,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD },
        .abilities = { ABILITY_GLUTTONY, ABILITY_NONE, ABILITY_BLAZE },
        .bodyColor = BODY_COLOR_RED,
        .noFlip = TRUE,
        .speciesName = _("Grillmak"),
        .cryId = CRY_PANSEAR,
        .natDexNum = NATIONAL_DEX_PANSEAR,
        .categoryName = _("Hitze"),
        .height = 6,
        .weight = 110,
        .description = POKEDEX_DESC_STRING(
            "Ein kultiviertes Pokémon, das\n"
            "Beeren vor dem Verzehr stets\n"
            "anbrät. Es bietet den Menschen\n"
            "gerne seine Hilfe an."),
        .pokemonScale = 422,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Pansear, 48, 48),
        .frontPicYOffset = 11,
        .frontAnimFrames = sAnims_Pansear,
        .frontAnimId = ANIM_V_STRETCH,
        BACK_PIC(Pansear, 48, 56),
        .backPicYOffset = 10,
        .backAnimId = BACK_ANIM_CONCAVE_ARC_LARGE,
        PALETTES(Pansear),
        ICON(Pansear, 2),
        .footprint = gMonFootprint_Pansear,
        LEARNSETS(Pansear),
        .evolutions = EVOLUTION({EVO_ITEM, ITEM_FIRE_STONE, SPECIES_SIMISEAR}),
    },

    [SPECIES_SIMISEAR] =
    {
        .baseHP        = 75,
        .baseAttack    = 98,
        .baseDefense   = 63,
        .baseSpeed     = 101,
        .baseSpAttack  = 98,
        .baseSpDefense = 63,
        .types = { TYPE_FIRE, TYPE_FIRE },
        .catchRate = 75,
        .expYield = 174,
        .evYield_Speed = 2,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD },
        .abilities = { ABILITY_GLUTTONY, ABILITY_NONE, ABILITY_BLAZE },
        .bodyColor = BODY_COLOR_RED,
        .noFlip = TRUE,
        .speciesName = _("Grillchita"),
        .cryId = CRY_SIMISEAR,
        .natDexNum = NATIONAL_DEX_SIMISEAR,
        .categoryName = _("Funkenregen"),
        .height = 10,
        .weight = 280,
        .description = POKEDEX_DESC_STRING(
            "Freut es sich, erhitzt sich sein Körper\n"
            "und aus seinem Kopf und Schweif sprühen\n"
            "Funken. Es liebt Süßigkeiten."),
        .pokemonScale = 305,
        .pokemonOffset = 7,
        .trainerScale = 257,
        .trainerOffset = 0,
        FRONT_PIC(Simisear, 56, 56),
        .frontPicYOffset = 6,
        .frontAnimFrames = sAnims_Simisear,
        .frontAnimId = ANIM_SWING_CONCAVE_FAST,
        BACK_PIC(Simisear, 64, 56),
        .backPicYOffset = 8,
        .backAnimId = BACK_ANIM_V_SHAKE_H_SLIDE,
        PALETTES(Simisear),
        ICON(Simisear, 2),
        .footprint = gMonFootprint_Simisear,
        LEARNSETS(Simisear),
    },
#endif //P_FAMILY_PANSEAR

#if P_FAMILY_PANPOUR
    [SPECIES_PANPOUR] =
    {
        .baseHP        = 50,
        .baseAttack    = 53,
        .baseDefense   = 48,
        .baseSpeed     = 64,
        .baseSpAttack  = 53,
        .baseSpDefense = 48,
        .types = { TYPE_WATER, TYPE_WATER },
        .catchRate = 190,
        .expYield = 63,
        .evYield_Speed = 1,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD },
        .abilities = { ABILITY_GLUTTONY, ABILITY_NONE, ABILITY_TORRENT },
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Sodamak"),
        .cryId = CRY_PANPOUR,
        .natDexNum = NATIONAL_DEX_PANPOUR,
        .categoryName = _("Wasserstrahl"),
        .height = 6,
        .weight = 135,
        .description = POKEDEX_DESC_STRING(
            "Das Büschel auf seinem Kopf enthält\n"
            "eine sehr nahrhafte Flüssigkeit,\n"
            "mit der es über seinen Schweif\n"
            "Pflanzen wässert."),
        .pokemonScale = 422,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Panpour, 48, 48),
        .frontPicYOffset = 10,
        .frontAnimFrames = sAnims_Panpour,
        .frontAnimId = ANIM_GROW_VIBRATE,
        BACK_PIC(Panpour, 48, 48),
        .backPicYOffset = 9,
        .backAnimId = BACK_ANIM_CONCAVE_ARC_LARGE,
        PALETTES(Panpour),
        ICON(Panpour, 2),
        .footprint = gMonFootprint_Panpour,
        LEARNSETS(Panpour),
        .evolutions = EVOLUTION({EVO_ITEM, ITEM_WATER_STONE, SPECIES_SIMIPOUR}),
    },

    [SPECIES_SIMIPOUR] =
    {
        .baseHP        = 75,
        .baseAttack    = 98,
        .baseDefense   = 63,
        .baseSpeed     = 101,
        .baseSpAttack  = 98,
        .baseSpDefense = 63,
        .types = { TYPE_WATER, TYPE_WATER },
        .catchRate = 75,
        .expYield = 174,
        .evYield_Speed = 2,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD },
        .abilities = { ABILITY_GLUTTONY, ABILITY_NONE, ABILITY_TORRENT },
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Sodachita"),
        .cryId = CRY_SIMIPOUR,
        .natDexNum = NATIONAL_DEX_SIMIPOUR,
        .categoryName = _("Drainage"),
        .height = 10,
        .weight = 290,
        .description = POKEDEX_DESC_STRING(
            "Hält sich bevorzugt in reinen Gewässern\n"
            "auf. Geht ihm das Wasser in seinem Kopf\n"
            "aus, tankt es mit seinem Schweif nach."),
        .pokemonScale = 305,
        .pokemonOffset = 7,
        .trainerScale = 257,
        .trainerOffset = 0,
        FRONT_PIC(Simipour, 56, 56),
        .frontPicYOffset = 6,
        .frontAnimFrames = sAnims_Simipour,
        .frontAnimId = ANIM_H_STRETCH,
        BACK_PIC(Simipour, 64, 56),
        .backPicYOffset = 5,
        .backAnimId = BACK_ANIM_V_SHAKE_H_SLIDE,
        PALETTES(Simipour),
        ICON(Simipour, 2),
        .footprint = gMonFootprint_Simipour,
        LEARNSETS(Simipour),
    },
#endif //P_FAMILY_PANPOUR

#if P_FAMILY_MUNNA
    [SPECIES_MUNNA] =
    {
        .baseHP        = 76,
        .baseAttack    = 25,
        .baseDefense   = 45,
        .baseSpeed     = 24,
        .baseSpAttack  = 67,
        .baseSpDefense = 55,
        .types = { TYPE_PSYCHIC, TYPE_PSYCHIC },
        .catchRate = 190,
        .expYield = 58,
        .evYield_HP = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 10,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_FAST,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD },
        .abilities = { ABILITY_FOREWARN, ABILITY_SYNCHRONIZE, ABILITY_TELEPATHY },
        .bodyColor = BODY_COLOR_PINK,
        .speciesName = _("Somniam"),
        .cryId = CRY_MUNNA,
        .natDexNum = NATIONAL_DEX_MUNNA,
        .categoryName = _("Traumfresser"),
        .height = 6,
        .weight = 233,
        .description = POKEDEX_DESC_STRING(
            "Es erscheint vor schlafenden\n"
            "Menschen und Pokémon und frisst\n"
            "ihre Alpträume."),
        .pokemonScale = 422,
        .pokemonOffset = 15,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Munna, 32, 32),
        .frontPicYOffset = 16,
        .frontAnimFrames = sAnims_Munna,
        .frontAnimId = ANIM_RISING_WOBBLE,
        .enemyMonElevation = 7,
        BACK_PIC(Munna, 48, 32),
        .backPicYOffset = 16,
        .backAnimId = BACK_ANIM_SHRINK_GROW,
        PALETTES(Munna),
        ICON(Munna, 0),
        .footprint = gMonFootprint_Munna,
        LEARNSETS(Munna),
        .evolutions = EVOLUTION({EVO_ITEM, ITEM_MOON_STONE, SPECIES_MUSHARNA}),
    },

    [SPECIES_MUSHARNA] =
    {
        .baseHP        = 116,
        .baseAttack    = 55,
        .baseDefense   = 85,
        .baseSpeed     = 29,
        .baseSpAttack  = 107,
        .baseSpDefense = 95,
        .types = { TYPE_PSYCHIC, TYPE_PSYCHIC },
        .catchRate = 75,
        .expYield = 170,
        .evYield_HP = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 10,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_FAST,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD },
        .abilities = { ABILITY_FOREWARN, ABILITY_SYNCHRONIZE, ABILITY_TELEPATHY },
        .bodyColor = BODY_COLOR_PINK,
        .speciesName = _("Somnivora"),
        .cryId = CRY_MUSHARNA,
        .natDexNum = NATIONAL_DEX_MUSHARNA,
        .categoryName = _("Halbschlaf"),
        .height = 11,
        .weight = 605,
        .description = POKEDEX_DESC_STRING(
            "Wenn es schwärzlichen Dunst ausströmt,\n"
            "sollte man sich ihm nicht nähern, denn\n"
            "sonst werden Alpträume wahr."),
        .pokemonScale = 320,
        .pokemonOffset = 7,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Musharna, 64, 64),
        .frontPicYOffset = 6,
        .frontAnimFrames = sAnims_Musharna,
        .frontAnimId = ANIM_ROTATE_TO_SIDES_TWICE,
        .enemyMonElevation = 5,
        BACK_PIC(Musharna, 64, 64),
        .backPicYOffset = 8,
        .backAnimId = BACK_ANIM_GROW,
        PALETTES(Musharna),
        ICON(Musharna, 0),
        .footprint = gMonFootprint_Musharna,
        LEARNSETS(Musharna),
    },
#endif //P_FAMILY_MUNNA

#if P_FAMILY_PIDOVE
    [SPECIES_PIDOVE] =
    {
        .baseHP        = 50,
        .baseAttack    = 55,
        .baseDefense   = 50,
        .baseSpeed     = 43,
        .baseSpAttack  = 36,
        .baseSpDefense = 30,
        .types = { TYPE_NORMAL, TYPE_FLYING },
        .catchRate = 255,
        .expYield = 53,
        .evYield_Attack = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_FLYING, EGG_GROUP_FLYING },
        .abilities = { ABILITY_BIG_PECKS, ABILITY_SUPER_LUCK, ABILITY_RIVALRY },
        .bodyColor = BODY_COLOR_GRAY,
        .speciesName = _("Dusselgurr"),
        .cryId = CRY_PIDOVE,
        .natDexNum = NATIONAL_DEX_PIDOVE,
        .categoryName = _("Täubchen"),
        .height = 3,
        .weight = 21,
        .description = POKEDEX_DESC_STRING(
            "Wartet oft vergeblich auf\n"
            "Anweisungen, obwohl es bereits\n"
            "einen Befehl erhalten hat. Ein sehr\n"
            "zerstreutes Pokémon."),
        .pokemonScale = 530,
        .pokemonOffset = 13,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Pidove, 40, 40),
        .frontPicYOffset = 12,
        .frontAnimFrames = sAnims_Pidove,
        .frontAnimId = ANIM_V_JUMPS_SMALL,
        BACK_PIC(Pidove, 48, 40),
        .backPicYOffset = 13,
        .backAnimId = BACK_ANIM_CONCAVE_ARC_SMALL,
        PALETTES(Pidove),
        ICON(Pidove, 0),
        .footprint = gMonFootprint_Pidove,
        LEARNSETS(Pidove),
        .evolutions = EVOLUTION({EVO_LEVEL, 21, SPECIES_TRANQUILL}),
    },

    [SPECIES_TRANQUILL] =
    {
        .baseHP        = 62,
        .baseAttack    = 77,
        .baseDefense   = 62,
        .baseSpeed     = 65,
        .baseSpAttack  = 50,
        .baseSpDefense = 42,
        .types = { TYPE_NORMAL, TYPE_FLYING },
        .catchRate = 120,
        .expYield = 125,
        .evYield_Attack = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_FLYING, EGG_GROUP_FLYING },
        .abilities = { ABILITY_BIG_PECKS, ABILITY_SUPER_LUCK, ABILITY_RIVALRY },
        .bodyColor = BODY_COLOR_GRAY,
        .speciesName = _("Navitaub"),
        .cryId = CRY_TRANQUILL,
        .natDexNum = NATIONAL_DEX_TRANQUILL,
        .categoryName = _("Wildtauben"),
        .height = 6,
        .weight = 150,
        .description = POKEDEX_DESC_STRING(
            "Findet selbst von der anderen Seite des\n"
            "Globus zu seinem Nest zurück. Nichts kann\n"
            "es von seinem Trainer trennen."),
        .pokemonScale = 422,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Tranquill, 40, 56),
        .frontPicYOffset = 7,
        .frontAnimFrames = sAnims_Tranquill,
        .frontAnimId = ANIM_V_STRETCH,
        BACK_PIC(Tranquill, 56, 48),
        .backPicYOffset = 9,
        .backAnimId = BACK_ANIM_JOLT_RIGHT,
        PALETTES(Tranquill),
        ICON(Tranquill, 0),
        .footprint = gMonFootprint_Tranquill,
        LEARNSETS(Tranquill),
        .evolutions = EVOLUTION({EVO_LEVEL, 32, SPECIES_UNFEZANT}),
    },

    [SPECIES_UNFEZANT] =
    {
        .baseHP        = 80,
        .baseAttack    = P_UPDATED_STATS >= GEN_6 ? 115 : 105,
        .baseDefense   = 80,
        .baseSpeed     = 93,
        .baseSpAttack  = 65,
        .baseSpDefense = 55,
        .types = { TYPE_NORMAL, TYPE_FLYING },
        .catchRate = 45,
        .expYield = 220,
        .evYield_Attack = 3,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_FLYING, EGG_GROUP_FLYING },
        .abilities = { ABILITY_BIG_PECKS, ABILITY_SUPER_LUCK, ABILITY_RIVALRY },
        .bodyColor = BODY_COLOR_GRAY,
        .speciesName = _("Fasasnob"),
        .cryId = CRY_UNFEZANT,
        .natDexNum = NATIONAL_DEX_UNFEZANT,
        .categoryName = _("Stolz"),
        .height = 12,
        .weight = 290,
        .description = POKEDEX_DESC_STRING(
            "Männchen schrecken Gegner ab, indem\n"
            "sie ihren Kopfschmuck schütteln.\n"
            "Weibchen verfügen über bessere\n"
            "Flugfertigkeiten."),
        .pokemonScale = 282,
        .pokemonOffset = 4,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Unfezant, 56, 64),
        FRONT_PIC_FEMALE(Unfezant, 56, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_Unfezant,
        .frontAnimId = ANIM_SHRINK_GROW,
        BACK_PIC(Unfezant, 64, 64),
        BACK_PIC_FEMALE(Unfezant, 64, 64),
        .backPicYOffset = 1,
        .backAnimId = BACK_ANIM_V_STRETCH,
        PALETTES(Unfezant),
        PALETTE_FEMALE(Unfezant),
        ICON(Unfezant, 1),
        ICON_FEMALE(Unfezant, 1),
        .footprint = gMonFootprint_Unfezant,
        LEARNSETS(Unfezant),
    },
#endif //P_FAMILY_PIDOVE

#if P_FAMILY_BLITZLE
    [SPECIES_BLITZLE] =
    {
        .baseHP        = 45,
        .baseAttack    = 60,
        .baseDefense   = 32,
        .baseSpeed     = 76,
        .baseSpAttack  = 50,
        .baseSpDefense = 32,
        .types = { TYPE_ELECTRIC, TYPE_ELECTRIC },
        .catchRate = 190,
        .expYield = 59,
        .evYield_Speed = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD },
        .abilities = { ABILITY_LIGHTNING_ROD, ABILITY_MOTOR_DRIVE, ABILITY_SAP_SIPPER },
        .bodyColor = BODY_COLOR_BLACK,
        .speciesName = _("Elezeba"),
        .cryId = CRY_BLITZLE,
        .natDexNum = NATIONAL_DEX_BLITZLE,
        .categoryName = _("Hochspannung"),
        .height = 8,
        .weight = 298,
        .description = POKEDEX_DESC_STRING(
            "Es erscheint, wenn Gewitterwolken\n"
            "den Himmel verdunkeln. Es fängt mit\n"
            "seiner Mähne Blitze und hortet ihre\n"
            "Energie."),
        .pokemonScale = 366,
        .pokemonOffset = 8,
        .trainerScale = 257,
        .trainerOffset = 0,
        FRONT_PIC(Blitzle, 40, 56),
        .frontPicYOffset = 5,
        .frontAnimFrames = sAnims_Blitzle,
        .frontAnimId = ANIM_V_STRETCH,
        BACK_PIC(Blitzle, 56, 56),
        .backPicYOffset = 7,
        .backAnimId = BACK_ANIM_DIP_RIGHT_SIDE,
        PALETTES(Blitzle),
        ICON(Blitzle, 2),
        .footprint = gMonFootprint_Blitzle,
        LEARNSETS(Blitzle),
        .evolutions = EVOLUTION({EVO_LEVEL, 27, SPECIES_ZEBSTRIKA}),
    },

    [SPECIES_ZEBSTRIKA] =
    {
        .baseHP        = 75,
        .baseAttack    = 100,
        .baseDefense   = 63,
        .baseSpeed     = 116,
        .baseSpAttack  = 80,
        .baseSpDefense = 63,
        .types = { TYPE_ELECTRIC, TYPE_ELECTRIC },
        .catchRate = 75,
        .expYield = 174,
        .evYield_Speed = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD },
        .abilities = { ABILITY_LIGHTNING_ROD, ABILITY_MOTOR_DRIVE, ABILITY_SAP_SIPPER },
        .bodyColor = BODY_COLOR_BLACK,
        .speciesName = _("Zebritz"),
        .cryId = CRY_ZEBSTRIKA,
        .natDexNum = NATIONAL_DEX_ZEBSTRIKA,
        .categoryName = _("Donnerkeil"),
        .height = 16,
        .weight = 795,
        .description = POKEDEX_DESC_STRING(
            "Ein stürmischer Geselle. Wenn es\n"
            "wütend ist, feuert es über seine\n"
            "Mähne in alle Richtungen\n"
            "Stromsalven ab."),
        .pokemonScale = 259,
        .pokemonOffset = 1,
        .trainerScale = 296,
        .trainerOffset = 1,
        FRONT_PIC(Zebstrika, 64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_Zebstrika,
        .frontAnimId = ANIM_BACK_AND_LUNGE,
        BACK_PIC(Zebstrika, 64, 64),
        .backPicYOffset = 7,
        .backAnimId = BACK_ANIM_SHAKE_FLASH_YELLOW,
        PALETTES(Zebstrika),
        ICON(Zebstrika, 2),
        .footprint = gMonFootprint_Zebstrika,
        LEARNSETS(Zebstrika),
    },
#endif //P_FAMILY_BLITZLE

#if P_FAMILY_ROGGENROLA
    [SPECIES_ROGGENROLA] =
    {
        .baseHP        = 55,
        .baseAttack    = 75,
        .baseDefense   = 85,
        .baseSpeed     = 15,
        .baseSpAttack  = 25,
        .baseSpDefense = 25,
        .types = { TYPE_ROCK, TYPE_ROCK },
        .catchRate = 255,
        .expYield = 56,
        .evYield_Defense = 1,
        .itemCommon = ITEM_EVERSTONE,
        .itemRare = ITEM_HARD_STONE,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_MINERAL, EGG_GROUP_MINERAL },
        .abilities = { ABILITY_STURDY, ABILITY_WEAK_ARMOR, ABILITY_SAND_FORCE },
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Kiesling"),
        .cryId = CRY_ROGGENROLA,
        .natDexNum = NATIONAL_DEX_ROGGENROLA,
        .categoryName = _("Erdmantel"),
        .height = 4,
        .weight = 180,
        .description = POKEDEX_DESC_STRING(
            "Wurde vor 100 Jahren nach einem großen\n"
            "Erdbeben in einer Erdspalte entdeckt. Es\n"
            "trägt eine Energiesphäre in sich."),
        .pokemonScale = 491,
        .pokemonOffset = 16,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Roggenrola, 24, 40),
        .frontPicYOffset = 14,
        .frontAnimFrames = sAnims_Roggenrola,
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(Roggenrola, 40, 48),
        .backPicYOffset = 13,
        .backAnimId = BACK_ANIM_V_SHAKE,
        PALETTES(Roggenrola),
        ICON(Roggenrola, 2),
        .footprint = gMonFootprint_Roggenrola,
        LEARNSETS(Roggenrola),
        .evolutions = EVOLUTION({EVO_LEVEL, 25, SPECIES_BOLDORE}),
    },

    [SPECIES_BOLDORE] =
    {
        .baseHP        = 70,
        .baseAttack    = 105,
        .baseDefense   = 105,
        .baseSpeed     = 20,
        .baseSpAttack  = 50,
        .baseSpDefense = 40,
        .types = { TYPE_ROCK, TYPE_ROCK },
        .catchRate = 120,
        .expYield = 137,
        .evYield_Attack = 1,
        .evYield_Defense = 1,
        .itemCommon = ITEM_EVERSTONE,
        .itemRare = ITEM_HARD_STONE,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_MINERAL, EGG_GROUP_MINERAL },
        .abilities = { ABILITY_STURDY, ABILITY_WEAK_ARMOR, ABILITY_SAND_FORCE },
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Sedimantur"),
        .cryId = CRY_BOLDORE,
        .natDexNum = NATIONAL_DEX_BOLDORE,
        .categoryName = _("Erz"),
        .height = 9,
        .weight = 1020,
        .description = POKEDEX_DESC_STRING(
            "Wenn die orangen Kristalle anfangen zu\n"
            "leuchten, ist Vorsicht vor spontanen\n"
            "Energieentladungen geboten."),
        .pokemonScale = 338,
        .pokemonOffset = 8,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Boldore, 56, 48),
        .frontPicYOffset = 10,
        .frontAnimFrames = sAnims_Boldore,
        .frontAnimId = ANIM_H_SLIDE_SLOW,
        BACK_PIC(Boldore, 64, 40),
        .backPicYOffset = 16,
        .backAnimId = BACK_ANIM_H_SHAKE,
        PALETTES(Boldore),
        ICON(Boldore, 0),
        .footprint = gMonFootprint_Boldore,
        LEARNSETS(Boldore),
        .evolutions = EVOLUTION({EVO_TRADE, 0, SPECIES_GIGALITH},
                                {EVO_ITEM, ITEM_LINKING_CORD, SPECIES_GIGALITH}),
    },

    [SPECIES_GIGALITH] =
    {
        .baseHP        = 85,
        .baseAttack    = 135,
        .baseDefense   = 130,
        .baseSpeed     = 25,
        .baseSpAttack  = 60,
        .baseSpDefense = P_UPDATED_STATS >= GEN_6 ? 80 : 70,
        .types = { TYPE_ROCK, TYPE_ROCK },
        .catchRate = 45,
        .expYield = 232,
        .evYield_Attack = 3,
        .itemCommon = ITEM_EVERSTONE,
        .itemRare = ITEM_HARD_STONE,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_MINERAL, EGG_GROUP_MINERAL },
        .abilities = { ABILITY_STURDY, ABILITY_SAND_STREAM, ABILITY_SAND_FORCE },
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Brockoloss"),
        .cryId = CRY_GIGALITH,
        .natDexNum = NATIONAL_DEX_GIGALITH,
        .categoryName = _("Kompressions"),
        .height = 17,
        .weight = 2600,
        .description = POKEDEX_DESC_STRING(
            "Es kann ganze Berge einebnen, indem es\n"
            "Energie entlädt, die es in seinem Kern\n"
            "gesammelt und verdichtet hat."),
        .pokemonScale = 259,
        .pokemonOffset = 0,
        .trainerScale = 290,
        .trainerOffset = 1,
        FRONT_PIC(Gigalith, 64, 64),
        .frontPicYOffset = 1,
        .frontAnimFrames = sAnims_Gigalith,
        .frontAnimId = ANIM_ROTATE_UP_SLAM_DOWN,
        BACK_PIC(Gigalith, 56, 64),
        .backPicYOffset = 2,
        .backAnimId = BACK_ANIM_V_SHAKE_LOW,
        PALETTES(Gigalith),
        ICON(Gigalith, 0),
        .footprint = gMonFootprint_Gigalith,
        LEARNSETS(Gigalith),
    },
#endif //P_FAMILY_ROGGENROLA

#if P_FAMILY_WOOBAT
    [SPECIES_WOOBAT] =
    {
        .baseHP        = P_UPDATED_STATS >= GEN_7 ? 65 : 55,
        .baseAttack    = 45,
        .baseDefense   = 43,
        .baseSpeed     = 72,
        .baseSpAttack  = 55,
        .baseSpDefense = 43,
        .types = { TYPE_PSYCHIC, TYPE_FLYING },
        .catchRate = 190,
        .expYield = 65,
        .evYield_Speed = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FLYING },
        .abilities = { ABILITY_UNAWARE, ABILITY_KLUTZ, ABILITY_SIMPLE },
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Fleknoil"),
        .cryId = CRY_WOOBAT,
        .natDexNum = NATIONAL_DEX_WOOBAT,
        .categoryName = _("Fledermaus"),
        .height = 4,
        .weight = 21,
        .description = POKEDEX_DESC_STRING(
            "Herzförmige Flecken an der Decke einer\n"
            "Höhle sind ein sicheres Zeichen dafür,\n"
            "dass sie von Fleknoil behaust wird."),
        .pokemonScale = 491,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Woobat, 64, 32),
        .frontPicYOffset = 16,
        .frontAnimFrames = sAnims_Woobat,
        .frontAnimId = ANIM_FOUR_PETAL,
        .enemyMonElevation = 19,
        BACK_PIC(Woobat, 64, 32),
        .backPicYOffset = 16,
        .backAnimId = BACK_ANIM_TRIANGLE_DOWN,
        PALETTES(Woobat),
        ICON(Woobat, 0),
        .footprint = gMonFootprint_Woobat,
        LEARNSETS(Woobat),
        .evolutions = EVOLUTION({EVO_FRIENDSHIP, 0, SPECIES_SWOOBAT}),
    },

    [SPECIES_SWOOBAT] =
    {
        .baseHP        = 67,
        .baseAttack    = 57,
        .baseDefense   = 55,
        .baseSpeed     = 114,
        .baseSpAttack  = 77,
        .baseSpDefense = 55,
        .types = { TYPE_PSYCHIC, TYPE_FLYING },
        .catchRate = 45,
        .expYield = 149,
        .evYield_Speed = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FLYING },
        .abilities = { ABILITY_UNAWARE, ABILITY_KLUTZ, ABILITY_SIMPLE },
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Fletiamo"),
        .cryId = CRY_SWOOBAT,
        .natDexNum = NATIONAL_DEX_SWOOBAT,
        .categoryName = _("Balz"),
        .height = 9,
        .weight = 105,
        .description = POKEDEX_DESC_STRING(
            "Es wird in manchen Regionen für seine\n"
            "Nasenform verehrt, die angeblich Glück\n"
            "bringen soll."),
        .pokemonScale = 338,
        .pokemonOffset = 8,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Swoobat, 64, 64),
        .frontPicYOffset = 4,
        .frontAnimFrames = sAnims_Swoobat,
        .frontAnimId = ANIM_BOUNCE_ROTATE_TO_SIDES_SMALL,
        .enemyMonElevation = 10,
        BACK_PIC(Swoobat, 64, 64),
        .backPicYOffset = 7,
        .backAnimId = BACK_ANIM_V_STRETCH,
        PALETTES(Swoobat),
        ICON(Swoobat, 0),
        .footprint = gMonFootprint_Swoobat,
        LEARNSETS(Swoobat),
    },
#endif //P_FAMILY_WOOBAT

#if P_FAMILY_DRILBUR
    [SPECIES_DRILBUR] =
    {
        .baseHP        = 60,
        .baseAttack    = 85,
        .baseDefense   = 40,
        .baseSpeed     = 68,
        .baseSpAttack  = 30,
        .baseSpDefense = 45,
        .types = { TYPE_GROUND, TYPE_GROUND },
        .catchRate = 120,
        .expYield = 66,
        .evYield_Attack = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD },
        .abilities = { ABILITY_SAND_RUSH, ABILITY_SAND_FORCE, ABILITY_MOLD_BREAKER },
        .bodyColor = BODY_COLOR_GRAY,
        .noFlip = TRUE,
        .speciesName = _("Rotomurf"),
        .cryId = CRY_DRILBUR,
        .natDexNum = NATIONAL_DEX_DRILBUR,
        .categoryName = _("Maulwurf"),
        .height = 3,
        .weight = 85,
        .description = POKEDEX_DESC_STRING(
            "Es gräbt sich mit 50 km/h schnurstracks\n"
            "durch das Erdreich, indem es sich rapide\n"
            "um die eigene Achse dreht."),
        .pokemonScale = 530,
        .pokemonOffset = 13,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Drilbur, 48, 48),
        .frontPicYOffset = 10,
        .frontAnimFrames = sAnims_Drilbur,
        .frontAnimId = ANIM_SWING_CONCAVE_FAST_SHORT,
        BACK_PIC(Drilbur, 64, 40),
        .backPicYOffset = 13,
        .backAnimId = BACK_ANIM_V_SHAKE,
        PALETTES(Drilbur),
        ICON(Drilbur, 0),
        .footprint = gMonFootprint_Drilbur,
        LEARNSETS(Drilbur),
        .evolutions = EVOLUTION({EVO_LEVEL, 31, SPECIES_EXCADRILL}),
    },

    [SPECIES_EXCADRILL] =
    {
        .baseHP        = 110,
        .baseAttack    = 135,
        .baseDefense   = 60,
        .baseSpeed     = 88,
        .baseSpAttack  = 50,
        .baseSpDefense = 65,
        .types = { TYPE_GROUND, TYPE_STEEL },
        .catchRate = 60,
        .expYield = 178,
        .evYield_Attack = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD },
        .abilities = { ABILITY_SAND_RUSH, ABILITY_SAND_FORCE, ABILITY_MOLD_BREAKER },
        .bodyColor = BODY_COLOR_GRAY,
        .noFlip = TRUE,
        .speciesName = _("Stalobor"),
        .cryId = CRY_EXCADRILL,
        .natDexNum = NATIONAL_DEX_EXCADRILL,
        .categoryName = _("Untergrund"),
        .height = 7,
        .weight = 404,
        .description = POKEDEX_DESC_STRING(
            "Seine zu Stahl weiterentwickelten\n"
            "Bohrer kriegen selbst Eisenplatten\n"
            "klein. Im Tunnelbau ist es ein\n"
            "absolutes Ass."),
        .pokemonScale = 365,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Excadrill, 64, 64),
        .frontPicYOffset = 5,
        .frontAnimFrames = sAnims_Excadrill,
        .frontAnimId = ANIM_H_SHAKE,
        BACK_PIC(Excadrill, 64, 64),
        .backPicYOffset = 11,
        .backAnimId = BACK_ANIM_V_SHAKE_LOW,
        PALETTES(Excadrill),
        ICON(Excadrill, 0),
        .footprint = gMonFootprint_Excadrill,
        LEARNSETS(Excadrill),
    },
#endif //P_FAMILY_DRILBUR

#define AUDINO_MISC_INFO                                    \
        .catchRate = 255,                                   \
        .evYield_HP = 2,                                    \
        .itemCommon = ITEM_ORAN_BERRY,                      \
        .itemRare = ITEM_SITRUS_BERRY,                      \
        .genderRatio = PERCENT_FEMALE(50),                  \
        .eggCycles = 20,                                    \
        .friendship = STANDARD_FRIENDSHIP,                  \
        .growthRate = GROWTH_FAST,                          \
        .eggGroups = { EGG_GROUP_FAIRY, EGG_GROUP_FAIRY },  \
        .speciesName = _("Stalobor"),                         \
        .natDexNum = NATIONAL_DEX_AUDINO,                   \
        .categoryName = _("Untergrund"),                       \
        .footprint = gMonFootprint_Audino,                  \
        LEARNSETS(Audino),                                  \
        .formSpeciesIdTable = sAudinoFormSpeciesIdTable,    \
        .formChangeTable = sAudinoFormChangeTable

#if P_FAMILY_AUDINO
    [SPECIES_AUDINO] =
    {
        AUDINO_MISC_INFO,
        .baseHP        = 103,
        .baseAttack    = 60,
        .baseDefense   = 86,
        .baseSpeed     = 50,
        .baseSpAttack  = 60,
        .baseSpDefense = 86,
        .types = { TYPE_NORMAL, TYPE_NORMAL },
        .expYield = 390,
        .abilities = { ABILITY_HEALER, ABILITY_REGENERATOR, ABILITY_KLUTZ },
        .bodyColor = BODY_COLOR_PINK,
        .cryId = CRY_AUDINO,
        .height = 11,
        .weight = 310,
        .description = POKEDEX_DESC_STRING(
            "Über die Fühler an seinen Ohren\n"
            "kann es ertasten, wie es einer\n"
            "Person geht oder wann ein Pokémon\n"
            "aus seinem Ei schlüpft."),
        .pokemonScale = 320,
        .pokemonOffset = 7,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Audino, 40, 48),
        .frontPicYOffset = 8,
        .frontAnimFrames = sAnims_Audino,
        .frontAnimId = ANIM_V_STRETCH,
        BACK_PIC(Audino, 56, 56),
        .backPicYOffset = 9,
        .backAnimId = BACK_ANIM_SHRINK_GROW,
        PALETTES(Audino),
        ICON(Audino, 1),
    },

#if P_MEGA_EVOLUTIONS
    [SPECIES_AUDINO_MEGA] =
    {
        AUDINO_MISC_INFO,
        .baseHP        = 103,
        .baseAttack    = 60,
        .baseDefense   = 126,
        .baseSpeed     = 50,
        .baseSpAttack  = 80,
        .baseSpDefense = 126,
        .types = { TYPE_NORMAL, TYPE_FAIRY },
        .expYield = 425,
        .abilities = { ABILITY_HEALER, ABILITY_HEALER, ABILITY_HEALER },
        .bodyColor = BODY_COLOR_WHITE,
        .cryId = CRY_AUDINO_MEGA,
        .height = 15,
        .weight = 320,
        .description = POKEDEX_DESC_STRING(
            "Über die Fühler an seinen Ohren\n"
            "kann es ertasten, wie es einer\n"
            "Person geht oder wann ein Pokémon\n"
            "aus seinem Ei schlüpft."),
        .pokemonScale = 320,
        .pokemonOffset = 7,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(AudinoMega, 48, 64),
        .frontPicYOffset = 6,
        .frontAnimFrames = sAnims_AudinoMega,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(AudinoMega, 56, 64),
        .backPicYOffset = 0,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(AudinoMega),
        ICON(AudinoMega, 1),
        .isMegaEvolution = TRUE,
    },
#endif //P_MEGA_EVOLUTIONS
#endif //P_FAMILY_AUDINO

#if P_FAMILY_TIMBURR
    [SPECIES_TIMBURR] =
    {
        .baseHP        = 75,
        .baseAttack    = 80,
        .baseDefense   = 55,
        .baseSpeed     = 35,
        .baseSpAttack  = 25,
        .baseSpDefense = 35,
        .types = { TYPE_FIGHTING, TYPE_FIGHTING },
        .catchRate = 180,
        .expYield = 61,
        .evYield_Attack = 1,
        .genderRatio = PERCENT_FEMALE(25),
        .eggCycles = 20,
        .friendship = 70,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_HUMAN_LIKE, EGG_GROUP_HUMAN_LIKE },
        .abilities = { ABILITY_GUTS, ABILITY_SHEER_FORCE, ABILITY_IRON_FIST },
        .bodyColor = BODY_COLOR_GRAY,
        .speciesName = _("Praktibalk"),
        .cryId = CRY_TIMBURR,
        .natDexNum = NATIONAL_DEX_TIMBURR,
        .categoryName = _("Muskel"),
        .height = 6,
        .weight = 125,
        .description = POKEDEX_DESC_STRING(
            "Trägt stets einen Holzbalken bei\n"
            "sich. Es taucht hier und da auf\n"
            "Baustellen auf und hilft dort den\n"
            "Arbeitern aus."),
        .pokemonScale = 422,
        .pokemonOffset = 14,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Timburr, 48, 40),
        .frontPicYOffset = 12,
        .frontAnimFrames = sAnims_Timburr,
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(Timburr, 64, 40),
        .backPicYOffset = 15,
        .backAnimId = BACK_ANIM_CONCAVE_ARC_SMALL,
        PALETTES(Timburr),
        ICON(Timburr, 1),
        .footprint = gMonFootprint_Timburr,
        LEARNSETS(Timburr),
        .evolutions = EVOLUTION({EVO_LEVEL, 25, SPECIES_GURDURR}),
    },

    [SPECIES_GURDURR] =
    {
        .baseHP        = 85,
        .baseAttack    = 105,
        .baseDefense   = 85,
        .baseSpeed     = 40,
        .baseSpAttack  = 40,
        .baseSpDefense = 50,
        .types = { TYPE_FIGHTING, TYPE_FIGHTING },
        .catchRate = 90,
        .expYield = 142,
        .evYield_Attack = 2,
        .genderRatio = PERCENT_FEMALE(25),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_HUMAN_LIKE, EGG_GROUP_HUMAN_LIKE },
        .abilities = { ABILITY_GUTS, ABILITY_SHEER_FORCE, ABILITY_IRON_FIST },
        .bodyColor = BODY_COLOR_GRAY,
        .speciesName = _("Strepoli"),
        .cryId = CRY_GURDURR,
        .natDexNum = NATIONAL_DEX_GURDURR,
        .categoryName = _("Muskel"),
        .height = 12,
        .weight = 400,
        .description = POKEDEX_DESC_STRING(
            "Diese durchtrainierten Muskelprotze\n"
            "sind im Umgang mit Stahlträgern\n"
            "versiert und können damit ganze\n"
            "Häuser abreißen."),
        .pokemonScale = 282,
        .pokemonOffset = 3,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Gurdurr, 64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_Gurdurr,
        .frontAnimId = ANIM_GROW_VIBRATE,
        BACK_PIC(Gurdurr, 64, 48),
        .backPicYOffset = 9,
        .backAnimId = BACK_ANIM_JOLT_RIGHT,
        PALETTES(Gurdurr),
        ICON(Gurdurr, 1),
        .footprint = gMonFootprint_Gurdurr,
        LEARNSETS(Gurdurr),
        .evolutions = EVOLUTION({EVO_TRADE, 0, SPECIES_CONKELDURR},
                                {EVO_ITEM, ITEM_LINKING_CORD, SPECIES_CONKELDURR}),
    },

    [SPECIES_CONKELDURR] =
    {
        .baseHP        = 105,
        .baseAttack    = 140,
        .baseDefense   = 95,
        .baseSpeed     = 45,
        .baseSpAttack  = 55,
        .baseSpDefense = 65,
        .types = { TYPE_FIGHTING, TYPE_FIGHTING },
        .catchRate = 45,
        .expYield = 227,
        .evYield_Attack = 3,
        .genderRatio = PERCENT_FEMALE(25),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_HUMAN_LIKE, EGG_GROUP_HUMAN_LIKE },
        .abilities = { ABILITY_GUTS, ABILITY_SHEER_FORCE, ABILITY_IRON_FIST },
        .bodyColor = BODY_COLOR_BROWN,
        .speciesName = _("Meistagrif"),
        .cryId = CRY_CONKELDURR,
        .natDexNum = NATIONAL_DEX_CONKELDURR,
        .categoryName = _("Muskel"),
        .height = 14,
        .weight = 870,
        .description = POKEDEX_DESC_STRING(
            "Man nimmt an, dass es der\n"
            "Menschheit vor ca. 2 000 Jahren das\n"
            "Betonmischen beigebracht hat."),
        .pokemonScale = 265,
        .pokemonOffset = 3,
        .trainerScale = 262,
        .trainerOffset = 0,
        FRONT_PIC(Conkeldurr, 64, 56),
        .frontPicYOffset = 6,
        .frontAnimFrames = sAnims_Conkeldurr,
        .frontAnimId = ANIM_V_SHAKE_TWICE,
        BACK_PIC(Conkeldurr, 64, 56),
        .backPicYOffset = 13,
        .backAnimId = BACK_ANIM_V_SHAKE_H_SLIDE,
        PALETTES(Conkeldurr),
        ICON(Conkeldurr, 1),
        .footprint = gMonFootprint_Conkeldurr,
        LEARNSETS(Conkeldurr),
    },
#endif //P_FAMILY_TIMBURR

#if P_FAMILY_TYMPOLE
    [SPECIES_TYMPOLE] =
    {
        .baseHP        = 50,
        .baseAttack    = 50,
        .baseDefense   = 40,
        .baseSpeed     = 64,
        .baseSpAttack  = 50,
        .baseSpDefense = 40,
        .types = { TYPE_WATER, TYPE_WATER },
        .catchRate = 255,
        .expYield = 59,
        .evYield_Speed = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_WATER_1, EGG_GROUP_WATER_1 },
        .abilities = { ABILITY_SWIFT_SWIM, ABILITY_HYDRATION, ABILITY_WATER_ABSORB },
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Schallquap"),
        .cryId = CRY_TYMPOLE,
        .natDexNum = NATIONAL_DEX_TYMPOLE,
        .categoryName = _("Kaulquappen"),
        .height = 5,
        .weight = 45,
        .description = POKEDEX_DESC_STRING(
            "Erzeugt mit seinen Wangen für Menschen\n"
            "unhörbare Schallwellen. Es verständigt\n"
            "sich über den Rhythmus dieser Wellen."),
        .pokemonScale = 432,
        .pokemonOffset = 15,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Tympole, 40, 40),
        .frontPicYOffset = 14,
        .frontAnimFrames = sAnims_Tympole,
        .frontAnimId = ANIM_H_JUMPS_V_STRETCH,
        BACK_PIC(Tympole, 40, 32),
        .backPicYOffset = 17,
        .backAnimId = BACK_ANIM_H_SPRING,
        PALETTES(Tympole),
        ICON(Tympole, 2),
        .footprint = gMonFootprint_Tympole,
        LEARNSETS(Tympole),
        .evolutions = EVOLUTION({EVO_LEVEL, 25, SPECIES_PALPITOAD}),
    },

    [SPECIES_PALPITOAD] =
    {
        .baseHP        = 75,
        .baseAttack    = 65,
        .baseDefense   = 55,
        .baseSpeed     = 69,
        .baseSpAttack  = 65,
        .baseSpDefense = 55,
        .types = { TYPE_WATER, TYPE_GROUND },
        .catchRate = 120,
        .expYield = 134,
        .evYield_HP = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_WATER_1, EGG_GROUP_WATER_1 },
        .abilities = { ABILITY_SWIFT_SWIM, ABILITY_HYDRATION, ABILITY_WATER_ABSORB },
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Mebrana"),
        .cryId = CRY_PALPITOAD,
        .natDexNum = NATIONAL_DEX_PALPITOAD,
        .categoryName = _("Vibrations"),
        .height = 8,
        .weight = 170,
        .description = POKEDEX_DESC_STRING(
            "Wenn es die Beulen auf seinem Kopf\n"
            "zum Schwingen bringt, tobt je nach\n"
            "Umgebung entweder das Wasser oder\n"
            "die Erde bebt."),
        .pokemonScale = 366,
        .pokemonOffset = 10,
        .trainerScale = 257,
        .trainerOffset = 0,
        FRONT_PIC(Palpitoad, 40, 48),
        .frontPicYOffset = 11,
        .frontAnimFrames = sAnims_Palpitoad,
        .frontAnimId = ANIM_CIRCULAR_STRETCH_TWICE,
        BACK_PIC(Palpitoad, 56, 40),
        .backPicYOffset = 12,
        .backAnimId = BACK_ANIM_H_VIBRATE,
        PALETTES(Palpitoad),
        ICON(Palpitoad, 2),
        .footprint = gMonFootprint_Palpitoad,
        LEARNSETS(Palpitoad),
        .evolutions = EVOLUTION({EVO_LEVEL, 36, SPECIES_SEISMITOAD}),
    },

    [SPECIES_SEISMITOAD] =
    {
        .baseHP        = 105,
        .baseAttack    = P_UPDATED_STATS >= GEN_6 ? 95 : 85,
        .baseDefense   = 75,
        .baseSpeed     = 74,
        .baseSpAttack  = 85,
        .baseSpDefense = 75,
        .types = { TYPE_WATER, TYPE_GROUND },
        .catchRate = 45,
        .expYield = 229,
        .evYield_HP = 3,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_WATER_1, EGG_GROUP_WATER_1 },
        .abilities = { ABILITY_SWIFT_SWIM, ABILITY_POISON_TOUCH, ABILITY_WATER_ABSORB },
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Branawarz"),
        .cryId = CRY_SEISMITOAD,
        .natDexNum = NATIONAL_DEX_SEISMITOAD,
        .categoryName = _("Vibrations"),
        .height = 15,
        .weight = 620,
        .description = POKEDEX_DESC_STRING(
            "Wenn es die Beulen an seinen\n"
            "Fäusten zum Schwingen bringt, kann\n"
            "es doppelt so fest zuschlagen und\n"
            "Felsen zertrümmern."),
        .pokemonScale = 268,
        .pokemonOffset = 2,
        .trainerScale = 271,
        .trainerOffset = 0,
        FRONT_PIC(Seismitoad, 64, 64),
        .frontPicYOffset = 2,
        .frontAnimFrames = sAnims_Seismitoad,
        .frontAnimId = ANIM_H_JUMPS,
        BACK_PIC(Seismitoad, 64, 40),
        .backPicYOffset = 12,
        .backAnimId = BACK_ANIM_V_SHAKE_H_SLIDE,
        PALETTES(Seismitoad),
        ICON(Seismitoad, 0),
        .footprint = gMonFootprint_Seismitoad,
        LEARNSETS(Seismitoad),
    },
#endif //P_FAMILY_TYMPOLE

#if P_FAMILY_THROH
    [SPECIES_THROH] =
    {
        .baseHP        = 120,
        .baseAttack    = 100,
        .baseDefense   = 85,
        .baseSpeed     = 45,
        .baseSpAttack  = 30,
        .baseSpDefense = 85,
        .types = { TYPE_FIGHTING, TYPE_FIGHTING },
        .catchRate = 45,
        .expYield = 163,
        .evYield_HP = 2,
        .itemRare = ITEM_BLACK_BELT,
        .genderRatio = MON_MALE,
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_HUMAN_LIKE, EGG_GROUP_HUMAN_LIKE },
        .abilities = { ABILITY_GUTS, ABILITY_INNER_FOCUS, ABILITY_MOLD_BREAKER },
        .bodyColor = BODY_COLOR_RED,
        .speciesName = _("Jiutesto"),
        .cryId = CRY_THROH,
        .natDexNum = NATIONAL_DEX_THROH,
        .categoryName = _("Judo"),
        .height = 13,
        .weight = 555,
        .description = POKEDEX_DESC_STRING(
            "Zurrt es seinen Gürtel fest,\n"
            "gewinnt es an Kraft. Wilde\n"
            "Exemplare flechten sich ihren\n"
            "Gürtel in Handarbeit aus Ranken."),
        .pokemonScale = 272,
        .pokemonOffset = 7,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Throh, 64, 48),
        .frontPicYOffset = 10,
        .frontAnimFrames = sAnims_Throh,
        .frontAnimId = ANIM_CIRCULAR_STRETCH_TWICE,
        BACK_PIC(Throh, 64, 48),
        .backPicYOffset = 11,
        .backAnimId = BACK_ANIM_V_SHAKE_LOW,
        PALETTES(Throh),
        ICON(Throh, 0),
        .footprint = gMonFootprint_Throh,
        LEARNSETS(Throh),
    },
#endif //P_FAMILY_THROH

#if P_FAMILY_SAWK
    [SPECIES_SAWK] =
    {
        .baseHP        = 75,
        .baseAttack    = 125,
        .baseDefense   = 75,
        .baseSpeed     = 85,
        .baseSpAttack  = 30,
        .baseSpDefense = 75,
        .types = { TYPE_FIGHTING, TYPE_FIGHTING },
        .catchRate = 45,
        .expYield = 163,
        .evYield_Attack = 2,
        .itemRare = ITEM_BLACK_BELT,
        .genderRatio = MON_MALE,
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_HUMAN_LIKE, EGG_GROUP_HUMAN_LIKE },
        .abilities = { ABILITY_STURDY, ABILITY_INNER_FOCUS, ABILITY_MOLD_BREAKER },
        .bodyColor = BODY_COLOR_BLUE,
        .noFlip = TRUE,
        .speciesName = _("Karadonis"),
        .cryId = CRY_SAWK,
        .natDexNum = NATIONAL_DEX_SAWK,
        .categoryName = _("Karate"),
        .height = 14,
        .weight = 510,
        .description = POKEDEX_DESC_STRING(
            "Der Karateschlag eines perfekt\n"
            "durchtrainierten Karadonis' hat genug\n"
            "Wucht, um selbst das Meer zu spalten."),
        .pokemonScale = 265,
        .pokemonOffset = 4,
        .trainerScale = 262,
        .trainerOffset = 0,
        FRONT_PIC(Sawk, 56, 56),
        .frontPicYOffset = 7,
        .frontAnimFrames = sAnims_Sawk,
        .frontAnimId = ANIM_GROW_VIBRATE,
        BACK_PIC(Sawk, 64, 40),
        .backPicYOffset = 13,
        .backAnimId = BACK_ANIM_H_STRETCH,
        PALETTES(Sawk),
        ICON(Sawk, 0),
        .footprint = gMonFootprint_Sawk,
        LEARNSETS(Sawk),
    },
#endif //P_FAMILY_SAWK

#if P_FAMILY_SEWADDLE
    [SPECIES_SEWADDLE] =
    {
        .baseHP        = 45,
        .baseAttack    = 53,
        .baseDefense   = 70,
        .baseSpeed     = 42,
        .baseSpAttack  = 40,
        .baseSpDefense = 60,
        .types = { TYPE_BUG, TYPE_GRASS },
        .catchRate = 255,
        .expYield = 62,
        .evYield_Defense = 1,
        .itemRare = ITEM_MENTAL_HERB,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_BUG, EGG_GROUP_BUG },
        .abilities = { ABILITY_SWARM, ABILITY_CHLOROPHYLL, ABILITY_OVERCOAT },
        .bodyColor = BODY_COLOR_YELLOW,
        .speciesName = _("Strawickl"),
        .cryId = CRY_SEWADDLE,
        .natDexNum = NATIONAL_DEX_SEWADDLE,
        .categoryName = _("Schneider"),
        .height = 3,
        .weight = 25,
        .description = POKEDEX_DESC_STRING(
            "Schneidert sich ein Kleid, indem es\n"
            "sich Blätter zurechtbeißt und sie\n"
            "mit Klebefäden aus seinem Mund\n"
            "zusammennäht."),
        .pokemonScale = 530,
        .pokemonOffset = 15,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Sewaddle, 40, 40),
        .frontPicYOffset = 14,
        .frontAnimFrames = sAnims_Sewaddle,
        .frontAnimId = ANIM_CIRCLE_INTO_BG,
        BACK_PIC(Sewaddle, 40, 48),
        .backPicYOffset = 13,
        .backAnimId = BACK_ANIM_H_SLIDE,
        PALETTES(Sewaddle),
        ICON(Sewaddle, 1),
        .footprint = gMonFootprint_Sewaddle,
        LEARNSETS(Sewaddle),
        .evolutions = EVOLUTION({EVO_LEVEL, 20, SPECIES_SWADLOON}),
    },

    [SPECIES_SWADLOON] =
    {
        .baseHP        = 55,
        .baseAttack    = 63,
        .baseDefense   = 90,
        .baseSpeed     = 42,
        .baseSpAttack  = 50,
        .baseSpDefense = 80,
        .types = { TYPE_BUG, TYPE_GRASS },
        .catchRate = 120,
        .expYield = 133,
        .evYield_Defense = 2,
        .itemRare = ITEM_MENTAL_HERB,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_BUG, EGG_GROUP_BUG },
        .abilities = { ABILITY_LEAF_GUARD, ABILITY_CHLOROPHYLL, ABILITY_OVERCOAT },
        .bodyColor = BODY_COLOR_GREEN,
        .speciesName = _("Folikon"),
        .cryId = CRY_SWADLOON,
        .natDexNum = NATIONAL_DEX_SWADLOON,
        .categoryName = _("Wickelblatt"),
        .height = 5,
        .weight = 73,
        .description = POKEDEX_DESC_STRING(
            "Es wandelt herabgefallenes Laub in\n"
            "Nährstoffe um. In Wäldern, wo es\n"
            "Folikon gibt, fühlen sich Pflanzen\n"
            "pudelwohl."),
        .pokemonScale = 432,
        .pokemonOffset = 15,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Swadloon, 56, 48),
        .frontPicYOffset = 12,
        .frontAnimFrames = sAnims_Swadloon,
        .frontAnimId = ANIM_CIRCULAR_STRETCH_TWICE,
        BACK_PIC(Swadloon, 48, 48),
        .backPicYOffset = 10,
        .backAnimId = BACK_ANIM_H_VIBRATE,
        PALETTES(Swadloon),
        ICON(Swadloon, 1),
        .footprint = gMonFootprint_Swadloon,
        LEARNSETS(Swadloon),
        .evolutions = EVOLUTION({EVO_FRIENDSHIP, 0, SPECIES_LEAVANNY}),
    },

    [SPECIES_LEAVANNY] =
    {
        .baseHP        = 75,
        .baseAttack    = 103,
        .baseDefense   = 80,
        .baseSpeed     = 92,
        .baseSpAttack  = 70,
        .baseSpDefense = P_UPDATED_STATS >= GEN_6 ? 80 : 70,
        .types = { TYPE_BUG, TYPE_GRASS },
        .catchRate = 45,
        .expYield = 225,
        .evYield_Attack = 3,
        .itemRare = ITEM_MENTAL_HERB,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_BUG, EGG_GROUP_BUG },
        .abilities = { ABILITY_SWARM, ABILITY_CHLOROPHYLL, ABILITY_OVERCOAT },
        .bodyColor = BODY_COLOR_YELLOW,
        .speciesName = _("Matrifol"),
        .cryId = CRY_LEAVANNY,
        .natDexNum = NATIONAL_DEX_LEAVANNY,
        .categoryName = _("Kinderpflege"),
        .height = 12,
        .weight = 205,
        .description = POKEDEX_DESC_STRING(
            "Begegnet es einem jungen Pokémon,\n"
            "näht es ihm mit den klebrigen Fäden\n"
            "aus seinem Mund ein Kleid aus\n"
            "Blättern."),
        .pokemonScale = 282,
        .pokemonOffset = 3,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Leavanny, 48, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_Leavanny,
        .frontAnimId = ANIM_GROW_VIBRATE,
        BACK_PIC(Leavanny, 56, 64),
        .backPicYOffset = 0,
        .backAnimId = BACK_ANIM_GROW_STUTTER,
        PALETTES(Leavanny),
        ICON(Leavanny, 1),
        .footprint = gMonFootprint_Leavanny,
        LEARNSETS(Leavanny),
    },
#endif //P_FAMILY_SEWADDLE

#if P_FAMILY_VENIPEDE
    [SPECIES_VENIPEDE] =
    {
        .baseHP        = 30,
        .baseAttack    = 45,
        .baseDefense   = 59,
        .baseSpeed     = 57,
        .baseSpAttack  = 30,
        .baseSpDefense = 39,
        .types = { TYPE_BUG, TYPE_POISON },
        .catchRate = 255,
        .expYield = 52,
        .evYield_Defense = 1,
        .itemRare = ITEM_POISON_BARB,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_BUG, EGG_GROUP_BUG },
        #if P_UPDATED_ABILITIES >= GEN_6
            .abilities = { ABILITY_POISON_POINT, ABILITY_SWARM, ABILITY_SPEED_BOOST },
        #else
            .abilities = { ABILITY_POISON_POINT, ABILITY_SWARM, ABILITY_QUICK_FEET },
        #endif
        .bodyColor = BODY_COLOR_RED,
        .speciesName = _("Toxiped"),
        .cryId = CRY_VENIPEDE,
        .natDexNum = NATIONAL_DEX_VENIPEDE,
        .categoryName = _("Tausendfüßer"),
        .height = 4,
        .weight = 53,
        .description = POKEDEX_DESC_STRING(
            "Es beißt Angreifer und injiziert ihnen\n"
            "Gift, das selbst große Vogel-Pokémon,\n"
            "seine natürlichen Feinde, lähmt."),
        .pokemonScale = 491,
        .pokemonOffset = 16,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Venipede, 48, 32),
        .frontPicYOffset = 16,
        .frontAnimFrames = sAnims_Venipede,
        .frontAnimId = ANIM_H_SLIDE,
        BACK_PIC(Venipede, 64, 40),
        .backPicYOffset = 14,
        .backAnimId = BACK_ANIM_H_VIBRATE,
        PALETTES(Venipede),
        ICON(Venipede, 1),
        .footprint = gMonFootprint_Venipede,
        LEARNSETS(Venipede),
        .evolutions = EVOLUTION({EVO_LEVEL, 22, SPECIES_WHIRLIPEDE}),
    },

    [SPECIES_WHIRLIPEDE] =
    {
        .baseHP        = 40,
        .baseAttack    = 55,
        .baseDefense   = 99,
        .baseSpeed     = 47,
        .baseSpAttack  = 40,
        .baseSpDefense = 79,
        .types = { TYPE_BUG, TYPE_POISON },
        .catchRate = 120,
        .expYield = 126,
        .evYield_Defense = 2,
        .itemRare = ITEM_POISON_BARB,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_BUG, EGG_GROUP_BUG },
        #if P_UPDATED_ABILITIES >= GEN_6
            .abilities = { ABILITY_POISON_POINT, ABILITY_SWARM, ABILITY_SPEED_BOOST },
        #else
            .abilities = { ABILITY_POISON_POINT, ABILITY_SWARM, ABILITY_QUICK_FEET },
        #endif
        .bodyColor = BODY_COLOR_GRAY,
        .speciesName = _("Rollum"),
        .cryId = CRY_WHIRLIPEDE,
        .natDexNum = NATIONAL_DEX_WHIRLIPEDE,
        .categoryName = _("Kokonfüßer"),
        .height = 12,
        .weight = 585,
        .description = POKEDEX_DESC_STRING(
            "An sich ist es harmlos. Bringt man es\n"
            "jedoch in Bedrängnis, setzt es sich mit\n"
            "blitzschnellen Rollattacken zur Wehr."),
        .pokemonScale = 282,
        .pokemonOffset = 7,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Whirlipede, 56, 40),
        .frontPicYOffset = 13,
        .frontAnimFrames = sAnims_Whirlipede,
        .frontAnimId = ANIM_TIP_MOVE_FORWARD,
        BACK_PIC(Whirlipede, 64, 40),
        .backPicYOffset = 15,
        .backAnimId = BACK_ANIM_DIP_RIGHT_SIDE,
        PALETTES(Whirlipede),
        ICON(Whirlipede, 2),
        .footprint = gMonFootprint_Whirlipede,
        LEARNSETS(Whirlipede),
        .evolutions = EVOLUTION({EVO_LEVEL, 30, SPECIES_SCOLIPEDE}),
    },

    [SPECIES_SCOLIPEDE] =
    {
        .baseHP        = 60,
        .baseAttack    = P_UPDATED_STATS >= GEN_6 ? 100 : 90,
        .baseDefense   = 89,
        .baseSpeed     = 112,
        .baseSpAttack  = 55,
        .baseSpDefense = 69,
        .types = { TYPE_BUG, TYPE_POISON },
        .catchRate = 45,
        .expYield = 218,
        .evYield_Speed = 3,
        .itemRare = ITEM_POISON_BARB,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_BUG, EGG_GROUP_BUG },
        #if P_UPDATED_ABILITIES >= GEN_6
            .abilities = { ABILITY_POISON_POINT, ABILITY_SWARM, ABILITY_SPEED_BOOST },
        #else
            .abilities = { ABILITY_POISON_POINT, ABILITY_SWARM, ABILITY_QUICK_FEET },
        #endif
        .bodyColor = BODY_COLOR_RED,
        .speciesName = _("Cerapendra"),
        .cryId = CRY_SCOLIPEDE,
        .natDexNum = NATIONAL_DEX_SCOLIPEDE,
        .categoryName = _("Riesenfüßer"),
        .height = 25,
        .weight = 2005,
        .description = POKEDEX_DESC_STRING(
            "Es liefert sich erbitterte Revierkämpfe\n"
            "mit Infernopod. Wer den Kampf verliert,\n"
            "wird zur Beute des Siegers."),
        .pokemonScale = 257,
        .pokemonOffset = 2,
        .trainerScale = 423,
        .trainerOffset = 8,
        FRONT_PIC(Scolipede, 64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_Scolipede,
        .frontAnimId = ANIM_H_SHAKE,
        BACK_PIC(Scolipede, 64, 64),
        .backPicYOffset = 4,
        .backAnimId = BACK_ANIM_V_SHAKE_LOW,
        PALETTES(Scolipede),
        ICON(Scolipede, 2),
        .footprint = gMonFootprint_Scolipede,
        LEARNSETS(Scolipede),
    },
#endif //P_FAMILY_VENIPEDE

#if P_FAMILY_COTTONEE
#if P_UPDATED_TYPES >= GEN_6
    #define COTTONEE_FAMILY_TYPES { TYPE_GRASS, TYPE_FAIRY }
#else
    #define COTTONEE_FAMILY_TYPES { TYPE_GRASS, TYPE_GRASS }
#endif

    [SPECIES_COTTONEE] =
    {
        .baseHP        = 40,
        .baseAttack    = 27,
        .baseDefense   = 60,
        .baseSpeed     = 66,
        .baseSpAttack  = 37,
        .baseSpDefense = 50,
        .types = COTTONEE_FAMILY_TYPES,
        .catchRate = 190,
        .expYield = 56,
        .evYield_Speed = 1,
        .itemRare = ITEM_ABSORB_BULB,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_GRASS, EGG_GROUP_FAIRY },
        .abilities = { ABILITY_PRANKSTER, ABILITY_INFILTRATOR, ABILITY_CHLOROPHYLL },
        .bodyColor = BODY_COLOR_GREEN,
        .speciesName = _("Waumboll"),
        .cryId = CRY_COTTONEE,
        .natDexNum = NATIONAL_DEX_COTTONEE,
        .categoryName = _("Wattebausch"),
        .height = 3,
        .weight = 6,
        .description = POKEDEX_DESC_STRING(
            "Luxusmarken verwenden oft feine Stoffe,\n"
            "die aus Mischwolle von Waumboll und\n"
            "Cottomi bestehen, für ihre Produkte."),
        .pokemonScale = 530,
        .pokemonOffset = 15,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Cottonee, 48, 32),
        .frontPicYOffset = 18,
        .frontAnimFrames = sAnims_Cottonee,
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(Cottonee, 64, 32),
        .backPicYOffset = 18,
        .backAnimId = BACK_ANIM_CONVEX_DOUBLE_ARC,
        PALETTES(Cottonee),
        ICON(Cottonee, 1),
        .footprint = gMonFootprint_Cottonee,
        LEARNSETS(Cottonee),
        .evolutions = EVOLUTION({EVO_ITEM, ITEM_SUN_STONE, SPECIES_WHIMSICOTT}),
    },

    [SPECIES_WHIMSICOTT] =
    {
        .baseHP        = 60,
        .baseAttack    = 67,
        .baseDefense   = 85,
        .baseSpeed     = 116,
        .baseSpAttack  = 77,
        .baseSpDefense = 75,
        .types = COTTONEE_FAMILY_TYPES,
        .catchRate = 75,
        .expYield = 168,
        .evYield_Speed = 2,
        .itemRare = ITEM_ABSORB_BULB,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_GRASS, EGG_GROUP_FAIRY },
        .abilities = { ABILITY_PRANKSTER, ABILITY_INFILTRATOR, ABILITY_CHLOROPHYLL },
        .bodyColor = BODY_COLOR_GREEN,
        .speciesName = _("Elfun"),
        .cryId = CRY_WHIMSICOTT,
        .natDexNum = NATIONAL_DEX_WHIMSICOTT,
        .categoryName = _("Windschatten"),
        .height = 7,
        .weight = 66,
        .description = POKEDEX_DESC_STRING(
            "Es reitet auf dem Wind, doch wenn dieser\n"
            "zu stark ist, wird die Watte an seinem\n"
            "Kopf abgerissen."),
        .pokemonScale = 365,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Whimsicott, 56, 56),
        .frontPicYOffset = 6,
        .frontAnimFrames = sAnims_Whimsicott,
        .frontAnimId = ANIM_SHRINK_GROW,
        BACK_PIC(Whimsicott, 64, 48),
        .backPicYOffset = 9,
        .backAnimId = BACK_ANIM_CONCAVE_ARC_LARGE,
        PALETTES(Whimsicott),
        ICON(Whimsicott, 1),
        .footprint = gMonFootprint_Whimsicott,
        LEARNSETS(Whimsicott),
    },
#endif //P_FAMILY_COTTONEE

#if P_FAMILY_PETILIL
    [SPECIES_PETILIL] =
    {
        .baseHP        = 45,
        .baseAttack    = 35,
        .baseDefense   = 50,
        .baseSpeed     = 30,
        .baseSpAttack  = 70,
        .baseSpDefense = 50,
        .types = { TYPE_GRASS, TYPE_GRASS },
        .catchRate = 190,
        .expYield = 56,
        .evYield_SpAttack = 1,
        .itemRare = ITEM_ABSORB_BULB,
        .genderRatio = MON_FEMALE,
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_GRASS, EGG_GROUP_GRASS },
        .abilities = { ABILITY_CHLOROPHYLL, ABILITY_OWN_TEMPO, ABILITY_LEAF_GUARD },
        .bodyColor = BODY_COLOR_GREEN,
        .speciesName = _("Lilminip"),
        .cryId = CRY_PETILIL,
        .natDexNum = NATIONAL_DEX_PETILIL,
        .categoryName = _("Wurzel"),
        .height = 5,
        .weight = 66,
        .description = POKEDEX_DESC_STRING(
            "Die Blätter auf seinem Kopf\n"
            "schmecken furchtbar bitter, doch\n"
            "sie helfen ausgezeichnet gegen\n"
            "Erschöpfung."),
        .pokemonScale = 432,
        .pokemonOffset = 13,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Petilil, 32, 48),
        .frontPicYOffset = 12,
        .frontAnimFrames = sAnims_Petilil,
        .frontAnimId = ANIM_H_JUMPS_V_STRETCH,
        .enemyMonElevation = 7,
        BACK_PIC(Petilil, 40, 56),
        .backPicYOffset = 9,
        .backAnimId = BACK_ANIM_V_STRETCH,
        PALETTES(Petilil),
        ICON(Petilil, 1),
        .footprint = gMonFootprint_Petilil,
        LEARNSETS(Petilil),
        .evolutions = EVOLUTION({EVO_ITEM, ITEM_SUN_STONE, SPECIES_LILLIGANT},
                                {EVO_NONE, 0, SPECIES_LILLIGANT_HISUI}),
    },

#define LILLIGANT_MISC_INFO                                 \
        .catchRate = 75,                                    \
        .expYield = 168,                                    \
        .itemRare = ITEM_ABSORB_BULB,                       \
        .genderRatio = MON_FEMALE,                          \
        .eggCycles = 20,                                    \
        .friendship = STANDARD_FRIENDSHIP,                  \
        .growthRate = GROWTH_MEDIUM_FAST,                   \
        .eggGroups = { EGG_GROUP_GRASS, EGG_GROUP_GRASS },  \
        .bodyColor = BODY_COLOR_GREEN,                      \
        .noFlip = TRUE,                                     \
        .speciesName = _("Lilminip"),                      \
        .cryId = CRY_LILLIGANT,                             \
        .natDexNum = NATIONAL_DEX_LILLIGANT,                \
        .footprint = gMonFootprint_Lilligant,               \
        .formSpeciesIdTable = sLilligantFormSpeciesIdTable

    [SPECIES_LILLIGANT] =
    {
        LILLIGANT_MISC_INFO,
        .baseHP        = 70,
        .baseAttack    = 60,
        .baseDefense   = 75,
        .baseSpeed     = 90,
        .baseSpAttack  = 110,
        .baseSpDefense = 75,
        .types = { TYPE_GRASS, TYPE_GRASS },
        .evYield_SpAttack = 2,
        .abilities = { ABILITY_CHLOROPHYLL, ABILITY_OWN_TEMPO, ABILITY_LEAF_GUARD },
        .categoryName = _("Blumenzier"),
        .height = 11,
        .weight = 163,
        .description = POKEDEX_DESC_STRING(
            "Sobald es einen Partner gefunden hat,\n"
            "verwelkt sein wunderschöner Blumenschmuck."),
        .pokemonScale = 320,
        .pokemonOffset = 7,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Lilligant, 56, 64),
        .frontPicYOffset = 1,
        .frontAnimFrames = sAnims_Lilligant,
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(Lilligant, 64, 56),
        .backPicYOffset = 8,
        .backAnimId = BACK_ANIM_SHRINK_GROW,
        PALETTES(Lilligant),
        ICON(Lilligant, 1),
        LEARNSETS(Lilligant),
    },

#if P_HISUIAN_FORMS
    [SPECIES_LILLIGANT_HISUI] =
    {
        LILLIGANT_MISC_INFO,
        .baseHP        = 70,
        .baseAttack    = 105,
        .baseDefense   = 75,
        .baseSpeed     = 105,
        .baseSpAttack  = 50,
        .baseSpDefense = 75,
        .types = { TYPE_GRASS, TYPE_FIGHTING },
        .evYield_Attack = 1,
        .evYield_Speed = 1,
        .abilities = { ABILITY_CHLOROPHYLL, ABILITY_HUSTLE, ABILITY_LEAF_GUARD },
        .categoryName = _("Blumenzier"),
        .height = 12,
        .weight = 192,
        .description = POKEDEX_DESC_STRING(
            "Der Duft des Blumenschmucks auf\n"
            "seinem Kopf wirkt beruhigend. Damit\n"
            "der Schmuck nicht verwelkt, muss\n"
            "man es gut pflegen."),
        .pokemonScale = 320,
        .pokemonOffset = 7,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(LilligantHisuian, 56, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_LilligantHisuian,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(LilligantHisuian, 56, 56),
        .backPicYOffset = 5,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(LilligantHisuian),
        ICON(LilligantHisuian, 1),
        LEARNSETS(LilligantHisuian),
        .isHisuianForm = TRUE,
    },
#endif //P_HISUIAN_FORMS
#endif //P_FAMILY_PETILIL

#if P_FAMILY_BASCULIN
#define BASCULIN_MISC_INFO                                      \
        .baseHP        = 70,                                    \
        .baseAttack    = 92,                                    \
        .baseDefense   = 65,                                    \
        .baseSpeed     = 98,                                    \
        .baseSpAttack  = 80,                                    \
        .baseSpDefense = 55,                                    \
        .types = { TYPE_WATER, TYPE_WATER },                    \
        .catchRate = 190,                                       \
        .expYield = 161,                                        \
        .evYield_Speed = 2,                                     \
        .genderRatio = PERCENT_FEMALE(50),                      \
        .eggCycles = 40,                                        \
        .friendship = STANDARD_FRIENDSHIP,                      \
        .growthRate = GROWTH_MEDIUM_FAST,                       \
        .eggGroups = { EGG_GROUP_WATER_2, EGG_GROUP_WATER_2 },  \
        .bodyColor = BODY_COLOR_GREEN,                          \
        .speciesName = _("Dressella"),                           \
        .cryId = CRY_BASCULIN,                                  \
        .natDexNum = NATIONAL_DEX_BASCULIN,                     \
        .height = 10,                                           \
        .weight = 180,                                          \
        .pokemonScale = 316,                                    \
        .pokemonOffset = 7,                                     \
        .trainerScale = 257,                                    \
        .trainerOffset = 0,                                     \
        .enemyMonElevation = 6,                                 \
        .footprint = gMonFootprint_Basculin,                    \
        .formSpeciesIdTable = sBasculinFormSpeciesIdTable

    [SPECIES_BASCULIN_RED_STRIPED] =
    {
        BASCULIN_MISC_INFO,
        .itemRare = ITEM_DEEP_SEA_TOOTH,
        .abilities = { ABILITY_RECKLESS, ABILITY_ADAPTABILITY, ABILITY_MOLD_BREAKER },
        .categoryName = _("Grobheits"),
        .description = POKEDEX_DESC_STRING(
            "Rot gestreifte und blau gestreifte\n"
            "Exemplare sind sich feindlich gesonnen.\n"
            "Doch ist jeder Schwarm bunt gemischt."),
        FRONT_PIC(BasculinRedStriped, 56, 40),
        .frontPicYOffset = 13,
        .frontAnimFrames = sAnims_Basculin,
        .frontAnimId = ANIM_TIP_MOVE_FORWARD,
        BACK_PIC(BasculinRedStriped, 64, 48),
        .backPicYOffset = 16,
        .backAnimId = BACK_ANIM_JOLT_RIGHT,
        PALETTES(BasculinRedStriped),
        ICON(BasculinRedStriped, 1),
        LEARNSETS(Basculin),
    },

    [SPECIES_BASCULIN_BLUE_STRIPED] =
    {
        BASCULIN_MISC_INFO,
        .itemRare = ITEM_DEEP_SEA_SCALE,
        .abilities = { ABILITY_ROCK_HEAD, ABILITY_ADAPTABILITY, ABILITY_MOLD_BREAKER },
        .categoryName = _("Grobheits"),
        .description = POKEDEX_DESC_STRING(
            "Sie gelten als Delikatesse.\n"
            "Aufgrund ihrer brutalen Natur\n"
            "liegen rot und blau gestreifte\n"
            "Exemplare immer im Clinch."),
        FRONT_PIC(BasculinBlueStriped, 56, 40),
        .frontPicYOffset = 16,
        .frontAnimFrames = sAnims_Basculin,
        .frontAnimId = ANIM_TIP_MOVE_FORWARD,
        BACK_PIC(BasculinBlueStriped, 64, 48),
        .backPicYOffset = 16,
        .backAnimId = BACK_ANIM_JOLT_RIGHT,
        PALETTES(BasculinBlueStriped),
        ICON(BasculinBlueStriped, 0),
        LEARNSETS(Basculin),
    },

#if P_HISUIAN_FORMS
    [SPECIES_BASCULIN_WHITE_STRIPED] =
    {
        BASCULIN_MISC_INFO,
        .itemRare = ITEM_DEEP_SEA_SCALE,
        .abilities = { ABILITY_RATTLED, ABILITY_ADAPTABILITY, ABILITY_MOLD_BREAKER },
        .categoryName = _("Grobheits"),
        .description = POKEDEX_DESC_STRING(
            "Sie gelten als Delikatesse.\n"
            "Aufgrund ihrer brutalen Natur\n"
            "liegen rot und blau gestreifte\n"
            "Exemplare immer im Clinch."),
        FRONT_PIC(BasculinWhiteStriped, 48, 40),
        .frontPicYOffset = 12,
        .frontAnimFrames = sAnims_Basculin,
        .frontAnimId = ANIM_TIP_MOVE_FORWARD,
        BACK_PIC(BasculinWhiteStriped, 64, 40),
        .backPicYOffset = 16,
        .backAnimId = BACK_ANIM_JOLT_RIGHT,
        PALETTES(BasculinWhiteStriped),
        ICON(BasculinWhiteStriped, 0),
        LEARNSETS(BasculinWhiteStriped),
        .evolutions = EVOLUTION({EVO_NONE, 0, SPECIES_BASCULEGION_MALE},
                                {EVO_NONE, 0, SPECIES_BASCULEGION_FEMALE}),
    },

#define BASCULEGION_MISC_INFO                                                               \
        .types = { TYPE_WATER, TYPE_GHOST },                                                \
        .catchRate = 45,                                                                    \
        .expYield = 265,                                                                    \
        .evYield_HP = 3,                                                                    \
        .eggCycles = 20,                                                                    \
        .friendship = STANDARD_FRIENDSHIP,                                                  \
        .growthRate = GROWTH_MEDIUM_FAST,                                                   \
        .eggGroups = { EGG_GROUP_WATER_2, EGG_GROUP_WATER_2 },                              \
        .abilities = { ABILITY_SWIFT_SWIM, ABILITY_ADAPTABILITY, ABILITY_MOLD_BREAKER },    \
        .bodyColor = BODY_COLOR_GREEN,                                                      \
        .speciesName = _("Barschuft"),                                                     \
        .cryId = CRY_BASCULEGION,                                                           \
        .natDexNum = NATIONAL_DEX_BASCULEGION,                                              \
        .categoryName = _("Grobheits"),                                                      \
        .height = 30,                                                                       \
        .weight = 1100,                                                                     \
        .pokemonScale = 275,                                                                \
        .pokemonOffset = 7,                                                                 \
        .trainerScale = 256,                                                                \
        .trainerOffset = 0,                                                                 \
        .frontAnimFrames = sAnims_Basculegion,                                              \
        .frontPicYOffset = 0,                                                               \
        .enemyMonElevation = 5,                                                             \
        .backPicYOffset = 8,                                                                \
        LEARNSETS(Basculegion),                                                             \
        .formSpeciesIdTable = sBasculegionFormSpeciesIdTable
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        //.backAnimId = BACK_ANIM_NONE,
        //.footprint = gMonFootprint_Basculegion,

    [SPECIES_BASCULEGION_MALE] =
    {
        BASCULEGION_MISC_INFO,
        .baseHP        = 120,
        .baseAttack    = 112,
        .baseDefense   = 65,
        .baseSpeed     = 78,
        .baseSpAttack  = 80,
        .baseSpDefense = 75,
        .genderRatio = MON_MALE,
        .description = POKEDEX_DESC_STRING(
            "Clads itself in the souls of comrades that\n"
            "perished before fulfilling their goals of\n"
            "journeying upstream. No other species in\n"
            "all Hisui's rivers is Basculegion's equal."),
        FRONT_PIC(BasculegionMale, 64, 64),
        BACK_PIC(BasculegionMale, 64, 64),
        PALETTES(BasculegionMale),
        ICON(BasculegionMale, 1),
    },

    [SPECIES_BASCULEGION_FEMALE] =
    {
        BASCULEGION_MISC_INFO,
        .baseHP        = 120,
        .baseAttack    = 92,
        .baseDefense   = 65,
        .baseSpeed     = 78,
        .baseSpAttack  = 100,
        .baseSpDefense = 75,
        .genderRatio = MON_FEMALE,
        .description = POKEDEX_DESC_STRING(
            "The souls of its comrades cloak its\n"
            "body and propel it effortlessly\n"
            "through even raging rapids."),
        FRONT_PIC(BasculegionFemale, 64, 64),
        BACK_PIC(BasculegionFemale, 64, 64),
        PALETTES(BasculegionFemale),
        ICON(BasculegionFemale, 0),
    },
#endif //P_HISUIAN_FORMS
#endif //P_FAMILY_BASCULIN

#if P_FAMILY_SANDILE
    [SPECIES_SANDILE] =
    {
        .baseHP        = 50,
        .baseAttack    = 72,
        .baseDefense   = 35,
        .baseSpeed     = 65,
        .baseSpAttack  = 35,
        .baseSpDefense = 35,
        .types = { TYPE_GROUND, TYPE_DARK },
        .catchRate = 180,
        .expYield = 58,
        .evYield_Attack = 1,
        .itemRare = ITEM_BLACK_GLASSES,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD },
        .abilities = { ABILITY_INTIMIDATE, ABILITY_MOXIE, ABILITY_ANGER_POINT },
        .bodyColor = BODY_COLOR_BROWN,
        .speciesName = _("Ganovil"),
        .cryId = CRY_SANDILE,
        .natDexNum = NATIONAL_DEX_SANDILE,
        .categoryName = _("Wüstenkroko"),
        .height = 7,
        .weight = 152,
        .description = POKEDEX_DESC_STRING(
            "Da die Wüste nachts abkühlt, vergräbt es\n"
            "sich tief im Sand und schläft dort, bis\n"
            "die Sonne wieder aufgeht."),
        .pokemonScale = 365,
        .pokemonOffset = 14,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Sandile, 48, 32),
        .frontPicYOffset = 18,
        .frontAnimFrames = sAnims_Sandile,
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(Sandile, 64, 32),
        .backPicYOffset = 18,
        .backAnimId = BACK_ANIM_H_SLIDE,
        PALETTES(Sandile),
        ICON(Sandile, 1),
        .footprint = gMonFootprint_Sandile,
        LEARNSETS(Sandile),
        .evolutions = EVOLUTION({EVO_LEVEL, 29, SPECIES_KROKOROK}),
    },

    [SPECIES_KROKOROK] =
    {
        .baseHP        = 60,
        .baseAttack    = 82,
        .baseDefense   = 45,
        .baseSpeed     = 74,
        .baseSpAttack  = 45,
        .baseSpDefense = 45,
        .types = { TYPE_GROUND, TYPE_DARK },
        .catchRate = 90,
        .expYield = 123,
        .evYield_Attack = 2,
        .itemRare = ITEM_BLACK_GLASSES,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD },
        .abilities = { ABILITY_INTIMIDATE, ABILITY_MOXIE, ABILITY_ANGER_POINT },
        .bodyColor = BODY_COLOR_BROWN,
        .speciesName = _("Rokkaiman"),
        .cryId = CRY_KROKOROK,
        .natDexNum = NATIONAL_DEX_KROKOROK,
        .categoryName = _("Wüstenkroko"),
        .height = 10,
        .weight = 334,
        .description = POKEDEX_DESC_STRING(
            "Die spezielle Membran um seine Augen\n"
            "fungiert als Wärmesensor, durch den es\n"
            "sich auch im Dunkeln zurechtfindet."),
        .pokemonScale = 305,
        .pokemonOffset = 7,
        .trainerScale = 257,
        .trainerOffset = 0,
        FRONT_PIC(Krokorok, 64, 56),
        .frontPicYOffset = 4,
        .frontAnimFrames = sAnims_Krokorok,
        .frontAnimId = ANIM_V_STRETCH,
        BACK_PIC(Krokorok, 56, 64),
        .backPicYOffset = 3,
        .backAnimId = BACK_ANIM_V_STRETCH,
        PALETTES(Krokorok),
        ICON(Krokorok, 1),
        .footprint = gMonFootprint_Krokorok,
        LEARNSETS(Krokorok),
        .evolutions = EVOLUTION({EVO_LEVEL, 40, SPECIES_KROOKODILE}),
    },

    [SPECIES_KROOKODILE] =
    {
        .baseHP        = 95,
        .baseAttack    = 117,
        .baseDefense   = P_UPDATED_STATS >= GEN_6 ? 80 : 70,
        .baseSpeed     = 92,
        .baseSpAttack  = 65,
        .baseSpDefense = 70,
        .types = { TYPE_GROUND, TYPE_DARK },
        .catchRate = 45,
        .expYield = 234,
        .evYield_Attack = 3,
        .itemCommon = ITEM_BLACK_GLASSES,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD },
        .abilities = { ABILITY_INTIMIDATE, ABILITY_MOXIE, ABILITY_ANGER_POINT },
        .bodyColor = BODY_COLOR_RED,
        .speciesName = _("Rabigator"),
        .cryId = CRY_KROOKODILE,
        .natDexNum = NATIONAL_DEX_KROOKODILE,
        .categoryName = _("Abschreckungs"),
        .height = 15,
        .weight = 963,
        .description = POKEDEX_DESC_STRING(
            "Hat es seine Beute erblickt, gibt es kein\n"
            "Entrinnen mehr. Sein mächtiger Kiefer\n"
            "knackt selbst Karosserien."),
        .pokemonScale = 268,
        .pokemonOffset = 2,
        .trainerScale = 271,
        .trainerOffset = 0,
        FRONT_PIC(Krookodile, 64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_Krookodile,
        .frontAnimId = ANIM_SWING_CONCAVE_FAST_SHORT,
        BACK_PIC(Krookodile, 64, 56),
        .backPicYOffset = 6,
        .backAnimId = BACK_ANIM_V_SHAKE_LOW,
        PALETTES(Krookodile),
        ICON(Krookodile, 0),
        .footprint = gMonFootprint_Krookodile,
        LEARNSETS(Krookodile),
    },
#endif //P_FAMILY_SANDILE

#if P_FAMILY_DARUMAKA
#define DARUMAKA_MISC_INFO                                                  \
        .baseHP        = 70,                                                \
        .baseAttack    = 90,                                                \
        .baseDefense   = 45,                                                \
        .baseSpeed     = 50,                                                \
        .baseSpAttack  = 15,                                                \
        .baseSpDefense = 45,                                                \
        .catchRate = 120,                                                   \
        .expYield = 63,                                                     \
        .evYield_Attack = 1,                                                \
        .genderRatio = PERCENT_FEMALE(50),                                  \
        .eggCycles = 20,                                                    \
        .friendship = STANDARD_FRIENDSHIP,                                  \
        .growthRate = GROWTH_MEDIUM_SLOW,                                   \
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD },                  \
        .abilities = { ABILITY_HUSTLE, ABILITY_NONE, ABILITY_INNER_FOCUS }, \
        .speciesName = _("Rabigator"),                                       \
        .cryId = CRY_DARUMAKA,                                              \
        .natDexNum = NATIONAL_DEX_DARUMAKA,                                 \
        .categoryName = _("Abschreckungs"),                                     \
        .footprint = gMonFootprint_Darumaka,                                \
        .formSpeciesIdTable = sDarumakaFormSpeciesIdTable

    [SPECIES_DARUMAKA] =
    {
        DARUMAKA_MISC_INFO,
        .types = { TYPE_FIRE, TYPE_FIRE },
        .bodyColor = BODY_COLOR_RED,
        .height = 6,
        .weight = 375,
        .description = POKEDEX_DESC_STRING(
            "Früher nutzte man die heißen\n"
            "Ausscheidungen von Flampion, um\n"
            "sich den Körper zu wärmen."),
        .pokemonScale = 422,
        .pokemonOffset = 14,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Darumaka, 40, 40),
        .frontPicYOffset = 13,
        .frontAnimFrames = sAnims_Darumaka,
        .frontAnimId = ANIM_SWING_CONCAVE,
        BACK_PIC(Darumaka, 56, 48),
        .backPicYOffset = 12,
        .backAnimId = BACK_ANIM_CONCAVE_ARC_LARGE,
        PALETTES(Darumaka),
        ICON(Darumaka, 0),
        LEARNSETS(Darumaka),
        .evolutions = EVOLUTION({EVO_LEVEL, 35, SPECIES_DARMANITAN_STANDARD_MODE}),
    },

#define DARMANITAN_MISC_INFO                                \
        .catchRate = 60,                                    \
        .genderRatio = PERCENT_FEMALE(50),                  \
        .eggCycles = 20,                                    \
        .friendship = STANDARD_FRIENDSHIP,                  \
        .growthRate = GROWTH_MEDIUM_SLOW,                   \
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD },  \
        .speciesName = _("Flampion"),                     \
        .cryId = CRY_DARMANITAN,                            \
        .natDexNum = NATIONAL_DEX_DARMANITAN,               \
        .footprint = gMonFootprint_Darmanitan,              \
        .formSpeciesIdTable = sDarmanitanFormSpeciesIdTable

#define DARMANITAN_STANDARD_MISC_INFO   \
        .baseHP        = 105,           \
        .baseAttack    = 140,           \
        .baseDefense   = 55,            \
        .baseSpeed     = 95,            \
        .baseSpAttack  = 30,            \
        .baseSpDefense = 55,            \
        .expYield = 168,                \
        .evYield_Attack = 2,            \
        DARMANITAN_MISC_INFO

#define DARMANITAN_ZEN_MODE_MISC_INFO   \
        .expYield = 189,                \
        .evYield_SpAttack = 2,          \
        .categoryName = _("Lampion"),   \
        DARMANITAN_MISC_INFO

#define DARMANITAN_UNOVAN_MISC_INFO                                         \
        .abilities = { ABILITY_SHEER_FORCE, ABILITY_NONE, ABILITY_ZEN_MODE },\
        .height = 13,                                                       \
        .weight = 929,                                                      \
        .pokemonScale = 272,                                                \
        .pokemonOffset = 3,                                                 \
        .trainerScale = 256,                                                \
        .trainerOffset = 0,                                                 \
        LEARNSETS(Darmanitan),                                              \
        .formChangeTable = sDarmanitanFormChangeTable

    [SPECIES_DARMANITAN_STANDARD_MODE] =
    {
        DARMANITAN_STANDARD_MISC_INFO,
        DARMANITAN_UNOVAN_MISC_INFO,
        .types = { TYPE_FIRE, TYPE_FIRE },
        .bodyColor = BODY_COLOR_RED,
        .categoryName = _("Lichterloh"),
        .description = POKEDEX_DESC_STRING(
            "Erhitzt das Innere seines Körpers auf 1\n"
            "400 Grad C und erlangt so die Kraft, um mit\n"
            "der Faust Laster zu zerstören."),
        FRONT_PIC(DarmanitanStandardMode, 56, 64),
        .frontPicYOffset = 2,
        .frontAnimFrames = sAnims_DarmanitanStandardMode,
        .frontAnimId = ANIM_CIRCULAR_STRETCH_TWICE,
        BACK_PIC(DarmanitanStandardMode, 64, 64),
        .backPicYOffset = 2,
        .backAnimId = BACK_ANIM_V_SHAKE_H_SLIDE,
        PALETTES(DarmanitanStandardMode),
        ICON(DarmanitanStandardMode, 0),
    },

    [SPECIES_DARMANITAN_ZEN_MODE] =
    {
        DARMANITAN_ZEN_MODE_MISC_INFO,
        DARMANITAN_UNOVAN_MISC_INFO,
        .baseHP        = 105,
        .baseAttack    = 30,
        .baseDefense   = 105,
        .baseSpeed     = 55,
        .baseSpAttack  = 140,
        .baseSpDefense = 105,
        .types = { TYPE_FIRE, TYPE_PSYCHIC },
        .bodyColor = BODY_COLOR_BLUE,
        .description = POKEDEX_DESC_STRING(
            "Nimmt es in einem heißen Kampf\n"
            "Schaden, wird es hart wie Stein und\n"
            "fällt in eine Trance, um seinen\n"
            "Verstand zu schärfen."),
        FRONT_PIC(DarmanitanZenMode, 40, 40),
        .frontPicYOffset = 14,
        .frontAnimFrames = sAnims_DarmanitanZenMode,
        .frontAnimId = ANIM_GROW_VIBRATE,
        BACK_PIC(DarmanitanZenMode, 56, 48),
        .backPicYOffset = 11,
        .backAnimId = BACK_ANIM_H_SHAKE,
        PALETTES(DarmanitanZenMode),
        ICON(DarmanitanZenMode, 0),
    },

#if P_GALARIAN_FORMS
    [SPECIES_DARUMAKA_GALAR] =
    {
        DARUMAKA_MISC_INFO,
        .types = { TYPE_ICE, TYPE_ICE },
        .bodyColor = BODY_COLOR_WHITE,
        .height = 7,
        .weight = 400,
        .description = POKEDEX_DESC_STRING(
            "Früher nutzte man die heißen\n"
            "Ausscheidungen von Flampion, um\n"
            "sich den Körper zu wärmen."),
        .pokemonScale = 422,
        .pokemonOffset = 14,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(DarumakaGalarian, 40, 40),
        .frontPicYOffset = 15,
        .frontAnimFrames = sAnims_DarumakaGalarian,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(DarumakaGalarian, 56, 48),
        .backPicYOffset = 11,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(DarumakaGalarian),
        ICON(DarumakaGalarian, 0),
        LEARNSETS(DarumakaGalarian),
        .isGalarianForm = TRUE,
        .evolutions = EVOLUTION({EVO_ITEM, ITEM_ICE_STONE, SPECIES_DARMANITAN_GALARIAN_STANDARD_MODE}),
    },

#define DARMANITAN_GALARIAN_MISC_INFO                                           \
        .abilities = { ABILITY_GORILLA_TACTICS, ABILITY_NONE, ABILITY_ZEN_MODE },\
        .bodyColor = BODY_COLOR_WHITE,                                          \
        .height = 17,                                                           \
        .weight = 1200,                                                         \
        .pokemonScale = 272,                                                    \
        .pokemonOffset = 3,                                                     \
        .trainerScale = 256,                                                    \
        .trainerOffset = 0,                                                     \
        LEARNSETS(DarmanitanGalarian),                                          \
        .formChangeTable = sDarmanitanGalarianFormChangeTable,                  \
        .isGalarianForm = TRUE

    [SPECIES_DARMANITAN_GALARIAN_STANDARD_MODE] =
    {
        DARMANITAN_GALARIAN_MISC_INFO,
        DARMANITAN_STANDARD_MISC_INFO,
        .types = { TYPE_ICE, TYPE_ICE },
        .categoryName = _("Lichterloh"),
        .description = POKEDEX_DESC_STRING(
            "Nimmt es in einem heißen Kampf\n"
            "Schaden, wird es hart wie Stein und\n"
            "fällt in eine Trance, um seinen\n"
            "Verstand zu schärfen."),
        FRONT_PIC(DarmanitanGalarianStandardMode, 56, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_DarmanitanGalarianStandardMode,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(DarmanitanGalarianStandardMode, 56, 64),
        .backPicYOffset = 2,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(DarmanitanGalarianStandardMode),
        ICON(DarmanitanGalarianStandardMode, 0),
    },

    [SPECIES_DARMANITAN_GALARIAN_ZEN_MODE] =
    {
        DARMANITAN_GALARIAN_MISC_INFO,
        DARMANITAN_ZEN_MODE_MISC_INFO,
        .baseHP        = 105,
        .baseAttack    = 160,
        .baseDefense   = 55,
        .baseSpeed     = 135,
        .baseSpAttack  = 30,
        .baseSpDefense = 55,
        .types = { TYPE_ICE, TYPE_FIRE },
        .description = POKEDEX_DESC_STRING(
            "Nimmt es in einem heißen Kampf\n"
            "Schaden, wird es hart wie Stein und\n"
            "fällt in eine Trance, um seinen\n"
            "Verstand zu schärfen."),
        FRONT_PIC(DarmanitanGalarianZenMode, 48, 64),
        .frontPicYOffset = 2,
        .frontAnimFrames = sAnims_DarmanitanGalarianZenMode,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(DarmanitanGalarianZenMode, 64, 64),
        .backPicYOffset = 1,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(DarmanitanGalarianZenMode),
        ICON(DarmanitanGalarianZenMode, 0),
    },
#endif //P_GALARIAN_FORMS
#endif //P_FAMILY_DARUMAKA

#if P_FAMILY_MARACTUS
    [SPECIES_MARACTUS] =
    {
        .baseHP        = 75,
        .baseAttack    = 86,
        .baseDefense   = 67,
        .baseSpeed     = 60,
        .baseSpAttack  = 106,
        .baseSpDefense = 67,
        .types = { TYPE_GRASS, TYPE_GRASS },
        .catchRate = 255,
        .expYield = 161,
        .evYield_SpAttack = 2,
        .itemRare = ITEM_MIRACLE_SEED,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_GRASS, EGG_GROUP_GRASS },
        .abilities = { ABILITY_WATER_ABSORB, ABILITY_CHLOROPHYLL, ABILITY_STORM_DRAIN },
        .bodyColor = BODY_COLOR_GREEN,
        .speciesName = _("Maracamba"),
        .cryId = CRY_MARACTUS,
        .natDexNum = NATIONAL_DEX_MARACTUS,
        .categoryName = _("Kaktus"),
        .height = 10,
        .weight = 280,
        .description = POKEDEX_DESC_STRING(
            "Verjagt Vogel-Pokémon, die auf\n"
            "seine Blüten aus sind, mit einem\n"
            "flotten Tänzchen und lauter\n"
            "Untermalung."),
        .pokemonScale = 305,
        .pokemonOffset = 6,
        .trainerScale = 257,
        .trainerOffset = 0,
        FRONT_PIC(Maractus, 56, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_Maractus,
        .frontAnimId = ANIM_H_JUMPS_V_STRETCH,
        BACK_PIC(Maractus, 64, 64),
        .backPicYOffset = 2,
        .backAnimId = BACK_ANIM_CONCAVE_ARC_LARGE,
        PALETTES(Maractus),
        ICON(Maractus, 1),
        .footprint = gMonFootprint_Maractus,
        LEARNSETS(Maractus),
    },
#endif //P_FAMILY_MARACTUS

#if P_FAMILY_DWEBBLE
    [SPECIES_DWEBBLE] =
    {
        .baseHP        = 50,
        .baseAttack    = 65,
        .baseDefense   = 85,
        .baseSpeed     = 55,
        .baseSpAttack  = 35,
        .baseSpDefense = 35,
        .types = { TYPE_BUG, TYPE_ROCK },
        .catchRate = 190,
        .expYield = 65,
        .evYield_Defense = 1,
        .itemRare = ITEM_HARD_STONE,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_BUG, EGG_GROUP_MINERAL },
        .abilities = { ABILITY_STURDY, ABILITY_SHELL_ARMOR, ABILITY_WEAK_ARMOR },
        .bodyColor = BODY_COLOR_RED,
        .speciesName = _("Lithomith"),
        .cryId = CRY_DWEBBLE,
        .natDexNum = NATIONAL_DEX_DWEBBLE,
        .categoryName = _("Steinhaus"),
        .height = 3,
        .weight = 145,
        .description = POKEDEX_DESC_STRING(
            "Sobald es einen angemessen großen Stein\n"
            "findet, höhlt es ihn mit einem ätzenden\n"
            "Sekret aus und kriecht hinein."),
        .pokemonScale = 530,
        .pokemonOffset = 15,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Dwebble, 40, 40),
        .frontPicYOffset = 14,
        .frontAnimFrames = sAnims_Dwebble,
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(Dwebble, 56, 32),
        .backPicYOffset = 17,
        .backAnimId = BACK_ANIM_H_SLIDE,
        PALETTES(Dwebble),
        ICON(Dwebble, 0),
        .footprint = gMonFootprint_Dwebble,
        LEARNSETS(Dwebble),
        .evolutions = EVOLUTION({EVO_LEVEL, 34, SPECIES_CRUSTLE}),
    },

    [SPECIES_CRUSTLE] =
    {
        .baseHP        = 70,
        .baseAttack    = P_UPDATED_STATS >= GEN_7 ? 105 : 95,
        .baseDefense   = 125,
        .baseSpeed     = 45,
        .baseSpAttack  = 65,
        .baseSpDefense = 75,
        .types = { TYPE_BUG, TYPE_ROCK },
        .catchRate = 75,
        .expYield = 170,
        .evYield_Defense = 2,
        .itemRare = ITEM_HARD_STONE,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_BUG, EGG_GROUP_MINERAL },
        .abilities = { ABILITY_STURDY, ABILITY_SHELL_ARMOR, ABILITY_WEAK_ARMOR },
        .bodyColor = BODY_COLOR_RED,
        .speciesName = _("Castellith"),
        .cryId = CRY_CRUSTLE,
        .natDexNum = NATIONAL_DEX_CRUSTLE,
        .categoryName = _("Felshaus"),
        .height = 14,
        .weight = 2000,
        .description = POKEDEX_DESC_STRING(
            "Revierkonflikte führen oft zu heftigen\n"
            "Kämpfen zwischen ihnen. Gewonnen hat, wer\n"
            "das gegnerische Haus zerstört."),
        .pokemonScale = 265,
        .pokemonOffset = 2,
        .trainerScale = 262,
        .trainerOffset = 0,
        FRONT_PIC(Crustle, 64, 64),
        .frontPicYOffset = 2,
        .frontAnimFrames = sAnims_Crustle,
        .frontAnimId = ANIM_H_SLIDE_SLOW,
        BACK_PIC(Crustle, 64, 56),
        .backPicYOffset = 9,
        .backAnimId = BACK_ANIM_V_SHAKE_LOW,
        PALETTES(Crustle),
        ICON(Crustle, 2),
        .footprint = gMonFootprint_Crustle,
        LEARNSETS(Crustle),
    },
#endif //P_FAMILY_DWEBBLE

#if P_FAMILY_SCRAGGY
    [SPECIES_SCRAGGY] =
    {
        .baseHP        = 50,
        .baseAttack    = 75,
        .baseDefense   = 70,
        .baseSpeed     = 48,
        .baseSpAttack  = 35,
        .baseSpDefense = 70,
        .types = { TYPE_DARK, TYPE_FIGHTING },
        .catchRate = 180,
        .expYield = 70,
        .evYield_Attack = 1,
        .itemRare = ITEM_SHED_SHELL,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = 35,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_DRAGON },
        .abilities = { ABILITY_SHED_SKIN, ABILITY_MOXIE, ABILITY_INTIMIDATE },
        .bodyColor = BODY_COLOR_YELLOW,
        .speciesName = _("Zurrokex"),
        .cryId = CRY_SCRAGGY,
        .natDexNum = NATIONAL_DEX_SCRAGGY,
        .categoryName = _("Hautwechsel"),
        .height = 6,
        .weight = 118,
        .description = POKEDEX_DESC_STRING(
            "Zurrokex deuten Blickkontakt als\n"
            "Einladung, ihr Gegenüber mit Kopfnüssen\n"
            "anzugreifen. Vorsicht ist also geboten."),
        .pokemonScale = 422,
        .pokemonOffset = 14,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Scraggy, 40, 48),
        .frontPicYOffset = 11,
        .frontAnimFrames = sAnims_Scraggy,
        .frontAnimId = ANIM_V_STRETCH,
        BACK_PIC(Scraggy, 48, 56),
        .backPicYOffset = 7,
        .backAnimId = BACK_ANIM_CONCAVE_ARC_LARGE,
        PALETTES(Scraggy),
        ICON(Scraggy, 2),
        .footprint = gMonFootprint_Scraggy,
        LEARNSETS(Scraggy),
        .evolutions = EVOLUTION({EVO_LEVEL, 39, SPECIES_SCRAFTY}),
    },

    [SPECIES_SCRAFTY] =
    {
        .baseHP        = 65,
        .baseAttack    = 90,
        .baseDefense   = 115,
        .baseSpeed     = 58,
        .baseSpAttack  = 45,
        .baseSpDefense = 115,
        .types = { TYPE_DARK, TYPE_FIGHTING },
        .catchRate = 90,
        .expYield = 171,
        .evYield_Defense = 1,
        .evYield_SpDefense = 1,
        .itemRare = ITEM_SHED_SHELL,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_DRAGON },
        .abilities = { ABILITY_SHED_SKIN, ABILITY_MOXIE, ABILITY_INTIMIDATE },
        .bodyColor = BODY_COLOR_RED,
        .speciesName = _("Irokex"),
        .cryId = CRY_SCRAFTY,
        .natDexNum = NATIONAL_DEX_SCRAFTY,
        .categoryName = _("Halunken"),
        .height = 11,
        .weight = 300,
        .description = POKEDEX_DESC_STRING(
            "Diesem ungestümen Pokémon liegen Freunde,\n"
            "Familie und Revier sehr am Herzen."),
        .pokemonScale = 320,
        .pokemonOffset = 7,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Scrafty, 48, 56),
        .frontPicYOffset = 4,
        .frontAnimFrames = sAnims_Scrafty,
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(Scrafty, 48, 64),
        .backPicYOffset = 5,
        .backAnimId = BACK_ANIM_GROW,
        PALETTES(Scrafty),
        ICON(Scrafty, 0),
        .footprint = gMonFootprint_Scrafty,
        LEARNSETS(Scrafty),
    },
#endif //P_FAMILY_SCRAGGY

#if P_FAMILY_SIGILYPH
    [SPECIES_SIGILYPH] =
    {
        .baseHP        = 72,
        .baseAttack    = 58,
        .baseDefense   = 80,
        .baseSpeed     = 97,
        .baseSpAttack  = 103,
        .baseSpDefense = 80,
        .types = { TYPE_PSYCHIC, TYPE_FLYING },
        .catchRate = 45,
        .expYield = 172,
        .evYield_SpAttack = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_FLYING, EGG_GROUP_FLYING },
        .abilities = { ABILITY_WONDER_SKIN, ABILITY_MAGIC_GUARD, ABILITY_TINTED_LENS },
        .bodyColor = BODY_COLOR_BLACK,
        .speciesName = _("Symvolara"),
        .cryId = CRY_SIGILYPH,
        .natDexNum = NATIONAL_DEX_SIGILYPH,
        .categoryName = _("Vogelgleich"),
        .height = 14,
        .weight = 140,
        .description = POKEDEX_DESC_STRING(
            "Vor langer Zeit war es der Wächter einer\n"
            "Stadt. Es fliegt auf der Suche nach\n"
            "Eindringlingen immer dieselbe Route ab."),
        .pokemonScale = 265,
        .pokemonOffset = 2,
        .trainerScale = 262,
        .trainerOffset = 0,
        FRONT_PIC(Sigilyph, 64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_Sigilyph,
        .frontAnimId = ANIM_FIGURE_8,
        .enemyMonElevation = 7,
        BACK_PIC(Sigilyph, 64, 64),
        .backPicYOffset = 7,
        .backAnimId = BACK_ANIM_TRIANGLE_DOWN,
        PALETTES(Sigilyph),
        ICON(Sigilyph, 0),
        .footprint = gMonFootprint_Sigilyph,
        LEARNSETS(Sigilyph),
    },
#endif //P_FAMILY_SIGILYPH

#if P_FAMILY_YAMASK
#define YAMASK_MISC_INFO                                            \
        .catchRate = 190,                                           \
        .expYield = 61,                                             \
        .evYield_Defense = 1,                                       \
        .genderRatio = PERCENT_FEMALE(50),                          \
        .eggCycles = 25,                                            \
        .friendship = STANDARD_FRIENDSHIP,                          \
        .growthRate = GROWTH_MEDIUM_FAST,                           \
        .eggGroups = { EGG_GROUP_MINERAL, EGG_GROUP_AMORPHOUS },    \
        .bodyColor = BODY_COLOR_BLACK,                              \
        .speciesName = _("Symvolara"),                                 \
        .cryId = CRY_YAMASK,                                        \
        .natDexNum = NATIONAL_DEX_YAMASK,                           \
        .categoryName = _("Vogelgleich"),                                \
        .height = 5,                                                \
        .weight = 15,                                               \
        .pokemonScale = 432,                                        \
        .pokemonOffset = 13,                                        \
        .trainerScale = 256,                                        \
        .trainerOffset = 0,                                         \
        .footprint = gMonFootprint_Yamask,                          \
        .formSpeciesIdTable = sYamaskFormSpeciesIdTable

    [SPECIES_YAMASK] =
    {
        YAMASK_MISC_INFO,
        .baseHP        = 38,
        .baseAttack    = 30,
        .baseDefense   = 85,
        .baseSpeed     = 30,
        .baseSpAttack  = 55,
        .baseSpDefense = 65,
        .types = { TYPE_GHOST, TYPE_GHOST },
        .itemRare = ITEM_SPELL_TAG,
        .abilities = { ABILITY_MUMMY, ABILITY_NONE },
        .description = POKEDEX_DESC_STRING(
            "Es entsteht aus den Seelen von\n"
            "längst begrabenen Menschen und kann\n"
            "sich immer noch an deren\n"
            "Vergangenheit erinnern."),
        FRONT_PIC(Yamask, 48, 40),
        .frontPicYOffset = 15,
        .frontAnimFrames = sAnims_Yamask,
        .frontAnimId = ANIM_V_SLIDE_WOBBLE,
        .enemyMonElevation = 10,
        BACK_PIC(Yamask, 40, 40),
        .backPicYOffset = 14,
        .backAnimId = BACK_ANIM_V_SHAKE,
        PALETTES(Yamask),
        ICON(Yamask, 0),
        LEARNSETS(Yamask),
        .evolutions = EVOLUTION({EVO_LEVEL, 34, SPECIES_COFAGRIGUS}),
    },

    [SPECIES_COFAGRIGUS] =
    {
        .baseHP        = 58,
        .baseAttack    = 50,
        .baseDefense   = 145,
        .baseSpeed     = 30,
        .baseSpAttack  = 95,
        .baseSpDefense = 105,
        .types = { TYPE_GHOST, TYPE_GHOST },
        .catchRate = 90,
        .expYield = 169,
        .evYield_Defense = 2,
        .itemRare = ITEM_SPELL_TAG,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 25,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_MINERAL, EGG_GROUP_AMORPHOUS },
        .abilities = { ABILITY_MUMMY, ABILITY_NONE },
        .bodyColor = BODY_COLOR_YELLOW,
        .speciesName = _("Echnatoll"),
        .cryId = CRY_COFAGRIGUS,
        .natDexNum = NATIONAL_DEX_COFAGRIGUS,
        .categoryName = _("Sarkophag"),
        .height = 17,
        .weight = 765,
        .description = POKEDEX_DESC_STRING(
            "Grabräuber, die es mit einem echten Sarg\n"
            "verwechseln und ihm zu nahe kommen, hält\n"
            "es im Inneren seines Körpers gefangen."),
        .pokemonScale = 259,
        .pokemonOffset = 0,
        .trainerScale = 290,
        .trainerOffset = 1,
        FRONT_PIC(Cofagrigus, 64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_Cofagrigus,
        .frontAnimId = ANIM_GLOW_BLACK,
        BACK_PIC(Cofagrigus, 56, 56),
        .backPicYOffset = 6,
        .backAnimId = BACK_ANIM_V_SHAKE_H_SLIDE,
        PALETTES(Cofagrigus),
        ICON(Cofagrigus, 0),
        .footprint = gMonFootprint_Cofagrigus,
        LEARNSETS(Cofagrigus),
    },

#if P_GALARIAN_FORMS
    [SPECIES_YAMASK_GALAR] =
    {
        YAMASK_MISC_INFO,
        .baseHP        = 38,
        .baseAttack    = 55,
        .baseDefense   = 85,
        .baseSpeed     = 30,
        .baseSpAttack  = 30,
        .baseSpDefense = 65,
        .types = { TYPE_GROUND, TYPE_GHOST },
        .abilities = { ABILITY_WANDERING_SPIRIT, ABILITY_NONE },
        .description = POKEDEX_DESC_STRING(
            "Es entsteht aus den Seelen von\n"
            "längst begrabenen Menschen und kann\n"
            "sich immer noch an deren\n"
            "Vergangenheit erinnern."),
        FRONT_PIC(YamaskGalarian, 48, 40),
        .frontPicYOffset = 13,
        .frontAnimFrames = sAnims_YamaskGalarian,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .enemyMonElevation = 4,
        BACK_PIC(YamaskGalarian, 40, 40),
        .backPicYOffset = 13,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(YamaskGalarian),
        ICON(YamaskGalarian, 2),
        LEARNSETS(YamaskGalarian),
        .isGalarianForm = TRUE,
        .evolutions = EVOLUTION({EVO_SCRIPT_TRIGGER_DMG, 49, SPECIES_RUNERIGUS}),
    },

    [SPECIES_RUNERIGUS] =
    {
        .baseHP        = 58,
        .baseAttack    = 95,
        .baseDefense   = 145,
        .baseSpeed     = 30,
        .baseSpAttack  = 50,
        .baseSpDefense = 105,
        .types = { TYPE_GROUND, TYPE_GHOST },
        .catchRate = 90,
        .expYield = 169,
        .evYield_Defense = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 25,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_MINERAL, EGG_GROUP_AMORPHOUS },
        .abilities = { ABILITY_WANDERING_SPIRIT, ABILITY_NONE },
        .bodyColor = BODY_COLOR_GRAY,
        .speciesName = _("Oghnatoll"),
        .cryId = CRY_RUNERIGUS,
        .natDexNum = NATIONAL_DEX_RUNERIGUS,
        .categoryName = _("Gram"),
        .height = 16,
        .weight = 666,
        .description = POKEDEX_DESC_STRING(
            "Man sollte seinen schattenhaften Körper\n"
            "nicht berühren, sonst zeigt es einem die\n"
            "schauerlichen Erinnerungen, die in sein\n"
            "Bild eingraviert wurden."),
        .pokemonScale = 259,
        .pokemonOffset = 1,
        .trainerScale = 296,
        .trainerOffset = 1,
        FRONT_PIC(Runerigus, 64, 64),
        .frontPicYOffset = 2,
        .frontAnimFrames = sAnims_Runerigus,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .enemyMonElevation = 5,
        BACK_PIC(Runerigus, 64, 48),
        .backPicYOffset = 9,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(Runerigus),
        ICON(Runerigus, 2),
        .footprint = gMonFootprint_Runerigus,
        LEARNSETS(Runerigus),
    },
#endif //P_GALARIAN_FORMS
#endif //P_FAMILY_YAMASK

#if P_FAMILY_TIRTOUGA
    [SPECIES_TIRTOUGA] =
    {
        .baseHP        = 54,
        .baseAttack    = 78,
        .baseDefense   = 103,
        .baseSpeed     = 22,
        .baseSpAttack  = 53,
        .baseSpDefense = 45,
        .types = { TYPE_WATER, TYPE_ROCK },
        .catchRate = 45,
        .expYield = 71,
        .evYield_Defense = 1,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 30,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_WATER_1, EGG_GROUP_WATER_3 },
        .abilities = { ABILITY_SOLID_ROCK, ABILITY_STURDY, ABILITY_SWIFT_SWIM },
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Galapaflos"),
        .cryId = CRY_TIRTOUGA,
        .natDexNum = NATIONAL_DEX_TIRTOUGA,
        .categoryName = _("Urzeitkröten"),
        .height = 7,
        .weight = 165,
        .description = POKEDEX_DESC_STRING(
            "Schwamm bereits vor 100 Millionen\n"
            "Jahren durch die Meere. Ab und zu\n"
            "führt es die Jagd auch an Land."),
        .pokemonScale = 365,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Tirtouga, 56, 40),
        .frontPicYOffset = 16,
        .frontAnimFrames = sAnims_Tirtouga,
        .frontAnimId = ANIM_RISING_WOBBLE,
        BACK_PIC(Tirtouga, 64, 32),
        .backPicYOffset = 16,
        .backAnimId = BACK_ANIM_H_SLIDE,
        PALETTES(Tirtouga),
        ICON(Tirtouga, 2),
        .footprint = gMonFootprint_Tirtouga,
        LEARNSETS(Tirtouga),
        .evolutions = EVOLUTION({EVO_LEVEL, 37, SPECIES_CARRACOSTA}),
    },

    [SPECIES_CARRACOSTA] =
    {
        .baseHP        = 74,
        .baseAttack    = 108,
        .baseDefense   = 133,
        .baseSpeed     = 32,
        .baseSpAttack  = 83,
        .baseSpDefense = 65,
        .types = { TYPE_WATER, TYPE_ROCK },
        .catchRate = 45,
        .expYield = 173,
        .evYield_Defense = 2,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 30,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_WATER_1, EGG_GROUP_WATER_3 },
        .abilities = { ABILITY_SOLID_ROCK, ABILITY_STURDY, ABILITY_SWIFT_SWIM },
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Karippas"),
        .cryId = CRY_CARRACOSTA,
        .natDexNum = NATIONAL_DEX_CARRACOSTA,
        .categoryName = _("Urzeitkröten"),
        .height = 12,
        .weight = 810,
        .description = POKEDEX_DESC_STRING(
            "Um seinen harten Panzer noch weiter zu\n"
            "verstärken, fraß es seine Beute samt\n"
            "Schale und Knochen restlos auf."),
        .pokemonScale = 282,
        .pokemonOffset = 4,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Carracosta, 64, 56),
        .frontPicYOffset = 4,
        .frontAnimFrames = sAnims_Carracosta,
        .frontAnimId = ANIM_H_SHAKE_SLOW,
        BACK_PIC(Carracosta, 64, 40),
        .backPicYOffset = 13,
        .backAnimId = BACK_ANIM_V_SHAKE_LOW,
        PALETTES(Carracosta),
        ICON(Carracosta, 2),
        .footprint = gMonFootprint_Carracosta,
        LEARNSETS(Carracosta),
    },
#endif //P_FAMILY_TIRTOUGA

#if P_FAMILY_ARCHEN
    [SPECIES_ARCHEN] =
    {
        .baseHP        = 55,
        .baseAttack    = 112,
        .baseDefense   = 45,
        .baseSpeed     = 70,
        .baseSpAttack  = 74,
        .baseSpDefense = 45,
        .types = { TYPE_ROCK, TYPE_FLYING },
        .catchRate = 45,
        .expYield = 71,
        .evYield_Attack = 1,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 30,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_FLYING, EGG_GROUP_WATER_3 },
        .abilities = { ABILITY_DEFEATIST, ABILITY_NONE },
        .bodyColor = BODY_COLOR_YELLOW,
        .speciesName = _("Flapteryx"),
        .cryId = CRY_ARCHEN,
        .natDexNum = NATIONAL_DEX_ARCHEN,
        .categoryName = _("Urzeitvogel"),
        .height = 5,
        .weight = 95,
        .description = POKEDEX_DESC_STRING(
            "Es kann nicht fliegen. Seine Beute fängt\n"
            "es, indem es von hohen Bäumen gleitet."),
        .pokemonScale = 432,
        .pokemonOffset = 13,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Archen, 56, 40),
        .frontPicYOffset = 14,
        .frontAnimFrames = sAnims_Archen,
        .frontAnimId = ANIM_V_JUMPS_SMALL,
        BACK_PIC(Archen, 64, 32),
        .backPicYOffset = 16,
        .backAnimId = BACK_ANIM_CONCAVE_ARC_SMALL,
        PALETTES(Archen),
        ICON(Archen, 0),
        .footprint = gMonFootprint_Archen,
        LEARNSETS(Archen),
        .evolutions = EVOLUTION({EVO_LEVEL, 37, SPECIES_ARCHEOPS}),
    },

    [SPECIES_ARCHEOPS] =
    {
        .baseHP        = 75,
        .baseAttack    = 140,
        .baseDefense   = 65,
        .baseSpeed     = 110,
        .baseSpAttack  = 112,
        .baseSpDefense = 65,
        .types = { TYPE_ROCK, TYPE_FLYING },
        .catchRate = 45,
        .expYield = 177,
        .evYield_Attack = 2,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 30,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_FLYING, EGG_GROUP_WATER_3 },
        .abilities = { ABILITY_DEFEATIST, ABILITY_NONE },
        .bodyColor = BODY_COLOR_YELLOW,
        .speciesName = _("Aeropteryx"),
        .cryId = CRY_ARCHEOPS,
        .natDexNum = NATIONAL_DEX_ARCHEOPS,
        .categoryName = _("Urzeitvogel"),
        .height = 14,
        .weight = 320,
        .description = POKEDEX_DESC_STRING(
            "Um abheben zu können, muss es circa 4 km\n"
            "Anlauf nehmen und dabei eine\n"
            "Geschwindigkeit von 40 km/h erreichen."),
        .pokemonScale = 265,
        .pokemonOffset = 2,
        .trainerScale = 262,
        .trainerOffset = 0,
        FRONT_PIC(Archeops, 64, 64),
        .frontPicYOffset = 4,
        .frontAnimFrames = sAnims_Archeops,
        .frontAnimId = ANIM_RISING_WOBBLE,
        .enemyMonElevation = 11,
        BACK_PIC(Archeops, 64, 40),
        .backPicYOffset = 12,
        .backAnimId = BACK_ANIM_V_STRETCH,
        PALETTES(Archeops),
        ICON(Archeops, 0),
        .footprint = gMonFootprint_Archeops,
        LEARNSETS(Archeops),
    },
#endif //P_FAMILY_ARCHEN

#if P_FAMILY_TRUBBISH
    [SPECIES_TRUBBISH] =
    {
        .baseHP        = 50,
        .baseAttack    = 50,
        .baseDefense   = 62,
        .baseSpeed     = 65,
        .baseSpAttack  = 40,
        .baseSpDefense = 62,
        .types = { TYPE_POISON, TYPE_POISON },
        .catchRate = 190,
        .expYield = 66,
        .evYield_Speed = 1,
        .itemRare = ITEM_SILK_SCARF,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_MINERAL, EGG_GROUP_MINERAL },
        .abilities = { ABILITY_STENCH, ABILITY_STICKY_HOLD, ABILITY_AFTERMATH },
        .bodyColor = BODY_COLOR_GREEN,
        .speciesName = _("Unratütox"),
        .cryId = CRY_TRUBBISH,
        .natDexNum = NATIONAL_DEX_TRUBBISH,
        .categoryName = _("Mülltüten"),
        .height = 6,
        .weight = 310,
        .description = POKEDEX_DESC_STRING(
            "Es liebt schmutzige Orte. In Alola sieht\n"
            "man oft, wie es von Sleima verfolgt wird."),
        .pokemonScale = 422,
        .pokemonOffset = 14,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Trubbish, 48, 40),
        .frontPicYOffset = 15,
        .frontAnimFrames = sAnims_Trubbish,
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(Trubbish, 48, 48),
        .backPicYOffset = 13,
        .backAnimId = BACK_ANIM_SHRINK_GROW,
        PALETTES(Trubbish),
        ICON(Trubbish, 1),
        .footprint = gMonFootprint_Trubbish,
        LEARNSETS(Trubbish),
        .evolutions = EVOLUTION({EVO_LEVEL, 36, SPECIES_GARBODOR}),
    },

#define GARBODOR_MISC_INFO                                                      \
        .baseHP        = 80,                                                    \
        .baseAttack    = 95,                                                    \
        .baseDefense   = 82,                                                    \
        .baseSpeed     = 75,                                                    \
        .baseSpAttack  = 60,                                                    \
        .baseSpDefense = 82,                                                    \
        .types = { TYPE_POISON, TYPE_POISON },                                  \
        .catchRate = 60,                                                        \
        .expYield = 166,                                                        \
        .evYield_Attack = 2,                                                    \
        .itemCommon = ITEM_SILK_SCARF,                                          \
        .itemRare = ITEM_BLACK_SLUDGE,                                          \
        .genderRatio = PERCENT_FEMALE(50),                                      \
        .eggCycles = 20,                                                        \
        .friendship = STANDARD_FRIENDSHIP,                                      \
        .growthRate = GROWTH_MEDIUM_FAST,                                       \
        .eggGroups = { EGG_GROUP_MINERAL, EGG_GROUP_MINERAL },                  \
        .abilities = { ABILITY_STENCH, ABILITY_WEAK_ARMOR, ABILITY_AFTERMATH }, \
        .bodyColor = BODY_COLOR_GREEN,                                          \
        .noFlip = TRUE,                                                         \
        .speciesName = _("Unratütox"),                                           \
        .cryId = CRY_GARBODOR,                                                  \
        .natDexNum = NATIONAL_DEX_GARBODOR,                                     \
        .categoryName = _("Mülltüten"),                                        \
        .footprint = gMonFootprint_Garbodor,                                    \
        LEARNSETS(Garbodor),                                                    \
        .formSpeciesIdTable = sGarbodorFormSpeciesIdTable,                      \
        .formChangeTable = sGarbodorFormChangeTable

    [SPECIES_GARBODOR] =
    {
        GARBODOR_MISC_INFO,
        .height = 19,
        .weight = 1073,
        .description = POKEDEX_DESC_STRING(
            "Es nimmt mit dem rechten Arm Gegner\n"
            "in die Mangel und gibt ihnen mit\n"
            "dem giftigen Gas aus seinem Maul\n"
            "den Rest."),
        .pokemonScale = 256,
        .pokemonOffset = 1,
        .trainerScale = 326,
        .trainerOffset = 4,
        FRONT_PIC(Garbodor, 64, 64),
        .frontPicYOffset = 4,
        .frontAnimFrames = sAnims_Garbodor,
        .frontAnimId = ANIM_V_STRETCH,
        BACK_PIC(Garbodor, 64, 64),
        .backPicYOffset = 5,
        .backAnimId = BACK_ANIM_H_STRETCH,
        PALETTES(Garbodor),
        ICON(Garbodor, 1),
    },

#if P_GIGANTAMAX_FORMS
    [SPECIES_GARBODOR_GIGANTAMAX] =
    {
        GARBODOR_MISC_INFO,
        .height = 210,
        .weight = 0,
        .description = POKEDEX_DESC_STRING(
            "Es nimmt mit dem rechten Arm Gegner\n"
            "in die Mangel und gibt ihnen mit\n"
            "dem giftigen Gas aus seinem Maul\n"
            "den Rest."),
        .pokemonScale = 256,
        .pokemonOffset = 1,
        .trainerScale = 326,
        .trainerOffset = 4,
        FRONT_PIC(GarbodorGigantamax, 64, 64),
        .frontPicYOffset = 2,
        .frontAnimFrames = sAnims_GarbodorGigantamax,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(GarbodorGigantamax, 64, 64),
        .backPicYOffset = 2,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(GarbodorGigantamax),
        ICON(GarbodorGigantamax, 0),
        .isGigantamax = TRUE,
    },
#endif //P_GIGANTAMAX_FORMS
#endif //P_FAMILY_TRUBBISH

#if P_FAMILY_ZORUA
#define ZORUA_MISC_INFO                                     \
        .catchRate = 75,                                    \
        .expYield = 66,                                     \
        .evYield_SpAttack = 1,                              \
        .genderRatio = PERCENT_FEMALE(12.5),                \
        .eggCycles = 25,                                    \
        .friendship = STANDARD_FRIENDSHIP,                  \
        .growthRate = GROWTH_MEDIUM_SLOW,                   \
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD },  \
        .abilities = { ABILITY_ILLUSION, ABILITY_NONE },    \
        .bodyColor = BODY_COLOR_GRAY,                       \
        .speciesName = _("Deponitox"),                          \
        .cryId = CRY_ZORUA,                                 \
        .natDexNum = NATIONAL_DEX_ZORUA,                    \
        .height = 7,                                        \
        .weight = 125,                                      \
        .pokemonScale = 365,                                \
        .pokemonOffset = 12,                                \
        .trainerScale = 256,                                \
        .trainerOffset = 0,                                 \
        .footprint = gMonFootprint_Zorua,                   \
        .formSpeciesIdTable = sZoruaFormSpeciesIdTable

#define ZOROARK_MISC_INFO                                   \
        .catchRate = 45,                                    \
        .expYield = 179,                                    \
        .evYield_SpAttack = 2,                              \
        .genderRatio = PERCENT_FEMALE(12.5),                \
        .eggCycles = 20,                                    \
        .friendship = STANDARD_FRIENDSHIP,                  \
        .growthRate = GROWTH_MEDIUM_SLOW,                   \
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD },  \
        .abilities = { ABILITY_ILLUSION, ABILITY_NONE },    \
        .bodyColor = BODY_COLOR_GRAY,                       \
        .speciesName = _("Deponitox"),                        \
        .cryId = CRY_ZOROARK,                               \
        .natDexNum = NATIONAL_DEX_ZOROARK,                  \
        .height = 16,                                       \
        .pokemonScale = 259,                                \
        .pokemonOffset = 1,                                 \
        .trainerScale = 296,                                \
        .trainerOffset = 1,                                 \
        .footprint = gMonFootprint_Zoroark,                 \
        .formSpeciesIdTable = sZoroarkFormSpeciesIdTable

    [SPECIES_ZORUA] =
    {
        ZORUA_MISC_INFO,
        .baseHP        = 40,
        .baseAttack    = 65,
        .baseDefense   = 40,
        .baseSpeed     = 65,
        .baseSpAttack  = 80,
        .baseSpDefense = 40,
        .types = { TYPE_DARK, TYPE_DARK },
        .categoryName = _("Polymorfuchs"),
        .description = POKEDEX_DESC_STRING(
            "Kann auf einen Schlag große Massen von\n"
            "Menschen täuschen. Es kreiert Illusionen,\n"
            "um sein Revier zu schützen."),
        FRONT_PIC(Zorua, 40, 48),
        .frontPicYOffset = 11,
        .frontAnimFrames = sAnims_Zorua,
        .frontAnimId = ANIM_CIRCULAR_VIBRATE,
        BACK_PIC(Zorua, 64, 56),
        .backPicYOffset = 7,
        .backAnimId = BACK_ANIM_CONCAVE_ARC_SMALL,
        PALETTES(Zorua),
        ICON(Zorua, 0),
        LEARNSETS(Zorua),
        .evolutions = EVOLUTION({EVO_LEVEL, 30, SPECIES_ZOROARK}),
    },

    [SPECIES_ZOROARK] =
    {
        ZOROARK_MISC_INFO,
        .baseHP        = 60,
        .baseAttack    = 105,
        .baseDefense   = 60,
        .baseSpeed     = 105,
        .baseSpAttack  = 120,
        .baseSpDefense = 60,
        .types = { TYPE_DARK, TYPE_DARK },
        .categoryName = _("Polymorfuchs"),
        .weight = 811,
        .description = POKEDEX_DESC_STRING(
            "Kann auf einen Schlag große Massen\n"
            "von Menschen täuschen. Es kreiert\n"
            "Illusionen, um sein Revier zu\n"
            "schützen."),
        FRONT_PIC(Zoroark, 64, 64),
        .frontPicYOffset = 2,
        .frontAnimFrames = sAnims_Zoroark,
        .frontAnimId = ANIM_FLICKER_INCREASING,
        BACK_PIC(Zoroark, 64, 56),
        .backPicYOffset = 10,
        .backAnimId = BACK_ANIM_JOLT_RIGHT,
        PALETTES(Zoroark),
        ICON(Zoroark, 0),
        LEARNSETS(Zoroark),
    },

#if P_HISUIAN_FORMS
    [SPECIES_ZORUA_HISUI] =
    {
        ZORUA_MISC_INFO,
        .baseHP        = 35,
        .baseAttack    = 60,
        .baseDefense   = 40,
        .baseSpeed     = 70,
        .baseSpAttack  = 85,
        .baseSpDefense = 40,
        .types = { TYPE_NORMAL, TYPE_GHOST },
        .categoryName = _("Lausefuchs"),
        .description = POKEDEX_DESC_STRING(
            "Nicht selten überrumpelt es Gegner,\n"
            "indem es ihre Gestalt annimmt und\n"
            "den Überraschungseffekt zur Flucht\n"
            "nutzt."),
        FRONT_PIC(ZoruaHisuian, 48, 64),
        .frontPicYOffset = 1,
        .frontAnimFrames = sAnims_ZoruaHisuian,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(ZoruaHisuian, 56, 64),
        .backPicYOffset = 1,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(ZoruaHisuian),
        ICON(ZoruaHisuian, 0),
        LEARNSETS(ZoruaHisuian),
        .isHisuianForm = TRUE,
        .evolutions = EVOLUTION({EVO_LEVEL, 30, SPECIES_ZOROARK_HISUI}),
    },

    [SPECIES_ZOROARK_HISUI] =
    {
        ZOROARK_MISC_INFO,
        .baseHP        = 55,
        .baseAttack    = 100,
        .baseDefense   = 60,
        .baseSpeed     = 110,
        .baseSpAttack  = 125,
        .baseSpDefense = 60,
        .types = { TYPE_NORMAL, TYPE_GHOST },
        .categoryName = _("Polymorfuchs"),
        .weight = 730,
        .description = POKEDEX_DESC_STRING(
            "Kann auf einen Schlag große Massen\n"
            "von Menschen täuschen. Es kreiert\n"
            "Illusionen, um sein Revier zu\n"
            "schützen."),
        FRONT_PIC(ZoroarkHisuian, 64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_ZoroarkHisuian,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(ZoroarkHisuian, 64, 64),
        .backPicYOffset = 0,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(ZoroarkHisuian),
        ICON(ZoroarkHisuian, 0),
        LEARNSETS(ZoroarkHisuian),
        .isHisuianForm = TRUE,
    },
#endif //P_HISUIAN_FORMS
#endif //P_FAMILY_ZORUA

#if P_FAMILY_MINCCINO
    [SPECIES_MINCCINO] =
    {
        .baseHP        = 55,
        .baseAttack    = 50,
        .baseDefense   = 40,
        .baseSpeed     = 75,
        .baseSpAttack  = 40,
        .baseSpDefense = 40,
        .types = { TYPE_NORMAL, TYPE_NORMAL },
        .catchRate = 255,
        .expYield = 60,
        .evYield_Speed = 1,
        .genderRatio = PERCENT_FEMALE(75),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_FAST,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD },
        .abilities = { ABILITY_CUTE_CHARM, ABILITY_TECHNICIAN, ABILITY_SKILL_LINK },
        .bodyColor = BODY_COLOR_GRAY,
        .speciesName = _("Picochilla"),
        .cryId = CRY_MINCCINO,
        .natDexNum = NATIONAL_DEX_MINCCINO,
        .categoryName = _("Chinchilla"),
        .height = 4,
        .weight = 58,
        .description = POKEDEX_DESC_STRING(
            "Sie begrüßen einander, indem sie\n"
            "ihr Gegenüber mithilfe ihres\n"
            "Schweifs säubern."),
        .pokemonScale = 491,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Minccino, 56, 48),
        .frontPicYOffset = 11,
        .frontAnimFrames = sAnims_Minccino,
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(Minccino, 56, 56),
        .backPicYOffset = 6,
        .backAnimId = BACK_ANIM_CONCAVE_ARC_SMALL,
        PALETTES(Minccino),
        ICON(Minccino, 0),
        .footprint = gMonFootprint_Minccino,
        LEARNSETS(Minccino),
        .evolutions = EVOLUTION({EVO_ITEM, ITEM_SHINY_STONE, SPECIES_CINCCINO}),
    },

    [SPECIES_CINCCINO] =
    {
        .baseHP        = 75,
        .baseAttack    = 95,
        .baseDefense   = 60,
        .baseSpeed     = 115,
        .baseSpAttack  = 65,
        .baseSpDefense = 60,
        .types = { TYPE_NORMAL, TYPE_NORMAL },
        .catchRate = 60,
        .expYield = 165,
        .evYield_Speed = 2,
        .genderRatio = PERCENT_FEMALE(75),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_FAST,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD },
        .abilities = { ABILITY_CUTE_CHARM, ABILITY_TECHNICIAN, ABILITY_SKILL_LINK },
        .bodyColor = BODY_COLOR_GRAY,
        .noFlip = TRUE,
        .speciesName = _("Chillabell"),
        .cryId = CRY_CINCCINO,
        .natDexNum = NATIONAL_DEX_CINCCINO,
        .categoryName = _("Schal"),
        .height = 5,
        .weight = 75,
        .description = POKEDEX_DESC_STRING(
            "Sein weißer Flaum fühlt sich\n"
            "wunderbar flauschig an und zieht\n"
            "weder Staub noch statische\n"
            "Elektrizität an."),
        .pokemonScale = 432,
        .pokemonOffset = 13,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Cinccino, 56, 56),
        .frontPicYOffset = 7,
        .frontAnimFrames = sAnims_Cinccino,
        .frontAnimId = ANIM_V_SLIDE,
        BACK_PIC(Cinccino, 64, 56),
        .backPicYOffset = 7,
        .backAnimId = BACK_ANIM_CONCAVE_ARC_LARGE,
        PALETTES(Cinccino),
        ICON(Cinccino, 0),
        .footprint = gMonFootprint_Cinccino,
        LEARNSETS(Cinccino),
    },
#endif //P_FAMILY_MINCCINO

#if P_FAMILY_GOTHITA
    [SPECIES_GOTHITA] =
    {
        .baseHP        = 45,
        .baseAttack    = 30,
        .baseDefense   = 50,
        .baseSpeed     = 45,
        .baseSpAttack  = 55,
        .baseSpDefense = 65,
        .types = { TYPE_PSYCHIC, TYPE_PSYCHIC },
        .catchRate = 200,
        .expYield = 58,
        .evYield_SpDefense = 1,
        .genderRatio = PERCENT_FEMALE(75),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_HUMAN_LIKE, EGG_GROUP_HUMAN_LIKE },
        .abilities = { ABILITY_FRISK, ABILITY_COMPETITIVE, ABILITY_SHADOW_TAG },
        .bodyColor = BODY_COLOR_PURPLE,
        .speciesName = _("Mollimorba"),
        .cryId = CRY_GOTHITA,
        .natDexNum = NATIONAL_DEX_GOTHITA,
        .categoryName = _("Glotz"),
        .height = 4,
        .weight = 58,
        .description = POKEDEX_DESC_STRING(
            "Beobachtet andere Pokémon und Trainer mit\n"
            "durchdringendem Blick, als könne es etwas\n"
            "erkennen, das keiner sonst sieht."),
        .pokemonScale = 491,
        .pokemonOffset = 14,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Gothita, 40, 40),
        .frontPicYOffset = 12,
        .frontAnimFrames = sAnims_Gothita,
        .frontAnimId = ANIM_V_JUMPS_SMALL,
        BACK_PIC(Gothita, 48, 48),
        .backPicYOffset = 10,
        .backAnimId = BACK_ANIM_CONCAVE_ARC_SMALL,
        PALETTES(Gothita),
        ICON(Gothita, 2),
        .footprint = gMonFootprint_Gothita,
        LEARNSETS(Gothita),
        .evolutions = EVOLUTION({EVO_LEVEL, 32, SPECIES_GOTHORITA}),
    },

    [SPECIES_GOTHORITA] =
    {
        .baseHP        = 60,
        .baseAttack    = 45,
        .baseDefense   = 70,
        .baseSpeed     = 55,
        .baseSpAttack  = 75,
        .baseSpDefense = 85,
        .types = { TYPE_PSYCHIC, TYPE_PSYCHIC },
        .catchRate = 100,
        .expYield = 137,
        .evYield_SpDefense = 2,
        .genderRatio = PERCENT_FEMALE(75),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_HUMAN_LIKE, EGG_GROUP_HUMAN_LIKE },
        .abilities = { ABILITY_FRISK, ABILITY_COMPETITIVE, ABILITY_SHADOW_TAG },
        .bodyColor = BODY_COLOR_PURPLE,
        .speciesName = _("Hypnomorba"),
        .cryId = CRY_GOTHORITA,
        .natDexNum = NATIONAL_DEX_GOTHORITA,
        .categoryName = _("Manipulator"),
        .height = 7,
        .weight = 180,
        .description = POKEDEX_DESC_STRING(
            "Zieht seine Energie aus dem\n"
            "Sternenlicht. Bei Nacht bringt es\n"
            "Steine zum Schweben und bildet\n"
            "damit Sternzeichen nach."),
        .pokemonScale = 365,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Gothorita, 48, 56),
        .frontPicYOffset = 7,
        .frontAnimFrames = sAnims_Gothorita,
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE_SLOW,
        BACK_PIC(Gothorita, 64, 56),
        .backPicYOffset = 7,
        .backAnimId = BACK_ANIM_JOLT_RIGHT,
        PALETTES(Gothorita),
        ICON(Gothorita, 2),
        .footprint = gMonFootprint_Gothorita,
        LEARNSETS(Gothorita),
        .evolutions = EVOLUTION({EVO_LEVEL, 41, SPECIES_GOTHITELLE}),
    },

    [SPECIES_GOTHITELLE] =
    {
        .baseHP        = 70,
        .baseAttack    = 55,
        .baseDefense   = 95,
        .baseSpeed     = 65,
        .baseSpAttack  = 95,
        .baseSpDefense = 110,
        .types = { TYPE_PSYCHIC, TYPE_PSYCHIC },
        .catchRate = 50,
        .expYield = 221,
        .evYield_SpDefense = 3,
        .genderRatio = PERCENT_FEMALE(75),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_HUMAN_LIKE, EGG_GROUP_HUMAN_LIKE },
        .abilities = { ABILITY_FRISK, ABILITY_COMPETITIVE, ABILITY_SHADOW_TAG },
        .bodyColor = BODY_COLOR_PURPLE,
        .speciesName = _("Morbitesse"),
        .cryId = CRY_GOTHITELLE,
        .natDexNum = NATIONAL_DEX_GOTHITELLE,
        .categoryName = _("Gestirns"),
        .height = 15,
        .weight = 440,
        .description = POKEDEX_DESC_STRING(
            "Kann anhand der Sternenkonstellationen die\n"
            "Zukunft voraussagen. Es weiß sogar, wie\n"
            "alt sein Trainer werden wird."),
        .pokemonScale = 268,
        .pokemonOffset = 2,
        .trainerScale = 271,
        .trainerOffset = 0,
        FRONT_PIC(Gothitelle, 48, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_Gothitelle,
        .frontAnimId = ANIM_GROW_VIBRATE,
        BACK_PIC(Gothitelle, 64, 64),
        .backPicYOffset = 0,
        .backAnimId = BACK_ANIM_H_STRETCH,
        PALETTES(Gothitelle),
        ICON(Gothitelle, 2),
        .footprint = gMonFootprint_Gothitelle,
        LEARNSETS(Gothitelle),
    },
#endif //P_FAMILY_GOTHITA

#if P_FAMILY_SOLOSIS
    [SPECIES_SOLOSIS] =
    {
        .baseHP        = 45,
        .baseAttack    = 30,
        .baseDefense   = 40,
        .baseSpeed     = 20,
        .baseSpAttack  = 105,
        .baseSpDefense = 50,
        .types = { TYPE_PSYCHIC, TYPE_PSYCHIC },
        .catchRate = 200,
        .expYield = 58,
        .evYield_SpAttack = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_AMORPHOUS, EGG_GROUP_AMORPHOUS },
        .abilities = { ABILITY_OVERCOAT, ABILITY_MAGIC_GUARD, ABILITY_REGENERATOR },
        .bodyColor = BODY_COLOR_GREEN,
        .noFlip = TRUE,
        .speciesName = _("Monozyto"),
        .cryId = CRY_SOLOSIS,
        .natDexNum = NATIONAL_DEX_SOLOSIS,
        .categoryName = _("Zellen"),
        .height = 3,
        .weight = 10,
        .description = POKEDEX_DESC_STRING(
            "Die spezielle Flüssigkeit, die es\n"
            "umgibt, bietet ihm in jeder noch so\n"
            "gefährlichen Situation Schutz."),
        .pokemonScale = 530,
        .pokemonOffset = 13,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Solosis, 32, 32),
        .frontPicYOffset = 17,
        .frontAnimFrames = sAnims_Solosis,
        .frontAnimId = ANIM_TWIST,
        .enemyMonElevation = 14,
        BACK_PIC(Solosis, 48, 32),
        .backPicYOffset = 19,
        .backAnimId = BACK_ANIM_SHRINK_GROW,
        PALETTES(Solosis),
        ICON(Solosis, 1),
        .footprint = gMonFootprint_Solosis,
        LEARNSETS(Solosis),
        .evolutions = EVOLUTION({EVO_LEVEL, 32, SPECIES_DUOSION}),
    },

    [SPECIES_DUOSION] =
    {
        .baseHP        = 65,
        .baseAttack    = 40,
        .baseDefense   = 50,
        .baseSpeed     = 30,
        .baseSpAttack  = 125,
        .baseSpDefense = 60,
        .types = { TYPE_PSYCHIC, TYPE_PSYCHIC },
        .catchRate = 100,
        .expYield = 130,
        .evYield_SpAttack = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_AMORPHOUS, EGG_GROUP_AMORPHOUS },
        .abilities = { ABILITY_OVERCOAT, ABILITY_MAGIC_GUARD, ABILITY_REGENERATOR },
        .bodyColor = BODY_COLOR_GREEN,
        .speciesName = _("Mitodos"),
        .cryId = CRY_DUOSION,
        .natDexNum = NATIONAL_DEX_DUOSION,
        .categoryName = _("Zellteilungs"),
        .height = 6,
        .weight = 80,
        .description = POKEDEX_DESC_STRING(
            "Wenn beide Hälften seines gespaltenen\n"
            "Denkapparates an dasselbe denken, sind\n"
            "seine Psycho-Kräfte am stärksten."),
        .pokemonScale = 422,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Duosion, 40, 48),
        .frontPicYOffset = 12,
        .frontAnimFrames = sAnims_Duosion,
        .frontAnimId = ANIM_CIRCULAR_STRETCH_TWICE,
        .enemyMonElevation = 7,
        BACK_PIC(Duosion, 56, 48),
        .backPicYOffset = 13,
        .backAnimId = BACK_ANIM_GROW,
        PALETTES(Duosion),
        ICON(Duosion, 1),
        .footprint = gMonFootprint_Duosion,
        LEARNSETS(Duosion),
        .evolutions = EVOLUTION({EVO_LEVEL, 41, SPECIES_REUNICLUS}),
    },

    [SPECIES_REUNICLUS] =
    {
        .baseHP        = 110,
        .baseAttack    = 65,
        .baseDefense   = 75,
        .baseSpeed     = 30,
        .baseSpAttack  = 125,
        .baseSpDefense = 85,
        .types = { TYPE_PSYCHIC, TYPE_PSYCHIC },
        .catchRate = 50,
        .expYield = 221,
        .evYield_SpAttack = 3,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_AMORPHOUS, EGG_GROUP_AMORPHOUS },
        .abilities = { ABILITY_OVERCOAT, ABILITY_MAGIC_GUARD, ABILITY_REGENERATOR },
        .bodyColor = BODY_COLOR_GREEN,
        .speciesName = _("Zytomega"),
        .cryId = CRY_REUNICLUS,
        .natDexNum = NATIONAL_DEX_REUNICLUS,
        .categoryName = _("Vermehrungs"),
        .height = 10,
        .weight = 201,
        .description = POKEDEX_DESC_STRING(
            "Seine Arme bestehen aus einer\n"
            "speziellen Flüssigkeit. Dank seiner\n"
            "Psycho-Kräfte kann es mit ihnen\n"
            "Felsen zerschmettern."),
        .pokemonScale = 305,
        .pokemonOffset = 7,
        .trainerScale = 257,
        .trainerOffset = 0,
        FRONT_PIC(Reuniclus, 64, 48),
        .frontPicYOffset = 11,
        .frontAnimFrames = sAnims_Reuniclus,
        .frontAnimId = ANIM_V_SLIDE_WOBBLE,
        .enemyMonElevation = 8,
        BACK_PIC(Reuniclus, 64, 48),
        .backPicYOffset = 13,
        .backAnimId = BACK_ANIM_SHRINK_GROW_VIBRATE,
        PALETTES(Reuniclus),
        ICON(Reuniclus, 1),
        .footprint = gMonFootprint_Reuniclus,
        LEARNSETS(Reuniclus),
    },
#endif //P_FAMILY_SOLOSIS

#if P_FAMILY_DUCKLETT
    [SPECIES_DUCKLETT] =
    {
        .baseHP        = 62,
        .baseAttack    = 44,
        .baseDefense   = 50,
        .baseSpeed     = 55,
        .baseSpAttack  = 44,
        .baseSpDefense = 50,
        .types = { TYPE_WATER, TYPE_FLYING },
        .catchRate = 190,
        .expYield = 61,
        .evYield_HP = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_WATER_1, EGG_GROUP_FLYING },
        .abilities = { ABILITY_KEEN_EYE, ABILITY_BIG_PECKS, ABILITY_HYDRATION },
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Piccolente"),
        .cryId = CRY_DUCKLETT,
        .natDexNum = NATIONAL_DEX_DUCKLETT,
        .categoryName = _("Wasservogel"),
        .height = 5,
        .weight = 55,
        .description = POKEDEX_DESC_STRING(
            "Gerät es in Gefahr, versprüht es\n"
            "Wasser aus seinem Federkleid und\n"
            "nutzt den Sprühregen, um Reißaus zu\n"
            "nehmen."),
        .pokemonScale = 432,
        .pokemonOffset = 14,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Ducklett, 32, 40),
        .frontPicYOffset = 12,
        .frontAnimFrames = sAnims_Ducklett,
        .frontAnimId = ANIM_V_STRETCH,
        BACK_PIC(Ducklett, 48, 48),
        .backPicYOffset = 10,
        .backAnimId = BACK_ANIM_CONCAVE_ARC_SMALL,
        PALETTES(Ducklett),
        ICON(Ducklett, 0),
        .footprint = gMonFootprint_Ducklett,
        LEARNSETS(Ducklett),
        .evolutions = EVOLUTION({EVO_LEVEL, 35, SPECIES_SWANNA}),
    },

    [SPECIES_SWANNA] =
    {
        .baseHP        = 75,
        .baseAttack    = 87,
        .baseDefense   = 63,
        .baseSpeed     = 98,
        .baseSpAttack  = 87,
        .baseSpDefense = 63,
        .types = { TYPE_WATER, TYPE_FLYING },
        .catchRate = 45,
        .expYield = 166,
        .evYield_Speed = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_WATER_1, EGG_GROUP_FLYING },
        .abilities = { ABILITY_KEEN_EYE, ABILITY_BIG_PECKS, ABILITY_HYDRATION },
        .bodyColor = BODY_COLOR_WHITE,
        .speciesName = _("Swaroness"),
        .cryId = CRY_SWANNA,
        .natDexNum = NATIONAL_DEX_SWANNA,
        .categoryName = _("Schwan"),
        .height = 13,
        .weight = 242,
        .description = POKEDEX_DESC_STRING(
            "Wenn der Morgen dämmert, fangen sie an zu\n"
            "tanzen. Das Swaroness in der Mitte führt\n"
            "die Gruppe an."),
        .pokemonScale = 272,
        .pokemonOffset = 3,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Swanna, 56, 64),
        .frontPicYOffset = 2,
        .frontAnimFrames = sAnims_Swanna,
        .frontAnimId = ANIM_V_STRETCH,
        BACK_PIC(Swanna, 64, 64),
        .backPicYOffset = 1,
        .backAnimId = BACK_ANIM_H_STRETCH,
        PALETTES(Swanna),
        ICON(Swanna, 2),
        .footprint = gMonFootprint_Swanna,
        LEARNSETS(Swanna),
    },
#endif //P_FAMILY_DUCKLETT

#if P_FAMILY_VANILLITE
    [SPECIES_VANILLITE] =
    {
        .baseHP        = 36,
        .baseAttack    = 50,
        .baseDefense   = 50,
        .baseSpeed     = 44,
        .baseSpAttack  = 65,
        .baseSpDefense = 60,
        .types = { TYPE_ICE, TYPE_ICE },
        .catchRate = 255,
        .expYield = 61,
        .evYield_SpAttack = 1,
        .itemRare = ITEM_NEVER_MELT_ICE,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_MINERAL, EGG_GROUP_MINERAL },
        .abilities = { ABILITY_ICE_BODY, ABILITY_SNOW_CLOAK, ABILITY_WEAK_ARMOR },
        .bodyColor = BODY_COLOR_WHITE,
        .speciesName = _("Gelatini"),
        .cryId = CRY_VANILLITE,
        .natDexNum = NATIONAL_DEX_VANILLITE,
        .categoryName = _("Neuschnee"),
        .height = 4,
        .weight = 57,
        .description = POKEDEX_DESC_STRING(
            "Ein Eiszapfen, der durch die Energie der\n"
            "aufgehenden Sonne zum Pokémon wurde.\n"
            "Nachts deckt es sich mit Schnee zu."),
        .pokemonScale = 491,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Vanillite, 32, 40),
        .frontPicYOffset = 14,
        .frontAnimFrames = sAnims_Vanillite,
        .frontAnimId = ANIM_H_SLIDE,
        BACK_PIC(Vanillite, 40, 48),
        .backPicYOffset = 9,
        .backAnimId = BACK_ANIM_H_SLIDE,
        PALETTES(Vanillite),
        ICON(Vanillite, 0),
        .footprint = gMonFootprint_Vanillite,
        LEARNSETS(Vanillite),
        .evolutions = EVOLUTION({EVO_LEVEL, 35, SPECIES_VANILLISH}),
    },

    [SPECIES_VANILLISH] =
    {
        .baseHP        = 51,
        .baseAttack    = 65,
        .baseDefense   = 65,
        .baseSpeed     = 59,
        .baseSpAttack  = 80,
        .baseSpDefense = 75,
        .types = { TYPE_ICE, TYPE_ICE },
        .catchRate = 120,
        .expYield = 138,
        .evYield_SpAttack = 2,
        .itemRare = ITEM_NEVER_MELT_ICE,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_MINERAL, EGG_GROUP_MINERAL },
        .abilities = { ABILITY_ICE_BODY, ABILITY_SNOW_CLOAK, ABILITY_WEAK_ARMOR },
        .bodyColor = BODY_COLOR_WHITE,
        .speciesName = _("Gelatroppo"),
        .cryId = CRY_VANILLISH,
        .natDexNum = NATIONAL_DEX_VANILLISH,
        .categoryName = _("Firn"),
        .height = 11,
        .weight = 410,
        .description = POKEDEX_DESC_STRING(
            "Es lebt auf schneebedeckten Bergen. Vor\n"
            "vielen Jahren fand es während einer\n"
            "Eiszeit seinen Weg in den Süden."),
        .pokemonScale = 320,
        .pokemonOffset = 7,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Vanillish, 32, 56),
        .frontPicYOffset = 5,
        .frontAnimFrames = sAnims_Vanillish,
        .frontAnimId = ANIM_GROW_VIBRATE,
        BACK_PIC(Vanillish, 48, 56),
        .backPicYOffset = 4,
        .backAnimId = BACK_ANIM_H_SLIDE,
        PALETTES(Vanillish),
        ICON(Vanillish, 2),
        .footprint = gMonFootprint_Vanillish,
        LEARNSETS(Vanillish),
        .evolutions = EVOLUTION({EVO_LEVEL, 47, SPECIES_VANILLUXE}),
    },

    [SPECIES_VANILLUXE] =
    {
        .baseHP        = 71,
        .baseAttack    = 95,
        .baseDefense   = 85,
        .baseSpeed     = 79,
        .baseSpAttack  = 110,
        .baseSpDefense = 95,
        .types = { TYPE_ICE, TYPE_ICE },
        .catchRate = 45,
        .expYield = 241,
        .evYield_SpAttack = 3,
        .itemCommon = ITEM_NEVER_MELT_ICE,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_MINERAL, EGG_GROUP_MINERAL },
        .abilities = { ABILITY_ICE_BODY, ABILITY_SNOW_WARNING, ABILITY_WEAK_ARMOR },
        .bodyColor = BODY_COLOR_WHITE,
        .speciesName = _("Gelatwino"),
        .cryId = CRY_VANILLUXE,
        .natDexNum = NATIONAL_DEX_VANILLUXE,
        .categoryName = _("Schneesturm"),
        .height = 13,
        .weight = 575,
        .description = POKEDEX_DESC_STRING(
            "Es verschluckt Unmengen an Wasser und\n"
            "wandelt es intern in Schneewolken um. Ist\n"
            "es wütend, erzeugt es Schneestürme."),
        .pokemonScale = 272,
        .pokemonOffset = 3,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Vanilluxe, 56, 56),
        .frontPicYOffset = 4,
        .frontAnimFrames = sAnims_Vanilluxe,
        .frontAnimId = ANIM_GROW_VIBRATE,
        BACK_PIC(Vanilluxe, 64, 64),
        .backPicYOffset = 6,
        .backAnimId = BACK_ANIM_H_SHAKE,
        PALETTES(Vanilluxe),
        ICON(Vanilluxe, 2),
        .footprint = gMonFootprint_Vanilluxe,
        LEARNSETS(Vanilluxe),
    },
#endif //P_FAMILY_VANILLITE

#if P_FAMILY_DEERLING
#define DEERLING_MISC_INFO                                                              \
        .baseHP        = 60,                                                            \
        .baseAttack    = 60,                                                            \
        .baseDefense   = 50,                                                            \
        .baseSpeed     = 75,                                                            \
        .baseSpAttack  = 40,                                                            \
        .baseSpDefense = 50,                                                            \
        .types = { TYPE_NORMAL, TYPE_GRASS },                                           \
        .catchRate = 190,                                                               \
        .expYield = 67,                                                                 \
        .evYield_Speed = 1,                                                             \
        .genderRatio = PERCENT_FEMALE(50),                                              \
        .eggCycles = 20,                                                                \
        .friendship = STANDARD_FRIENDSHIP,                                              \
        .growthRate = GROWTH_MEDIUM_FAST,                                               \
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD },                              \
        .abilities = { ABILITY_CHLOROPHYLL, ABILITY_SAP_SIPPER, ABILITY_SERENE_GRACE }, \
        .speciesName = _("Gelatwino"),                                                   \
        .cryId = CRY_DEERLING,                                                          \
        .natDexNum = NATIONAL_DEX_DEERLING,                                             \
        .categoryName = _("Schneesturm"),                                                    \
        .height = 6,                                                                    \
        .weight = 195,                                                                  \
        .pokemonScale = 422,                                                            \
        .pokemonOffset = 14,                                                            \
        .trainerScale = 256,                                                            \
        .trainerOffset = 0,                                                             \
        FRONT_PIC(Deerling, 32, 48),                                                    \
        .frontPicYOffset = 11,                                                          \
        .frontAnimFrames = sAnims_Deerling,                                             \
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,                                        \
        BACK_PIC(Deerling, 48, 56),                                                     \
        .backPicYOffset = 9,                                                            \
        .backAnimId = BACK_ANIM_H_SLIDE,                                                \
        .footprint = gMonFootprint_Deerling,                                            \
        LEARNSETS(Deerling),                                                            \
        .formSpeciesIdTable = sDeerlingFormSpeciesIdTable

    [SPECIES_DEERLING_SPRING] =
    {
        DEERLING_MISC_INFO,
        .bodyColor = BODY_COLOR_PINK,
        .description = POKEDEX_DESC_STRING(
            "Unabhängig von der Jahreszeit\n"
            "ändert sich seine Farbe auch bei\n"
            "wechselnder Temperatur oder\n"
            "Luftfeuchtigkeit leicht."),
        PALETTES(DeerlingSpring),
        ICON(DeerlingSpring, 1),
        .evolutions = EVOLUTION({EVO_LEVEL, 34, SPECIES_SAWSBUCK_SPRING}),
    },
    [SPECIES_DEERLING_SUMMER] =
    {
        DEERLING_MISC_INFO,
        .bodyColor = BODY_COLOR_GREEN,
        .description = POKEDEX_DESC_STRING(
            "Unabhängig von der Jahreszeit\n"
            "ändert sich seine Farbe auch bei\n"
            "wechselnder Temperatur oder\n"
            "Luftfeuchtigkeit leicht."),
        PALETTES(DeerlingSummer),
        ICON(DeerlingSummer, 1),
        .evolutions = EVOLUTION({EVO_LEVEL, 34, SPECIES_SAWSBUCK_SUMMER}),
    },
    [SPECIES_DEERLING_AUTUMN] =
    {
        DEERLING_MISC_INFO,
        .bodyColor = BODY_COLOR_RED,
        .description = POKEDEX_DESC_STRING(
            "Unabhängig von der Jahreszeit\n"
            "ändert sich seine Farbe auch bei\n"
            "wechselnder Temperatur oder\n"
            "Luftfeuchtigkeit leicht."),
        PALETTES(DeerlingAutumn),
        ICON(DeerlingAutumn, 0),
        .evolutions = EVOLUTION({EVO_LEVEL, 34, SPECIES_SAWSBUCK_AUTUMN}),
    },
    [SPECIES_DEERLING_WINTER] =
    {
        DEERLING_MISC_INFO,
        .bodyColor = BODY_COLOR_BROWN,
        .description = POKEDEX_DESC_STRING(
            "Unabhängig von der Jahreszeit\n"
            "ändert sich seine Farbe auch bei\n"
            "wechselnder Temperatur oder\n"
            "Luftfeuchtigkeit leicht."),
        PALETTES(DeerlingWinter),
        ICON(DeerlingWinter, 2),
        .evolutions = EVOLUTION({EVO_LEVEL, 34, SPECIES_SAWSBUCK_WINTER}),
    },

#define SAWSBUCK_MISC_INFO                                                              \
        .baseHP        = 80,                                                            \
        .baseAttack    = 100,                                                           \
        .baseDefense   = 70,                                                            \
        .baseSpeed     = 95,                                                            \
        .baseSpAttack  = 60,                                                            \
        .baseSpDefense = 70,                                                            \
        .types = { TYPE_NORMAL, TYPE_GRASS },                                           \
        .catchRate = 75,                                                                \
        .expYield = 166,                                                                \
        .evYield_Attack = 2,                                                            \
        .genderRatio = PERCENT_FEMALE(50),                                              \
        .eggCycles = 20,                                                                \
        .friendship = STANDARD_FRIENDSHIP,                                              \
        .growthRate = GROWTH_MEDIUM_FAST,                                               \
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD },                              \
        .abilities = { ABILITY_CHLOROPHYLL, ABILITY_SAP_SIPPER, ABILITY_SERENE_GRACE }, \
        .bodyColor = BODY_COLOR_BROWN,                                                  \
        .speciesName = _("Sesokitz"),                                                   \
        .cryId = CRY_SAWSBUCK,                                                          \
        .natDexNum = NATIONAL_DEX_SAWSBUCK,                                             \
        .categoryName = _("Jahreszeit"),                                                    \
        .height = 19,                                                                   \
        .weight = 925,                                                                  \
        .pokemonScale = 256,                                                            \
        .pokemonOffset = 1,                                                             \
        .trainerScale = 326,                                                            \
        .trainerOffset = 4,                                                             \
        .frontPicYOffset = 0,                                                           \
        .frontAnimFrames = sAnims_Sawsbuck,                                             \
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,                                        \
        .backPicYOffset = 5,                                                            \
        .backAnimId = BACK_ANIM_DIP_RIGHT_SIDE,                                         \
        .footprint = gMonFootprint_Sawsbuck,                                            \
        LEARNSETS(Sawsbuck),                                                            \
        .formSpeciesIdTable = sSawsbuckFormSpeciesIdTable

    [SPECIES_SAWSBUCK_SPRING] =
    {
        SAWSBUCK_MISC_INFO,
        .description = POKEDEX_DESC_STRING(
            "An seinem Geweih kann man ablesen,\n"
            "wann eine neue Jahreszeit beginnt.\n"
            "Sein Revier wechselt mit jeder\n"
            "neuen Jahreszeit."),
        FRONT_PIC(SawsbuckSpring, 56, 64),
        BACK_PIC(SawsbuckSpring, 48, 64),
        PALETTES(SawsbuckSpring),
        ICON(SawsbuckSpring, 1),
    },

    [SPECIES_SAWSBUCK_SUMMER] =
    {
        SAWSBUCK_MISC_INFO,
        .description = POKEDEX_DESC_STRING(
            "An seinem Geweih kann man ablesen,\n"
            "wann eine neue Jahreszeit beginnt.\n"
            "Sein Revier wechselt mit jeder\n"
            "neuen Jahreszeit."),
        FRONT_PIC(SawsbuckSummer, 64, 64),
        BACK_PIC(SawsbuckSummer, 64, 64),
        PALETTES(SawsbuckSummer),
        ICON(SawsbuckSummer, 1),
    },

    [SPECIES_SAWSBUCK_AUTUMN] =
    {
        SAWSBUCK_MISC_INFO,
        .description = POKEDEX_DESC_STRING(
            "An seinem Geweih kann man ablesen,\n"
            "wann eine neue Jahreszeit beginnt.\n"
            "Sein Revier wechselt mit jeder\n"
            "neuen Jahreszeit."),
        FRONT_PIC(SawsbuckAutumn, 64, 64),
        BACK_PIC(SawsbuckAutumn, 64, 64),
        PALETTES(SawsbuckAutumn),
        ICON(SawsbuckAutumn, 1),
    },

    [SPECIES_SAWSBUCK_WINTER] =
    {
        SAWSBUCK_MISC_INFO,
        .description = POKEDEX_DESC_STRING(
            "An seinem Geweih kann man ablesen,\n"
            "wann eine neue Jahreszeit beginnt.\n"
            "Sein Revier wechselt mit jeder\n"
            "neuen Jahreszeit."),
        FRONT_PIC(SawsbuckWinter, 56, 64),
        BACK_PIC(SawsbuckWinter, 48, 64),
        PALETTES(SawsbuckWinter),
        ICON(SawsbuckWinter, 1),
    },

#endif //P_FAMILY_DEERLING

#if P_FAMILY_EMOLGA
    [SPECIES_EMOLGA] =
    {
        .baseHP        = 55,
        .baseAttack    = 75,
        .baseDefense   = 60,
        .baseSpeed     = 103,
        .baseSpAttack  = 75,
        .baseSpDefense = 60,
        .types = { TYPE_ELECTRIC, TYPE_FLYING },
        .catchRate = 200,
        .expYield = 150,
        .evYield_Speed = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD },
        .abilities = { ABILITY_STATIC, ABILITY_NONE, ABILITY_MOTOR_DRIVE },
        .bodyColor = BODY_COLOR_WHITE,
        .speciesName = _("Emolga"),
        .cryId = CRY_EMOLGA,
        .natDexNum = NATIONAL_DEX_EMOLGA,
        .categoryName = _("Flughörnchen"),
        .height = 4,
        .weight = 50,
        .description = POKEDEX_DESC_STRING(
            "Im Flug entlädt es Strom, den es mit\n"
            "seinen Backentaschen erzeugt und in seinen\n"
            "Fluglappen gespeichert hat."),
        .pokemonScale = 491,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Emolga, 64, 48),
        .frontPicYOffset = 17,
        .frontAnimFrames = sAnims_Emolga,
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE_SLOW,
        .enemyMonElevation = 19,
        BACK_PIC(Emolga, 56, 40),
        .backPicYOffset = 16,
        .backAnimId = BACK_ANIM_CONVEX_DOUBLE_ARC,
        PALETTES(Emolga),
        ICON(Emolga, 2),
        .footprint = gMonFootprint_Emolga,
        LEARNSETS(Emolga),
    },
#endif //P_FAMILY_EMOLGA

#if P_FAMILY_KARRABLAST
    [SPECIES_KARRABLAST] =
    {
        .baseHP        = 50,
        .baseAttack    = 75,
        .baseDefense   = 45,
        .baseSpeed     = 60,
        .baseSpAttack  = 40,
        .baseSpDefense = 45,
        .types = { TYPE_BUG, TYPE_BUG },
        .catchRate = 200,
        .expYield = 63,
        .evYield_Attack = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_BUG, EGG_GROUP_BUG },
        .abilities = { ABILITY_SWARM, ABILITY_SHED_SKIN, ABILITY_NO_GUARD },
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Laukaps"),
        .cryId = CRY_KARRABLAST,
        .natDexNum = NATIONAL_DEX_KARRABLAST,
        .categoryName = _("Schnappbiss"),
        .height = 5,
        .weight = 59,
        .description = POKEDEX_DESC_STRING(
            "Ein mysteriöses Pokémon, das sich\n"
            "entwickelt, wenn es zusammen mit\n"
            "Schnuthelm einen Stromschlag\n"
            "abbekommt."),
        .pokemonScale = 432,
        .pokemonOffset = 15,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Karrablast, 40, 48),
        .frontPicYOffset = 13,
        .frontAnimFrames = sAnims_Karrablast,
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(Karrablast, 48, 48),
        .backPicYOffset = 14,
        .backAnimId = BACK_ANIM_CONCAVE_ARC_LARGE,
        PALETTES(Karrablast),
        ICON(Karrablast, 0),
        .footprint = gMonFootprint_Karrablast,
        LEARNSETS(Karrablast),
        .evolutions = EVOLUTION({EVO_TRADE_SPECIFIC_MON, SPECIES_SHELMET, SPECIES_ESCAVALIER}),
    },

    [SPECIES_ESCAVALIER] =
    {
        .baseHP        = 70,
        .baseAttack    = 135,
        .baseDefense   = 105,
        .baseSpeed     = 20,
        .baseSpAttack  = 60,
        .baseSpDefense = 105,
        .types = { TYPE_BUG, TYPE_STEEL },
        .catchRate = 75,
        .expYield = 173,
        .evYield_Attack = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_BUG, EGG_GROUP_BUG },
        .abilities = { ABILITY_SWARM, ABILITY_SHELL_ARMOR, ABILITY_OVERCOAT },
        .bodyColor = BODY_COLOR_GRAY,
        .speciesName = _("Cavalanzas"),
        .cryId = CRY_ESCAVALIER,
        .natDexNum = NATIONAL_DEX_ESCAVALIER,
        .categoryName = _("Kavallerie"),
        .height = 10,
        .weight = 330,
        .description = POKEDEX_DESC_STRING(
            "Eine von einem Schnuthelm\n"
            "gestohlene Muschel dient ihm als\n"
            "Helm. Es greift Gegner mit seinen\n"
            "beiden Lanzen an."),
        .pokemonScale = 305,
        .pokemonOffset = 7,
        .trainerScale = 257,
        .trainerOffset = 0,
        FRONT_PIC(Escavalier, 64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_Escavalier,
        .frontAnimId = ANIM_BACK_AND_LUNGE,
        BACK_PIC(Escavalier, 64, 56),
        .backPicYOffset = 9,
        .backAnimId = BACK_ANIM_JOLT_RIGHT,
        PALETTES(Escavalier),
        ICON(Escavalier, 0),
        .footprint = gMonFootprint_Escavalier,
        LEARNSETS(Escavalier),
    },
#endif //P_FAMILY_KARRABLAST

#if P_FAMILY_FOONGUS
    [SPECIES_FOONGUS] =
    {
        .baseHP        = 69,
        .baseAttack    = 55,
        .baseDefense   = 45,
        .baseSpeed     = 15,
        .baseSpAttack  = 55,
        .baseSpDefense = 55,
        .types = { TYPE_GRASS, TYPE_POISON },
        .catchRate = 190,
        .expYield = 59,
        .evYield_HP = 1,
        .itemCommon = ITEM_TINY_MUSHROOM,
        .itemRare = ITEM_BIG_MUSHROOM,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_GRASS, EGG_GROUP_GRASS },
        .abilities = { ABILITY_EFFECT_SPORE, ABILITY_NONE, ABILITY_REGENERATOR },
        .bodyColor = BODY_COLOR_WHITE,
        .speciesName = _("Tarnpignon"),
        .cryId = CRY_FOONGUS,
        .natDexNum = NATIONAL_DEX_FOONGUS,
        .categoryName = _("Pilz"),
        .height = 2,
        .weight = 10,
        .description = POKEDEX_DESC_STRING(
            "Bis heute kann niemand genau sagen, wieso\n"
            "Tarnpignon ein Pokéball-Muster aufweisen\n"
            "und welchen Zweck dies erfüllt."),
        .pokemonScale = 682,
        .pokemonOffset = 24,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Foongus, 32, 32),
        .frontPicYOffset = 16,
        .frontAnimFrames = sAnims_Foongus,
        .frontAnimId = ANIM_SWING_CONCAVE_FAST,
        BACK_PIC(Foongus, 48, 40),
        .backPicYOffset = 13,
        .backAnimId = BACK_ANIM_SHRINK_GROW,
        PALETTES(Foongus),
        ICON(Foongus, 0),
        .footprint = gMonFootprint_Foongus,
        LEARNSETS(Foongus),
        .evolutions = EVOLUTION({EVO_LEVEL, 39, SPECIES_AMOONGUSS}),
    },

    [SPECIES_AMOONGUSS] =
    {
        .baseHP        = 114,
        .baseAttack    = 85,
        .baseDefense   = 70,
        .baseSpeed     = 30,
        .baseSpAttack  = 85,
        .baseSpDefense = 80,
        .types = { TYPE_GRASS, TYPE_POISON },
        .catchRate = 75,
        .expYield = 162,
        .evYield_HP = 2,
        .itemCommon = ITEM_TINY_MUSHROOM,
        .itemRare = ITEM_BIG_MUSHROOM,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_GRASS, EGG_GROUP_GRASS },
        .abilities = { ABILITY_EFFECT_SPORE, ABILITY_NONE, ABILITY_REGENERATOR },
        .bodyColor = BODY_COLOR_WHITE,
        .noFlip = TRUE,
        .speciesName = _("Hutsassa"),
        .cryId = CRY_AMOONGUSS,
        .natDexNum = NATIONAL_DEX_AMOONGUSS,
        .categoryName = _("Pilz"),
        .height = 6,
        .weight = 105,
        .description = POKEDEX_DESC_STRING(
            "Die meiste Zeit über bewegt es sich kaum\n"
            "und steht einfach nur regungslos neben\n"
            "Pokébällen, die am Boden liegen."),
        .pokemonScale = 422,
        .pokemonOffset = 13,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Amoonguss, 56, 56),
        .frontPicYOffset = 8,
        .frontAnimFrames = sAnims_Amoonguss,
        .frontAnimId = ANIM_H_SLIDE,
        BACK_PIC(Amoonguss, 64, 48),
        .backPicYOffset = 12,
        .backAnimId = BACK_ANIM_GROW_STUTTER,
        PALETTES(Amoonguss),
        ICON(Amoonguss, 1),
        .footprint = gMonFootprint_Amoonguss,
        LEARNSETS(Amoonguss),
    },
#endif //P_FAMILY_FOONGUS

#if P_FAMILY_FRILLISH
    [SPECIES_FRILLISH] =
    {
        .baseHP        = 55,
        .baseAttack    = 40,
        .baseDefense   = 50,
        .baseSpeed     = 40,
        .baseSpAttack  = 65,
        .baseSpDefense = 85,
        .types = { TYPE_WATER, TYPE_GHOST },
        .catchRate = 190,
        .expYield = 67,
        .evYield_SpDefense = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_AMORPHOUS, EGG_GROUP_AMORPHOUS },
        .abilities = { ABILITY_WATER_ABSORB, ABILITY_CURSED_BODY, ABILITY_DAMP },
        .bodyColor = BODY_COLOR_WHITE,
        .speciesName = _("Quabbel"),
        .cryId = CRY_FRILLISH,
        .natDexNum = NATIONAL_DEX_FRILLISH,
        .categoryName = _("Gleit"),
        .height = 12,
        .weight = 330,
        .description = POKEDEX_DESC_STRING(
            "Durch das Meer schwimmende Beute\n"
            "umschlingt es mit seinen schleierartigen\n"
            "Armen und zieht sie in die Tiefe."),
        .pokemonScale = 282,
        .pokemonOffset = 4,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Frillish, 56, 56),
        FRONT_PIC_FEMALE(Frillish, 56, 56),
        .frontPicYOffset = 5,
        .frontAnimFrames = sAnims_Frillish,
        .frontAnimId = ANIM_RISING_WOBBLE,
        BACK_PIC(Frillish, 40, 56),
        BACK_PIC_FEMALE(Frillish, 40, 56),
        .backPicYOffset = 7,
        .backAnimId = BACK_ANIM_CONVEX_DOUBLE_ARC,
        PALETTES(Frillish),
        PALETTE_FEMALE(Frillish),
        ICON(Frillish, 0),
        ICON_FEMALE(Frillish, 1),
        .footprint = gMonFootprint_Frillish,
        LEARNSETS(Frillish),
        .evolutions = EVOLUTION({EVO_LEVEL, 40, SPECIES_JELLICENT}),
    },

    [SPECIES_JELLICENT] =
    {
        .baseHP        = 100,
        .baseAttack    = 60,
        .baseDefense   = 70,
        .baseSpeed     = 60,
        .baseSpAttack  = 85,
        .baseSpDefense = 105,
        .types = { TYPE_WATER, TYPE_GHOST },
        .catchRate = 60,
        .expYield = 168,
        .evYield_SpDefense = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_AMORPHOUS, EGG_GROUP_AMORPHOUS },
        .abilities = { ABILITY_WATER_ABSORB, ABILITY_CURSED_BODY, ABILITY_DAMP },
        .bodyColor = BODY_COLOR_WHITE,
        .speciesName = _("Apoquallyp"),
        .cryId = CRY_JELLICENT,
        .natDexNum = NATIONAL_DEX_JELLICENT,
        .categoryName = _("Gleit"),
        .height = 22,
        .weight = 1350,
        .description = POKEDEX_DESC_STRING(
            "Bei Vollmond treiben Apoquallyp in\n"
            "Schwärmen an die Meeresoberfläche und\n"
            "lauern dort ihrer Beute auf."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 348,
        .trainerOffset = 6,
        FRONT_PIC(Jellicent, 64, 64),
        FRONT_PIC_FEMALE(Jellicent, 64, 64),
        .frontPicYOffset = 3,
        .frontAnimFrames = sAnims_Jellicent,
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(Jellicent, 64, 48),
        BACK_PIC_FEMALE(Jellicent, 64, 48),
        .backPicYOffset = 10,
        .backAnimId = BACK_ANIM_GROW_STUTTER,
        PALETTES(Jellicent),
        PALETTE_FEMALE(Jellicent),
        ICON(Jellicent, 0),
        ICON_FEMALE(Jellicent, 1),
        .footprint = gMonFootprint_Jellicent,
        LEARNSETS(Jellicent),
    },
#endif //P_FAMILY_FRILLISH

#if P_FAMILY_ALOMOMOLA
    [SPECIES_ALOMOMOLA] =
    {
        .baseHP        = 165,
        .baseAttack    = 75,
        .baseDefense   = 80,
        .baseSpeed     = 65,
        .baseSpAttack  = 40,
        .baseSpDefense = 45,
        .types = { TYPE_WATER, TYPE_WATER },
        .catchRate = 75,
        .expYield = 165,
        .evYield_HP = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 40,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_FAST,
        .eggGroups = { EGG_GROUP_WATER_1, EGG_GROUP_WATER_2 },
        .abilities = { ABILITY_HEALER, ABILITY_HYDRATION, ABILITY_REGENERATOR },
        .bodyColor = BODY_COLOR_PINK,
        .speciesName = _("Mamolida"),
        .cryId = CRY_ALOMOMOLA,
        .natDexNum = NATIONAL_DEX_ALOMOMOLA,
        .categoryName = _("Fürsorge"),
        .height = 12,
        .weight = 316,
        .description = POKEDEX_DESC_STRING(
            "Es treibt durch den Ozean. Um Mamolida\n"
            "versammeln sich stets viele\n"
            "Wasser-Pokémon."),
        .pokemonScale = 282,
        .pokemonOffset = 4,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Alomomola, 32, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_Alomomola,
        .frontAnimId = ANIM_SWING_CONCAVE,
        BACK_PIC(Alomomola, 48, 64),
        .backPicYOffset = 0,
        .backAnimId = BACK_ANIM_CONVEX_DOUBLE_ARC,
        PALETTES(Alomomola),
        ICON(Alomomola, 0),
        .footprint = gMonFootprint_Alomomola,
        LEARNSETS(Alomomola),
    },
#endif //P_FAMILY_ALOMOMOLA

#if P_FAMILY_JOLTIK
    [SPECIES_JOLTIK] =
    {
        .baseHP        = 50,
        .baseAttack    = 47,
        .baseDefense   = 50,
        .baseSpeed     = 65,
        .baseSpAttack  = 57,
        .baseSpDefense = 50,
        .types = { TYPE_BUG, TYPE_ELECTRIC },
        .catchRate = 190,
        .expYield = 64,
        .evYield_Speed = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_BUG, EGG_GROUP_BUG },
        .abilities = { ABILITY_COMPOUND_EYES, ABILITY_UNNERVE, ABILITY_SWARM },
        .bodyColor = BODY_COLOR_YELLOW,
        .speciesName = _("Wattzapf"),
        .cryId = CRY_JOLTIK,
        .natDexNum = NATIONAL_DEX_JOLTIK,
        .categoryName = _("Kleben"),
        .height = 1,
        .weight = 6,
        .description = POKEDEX_DESC_STRING(
            "Da es selbst keinen Strom erzeugen\n"
            "kann, klettert es auf andere\n"
            "Pokémon, um ihnen elektrostatische\n"
            "Energie abzusaugen."),
        .pokemonScale = 682,
        .pokemonOffset = 24,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Joltik, 32, 32),
        .frontPicYOffset = 17,
        .frontAnimFrames = sAnims_Joltik,
        .frontAnimId = ANIM_H_SLIDE,
        BACK_PIC(Joltik, 48, 32),
        .backPicYOffset = 19,
        .backAnimId = BACK_ANIM_H_SLIDE,
        PALETTES(Joltik),
        ICON(Joltik, 0),
        .footprint = gMonFootprint_Joltik,
        LEARNSETS(Joltik),
        .evolutions = EVOLUTION({EVO_LEVEL, 36, SPECIES_GALVANTULA}),
    },

    [SPECIES_GALVANTULA] =
    {
        .baseHP        = 70,
        .baseAttack    = 77,
        .baseDefense   = 60,
        .baseSpeed     = 108,
        .baseSpAttack  = 97,
        .baseSpDefense = 60,
        .types = { TYPE_BUG, TYPE_ELECTRIC },
        .catchRate = 75,
        .expYield = 165,
        .evYield_Speed = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_BUG, EGG_GROUP_BUG },
        .abilities = { ABILITY_COMPOUND_EYES, ABILITY_UNNERVE, ABILITY_SWARM },
        .bodyColor = BODY_COLOR_YELLOW,
        .speciesName = _("Voltula"),
        .cryId = CRY_GALVANTULA,
        .natDexNum = NATIONAL_DEX_GALVANTULA,
        .categoryName = _("Stromspinnen"),
        .height = 8,
        .weight = 143,
        .description = POKEDEX_DESC_STRING(
            "Lässt seine Beute in elektrisch\n"
            "geladene Fäden tappen. Solang diese\n"
            "durch den Schock gelähmt ist, labt\n"
            "es sich an ihr."),
        .pokemonScale = 366,
        .pokemonOffset = 10,
        .trainerScale = 257,
        .trainerOffset = 0,
        FRONT_PIC(Galvantula, 56, 48),
        .frontPicYOffset = 10,
        .frontAnimFrames = sAnims_Galvantula,
        .frontAnimId = ANIM_CIRCLE_C_CLOCKWISE_SLOW,
        BACK_PIC(Galvantula, 64, 40),
        .backPicYOffset = 18,
        .backAnimId = BACK_ANIM_SHAKE_FLASH_YELLOW,
        PALETTES(Galvantula),
        ICON(Galvantula, 2),
        .footprint = gMonFootprint_Galvantula,
        LEARNSETS(Galvantula),
    },
#endif //P_FAMILY_JOLTIK

#if P_FAMILY_FERROSEED
    [SPECIES_FERROSEED] =
    {
        .baseHP        = 44,
        .baseAttack    = 50,
        .baseDefense   = 91,
        .baseSpeed     = 10,
        .baseSpAttack  = 24,
        .baseSpDefense = 86,
        .types = { TYPE_GRASS, TYPE_STEEL },
        .catchRate = 255,
        .expYield = 61,
        .evYield_Defense = 1,
        .itemRare = ITEM_STICKY_BARB,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_GRASS, EGG_GROUP_MINERAL },
        .abilities = { ABILITY_IRON_BARBS, ABILITY_NONE },
        .bodyColor = BODY_COLOR_GRAY,
        .speciesName = _("Kastadur"),
        .cryId = CRY_FERROSEED,
        .natDexNum = NATIONAL_DEX_FERROSEED,
        .categoryName = _("Dornfrucht"),
        .height = 6,
        .weight = 188,
        .description = POKEDEX_DESC_STRING(
            "Fühlt es sich bedroht, wehrt es\n"
            "sich, indem es eine großzügige\n"
            "Salve Dornen abfeuert."),
        .pokemonScale = 422,
        .pokemonOffset = 14,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Ferroseed, 32, 40),
        .frontPicYOffset = 12,
        .frontAnimFrames = sAnims_Ferroseed,
        .frontAnimId = ANIM_H_VIBRATE,
        BACK_PIC(Ferroseed, 48, 40),
        .backPicYOffset = 15,
        .backAnimId = BACK_ANIM_H_SHAKE,
        PALETTES(Ferroseed),
        ICON(Ferroseed, 1),
        .footprint = gMonFootprint_Ferroseed,
        LEARNSETS(Ferroseed),
        .evolutions = EVOLUTION({EVO_LEVEL, 40, SPECIES_FERROTHORN}),
    },

    [SPECIES_FERROTHORN] =
    {
        .baseHP        = 74,
        .baseAttack    = 94,
        .baseDefense   = 131,
        .baseSpeed     = 20,
        .baseSpAttack  = 54,
        .baseSpDefense = 116,
        .types = { TYPE_GRASS, TYPE_STEEL },
        .catchRate = 90,
        .expYield = 171,
        .evYield_Defense = 2,
        .itemRare = ITEM_STICKY_BARB,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_GRASS, EGG_GROUP_MINERAL },
        .abilities = { ABILITY_IRON_BARBS, ABILITY_NONE, ABILITY_ANTICIPATION },
        .bodyColor = BODY_COLOR_GRAY,
        .speciesName = _("Tentantel"),
        .cryId = CRY_FERROTHORN,
        .natDexNum = NATIONAL_DEX_FERROTHORN,
        .categoryName = _("Dornkugel"),
        .height = 10,
        .weight = 1100,
        .description = POKEDEX_DESC_STRING(
            "Es setzt sich an der Decke von Höhlen fest\n"
            "und wirft seine dornengespickten Schlingen\n"
            "auf vorbeigehende Beute ab."),
        .pokemonScale = 305,
        .pokemonOffset = 7,
        .trainerScale = 257,
        .trainerOffset = 0,
        FRONT_PIC(Ferrothorn, 64, 64),
        .frontPicYOffset = 4,
        .frontAnimFrames = sAnims_Ferrothorn,
        .frontAnimId = ANIM_V_SHAKE,
        .enemyMonElevation = 10,
        BACK_PIC(Ferrothorn, 64, 40),
        .backPicYOffset = 14,
        .backAnimId = BACK_ANIM_V_SHAKE_LOW,
        PALETTES(Ferrothorn),
        ICON(Ferrothorn, 1),
        .footprint = gMonFootprint_Ferrothorn,
        LEARNSETS(Ferrothorn),
    },
#endif //P_FAMILY_FERROSEED

#if P_FAMILY_KLINK
    [SPECIES_KLINK] =
    {
        .baseHP        = 40,
        .baseAttack    = 55,
        .baseDefense   = 70,
        .baseSpeed     = 30,
        .baseSpAttack  = 45,
        .baseSpDefense = 60,
        .types = { TYPE_STEEL, TYPE_STEEL },
        .catchRate = 130,
        .expYield = 60,
        .evYield_Defense = 1,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_MINERAL, EGG_GROUP_MINERAL },
        .abilities = { ABILITY_PLUS, ABILITY_MINUS, ABILITY_CLEAR_BODY },
        .bodyColor = BODY_COLOR_GRAY,
        .noFlip = TRUE,
        .speciesName = _("Klikk"),
        .cryId = CRY_KLINK,
        .natDexNum = NATIONAL_DEX_KLINK,
        .categoryName = _("Getriebe"),
        .height = 3,
        .weight = 210,
        .description = POKEDEX_DESC_STRING(
            "Es gewinnt lebenswichtige Energie,\n"
            "indem es seine zwei Einzelteile\n"
            "ineinander verzahnt und rotieren\n"
            "lässt."),
        .pokemonScale = 530,
        .pokemonOffset = 15,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Klink, 48, 40),
        .frontPicYOffset = 12,
        .frontAnimFrames = sAnims_Klink,
        .frontAnimId = ANIM_CIRCULAR_STRETCH_TWICE,
        .enemyMonElevation = 12,
        BACK_PIC(Klink, 64, 64),
        .backPicYOffset = 17,
        .backAnimId = BACK_ANIM_TRIANGLE_DOWN,
        PALETTES(Klink),
        ICON(Klink, 0),
        .footprint = gMonFootprint_Klink,
        LEARNSETS(Klink),
        .evolutions = EVOLUTION({EVO_LEVEL, 38, SPECIES_KLANG}),
    },

    [SPECIES_KLANG] =
    {
        .baseHP        = 60,
        .baseAttack    = 80,
        .baseDefense   = 95,
        .baseSpeed     = 50,
        .baseSpAttack  = 70,
        .baseSpDefense = 85,
        .types = { TYPE_STEEL, TYPE_STEEL },
        .catchRate = 60,
        .expYield = 154,
        .evYield_Defense = 2,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_MINERAL, EGG_GROUP_MINERAL },
        .abilities = { ABILITY_PLUS, ABILITY_MINUS, ABILITY_CLEAR_BODY },
        .bodyColor = BODY_COLOR_GRAY,
        .noFlip = TRUE,
        .speciesName = _("Kliklak"),
        .cryId = CRY_KLANG,
        .natDexNum = NATIONAL_DEX_KLANG,
        .categoryName = _("Getriebe"),
        .height = 6,
        .weight = 510,
        .description = POKEDEX_DESC_STRING(
            "Macht es Ernst, greift das kleine äußere\n"
            "Rad in das große Rad, was die\n"
            "Drehgeschwindigkeit merklich erhöht."),
        .pokemonScale = 422,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Klang, 64, 56),
        .frontPicYOffset = 7,
        .frontAnimFrames = sAnims_Klang,
        .frontAnimId = ANIM_CIRCULAR_STRETCH_TWICE,
        .enemyMonElevation = 8,
        BACK_PIC(Klang, 64, 64),
        .backPicYOffset = 7,
        .backAnimId = BACK_ANIM_CONVEX_DOUBLE_ARC,
        PALETTES(Klang),
        ICON(Klang, 0),
        .footprint = gMonFootprint_Klang,
        LEARNSETS(Klang),
        .evolutions = EVOLUTION({EVO_LEVEL, 49, SPECIES_KLINKLANG}),
    },

    [SPECIES_KLINKLANG] =
    {
        .baseHP        = 60,
        .baseAttack    = 100,
        .baseDefense   = 115,
        .baseSpeed     = 90,
        .baseSpAttack  = 70,
        .baseSpDefense = 85,
        .types = { TYPE_STEEL, TYPE_STEEL },
        .catchRate = 30,
        .expYield = 234,
        .evYield_Defense = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_MINERAL, EGG_GROUP_MINERAL },
        .abilities = { ABILITY_PLUS, ABILITY_MINUS, ABILITY_CLEAR_BODY },
        .bodyColor = BODY_COLOR_GRAY,
        .noFlip = TRUE,
        .speciesName = _("Klikdiklak"),
        .cryId = CRY_KLINKLANG,
        .natDexNum = NATIONAL_DEX_KLINKLANG,
        .categoryName = _("Getriebe"),
        .height = 6,
        .weight = 810,
        .description = POKEDEX_DESC_STRING(
            "Der rote Zentralbestandteil dient als\n"
            "Energiespeicher. Darin geladene Energie\n"
            "feuert es über seine Stacheln ab."),
        .pokemonScale = 422,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Klinklang, 64, 64),
        .frontPicYOffset = 2,
        .frontAnimFrames = sAnims_Klinklang,
        .frontAnimId = ANIM_CIRCULAR_STRETCH_TWICE,
        .enemyMonElevation = 4,
        BACK_PIC(Klinklang, 64, 64),
        .backPicYOffset = 7,
        .backAnimId = BACK_ANIM_CIRCLE_COUNTERCLOCKWISE,
        PALETTES(Klinklang),
        ICON(Klinklang, 0),
        .footprint = gMonFootprint_Klinklang,
        LEARNSETS(Klinklang),
    },
#endif //P_FAMILY_KLINK

#if P_FAMILY_TYNAMO
    [SPECIES_TYNAMO] =
    {
        .baseHP        = 35,
        .baseAttack    = 55,
        .baseDefense   = 40,
        .baseSpeed     = 60,
        .baseSpAttack  = 45,
        .baseSpDefense = 40,
        .types = { TYPE_ELECTRIC, TYPE_ELECTRIC },
        .catchRate = 190,
        .expYield = 55,
        .evYield_Speed = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_AMORPHOUS, EGG_GROUP_AMORPHOUS },
        .abilities = { ABILITY_LEVITATE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_WHITE,
        .speciesName = _("Zapplardin"),
        .cryId = CRY_TYNAMO,
        .natDexNum = NATIONAL_DEX_TYNAMO,
        .categoryName = _("Stromfisch"),
        .height = 2,
        .weight = 3,
        .description = POKEDEX_DESC_STRING(
            "Allein erzeugt es nur wenig Strom,\n"
            "doch tritt es geschlossen im\n"
            "Schwarm auf, gleicht seine Kraft\n"
            "der eines Blitzes."),
        .pokemonScale = 682,
        .pokemonOffset = 24,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Tynamo, 40, 24),
        .frontPicYOffset = 22,
        .frontAnimFrames = sAnims_Tynamo,
        .frontAnimId = ANIM_V_SLIDE_WOBBLE_SMALL,
        .enemyMonElevation = 16,
        BACK_PIC(Tynamo, 64, 24),
        .backPicYOffset = 21,
        .backAnimId = BACK_ANIM_H_SLIDE,
        PALETTES(Tynamo),
        ICON(Tynamo, 0),
        .footprint = gMonFootprint_Tynamo,
        LEARNSETS(Tynamo),
        .evolutions = EVOLUTION({EVO_LEVEL, 39, SPECIES_EELEKTRIK}),
    },

    [SPECIES_EELEKTRIK] =
    {
        .baseHP        = 65,
        .baseAttack    = 85,
        .baseDefense   = 70,
        .baseSpeed     = 40,
        .baseSpAttack  = 75,
        .baseSpDefense = 70,
        .types = { TYPE_ELECTRIC, TYPE_ELECTRIC },
        .catchRate = 60,
        .expYield = 142,
        .evYield_Attack = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_AMORPHOUS, EGG_GROUP_AMORPHOUS },
        .abilities = { ABILITY_LEVITATE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Zapplalek"),
        .cryId = CRY_EELEKTRIK,
        .natDexNum = NATIONAL_DEX_EELEKTRIK,
        .categoryName = _("Stromfisch"),
        .height = 12,
        .weight = 220,
        .description = POKEDEX_DESC_STRING(
            "Schlingt sich um Gegner, lähmt sie\n"
            "über die rund gemaserten Flächen an\n"
            "seinem Körper mit Strom und beißt\n"
            "beherzt zu."),
        .pokemonScale = 282,
        .pokemonOffset = 4,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Eelektrik, 48, 64),
        .frontPicYOffset = 6,
        .frontAnimFrames = sAnims_Eelektrik,
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .enemyMonElevation = 8,
        BACK_PIC(Eelektrik, 56, 64),
        .backPicYOffset = 4,
        .backAnimId = BACK_ANIM_SHRINK_GROW,
        PALETTES(Eelektrik),
        ICON(Eelektrik, 0),
        .footprint = gMonFootprint_Eelektrik,
        LEARNSETS(Eelektrik),
        .evolutions = EVOLUTION({EVO_ITEM, ITEM_THUNDER_STONE, SPECIES_EELEKTROSS}),
    },

    [SPECIES_EELEKTROSS] =
    {
        .baseHP        = 85,
        .baseAttack    = 115,
        .baseDefense   = 80,
        .baseSpeed     = 50,
        .baseSpAttack  = 105,
        .baseSpDefense = 80,
        .types = { TYPE_ELECTRIC, TYPE_ELECTRIC },
        .catchRate = 30,
        .expYield = 232,
        .evYield_Attack = 3,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_AMORPHOUS, EGG_GROUP_AMORPHOUS },
        .abilities = { ABILITY_LEVITATE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Zapplarang"),
        .cryId = CRY_EELEKTROSS,
        .natDexNum = NATIONAL_DEX_EELEKTROSS,
        .categoryName = _("Stromfisch"),
        .height = 21,
        .weight = 805,
        .description = POKEDEX_DESC_STRING(
            "Es schleppt sich mithilfe seiner Arme an\n"
            "Land, schnappt nach seiner Beute und zerrt\n"
            "sie augenblicklich ins Meer."),
        .pokemonScale = 256,
        .pokemonOffset = 1,
        .trainerScale = 365,
        .trainerOffset = 7,
        FRONT_PIC(Eelektross, 64, 56),
        .frontPicYOffset = 6,
        .frontAnimFrames = sAnims_Eelektross,
        .frontAnimId = ANIM_BOUNCE_ROTATE_TO_SIDES_SMALL_SLOW,
        .enemyMonElevation = 8,
        BACK_PIC(Eelektross, 64, 64),
        .backPicYOffset = 0,
        .backAnimId = BACK_ANIM_SHAKE_FLASH_YELLOW,
        PALETTES(Eelektross),
        ICON(Eelektross, 0),
        .footprint = gMonFootprint_Eelektross,
        LEARNSETS(Eelektross),
    },
#endif //P_FAMILY_TYNAMO

#if P_FAMILY_ELGYEM
    [SPECIES_ELGYEM] =
    {
        .baseHP        = 55,
        .baseAttack    = 55,
        .baseDefense   = 55,
        .baseSpeed     = 30,
        .baseSpAttack  = 85,
        .baseSpDefense = 55,
        .types = { TYPE_PSYCHIC, TYPE_PSYCHIC },
        .catchRate = 255,
        .expYield = 67,
        .evYield_SpAttack = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_HUMAN_LIKE, EGG_GROUP_HUMAN_LIKE },
        .abilities = { ABILITY_TELEPATHY, ABILITY_SYNCHRONIZE, ABILITY_ANALYTIC },
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Pygraulon"),
        .cryId = CRY_ELGYEM,
        .natDexNum = NATIONAL_DEX_ELGYEM,
        .categoryName = _("Grips"),
        .height = 5,
        .weight = 90,
        .description = POKEDEX_DESC_STRING(
            "Ein Pokémon, das vor 50 Jahren entdeckt\n"
            "wurde. Sein hochentwickeltes Gehirn\n"
            "verleiht ihm Psycho-Kräfte."),
        .pokemonScale = 432,
        .pokemonOffset = 13,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Elgyem, 32, 48),
        .frontPicYOffset = 11,
        .frontAnimFrames = sAnims_Elgyem,
        .frontAnimId = ANIM_RISING_WOBBLE,
        BACK_PIC(Elgyem, 48, 56),
        .backPicYOffset = 10,
        .backAnimId = BACK_ANIM_SHRINK_GROW,
        PALETTES(Elgyem),
        ICON(Elgyem, 0),
        .footprint = gMonFootprint_Elgyem,
        LEARNSETS(Elgyem),
        .evolutions = EVOLUTION({EVO_LEVEL, 42, SPECIES_BEHEEYEM}),
    },

    [SPECIES_BEHEEYEM] =
    {
        .baseHP        = 75,
        .baseAttack    = 75,
        .baseDefense   = 75,
        .baseSpeed     = 40,
        .baseSpAttack  = 125,
        .baseSpDefense = 95,
        .types = { TYPE_PSYCHIC, TYPE_PSYCHIC },
        .catchRate = 90,
        .expYield = 170,
        .evYield_SpAttack = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_HUMAN_LIKE, EGG_GROUP_HUMAN_LIKE },
        .abilities = { ABILITY_TELEPATHY, ABILITY_SYNCHRONIZE, ABILITY_ANALYTIC },
        .bodyColor = BODY_COLOR_BROWN,
        .speciesName = _("Megalon"),
        .cryId = CRY_BEHEEYEM,
        .natDexNum = NATIONAL_DEX_BEHEEYEM,
        .categoryName = _("Grips"),
        .height = 10,
        .weight = 345,
        .description = POKEDEX_DESC_STRING(
            "Es manipuliert die Gehirne seiner Gegner\n"
            "mit Psycho-Kräften, indem es die Bilder\n"
            "ihrer Erinnerungen umgestaltet."),
        .pokemonScale = 305,
        .pokemonOffset = 7,
        .trainerScale = 257,
        .trainerOffset = 0,
        FRONT_PIC(Beheeyem, 48, 56),
        .frontPicYOffset = 4,
        .frontAnimFrames = sAnims_Beheeyem,
        .frontAnimId = ANIM_GROW_VIBRATE,
        BACK_PIC(Beheeyem, 64, 64),
        .backPicYOffset = 0,
        .backAnimId = BACK_ANIM_H_SHAKE,
        PALETTES(Beheeyem),
        ICON(Beheeyem, 2),
        .footprint = gMonFootprint_Beheeyem,
        LEARNSETS(Beheeyem),
    },
#endif //P_FAMILY_ELGYEM

#if P_FAMILY_LITWICK
    [SPECIES_LITWICK] =
    {
        .baseHP        = 50,
        .baseAttack    = 30,
        .baseDefense   = 55,
        .baseSpeed     = 20,
        .baseSpAttack  = 65,
        .baseSpDefense = 55,
        .types = { TYPE_GHOST, TYPE_FIRE },
        .catchRate = 190,
        .expYield = 55,
        .evYield_SpAttack = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_AMORPHOUS, EGG_GROUP_AMORPHOUS },
        #if P_UPDATED_ABILITIES >= GEN_6
            .abilities = { ABILITY_FLASH_FIRE, ABILITY_FLAME_BODY, ABILITY_INFILTRATOR },
        #else
            .abilities = { ABILITY_FLASH_FIRE, ABILITY_FLAME_BODY, ABILITY_SHADOW_TAG },
        #endif
        .bodyColor = BODY_COLOR_WHITE,
        .noFlip = TRUE,
        .speciesName = _("Lichtel"),
        .cryId = CRY_LITWICK,
        .natDexNum = NATIONAL_DEX_LITWICK,
        .categoryName = _("Kerzen"),
        .height = 3,
        .weight = 31,
        .description = POKEDEX_DESC_STRING(
            "Es entfacht eine Flamme, die von der\n"
            "Lebensenergie eines Menschen oder eines\n"
            "Pokémon zehrt."),
        .pokemonScale = 530,
        .pokemonOffset = 13,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Litwick, 32, 40),
        .frontPicYOffset = 14,
        .frontAnimFrames = sAnims_Litwick,
        .frontAnimId = ANIM_V_STRETCH,
        BACK_PIC(Litwick, 40, 40),
        .backPicYOffset = 14,
        .backAnimId = BACK_ANIM_SHRINK_GROW,
        PALETTES(Litwick),
        ICON(Litwick, 2),
        .footprint = gMonFootprint_Litwick,
        LEARNSETS(Litwick),
        .evolutions = EVOLUTION({EVO_LEVEL, 41, SPECIES_LAMPENT}),
    },

    [SPECIES_LAMPENT] =
    {
        .baseHP        = 60,
        .baseAttack    = 40,
        .baseDefense   = 60,
        .baseSpeed     = 55,
        .baseSpAttack  = 95,
        .baseSpDefense = 60,
        .types = { TYPE_GHOST, TYPE_FIRE },
        .catchRate = 90,
        .expYield = 130,
        .evYield_SpAttack = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_AMORPHOUS, EGG_GROUP_AMORPHOUS },
        #if P_UPDATED_ABILITIES >= GEN_6
            .abilities = { ABILITY_FLASH_FIRE, ABILITY_FLAME_BODY, ABILITY_INFILTRATOR },
        #else
            .abilities = { ABILITY_FLASH_FIRE, ABILITY_FLAME_BODY, ABILITY_SHADOW_TAG },
        #endif
        .bodyColor = BODY_COLOR_BLACK,
        .speciesName = _("Laternecto"),
        .cryId = CRY_LAMPENT,
        .natDexNum = NATIONAL_DEX_LAMPENT,
        .categoryName = _("Lampen"),
        .height = 6,
        .weight = 130,
        .description = POKEDEX_DESC_STRING(
            "Es wird als Todesbote gefürchtet, da es\n"
            "oft in der Nähe von Menschen auftaucht,\n"
            "deren Ende kurz bevorsteht."),
        .pokemonScale = 422,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Lampent, 56, 48),
        .frontPicYOffset = 8,
        .frontAnimFrames = sAnims_Lampent,
        .frontAnimId = ANIM_V_SLIDE_WOBBLE,
        .enemyMonElevation = 6,
        BACK_PIC(Lampent, 56, 48),
        .backPicYOffset = 12,
        .backAnimId = BACK_ANIM_TRIANGLE_DOWN,
        PALETTES(Lampent),
        ICON(Lampent, 2),
        .footprint = gMonFootprint_Lampent,
        LEARNSETS(Lampent),
        .evolutions = EVOLUTION({EVO_ITEM, ITEM_DUSK_STONE, SPECIES_CHANDELURE}),
    },

    [SPECIES_CHANDELURE] =
    {
        .baseHP        = 60,
        .baseAttack    = 55,
        .baseDefense   = 90,
        .baseSpeed     = 80,
        .baseSpAttack  = 145,
        .baseSpDefense = 90,
        .types = { TYPE_GHOST, TYPE_FIRE },
        .catchRate = 45,
        .expYield = 234,
        .evYield_SpAttack = 3,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_AMORPHOUS, EGG_GROUP_AMORPHOUS },
        #if P_UPDATED_ABILITIES >= GEN_6
            .abilities = { ABILITY_FLASH_FIRE, ABILITY_FLAME_BODY, ABILITY_INFILTRATOR },
        #else
            .abilities = { ABILITY_FLASH_FIRE, ABILITY_FLAME_BODY, ABILITY_SHADOW_TAG },
        #endif
        .bodyColor = BODY_COLOR_BLACK,
        .speciesName = _("Skelabra"),
        .cryId = CRY_CHANDELURE,
        .natDexNum = NATIONAL_DEX_CHANDELURE,
        .categoryName = _("Geleit"),
        .height = 10,
        .weight = 343,
        .description = POKEDEX_DESC_STRING(
            "Es saugt die Seele eines jeden auf,\n"
            "der in seinen Feuerkranz gerät, bis\n"
            "nur noch eine leere Hülle von ihm\n"
            "übrig ist."),
        .pokemonScale = 305,
        .pokemonOffset = 7,
        .trainerScale = 257,
        .trainerOffset = 0,
        FRONT_PIC(Chandelure, 64, 64),
        .frontPicYOffset = 4,
        .frontAnimFrames = sAnims_Chandelure,
        .frontAnimId = ANIM_H_SLIDE_WOBBLE,
        .enemyMonElevation = 6,
        BACK_PIC(Chandelure, 64, 64),
        .backPicYOffset = 0,
        .backAnimId = BACK_ANIM_CONVEX_DOUBLE_ARC,
        PALETTES(Chandelure),
        ICON(Chandelure, 2),
        .footprint = gMonFootprint_Chandelure,
        LEARNSETS(Chandelure),
    },
#endif //P_FAMILY_LITWICK

#if P_FAMILY_AXEW
    [SPECIES_AXEW] =
    {
        .baseHP        = 46,
        .baseAttack    = 87,
        .baseDefense   = 60,
        .baseSpeed     = 57,
        .baseSpAttack  = 30,
        .baseSpDefense = 40,
        .types = { TYPE_DRAGON, TYPE_DRAGON },
        .catchRate = 75,
        .expYield = 64,
        .evYield_Attack = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 40,
        .friendship = 35,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_MONSTER, EGG_GROUP_DRAGON },
        .abilities = { ABILITY_RIVALRY, ABILITY_MOLD_BREAKER, ABILITY_UNNERVE },
        .bodyColor = BODY_COLOR_GREEN,
        .speciesName = _("Milza"),
        .cryId = CRY_AXEW,
        .natDexNum = NATIONAL_DEX_AXEW,
        .categoryName = _("Stoßzahn"),
        .height = 6,
        .weight = 180,
        .description = POKEDEX_DESC_STRING(
            "Sie rammen sich spielerisch mit ihren\n"
            "Fangzähnen. Brechen diese ab, wachsen sie\n"
            "sofort nach."),
        .pokemonScale = 422,
        .pokemonOffset = 13,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Axew, 40, 48),
        .frontPicYOffset = 12,
        .frontAnimFrames = sAnims_Axew,
        .frontAnimId = ANIM_H_SHAKE,
        BACK_PIC(Axew, 48, 56),
        .backPicYOffset = 8,
        .backAnimId = BACK_ANIM_CONCAVE_ARC_SMALL,
        PALETTES(Axew),
        ICON(Axew, 1),
        .footprint = gMonFootprint_Axew,
        LEARNSETS(Axew),
        .evolutions = EVOLUTION({EVO_LEVEL, 38, SPECIES_FRAXURE}),
    },

    [SPECIES_FRAXURE] =
    {
        .baseHP        = 66,
        .baseAttack    = 117,
        .baseDefense   = 70,
        .baseSpeed     = 67,
        .baseSpAttack  = 40,
        .baseSpDefense = 50,
        .types = { TYPE_DRAGON, TYPE_DRAGON },
        .catchRate = 60,
        .expYield = 144,
        .evYield_Attack = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 40,
        .friendship = 35,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_MONSTER, EGG_GROUP_DRAGON },
        .abilities = { ABILITY_RIVALRY, ABILITY_MOLD_BREAKER, ABILITY_UNNERVE },
        .bodyColor = BODY_COLOR_GREEN,
        .speciesName = _("Sharfax"),
        .cryId = CRY_FRAXURE,
        .natDexNum = NATIONAL_DEX_FRAXURE,
        .categoryName = _("Beilkiefer"),
        .height = 10,
        .weight = 360,
        .description = POKEDEX_DESC_STRING(
            "Da seine Hauer nicht mehr nachwachsen,\n"
            "wetzt es sie nach einem Kampf behutsam an\n"
            "den Felsen eines Flussbettes."),
        .pokemonScale = 305,
        .pokemonOffset = 7,
        .trainerScale = 257,
        .trainerOffset = 0,
        FRONT_PIC(Fraxure, 56, 56),
        .frontPicYOffset = 5,
        .frontAnimFrames = sAnims_Fraxure,
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(Fraxure, 64, 48),
        .backPicYOffset = 13,
        .backAnimId = BACK_ANIM_V_SHAKE_H_SLIDE,
        PALETTES(Fraxure),
        ICON(Fraxure, 1),
        .footprint = gMonFootprint_Fraxure,
        LEARNSETS(Fraxure),
        .evolutions = EVOLUTION({EVO_LEVEL, 48, SPECIES_HAXORUS}),
    },

    [SPECIES_HAXORUS] =
    {
        .baseHP        = 76,
        .baseAttack    = 147,
        .baseDefense   = 90,
        .baseSpeed     = 97,
        .baseSpAttack  = 60,
        .baseSpDefense = 70,
        .types = { TYPE_DRAGON, TYPE_DRAGON },
        .catchRate = 45,
        .expYield = 243,
        .evYield_Attack = 3,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 40,
        .friendship = 35,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_MONSTER, EGG_GROUP_DRAGON },
        .abilities = { ABILITY_RIVALRY, ABILITY_MOLD_BREAKER, ABILITY_UNNERVE },
        .bodyColor = BODY_COLOR_YELLOW,
        .speciesName = _("Maxax"),
        .cryId = CRY_HAXORUS,
        .natDexNum = NATIONAL_DEX_HAXORUS,
        .categoryName = _("Beilkiefer"),
        .height = 18,
        .weight = 1055,
        .description = POKEDEX_DESC_STRING(
            "Wenn es mit seinen robusten Hauern Stahl\n"
            "durchbohrt, bleiben diese unversehrt. Es\n"
            "ist von einem festen Panzer umgeben."),
        .pokemonScale = 267,
        .pokemonOffset = 2,
        .trainerScale = 286,
        .trainerOffset = 1,
        FRONT_PIC(Haxorus, 64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_Haxorus,
        .frontAnimId = ANIM_H_SHAKE,
        BACK_PIC(Haxorus, 64, 56),
        .backPicYOffset = 8,
        .backAnimId = BACK_ANIM_V_SHAKE_LOW,
        PALETTES(Haxorus),
        ICON(Haxorus, 2),
        .footprint = gMonFootprint_Haxorus,
        LEARNSETS(Haxorus),
    },
#endif //P_FAMILY_AXEW

#if P_FAMILY_CUBCHOO
    [SPECIES_CUBCHOO] =
    {
        .baseHP        = 55,
        .baseAttack    = 70,
        .baseDefense   = 40,
        .baseSpeed     = 40,
        .baseSpAttack  = 60,
        .baseSpDefense = 40,
        .types = { TYPE_ICE, TYPE_ICE },
        .catchRate = 120,
        .expYield = 61,
        .evYield_Attack = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD },
        .abilities = { ABILITY_SNOW_CLOAK, ABILITY_SLUSH_RUSH, ABILITY_RATTLED },
        .bodyColor = BODY_COLOR_WHITE,
        .speciesName = _("Petznief"),
        .cryId = CRY_CUBCHOO,
        .natDexNum = NATIONAL_DEX_CUBCHOO,
        .categoryName = _("Eisschollen"),
        .height = 5,
        .weight = 85,
        .description = POKEDEX_DESC_STRING(
            "Fühlt es sich wohl, erhöht sich die\n"
            "Klebrigkeit seines Nasenschleims. Wer es\n"
            "verärgert, wird damit angeschmiert."),
        .pokemonScale = 432,
        .pokemonOffset = 15,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Cubchoo, 32, 40),
        .frontPicYOffset = 12,
        .frontAnimFrames = sAnims_Cubchoo,
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(Cubchoo, 40, 40),
        .backPicYOffset = 12,
        .backAnimId = BACK_ANIM_H_SLIDE,
        PALETTES(Cubchoo),
        ICON(Cubchoo, 0),
        .footprint = gMonFootprint_Cubchoo,
        LEARNSETS(Cubchoo),
        .evolutions = EVOLUTION({EVO_LEVEL, 37, SPECIES_BEARTIC}),
    },

    [SPECIES_BEARTIC] =
    {
        .baseHP        = 95,
        .baseAttack    = P_UPDATED_STATS >= GEN_7 ? 130 : 110,
        .baseDefense   = 80,
        .baseSpeed     = 50,
        .baseSpAttack  = 70,
        .baseSpDefense = 80,
        .types = { TYPE_ICE, TYPE_ICE },
        .catchRate = 60,
        .expYield = 177,
        .evYield_Attack = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD },
        .abilities = { ABILITY_SNOW_CLOAK, ABILITY_SLUSH_RUSH, ABILITY_SWIFT_SWIM },
        .bodyColor = BODY_COLOR_WHITE,
        .speciesName = _("Siberio"),
        .cryId = CRY_BEARTIC,
        .natDexNum = NATIONAL_DEX_BEARTIC,
        .categoryName = _("Packeis"),
        .height = 26,
        .weight = 2600,
        .description = POKEDEX_DESC_STRING(
            "Kämpft mit Reißzähnen aus Eis, die es aus\n"
            "gefrorenem Atem herstellt. Es lebt im\n"
            "Norden, wo es kalt ist."),
        .pokemonScale = 266,
        .pokemonOffset = 3,
        .trainerScale = 399,
        .trainerOffset = 4,
        FRONT_PIC(Beartic, 64, 64),
        .frontPicYOffset = 1,
        .frontAnimFrames = sAnims_Beartic,
        .frontAnimId = ANIM_H_SHAKE,
        BACK_PIC(Beartic, 64, 64),
        .backPicYOffset = 5,
        .backAnimId = BACK_ANIM_V_SHAKE_H_SLIDE,
        PALETTES(Beartic),
        ICON(Beartic, 0),
        .footprint = gMonFootprint_Beartic,
        LEARNSETS(Beartic),
    },
#endif //P_FAMILY_CUBCHOO

#if P_FAMILY_CRYOGONAL
    [SPECIES_CRYOGONAL] =
    {
        .baseAttack    = 50,
        .baseSpeed     = 105,
        .baseSpAttack  = 95,
        .baseSpDefense = 135,
        #if P_UPDATED_STATS >= GEN_7
            .baseHP        = 80,
            .baseDefense   = 50,
        #else
            .baseHP        = 70,
            .baseDefense   = 30,
        #endif
        .types = { TYPE_ICE, TYPE_ICE },
        .catchRate = 25,
        .expYield = 180,
        .evYield_SpDefense = 2,
        .itemRare = ITEM_NEVER_MELT_ICE,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 25,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_MINERAL, EGG_GROUP_MINERAL },
        .abilities = { ABILITY_LEVITATE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Frigometri"),
        .cryId = CRY_CRYOGONAL,
        .natDexNum = NATIONAL_DEX_CRYOGONAL,
        .categoryName = _("Kristall"),
        .height = 11,
        .weight = 1480,
        .description = POKEDEX_DESC_STRING(
            "Bei Hitze wird es zu Wasserdampf. Im\n"
            "Sommer bekommt man es daher kaum zu\n"
            "Gesicht."),
        .pokemonScale = 320,
        .pokemonOffset = 7,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Cryogonal, 56, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_Cryogonal,
        .frontAnimId = ANIM_SHRINK_GROW,
        .enemyMonElevation = 3,
        BACK_PIC(Cryogonal, 56, 64),
        .backPicYOffset = 4,
        .backAnimId = BACK_ANIM_H_VIBRATE,
        PALETTES(Cryogonal),
        ICON(Cryogonal, 0),
        .footprint = gMonFootprint_Cryogonal,
        LEARNSETS(Cryogonal),
    },
#endif //P_FAMILY_CRYOGONAL

#if P_FAMILY_SHELMET
    [SPECIES_SHELMET] =
    {
        .baseHP        = 50,
        .baseAttack    = 40,
        .baseDefense   = 85,
        .baseSpeed     = 25,
        .baseSpAttack  = 40,
        .baseSpDefense = 65,
        .types = { TYPE_BUG, TYPE_BUG },
        .catchRate = 200,
        .expYield = 61,
        .evYield_Defense = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_BUG, EGG_GROUP_BUG },
        .abilities = { ABILITY_HYDRATION, ABILITY_SHELL_ARMOR, ABILITY_OVERCOAT },
        .bodyColor = BODY_COLOR_RED,
        .speciesName = _("Schnuthelm"),
        .cryId = CRY_SHELMET,
        .natDexNum = NATIONAL_DEX_SHELMET,
        .categoryName = _("Schnecken"),
        .height = 4,
        .weight = 77,
        .description = POKEDEX_DESC_STRING(
            "Führt man ihm zusammen mit Laukaps\n"
            "elektrische Energie zu, entwickelt es\n"
            "sich. Niemand kennt den Grund dafür."),
        .pokemonScale = 491,
        .pokemonOffset = 15,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Shelmet, 40, 40),
        .frontPicYOffset = 14,
        .frontAnimFrames = sAnims_Shelmet,
        .frontAnimId = ANIM_TWIST,
        BACK_PIC(Shelmet, 64, 32),
        .backPicYOffset = 19,
        .backAnimId = BACK_ANIM_V_SHAKE,
        PALETTES(Shelmet),
        ICON(Shelmet, 1),
        .footprint = gMonFootprint_Shelmet,
        LEARNSETS(Shelmet),
        .evolutions = EVOLUTION({EVO_TRADE_SPECIFIC_MON, SPECIES_KARRABLAST, SPECIES_ACCELGOR}),
    },

    [SPECIES_ACCELGOR] =
    {
        .baseHP        = 80,
        .baseAttack    = 70,
        .baseDefense   = 40,
        .baseSpeed     = 145,
        .baseSpAttack  = 100,
        .baseSpDefense = 60,
        .types = { TYPE_BUG, TYPE_BUG },
        .catchRate = 75,
        .expYield = 173,
        .evYield_Speed = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_BUG, EGG_GROUP_BUG },
        .abilities = { ABILITY_HYDRATION, ABILITY_STICKY_HOLD, ABILITY_UNBURDEN },
        .bodyColor = BODY_COLOR_RED,
        .speciesName = _("Hydragil"),
        .cryId = CRY_ACCELGOR,
        .natDexNum = NATIONAL_DEX_ACCELGOR,
        .categoryName = _("Entschalungs"),
        .height = 8,
        .weight = 253,
        .description = POKEDEX_DESC_STRING(
            "Seit es die schwere Muschel\n"
            "abgestreift hat, ist es viel\n"
            "leichter. Nun gleichen seine\n"
            "Kampfbewegungen denen eines Ninja."),
        .pokemonScale = 366,
        .pokemonOffset = 9,
        .trainerScale = 257,
        .trainerOffset = 0,
        FRONT_PIC(Accelgor, 64, 56),
        .frontPicYOffset = 7,
        .frontAnimFrames = sAnims_Accelgor,
        .frontAnimId = ANIM_H_JUMPS_V_STRETCH,
        BACK_PIC(Accelgor, 64, 64),
        .backPicYOffset = 2,
        .backAnimId = BACK_ANIM_H_SPRING_REPEATED,
        PALETTES(Accelgor),
        ICON(Accelgor, 1),
        .footprint = gMonFootprint_Accelgor,
        LEARNSETS(Accelgor),
    },
#endif //P_FAMILY_SHELMET

#if P_FAMILY_STUNFISK
#define STUNFISK_MISC_INFO                                          \
        .catchRate = 75,                                            \
        .expYield = 165,                                            \
        .evYield_HP = 2,                                            \
        .genderRatio = PERCENT_FEMALE(50),                          \
        .eggCycles = 20,                                            \
        .growthRate = GROWTH_MEDIUM_FAST,                           \
        .eggGroups = { EGG_GROUP_WATER_1, EGG_GROUP_AMORPHOUS },    \
        .speciesName = _("Hydragil"),                               \
        .cryId = CRY_STUNFISK,                                      \
        .natDexNum = NATIONAL_DEX_STUNFISK,                         \
        .categoryName = _("Entschalungs"),                                  \
        .height = 7,                                                \
        .pokemonScale = 365,                                        \
        .pokemonOffset = 14,                                        \
        .trainerScale = 256,                                        \
        .trainerOffset = 0,                                         \
        .footprint = gMonFootprint_Stunfisk,                        \
        .formSpeciesIdTable = sStunfiskFormSpeciesIdTable

    [SPECIES_STUNFISK] =
    {
        STUNFISK_MISC_INFO,
        .baseHP        = 109,
        .baseAttack    = 66,
        .baseDefense   = 84,
        .baseSpeed     = 32,
        .baseSpAttack  = 81,
        .baseSpDefense = 99,
        .types = { TYPE_GROUND, TYPE_ELECTRIC },
        .itemRare = ITEM_SOFT_SAND,
        .friendship = 70,
        .abilities = { ABILITY_STATIC, ABILITY_LIMBER, ABILITY_SAND_VEIL },
        .bodyColor = BODY_COLOR_BROWN,
        .weight = 110,
        .description = POKEDEX_DESC_STRING(
            "Dank seiner dicken Haut hält es\n"
            "selbst das Gewicht eines\n"
            "Sumoringers aus. Wenn es\n"
            "Stromschläge verteilt, grinst es."),
        FRONT_PIC(Stunfisk, 56, 48),
        .frontPicYOffset = 14,
        .frontAnimFrames = sAnims_Stunfisk,
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(Stunfisk, 64, 24),
        .backPicYOffset = 22,
        .backAnimId = BACK_ANIM_H_STRETCH,
        PALETTES(Stunfisk),
        ICON(Stunfisk, 2),
        LEARNSETS(Stunfisk),
    },

#if P_GALARIAN_FORMS
    [SPECIES_STUNFISK_GALAR] =
    {
        STUNFISK_MISC_INFO,
        .baseHP        = 109,
        .baseAttack    = 81,
        .baseDefense   = 99,
        .baseSpeed     = 32,
        .baseSpAttack  = 66,
        .baseSpDefense = 84,
        .types = { TYPE_GROUND, TYPE_STEEL },
        .friendship = STANDARD_FRIENDSHIP,
        .abilities = { ABILITY_MIMICRY, ABILITY_NONE },
        .bodyColor = BODY_COLOR_GREEN,
        .weight = 205,
        .description = POKEDEX_DESC_STRING(
            "Dank seiner dicken Haut hält es\n"
            "selbst das Gewicht eines\n"
            "Sumoringers aus. Wenn es\n"
            "Stromschläge verteilt, grinst es."),
        FRONT_PIC(StunfiskGalarian, 48, 40),
        .frontPicYOffset = 14,
        .frontAnimFrames = sAnims_StunfiskGalarian,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(StunfiskGalarian, 64, 24),
        .backPicYOffset = 23,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(StunfiskGalarian),
        ICON(StunfiskGalarian, 1),
        LEARNSETS(StunfiskGalarian),
        .isGalarianForm = TRUE,
    },
#endif //P_GALARIAN_FORMS
#endif //P_FAMILY_STUNFISK

#if P_FAMILY_MIENFOO
    [SPECIES_MIENFOO] =
    {
        .baseHP        = 45,
        .baseAttack    = 85,
        .baseDefense   = 50,
        .baseSpeed     = 65,
        .baseSpAttack  = 55,
        .baseSpDefense = 50,
        .types = { TYPE_FIGHTING, TYPE_FIGHTING },
        .catchRate = 180,
        .expYield = 70,
        .evYield_Attack = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 25,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_HUMAN_LIKE },
        .abilities = { ABILITY_INNER_FOCUS, ABILITY_REGENERATOR, ABILITY_RECKLESS },
        .bodyColor = BODY_COLOR_YELLOW,
        .speciesName = _("Lin-Fu"),
        .cryId = CRY_MIENFOO,
        .natDexNum = NATIONAL_DEX_MIENFOO,
        .categoryName = _("Kampfkünste"),
        .height = 9,
        .weight = 200,
        .description = POKEDEX_DESC_STRING(
            "Ein gut trainiertes Lin-Fu kann in einer\n"
            "Minute über 100 Schläge ausführen."),
        .pokemonScale = 338,
        .pokemonOffset = 10,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Mienfoo, 40, 48),
        .frontPicYOffset = 11,
        .frontAnimFrames = sAnims_Mienfoo,
        .frontAnimId = ANIM_H_VIBRATE,
        BACK_PIC(Mienfoo, 56, 40),
        .backPicYOffset = 14,
        .backAnimId = BACK_ANIM_CONCAVE_ARC_LARGE,
        PALETTES(Mienfoo),
        ICON(Mienfoo, 1),
        .footprint = gMonFootprint_Mienfoo,
        LEARNSETS(Mienfoo),
        .evolutions = EVOLUTION({EVO_LEVEL, 50, SPECIES_MIENSHAO}),
    },

    [SPECIES_MIENSHAO] =
    {
        .baseHP        = 65,
        .baseAttack    = 125,
        .baseDefense   = 60,
        .baseSpeed     = 105,
        .baseSpAttack  = 95,
        .baseSpDefense = 60,
        .types = { TYPE_FIGHTING, TYPE_FIGHTING },
        .catchRate = 45,
        .expYield = 179,
        .evYield_Attack = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 25,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_HUMAN_LIKE },
        .abilities = { ABILITY_INNER_FOCUS, ABILITY_REGENERATOR, ABILITY_RECKLESS },
        .bodyColor = BODY_COLOR_PURPLE,
        .speciesName = _("Wie-Shu"),
        .cryId = CRY_MIENSHAO,
        .natDexNum = NATIONAL_DEX_MIENSHAO,
        .categoryName = _("Kampfkünste"),
        .height = 14,
        .weight = 355,
        .description = POKEDEX_DESC_STRING(
            "Es benutzt das Fell an seinen Armen\n"
            "als Peitsche. Beide Arme bewegen\n"
            "sich dabei mit atemberaubender\n"
            "Geschwindigkeit."),
        .pokemonScale = 265,
        .pokemonOffset = 2,
        .trainerScale = 262,
        .trainerOffset = 0,
        FRONT_PIC(Mienshao, 64, 56),
        .frontPicYOffset = 4,
        .frontAnimFrames = sAnims_Mienshao,
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(Mienshao, 56, 56),
        .backPicYOffset = 7,
        .backAnimId = BACK_ANIM_V_STRETCH,
        PALETTES(Mienshao),
        ICON(Mienshao, 2),
        .footprint = gMonFootprint_Mienshao,
        LEARNSETS(Mienshao),
    },
#endif //P_FAMILY_MIENFOO

#if P_FAMILY_DRUDDIGON
    [SPECIES_DRUDDIGON] =
    {
        .baseHP        = 77,
        .baseAttack    = 120,
        .baseDefense   = 90,
        .baseSpeed     = 48,
        .baseSpAttack  = 60,
        .baseSpDefense = 90,
        .types = { TYPE_DRAGON, TYPE_DRAGON },
        .catchRate = 45,
        .expYield = 170,
        .evYield_Attack = 2,
        .itemRare = ITEM_DRAGON_FANG,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 30,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_DRAGON, EGG_GROUP_MONSTER },
        .abilities = { ABILITY_ROUGH_SKIN, ABILITY_SHEER_FORCE, ABILITY_MOLD_BREAKER },
        .bodyColor = BODY_COLOR_RED,
        .speciesName = _("Shardrago"),
        .cryId = CRY_DRUDDIGON,
        .natDexNum = NATIONAL_DEX_DRUDDIGON,
        .categoryName = _("Höhlen"),
        .height = 16,
        .weight = 1390,
        .description = POKEDEX_DESC_STRING(
            "Shardrago lebt in Grotten. Kühlt sein\n"
            "Körper ab, erstarrt es, weshalb es\n"
            "regelmäßig Sonnenbäder nehmen muss."),
        .pokemonScale = 259,
        .pokemonOffset = 1,
        .trainerScale = 296,
        .trainerOffset = 1,
        FRONT_PIC(Druddigon, 64, 64),
        .frontPicYOffset = 4,
        .frontAnimFrames = sAnims_Druddigon,
        .frontAnimId = ANIM_BOUNCE_ROTATE_TO_SIDES_SMALL_SLOW,
        BACK_PIC(Druddigon, 64, 56),
        .backPicYOffset = 8,
        .backAnimId = BACK_ANIM_V_SHAKE_LOW,
        PALETTES(Druddigon),
        ICON(Druddigon, 0),
        .footprint = gMonFootprint_Druddigon,
        LEARNSETS(Druddigon),
    },
#endif //P_FAMILY_DRUDDIGON

#if P_FAMILY_GOLETT
    [SPECIES_GOLETT] =
    {
        .baseHP        = 59,
        .baseAttack    = 74,
        .baseDefense   = 50,
        .baseSpeed     = 35,
        .baseSpAttack  = 35,
        .baseSpDefense = 50,
        .types = { TYPE_GROUND, TYPE_GHOST },
        .catchRate = 190,
        .expYield = 61,
        .evYield_Attack = 1,
        .itemRare = ITEM_LIGHT_CLAY,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 25,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_MINERAL, EGG_GROUP_MINERAL },
        .abilities = { ABILITY_IRON_FIST, ABILITY_KLUTZ, ABILITY_NO_GUARD },
        .bodyColor = BODY_COLOR_GREEN,
        .noFlip = TRUE,
        .speciesName = _("Golbit"),
        .cryId = CRY_GOLETT,
        .natDexNum = NATIONAL_DEX_GOLETT,
        .categoryName = _("Urgolem"),
        .height = 10,
        .weight = 920,
        .description = POKEDEX_DESC_STRING(
            "Es wird durch eine Energie\n"
            "angetrieben, die seinem Körper\n"
            "entspringt. Keiner weiß jedoch,\n"
            "woher diese Energie stammt."),
        .pokemonScale = 305,
        .pokemonOffset = 7,
        .trainerScale = 257,
        .trainerOffset = 0,
        FRONT_PIC(Golett, 56, 56),
        .frontPicYOffset = 7,
        .frontAnimFrames = sAnims_Golett,
        .frontAnimId = ANIM_V_SHAKE,
        BACK_PIC(Golett, 64, 56),
        .backPicYOffset = 8,
        .backAnimId = BACK_ANIM_H_SLIDE,
        PALETTES(Golett),
        ICON(Golett, 0),
        .footprint = gMonFootprint_Golett,
        LEARNSETS(Golett),
        .evolutions = EVOLUTION({EVO_LEVEL, 43, SPECIES_GOLURK}),
    },

    [SPECIES_GOLURK] =
    {
        .baseHP        = 89,
        .baseAttack    = 124,
        .baseDefense   = 80,
        .baseSpeed     = 55,
        .baseSpAttack  = 55,
        .baseSpDefense = 80,
        .types = { TYPE_GROUND, TYPE_GHOST },
        .catchRate = 90,
        .expYield = 169,
        .evYield_Attack = 2,
        .itemRare = ITEM_LIGHT_CLAY,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 25,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_MINERAL, EGG_GROUP_MINERAL },
        .abilities = { ABILITY_IRON_FIST, ABILITY_KLUTZ, ABILITY_NO_GUARD },
        .bodyColor = BODY_COLOR_GREEN,
        .noFlip = TRUE,
        .speciesName = _("Golgantes"),
        .cryId = CRY_GOLURK,
        .natDexNum = NATIONAL_DEX_GOLURK,
        .categoryName = _("Urgolem"),
        .height = 28,
        .weight = 3300,
        .description = POKEDEX_DESC_STRING(
            "Man munkelt, sein Schöpfer habe ihm\n"
            "aufgetragen, schützend über Pokémon\n"
            "und Menschen zu wachen."),
        .pokemonScale = 275,
        .pokemonOffset = 3,
        .trainerScale = 300,
        .trainerOffset = 0,
        FRONT_PIC(Golurk, 64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_Golurk,
        .frontAnimId = ANIM_V_SHAKE_TWICE,
        BACK_PIC(Golurk, 64, 56),
        .backPicYOffset = 7,
        .backAnimId = BACK_ANIM_V_SHAKE,
        PALETTES(Golurk),
        ICON(Golurk, 0),
        .footprint = gMonFootprint_Golurk,
        LEARNSETS(Golurk),
    },
#endif //P_FAMILY_GOLETT

#if P_FAMILY_PAWNIARD
    [SPECIES_PAWNIARD] =
    {
        .baseHP        = 45,
        .baseAttack    = 85,
        .baseDefense   = 70,
        .baseSpeed     = 60,
        .baseSpAttack  = 40,
        .baseSpDefense = 40,
        .types = { TYPE_DARK, TYPE_STEEL },
        .catchRate = 120,
        .expYield = 68,
        .evYield_Attack = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = 35,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_HUMAN_LIKE, EGG_GROUP_HUMAN_LIKE },
        .abilities = { ABILITY_DEFIANT, ABILITY_INNER_FOCUS, ABILITY_PRESSURE },
        .bodyColor = BODY_COLOR_RED,
        .speciesName = _("Gladiantri"),
        .cryId = CRY_PAWNIARD,
        .natDexNum = NATIONAL_DEX_PAWNIARD,
        .categoryName = _("Stahlklingen"),
        .height = 5,
        .weight = 102,
        .description = POKEDEX_DESC_STRING(
            "Es treibt Gegner mit seinen scharfen\n"
            "Klingen in die Ecke. Diese schärft es an\n"
            "den Felsen eines Flussbettes."),
        .pokemonScale = 432,
        .pokemonOffset = 15,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Pawniard, 56, 48),
        .frontPicYOffset = 10,
        .frontAnimFrames = sAnims_Pawniard,
        .frontAnimId = ANIM_H_VIBRATE,
        BACK_PIC(Pawniard, 64, 48),
        .backPicYOffset = 10,
        .backAnimId = BACK_ANIM_H_SLIDE,
        PALETTES(Pawniard),
        ICON(Pawniard, 0),
        .footprint = gMonFootprint_Pawniard,
        LEARNSETS(Pawniard),
        .evolutions = EVOLUTION({EVO_LEVEL, 52, SPECIES_BISHARP}),
    },

    [SPECIES_BISHARP] =
    {
        .baseHP        = 65,
        .baseAttack    = 125,
        .baseDefense   = 100,
        .baseSpeed     = 70,
        .baseSpAttack  = 60,
        .baseSpDefense = 70,
        .types = { TYPE_DARK, TYPE_STEEL },
        .catchRate = 45,
        .expYield = 172,
        .evYield_Attack = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = 35,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_HUMAN_LIKE, EGG_GROUP_HUMAN_LIKE },
        .abilities = { ABILITY_DEFIANT, ABILITY_INNER_FOCUS, ABILITY_PRESSURE },
        .bodyColor = BODY_COLOR_RED,
        .speciesName = _("Caesurio"),
        .cryId = CRY_BISHARP,
        .natDexNum = NATIONAL_DEX_BISHARP,
        .categoryName = _("Schwertklingen"),
        .height = 16,
        .weight = 700,
        .description = POKEDEX_DESC_STRING(
            "Ein kaltblütiges Pokémon, das\n"
            "Gegner zunächst mit einer Schar von\n"
            "Gladiantri lähmt und dann\n"
            "zweiteilt."),
        .pokemonScale = 259,
        .pokemonOffset = 1,
        .trainerScale = 296,
        .trainerOffset = 1,
        FRONT_PIC(Bisharp, 48, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_Bisharp,
        .frontAnimId = ANIM_H_STRETCH,
        BACK_PIC(Bisharp, 64, 64),
        .backPicYOffset = 3,
        .backAnimId = BACK_ANIM_GROW_STUTTER,
        PALETTES(Bisharp),
        ICON(Bisharp, 0),
        .footprint = gMonFootprint_Bisharp,
        LEARNSETS(Bisharp),
        .evolutions = EVOLUTION({EVO_NONE, 0, SPECIES_KINGAMBIT}),
    },

#if P_GEN_9_CROSS_EVOS
    [SPECIES_KINGAMBIT] =
    {
        .baseHP        = 100,
        .baseAttack    = 135,
        .baseDefense   = 120,
        .baseSpeed     = 50,
        .baseSpAttack  = 60,
        .baseSpDefense = 85,
        .types = { TYPE_DARK, TYPE_STEEL },
        .catchRate = 25,
        .expYield = 275,
        .evYield_Attack = 3,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_HUMAN_LIKE, EGG_GROUP_HUMAN_LIKE },
        .abilities = { ABILITY_DEFIANT, ABILITY_SUPREME_OVERLORD, ABILITY_PRESSURE },
        .bodyColor = BODY_COLOR_BLACK,
        .speciesName = _("Gladimperio"),
        .cryId = CRY_KINGAMBIT,
        .natDexNum = NATIONAL_DEX_KINGAMBIT,
        .categoryName = _("Langschwert"),
        .height = 20,
        .weight = 1200,
        .description = POKEDEX_DESC_STRING(
            "Obwohl es im Kampf eine riesige Armee\n"
            "befehligt, ist es nicht in der Lage,\n"
            "komplexe Strategien zu entwickeln. Es\n"
            "nutzt einfach"),
        .pokemonScale = 356,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Kingambit, 64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_Kingambit,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(Kingambit, 64, 64),
        .backPicYOffset = 0,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(Kingambit),
        ICON(Kingambit, 0),
        //.footprint = gMonFootprint_Kingambit,
        LEARNSETS(Kingambit),
    },
#endif //P_GEN_9_CROSS_EVOS
#endif //P_FAMILY_PAWNIARD

#if P_FAMILY_BOUFFALANT
    [SPECIES_BOUFFALANT] =
    {
        .baseHP        = 95,
        .baseAttack    = 110,
        .baseDefense   = 95,
        .baseSpeed     = 55,
        .baseSpAttack  = 40,
        .baseSpDefense = 95,
        .types = { TYPE_NORMAL, TYPE_NORMAL },
        .catchRate = 45,
        .expYield = 172,
        .evYield_Attack = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD },
        .abilities = { ABILITY_RECKLESS, ABILITY_SAP_SIPPER, ABILITY_SOUNDPROOF },
        .bodyColor = BODY_COLOR_BROWN,
        .speciesName = _("Bisofank"),
        .cryId = CRY_BOUFFALANT,
        .natDexNum = NATIONAL_DEX_BOUFFALANT,
        .categoryName = _("Kopfstoßrind"),
        .height = 16,
        .weight = 946,
        .description = POKEDEX_DESC_STRING(
            "Sein zotteliges Fell fängt selbst nach\n"
            "einer seiner wuchtigen Rempelattacken\n"
            "einiges an Schaden ab."),
        .pokemonScale = 259,
        .pokemonOffset = 1,
        .trainerScale = 296,
        .trainerOffset = 1,
        FRONT_PIC(Bouffalant, 64, 56),
        .frontPicYOffset = 4,
        .frontAnimFrames = sAnims_Bouffalant,
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE_SLOW,
        BACK_PIC(Bouffalant, 64, 56),
        .backPicYOffset = 7,
        .backAnimId = BACK_ANIM_V_SHAKE_LOW,
        PALETTES(Bouffalant),
        ICON(Bouffalant, 2),
        .footprint = gMonFootprint_Bouffalant,
        LEARNSETS(Bouffalant),
    },
#endif //P_FAMILY_BOUFFALANT

#if P_FAMILY_RUFFLET
    [SPECIES_RUFFLET] =
    {
        .baseHP        = 70,
        .baseAttack    = 83,
        .baseDefense   = 50,
        .baseSpeed     = 60,
        .baseSpAttack  = 37,
        .baseSpDefense = 50,
        .types = { TYPE_NORMAL, TYPE_FLYING },
        .catchRate = 190,
        .expYield = 70,
        .evYield_Attack = 1,
        .genderRatio = MON_MALE,
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_FLYING, EGG_GROUP_FLYING },
        .abilities = { ABILITY_KEEN_EYE, ABILITY_SHEER_FORCE, ABILITY_HUSTLE },
        .bodyColor = BODY_COLOR_WHITE,
        .speciesName = _("Geronimatz"),
        .cryId = CRY_RUFFLET,
        .natDexNum = NATIONAL_DEX_RUFFLET,
        .categoryName = _("Adlerküken"),
        .height = 5,
        .weight = 105,
        .description = POKEDEX_DESC_STRING(
            "Kann mit seinen Füßen Nüsse\n"
            "zermalmen. Es stellt sich jedem\n"
            "noch so starken Gegner tapfer zum\n"
            "Kampf."),
        .pokemonScale = 432,
        .pokemonOffset = 13,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Rufflet, 32, 48),
        .frontPicYOffset = 10,
        .frontAnimFrames = sAnims_Rufflet,
        .frontAnimId = ANIM_V_STRETCH,
        BACK_PIC(Rufflet, 48, 56),
        .backPicYOffset = 9,
        .backAnimId = BACK_ANIM_CONCAVE_ARC_SMALL,
        PALETTES(Rufflet),
        ICON(Rufflet, 2),
        .footprint = gMonFootprint_Rufflet,
        LEARNSETS(Rufflet),
        .evolutions = EVOLUTION({EVO_LEVEL, 54, SPECIES_BRAVIARY},
                                {EVO_NONE, 0, SPECIES_BRAVIARY_HISUI}),
    },

#define BRAVIARY_MISC_INFO                                      \
        .catchRate = 60,                                        \
        .expYield = 179,                                        \
        .genderRatio = MON_MALE,                                \
        .eggCycles = 20,                                        \
        .friendship = STANDARD_FRIENDSHIP,                      \
        .growthRate = GROWTH_SLOW,                              \
        .eggGroups = { EGG_GROUP_FLYING, EGG_GROUP_FLYING },    \
        .speciesName = _("Geronimatz"),                           \
        .cryId = CRY_BRAVIARY,                                  \
        .natDexNum = NATIONAL_DEX_BRAVIARY,                     \
        .footprint = gMonFootprint_Braviary,                    \
        .formSpeciesIdTable = sBraviaryFormSpeciesIdTable

    [SPECIES_BRAVIARY] =
    {
        BRAVIARY_MISC_INFO,
        .baseHP        = 100,
        .baseAttack    = 123,
        .baseDefense   = 75,
        .baseSpeed     = 80,
        .baseSpAttack  = 57,
        .baseSpDefense = 75,
        .types = { TYPE_NORMAL, TYPE_FLYING },
        .evYield_Attack = 2,
        .abilities = { ABILITY_KEEN_EYE, ABILITY_SHEER_FORCE, ABILITY_DEFIANT },
        .bodyColor = BODY_COLOR_RED,
        .categoryName = _("Kühnheits"),
        .height = 15,
        .weight = 410,
        .description = POKEDEX_DESC_STRING(
            "Ein tapferer Krieger der Lüfte, der\n"
            "zum Schutz seiner Kameraden auch\n"
            "mit Verletzungen immer\n"
            "weiterkämpft."),
        .pokemonScale = 268,
        .pokemonOffset = 2,
        .trainerScale = 271,
        .trainerOffset = 0,
        FRONT_PIC(Braviary, 64, 64),
        .frontPicYOffset = 1,
        .frontAnimFrames = sAnims_Braviary,
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .enemyMonElevation = 6,
        BACK_PIC(Braviary, 64, 48),
        .backPicYOffset = 10,
        .backAnimId = BACK_ANIM_TRIANGLE_DOWN,
        PALETTES(Braviary),
        ICON(Braviary, 0),
        LEARNSETS(Braviary),
    },

#if P_HISUIAN_FORMS
    [SPECIES_BRAVIARY_HISUI] =
    {
        BRAVIARY_MISC_INFO,
        .baseHP        = 110,
        .baseAttack    = 83,
        .baseDefense   = 70,
        .baseSpeed     = 65,
        .baseSpAttack  = 112,
        .baseSpDefense = 70,
        .types = { TYPE_PSYCHIC, TYPE_FLYING },
        .evYield_SpAttack = 2,
        .abilities = { ABILITY_KEEN_EYE, ABILITY_SHEER_FORCE, ABILITY_TINTED_LENS },
        .bodyColor = BODY_COLOR_WHITE,
        .categoryName = _("Kühnheits"),
        .height = 17,
        .weight = 434,
        .description = POKEDEX_DESC_STRING(
            "Ein tapferer Krieger der Lüfte, der\n"
            "zum Schutz seiner Kameraden auch\n"
            "mit Verletzungen immer\n"
            "weiterkämpft."),
        .pokemonScale = 268,
        .pokemonOffset = 2,
        .trainerScale = 271,
        .trainerOffset = 0,
        FRONT_PIC(BraviaryHisuian, 64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_BraviaryHisuian,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .enemyMonElevation = 3,
        BACK_PIC(BraviaryHisuian, 64, 56),
        .backPicYOffset = 7,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(BraviaryHisuian),
        ICON(BraviaryHisuian, 2),
        LEARNSETS(BraviaryHisuian),
        .isHisuianForm = TRUE,
    },
#endif //P_HISUIAN_FORMS
#endif //P_FAMILY_RUFFLET

#if P_FAMILY_VULLABY
    [SPECIES_VULLABY] =
    {
        .baseHP        = 70,
        .baseAttack    = 55,
        .baseDefense   = 75,
        .baseSpeed     = 60,
        .baseSpAttack  = 45,
        .baseSpDefense = 65,
        .types = { TYPE_DARK, TYPE_FLYING },
        .catchRate = 190,
        .expYield = 74,
        .evYield_Defense = 1,
        .genderRatio = MON_FEMALE,
        .eggCycles = 20,
        .friendship = 35,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_FLYING, EGG_GROUP_FLYING },
        .abilities = { ABILITY_BIG_PECKS, ABILITY_OVERCOAT, ABILITY_WEAK_ARMOR },
        .bodyColor = BODY_COLOR_BROWN,
        .speciesName = _("Skallyk"),
        .cryId = CRY_VULLABY,
        .natDexNum = NATIONAL_DEX_VULLABY,
        .categoryName = _("Windel"),
        .height = 5,
        .weight = 90,
        .description = POKEDEX_DESC_STRING(
            "Seine Flügel sind noch zu klein zum\n"
            "Fliegen. Ein von Grypheldis beschaffter\n"
            "Schädel schützt seinen Bürzel."),
        .pokemonScale = 432,
        .pokemonOffset = 13,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Vullaby, 56, 56),
        .frontPicYOffset = 5,
        .frontAnimFrames = sAnims_Vullaby,
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(Vullaby, 64, 48),
        .backPicYOffset = 14,
        .backAnimId = BACK_ANIM_DIP_RIGHT_SIDE,
        PALETTES(Vullaby),
        ICON(Vullaby, 0),
        .footprint = gMonFootprint_Vullaby,
        LEARNSETS(Vullaby),
        .evolutions = EVOLUTION({EVO_LEVEL, 54, SPECIES_MANDIBUZZ}),
    },

    [SPECIES_MANDIBUZZ] =
    {
        .baseHP        = 110,
        .baseAttack    = 65,
        .baseDefense   = 105,
        .baseSpeed     = 80,
        .baseSpAttack  = 55,
        .baseSpDefense = 95,
        .types = { TYPE_DARK, TYPE_FLYING },
        .catchRate = 60,
        .expYield = 179,
        .evYield_SpAttack = 2,
        .genderRatio = MON_FEMALE,
        .eggCycles = 20,
        .friendship = 35,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_FLYING, EGG_GROUP_FLYING },
        .abilities = { ABILITY_BIG_PECKS, ABILITY_OVERCOAT, ABILITY_WEAK_ARMOR },
        .bodyColor = BODY_COLOR_BROWN,
        .speciesName = _("Grypheldis"),
        .cryId = CRY_MANDIBUZZ,
        .natDexNum = NATIONAL_DEX_MANDIBUZZ,
        .categoryName = _("Knochenadler"),
        .height = 12,
        .weight = 395,
        .description = POKEDEX_DESC_STRING(
            "Es kreist am Himmel, bis es seine\n"
            "Beute findet. Nach erfolgtem\n"
            "Angriff trägt es sie mühelos zu\n"
            "seinem Nest."),
        .pokemonScale = 282,
        .pokemonOffset = 4,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Mandibuzz, 48, 64),
        .frontPicYOffset = 1,
        .frontAnimFrames = sAnims_Mandibuzz,
        .frontAnimId = ANIM_V_STRETCH,
        BACK_PIC(Mandibuzz, 64, 48),
        .backPicYOffset = 10,
        .backAnimId = BACK_ANIM_JOLT_RIGHT,
        PALETTES(Mandibuzz),
        ICON(Mandibuzz, 1),
        .footprint = gMonFootprint_Mandibuzz,
        LEARNSETS(Mandibuzz),
    },
#endif //P_FAMILY_VULLABY

#if P_FAMILY_HEATMOR
    [SPECIES_HEATMOR] =
    {
        .baseHP        = 85,
        .baseAttack    = 97,
        .baseDefense   = 66,
        .baseSpeed     = 65,
        .baseSpAttack  = 105,
        .baseSpDefense = 66,
        .types = { TYPE_FIRE, TYPE_FIRE },
        .catchRate = 90,
        .expYield = 169,
        .evYield_SpAttack = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD },
        .abilities = { ABILITY_GLUTTONY, ABILITY_FLASH_FIRE, ABILITY_WHITE_SMOKE },
        .bodyColor = BODY_COLOR_RED,
        .speciesName = _("Furnifraß"),
        .cryId = CRY_HEATMOR,
        .natDexNum = NATIONAL_DEX_HEATMOR,
        .categoryName = _("Ameisenbären"),
        .height = 14,
        .weight = 580,
        .description = POKEDEX_DESC_STRING(
            "Mit seiner brandheißen Zunge bringt\n"
            "es Fermicula zum Schmelzen, um so\n"
            "an sein weiches Inneres zu\n"
            "gelangen."),
        .pokemonScale = 265,
        .pokemonOffset = 2,
        .trainerScale = 262,
        .trainerOffset = 0,
        FRONT_PIC(Heatmor, 64, 56),
        .frontPicYOffset = 6,
        .frontAnimFrames = sAnims_Heatmor,
        .frontAnimId = ANIM_H_SHAKE,
        BACK_PIC(Heatmor, 64, 24),
        .backPicYOffset = 21,
        .backAnimId = BACK_ANIM_DIP_RIGHT_SIDE,
        PALETTES(Heatmor),
        ICON(Heatmor, 2),
        .footprint = gMonFootprint_Heatmor,
        LEARNSETS(Heatmor),
    },
#endif //P_FAMILY_HEATMOR

#if P_FAMILY_DURANT
    [SPECIES_DURANT] =
    {
        .baseHP        = 58,
        .baseAttack    = 109,
        .baseDefense   = 112,
        .baseSpeed     = 109,
        .baseSpAttack  = 48,
        .baseSpDefense = 48,
        .types = { TYPE_BUG, TYPE_STEEL },
        .catchRate = 90,
        .expYield = 169,
        .evYield_Defense = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_BUG, EGG_GROUP_BUG },
        .abilities = { ABILITY_SWARM, ABILITY_HUSTLE, ABILITY_TRUANT },
        .bodyColor = BODY_COLOR_GRAY,
        .speciesName = _("Fermicula"),
        .cryId = CRY_DURANT,
        .natDexNum = NATIONAL_DEX_DURANT,
        .categoryName = _("Eisenameisen"),
        .height = 3,
        .weight = 330,
        .description = POKEDEX_DESC_STRING(
            "Ein eiserner Panzer umgibt seinen Leib.\n"
            "Angriffe von Furnifraß, seinem Feind,\n"
            "schlägt es in der Gruppe zurück."),
        .pokemonScale = 530,
        .pokemonOffset = 19,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Durant, 48, 32),
        .frontPicYOffset = 17,
        .frontAnimFrames = sAnims_Durant,
        .frontAnimId = ANIM_RAPID_H_HOPS,
        BACK_PIC(Durant, 64, 32),
        .backPicYOffset = 17,
        .backAnimId = BACK_ANIM_H_VIBRATE,
        PALETTES(Durant),
        ICON(Durant, 0),
        .footprint = gMonFootprint_Durant,
        LEARNSETS(Durant),
    },
#endif //P_FAMILY_DURANT

#if P_FAMILY_DEINO
    [SPECIES_DEINO] =
    {
        .baseHP        = 52,
        .baseAttack    = 65,
        .baseDefense   = 50,
        .baseSpeed     = 38,
        .baseSpAttack  = 45,
        .baseSpDefense = 50,
        .types = { TYPE_DARK, TYPE_DRAGON },
        .catchRate = 45,
        .expYield = 60,
        .evYield_Attack = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 40,
        .friendship = 35,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_DRAGON, EGG_GROUP_DRAGON },
        .abilities = { ABILITY_HUSTLE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Kapuno"),
        .cryId = CRY_DEINO,
        .natDexNum = NATIONAL_DEX_DEINO,
        .categoryName = _("Haudrauf"),
        .height = 8,
        .weight = 173,
        .description = POKEDEX_DESC_STRING(
            "Da es nichts sehen kann, sucht es\n"
            "seine Umgebung mit Rempel- und\n"
            "Bissattacken ab und ist immer mit\n"
            "Wunden übersät."),
        .pokemonScale = 366,
        .pokemonOffset = 12,
        .trainerScale = 257,
        .trainerOffset = 0,
        FRONT_PIC(Deino, 40, 48),
        .frontPicYOffset = 10,
        .frontAnimFrames = sAnims_Deino,
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(Deino, 48, 48),
        .backPicYOffset = 14,
        .backAnimId = BACK_ANIM_H_SLIDE,
        PALETTES(Deino),
        ICON(Deino, 2),
        .footprint = gMonFootprint_Deino,
        LEARNSETS(Deino),
        .evolutions = EVOLUTION({EVO_LEVEL, 50, SPECIES_ZWEILOUS}),
    },

    [SPECIES_ZWEILOUS] =
    {
        .baseHP        = 72,
        .baseAttack    = 85,
        .baseDefense   = 70,
        .baseSpeed     = 58,
        .baseSpAttack  = 65,
        .baseSpDefense = 70,
        .types = { TYPE_DARK, TYPE_DRAGON },
        .catchRate = 45,
        .expYield = 147,
        .evYield_Attack = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 40,
        .friendship = 35,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_DRAGON, EGG_GROUP_DRAGON },
        .abilities = { ABILITY_HUSTLE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Duodino"),
        .cryId = CRY_ZWEILOUS,
        .natDexNum = NATIONAL_DEX_ZWEILOUS,
        .categoryName = _("Grobheits"),
        .height = 14,
        .weight = 500,
        .description = POKEDEX_DESC_STRING(
            "Wenn es sein Revier leergejagt hat, sucht\n"
            "es sich ein neues. Seine beiden Köpfe\n"
            "liegen ständig im Streit."),
        .pokemonScale = 265,
        .pokemonOffset = 3,
        .trainerScale = 262,
        .trainerOffset = 0,
        FRONT_PIC(Zweilous, 64, 56),
        .frontPicYOffset = 6,
        .frontAnimFrames = sAnims_Zweilous,
        .frontAnimId = ANIM_H_STRETCH,
        BACK_PIC(Zweilous, 64, 56),
        .backPicYOffset = 9,
        .backAnimId = BACK_ANIM_H_SHAKE,
        PALETTES(Zweilous),
        ICON(Zweilous, 2),
        .footprint = gMonFootprint_Zweilous,
        LEARNSETS(Zweilous),
        .evolutions = EVOLUTION({EVO_LEVEL, 64, SPECIES_HYDREIGON}),
    },

    [SPECIES_HYDREIGON] =
    {
        .baseHP        = 92,
        .baseAttack    = 105,
        .baseDefense   = 90,
        .baseSpeed     = 98,
        .baseSpAttack  = 125,
        .baseSpDefense = 90,
        .types = { TYPE_DARK, TYPE_DRAGON },
        .catchRate = 45,
        .expYield = 270,
        .evYield_SpAttack = 3,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 40,
        .friendship = 35,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_DRAGON, EGG_GROUP_DRAGON },
        .abilities = { ABILITY_LEVITATE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Trikephalo"),
        .cryId = CRY_HYDREIGON,
        .natDexNum = NATIONAL_DEX_HYDREIGON,
        .categoryName = _("Brutal"),
        .height = 18,
        .weight = 1600,
        .description = POKEDEX_DESC_STRING(
            "Die Köpfe an seinen beiden Armen\n"
            "haben kein eigenes Gehirn. Seine\n"
            "drei Mäuler kauen alles radikal\n"
            "kurz und klein."),
        .pokemonScale = 267,
        .pokemonOffset = 2,
        .trainerScale = 286,
        .trainerOffset = 1,
        FRONT_PIC(Hydreigon, 64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_Hydreigon,
        .frontAnimId = ANIM_RISING_WOBBLE,
        .enemyMonElevation = 3,
        BACK_PIC(Hydreigon, 64, 56),
        .backPicYOffset = 11,
        .backAnimId = BACK_ANIM_GROW_STUTTER,
        PALETTES(Hydreigon),
        ICON(Hydreigon, 2),
        .footprint = gMonFootprint_Hydreigon,
        LEARNSETS(Hydreigon),
    },
#endif //P_FAMILY_DEINO

#if P_FAMILY_LARVESTA
    [SPECIES_LARVESTA] =
    {
        .baseHP        = 55,
        .baseAttack    = 85,
        .baseDefense   = 55,
        .baseSpeed     = 60,
        .baseSpAttack  = 50,
        .baseSpDefense = 55,
        .types = { TYPE_BUG, TYPE_FIRE },
        .catchRate = 45,
        .expYield = 72,
        .evYield_Attack = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 40,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_BUG, EGG_GROUP_BUG },
        .abilities = { ABILITY_FLAME_BODY, ABILITY_NONE, ABILITY_SWARM },
        .bodyColor = BODY_COLOR_WHITE,
        .speciesName = _("Ignivor"),
        .cryId = CRY_LARVESTA,
        .natDexNum = NATIONAL_DEX_LARVESTA,
        .categoryName = _("Fackel"),
        .height = 11,
        .weight = 288,
        .description = POKEDEX_DESC_STRING(
            "Vor langer Zeit glaubten die Menschen,\n"
            "Ignivor sei von der Sonne herabgefallen."),
        .pokemonScale = 320,
        .pokemonOffset = 10,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Larvesta, 40, 48),
        .frontPicYOffset = 13,
        .frontAnimFrames = sAnims_Larvesta,
        .frontAnimId = ANIM_GLOW_ORANGE,
        BACK_PIC(Larvesta, 64, 48),
        .backPicYOffset = 12,
        .backAnimId = BACK_ANIM_H_SLIDE,
        PALETTES(Larvesta),
        ICON(Larvesta, 0),
        .footprint = gMonFootprint_Larvesta,
        LEARNSETS(Larvesta),
        .evolutions = EVOLUTION({EVO_LEVEL, 59, SPECIES_VOLCARONA}),
    },

    [SPECIES_VOLCARONA] =
    {
        .baseHP        = 85,
        .baseAttack    = 60,
        .baseDefense   = 65,
        .baseSpeed     = 100,
        .baseSpAttack  = 135,
        .baseSpDefense = 105,
        .types = { TYPE_BUG, TYPE_FIRE },
        .catchRate = 15,
        .expYield = 248,
        .evYield_SpAttack = 3,
        .itemCommon = ITEM_SILVER_POWDER,
        .itemRare = ITEM_SILVER_POWDER,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 40,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_BUG, EGG_GROUP_BUG },
        .abilities = { ABILITY_FLAME_BODY, ABILITY_NONE, ABILITY_SWARM },
        .bodyColor = BODY_COLOR_WHITE,
        .speciesName = _("Ramoth"),
        .cryId = CRY_VOLCARONA,
        .natDexNum = NATIONAL_DEX_VOLCARONA,
        .categoryName = _("Sonnen"),
        .height = 16,
        .weight = 460,
        .description = POKEDEX_DESC_STRING(
            "Es heißt, als das Land einst unter einer\n"
            "düsteren Wolke aus Vulkanasche lag,\n"
            "übernahm es die Rolle der Sonne."),
        .pokemonScale = 259,
        .pokemonOffset = 1,
        .trainerScale = 296,
        .trainerOffset = 1,
        FRONT_PIC(Volcarona, 64, 56),
        .frontPicYOffset = 4,
        .frontAnimFrames = sAnims_Volcarona,
        .frontAnimId = ANIM_V_SLIDE_WOBBLE,
        .enemyMonElevation = 6,
        BACK_PIC(Volcarona, 64, 64),
        .backPicYOffset = 3,
        .backAnimId = BACK_ANIM_SHAKE_GLOW_RED,
        PALETTES(Volcarona),
        ICON(Volcarona, 0),
        .footprint = gMonFootprint_Volcarona,
        LEARNSETS(Volcarona),
    },
#endif //P_FAMILY_LARVESTA

#if P_FAMILY_COBALION
    [SPECIES_COBALION] =
    {
        .baseHP        = 91,
        .baseAttack    = 90,
        .baseDefense   = 129,
        .baseSpeed     = 108,
        .baseSpAttack  = 90,
        .baseSpDefense = 72,
        .types = { TYPE_STEEL, TYPE_FIGHTING },
        .catchRate = 3,
        .expYield = 261,
        .evYield_Defense = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 80,
        .friendship = 35,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_NO_EGGS_DISCOVERED, EGG_GROUP_NO_EGGS_DISCOVERED },
        .abilities = { ABILITY_JUSTIFIED, ABILITY_NONE },
        .bodyColor = BODY_COLOR_BLUE,
        .isLegendary = TRUE,
        .speciesName = _("Kobalium"),
        .cryId = CRY_COBALION,
        .natDexNum = NATIONAL_DEX_COBALION,
        .categoryName = _("Eisenkern"),
        .height = 21,
        .weight = 2500,
        .description = POKEDEX_DESC_STRING(
            "Sein Körper und Herz sind aus Stahl.\n"
            "Gemeinsam mit seinen Gefährten bestrafte\n"
            "es alle Menschen, die Pokémon verletzen."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 365,
        .trainerOffset = 7,
        FRONT_PIC(Cobalion, 48, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_Cobalion,
        .frontAnimId = ANIM_V_STRETCH,
        BACK_PIC(Cobalion, 48, 64),
        .backPicYOffset = 6,
        .backAnimId = BACK_ANIM_V_STRETCH,
        PALETTES(Cobalion),
        ICON(Cobalion, 0),
        .footprint = gMonFootprint_Cobalion,
        LEARNSETS(Cobalion),
    },
#endif //P_FAMILY_COBALION

#if P_FAMILY_TERRAKION
    [SPECIES_TERRAKION] =
    {
        .baseHP        = 91,
        .baseAttack    = 129,
        .baseDefense   = 90,
        .baseSpeed     = 108,
        .baseSpAttack  = 72,
        .baseSpDefense = 90,
        .types = { TYPE_ROCK, TYPE_FIGHTING },
        .catchRate = 3,
        .expYield = 261,
        .evYield_Attack = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 80,
        .friendship = 35,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_NO_EGGS_DISCOVERED, EGG_GROUP_NO_EGGS_DISCOVERED },
        .abilities = { ABILITY_JUSTIFIED, ABILITY_NONE },
        .bodyColor = BODY_COLOR_GRAY,
        .isLegendary = TRUE,
        .speciesName = _("Terrakium"),
        .cryId = CRY_TERRAKION,
        .natDexNum = NATIONAL_DEX_TERRAKION,
        .categoryName = _("Felsenhöhlen"),
        .height = 19,
        .weight = 2600,
        .description = POKEDEX_DESC_STRING(
            "Seine Angriffskraft genügt, um\n"
            "selbst mächtige Wälle\n"
            "niederzureißen. Ein Held\n"
            "zahlreicher Legenden."),
        .pokemonScale = 256,
        .pokemonOffset = 1,
        .trainerScale = 336,
        .trainerOffset = 4,
        FRONT_PIC(Terrakion, 64, 56),
        .frontPicYOffset = 5,
        .frontAnimFrames = sAnims_Terrakion,
        .frontAnimId = ANIM_V_SHAKE_TWICE,
        BACK_PIC(Terrakion, 64, 48),
        .backPicYOffset = 8,
        .backAnimId = BACK_ANIM_V_SHAKE_LOW,
        PALETTES(Terrakion),
        ICON(Terrakion, 2),
        .footprint = gMonFootprint_Terrakion,
        LEARNSETS(Terrakion),
    },
#endif //P_FAMILY_TERRAKION

#if P_FAMILY_VIRIZION
    [SPECIES_VIRIZION] =
    {
        .baseHP        = 91,
        .baseAttack    = 90,
        .baseDefense   = 72,
        .baseSpeed     = 108,
        .baseSpAttack  = 90,
        .baseSpDefense = 129,
        .types = { TYPE_GRASS, TYPE_FIGHTING },
        .catchRate = 3,
        .expYield = 261,
        .evYield_SpDefense = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 80,
        .friendship = 35,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_NO_EGGS_DISCOVERED, EGG_GROUP_NO_EGGS_DISCOVERED },
        .abilities = { ABILITY_JUSTIFIED, ABILITY_NONE },
        .bodyColor = BODY_COLOR_GREEN,
        .isLegendary = TRUE,
        .speciesName = _("Viridium"),
        .cryId = CRY_VIRIZION,
        .natDexNum = NATIONAL_DEX_VIRIZION,
        .categoryName = _("Wiesen"),
        .height = 20,
        .weight = 2000,
        .description = POKEDEX_DESC_STRING(
            "Das Horn an seinem Kopf ist eine\n"
            "scharfe Klinge. Neckt seine Gegner\n"
            "mit quirligen Bewegungen und greift\n"
            "blitzartig an."),
        .pokemonScale = 261,
        .pokemonOffset = 1,
        .trainerScale = 344,
        .trainerOffset = 4,
        FRONT_PIC(Virizion, 48, 64),
        .frontPicYOffset = 2,
        .frontAnimFrames = sAnims_Virizion,
        .frontAnimId = ANIM_GROW_VIBRATE,
        BACK_PIC(Virizion, 64, 56),
        .backPicYOffset = 8,
        .backAnimId = BACK_ANIM_H_SHAKE,
        PALETTES(Virizion),
        ICON(Virizion, 1),
        .footprint = gMonFootprint_Virizion,
        LEARNSETS(Virizion),
    },
#endif //P_FAMILY_VIRIZION

#if P_FAMILY_TORNADUS
#define TORNADUS_MISC_INFO                                                              \
        .types = { TYPE_FLYING, TYPE_FLYING },                                          \
        .catchRate = 3,                                                                 \
        .expYield = 261,                                                                \
        .evYield_Attack = 3,                                                            \
        .genderRatio = MON_MALE,                                                        \
        .eggCycles = 120,                                                               \
        .friendship = 90,                                                               \
        .growthRate = GROWTH_SLOW,                                                      \
        .eggGroups = { EGG_GROUP_NO_EGGS_DISCOVERED, EGG_GROUP_NO_EGGS_DISCOVERED },    \
        .bodyColor = BODY_COLOR_GREEN,                                                  \
        .isLegendary = TRUE,                                                            \
        .speciesName = _("Viridium"),                                                   \
        .natDexNum = NATIONAL_DEX_TORNADUS,                                             \
        .categoryName = _("Wiesen"),                                                   \
        .weight = 630,                                                                  \
        .footprint = gMonFootprint_Tornadus,                                            \
        LEARNSETS(Tornadus),                                                            \
        .formSpeciesIdTable = sTornadusFormSpeciesIdTable,                              \
        .formChangeTable = sTornadusFormChangeTable

    [SPECIES_TORNADUS_INCARNATE] =
    {
        TORNADUS_MISC_INFO,
        .baseHP        = 79,
        .baseAttack    = 115,
        .baseDefense   = 70,
        .baseSpeed     = 111,
        .baseSpAttack  = 125,
        .baseSpDefense = 80,
        .abilities = { ABILITY_PRANKSTER, ABILITY_NONE, ABILITY_DEFIANT },
        .cryId = CRY_TORNADUS_INCARNATE,
        .height = 15,
        .description = POKEDEX_DESC_STRING(
            "Sein Unterkörper ist in eine\n"
            "wolkenartige Energieschicht\n"
            "gehüllt. Es jagt mit bis zu 300\n"
            "km/h durch die Lüfte."),
        .pokemonScale = 268,
        .pokemonOffset = 2,
        .trainerScale = 271,
        .trainerOffset = 0,
        FRONT_PIC(TornadusIncarnate, 64, 64),
        .frontPicYOffset = 1,
        .frontAnimFrames = sAnims_TornadusIncarnate,
        .frontAnimId = ANIM_FIGURE_8,
        .enemyMonElevation = 7,
        BACK_PIC(TornadusIncarnate, 64, 64),
        .backPicYOffset = 0,
        .backAnimId = BACK_ANIM_V_SHAKE,
        PALETTES(TornadusIncarnate),
        ICON(TornadusIncarnate, 1),
    },

    [SPECIES_TORNADUS_THERIAN] =
    {
        TORNADUS_MISC_INFO,
        .baseHP        = 79,
        .baseAttack    = 100,
        .baseDefense   = 80,
        .baseSpeed     = 121,
        .baseSpAttack  = 110,
        .baseSpDefense = 90,
        .abilities = { ABILITY_REGENERATOR, ABILITY_NONE, ABILITY_REGENERATOR },
        .cryId = CRY_TORNADUS_THERIAN,
        .height = 14,
        .description = POKEDEX_DESC_STRING(
            "Sein Unterkörper ist in eine\n"
            "wolkenartige Energieschicht\n"
            "gehüllt. Es jagt mit bis zu 300\n"
            "km/h durch die Lüfte."),
        .pokemonScale = 268,
        .pokemonOffset = 2,
        .trainerScale = 271,
        .trainerOffset = 0,
        FRONT_PIC(TornadusTherian, 64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_TornadusTherian,
        .frontAnimId = ANIM_V_STRETCH,
        BACK_PIC(TornadusTherian, 56, 64),
        .backPicYOffset = 0,
        .backAnimId = BACK_ANIM_SHRINK_GROW_VIBRATE,
        PALETTES(TornadusTherian),
        ICON(TornadusTherian, 1),
    },
#endif //P_FAMILY_TORNADUS

#if P_FAMILY_THUNDURUS
#define THUNDURUS_MISC_INFO                                                             \
        .types = { TYPE_ELECTRIC, TYPE_FLYING },                                        \
        .catchRate = 3,                                                                 \
        .expYield = 261,                                                                \
        .genderRatio = MON_MALE,                                                        \
        .eggCycles = 120,                                                               \
        .friendship = 90,                                                               \
        .growthRate = GROWTH_SLOW,                                                      \
        .eggGroups = { EGG_GROUP_NO_EGGS_DISCOVERED, EGG_GROUP_NO_EGGS_DISCOVERED },    \
        .bodyColor = BODY_COLOR_BLUE,                                                   \
        .isLegendary = TRUE,                                                            \
        .speciesName = _("Boreos"),                                                  \
        .natDexNum = NATIONAL_DEX_THUNDURUS,                                            \
        .categoryName = _("Wirbelsturm"),                                               \
        .weight = 610,                                                                  \
        .footprint = gMonFootprint_Thundurus,                                           \
        LEARNSETS(Thundurus),                                                           \
        .formSpeciesIdTable = sThundurusFormSpeciesIdTable,                             \
        .formChangeTable = sThundurusFormChangeTable

    [SPECIES_THUNDURUS_INCARNATE] =
    {
        THUNDURUS_MISC_INFO,
        .baseHP        = 79,
        .baseAttack    = 115,
        .baseDefense   = 70,
        .baseSpeed     = 111,
        .baseSpAttack  = 125,
        .baseSpDefense = 80,
        .evYield_Attack = 3,
        .abilities = { ABILITY_PRANKSTER, ABILITY_NONE, ABILITY_DEFIANT },
        .cryId = CRY_THUNDURUS_INCARNATE,
        .height = 15,
        .description = POKEDEX_DESC_STRING(
            "Es greift mit elektrischer Ladung\n"
            "aus den Dornen seiner Rute an und\n"
            "bombardiert Einall aus der Luft mit\n"
            "Blitzen."),
        .pokemonScale = 268,
        .pokemonOffset = 2,
        .trainerScale = 271,
        .trainerOffset = 0,
        FRONT_PIC(ThundurusIncarnate, 64, 64),
        .frontPicYOffset = 1,
        .frontAnimFrames = sAnims_ThundurusIncarnate,
        .frontAnimId = ANIM_FIGURE_8,
        .enemyMonElevation = 7,
        BACK_PIC(ThundurusIncarnate, 64, 64),
        .backPicYOffset = 0,
        .backAnimId = BACK_ANIM_V_SHAKE,
        PALETTES(ThundurusIncarnate),
        ICON(ThundurusIncarnate, 0),
    },

    [SPECIES_THUNDURUS_THERIAN] =
    {
        THUNDURUS_MISC_INFO,
        .baseHP        = 79,
        .baseAttack    = 105,
        .baseDefense   = 70,
        .baseSpeed     = 101,
        .baseSpAttack  = 145,
        .baseSpDefense = 80,
        .evYield_SpAttack = 3,
        .abilities = { ABILITY_VOLT_ABSORB, ABILITY_NONE, ABILITY_VOLT_ABSORB },
        .cryId = CRY_THUNDURUS_THERIAN,
        .height = 30,
        .description = POKEDEX_DESC_STRING(
            "Es greift mit elektrischer Ladung\n"
            "aus den Dornen seiner Rute an und\n"
            "bombardiert Einall aus der Luft mit\n"
            "Blitzen."),
        .pokemonScale = 268,
        .pokemonOffset = 2,
        .trainerScale = 271,
        .trainerOffset = 0,
        FRONT_PIC(ThundurusTherian, 64, 64),
        .frontPicYOffset = 2,
        .frontAnimFrames = sAnims_ThundurusTherian,
        .frontAnimId = ANIM_RISING_WOBBLE,
        .enemyMonElevation = 7,
        BACK_PIC(ThundurusTherian, 64, 64),
        .backPicYOffset = 5,
        .backAnimId = BACK_ANIM_SHAKE_FLASH_YELLOW,
        PALETTES(ThundurusTherian),
        ICON(ThundurusTherian, 0),
    },
#endif //P_FAMILY_THUNDURUS

#if P_FAMILY_RESHIRAM
    [SPECIES_RESHIRAM] =
    {
        .baseHP        = 100,
        .baseAttack    = 120,
        .baseDefense   = 100,
        .baseSpeed     = 90,
        .baseSpAttack  = 150,
        .baseSpDefense = 120,
        .types = { TYPE_DRAGON, TYPE_FIRE },
        .catchRate = 3,
        .expYield = 306,
        .evYield_SpAttack = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_NO_EGGS_DISCOVERED, EGG_GROUP_NO_EGGS_DISCOVERED },
        .abilities = { ABILITY_TURBOBLAZE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_WHITE,
        .isLegendary = TRUE,
        .speciesName = _("Reshiram"),
        .cryId = CRY_RESHIRAM,
        .natDexNum = NATIONAL_DEX_RESHIRAM,
        .categoryName = _("Wahres Weiß"),
        .height = 32,
        .weight = 3300,
        .description = POKEDEX_DESC_STRING(
            "Lodert das Feuer in seinem Schweif auf,\n"
            "gerät die Erdatmosphäre durch die Hitze in\n"
            "Wallung und das Weltklima ändert sich."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 445,
        .trainerOffset = 8,
        FRONT_PIC(Reshiram, 64, 64),
        .frontPicYOffset = 1,
        .frontAnimFrames = sAnims_Reshiram,
        .frontAnimId = ANIM_V_SHAKE,
        BACK_PIC(Reshiram, 64, 64),
        .backPicYOffset = 7,
        .backAnimId = BACK_ANIM_SHAKE_GLOW_RED,
        PALETTES(Reshiram),
        ICON(Reshiram, 0),
        .footprint = gMonFootprint_Reshiram,
        LEARNSETS(Reshiram),
    },
#endif //P_FAMILY_RESHIRAM

#if P_FAMILY_ZEKROM
    [SPECIES_ZEKROM] =
    {
        .baseHP        = 100,
        .baseAttack    = 150,
        .baseDefense   = 120,
        .baseSpeed     = 90,
        .baseSpAttack  = 120,
        .baseSpDefense = 100,
        .types = { TYPE_DRAGON, TYPE_ELECTRIC },
        .catchRate = 3,
        .expYield = 306,
        .evYield_Attack = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_NO_EGGS_DISCOVERED, EGG_GROUP_NO_EGGS_DISCOVERED },
        .abilities = { ABILITY_TERAVOLT, ABILITY_NONE },
        .bodyColor = BODY_COLOR_BLACK,
        .isLegendary = TRUE,
        .speciesName = _("Zekrom"),
        .cryId = CRY_ZEKROM,
        .natDexNum = NATIONAL_DEX_ZEKROM,
        .categoryName = _("Reines Schwarz"),
        .height = 29,
        .weight = 3450,
        .description = POKEDEX_DESC_STRING(
            "Sein Schweif erzeugt Strom. Es verbirgt\n"
            "sich hinter dichten Gewitterwolken und\n"
            "fliegt durch den Luftraum über Einall."),
        .pokemonScale = 275,
        .pokemonOffset = 2,
        .trainerScale = 412,
        .trainerOffset = 10,
        FRONT_PIC(Zekrom, 64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_Zekrom,
        .frontAnimId = ANIM_V_SHAKE,
        BACK_PIC(Zekrom, 64, 64),
        .backPicYOffset = 3,
        .backAnimId = BACK_ANIM_SHAKE_GLOW_BLUE,
        PALETTES(Zekrom),
        ICON(Zekrom, 2),
        .footprint = gMonFootprint_Zekrom,
        LEARNSETS(Zekrom),
    },
#endif //P_FAMILY_ZEKROM

#if P_FAMILY_LANDORUS
#define LANDORUS_MISC_INFO                                                              \
        .types = { TYPE_GROUND, TYPE_FLYING },                                          \
        .catchRate = 3,                                                                 \
        .expYield = 270,                                                                \
        .genderRatio = MON_MALE,                                                        \
        .eggCycles = 120,                                                               \
        .friendship = 90,                                                               \
        .growthRate = GROWTH_SLOW,                                                      \
        .eggGroups = { EGG_GROUP_NO_EGGS_DISCOVERED, EGG_GROUP_NO_EGGS_DISCOVERED },    \
        .bodyColor = BODY_COLOR_BROWN,                                                  \
        .isLegendary = TRUE,                                                            \
        .speciesName = _("Zekrom"),                                                   \
        .natDexNum = NATIONAL_DEX_LANDORUS,                                             \
        .categoryName = _("Reines Schwarz"),                                                 \
        .weight = 680,                                                                  \
        .footprint = gMonFootprint_Landorus,                                            \
        LEARNSETS(Landorus),                                                            \
        .formSpeciesIdTable = sLandorusFormSpeciesIdTable,                              \
        .formChangeTable = sLandorusFormChangeTable

    [SPECIES_LANDORUS_INCARNATE] =
    {
        LANDORUS_MISC_INFO,
        .baseHP        = 89,
        .baseAttack    = 125,
        .baseDefense   = 90,
        .baseSpeed     = 101,
        .baseSpAttack  = 115,
        .baseSpDefense = 80,
        .evYield_SpAttack = 3,
        .abilities = { ABILITY_SAND_FORCE, ABILITY_NONE, ABILITY_SHEER_FORCE },
        .cryId = CRY_LANDORUS_INCARNATE,
        .height = 15,
        .description = POKEDEX_DESC_STRING(
            "Da an Orten, wo es sich blicken\n"
            "lässt, mit reicher Ernte zu rechnen\n"
            "ist, nennt man es auch den "Herrn\n"
            "des Ackerbaus"."),
        .pokemonScale = 268,
        .pokemonOffset = 2,
        .trainerScale = 271,
        .trainerOffset = 0,
        FRONT_PIC(LandorusIncarnate, 64, 64),
        .frontPicYOffset = 1,
        .frontAnimFrames = sAnims_LandorusIncarnate,
        .frontAnimId = ANIM_FIGURE_8,
        .enemyMonElevation = 7,
        BACK_PIC(LandorusIncarnate, 64, 64),
        .backPicYOffset = 0,
        .backAnimId = BACK_ANIM_V_SHAKE,
        PALETTES(LandorusIncarnate),
        ICON(LandorusIncarnate, 0),
    },

    [SPECIES_LANDORUS_THERIAN] =
    {
        LANDORUS_MISC_INFO,
        .baseHP        = 89,
        .baseAttack    = 145,
        .baseDefense   = 90,
        .baseSpeed     = 91,
        .baseSpAttack  = 105,
        .baseSpDefense = 80,
        .evYield_Attack = 3,
        .abilities = { ABILITY_INTIMIDATE, ABILITY_NONE },
        .cryId = CRY_LANDORUS_THERIAN,
        .height = 13,
        .description = POKEDEX_DESC_STRING(
            "Da an Orten, wo es sich blicken\n"
            "lässt, mit reicher Ernte zu rechnen\n"
            "ist, nennt man es auch den "Herrn\n"
            "des Ackerbaus"."),
        .pokemonScale = 268,
        .pokemonOffset = 2,
        .trainerScale = 271,
        .trainerOffset = 0,
        FRONT_PIC(LandorusTherian, 64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_LandorusTherian,
        .frontAnimId = ANIM_CIRCULAR_VIBRATE,
        BACK_PIC(LandorusTherian, 64, 56),
        .backPicYOffset = 7,
        .backAnimId = BACK_ANIM_GROW_STUTTER,
        PALETTES(LandorusTherian),
        ICON(LandorusTherian, 0),
    },
#endif //P_FAMILY_LANDORUS

#if P_FAMILY_KYUREM
#define KYUREM_MISC_INFO                                                                \
        .types = { TYPE_DRAGON, TYPE_ICE },                                             \
        .catchRate = 3,                                                                 \
        .genderRatio = MON_GENDERLESS,                                                  \
        .eggCycles = 120,                                                               \
        .friendship = 0,                                                                \
        .growthRate = GROWTH_SLOW,                                                      \
        .eggGroups = { EGG_GROUP_NO_EGGS_DISCOVERED, EGG_GROUP_NO_EGGS_DISCOVERED },    \
        .bodyColor = BODY_COLOR_GRAY,                                                   \
        .noFlip = TRUE,                                                                 \
        .speciesName = _("Demeteros"),                                                     \
        .natDexNum = NATIONAL_DEX_KYUREM,                                               \
        .categoryName = _("Reichtums"),                                                  \
        .weight = 3250,                                                                 \
        .footprint = gMonFootprint_Kyurem,                                              \
        .formSpeciesIdTable = sKyuremFormSpeciesIdTable,                                \
        .isLegendary = TRUE

    [SPECIES_KYUREM] =
    {
        KYUREM_MISC_INFO,
        .baseHP        = 125,
        .baseAttack    = 130,
        .baseDefense   = 90,
        .baseSpeed     = 95,
        .baseSpAttack  = 130,
        .baseSpDefense = 90,
        .expYield = 297,
        .evYield_HP = 1,
        .evYield_Attack = 1,
        .evYield_SpAttack = 1,
        .abilities = { ABILITY_PRESSURE, ABILITY_NONE },
        .cryId = CRY_KYUREM,
        .height = 30,
        .description = POKEDEX_DESC_STRING(
            "Ein Legendäres Eis-Pokémon, das auf\n"
            "den Helden wartet, der seinen\n"
            "verstümmelten Körper mit Wunsch und\n"
            "Wirklichkeit heilt."),
        .pokemonScale = 275,
        .pokemonOffset = 7,
        .trainerScale = 356,
        .trainerOffset = 0,
        FRONT_PIC(Kyurem, 64, 64),
        .frontPicYOffset = 6,
        .frontAnimFrames = sAnims_Kyurem,
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(Kyurem, 64, 40),
        .backPicYOffset = 12,
        .backAnimId = BACK_ANIM_V_SHAKE_LOW,
        PALETTES(Kyurem),
        ICON(Kyurem, 0),
        LEARNSETS(Kyurem),
    },

#if P_FUSION_FORMS
    [SPECIES_KYUREM_WHITE] =
    {
        KYUREM_MISC_INFO,
        .baseHP        = 125,
        .baseAttack    = 120,
        .baseDefense   = 90,
        .baseSpeed     = 95,
        .baseSpAttack  = 170,
        .baseSpDefense = 100,
        .expYield = 315,
        .evYield_SpAttack = 3,
        .abilities = { ABILITY_TURBOBLAZE, ABILITY_NONE },
        .cryId = CRY_KYUREM_WHITE,
        .height = 36,
        .description = POKEDEX_DESC_STRING(
            "Ein Legendäres Eis-Pokémon, das auf\n"
            "den Helden wartet, der seinen\n"
            "verstümmelten Körper mit Wunsch und\n"
            "Wirklichkeit heilt."),
        .pokemonScale = 275,
        .pokemonOffset = 7,
        .trainerScale = 356,
        .trainerOffset = 0,
        FRONT_PIC(KyuremWhite, 64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_KyuremWhite,
        .frontAnimId = ANIM_H_SHAKE,
        BACK_PIC(KyuremWhite, 64, 64),
        .backPicYOffset = 0,
        .backAnimId = BACK_ANIM_SHAKE_GLOW_RED,
        PALETTES(KyuremWhite),
        ICON(KyuremWhite, 0),
        //.levelUpLearnset = sKyuremWhiteLevelUpLearnset,
        //.teachableLearnset = sKyuremTeachableLearnset,
        .cannotBeTraded = TRUE,
    },

    [SPECIES_KYUREM_BLACK] =
    {
        KYUREM_MISC_INFO,
        .baseHP        = 125,
        .baseAttack    = 170,
        .baseDefense   = 100,
        .baseSpeed     = 95,
        .baseSpAttack  = 120,
        .baseSpDefense = 90,
        .expYield = 315,
        .evYield_Attack = 3,
        .abilities = { ABILITY_TERAVOLT, ABILITY_NONE },
        .cryId = CRY_KYUREM_BLACK,
        .height = 33,
        .description = POKEDEX_DESC_STRING(
            "Ein Legendäres Eis-Pokémon, das auf\n"
            "den Helden wartet, der seinen\n"
            "verstümmelten Körper mit Wunsch und\n"
            "Wirklichkeit heilt."),
        .pokemonScale = 275,
        .pokemonOffset = 7,
        .trainerScale = 356,
        .trainerOffset = 0,
        FRONT_PIC(KyuremBlack, 64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_KyuremBlack,
        .frontAnimId = ANIM_V_SHAKE,
        BACK_PIC(KyuremBlack, 64, 64),
        .backPicYOffset = 3,
        .backAnimId = BACK_ANIM_SHAKE_GLOW_BLUE,
        PALETTES(KyuremBlack),
        ICON(KyuremBlack, 0),
        //.levelUpLearnset = sKyuremBlackLevelUpLearnset,
        //.teachableLearnset = sKyuremTeachableLearnset,
        .cannotBeTraded = TRUE,
    },
#endif //P_FUSION_FORMS
#endif //P_FAMILY_KYUREM

#if P_FAMILY_KELDEO
#define KELDEO_MISC_INFO                                                                \
        .baseHP        = 91,                                                            \
        .baseAttack    = 72,                                                            \
        .baseDefense   = 90,                                                            \
        .baseSpeed     = 108,                                                           \
        .baseSpAttack  = 129,                                                           \
        .baseSpDefense = 90,                                                            \
        .types = { TYPE_WATER, TYPE_FIGHTING },                                         \
        .catchRate = 3,                                                                 \
        .expYield = 261,                                                                \
        .evYield_SpAttack = 3,                                                          \
        .genderRatio = MON_GENDERLESS,                                                  \
        .eggCycles = 80,                                                                \
        .friendship = 35,                                                               \
        .growthRate = GROWTH_SLOW,                                                      \
        .eggGroups = { EGG_GROUP_NO_EGGS_DISCOVERED, EGG_GROUP_NO_EGGS_DISCOVERED },    \
        .abilities = { ABILITY_JUSTIFIED, ABILITY_NONE },                               \
        .bodyColor = BODY_COLOR_YELLOW,                                                 \
        .isMythical = TRUE,                                                             \
        .speciesName = _("Kyurem"),                                                     \
        .cryId = CRY_KELDEO,                                                            \
        .natDexNum = NATIONAL_DEX_KELDEO,                                               \
        .categoryName = _("Schwellen"),                                                      \
        .height = 14,                                                                   \
        .weight = 485,                                                                  \
        .pokemonScale = 265,                                                            \
        .pokemonOffset = 2,                                                             \
        .trainerScale = 262,                                                            \
        .trainerOffset = 0,                                                             \
        .footprint = gMonFootprint_Keldeo,                                              \
        LEARNSETS(Keldeo),                                                              \
        .formSpeciesIdTable = sKeldeoFormSpeciesIdTable,                                \
        .formChangeTable = sKeldeoFormChangeTable

    [SPECIES_KELDEO_ORDINARY] =
    {
        KELDEO_MISC_INFO,
        .description = POKEDEX_DESC_STRING(
            "Es kann auf dem Wasser laufen und\n"
            "reist auf Flüssen und Meeren um die\n"
            "Welt. Zu sehen in malerischen\n"
            "Küstengebieten."),
        FRONT_PIC(KeldeoOrdinary, 56, 56),
        .frontPicYOffset = 5,
        .frontAnimFrames = sAnims_KeldeoOrdinary,
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(KeldeoOrdinary, 56, 64),
        .backPicYOffset = 4,
        .backAnimId = BACK_ANIM_JOLT_RIGHT,
        PALETTES(KeldeoOrdinary),
        ICON(KeldeoOrdinary, 0),
    },

    [SPECIES_KELDEO_RESOLUTE] =
    {
        KELDEO_MISC_INFO,
        .noFlip = TRUE,
        .description = POKEDEX_DESC_STRING(
            "Es kann auf dem Wasser laufen und\n"
            "reist auf Flüssen und Meeren um die\n"
            "Welt. Zu sehen in malerischen\n"
            "Küstengebieten."),
        FRONT_PIC(KeldeoResolute, 64, 64),
        .frontPicYOffset = 2,
        .frontAnimFrames = sAnims_KeldeoResolute,
        .frontAnimId = ANIM_V_STRETCH,
        BACK_PIC(KeldeoResolute, 64, 64),
        .backPicYOffset = 3,
        .backAnimId = BACK_ANIM_GROW_STUTTER,
        PALETTES(KeldeoResolute),
        ICON(KeldeoResolute, 0),
    },
#endif //P_FAMILY_KELDEO

#if P_FAMILY_MELOETTA
#define MELOETTA_MISC_INFO                                                              \
        .catchRate = 3,                                                                 \
        .expYield = 270,                                                                \
        .evYield_Speed = 1,                                                             \
        .itemCommon = ITEM_STAR_PIECE,                                                  \
        .itemRare = ITEM_STAR_PIECE,                                                    \
        .genderRatio = MON_GENDERLESS,                                                  \
        .eggCycles = 120,                                                               \
        .friendship = 100,                                                              \
        .growthRate = GROWTH_SLOW,                                                      \
        .eggGroups = { EGG_GROUP_NO_EGGS_DISCOVERED, EGG_GROUP_NO_EGGS_DISCOVERED },    \
        .abilities = { ABILITY_SERENE_GRACE, ABILITY_NONE },                            \
        .bodyColor = BODY_COLOR_WHITE,                                                  \
        .noFlip = TRUE,                                                                 \
        .isMythical = TRUE,                                                             \
        .speciesName = _("Keldeo"),                                                   \
        .cryId = CRY_MELOETTA,                                                          \
        .natDexNum = NATIONAL_DEX_MELOETTA,                                             \
        .categoryName = _("Fohlen"),                                                    \
        .height = 6,                                                                    \
        .weight = 65,                                                                   \
        .pokemonScale = 422,                                                            \
        .pokemonOffset = 12,                                                            \
        .trainerScale = 256,                                                            \
        .trainerOffset = 0,                                                             \
        .footprint = gMonFootprint_Meloetta,                                            \
        LEARNSETS(Meloetta),                                                            \
        .formSpeciesIdTable = sMeloettaFormSpeciesIdTable,                              \
        .formChangeTable = sMeloettaFormChangeTable

    [SPECIES_MELOETTA_ARIA] =
    {
        MELOETTA_MISC_INFO,
        .baseHP        = 100,
        .baseAttack    = 77,
        .baseDefense   = 77,
        .baseSpeed     = 90,
        .baseSpAttack  = 128,
        .baseSpDefense = 128,
        .types = { TYPE_NORMAL, TYPE_PSYCHIC },
        .evYield_SpAttack = 1,
        .evYield_SpDefense = 1,
        .description = POKEDEX_DESC_STRING(
            "Es besitzt die Macht, Pokémon, die\n"
            "sich in seiner Nähe aufhalten, mit\n"
            "seinen Melodien froh oder traurig\n"
            "zu stimmen."),
        FRONT_PIC(MeloettaAria, 32, 48),
        .frontPicYOffset = 9,
        .frontAnimFrames = sAnims_MeloettaAria,
        .frontAnimId = ANIM_GROW_VIBRATE,
        .enemyMonElevation = 8,
        BACK_PIC(MeloettaAria, 48, 56),
        .backPicYOffset = 7,
        .backAnimId = BACK_ANIM_CONVEX_DOUBLE_ARC,
        PALETTES(MeloettaAria),
        ICON(MeloettaAria, 4),
    },

    [SPECIES_MELOETTA_PIROUETTE] =
    {
        MELOETTA_MISC_INFO,
        .baseHP        = 100,
        .baseAttack    = 128,
        .baseDefense   = 90,
        .baseSpeed     = 128,
        .baseSpAttack  = 77,
        .baseSpDefense = 77,
        .types = { TYPE_NORMAL, TYPE_FIGHTING },
        .evYield_Attack = 1,
        .evYield_Defense = 1,
        .description = POKEDEX_DESC_STRING(
            "Es besitzt die Macht, Pokémon, die\n"
            "sich in seiner Nähe aufhalten, mit\n"
            "seinen Melodien froh oder traurig\n"
            "zu stimmen."),
        FRONT_PIC(MeloettaPirouette, 40, 64),
        .frontPicYOffset = 2,
        .frontAnimFrames = sAnims_MeloettaPirouette,
        .frontAnimId = ANIM_H_SLIDE_SLOW,
        .enemyMonElevation = 5,
        BACK_PIC(MeloettaPirouette, 56, 64),
        .backPicYOffset = 4,
        .backAnimId = BACK_ANIM_TRIANGLE_DOWN,
        PALETTES(MeloettaPirouette),
        ICON(MeloettaPirouette, 0),
    },
#endif //P_FAMILY_MELOETTA

#if P_FAMILY_GENESECT
#define GENESECT_SPECIES_INFO(form)                                                     \
    {                                                                                   \
        .baseHP        = 71,                                                            \
        .baseAttack    = 120,                                                           \
        .baseDefense   = 95,                                                            \
        .baseSpeed     = 99,                                                            \
        .baseSpAttack  = 120,                                                           \
        .baseSpDefense = 95,                                                            \
        .types = { TYPE_BUG, TYPE_STEEL },                                              \
        .catchRate = 3,                                                                 \
        .expYield = 270,                                                                \
        .evYield_Attack = 1,                                                            \
        .evYield_Speed = 1,                                                             \
        .evYield_SpAttack = 1,                                                          \
        .genderRatio = MON_GENDERLESS,                                                  \
        .eggCycles = 120,                                                               \
        .friendship = 0,                                                                \
        .growthRate = GROWTH_SLOW,                                                      \
        .eggGroups = { EGG_GROUP_NO_EGGS_DISCOVERED, EGG_GROUP_NO_EGGS_DISCOVERED },    \
        .abilities = { ABILITY_DOWNLOAD, ABILITY_NONE },                                \
        .bodyColor = BODY_COLOR_PURPLE,                                                 \
        .speciesName = _("Genesect"),                                                   \
        .cryId = CRY_GENESECT,                                                          \
        .natDexNum = NATIONAL_DEX_GENESECT,                                             \
        .categoryName = _("Paläozoikum"),                                                 \
        .height = 15,                                                                   \
        .weight = 825,                                                                  \
        .description = gGenesectPokedexText,                                            \
        .pokemonScale = 268,                                                            \
        .pokemonOffset = 2,                                                             \
        .trainerScale = 271,                                                            \
        .trainerOffset = 0,                                                             \
        FRONT_PIC(Genesect, 56, 64),                                                    \
        .frontPicYOffset = 0,                                                           \
        .frontAnimFrames = sAnims_Genesect,                                             \
        .frontAnimId = ANIM_H_VIBRATE,                                                  \
        BACK_PIC(Genesect, 64, 48),                                                     \
        .backPicYOffset = 8,                                                            \
        .backAnimId = BACK_ANIM_CIRCLE_COUNTERCLOCKWISE,                                \
        PALETTES(form),                                                                 \
        ICON(Genesect, 2),                                                              \
        .footprint = gMonFootprint_Genesect,                                            \
        LEARNSETS(Genesect),                                                            \
        .formSpeciesIdTable = sGenesectFormSpeciesIdTable,                              \
        .formChangeTable = sGenesectFormChangeTable,                                    \
        .isMythical = TRUE,                                                             \
    }

    [SPECIES_GENESECT]             = GENESECT_SPECIES_INFO(Genesect),
    [SPECIES_GENESECT_DOUSE_DRIVE] = GENESECT_SPECIES_INFO(GenesectDouseDrive),
    [SPECIES_GENESECT_SHOCK_DRIVE] = GENESECT_SPECIES_INFO(GenesectShockDrive),
    [SPECIES_GENESECT_BURN_DRIVE]  = GENESECT_SPECIES_INFO(GenesectBurnDrive),
    [SPECIES_GENESECT_CHILL_DRIVE] = GENESECT_SPECIES_INFO(GenesectChillDrive),
#endif //P_FAMILY_GENESECT

#ifdef __INTELLISENSE__
};
#endif