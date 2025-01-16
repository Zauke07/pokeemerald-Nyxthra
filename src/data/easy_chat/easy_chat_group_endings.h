const u8 gEasyChatWord_Will[] = _("Wird");
const u8 gEasyChatWord_WillBeHere[] = _("Wird hier sein");
const u8 gEasyChatWord_Or[] = _("Oder");
const u8 gEasyChatWord_Times[] = _("Mal");
const u8 gEasyChatWord_Wonder[] = _("Wunder");
const u8 gEasyChatWord_IsItQues[] = _("Ist es?");
const u8 gEasyChatWord_Be[] = _("Sein");
const u8 gEasyChatWord_Gimme[] = _("Gib mir");
const u8 gEasyChatWord_Could[] = _("Könnte");
const u8 gEasyChatWord_LikelyTo[] = _("Wahrscheinlich");
const u8 gEasyChatWord_Would[] = _("Würde");
const u8 gEasyChatWord_Is[] = _("Ist");
const u8 gEasyChatWord_IsntItQues[] = _("Ist es nicht?");
const u8 gEasyChatWord_Lets[] = _("Lass uns");
const u8 gEasyChatWord_Other[] = _("Andere");
const u8 gEasyChatWord_Are[] = _("Sind");
const u8 gEasyChatWord_Was[] = _("War");
const u8 gEasyChatWord_Were[] = _("Waren");
const u8 gEasyChatWord_Those[] = _("Diese");
const u8 gEasyChatWord_Isnt[] = _("Ist nicht");
const u8 gEasyChatWord_Wont[] = _("Wird nicht");
const u8 gEasyChatWord_Cant[] = _("Kann nicht");
const u8 gEasyChatWord_Can[] = _("Kann");
const u8 gEasyChatWord_Dont[] = _("Nicht");
const u8 gEasyChatWord_Do[] = _("Tun");
const u8 gEasyChatWord_Does[] = _("Tut");
const u8 gEasyChatWord_Whom[] = _("Wen");
const u8 gEasyChatWord_Which[] = _("Welche");
const u8 gEasyChatWord_Wasnt[] = _("War nicht");
const u8 gEasyChatWord_Werent[] = _("Waren nicht");
const u8 gEasyChatWord_Have[] = _("Haben");
const u8 gEasyChatWord_Havent[] = _("Haben nicht");
const u8 gEasyChatWord_A[] = _("Ein");
const u8 gEasyChatWord_An[] = _("Ein");
const u8 gEasyChatWord_Not[] = _("Nicht");
const u8 gEasyChatWord_There[] = _("Da");
const u8 gEasyChatWord_OkQues[] = _("Ok?");
const u8 gEasyChatWord_So[] = _("So");
const u8 gEasyChatWord_Maybe[] = _("Vielleicht");
const u8 gEasyChatWord_About[] = _("Über");
const u8 gEasyChatWord_Over[] = _("Über");
const u8 gEasyChatWord_It[] = _("Es");
const u8 gEasyChatWord_All[] = _("Alle");
const u8 gEasyChatWord_For[] = _("Für");
const u8 gEasyChatWord_On[] = _("Auf");
const u8 gEasyChatWord_Off[] = _("Aus");
const u8 gEasyChatWord_As[] = _("Als");
const u8 gEasyChatWord_To[] = _("Zu");
const u8 gEasyChatWord_With[] = _("Mit");
const u8 gEasyChatWord_Better[] = _("Besser");
const u8 gEasyChatWord_Ever[] = _("Immer");
const u8 gEasyChatWord_Since[] = _("Seit");
const u8 gEasyChatWord_Of[] = _("Von");
const u8 gEasyChatWord_BelongsTo[] = _("Gehört zu");
const u8 gEasyChatWord_At[] = _("Bei");
const u8 gEasyChatWord_In[] = _("In");
const u8 gEasyChatWord_Out[] = _("Aus");
const u8 gEasyChatWord_Too[] = _("Zu");
const u8 gEasyChatWord_Like[] = _("Wie");
const u8 gEasyChatWord_Did[] = _("Tat");
const u8 gEasyChatWord_Didnt[] = _("Tat nicht");
const u8 gEasyChatWord_Doesnt[] = _("Tut nicht");
const u8 gEasyChatWord_Without[] = _("Ohne");
const u8 gEasyChatWord_After[] = _("Nach");
const u8 gEasyChatWord_Before[] = _("Vor");
const u8 gEasyChatWord_While[] = _("Während");
const u8 gEasyChatWord_Than[] = _("Als");
const u8 gEasyChatWord_Once[] = _("Einmal");
const u8 gEasyChatWord_Anywhere[] = _("Überall");

