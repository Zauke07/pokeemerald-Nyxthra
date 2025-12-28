GraniteCave_B3F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, GraniteCave_B3F_OnTransition
	.byte 0

GraniteCave_B3F_OnTransition::
	goto_if_set FLAG_ENCOUNTERED_ENTEI,   GraniteCave_B3F_HideEntei
	goto_if_set FLAG_ENCOUNTERED_RAIKOU,  GraniteCave_B3F_HideRaikou
	goto_if_set FLAG_ENCOUNTERED_SUICUNE, GraniteCave_B3F_HideSuicune
	end

GraniteCave_B3F_HideEntei::
	hideobject LOCALID_ENTEI
	goto_if_set FLAG_ENCOUNTERED_RAIKOU,  GraniteCave_B3F_HideRaikou
	goto_if_set FLAG_ENCOUNTERED_SUICUNE, GraniteCave_B3F_HideSuicune
	end

GraniteCave_B3F_HideRaikou::
	hideobject LOCALID_RAIKOU
	goto_if_set FLAG_ENCOUNTERED_SUICUNE, GraniteCave_B3F_HideSuicune
	end

GraniteCave_B3F_HideSuicune::
	hideobject LOCALID_SUICUNE
	end

@ ==================================================================
@ Trigger links (Entei)
@ ==================================================================
GraniteCave_B3F_Trigger_Entei::
	goto_if_set FLAG_ENCOUNTERED_ENTEI, GraniteCave_B3F_Trigger_DoNothing
	goto_if_set FLAG_HOUND_EVENT_ACTIVE, GraniteCave_B3F_Event_AllHounds_FromLeft
	goto_if_set FLAG_HOUND_TRIGGER_BLOCKED_SHOWN, GraniteCave_B3F_Trigger_DoNothing
	goto GraniteCave_B3F_TriggerBlocked

@ ==================================================================
@ Trigger mitte (Raikou)
@ ==================================================================
GraniteCave_B3F_Trigger_Raikou::
	goto_if_set FLAG_ENCOUNTERED_RAIKOU, GraniteCave_B3F_Trigger_DoNothing
	goto_if_set FLAG_HOUND_EVENT_ACTIVE, GraniteCave_B3F_Event_AllHounds_FromMiddle
	goto_if_set FLAG_HOUND_TRIGGER_BLOCKED_SHOWN, GraniteCave_B3F_Trigger_DoNothing
	goto GraniteCave_B3F_TriggerBlocked

@ ==================================================================
@ Trigger rechts (Suicune)
@ ==================================================================
GraniteCave_B3F_Trigger_Suicune::
	goto_if_set FLAG_ENCOUNTERED_SUICUNE, GraniteCave_B3F_Trigger_DoNothing
	goto_if_set FLAG_HOUND_EVENT_ACTIVE, GraniteCave_B3F_Event_AllHounds_FromRight
	goto_if_set FLAG_HOUND_TRIGGER_BLOCKED_SHOWN, GraniteCave_B3F_Trigger_DoNothing
	goto GraniteCave_B3F_TriggerBlocked

@ ==================================================================
@ Blockierter Trigger - Text nur einmal
@ ==================================================================
GraniteCave_B3F_TriggerBlocked::
	msgbox GraniteCave_B3F_Text_TriggerBlocked, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_HOUND_TRIGGER_BLOCKED_SHOWN
	end

@ ==================================================================
@ Trigger macht nichts
@ ==================================================================
GraniteCave_B3F_Trigger_DoNothing::
	end

@ ==================================================================
@ Events mit unterschiedlichen Spielerbewegungen
@ ==================================================================

GraniteCave_B3F_Event_AllHounds_FromLeft::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, GraniteCave_B3F_Movement_PlayerForward3RightFaceUp
	waitmovement 0
	goto GraniteCave_B3F_Event_AllHounds_Common

GraniteCave_B3F_Event_AllHounds_FromMiddle::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, GraniteCave_B3F_Movement_PlayerForward3FaceUp
	waitmovement 0
	goto GraniteCave_B3F_Event_AllHounds_Common

GraniteCave_B3F_Event_AllHounds_FromRight::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, GraniteCave_B3F_Movement_PlayerForward3LeftFaceUp
	waitmovement 0
	goto GraniteCave_B3F_Event_AllHounds_Common

