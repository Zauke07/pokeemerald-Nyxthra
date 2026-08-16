PacifidlogTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PacifidlogTown_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, PacifidlogTown_OnResume
	.byte 0

PacifidlogTown_OnTransition:
	setflag FLAG_VISITED_PACIFIDLOG_TOWN
	end

PacifidlogTown_OnResume:
	setstepcallback STEP_CB_PACIFIDLOG_BRIDGE
	end

PacifidlogTown_EventScript_NinjaBoy::
	msgbox PacifidlogTown_Text_NeatHousesOnWater, MSGBOX_NPC
	end

PacifidlogTown_EventScript_Girl::
	msgbox PacifidlogTown_Text_FastRunningCurrent, MSGBOX_NPC
	end

PacifidlogTown_EventScript_Fisherman::
	msgbox PacifidlogTown_Text_SkyPillarTooScary, MSGBOX_NPC
	end

PacifidlogTown_EventScript_TownSign::
	msgbox PacifidlogTown_Text_TownSign, MSGBOX_SIGN
	end

PacifidlogTown_Text_FastRunningCurrent:
	.string "Das Wasser zwischen Floßbrunn und\n"
	.string "GRAPHITPORT CITY hat 'ne brutale\l"
	.string "Strömung.\p"
	.string "Einmal falsch gesurft und du wachst in\n"
	.string "irgendeinem scheiß Niemandsland auf.$"

PacifidlogTown_Text_NeatHousesOnWater:
	.string "Schon mal gecheckt, wie krass das ist?\n"
	.string "Die Buden chillen einfach auf dem Wasser!\p"
	.string "Bin hier geboren. Wild, oder?$"

PacifidlogTown_Text_SkyPillarTooScary:
	.string "Der HIMMELSTURM?\p"
	.string "… Ach, du meinst diesen fetten Turm\n"
	.string "da hinten.\p"
	.string "Kein Plan, wer da freiwillig raufklettert.\n"
	.string "Ich scheiß mir da oben\l"
	.string "original in die Hose.\p"
	.string "Auf Meereshöhe hier in FLOßBRUNN zu\n"
	.string "chillen, bockt eh viel mehr.$"

PacifidlogTown_Text_TownSign:
	.string "FLOßBRUNN\p"
	.string "“Wo die Morgensonne entspannt aufs\n"
	.string "Wasser ballert.”$"



