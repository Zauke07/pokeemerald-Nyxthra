Route117_EventScript_DaycareManNormal::
	lock
	faceplayer
	checkflag FLAG_PLAYER_IN_GARDEN
	goto_if 1, Route117_EventScript_DaycareManAskToExit @ Springt zu RAUS-Logik, wenn Flag gesetzt ist
	specialvar VAR_RESULT, GetDaycareState
	goto_if_eq VAR_RESULT, DAYCARE_EGG_WAITING, Route117_EventScript_DaycareEggWaiting
	goto_if_eq VAR_RESULT, DAYCARE_TWO_MONS, Route117_EventScript_CheckOnTwoMons
	goto_if_eq VAR_RESULT, DAYCARE_ONE_MON, Route117_EventScript_CheckOnOneMon
	msgbox Route117_Text_SeeWifeIfYoudLikeMeToRaiseMon, MSGBOX_DEFAULT
	msgbox Route117_Text_DaycareManWantToGoInside, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route117_EventScript_DaycareManLetPlayerIn
	release
	end

Route117_EventScript_DaycareManAskToExit::
	@ Prüfe ob Quest gerade abgeschlossen wurde (erstes Mal)
	goto_if_unset FLAG_DAYCARE_MAN_FIRST_EXIT_DONE, Route117_EventScript_DaycareManFirstTimeExit
	@ Ab dem 2. Mal: Normaler Dialog
	msgbox Route117_Text_DaycareManWantToExit, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route117_EventScript_DaycareManLetPlayerOut
	msgbox Route117_Text_DaycareManOkayStay, MSGBOX_DEFAULT
	release
	end

Route117_EventScript_DaycareManFirstTimeExit::
	@ KORREKTUR: Zeigt den Danke-Text, setzt den Flag, springt DANN zum RAUS-Dialog (MSGBOX_YESNO)
	msgbox Route117_Text_DaycareManThankYouAgain, MSGBOX_DEFAULT
	setflag FLAG_DAYCARE_MAN_FIRST_EXIT_DONE
	goto Route117_EventScript_DaycareManAskToExit


Route117_EventScript_DaycareManLetPlayerIn::
	msgbox Route117_Text_DaycareManLetMeHelp, MSGBOX_DEFAULT
	closemessage
	
	@ 1. Opa weicht aus (1h, 1r, schaut l)
	applymovement LOCALID_DAYCARE_MAN, Route117_Movement_DaycareManMoveAsideIn
	
	@ 2. Spieler geht rein (2h, 1l, schaut r) - Gleichzeitig
	applymovement OBJ_EVENT_ID_PLAYER, Route117_Movement_PlayerEnterGarden
	
	@ 3. Auf beide warten
	waitmovement LOCALID_DAYCARE_MAN
	waitmovement OBJ_EVENT_ID_PLAYER
	delay 10
	
	@ 4. Dialog
	msgbox Route117_Text_DaycareManEnjoyGarden, MSGBOX_DEFAULT
	
	@ 5. Opa geht zurück (1l, 1u, schaut u)
	applymovement LOCALID_DAYCARE_MAN, Route117_Movement_DaycareManReturnIn
	waitmovement LOCALID_DAYCARE_MAN
	
	setflag FLAG_PLAYER_IN_GARDEN
	release
	end

Route117_EventScript_DaycareManLetPlayerOut::
	msgbox Route117_Text_DaycareManLetMeHelp, MSGBOX_DEFAULT
	closemessage
	
	@ 1. Opa weicht aus (2u, 1r, schaut l)
	applymovement LOCALID_DAYCARE_MAN, Route117_Movement_DaycareManMoveAside
	
	@ 2. Spieler geht raus (3u, 1l, schaut r) - Gleichzeitig
	applymovement OBJ_EVENT_ID_PLAYER, Route117_Movement_PlayerExitGarden
	
	@ 3. Auf beide warten
	waitmovement LOCALID_DAYCARE_MAN
	waitmovement OBJ_EVENT_ID_PLAYER
	delay 10
	
	@ 4. Dialog
	msgbox Route117_Text_DaycareManBackToNormal, MSGBOX_DEFAULT
	
	@ 5. Opa geht zurück (1l, 2h, schaut u)
	applymovement LOCALID_DAYCARE_MAN, Route117_Movement_DaycareManReturn
	waitmovement LOCALID_DAYCARE_MAN
	
	clearflag FLAG_PLAYER_IN_GARDEN
	release
	end

