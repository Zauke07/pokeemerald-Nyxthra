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
const u8 gEasyChatWord_Red[] = _("Rot");
const u8 gEasyChatWord_Green[] = _("Grün");
const u8 gEasyChatWord_Bag[] = _("Tasche");
const u8 gEasyChatWord_Flame[] = _("Flamme");
const u8 gEasyChatWord_Gold[] = _("Gold");
const u8 gEasyChatWord_Leaf[] = _("Blatt");
const u8 gEasyChatWord_Silver[] = _("Silber");
const u8 gEasyChatWord_Emerald[] = _("Smaragd");

const struct EasyChatWordInfo gEasyChatGroup_Trainer[] = {
    [EC_INDEX(EC_WORD_I_CHOOSE_YOU)] =
    {
        .text = gEasyChatWord_IChooseYou,
        .alphabeticalOrder = 21,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_GOTCHA)] =
    {
        .text = gEasyChatWord_Gotcha,
        .alphabeticalOrder = 7,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_TRADE)] =
    {
        .text = gEasyChatWord_Trade,
        .alphabeticalOrder = 8,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SAPPHIRE)] =
    {
        .text = gEasyChatWord_Sapphire,
        .alphabeticalOrder = 26,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_EVOLVE)] =
    {
        .text = gEasyChatWord_Evolve,
        .alphabeticalOrder = 5,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_ENCYCLOPEDIA)] =
    {
        .text = gEasyChatWord_Encyclopedia,
        .alphabeticalOrder = 4,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_NATURE)] =
    {
        .text = gEasyChatWord_Nature,
        .alphabeticalOrder = 22,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_CENTER)] =
    {
        .text = gEasyChatWord_Center,
        .alphabeticalOrder = 15,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_EGG)] =
    {
        .text = gEasyChatWord_Egg,
        .alphabeticalOrder = 23,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_LINK)] =
    {
        .text = gEasyChatWord_Link,
        .alphabeticalOrder = 1,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SP_ABILITY)] =
    {
        .text = gEasyChatWord_SpAbility,
        .alphabeticalOrder = 20,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_TRAINER)] =
    {
        .text = gEasyChatWord_Trainer,
        .alphabeticalOrder = 0,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_VERSION)] =
    {
        .text = gEasyChatWord_Version,
        .alphabeticalOrder = 24,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_POKENAV)] =
    {
        .text = gEasyChatWord_Pokenav,
        .alphabeticalOrder = 18,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_POKEMON)] =
    {
        .text = gEasyChatWord_Pokemon,
        .alphabeticalOrder = 9,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_GET)] =
    {
        .text = gEasyChatWord_Get,
        .alphabeticalOrder = 6,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_POKEDEX)] =
    {
        .text = gEasyChatWord_Pokedex,
        .alphabeticalOrder = 16,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_RUBY)] =
    {
        .text = gEasyChatWord_Ruby,
        .alphabeticalOrder = 14,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_LEVEL)] =
    {
        .text = gEasyChatWord_Level,
        .alphabeticalOrder = 13,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_RED)] =
    {
        .text = gEasyChatWord_Red,
        .alphabeticalOrder = 19,
        .enabled = FALSE,
    },
    [EC_INDEX(EC_WORD_GREEN)] =
    {
        .text = gEasyChatWord_Green,
        .alphabeticalOrder = 17,
        .enabled = FALSE,
    },
    [EC_INDEX(EC_WORD_BAG)] =
    {
        .text = gEasyChatWord_Bag,
        .alphabeticalOrder = 3,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_FLAME)] =
    {
        .text = gEasyChatWord_Flame,
        .alphabeticalOrder = 25,
        .enabled = FALSE,
    },
    [EC_INDEX(EC_WORD_GOLD)] =
    {
        .text = gEasyChatWord_Gold,
        .alphabeticalOrder = 10,
        .enabled = FALSE,
    },
    [EC_INDEX(EC_WORD_LEAF)] =
    {
        .text = gEasyChatWord_Leaf,
        .alphabeticalOrder = 2,
        .enabled = FALSE,
    },
    [EC_INDEX(EC_WORD_SILVER)] =
    {
        .text = gEasyChatWord_Silver,
        .alphabeticalOrder = 11,
        .enabled = FALSE,
    },
    [EC_INDEX(EC_WORD_EMERALD)] =
    {
        .text = gEasyChatWord_Emerald,
        .alphabeticalOrder = 12,
        .enabled = TRUE,
    },
};
