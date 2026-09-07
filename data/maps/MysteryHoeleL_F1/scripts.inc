MysteryHoeleL_F1_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MysteryHoeleL_F1_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, MysteryHoeleL_F1_OnResume
	.byte 0

MysteryHoeleL_F1_OnTransition:
	@ Lavados verstecken, wenn schon gefangen
	call_if_set   FLAG_CAUGHT_LAVADOS, MysteryHoeleL_F1_EventScript_HideLavados
	@ Lavados zeigen, wenn noch nicht besiegt/gefangen
	call_if_unset FLAG_CAUGHT_LAVADOS, MysteryHoeleL_F1_EventScript_TryShowLavados
	end

MysteryHoeleL_F1_EventScript_HideLavados::
	setvar VAR_TEMP_1, 1
	setflag FLAG_HIDE_LAVADOS
	return

@ Nyxthra story: shows again on every revisit as long as it hasn't actually
@ been caught - only fleeing/defeating it used to permanently hide it too
@ (FLAG_DEFEATED_LAVADOS), which meant losing your one shot forever if you
@ didn't catch it that first time. Matches Mewtwo Statue's own behavior
@ (Route119_Mistery) - that one only ever checks its CAUGHT flag too.
MysteryHoeleL_F1_EventScript_TryShowLavados::
	setvar VAR_TEMP_1, 0
	clearflag FLAG_HIDE_LAVADOS
	return

MysteryHoeleL_F1_OnResume:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, MysteryHoeleL_F1_EventScript_TryRemoveLavados
	call_if_set   FLAG_CAUGHT_LAVADOS, MysteryHoeleL_F1_EventScript_HideLavados
	end

MysteryHoeleL_F1_EventScript_TryRemoveLavados::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject LOCALID_MYSTERY_HOELE_LAVADOS
	return

@ =====================================================================
@ Haupt-Event: Lavados ansprechen
@ =====================================================================

MysteryHoeleL_F1_EventScript_Lavados::
	lockall
	setvar VAR_TEMP_1, 1
	special SpawnCameraObject
	applymovement LOCALID_MYSTERY_HOELE_LAVADOS, MysteryHoeleL_F1_Movement_LavadosAppear
	applymovement LOCALID_CAMERA, MysteryHoeleL_F1_Movement_CameraPanUp
	waitmovement 0
	delay 50
	setweather WEATHER_NONE
	doweather
	setvar VAR_0x8004, SPECIES_MOLTRES
	special RandomizeStaticMonVar8004
	waitse
	playmoncry VAR_0x8004, CRY_MODE_ENCOUNTER
	delay 30
	waitmoncry
	delay 60

	@ EINMAL Flügelschlag, während Lavados auf dich zufliegt
	setvar VAR_0x8004, 3	@ nur 1 Loop
	setvar VAR_0x8005, 35
	special LoopWingFlapSE
	applymovement LOCALID_CAMERA, MysteryHoeleL_F1_Movement_CameraPanDown
	applymovement LOCALID_MYSTERY_HOELE_LAVADOS, MysteryHoeleL_F1_Movement_LavadosApproach
	waitmovement 0
	special RemoveCameraObject

	setvar VAR_LAST_TALKED, LOCALID_MYSTERY_HOELE_LAVADOS
	seteventmon SPECIES_MOLTRES, 30
	playmoncry VAR_0x8004, CRY_MODE_ENCOUNTER
	delay 30
	waitmoncry
	delay 60
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, MysteryHoeleL_F1_EventScript_DefeatedLavados
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, MysteryHoeleL_F1_EventScript_RanFromLavados
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, MysteryHoeleL_F1_EventScript_RanFromLavados
	setflag FLAG_CAUGHT_LAVADOS
	setvar VAR_TEMP_1, 1
	setflag FLAG_HIDE_LAVADOS
	goto Common_EventScript_RemoveStaticPokemon
	end


MysteryHoeleL_F1_EventScript_DefeatedLavados::
	setflag FLAG_DEFEATED_LAVADOS
	goto Common_EventScript_LegendaryFlewAway
	end

MysteryHoeleL_F1_EventScript_RanFromLavados::
	goto Common_EventScript_LegendaryFlewAway
	end

@ =====================================================================
@ Bewegungen - einfach 1:1 von Ho-Oh kopiert und umbenannt
@ =====================================================================

MysteryHoeleL_F1_Movement_CameraPanUp:
	walk_up
	walk_up
	walk_up
	step_end

MysteryHoeleL_F1_Movement_CameraPanDown:
	delay_16
	delay_16
	walk_down
	walk_down
	walk_down
	step_end

MysteryHoeleL_F1_Movement_LavadosApproach:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_in_place_down
	delay_16
	delay_16
	step_end

MysteryHoeleL_F1_Movement_LavadosAppear:
	delay_16
	delay_16
	walk_in_place_down
	walk_in_place_down
	walk_in_place_down
	walk_in_place_down
	step_end
