@ ============================================================
@ Challenge House B1F – Protagonisten-Ansturm
@ 18 Protagonisten (Gen1→Gen9), in Reihenfolge besiegen.
@ Niederlage → Fortschritt auf 0 zurück.
@ ============================================================

#define LOCALID_CHALLENGE_OPPONENT 1

SootopolisCity_MysteryEventsHouse_B1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SootopolisCity_MysteryEventsHouse_B1F_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SootopolisCity_MysteryEventsHouse_B1F_OnFrame
	.byte 0

@ ---- ON_TRANSITION ----
SootopolisCity_MysteryEventsHouse_B1F_OnTransition:
	goto_if_unset FLAG_SYS_GAME_CLEAR, SootopolisCity_MysteryEventsHouse_B1F_OnTransition_End
	call_if_set FLAG_CHALLENGE_HOUSE_BATTLE_ACTIVE, SootopolisCity_MysteryEventsHouse_B1F_EventScript_ResetOnLoss
	call SootopolisCity_MysteryEventsHouse_B1F_EventScript_SetCurrentGfx
	setflag FLAG_CHALLENGE_OPPONENT_HIDDEN
SootopolisCity_MysteryEventsHouse_B1F_OnTransition_End:
	end

SootopolisCity_MysteryEventsHouse_B1F_EventScript_ResetOnLoss::
	clearflag FLAG_CHALLENGE_HOUSE_BATTLE_ACTIVE
	setvar VAR_PROTAGONIST_CHALLENGE_PROGRESS, 0
	return

@ ---- ON_FRAME ----
SootopolisCity_MysteryEventsHouse_B1F_OnFrame:
	map_script_2 VAR_TEMP_0, 0, SootopolisCity_MysteryEventsHouse_B1F_EventScript_StartChallenge
	.2byte 0

@ ---- HAUPTEINSTIEGSPUNKT ----
SootopolisCity_MysteryEventsHouse_B1F_EventScript_StartChallenge::
	setvar VAR_TEMP_0, 1
	goto_if_unset FLAG_SYS_GAME_CLEAR, SootopolisCity_MysteryEventsHouse_B1F_EventScript_NotChamp
	goto_if_eq VAR_PROTAGONIST_CHALLENGE_PROGRESS, 18, SootopolisCity_MysteryEventsHouse_B1F_EventScript_AllBeatenOnEntry
	lockall
	applymovement LOCALID_PLAYER, SootopolisCity_MysteryEventsHouse_B1F_Movement_PlayerEnter
	waitmovement 0

SootopolisCity_MysteryEventsHouse_B1F_EventScript_BattleLoop::
	call SootopolisCity_MysteryEventsHouse_B1F_EventScript_SpawnProtagonist
	call SootopolisCity_MysteryEventsHouse_B1F_EventScript_GreetPlayer
	setflag FLAG_CHALLENGE_HOUSE_BATTLE_ACTIVE
	call SootopolisCity_MysteryEventsHouse_B1F_EventScript_DoBattle
	clearflag FLAG_CHALLENGE_HOUSE_BATTLE_ACTIVE
	call SootopolisCity_MysteryEventsHouse_B1F_EventScript_ProtagonistExit
	special HealPlayerParty
	special LoadPlayerParty
	addvar VAR_PROTAGONIST_CHALLENGE_PROGRESS, 1
	goto_if_eq VAR_PROTAGONIST_CHALLENGE_PROGRESS, 18, SootopolisCity_MysteryEventsHouse_B1F_EventScript_AllBeaten
	call SootopolisCity_MysteryEventsHouse_B1F_EventScript_SetCurrentGfx
	goto SootopolisCity_MysteryEventsHouse_B1F_EventScript_BattleLoop

@ ---- PROTAGONIST ERSCHEINEN ----
SootopolisCity_MysteryEventsHouse_B1F_EventScript_SpawnProtagonist::
	setflag FLAG_CHALLENGE_OPPONENT_HIDDEN
	call SootopolisCity_MysteryEventsHouse_B1F_EventScript_SetCurrentGfx
	setobjectxyperm LOCALID_CHALLENGE_OPPONENT, 3, 1
	clearflag FLAG_CHALLENGE_OPPONENT_HIDDEN
	applymovement LOCALID_CHALLENGE_OPPONENT, SootopolisCity_MysteryEventsHouse_B1F_Movement_ProtagonistEnter
	waitmovement 0
	return

@ ---- PROTAGONIST ABGANG ----
SootopolisCity_MysteryEventsHouse_B1F_EventScript_ProtagonistExit::
	applymovement LOCALID_CHALLENGE_OPPONENT, SootopolisCity_MysteryEventsHouse_B1F_Movement_ProtagonistExit
	waitmovement 0
	setflag FLAG_CHALLENGE_OPPONENT_HIDDEN
	playse SE_EXIT
	return

