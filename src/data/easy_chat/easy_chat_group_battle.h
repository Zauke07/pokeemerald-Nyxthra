const u8 gEasyChatWord_MatchUp[] = _("Harmonieren");
const u8 gEasyChatWord_Go[] = _("Los");
const u8 gEasyChatWord_No1[] = _("Nr. 1");
const u8 gEasyChatWord_Decide[] = _("Entscheiden");
const u8 gEasyChatWord_LetMeWin[] = _("Ich Siege!");
const u8 gEasyChatWord_Wins[] = _("Gewinnen");
const u8 gEasyChatWord_Win[] = _("Gewinne");
const u8 gEasyChatWord_Won[] = _("Gewonnen");
const u8 gEasyChatWord_IfIWin[] = _("Gewinne ich");
const u8 gEasyChatWord_WhenIWin[] = _("Siege ich");
const u8 gEasyChatWord_CantWin[] = _("Sieg Unmögl.");
const u8 gEasyChatWord_CanWin[] = _("Kann Siegen");
const u8 gEasyChatWord_NoMatch[] = _("Unterlegen");
const u8 gEasyChatWord_Spirit[] = _("Seele");
const u8 gEasyChatWord_Decided[] = _("Entscheidend");
const u8 gEasyChatWord_TrumpCard[] = _("Trumpfkarte");
const u8 gEasyChatWord_TakeThat[] = _("Nimm das");
const u8 gEasyChatWord_ComeOn[] = _("Komm Schon");
const u8 gEasyChatWord_Attack[] = _("Angriff");
const u8 gEasyChatWord_Surrender[] = _("Ergeben");
const u8 gEasyChatWord_Gutsy[] = _("Mutig");
const u8 gEasyChatWord_Talent[] = _("Talentiert");
const u8 gEasyChatWord_Strategy[] = _("Strategie");
const u8 gEasyChatWord_Smite[] = _("Schlagen");
const u8 gEasyChatWord_Match[] = _("Partie");
const u8 gEasyChatWord_Victory[] = _("Sieg");
const u8 gEasyChatWord_Offensive[] = _("Offensiv");
const u8 gEasyChatWord_Sense[] = _("Sinn");
const u8 gEasyChatWord_Versus[] = _("Gegen");
const u8 gEasyChatWord_Fights[] = _("Streiten");
const u8 gEasyChatWord_Power[] = _("Kraft");
const u8 gEasyChatWord_Challenge[] = _("Herausforderung");
const u8 gEasyChatWord_Strong[] = _("Starken");
const u8 gEasyChatWord_TooStrong[] = _("zu Stark");
const u8 gEasyChatWord_GoEasy[] = _("Schonen");
const u8 gEasyChatWord_Foe[] = _("Gegner");
const u8 gEasyChatWord_Genius[] = _("Genie");
const u8 gEasyChatWord_Legend[] = _("Legende");
const u8 gEasyChatWord_Escape[] = _("Flucht");
const u8 gEasyChatWord_Aim[] = _("Ziel");
const u8 gEasyChatWord_Battle[] = _("Kämpfe");
const u8 gEasyChatWord_Fight[] = _("Kämpfen");
const u8 gEasyChatWord_Resuscitate[] = _("Beleben");
const u8 gEasyChatWord_Points[] = _("Punkte");
const u8 gEasyChatWord_Serious[] = _("Ernsthaft");
const u8 gEasyChatWord_GiveUp[] = _("Aufgeben");
const u8 gEasyChatWord_Loss[] = _("Verlust");
const u8 gEasyChatWord_IfILose[] = _("Verliere Ich");
const u8 gEasyChatWord_Lost[] = _("Verloren");
const u8 gEasyChatWord_Lose[] = _("Verlieren");
const u8 gEasyChatWord_Guard[] = _("Wache");
const u8 gEasyChatWord_Partner[] = _("Partner");
const u8 gEasyChatWord_Reject[] = _("Ablehnen");
const u8 gEasyChatWord_Accept[] = _("Akzeptieren");
const u8 gEasyChatWord_Invincible[] = _("Uschlagbar");
const u8 gEasyChatWord_Received[] = _("Erhalten");
const u8 gEasyChatWord_Easy[] = _("Leicht");
const u8 gEasyChatWord_Weak[] = _("Schwach");
const u8 gEasyChatWord_TooWeak[] = _("Zu Schwach");
const u8 gEasyChatWord_Pushover[] = _("Lappalie");
const u8 gEasyChatWord_Leader[] = _("Leiter");
const u8 gEasyChatWord_Rule[] = _("Regel");
const u8 gEasyChatWord_Move[] = _("Attacke");