Route117_EventScript_CheckOnOneMon::
	special GetDaycareMonNicknames
	msgbox Route117_Text_YourMonIsDoingFine, MSGBOX_DEFAULT
	setvar VAR_0x8004, 0
	call Route117_EventScript_CheckMonReceivedMail
	
	@ ✅ WICHTIG: Prüfe ob Spieler IM GARTEN ist!
	checkflag FLAG_PLAYER_IN_GARDEN
	goto_if 1, Route117_EventScript_DaycareManAskToExitAfterCheck
	
	msgbox Route117_Text_DaycareManWantToGoInside, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route117_EventScript_DaycareManLetPlayerIn
	release
	end

Route117_EventScript_DaycareManAskToExitAfterCheck::
	msgbox Route117_Text_DaycareManWantToExit, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route117_EventScript_DaycareManLetPlayerOut
	msgbox Route117_Text_DaycareManOkayStay, MSGBOX_DEFAULT
	release
	end

Route117_EventScript_CheckOnTwoMons::
	special GetDaycareMonNicknames
	msgbox Route117_Text_YourMonsAreDoingFine, MSGBOX_DEFAULT
	special SetDaycareCompatibilityString
	special ShowFieldMessageStringVar4
	waitmessage
	waitbuttonpress
	setvar VAR_0x8004, 0
	call Route117_EventScript_CheckMonReceivedMail
	setvar VAR_0x8004, 1
	call Route117_EventScript_CheckMonReceivedMail
	
	@ ✅ WICHTIG: Prüfe ob Spieler IM GARTEN ist!
	checkflag FLAG_PLAYER_IN_GARDEN
	goto_if 1, Route117_EventScript_DaycareManAskToExitAfterCheck
	
	msgbox Route117_Text_DaycareManWantToGoInside, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route117_EventScript_DaycareManLetPlayerIn
	release
	end

Route117_EventScript_DaycareEggWaiting::
	msgbox Route117_Text_DoYouWantEgg, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route117_EventScript_DaycareAcceptEgg
	msgbox Route117_Text_IWillKeepDoYouWantIt, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route117_EventScript_DaycareAcceptEgg
	msgbox Route117_Text_IllKeepIt, MSGBOX_DEFAULT
	clearflag FLAG_PENDING_DAYCARE_EGG
	special RejectEggFromDayCare
	
	@ ✅ WICHTIG: Prüfe ob Spieler IM GARTEN ist!
	checkflag FLAG_PLAYER_IN_GARDEN
	goto_if 1, Route117_EventScript_DaycareManAskToExitAfterEgg
	
	@ Wenn draußen: Frage nach REIN
	msgbox Route117_Text_DaycareManWantToGoInside, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route117_EventScript_DaycareManLetPlayerIn
	release
	end

Route117_EventScript_DaycareManAskToExitAfterEgg::
	@ Wenn drinnen: Frage nach RAUS
	msgbox Route117_Text_DaycareManWantToExit, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route117_EventScript_DaycareManLetPlayerOut
	msgbox Route117_Text_DaycareManOkayStay, MSGBOX_DEFAULT
	release
	end

Route117_EventScript_DaycareAcceptEgg::
	specialvar VAR_RESULT, CalculatePlayerPartyCount
	goto_if_ne VAR_RESULT, PARTY_SIZE, Route117_EventScript_DaycareReceiveEgg
	msgbox Route117_Text_YouHaveNoRoomForIt, MSGBOX_DEFAULT
	release
	end

Route117_EventScript_DaycareReceiveEgg::
	message Route117_Text_ReceivedEgg
	playfanfare MUS_LEVEL_UP
	waitfanfare
	waitbuttonpress
	msgbox Route117_Text_TakeGoodCareOfIt, MSGBOX_DEFAULT
	special GiveEggFromDaycare
	clearflag FLAG_PENDING_DAYCARE_EGG
	
	@ ✅ WICHTIG: Prüfe ob Spieler IM GARTEN ist!
	checkflag FLAG_PLAYER_IN_GARDEN
	goto_if 1, Route117_EventScript_DaycareManAskToExitAfterEgg
	
	@ Wenn draußen: Frage nach REIN
	msgbox Route117_Text_DaycareManWantToGoInside, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route117_EventScript_DaycareManLetPlayerIn
	release
	end

Route117_EventScript_CheckMonReceivedMail::
	specialvar VAR_RESULT, CheckDaycareMonReceivedMail
	call_if_eq VAR_RESULT, 1, Route117_EventScript_MonReceivedMail
	return

