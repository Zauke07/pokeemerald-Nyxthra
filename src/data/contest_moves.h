const struct ContestEffect gContestEffects[] =
{
    [CONTEST_EFFECT_HIGHLY_APPEALING] =
    {
        #if C_UPDATED_MOVE_EFFECTS >= GEN_6
        .description = COMPOUND_STRING("Eine recht ansprechende Attacke."),
        #else
        .description = COMPOUND_STRING("Eine äußerst ansprechende Attacke."),
        #endif
        .effectType = CONTEST_EFFECT_TYPE_APPEAL,
        .appeal = 40,
        .jam = 0,
        .function = ContestEffect_HighlyAppealing,
    },
    [CONTEST_EFFECT_USER_MORE_EASILY_STARTLED] =
    {
        .description = COMPOUND_STRING("Danach lässt sich der Anwender\nleichter erschrecken."),
        .effectType = CONTEST_EFFECT_TYPE_APPEAL,
        .appeal = 60,
        .jam = 0,
        .function = ContestEffect_UserMoreEasilyStartled,
    },
    [CONTEST_EFFECT_GREAT_APPEAL_BUT_NO_MORE_MOVES] =
    {
        .description = COMPOUND_STRING("Ein toller Auftritt, danach sind\nkeine Attacken mehr möglich."),
        .effectType = CONTEST_EFFECT_TYPE_APPEAL,
        .appeal = 80,
        .jam = 0,
        .function = ContestEffect_GreatAppealButNoMoreMoves,
    },
    [CONTEST_EFFECT_REPETITION_NOT_BORING] =
    {
        .description = COMPOUND_STRING("Kann wiederholt eingesetzt werden,\nohne den RICHTER zu langweilen."),
        .effectType = CONTEST_EFFECT_TYPE_APPEAL,
        .appeal = 30,
        .jam = 0,
        .function = ContestEffect_RepetitionNotBoring,
    },
    [CONTEST_EFFECT_AVOID_STARTLE_ONCE] =
    {
        .description = COMPOUND_STRING("Kann einmal verhindern, von\nanderen erschreckt zu werden."),
        .effectType = CONTEST_EFFECT_TYPE_AVOID_STARTLE,
        .appeal = 20,
        .jam = 0,
        .function = ContestEffect_AvoidStartleOnce,
    },
    [CONTEST_EFFECT_AVOID_STARTLE] =
    {
        .description = COMPOUND_STRING("Kann verhindern, von\nanderen erschreckt zu werden."),
        .effectType = CONTEST_EFFECT_TYPE_AVOID_STARTLE,
        .appeal = 10,
        .jam = 0,
        .function = ContestEffect_AvoidStartle,
    },
    [CONTEST_EFFECT_AVOID_STARTLE_SLIGHTLY] =
    {
        .description = COMPOUND_STRING("Kann ein wenig verhindern, von\nanderen erschreckt zu werden."),
        .effectType = CONTEST_EFFECT_TYPE_AVOID_STARTLE,
        .appeal = 30,
        .jam = 0,
        .function = ContestEffect_AvoidStartleSlightly,
    },
    [CONTEST_EFFECT_USER_LESS_EASILY_STARTLED] =
    {
        .description = COMPOUND_STRING("Danach lässt sich der Anwender\nschwerer erschrecken."),
        .effectType = CONTEST_EFFECT_TYPE_AVOID_STARTLE,
        .appeal = 30,
        .jam = 0,
        .function = ContestEffect_UserLessEasilyStartled,
    },
    [CONTEST_EFFECT_STARTLE_FRONT_MON] =
    {
        .description = COMPOUND_STRING("Erschreckt das Pokémon\ndavor ein wenig."),
        .effectType = CONTEST_EFFECT_TYPE_STARTLE_MON,
        .appeal = 30,
        .jam = 20,
        .function = ContestEffect_StartleFrontMon,
    },
    [CONTEST_EFFECT_SLIGHTLY_STARTLE_PREV_MONS] =
    {
        .description = COMPOUND_STRING("Erschreckt alle, die schon\nihren Auftritt hatten, ein wenig."),
        .effectType = CONTEST_EFFECT_TYPE_STARTLE_MONS,
        .appeal = 30,
        .jam = 10,
        .function = ContestEffect_StartlePrevMons,
    },
    [CONTEST_EFFECT_STARTLE_PREV_MON] =
    {
        #if C_UPDATED_MOVE_EFFECTS >= GEN_6
        .description = COMPOUND_STRING("Erschreckt das Pokémon, das\nvor dem Anwender dran war."),
        #else
        .description = COMPOUND_STRING("Erschreckt das Pokémon, das\nvor dem Anwender aufgetreten ist."),
        #endif
        .effectType = CONTEST_EFFECT_TYPE_STARTLE_MON,
        .appeal = 20,
        .jam = 30,
        .function = ContestEffect_StartleFrontMon,
    },
    [CONTEST_EFFECT_STARTLE_PREV_MONS] =
    {
        #if C_UPDATED_MOVE_EFFECTS >= GEN_6
        .description = COMPOUND_STRING("Erschreckt alle Pokémon, die\nvor dem Anwender dran waren."),
        #else
        .description = COMPOUND_STRING("Erschreckt alle Pokémon, die\nbereits aufgetreten sind."),
        #endif
        .effectType = CONTEST_EFFECT_TYPE_STARTLE_MONS,
        .appeal = 20,
        .jam = 20,
        .function = ContestEffect_StartlePrevMons,
    },
    [CONTEST_EFFECT_BADLY_STARTLE_FRONT_MON] =
    {
        .description = COMPOUND_STRING("Erschreckt das Pokémon\ndavor stark."),
        .effectType = CONTEST_EFFECT_TYPE_STARTLE_MON,
        .appeal = 10,
        .jam = 40,
        .function = ContestEffect_StartleFrontMon,
    },
    [CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS] =
    {
        .description = COMPOUND_STRING("Erschreckt alle, die schon\nihren Auftritt hatten, stark."),
        .effectType = CONTEST_EFFECT_TYPE_STARTLE_MONS,
        .appeal = 10,
        .jam = 30,
        .function = ContestEffect_StartlePrevMons,
    },
    [CONTEST_EFFECT_STARTLE_PREV_MON_2] =
    {
        .description = COMPOUND_STRING("Erschreckt das Pokémon, das\nvor dem Anwender aufgetreten ist."),
        .effectType = CONTEST_EFFECT_TYPE_STARTLE_MON,
        .appeal = 30,
        .jam = 20,
        .function = ContestEffect_StartlePrevMon2,
    },
    [CONTEST_EFFECT_STARTLE_PREV_MONS_2] =
    {
        .description = COMPOUND_STRING("Erschreckt alle Pokémon, die\nbereits aufgetreten sind."),
        .effectType = CONTEST_EFFECT_TYPE_STARTLE_MONS,
        .appeal = 30,
        .jam = 10,
        .function = ContestEffect_StartlePrevMons2,
    },
    [CONTEST_EFFECT_SHIFT_JUDGE_ATTENTION] =
    {
        #if C_UPDATED_MOVE_EFFECTS >= GEN_6
        .description = COMPOUND_STRING("Das Publikum erwartet von den\nanderen Teilnehmern wenig."),
        #else
        .description = COMPOUND_STRING("Lenkt die Aufmerksamkeit des\nRICHTERS von den anderen ab."),
        #endif
        .effectType = CONTEST_EFFECT_TYPE_WORSEN,
        .appeal = 30,
        .jam = 0,
        .function = ContestEffect_ShiftJudgeAttention,
    },
    [CONTEST_EFFECT_STARTLE_MON_WITH_JUDGES_ATTENTION] =
    {
        .description = COMPOUND_STRING("Erschreckt das Pokémon, das die\nAufmerksamkeit des RICHTERS hat."),
        .effectType = CONTEST_EFFECT_TYPE_STARTLE_MONS,
        .appeal = 20,
        .jam = 10,
        .function = ContestEffect_StartleMonWithJudgesAttention,
    },
    [CONTEST_EFFECT_JAMS_OTHERS_BUT_MISS_ONE_TURN] =
    {
        .description = COMPOUND_STRING("Stört die anderen, setzt aber\neinen Auftritt aus."),
        .effectType = CONTEST_EFFECT_TYPE_STARTLE_MONS,
        .appeal = 40,
        .jam = 40,
        .function = ContestEffect_JamsOthersButMissOneTurn,
    },
    [CONTEST_EFFECT_STARTLE_MONS_SAME_TYPE_APPEAL] =
    {
        .description = COMPOUND_STRING("Erschreckt Pokémon, die einen\nAuftritt desselben Typs hatten."),
        .effectType = CONTEST_EFFECT_TYPE_STARTLE_MONS,
        .appeal = 20,
        .jam = 10,
        .function = ContestEffect_StartleMonsSameTypeAppeal,
    },
    [CONTEST_EFFECT_STARTLE_MONS_COOL_APPEAL] =
    {
        .description = COMPOUND_STRING("Erschreckt Pokémon mit\nCOOLNESS-Auftritten stark."),
        .effectType = CONTEST_EFFECT_TYPE_STARTLE_MONS,
        .appeal = 20,
        .jam = 10,
        .function = ContestEffect_StartleMonsCoolAppeal,
    },
    [CONTEST_EFFECT_STARTLE_MONS_BEAUTY_APPEAL] =
    {
        .description = COMPOUND_STRING("Erschreckt Pokémon mit\nSCHÖNHEITS-Auftritten stark."),
        .effectType = CONTEST_EFFECT_TYPE_STARTLE_MONS,
        .appeal = 20,
        .jam = 10,
        .function = ContestEffect_StartleMonsBeautyAppeal,
    },
    [CONTEST_EFFECT_STARTLE_MONS_CUTE_APPEAL] =
    {
        .description = COMPOUND_STRING("Erschreckt Pokémon mit\nANMUT-Auftritten stark."),
        .effectType = CONTEST_EFFECT_TYPE_STARTLE_MONS,
        .appeal = 20,
        .jam = 10,
        .function = ContestEffect_StartleMonsCuteAppeal,
    },
    [CONTEST_EFFECT_STARTLE_MONS_SMART_APPEAL] =
    {
        .description = COMPOUND_STRING("Erschreckt Pokémon mit\nKLUGHEITS-Auftritten stark."),
        .effectType = CONTEST_EFFECT_TYPE_STARTLE_MONS,
        .appeal = 20,
        .jam = 10,
        .function = ContestEffect_StartleMonsSmartAppeal,
    },
    [CONTEST_EFFECT_STARTLE_MONS_TOUGH_APPEAL] =
    {
        .description = COMPOUND_STRING("Erschreckt Pokémon mit\nSTÄRKE-Auftritten stark."),
        .effectType = CONTEST_EFFECT_TYPE_STARTLE_MONS,
        .appeal = 20,
        .jam = 10,
        .function = ContestEffect_StartleMonsToughAppeal,
    },
    [CONTEST_EFFECT_MAKE_FOLLOWING_MON_NERVOUS] =
    {
        .description = COMPOUND_STRING("Macht ein Pokémon nach dem\nAnwender nervös."),
        .effectType = CONTEST_EFFECT_TYPE_WORSEN,
        .appeal = 20,
        .jam = 0,
        .function = ContestEffect_MakeFollowingMonNervous,
    },
    [CONTEST_EFFECT_MAKE_FOLLOWING_MONS_NERVOUS] =
    {
        #if C_UPDATED_MOVE_EFFECTS >= GEN_6
        .description = COMPOUND_STRING("Macht die übrigen\nPokémon nervös."),
        #else
        .description = COMPOUND_STRING("Macht alle Pokémon nach dem\nAnwender nervös."),
        #endif
        .effectType = CONTEST_EFFECT_TYPE_WORSEN,
        .appeal = 20,
        .jam = 0,
        .function = ContestEffect_MakeFollowingMonsNervous,
    },
    [CONTEST_EFFECT_WORSEN_CONDITION_OF_PREV_MONS] =
    {
        .description = COMPOUND_STRING("Verschlechtert die Verfassung\naller, die schon aufgetreten sind."),
        .effectType = CONTEST_EFFECT_TYPE_WORSEN,
        .appeal = 30,
        .jam = 0,
        .function = ContestEffect_WorsenConditionOfPrevMons,
    },
    [CONTEST_EFFECT_BADLY_STARTLES_MONS_IN_GOOD_CONDITION] =
    {
        .description = COMPOUND_STRING("Erschreckt Pokémon in guter\nVerfassung stark."),
        .effectType = CONTEST_EFFECT_TYPE_STARTLE_MONS,
        .appeal = 30,
        .jam = 10,
        .function = ContestEffect_BadlyStartlesMonsInGoodCondition,
    },
    [CONTEST_EFFECT_BETTER_IF_FIRST] =
    {
        .description = COMPOUND_STRING("Der Auftritt wirkt sehr gut,\nwenn er als Erster erfolgt."),
        .effectType = CONTEST_EFFECT_TYPE_SPECIAL_APPEAL,
        .appeal = 20,
        .jam = 0,
        .function = ContestEffect_BetterIfFirst,
    },
    [CONTEST_EFFECT_BETTER_IF_LAST] =
    {
        .description = COMPOUND_STRING("Der Auftritt wirkt sehr gut,\nwenn er als Letzter erfolgt."),
        .effectType = CONTEST_EFFECT_TYPE_SPECIAL_APPEAL,
        .appeal = 20,
        .jam = 0,
        .function = ContestEffect_BetterIfLast,
    },
    [CONTEST_EFFECT_APPEAL_AS_GOOD_AS_PREV_ONES] =
    {
        .description = COMPOUND_STRING("Macht den Auftritt so gut wie\ndie davor."),
        .effectType = CONTEST_EFFECT_TYPE_SPECIAL_APPEAL,
        .appeal = 10,
        .jam = 0,
        .function = ContestEffect_AppealAsGoodAsPrevOnes,
    },
    [CONTEST_EFFECT_APPEAL_AS_GOOD_AS_PREV_ONE] =
    {
        .description = COMPOUND_STRING("Macht den Auftritt so gut wie\nden davor."),
        .effectType = CONTEST_EFFECT_TYPE_SPECIAL_APPEAL,
        .appeal = 10,
        .jam = 0,
        .function = ContestEffect_AppealAsGoodAsPrevOne,
    },
    [CONTEST_EFFECT_BETTER_WHEN_LATER] =
    {
        .description = COMPOUND_STRING("Der Auftritt wirkt besser,\nje später er erfolgt."),
        .effectType = CONTEST_EFFECT_TYPE_SPECIAL_APPEAL,
        .appeal = 10,
        .jam = 0,
        .function = ContestEffect_BetterWhenLater,
    },
    [CONTEST_EFFECT_QUALITY_DEPENDS_ON_TIMING] =
    {
        #if C_UPDATED_MOVE_EFFECTS >= GEN_6
        .description = COMPOUND_STRING("Die Wirkung hängt davon ab,\nwann sie eingesetzt wird."),
        #else
        .description = COMPOUND_STRING("Die Qualität des Auftritts hängt\nvom Zeitpunkt ab."),
        #endif
        .effectType = CONTEST_EFFECT_TYPE_SPECIAL_APPEAL,
        .appeal = 10,
        .jam = 0,
        .function = ContestEffect_QualityDependsOnTiming,
    },
    [CONTEST_EFFECT_BETTER_IF_SAME_TYPE] =
    {
        .description = COMPOUND_STRING("Wirkt gut, wenn sie denselben Typ\nwie die davor hat."),
        .effectType = CONTEST_EFFECT_TYPE_SPECIAL_APPEAL,
        .appeal = 20,
        .jam = 0,
        .function = ContestEffect_BetterIfSameType,
    },
    [CONTEST_EFFECT_BETTER_IF_DIFF_TYPE] =
    {
        .description = COMPOUND_STRING("Wirkt gut, wenn sie einen anderen\nTyp als die davor hat."),
        .effectType = CONTEST_EFFECT_TYPE_SPECIAL_APPEAL,
        .appeal = 20,
        .jam = 0,
        .function = ContestEffect_BetterIfDiffType,
    },
    [CONTEST_EFFECT_AFFECTED_BY_PREV_APPEAL] =
    {
        #if C_UPDATED_MOVE_EFFECTS >= GEN_6
        .description = COMPOUND_STRING("Hängt davon ab, wie gut die Attacke\ndes vorherigen Pokémon lief."),
        #else
        .description = COMPOUND_STRING("Hängt davon ab, wie gut der\nAuftritt davor lief."),
        #endif
        .effectType = CONTEST_EFFECT_TYPE_SPECIAL_APPEAL,
        .appeal = 30,
        .jam = 0,
        .function = ContestEffect_AffectedByPrevAppeal,
    },
    [CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS] =
    {
        .description = COMPOUND_STRING("Verbessert die Verfassung des\nAnwenders. Hilft gegen Nervosität."),
        .effectType = CONTEST_EFFECT_TYPE_SPECIAL_APPEAL,
        .appeal = 10,
        .jam = 0,
        .function = ContestEffect_ImproveConditionPreventNervousness,
    },
    [CONTEST_EFFECT_BETTER_WITH_GOOD_CONDITION] =
    {
        .description = COMPOUND_STRING("Der Auftritt wirkt gut, wenn die\nVerfassung des Anwenders gut ist."),
        .effectType = CONTEST_EFFECT_TYPE_SPECIAL_APPEAL,
        .appeal = 10,
        .jam = 0,
        .function = ContestEffect_BetterWithGoodCondition,
    },
    [CONTEST_EFFECT_NEXT_APPEAL_EARLIER] =
    {
        #if C_UPDATED_MOVE_EFFECTS >= GEN_6
        .description = COMPOUND_STRING("Der Anwender ist in der nächsten\nRunde früher dran."),
        #else
        .description = COMPOUND_STRING("Der nächste Auftritt kann in der\nnächsten Runde früher erfolgen."),
        #endif
        .effectType = CONTEST_EFFECT_TYPE_TURN_ORDER,
        .appeal = 30,
        .jam = 0,
        .function = ContestEffect_NextAppealEarlier,
    },
    [CONTEST_EFFECT_NEXT_APPEAL_LATER] =
    {
        #if C_UPDATED_MOVE_EFFECTS >= GEN_6
        .description = COMPOUND_STRING("Der Anwender ist in der nächsten\nRunde später dran."),
        #else
        .description = COMPOUND_STRING("Der nächste Auftritt kann in der\nnächsten Runde später erfolgen."),
        #endif
        .effectType = CONTEST_EFFECT_TYPE_TURN_ORDER,
        .appeal = 30,
        .jam = 0,
        .function = ContestEffect_NextAppealLater,
    },
    [CONTEST_EFFECT_MAKE_SCRAMBLING_TURN_ORDER_EASIER] =
    {
        .description = COMPOUND_STRING("Die Reihenfolge der nächsten Runde\nwird leichter durcheinandergebracht."),
        .effectType = CONTEST_EFFECT_TYPE_TURN_ORDER,
        .appeal = 30,
        .jam = 0,
        .function = ContestEffect_MakeScramblingTurnOrderEasier,
    },
    [CONTEST_EFFECT_SCRAMBLE_NEXT_TURN_ORDER] =
    {
        .description = COMPOUND_STRING("Bringt die Reihenfolge der Auftritte\nder nächsten Runde durcheinander."),
        .effectType = CONTEST_EFFECT_TYPE_TURN_ORDER,
        .appeal = 30,
        .jam = 0,
        .function = ContestEffect_ScrambleNextTurnOrder,
    },
    [CONTEST_EFFECT_EXCITE_AUDIENCE_IN_ANY_CONTEST] =
    {
        .description = COMPOUND_STRING("Ein Auftritt, der das Publikum in\njedem WETTBEWERB begeistert."),
        .effectType = CONTEST_EFFECT_TYPE_SPECIAL_APPEAL,
        .appeal = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? 20 : 10,
        .jam = 0,
        .function = ContestEffect_ExciteAudienceInAnyContest,
    },
    [CONTEST_EFFECT_BADLY_STARTLE_MONS_WITH_GOOD_APPEALS] =
    {
        .description = COMPOUND_STRING("Erschreckt alle Pokémon mit guten\nAuftritten stark."),
        .effectType = CONTEST_EFFECT_TYPE_STARTLE_MONS,
        .appeal = 20,
        .jam = 10,
        .function = ContestEffect_BadlyStartleMonsWithGoodAppeals,
    },
    [CONTEST_EFFECT_BETTER_WHEN_AUDIENCE_EXCITED] =
    {
        .description = COMPOUND_STRING("Der Auftritt wirkt umso besser,\nje begeisterter das Publikum ist."),
        .effectType = CONTEST_EFFECT_TYPE_SPECIAL_APPEAL,
        .appeal = 10,
        .jam = 0,
        .function = ContestEffect_BetterWhenAudienceExcited,
    },
    [CONTEST_EFFECT_DONT_EXCITE_AUDIENCE] =
    {
        .description = COMPOUND_STRING("Hält das Publikum vorübergehend\ndavon ab, sich zu begeistern."),
        .effectType = CONTEST_EFFECT_TYPE_WORSEN,
        .appeal = 30,
        .jam = 0,
        .function = ContestEffect_DontExciteAudience,
    },
};
