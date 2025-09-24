RustboroCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RustboroCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

RustboroCity_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_RUSTBORO_CITY
	call Common_EventScript_UpdateBrineyLocation
	end

RustboroCity_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_RUSTBORO_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

RustboroCity_PokemonCenter_1F_EventScript_Man::
	msgbox RustboroCity_PokemonCenter_1F_Text_PokemonHavePersonalities, MSGBOX_NPC
	end

RustboroCity_PokemonCenter_1F_EventScript_Boy::
	msgbox RustboroCity_PokemonCenter_1F_Text_MaleAndFemalePokemon, MSGBOX_NPC
	end

RustboroCity_PokemonCenter_1F_EventScript_Girl::
	msgbox RustboroCity_PokemonCenter_1F_Text_HMCutNextDoor, MSGBOX_NPC
	end

RustboroCity_PokemonCenter_1F_Text_PokemonHavePersonalities:
    .string "Mein POKéMON ist NAIV, das von meinem\n"
    .string "Kumpel total HYPERAKTIV.\p"
    .string "Wie soll man da ne ernsthafte\n"
    .string "STRATEGIE aufbauen, Bruder?$"

RustboroCity_PokemonCenter_1F_Text_MaleAndFemalePokemon:
    .string "Männlich, weiblich... bei POKéMON\n"
    .string "merkt man eh kaum nen Unterschied.\p"
    .string "Außer bei KUSSILLA. Das schaut dich\n"
    .string "an, und du fühlst dich\l"
    .string "irgendwie schmutzig.$"

RustboroCity_PokemonCenter_1F_Text_HMCutNextDoor:
    .string "Der Typ nebenan hat mir ne VM geschenkt.\p"
    .string "Jetzt zersägt mein GECKARBOR die halbe\n"
    .string "Nachbarschaft. Keine BÜSCHE mehr sicher.$"