Route117_EventScript_MonReceivedMail::
	msgbox Route117_Text_FriendlyWithOtherTrainersMon, MSGBOX_DEFAULT
	return

Route117_PokemonDayCare_EventScript_DaycareWoman::
	lock
	faceplayer
	@ QUEST CHECK - Während der Quest anderen Dialog!
	goto_if_unset FLAG_DAYCARE_RESCUE_QUEST_COMPLETED, Route117_PokemonDayCare_EventScript_CheckQuestActive
	@ Quest abgeschlossen - normales Verhalten
	specialvar VAR_RESULT, GetDaycareState
	goto_if_eq VAR_RESULT, DAYCARE_EGG_WAITING, Route117_PokemonDayCare_EventScript_EggWaiting
	goto_if_eq VAR_RESULT, DAYCARE_ONE_MON, Route117_PokemonDayCare_EventScript_OneMonInDaycare
	goto_if_eq VAR_RESULT, DAYCARE_TWO_MONS, Route117_PokemonDayCare_EventScript_TwoMonsInDaycare
	msgbox Route117_PokemonDayCare_Text_WouldYouLikeUsToRaiseAMon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route117_PokemonDayCare_EventScript_GiveMonToRaise
	msgbox Route117_PokemonDayCare_Text_FineThenComeAgain, MSGBOX_DEFAULT
	release
	end

@ ========== QUEST SCRIPTS ==========

Route117_PokemonDayCare_EventScript_CheckQuestActive::
	@ Wenn Ei wartet UND Mann ist weg
	goto_if_set FLAG_PENDING_DAYCARE_EGG, Route117_PokemonDayCare_EventScript_QuestEggWaiting
	@ Sonst: Normaler Dialog aber mit Sorge um Mann
	specialvar VAR_RESULT, GetDaycareState
	goto_if_eq VAR_RESULT, DAYCARE_ONE_MON, Route117_PokemonDayCare_EventScript_QuestOneMonInDaycare
	goto_if_eq VAR_RESULT, DAYCARE_TWO_MONS, Route117_PokemonDayCare_EventScript_QuestTwoMonsInDaycare
	@ Kein Pokemon in Daycare - Sorgen-Dialog + trotzdem Pokemon annehmen!
	msgbox Route117_PokemonDayCare_Text_WomanCantFindHusbandButWillHelp, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route117_PokemonDayCare_EventScript_GiveMonToRaise
	msgbox Route117_PokemonDayCare_Text_FineThenComeAgain, MSGBOX_DEFAULT
	release
	end

Route117_PokemonDayCare_EventScript_QuestEggWaiting::
	@ Ei ist da, aber Mann ist verschwunden!
	msgbox Route117_PokemonDayCare_Text_WomanWorried, MSGBOX_DEFAULT
	release
	end

Route117_PokemonDayCare_EventScript_QuestOneMonInDaycare::
	msgbox Route117_PokemonDayCare_Text_GoodToSeeYouQuestHint, MSGBOX_DEFAULT
	setvar VAR_0x8004, 0
	call Route117_PokemonDayCare_EventScript_DisplayLevelsGained
	@ Biete zweites Pokemon oder abholen an
	msgbox Route117_PokemonDayCare_Text_WeCanRaiseOneMore, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route117_PokemonDayCare_EventScript_GiveMonToRaise
	msgbox Route117_PokemonDayCare_Text_TakeYourMonBack, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route117_PokemonDayCare_EventScript_TryRetrieveMon
	goto Route117_PokemonDayCare_EventScript_ComeAgain
	end

Route117_PokemonDayCare_EventScript_QuestTwoMonsInDaycare::
	msgbox Route117_PokemonDayCare_Text_GoodToSeeYouQuestHint, MSGBOX_DEFAULT
	setvar VAR_0x8004, 0
	call Route117_PokemonDayCare_EventScript_DisplayLevelsGained
	setvar VAR_0x8004, 1
	call Route117_PokemonDayCare_EventScript_DisplayLevelsGained
	@ Biete abholen an
	msgbox Route117_PokemonDayCare_Text_TakeYourMonBack, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route117_PokemonDayCare_EventScript_TryRetrieveMon
	msgbox Route117_PokemonDayCare_Text_ComeAgain, MSGBOX_DEFAULT
	release
	end

@ ========== NORMALE DAYCARE SCRIPTS ==========

