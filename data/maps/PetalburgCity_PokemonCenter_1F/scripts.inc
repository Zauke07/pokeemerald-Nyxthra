PetalburgCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PetalburgCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

PetalburgCity_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_PETALBURG_CITY
	call Common_EventScript_UpdateBrineyLocation
	end

PetalburgCity_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_PETALBURG_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

PetalburgCity_PokemonCenter_1F_EventScript_FatMan::
	msgbox PetalburgCity_PokemonCenter_1F_Text_PCStorageSystem, MSGBOX_NPC
	end

PetalburgCity_PokemonCenter_1F_EventScript_Youngster::
	msgbox PetalburgCity_PokemonCenter_1F_Text_OranBerryRegainedHP, MSGBOX_NPC
	end

PetalburgCity_PokemonCenter_1F_EventScript_Woman::
	lock
	faceplayer
	msgbox PetalburgCity_PokemonCenter_1F_Text_ManyTypesOfPokemon, MSGBOX_DEFAULT
	specialvar VAR_RESULT, IsStarterInParty
	goto_if_eq VAR_RESULT, TRUE, PetalburgCity_PokemonCenter_1F_EventScript_SayStarterTypeInfo
	release
	end

PetalburgCity_PokemonCenter_1F_EventScript_SayStarterTypeInfo::
	call_if_eq VAR_STARTER_MON, 0, PetalburgCity_PokemonCenter_1F_EventScript_SayTreeckoType
	call_if_eq VAR_STARTER_MON, 1, PetalburgCity_PokemonCenter_1F_EventScript_SayTorchicType
	call_if_eq VAR_STARTER_MON, 2, PetalburgCity_PokemonCenter_1F_EventScript_SayMudkipType
	release
	end

PetalburgCity_PokemonCenter_1F_EventScript_SayTreeckoType::
	msgbox PetalburgCity_PokemonCenter_1F_Text_TreeckoIsGrassType, MSGBOX_DEFAULT
	return

PetalburgCity_PokemonCenter_1F_EventScript_SayTorchicType::
	msgbox PetalburgCity_PokemonCenter_1F_Text_TorchicIsFireType, MSGBOX_DEFAULT
	return

PetalburgCity_PokemonCenter_1F_EventScript_SayMudkipType::
	msgbox PetalburgCity_PokemonCenter_1F_Text_MudkipIsWaterType, MSGBOX_DEFAULT
	return

PetalburgCity_PokemonCenter_1F_Text_PCStorageSystem:
	.string "Pokémon-Lagerung per PC…\n"
	.string "Irgendwer hat das mal programmiert.\p"
	.string "Der Typ muss ein Hexer sein.\n"
	.string "Oder einfach komplett arbeitslos.$"

PetalburgCity_PokemonCenter_1F_Text_OranBerryRegainedHP:
	.string "Mein Pokémon hat 'ne Sinelbeere gefressen -\n"
	.string "zack, HP voll. Einfach magisch.\l"
	.string "Ich hab dann auch eine gegessen.\n"
	.string "War… enttäuschend.$"

PetalburgCity_PokemonCenter_1F_Text_ManyTypesOfPokemon:
	.string "Es gibt so viele Pokémon-Typen, ey…\p"
	.string "Feuer, Wasser, Psycho, Drache,\n"
	.string "Feenstaub, Matsch, irgendwas.\p"
	.string "Ich google die Schwächen eh jedes Mal.\n"
	.string "Merkt sich doch kein Mensch.$"


PetalburgCity_PokemonCenter_1F_Text_TreeckoIsGrassType:
	.string "Dein Geckarbor ist vom Typ Pflanze.\p"
	.string "Stark gegen Wasser und Boden -\n"
	.string "außer du vergisst, es zu trainieren.\p"
	.string "Aber gegen Feuer? Tja… RIP.$"

PetalburgCity_PokemonCenter_1F_Text_TorchicIsFireType:
	.string "Flemmli = Feuer-Typ.\p"
	.string "Heiß. Effektiv gegen Pflanzen und Käfer.\p"
	.string "Aber wehe, es sieht Wasser -\n"
	.string "dann geht’s baden. Im wahrsten Sinne.$"

PetalburgCity_PokemonCenter_1F_Text_MudkipIsWaterType:
	.string "Hydropi ist ein Wasser-Typ.\p"
	.string "Gut gegen Feuer, schlecht gegen Strom.\n"
	.string "Also bloß kein Blitzableiter spielen.$"



