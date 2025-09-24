OldaleTown_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, OldaleTown_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

OldaleTown_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_OLDALE_TOWN
	call Common_EventScript_UpdateBrineyLocation
	end

OldaleTown_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_OLDALE_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

OldaleTown_PokemonCenter_1F_EventScript_Gentleman::
	msgbox OldaleTown_PokemonCenter_1F_Text_TrainersCanUsePC, MSGBOX_NPC
	end

OldaleTown_PokemonCenter_1F_EventScript_Boy::
	msgbox OldaleTown_PokemonCenter_1F_Text_PokemonCentersAreGreat, MSGBOX_NPC
	end

OldaleTown_PokemonCenter_1F_EventScript_Girl::
	lock
	faceplayer
	goto_if_set FLAG_SYS_POKEDEX_GET, OldaleTown_PokemonCenter_1F_EventScript_WirelessClubAvailable
	msgbox OldaleTown_PokemonCenter_1F_Text_WirelessClubNotAvailable, MSGBOX_DEFAULT
	release
	end

OldaleTown_PokemonCenter_1F_EventScript_WirelessClubAvailable::
	msgbox OldaleTown_PokemonCenter_1F_Text_TradedInWirelessClub, MSGBOX_DEFAULT
	release
	end

OldaleTown_PokemonCenter_1F_Text_TrainersCanUsePC:
	.string "Der PC in der Ecke ist für POKéMON-\n"
	.string "TRAINER gedacht.\p"
	.string "Man sagt, manche Trainer finden darin\n"
	.string "mehr als nur Boxen…$"

OldaleTown_PokemonCenter_1F_Text_PokemonCentersAreGreat:
	.string "POKéMON-CENTER sind wahre Wunderwerke!\p"
	.string "Kostenlos heilen, speichern, durchatmen…\n"
	.string "Du wirst sie auf deiner Reise brauchen.$"

OldaleTown_PokemonCenter_1F_Text_WirelessClubNotAvailable:
	.string "Der DRAHTLOSKLUB im zweiten Stock\n"
	.string "ist noch nicht ganz fertig…\p"
	.string "Sie sagen, das neue System könnte sogar\n"
	.string "seltene Formen sichtbar machen.$"

OldaleTown_PokemonCenter_1F_Text_TradedInWirelessClub:
	.string "Ich habe im DRAHTLOSKLUB schon ein\n"
	.string "POKéMON getauscht!\p"
	.string "Es hieß, manche Formen zeigen sich\n"
	.string "nur nach einem Tausch.$"
