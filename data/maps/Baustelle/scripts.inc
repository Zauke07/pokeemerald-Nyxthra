Baustelle_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Baustelle_OnTransition
	.byte 0

Baustelle_OnTransition:
	end

Baustelle_EventScript_TriggerBlockedStairs::
	lockall
	applymovement LOCALID_PLAYER, Common_Movement_QuestionMark
	playse SE_PIN	   @ Soundeffekt für das Ausrufezeichen
	waitmovement 0
	delay 16					   @ kurze Pause (~0.25 Sekunden)
	delay 16					   @ noch eine kleine Pause für sichtbare Reaktion
	applymovement LOCALID_PLAYER, Baustelle_Movement_RunUpLook
	waitmovement 0
	msgbox Baustelle_Text_PlayerBlockedStairs, MSGBOX_DEFAULT
	setvar VAR_TEMP_0, 1
	releaseall
	end

Baustelle_Movement_RunUpLook:
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

Baustelle_Text_PlayerBlockedStairs:
	.string "{COLOR RED}{PLAYER}: Hm… Beide Treppen sind mit\n"
	.string "Steinen umstellt. Da komme ich erstmal\l"
	.string "nicht weiter.\p"
	.string "Merkwürdig…{COLOR WHITE}$"
