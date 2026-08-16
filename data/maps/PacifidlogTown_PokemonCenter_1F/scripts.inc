PacifidlogTown_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PacifidlogTown_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

PacifidlogTown_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_PACIFIDLOG_TOWN
	end

PacifidlogTown_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_PACIFIDLOG_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

PacifidlogTown_PokemonCenter_1F_EventScript_Girl::
	msgbox PacifidlogTown_PokemonCenter_1F_Text_WhatColorTrainerCard, MSGBOX_NPC
	end

PacifidlogTown_PokemonCenter_1F_EventScript_Woman::
	msgbox PacifidlogTown_PokemonCenter_1F_Text_OnColonyOfCorsola, MSGBOX_NPC
	end

PacifidlogTown_PokemonCenter_1F_EventScript_OldMan::
	msgbox PacifidlogTown_PokemonCenter_1F_Text_AncestorsLivedOnBoats, MSGBOX_NPC
	end

PacifidlogTown_PokemonCenter_1F_Text_WhatColorTrainerCard:
	.string "Ey, welche Farbe hat dein TRAINERPASS?\p"
	.string "Meiner ist aus Kupfer. Ziemlich\n"
	.string "räudiger Flex, aber was soll's.$"

PacifidlogTown_PokemonCenter_1F_Text_OnColonyOfCorsola:
	.string "Ganz ehrlich, FLOßBRUNN schwimmt auf\n"
	.string "einem fetten Haufen von CORASONN.\p"
	.string "Wenn ich dir den kranken Scheiß jetzt\n"
	.string "erzähle, kaufst du mir das ab?$"

PacifidlogTown_PokemonCenter_1F_Text_AncestorsLivedOnBoats:
	.string "Angeblich sind die Urahnen der Leute\n"
	.string "hier in FLOßBRUNN auf Booten geboren,\l"
	.string "haben da gelebt und sind da verreckt.\p"
	.string "Einfach das komplette Leben auf'm\n"
	.string "Wasser verschwendet, nur weil sie auf\l"
	.string "der Jagd nach irgendeinem Scheiß waren.$"

