const u8 gEasyChatWord_Wandering[] = _("Latsch");
const u8 gEasyChatWord_Rickety[] = _("Wackel");
const u8 gEasyChatWord_RockSolid[] = _("Steinhart");
const u8 gEasyChatWord_Hungry[] = _("Magenknurr");
const u8 gEasyChatWord_Tight[] = _("Knurschp");
const u8 gEasyChatWord_Ticklish[] = _("Kille kille");
const u8 gEasyChatWord_Twirling[] = _("Schleuder");
const u8 gEasyChatWord_Spiraling[] = _("Wirbel");
const u8 gEasyChatWord_Thirsty[] = _("Lechz");
const u8 gEasyChatWord_Lolling[] = _("Lümmel räkel");
const u8 gEasyChatWord_Silky[] = _("Wuschel");
const u8 gEasyChatWord_Sadly[] = _("Schnüff");
const u8 gEasyChatWord_Hopeless[] = _("Ooch");
const u8 gEasyChatWord_Useless[] = _("Müll");
const u8 gEasyChatWord_Drooling[] = _("Sabber");
const u8 gEasyChatWord_Exciting[] = _("Jipp! jipp!");
const u8 gEasyChatWord_Thick[] = _("Schwabbel");
const u8 gEasyChatWord_Smooth[] = _("Glatt");
const u8 gEasyChatWord_Slimy[] = _("Glibber");
const u8 gEasyChatWord_Thin[] = _("Klapper");
const u8 gEasyChatWord_Break[] = _("Schepper");
const u8 gEasyChatWord_Voracious[] = _("Mampf fress");
const u8 gEasyChatWord_Scatter[] = _("Schmeiss");
const u8 gEasyChatWord_Awesome[] = _("Irre");
const u8 gEasyChatWord_Wimpy[] = _("Angst bibber");
const u8 gEasyChatWord_Wobbly[] = _("Zitter");
const u8 gEasyChatWord_Shaky[] = _("Schüttel");
const u8 gEasyChatWord_Ripped[] = _("Fetz");
const u8 gEasyChatWord_Shredded[] = _("Wurgs");
const u8 gEasyChatWord_Increasing[] = _("Nööö");
const u8 gEasyChatWord_Yet[] = _("Rumms berst");
const u8 gEasyChatWord_Destroyed[] = _("Zisch fackel");
const u8 gEasyChatWord_Fiery[] = _("Schnuckelig");
const u8 gEasyChatWord_LoveyDovey[] = _("Megagrins");
const u8 gEasyChatWord_Happily[] = _("Grins hoff");
const u8 gEasyChatWord_Anticipation[] = _("Vorwegnahme");

const struct EasyChatWordInfo gEasyChatGroup_Adjectives[] = {
    [EC_INDEX(EC_WORD_WANDERING)] =
    {
        .text = COMPOUND_STRING("WANDERING"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_ANTICIPATION),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_RICKETY)] =
    {
        .text = COMPOUND_STRING("RICKETY"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_AWESOME),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_ROCK_SOLID)] =
    {
        .text = COMPOUND_STRING("ROCK-SOLID"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_BREAK),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HUNGRY)] =
    {
        .text = COMPOUND_STRING("HUNGRY"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_DESTROYED),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_TIGHT)] =
    {
        .text = COMPOUND_STRING("TIGHT"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_DROOLING),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_TICKLISH)] =
    {
        .text = COMPOUND_STRING("TICKLISH"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_EXCITING),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_TWIRLING)] =
    {
        .text = COMPOUND_STRING("TWIRLING"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_FIERY),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SPIRALING)] =
    {
        .text = COMPOUND_STRING("SPIRALING"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_HAPPILY),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_THIRSTY)] =
    {
        .text = COMPOUND_STRING("THIRSTY"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_HOPELESS),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_LOLLING)] =
    {
        .text = COMPOUND_STRING("LOLLING"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_HUNGRY),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SILKY)] =
    {
        .text = COMPOUND_STRING("SILKY"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_INCREASING),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SADLY)] =
    {
        .text = COMPOUND_STRING("SADLY"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_LOLLING),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HOPELESS)] =
    {
        .text = COMPOUND_STRING("HOPELESS"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_LOVEY_DOVEY),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_USELESS)] =
    {
        .text = COMPOUND_STRING("USELESS"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_RICKETY),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_DROOLING)] =
    {
        .text = COMPOUND_STRING("DROOLING"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_RIPPED),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_EXCITING)] =
    {
        .text = COMPOUND_STRING("EXCITING"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_ROCK_SOLID),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_THICK)] =
    {
        .text = COMPOUND_STRING("THICK"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SADLY),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SMOOTH)] =
    {
        .text = COMPOUND_STRING("SMOOTH"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SCATTER),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SLIMY)] =
    {
        .text = COMPOUND_STRING("SLIMY"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SHAKY),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_THIN)] =
    {
        .text = COMPOUND_STRING("THIN"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SHREDDED),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_BREAK)] =
    {
        .text = COMPOUND_STRING("BREAK"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SILKY),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_VORACIOUS)] =
    {
        .text = COMPOUND_STRING("VORACIOUS"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SLIMY),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SCATTER)] =
    {
        .text = COMPOUND_STRING("SCATTER"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SMOOTH),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_AWESOME)] =
    {
        .text = COMPOUND_STRING("AWESOME"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SPIRALING),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WIMPY)] =
    {
        .text = COMPOUND_STRING("WIMPY"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_THICK),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WOBBLY)] =
    {
        .text = COMPOUND_STRING("WOBBLY"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_THIN),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SHAKY)] =
    {
        .text = COMPOUND_STRING("SHAKY"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_THIRSTY),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_RIPPED)] =
    {
        .text = COMPOUND_STRING("RIPPED"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_TICKLISH),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SHREDDED)] =
    {
        .text = COMPOUND_STRING("SHREDDED"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_TIGHT),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_INCREASING)] =
    {
        .text = COMPOUND_STRING("INCREASING"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_TWIRLING),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_YET)] =
    {
        .text = COMPOUND_STRING("YET"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_USELESS),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_DESTROYED)] =
    {
        .text = COMPOUND_STRING("DESTROYED"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_VORACIOUS),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_FIERY)] =
    {
        .text = COMPOUND_STRING("FIERY"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_WANDERING),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_LOVEY_DOVEY)] =
    {
        .text = COMPOUND_STRING("LOVEY-DOVEY"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_WIMPY),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HAPPILY)] =
    {
        .text = COMPOUND_STRING("HAPPILY"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_WOBBLY),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_ANTICIPATION)] =
    {
        .text = COMPOUND_STRING("ANTICIPATION"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_YET),
        .enabled = TRUE,
    },
};
