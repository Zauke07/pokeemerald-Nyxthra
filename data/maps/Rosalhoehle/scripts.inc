Rosalhoehle_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, Rosalhoehle_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, Rosalhoehle_OnTransition
	.byte 0

@ Nyxthra: Sobald der Spieler den EP-Teiler von MR. TRUMM hat, hat Team Rocket
@ die Steine vor der rechten Leiter weggeräumt (Zugang zum Versteck).
Rosalhoehle_OnLoad:
	call_if_set FLAG_RECEIVED_EXP_SHARE, Rosalhoehle_EventScript_OpenRocketLadder
	end

Rosalhoehle_EventScript_OpenRocketLadder::
	setmetatile 14, 5, 0x201, FALSE
	setmetatile 15, 5, 0x201, FALSE
	setmetatile 16, 5, 0x201, FALSE
	return

Rosalhoehle_OnTransition:
	call_if_set FLAG_ROSAL_ROCKET_SPUREN_GESEHEN, Rosalhoehle_EventScript_DisableTrigger
	end

Rosalhoehle_EventScript_DisableTrigger::
	setvar VAR_TEMP_0, 1
	return

Rosalhoehle_EventScript_TriggerBlockedStairs::
	goto_if_set FLAG_RECEIVED_EXP_SHARE, Rosalhoehle_EventScript_TriggerRocketTracks
	lockall
	applymovement LOCALID_PLAYER, Common_Movement_QuestionMark
	playse SE_PIN	   @ Soundeffekt für das Ausrufezeichen
	waitmovement 0
	delay 16					   @ kurze Pause (~0.25 Sekunden)
	delay 16					   @ noch eine kleine Pause für sichtbare Reaktion
	applymovement LOCALID_PLAYER, Rosalhoehle_Movement_RunUpLook
	waitmovement 0
	msgbox Rosalhoehle_Text_PlayerBlockedStairs, MSGBOX_DEFAULT
	setvar VAR_TEMP_0, 1
	releaseall
	end

Rosalhoehle_Movement_RunUpLook:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_in_place_faster_left
	delay_16
	walk_in_place_faster_right
	delay_16
	step_end

Rosalhoehle_Text_PlayerBlockedStairs:
	.string "{COLOR PLAYER_CLR}{PLAYER}: Hm… Beide Treppen sind mit\n"
	.string "Steinen umstellt. Da komme ich erstmal\l"
	.string "nicht weiter.\p"
	.string "Merkwürdig…{COLOR WHITE}$"

Rosalhoehle_EventScript_TriggerRocketTracks::
	lockall
	applymovement LOCALID_PLAYER, Common_Movement_ExclamationMark
	playse SE_PIN
	waitmovement 0
	delay 16
	applymovement LOCALID_PLAYER, Rosalhoehle_Movement_RunUpLookRight
	waitmovement 0
	msgbox Rosalhoehle_Text_PlayerRocketTracks, MSGBOX_DEFAULT
	setflag FLAG_ROSAL_ROCKET_SPUREN_GESEHEN
	setvar VAR_TEMP_0, 1
	releaseall
	end

Rosalhoehle_Movement_RunUpLookRight:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_in_place_faster_right
	delay_16
	step_end

Rosalhoehle_Text_PlayerRocketTracks:
	.string "{COLOR PLAYER_CLR}{PLAYER}: Hm? Die Steine vor der\n"
	.string "rechten Leiter wurden weggeräumt!\p"
	.string "Überall Bohrstaub… und hier hängt\n"
	.string "ein Stück Stoff mit einem roten “R”.\p"
	.string "Team ROCKET? Hier in ROSALTSTADT?\n"
	.string "Ich sollte mir das ansehen!{COLOR WHITE}$"