Route117_PokemonDayCare_EventScript_GiveMonToRaise::
	specialvar VAR_RESULT, CountPartyNonEggMons
	goto_if_eq VAR_RESULT, 1, Route117_PokemonDayCare_EventScript_OnlyOneMon
	specialvar VAR_RESULT, CountPartyAliveNonEggMons
	goto_if_eq VAR_RESULT, 2, Route117_PokemonDayCare_EventScript_OnlyTwoAliveMons
	msgbox Route117_PokemonDayCare_Text_WhichMonShouldWeRaise, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	special ChooseSendDaycareMon
	waitstate
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, Route117_PokemonDayCare_EventScript_ComeAgain
	specialvar VAR_RESULT, CountPartyAliveNonEggMons_IgnoreVar0x8004Slot
	goto_if_eq VAR_RESULT, 0, Route117_PokemonDayCare_EventScript_OnlyOneAliveMon
	specialvar VAR_0x8005, GetSelectedMonNicknameAndSpecies
	waitse
	playmoncry VAR_0x8005, CRY_MODE_NORMAL
	msgbox Route117_PokemonDayCare_Text_WellRaiseYourMon, MSGBOX_DEFAULT
	waitmoncry
	special StoreSelectedPokemonInDaycare
	callnative UpdateFollowingPokemon
	incrementgamestat GAME_STAT_USED_DAYCARE
	specialvar VAR_RESULT, GetDaycareState
	goto_if_eq VAR_RESULT, DAYCARE_ONE_MON, Route117_PokemonDayCare_EventScript_CanRaiseOneMore
	release
	end

Route117_PokemonDayCare_EventScript_ComeAgain::
	msgbox Route117_PokemonDayCare_Text_ComeAgain, MSGBOX_DEFAULT
	release
	end

Route117_PokemonDayCare_EventScript_CanRaiseOneMore::
	msgbox Route117_PokemonDayCare_Text_WeCanRaiseOneMore, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route117_PokemonDayCare_EventScript_GiveMonToRaise
	goto Route117_PokemonDayCare_EventScript_ComeAgain
	end

Route117_PokemonDayCare_EventScript_OnlyOneMon::
	msgbox Route117_PokemonDayCare_Text_YouHaveJustOneMon, MSGBOX_DEFAULT
	release
	end

Route117_PokemonDayCare_EventScript_OnlyOneAliveMon::
	msgbox Route117_PokemonDayCare_Text_WhatWillYouBattleWith, MSGBOX_DEFAULT
	release
	end

Route117_PokemonDayCare_EventScript_OnlyTwoAliveMons::
	msgbox Route117_PokemonDayCare_Text_YoullBeLeftWithJustOne, MSGBOX_DEFAULT
	release
	end

Route117_PokemonDayCare_EventScript_EggWaiting::
	msgbox Route117_PokemonDayCare_Text_HusbandWasLookingForYou, MSGBOX_DEFAULT
	release
	end

Route117_PokemonDayCare_EventScript_YourMonHasGrownXLevels::
	msgbox Route117_PokemonDayCare_Text_YourMonHasGrownXLevels, MSGBOX_DEFAULT
	return

Route117_PokemonDayCare_EventScript_DisplayLevelsGained::
	specialvar VAR_RESULT, GetNumLevelsGainedFromDaycare
	call_if_ne VAR_RESULT, 0, Route117_PokemonDayCare_EventScript_YourMonHasGrownXLevels
	return

Route117_PokemonDayCare_EventScript_OneMonInDaycare::
	msgbox Route117_PokemonDayCare_Text_GoodToSeeYou, MSGBOX_DEFAULT
	setvar VAR_0x8004, 0
	call Route117_PokemonDayCare_EventScript_DisplayLevelsGained
	msgbox Route117_PokemonDayCare_Text_WeCanRaiseOneMore, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route117_PokemonDayCare_EventScript_GiveMonToRaise
	msgbox Route117_PokemonDayCare_Text_TakeYourMonBack, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route117_PokemonDayCare_EventScript_TryRetrieveMon
	goto Route117_PokemonDayCare_EventScript_ComeAgain
	end

Route117_PokemonDayCare_EventScript_TryRetrieveMon::
	specialvar VAR_RESULT, CalculatePlayerPartyCount
	goto_if_eq VAR_RESULT, PARTY_SIZE, Route117_PokemonDayCare_EventScript_NoRoom
	specialvar VAR_RESULT, GetDaycareState
	setvar VAR_0x8004, 0
	goto_if_eq VAR_RESULT, DAYCARE_ONE_MON, Route117_PokemonDayCare_EventScript_CostPrompt
	special ShowDaycareLevelMenu
	waitstate
	copyvar VAR_0x8004, VAR_RESULT
	goto_if_eq VAR_RESULT, DAYCARE_EXITED_LEVEL_MENU, Route117_PokemonDayCare_EventScript_ComeAgain
	goto Route117_PokemonDayCare_EventScript_CostPrompt
	end

