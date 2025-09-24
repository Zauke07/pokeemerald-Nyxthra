Route111_02_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, Route111_02_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, Route111_02_OnTransition
	.byte 0

Route111_02_OnResume:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, Route111_02_EventScript_TryRemoveLandorus
	end

Route111_02_EventScript_TryRemoveLandorus::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject VAR_LAST_TALKED
	setweather WEATHER_NONE
	doweather
	return

Route111_02_OnTransition:
	call_if_unset FLAG_DEFEATED_LANDORUS, Route111_02_EventScript_ShowLandorusAndWeather
	end

Route111_02_EventScript_ShowLandorusAndWeather::
	clearflag FLAG_HIDE_ROUTE_111_02_LANDORUS
	setweather WEATHER_SANDSTORM
	doweather
	return

Route111_02_EventScript_Landorus::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_LANDORUS, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	seteventmon SPECIES_LANDORUS, 30
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, Route111_02_EventScript_DefeatedLandorus
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, Route111_02_EventScript_RanFromLandorus
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, Route111_02_EventScript_RanFromLandorus
	setflag FLAG_DEFEATED_LANDORUS
	release
	end

Route111_02_EventScript_DefeatedLandorus::
	setflag FLAG_DEFEATED_LANDORUS
	setweather WEATHER_NONE
	doweather
	goto Common_EventScript_RemoveStaticPokemon
	end

Route111_02_EventScript_RanFromLandorus::
	setvar VAR_0x8004, SPECIES_LANDORUS
	goto Common_EventScript_LegendaryFlewAway
	end

Route111_02_EventScript_TriggerBlockedPath::
	lockall
	goto_if_eq VAR_TEMP_0, 1, Common_EventScript_NopReturn
	applymovement LOCALID_PLAYER, Common_Movement_QuestionMark
	playse SE_PIN
	waitmovement 0
	msgbox Route111_02_Text_PlayerBlockedPath, MSGBOX_DEFAULT
	setvar VAR_TEMP_0, 1
	releaseall
	end

Route111_02_Text_PlayerBlockedPath:
	.string "{COLOR RED}{PLAYER}: Hm… Hier gehts erstmal\n"
	.string "nicht weiter.\p"
	.string "Ich frage mich, was in den drei Höhlen\n"
	.string "drin sein könnte…{COLOR WHITE}$"

Route111_02_Eventscript_Hiker::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_LANDORUS, Route111_02_EventScript_Hiker_After
	msgbox Route111_02_Text_Hiker_nowildpokemon, MSGBOX_DEFAULT
	release
	end

Route111_02_EventScript_Hiker_After::
	msgbox Route111_02_Text_Hiker_after_storm, MSGBOX_DEFAULT
	release
	end

Route111_02_Text_Hiker_nowildpokemon:
	.string "Hier gibt es keine wilden Pokémon.\n"
	.string "Das ist sehr merkwürdig…\p"
	.string "Ich frage mich, was hier los ist…\n"
	.string "Ob es mit den Höhlen zu tun hat?$"

Route111_02_Text_Hiker_after_storm:
	.string "Unglaublich! Der Sandsturm hat sich\n"
	.string "einfach aufgelöst!\p"
	.string "Es ist, als wäre eine enorme Kraft\n"
	.string "plötzlich verschwunden…\l"
	.string "Wirklich merkwürdig, oder?$"