@ ---- GFX-DISPATCH ----
SootopolisCity_MysteryEventsHouse_B1F_EventScript_SetCurrentGfx::
	call_if_eq VAR_PROTAGONIST_CHALLENGE_PROGRESS, 0,  SootopolisCity_MysteryEventsHouse_B1F_EventScript_SetGfx_Red
	call_if_eq VAR_PROTAGONIST_CHALLENGE_PROGRESS, 1,  SootopolisCity_MysteryEventsHouse_B1F_EventScript_SetGfx_Leaf
	call_if_eq VAR_PROTAGONIST_CHALLENGE_PROGRESS, 2,  SootopolisCity_MysteryEventsHouse_B1F_EventScript_SetGfx_Ethan
	call_if_eq VAR_PROTAGONIST_CHALLENGE_PROGRESS, 3,  SootopolisCity_MysteryEventsHouse_B1F_EventScript_SetGfx_Lyra
	call_if_eq VAR_PROTAGONIST_CHALLENGE_PROGRESS, 4,  SootopolisCity_MysteryEventsHouse_B1F_EventScript_SetGfx_Brendan
	call_if_eq VAR_PROTAGONIST_CHALLENGE_PROGRESS, 5,  SootopolisCity_MysteryEventsHouse_B1F_EventScript_SetGfx_May
	call_if_eq VAR_PROTAGONIST_CHALLENGE_PROGRESS, 6,  SootopolisCity_MysteryEventsHouse_B1F_EventScript_SetGfx_Lucas
	call_if_eq VAR_PROTAGONIST_CHALLENGE_PROGRESS, 7,  SootopolisCity_MysteryEventsHouse_B1F_EventScript_SetGfx_Dawn
	call_if_eq VAR_PROTAGONIST_CHALLENGE_PROGRESS, 8,  SootopolisCity_MysteryEventsHouse_B1F_EventScript_SetGfx_Hilbert
	call_if_eq VAR_PROTAGONIST_CHALLENGE_PROGRESS, 9,  SootopolisCity_MysteryEventsHouse_B1F_EventScript_SetGfx_Hilda
	call_if_eq VAR_PROTAGONIST_CHALLENGE_PROGRESS, 10, SootopolisCity_MysteryEventsHouse_B1F_EventScript_SetGfx_Calem
	call_if_eq VAR_PROTAGONIST_CHALLENGE_PROGRESS, 11, SootopolisCity_MysteryEventsHouse_B1F_EventScript_SetGfx_Serena
	call_if_eq VAR_PROTAGONIST_CHALLENGE_PROGRESS, 12, SootopolisCity_MysteryEventsHouse_B1F_EventScript_SetGfx_Elio
	call_if_eq VAR_PROTAGONIST_CHALLENGE_PROGRESS, 13, SootopolisCity_MysteryEventsHouse_B1F_EventScript_SetGfx_Selene
	call_if_eq VAR_PROTAGONIST_CHALLENGE_PROGRESS, 14, SootopolisCity_MysteryEventsHouse_B1F_EventScript_SetGfx_Victor
	call_if_eq VAR_PROTAGONIST_CHALLENGE_PROGRESS, 15, SootopolisCity_MysteryEventsHouse_B1F_EventScript_SetGfx_Gloria
	call_if_eq VAR_PROTAGONIST_CHALLENGE_PROGRESS, 16, SootopolisCity_MysteryEventsHouse_B1F_EventScript_SetGfx_Florian
	call_if_eq VAR_PROTAGONIST_CHALLENGE_PROGRESS, 17, SootopolisCity_MysteryEventsHouse_B1F_EventScript_SetGfx_Juliana
	return

SootopolisCity_MysteryEventsHouse_B1F_EventScript_SetGfx_Red::
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RED
	return
SootopolisCity_MysteryEventsHouse_B1F_EventScript_SetGfx_Leaf::
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_LEAF
	return
SootopolisCity_MysteryEventsHouse_B1F_EventScript_SetGfx_Ethan::
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_ETHAN
	return
SootopolisCity_MysteryEventsHouse_B1F_EventScript_SetGfx_Lyra::
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_LYRA
	return
SootopolisCity_MysteryEventsHouse_B1F_EventScript_SetGfx_Brendan::
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_BRENDAN_NORMAL
	return
SootopolisCity_MysteryEventsHouse_B1F_EventScript_SetGfx_May::
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_MAY_NORMAL
	return
SootopolisCity_MysteryEventsHouse_B1F_EventScript_SetGfx_Lucas::
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_LUCAS
	return
SootopolisCity_MysteryEventsHouse_B1F_EventScript_SetGfx_Dawn::
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_DAWN
	return
SootopolisCity_MysteryEventsHouse_B1F_EventScript_SetGfx_Hilbert::
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_HILBERT
	return
SootopolisCity_MysteryEventsHouse_B1F_EventScript_SetGfx_Hilda::
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_HILDA
	return
SootopolisCity_MysteryEventsHouse_B1F_EventScript_SetGfx_Calem::
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_CALEM
	return
SootopolisCity_MysteryEventsHouse_B1F_EventScript_SetGfx_Serena::
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_SERENA
	return
SootopolisCity_MysteryEventsHouse_B1F_EventScript_SetGfx_Elio::
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_ELIO
	return
SootopolisCity_MysteryEventsHouse_B1F_EventScript_SetGfx_Selene::
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_SELENE
	return
SootopolisCity_MysteryEventsHouse_B1F_EventScript_SetGfx_Victor::
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_VICTOR
	return
SootopolisCity_MysteryEventsHouse_B1F_EventScript_SetGfx_Gloria::
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_GLORIA
	return
SootopolisCity_MysteryEventsHouse_B1F_EventScript_SetGfx_Florian::
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_FLORIAN
	return
SootopolisCity_MysteryEventsHouse_B1F_EventScript_SetGfx_Juliana::
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_JULIANA
	return