Route117_PokemonDayCare_EventScript_CostPrompt::
	special GetDaycareCost
	msgbox Route117_PokemonDayCare_Text_ItWillCostX, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route117_PokemonDayCare_EventScript_CheckEnoughMoney
	goto Route117_PokemonDayCare_EventScript_ComeAgain
	end

Route117_PokemonDayCare_EventScript_CheckEnoughMoney::
	specialvar VAR_RESULT, IsEnoughForCostInVar0x8005
	goto_if_eq VAR_RESULT, 1, Route117_PokemonDayCare_EventScript_RetrieveMon
	msgbox Route117_PokemonDayCare_Text_NotEnoughMoney, MSGBOX_DEFAULT
	release
	end

Route117_PokemonDayCare_EventScript_RetrieveMon::
	applymovement LOCALID_DAYCARE_LADY, Route117_PokemonDayCare_Movement_RetrieveDaycareMon
	waitmovement 0
	specialvar VAR_RESULT, TakePokemonFromDaycare
	special SubtractMoneyFromVar0x8005
	playse SE_SHOP
	msgbox Route117_PokemonDayCare_Text_HeresYourMon, MSGBOX_DEFAULT
	waitse
	playmoncry VAR_RESULT, CRY_MODE_NORMAL
	msgbox Route117_PokemonDayCare_Text_TookBackMon, MSGBOX_DEFAULT
	waitmoncry
	specialvar VAR_RESULT, GetDaycareState
	goto_if_eq VAR_RESULT, DAYCARE_ONE_MON, Route117_PokemonDayCare_EventScript_AskRetrieveOtherMon
	goto Route117_PokemonDayCare_EventScript_ComeAgain
	end

Route117_PokemonDayCare_EventScript_AskRetrieveOtherMon::
	msgbox Route117_PokemonDayCare_Text_TakeOtherOneBackToo, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route117_PokemonDayCare_EventScript_TryRetrieveMon
	goto Route117_PokemonDayCare_EventScript_ComeAgain
	end

Route117_PokemonDayCare_EventScript_NoRoom::
	msgbox Route117_PokemonDayCare_Text_YourTeamIsFull, MSGBOX_DEFAULT
	release
	end

Route117_PokemonDayCare_Movement_RetrieveDaycareMon:
	delay_16
	delay_16
	face_left
	delay_16
	delay_16
	face_right
	delay_16
	delay_16
	face_up
	walk_slow_up
	set_invisible
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	face_down
	set_visible
	walk_slow_down
	step_end

@ =================================================================
@ KORRIGIERTE BEWEGUNGS-SKRIPTE (RAUSLASSEN)
@ =================================================================

@ Opa macht Platz (2u, 1r, schaut l)
Route117_Movement_DaycareManMoveAside:
	walk_slow_down
	walk_slow_down
	walk_slow_right
	face_left	   @ Schaut links (ohne Schritt)
	step_end

@ Opa geht zurück (1l, 2h, schaut u)
Route117_Movement_DaycareManReturn:
	walk_slow_left
	walk_slow_up
	walk_slow_up
	face_down	   @ Schaut runter
	step_end

@ Spieler geht raus (3u, 1l, schaut r)
Route117_Movement_PlayerExitGarden:
	walk_slow_down
	walk_slow_down
	walk_slow_down
	walk_slow_left
	face_right	  @ Schaut rechts (ohne Schritt)
	step_end

@ Spieler geht 2 Schritte runter
Route117_Movement_PlayerMoveDown2:
	walk_down
	walk_down
	step_end

@ Spieler geht wieder rein (2h, 1l, schaut r)
Route117_Movement_PlayerEnterGarden:
	walk_slow_up
	walk_slow_up
	walk_slow_left
	face_right	  @ Schaut rechts (ohne Schritt)
	step_end


@ === NEUE EINGANGS-BEWEGUNGEN ===

@ Opa macht Platz (1h, 1r, schaut l)
Route117_Movement_DaycareManMoveAsideIn:
	walk_slow_up
	walk_slow_right
	face_left	   @ Schaut links (ohne Schritt)
	step_end

