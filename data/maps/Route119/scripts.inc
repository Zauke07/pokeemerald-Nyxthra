Route119_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, Route119_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, Route119_OnTransition
	.byte 0

Route119_OnResume:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, Route119_EventScript_TryRemoveKecleon
	end

Route119_EventScript_TryRemoveKecleon::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject VAR_LAST_TALKED
	return

Route119_OnTransition:
	call Common_EventScript_SetupRivalGfxId_FromPlayerStyle
	call Common_EventScript_SetupRivalOnBikeGfxId
	call_if_eq VAR_WEATHER_INSTITUTE_STATE, 1, Route119_EventScript_MoveInstituteWorkersDownstairs
	special SetRoute119Weather
	end

Route119_EventScript_MoveInstituteWorkersDownstairs::
	setflag FLAG_HIDE_WEATHER_INSTITUTE_2F_WORKERS
	clearflag FLAG_HIDE_WEATHER_INSTITUTE_1F_WORKERS
	setvar VAR_WEATHER_INSTITUTE_STATE, 2
	return

Route119_EventScript_RivalTrigger1::
	setvar VAR_TEMP_1, 1
	goto Route119_EventScript_RivalEncounter
	end

Route119_EventScript_RivalTrigger2::
	setvar VAR_TEMP_1, 2
	goto Route119_EventScript_RivalEncounter
	end

Route119_EventScript_RivalEncounter::
	lockall
	addobject LOCALID_ROUTE119_RIVAL_ON_BIKE
	call Common_EventScript_SetupRivalMusic
	delay 65
	call_if_eq VAR_TEMP_1, 1, Route119_EventScript_RivalEnter1
	call_if_eq VAR_TEMP_1, 2, Route119_EventScript_RivalEnter2
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	delay 30
	call_if_eq VAR_TEMP_1, 1, Route119_EventScript_SetRivalPos1
	call_if_eq VAR_TEMP_1, 2, Route119_EventScript_SetRivalPos2
	removeobject LOCALID_ROUTE119_RIVAL_ON_BIKE
	addobject LOCALID_ROUTE119_RIVAL
	delay 30
	getplayerstyle
	copyvar VAR_TEMP_2, VAR_RESULT
	switch VAR_TEMP_2
	case STYLE_BRENDAN, Route119_EventScript_StartBattle_Brendan
	case STYLE_MAY, Route119_EventScript_StartBattle_May
	case STYLE_RED, Route119_EventScript_StartBattle_Red
	case STYLE_LEAF, Route119_EventScript_StartBattle_Leaf
	case STYLE_ETHAN, Route119_EventScript_StartBattle_Ethan
	case STYLE_LYRA, Route119_EventScript_StartBattle_Lyra
	case STYLE_LUCAS, Route119_EventScript_StartBattle_Lucas
	case STYLE_DAWN, Route119_EventScript_StartBattle_Dawn
    case STYLE_HILBERT, Route119_EventScript_StartBattle_Hilbert
    case STYLE_HILDA, Route119_EventScript_StartBattle_Hilda
    @case STYLE_NATE, Route119_EventScript_StartBattle_Nate
    @case STYLE_ROSA, Route119_EventScript_StartBattle_Rosa
    @case STYLE_CALEM, Route119_EventScript_StartBattle_Calem
    @case STYLE_SERENA, Route119_EventScript_StartBattle_Serena
    @case STYLE_ELIO, Route119_EventScript_StartBattle_Elio
    @case STYLE_SELENE, Route119_EventScript_StartBattle_Selene
    @case STYLE_VICTOR, Route119_EventScript_StartBattle_Victor
    @case STYLE_GLORIA, Route119_EventScript_StartBattle_Gloria
    @case STYLE_FLORIAN, Route119_EventScript_StartBattle_Florian
    @case STYLE_JULIANA, Route119_EventScript_StartBattle_Juliana
	releaseall
	end

Route119_EventScript_StartBattle_Brendan::
	switch VAR_STARTER_REGION
	case STARTER_REGION_KANTO, Route119_EventScript_StartBrendan_Kanto
	case STARTER_REGION_JOHTO, Route119_EventScript_StartBrendan_Johto
	case STARTER_REGION_HOENN, Route119_EventScript_StartBrendan_Hoenn
	case STARTER_REGION_SINNOH, Route119_EventScript_StartBrendan_Sinnoh
	case STARTER_REGION_UNOVA, Route119_EventScript_StartBrendan_Unova
	case STARTER_REGION_KALOS, Route119_EventScript_StartBrendan_Kalos
	case STARTER_REGION_ALOLA, Route119_EventScript_StartBrendan_Alola
	case STARTER_REGION_GALAR, Route119_EventScript_StartBrendan_Galar
	case STARTER_REGION_PALDEA, Route119_EventScript_StartBrendan_Paldea
	end

Route119_EventScript_StartBattle_May::
	switch VAR_STARTER_REGION
	case STARTER_REGION_KANTO, Route119_EventScript_StartMay_Kanto
	case STARTER_REGION_JOHTO, Route119_EventScript_StartMay_Johto
	case STARTER_REGION_HOENN, Route119_EventScript_StartMay_Hoenn
	case STARTER_REGION_SINNOH, Route119_EventScript_StartMay_Sinnoh
	case STARTER_REGION_UNOVA, Route119_EventScript_StartMay_Unova
	case STARTER_REGION_KALOS, Route119_EventScript_StartMay_Kalos
	case STARTER_REGION_ALOLA, Route119_EventScript_StartMay_Alola
	case STARTER_REGION_GALAR, Route119_EventScript_StartMay_Galar
	case STARTER_REGION_PALDEA, Route119_EventScript_StartMay_Paldea
	end

Route119_EventScript_StartBattle_Red::
	switch VAR_STARTER_REGION
	case STARTER_REGION_KANTO, Route119_EventScript_StartRed_Kanto
	case STARTER_REGION_JOHTO, Route119_EventScript_StartRed_Johto
	case STARTER_REGION_HOENN, Route119_EventScript_StartRed_Hoenn
	case STARTER_REGION_SINNOH, Route119_EventScript_StartRed_Sinnoh
	case STARTER_REGION_UNOVA, Route119_EventScript_StartRed_Unova
	case STARTER_REGION_KALOS, Route119_EventScript_StartRed_Kalos
	case STARTER_REGION_ALOLA, Route119_EventScript_StartRed_Alola
	case STARTER_REGION_GALAR, Route119_EventScript_StartRed_Galar
	case STARTER_REGION_PALDEA, Route119_EventScript_StartRed_Paldea
	end

Route119_EventScript_StartBattle_Leaf::
	switch VAR_STARTER_REGION
	case STARTER_REGION_KANTO, Route119_EventScript_StartLeaf_Kanto
	case STARTER_REGION_JOHTO, Route119_EventScript_StartLeaf_Johto
	case STARTER_REGION_HOENN, Route119_EventScript_StartLeaf_Hoenn
	case STARTER_REGION_SINNOH, Route119_EventScript_StartLeaf_Sinnoh
	case STARTER_REGION_UNOVA, Route119_EventScript_StartLeaf_Unova
	case STARTER_REGION_KALOS, Route119_EventScript_StartLeaf_Kalos
	case STARTER_REGION_ALOLA, Route119_EventScript_StartLeaf_Alola
	case STARTER_REGION_GALAR, Route119_EventScript_StartLeaf_Galar
	case STARTER_REGION_PALDEA, Route119_EventScript_StartLeaf_Paldea
	end

Route119_EventScript_StartBattle_Ethan::
	switch VAR_STARTER_REGION
	case STARTER_REGION_KANTO, Route119_EventScript_StartEthan_Kanto
	case STARTER_REGION_JOHTO, Route119_EventScript_StartEthan_Johto
	case STARTER_REGION_HOENN, Route119_EventScript_StartEthan_Hoenn
	case STARTER_REGION_SINNOH, Route119_EventScript_StartEthan_Sinnoh
	case STARTER_REGION_UNOVA, Route119_EventScript_StartEthan_Unova
	case STARTER_REGION_KALOS, Route119_EventScript_StartEthan_Kalos
	case STARTER_REGION_ALOLA, Route119_EventScript_StartEthan_Alola
	case STARTER_REGION_GALAR, Route119_EventScript_StartEthan_Galar
	case STARTER_REGION_PALDEA, Route119_EventScript_StartEthan_Paldea
	end

Route119_EventScript_StartBattle_Lyra::
	switch VAR_STARTER_REGION
	case STARTER_REGION_KANTO, Route119_EventScript_StartLyra_Kanto
	case STARTER_REGION_JOHTO, Route119_EventScript_StartLyra_Johto
	case STARTER_REGION_HOENN, Route119_EventScript_StartLyra_Hoenn
	case STARTER_REGION_SINNOH, Route119_EventScript_StartLyra_Sinnoh
	case STARTER_REGION_UNOVA, Route119_EventScript_StartLyra_Unova
	case STARTER_REGION_KALOS, Route119_EventScript_StartLyra_Kalos
	case STARTER_REGION_ALOLA, Route119_EventScript_StartLyra_Alola
	case STARTER_REGION_GALAR, Route119_EventScript_StartLyra_Galar
	case STARTER_REGION_PALDEA, Route119_EventScript_StartLyra_Paldea
	end

Route119_EventScript_StartBattle_Lucas::
	switch VAR_STARTER_REGION
	case STARTER_REGION_KANTO, Route119_EventScript_StartLucas_Kanto
	case STARTER_REGION_JOHTO, Route119_EventScript_StartLucas_Johto
	case STARTER_REGION_HOENN, Route119_EventScript_StartLucas_Hoenn
	case STARTER_REGION_SINNOH, Route119_EventScript_StartLucas_Sinnoh
	case STARTER_REGION_UNOVA, Route119_EventScript_StartLucas_Unova
	case STARTER_REGION_KALOS, Route119_EventScript_StartLucas_Kalos
	case STARTER_REGION_ALOLA, Route119_EventScript_StartLucas_Alola
	case STARTER_REGION_GALAR, Route119_EventScript_StartLucas_Galar
	case STARTER_REGION_PALDEA, Route119_EventScript_StartLucas_Paldea
	end

Route119_EventScript_StartBattle_Dawn::
	switch VAR_STARTER_REGION
	case STARTER_REGION_KANTO, Route119_EventScript_StartDawn_Kanto
	case STARTER_REGION_JOHTO, Route119_EventScript_StartDawn_Johto
	case STARTER_REGION_HOENN, Route119_EventScript_StartDawn_Hoenn
	case STARTER_REGION_SINNOH, Route119_EventScript_StartDawn_Sinnoh
	case STARTER_REGION_UNOVA, Route119_EventScript_StartDawn_Unova
	case STARTER_REGION_KALOS, Route119_EventScript_StartDawn_Kalos
	case STARTER_REGION_ALOLA, Route119_EventScript_StartDawn_Alola
	case STARTER_REGION_GALAR, Route119_EventScript_StartDawn_Galar
	case STARTER_REGION_PALDEA, Route119_EventScript_StartDawn_Paldea
	end

Route119_EventScript_StartBattle_Hilbert::
	switch VAR_STARTER_REGION
	case STARTER_REGION_KANTO, Route119_EventScript_StartHilbert_Kanto
	case STARTER_REGION_JOHTO, Route119_EventScript_StartHilbert_Johto
	case STARTER_REGION_HOENN, Route119_EventScript_StartHilbert_Hoenn
	case STARTER_REGION_SINNOH, Route119_EventScript_StartHilbert_Sinnoh
	case STARTER_REGION_UNOVA, Route119_EventScript_StartHilbert_Unova
	case STARTER_REGION_KALOS, Route119_EventScript_StartHilbert_Kalos
	case STARTER_REGION_ALOLA, Route119_EventScript_StartHilbert_Alola
	case STARTER_REGION_GALAR, Route119_EventScript_StartHilbert_Galar
	case STARTER_REGION_PALDEA, Route119_EventScript_StartHilbert_Paldea
	end

Route119_EventScript_StartBattle_Hilda::
	switch VAR_STARTER_REGION
	case STARTER_REGION_KANTO, Route119_EventScript_StartHilda_Kanto
	case STARTER_REGION_JOHTO, Route119_EventScript_StartHilda_Johto
	case STARTER_REGION_HOENN, Route119_EventScript_StartHilda_Hoenn
	case STARTER_REGION_SINNOH, Route119_EventScript_StartHilda_Sinnoh
	case STARTER_REGION_UNOVA, Route119_EventScript_StartHilda_Unova
	case STARTER_REGION_KALOS, Route119_EventScript_StartHilda_Kalos
	case STARTER_REGION_ALOLA, Route119_EventScript_StartHilda_Alola
	case STARTER_REGION_GALAR, Route119_EventScript_StartHilda_Galar
	case STARTER_REGION_PALDEA, Route119_EventScript_StartHilda_Paldea
	end

Route119_EventScript_StartBattle_Nate::
	switch VAR_STARTER_REGION
	case STARTER_REGION_KANTO, Route119_EventScript_StartNate_Kanto
	case STARTER_REGION_JOHTO, Route119_EventScript_StartNate_Johto
	case STARTER_REGION_HOENN, Route119_EventScript_StartNate_Hoenn
	case STARTER_REGION_SINNOH, Route119_EventScript_StartNate_Sinnoh
	case STARTER_REGION_UNOVA, Route119_EventScript_StartNate_Unova
	case STARTER_REGION_KALOS, Route119_EventScript_StartNate_Kalos
	case STARTER_REGION_ALOLA, Route119_EventScript_StartNate_Alola
	case STARTER_REGION_GALAR, Route119_EventScript_StartNate_Galar
	case STARTER_REGION_PALDEA, Route119_EventScript_StartNate_Paldea
	end

Route119_EventScript_StartBattle_Rosa::
	switch VAR_STARTER_REGION
	case STARTER_REGION_KANTO, Route119_EventScript_StartRosa_Kanto
	case STARTER_REGION_JOHTO, Route119_EventScript_StartRosa_Johto
	case STARTER_REGION_HOENN, Route119_EventScript_StartRosa_Hoenn
	case STARTER_REGION_SINNOH, Route119_EventScript_StartRosa_Sinnoh
	case STARTER_REGION_UNOVA, Route119_EventScript_StartRosa_Unova
	case STARTER_REGION_KALOS, Route119_EventScript_StartRosa_Kalos
	case STARTER_REGION_ALOLA, Route119_EventScript_StartRosa_Alola
	case STARTER_REGION_GALAR, Route119_EventScript_StartRosa_Galar
	case STARTER_REGION_PALDEA, Route119_EventScript_StartRosa_Paldea
	end

Route119_EventScript_StartBattle_Calem::
	switch VAR_STARTER_REGION
	case STARTER_REGION_KANTO, Route119_EventScript_StartCalem_Kanto
	case STARTER_REGION_JOHTO, Route119_EventScript_StartCalem_Johto
	case STARTER_REGION_HOENN, Route119_EventScript_StartCalem_Hoenn
	case STARTER_REGION_SINNOH, Route119_EventScript_StartCalem_Sinnoh
	case STARTER_REGION_UNOVA, Route119_EventScript_StartCalem_Unova
	case STARTER_REGION_KALOS, Route119_EventScript_StartCalem_Kalos
	case STARTER_REGION_ALOLA, Route119_EventScript_StartCalem_Alola
	case STARTER_REGION_GALAR, Route119_EventScript_StartCalem_Galar
	case STARTER_REGION_PALDEA, Route119_EventScript_StartCalem_Paldea
	end

Route119_EventScript_StartBattle_Serena::
	switch VAR_STARTER_REGION
	case STARTER_REGION_KANTO, Route119_EventScript_StartSerena_Kanto
	case STARTER_REGION_JOHTO, Route119_EventScript_StartSerena_Johto
	case STARTER_REGION_HOENN, Route119_EventScript_StartSerena_Hoenn
	case STARTER_REGION_SINNOH, Route119_EventScript_StartSerena_Sinnoh
	case STARTER_REGION_UNOVA, Route119_EventScript_StartSerena_Unova
	case STARTER_REGION_KALOS, Route119_EventScript_StartSerena_Kalos
	case STARTER_REGION_ALOLA, Route119_EventScript_StartSerena_Alola
	case STARTER_REGION_GALAR, Route119_EventScript_StartSerena_Galar
	case STARTER_REGION_PALDEA, Route119_EventScript_StartSerena_Paldea
	end

Route119_EventScript_StartBattle_Elio::
	switch VAR_STARTER_REGION
	case STARTER_REGION_KANTO, Route119_EventScript_StartElio_Kanto
	case STARTER_REGION_JOHTO, Route119_EventScript_StartElio_Johto
	case STARTER_REGION_HOENN, Route119_EventScript_StartElio_Hoenn
	case STARTER_REGION_SINNOH, Route119_EventScript_StartElio_Sinnoh
	case STARTER_REGION_UNOVA, Route119_EventScript_StartElio_Unova
	case STARTER_REGION_KALOS, Route119_EventScript_StartElio_Kalos
	case STARTER_REGION_ALOLA, Route119_EventScript_StartElio_Alola
	case STARTER_REGION_GALAR, Route119_EventScript_StartElio_Galar
	case STARTER_REGION_PALDEA, Route119_EventScript_StartElio_Paldea
	end

Route119_EventScript_StartBattle_Selene::
	switch VAR_STARTER_REGION
	case STARTER_REGION_KANTO, Route119_EventScript_StartSelene_Kanto
	case STARTER_REGION_JOHTO, Route119_EventScript_StartSelene_Johto
	case STARTER_REGION_HOENN, Route119_EventScript_StartSelene_Hoenn
	case STARTER_REGION_SINNOH, Route119_EventScript_StartSelene_Sinnoh
	case STARTER_REGION_UNOVA, Route119_EventScript_StartSelene_Unova
	case STARTER_REGION_KALOS, Route119_EventScript_StartSelene_Kalos
	case STARTER_REGION_ALOLA, Route119_EventScript_StartSelene_Alola
	case STARTER_REGION_GALAR, Route119_EventScript_StartSelene_Galar
	case STARTER_REGION_PALDEA, Route119_EventScript_StartSelene_Paldea
	end

Route119_EventScript_StartBattle_Victor::
	switch VAR_STARTER_REGION
	case STARTER_REGION_KANTO, Route119_EventScript_StartVictor_Kanto
	case STARTER_REGION_JOHTO, Route119_EventScript_StartVictor_Johto
	case STARTER_REGION_HOENN, Route119_EventScript_StartVictor_Hoenn
	case STARTER_REGION_SINNOH, Route119_EventScript_StartVictor_Sinnoh
	case STARTER_REGION_UNOVA, Route119_EventScript_StartVictor_Unova
	case STARTER_REGION_KALOS, Route119_EventScript_StartVictor_Kalos
	case STARTER_REGION_ALOLA, Route119_EventScript_StartVictor_Alola
	case STARTER_REGION_GALAR, Route119_EventScript_StartVictor_Galar
	case STARTER_REGION_PALDEA, Route119_EventScript_StartVictor_Paldea
	end

