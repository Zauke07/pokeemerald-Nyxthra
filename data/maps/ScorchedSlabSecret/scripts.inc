ScorchedSlabSecret_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, ScorchedSlabSecret_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, ScorchedSlabSecret_OnTransition
	.byte 0

ScorchedSlabSecret_OnTransition:
	call_if_set   FLAG_CAUGHT_UXIE, ScorchedSlabSecret_EventScript_HideUxie
	call_if_unset FLAG_CAUGHT_UXIE, ScorchedSlabSecret_EventScript_TryShowUxie
	end

ScorchedSlabSecret_OnResume:
	call_if_set   FLAG_SYS_CTRL_OBJ_DELETE, ScorchedSlabSecret_EventScript_TryRemoveUxie
	call_if_set   FLAG_CAUGHT_UXIE, ScorchedSlabSecret_EventScript_HideUxie
	end

ScorchedSlabSecret_EventScript_HideUxie::
	setflag FLAG_HIDE_SCORCHED_SLAB_SECRET_UXIE
	return

@ Nyxthra story: reappears on every revisit until actually caught - matches
@ Mewtwo Statue's behavior (Route119_Mistery), which never permanently hides
@ on a mere defeat/flee either, only on FLAG_CAUGHT_MEWTWO_STATUE.
ScorchedSlabSecret_EventScript_TryShowUxie::
	clearflag FLAG_HIDE_SCORCHED_SLAB_SECRET_UXIE
	return

ScorchedSlabSecret_EventScript_TryRemoveUxie::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject 1
	return

ScorchedSlabSecret_EventScript_Uxie::
	lockall
	faceplayer
	waitse
	setvar VAR_LAST_TALKED, 1
	seteventmon SPECIES_UXIE, 30
	playmoncry VAR_0x8004, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, ScorchedSlabSecret_EventScript_DefeatedUxie
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, ScorchedSlabSecret_EventScript_RanFromUxie
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, ScorchedSlabSecret_EventScript_RanFromUxie
	setflag FLAG_CAUGHT_UXIE
	setflag FLAG_HIDE_SCORCHED_SLAB_SECRET_UXIE
	goto Common_EventScript_RemoveStaticPokemon
	end

ScorchedSlabSecret_EventScript_DefeatedUxie::
	setflag FLAG_DEFEATED_UXIE
	goto Common_EventScript_LegendaryFlewAway
	end

ScorchedSlabSecret_EventScript_RanFromUxie::
	goto Common_EventScript_LegendaryFlewAway
	end

ScorchedSlabSecret_EventScript_Victor::
	lock
	faceplayer
	msgbox ScorchedSlabSecret_Text_VictorExplainsUxie, MSGBOX_DEFAULT
	release
	end

ScorchedSlabSecret_Text_VictorExplainsUxie:
	.string "VICTOR: Hey!\n"
	.string "Eigentlich sollte hier SELFE warten.\p"
	.string "Aber das führt momentan zu schwer-\n"
	.string "wiegenden Fehlern im Code.\p"
	.string "Die Musik läuft zwar schon, aber das\n"
	.string "Pokémon ist aktuell nicht als Objekt\l"
	.string "im Spiel vorhanden.\p"
	.string "Es wird aber bald nachgereicht!\p"
	.string "Wenn du zurückkommst und ich nicht\n"
	.string "mehr hier bin, wirst du SELFE an\l"
	.string "meiner Stelle finden.$"
