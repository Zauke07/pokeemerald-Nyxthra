GraniteCave_B2F_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, GraniteCave_B2F_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, GraniteCave_B2F_OnTransition
	.byte 0

GraniteCave_B2F_OnLoad:
	call_if_set FLAG_HOUND_EVENT_FINISHED, GraniteCave_B2F_EventScript_OpenSecretExit
	call_if_unset FLAG_HOUND_EVENT_FINISHED, GraniteCave_B2F_EventScript_CloseSecretExit
	end

GraniteCave_B2F_OnTransition:
	call_if_set FLAG_HOUND_EVENT_FINISHED, GraniteCave_B2F_EventScript_OpenSecretExit
	call_if_unset FLAG_HOUND_EVENT_FINISHED, GraniteCave_B2F_EventScript_CloseSecretExit
	end

@ =====================================================
@ Braille-Wand
@ =====================================================
GraniteCave_B2F_EventScript_BrailleWall::
	lockall
	braillemsgbox GraniteCave_B2F_Braille_JohtoStarters
	goto_if_set FLAG_HOUND_EVENT_FINISHED, GraniteCave_B2F_EventScript_AlreadyDone
	goto_if_set FLAG_HOUND_EVENT_ACTIVE, GraniteCave_B2F_EventScript_NoEffect
	specialvar VAR_RESULT, CheckChikoritaCharmanderSquirtle
	goto_if_eq VAR_RESULT, FALSE, GraniteCave_B2F_EventScript_NoEffect
	fadeoutbgm 0
	playse SE_TRUCK_MOVE
	special DoSealedChamberShakingEffect_Long
	waitstate
	delay 40
	special DoSealedChamberShakingEffect_Short
	waitstate
	playse SE_DOOR
	delay 40
	special DoSealedChamberShakingEffect_Short
	waitstate
	playse SE_DOOR
	delay 40
	special DoSealedChamberShakingEffect_Short
	waitstate
	playse SE_DOOR
	delay 40
	msgbox GraniteCave_B2F_Text_HoundsAwaken, MSGBOX_DEFAULT
	closemessage
	fadeinbgm 0
	setflag FLAG_HOUND_EVENT_ACTIVE
	setflag FLAG_HOUND_EVENT_FINISHED
	setflag FLAG_HIDE_GRANITECAVE_B2F_NPC
	releaseall
	end

GraniteCave_B2F_EventScript_AlreadyDone::
	msgbox GraniteCave_B2F_Text_NothingHappened, MSGBOX_DEFAULT
	releaseall
	end

GraniteCave_B2F_EventScript_NoEffect::
	msgbox GraniteCave_B2F_Text_NothingHappened, MSGBOX_DEFAULT
	releaseall
	end

@ =====================================================
@ NPC vor der Wand
@ =====================================================
GraniteCave_B2F_EventScript_NPC::
	lockall
	faceplayer
	goto_if_set FLAG_HOUND_EVENT_ACTIVE, GraniteCave_B2F_EventScript_NPC_After
	msgbox GraniteCave_B2F_Text_NPC_Before, MSGBOX_DEFAULT
	releaseall
	end

GraniteCave_B2F_EventScript_NPC_After::
	msgbox GraniteCave_B2F_Text_NPC_After, MSGBOX_DEFAULT
	releaseall
	end

@ =====================================================
@ Metatile-Wechsel für Eingang
@ =====================================================
GraniteCave_B2F_EventScript_OpenSecretExit::
	setmetatile 21, 9, METATILE_Cave_SealedChamberEntrance_TopMid, TRUE
	setmetatile 21, 10, METATILE_Cave_SealedChamberEntrance_BottomMid, TRUE
	return

GraniteCave_B2F_EventScript_CloseSecretExit::
	setmetatile 21, 9, METATILE_Cave_EntranceCover, TRUE
	setmetatile 21, 10, METATILE_Cave_EntranceCover, TRUE
	return

@ =====================================================
@ Texte
@ =====================================================
GraniteCave_B2F_Text_NPC_Before:
	.string "Man sagt, tief in dieser Höhle\n"
	.string "sollen sich uralte Gesteinswesen\l"
	.string "verborgen haben.\p"
	.string "Sie schlafen seit Jahrtausenden.\p"
	.string "Alte Schriften berichten, dass\n"
	.string "man drei bestimmte Pokémon bei\l"
	.string "sich tragen muss, um sie zu\n"
	.string "erwecken.\p"
	.string "Doch niemand kennt die Sprache\n"
	.string "dieser Schriften mehr…$"

GraniteCave_B2F_Text_NPC_After:
	.string "Unglaublich… du hast es geschafft!\n"
	.string "Ich spüre, wie etwas erwacht…$"

GraniteCave_B2F_Text_NothingHappened:
	.string "…Aber nichts geschieht.$"

GraniteCave_B2F_Text_HoundsAwaken:
	.string "Die Höhle erbebt…\n"
	.string "Du hörst ferne Schreie!$"