@ ---- BEGRÜSSUNGS-DISPATCH ----
SootopolisCity_MysteryEventsHouse_B1F_EventScript_GreetPlayer::
	call_if_eq VAR_PROTAGONIST_CHALLENGE_PROGRESS, 0,  SootopolisCity_MysteryEventsHouse_B1F_EventScript_Greet_Red
	call_if_eq VAR_PROTAGONIST_CHALLENGE_PROGRESS, 1,  SootopolisCity_MysteryEventsHouse_B1F_EventScript_Greet_Leaf
	call_if_eq VAR_PROTAGONIST_CHALLENGE_PROGRESS, 2,  SootopolisCity_MysteryEventsHouse_B1F_EventScript_Greet_Ethan
	call_if_eq VAR_PROTAGONIST_CHALLENGE_PROGRESS, 3,  SootopolisCity_MysteryEventsHouse_B1F_EventScript_Greet_Lyra
	call_if_eq VAR_PROTAGONIST_CHALLENGE_PROGRESS, 4,  SootopolisCity_MysteryEventsHouse_B1F_EventScript_Greet_Brendan
	call_if_eq VAR_PROTAGONIST_CHALLENGE_PROGRESS, 5,  SootopolisCity_MysteryEventsHouse_B1F_EventScript_Greet_May
	call_if_eq VAR_PROTAGONIST_CHALLENGE_PROGRESS, 6,  SootopolisCity_MysteryEventsHouse_B1F_EventScript_Greet_Lucas
	call_if_eq VAR_PROTAGONIST_CHALLENGE_PROGRESS, 7,  SootopolisCity_MysteryEventsHouse_B1F_EventScript_Greet_Dawn
	call_if_eq VAR_PROTAGONIST_CHALLENGE_PROGRESS, 8,  SootopolisCity_MysteryEventsHouse_B1F_EventScript_Greet_Hilbert
	call_if_eq VAR_PROTAGONIST_CHALLENGE_PROGRESS, 9,  SootopolisCity_MysteryEventsHouse_B1F_EventScript_Greet_Hilda
	call_if_eq VAR_PROTAGONIST_CHALLENGE_PROGRESS, 10, SootopolisCity_MysteryEventsHouse_B1F_EventScript_Greet_Calem
	call_if_eq VAR_PROTAGONIST_CHALLENGE_PROGRESS, 11, SootopolisCity_MysteryEventsHouse_B1F_EventScript_Greet_Serena
	call_if_eq VAR_PROTAGONIST_CHALLENGE_PROGRESS, 12, SootopolisCity_MysteryEventsHouse_B1F_EventScript_Greet_Elio
	call_if_eq VAR_PROTAGONIST_CHALLENGE_PROGRESS, 13, SootopolisCity_MysteryEventsHouse_B1F_EventScript_Greet_Selene
	call_if_eq VAR_PROTAGONIST_CHALLENGE_PROGRESS, 14, SootopolisCity_MysteryEventsHouse_B1F_EventScript_Greet_Victor
	call_if_eq VAR_PROTAGONIST_CHALLENGE_PROGRESS, 15, SootopolisCity_MysteryEventsHouse_B1F_EventScript_Greet_Gloria
	call_if_eq VAR_PROTAGONIST_CHALLENGE_PROGRESS, 16, SootopolisCity_MysteryEventsHouse_B1F_EventScript_Greet_Florian
	call_if_eq VAR_PROTAGONIST_CHALLENGE_PROGRESS, 17, SootopolisCity_MysteryEventsHouse_B1F_EventScript_Greet_Juliana
	return

SootopolisCity_MysteryEventsHouse_B1F_EventScript_Greet_Red::
	msgbox SootopolisCity_MysteryEventsHouse_B1F_Text_Greet_Red, MSGBOX_DEFAULT
	closemessage
	return
SootopolisCity_MysteryEventsHouse_B1F_EventScript_Greet_Leaf::
	msgbox SootopolisCity_MysteryEventsHouse_B1F_Text_Greet_Leaf, MSGBOX_DEFAULT
	closemessage
	return
SootopolisCity_MysteryEventsHouse_B1F_EventScript_Greet_Ethan::
	msgbox SootopolisCity_MysteryEventsHouse_B1F_Text_Greet_Ethan, MSGBOX_DEFAULT
	closemessage
	return
SootopolisCity_MysteryEventsHouse_B1F_EventScript_Greet_Lyra::
	msgbox SootopolisCity_MysteryEventsHouse_B1F_Text_Greet_Lyra, MSGBOX_DEFAULT
	closemessage
	return
SootopolisCity_MysteryEventsHouse_B1F_EventScript_Greet_Brendan::
	msgbox SootopolisCity_MysteryEventsHouse_B1F_Text_Greet_Brendan, MSGBOX_DEFAULT
	closemessage
	return
SootopolisCity_MysteryEventsHouse_B1F_EventScript_Greet_May::
	msgbox SootopolisCity_MysteryEventsHouse_B1F_Text_Greet_May, MSGBOX_DEFAULT
	closemessage
	return
SootopolisCity_MysteryEventsHouse_B1F_EventScript_Greet_Lucas::
	msgbox SootopolisCity_MysteryEventsHouse_B1F_Text_Greet_Lucas, MSGBOX_DEFAULT
	closemessage
	return