Route119_EventScript_StartBattle_Gloria::
	switch VAR_STARTER_REGION
	case STARTER_REGION_KANTO, Route119_EventScript_StartGloria_Kanto
	case STARTER_REGION_JOHTO, Route119_EventScript_StartGloria_Johto
	case STARTER_REGION_HOENN, Route119_EventScript_StartGloria_Hoenn
	case STARTER_REGION_SINNOH, Route119_EventScript_StartGloria_Sinnoh
	case STARTER_REGION_UNOVA, Route119_EventScript_StartGloria_Unova
	case STARTER_REGION_KALOS, Route119_EventScript_StartGloria_Kalos
	case STARTER_REGION_ALOLA, Route119_EventScript_StartGloria_Alola
	case STARTER_REGION_GALAR, Route119_EventScript_StartGloria_Galar
	case STARTER_REGION_PALDEA, Route119_EventScript_StartGloria_Paldea
	end

Route119_EventScript_StartBattle_Florian::
	switch VAR_STARTER_REGION
	case STARTER_REGION_KANTO, Route119_EventScript_StartFlorian_Kanto
	case STARTER_REGION_JOHTO, Route119_EventScript_StartFlorian_Johto
	case STARTER_REGION_HOENN, Route119_EventScript_StartFlorian_Hoenn
	case STARTER_REGION_SINNOH, Route119_EventScript_StartFlorian_Sinnoh
	case STARTER_REGION_UNOVA, Route119_EventScript_StartFlorian_Unova
	case STARTER_REGION_KALOS, Route119_EventScript_StartFlorian_Kalos
	case STARTER_REGION_ALOLA, Route119_EventScript_StartFlorian_Alola
	case STARTER_REGION_GALAR, Route119_EventScript_StartFlorian_Galar
	case STARTER_REGION_PALDEA, Route119_EventScript_StartFlorian_Paldea
	end

Route119_EventScript_StartBattle_Juliana::
	switch VAR_STARTER_REGION
	case STARTER_REGION_KANTO, Route119_EventScript_StartJuliana_Kanto
	case STARTER_REGION_JOHTO, Route119_EventScript_StartJuliana_Johto
	case STARTER_REGION_HOENN, Route119_EventScript_StartJuliana_Hoenn
	case STARTER_REGION_SINNOH, Route119_EventScript_StartJuliana_Sinnoh
	case STARTER_REGION_UNOVA, Route119_EventScript_StartJuliana_Unova
	case STARTER_REGION_KALOS, Route119_EventScript_StartJuliana_Kalos
	case STARTER_REGION_ALOLA, Route119_EventScript_StartJuliana_Alola
	case STARTER_REGION_GALAR, Route119_EventScript_StartJuliana_Galar
	case STARTER_REGION_PALDEA, Route119_EventScript_StartJuliana_Paldea
	end

Route119_EventScript_GiveFlyHM::
	giveitem ITEM_HM_FLY
	setflag FLAG_RECEIVED_HM_FLY
	return

Route119_EventScript_RivalExitScottArrive::
	closemessage
	call_if_eq VAR_TEMP_1, 1, Route119_EventScript_SetRivalPos1
	call_if_eq VAR_TEMP_1, 2, Route119_EventScript_SetRivalPos2
	removeobject LOCALID_ROUTE119_RIVAL
	addobject LOCALID_ROUTE119_RIVAL_ON_BIKE
	delay 30
	call_if_eq VAR_TEMP_1, 1, Route119_EventScript_RivalExit1
	call_if_eq VAR_TEMP_1, 2, Route119_EventScript_RivalExit2
	removeobject LOCALID_ROUTE119_RIVAL_ON_BIKE
	setvar VAR_ROUTE119_STATE, 1
	savebgm MUS_DUMMY
	fadedefaultbgm
	delay 60
	call_if_eq VAR_TEMP_1, 1, Route119_EventScript_SetScottPos1
	call_if_eq VAR_TEMP_1, 2, Route119_EventScript_SetScottPos2
	addobject LOCALID_ROUTE119_SCOTT
	applymovement LOCALID_ROUTE119_SCOTT, Route119_Movement_ScottEnter
	waitmovement 0
	addvar VAR_SCOTT_STATE, 1
	msgbox Route119_Text_ScottWayToGoBeSeeingYou, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_TEMP_1, 1, Route119_EventScript_ScottExit1
	call_if_eq VAR_TEMP_1, 2, Route119_EventScript_ScottExit2
	removeobject LOCALID_ROUTE119_SCOTT
	releaseall
	end

Route119_EventScript_SetScottPos1::
	setobjectxyperm LOCALID_ROUTE119_SCOTT, 27, 25
	return

Route119_EventScript_SetScottPos2::
	setobjectxyperm LOCALID_ROUTE119_SCOTT, 28, 25
	return

Route119_EventScript_ScottExit1::
	applymovement LOCALID_ROUTE119_SCOTT, Route119_Movement_ScottExit1
	waitmovement 0
	return

Route119_EventScript_ScottExit2::
	applymovement LOCALID_ROUTE119_SCOTT, Route119_Movement_ScottExit2
	waitmovement 0
	return

Route119_EventScript_RivalEnter1::
	applymovement LOCALID_ROUTE119_RIVAL_ON_BIKE, Route119_Movement_RivalEnter1
	waitmovement 0
	return

Route119_EventScript_RivalEnter2::
	applymovement LOCALID_ROUTE119_RIVAL_ON_BIKE, Route119_Movement_RivalEnter2
	waitmovement 0
	return

Route119_EventScript_RivalExit1::
	applymovement LOCALID_PLAYER, Route119_Movement_PlayerWatchRivalExit1
	applymovement LOCALID_ROUTE119_RIVAL_ON_BIKE, Route119_Movement_RivalExit1
	waitmovement 0
	return

Route119_EventScript_RivalExit2::
	applymovement LOCALID_PLAYER, Route119_Movement_PlayerWatchRivalExit2
	applymovement LOCALID_ROUTE119_RIVAL_ON_BIKE, Route119_Movement_RivalExit2
	waitmovement 0
	return

Route119_EventScript_SetRivalPos1::
	setobjectxyperm LOCALID_ROUTE119_RIVAL, 25, 32
	setobjectxyperm LOCALID_ROUTE119_RIVAL_ON_BIKE, 25, 32
	return

Route119_EventScript_SetRivalPos2::
	setobjectxyperm LOCALID_ROUTE119_RIVAL, 26, 32
	setobjectxyperm LOCALID_ROUTE119_RIVAL_ON_BIKE, 26, 32
	return

Route119_Movement_PlayerWatchRivalExit1:
	delay_16
	walk_in_place_faster_right
	delay_8
	walk_in_place_faster_up
	step_end

Route119_Movement_PlayerWatchRivalExit2:
	delay_16
	walk_in_place_faster_left
	delay_8
	walk_in_place_faster_up
	step_end

Route119_Movement_RivalEnter1:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_up
	step_end

Route119_Movement_RivalEnter2:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_up
	step_end

Route119_Movement_RivalExit1:
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

Route119_Movement_RivalExit2:
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

Route119_Movement_ScottEnter:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_down
	step_end

Route119_Movement_ScottExit1:
	walk_up
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

Route119_Movement_ScottExit2:
	walk_up
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

Route119_EventScript_CyclingTriathleteM::
	msgbox Route119_Text_TallGrassSnaresBikeTires, MSGBOX_NPC
	end

Route119_EventScript_RouteSignFortree::
	msgbox Route119_Text_RouteSignFortree, MSGBOX_SIGN
	end

Route119_EventScript_WeatherInstituteSign::
	msgbox Route119_Text_WeatherInstitute, MSGBOX_SIGN
	end

Route119_EventScript_Brent::
	trainerbattle_single TRAINER_BRENT, Route119_Text_BrentIntro, Route119_Text_BrentDefeat
	msgbox Route119_Text_BrentPostBattle, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_Donald::
	trainerbattle_single TRAINER_DONALD, Route119_Text_DonaldIntro, Route119_Text_DonaldDefeat
	msgbox Route119_Text_DonaldPostBattle, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_Taylor::
	trainerbattle_single TRAINER_TAYLOR, Route119_Text_TaylorIntro, Route119_Text_TaylorDefeat
	msgbox Route119_Text_TaylorPostBattle, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_Doug::
	trainerbattle_single TRAINER_DOUG, Route119_Text_DougIntro, Route119_Text_DougDefeat
	msgbox Route119_Text_DougPostBattle, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_Greg::
	trainerbattle_single TRAINER_GREG, Route119_Text_GregIntro, Route119_Text_GregDefeat
	msgbox Route119_Text_GregPostBattle, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_Kent::
	trainerbattle_single TRAINER_KENT, Route119_Text_KentIntro, Route119_Text_KentDefeat
	msgbox Route119_Text_KentPostBattle, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_Jackson::
	trainerbattle_single TRAINER_JACKSON_1, Route119_Text_JacksonIntro, Route119_Text_JacksonDefeat, Route119_EventScript_RegisterJackson
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route119_EventScript_RematchJackson
	msgbox Route119_Text_JacksonPostBattle, MSGBOX_DEFAULT
	release
	end

Route119_EventScript_RegisterJackson::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route119_Text_JacksonRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_JACKSON_1
	release
	end

Route119_EventScript_RematchJackson::
	trainerbattle_rematch TRAINER_JACKSON_1, Route119_Text_JacksonRematchIntro, Route119_Text_JacksonRematchDefeat
	msgbox Route119_Text_JacksonPostRematch, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_Catherine::
	trainerbattle_single TRAINER_CATHERINE_1, Route119_Text_CatherineIntro, Route119_Text_CatherineDefeat, Route119_EventScript_RegisterCatherine
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route119_EventScript_RematchCatherine
	msgbox Route119_Text_CatherinePostBattle, MSGBOX_DEFAULT
	release
	end

Route119_EventScript_RegisterCatherine::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route119_Text_CatherineRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_CATHERINE_1
	release
	end

Route119_EventScript_RematchCatherine::
	trainerbattle_rematch TRAINER_CATHERINE_1, Route119_Text_CatherineRematchIntro, Route119_Text_CatherineRematchDefeat
	msgbox Route119_Text_CatherinePostRematch, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_Hugh::
	trainerbattle_single TRAINER_HUGH, Route119_Text_HughIntro, Route119_Text_HughDefeat
	msgbox Route119_Text_HughPostBattle, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_Phil::
	trainerbattle_single TRAINER_PHIL, Route119_Text_PhilIntro, Route119_Text_PhilDefeat
	msgbox Route119_Text_PhilPostBattle, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_Yasu::
	trainerbattle_single TRAINER_YASU, Route119_Text_YasuIntro, Route119_Text_YasuDefeat
	msgbox Route119_Text_YasuPostBattle, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_Takashi::
	trainerbattle_single TRAINER_TAKASHI, Route119_Text_TakashiIntro, Route119_Text_TakashiDefeat
	msgbox Route119_Text_TakashiPostBattle, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_Hideo::
	trainerbattle_single TRAINER_HIDEO, Route119_Text_HideoIntro, Route119_Text_HideoDefeat
	msgbox Route119_Text_HideoPostBattle, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_Chris::
	trainerbattle_single TRAINER_CHRIS, Route119_Text_ChrisIntro, Route119_Text_ChrisDefeat
	msgbox Route119_Text_ChrisPostBattle, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_Fabian::
	trainerbattle_single TRAINER_FABIAN, Route119_Text_FabianIntro, Route119_Text_FabianDefeat
	msgbox Route119_Text_FabianPostBattle, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_Dayton::
	trainerbattle_single TRAINER_DAYTON, Route119_Text_DaytonIntro, Route119_Text_DaytonDefeat
	msgbox Route119_Text_DaytonPostBattle, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_Rachel::
	trainerbattle_single TRAINER_RACHEL, Route119_Text_RachelIntro, Route119_Text_RachelDefeat
	msgbox Route119_Text_RachelPostBattle, MSGBOX_AUTOCLOSE
	end

Route119_EventScript_BridgeAquaGrunt1::
	lock
	faceplayer
	msgbox Route119_Text_StayAwayFromWeatherInstitute, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

Route119_EventScript_BridgeAquaGrunt2::
	lock
	faceplayer
	msgbox Route119_Text_DontGoNearWeatherInstitute, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

Route119_EventScript_Boy1::
	msgbox Route119_Text_ThoughtFlyByCatchingBirdMons, MSGBOX_NPC
	end

Route119_EventScript_Boy2::
	msgbox Route119_Text_CanYourMonMakeSecretBase, MSGBOX_NPC
	end

Route119_EventScript_TrainerTipsDecoration::
	msgbox Route119_Text_TrainerTipsDecoration, MSGBOX_SIGN
	end

Route119_EventScript_ScottWonAtFortreeGymCall::
	lockall
	pokenavcall Route119_Text_ScottYouWonAtFortreeGym
	waitmessage
	clearflag FLAG_SCOTT_CALL_FORTREE_GYM
	addvar VAR_SCOTT_STATE, 1
	releaseall
	end

Route119_Text_MayIntro:
	.string "{RIVAL}: {PLAYER}{KUN}! Wo warst du?\n"
	.string "Ich habe dich schon gesucht!\p"
	.string "Wie stark bist du geworden?\n"
	.string "Lass mich das für dich herausfinden!\p"
	.string "Bereit? Du und deine Pokémon?\n"
	.string "Natürlich seid ihr das! Los!$"

Route119_Text_MayDefeat:
	.string "Achah!\n"
	.string "{PLAYER}{KUN}, du bist stark!\p"
	.string "Ich hatte schon befürchtet, du\n"
	.string "hättest im Training nachgelassen.$"

Route119_Text_MayPresentForYou:
	.string "{RIVAL}: Aber ich hätte mir absolut keine\n"
	.string "Sorgen zu machen brauchen! Weiter so!\p"
	.string "Und hier!\n"
	.string "Dies ist ein Geschenk für dich!$"

Route119_Text_MayExplainFly:
	.string "{RIVAL}: Setze FLIEGEN ein und deine\n"
	.string "Pokémon bringen dich an jeden Ort, an\l"
	.string "dem du schon einmal warst.\p"
	.string "Aber um FLIEGEN einsetzen zu können,\n"
	.string "brauchst du erst den ORDEN der ARENA\l"
	.string "von BAUMHAUSEN CITY.\l"
	.string "Vergiss das nicht!\p"
	.string "Du solltest mal nach WURZELHEIM\n"
	.string "FLIEGEN.\p"
	.string "Ich wette, deine Mutter macht sich\n"
	.string "schon Sorgen um dich, {PLAYER}{KUN}.\p"
	.string "Nun, wir treffen uns sicher bald wieder!$"

Route119_Text_BrendanIntro:
	.string "{RIVAL}: {PLAYER}! Hier schaust du dich\n"
	.string "also nach Pokémon um?\p"
	.string "Zeig mir, wie gut du geworden bist.\n"
	.string "Ich werde dich jetzt testen!\p"
	.string "Nun!\n"
	.string "Das ist ein Kampf, also kämpfen wir!$"

Route119_Text_BrendanDefeat:
	.string "Hmm…\n"
	.string "Du bist verdammt gut geworden.$"

Route119_Text_BrendanIllGiveYouThis:
	.string "{RIVAL}: Ich sage, du bist so gut, dass\n"
	.string "du überall nach Pokémon suchen kannst.\p"
	.string "Hier, das ist für dich.\n"
	.string "Probier es aus.$"

Route119_Text_BrendanExplainFly:
	.string "{RIVAL}: Setze es ein, und deine\n"
	.string "Pokémon FLIEGEN dich sofort an jeden\l"
	.string "Ort, an dem du schon einmal warst.\p"
	.string "Aber du brauchst den ORDEN der ARENA\n"
	.string "von BAUMHAUSEN CITY dafür.\p"
	.string "Nun ja, ich muss jetzt weiter. Bis bald.$"

Route119_Text_ScottWayToGoBeSeeingYou:
	.string "SCOTT: Hahahaha!\n"
	.string "Mach weiter so, {PLAYER}{KUN}!\p"
	.string "Ich bin gerade einem TRAINER begegnet,\n"
	.string "der auf einem FAHRRAD fuhr.\p"
	.string "Du hast den TRAINER besiegt, stimmt’s?\n"
	.string "Das war ihm anzumerken.\p"
	.string "Das Kind war richtig wütend und sein\n"
	.string "Gesicht war rot vor Zorn.\p"
	.string "Wir laufen uns wirklich oft über den\n"
	.string "Weg! Gehst du jetzt zur ARENA in\l"
	.string "BAUMHAUSEN CITY?\p"
	.string "Ich erwarte, dass du dich dort\n"
	.string "besonders anstrengst. Mach’s gut.$"

Route119_Text_ScottYouWonAtFortreeGym:
	.string "… … … … …\n"
	.string "…\l"
	.string "… … … … …\l"
	.string "Piep!\p"
	.string "SCOTT: Hi {PLAYER}{KUN}, ich bin’s!\p"
	.string "Ich wusste, dass du in der ARENA\n"
	.string "von BAUMHAUSEN gewinnen würdest.\p"
	.string "Deine Stärke…\n"
	.string "Vielleicht bist du wirklich der\l"
	.string "TRAINER, den ich die ganze Zeit\p"
	.string "suche. Ich bin dein Fan, vergiss\n"
	.string "das nicht. Ich werde dir zujubeln.\l"
	.string "Mach weiter so!\p"
	.string "… … … … …\n"
	.string "…\l"
	.string "… … … … …\l"
	.string "Klick!$"

Route119_Text_StayAwayFromWeatherInstitute:
	.string "Wir stehen hier Wache.\p"
	.string "Hey, du! Halt dich bloß von dem KLIMA-\n"
	.string "INSTITUT fern. Da ist es nicht sicher!$"

Route119_Text_DontGoNearWeatherInstitute:
	.string "Wache schieben ist langweilig.\p"
	.string "Hey, du! Komm nicht in die Nähe des\n"
	.string "KLIMA-INSTITUTs.$"

Route119_Text_ThoughtFlyByCatchingBirdMons:
	.string "Ich dachte, FLIEGEN könnte man, indem\n"
	.string "man viele VOGEL-Pokémon fängt, sie\p"
	.string "zusammenbindet und sich dann\n"
	.string "dranhängt.\p"
	.string "Aber es gibt tatsächlich eine VM, die\n"
	.string "FLIEGEN heißt!\p"
	.string "Wenn ich das doch nur eher gewusst\n"
	.string "hätte…$"

Route119_Text_TallGrassSnaresBikeTires:
	.string "Tse… So geht es nicht weiter…\p"
	.string "Das hohe Gras verfängt sich in den \n"
	.string "Speichen des RADs…$"

Route119_Text_CanYourMonMakeSecretBase:
	.string "Kann dein Pokémon GEHEIMPOWER an\n"
	.string "einem Berg von Gras einsetzen und eine\l"
	.string "GEHEIMBASIS einrichten?$"

Route119_Text_RouteSignFortree:
	.string "ROUTE 119\n"
	.string "{RIGHT_ARROW} BAUMHAUSEN CITY$"

Route119_Text_WeatherInstitute:
	.string "KLIMA-INSTITUT$"

Route119_Text_TrainerTipsDecoration:
	.string "TIPPS für TRAINER\p"
	.string "In der GEHEIMBASIS können bis zu 16\n"
	.string "Dekorationen und Möbel untergebracht\l"
	.string "werden.\p"
	.string "Nimm deine Lieblingsitems und richte dir\n"
	.string "deine GEHEIMBASIS ganz nach deinem\l"
	.string "Geschmack ein.$"

