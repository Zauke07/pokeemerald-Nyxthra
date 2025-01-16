const u8 gEasyChatWord_Thanks[] = _("Danke");
const u8 gEasyChatWord_Yes[] = _("Ja");
const u8 gEasyChatWord_HereGoes[] = _("Los geht's");
const u8 gEasyChatWord_HereICome[] = _("Hier komme ich");
const u8 gEasyChatWord_HereItIs[] = _("Hier ist es");
const u8 gEasyChatWord_Yeah[] = _("Ja");
const u8 gEasyChatWord_Welcome[] = _("Willkommen");
const u8 gEasyChatWord_Oi[] = _("Oi");
const u8 gEasyChatWord_HowDo[] = _("Wie geht's");
const u8 gEasyChatWord_Congrats[] = _("Glückwunsch");
const u8 gEasyChatWord_GiveMe[] = _("Gib mir");
const u8 gEasyChatWord_Sorry[] = _("Entschuldigung");
const u8 gEasyChatWord_Apologize[] = _("Entschuldige");
const u8 gEasyChatWord_Forgive[] = _("Verzeih");
const u8 gEasyChatWord_HeyThere[] = _("Hey, du");
const u8 gEasyChatWord_Hello[] = _("Hallo");
const u8 gEasyChatWord_GoodBye[] = _("Auf Wiedersehen");
const u8 gEasyChatWord_ThankYou[] = _("Danke dir");
const u8 gEasyChatWord_IveArrived[] = _("Ich bin da");
const u8 gEasyChatWord_Pardon[] = _("Verzeihung");
const u8 gEasyChatWord_Excuse[] = _("Entschuldige");
const u8 gEasyChatWord_SeeYa[] = _("Bis dann");
const u8 gEasyChatWord_ExcuseMe[] = _("Entschuldige mich");
const u8 gEasyChatWord_WellThen[] = _("Na dann");
const u8 gEasyChatWord_GoAhead[] = _("Mach weiter");
const u8 gEasyChatWord_Appreciate[] = _("Schätze");
const u8 gEasyChatWord_HeyQues[] = _("Hey?");
const u8 gEasyChatWord_WhatsUpQues[] = _("Was geht?");
const u8 gEasyChatWord_HuhQues[] = _("Hä?");
const u8 gEasyChatWord_No[] = _("Nein");
const u8 gEasyChatWord_Hi[] = _("Hi");
const u8 gEasyChatWord_YeahYeah[] = _("Ja, ja");
const u8 gEasyChatWord_ByeBye[] = _("Tschüss");
const u8 gEasyChatWord_MeetYou[] = _("Treffen");
const u8 gEasyChatWord_Hey[] = _("Hey");
const u8 gEasyChatWord_Smell[] = _("Riechen");
const u8 gEasyChatWord_Listening[] = _("Hören");
const u8 gEasyChatWord_HooHah[] = _("Hoo-hah");
const u8 gEasyChatWord_Yahoo[] = _("Juhu");
const u8 gEasyChatWord_Yo[] = _("Yo");
const u8 gEasyChatWord_ComeOver[] = _("Komm herüber");
const u8 gEasyChatWord_CountOn[] = _("Zähl auf");