SootopolisCity_MysteryEventsHouse_B1F_EventScript_Greet_Dawn::
	msgbox SootopolisCity_MysteryEventsHouse_B1F_Text_Greet_Dawn, MSGBOX_DEFAULT
	closemessage
	return
SootopolisCity_MysteryEventsHouse_B1F_EventScript_Greet_Hilbert::
	msgbox SootopolisCity_MysteryEventsHouse_B1F_Text_Greet_Hilbert, MSGBOX_DEFAULT
	closemessage
	return
SootopolisCity_MysteryEventsHouse_B1F_EventScript_Greet_Hilda::
	msgbox SootopolisCity_MysteryEventsHouse_B1F_Text_Greet_Hilda, MSGBOX_DEFAULT
	closemessage
	return
SootopolisCity_MysteryEventsHouse_B1F_EventScript_Greet_Calem::
	msgbox SootopolisCity_MysteryEventsHouse_B1F_Text_Greet_Calem, MSGBOX_DEFAULT
	closemessage
	return
SootopolisCity_MysteryEventsHouse_B1F_EventScript_Greet_Serena::
	msgbox SootopolisCity_MysteryEventsHouse_B1F_Text_Greet_Serena, MSGBOX_DEFAULT
	closemessage
	return
SootopolisCity_MysteryEventsHouse_B1F_EventScript_Greet_Elio::
	msgbox SootopolisCity_MysteryEventsHouse_B1F_Text_Greet_Elio, MSGBOX_DEFAULT
	closemessage
	return
SootopolisCity_MysteryEventsHouse_B1F_EventScript_Greet_Selene::
	msgbox SootopolisCity_MysteryEventsHouse_B1F_Text_Greet_Selene, MSGBOX_DEFAULT
	closemessage
	return
SootopolisCity_MysteryEventsHouse_B1F_EventScript_Greet_Victor::
	msgbox SootopolisCity_MysteryEventsHouse_B1F_Text_Greet_Victor, MSGBOX_DEFAULT
	closemessage
	return
SootopolisCity_MysteryEventsHouse_B1F_EventScript_Greet_Gloria::
	msgbox SootopolisCity_MysteryEventsHouse_B1F_Text_Greet_Gloria, MSGBOX_DEFAULT
	closemessage
	return
SootopolisCity_MysteryEventsHouse_B1F_EventScript_Greet_Florian::
	msgbox SootopolisCity_MysteryEventsHouse_B1F_Text_Greet_Florian, MSGBOX_DEFAULT
	closemessage
	return
SootopolisCity_MysteryEventsHouse_B1F_EventScript_Greet_Juliana::
	msgbox SootopolisCity_MysteryEventsHouse_B1F_Text_Greet_Juliana, MSGBOX_DEFAULT
	closemessage
	return

@ ---- KAMPF-DISPATCH ----
SootopolisCity_MysteryEventsHouse_B1F_EventScript_DoBattle::
	call_if_eq VAR_PROTAGONIST_CHALLENGE_PROGRESS, 0,  SootopolisCity_MysteryEventsHouse_B1F_EventScript_Battle_Red
	call_if_eq VAR_PROTAGONIST_CHALLENGE_PROGRESS, 1,  SootopolisCity_MysteryEventsHouse_B1F_EventScript_Battle_Leaf
	call_if_eq VAR_PROTAGONIST_CHALLENGE_PROGRESS, 2,  SootopolisCity_MysteryEventsHouse_B1F_EventScript_Battle_Ethan
	call_if_eq VAR_PROTAGONIST_CHALLENGE_PROGRESS, 3,  SootopolisCity_MysteryEventsHouse_B1F_EventScript_Battle_Lyra
	call_if_eq VAR_PROTAGONIST_CHALLENGE_PROGRESS, 4,  SootopolisCity_MysteryEventsHouse_B1F_EventScript_Battle_Brendan
	call_if_eq VAR_PROTAGONIST_CHALLENGE_PROGRESS, 5,  SootopolisCity_MysteryEventsHouse_B1F_EventScript_Battle_May
	call_if_eq VAR_PROTAGONIST_CHALLENGE_PROGRESS, 6,  SootopolisCity_MysteryEventsHouse_B1F_EventScript_Battle_Lucas
	call_if_eq VAR_PROTAGONIST_CHALLENGE_PROGRESS, 7,  SootopolisCity_MysteryEventsHouse_B1F_EventScript_Battle_Dawn
	call_if_eq VAR_PROTAGONIST_CHALLENGE_PROGRESS, 8,  SootopolisCity_MysteryEventsHouse_B1F_EventScript_Battle_Hilbert
	call_if_eq VAR_PROTAGONIST_CHALLENGE_PROGRESS, 9,  SootopolisCity_MysteryEventsHouse_B1F_EventScript_Battle_Hilda
	call_if_eq VAR_PROTAGONIST_CHALLENGE_PROGRESS, 10, SootopolisCity_MysteryEventsHouse_B1F_EventScript_Battle_Calem
	call_if_eq VAR_PROTAGONIST_CHALLENGE_PROGRESS, 11, SootopolisCity_MysteryEventsHouse_B1F_EventScript_Battle_Serena
	call_if_eq VAR_PROTAGONIST_CHALLENGE_PROGRESS, 12, SootopolisCity_MysteryEventsHouse_B1F_EventScript_Battle_Elio
	call_if_eq VAR_PROTAGONIST_CHALLENGE_PROGRESS, 13, SootopolisCity_MysteryEventsHouse_B1F_EventScript_Battle_Selene
	call_if_eq VAR_PROTAGONIST_CHALLENGE_PROGRESS, 14, SootopolisCity_MysteryEventsHouse_B1F_EventScript_Battle_Victor
	call_if_eq VAR_PROTAGONIST_CHALLENGE_PROGRESS, 15, SootopolisCity_MysteryEventsHouse_B1F_EventScript_Battle_Gloria
	call_if_eq VAR_PROTAGONIST_CHALLENGE_PROGRESS, 16, SootopolisCity_MysteryEventsHouse_B1F_EventScript_Battle_Florian
	call_if_eq VAR_PROTAGONIST_CHALLENGE_PROGRESS, 17, SootopolisCity_MysteryEventsHouse_B1F_EventScript_Battle_Juliana
	return