@ ==================================================================
@ Gemeinsamer Teil: alle drei Hunde springen
@ ==================================================================

GraniteCave_B3F_Event_AllHounds_Common::
	@ Entei
	playmoncry SPECIES_ENTEI, CRY_MODE_ENCOUNTER
	waitmoncry
	applymovement LOCALID_ENTEI, GraniteCave_B3F_Movement_HopOutOfRock
	waitmovement 0
	applymovement LOCALID_ENTEI, GraniteCave_B3F_Movement_HopRightToMiddle
	waitmovement 0
	playmoncry SPECIES_ENTEI, CRY_MODE_NORMAL
	waitmoncry
	applymovement LOCALID_ENTEI, GraniteCave_B3F_Movement_HopLeftDownAndExit
	waitmovement 0
	removeobject LOCALID_ENTEI
	setflag FLAG_ENCOUNTERED_ENTEI

	@ Raikou
	playmoncry SPECIES_RAIKOU, CRY_MODE_ENCOUNTER
	waitmoncry
	applymovement LOCALID_RAIKOU, GraniteCave_B3F_Movement_HopOutOfRock
	waitmovement 0
	applymovement LOCALID_RAIKOU, GraniteCave_B3F_Movement_HopDownMiddle
	waitmovement 0
	playmoncry SPECIES_RAIKOU, CRY_MODE_NORMAL
	waitmoncry
	applymovement LOCALID_RAIKOU, GraniteCave_B3F_Movement_HopRightDownAndExit
	waitmovement 0
	removeobject LOCALID_RAIKOU
	setflag FLAG_ENCOUNTERED_RAIKOU

	@ Suicune
	playmoncry SPECIES_SUICUNE, CRY_MODE_ENCOUNTER
	waitmoncry
	applymovement LOCALID_SUICUNE, GraniteCave_B3F_Movement_HopOutOfRock
	waitmovement 0
	applymovement LOCALID_SUICUNE, GraniteCave_B3F_Movement_HopLeftToMiddle
	waitmovement 0
	playmoncry SPECIES_SUICUNE, CRY_MODE_NORMAL
	waitmoncry
	applymovement LOCALID_SUICUNE, GraniteCave_B3F_Movement_HopRightDownAndExit
	waitmovement 0
	removeobject LOCALID_SUICUNE
	setflag FLAG_ENCOUNTERED_SUICUNE

	clearflag FLAG_HOUND_EVENT_ACTIVE
	setflag FLAG_HOUND_EVENT_FINISHED
	releaseall
	end

@ ==================================================================
@ Blockierter Trigger
@ ==================================================================

GraniteCave_B3F_Text_TriggerBlocked:
	.string "Es scheint nichts zu passieren…\n"
	.string "Vielleicht fehlt etwas.$"

@ ==================================================================
@ Bewegungen für den Spieler (je nach Trigger)
@ ==================================================================

GraniteCave_B3F_Movement_PlayerForward3FaceUp::
	walk_fast_up
	walk_fast_up
	walk_fast_up
	face_up
	step_end

GraniteCave_B3F_Movement_PlayerForward3RightFaceUp::
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_right
	face_up
	step_end

GraniteCave_B3F_Movement_PlayerForward3LeftFaceUp::
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_left
	face_up
	step_end

@ ==================================================================
@ Bewegungen der Hunde
@ ==================================================================

GraniteCave_B3F_Movement_HopOutOfRock::
	jump_2_down
	jump_down
	step_end

GraniteCave_B3F_Movement_HopRightToMiddle::
	jump_right
	jump_right
	jump_right
	step_end

GraniteCave_B3F_Movement_HopLeftDownAndExit::
	jump_left
	jump_down
	jump_down
	jump_down
	step_end

GraniteCave_B3F_Movement_HopDownMiddle::
	jump_down
	jump_down
	jump_down
	step_end

GraniteCave_B3F_Movement_HopRightDownAndExit::
	jump_right
	jump_down
	jump_down
	jump_down
	step_end

GraniteCave_B3F_Movement_HopLeftToMiddle::
	jump_left
	jump_left
	jump_left
	step_end