Route119_EventScript_Froxy::
	msgbox Route119_Text_Froxy, MSGBOX_NPC
	end

Route119_Text_Froxy:
	.string "Tipp:\p"
	.string "Auf dieser Route versteckt sich ein\n"
	.string "Starter aus der 6 Generation mit\l"
	.string "einer Spawnrate von 1%!\p"
	.string "Welches es ist, musst du selbst\n"
	.string "herausfinden :D !$"

Route119_EventScript_StartBrendan_Kanto::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartBrendanBattleBULBASAUR
	case 1, Route119_EventScript_StartBrendanBattleCHARMANDER
	case 2, Route119_EventScript_StartBrendanBattleSQUIRTLE
	end

Route119_EventScript_StartBrendanBattleBULBASAUR::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_119_BULBASAUR, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartBrendanBattleCHARMANDER::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_119_CHARMANDER, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartBrendanBattleSQUIRTLE::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_119_SQUIRTLE, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartBrendan_Johto::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartBrendanBattleCHIKORITA
	case 1, Route119_EventScript_StartBrendanBattleCYNDAQUIL
	case 2, Route119_EventScript_StartBrendanBattleTOTODILE
	end

Route119_EventScript_StartBrendanBattleCHIKORITA::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_119_CHIKORITA, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartBrendanBattleCYNDAQUIL::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_119_CYNDAQUIL, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartBrendanBattleTOTODILE::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_119_TOTODILE, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartBrendan_Hoenn::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartBrendanBattleTREECKO
	case 1, Route119_EventScript_StartBrendanBattleTORCHIC
	case 2, Route119_EventScript_StartBrendanBattleMUDKIP
	end

Route119_EventScript_StartBrendanBattleTREECKO::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_119_TREECKO, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartBrendanBattleTORCHIC::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_119_TORCHIC, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartBrendanBattleMUDKIP::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_119_MUDKIP, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartBrendan_Sinnoh::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartBrendanBattleTURTWIG
	case 1, Route119_EventScript_StartBrendanBattleCHIMCHAR
	case 2, Route119_EventScript_StartBrendanBattlePIPLUP
	end

Route119_EventScript_StartBrendanBattleTURTWIG::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_119_TURTWIG, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartBrendanBattleCHIMCHAR::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_119_CHIMCHAR, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartBrendanBattlePIPLUP::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_119_PIPLUP, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartBrendan_Unova::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartBrendanBattleSNIVY
	case 1, Route119_EventScript_StartBrendanBattleTEPIG
	case 2, Route119_EventScript_StartBrendanBattleOSHAWOTT
	end

Route119_EventScript_StartBrendanBattleSNIVY::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_119_SNIVY, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartBrendanBattleTEPIG::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_119_TEPIG, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartBrendanBattleOSHAWOTT::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_119_OSHAWOTT, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartBrendan_Kalos::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartBrendanBattleCHESPIN
	case 1, Route119_EventScript_StartBrendanBattleFENNEKIN
	case 2, Route119_EventScript_StartBrendanBattleFROAKIE
	end

Route119_EventScript_StartBrendanBattleCHESPIN::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_119_CHESPIN, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartBrendanBattleFENNEKIN::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_119_FENNEKIN, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartBrendanBattleFROAKIE::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_119_FROAKIE, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartBrendan_Alola::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartBrendanBattleROWLET
	case 1, Route119_EventScript_StartBrendanBattleLITTEN
	case 2, Route119_EventScript_StartBrendanBattlePOPPLIO
	end

Route119_EventScript_StartBrendanBattleROWLET::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_119_ROWLET, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartBrendanBattleLITTEN::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_119_LITTEN, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartBrendanBattlePOPPLIO::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_119_POPPLIO, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartBrendan_Galar::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartBrendanBattleGROOKEY
	case 1, Route119_EventScript_StartBrendanBattleSCORBUNNY
	case 2, Route119_EventScript_StartBrendanBattleSOBBLE
	end

Route119_EventScript_StartBrendanBattleGROOKEY::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_119_GROOKEY, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartBrendanBattleSCORBUNNY::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_119_SCORBUNNY, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartBrendanBattleSOBBLE::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_119_SOBBLE, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartBrendan_Paldea::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartBrendanBattleSPRIGATITO
	case 1, Route119_EventScript_StartBrendanBattleFUECOCO
	case 2, Route119_EventScript_StartBrendanBattleQUAXLY
	end

Route119_EventScript_StartBrendanBattleSPRIGATITO::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_119_SPRIGATITO, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartBrendanBattleFUECOCO::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_119_FUECOCO, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartBrendanBattleQUAXLY::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_119_QUAXLY, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartMay_Kanto::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartMayBattleBULBASAUR
	case 1, Route119_EventScript_StartMayBattleCHARMANDER
	case 2, Route119_EventScript_StartMayBattleSQUIRTLE
	end

Route119_EventScript_StartMayBattleBULBASAUR::
	trainerbattle_no_intro TRAINER_MAY_ROUTE_119_BULBASAUR, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartMayBattleCHARMANDER::
	trainerbattle_no_intro TRAINER_MAY_ROUTE_119_CHARMANDER, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartMayBattleSQUIRTLE::
	trainerbattle_no_intro TRAINER_MAY_ROUTE_119_SQUIRTLE, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartMay_Johto::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartMayBattleCHIKORITA
	case 1, Route119_EventScript_StartMayBattleCYNDAQUIL
	case 2, Route119_EventScript_StartMayBattleTOTODILE
	end

Route119_EventScript_StartMayBattleCHIKORITA::
	trainerbattle_no_intro TRAINER_MAY_ROUTE_119_CHIKORITA, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartMayBattleCYNDAQUIL::
	trainerbattle_no_intro TRAINER_MAY_ROUTE_119_CYNDAQUIL, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartMayBattleTOTODILE::
	trainerbattle_no_intro TRAINER_MAY_ROUTE_119_TOTODILE, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartMay_Hoenn::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartMayBattleTREECKO
	case 1, Route119_EventScript_StartMayBattleTORCHIC
	case 2, Route119_EventScript_StartMayBattleMUDKIP
	end

Route119_EventScript_StartMayBattleTREECKO::
	trainerbattle_no_intro TRAINER_MAY_ROUTE_119_TREECKO, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartMayBattleTORCHIC::
	trainerbattle_no_intro TRAINER_MAY_ROUTE_119_TORCHIC, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartMayBattleMUDKIP::
	trainerbattle_no_intro TRAINER_MAY_ROUTE_119_MUDKIP, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartMay_Sinnoh::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartMayBattleTURTWIG
	case 1, Route119_EventScript_StartMayBattleCHIMCHAR
	case 2, Route119_EventScript_StartMayBattlePIPLUP
	end

Route119_EventScript_StartMayBattleTURTWIG::
	trainerbattle_no_intro TRAINER_MAY_ROUTE_119_TURTWIG, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartMayBattleCHIMCHAR::
	trainerbattle_no_intro TRAINER_MAY_ROUTE_119_CHIMCHAR, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartMayBattlePIPLUP::
	trainerbattle_no_intro TRAINER_MAY_ROUTE_119_PIPLUP, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartMay_Unova::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartMayBattleSNIVY
	case 1, Route119_EventScript_StartMayBattleTEPIG
	case 2, Route119_EventScript_StartMayBattleOSHAWOTT
	end

Route119_EventScript_StartMayBattleSNIVY::
	trainerbattle_no_intro TRAINER_MAY_ROUTE_119_SNIVY, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartMayBattleTEPIG::
	trainerbattle_no_intro TRAINER_MAY_ROUTE_119_TEPIG, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartMayBattleOSHAWOTT::
	trainerbattle_no_intro TRAINER_MAY_ROUTE_119_OSHAWOTT, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartMay_Kalos::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartMayBattleCHESPIN
	case 1, Route119_EventScript_StartMayBattleFENNEKIN
	case 2, Route119_EventScript_StartMayBattleFROAKIE
	end

Route119_EventScript_StartMayBattleCHESPIN::
	trainerbattle_no_intro TRAINER_MAY_ROUTE_119_CHESPIN, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartMayBattleFENNEKIN::
	trainerbattle_no_intro TRAINER_MAY_ROUTE_119_FENNEKIN, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartMayBattleFROAKIE::
	trainerbattle_no_intro TRAINER_MAY_ROUTE_119_FROAKIE, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartMay_Alola::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartMayBattleROWLET
	case 1, Route119_EventScript_StartMayBattleLITTEN
	case 2, Route119_EventScript_StartMayBattlePOPPLIO
	end

Route119_EventScript_StartMayBattleROWLET::
	trainerbattle_no_intro TRAINER_MAY_ROUTE_119_ROWLET, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartMayBattleLITTEN::
	trainerbattle_no_intro TRAINER_MAY_ROUTE_119_LITTEN, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartMayBattlePOPPLIO::
	trainerbattle_no_intro TRAINER_MAY_ROUTE_119_POPPLIO, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartMay_Galar::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartMayBattleGROOKEY
	case 1, Route119_EventScript_StartMayBattleSCORBUNNY
	case 2, Route119_EventScript_StartMayBattleSOBBLE
	end

Route119_EventScript_StartMayBattleGROOKEY::
	trainerbattle_no_intro TRAINER_MAY_ROUTE_119_GROOKEY, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartMayBattleSCORBUNNY::
	trainerbattle_no_intro TRAINER_MAY_ROUTE_119_SCORBUNNY, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartMayBattleSOBBLE::
	trainerbattle_no_intro TRAINER_MAY_ROUTE_119_SOBBLE, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartMay_Paldea::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartMayBattleSPRIGATITO
	case 1, Route119_EventScript_StartMayBattleFUECOCO
	case 2, Route119_EventScript_StartMayBattleQUAXLY
	end

Route119_EventScript_StartMayBattleSPRIGATITO::
	trainerbattle_no_intro TRAINER_MAY_ROUTE_119_SPRIGATITO, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartMayBattleFUECOCO::
	trainerbattle_no_intro TRAINER_MAY_ROUTE_119_FUECOCO, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartMayBattleQUAXLY::
	trainerbattle_no_intro TRAINER_MAY_ROUTE_119_QUAXLY, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartRed_Kanto::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartRedBattleBULBASAUR
	case 1, Route119_EventScript_StartRedBattleCHARMANDER
	case 2, Route119_EventScript_StartRedBattleSQUIRTLE
	end

Route119_EventScript_StartRedBattleBULBASAUR::
	trainerbattle_no_intro TRAINER_RED_ROUTE_119_BULBASAUR, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartRedBattleCHARMANDER::
	trainerbattle_no_intro TRAINER_RED_ROUTE_119_CHARMANDER, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartRedBattleSQUIRTLE::
	trainerbattle_no_intro TRAINER_RED_ROUTE_119_SQUIRTLE, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartRed_Johto::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartRedBattleCHIKORITA
	case 1, Route119_EventScript_StartRedBattleCYNDAQUIL
	case 2, Route119_EventScript_StartRedBattleTOTODILE
	end

Route119_EventScript_StartRedBattleCHIKORITA::
	trainerbattle_no_intro TRAINER_RED_ROUTE_119_CHIKORITA, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartRedBattleCYNDAQUIL::
	trainerbattle_no_intro TRAINER_RED_ROUTE_119_CYNDAQUIL, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartRedBattleTOTODILE::
	trainerbattle_no_intro TRAINER_RED_ROUTE_119_TOTODILE, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartRed_Hoenn::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartRedBattleTREECKO
	case 1, Route119_EventScript_StartRedBattleTORCHIC
	case 2, Route119_EventScript_StartRedBattleMUDKIP
	end

Route119_EventScript_StartRedBattleTREECKO::
	trainerbattle_no_intro TRAINER_RED_ROUTE_119_TREECKO, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartRedBattleTORCHIC::
	trainerbattle_no_intro TRAINER_RED_ROUTE_119_TORCHIC, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartRedBattleMUDKIP::
	trainerbattle_no_intro TRAINER_RED_ROUTE_119_MUDKIP, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartRed_Sinnoh::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartRedBattleTURTWIG
	case 1, Route119_EventScript_StartRedBattleCHIMCHAR
	case 2, Route119_EventScript_StartRedBattlePIPLUP
	end

Route119_EventScript_StartRedBattleTURTWIG::
	trainerbattle_no_intro TRAINER_RED_ROUTE_119_TURTWIG, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartRedBattleCHIMCHAR::
	trainerbattle_no_intro TRAINER_RED_ROUTE_119_CHIMCHAR, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartRedBattlePIPLUP::
	trainerbattle_no_intro TRAINER_RED_ROUTE_119_PIPLUP, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartRed_Unova::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartRedBattleSNIVY
	case 1, Route119_EventScript_StartRedBattleTEPIG
	case 2, Route119_EventScript_StartRedBattleOSHAWOTT
	end

Route119_EventScript_StartRedBattleSNIVY::
	trainerbattle_no_intro TRAINER_RED_ROUTE_119_SNIVY, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartRedBattleTEPIG::
	trainerbattle_no_intro TRAINER_RED_ROUTE_119_TEPIG, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartRedBattleOSHAWOTT::
	trainerbattle_no_intro TRAINER_RED_ROUTE_119_OSHAWOTT, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartRed_Kalos::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartRedBattleCHESPIN
	case 1, Route119_EventScript_StartRedBattleFENNEKIN
	case 2, Route119_EventScript_StartRedBattleFROAKIE
	end

Route119_EventScript_StartRedBattleCHESPIN::
	trainerbattle_no_intro TRAINER_RED_ROUTE_119_CHESPIN, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartRedBattleFENNEKIN::
	trainerbattle_no_intro TRAINER_RED_ROUTE_119_FENNEKIN, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartRedBattleFROAKIE::
	trainerbattle_no_intro TRAINER_RED_ROUTE_119_FROAKIE, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartRed_Alola::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartRedBattleROWLET
	case 1, Route119_EventScript_StartRedBattleLITTEN
	case 2, Route119_EventScript_StartRedBattlePOPPLIO
	end

Route119_EventScript_StartRedBattleROWLET::
	trainerbattle_no_intro TRAINER_RED_ROUTE_119_ROWLET, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartRedBattleLITTEN::
	trainerbattle_no_intro TRAINER_RED_ROUTE_119_LITTEN, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartRedBattlePOPPLIO::
	trainerbattle_no_intro TRAINER_RED_ROUTE_119_POPPLIO, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartRed_Galar::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartRedBattleGROOKEY
	case 1, Route119_EventScript_StartRedBattleSCORBUNNY
	case 2, Route119_EventScript_StartRedBattleSOBBLE
	end

Route119_EventScript_StartRedBattleGROOKEY::
	trainerbattle_no_intro TRAINER_RED_ROUTE_119_GROOKEY, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartRedBattleSCORBUNNY::
	trainerbattle_no_intro TRAINER_RED_ROUTE_119_SCORBUNNY, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartRedBattleSOBBLE::
	trainerbattle_no_intro TRAINER_RED_ROUTE_119_SOBBLE, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartRed_Paldea::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartRedBattleSPRIGATITO
	case 1, Route119_EventScript_StartRedBattleFUECOCO
	case 2, Route119_EventScript_StartRedBattleQUAXLY
	end

Route119_EventScript_StartRedBattleSPRIGATITO::
	trainerbattle_no_intro TRAINER_RED_ROUTE_119_SPRIGATITO, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartRedBattleFUECOCO::
	trainerbattle_no_intro TRAINER_RED_ROUTE_119_FUECOCO, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartRedBattleQUAXLY::
	trainerbattle_no_intro TRAINER_RED_ROUTE_119_QUAXLY, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartLeaf_Kanto::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartLeafBattleBULBASAUR
	case 1, Route119_EventScript_StartLeafBattleCHARMANDER
	case 2, Route119_EventScript_StartLeafBattleSQUIRTLE
	end

Route119_EventScript_StartLeafBattleBULBASAUR::
	trainerbattle_no_intro TRAINER_LEAF_ROUTE_119_BULBASAUR, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartLeafBattleCHARMANDER::
	trainerbattle_no_intro TRAINER_LEAF_ROUTE_119_CHARMANDER, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartLeafBattleSQUIRTLE::
	trainerbattle_no_intro TRAINER_LEAF_ROUTE_119_SQUIRTLE, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartLeaf_Johto::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartLeafBattleCHIKORITA
	case 1, Route119_EventScript_StartLeafBattleCYNDAQUIL
	case 2, Route119_EventScript_StartLeafBattleTOTODILE
	end

Route119_EventScript_StartLeafBattleCHIKORITA::
	trainerbattle_no_intro TRAINER_LEAF_ROUTE_119_CHIKORITA, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartLeafBattleCYNDAQUIL::
	trainerbattle_no_intro TRAINER_LEAF_ROUTE_119_CYNDAQUIL, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartLeafBattleTOTODILE::
	trainerbattle_no_intro TRAINER_LEAF_ROUTE_119_TOTODILE, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartLeaf_Hoenn::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartLeafBattleTREECKO
	case 1, Route119_EventScript_StartLeafBattleTORCHIC
	case 2, Route119_EventScript_StartLeafBattleMUDKIP
	end

Route119_EventScript_StartLeafBattleTREECKO::
	trainerbattle_no_intro TRAINER_LEAF_ROUTE_119_TREECKO, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartLeafBattleTORCHIC::
	trainerbattle_no_intro TRAINER_LEAF_ROUTE_119_TORCHIC, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartLeafBattleMUDKIP::
	trainerbattle_no_intro TRAINER_LEAF_ROUTE_119_MUDKIP, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartLeaf_Sinnoh::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartLeafBattleTURTWIG
	case 1, Route119_EventScript_StartLeafBattleCHIMCHAR
	case 2, Route119_EventScript_StartLeafBattlePIPLUP
	end

Route119_EventScript_StartLeafBattleTURTWIG::
	trainerbattle_no_intro TRAINER_LEAF_ROUTE_119_TURTWIG, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartLeafBattleCHIMCHAR::
	trainerbattle_no_intro TRAINER_LEAF_ROUTE_119_CHIMCHAR, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartLeafBattlePIPLUP::
	trainerbattle_no_intro TRAINER_LEAF_ROUTE_119_PIPLUP, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartLeaf_Unova::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartLeafBattleSNIVY
	case 1, Route119_EventScript_StartLeafBattleTEPIG
	case 2, Route119_EventScript_StartLeafBattleOSHAWOTT
	end

Route119_EventScript_StartLeafBattleSNIVY::
	trainerbattle_no_intro TRAINER_LEAF_ROUTE_119_SNIVY, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartLeafBattleTEPIG::
	trainerbattle_no_intro TRAINER_LEAF_ROUTE_119_TEPIG, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartLeafBattleOSHAWOTT::
	trainerbattle_no_intro TRAINER_LEAF_ROUTE_119_OSHAWOTT, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartLeaf_Kalos::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartLeafBattleCHESPIN
	case 1, Route119_EventScript_StartLeafBattleFENNEKIN
	case 2, Route119_EventScript_StartLeafBattleFROAKIE
	end

