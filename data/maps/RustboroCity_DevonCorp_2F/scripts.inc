RustboroCity_DevonCorp_2F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RustboroCity_DevonCorp_2F_OnTransition
	.byte 0

RustboroCity_DevonCorp_2F_OnTransition:
	call_if_eq VAR_FOSSIL_RESURRECTION_STATE, 1, RustboroCity_DevonCorp_2F_EventScript_SetFossilReady
	end

RustboroCity_DevonCorp_2F_EventScript_SetFossilReady::
	setvar VAR_FOSSIL_RESURRECTION_STATE, 2
	return

RustboroCity_DevonCorp_2F_EventScript_TalkToPokemonScientist::
	lock
	faceplayer
	call_if_eq VAR_FOSSIL_RESURRECTION_STATE, 1, RustboroCity_DevonCorp_2F_EventScript_SetFossilReady
	msgbox RustboroCity_DevonCorp_2F_Text_DeviceForTalkingToPokemon, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_2F_EventScript_BallScientist::
	lock
	faceplayer
	call_if_eq VAR_FOSSIL_RESURRECTION_STATE, 1, RustboroCity_DevonCorp_2F_EventScript_SetFossilReady
	goto_if_set FLAG_MET_DEVON_EMPLOYEE, RustboroCity_DevonCorp_2F_EventScript_DevelopedBalls
	msgbox RustboroCity_DevonCorp_2F_Text_DevelopingNewBalls, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_2F_EventScript_DevelopedBalls::
	msgbox RustboroCity_DevonCorp_2F_Text_WeFinallyMadeNewBalls, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_2F_EventScript_PokenavScientist::
	lock
	faceplayer
	call_if_eq VAR_FOSSIL_RESURRECTION_STATE, 1, RustboroCity_DevonCorp_2F_EventScript_SetFossilReady
	goto_if_set FLAG_RECEIVED_POKENAV, RustboroCity_DevonCorp_2F_EventScript_HasPokenav
	msgbox RustboroCity_DevonCorp_2F_Text_IMadePokenav, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_2F_EventScript_HasPokenav::
	msgbox RustboroCity_DevonCorp_2F_Text_WowThatsAPokenav, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_2F_EventScript_PokemonDreamsScientist::
	lock
	faceplayer
	call_if_eq VAR_FOSSIL_RESURRECTION_STATE, 1, RustboroCity_DevonCorp_2F_EventScript_SetFossilReady
	msgbox RustboroCity_DevonCorp_2F_Text_DeviceToVisualizePokemonDreams, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_2F_EventScript_FossilScientist::
	lock
	faceplayer
	goto_if_eq VAR_FOSSIL_RESURRECTION_STATE, 2, RustboroCity_DevonCorp_2F_EventScript_FossilMonReady
	goto_if_eq VAR_FOSSIL_RESURRECTION_STATE, 1, RustboroCity_DevonCorp_2F_EventScript_StillRegenerating
	msgbox RustboroCity_DevonCorp_2F_Text_DevelopDeviceToResurrectFossils, MSGBOX_DEFAULT
	checkitem ITEM_HELIX_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_DevonCorp_2F_EventScript_NoticeAnyFossil
	checkitem ITEM_DOME_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_DevonCorp_2F_EventScript_NoticeAnyFossil
	checkitem ITEM_OLD_AMBER
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_DevonCorp_2F_EventScript_NoticeAnyFossil
	checkitem ITEM_ROOT_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_DevonCorp_2F_EventScript_NoticeAnyFossil
	checkitem ITEM_CLAW_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_DevonCorp_2F_EventScript_NoticeAnyFossil
	checkitem ITEM_ARMOR_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_DevonCorp_2F_EventScript_NoticeAnyFossil
	checkitem ITEM_SKULL_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_DevonCorp_2F_EventScript_NoticeAnyFossil
	checkitem ITEM_COVER_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_DevonCorp_2F_EventScript_NoticeAnyFossil
	checkitem ITEM_PLUME_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_DevonCorp_2F_EventScript_NoticeAnyFossil
	checkitem ITEM_JAW_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_DevonCorp_2F_EventScript_NoticeAnyFossil
	checkitem ITEM_SAIL_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_DevonCorp_2F_EventScript_NoticeAnyFossil
	checkitem ITEM_FOSSILIZED_BIRD
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_DevonCorp_2F_EventScript_NoticeAnyFossil
	checkitem ITEM_FOSSILIZED_FISH
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_DevonCorp_2F_EventScript_NoticeAnyFossil
	checkitem ITEM_FOSSILIZED_DRAKE
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_DevonCorp_2F_EventScript_NoticeAnyFossil
	checkitem ITEM_FOSSILIZED_DINO
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_DevonCorp_2F_EventScript_NoticeAnyFossil
	release
	end

