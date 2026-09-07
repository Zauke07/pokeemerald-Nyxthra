MeteorFalls_B1F_4R_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, MeteorFalls_B1F_4R_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, MeteorFalls_B1F_4R_OnTransition
	.byte 0

MeteorFalls_B1F_4R_OnResume:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, MeteorFalls_B1F_4R_EventScript_TryRemoveArticuno
	call_if_unset FLAG_CAUGHT_ARTICUNO, MeteorFalls_B1F_4R_EventScript_ShowArticuno
	end

MeteorFalls_B1F_4R_EventScript_TryRemoveArticuno::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject LOCALID_METEOR_ARTICUNO
	return

@ Nyxthra story: reappears on every revisit until actually caught - see
@ FLAG_CAUGHT_ARTICUNO, kept separate from FLAG_DEFEATED_METEOR_FALLS_ARTICUNO
@ (which used to gate this too, meaning a mere defeat/flee hid it forever).
MeteorFalls_B1F_4R_OnTransition:
	call_if_unset FLAG_CAUGHT_ARTICUNO, MeteorFalls_B1F_4R_EventScript_ShowArticuno
	end

MeteorFalls_B1F_4R_EventScript_ShowArticuno::
	clearflag FLAG_HIDE_METEOR_FALLS_B1F_4R_ARTICUNO
	showobject LOCALID_METEOR_ARTICUNO
	return

MeteorFalls_B1F_4R_EventScript_Articuno::
	lock
	faceplayer
	waitse
	setvar VAR_LAST_TALKED, LOCALID_METEOR_ARTICUNO
	seteventmon SPECIES_ARTICUNO, 30
	playmoncry VAR_0x8004, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, MeteorFalls_B1F_4R_EventScript_DefeatedArticuno
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, MeteorFalls_B1F_4R_EventScript_RanFromArticuno
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, MeteorFalls_B1F_4R_EventScript_RanFromArticuno
	setflag FLAG_CAUGHT_ARTICUNO
	setflag FLAG_HIDE_METEOR_FALLS_B1F_4R_ARTICUNO
	goto Common_EventScript_RemoveStaticPokemon
	end

@ Nyxthra story: mere defeat (no catch) - flies away and can be fought
@ again on a revisit, matching Lavados/Celebi/Uxie/Mewtwo Statue. Also
@ switched to LegendaryFlewAway (shows the "flew away" text like those do)
@ instead of the silent RemoveStaticPokemon a real catch uses.
MeteorFalls_B1F_4R_EventScript_DefeatedArticuno::
	setflag FLAG_DEFEATED_METEOR_FALLS_ARTICUNO
	goto Common_EventScript_LegendaryFlewAway
	end

MeteorFalls_B1F_4R_EventScript_RanFromArticuno::
	goto Common_EventScript_LegendaryFlewAway
	end