Route119_EventScript_StartLeafBattleCHESPIN::
	trainerbattle_no_intro TRAINER_LEAF_ROUTE_119_CHESPIN, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartLeafBattleFENNEKIN::
	trainerbattle_no_intro TRAINER_LEAF_ROUTE_119_FENNEKIN, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartLeafBattleFROAKIE::
	trainerbattle_no_intro TRAINER_LEAF_ROUTE_119_FROAKIE, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartLeaf_Alola::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartLeafBattleROWLET
	case 1, Route119_EventScript_StartLeafBattleLITTEN
	case 2, Route119_EventScript_StartLeafBattlePOPPLIO
	end

Route119_EventScript_StartLeafBattleROWLET::
	trainerbattle_no_intro TRAINER_LEAF_ROUTE_119_ROWLET, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartLeafBattleLITTEN::
	trainerbattle_no_intro TRAINER_LEAF_ROUTE_119_LITTEN, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartLeafBattlePOPPLIO::
	trainerbattle_no_intro TRAINER_LEAF_ROUTE_119_POPPLIO, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartLeaf_Galar::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartLeafBattleGROOKEY
	case 1, Route119_EventScript_StartLeafBattleSCORBUNNY
	case 2, Route119_EventScript_StartLeafBattleSOBBLE
	end

Route119_EventScript_StartLeafBattleGROOKEY::
	trainerbattle_no_intro TRAINER_LEAF_ROUTE_119_GROOKEY, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartLeafBattleSCORBUNNY::
	trainerbattle_no_intro TRAINER_LEAF_ROUTE_119_SCORBUNNY, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartLeafBattleSOBBLE::
	trainerbattle_no_intro TRAINER_LEAF_ROUTE_119_SOBBLE, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartLeaf_Paldea::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartLeafBattleSPRIGATITO
	case 1, Route119_EventScript_StartLeafBattleFUECOCO
	case 2, Route119_EventScript_StartLeafBattleQUAXLY
	end

Route119_EventScript_StartLeafBattleSPRIGATITO::
	trainerbattle_no_intro TRAINER_LEAF_ROUTE_119_SPRIGATITO, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartLeafBattleFUECOCO::
	trainerbattle_no_intro TRAINER_LEAF_ROUTE_119_FUECOCO, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartLeafBattleQUAXLY::
	trainerbattle_no_intro TRAINER_LEAF_ROUTE_119_QUAXLY, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartEthan_Kanto::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartEthanBattleBULBASAUR
	case 1, Route119_EventScript_StartEthanBattleCHARMANDER
	case 2, Route119_EventScript_StartEthanBattleSQUIRTLE
	end

Route119_EventScript_StartEthanBattleBULBASAUR::
	trainerbattle_no_intro TRAINER_ETHAN_ROUTE_119_BULBASAUR, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartEthanBattleCHARMANDER::
	trainerbattle_no_intro TRAINER_ETHAN_ROUTE_119_CHARMANDER, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartEthanBattleSQUIRTLE::
	trainerbattle_no_intro TRAINER_ETHAN_ROUTE_119_SQUIRTLE, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartEthan_Johto::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartEthanBattleCHIKORITA
	case 1, Route119_EventScript_StartEthanBattleCYNDAQUIL
	case 2, Route119_EventScript_StartEthanBattleTOTODILE
	end

Route119_EventScript_StartEthanBattleCHIKORITA::
	trainerbattle_no_intro TRAINER_ETHAN_ROUTE_119_CHIKORITA, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartEthanBattleCYNDAQUIL::
	trainerbattle_no_intro TRAINER_ETHAN_ROUTE_119_CYNDAQUIL, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartEthanBattleTOTODILE::
	trainerbattle_no_intro TRAINER_ETHAN_ROUTE_119_TOTODILE, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartEthan_Hoenn::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartEthanBattleTREECKO
	case 1, Route119_EventScript_StartEthanBattleTORCHIC
	case 2, Route119_EventScript_StartEthanBattleMUDKIP
	end

Route119_EventScript_StartEthanBattleTREECKO::
	trainerbattle_no_intro TRAINER_ETHAN_ROUTE_119_TREECKO, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartEthanBattleTORCHIC::
	trainerbattle_no_intro TRAINER_ETHAN_ROUTE_119_TORCHIC, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartEthanBattleMUDKIP::
	trainerbattle_no_intro TRAINER_ETHAN_ROUTE_119_MUDKIP, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartEthan_Sinnoh::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartEthanBattleTURTWIG
	case 1, Route119_EventScript_StartEthanBattleCHIMCHAR
	case 2, Route119_EventScript_StartEthanBattlePIPLUP
	end

Route119_EventScript_StartEthanBattleTURTWIG::
	trainerbattle_no_intro TRAINER_ETHAN_ROUTE_119_TURTWIG, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartEthanBattleCHIMCHAR::
	trainerbattle_no_intro TRAINER_ETHAN_ROUTE_119_CHIMCHAR, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartEthanBattlePIPLUP::
	trainerbattle_no_intro TRAINER_ETHAN_ROUTE_119_PIPLUP, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartEthan_Unova::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartEthanBattleSNIVY
	case 1, Route119_EventScript_StartEthanBattleTEPIG
	case 2, Route119_EventScript_StartEthanBattleOSHAWOTT
	end

Route119_EventScript_StartEthanBattleSNIVY::
	trainerbattle_no_intro TRAINER_ETHAN_ROUTE_119_SNIVY, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartEthanBattleTEPIG::
	trainerbattle_no_intro TRAINER_ETHAN_ROUTE_119_TEPIG, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartEthanBattleOSHAWOTT::
	trainerbattle_no_intro TRAINER_ETHAN_ROUTE_119_OSHAWOTT, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartEthan_Kalos::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartEthanBattleCHESPIN
	case 1, Route119_EventScript_StartEthanBattleFENNEKIN
	case 2, Route119_EventScript_StartEthanBattleFROAKIE
	end

Route119_EventScript_StartEthanBattleCHESPIN::
	trainerbattle_no_intro TRAINER_ETHAN_ROUTE_119_CHESPIN, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartEthanBattleFENNEKIN::
	trainerbattle_no_intro TRAINER_ETHAN_ROUTE_119_FENNEKIN, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartEthanBattleFROAKIE::
	trainerbattle_no_intro TRAINER_ETHAN_ROUTE_119_FROAKIE, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartEthan_Alola::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartEthanBattleROWLET
	case 1, Route119_EventScript_StartEthanBattleLITTEN
	case 2, Route119_EventScript_StartEthanBattlePOPPLIO
	end

Route119_EventScript_StartEthanBattleROWLET::
	trainerbattle_no_intro TRAINER_ETHAN_ROUTE_119_ROWLET, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartEthanBattleLITTEN::
	trainerbattle_no_intro TRAINER_ETHAN_ROUTE_119_LITTEN, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartEthanBattlePOPPLIO::
	trainerbattle_no_intro TRAINER_ETHAN_ROUTE_119_POPPLIO, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartEthan_Galar::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartEthanBattleGROOKEY
	case 1, Route119_EventScript_StartEthanBattleSCORBUNNY
	case 2, Route119_EventScript_StartEthanBattleSOBBLE
	end

Route119_EventScript_StartEthanBattleGROOKEY::
	trainerbattle_no_intro TRAINER_ETHAN_ROUTE_119_GROOKEY, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartEthanBattleSCORBUNNY::
	trainerbattle_no_intro TRAINER_ETHAN_ROUTE_119_SCORBUNNY, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartEthanBattleSOBBLE::
	trainerbattle_no_intro TRAINER_ETHAN_ROUTE_119_SOBBLE, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartEthan_Paldea::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartEthanBattleSPRIGATITO
	case 1, Route119_EventScript_StartEthanBattleFUECOCO
	case 2, Route119_EventScript_StartEthanBattleQUAXLY
	end

Route119_EventScript_StartEthanBattleSPRIGATITO::
	trainerbattle_no_intro TRAINER_ETHAN_ROUTE_119_SPRIGATITO, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartEthanBattleFUECOCO::
	trainerbattle_no_intro TRAINER_ETHAN_ROUTE_119_FUECOCO, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartEthanBattleQUAXLY::
	trainerbattle_no_intro TRAINER_ETHAN_ROUTE_119_QUAXLY, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartLyra_Kanto::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartLyraBattleBULBASAUR
	case 1, Route119_EventScript_StartLyraBattleCHARMANDER
	case 2, Route119_EventScript_StartLyraBattleSQUIRTLE
	end

Route119_EventScript_StartLyraBattleBULBASAUR::
	trainerbattle_no_intro TRAINER_LYRA_ROUTE_119_BULBASAUR, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartLyraBattleCHARMANDER::
	trainerbattle_no_intro TRAINER_LYRA_ROUTE_119_CHARMANDER, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartLyraBattleSQUIRTLE::
	trainerbattle_no_intro TRAINER_LYRA_ROUTE_119_SQUIRTLE, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartLyra_Johto::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartLyraBattleCHIKORITA
	case 1, Route119_EventScript_StartLyraBattleCYNDAQUIL
	case 2, Route119_EventScript_StartLyraBattleTOTODILE
	end

Route119_EventScript_StartLyraBattleCHIKORITA::
	trainerbattle_no_intro TRAINER_LYRA_ROUTE_119_CHIKORITA, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartLyraBattleCYNDAQUIL::
	trainerbattle_no_intro TRAINER_LYRA_ROUTE_119_CYNDAQUIL, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartLyraBattleTOTODILE::
	trainerbattle_no_intro TRAINER_LYRA_ROUTE_119_TOTODILE, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartLyra_Hoenn::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartLyraBattleTREECKO
	case 1, Route119_EventScript_StartLyraBattleTORCHIC
	case 2, Route119_EventScript_StartLyraBattleMUDKIP
	end

Route119_EventScript_StartLyraBattleTREECKO::
	trainerbattle_no_intro TRAINER_LYRA_ROUTE_119_TREECKO, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartLyraBattleTORCHIC::
	trainerbattle_no_intro TRAINER_LYRA_ROUTE_119_TORCHIC, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartLyraBattleMUDKIP::
	trainerbattle_no_intro TRAINER_LYRA_ROUTE_119_MUDKIP, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartLyra_Sinnoh::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartLyraBattleTURTWIG
	case 1, Route119_EventScript_StartLyraBattleCHIMCHAR
	case 2, Route119_EventScript_StartLyraBattlePIPLUP
	end

Route119_EventScript_StartLyraBattleTURTWIG::
	trainerbattle_no_intro TRAINER_LYRA_ROUTE_119_TURTWIG, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartLyraBattleCHIMCHAR::
	trainerbattle_no_intro TRAINER_LYRA_ROUTE_119_CHIMCHAR, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartLyraBattlePIPLUP::
	trainerbattle_no_intro TRAINER_LYRA_ROUTE_119_PIPLUP, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartLyra_Unova::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartLyraBattleSNIVY
	case 1, Route119_EventScript_StartLyraBattleTEPIG
	case 2, Route119_EventScript_StartLyraBattleOSHAWOTT
	end

Route119_EventScript_StartLyraBattleSNIVY::
	trainerbattle_no_intro TRAINER_LYRA_ROUTE_119_SNIVY, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartLyraBattleTEPIG::
	trainerbattle_no_intro TRAINER_LYRA_ROUTE_119_TEPIG, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartLyraBattleOSHAWOTT::
	trainerbattle_no_intro TRAINER_LYRA_ROUTE_119_OSHAWOTT, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartLyra_Kalos::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartLyraBattleCHESPIN
	case 1, Route119_EventScript_StartLyraBattleFENNEKIN
	case 2, Route119_EventScript_StartLyraBattleFROAKIE
	end

Route119_EventScript_StartLyraBattleCHESPIN::
	trainerbattle_no_intro TRAINER_LYRA_ROUTE_119_CHESPIN, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartLyraBattleFENNEKIN::
	trainerbattle_no_intro TRAINER_LYRA_ROUTE_119_FENNEKIN, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartLyraBattleFROAKIE::
	trainerbattle_no_intro TRAINER_LYRA_ROUTE_119_FROAKIE, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartLyra_Alola::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartLyraBattleROWLET
	case 1, Route119_EventScript_StartLyraBattleLITTEN
	case 2, Route119_EventScript_StartLyraBattlePOPPLIO
	end

Route119_EventScript_StartLyraBattleROWLET::
	trainerbattle_no_intro TRAINER_LYRA_ROUTE_119_ROWLET, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartLyraBattleLITTEN::
	trainerbattle_no_intro TRAINER_LYRA_ROUTE_119_LITTEN, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartLyraBattlePOPPLIO::
	trainerbattle_no_intro TRAINER_LYRA_ROUTE_119_POPPLIO, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartLyra_Galar::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartLyraBattleGROOKEY
	case 1, Route119_EventScript_StartLyraBattleSCORBUNNY
	case 2, Route119_EventScript_StartLyraBattleSOBBLE
	end

Route119_EventScript_StartLyraBattleGROOKEY::
	trainerbattle_no_intro TRAINER_LYRA_ROUTE_119_GROOKEY, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartLyraBattleSCORBUNNY::
	trainerbattle_no_intro TRAINER_LYRA_ROUTE_119_SCORBUNNY, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartLyraBattleSOBBLE::
	trainerbattle_no_intro TRAINER_LYRA_ROUTE_119_SOBBLE, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartLyra_Paldea::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartLyraBattleSPRIGATITO
	case 1, Route119_EventScript_StartLyraBattleFUECOCO
	case 2, Route119_EventScript_StartLyraBattleQUAXLY
	end

Route119_EventScript_StartLyraBattleSPRIGATITO::
	trainerbattle_no_intro TRAINER_LYRA_ROUTE_119_SPRIGATITO, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartLyraBattleFUECOCO::
	trainerbattle_no_intro TRAINER_LYRA_ROUTE_119_FUECOCO, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartLyraBattleQUAXLY::
	trainerbattle_no_intro TRAINER_LYRA_ROUTE_119_QUAXLY, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartLucas_Kanto::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartLucasBattleBULBASAUR
	case 1, Route119_EventScript_StartLucasBattleCHARMANDER
	case 2, Route119_EventScript_StartLucasBattleSQUIRTLE
	end

Route119_EventScript_StartLucasBattleBULBASAUR::
	trainerbattle_no_intro TRAINER_LUCAS_ROUTE_119_BULBASAUR, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartLucasBattleCHARMANDER::
	trainerbattle_no_intro TRAINER_LUCAS_ROUTE_119_CHARMANDER, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartLucasBattleSQUIRTLE::
	trainerbattle_no_intro TRAINER_LUCAS_ROUTE_119_SQUIRTLE, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartLucas_Johto::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartLucasBattleCHIKORITA
	case 1, Route119_EventScript_StartLucasBattleCYNDAQUIL
	case 2, Route119_EventScript_StartLucasBattleTOTODILE
	end

Route119_EventScript_StartLucasBattleCHIKORITA::
	trainerbattle_no_intro TRAINER_LUCAS_ROUTE_119_CHIKORITA, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartLucasBattleCYNDAQUIL::
	trainerbattle_no_intro TRAINER_LUCAS_ROUTE_119_CYNDAQUIL, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartLucasBattleTOTODILE::
	trainerbattle_no_intro TRAINER_LUCAS_ROUTE_119_TOTODILE, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartLucas_Hoenn::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartLucasBattleTREECKO
	case 1, Route119_EventScript_StartLucasBattleTORCHIC
	case 2, Route119_EventScript_StartLucasBattleMUDKIP
	end

Route119_EventScript_StartLucasBattleTREECKO::
	trainerbattle_no_intro TRAINER_LUCAS_ROUTE_119_TREECKO, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartLucasBattleTORCHIC::
	trainerbattle_no_intro TRAINER_LUCAS_ROUTE_119_TORCHIC, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartLucasBattleMUDKIP::
	trainerbattle_no_intro TRAINER_LUCAS_ROUTE_119_MUDKIP, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartLucas_Sinnoh::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartLucasBattleTURTWIG
	case 1, Route119_EventScript_StartLucasBattleCHIMCHAR
	case 2, Route119_EventScript_StartLucasBattlePIPLUP
	end

Route119_EventScript_StartLucasBattleTURTWIG::
	trainerbattle_no_intro TRAINER_LUCAS_ROUTE_119_TURTWIG, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartLucasBattleCHIMCHAR::
	trainerbattle_no_intro TRAINER_LUCAS_ROUTE_119_CHIMCHAR, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartLucasBattlePIPLUP::
	trainerbattle_no_intro TRAINER_LUCAS_ROUTE_119_PIPLUP, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartLucas_Unova::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartLucasBattleSNIVY
	case 1, Route119_EventScript_StartLucasBattleTEPIG
	case 2, Route119_EventScript_StartLucasBattleOSHAWOTT
	end

Route119_EventScript_StartLucasBattleSNIVY::
	trainerbattle_no_intro TRAINER_LUCAS_ROUTE_119_SNIVY, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartLucasBattleTEPIG::
	trainerbattle_no_intro TRAINER_LUCAS_ROUTE_119_TEPIG, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartLucasBattleOSHAWOTT::
	trainerbattle_no_intro TRAINER_LUCAS_ROUTE_119_OSHAWOTT, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartLucas_Kalos::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartLucasBattleCHESPIN
	case 1, Route119_EventScript_StartLucasBattleFENNEKIN
	case 2, Route119_EventScript_StartLucasBattleFROAKIE
	end

Route119_EventScript_StartLucasBattleCHESPIN::
	trainerbattle_no_intro TRAINER_LUCAS_ROUTE_119_CHESPIN, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartLucasBattleFENNEKIN::
	trainerbattle_no_intro TRAINER_LUCAS_ROUTE_119_FENNEKIN, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartLucasBattleFROAKIE::
	trainerbattle_no_intro TRAINER_LUCAS_ROUTE_119_FROAKIE, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartLucas_Alola::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartLucasBattleROWLET
	case 1, Route119_EventScript_StartLucasBattleLITTEN
	case 2, Route119_EventScript_StartLucasBattlePOPPLIO
	end

Route119_EventScript_StartLucasBattleROWLET::
	trainerbattle_no_intro TRAINER_LUCAS_ROUTE_119_ROWLET, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartLucasBattleLITTEN::
	trainerbattle_no_intro TRAINER_LUCAS_ROUTE_119_LITTEN, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartLucasBattlePOPPLIO::
	trainerbattle_no_intro TRAINER_LUCAS_ROUTE_119_POPPLIO, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartLucas_Galar::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartLucasBattleGROOKEY
	case 1, Route119_EventScript_StartLucasBattleSCORBUNNY
	case 2, Route119_EventScript_StartLucasBattleSOBBLE
	end

Route119_EventScript_StartLucasBattleGROOKEY::
	trainerbattle_no_intro TRAINER_LUCAS_ROUTE_119_GROOKEY, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartLucasBattleSCORBUNNY::
	trainerbattle_no_intro TRAINER_LUCAS_ROUTE_119_SCORBUNNY, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartLucasBattleSOBBLE::
	trainerbattle_no_intro TRAINER_LUCAS_ROUTE_119_SOBBLE, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartLucas_Paldea::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartLucasBattleSPRIGATITO
	case 1, Route119_EventScript_StartLucasBattleFUECOCO
	case 2, Route119_EventScript_StartLucasBattleQUAXLY
	end

