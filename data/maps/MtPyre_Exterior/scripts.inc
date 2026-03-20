MtPyre_Exterior_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MtPyre_Exterior_OnTransition
	.byte 0

MtPyre_Exterior_OnTransition:
	call MtPyre_Exterior_EventScript_CheckEnterFromSummit
	end

MtPyre_Exterior_EventScript_CheckEnterFromSummit::
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	goto_if_lt VAR_TEMP_1, 12, MtPyre_Exterior_EventScript_EnterFromSummit
	return

MtPyre_Exterior_EventScript_EnterFromSummit::
	setweather WEATHER_FOG_HORIZONTAL
	return

MtPyre_Exterior_EventScript_FogTrigger::
	setweather WEATHER_FOG_HORIZONTAL
	doweather
	end

MtPyre_Exterior_EventScript_SunTrigger::
	setweather WEATHER_SUNNY
	doweather
	end

MtPyre_Exterior_EventScript_Fynx::
	specialvar VAR_RESULT, IsWildRandomizerEnabled
	goto_if_eq VAR_RESULT, TRUE, MtPyre_Exterior_EventScript_Fynx_RandomizerText
	msgbox MtPyre_Exterior_Text_Fynx, MSGBOX_NPC
	end

MtPyre_Exterior_EventScript_Fynx_RandomizerText::
	msgbox MtPyre_Exterior_Text_FynxRandomizer, MSGBOX_NPC
	end

MtPyre_Exterior_Text_Fynx:
	.string "Tipp:\p"
	.string "Auf dieser Route versteckt sich ein\n"
	.string "Starter aus der 6. Generation mit\l"
	.string "einer Spawnrate von 1%!\p"
	.string "Welches es ist, musst du selbst\n"
	.string "herausfinden :D !$"

MtPyre_Exterior_Text_FynxRandomizer:
	.string "Tipp:\p"
	.string "Wild-Randomizer ist aktiv.\n"
	.string "Der feste 1%-Starter-Hinweis\l"
	.string "gilt deshalb hier nicht.\p"
	.string "Die Wild-Spawns werden über deinen\n"
	.string "Seed neu gemappt!$"
