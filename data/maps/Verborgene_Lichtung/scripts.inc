Verborgene_Lichtung_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Verborgene_Lichtung_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, Verborgene_Lichtung_OnResume
	.byte 0

Verborgene_Lichtung_OnTransition:
	call_if_set   FLAG_CAUGHT_VERBORGENE_LICHTUNG_CELEBI, Verborgene_Lichtung_EventScript_HideCelebi
	call_if_unset FLAG_CAUGHT_VERBORGENE_LICHTUNG_CELEBI, Verborgene_Lichtung_EventScript_TryShowCelebi
	end

Verborgene_Lichtung_EventScript_HideCelebi::
	setvar VAR_TEMP_0, 1
	setflag FLAG_HIDE_VERBORGENE_LICHTUNG_CELEBI
	return

@ Nyxthra story: reappears on every revisit until actually caught, same as
@ Mewtwo Statue/Lavados/Uxie - a mere defeat/flee no longer permanently
@ hides it (FLAG_DEFEATED_VERBORGENE_LICHTUNG_CELEBI is still set for any
@ other tracking purposes, just no longer checked here).
Verborgene_Lichtung_EventScript_TryShowCelebi::
	setvar VAR_TEMP_0, 0
	clearflag FLAG_HIDE_VERBORGENE_LICHTUNG_CELEBI
	return

Verborgene_Lichtung_OnResume:
	call_if_set   FLAG_SYS_CTRL_OBJ_DELETE, Verborgene_Lichtung_EventScript_TryRemoveCelebi
	call_if_set   FLAG_CAUGHT_VERBORGENE_LICHTUNG_CELEBI,        Verborgene_Lichtung_EventScript_HideCelebi
	end

Verborgene_Lichtung_EventScript_TryRemoveCelebi::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject LOCALID_LICHTUNG_CELEBI
	return

Verborgene_Lichtung_EventScript_Celebi::
	lockall
	faceplayer
	goto Verborgene_Lichtung_EventScript_StartCelebiBattleNoMovement

@ =====================================================================
@ Trigger: Spieler betritt Auslösefeld
@ =====================================================================

Verborgene_Lichtung_EventScript_TriggerCelebi::
	setvar VAR_TEMP_0, 1
	goto_if_set FLAG_CAUGHT_VERBORGENE_LICHTUNG_CELEBI,  Common_EventScript_NopReturn
	goto_if_set FLAG_DEFEATED_VERBORGENE_LICHTUNG_CELEBI, Common_EventScript_NopReturn
	lockall
	applymovement LOCALID_LICHTUNG_CELEBI, Verborgene_Lichtung_Movement_CelebiApproach
	waitmovement 0
	goto Verborgene_Lichtung_EventScript_StartCelebiBattleNoMovement

Verborgene_Lichtung_EventScript_StartCelebiBattleNoMovement:
	setvar VAR_LAST_TALKED, LOCALID_LICHTUNG_CELEBI
	seteventmon SPECIES_CELEBI, 30
	playmoncry VAR_0x8004, CRY_MODE_ENCOUNTER
	waitmoncry
	delay 30
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON,               Verborgene_Lichtung_EventScript_DefeatedCelebi
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN,               Verborgene_Lichtung_EventScript_RanFromCelebi
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, Verborgene_Lichtung_EventScript_RanFromCelebi
	setflag FLAG_CAUGHT_VERBORGENE_LICHTUNG_CELEBI
	setvar VAR_TEMP_0, 1
	setflag FLAG_HIDE_VERBORGENE_LICHTUNG_CELEBI
	goto Common_EventScript_RemoveStaticPokemon
	end

Verborgene_Lichtung_EventScript_DefeatedCelebi::
	setflag FLAG_DEFEATED_VERBORGENE_LICHTUNG_CELEBI
	goto Common_EventScript_LegendaryFlewAway
	end

Verborgene_Lichtung_EventScript_RanFromCelebi::
	goto Common_EventScript_LegendaryFlewAway
	end

@ =====================================================================
@ Bewegungen
@ =====================================================================

Verborgene_Lichtung_Movement_CelebiApproach:
	walk_down
	walk_down
	walk_down
	walk_in_place_down
	delay_16
	delay_16
	step_end

@ =====================================================================
@ Schild: Vermoostes Steinschild
@ =====================================================================

Verborgene_Lichtung_EventScript_Sign::
	msgbox Verborgene_Lichtung_Text_Sign, MSGBOX_SIGN
	end

Verborgene_Lichtung_Text_Sign:
	.string "{COLOR GREEN}VERBORGENE L…CH…UNG\n"
	.string "… … … … … …{COLOR WHITE}\p"
	.string "{COLOR PLAYER_CLR}{PLAYER}: Die restlichen Buchstaben\n"
	.string "sind vom Moos überwuchert.{COLOR WHITE}$"