RustboroCity_DevonCorp_2F_EventScript_NoticeAnyFossil::
	closemessage
	playse SE_PIN
	applymovement LOCALID_FOSSIL_SCIENTIST, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_FOSSIL_SCIENTIST, Common_Movement_Delay48
	waitmovement 0
	msgbox RustboroCity_DevonCorp_2F_Text_WantToBringFossilBackToLife, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, RustboroCity_DevonCorp_2F_EventScript_DeclineGiveFossil
	goto RustboroCity_DevonCorp_2F_EventScript_ChooseFossil
	end

RustboroCity_DevonCorp_2F_EventScript_GiveSelectedFossil::
	bufferitemname STR_VAR_1, VAR_0x8000
	msgbox RustboroCity_DevonCorp_2F_Text_HandedFossilToResearcher, MSGBOX_DEFAULT
	removeitem VAR_0x8000
	setvar VAR_FOSSIL_RESURRECTION_STATE, 1
	copyvar VAR_WHICH_FOSSIL_REVIVED, VAR_0x8001
	release
	end

RustboroCity_DevonCorp_2F_EventScript_DeclineGiveFossil::
	msgbox RustboroCity_DevonCorp_2F_Text_OhIsThatSo, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_2F_EventScript_StillRegenerating::
	msgbox RustboroCity_DevonCorp_2F_Text_FossilRegeneratorTakesTime, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_2F_EventScript_FossilMonReady::
	copyvar VAR_TEMP_TRANSFERRED_SPECIES, VAR_WHICH_FOSSIL_REVIVED
	bufferspeciesname STR_VAR_2, VAR_TEMP_TRANSFERRED_SPECIES
	msgbox RustboroCity_DevonCorp_2F_Text_FossilizedMonBroughtBackToLife, MSGBOX_DEFAULT
	goto RustboroCity_DevonCorp_2F_EventScript_ReceiveRevivedFossil
	end

RustboroCity_DevonCorp_2F_EventScript_ReceiveRevivedFossil::
	givemon VAR_TEMP_TRANSFERRED_SPECIES, 20
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, RustboroCity_DevonCorp_2F_EventScript_ReceiveRevivedFossilParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, RustboroCity_DevonCorp_2F_EventScript_ReceiveRevivedFossilPC
	goto Common_EventScript_NoMoreRoomForPokemon
	end

RustboroCity_DevonCorp_2F_EventScript_ReceiveRevivedFossilParty::
	call RustboroCity_DevonCorp_2F_EventScript_ReceivedRevivedFossilFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, RustboroCity_DevonCorp_2F_EventScript_FinishReceivingRevivedFossil
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto RustboroCity_DevonCorp_2F_EventScript_FinishReceivingRevivedFossil
	end

RustboroCity_DevonCorp_2F_EventScript_ReceiveRevivedFossilPC::
	call RustboroCity_DevonCorp_2F_EventScript_ReceivedRevivedFossilFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, RustboroCity_DevonCorp_2F_EventScript_TransferRevivedFossilToPC
	call Common_EventScript_NameReceivedBoxMon
	goto RustboroCity_DevonCorp_2F_EventScript_TransferRevivedFossilToPC
	end

RustboroCity_DevonCorp_2F_EventScript_TransferRevivedFossilToPC::
	call Common_EventScript_TransferredToPC
	goto RustboroCity_DevonCorp_2F_EventScript_FinishReceivingRevivedFossil
	end

