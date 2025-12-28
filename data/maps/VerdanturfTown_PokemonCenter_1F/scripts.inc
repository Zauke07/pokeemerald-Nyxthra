VerdanturfTown_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, VerdanturfTown_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

VerdanturfTown_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_VERDANTURF_TOWN
	call Common_EventScript_UpdateBrineyLocation
	end

VerdanturfTown_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_VERDANTURF_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

VerdanturfTown_PokemonCenter_1F_EventScript_Gentleman::
	msgbox VerdanturfTown_PokemonCenter_1F_Text_FaithInYourPokemon, MSGBOX_NPC
	end

VerdanturfTown_PokemonCenter_1F_EventScript_ExpertM::
	msgbox VerdanturfTown_PokemonCenter_1F_Text_VisitForBattleTent, MSGBOX_NPC
	end

VerdanturfTown_PokemonCenter_1F_Text_FaithInYourPokemon::
	.string "Du willst dich TRAINER nennen? Dass ich\n"
	.string "nicht lache, du Witzfigur!\p"
	.string "Wer nicht die Eier hat, seine Viecher\n"
	.string "bis zum Äußersten zu treiben, wird\l"
	.string "hier gnadenlos im Dreck landen.\p"
	.string "Glaubst du etwa, Siege fallen vom Himmel?\n"
	.string "Nur wer seine POKéMON hart rannimmt,\l"
	.string "darf am Ende dumm grinsen.$"

VerdanturfTown_PokemonCenter_1F_Text_VisitForBattleTent::
	.string "Der einzige Grund, warum man sich\n"
	.string "dieses Kaff hier überhaupt antut…\p"
	.string "ist das KAMPFCAMP. Logisch, oder?\p"
	.string "Oder hast du dich verlaufen, weil du\n"
	.string "die Karte nicht lesen kannst?$"


