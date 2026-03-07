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
        .text = COMPOUND_STRING("MATCH UP"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_ACCEPT),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_GO)] =
    {
        .text = COMPOUND_STRING("GO"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_AIM),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_NO_1)] =
    {
        .text = COMPOUND_STRING("NO. 1"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_ATTACK),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_DECIDE)] =
    {
        .text = COMPOUND_STRING("DECIDE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_BATTLE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_LET_ME_WIN)] =
    {
        .text = COMPOUND_STRING("LET ME WIN"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_CAN_WIN),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WINS)] =
    {
        .text = COMPOUND_STRING("WINS"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_CAN_T_WIN),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WIN)] =
    {
        .text = COMPOUND_STRING("WIN"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_CHALLENGE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WON)] =
    {
        .text = COMPOUND_STRING("WON"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_COME_ON),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_IF_I_WIN)] =
    {
        .text = COMPOUND_STRING("IF I WIN"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_DECIDE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WHEN_I_WIN)] =
    {
        .text = COMPOUND_STRING("WHEN I WIN"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_DECIDED),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_CAN_T_WIN)] =
    {
        .text = COMPOUND_STRING("CAN'T WIN"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_EASY),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_CAN_WIN)] =
    {
        .text = COMPOUND_STRING("CAN WIN"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_ESCAPE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_NO_MATCH)] =
    {
        .text = COMPOUND_STRING("NO MATCH"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_FIGHT),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SPIRIT)] =
    {
        .text = COMPOUND_STRING("SPIRIT"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_FIGHTS),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_DECIDED)] =
    {
        .text = COMPOUND_STRING("DECIDED"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_FOE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_TRUMP_CARD)] =
    {
        .text = COMPOUND_STRING("TRUMP CARD"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_GENIUS),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_TAKE_THAT)] =
    {
        .text = COMPOUND_STRING("TAKE THAT"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_GIVE_UP),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_COME_ON)] =
    {
        .text = COMPOUND_STRING("COME ON"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_GO),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_ATTACK)] =
    {
        .text = COMPOUND_STRING("ATTACK"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_GO_EASY),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SURRENDER)] =
    {
        .text = COMPOUND_STRING("SURRENDER"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_GUARD),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_GUTSY)] =
    {
        .text = COMPOUND_STRING("GUTSY"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_GUTSY),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_TALENT)] =
    {
        .text = COMPOUND_STRING("TALENT"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_IF_I_LOSE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_STRATEGY)] =
    {
        .text = COMPOUND_STRING("STRATEGY"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_IF_I_WIN),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SMITE)] =
    {
        .text = COMPOUND_STRING("SMITE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_INVINCIBLE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_MATCH)] =
    {
        .text = COMPOUND_STRING("MATCH"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_LEADER),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_VICTORY)] =
    {
        .text = COMPOUND_STRING("VICTORY"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_LEGEND),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_OFFENSIVE)] =
    {
        .text = COMPOUND_STRING("OFFENSIVE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_LET_ME_WIN),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SENSE)] =
    {
        .text = COMPOUND_STRING("SENSE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_LOSE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_VERSUS)] =
    {
        .text = COMPOUND_STRING("VERSUS"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_LOSS),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_FIGHTS)] =
    {
        .text = COMPOUND_STRING("FIGHTS"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_LOST),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_POWER)] =
    {
        .text = COMPOUND_STRING("POWER"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_MATCH),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_CHALLENGE)] =
    {
        .text = COMPOUND_STRING("CHALLENGE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_MATCH_UP),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_STRONG)] =
    {
        .text = COMPOUND_STRING("STRONG"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_MOVE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_TOO_STRONG)] =
    {
        .text = COMPOUND_STRING("TOO STRONG"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_NO_MATCH),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_GO_EASY)] =
    {
        .text = COMPOUND_STRING("GO EASY"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_NO_1),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_FOE)] =
    {
        .text = COMPOUND_STRING("FOE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_OFFENSIVE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_GENIUS)] =
    {
        .text = COMPOUND_STRING("GENIUS"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_PARTNER),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_LEGEND)] =
    {
        .text = COMPOUND_STRING("LEGEND"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_POINTS),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_ESCAPE)] =
    {
        .text = COMPOUND_STRING("ESCAPE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_POWER),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_AIM)] =
    {
        .text = COMPOUND_STRING("AIM"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_PUSHOVER),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_BATTLE)] =
    {
        .text = COMPOUND_STRING("BATTLE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_RECEIVED),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_FIGHT)] =
    {
        .text = COMPOUND_STRING("FIGHT"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_REJECT),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_RESUSCITATE)] =
    {
        .text = COMPOUND_STRING("RESUSCITATE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_RESUSCITATE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_POINTS)] =
    {
        .text = COMPOUND_STRING("POINTS"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_RULE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SERIOUS)] =
    {
        .text = COMPOUND_STRING("SERIOUS"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SENSE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_GIVE_UP)] =
    {
        .text = COMPOUND_STRING("GIVE UP"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SERIOUS),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_LOSS)] =
    {
        .text = COMPOUND_STRING("LOSS"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SMITE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_IF_I_LOSE)] =
    {
        .text = COMPOUND_STRING("IF I LOSE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SPIRIT),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_LOST)] =
    {
        .text = COMPOUND_STRING("LOST"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_STRATEGY),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_LOSE)] =
    {
        .text = COMPOUND_STRING("LOSE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_STRONG),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_GUARD)] =
    {
        .text = COMPOUND_STRING("GUARD"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SURRENDER),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_PARTNER)] =
    {
        .text = COMPOUND_STRING("PARTNER"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_TAKE_THAT),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_REJECT)] =
    {
        .text = COMPOUND_STRING("REJECT"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_TALENT),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_ACCEPT)] =
    {
        .text = COMPOUND_STRING("ACCEPT"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_TOO_STRONG),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_INVINCIBLE)] =
    {
        .text = COMPOUND_STRING("INVINCIBLE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_TOO_WEAK),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_RECEIVED)] =
    {
        .text = COMPOUND_STRING("RECEIVED"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_TRUMP_CARD),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_EASY)] =
    {
        .text = COMPOUND_STRING("EASY"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_VERSUS),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WEAK)] =
    {
        .text = COMPOUND_STRING("WEAK"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_VICTORY),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_TOO_WEAK)] =
    {
        .text = COMPOUND_STRING("TOO WEAK"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_WEAK),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_PUSHOVER)] =
    {
        .text = COMPOUND_STRING("PUSHOVER"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_WHEN_I_WIN),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_LEADER)] =
    {
        .text = COMPOUND_STRING("LEADER"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_WIN),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_RULE)] =
    {
        .text = COMPOUND_STRING("RULE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_WINS),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_MOVE)] =
    {
        .text = COMPOUND_STRING("MOVE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_WON),
        .enabled = TRUE,
    },
};