SootopolisCity_MysteryEventsHouse_B1F_EventScript_Battle_Red::
	cleartrainerflag TRAINER_CHALLENGE_HOUSE_RED
	trainerbattle_no_intro TRAINER_CHALLENGE_HOUSE_RED, SootopolisCity_MysteryEventsHouse_B1F_Text_Defeat_Red
	return
SootopolisCity_MysteryEventsHouse_B1F_EventScript_Battle_Leaf::
	cleartrainerflag TRAINER_CHALLENGE_HOUSE_LEAF
	trainerbattle_no_intro TRAINER_CHALLENGE_HOUSE_LEAF, SootopolisCity_MysteryEventsHouse_B1F_Text_Defeat_Leaf
	return
SootopolisCity_MysteryEventsHouse_B1F_EventScript_Battle_Ethan::
	cleartrainerflag TRAINER_CHALLENGE_HOUSE_ETHAN
	trainerbattle_no_intro TRAINER_CHALLENGE_HOUSE_ETHAN, SootopolisCity_MysteryEventsHouse_B1F_Text_Defeat_Ethan
	return
SootopolisCity_MysteryEventsHouse_B1F_EventScript_Battle_Lyra::
	cleartrainerflag TRAINER_CHALLENGE_HOUSE_LYRA
	trainerbattle_no_intro TRAINER_CHALLENGE_HOUSE_LYRA, SootopolisCity_MysteryEventsHouse_B1F_Text_Defeat_Lyra
	return
SootopolisCity_MysteryEventsHouse_B1F_EventScript_Battle_Brendan::
	cleartrainerflag TRAINER_CHALLENGE_HOUSE_BRENDAN
	trainerbattle_no_intro TRAINER_CHALLENGE_HOUSE_BRENDAN, SootopolisCity_MysteryEventsHouse_B1F_Text_Defeat_Brendan
	return
SootopolisCity_MysteryEventsHouse_B1F_EventScript_Battle_May::
	cleartrainerflag TRAINER_CHALLENGE_HOUSE_MAY
	trainerbattle_no_intro TRAINER_CHALLENGE_HOUSE_MAY, SootopolisCity_MysteryEventsHouse_B1F_Text_Defeat_May
	return
SootopolisCity_MysteryEventsHouse_B1F_EventScript_Battle_Lucas::
	cleartrainerflag TRAINER_CHALLENGE_HOUSE_LUCAS
	trainerbattle_no_intro TRAINER_CHALLENGE_HOUSE_LUCAS, SootopolisCity_MysteryEventsHouse_B1F_Text_Defeat_Lucas
	return
SootopolisCity_MysteryEventsHouse_B1F_EventScript_Battle_Dawn::
	cleartrainerflag TRAINER_CHALLENGE_HOUSE_DAWN
	trainerbattle_no_intro TRAINER_CHALLENGE_HOUSE_DAWN, SootopolisCity_MysteryEventsHouse_B1F_Text_Defeat_Dawn
	return
SootopolisCity_MysteryEventsHouse_B1F_EventScript_Battle_Hilbert::
	cleartrainerflag TRAINER_CHALLENGE_HOUSE_HILBERT
	trainerbattle_no_intro TRAINER_CHALLENGE_HOUSE_HILBERT, SootopolisCity_MysteryEventsHouse_B1F_Text_Defeat_Hilbert
	return
SootopolisCity_MysteryEventsHouse_B1F_EventScript_Battle_Hilda::
	cleartrainerflag TRAINER_CHALLENGE_HOUSE_HILDA
	trainerbattle_no_intro TRAINER_CHALLENGE_HOUSE_HILDA, SootopolisCity_MysteryEventsHouse_B1F_Text_Defeat_Hilda
	return
SootopolisCity_MysteryEventsHouse_B1F_EventScript_Battle_Calem::
	cleartrainerflag TRAINER_CHALLENGE_HOUSE_CALEM
	trainerbattle_no_intro TRAINER_CHALLENGE_HOUSE_CALEM, SootopolisCity_MysteryEventsHouse_B1F_Text_Defeat_Calem
	return
SootopolisCity_MysteryEventsHouse_B1F_EventScript_Battle_Serena::
	cleartrainerflag TRAINER_CHALLENGE_HOUSE_SERENA
	trainerbattle_no_intro TRAINER_CHALLENGE_HOUSE_SERENA, SootopolisCity_MysteryEventsHouse_B1F_Text_Defeat_Serena
	return
