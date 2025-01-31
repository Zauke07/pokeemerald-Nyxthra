.set LOCALID_CELEBI, 1

BabyBootCamp_Tests_MapScripts::
    map_script MAP_SCRIPT_ON_TRANSITION, BabyBootCamp_Tests_OnTransition
    map_script MAP_SCRIPT_ON_RESUME, BabyBootCamp_Tests_OnResume
    .byte 0

BabyBootCamp_Tests_OnTransition:
    call_if_set FLAG_CAUGHT_CELEBI, BabyBootCamp_Tests_EventScript_HideCelebi
    call_if_unset FLAG_CAUGHT_CELEBI, BabyBootCamp_Tests_EventScript_TryShowCelebi
    call_if_set FLAG_CAUGHT_LUGIA, BabyBootCamp_Tests_EventScript_HideLugia
	call_if_unset FLAG_CAUGHT_LUGIA, BabyBootCamp_Tests_EventScript_TryShowLugia
	end

BabyBootCamp_Tests_EventScript_HideCelebi::
    setflag FLAG_HIDE_CELEBI
    return

BabyBootCamp_Tests_EventScript_TryShowCelebi::
    goto_if_set FLAG_DEFEATED_CELEBI, Common_EventScript_NopReturn
    clearflag FLAG_HIDE_CELEBI
    return

BabyBootCamp_Tests_OnResume:
    call_if_set FLAG_SYS_CTRL_OBJ_DELETE, BabyBootCamp_Tests_EventScript_TryRemoveCelebi
    call_if_set FLAG_SYS_CTRL_OBJ_DELETE, BabyBootCamp_Tests_EventScript_TryRemoveLugia
    end

BabyBootCamp_Tests_EventScript_TryRemoveCelebi::
    specialvar VAR_RESULT, GetBattleOutcome
    goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
    removeobject LOCALID_CELEBI
    return

BabyBootCamp_Tests_EventScript_Celebi::
    lock
    faceplayer
    playmoncry SPECIES_CELEBI, CRY_MODE_ENCOUNTER
    waitmoncry
    setflag FLAG_HIDE_CELEBI
    seteventmon SPECIES_CELEBI, 1
    special BattleSetup_StartLegendaryBattle
    waitstate
    specialvar VAR_RESULT, GetBattleOutcome
    goto_if_eq VAR_RESULT, B_OUTCOME_WON, BabyBootCamp_Tests_EventScript_CelebiDefeated
    goto_if_eq VAR_RESULT, B_OUTCOME_RAN, BabyBootCamp_Tests_EventScript_CelebiRan
    goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, BabyBootCamp_Tests_EventScript_CelebiRan
    setflag FLAG_CAUGHT_CELEBI
    release
    end

BabyBootCamp_Tests_EventScript_CelebiDefeated::
    setflag FLAG_CAUGHT_CELEBI
    setflag FLAG_DEFEATED_CELEBI
    release
    end

BabyBootCamp_Tests_EventScript_CelebiRan::
    setflag FLAG_DEFEATED_CELEBI
    release
    end

BabyBootCamp_Tests_EventScript_AGATHA::
    msgbox BabyBootCamp_Tests_Text_AGATHA, MSGBOX_DEFAULT
    release
    end

BabyBootCamp_Tests_Text_AGATHA:
    .string "Hallo test.$"
	