@ Opa geht zurück (1l, 1u, schaut u)
Route117_Movement_DaycareManReturnIn:
	walk_slow_left
	walk_slow_down
	face_down	   @ Schaut runter
	step_end

@ Unused. Possibly a commented script, or a typo end added to the above Movement script
Route117_PokemonDayCare_EventScript_UnusedEnd::
	end

Route117_PokemonDayCare_EventScript_TwoMonsInDaycare::
	msgbox Route117_PokemonDayCare_Text_GoodToSeeYou, MSGBOX_DEFAULT
	setvar VAR_0x8004, 0
	call Route117_PokemonDayCare_EventScript_DisplayLevelsGained
	setvar VAR_0x8004, 1
	call Route117_PokemonDayCare_EventScript_DisplayLevelsGained
	msgbox Route117_PokemonDayCare_Text_TakeYourMonBack, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route117_PokemonDayCare_EventScript_TryRetrieveMon
	msgbox Route117_PokemonDayCare_Text_ComeAgain, MSGBOX_DEFAULT
	release
	end

@ Unused
Route117_PokemonDayCare_EventScript_UnusedRetrieveMon::
	special ShowDaycareLevelMenu
	waitstate
	goto_if_eq VAR_RESULT, 2, Route117_PokemonDayCare_EventScript_ComeAgain
	copyvar VAR_0x8004, VAR_RESULT
	specialvar VAR_RESULT, TakePokemonFromDaycare
	msgbox Route117_PokemonDayCare_Text_HeresYourMon, MSGBOX_DEFAULT
	msgbox Route117_PokemonDayCare_Text_ComeAgain, MSGBOX_DEFAULT
	release
	end

EventScript_EggHatch::
	lockall
	msgbox Text_EggHatchHuh, MSGBOX_DEFAULT
	special EggHatch
	waitstate
	releaseall
	end

@ ========== TEXTE ==========

Route117_Text_SeeWifeIfYoudLikeMeToRaiseMon:
	.string "Ich bin der PENSIONSLEITER.\p"
	.string "Ich kümmere mich um die wertvollen\n"
	.string "Pokémon der TRAINER.\p"
	.string "Wenn ich eines deiner Pokémon auf-\n"
	.string "ziehen soll, sprich mit meiner Frau.$"

Route117_Text_DoYouWantEgg:
	.string "Ach, du bist es!\p"
	.string "Wir haben deine Pokémon aufgezogen\n"
	.string "und wurden überrascht!\p"
	.string "Deine Pokémon haben nun ein EI!\p"
	.string "Wir wissen nicht, wie das passiert ist,\n"
	.string "aber deine Pokémon haben es.\p"
	.string "Möchtest du es haben?$"

Route117_Text_YourMonIsDoingFine:
	.string "Ach, du bist es! Schön, dich zu sehen.\n"
	.string "Deinem {STR_VAR_1} geht es sehr gut.$"

Route117_Text_IllKeepIt:
	.string "Ich werde es behalten.$"

Route117_Text_YouHaveNoRoomForIt:
	.string "Du hast keinen Platz dafür… Komm\n"
	.string "wieder, wenn du Platz geschafft hast.$"

Route117_Text_ReceivedEgg:
	.string "{PLAYER} erhält das EI vom\n"
	.string "PENSIONSLEITER.$"

Route117_Text_TakeGoodCareOfIt:
	.string "Kümmere dich gut darum.$"

Route117_Text_FriendlyWithOtherTrainersMon:
	.string "Übrigens, dein {STR_VAR_1} scheint sich\n"
	.string "gut mit dem {STR_VAR_3} von {STR_VAR_2} \l"
	.string "zu verstehen.\p"
	.string "Ich habe gesehen, wie sie einen BRIEF\n"
	.string "ausgetauscht haben…$"

@ Unused
Route117_Text_SeeWifeIfYouWantToPickUpMon:
	.string "If you want to pick up your POKéMON,\n"
	.string "have a word with my wife.$"

Route117_Text_YourMonsAreDoingFine:
	.string "Ah, du bist es! Deine Pokémon\n"
	.string "{STR_VAR_1} und {STR_VAR_2} entwickeln\l"
	.string "sich prächtig.$"

Route117_Text_IWillKeepDoYouWantIt:
	.string "Ich werde es behalten.\n"
	.string "Oder möchtest du es haben?$"