Route119_EventScript_StartLucasBattleSPRIGATITO::
	trainerbattle_no_intro TRAINER_LUCAS_ROUTE_119_SPRIGATITO, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartLucasBattleFUECOCO::
	trainerbattle_no_intro TRAINER_LUCAS_ROUTE_119_FUECOCO, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartLucasBattleQUAXLY::
	trainerbattle_no_intro TRAINER_LUCAS_ROUTE_119_QUAXLY, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartDawn_Kanto::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartDawnBattleBULBASAUR
	case 1, Route119_EventScript_StartDawnBattleCHARMANDER
	case 2, Route119_EventScript_StartDawnBattleSQUIRTLE
	end

Route119_EventScript_StartDawnBattleBULBASAUR::
	trainerbattle_no_intro TRAINER_DAWN_ROUTE_119_BULBASAUR, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartDawnBattleCHARMANDER::
	trainerbattle_no_intro TRAINER_DAWN_ROUTE_119_CHARMANDER, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartDawnBattleSQUIRTLE::
	trainerbattle_no_intro TRAINER_DAWN_ROUTE_119_SQUIRTLE, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartDawn_Johto::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartDawnBattleCHIKORITA
	case 1, Route119_EventScript_StartDawnBattleCYNDAQUIL
	case 2, Route119_EventScript_StartDawnBattleTOTODILE
	end

Route119_EventScript_StartDawnBattleCHIKORITA::
	trainerbattle_no_intro TRAINER_DAWN_ROUTE_119_CHIKORITA, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartDawnBattleCYNDAQUIL::
	trainerbattle_no_intro TRAINER_DAWN_ROUTE_119_CYNDAQUIL, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartDawnBattleTOTODILE::
	trainerbattle_no_intro TRAINER_DAWN_ROUTE_119_TOTODILE, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartDawn_Hoenn::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartDawnBattleTREECKO
	case 1, Route119_EventScript_StartDawnBattleTORCHIC
	case 2, Route119_EventScript_StartDawnBattleMUDKIP
	end

Route119_EventScript_StartDawnBattleTREECKO::
	trainerbattle_no_intro TRAINER_DAWN_ROUTE_119_TREECKO, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartDawnBattleTORCHIC::
	trainerbattle_no_intro TRAINER_DAWN_ROUTE_119_TORCHIC, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartDawnBattleMUDKIP::
	trainerbattle_no_intro TRAINER_DAWN_ROUTE_119_MUDKIP, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartDawn_Sinnoh::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartDawnBattleTURTWIG
	case 1, Route119_EventScript_StartDawnBattleCHIMCHAR
	case 2, Route119_EventScript_StartDawnBattlePIPLUP
	end

Route119_EventScript_StartDawnBattleTURTWIG::
	trainerbattle_no_intro TRAINER_DAWN_ROUTE_119_TURTWIG, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartDawnBattleCHIMCHAR::
	trainerbattle_no_intro TRAINER_DAWN_ROUTE_119_CHIMCHAR, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartDawnBattlePIPLUP::
	trainerbattle_no_intro TRAINER_DAWN_ROUTE_119_PIPLUP, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartDawn_Unova::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartDawnBattleSNIVY
	case 1, Route119_EventScript_StartDawnBattleTEPIG
	case 2, Route119_EventScript_StartDawnBattleOSHAWOTT
	end

Route119_EventScript_StartDawnBattleSNIVY::
	trainerbattle_no_intro TRAINER_DAWN_ROUTE_119_SNIVY, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartDawnBattleTEPIG::
	trainerbattle_no_intro TRAINER_DAWN_ROUTE_119_TEPIG, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartDawnBattleOSHAWOTT::
	trainerbattle_no_intro TRAINER_DAWN_ROUTE_119_OSHAWOTT, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartDawn_Kalos::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartDawnBattleCHESPIN
	case 1, Route119_EventScript_StartDawnBattleFENNEKIN
	case 2, Route119_EventScript_StartDawnBattleFROAKIE
	end

Route119_EventScript_StartDawnBattleCHESPIN::
	trainerbattle_no_intro TRAINER_DAWN_ROUTE_119_CHESPIN, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartDawnBattleFENNEKIN::
	trainerbattle_no_intro TRAINER_DAWN_ROUTE_119_FENNEKIN, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartDawnBattleFROAKIE::
	trainerbattle_no_intro TRAINER_DAWN_ROUTE_119_FROAKIE, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartDawn_Alola::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartDawnBattleROWLET
	case 1, Route119_EventScript_StartDawnBattleLITTEN
	case 2, Route119_EventScript_StartDawnBattlePOPPLIO
	end

Route119_EventScript_StartDawnBattleROWLET::
	trainerbattle_no_intro TRAINER_DAWN_ROUTE_119_ROWLET, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartDawnBattleLITTEN::
	trainerbattle_no_intro TRAINER_DAWN_ROUTE_119_LITTEN, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartDawnBattlePOPPLIO::
	trainerbattle_no_intro TRAINER_DAWN_ROUTE_119_POPPLIO, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartDawn_Galar::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartDawnBattleGROOKEY
	case 1, Route119_EventScript_StartDawnBattleSCORBUNNY
	case 2, Route119_EventScript_StartDawnBattleSOBBLE
	end

Route119_EventScript_StartDawnBattleGROOKEY::
	trainerbattle_no_intro TRAINER_DAWN_ROUTE_119_GROOKEY, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartDawnBattleSCORBUNNY::
	trainerbattle_no_intro TRAINER_DAWN_ROUTE_119_SCORBUNNY, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartDawnBattleSOBBLE::
	trainerbattle_no_intro TRAINER_DAWN_ROUTE_119_SOBBLE, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartDawn_Paldea::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartDawnBattleSPRIGATITO
	case 1, Route119_EventScript_StartDawnBattleFUECOCO
	case 2, Route119_EventScript_StartDawnBattleQUAXLY
	end

Route119_EventScript_StartDawnBattleSPRIGATITO::
	trainerbattle_no_intro TRAINER_DAWN_ROUTE_119_SPRIGATITO, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartDawnBattleFUECOCO::
	trainerbattle_no_intro TRAINER_DAWN_ROUTE_119_FUECOCO, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartDawnBattleQUAXLY::
	trainerbattle_no_intro TRAINER_DAWN_ROUTE_119_QUAXLY, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartHilbert_Kanto::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartHilbertBattleBULBASAUR
	case 1, Route119_EventScript_StartHilbertBattleCHARMANDER
	case 2, Route119_EventScript_StartHilbertBattleSQUIRTLE
	end

Route119_EventScript_StartHilbertBattleBULBASAUR::
	trainerbattle_no_intro TRAINER_HILBERT_ROUTE_119_BULBASAUR, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartHilbertBattleCHARMANDER::
	trainerbattle_no_intro TRAINER_HILBERT_ROUTE_119_CHARMANDER, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartHilbertBattleSQUIRTLE::
	trainerbattle_no_intro TRAINER_HILBERT_ROUTE_119_SQUIRTLE, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartHilbert_Johto::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartHilbertBattleCHIKORITA
	case 1, Route119_EventScript_StartHilbertBattleCYNDAQUIL
	case 2, Route119_EventScript_StartHilbertBattleTOTODILE
	end

Route119_EventScript_StartHilbertBattleCHIKORITA::
	trainerbattle_no_intro TRAINER_HILBERT_ROUTE_119_CHIKORITA, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartHilbertBattleCYNDAQUIL::
	trainerbattle_no_intro TRAINER_HILBERT_ROUTE_119_CYNDAQUIL, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartHilbertBattleTOTODILE::
	trainerbattle_no_intro TRAINER_HILBERT_ROUTE_119_TOTODILE, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartHilbert_Hoenn::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartHilbertBattleTREECKO
	case 1, Route119_EventScript_StartHilbertBattleTORCHIC
	case 2, Route119_EventScript_StartHilbertBattleMUDKIP
	end

Route119_EventScript_StartHilbertBattleTREECKO::
	trainerbattle_no_intro TRAINER_HILBERT_ROUTE_119_TREECKO, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartHilbertBattleTORCHIC::
	trainerbattle_no_intro TRAINER_HILBERT_ROUTE_119_TORCHIC, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartHilbertBattleMUDKIP::
	trainerbattle_no_intro TRAINER_HILBERT_ROUTE_119_MUDKIP, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartHilbert_Sinnoh::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartHilbertBattleTURTWIG
	case 1, Route119_EventScript_StartHilbertBattleCHIMCHAR
	case 2, Route119_EventScript_StartHilbertBattlePIPLUP
	end

Route119_EventScript_StartHilbertBattleTURTWIG::
	trainerbattle_no_intro TRAINER_HILBERT_ROUTE_119_TURTWIG, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartHilbertBattleCHIMCHAR::
	trainerbattle_no_intro TRAINER_HILBERT_ROUTE_119_CHIMCHAR, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartHilbertBattlePIPLUP::
	trainerbattle_no_intro TRAINER_HILBERT_ROUTE_119_PIPLUP, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartHilbert_Unova::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartHilbertBattleSNIVY
	case 1, Route119_EventScript_StartHilbertBattleTEPIG
	case 2, Route119_EventScript_StartHilbertBattleOSHAWOTT
	end

Route119_EventScript_StartHilbertBattleSNIVY::
	trainerbattle_no_intro TRAINER_HILBERT_ROUTE_119_SNIVY, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartHilbertBattleTEPIG::
	trainerbattle_no_intro TRAINER_HILBERT_ROUTE_119_TEPIG, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartHilbertBattleOSHAWOTT::
	trainerbattle_no_intro TRAINER_HILBERT_ROUTE_119_OSHAWOTT, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartHilbert_Kalos::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartHilbertBattleCHESPIN
	case 1, Route119_EventScript_StartHilbertBattleFENNEKIN
	case 2, Route119_EventScript_StartHilbertBattleFROAKIE
	end

Route119_EventScript_StartHilbertBattleCHESPIN::
	trainerbattle_no_intro TRAINER_HILBERT_ROUTE_119_CHESPIN, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartHilbertBattleFENNEKIN::
	trainerbattle_no_intro TRAINER_HILBERT_ROUTE_119_FENNEKIN, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartHilbertBattleFROAKIE::
	trainerbattle_no_intro TRAINER_HILBERT_ROUTE_119_FROAKIE, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartHilbert_Alola::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartHilbertBattleROWLET
	case 1, Route119_EventScript_StartHilbertBattleLITTEN
	case 2, Route119_EventScript_StartHilbertBattlePOPPLIO
	end

Route119_EventScript_StartHilbertBattleROWLET::
	trainerbattle_no_intro TRAINER_HILBERT_ROUTE_119_ROWLET, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartHilbertBattleLITTEN::
	trainerbattle_no_intro TRAINER_HILBERT_ROUTE_119_LITTEN, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartHilbertBattlePOPPLIO::
	trainerbattle_no_intro TRAINER_HILBERT_ROUTE_119_POPPLIO, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartHilbert_Galar::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartHilbertBattleGROOKEY
	case 1, Route119_EventScript_StartHilbertBattleSCORBUNNY
	case 2, Route119_EventScript_StartHilbertBattleSOBBLE
	end

Route119_EventScript_StartHilbertBattleGROOKEY::
	trainerbattle_no_intro TRAINER_HILBERT_ROUTE_119_GROOKEY, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartHilbertBattleSCORBUNNY::
	trainerbattle_no_intro TRAINER_HILBERT_ROUTE_119_SCORBUNNY, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartHilbertBattleSOBBLE::
	trainerbattle_no_intro TRAINER_HILBERT_ROUTE_119_SOBBLE, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartHilbert_Paldea::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartHilbertBattleSPRIGATITO
	case 1, Route119_EventScript_StartHilbertBattleFUECOCO
	case 2, Route119_EventScript_StartHilbertBattleQUAXLY
	end

Route119_EventScript_StartHilbertBattleSPRIGATITO::
	trainerbattle_no_intro TRAINER_HILBERT_ROUTE_119_SPRIGATITO, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartHilbertBattleFUECOCO::
	trainerbattle_no_intro TRAINER_HILBERT_ROUTE_119_FUECOCO, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartHilbertBattleQUAXLY::
	trainerbattle_no_intro TRAINER_HILBERT_ROUTE_119_QUAXLY, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartHilda_Kanto::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartHildaBattleBULBASAUR
	case 1, Route119_EventScript_StartHildaBattleCHARMANDER
	case 2, Route119_EventScript_StartHildaBattleSQUIRTLE
	end

Route119_EventScript_StartHildaBattleBULBASAUR::
	trainerbattle_no_intro TRAINER_HILDA_ROUTE_119_BULBASAUR, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartHildaBattleCHARMANDER::
	trainerbattle_no_intro TRAINER_HILDA_ROUTE_119_CHARMANDER, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartHildaBattleSQUIRTLE::
	trainerbattle_no_intro TRAINER_HILDA_ROUTE_119_SQUIRTLE, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartHilda_Johto::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartHildaBattleCHIKORITA
	case 1, Route119_EventScript_StartHildaBattleCYNDAQUIL
	case 2, Route119_EventScript_StartHildaBattleTOTODILE
	end

Route119_EventScript_StartHildaBattleCHIKORITA::
	trainerbattle_no_intro TRAINER_HILDA_ROUTE_119_CHIKORITA, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartHildaBattleCYNDAQUIL::
	trainerbattle_no_intro TRAINER_HILDA_ROUTE_119_CYNDAQUIL, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartHildaBattleTOTODILE::
	trainerbattle_no_intro TRAINER_HILDA_ROUTE_119_TOTODILE, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartHilda_Hoenn::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartHildaBattleTREECKO
	case 1, Route119_EventScript_StartHildaBattleTORCHIC
	case 2, Route119_EventScript_StartHildaBattleMUDKIP
	end

Route119_EventScript_StartHildaBattleTREECKO::
	trainerbattle_no_intro TRAINER_HILDA_ROUTE_119_TREECKO, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartHildaBattleTORCHIC::
	trainerbattle_no_intro TRAINER_HILDA_ROUTE_119_TORCHIC, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartHildaBattleMUDKIP::
	trainerbattle_no_intro TRAINER_HILDA_ROUTE_119_MUDKIP, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartHilda_Sinnoh::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartHildaBattleTURTWIG
	case 1, Route119_EventScript_StartHildaBattleCHIMCHAR
	case 2, Route119_EventScript_StartHildaBattlePIPLUP
	end

Route119_EventScript_StartHildaBattleTURTWIG::
	trainerbattle_no_intro TRAINER_HILDA_ROUTE_119_TURTWIG, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartHildaBattleCHIMCHAR::
	trainerbattle_no_intro TRAINER_HILDA_ROUTE_119_CHIMCHAR, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartHildaBattlePIPLUP::
	trainerbattle_no_intro TRAINER_HILDA_ROUTE_119_PIPLUP, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartHilda_Unova::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartHildaBattleSNIVY
	case 1, Route119_EventScript_StartHildaBattleTEPIG
	case 2, Route119_EventScript_StartHildaBattleOSHAWOTT
	end

Route119_EventScript_StartHildaBattleSNIVY::
	trainerbattle_no_intro TRAINER_HILDA_ROUTE_119_SNIVY, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartHildaBattleTEPIG::
	trainerbattle_no_intro TRAINER_HILDA_ROUTE_119_TEPIG, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartHildaBattleOSHAWOTT::
	trainerbattle_no_intro TRAINER_HILDA_ROUTE_119_OSHAWOTT, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartHilda_Kalos::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartHildaBattleCHESPIN
	case 1, Route119_EventScript_StartHildaBattleFENNEKIN
	case 2, Route119_EventScript_StartHildaBattleFROAKIE
	end

Route119_EventScript_StartHildaBattleCHESPIN::
	trainerbattle_no_intro TRAINER_HILDA_ROUTE_119_CHESPIN, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartHildaBattleFENNEKIN::
	trainerbattle_no_intro TRAINER_HILDA_ROUTE_119_FENNEKIN, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartHildaBattleFROAKIE::
	trainerbattle_no_intro TRAINER_HILDA_ROUTE_119_FROAKIE, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartHilda_Alola::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartHildaBattleROWLET
	case 1, Route119_EventScript_StartHildaBattleLITTEN
	case 2, Route119_EventScript_StartHildaBattlePOPPLIO
	end

Route119_EventScript_StartHildaBattleROWLET::
	trainerbattle_no_intro TRAINER_HILDA_ROUTE_119_ROWLET, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartHildaBattleLITTEN::
	trainerbattle_no_intro TRAINER_HILDA_ROUTE_119_LITTEN, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartHildaBattlePOPPLIO::
	trainerbattle_no_intro TRAINER_HILDA_ROUTE_119_POPPLIO, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartHilda_Galar::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartHildaBattleGROOKEY
	case 1, Route119_EventScript_StartHildaBattleSCORBUNNY
	case 2, Route119_EventScript_StartHildaBattleSOBBLE
	end

Route119_EventScript_StartHildaBattleGROOKEY::
	trainerbattle_no_intro TRAINER_HILDA_ROUTE_119_GROOKEY, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartHildaBattleSCORBUNNY::
	trainerbattle_no_intro TRAINER_HILDA_ROUTE_119_SCORBUNNY, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartHildaBattleSOBBLE::
	trainerbattle_no_intro TRAINER_HILDA_ROUTE_119_SOBBLE, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartHilda_Paldea::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartHildaBattleSPRIGATITO
	case 1, Route119_EventScript_StartHildaBattleFUECOCO
	case 2, Route119_EventScript_StartHildaBattleQUAXLY
	end

Route119_EventScript_StartHildaBattleSPRIGATITO::
	trainerbattle_no_intro TRAINER_HILDA_ROUTE_119_SPRIGATITO, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartHildaBattleFUECOCO::
	trainerbattle_no_intro TRAINER_HILDA_ROUTE_119_FUECOCO, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartHildaBattleQUAXLY::
	trainerbattle_no_intro TRAINER_HILDA_ROUTE_119_QUAXLY, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartNate_Kanto::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartNateBattleBULBASAUR
	case 1, Route119_EventScript_StartNateBattleCHARMANDER
	case 2, Route119_EventScript_StartNateBattleSQUIRTLE
	end

Route119_EventScript_StartNateBattleBULBASAUR::
	trainerbattle_no_intro TRAINER_NATE_ROUTE_119_BULBASAUR, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartNateBattleCHARMANDER::
	trainerbattle_no_intro TRAINER_NATE_ROUTE_119_CHARMANDER, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartNateBattleSQUIRTLE::
	trainerbattle_no_intro TRAINER_NATE_ROUTE_119_SQUIRTLE, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartNate_Johto::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartNateBattleCHIKORITA
	case 1, Route119_EventScript_StartNateBattleCYNDAQUIL
	case 2, Route119_EventScript_StartNateBattleTOTODILE
	end

Route119_EventScript_StartNateBattleCHIKORITA::
	trainerbattle_no_intro TRAINER_NATE_ROUTE_119_CHIKORITA, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartNateBattleCYNDAQUIL::
	trainerbattle_no_intro TRAINER_NATE_ROUTE_119_CYNDAQUIL, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartNateBattleTOTODILE::
	trainerbattle_no_intro TRAINER_NATE_ROUTE_119_TOTODILE, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartNate_Hoenn::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartNateBattleTREECKO
	case 1, Route119_EventScript_StartNateBattleTORCHIC
	case 2, Route119_EventScript_StartNateBattleMUDKIP
	end