RustboroCity_DevonCorp_2F_EventScript_ReceivedRevivedFossilFanfare::
	bufferspeciesname STR_VAR_2, VAR_TEMP_TRANSFERRED_SPECIES
	playfanfare MUS_OBTAIN_ITEM
	message RustboroCity_DevonCorp_2F_Text_ReceivedMonFromResearcher
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, VAR_TEMP_TRANSFERRED_SPECIES
	return

RustboroCity_DevonCorp_2F_EventScript_FinishReceivingRevivedFossil::
	setvar VAR_FOSSIL_RESURRECTION_STATE, 0
	setflag FLAG_RECEIVED_REVIVED_FOSSIL_MON
	release
	end

RustboroCity_DevonCorp_2F_EventScript_ChooseFossil::
	call RustboroCity_DevonCorp_2F_EventScript_AddHelixFossilChoice
	call RustboroCity_DevonCorp_2F_EventScript_AddDomeFossilChoice
	call RustboroCity_DevonCorp_2F_EventScript_AddOldAmberChoice
	call RustboroCity_DevonCorp_2F_EventScript_AddRootFossilChoice
	call RustboroCity_DevonCorp_2F_EventScript_AddClawFossilChoice
	call RustboroCity_DevonCorp_2F_EventScript_AddArmorFossilChoice
	call RustboroCity_DevonCorp_2F_EventScript_AddSkullFossilChoice
	call RustboroCity_DevonCorp_2F_EventScript_AddCoverFossilChoice
	call RustboroCity_DevonCorp_2F_EventScript_AddPlumeFossilChoice
	call RustboroCity_DevonCorp_2F_EventScript_AddJawFossilChoice
	call RustboroCity_DevonCorp_2F_EventScript_AddSailFossilChoice
	call RustboroCity_DevonCorp_2F_EventScript_AddFossilizedBirdChoice
	call RustboroCity_DevonCorp_2F_EventScript_AddFossilizedFishChoice
	call RustboroCity_DevonCorp_2F_EventScript_AddFossilizedDrakeChoice
	call RustboroCity_DevonCorp_2F_EventScript_AddFossilizedDinoChoice
	dynmultipush gText_Exit, ITEM_NONE
	dynmultistack 17, 4, FALSE, 6, 0, 0, DYN_MULTICHOICE_CB_NONE
	closemessage
	switch VAR_RESULT
	case ITEM_HELIX_FOSSIL, RustboroCity_DevonCorp_2F_EventScript_ChooseHelixFossil
	case ITEM_DOME_FOSSIL, RustboroCity_DevonCorp_2F_EventScript_ChooseDomeFossil
	case ITEM_OLD_AMBER, RustboroCity_DevonCorp_2F_EventScript_ChooseOldAmber
	case ITEM_ROOT_FOSSIL, RustboroCity_DevonCorp_2F_EventScript_ChooseRootFossil
	case ITEM_CLAW_FOSSIL, RustboroCity_DevonCorp_2F_EventScript_ChooseClawFossil
	case ITEM_ARMOR_FOSSIL, RustboroCity_DevonCorp_2F_EventScript_ChooseArmorFossil
	case ITEM_SKULL_FOSSIL, RustboroCity_DevonCorp_2F_EventScript_ChooseSkullFossil
	case ITEM_COVER_FOSSIL, RustboroCity_DevonCorp_2F_EventScript_ChooseCoverFossil
	case ITEM_PLUME_FOSSIL, RustboroCity_DevonCorp_2F_EventScript_ChoosePlumeFossil
	case ITEM_JAW_FOSSIL, RustboroCity_DevonCorp_2F_EventScript_ChooseJawFossil
	case ITEM_SAIL_FOSSIL, RustboroCity_DevonCorp_2F_EventScript_ChooseSailFossil
	case ITEM_FOSSILIZED_BIRD, RustboroCity_DevonCorp_2F_EventScript_ChooseFossilizedBird
	case ITEM_FOSSILIZED_FISH, RustboroCity_DevonCorp_2F_EventScript_ChooseFossilizedFish
	case ITEM_FOSSILIZED_DRAKE, RustboroCity_DevonCorp_2F_EventScript_ChooseFossilizedDrake
	case ITEM_FOSSILIZED_DINO, RustboroCity_DevonCorp_2F_EventScript_ChooseFossilizedDino
	case ITEM_NONE, RustboroCity_DevonCorp_2F_EventScript_CancelFossilSelect
	case MULTI_B_PRESSED, RustboroCity_DevonCorp_2F_EventScript_CancelFossilSelect
	end