const struct EasyChatWordInfo gEasyChatGroup_Endings[] = {
    [EC_INDEX(EC_WORD_WILL)] =
    {
        .text = gEasyChatWord_Will,
        .alphabeticalOrder = 32,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WILL_BE_HERE)] =
    {
        .text = gEasyChatWord_WillBeHere,
        .alphabeticalOrder = 39,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_OR)] =
    {
        .text = gEasyChatWord_Or,
        .alphabeticalOrder = 63,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_TIMES)] =
    {
        .text = gEasyChatWord_Times,
        .alphabeticalOrder = 42,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WONDER)] =
    {
        .text = gEasyChatWord_Wonder,
        .alphabeticalOrder = 33,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_IS_IT_QUES)] =
    {
        .text = gEasyChatWord_IsItQues,
        .alphabeticalOrder = 68,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_BE)] =
    {
        .text = gEasyChatWord_Be,
        .alphabeticalOrder = 15,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_GIMME)] =
    {
        .text = gEasyChatWord_Gimme,
        .alphabeticalOrder = 46,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_COULD)] =
    {
        .text = gEasyChatWord_Could,
        .alphabeticalOrder = 54,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_LIKELY_TO)] =
    {
        .text = gEasyChatWord_LikelyTo,
        .alphabeticalOrder = 6,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WOULD)] =
    {
        .text = gEasyChatWord_Would,
        .alphabeticalOrder = 64,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_IS)] =
    {
        .text = gEasyChatWord_Is,
        .alphabeticalOrder = 53,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_ISN_T_IT_QUES)] =
    {
        .text = gEasyChatWord_IsntItQues,
        .alphabeticalOrder = 49,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_LET_S)] =
    {
        .text = gEasyChatWord_Lets,
        .alphabeticalOrder = 22,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_OTHER)] =
    {
        .text = gEasyChatWord_Other,
        .alphabeticalOrder = 21,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_ARE)] =
    {
        .text = gEasyChatWord_Are,
        .alphabeticalOrder = 8,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WAS)] =
    {
        .text = gEasyChatWord_Was,
        .alphabeticalOrder = 59,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WERE)] =
    {
        .text = gEasyChatWord_Were,
        .alphabeticalOrder = 60,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_THOSE)] =
    {
        .text = gEasyChatWord_Those,
        .alphabeticalOrder = 24,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_ISN_T)] =
    {
        .text = gEasyChatWord_Isnt,
        .alphabeticalOrder = 25,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WON_T)] =
    {
        .text = gEasyChatWord_Wont,
        .alphabeticalOrder = 61,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_CAN_T)] =
    {
        .text = gEasyChatWord_Cant,
        .alphabeticalOrder = 23,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_CAN)] =
    {
        .text = gEasyChatWord_Can,
        .alphabeticalOrder = 50,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_DON_T)] =
    {
        .text = gEasyChatWord_Dont,
        .alphabeticalOrder = 43,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_DO)] =
    {
        .text = gEasyChatWord_Do,
        .alphabeticalOrder = 7,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_DOES)] =
    {
        .text = gEasyChatWord_Does,
        .alphabeticalOrder = 30,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WHOM)] =
    {
        .text = gEasyChatWord_Whom,
        .alphabeticalOrder = 31,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WHICH)] =
    {
        .text = gEasyChatWord_Which,
        .alphabeticalOrder = 55,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WASN_T)] =
    {
        .text = gEasyChatWord_Wasnt,
        .alphabeticalOrder = 11,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WEREN_T)] =
    {
        .text = gEasyChatWord_Werent,
        .alphabeticalOrder = 5,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HAVE)] =
    {
        .text = gEasyChatWord_Have,
        .alphabeticalOrder = 19,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HAVEN_T)] =
    {
        .text = gEasyChatWord_Havent,
        .alphabeticalOrder = 12,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_A)] =
    {
        .text = gEasyChatWord_A,
        .alphabeticalOrder = 41,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_AN)] =
    {
        .text = gEasyChatWord_An,
        .alphabeticalOrder = 13,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_NOT)] =
    {
        .text = gEasyChatWord_Not,
        .alphabeticalOrder = 58,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_THERE)] =
    {
        .text = gEasyChatWord_There,
        .alphabeticalOrder = 9,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_OK_QUES)] =
    {
        .text = gEasyChatWord_OkQues,
        .alphabeticalOrder = 38,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SO)] =
    {
        .text = gEasyChatWord_So,
        .alphabeticalOrder = 34,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_MAYBE)] =
    {
        .text = gEasyChatWord_Maybe,
        .alphabeticalOrder = 52,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_ABOUT)] =
    {
        .text = gEasyChatWord_About,
        .alphabeticalOrder = 45,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_OVER)] =
    {
        .text = gEasyChatWord_Over,
        .alphabeticalOrder = 36,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_IT)] =
    {
        .text = gEasyChatWord_It,
        .alphabeticalOrder = 44,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_ALL)] =
    {
        .text = gEasyChatWord_All,
        .alphabeticalOrder = 67,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_FOR)] =
    {
        .text = gEasyChatWord_For,
        .alphabeticalOrder = 2,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_ON)] =
    {
        .text = gEasyChatWord_On,
        .alphabeticalOrder = 14,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_OFF)] =
    {
        .text = gEasyChatWord_Off,
        .alphabeticalOrder = 56,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_AS)] =
    {
        .text = gEasyChatWord_As,
        .alphabeticalOrder = 40,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_TO)] =
    {
        .text = gEasyChatWord_To,
        .alphabeticalOrder = 51,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WITH)] =
    {
        .text = gEasyChatWord_With,
        .alphabeticalOrder = 37,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_BETTER)] =
    {
        .text = gEasyChatWord_Better,
        .alphabeticalOrder = 66,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_EVER)] =
    {
        .text = gEasyChatWord_Ever,
        .alphabeticalOrder = 35,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SINCE)] =
    {
        .text = gEasyChatWord_Since,
        .alphabeticalOrder = 18,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_OF)] =
    {
        .text = gEasyChatWord_Of,
        .alphabeticalOrder = 3,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_BELONGS_TO)] =
    {
        .text = gEasyChatWord_BelongsTo,
        .alphabeticalOrder = 47,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_AT)] =
    {
        .text = gEasyChatWord_At,
        .alphabeticalOrder = 57,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_IN)] =
    {
        .text = gEasyChatWord_In,
        .alphabeticalOrder = 16,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_OUT)] =
    {
        .text = gEasyChatWord_Out,
        .alphabeticalOrder = 28,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_TOO)] =
    {
        .text = gEasyChatWord_Too,
        .alphabeticalOrder = 17,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_LIKE)] =
    {
        .text = gEasyChatWord_Like,
        .alphabeticalOrder = 29,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_DID)] =
    {
        .text = gEasyChatWord_Did,
        .alphabeticalOrder = 27,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_DIDN_T)] =
    {
        .text = gEasyChatWord_Didnt,
        .alphabeticalOrder = 65,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_DOESN_T)] =
    {
        .text = gEasyChatWord_Doesnt,
        .alphabeticalOrder = 26,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WITHOUT)] =
    {
        .text = gEasyChatWord_Without,
        .alphabeticalOrder = 0,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_AFTER)] =
    {
        .text = gEasyChatWord_After,
        .alphabeticalOrder = 1,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_BEFORE)] =
    {
        .text = gEasyChatWord_Before,
        .alphabeticalOrder = 48,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WHILE)] =
    {
        .text = gEasyChatWord_While,
        .alphabeticalOrder = 62,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_THAN)] =
    {
        .text = gEasyChatWord_Than,
        .alphabeticalOrder = 20,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_ONCE)] =
    {
        .text = gEasyChatWord_Once,
        .alphabeticalOrder = 4,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_ANYWHERE)] =
    {
        .text = gEasyChatWord_Anywhere,
        .alphabeticalOrder = 10,
        .enabled = TRUE,
    },
};