Route119_EventScript_StartNateBattleTREECKO::
	trainerbattle_no_intro TRAINER_NATE_ROUTE_119_TREECKO, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartNateBattleTORCHIC::
	trainerbattle_no_intro TRAINER_NATE_ROUTE_119_TORCHIC, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartNateBattleMUDKIP::
	trainerbattle_no_intro TRAINER_NATE_ROUTE_119_MUDKIP, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartNate_Sinnoh::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartNateBattleTURTWIG
	case 1, Route119_EventScript_StartNateBattleCHIMCHAR
	case 2, Route119_EventScript_StartNateBattlePIPLUP
	end

Route119_EventScript_StartNateBattleTURTWIG::
	trainerbattle_no_intro TRAINER_NATE_ROUTE_119_TURTWIG, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartNateBattleCHIMCHAR::
	trainerbattle_no_intro TRAINER_NATE_ROUTE_119_CHIMCHAR, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartNateBattlePIPLUP::
	trainerbattle_no_intro TRAINER_NATE_ROUTE_119_PIPLUP, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartNate_Unova::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartNateBattleSNIVY
	case 1, Route119_EventScript_StartNateBattleTEPIG
	case 2, Route119_EventScript_StartNateBattleOSHAWOTT
	end

Route119_EventScript_StartNateBattleSNIVY::
	trainerbattle_no_intro TRAINER_NATE_ROUTE_119_SNIVY, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartNateBattleTEPIG::
	trainerbattle_no_intro TRAINER_NATE_ROUTE_119_TEPIG, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartNateBattleOSHAWOTT::
	trainerbattle_no_intro TRAINER_NATE_ROUTE_119_OSHAWOTT, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartNate_Kalos::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartNateBattleCHESPIN
	case 1, Route119_EventScript_StartNateBattleFENNEKIN
	case 2, Route119_EventScript_StartNateBattleFROAKIE
	end

Route119_EventScript_StartNateBattleCHESPIN::
	trainerbattle_no_intro TRAINER_NATE_ROUTE_119_CHESPIN, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartNateBattleFENNEKIN::
	trainerbattle_no_intro TRAINER_NATE_ROUTE_119_FENNEKIN, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartNateBattleFROAKIE::
	trainerbattle_no_intro TRAINER_NATE_ROUTE_119_FROAKIE, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartNate_Alola::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartNateBattleROWLET
	case 1, Route119_EventScript_StartNateBattleLITTEN
	case 2, Route119_EventScript_StartNateBattlePOPPLIO
	end

Route119_EventScript_StartNateBattleROWLET::
	trainerbattle_no_intro TRAINER_NATE_ROUTE_119_ROWLET, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartNateBattleLITTEN::
	trainerbattle_no_intro TRAINER_NATE_ROUTE_119_LITTEN, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartNateBattlePOPPLIO::
	trainerbattle_no_intro TRAINER_NATE_ROUTE_119_POPPLIO, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartNate_Galar::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartNateBattleGROOKEY
	case 1, Route119_EventScript_StartNateBattleSCORBUNNY
	case 2, Route119_EventScript_StartNateBattleSOBBLE
	end

Route119_EventScript_StartNateBattleGROOKEY::
	trainerbattle_no_intro TRAINER_NATE_ROUTE_119_GROOKEY, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartNateBattleSCORBUNNY::
	trainerbattle_no_intro TRAINER_NATE_ROUTE_119_SCORBUNNY, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartNateBattleSOBBLE::
	trainerbattle_no_intro TRAINER_NATE_ROUTE_119_SOBBLE, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartNate_Paldea::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartNateBattleSPRIGATITO
	case 1, Route119_EventScript_StartNateBattleFUECOCO
	case 2, Route119_EventScript_StartNateBattleQUAXLY
	end

Route119_EventScript_StartNateBattleSPRIGATITO::
	trainerbattle_no_intro TRAINER_NATE_ROUTE_119_SPRIGATITO, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartNateBattleFUECOCO::
	trainerbattle_no_intro TRAINER_NATE_ROUTE_119_FUECOCO, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartNateBattleQUAXLY::
	trainerbattle_no_intro TRAINER_NATE_ROUTE_119_QUAXLY, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartRosa_Kanto::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartRosaBattleBULBASAUR
	case 1, Route119_EventScript_StartRosaBattleCHARMANDER
	case 2, Route119_EventScript_StartRosaBattleSQUIRTLE
	end

Route119_EventScript_StartRosaBattleBULBASAUR::
	trainerbattle_no_intro TRAINER_ROSA_ROUTE_119_BULBASAUR, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartRosaBattleCHARMANDER::
	trainerbattle_no_intro TRAINER_ROSA_ROUTE_119_CHARMANDER, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartRosaBattleSQUIRTLE::
	trainerbattle_no_intro TRAINER_ROSA_ROUTE_119_SQUIRTLE, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartRosa_Johto::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartRosaBattleCHIKORITA
	case 1, Route119_EventScript_StartRosaBattleCYNDAQUIL
	case 2, Route119_EventScript_StartRosaBattleTOTODILE
	end

Route119_EventScript_StartRosaBattleCHIKORITA::
	trainerbattle_no_intro TRAINER_ROSA_ROUTE_119_CHIKORITA, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartRosaBattleCYNDAQUIL::
	trainerbattle_no_intro TRAINER_ROSA_ROUTE_119_CYNDAQUIL, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartRosaBattleTOTODILE::
	trainerbattle_no_intro TRAINER_ROSA_ROUTE_119_TOTODILE, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartRosa_Hoenn::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartRosaBattleTREECKO
	case 1, Route119_EventScript_StartRosaBattleTORCHIC
	case 2, Route119_EventScript_StartRosaBattleMUDKIP
	end

Route119_EventScript_StartRosaBattleTREECKO::
	trainerbattle_no_intro TRAINER_ROSA_ROUTE_119_TREECKO, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartRosaBattleTORCHIC::
	trainerbattle_no_intro TRAINER_ROSA_ROUTE_119_TORCHIC, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartRosaBattleMUDKIP::
	trainerbattle_no_intro TRAINER_ROSA_ROUTE_119_MUDKIP, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartRosa_Sinnoh::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartRosaBattleTURTWIG
	case 1, Route119_EventScript_StartRosaBattleCHIMCHAR
	case 2, Route119_EventScript_StartRosaBattlePIPLUP
	end

Route119_EventScript_StartRosaBattleTURTWIG::
	trainerbattle_no_intro TRAINER_ROSA_ROUTE_119_TURTWIG, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartRosaBattleCHIMCHAR::
	trainerbattle_no_intro TRAINER_ROSA_ROUTE_119_CHIMCHAR, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartRosaBattlePIPLUP::
	trainerbattle_no_intro TRAINER_ROSA_ROUTE_119_PIPLUP, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartRosa_Unova::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartRosaBattleSNIVY
	case 1, Route119_EventScript_StartRosaBattleTEPIG
	case 2, Route119_EventScript_StartRosaBattleOSHAWOTT
	end

Route119_EventScript_StartRosaBattleSNIVY::
	trainerbattle_no_intro TRAINER_ROSA_ROUTE_119_SNIVY, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartRosaBattleTEPIG::
	trainerbattle_no_intro TRAINER_ROSA_ROUTE_119_TEPIG, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartRosaBattleOSHAWOTT::
	trainerbattle_no_intro TRAINER_ROSA_ROUTE_119_OSHAWOTT, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartRosa_Kalos::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartRosaBattleCHESPIN
	case 1, Route119_EventScript_StartRosaBattleFENNEKIN
	case 2, Route119_EventScript_StartRosaBattleFROAKIE
	end

Route119_EventScript_StartRosaBattleCHESPIN::
	trainerbattle_no_intro TRAINER_ROSA_ROUTE_119_CHESPIN, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartRosaBattleFENNEKIN::
	trainerbattle_no_intro TRAINER_ROSA_ROUTE_119_FENNEKIN, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartRosaBattleFROAKIE::
	trainerbattle_no_intro TRAINER_ROSA_ROUTE_119_FROAKIE, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartRosa_Alola::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartRosaBattleROWLET
	case 1, Route119_EventScript_StartRosaBattleLITTEN
	case 2, Route119_EventScript_StartRosaBattlePOPPLIO
	end

Route119_EventScript_StartRosaBattleROWLET::
	trainerbattle_no_intro TRAINER_ROSA_ROUTE_119_ROWLET, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartRosaBattleLITTEN::
	trainerbattle_no_intro TRAINER_ROSA_ROUTE_119_LITTEN, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartRosaBattlePOPPLIO::
	trainerbattle_no_intro TRAINER_ROSA_ROUTE_119_POPPLIO, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartRosa_Galar::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartRosaBattleGROOKEY
	case 1, Route119_EventScript_StartRosaBattleSCORBUNNY
	case 2, Route119_EventScript_StartRosaBattleSOBBLE
	end

Route119_EventScript_StartRosaBattleGROOKEY::
	trainerbattle_no_intro TRAINER_ROSA_ROUTE_119_GROOKEY, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartRosaBattleSCORBUNNY::
	trainerbattle_no_intro TRAINER_ROSA_ROUTE_119_SCORBUNNY, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartRosaBattleSOBBLE::
	trainerbattle_no_intro TRAINER_ROSA_ROUTE_119_SOBBLE, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartRosa_Paldea::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartRosaBattleSPRIGATITO
	case 1, Route119_EventScript_StartRosaBattleFUECOCO
	case 2, Route119_EventScript_StartRosaBattleQUAXLY
	end

Route119_EventScript_StartRosaBattleSPRIGATITO::
	trainerbattle_no_intro TRAINER_ROSA_ROUTE_119_SPRIGATITO, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartRosaBattleFUECOCO::
	trainerbattle_no_intro TRAINER_ROSA_ROUTE_119_FUECOCO, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartRosaBattleQUAXLY::
	trainerbattle_no_intro TRAINER_ROSA_ROUTE_119_QUAXLY, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartCalem_Kanto::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartCalemBattleBULBASAUR
	case 1, Route119_EventScript_StartCalemBattleCHARMANDER
	case 2, Route119_EventScript_StartCalemBattleSQUIRTLE
	end

Route119_EventScript_StartCalemBattleBULBASAUR::
	trainerbattle_no_intro TRAINER_CALEM_ROUTE_119_BULBASAUR, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartCalemBattleCHARMANDER::
	trainerbattle_no_intro TRAINER_CALEM_ROUTE_119_CHARMANDER, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartCalemBattleSQUIRTLE::
	trainerbattle_no_intro TRAINER_CALEM_ROUTE_119_SQUIRTLE, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartCalem_Johto::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartCalemBattleCHIKORITA
	case 1, Route119_EventScript_StartCalemBattleCYNDAQUIL
	case 2, Route119_EventScript_StartCalemBattleTOTODILE
	end

Route119_EventScript_StartCalemBattleCHIKORITA::
	trainerbattle_no_intro TRAINER_CALEM_ROUTE_119_CHIKORITA, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartCalemBattleCYNDAQUIL::
	trainerbattle_no_intro TRAINER_CALEM_ROUTE_119_CYNDAQUIL, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartCalemBattleTOTODILE::
	trainerbattle_no_intro TRAINER_CALEM_ROUTE_119_TOTODILE, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartCalem_Hoenn::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartCalemBattleTREECKO
	case 1, Route119_EventScript_StartCalemBattleTORCHIC
	case 2, Route119_EventScript_StartCalemBattleMUDKIP
	end

Route119_EventScript_StartCalemBattleTREECKO::
	trainerbattle_no_intro TRAINER_CALEM_ROUTE_119_TREECKO, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartCalemBattleTORCHIC::
	trainerbattle_no_intro TRAINER_CALEM_ROUTE_119_TORCHIC, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartCalemBattleMUDKIP::
	trainerbattle_no_intro TRAINER_CALEM_ROUTE_119_MUDKIP, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartCalem_Sinnoh::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartCalemBattleTURTWIG
	case 1, Route119_EventScript_StartCalemBattleCHIMCHAR
	case 2, Route119_EventScript_StartCalemBattlePIPLUP
	end

Route119_EventScript_StartCalemBattleTURTWIG::
	trainerbattle_no_intro TRAINER_CALEM_ROUTE_119_TURTWIG, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartCalemBattleCHIMCHAR::
	trainerbattle_no_intro TRAINER_CALEM_ROUTE_119_CHIMCHAR, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartCalemBattlePIPLUP::
	trainerbattle_no_intro TRAINER_CALEM_ROUTE_119_PIPLUP, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartCalem_Unova::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartCalemBattleSNIVY
	case 1, Route119_EventScript_StartCalemBattleTEPIG
	case 2, Route119_EventScript_StartCalemBattleOSHAWOTT
	end

Route119_EventScript_StartCalemBattleSNIVY::
	trainerbattle_no_intro TRAINER_CALEM_ROUTE_119_SNIVY, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartCalemBattleTEPIG::
	trainerbattle_no_intro TRAINER_CALEM_ROUTE_119_TEPIG, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartCalemBattleOSHAWOTT::
	trainerbattle_no_intro TRAINER_CALEM_ROUTE_119_OSHAWOTT, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartCalem_Kalos::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartCalemBattleCHESPIN
	case 1, Route119_EventScript_StartCalemBattleFENNEKIN
	case 2, Route119_EventScript_StartCalemBattleFROAKIE
	end

Route119_EventScript_StartCalemBattleCHESPIN::
	trainerbattle_no_intro TRAINER_CALEM_ROUTE_119_CHESPIN, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartCalemBattleFENNEKIN::
	trainerbattle_no_intro TRAINER_CALEM_ROUTE_119_FENNEKIN, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartCalemBattleFROAKIE::
	trainerbattle_no_intro TRAINER_CALEM_ROUTE_119_FROAKIE, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartCalem_Alola::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartCalemBattleROWLET
	case 1, Route119_EventScript_StartCalemBattleLITTEN
	case 2, Route119_EventScript_StartCalemBattlePOPPLIO
	end

Route119_EventScript_StartCalemBattleROWLET::
	trainerbattle_no_intro TRAINER_CALEM_ROUTE_119_ROWLET, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartCalemBattleLITTEN::
	trainerbattle_no_intro TRAINER_CALEM_ROUTE_119_LITTEN, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartCalemBattlePOPPLIO::
	trainerbattle_no_intro TRAINER_CALEM_ROUTE_119_POPPLIO, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartCalem_Galar::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartCalemBattleGROOKEY
	case 1, Route119_EventScript_StartCalemBattleSCORBUNNY
	case 2, Route119_EventScript_StartCalemBattleSOBBLE
	end

Route119_EventScript_StartCalemBattleGROOKEY::
	trainerbattle_no_intro TRAINER_CALEM_ROUTE_119_GROOKEY, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartCalemBattleSCORBUNNY::
	trainerbattle_no_intro TRAINER_CALEM_ROUTE_119_SCORBUNNY, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartCalemBattleSOBBLE::
	trainerbattle_no_intro TRAINER_CALEM_ROUTE_119_SOBBLE, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartCalem_Paldea::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartCalemBattleSPRIGATITO
	case 1, Route119_EventScript_StartCalemBattleFUECOCO
	case 2, Route119_EventScript_StartCalemBattleQUAXLY
	end

Route119_EventScript_StartCalemBattleSPRIGATITO::
	trainerbattle_no_intro TRAINER_CALEM_ROUTE_119_SPRIGATITO, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartCalemBattleFUECOCO::
	trainerbattle_no_intro TRAINER_CALEM_ROUTE_119_FUECOCO, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartCalemBattleQUAXLY::
	trainerbattle_no_intro TRAINER_CALEM_ROUTE_119_QUAXLY, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartSerena_Kanto::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartSerenaBattleBULBASAUR
	case 1, Route119_EventScript_StartSerenaBattleCHARMANDER
	case 2, Route119_EventScript_StartSerenaBattleSQUIRTLE
	end

Route119_EventScript_StartSerenaBattleBULBASAUR::
	trainerbattle_no_intro TRAINER_SERENA_ROUTE_119_BULBASAUR, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartSerenaBattleCHARMANDER::
	trainerbattle_no_intro TRAINER_SERENA_ROUTE_119_CHARMANDER, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartSerenaBattleSQUIRTLE::
	trainerbattle_no_intro TRAINER_SERENA_ROUTE_119_SQUIRTLE, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartSerena_Johto::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartSerenaBattleCHIKORITA
	case 1, Route119_EventScript_StartSerenaBattleCYNDAQUIL
	case 2, Route119_EventScript_StartSerenaBattleTOTODILE
	end

Route119_EventScript_StartSerenaBattleCHIKORITA::
	trainerbattle_no_intro TRAINER_SERENA_ROUTE_119_CHIKORITA, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartSerenaBattleCYNDAQUIL::
	trainerbattle_no_intro TRAINER_SERENA_ROUTE_119_CYNDAQUIL, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartSerenaBattleTOTODILE::
	trainerbattle_no_intro TRAINER_SERENA_ROUTE_119_TOTODILE, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartSerena_Hoenn::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartSerenaBattleTREECKO
	case 1, Route119_EventScript_StartSerenaBattleTORCHIC
	case 2, Route119_EventScript_StartSerenaBattleMUDKIP
	end

Route119_EventScript_StartSerenaBattleTREECKO::
	trainerbattle_no_intro TRAINER_SERENA_ROUTE_119_TREECKO, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartSerenaBattleTORCHIC::
	trainerbattle_no_intro TRAINER_SERENA_ROUTE_119_TORCHIC, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartSerenaBattleMUDKIP::
	trainerbattle_no_intro TRAINER_SERENA_ROUTE_119_MUDKIP, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartSerena_Sinnoh::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartSerenaBattleTURTWIG
	case 1, Route119_EventScript_StartSerenaBattleCHIMCHAR
	case 2, Route119_EventScript_StartSerenaBattlePIPLUP
	end

Route119_EventScript_StartSerenaBattleTURTWIG::
	trainerbattle_no_intro TRAINER_SERENA_ROUTE_119_TURTWIG, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartSerenaBattleCHIMCHAR::
	trainerbattle_no_intro TRAINER_SERENA_ROUTE_119_CHIMCHAR, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartSerenaBattlePIPLUP::
	trainerbattle_no_intro TRAINER_SERENA_ROUTE_119_PIPLUP, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartSerena_Unova::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartSerenaBattleSNIVY
	case 1, Route119_EventScript_StartSerenaBattleTEPIG
	case 2, Route119_EventScript_StartSerenaBattleOSHAWOTT
	end

Route119_EventScript_StartSerenaBattleSNIVY::
	trainerbattle_no_intro TRAINER_SERENA_ROUTE_119_SNIVY, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartSerenaBattleTEPIG::
	trainerbattle_no_intro TRAINER_SERENA_ROUTE_119_TEPIG, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartSerenaBattleOSHAWOTT::
	trainerbattle_no_intro TRAINER_SERENA_ROUTE_119_OSHAWOTT, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartSerena_Kalos::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartSerenaBattleCHESPIN
	case 1, Route119_EventScript_StartSerenaBattleFENNEKIN
	case 2, Route119_EventScript_StartSerenaBattleFROAKIE
	end