RustboroCity_DevonCorp_2F_EventScript_AddHelixFossilChoice::
	checkitem ITEM_HELIX_FOSSIL
	goto_if_eq VAR_RESULT, FALSE, RustboroCity_DevonCorp_2F_EventScript_Return
	dynmultipush RustboroCity_DevonCorp_2F_Text_MenuHelixFossil, ITEM_HELIX_FOSSIL
	return

RustboroCity_DevonCorp_2F_EventScript_AddDomeFossilChoice::
	checkitem ITEM_DOME_FOSSIL
	goto_if_eq VAR_RESULT, FALSE, RustboroCity_DevonCorp_2F_EventScript_Return
	dynmultipush RustboroCity_DevonCorp_2F_Text_MenuDomeFossil, ITEM_DOME_FOSSIL
	return

RustboroCity_DevonCorp_2F_EventScript_AddOldAmberChoice::
	checkitem ITEM_OLD_AMBER
	goto_if_eq VAR_RESULT, FALSE, RustboroCity_DevonCorp_2F_EventScript_Return
	dynmultipush RustboroCity_DevonCorp_2F_Text_MenuOldAmber, ITEM_OLD_AMBER
	return

RustboroCity_DevonCorp_2F_EventScript_AddRootFossilChoice::
	checkitem ITEM_ROOT_FOSSIL
	goto_if_eq VAR_RESULT, FALSE, RustboroCity_DevonCorp_2F_EventScript_Return
	dynmultipush RustboroCity_DevonCorp_2F_Text_MenuRootFossil, ITEM_ROOT_FOSSIL
	return

RustboroCity_DevonCorp_2F_EventScript_AddClawFossilChoice::
	checkitem ITEM_CLAW_FOSSIL
	goto_if_eq VAR_RESULT, FALSE, RustboroCity_DevonCorp_2F_EventScript_Return
	dynmultipush RustboroCity_DevonCorp_2F_Text_MenuClawFossil, ITEM_CLAW_FOSSIL
	return

RustboroCity_DevonCorp_2F_EventScript_AddArmorFossilChoice::
	checkitem ITEM_ARMOR_FOSSIL
	goto_if_eq VAR_RESULT, FALSE, RustboroCity_DevonCorp_2F_EventScript_Return
	dynmultipush RustboroCity_DevonCorp_2F_Text_MenuArmorFossil, ITEM_ARMOR_FOSSIL
	return

RustboroCity_DevonCorp_2F_EventScript_AddSkullFossilChoice::
	checkitem ITEM_SKULL_FOSSIL
	goto_if_eq VAR_RESULT, FALSE, RustboroCity_DevonCorp_2F_EventScript_Return
	dynmultipush RustboroCity_DevonCorp_2F_Text_MenuSkullFossil, ITEM_SKULL_FOSSIL
	return

RustboroCity_DevonCorp_2F_EventScript_AddCoverFossilChoice::
	checkitem ITEM_COVER_FOSSIL
	goto_if_eq VAR_RESULT, FALSE, RustboroCity_DevonCorp_2F_EventScript_Return
	dynmultipush RustboroCity_DevonCorp_2F_Text_MenuCoverFossil, ITEM_COVER_FOSSIL
	return

RustboroCity_DevonCorp_2F_EventScript_AddPlumeFossilChoice::
	checkitem ITEM_PLUME_FOSSIL
	goto_if_eq VAR_RESULT, FALSE, RustboroCity_DevonCorp_2F_EventScript_Return
	dynmultipush RustboroCity_DevonCorp_2F_Text_MenuPlumeFossil, ITEM_PLUME_FOSSIL
	return

