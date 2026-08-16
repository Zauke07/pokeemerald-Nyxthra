Route121_MapScripts::
	.byte 0

Route121_EventScript_Woman::
	msgbox Route121_Text_AheadLoomsMtPyre, MSGBOX_NPC
	end

Route121_EventScript_MtPyrePierSign::
	msgbox Route121_Text_MtPyrePierSign, MSGBOX_SIGN
	end

Route121_EventScript_SafariZoneSign::
	msgbox Route121_Text_SafariZoneSign, MSGBOX_SIGN
	end

Route121_EventScript_AquaGruntsMoveOut::
	lockall
	playbgm MUS_ENCOUNTER_AQUA, FALSE
	applymovement LOCALID_ROUTE121_GRUNT_2, Common_Movement_WalkInPlaceRight
	waitmovement 0
	msgbox Route121_Text_OkayMoveOutToMtPyre, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ROUTE121_GRUNT_1, Route121_Movement_Grunt1Exit
	applymovement LOCALID_ROUTE121_GRUNT_2, Route121_Movement_Grunt2Exit
	applymovement LOCALID_ROUTE121_GRUNT_3, Route121_Movement_Grunt3Exit
	waitmovement 0
	fadedefaultbgm
	removeobject LOCALID_ROUTE121_GRUNT_1
	removeobject LOCALID_ROUTE121_GRUNT_2
	removeobject LOCALID_ROUTE121_GRUNT_3
	setvar VAR_ROUTE121_STATE, 1
	releaseall
	end

Route121_Movement_Grunt1Exit:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

Route121_Movement_Grunt2Exit:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

Route121_Movement_Grunt3Exit:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

Route121_EventScript_Vanessa::
	trainerbattle_single TRAINER_VANESSA, Route121_Text_VanessaIntro, Route121_Text_VanessaDefeat
	msgbox Route121_Text_VanessaPostBattle, MSGBOX_AUTOCLOSE
	end

Route121_EventScript_Walter::
	trainerbattle_single TRAINER_WALTER_1, Route121_Text_WalterIntro, Route121_Text_WalterDefeat, Route121_EventScript_RegisterWalter
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route121_EventScript_RematchWalter
	msgbox Route121_Text_WalterPostBattle, MSGBOX_DEFAULT
	release
	end

Route121_EventScript_RegisterWalter::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route121_Text_WalterRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_WALTER_1
	release
	end

Route121_EventScript_RematchWalter::
	trainerbattle_rematch TRAINER_WALTER_1, Route121_Text_WalterRematchIntro, Route121_Text_WalterRematchDefeat
	msgbox Route121_Text_WalterPostRematch, MSGBOX_AUTOCLOSE
	end

Route121_EventScript_Tammy::
	trainerbattle_single TRAINER_TAMMY, Route121_Text_TammyIntro, Route121_Text_TammyDefeat
	msgbox Route121_Text_TammyPostBattle, MSGBOX_AUTOCLOSE
	end

Route121_EventScript_Kate::
	trainerbattle_double TRAINER_KATE_AND_JOY, Route121_Text_KateIntro, Route121_Text_KateDefeat, Route121_Text_KateNotEnoughMons
	msgbox Route121_Text_KatePostBattle, MSGBOX_AUTOCLOSE
	end

Route121_EventScript_Joy::
	trainerbattle_double TRAINER_KATE_AND_JOY, Route121_Text_JoyIntro, Route121_Text_JoyDefeat, Route121_Text_JoyNotEnoughMons
	msgbox Route121_Text_JoyPostBattle, MSGBOX_AUTOCLOSE
	end

Route121_EventScript_Jessica::
	trainerbattle_single TRAINER_JESSICA_1, Route121_Text_JessicaIntro, Route121_Text_JessicaDefeat, Route121_EventScript_RegisterJessica
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route121_EventScript_RematchJessica
	msgbox Route121_Text_JessicaPostBattle, MSGBOX_DEFAULT
	release
	end

Route121_EventScript_RegisterJessica::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route121_Text_JessicaRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_JESSICA_1
	release
	end

Route121_EventScript_RematchJessica::
	trainerbattle_rematch TRAINER_JESSICA_1, Route121_Text_JessicaRematchIntro, Route121_Text_JessicaRematchDefeat
	msgbox Route121_Text_JessicaPostRematch, MSGBOX_AUTOCLOSE
	end

Route121_EventScript_Cale::
	trainerbattle_single TRAINER_CALE, Route121_Text_CaleIntro, Route121_Text_CaleDefeat
	msgbox Route121_Text_CalePostBattle, MSGBOX_AUTOCLOSE
	end