const struct EasyChatWordInfo gEasyChatGroup_Battle[] = {
    [EC_INDEX(EC_WORD_MATCH_UP)] =
    {
        .text = gEasyChatWord_MatchUp,
        .alphabeticalOrder = 53,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_GO)] =
    {
        .text = gEasyChatWord_Go,
        .alphabeticalOrder = 39,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_NO_1)] =
    {
        .text = gEasyChatWord_No1,
        .alphabeticalOrder = 18,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_DECIDE)] =
    {
        .text = gEasyChatWord_Decide,
        .alphabeticalOrder = 40,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_LET_ME_WIN)] =
    {
        .text = gEasyChatWord_LetMeWin,
        .alphabeticalOrder = 11,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WINS)] =
    {
        .text = gEasyChatWord_Wins,
        .alphabeticalOrder = 10,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WIN)] =
    {
        .text = gEasyChatWord_Win,
        .alphabeticalOrder = 31,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WON)] =
    {
        .text = gEasyChatWord_Won,
        .alphabeticalOrder = 17,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_IF_I_WIN)] =
    {
        .text = gEasyChatWord_IfIWin,
        .alphabeticalOrder = 3,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WHEN_I_WIN)] =
    {
        .text = gEasyChatWord_WhenIWin,
        .alphabeticalOrder = 14,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_CAN_T_WIN)] =
    {
        .text = gEasyChatWord_CantWin,
        .alphabeticalOrder = 56,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_CAN_WIN)] =
    {
        .text = gEasyChatWord_CanWin,
        .alphabeticalOrder = 38,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_NO_MATCH)] =
    {
        .text = gEasyChatWord_NoMatch,
        .alphabeticalOrder = 41,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SPIRIT)] =
    {
        .text = gEasyChatWord_Spirit,
        .alphabeticalOrder = 29,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_DECIDED)] =
    {
        .text = gEasyChatWord_Decided,
        .alphabeticalOrder = 35,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_TRUMP_CARD)] =
    {
        .text = gEasyChatWord_TrumpCard,
        .alphabeticalOrder = 36,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_TAKE_THAT)] =
    {
        .text = gEasyChatWord_TakeThat,
        .alphabeticalOrder = 45,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_COME_ON)] =
    {
        .text = gEasyChatWord_ComeOn,
        .alphabeticalOrder = 1,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_ATTACK)] =
    {
        .text = gEasyChatWord_Attack,
        .alphabeticalOrder = 34,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SURRENDER)] =
    {
        .text = gEasyChatWord_Surrender,
        .alphabeticalOrder = 50,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_GUTSY)] =
    {
        .text = gEasyChatWord_Gutsy,
        .alphabeticalOrder = 20,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_TALENT)] =
    {
        .text = gEasyChatWord_Talent,
        .alphabeticalOrder = 47,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_STRATEGY)] =
    {
        .text = gEasyChatWord_Strategy,
        .alphabeticalOrder = 8,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SMITE)] =
    {
        .text = gEasyChatWord_Smite,
        .alphabeticalOrder = 54,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_MATCH)] =
    {
        .text = gEasyChatWord_Match,
        .alphabeticalOrder = 60,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_VICTORY)] =
    {
        .text = gEasyChatWord_Victory,
        .alphabeticalOrder = 37,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_OFFENSIVE)] =
    {
        .text = gEasyChatWord_Offensive,
        .alphabeticalOrder = 4,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SENSE)] =
    {
        .text = gEasyChatWord_Sense,
        .alphabeticalOrder = 49,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_VERSUS)] =
    {
        .text = gEasyChatWord_Versus,
        .alphabeticalOrder = 46,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_FIGHTS)] =
    {
        .text = gEasyChatWord_Fights,
        .alphabeticalOrder = 48,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_POWER)] =
    {
        .text = gEasyChatWord_Power,
        .alphabeticalOrder = 24,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_CHALLENGE)] =
    {
        .text = gEasyChatWord_Challenge,
        .alphabeticalOrder = 0,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_STRONG)] =
    {
        .text = gEasyChatWord_Strong,
        .alphabeticalOrder = 62,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_TOO_STRONG)] =
    {
        .text = gEasyChatWord_TooStrong,
        .alphabeticalOrder = 12,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_GO_EASY)] =
    {
        .text = gEasyChatWord_GoEasy,
        .alphabeticalOrder = 2,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_FOE)] =
    {
        .text = gEasyChatWord_Foe,
        .alphabeticalOrder = 26,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_GENIUS)] =
    {
        .text = gEasyChatWord_Genius,
        .alphabeticalOrder = 51,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_LEGEND)] =
    {
        .text = gEasyChatWord_Legend,
        .alphabeticalOrder = 43,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_ESCAPE)] =
    {
        .text = gEasyChatWord_Escape,
        .alphabeticalOrder = 30,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_AIM)] =
    {
        .text = gEasyChatWord_Aim,
        .alphabeticalOrder = 59,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_BATTLE)] =
    {
        .text = gEasyChatWord_Battle,
        .alphabeticalOrder = 55,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_FIGHT)] =
    {
        .text = gEasyChatWord_Fight,
        .alphabeticalOrder = 52,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_RESUSCITATE)] =
    {
        .text = gEasyChatWord_Resuscitate,
        .alphabeticalOrder = 42,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_POINTS)] =
    {
        .text = gEasyChatWord_Points,
        .alphabeticalOrder = 61,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SERIOUS)] =
    {
        .text = gEasyChatWord_Serious,
        .alphabeticalOrder = 27,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_GIVE_UP)] =
    {
        .text = gEasyChatWord_GiveUp,
        .alphabeticalOrder = 44,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_LOSS)] =
    {
        .text = gEasyChatWord_Loss,
        .alphabeticalOrder = 23,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_IF_I_LOSE)] =
    {
        .text = gEasyChatWord_IfILose,
        .alphabeticalOrder = 13,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_LOST)] =
    {
        .text = gEasyChatWord_Lost,
        .alphabeticalOrder = 22,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_LOSE)] =
    {
        .text = gEasyChatWord_Lose,
        .alphabeticalOrder = 32,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_GUARD)] =
    {
        .text = gEasyChatWord_Guard,
        .alphabeticalOrder = 19,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_PARTNER)] =
    {
        .text = gEasyChatWord_Partner,
        .alphabeticalOrder = 16,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_REJECT)] =
    {
        .text = gEasyChatWord_Reject,
        .alphabeticalOrder = 21,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_ACCEPT)] =
    {
        .text = gEasyChatWord_Accept,
        .alphabeticalOrder = 33,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_INVINCIBLE)] =
    {
        .text = gEasyChatWord_Invincible,
        .alphabeticalOrder = 58,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_RECEIVED)] =
    {
        .text = gEasyChatWord_Received,
        .alphabeticalOrder = 15,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_EASY)] =
    {
        .text = gEasyChatWord_Easy,
        .alphabeticalOrder = 28,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WEAK)] =
    {
        .text = gEasyChatWord_Weak,
        .alphabeticalOrder = 25,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_TOO_WEAK)] =
    {
        .text = gEasyChatWord_TooWeak,
        .alphabeticalOrder = 57,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_PUSHOVER)] =
    {
        .text = gEasyChatWord_Pushover,
        .alphabeticalOrder = 9,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_LEADER)] =
    {
        .text = gEasyChatWord_Leader,
        .alphabeticalOrder = 6,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_RULE)] =
    {
        .text = gEasyChatWord_Rule,
        .alphabeticalOrder = 5,
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_MOVE)] =
    {
        .text = gEasyChatWord_Move,
        .alphabeticalOrder = 7,
        .enabled = TRUE,
    },
};