const struct EasyChatWordInfo gEasyChatGroup_Greetings[] = {
    [EC_INDEX(EC_WORD_THANKS)] =
    {
        .text = gEasyChatWord_Thanks,
        .alphabeticalOrder = 12,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_YES)] =
    {
        .text = gEasyChatWord_Yes,
        .alphabeticalOrder = 25,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HERE_GOES)] =
    {
        .text = gEasyChatWord_HereGoes,
        .alphabeticalOrder = 32,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HERE_I_COME)] =
    {
        .text = gEasyChatWord_HereICome,
        .alphabeticalOrder = 40,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HERE_IT_IS)] =
    {
        .text = gEasyChatWord_HereItIs,
        .alphabeticalOrder = 9,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_YEAH)] =
    {
        .text = gEasyChatWord_Yeah,
        .alphabeticalOrder = 41,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WELCOME)] =
    {
        .text = gEasyChatWord_Welcome,
        .alphabeticalOrder = 20,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_OI)] =
    {
        .text = gEasyChatWord_Oi,
        .alphabeticalOrder = 22,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HOW_DO)] =
    {
        .text = gEasyChatWord_HowDo,
        .alphabeticalOrder = 13,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_CONGRATS)] =
    {
        .text = gEasyChatWord_Congrats,
        .alphabeticalOrder = 10,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_GIVE_ME)] =
    {
        .text = gEasyChatWord_GiveMe,
        .alphabeticalOrder = 24,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SORRY)] =
    {
        .text = gEasyChatWord_Sorry,
        .alphabeticalOrder = 16,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_APOLOGIZE)] =
    {
        .text = gEasyChatWord_Apologize,
        .alphabeticalOrder = 15,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_FORGIVE)] =
    {
        .text = gEasyChatWord_Forgive,
        .alphabeticalOrder = 2,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HEY_THERE)] =
    {
        .text = gEasyChatWord_HeyThere,
        .alphabeticalOrder = 3,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HELLO)] =
    {
        .text = gEasyChatWord_Hello,
        .alphabeticalOrder = 4,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_GOOD_BYE)] =
    {
        .text = gEasyChatWord_GoodBye,
        .alphabeticalOrder = 34,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_THANK_YOU)] =
    {
        .text = gEasyChatWord_ThankYou,
        .alphabeticalOrder = 14,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_I_VE_ARRIVED)] =
    {
        .text = gEasyChatWord_IveArrived,
        .alphabeticalOrder = 26,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_PARDON)] =
    {
        .text = gEasyChatWord_Pardon,
        .alphabeticalOrder = 30,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_EXCUSE)] =
    {
        .text = gEasyChatWord_Excuse,
        .alphabeticalOrder = 37,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SEE_YA)] =
    {
        .text = gEasyChatWord_SeeYa,
        .alphabeticalOrder = 8,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_EXCUSE_ME)] =
    {
        .text = gEasyChatWord_ExcuseMe,
        .alphabeticalOrder = 28,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WELL_THEN)] =
    {
        .text = gEasyChatWord_WellThen,
        .alphabeticalOrder = 18,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_GO_AHEAD)] =
    {
        .text = gEasyChatWord_GoAhead,
        .alphabeticalOrder = 36,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_APPRECIATE)] =
    {
        .text = gEasyChatWord_Appreciate,
        .alphabeticalOrder = 33,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HEY_QUES)] =
    {
        .text = gEasyChatWord_HeyQues,
        .alphabeticalOrder = 29,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WHAT_S_UP_QUES)] =
    {
        .text = gEasyChatWord_WhatsUpQues,
        .alphabeticalOrder = 7,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HUH_QUES)] =
    {
        .text = gEasyChatWord_HuhQues,
        .alphabeticalOrder = 19,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_NO)] =
    {
        .text = gEasyChatWord_No,
        .alphabeticalOrder = 21,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HI)] =
    {
        .text = gEasyChatWord_Hi,
        .alphabeticalOrder = 35,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_YEAH_YEAH)] =
    {
        .text = gEasyChatWord_YeahYeah,
        .alphabeticalOrder = 11,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_BYE_BYE)] =
    {
        .text = gEasyChatWord_ByeBye,
        .alphabeticalOrder = 17,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_MEET_YOU)] =
    {
        .text = gEasyChatWord_MeetYou,
        .alphabeticalOrder = 0,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HEY)] =
    {
        .text = gEasyChatWord_Hey,
        .alphabeticalOrder = 6,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SMELL)] =
    {
        .text = gEasyChatWord_Smell,
        .alphabeticalOrder = 23,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_LISTENING)] =
    {
        .text = gEasyChatWord_Listening,
        .alphabeticalOrder = 27,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HOO_HAH)] =
    {
        .text = gEasyChatWord_HooHah,
        .alphabeticalOrder = 38,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_YAHOO)] =
    {
        .text = gEasyChatWord_Yahoo,
        .alphabeticalOrder = 5,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_YO)] =
    {
        .text = gEasyChatWord_Yo,
        .alphabeticalOrder = 31,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_COME_OVER)] =
    {
        .text = gEasyChatWord_ComeOver,
        .alphabeticalOrder = 1,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_COUNT_ON)] =
    {
        .text = gEasyChatWord_CountOn,
        .alphabeticalOrder = 39,
        .enabled = TRUE,
    },
};