Route117_PokemonDayCare_Text_WouldYouLikeUsToRaiseAMon:
	.string "Ich bin die PENSIONSLEITERIN.\p"
	.string "Wir ziehen Pokémon für dich auf.\p"
	.string "Sollen wir eins für dich aufziehen?$"

Route117_PokemonDayCare_Text_WhichMonShouldWeRaise:
	.string "Welches Pokémon sollen wir für dich\n"
	.string "aufziehen?$"

Route117_PokemonDayCare_Text_WellRaiseYourMon:
	.string "Fein, dann nehmen wir dein {STR_VAR_1}\n"
	.string "für eine Weile in Pflege.\p"
	.string "Schau später mal nach ihm.$"

Route117_PokemonDayCare_Text_WeCanRaiseOneMore:
	.string "Wir können zwei deiner Pokémon nehmen.\n"
	.string "Möchtest du noch eins in Pflege geben?$"

Route117_PokemonDayCare_Text_HusbandWasLookingForYou:
	.string "Mein Mann hat dich schon gesucht.$"

Route117_PokemonDayCare_Text_FineThenComeAgain:
	.string "Oh, gut.\n"
	.string "Komm bald wieder.$"

Route117_PokemonDayCare_Text_NotEnoughMoney:
	.string "Du hast nicht genug Geld…$"

Route117_PokemonDayCare_Text_TakeOtherOneBackToo:
	.string "Möchtest du das andere auch wieder\n"
	.string "mitnehmen?$"

Route117_PokemonDayCare_Text_ComeAgain:
	.string "Gut.\n"
	.string "Komm bald wieder.$"

Route117_PokemonDayCare_Text_GoodToSeeYou:
	.string "Ach, du bist es! Schön, dich zu sehen.\n"
	.string "Deinen Pokémon kann es einfach\l"
	.string "nur gut gehen!$"

Route117_PokemonDayCare_Text_YourMonHasGrownXLevels:
	.string "Dein {STR_VAR_1} ist um {STR_VAR_2} Level\n"
	.string "gewachsen.$"

Route117_PokemonDayCare_Text_YourTeamIsFull:
	.string "Dein Pokémon-Team ist vollzählig.\n"
	.string "Schaffe Platz und komm dann wieder.$"

@ Unused
Route117_PokemonDayCare_Text_TakeBackWhichMon:
	.string "Which POKéMON will you take back?$"

Route117_PokemonDayCare_Text_ItWillCostX:
	.string "Wenn du dein {STR_VAR_1}\n"
	.string "mitnehmen willst, kostet das ¥{STR_VAR_2}.$"

Route117_PokemonDayCare_Text_HeresYourMon:
	.string "Sehr schön!\n"
	.string "Hier ist dein Pokémon!$"

Route117_PokemonDayCare_Text_TookBackMon:
	.string "{PLAYER} hat {STR_VAR_1} von der\n"
	.string "PENSIONSLEITERIN zurückerhalten.$"

Route117_PokemonDayCare_Text_YouHaveJustOneMon:
	.string "Oh! Du hast aber nur ein Pokémon.\p"
	.string "Komm einfach später wieder.$"

Route117_PokemonDayCare_Text_TakeYourMonBack:
	.string "Möchtest du dein Pokémon wieder\n"
	.string "mitnehmen?$"

Route117_PokemonDayCare_Text_WhatWillYouBattleWith:
	.string "Wenn du das Pokémon hier lässt, womit\n"
	.string "willst du denn dann kämpfen?\p"
	.string "Komm einfach später wieder.$"

Text_EggHatchHuh:
	.string "Wie?$"

Route117_PokemonDayCare_Text_YoullBeLeftWithJustOne:
	.string "Bitte?\n"
	.string "Aber, aber…\p"
	.string "Wenn du das Pokémon bei mir lässt, dann\n"
	.string "hast du ja nur noch ein einziges bei dir!\p"
	.string "Fang doch einfach ein paar Pokémon,\n"
	.string "dann sehen wir weiter.$"

@ ========== QUEST TEXTE ==========

Route117_PokemonDayCare_Text_WomanCantFindHusband:
	.string "Ich bin die PENSIONSLEITERIN.\p"
	.string "Normalerweise ziehen wir Pokémon\n"
	.string "für TRAINER auf, aber…\p"
	.string "Ich kann meinen Mann nicht finden.\n"
	.string "Er ist heute nicht aufgetaucht…\p"
	.string "Das ist sehr seltsam. Er würde niemals\n"
	.string "einfach verschwinden…$"

