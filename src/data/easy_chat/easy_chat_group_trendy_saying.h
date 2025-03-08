const u8 gEasyChatWord_KthxBye[] = _("Tschüss.");
const u8 gEasyChatWord_YesSirExcl[] = _("Ja, Sir!");
const u8 gEasyChatWord_AvantGarde[] = _("Avantgarde");
const u8 gEasyChatWord_Couple[] = _("Paar");
const u8 gEasyChatWord_MuchObliged[] = _("Vielen Dank");
const u8 gEasyChatWord_YeehawExcl[] = _("Juhu!");
const u8 gEasyChatWord_Mega[] = _("Mega");
const u8 gEasyChatWord_1HitKOExcl[] = _("K.O.!");
const u8 gEasyChatWord_Destiny[] = _("Schicksal");
const u8 gEasyChatWord_Cancel[] = _("Abbrechen");
const u8 gEasyChatWord_New[] = _("Neu");
const u8 gEasyChatWord_Flatten[] = _("Plattmachen");
const u8 gEasyChatWord_Kidding[] = _("Scherz");
const u8 gEasyChatWord_Loser[] = _("Verlierer");
const u8 gEasyChatWord_Losing[] = _("Verlieren");
const u8 gEasyChatWord_Happening[] = _("Ereignis");
const u8 gEasyChatWord_HipAnd[] = _("Hip und");
const u8 gEasyChatWord_Shake[] = _("Schütteln");
const u8 gEasyChatWord_Shady[] = _("Schattig");
const u8 gEasyChatWord_Upbeat[] = _("Optimistisch");
const u8 gEasyChatWord_Modern[] = _("Modern");
const u8 gEasyChatWord_SmellYa[] = _("Riech dich");
const u8 gEasyChatWord_Bang[] = _("Knall");
const u8 gEasyChatWord_Knockout[] = _("K.O.");
const u8 gEasyChatWord_Hassle[] = _("Ärger");
const u8 gEasyChatWord_Winner[] = _("Gewinner");
const u8 gEasyChatWord_Fever[] = _("Fieber");
const u8 gEasyChatWord_Wannabe[] = _("Möchtegern");
const u8 gEasyChatWord_Baby[] = _("Baby");
const u8 gEasyChatWord_Heart[] = _("Herz");
const u8 gEasyChatWord_Old[] = _("Alt");
const u8 gEasyChatWord_Young[] = _("Jung");
const u8 gEasyChatWord_Ugly[] = _("Hässlich");

