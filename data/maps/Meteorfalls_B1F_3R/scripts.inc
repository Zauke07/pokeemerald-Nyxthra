Meteorfalls_B1F_3R_MapScripts::
	.byte 0

Meteorfalls_B1F_3R_EventScript_TriggerColdSpot::
	lockall
	msgbox Meteorfalls_B1F_3R_Text_PlayerColdSpot, MSGBOX_DEFAULT
	setvar VAR_METEORFALLS_B1F_3R_COLD_SPOT_TRIGGERED, 1
	releaseall
	end

Meteorfalls_B1F_3R_Text_PlayerColdSpot:
	.string "{COLOR PLAYER_CLR}{PLAYER}: Puuh, es wird plötzlich so\n"
	.string "kalt hier…{COLOR WHITE}$"