SootopolisCity_MysteryEventsHouse_B1F_EventScript_Battle_Elio::
	cleartrainerflag TRAINER_CHALLENGE_HOUSE_ELIO
	trainerbattle_no_intro TRAINER_CHALLENGE_HOUSE_ELIO, SootopolisCity_MysteryEventsHouse_B1F_Text_Defeat_Elio
	return
SootopolisCity_MysteryEventsHouse_B1F_EventScript_Battle_Selene::
	cleartrainerflag TRAINER_CHALLENGE_HOUSE_SELENE
	trainerbattle_no_intro TRAINER_CHALLENGE_HOUSE_SELENE, SootopolisCity_MysteryEventsHouse_B1F_Text_Defeat_Selene
	return
SootopolisCity_MysteryEventsHouse_B1F_EventScript_Battle_Victor::
	cleartrainerflag TRAINER_CHALLENGE_HOUSE_VICTOR
	trainerbattle_no_intro TRAINER_CHALLENGE_HOUSE_VICTOR, SootopolisCity_MysteryEventsHouse_B1F_Text_Defeat_Victor
	return
SootopolisCity_MysteryEventsHouse_B1F_EventScript_Battle_Gloria::
	cleartrainerflag TRAINER_CHALLENGE_HOUSE_GLORIA
	trainerbattle_no_intro TRAINER_CHALLENGE_HOUSE_GLORIA, SootopolisCity_MysteryEventsHouse_B1F_Text_Defeat_Gloria
	return
SootopolisCity_MysteryEventsHouse_B1F_EventScript_Battle_Florian::
	cleartrainerflag TRAINER_CHALLENGE_HOUSE_FLORIAN
	trainerbattle_no_intro TRAINER_CHALLENGE_HOUSE_FLORIAN, SootopolisCity_MysteryEventsHouse_B1F_Text_Defeat_Florian
	return
SootopolisCity_MysteryEventsHouse_B1F_EventScript_Battle_Juliana::
	cleartrainerflag TRAINER_CHALLENGE_HOUSE_JULIANA
	trainerbattle_no_intro TRAINER_CHALLENGE_HOUSE_JULIANA, SootopolisCity_MysteryEventsHouse_B1F_Text_Defeat_Juliana
	return

@ ---- ABSCHLUSS ----
SootopolisCity_MysteryEventsHouse_B1F_EventScript_AllBeaten::
	msgbox SootopolisCity_MysteryEventsHouse_B1F_Text_AllBeaten, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, SootopolisCity_MysteryEventsHouse_B1F_Movement_PlayerExit
	waitmovement 0
	warp MAP_SOOTOPOLIS_CITY_MYSTERY_EVENTS_HOUSE_1F, 3, 1
	waitstate
	releaseall
	end

SootopolisCity_MysteryEventsHouse_B1F_EventScript_AllBeatenOnEntry::
	lockall
	msgbox SootopolisCity_MysteryEventsHouse_B1F_Text_AlreadyBeaten, MSGBOX_DEFAULT
	closemessage
	warp MAP_SOOTOPOLIS_CITY_MYSTERY_EVENTS_HOUSE_1F, 3, 1
	waitstate
	releaseall
	end

SootopolisCity_MysteryEventsHouse_B1F_EventScript_NotChamp::
	end

@ ---- BEWEGUNGSDATEN ----
SootopolisCity_MysteryEventsHouse_B1F_Movement_PlayerEnter:
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	step_end

SootopolisCity_MysteryEventsHouse_B1F_Movement_PlayerExit:
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	delay_8
	step_end

SootopolisCity_MysteryEventsHouse_B1F_Movement_ProtagonistEnter:
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_in_place_faster_left
	step_end

SootopolisCity_MysteryEventsHouse_B1F_Movement_ProtagonistExit:
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	step_end

@ ---- TEXTE ----
SootopolisCity_MysteryEventsHouse_B1F_Text_Greet_Red:
	.string "Red: … … …\p"
	.string "…Worte sind überflüssig.\n"
	.string "Zeig, was du kannst.$"

SootopolisCity_MysteryEventsHouse_B1F_Text_Greet_Leaf:
	.string "Leaf: Du bist also der Champ?\p"
	.string "Sehen wir mal, ob du auch in\n"
	.string "Kanto überlebt hättest.$"

SootopolisCity_MysteryEventsHouse_B1F_Text_Greet_Ethan:
	.string "Klarin: Champ zu sein ist ein\n"
	.string "ziemlich cooler Titel…\p"
	.string "Aber kannst du auch Johto-Style\n"
	.string "mithalten?$"

SootopolisCity_MysteryEventsHouse_B1F_Text_Greet_Lyra:
	.string "Lyra: Ich hab extra mein Marill\n"
	.string "zuhause gelassen…\p"
	.string "Nur um dich hier mal so richtig\n"
	.string "zu fordern!$"

SootopolisCity_MysteryEventsHouse_B1F_Text_Greet_Brendan:
	.string "Hans: Ah, der Champion!\p"
	.string "Lass uns checken, ob du den\n"
	.string "Titel wirklich verdient hast.$"

SootopolisCity_MysteryEventsHouse_B1F_Text_Greet_May:
	.string "Brigitte: Hey, Champion!\n"
	.string "Bereit für eine gute Show?\p"
	.string "Ich hab nämlich ein paar neue\n"
	.string "Taktiken auf Lager!$"

