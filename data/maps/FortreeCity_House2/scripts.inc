FortreeCity_House2_MapScripts::
	.byte 0

FortreeCity_House2_EventScript_HiddenPowerGiver::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TM_HIDDEN_POWER, FortreeCity_House2_EventScript_ExplainHiddenPower
	call_if_unset FLAG_MET_HIDDEN_POWER_GIVER, FortreeCity_House2_EventScript_Greeting
	msgbox FortreeCity_House2_Text_CoinInWhichHand, MSGBOX_DEFAULT
	multichoice 21, 8, MULTI_RIGHTLEFT, TRUE
	switch VAR_RESULT
	case 1, FortreeCity_House2_EventScript_WrongGuess
	msgbox FortreeCity_House2_Text_CorrectTryAgainWhichHand, MSGBOX_DEFAULT
	multichoice 21, 8, MULTI_RIGHTLEFT, TRUE
	switch VAR_RESULT
	case 1, FortreeCity_House2_EventScript_WrongGuess
	msgbox FortreeCity_House2_Text_CorrectTryAgainWhichHand2, MSGBOX_DEFAULT
	multichoice 21, 8, MULTI_RIGHTLEFT, TRUE
	switch VAR_RESULT
	case 0, FortreeCity_House2_EventScript_WrongGuess
	msgbox FortreeCity_House2_Text_YourHiddenPowerHasAwoken, MSGBOX_DEFAULT
	giveitem ITEM_TM_HIDDEN_POWER
	goto_if_eq VAR_RESULT, 0, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM_HIDDEN_POWER
	msgbox FortreeCity_House2_Text_ExplainHiddenPower, MSGBOX_DEFAULT
	release
	end

FortreeCity_House2_EventScript_Greeting::
	msgbox FortreeCity_House2_Text_HiddenPowersArousedByNature, MSGBOX_DEFAULT
	setflag FLAG_MET_HIDDEN_POWER_GIVER
	return

FortreeCity_House2_EventScript_ExplainHiddenPower::
	msgbox FortreeCity_House2_Text_ExplainHiddenPower, MSGBOX_DEFAULT
	release
	end

FortreeCity_House2_EventScript_WrongGuess::
	msgbox FortreeCity_House2_Text_YouGuessedWrong, MSGBOX_DEFAULT
	release
	end

FortreeCity_House2_Text_HiddenPowersArousedByNature::
	.string "Menschen…… POKéMON……\p"
	.string "Ihre versteckten Kräfte werden nur wach,\n"
	.string "wenn sie hier im Dreck der Natur hausen.$"

FortreeCity_House2_Text_CoinInWhichHand::
	.string "Lass die alte Frau mal sehen, ob dein\n"
	.string "Spatzenhirn überhaupt was peilt……\p"
	.string "Ich hab 'ne Münze in der Hand.\p"
	.string "Na? Wo ist sie drin, Bürschchen?\n"
	.string "Links oder rechts? Rate mal!$"

FortreeCity_House2_Text_CorrectTryAgainWhichHand::
	.string "Oh! Ein blindes Huhn findet auch mal……\p"
	.string "Versuchen wir es noch mal.\p"
	.string "In welcher Hand ist die Münze?\n"
	.string "Rechts oder links?$"

FortreeCity_House2_Text_CorrectTryAgainWhichHand2::
	.string "Was? Schon wieder richtig?\n"
	.string "Hast du etwa geschummelt?\p"
	.string "Aller guten Dinge sind drei.\n"
	.string "Links oder rechts? Sag schon!$"

FortreeCity_House2_Text_YourHiddenPowerHasAwoken::
	.string "Oh! Na sieh mal einer an!\n"
	.string "Anscheinend bist du doch nicht so hohl!\p"
	.string "Hier, nimm das und wecke damit die\n"
	.string "mickrigen Kräfte deiner POKéMON.$"

FortreeCity_House2_Text_ExplainHiddenPower::
	.string "KRAFTRESERVE ist 'ne Attacke, die je\n"
	.string "nach POKéMON anders reinhaut.\l"
	.string "Ist halt 'ne Überraschungstüte!$"

FortreeCity_House2_Text_YouGuessedWrong::
	.string "Och, wie traurig!\n"
	.string "Voll daneben geraten, Kleiner.$"