Route117_PokemonDayCare_Text_WomanWorried:
	.string "Oh! Ich… ich weiß nicht wo mein Mann\n"
	.string "ist!\p"
	.string "Er hat dein EI mitgenommen und ist\n"
	.string "verschwunden!\p"
	.string "Das ist nicht wie er… Ich mache mir\n"
	.string "solche Sorgen!$"

Route117_PokemonDayCare_Text_GoodToSeeYouQuestHint:
	.string "Ach, du bist es! Schön, dich zu sehen.\n"
	.string "Deinen Pokémon geht es gut!\p"
	.string "Aber… hast du meinen Mann draußen\n"
	.string "gesehen?\p"
	.string "Ich mache mir langsam Sorgen…$"

Route117_PokemonDayCare_Text_WomanCantFindHusbandButWillHelp:
	.string "Ich bin die PENSIONSLEITERIN.\p"
	.string "Normalerweise ziehen wir Pokémon\n"
	.string "für TRAINER auf, aber…\p"
	.string "Ich kann meinen Mann nicht finden.\n"
	.string "Er ist heute nicht aufgetaucht…\p"
	.string "Das ist sehr seltsam. Er würde niemals\n"
	.string "einfach verschwinden…\p"
	.string "Aber… ich kann trotzdem deine\n"
	.string "Pokémon aufziehen, wenn du möchtest?\p"
	.string "Soll ich eins für dich aufziehen?$"

Route117_Text_DaycareManThankYouAgain:
	.string "PENSIONSLEITER: Ah, da bist du ja!\p"
	.string "Nochmals vielen Dank, dass du mich\n"
	.string "aus diesem Labor gerettet hast!\p"
	.string "TEAM ROCKET… Ich kann nicht glauben,\n"
	.string "dass sie es hierher geschafft haben!\p"
	.string "Möchtest du aus dem Garten raus?\n"
	.string "Ich gehe kurz aus dem Weg.$"

Route117_Text_DaycareManLetMeHelp:
	.string "PENSIONSLEITER: Moment, ich mache\n"
	.string "Platz für dich!$"

Route117_Text_DaycareManBackToNormal:
	.string "PENSIONSLEITER: So, alles wieder\n"
	.string "normal!\p"
	.string "Wenn du möchtest, dass ich deine\n"
	.string "Pokémon aufziehe, sprich mit meiner\l"
	.string "Frau drinnen!$"

Route117_Text_DaycareManOkayStay:
	.string "PENSIONSLEITER: In Ordnung!\p"
	.string "Sag mir Bescheid, wenn du raus\n"
	.string "möchtest.$"

Route117_Text_DaycareManWantToGoInside:
	.string "Möchtest du in den Garten rein?$"

Route117_Text_DaycareManEnjoyGarden:
	.string "PENSIONSLEITER: Viel Spaß im Garten!\p"
	.string "Wenn du wieder raus möchtest, sag\n"
	.string "mir einfach Bescheid!$"

Route117_Text_DaycareManWantToExit:
	.string "Möchtest du aus dem Garten raus?$"

Route117_EventScript_DaycareMon1::
	lock
	faceplayer
	@ Hole Species von Daycare Slot 0
	setvar VAR_0x8004, 0
	special GetDaycareMonSpecies
	goto_if_eq VAR_RESULT, SPECIES_NONE, Route117_EventScript_NoMonInSlot
	waitse
	playmoncry VAR_RESULT, CRY_MODE_NORMAL
	msgbox Route117_Text_DaycareMonHappy, MSGBOX_DEFAULT
	waitmoncry
	release
	end

Route117_EventScript_DaycareMon2::
	lock
	faceplayer
	@ Hole Species von Daycare Slot 1
	setvar VAR_0x8004, 1
	special GetDaycareMonSpecies
	goto_if_eq VAR_RESULT, SPECIES_NONE, Route117_EventScript_NoMonInSlot
	waitse
	playmoncry VAR_RESULT, CRY_MODE_NORMAL
	msgbox Route117_Text_DaycareMonHappy, MSGBOX_DEFAULT
	waitmoncry
	release
	end

Route117_EventScript_NoMonInSlot::
	@ Sollte nie erreicht werden, aber Sicherheit
	msgbox Route117_Text_NoMonHere, MSGBOX_DEFAULT
	release
	end

@ ========== TEXTE ==========

Route117_Text_DaycareMonHappy:
	.string "Das Pokémon macht fröhliche Geräusche!$"

Route117_Text_NoMonHere:
	.string "…$"