RustboroCity_DevonCorp_2F_EventScript_AddJawFossilChoice::
	checkitem ITEM_JAW_FOSSIL
	goto_if_eq VAR_RESULT, FALSE, RustboroCity_DevonCorp_2F_EventScript_Return
	dynmultipush RustboroCity_DevonCorp_2F_Text_MenuJawFossil, ITEM_JAW_FOSSIL
	return

RustboroCity_DevonCorp_2F_EventScript_AddSailFossilChoice::
	checkitem ITEM_SAIL_FOSSIL
	goto_if_eq VAR_RESULT, FALSE, RustboroCity_DevonCorp_2F_EventScript_Return
	dynmultipush RustboroCity_DevonCorp_2F_Text_MenuSailFossil, ITEM_SAIL_FOSSIL
	return

RustboroCity_DevonCorp_2F_EventScript_AddFossilizedBirdChoice::
	checkitem ITEM_FOSSILIZED_BIRD
	goto_if_eq VAR_RESULT, FALSE, RustboroCity_DevonCorp_2F_EventScript_Return
	dynmultipush RustboroCity_DevonCorp_2F_Text_MenuFossilizedBird, ITEM_FOSSILIZED_BIRD
	return

RustboroCity_DevonCorp_2F_EventScript_AddFossilizedFishChoice::
	checkitem ITEM_FOSSILIZED_FISH
	goto_if_eq VAR_RESULT, FALSE, RustboroCity_DevonCorp_2F_EventScript_Return
	dynmultipush RustboroCity_DevonCorp_2F_Text_MenuFossilizedFish, ITEM_FOSSILIZED_FISH
	return

RustboroCity_DevonCorp_2F_EventScript_AddFossilizedDrakeChoice::
	checkitem ITEM_FOSSILIZED_DRAKE
	goto_if_eq VAR_RESULT, FALSE, RustboroCity_DevonCorp_2F_EventScript_Return
	dynmultipush RustboroCity_DevonCorp_2F_Text_MenuFossilizedDrake, ITEM_FOSSILIZED_DRAKE
	return

RustboroCity_DevonCorp_2F_EventScript_AddFossilizedDinoChoice::
	checkitem ITEM_FOSSILIZED_DINO
	goto_if_eq VAR_RESULT, FALSE, RustboroCity_DevonCorp_2F_EventScript_Return
	dynmultipush RustboroCity_DevonCorp_2F_Text_MenuFossilizedDino, ITEM_FOSSILIZED_DINO
	return

RustboroCity_DevonCorp_2F_EventScript_Return::
	return

RustboroCity_DevonCorp_2F_EventScript_ChooseHelixFossil::
	setvar VAR_0x8000, ITEM_HELIX_FOSSIL
	setvar VAR_0x8001, SPECIES_OMANYTE
	goto RustboroCity_DevonCorp_2F_EventScript_GiveSelectedFossil

RustboroCity_DevonCorp_2F_EventScript_ChooseDomeFossil::
	setvar VAR_0x8000, ITEM_DOME_FOSSIL
	setvar VAR_0x8001, SPECIES_KABUTO
	goto RustboroCity_DevonCorp_2F_EventScript_GiveSelectedFossil

RustboroCity_DevonCorp_2F_EventScript_ChooseOldAmber::
	setvar VAR_0x8000, ITEM_OLD_AMBER
	setvar VAR_0x8001, SPECIES_AERODACTYL
	goto RustboroCity_DevonCorp_2F_EventScript_GiveSelectedFossil

RustboroCity_DevonCorp_2F_EventScript_ChooseClawFossil::
	setvar VAR_0x8000, ITEM_CLAW_FOSSIL
	setvar VAR_0x8001, SPECIES_ANORITH
	goto RustboroCity_DevonCorp_2F_EventScript_GiveSelectedFossil

RustboroCity_DevonCorp_2F_EventScript_ChooseRootFossil::
	setvar VAR_0x8000, ITEM_ROOT_FOSSIL
	setvar VAR_0x8001, SPECIES_LILEEP
	goto RustboroCity_DevonCorp_2F_EventScript_GiveSelectedFossil

