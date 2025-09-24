SecretPetalburgWoods_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, SecretPetalburgWoods_OnLoad
	.byte 0

SecretPetalburgWoods_OnLoad:
	goto_if_set FLAG_HOUND_EVENT_FINISHED, SecretPetalburgWoods_EventScript_OpenHiddenEntrance
	goto SecretPetalburgWoods_EventScript_CloseHiddenEntrance


SecretPetalburgWoods_EventScript_OpenHiddenEntrance::
	setmetatile 4, 15, METATILE_General_CaveEntrance_Top, TRUE
	setmetatile 4, 16, METATILE_General_CaveEntrance_Bottom, TRUE
	return

SecretPetalburgWoods_EventScript_CloseHiddenEntrance::
	setmetatile 4, 15, METATILE_General_RockWall_RockBase, TRUE
	setmetatile 4, 16, METATILE_General_RockWall_RockBase, TRUE
	return