SootopolisCity_MysteryEventsHouse_B1F_Text_Greet_Lucas:
	.string "Lukas: Die Wahrscheinlichkeit,\n"
	.string "dass ich gewinne, ist hoch.\p"
	.string "Aber beweis mir sehr gern\n"
	.string "das Gegenteil.$"

SootopolisCity_MysteryEventsHouse_B1F_Text_Greet_Dawn:
	.string "Lucia: Sinnohs Kälte härtet ab.\p"
	.string "Mal sehen, ob du dieser\n"
	.string "Prüfung standhalten kannst.$"

SootopolisCity_MysteryEventsHouse_B1F_Text_Greet_Hilbert:
	.string "Warren: Ein Kampf zwischen\n"
	.string "Champions…\p"
	.string "Zeig mir deine Ideale und\n"
	.string "lass Taten sprechen!$"

SootopolisCity_MysteryEventsHouse_B1F_Text_Greet_Hilda:
	.string "Lotta: Einall-Trainer fackeln\n"
	.string "nicht lange.\p"
	.string "Ich hoffe, du hast dich gut\n"
	.string "vorbereitet!$"

SootopolisCity_MysteryEventsHouse_B1F_Text_Greet_Calem:
	.string "Kalem: Ein Kampf sollte immer\n"
	.string "elegant geführt werden.\p"
	.string "Enttäusche mich nicht.$"

SootopolisCity_MysteryEventsHouse_B1F_Text_Greet_Serena:
	.string "Serena: Glamour und Stärke!\p"
	.string "Ich zeig dir, wie man beides\n"
	.string "perfekt auf dem Feld vereint.$"

SootopolisCity_MysteryEventsHouse_B1F_Text_Greet_Elio:
	.string "Elio: Alola! Mach dir keinen\n"
	.string "Stress, entspann dich…\p"
	.string "Aber im Kampf kenne ich absolut\n"
	.string "kein Erbarmen.$"

SootopolisCity_MysteryEventsHouse_B1F_Text_Greet_Selene:
	.string "Selene: Alola!\p"
	.string "Ich hoffe, du bist bereit für\n"
	.string "einen kleinen Wirbelsturm.$"

SootopolisCity_MysteryEventsHouse_B1F_Text_Greet_Victor:
	.string "Victor: In Galar machen wir aus\n"
	.string "Kämpfen ein Riesenspektakel.\p"
	.string "Zeit für Stadion-Atmosphäre!$"

SootopolisCity_MysteryEventsHouse_B1F_Text_Greet_Gloria:
	.string "Gloria: Kumpel, zieh dich warm\n"
	.string "an!\p"
	.string "Ich mach mit deinem Team jetzt\n"
	.string "kurzen Prozess.$"

SootopolisCity_MysteryEventsHouse_B1F_Text_Greet_Florian:
	.string "Florian: Mein persönlicher\n"
	.string "Schatz ist Kampferfahrung.\p"
	.string "Was kannst du mir beibringen?$"

SootopolisCity_MysteryEventsHouse_B1F_Text_Greet_Juliana:
	.string "Juliana: Ich hab mir extra ein\n"
	.string "Sandwich gemacht.\p"
	.string "Ich bin also voller Energie für\n"
	.string "unseren Kampf!$"

SootopolisCity_MysteryEventsHouse_B1F_Text_Defeat_Red:
	.string "Red: …!\p"
	.string "(Ein stilles, aber tiefes\n"
	.string "Nicken des Respekts.)$"

SootopolisCity_MysteryEventsHouse_B1F_Text_Defeat_Leaf:
	.string "Leaf: Okay, ich geb's zu.\n"
	.string "Du bist den Hype absolut wert.$"

SootopolisCity_MysteryEventsHouse_B1F_Text_Defeat_Ethan:
	.string "Klarin: Autsch!\p"
	.string "Da hat wohl jemand noch eine\n"
	.string "Ecke härter trainiert.$"

SootopolisCity_MysteryEventsHouse_B1F_Text_Defeat_Lyra:
	.string "Lyra: Wow, du spielst echt in\n"
	.string "einer ganz anderen Liga!$"

SootopolisCity_MysteryEventsHouse_B1F_Text_Defeat_Brendan:
	.string "Hans: Alles klar, der Titel\n"
	.string "bleibt wohl erstmal bei dir.$"

SootopolisCity_MysteryEventsHouse_B1F_Text_Defeat_May:
	.string "Brigitte: Puh!\p"
	.string "Da muss ich mir wohl noch\n"
	.string "krassere Moves überlegen.$"

SootopolisCity_MysteryEventsHouse_B1F_Text_Defeat_Lucas:
	.string "Lukas: Faszinierend…\p"
	.string "Meine Berechnungen waren\n"
	.string "komplett daneben.$"

SootopolisCity_MysteryEventsHouse_B1F_Text_Defeat_Dawn:
	.string "Lucia: Keine Chance…\n"
	.string "Du bist ein makelloser Champion.$"

SootopolisCity_MysteryEventsHouse_B1F_Text_Defeat_Hilbert:
	.string "Warren: Deine Wahrheit hat\n"
	.string "meine Ideale übertroffen.\p"
	.string "Größten Respekt.$"