RustboroCity_DevonCorp_2F_EventScript_ChooseArmorFossil::
	setvar VAR_0x8000, ITEM_ARMOR_FOSSIL
	setvar VAR_0x8001, SPECIES_SHIELDON
	goto RustboroCity_DevonCorp_2F_EventScript_GiveSelectedFossil

RustboroCity_DevonCorp_2F_EventScript_ChooseSkullFossil::
	setvar VAR_0x8000, ITEM_SKULL_FOSSIL
	setvar VAR_0x8001, SPECIES_CRANIDOS
	goto RustboroCity_DevonCorp_2F_EventScript_GiveSelectedFossil

RustboroCity_DevonCorp_2F_EventScript_ChooseCoverFossil::
	setvar VAR_0x8000, ITEM_COVER_FOSSIL
	setvar VAR_0x8001, SPECIES_TIRTOUGA
	goto RustboroCity_DevonCorp_2F_EventScript_GiveSelectedFossil

RustboroCity_DevonCorp_2F_EventScript_ChoosePlumeFossil::
	setvar VAR_0x8000, ITEM_PLUME_FOSSIL
	setvar VAR_0x8001, SPECIES_ARCHEN
	goto RustboroCity_DevonCorp_2F_EventScript_GiveSelectedFossil

RustboroCity_DevonCorp_2F_EventScript_ChooseJawFossil::
	setvar VAR_0x8000, ITEM_JAW_FOSSIL
	setvar VAR_0x8001, SPECIES_TYRUNT
	goto RustboroCity_DevonCorp_2F_EventScript_GiveSelectedFossil

RustboroCity_DevonCorp_2F_EventScript_ChooseSailFossil::
	setvar VAR_0x8000, ITEM_SAIL_FOSSIL
	setvar VAR_0x8001, SPECIES_AMAURA
	goto RustboroCity_DevonCorp_2F_EventScript_GiveSelectedFossil

RustboroCity_DevonCorp_2F_EventScript_ChooseFossilizedBird::
	setvar VAR_0x8000, ITEM_FOSSILIZED_BIRD
	setvar VAR_0x8001, SPECIES_ARCTOZOLT
	goto RustboroCity_DevonCorp_2F_EventScript_GiveSelectedFossil

RustboroCity_DevonCorp_2F_EventScript_ChooseFossilizedFish::
	setvar VAR_0x8000, ITEM_FOSSILIZED_FISH
	setvar VAR_0x8001, SPECIES_DRACOVISH
	goto RustboroCity_DevonCorp_2F_EventScript_GiveSelectedFossil

RustboroCity_DevonCorp_2F_EventScript_ChooseFossilizedDrake::
	setvar VAR_0x8000, ITEM_FOSSILIZED_DRAKE
	setvar VAR_0x8001, SPECIES_DRACOZOLT
	goto RustboroCity_DevonCorp_2F_EventScript_GiveSelectedFossil

RustboroCity_DevonCorp_2F_EventScript_ChooseFossilizedDino::
	setvar VAR_0x8000, ITEM_FOSSILIZED_DINO
	setvar VAR_0x8001, SPECIES_ARCTOVISH
	goto RustboroCity_DevonCorp_2F_EventScript_GiveSelectedFossil

RustboroCity_DevonCorp_2F_EventScript_CancelFossilSelect::
	release
	end

RustboroCity_DevonCorp_2F_EventScript_MatchCallScientist::
	lock
	faceplayer
	call_if_eq VAR_FOSSIL_RESURRECTION_STATE, 1, RustboroCity_DevonCorp_2F_EventScript_SetFossilReady
	goto_if_ge VAR_RUSTBORO_CITY_STATE, 6, RustboroCity_DevonCorp_2F_EventScript_WorkOnNext
	msgbox RustboroCity_DevonCorp_2F_Text_DevelopNewPokenavFeature, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_2F_EventScript_WorkOnNext::
	msgbox RustboroCity_DevonCorp_2F_Text_WhatToWorkOnNext, MSGBOX_DEFAULT
	release
	end


