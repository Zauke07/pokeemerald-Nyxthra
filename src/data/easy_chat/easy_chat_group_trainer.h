const u8 gEasyChatWord_IChooseYou[] = _("Ich wähle dich");
const u8 gEasyChatWord_Gotcha[] = _("Gefangen");
const u8 gEasyChatWord_Trade[] = _("Tausch");
const u8 gEasyChatWord_Sapphire[] = _("Saphir");
const u8 gEasyChatWord_Evolve[] = _("Entwickeln");
const u8 gEasyChatWord_Encyclopedia[] = _("Enzyklopädie");
const u8 gEasyChatWord_Nature[] = _("Wesen");
const u8 gEasyChatWord_Center[] = _("Center");
const u8 gEasyChatWord_Egg[] = _("Ei");
const u8 gEasyChatWord_Link[] = _("Link");
const u8 gEasyChatWord_SpAbility[] = _("Spezialfähigkeit");
const u8 gEasyChatWord_Trainer[] = _("Trainer");
const u8 gEasyChatWord_Version[] = _("Version");
const u8 gEasyChatWord_Pokenav[] = _("PokéCom");
const u8 gEasyChatWord_Pokemon[] = _("Pokémon");
const u8 gEasyChatWord_Get[] = _("Fangen");
const u8 gEasyChatWord_Pokedex[] = _("Pokédex");
const u8 gEasyChatWord_Ruby[] = _("Rubin");
const u8 gEasyChatWord_Level[] = _("Level");
const u8 gEasyChatWord_Red[] = _("Red");
const u8 gEasyChatWord_Green[] = _("Grün");
const u8 gEasyChatWord_Bag[] = _("Tasche");
const u8 gEasyChatWord_Flame[] = _("Flamme");
const u8 gEasyChatWord_Gold[] = _("Gold");
const u8 gEasyChatWord_Leaf[] = _("Leaf");
const u8 gEasyChatWord_Silver[] = _("Silber");
const u8 gEasyChatWord_Emerald[] = _("Smaragd");

const struct EasyChatWordInfo gEasyChatGroup_Trainer[] = {
    [EC_INDEX(EC_WORD_I_CHOOSE_YOU)] =
    {
        .text = COMPOUND_STRING("I CHOOSE YOU"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_BAG),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_GOTCHA)] =
    {
        .text = COMPOUND_STRING("GOTCHA"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_CENTER),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_TRADE)] =
    {
        .text = COMPOUND_STRING("TRADE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_EGG),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SAPPHIRE)] =
    {
        .text = COMPOUND_STRING("SAPPHIRE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_EMERALD),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_EVOLVE)] =
    {
        .text = COMPOUND_STRING("EVOLVE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_ENCYCLOPEDIA),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_ENCYCLOPEDIA)] =
    {
        .text = COMPOUND_STRING("ENCYCLOPEDIA"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_EVOLVE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_NATURE)] =
    {
        .text = COMPOUND_STRING("NATURE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_FLAME),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_CENTER)] =
    {
        .text = COMPOUND_STRING("CENTER"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_GET),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_EGG)] =
    {
        .text = COMPOUND_STRING("EGG"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_GOLD),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_LINK)] =
    {
        .text = COMPOUND_STRING("LINK"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_GOTCHA),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SP_ABILITY)] =
    {
        .text = COMPOUND_STRING("SP. ABILITY"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_GREEN),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_TRAINER)] =
    {
        .text = COMPOUND_STRING("TRAINER"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_I_CHOOSE_YOU),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_VERSION)] =
    {
        .text = COMPOUND_STRING("VERSION"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_LEAF),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_POKENAV)] =
    {
        .text = COMPOUND_STRING("POKéNAV"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_LEVEL),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_POKEMON)] =
    {
        .text = COMPOUND_STRING("POKéMON"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_LINK),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_GET)] =
    {
        .text = COMPOUND_STRING("GET"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_NATURE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_POKEDEX)] =
    {
        .text = COMPOUND_STRING("POKéDEX"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_POKEDEX),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_RUBY)] =
    {
        .text = COMPOUND_STRING("RUBY"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_POKEMON),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_LEVEL)] =
    {
        .text = COMPOUND_STRING("LEVEL"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_POKENAV),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_RED)] =
    {
        .text = COMPOUND_STRING("RED"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_RED),
        .enabled = FALSE,
    },
    [EC_INDEX(EC_WORD_GREEN)] =
    {
        .text = COMPOUND_STRING("GREEN"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_RUBY),
        .enabled = FALSE,
    },
    [EC_INDEX(EC_WORD_BAG)] =
    {
        .text = COMPOUND_STRING("BAG"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SAPPHIRE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_FLAME)] =
    {
        .text = COMPOUND_STRING("FLAME"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SILVER),
        .enabled = FALSE,
    },
    [EC_INDEX(EC_WORD_GOLD)] =
    {
        .text = COMPOUND_STRING("GOLD"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SP_ABILITY),
        .enabled = FALSE,
    },
    [EC_INDEX(EC_WORD_LEAF)] =
    {
        .text = COMPOUND_STRING("LEAF"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_TRADE),
        .enabled = FALSE,
    },
    [EC_INDEX(EC_WORD_SILVER)] =
    {
        .text = COMPOUND_STRING("SILVER"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_TRAINER),
        .enabled = FALSE,
    },
    [EC_INDEX(EC_WORD_EMERALD)] =
    {
        .text = COMPOUND_STRING("EMERALD"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_VERSION),
        .enabled = TRUE,
    },
};