Route119_EventScript_StartSerenaBattleCHESPIN::
	trainerbattle_no_intro TRAINER_SERENA_ROUTE_119_CHESPIN, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartSerenaBattleFENNEKIN::
	trainerbattle_no_intro TRAINER_SERENA_ROUTE_119_FENNEKIN, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartSerenaBattleFROAKIE::
	trainerbattle_no_intro TRAINER_SERENA_ROUTE_119_FROAKIE, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartSerena_Alola::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartSerenaBattleROWLET
	case 1, Route119_EventScript_StartSerenaBattleLITTEN
	case 2, Route119_EventScript_StartSerenaBattlePOPPLIO
	end

Route119_EventScript_StartSerenaBattleROWLET::
	trainerbattle_no_intro TRAINER_SERENA_ROUTE_119_ROWLET, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartSerenaBattleLITTEN::
	trainerbattle_no_intro TRAINER_SERENA_ROUTE_119_LITTEN, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartSerenaBattlePOPPLIO::
	trainerbattle_no_intro TRAINER_SERENA_ROUTE_119_POPPLIO, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartSerena_Galar::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartSerenaBattleGROOKEY
	case 1, Route119_EventScript_StartSerenaBattleSCORBUNNY
	case 2, Route119_EventScript_StartSerenaBattleSOBBLE
	end

Route119_EventScript_StartSerenaBattleGROOKEY::
	trainerbattle_no_intro TRAINER_SERENA_ROUTE_119_GROOKEY, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartSerenaBattleSCORBUNNY::
	trainerbattle_no_intro TRAINER_SERENA_ROUTE_119_SCORBUNNY, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartSerenaBattleSOBBLE::
	trainerbattle_no_intro TRAINER_SERENA_ROUTE_119_SOBBLE, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartSerena_Paldea::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartSerenaBattleSPRIGATITO
	case 1, Route119_EventScript_StartSerenaBattleFUECOCO
	case 2, Route119_EventScript_StartSerenaBattleQUAXLY
	end

Route119_EventScript_StartSerenaBattleSPRIGATITO::
	trainerbattle_no_intro TRAINER_SERENA_ROUTE_119_SPRIGATITO, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartSerenaBattleFUECOCO::
	trainerbattle_no_intro TRAINER_SERENA_ROUTE_119_FUECOCO, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartSerenaBattleQUAXLY::
	trainerbattle_no_intro TRAINER_SERENA_ROUTE_119_QUAXLY, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartElio_Kanto::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartElioBattleBULBASAUR
	case 1, Route119_EventScript_StartElioBattleCHARMANDER
	case 2, Route119_EventScript_StartElioBattleSQUIRTLE
	end

Route119_EventScript_StartElioBattleBULBASAUR::
	trainerbattle_no_intro TRAINER_ELIO_ROUTE_119_BULBASAUR, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartElioBattleCHARMANDER::
	trainerbattle_no_intro TRAINER_ELIO_ROUTE_119_CHARMANDER, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartElioBattleSQUIRTLE::
	trainerbattle_no_intro TRAINER_ELIO_ROUTE_119_SQUIRTLE, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartElio_Johto::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartElioBattleCHIKORITA
	case 1, Route119_EventScript_StartElioBattleCYNDAQUIL
	case 2, Route119_EventScript_StartElioBattleTOTODILE
	end

Route119_EventScript_StartElioBattleCHIKORITA::
	trainerbattle_no_intro TRAINER_ELIO_ROUTE_119_CHIKORITA, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartElioBattleCYNDAQUIL::
	trainerbattle_no_intro TRAINER_ELIO_ROUTE_119_CYNDAQUIL, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartElioBattleTOTODILE::
	trainerbattle_no_intro TRAINER_ELIO_ROUTE_119_TOTODILE, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartElio_Hoenn::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartElioBattleTREECKO
	case 1, Route119_EventScript_StartElioBattleTORCHIC
	case 2, Route119_EventScript_StartElioBattleMUDKIP
	end

Route119_EventScript_StartElioBattleTREECKO::
	trainerbattle_no_intro TRAINER_ELIO_ROUTE_119_TREECKO, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartElioBattleTORCHIC::
	trainerbattle_no_intro TRAINER_ELIO_ROUTE_119_TORCHIC, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartElioBattleMUDKIP::
	trainerbattle_no_intro TRAINER_ELIO_ROUTE_119_MUDKIP, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartElio_Sinnoh::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartElioBattleTURTWIG
	case 1, Route119_EventScript_StartElioBattleCHIMCHAR
	case 2, Route119_EventScript_StartElioBattlePIPLUP
	end

Route119_EventScript_StartElioBattleTURTWIG::
	trainerbattle_no_intro TRAINER_ELIO_ROUTE_119_TURTWIG, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartElioBattleCHIMCHAR::
	trainerbattle_no_intro TRAINER_ELIO_ROUTE_119_CHIMCHAR, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartElioBattlePIPLUP::
	trainerbattle_no_intro TRAINER_ELIO_ROUTE_119_PIPLUP, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartElio_Unova::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartElioBattleSNIVY
	case 1, Route119_EventScript_StartElioBattleTEPIG
	case 2, Route119_EventScript_StartElioBattleOSHAWOTT
	end

Route119_EventScript_StartElioBattleSNIVY::
	trainerbattle_no_intro TRAINER_ELIO_ROUTE_119_SNIVY, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartElioBattleTEPIG::
	trainerbattle_no_intro TRAINER_ELIO_ROUTE_119_TEPIG, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartElioBattleOSHAWOTT::
	trainerbattle_no_intro TRAINER_ELIO_ROUTE_119_OSHAWOTT, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartElio_Kalos::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartElioBattleCHESPIN
	case 1, Route119_EventScript_StartElioBattleFENNEKIN
	case 2, Route119_EventScript_StartElioBattleFROAKIE
	end

Route119_EventScript_StartElioBattleCHESPIN::
	trainerbattle_no_intro TRAINER_ELIO_ROUTE_119_CHESPIN, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartElioBattleFENNEKIN::
	trainerbattle_no_intro TRAINER_ELIO_ROUTE_119_FENNEKIN, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartElioBattleFROAKIE::
	trainerbattle_no_intro TRAINER_ELIO_ROUTE_119_FROAKIE, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartElio_Alola::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartElioBattleROWLET
	case 1, Route119_EventScript_StartElioBattleLITTEN
	case 2, Route119_EventScript_StartElioBattlePOPPLIO
	end

Route119_EventScript_StartElioBattleROWLET::
	trainerbattle_no_intro TRAINER_ELIO_ROUTE_119_ROWLET, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartElioBattleLITTEN::
	trainerbattle_no_intro TRAINER_ELIO_ROUTE_119_LITTEN, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartElioBattlePOPPLIO::
	trainerbattle_no_intro TRAINER_ELIO_ROUTE_119_POPPLIO, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartElio_Galar::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartElioBattleGROOKEY
	case 1, Route119_EventScript_StartElioBattleSCORBUNNY
	case 2, Route119_EventScript_StartElioBattleSOBBLE
	end

Route119_EventScript_StartElioBattleGROOKEY::
	trainerbattle_no_intro TRAINER_ELIO_ROUTE_119_GROOKEY, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartElioBattleSCORBUNNY::
	trainerbattle_no_intro TRAINER_ELIO_ROUTE_119_SCORBUNNY, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartElioBattleSOBBLE::
	trainerbattle_no_intro TRAINER_ELIO_ROUTE_119_SOBBLE, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartElio_Paldea::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartElioBattleSPRIGATITO
	case 1, Route119_EventScript_StartElioBattleFUECOCO
	case 2, Route119_EventScript_StartElioBattleQUAXLY
	end

Route119_EventScript_StartElioBattleSPRIGATITO::
	trainerbattle_no_intro TRAINER_ELIO_ROUTE_119_SPRIGATITO, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartElioBattleFUECOCO::
	trainerbattle_no_intro TRAINER_ELIO_ROUTE_119_FUECOCO, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartElioBattleQUAXLY::
	trainerbattle_no_intro TRAINER_ELIO_ROUTE_119_QUAXLY, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartSelene_Kanto::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartSeleneBattleBULBASAUR
	case 1, Route119_EventScript_StartSeleneBattleCHARMANDER
	case 2, Route119_EventScript_StartSeleneBattleSQUIRTLE
	end

Route119_EventScript_StartSeleneBattleBULBASAUR::
	trainerbattle_no_intro TRAINER_SELENE_ROUTE_119_BULBASAUR, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartSeleneBattleCHARMANDER::
	trainerbattle_no_intro TRAINER_SELENE_ROUTE_119_CHARMANDER, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartSeleneBattleSQUIRTLE::
	trainerbattle_no_intro TRAINER_SELENE_ROUTE_119_SQUIRTLE, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartSelene_Johto::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartSeleneBattleCHIKORITA
	case 1, Route119_EventScript_StartSeleneBattleCYNDAQUIL
	case 2, Route119_EventScript_StartSeleneBattleTOTODILE
	end

Route119_EventScript_StartSeleneBattleCHIKORITA::
	trainerbattle_no_intro TRAINER_SELENE_ROUTE_119_CHIKORITA, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartSeleneBattleCYNDAQUIL::
	trainerbattle_no_intro TRAINER_SELENE_ROUTE_119_CYNDAQUIL, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartSeleneBattleTOTODILE::
	trainerbattle_no_intro TRAINER_SELENE_ROUTE_119_TOTODILE, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartSelene_Hoenn::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartSeleneBattleTREECKO
	case 1, Route119_EventScript_StartSeleneBattleTORCHIC
	case 2, Route119_EventScript_StartSeleneBattleMUDKIP
	end

Route119_EventScript_StartSeleneBattleTREECKO::
	trainerbattle_no_intro TRAINER_SELENE_ROUTE_119_TREECKO, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartSeleneBattleTORCHIC::
	trainerbattle_no_intro TRAINER_SELENE_ROUTE_119_TORCHIC, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartSeleneBattleMUDKIP::
	trainerbattle_no_intro TRAINER_SELENE_ROUTE_119_MUDKIP, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartSelene_Sinnoh::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartSeleneBattleTURTWIG
	case 1, Route119_EventScript_StartSeleneBattleCHIMCHAR
	case 2, Route119_EventScript_StartSeleneBattlePIPLUP
	end

Route119_EventScript_StartSeleneBattleTURTWIG::
	trainerbattle_no_intro TRAINER_SELENE_ROUTE_119_TURTWIG, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartSeleneBattleCHIMCHAR::
	trainerbattle_no_intro TRAINER_SELENE_ROUTE_119_CHIMCHAR, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartSeleneBattlePIPLUP::
	trainerbattle_no_intro TRAINER_SELENE_ROUTE_119_PIPLUP, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartSelene_Unova::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartSeleneBattleSNIVY
	case 1, Route119_EventScript_StartSeleneBattleTEPIG
	case 2, Route119_EventScript_StartSeleneBattleOSHAWOTT
	end

Route119_EventScript_StartSeleneBattleSNIVY::
	trainerbattle_no_intro TRAINER_SELENE_ROUTE_119_SNIVY, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartSeleneBattleTEPIG::
	trainerbattle_no_intro TRAINER_SELENE_ROUTE_119_TEPIG, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartSeleneBattleOSHAWOTT::
	trainerbattle_no_intro TRAINER_SELENE_ROUTE_119_OSHAWOTT, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartSelene_Kalos::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartSeleneBattleCHESPIN
	case 1, Route119_EventScript_StartSeleneBattleFENNEKIN
	case 2, Route119_EventScript_StartSeleneBattleFROAKIE
	end

Route119_EventScript_StartSeleneBattleCHESPIN::
	trainerbattle_no_intro TRAINER_SELENE_ROUTE_119_CHESPIN, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartSeleneBattleFENNEKIN::
	trainerbattle_no_intro TRAINER_SELENE_ROUTE_119_FENNEKIN, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartSeleneBattleFROAKIE::
	trainerbattle_no_intro TRAINER_SELENE_ROUTE_119_FROAKIE, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartSelene_Alola::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartSeleneBattleROWLET
	case 1, Route119_EventScript_StartSeleneBattleLITTEN
	case 2, Route119_EventScript_StartSeleneBattlePOPPLIO
	end

Route119_EventScript_StartSeleneBattleROWLET::
	trainerbattle_no_intro TRAINER_SELENE_ROUTE_119_ROWLET, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartSeleneBattleLITTEN::
	trainerbattle_no_intro TRAINER_SELENE_ROUTE_119_LITTEN, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartSeleneBattlePOPPLIO::
	trainerbattle_no_intro TRAINER_SELENE_ROUTE_119_POPPLIO, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartSelene_Galar::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartSeleneBattleGROOKEY
	case 1, Route119_EventScript_StartSeleneBattleSCORBUNNY
	case 2, Route119_EventScript_StartSeleneBattleSOBBLE
	end

Route119_EventScript_StartSeleneBattleGROOKEY::
	trainerbattle_no_intro TRAINER_SELENE_ROUTE_119_GROOKEY, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartSeleneBattleSCORBUNNY::
	trainerbattle_no_intro TRAINER_SELENE_ROUTE_119_SCORBUNNY, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartSeleneBattleSOBBLE::
	trainerbattle_no_intro TRAINER_SELENE_ROUTE_119_SOBBLE, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartSelene_Paldea::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartSeleneBattleSPRIGATITO
	case 1, Route119_EventScript_StartSeleneBattleFUECOCO
	case 2, Route119_EventScript_StartSeleneBattleQUAXLY
	end

Route119_EventScript_StartSeleneBattleSPRIGATITO::
	trainerbattle_no_intro TRAINER_SELENE_ROUTE_119_SPRIGATITO, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartSeleneBattleFUECOCO::
	trainerbattle_no_intro TRAINER_SELENE_ROUTE_119_FUECOCO, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartSeleneBattleQUAXLY::
	trainerbattle_no_intro TRAINER_SELENE_ROUTE_119_QUAXLY, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartVictor_Kanto::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartVictorBattleBULBASAUR
	case 1, Route119_EventScript_StartVictorBattleCHARMANDER
	case 2, Route119_EventScript_StartVictorBattleSQUIRTLE
	end

Route119_EventScript_StartVictorBattleBULBASAUR::
	trainerbattle_no_intro TRAINER_VICTOR_ROUTE_119_BULBASAUR, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartVictorBattleCHARMANDER::
	trainerbattle_no_intro TRAINER_VICTOR_ROUTE_119_CHARMANDER, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartVictorBattleSQUIRTLE::
	trainerbattle_no_intro TRAINER_VICTOR_ROUTE_119_SQUIRTLE, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartVictor_Johto::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartVictorBattleCHIKORITA
	case 1, Route119_EventScript_StartVictorBattleCYNDAQUIL
	case 2, Route119_EventScript_StartVictorBattleTOTODILE
	end

Route119_EventScript_StartVictorBattleCHIKORITA::
	trainerbattle_no_intro TRAINER_VICTOR_ROUTE_119_CHIKORITA, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartVictorBattleCYNDAQUIL::
	trainerbattle_no_intro TRAINER_VICTOR_ROUTE_119_CYNDAQUIL, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartVictorBattleTOTODILE::
	trainerbattle_no_intro TRAINER_VICTOR_ROUTE_119_TOTODILE, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartVictor_Hoenn::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartVictorBattleTREECKO
	case 1, Route119_EventScript_StartVictorBattleTORCHIC
	case 2, Route119_EventScript_StartVictorBattleMUDKIP
	end

Route119_EventScript_StartVictorBattleTREECKO::
	trainerbattle_no_intro TRAINER_VICTOR_ROUTE_119_TREECKO, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartVictorBattleTORCHIC::
	trainerbattle_no_intro TRAINER_VICTOR_ROUTE_119_TORCHIC, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartVictorBattleMUDKIP::
	trainerbattle_no_intro TRAINER_VICTOR_ROUTE_119_MUDKIP, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartVictor_Sinnoh::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartVictorBattleTURTWIG
	case 1, Route119_EventScript_StartVictorBattleCHIMCHAR
	case 2, Route119_EventScript_StartVictorBattlePIPLUP
	end

Route119_EventScript_StartVictorBattleTURTWIG::
	trainerbattle_no_intro TRAINER_VICTOR_ROUTE_119_TURTWIG, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartVictorBattleCHIMCHAR::
	trainerbattle_no_intro TRAINER_VICTOR_ROUTE_119_CHIMCHAR, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartVictorBattlePIPLUP::
	trainerbattle_no_intro TRAINER_VICTOR_ROUTE_119_PIPLUP, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartVictor_Unova::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartVictorBattleSNIVY
	case 1, Route119_EventScript_StartVictorBattleTEPIG
	case 2, Route119_EventScript_StartVictorBattleOSHAWOTT
	end

Route119_EventScript_StartVictorBattleSNIVY::
	trainerbattle_no_intro TRAINER_VICTOR_ROUTE_119_SNIVY, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartVictorBattleTEPIG::
	trainerbattle_no_intro TRAINER_VICTOR_ROUTE_119_TEPIG, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartVictorBattleOSHAWOTT::
	trainerbattle_no_intro TRAINER_VICTOR_ROUTE_119_OSHAWOTT, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartVictor_Kalos::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartVictorBattleCHESPIN
	case 1, Route119_EventScript_StartVictorBattleFENNEKIN
	case 2, Route119_EventScript_StartVictorBattleFROAKIE
	end

Route119_EventScript_StartVictorBattleCHESPIN::
	trainerbattle_no_intro TRAINER_VICTOR_ROUTE_119_CHESPIN, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartVictorBattleFENNEKIN::
	trainerbattle_no_intro TRAINER_VICTOR_ROUTE_119_FENNEKIN, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartVictorBattleFROAKIE::
	trainerbattle_no_intro TRAINER_VICTOR_ROUTE_119_FROAKIE, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartVictor_Alola::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartVictorBattleROWLET
	case 1, Route119_EventScript_StartVictorBattleLITTEN
	case 2, Route119_EventScript_StartVictorBattlePOPPLIO
	end

Route119_EventScript_StartVictorBattleROWLET::
	trainerbattle_no_intro TRAINER_VICTOR_ROUTE_119_ROWLET, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartVictorBattleLITTEN::
	trainerbattle_no_intro TRAINER_VICTOR_ROUTE_119_LITTEN, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartVictorBattlePOPPLIO::
	trainerbattle_no_intro TRAINER_VICTOR_ROUTE_119_POPPLIO, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartVictor_Galar::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartVictorBattleGROOKEY
	case 1, Route119_EventScript_StartVictorBattleSCORBUNNY
	case 2, Route119_EventScript_StartVictorBattleSOBBLE
	end

Route119_EventScript_StartVictorBattleGROOKEY::
	trainerbattle_no_intro TRAINER_VICTOR_ROUTE_119_GROOKEY, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartVictorBattleSCORBUNNY::
	trainerbattle_no_intro TRAINER_VICTOR_ROUTE_119_SCORBUNNY, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartVictorBattleSOBBLE::
	trainerbattle_no_intro TRAINER_VICTOR_ROUTE_119_SOBBLE, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartVictor_Paldea::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartVictorBattleSPRIGATITO
	case 1, Route119_EventScript_StartVictorBattleFUECOCO
	case 2, Route119_EventScript_StartVictorBattleQUAXLY
	end