SootopolisCity_MysteryEventsHouse_B1F_Text_Defeat_Hilda:
	.string "Lotta: Puh, das war eine\n"
	.string "absolute Meisterleistung!$"

SootopolisCity_MysteryEventsHouse_B1F_Text_Defeat_Calem:
	.string "Kalem: Wunderschön gekämpft.\n"
	.string "Du bist ein wahres Vorbild.$"

SootopolisCity_MysteryEventsHouse_B1F_Text_Defeat_Serena:
	.string "Serena: Chapeau!\p"
	.string "Du hast mir heute völlig die\n"
	.string "Show gestohlen.$"

SootopolisCity_MysteryEventsHouse_B1F_Text_Defeat_Elio:
	.string "Elio: Uff…\p"
	.string "Das war wie ein Z-Move direkt\n"
	.string "ins Gesicht.$"

SootopolisCity_MysteryEventsHouse_B1F_Text_Defeat_Selene:
	.string "Selene: Wow, du bist ja noch\n"
	.string "stürmischer als ich!$"

SootopolisCity_MysteryEventsHouse_B1F_Text_Defeat_Victor:
	.string "Victor: Brilliant!\p"
	.string "Du hättest das ganze Stadion\n"
	.string "zum Toben gebracht.$"

SootopolisCity_MysteryEventsHouse_B1F_Text_Defeat_Gloria:
	.string "Gloria: Ach, verflixt!\p"
	.string "Das hast du echt verdammt\n"
	.string "clever gespielt.$"

SootopolisCity_MysteryEventsHouse_B1F_Text_Defeat_Florian:
	.string "Florian: Eine Lektion der\n"
	.string "absoluten Meisterklasse!\p"
	.string "Danke dafür.$"

SootopolisCity_MysteryEventsHouse_B1F_Text_Defeat_Juliana:
	.string "Juliana: Oh Mann…\p"
	.string "Jetzt brauch ich definitiv\n"
	.string "noch ein Sandwich zum Trost.$"

SootopolisCity_MysteryEventsHouse_B1F_Text_AllBeaten:
	.string "Wahnsinn! Du hast tatsächlich\n"
	.string "alle 18 Protagonisten besiegt.\p"
	.string "Eine echte Meisterleistung,\n"
	.string "die in die Geschichte eingeht.\p"
	.string "Du bist ohne jeden Zweifel der\n"
	.string "stärkste Trainer aller Regionen!$"

SootopolisCity_MysteryEventsHouse_B1F_Text_AlreadyBeaten:
	.string "Du hast diesen Raum bereits\n"
	.string "komplett dominiert.\p"
	.string "Es gibt niemanden mehr, der\n"
	.string "dir noch das Wasser reichen kann.\p"
	.string "Genieß deinen wohlverdienten\n"
	.string "Ruhestand, Champion!$"


SootopolisCity_MysteryEventsHouse_B1F_EventScript_BattleVisitingTrainer::
	lockall
	applymovement LOCALID_PLAYER, SootopolisCity_MysteryEventsHouse_B1F_Movement_PlayerEnterBasement
	waitmovement 0
	special CopyEReaderTrainerGreeting
	msgbox gStringVar4, MSGBOX_DEFAULT
	closemessage
	setvar VAR_0x8004, SPECIAL_BATTLE_EREADER
	setvar VAR_0x8005, 0
	special DoSpecialTrainerBattle
	call_if_eq VAR_RESULT, B_OUTCOME_DREW, SootopolisCity_MysteryEventsHouse_B1F_EventScript_BattleTie
	call_if_eq VAR_RESULT, B_OUTCOME_WON, SootopolisCity_MysteryEventsHouse_B1F_EventScript_BattleWon
	call_if_eq VAR_RESULT, B_OUTCOME_LOST, SootopolisCity_MysteryEventsHouse_B1F_EventScript_BattleLost
	closemessage
	special HealPlayerParty
	applymovement LOCALID_PLAYER, SootopolisCity_MysteryEventsHouse_B1F_Movement_PlayerExitBasement
	waitmovement 0
	special LoadPlayerParty
	setvar VAR_TEMP_1, 1
	warp MAP_SOOTOPOLIS_CITY_MYSTERY_EVENTS_HOUSE_1F, 3, 1
	waitstate
	releaseall
	end

SootopolisCity_MysteryEventsHouse_B1F_EventScript_BattleTie::
	setvar VAR_SOOTOPOLIS_MYSTERY_EVENTS_STATE, 3
	msgbox SootopolisCity_MysteryEventsHouse_B1F_Text_MatchEndedUpDraw, MSGBOX_DEFAULT
	return

SootopolisCity_MysteryEventsHouse_B1F_EventScript_BattleWon::
	setvar VAR_SOOTOPOLIS_MYSTERY_EVENTS_STATE, 1
	special ShowFieldMessageStringVar4
	waitmessage
	waitbuttonpress
	return

SootopolisCity_MysteryEventsHouse_B1F_EventScript_BattleLost::
	setvar VAR_SOOTOPOLIS_MYSTERY_EVENTS_STATE, 2
	special ShowFieldMessageStringVar4
	waitmessage
	waitbuttonpress
	return

SootopolisCity_MysteryEventsHouse_B1F_Movement_PlayerEnterBasement:
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	step_end

SootopolisCity_MysteryEventsHouse_B1F_Movement_PlayerExitBasement:
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	delay_8
	step_end