RustboroCity_DevonCorp_2F_Text_MenuHelixFossil:
	.string "HELIXFOSSIL$"

RustboroCity_DevonCorp_2F_Text_MenuDomeFossil:
	.string "KUPPELFOSSIL$"

RustboroCity_DevonCorp_2F_Text_MenuOldAmber:
	.string "BERNSTEIN$"

RustboroCity_DevonCorp_2F_Text_MenuRootFossil:
	.string "WURZELFOSSIL$"

RustboroCity_DevonCorp_2F_Text_MenuClawFossil:
	.string "KLAUENFOSSIL$"

RustboroCity_DevonCorp_2F_Text_MenuArmorFossil:
	.string "PANZERFOSSIL$"

RustboroCity_DevonCorp_2F_Text_MenuSkullFossil:
	.string "KOPFFOSSIL$"

RustboroCity_DevonCorp_2F_Text_MenuCoverFossil:
	.string "DECKELFOSSIL$"

RustboroCity_DevonCorp_2F_Text_MenuPlumeFossil:
	.string "FEDERFOSSIL$"

RustboroCity_DevonCorp_2F_Text_MenuJawFossil:
	.string "KIEFERFOSSIL$"

RustboroCity_DevonCorp_2F_Text_MenuSailFossil:
	.string "SEGELFOSSIL$"

RustboroCity_DevonCorp_2F_Text_MenuFossilizedBird:
	.string "VERSTEINERTER VOGEL$"

RustboroCity_DevonCorp_2F_Text_MenuFossilizedFish:
	.string "VERSTEINERTER FISCH$"

RustboroCity_DevonCorp_2F_Text_MenuFossilizedDrake:
	.string "VERSTEINERTER DRAKE$"

RustboroCity_DevonCorp_2F_Text_MenuFossilizedDino:
	.string "VERSTEINERTER DINO$"

RustboroCity_DevonCorp_2F_Text_DeviceForTalkingToPokemon:
	.string "Team ROCKET?\n"
	.string "Das ist doch diese alte Gang aus KANTO…?\p"
	.string "Ich dachte, die wären längst zerschlagen.$"

RustboroCity_DevonCorp_2F_Text_DevelopingNewBalls:
	.string "Ich tüftle an neuen POKéBÄLLEN…\p"
	.string "Bisher fliegen sie nur besonders gut\n"
	.string "gegen die Wand.$"

RustboroCity_DevonCorp_2F_Text_WeFinallyMadeNewBalls:
	.string "Endlich! Zwei brandneue Bälle sind da!\p"
	.string "WIEDERBALL - perfekt für Déjà-vu-Fänge.\n"
	.string "TIMERBALL - je länger du kämpfst,\l"
	.string "desto besser fängt er.\p"
	.string "Kein Gimmick. Nur genial.\n"
	.string "Probier sie unbedingt aus!$"

RustboroCity_DevonCorp_2F_Text_IMadePokenav:
	.string "Der POKéNAV? Meine Idee.\p"
	.string "Und ja - manchmal sag ich das auch beim\n"
	.string "ersten Date. Muss man auch mal stolz sein.$"

RustboroCity_DevonCorp_2F_Text_WowThatsAPokenav:
	.string "In letzter Zeit durchsucht der\n"
	.string "PRÄSIDENT unsere alten Datenbanken\l"
	.string "nach “Rocket“…\p"
	.string "Ich wüsste zu gern, was er vermutet.$"

RustboroCity_DevonCorp_2F_Text_DeviceToVisualizePokemonDreams:
	.string "Ein Team ROCKET hier in HOENN?\n"
	.string "Klingt für mich nach\l"
	.string "Verschwörungstheorie.$"

RustboroCity_DevonCorp_2F_Text_DevelopDeviceToResurrectFossils:
	.string "Fossilien reanimieren?\n"
	.string "Challenge accepted!\p"
	.string "Und: BOOM! Es funktioniert tatsächlich!\n"
	.string "JURASSIC PARK lässt grüßen.$"

