LilycoveCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LilycoveCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

LilycoveCity_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_LILYCOVE_CITY
	goto LilycoveCity_PokemonCenter_1F_EventScript_SetLilycoveLadyGfx
	end

@ SetLilycoveLadyGfx returns TRUE if its the Contest Lady
LilycoveCity_PokemonCenter_1F_EventScript_SetLilycoveLadyGfx::
	special SetLilycoveLadyGfx
	goto_if_eq VAR_RESULT, FALSE, LilycoveCity_PokemonCenter_1F_EventScript_HideContestLadyMon
	goto_if_eq VAR_RESULT, TRUE, LilycoveCity_PokemonCenter_1F_EventScript_ShowContestLadyMon
	end

LilycoveCity_PokemonCenter_1F_EventScript_HideContestLadyMon::
	setflag FLAG_HIDE_LILYCOVE_POKEMON_CENTER_CONTEST_LADY_MON
	end

LilycoveCity_PokemonCenter_1F_EventScript_ShowContestLadyMon::
	clearflag FLAG_HIDE_LILYCOVE_POKEMON_CENTER_CONTEST_LADY_MON
	end

LilycoveCity_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_LILYCOVE_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

LilycoveCity_PokemonCenter_1F_EventScript_Boy::
	msgbox LilycoveCity_PokemonCenter_1F_Text_HowManyKindsOfPokemon, MSGBOX_NPC
	end

LilycoveCity_PokemonCenter_1F_EventScript_Maniac::
	lock
	faceplayer
	goto_if_set FLAG_BADGE07_GET, LilycoveCity_PokemonCenter_1F_EventScript_ManiacBadTeamGone
	msgbox LilycoveCity_PokemonCenter_1F_Text_HeardAboutRottenScoundrels, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonCenter_1F_EventScript_ManiacBadTeamGone::
	msgbox LilycoveCity_PokemonCenter_1F_Text_HaventSeenRottenScoundrels, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonCenter_1F_Text_HowManyKindsOfPokemon::
	.string "Ich frag mich, wie viele Arten von\n"
	.string "POKéMON es auf dieser Welt gibt.\p"
	.string "Wär schon geil, übers Meer zu schippern\n"
	.string "und Leuten, die weit weg wohnen, ihren\l"
	.string "Kram beim Tauschen abzuluchsen.$"

LilycoveCity_PokemonCenter_1F_Text_HeardAboutRottenScoundrels::
	.string "Ich hab von so 'nem asozialen Pack\n"
	.string "gehört, das POKéMON klaut und sogar\l"
	.string "METEORITEN abzieht.\p"
	.string "Echt unter aller Sau, was hier abgeht!$"

LilycoveCity_PokemonCenter_1F_Text_HaventSeenRottenScoundrels::
	.string "Dieses kriminelle Gesindel, das Viecher\n"
	.string "klaut und METEORITEN einsackt……\p"
	.string "In letzter Zeit hab ich die Visagen hier\n"
	.string "nicht mehr gesehen. Wurde auch Zeit!$"