Route119_EventScript_StartVictorBattleSPRIGATITO::
	trainerbattle_no_intro TRAINER_VICTOR_ROUTE_119_SPRIGATITO, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartVictorBattleFUECOCO::
	trainerbattle_no_intro TRAINER_VICTOR_ROUTE_119_FUECOCO, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartVictorBattleQUAXLY::
	trainerbattle_no_intro TRAINER_VICTOR_ROUTE_119_QUAXLY, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartGloria_Kanto::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartGloriaBattleBULBASAUR
	case 1, Route119_EventScript_StartGloriaBattleCHARMANDER
	case 2, Route119_EventScript_StartGloriaBattleSQUIRTLE
	end

Route119_EventScript_StartGloriaBattleBULBASAUR::
	trainerbattle_no_intro TRAINER_GLORIA_ROUTE_119_BULBASAUR, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartGloriaBattleCHARMANDER::
	trainerbattle_no_intro TRAINER_GLORIA_ROUTE_119_CHARMANDER, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartGloriaBattleSQUIRTLE::
	trainerbattle_no_intro TRAINER_GLORIA_ROUTE_119_SQUIRTLE, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartGloria_Johto::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartGloriaBattleCHIKORITA
	case 1, Route119_EventScript_StartGloriaBattleCYNDAQUIL
	case 2, Route119_EventScript_StartGloriaBattleTOTODILE
	end

Route119_EventScript_StartGloriaBattleCHIKORITA::
	trainerbattle_no_intro TRAINER_GLORIA_ROUTE_119_CHIKORITA, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartGloriaBattleCYNDAQUIL::
	trainerbattle_no_intro TRAINER_GLORIA_ROUTE_119_CYNDAQUIL, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartGloriaBattleTOTODILE::
	trainerbattle_no_intro TRAINER_GLORIA_ROUTE_119_TOTODILE, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartGloria_Hoenn::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartGloriaBattleTREECKO
	case 1, Route119_EventScript_StartGloriaBattleTORCHIC
	case 2, Route119_EventScript_StartGloriaBattleMUDKIP
	end

Route119_EventScript_StartGloriaBattleTREECKO::
	trainerbattle_no_intro TRAINER_GLORIA_ROUTE_119_TREECKO, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartGloriaBattleTORCHIC::
	trainerbattle_no_intro TRAINER_GLORIA_ROUTE_119_TORCHIC, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartGloriaBattleMUDKIP::
	trainerbattle_no_intro TRAINER_GLORIA_ROUTE_119_MUDKIP, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartGloria_Sinnoh::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartGloriaBattleTURTWIG
	case 1, Route119_EventScript_StartGloriaBattleCHIMCHAR
	case 2, Route119_EventScript_StartGloriaBattlePIPLUP
	end

Route119_EventScript_StartGloriaBattleTURTWIG::
	trainerbattle_no_intro TRAINER_GLORIA_ROUTE_119_TURTWIG, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartGloriaBattleCHIMCHAR::
	trainerbattle_no_intro TRAINER_GLORIA_ROUTE_119_CHIMCHAR, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartGloriaBattlePIPLUP::
	trainerbattle_no_intro TRAINER_GLORIA_ROUTE_119_PIPLUP, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartGloria_Unova::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartGloriaBattleSNIVY
	case 1, Route119_EventScript_StartGloriaBattleTEPIG
	case 2, Route119_EventScript_StartGloriaBattleOSHAWOTT
	end

Route119_EventScript_StartGloriaBattleSNIVY::
	trainerbattle_no_intro TRAINER_GLORIA_ROUTE_119_SNIVY, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartGloriaBattleTEPIG::
	trainerbattle_no_intro TRAINER_GLORIA_ROUTE_119_TEPIG, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartGloriaBattleOSHAWOTT::
	trainerbattle_no_intro TRAINER_GLORIA_ROUTE_119_OSHAWOTT, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartGloria_Kalos::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartGloriaBattleCHESPIN
	case 1, Route119_EventScript_StartGloriaBattleFENNEKIN
	case 2, Route119_EventScript_StartGloriaBattleFROAKIE
	end

Route119_EventScript_StartGloriaBattleCHESPIN::
	trainerbattle_no_intro TRAINER_GLORIA_ROUTE_119_CHESPIN, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartGloriaBattleFENNEKIN::
	trainerbattle_no_intro TRAINER_GLORIA_ROUTE_119_FENNEKIN, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartGloriaBattleFROAKIE::
	trainerbattle_no_intro TRAINER_GLORIA_ROUTE_119_FROAKIE, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartGloria_Alola::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartGloriaBattleROWLET
	case 1, Route119_EventScript_StartGloriaBattleLITTEN
	case 2, Route119_EventScript_StartGloriaBattlePOPPLIO
	end

Route119_EventScript_StartGloriaBattleROWLET::
	trainerbattle_no_intro TRAINER_GLORIA_ROUTE_119_ROWLET, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartGloriaBattleLITTEN::
	trainerbattle_no_intro TRAINER_GLORIA_ROUTE_119_LITTEN, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartGloriaBattlePOPPLIO::
	trainerbattle_no_intro TRAINER_GLORIA_ROUTE_119_POPPLIO, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartGloria_Galar::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartGloriaBattleGROOKEY
	case 1, Route119_EventScript_StartGloriaBattleSCORBUNNY
	case 2, Route119_EventScript_StartGloriaBattleSOBBLE
	end

Route119_EventScript_StartGloriaBattleGROOKEY::
	trainerbattle_no_intro TRAINER_GLORIA_ROUTE_119_GROOKEY, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartGloriaBattleSCORBUNNY::
	trainerbattle_no_intro TRAINER_GLORIA_ROUTE_119_SCORBUNNY, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartGloriaBattleSOBBLE::
	trainerbattle_no_intro TRAINER_GLORIA_ROUTE_119_SOBBLE, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartGloria_Paldea::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartGloriaBattleSPRIGATITO
	case 1, Route119_EventScript_StartGloriaBattleFUECOCO
	case 2, Route119_EventScript_StartGloriaBattleQUAXLY
	end

Route119_EventScript_StartGloriaBattleSPRIGATITO::
	trainerbattle_no_intro TRAINER_GLORIA_ROUTE_119_SPRIGATITO, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartGloriaBattleFUECOCO::
	trainerbattle_no_intro TRAINER_GLORIA_ROUTE_119_FUECOCO, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartGloriaBattleQUAXLY::
	trainerbattle_no_intro TRAINER_GLORIA_ROUTE_119_QUAXLY, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartFlorian_Kanto::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartFlorianBattleBULBASAUR
	case 1, Route119_EventScript_StartFlorianBattleCHARMANDER
	case 2, Route119_EventScript_StartFlorianBattleSQUIRTLE
	end

Route119_EventScript_StartFlorianBattleBULBASAUR::
	trainerbattle_no_intro TRAINER_FLORIAN_ROUTE_119_BULBASAUR, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartFlorianBattleCHARMANDER::
	trainerbattle_no_intro TRAINER_FLORIAN_ROUTE_119_CHARMANDER, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartFlorianBattleSQUIRTLE::
	trainerbattle_no_intro TRAINER_FLORIAN_ROUTE_119_SQUIRTLE, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartFlorian_Johto::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartFlorianBattleCHIKORITA
	case 1, Route119_EventScript_StartFlorianBattleCYNDAQUIL
	case 2, Route119_EventScript_StartFlorianBattleTOTODILE
	end

Route119_EventScript_StartFlorianBattleCHIKORITA::
	trainerbattle_no_intro TRAINER_FLORIAN_ROUTE_119_CHIKORITA, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartFlorianBattleCYNDAQUIL::
	trainerbattle_no_intro TRAINER_FLORIAN_ROUTE_119_CYNDAQUIL, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartFlorianBattleTOTODILE::
	trainerbattle_no_intro TRAINER_FLORIAN_ROUTE_119_TOTODILE, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartFlorian_Hoenn::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartFlorianBattleTREECKO
	case 1, Route119_EventScript_StartFlorianBattleTORCHIC
	case 2, Route119_EventScript_StartFlorianBattleMUDKIP
	end

Route119_EventScript_StartFlorianBattleTREECKO::
	trainerbattle_no_intro TRAINER_FLORIAN_ROUTE_119_TREECKO, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartFlorianBattleTORCHIC::
	trainerbattle_no_intro TRAINER_FLORIAN_ROUTE_119_TORCHIC, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartFlorianBattleMUDKIP::
	trainerbattle_no_intro TRAINER_FLORIAN_ROUTE_119_MUDKIP, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartFlorian_Sinnoh::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartFlorianBattleTURTWIG
	case 1, Route119_EventScript_StartFlorianBattleCHIMCHAR
	case 2, Route119_EventScript_StartFlorianBattlePIPLUP
	end

Route119_EventScript_StartFlorianBattleTURTWIG::
	trainerbattle_no_intro TRAINER_FLORIAN_ROUTE_119_TURTWIG, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartFlorianBattleCHIMCHAR::
	trainerbattle_no_intro TRAINER_FLORIAN_ROUTE_119_CHIMCHAR, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartFlorianBattlePIPLUP::
	trainerbattle_no_intro TRAINER_FLORIAN_ROUTE_119_PIPLUP, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartFlorian_Unova::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartFlorianBattleSNIVY
	case 1, Route119_EventScript_StartFlorianBattleTEPIG
	case 2, Route119_EventScript_StartFlorianBattleOSHAWOTT
	end

Route119_EventScript_StartFlorianBattleSNIVY::
	trainerbattle_no_intro TRAINER_FLORIAN_ROUTE_119_SNIVY, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartFlorianBattleTEPIG::
	trainerbattle_no_intro TRAINER_FLORIAN_ROUTE_119_TEPIG, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartFlorianBattleOSHAWOTT::
	trainerbattle_no_intro TRAINER_FLORIAN_ROUTE_119_OSHAWOTT, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartFlorian_Kalos::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartFlorianBattleCHESPIN
	case 1, Route119_EventScript_StartFlorianBattleFENNEKIN
	case 2, Route119_EventScript_StartFlorianBattleFROAKIE
	end

Route119_EventScript_StartFlorianBattleCHESPIN::
	trainerbattle_no_intro TRAINER_FLORIAN_ROUTE_119_CHESPIN, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartFlorianBattleFENNEKIN::
	trainerbattle_no_intro TRAINER_FLORIAN_ROUTE_119_FENNEKIN, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartFlorianBattleFROAKIE::
	trainerbattle_no_intro TRAINER_FLORIAN_ROUTE_119_FROAKIE, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartFlorian_Alola::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartFlorianBattleROWLET
	case 1, Route119_EventScript_StartFlorianBattleLITTEN
	case 2, Route119_EventScript_StartFlorianBattlePOPPLIO
	end

Route119_EventScript_StartFlorianBattleROWLET::
	trainerbattle_no_intro TRAINER_FLORIAN_ROUTE_119_ROWLET, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartFlorianBattleLITTEN::
	trainerbattle_no_intro TRAINER_FLORIAN_ROUTE_119_LITTEN, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartFlorianBattlePOPPLIO::
	trainerbattle_no_intro TRAINER_FLORIAN_ROUTE_119_POPPLIO, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartFlorian_Galar::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartFlorianBattleGROOKEY
	case 1, Route119_EventScript_StartFlorianBattleSCORBUNNY
	case 2, Route119_EventScript_StartFlorianBattleSOBBLE
	end

Route119_EventScript_StartFlorianBattleGROOKEY::
	trainerbattle_no_intro TRAINER_FLORIAN_ROUTE_119_GROOKEY, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartFlorianBattleSCORBUNNY::
	trainerbattle_no_intro TRAINER_FLORIAN_ROUTE_119_SCORBUNNY, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartFlorianBattleSOBBLE::
	trainerbattle_no_intro TRAINER_FLORIAN_ROUTE_119_SOBBLE, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartFlorian_Paldea::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartFlorianBattleSPRIGATITO
	case 1, Route119_EventScript_StartFlorianBattleFUECOCO
	case 2, Route119_EventScript_StartFlorianBattleQUAXLY
	end

Route119_EventScript_StartFlorianBattleSPRIGATITO::
	trainerbattle_no_intro TRAINER_FLORIAN_ROUTE_119_SPRIGATITO, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartFlorianBattleFUECOCO::
	trainerbattle_no_intro TRAINER_FLORIAN_ROUTE_119_FUECOCO, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartFlorianBattleQUAXLY::
	trainerbattle_no_intro TRAINER_FLORIAN_ROUTE_119_QUAXLY, Route119_Text_BrendanDefeat
	goto Route119_EventScript_DefeatedBrendan
	end

Route119_EventScript_StartJuliana_Kanto::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartJulianaBattleBULBASAUR
	case 1, Route119_EventScript_StartJulianaBattleCHARMANDER
	case 2, Route119_EventScript_StartJulianaBattleSQUIRTLE
	end

Route119_EventScript_StartJulianaBattleBULBASAUR::
	trainerbattle_no_intro TRAINER_JULIANA_ROUTE_119_BULBASAUR, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartJulianaBattleCHARMANDER::
	trainerbattle_no_intro TRAINER_JULIANA_ROUTE_119_CHARMANDER, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartJulianaBattleSQUIRTLE::
	trainerbattle_no_intro TRAINER_JULIANA_ROUTE_119_SQUIRTLE, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartJuliana_Johto::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartJulianaBattleCHIKORITA
	case 1, Route119_EventScript_StartJulianaBattleCYNDAQUIL
	case 2, Route119_EventScript_StartJulianaBattleTOTODILE
	end

Route119_EventScript_StartJulianaBattleCHIKORITA::
	trainerbattle_no_intro TRAINER_JULIANA_ROUTE_119_CHIKORITA, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartJulianaBattleCYNDAQUIL::
	trainerbattle_no_intro TRAINER_JULIANA_ROUTE_119_CYNDAQUIL, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartJulianaBattleTOTODILE::
	trainerbattle_no_intro TRAINER_JULIANA_ROUTE_119_TOTODILE, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartJuliana_Hoenn::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartJulianaBattleTREECKO
	case 1, Route119_EventScript_StartJulianaBattleTORCHIC
	case 2, Route119_EventScript_StartJulianaBattleMUDKIP
	end

Route119_EventScript_StartJulianaBattleTREECKO::
	trainerbattle_no_intro TRAINER_JULIANA_ROUTE_119_TREECKO, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartJulianaBattleTORCHIC::
	trainerbattle_no_intro TRAINER_JULIANA_ROUTE_119_TORCHIC, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartJulianaBattleMUDKIP::
	trainerbattle_no_intro TRAINER_JULIANA_ROUTE_119_MUDKIP, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartJuliana_Sinnoh::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartJulianaBattleTURTWIG
	case 1, Route119_EventScript_StartJulianaBattleCHIMCHAR
	case 2, Route119_EventScript_StartJulianaBattlePIPLUP
	end

Route119_EventScript_StartJulianaBattleTURTWIG::
	trainerbattle_no_intro TRAINER_JULIANA_ROUTE_119_TURTWIG, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartJulianaBattleCHIMCHAR::
	trainerbattle_no_intro TRAINER_JULIANA_ROUTE_119_CHIMCHAR, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartJulianaBattlePIPLUP::
	trainerbattle_no_intro TRAINER_JULIANA_ROUTE_119_PIPLUP, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartJuliana_Unova::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartJulianaBattleSNIVY
	case 1, Route119_EventScript_StartJulianaBattleTEPIG
	case 2, Route119_EventScript_StartJulianaBattleOSHAWOTT
	end

Route119_EventScript_StartJulianaBattleSNIVY::
	trainerbattle_no_intro TRAINER_JULIANA_ROUTE_119_SNIVY, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartJulianaBattleTEPIG::
	trainerbattle_no_intro TRAINER_JULIANA_ROUTE_119_TEPIG, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartJulianaBattleOSHAWOTT::
	trainerbattle_no_intro TRAINER_JULIANA_ROUTE_119_OSHAWOTT, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartJuliana_Kalos::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartJulianaBattleCHESPIN
	case 1, Route119_EventScript_StartJulianaBattleFENNEKIN
	case 2, Route119_EventScript_StartJulianaBattleFROAKIE
	end

Route119_EventScript_StartJulianaBattleCHESPIN::
	trainerbattle_no_intro TRAINER_JULIANA_ROUTE_119_CHESPIN, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartJulianaBattleFENNEKIN::
	trainerbattle_no_intro TRAINER_JULIANA_ROUTE_119_FENNEKIN, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartJulianaBattleFROAKIE::
	trainerbattle_no_intro TRAINER_JULIANA_ROUTE_119_FROAKIE, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartJuliana_Alola::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartJulianaBattleROWLET
	case 1, Route119_EventScript_StartJulianaBattleLITTEN
	case 2, Route119_EventScript_StartJulianaBattlePOPPLIO
	end

Route119_EventScript_StartJulianaBattleROWLET::
	trainerbattle_no_intro TRAINER_JULIANA_ROUTE_119_ROWLET, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartJulianaBattleLITTEN::
	trainerbattle_no_intro TRAINER_JULIANA_ROUTE_119_LITTEN, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartJulianaBattlePOPPLIO::
	trainerbattle_no_intro TRAINER_JULIANA_ROUTE_119_POPPLIO, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartJuliana_Galar::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartJulianaBattleGROOKEY
	case 1, Route119_EventScript_StartJulianaBattleSCORBUNNY
	case 2, Route119_EventScript_StartJulianaBattleSOBBLE
	end

Route119_EventScript_StartJulianaBattleGROOKEY::
	trainerbattle_no_intro TRAINER_JULIANA_ROUTE_119_GROOKEY, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartJulianaBattleSCORBUNNY::
	trainerbattle_no_intro TRAINER_JULIANA_ROUTE_119_SCORBUNNY, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartJulianaBattleSOBBLE::
	trainerbattle_no_intro TRAINER_JULIANA_ROUTE_119_SOBBLE, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartJuliana_Paldea::
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_StartJulianaBattleSPRIGATITO
	case 1, Route119_EventScript_StartJulianaBattleFUECOCO
	case 2, Route119_EventScript_StartJulianaBattleQUAXLY
	end

Route119_EventScript_StartJulianaBattleSPRIGATITO::
	trainerbattle_no_intro TRAINER_JULIANA_ROUTE_119_SPRIGATITO, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartJulianaBattleFUECOCO::
	trainerbattle_no_intro TRAINER_JULIANA_ROUTE_119_FUECOCO, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_StartJulianaBattleQUAXLY::
	trainerbattle_no_intro TRAINER_JULIANA_ROUTE_119_QUAXLY, Route119_Text_MayDefeat
	goto Route119_EventScript_DefeatedMay
	end

Route119_EventScript_DefeatedBrendan:
	msgbox Route119_Text_BrendanIntro, MSGBOX_DEFAULT
	msgbox Route119_Text_BrendanIllGiveYouThis, MSGBOX_DEFAULT
	call Route119_EventScript_GiveFlyHM
	msgbox Route119_Text_BrendanExplainFly, MSGBOX_DEFAULT
	end

Route119_EventScript_DefeatedMay:
	msgbox Route119_Text_MayIntro, MSGBOX_DEFAULT
	msgbox Route119_Text_MayPresentForYou, MSGBOX_DEFAULT
	call Route119_EventScript_GiveFlyHM
	msgbox Route119_Text_MayExplainFly, MSGBOX_DEFAULT
	end