const struct EasyChatWordInfo gEasyChatGroup_TrendySaying[] = {
    [EC_INDEX(EC_WORD_KTHX_BYE)] =
    {
        .text = gEasyChatWord_KthxBye,
        .alphabeticalOrder = EC_INDEX(EC_WORD_1_HIT_KO_EXCL),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_YES_SIR_EXCL)] =
    {
        .text = gEasyChatWord_YesSirExcl,
        .alphabeticalOrder = EC_INDEX(EC_WORD_AVANT_GARDE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_AVANT_GARDE)] =
    {
        .text = gEasyChatWord_AvantGarde,
        .alphabeticalOrder = EC_INDEX(EC_WORD_BABY),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_COUPLE)] =
    {
        .text = gEasyChatWord_Couple,
        .alphabeticalOrder = EC_INDEX(EC_WORD_BANG),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_MUCH_OBLIGED)] =
    {
        .text = gEasyChatWord_MuchObliged,
        .alphabeticalOrder = EC_INDEX(EC_WORD_CANCEL),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_YEEHAW_EXCL)] =
    {
        .text = gEasyChatWord_YeehawExcl,
        .alphabeticalOrder = EC_INDEX(EC_WORD_COUPLE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_MEGA)] =
    {
        .text = gEasyChatWord_Mega,
        .alphabeticalOrder = EC_INDEX(EC_WORD_DESTINY),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_1_HIT_KO_EXCL)] =
    {
        .text = gEasyChatWord_1HitKOExcl,
        .alphabeticalOrder = EC_INDEX(EC_WORD_FEVER),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_DESTINY)] =
    {
        .text = gEasyChatWord_Destiny,
        .alphabeticalOrder = EC_INDEX(EC_WORD_FLATTEN),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_CANCEL)] =
    {
        .text = gEasyChatWord_Cancel,
        .alphabeticalOrder = EC_INDEX(EC_WORD_HAPPENING),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_NEW)] =
    {
        .text = gEasyChatWord_New,
        .alphabeticalOrder = EC_INDEX(EC_WORD_HASSLE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_FLATTEN)] =
    {
        .text = gEasyChatWord_Flatten,
        .alphabeticalOrder = EC_INDEX(EC_WORD_HEART),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_KIDDING)] =
    {
        .text = gEasyChatWord_Kidding,
        .alphabeticalOrder = EC_INDEX(EC_WORD_HIP_AND),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_LOSER)] =
    {
        .text = gEasyChatWord_Loser,
        .alphabeticalOrder = EC_INDEX(EC_WORD_KIDDING),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_LOSING)] =
    {
        .text = gEasyChatWord_Losing,
        .alphabeticalOrder = EC_INDEX(EC_WORD_KNOCKOUT),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HAPPENING)] =
    {
        .text = gEasyChatWord_Happening,
        .alphabeticalOrder = EC_INDEX(EC_WORD_KTHX_BYE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HIP_AND)] =
    {
        .text = gEasyChatWord_HipAnd,
        .alphabeticalOrder = EC_INDEX(EC_WORD_LOSER),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SHAKE)] =
    {
        .text = gEasyChatWord_Shake,
        .alphabeticalOrder = EC_INDEX(EC_WORD_LOSING),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SHADY)] =
    {
        .text = gEasyChatWord_Shady,
        .alphabeticalOrder = EC_INDEX(EC_WORD_MEGA),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_UPBEAT)] =
    {
        .text = gEasyChatWord_Upbeat,
        .alphabeticalOrder = EC_INDEX(EC_WORD_MODERN),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_MODERN)] =
    {
        .text = gEasyChatWord_Modern,
        .alphabeticalOrder = EC_INDEX(EC_WORD_MUCH_OBLIGED),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SMELL_YA)] =
    {
        .text = gEasyChatWord_SmellYa,
        .alphabeticalOrder = EC_INDEX(EC_WORD_NEW),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_BANG)] =
    {
        .text = gEasyChatWord_Bang,
        .alphabeticalOrder = EC_INDEX(EC_WORD_OLD),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_KNOCKOUT)] =
    {
        .text = gEasyChatWord_Knockout,
        .alphabeticalOrder = EC_INDEX(EC_WORD_SHADY),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HASSLE)] =
    {
        .text = gEasyChatWord_Hassle,
        .alphabeticalOrder = EC_INDEX(EC_WORD_SHAKE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WINNER)] =
    {
        .text = gEasyChatWord_Winner,
        .alphabeticalOrder = EC_INDEX(EC_WORD_SMELL_YA),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_FEVER)] =
    {
        .text = gEasyChatWord_Fever,
        .alphabeticalOrder = EC_INDEX(EC_WORD_UGLY),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WANNABE)] =
    {
        .text = gEasyChatWord_Wannabe,
        .alphabeticalOrder = EC_INDEX(EC_WORD_UPBEAT),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_BABY)] =
    {
        .text = gEasyChatWord_Baby,
        .alphabeticalOrder = EC_INDEX(EC_WORD_WANNABE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HEART)] =
    {
        .text = gEasyChatWord_Heart,
        .alphabeticalOrder = EC_INDEX(EC_WORD_WINNER),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_OLD)] =
    {
        .text = gEasyChatWord_Old,
        .alphabeticalOrder = EC_INDEX(EC_WORD_YEEHAW_EXCL),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_YOUNG)] =
    {
        .text = gEasyChatWord_Young,
        .alphabeticalOrder = EC_INDEX(EC_WORD_YES_SIR_EXCL),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_UGLY)] =
    {
        .text = gEasyChatWord_Ugly,
        .alphabeticalOrder = EC_INDEX(EC_WORD_YOUNG),
        .enabled = TRUE,
    },
};