Route121_EventScript_Myles::
	trainerbattle_single TRAINER_MYLES, Route121_Text_MylesIntro, Route121_Text_MylesDefeat
	msgbox Route121_Text_MylesPostBattle, MSGBOX_AUTOCLOSE
	end

Route121_EventScript_Pat::
	trainerbattle_single TRAINER_PAT, Route121_Text_PatIntro, Route121_Text_PatDefeat
	msgbox Route121_Text_PatPostBattle, MSGBOX_AUTOCLOSE
	end

Route121_EventScript_Marcel::
	trainerbattle_single TRAINER_MARCEL, Route121_Text_MarcelIntro, Route121_Text_MarcelDefeat
	msgbox Route121_Text_MarcelPostBattle, MSGBOX_AUTOCLOSE
	end

Route121_EventScript_Cristin::
	trainerbattle_single TRAINER_CRISTIN_1, Route121_Text_CristinIntro, Route121_Text_CristinDefeat, Route121_EventScript_RegisterCristin
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route121_EventScript_RematchCristin
	msgbox Route121_Text_CristinPostBattle, MSGBOX_DEFAULT
	release
	end

Route121_EventScript_RegisterCristin::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route121_Text_CristinRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_CRISTIN_1
	release
	end

Route121_EventScript_RematchCristin::
	trainerbattle_rematch TRAINER_CRISTIN_1, Route121_Text_CristinRematchIntro, Route121_Text_CristinRematchDefeat
	msgbox Route121_Text_CristinPostRematch, MSGBOX_AUTOCLOSE
	end

Route121_Text_OkayMoveOutToMtPyre::
	.string "Alles klar!\n"
	.string "Abmarsch zum PYROBERG, ihr Lappen!$"

Route121_Text_AheadLoomsMtPyre::
	.string "Da vorne ragt der PYROBERG auf……\p"
	.string "Ein riesiger Steinhaufen für die Geister\n"
	.string "verreckt…… äh, verstorbener POKéMON.$"

Route121_Text_MtPyrePierSign::
	.string "ANLEGESTELLE PYROBERG\p"
	.string "……Das Schild ist alt und total vergammelt.\n"
	.string "Man kann das Gekritzel kaum noch lesen……$"

Route121_Text_SafariZoneSign::
	.string "“Vollgestopft mit seltenen POKéMON!”\n"
	.string "SAFARI-ZONE$"

Route121_EventScript_Bauz::
	specialvar VAR_RESULT, IsWildRandomizerEnabled
	goto_if_eq VAR_RESULT, TRUE, Route121_EventScript_Bauz_RandomizerText
	msgbox Route121_Text_Bauz, MSGBOX_NPC
	end

Route121_EventScript_Bauz_RandomizerText::
	msgbox Route121_Text_BauzRandomizer, MSGBOX_NPC
	end

Route121_Text_Bauz:
	.string "Tipp:\p"
	.string "Auf dieser Route versteckt sich ein\n"
	.string "Starter aus der 7 Generation mit\l"
	.string "einer Spawnrate von 1%!\p"
	.string "Welches es ist, musst du selbst\n"
	.string "herausfinden :D !$"

Route121_Text_BauzRandomizer:
	.string "Tipp:\p"
	.string "Wild-Randomizer ist aktiv.\n"
	.string "Der feste 1%-Starter-Hinweis\l"
	.string "gilt deshalb hier nicht.\p"
	.string "Die Wild-Spawns werden über deinen\n"
	.string "Seed neu gemappt!$"

Route121_EventScript_Falle::
	msgbox Route121_Text_Falle, MSGBOX_NPC
	end

Route121_Text_Falle:
	.string "Man ist das Scheiße...\n"
	.string "Da liegt ein Meisterball!\p"
	.string "Aber es sieht so aus, als\n"
	.string "ob es ein softlock ist.\l"
	.string "Da kommt man nicht mehr weg!$"

Route121_EventScript_FalleSign::
	msgbox Route121_Text_FalleSign, MSGBOX_SIGN
	end

Route121_Text_FalleSign:
	.string "War die Gier nach Loot zu groß,\n"
	.string "geht der Abfuck jetzt erst los!\p"
	.string "Dachtest wohl, der Ball ist echt?\n"
	.string "Tja, du Lappen, hast du Pech!\p"
	.string "Hier kommst du nie wieder weg,\n"
	.string "verreckst in diesem miesen Dreck!\p"
	.string "Drück Reset, du kleines Licht,\n"
	.string "nen andern Ausweg gibt es nicht!\p"
	.string "Und wehe, du hast grad gespeichert...\n"
	.string "dann hast du dein Leben mit Frust bereichert!\p"
	.string "Dein Savegame ist nämlich am Arsch!\n"
	.string "HAHAHA, DU OPFER!$"