RustboroCity_DevonCorp_2F_Text_WantToBringFossilBackToLife:
	.string "Whoa, hast du da ein Fossil?\n"
	.string "Willst du's wiederbeleben?\p"
	.string "Kein Ding - mit dem FOSSIL-REGENERATOR\n"
	.string "hauchen wir alten Knochen Leben ein!$"

RustboroCity_DevonCorp_2F_Text_OhIsThatSo:
	.string "Ach ja?\p"
	.string "DEVON hat 'nen Ruf wie Red Bull:\n"
	.string "Hochtechnologie mit Flügeln. Na ja fast.$"

RustboroCity_DevonCorp_2F_Text_TwoFossilsPickOne:
	.string "Whoa, das da sieht fossil aus.\n"
	.string "Willst du daraus wieder ein POKéMON machen?\p"
	.string "Unser FOSSIL-REGENERATOR steht schon in\n"
	.string "den Startlöchern.$"

RustboroCity_DevonCorp_2F_Text_HandedFossilToResearcher:
	.string "Yes! Ab mit dem Teil ins Hightech-Ding.\p"
	.string "{PLAYER} überreicht dem DEVON-FORSCHER\n"
	.string "{STR_VAR_1}.$"

RustboroCity_DevonCorp_2F_Text_FossilRegeneratorTakesTime:
	.string "Der FOSSIL-REGENERATOR ist ziemlich geil…\p"
	.string "Aber langsam wie 'ne Schnecke mit Jetlag.\n"
	.string "Guck dich einfach etwas um in der Zeit.$"

RustboroCity_DevonCorp_2F_Text_FossilizedMonBroughtBackToLife:
	.string "Und fertig ist der Dino aus der Dose!\p"
	.string "Dein Fossil wurde wiederbelebt.\n"
	.string "Sag Hallo zu deinem neuen {STR_VAR_2}!$"

RustboroCity_DevonCorp_2F_Text_ReceivedMonFromResearcher:
	.string "{PLAYER} erhält das {STR_VAR_2} vom\n"
	.string "DEVON-FORSCHER.$"

@ Unused
RustboroCity_DevonCorp_2F_Text_TooManyPokemon:
	.string "Äh… deine Box ist voll.\n"
	.string "Du sammelst echt wie ’n Glurak-Stan.$"

RustboroCity_DevonCorp_2F_Text_DevelopNewPokenavFeature:
	.string "Ich versuch was Neues für den POKéNAV…\p"
	.string "Aber der Code sieht aus wie ein\n"
	.string "Karpador auf Tastatur. Hilfe.$"

RustboroCity_DevonCorp_2F_Text_WhatToWorkOnNext:
	.string "Was soll ich als nächstes bauen?\p"
	.string "DEVON erfüllt quasi jeden Wunsch.\n"
	.string "Außer Kaffee, den muss ich selbst holen.\p"
	.string "Aber hey - besser wird’s als\n"
	.string "Entwickler nicht.$"

RustboroCity_DevonCorp_2F_EventScript_Trade_Scientist::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_LINKING_CORD, RustboroCity_DevonCorp_2F_EventScript_Scientist_After
	msgbox RustboroCity_DevonCorp_2F_Text_InventedLinkingCord, MSGBOX_DEFAULT
	giveitem ITEM_LINKING_CORD
	setflag FLAG_RECEIVED_LINKING_CORD
	release
	end

RustboroCity_DevonCorp_2F_EventScript_Scientist_After::
	msgbox RustboroCity_DevonCorp_2F_Text_ExplainLinkingCord, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_2F_Text_InventedLinkingCord:
	.string "Hehehe! Ich habe eine absolut geniale\n"
	.string "Erfindung gemacht!\p"
	.string "Ein Item, mit dem man POKéMON ganz ohne\n"
	.string "Tauschpartner entwickeln kann!\l"
	.string "Genau das Richtige für dich.\p"
	.string "Du Hurensohn, hast ja eh keine\n"
	.string "Freunde, haha!$"

RustboroCity_DevonCorp_2F_Text_ExplainLinkingCord:
	.string "Gib die VERBUNDSSCHNUR einfach einem\n"
	.string "POKéMON, das sich durch Tausch\l"
	.string "entwickelt, und sieh zu, was passiert!$"

