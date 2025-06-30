Route103_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route103_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, Route103_OnLoad
	.byte 0

Route103_OnTransition:
	call ProfBirch_EventScript_UpdateLocation
	end

Route103_OnLoad:
	call_if_set FLAG_SYS_GAME_CLEAR, Route103_EventScript_OpenAlteringCave
	end

Route103_EventScript_OpenAlteringCave::
	setmetatile 45, 5, METATILE_General_CaveEntrance_Top, TRUE
	setmetatile 45, 6, METATILE_General_CaveEntrance_Bottom, FALSE
	return

Route103_EventScript_Rival::
	lockall
	setvar VAR_0x8004, LOCALID_ROUTE103_RIVAL
	applymovement LOCALID_ROUTE103_RIVAL, Common_Movement_FacePlayer
	waitmovement 0
	goto Route103_EventScript_ShowRivalMessage


Route103_EventScript_ShowRivalMessage::
    getplayerstyle
    copyvar VAR_TEMP_0, VAR_RESULT
    copyvar VAR_TEMP_1, VAR_STARTER_REGION

    compare VAR_TEMP_0, STYLE_BRENDAN
    goto_if_eq Route103_EventScript_Rival_MAY
    compare VAR_TEMP_0, STYLE_MAY
    goto_if_eq Route103_EventScript_Rival_BRENDAN
    compare VAR_TEMP_0, STYLE_RED
    goto_if_eq Route103_EventScript_Rival_LEAF
    compare VAR_TEMP_0, STYLE_LEAF
    goto_if_eq Route103_EventScript_Rival_RED
    compare VAR_TEMP_0, STYLE_ETHAN
    goto_if_eq Route103_EventScript_Rival_LYRA
    compare VAR_TEMP_0, STYLE_LYRA
    goto_if_eq Route103_EventScript_Rival_ETHAN
    compare VAR_TEMP_0, STYLE_LUCAS
    goto_if_eq Route103_EventScript_Rival_DAWN
    compare VAR_TEMP_0, STYLE_DAWN
    goto_if_eq Route103_EventScript_Rival_LUCAS
    compare VAR_TEMP_0, STYLE_HILBERT
    goto_if_eq Route103_EventScript_Rival_HILDA
    compare VAR_TEMP_0, STYLE_HILDA
    goto_if_eq Route103_EventScript_Rival_HILBERT
    compare VAR_TEMP_0, STYLE_NATE
    goto_if_eq Route103_EventScript_Rival_ROSA
    compare VAR_TEMP_0, STYLE_ROSA
    goto_if_eq Route103_EventScript_Rival_NATE
    compare VAR_TEMP_0, STYLE_CALEM
    goto_if_eq Route103_EventScript_Rival_SERENA
    compare VAR_TEMP_0, STYLE_SERENA
    goto_if_eq Route103_EventScript_Rival_CALEM
    compare VAR_TEMP_0, STYLE_ELIO
    goto_if_eq Route103_EventScript_Rival_SELENE
    compare VAR_TEMP_0, STYLE_SELENE
    goto_if_eq Route103_EventScript_Rival_ELIO
    compare VAR_TEMP_0, STYLE_VICTOR
    goto_if_eq Route103_EventScript_Rival_GLORIA
    compare VAR_TEMP_0, STYLE_GLORIA
    goto_if_eq Route103_EventScript_Rival_VICTOR
    compare VAR_TEMP_0, STYLE_FLORIAN
    goto_if_eq Route103_EventScript_Rival_JULIANA
    compare VAR_TEMP_0, STYLE_JULIANA
    goto_if_eq Route103_EventScript_Rival_FLORIAN
    end

Route103_EventScript_Rival_BRENDAN::
    switch VAR_TEMP_1
    case STARTER_REGION_KANTO, Route103_EventScript_RivalBrendan
    case STARTER_REGION_JOHTO, Route103_EventScript_RivalBrendan
    case STARTER_REGION_HOENN, Route103_EventScript_RivalBrendan
    case STARTER_REGION_SINNOH, Route103_EventScript_RivalBrendan
    case STARTER_REGION_UNOVA, Route103_EventScript_RivalBrendan
    case STARTER_REGION_KALOS, Route103_EventScript_RivalBrendan
    case STARTER_REGION_ALOLA, Route103_EventScript_RivalBrendan
    case STARTER_REGION_GALAR, Route103_EventScript_RivalBrendan
    case STARTER_REGION_PALDEA, Route103_EventScript_RivalBrendan
    end

Route103_EventScript_Rival_MAY::
    switch VAR_TEMP_1
    case STARTER_REGION_KANTO, Route103_EventScript_RivalMay
    case STARTER_REGION_JOHTO, Route103_EventScript_RivalMay
    case STARTER_REGION_HOENN, Route103_EventScript_RivalMay
    case STARTER_REGION_SINNOH, Route103_EventScript_RivalMay
    case STARTER_REGION_UNOVA, Route103_EventScript_RivalMay
    case STARTER_REGION_KALOS, Route103_EventScript_RivalMay
    case STARTER_REGION_ALOLA, Route103_EventScript_RivalMay
    case STARTER_REGION_GALAR, Route103_EventScript_RivalMay
    case STARTER_REGION_PALDEA, Route103_EventScript_RivalMay
    end

Route103_EventScript_Rival_RED::
    switch VAR_TEMP_1
    case STARTER_REGION_KANTO, Route103_EventScript_RivalRed
    case STARTER_REGION_JOHTO, Route103_EventScript_RivalRed
    case STARTER_REGION_HOENN, Route103_EventScript_RivalRed
    case STARTER_REGION_SINNOH, Route103_EventScript_RivalRed
    case STARTER_REGION_UNOVA, Route103_EventScript_RivalRed
    case STARTER_REGION_KALOS, Route103_EventScript_RivalRed
    case STARTER_REGION_ALOLA, Route103_EventScript_RivalRed
    case STARTER_REGION_GALAR, Route103_EventScript_RivalRed
    case STARTER_REGION_PALDEA, Route103_EventScript_RivalRed
    end

Route103_EventScript_Rival_LEAF::
    switch VAR_TEMP_1
    case STARTER_REGION_KANTO, Route103_EventScript_RivalLeaf
    case STARTER_REGION_JOHTO, Route103_EventScript_RivalLeaf
    case STARTER_REGION_HOENN, Route103_EventScript_RivalLeaf
    case STARTER_REGION_SINNOH, Route103_EventScript_RivalLeaf
    case STARTER_REGION_UNOVA, Route103_EventScript_RivalLeaf
    case STARTER_REGION_KALOS, Route103_EventScript_RivalLeaf
    case STARTER_REGION_ALOLA, Route103_EventScript_RivalLeaf
    case STARTER_REGION_GALAR, Route103_EventScript_RivalLeaf
    case STARTER_REGION_PALDEA, Route103_EventScript_RivalLeaf
    end

Route103_EventScript_Rival_ETHAN::
    switch VAR_TEMP_1
    case STARTER_REGION_KANTO, Route103_EventScript_RivalEthan
    case STARTER_REGION_JOHTO, Route103_EventScript_RivalEthan
    case STARTER_REGION_HOENN, Route103_EventScript_RivalEthan
    case STARTER_REGION_SINNOH, Route103_EventScript_RivalEthan
    case STARTER_REGION_UNOVA, Route103_EventScript_RivalEthan
    case STARTER_REGION_KALOS, Route103_EventScript_RivalEthan
    case STARTER_REGION_ALOLA, Route103_EventScript_RivalEthan
    case STARTER_REGION_GALAR, Route103_EventScript_RivalEthan
    case STARTER_REGION_PALDEA, Route103_EventScript_RivalEthan
    end

Route103_EventScript_Rival_LYRA::
    switch VAR_TEMP_1
    case STARTER_REGION_KANTO, Route103_EventScript_RivalLyra
    case STARTER_REGION_JOHTO, Route103_EventScript_RivalLyra
    case STARTER_REGION_HOENN, Route103_EventScript_RivalLyra
    case STARTER_REGION_SINNOH, Route103_EventScript_RivalLyra
    case STARTER_REGION_UNOVA, Route103_EventScript_RivalLyra
    case STARTER_REGION_KALOS, Route103_EventScript_RivalLyra
    case STARTER_REGION_ALOLA, Route103_EventScript_RivalLyra
    case STARTER_REGION_GALAR, Route103_EventScript_RivalLyra
    case STARTER_REGION_PALDEA, Route103_EventScript_RivalLyra
    end

Route103_EventScript_Rival_LUCAS::
    switch VAR_TEMP_1
    case STARTER_REGION_KANTO, Route103_EventScript_RivalLucas
    case STARTER_REGION_JOHTO, Route103_EventScript_RivalLucas
    case STARTER_REGION_HOENN, Route103_EventScript_RivalLucas
    case STARTER_REGION_SINNOH, Route103_EventScript_RivalLucas
    case STARTER_REGION_UNOVA, Route103_EventScript_RivalLucas
    case STARTER_REGION_KALOS, Route103_EventScript_RivalLucas
    case STARTER_REGION_ALOLA, Route103_EventScript_RivalLucas
    case STARTER_REGION_GALAR, Route103_EventScript_RivalLucas
    case STARTER_REGION_PALDEA, Route103_EventScript_RivalLucas
    end

Route103_EventScript_Rival_DAWN::
    switch VAR_TEMP_1
    case STARTER_REGION_KANTO, Route103_EventScript_RivalDawn
    case STARTER_REGION_JOHTO, Route103_EventScript_RivalDawn
    case STARTER_REGION_HOENN, Route103_EventScript_RivalDawn
    case STARTER_REGION_SINNOH, Route103_EventScript_RivalDawn
    case STARTER_REGION_UNOVA, Route103_EventScript_RivalDawn
    case STARTER_REGION_KALOS, Route103_EventScript_RivalDawn
    case STARTER_REGION_ALOLA, Route103_EventScript_RivalDawn
    case STARTER_REGION_GALAR, Route103_EventScript_RivalDawn
    case STARTER_REGION_PALDEA, Route103_EventScript_RivalDawn
    end

Route103_EventScript_Rival_HILBERT::
    switch VAR_TEMP_1
    case STARTER_REGION_KANTO, Route103_EventScript_RivalHilbert
    case STARTER_REGION_JOHTO, Route103_EventScript_RivalHilbert
    case STARTER_REGION_HOENN, Route103_EventScript_RivalHilbert
    case STARTER_REGION_SINNOH, Route103_EventScript_RivalHilbert
    case STARTER_REGION_UNOVA, Route103_EventScript_RivalHilbert
    case STARTER_REGION_KALOS, Route103_EventScript_RivalHilbert
    case STARTER_REGION_ALOLA, Route103_EventScript_RivalHilbert
    case STARTER_REGION_GALAR, Route103_EventScript_RivalHilbert
    case STARTER_REGION_PALDEA, Route103_EventScript_RivalHilbert
    end

Route103_EventScript_Rival_HILDA::
    switch VAR_TEMP_1
    case STARTER_REGION_KANTO, Route103_EventScript_RivalHilda
    case STARTER_REGION_JOHTO, Route103_EventScript_RivalHilda
    case STARTER_REGION_HOENN, Route103_EventScript_RivalHilda
    case STARTER_REGION_SINNOH, Route103_EventScript_RivalHilda
    case STARTER_REGION_UNOVA, Route103_EventScript_RivalHilda
    case STARTER_REGION_KALOS, Route103_EventScript_RivalHilda
    case STARTER_REGION_ALOLA, Route103_EventScript_RivalHilda
    case STARTER_REGION_GALAR, Route103_EventScript_RivalHilda
    case STARTER_REGION_PALDEA, Route103_EventScript_RivalHilda
    end

Route103_EventScript_Rival_NATE::
    switch VAR_TEMP_1
    case STARTER_REGION_KANTO, Route103_EventScript_RivalNate
    case STARTER_REGION_JOHTO, Route103_EventScript_RivalNate
    case STARTER_REGION_HOENN, Route103_EventScript_RivalNate
    case STARTER_REGION_SINNOH, Route103_EventScript_RivalNate
    case STARTER_REGION_UNOVA, Route103_EventScript_RivalNate
    case STARTER_REGION_KALOS, Route103_EventScript_RivalNate
    case STARTER_REGION_ALOLA, Route103_EventScript_RivalNate
    case STARTER_REGION_GALAR, Route103_EventScript_RivalNate
    case STARTER_REGION_PALDEA, Route103_EventScript_RivalNate
    end

Route103_EventScript_Rival_ROSA::
    switch VAR_TEMP_1
    case STARTER_REGION_KANTO, Route103_EventScript_RivalRosa
    case STARTER_REGION_JOHTO, Route103_EventScript_RivalRosa
    case STARTER_REGION_HOENN, Route103_EventScript_RivalRosa
    case STARTER_REGION_SINNOH, Route103_EventScript_RivalRosa
    case STARTER_REGION_UNOVA, Route103_EventScript_RivalRosa
    case STARTER_REGION_KALOS, Route103_EventScript_RivalRosa
    case STARTER_REGION_ALOLA, Route103_EventScript_RivalRosa
    case STARTER_REGION_GALAR, Route103_EventScript_RivalRosa
    case STARTER_REGION_PALDEA, Route103_EventScript_RivalRosa
    end

Route103_EventScript_Rival_CALEM::
    switch VAR_TEMP_1
    case STARTER_REGION_KANTO, Route103_EventScript_RivalCalem
    case STARTER_REGION_JOHTO, Route103_EventScript_RivalCalem
    case STARTER_REGION_HOENN, Route103_EventScript_RivalCalem
    case STARTER_REGION_SINNOH, Route103_EventScript_RivalCalem
    case STARTER_REGION_UNOVA, Route103_EventScript_RivalCalem
    case STARTER_REGION_KALOS, Route103_EventScript_RivalCalem
    case STARTER_REGION_ALOLA, Route103_EventScript_RivalCalem
    case STARTER_REGION_GALAR, Route103_EventScript_RivalCalem
    case STARTER_REGION_PALDEA, Route103_EventScript_RivalCalem
    end

Route103_EventScript_Rival_SERENA::
    switch VAR_TEMP_1
    case STARTER_REGION_KANTO, Route103_EventScript_RivalSerena
    case STARTER_REGION_JOHTO, Route103_EventScript_RivalSerena
    case STARTER_REGION_HOENN, Route103_EventScript_RivalSerena
    case STARTER_REGION_SINNOH, Route103_EventScript_RivalSerena
    case STARTER_REGION_UNOVA, Route103_EventScript_RivalSerena
    case STARTER_REGION_KALOS, Route103_EventScript_RivalSerena
    case STARTER_REGION_ALOLA, Route103_EventScript_RivalSerena
    case STARTER_REGION_GALAR, Route103_EventScript_RivalSerena
    case STARTER_REGION_PALDEA, Route103_EventScript_RivalSerena
    end

Route103_EventScript_Rival_ELIO::
    switch VAR_TEMP_1
    case STARTER_REGION_KANTO, Route103_EventScript_RivalElio
    case STARTER_REGION_JOHTO, Route103_EventScript_RivalElio
    case STARTER_REGION_HOENN, Route103_EventScript_RivalElio
    case STARTER_REGION_SINNOH, Route103_EventScript_RivalElio
    case STARTER_REGION_UNOVA, Route103_EventScript_RivalElio
    case STARTER_REGION_KALOS, Route103_EventScript_RivalElio
    case STARTER_REGION_ALOLA, Route103_EventScript_RivalElio
    case STARTER_REGION_GALAR, Route103_EventScript_RivalElio
    case STARTER_REGION_PALDEA, Route103_EventScript_RivalElio
    end

Route103_EventScript_Rival_SELENE::
    switch VAR_TEMP_1
    case STARTER_REGION_KANTO, Route103_EventScript_RivalSelene
    case STARTER_REGION_JOHTO, Route103_EventScript_RivalSelene
    case STARTER_REGION_HOENN, Route103_EventScript_RivalSelene
    case STARTER_REGION_SINNOH, Route103_EventScript_RivalSelene
    case STARTER_REGION_UNOVA, Route103_EventScript_RivalSelene
    case STARTER_REGION_KALOS, Route103_EventScript_RivalSelene
    case STARTER_REGION_ALOLA, Route103_EventScript_RivalSelene
    case STARTER_REGION_GALAR, Route103_EventScript_RivalSelene
    case STARTER_REGION_PALDEA, Route103_EventScript_RivalSelene
    end

Route103_EventScript_Rival_VICTOR::
    switch VAR_TEMP_1
    case STARTER_REGION_KANTO, Route103_EventScript_RivalVictor
    case STARTER_REGION_JOHTO, Route103_EventScript_RivalVictor
    case STARTER_REGION_HOENN, Route103_EventScript_RivalVictor
    case STARTER_REGION_SINNOH, Route103_EventScript_RivalVictor
    case STARTER_REGION_UNOVA, Route103_EventScript_RivalVictor
    case STARTER_REGION_KALOS, Route103_EventScript_RivalVictor
    case STARTER_REGION_ALOLA, Route103_EventScript_RivalVictor
    case STARTER_REGION_GALAR, Route103_EventScript_RivalVictor
    case STARTER_REGION_PALDEA, Route103_EventScript_RivalVictor
    end

Route103_EventScript_Rival_GLORIA::
    switch VAR_TEMP_1
    case STARTER_REGION_KANTO, Route103_EventScript_RivalGloria
    case STARTER_REGION_JOHTO, Route103_EventScript_RivalGloria
    case STARTER_REGION_HOENN, Route103_EventScript_RivalGloria
    case STARTER_REGION_SINNOH, Route103_EventScript_RivalGloria
    case STARTER_REGION_UNOVA, Route103_EventScript_RivalGloria
    case STARTER_REGION_KALOS, Route103_EventScript_RivalGloria
    case STARTER_REGION_ALOLA, Route103_EventScript_RivalGloria
    case STARTER_REGION_GALAR, Route103_EventScript_RivalGloria
    case STARTER_REGION_PALDEA, Route103_EventScript_RivalGloria
    end

Route103_EventScript_Rival_FLORIAN::
    switch VAR_TEMP_1
    case STARTER_REGION_KANTO, Route103_EventScript_RivalFlorian
    case STARTER_REGION_JOHTO, Route103_EventScript_RivalFlorian
    case STARTER_REGION_HOENN, Route103_EventScript_RivalFlorian
    case STARTER_REGION_SINNOH, Route103_EventScript_RivalFlorian
    case STARTER_REGION_UNOVA, Route103_EventScript_RivalFlorian
    case STARTER_REGION_KALOS, Route103_EventScript_RivalFlorian
    case STARTER_REGION_ALOLA, Route103_EventScript_RivalFlorian
    case STARTER_REGION_GALAR, Route103_EventScript_RivalFlorian
    case STARTER_REGION_PALDEA, Route103_EventScript_RivalFlorian
    end

Route103_EventScript_Rival_JULIANA::
    switch VAR_TEMP_1
    case STARTER_REGION_KANTO, Route103_EventScript_RivalJuliana
    case STARTER_REGION_JOHTO, Route103_EventScript_RivalJuliana
    case STARTER_REGION_HOENN, Route103_EventScript_RivalJuliana
    case STARTER_REGION_SINNOH, Route103_EventScript_RivalJuliana
    case STARTER_REGION_UNOVA, Route103_EventScript_RivalJuliana
    case STARTER_REGION_KALOS, Route103_EventScript_RivalJuliana
    case STARTER_REGION_ALOLA, Route103_EventScript_RivalJuliana
    case STARTER_REGION_GALAR, Route103_EventScript_RivalJuliana
    case STARTER_REGION_PALDEA, Route103_EventScript_RivalJuliana
    end

Route103_EventScript_RivalMay::
    msgbox Route103_Text_MayRoute103Pokemon, MSGBOX_DEFAULT
    closemessage
    playbgm MUS_ENCOUNTER_MAY, TRUE
    applymovement LOCALID_ROUTE103_RIVAL, Common_Movement_FacePlayer
    waitmovement 0
    applymovement LOCALID_ROUTE103_RIVAL, Common_Movement_ExclamationMark
    waitmovement 0
    applymovement LOCALID_ROUTE103_RIVAL, Common_Movement_Delay48
    waitmovement 0
    msgbox Route103_Text_MayLetsBattle, MSGBOX_DEFAULT
    waitbuttonpress
    closemessage
    switch VAR_STARTER_REGION
    case STARTER_REGION_KANTO, Route103_EventScript_StartMay_Kanto
    case STARTER_REGION_JOHTO, Route103_EventScript_StartMay_Johto
    case STARTER_REGION_HOENN, Route103_EventScript_StartMay_Hoenn
    case STARTER_REGION_SINNOH, Route103_EventScript_StartMay_Sinnoh
    case STARTER_REGION_UNOVA, Route103_EventScript_StartMay_Unova
    case STARTER_REGION_KALOS, Route103_EventScript_StartMay_Kalos
    case STARTER_REGION_ALOLA, Route103_EventScript_StartMay_Alola
    case STARTER_REGION_GALAR, Route103_EventScript_StartMay_Galar
    case STARTER_REGION_PALDEA, Route103_EventScript_StartMay_Paldea
    end

Route103_EventScript_RivalBrendan::
    msgbox Route103_Text_BrendanRoute103Pokemon, MSGBOX_DEFAULT
    closemessage
    playbgm MUS_ENCOUNTER_BRENDAN, TRUE
    applymovement LOCALID_ROUTE103_RIVAL, Common_Movement_FacePlayer
    waitmovement 0
    applymovement LOCALID_ROUTE103_RIVAL, Common_Movement_ExclamationMark
    waitmovement 0
    applymovement LOCALID_ROUTE103_RIVAL, Common_Movement_Delay48
    waitmovement 0
    msgbox Route103_Text_BrendanLetsBattle, MSGBOX_DEFAULT
    switch VAR_STARTER_REGION
    case STARTER_REGION_KANTO, Route103_EventScript_StartBrendan_Kanto
    case STARTER_REGION_JOHTO, Route103_EventScript_StartBrendan_Johto
    case STARTER_REGION_HOENN, Route103_EventScript_StartBrendan_Hoenn
    case STARTER_REGION_SINNOH, Route103_EventScript_StartBrendan_Sinnoh
    case STARTER_REGION_UNOVA, Route103_EventScript_StartBrendan_Unova
    case STARTER_REGION_KALOS, Route103_EventScript_StartBrendan_Kalos
    case STARTER_REGION_ALOLA, Route103_EventScript_StartBrendan_Alola
    case STARTER_REGION_GALAR, Route103_EventScript_StartBrendan_Galar
    case STARTER_REGION_PALDEA, Route103_EventScript_StartBrendan_Paldea
    end

Route103_EventScript_RivalRed::
    msgbox Route103_Text_RedRoute103Pokemon, MSGBOX_DEFAULT
    closemessage
    playbgm MUS_ENCOUNTER_BRENDAN, TRUE
    applymovement LOCALID_ROUTE103_RIVAL, Common_Movement_FacePlayer
    waitmovement 0
    applymovement LOCALID_ROUTE103_RIVAL, Common_Movement_ExclamationMark
    waitmovement 0
    applymovement LOCALID_ROUTE103_RIVAL, Common_Movement_Delay48
    waitmovement 0
    msgbox Route103_Text_RedLetsBattle, MSGBOX_DEFAULT
    switch VAR_STARTER_REGION
    case STARTER_REGION_KANTO, Route103_EventScript_StartRed_Kanto
    case STARTER_REGION_JOHTO, Route103_EventScript_StartRed_Johto
    case STARTER_REGION_HOENN, Route103_EventScript_StartRed_Hoenn
    case STARTER_REGION_SINNOH, Route103_EventScript_StartRed_Sinnoh
    case STARTER_REGION_UNOVA, Route103_EventScript_StartRed_Unova
    case STARTER_REGION_KALOS, Route103_EventScript_StartRed_Kalos
    case STARTER_REGION_ALOLA, Route103_EventScript_StartRed_Alola
    case STARTER_REGION_GALAR, Route103_EventScript_StartRed_Galar
    case STARTER_REGION_PALDEA, Route103_EventScript_StartRed_Paldea
    end

Route103_EventScript_RivalLeaf::
    msgbox Route103_Text_LeafRoute103Pokemon, MSGBOX_DEFAULT
    closemessage
    playbgm MUS_ENCOUNTER_MAY, TRUE
    applymovement LOCALID_ROUTE103_RIVAL, Common_Movement_FacePlayer
    waitmovement 0
    applymovement LOCALID_ROUTE103_RIVAL, Common_Movement_ExclamationMark
    waitmovement 0
    applymovement LOCALID_ROUTE103_RIVAL, Common_Movement_Delay48
    waitmovement 0
    msgbox Route103_Text_LeafLetsBattle, MSGBOX_DEFAULT
    switch VAR_STARTER_REGION
    case STARTER_REGION_KANTO, Route103_EventScript_StartLeaf_Kanto
    case STARTER_REGION_JOHTO, Route103_EventScript_StartLeaf_Johto
    case STARTER_REGION_HOENN, Route103_EventScript_StartLeaf_Hoenn
    case STARTER_REGION_SINNOH, Route103_EventScript_StartLeaf_Sinnoh
    case STARTER_REGION_UNOVA, Route103_EventScript_StartLeaf_Unova
    case STARTER_REGION_KALOS, Route103_EventScript_StartLeaf_Kalos
    case STARTER_REGION_ALOLA, Route103_EventScript_StartLeaf_Alola
    case STARTER_REGION_GALAR, Route103_EventScript_StartLeaf_Galar
    case STARTER_REGION_PALDEA, Route103_EventScript_StartLeaf_Paldea
    end

Route103_EventScript_RivalEthan::
    msgbox Route103_Text_BrendanRoute103Pokemon, MSGBOX_DEFAULT
    closemessage
    playbgm MUS_ENCOUNTER_BRENDAN, TRUE
    applymovement LOCALID_ROUTE103_RIVAL, Common_Movement_FacePlayer
    waitmovement 0
    applymovement LOCALID_ROUTE103_RIVAL, Common_Movement_ExclamationMark
    waitmovement 0
    applymovement LOCALID_ROUTE103_RIVAL, Common_Movement_Delay48
    waitmovement 0
    msgbox Route103_Text_BrendanLetsBattle, MSGBOX_DEFAULT
    switch VAR_STARTER_REGION
    case STARTER_REGION_KANTO, Route103_EventScript_StartEthan_Kanto
    case STARTER_REGION_JOHTO, Route103_EventScript_StartEthan_Johto
    case STARTER_REGION_HOENN, Route103_EventScript_StartEthan_Hoenn
    case STARTER_REGION_SINNOH, Route103_EventScript_StartEthan_Sinnoh
    case STARTER_REGION_UNOVA, Route103_EventScript_StartEthan_Unova
    case STARTER_REGION_KALOS, Route103_EventScript_StartEthan_Kalos
    case STARTER_REGION_ALOLA, Route103_EventScript_StartEthan_Alola
    case STARTER_REGION_GALAR, Route103_EventScript_StartEthan_Galar
    case STARTER_REGION_PALDEA, Route103_EventScript_StartEthan_Paldea
    end

Route103_EventScript_RivalLyra::
    msgbox Route103_Text_MayRoute103Pokemon, MSGBOX_DEFAULT
    closemessage
    playbgm MUS_ENCOUNTER_MAY, TRUE
    applymovement LOCALID_ROUTE103_RIVAL, Common_Movement_FacePlayer
    waitmovement 0
    applymovement LOCALID_ROUTE103_RIVAL, Common_Movement_ExclamationMark
    waitmovement 0
    applymovement LOCALID_ROUTE103_RIVAL, Common_Movement_Delay48
    waitmovement 0
    msgbox Route103_Text_MayLetsBattle, MSGBOX_DEFAULT
    switch VAR_STARTER_REGION
    case STARTER_REGION_KANTO, Route103_EventScript_StartLyra_Kanto
    case STARTER_REGION_JOHTO, Route103_EventScript_StartLyra_Johto
    case STARTER_REGION_HOENN, Route103_EventScript_StartLyra_Hoenn
    case STARTER_REGION_SINNOH, Route103_EventScript_StartLyra_Sinnoh
    case STARTER_REGION_UNOVA, Route103_EventScript_StartLyra_Unova
    case STARTER_REGION_KALOS, Route103_EventScript_StartLyra_Kalos
    case STARTER_REGION_ALOLA, Route103_EventScript_StartLyra_Alola
    case STARTER_REGION_GALAR, Route103_EventScript_StartLyra_Galar
    case STARTER_REGION_PALDEA, Route103_EventScript_StartLyra_Paldea
    end

Route103_EventScript_RivalLucas::
    msgbox Route103_Text_BrendanRoute103Pokemon, MSGBOX_DEFAULT
    closemessage
    playbgm MUS_ENCOUNTER_BRENDAN, TRUE
    applymovement LOCALID_ROUTE103_RIVAL, Common_Movement_FacePlayer
    waitmovement 0
    applymovement LOCALID_ROUTE103_RIVAL, Common_Movement_ExclamationMark
    waitmovement 0
    applymovement LOCALID_ROUTE103_RIVAL, Common_Movement_Delay48
    waitmovement 0
    msgbox Route103_Text_BrendanLetsBattle, MSGBOX_DEFAULT
    switch VAR_STARTER_REGION
    case STARTER_REGION_KANTO, Route103_EventScript_StartLucas_Kanto
    case STARTER_REGION_JOHTO, Route103_EventScript_StartLucas_Johto
    case STARTER_REGION_HOENN, Route103_EventScript_StartLucas_Hoenn
    case STARTER_REGION_SINNOH, Route103_EventScript_StartLucas_Sinnoh
    case STARTER_REGION_UNOVA, Route103_EventScript_StartLucas_Unova
    case STARTER_REGION_KALOS, Route103_EventScript_StartLucas_Kalos
    case STARTER_REGION_ALOLA, Route103_EventScript_StartLucas_Alola
    case STARTER_REGION_GALAR, Route103_EventScript_StartLucas_Galar
    case STARTER_REGION_PALDEA, Route103_EventScript_StartLucas_Paldea
    end

Route103_EventScript_RivalDawn::
    msgbox Route103_Text_MayRoute103Pokemon, MSGBOX_DEFAULT
    closemessage
    playbgm MUS_ENCOUNTER_MAY, TRUE
    applymovement LOCALID_ROUTE103_RIVAL, Common_Movement_FacePlayer
    waitmovement 0
    applymovement LOCALID_ROUTE103_RIVAL, Common_Movement_ExclamationMark
    waitmovement 0
    applymovement LOCALID_ROUTE103_RIVAL, Common_Movement_Delay48
    waitmovement 0
    msgbox Route103_Text_MayLetsBattle, MSGBOX_DEFAULT
    switch VAR_STARTER_REGION
    case STARTER_REGION_KANTO, Route103_EventScript_StartDawn_Kanto
    case STARTER_REGION_JOHTO, Route103_EventScript_StartDawn_Johto
    case STARTER_REGION_HOENN, Route103_EventScript_StartDawn_Hoenn
    case STARTER_REGION_SINNOH, Route103_EventScript_StartDawn_Sinnoh
    case STARTER_REGION_UNOVA, Route103_EventScript_StartDawn_Unova
    case STARTER_REGION_KALOS, Route103_EventScript_StartDawn_Kalos
    case STARTER_REGION_ALOLA, Route103_EventScript_StartDawn_Alola
    case STARTER_REGION_GALAR, Route103_EventScript_StartDawn_Galar
    case STARTER_REGION_PALDEA, Route103_EventScript_StartDawn_Paldea
    end

Route103_EventScript_RivalHilbert::
    msgbox Route103_Text_BrendanRoute103Pokemon, MSGBOX_DEFAULT
    closemessage
    playbgm MUS_ENCOUNTER_BRENDAN, TRUE
    applymovement LOCALID_ROUTE103_RIVAL, Common_Movement_FacePlayer
    waitmovement 0
    applymovement LOCALID_ROUTE103_RIVAL, Common_Movement_ExclamationMark
    waitmovement 0
    applymovement LOCALID_ROUTE103_RIVAL, Common_Movement_Delay48
    waitmovement 0
    msgbox Route103_Text_BrendanLetsBattle, MSGBOX_DEFAULT
    switch VAR_STARTER_REGION
    case STARTER_REGION_KANTO, Route103_EventScript_StartHilbert_Kanto
    case STARTER_REGION_JOHTO, Route103_EventScript_StartHilbert_Johto
    case STARTER_REGION_HOENN, Route103_EventScript_StartHilbert_Hoenn
    case STARTER_REGION_SINNOH, Route103_EventScript_StartHilbert_Sinnoh
    case STARTER_REGION_UNOVA, Route103_EventScript_StartHilbert_Unova
    case STARTER_REGION_KALOS, Route103_EventScript_StartHilbert_Kalos
    case STARTER_REGION_ALOLA, Route103_EventScript_StartHilbert_Alola
    case STARTER_REGION_GALAR, Route103_EventScript_StartHilbert_Galar
    case STARTER_REGION_PALDEA, Route103_EventScript_StartHilbert_Paldea
    end

Route103_EventScript_RivalHilda::
    msgbox Route103_Text_MayRoute103Pokemon, MSGBOX_DEFAULT
    closemessage
    playbgm MUS_ENCOUNTER_MAY, TRUE
    applymovement LOCALID_ROUTE103_RIVAL, Common_Movement_FacePlayer
    waitmovement 0
    applymovement LOCALID_ROUTE103_RIVAL, Common_Movement_ExclamationMark
    waitmovement 0
    applymovement LOCALID_ROUTE103_RIVAL, Common_Movement_Delay48
    waitmovement 0
    msgbox Route103_Text_MayLetsBattle, MSGBOX_DEFAULT
    switch VAR_STARTER_REGION
    case STARTER_REGION_KANTO, Route103_EventScript_StartHilda_Kanto
    case STARTER_REGION_JOHTO, Route103_EventScript_StartHilda_Johto
    case STARTER_REGION_HOENN, Route103_EventScript_StartHilda_Hoenn
    case STARTER_REGION_SINNOH, Route103_EventScript_StartHilda_Sinnoh
    case STARTER_REGION_UNOVA, Route103_EventScript_StartHilda_Unova
    case STARTER_REGION_KALOS, Route103_EventScript_StartHilda_Kalos
    case STARTER_REGION_ALOLA, Route103_EventScript_StartHilda_Alola
    case STARTER_REGION_GALAR, Route103_EventScript_StartHilda_Galar
    case STARTER_REGION_PALDEA, Route103_EventScript_StartHilda_Paldea
    end

Route103_EventScript_RivalNate::
    msgbox Route103_Text_BrendanRoute103Pokemon, MSGBOX_DEFAULT
    closemessage
    playbgm MUS_ENCOUNTER_BRENDAN, TRUE
    applymovement LOCALID_ROUTE103_RIVAL, Common_Movement_FacePlayer
    waitmovement 0
    applymovement LOCALID_ROUTE103_RIVAL, Common_Movement_ExclamationMark
    waitmovement 0
    applymovement LOCALID_ROUTE103_RIVAL, Common_Movement_Delay48
    waitmovement 0
    msgbox Route103_Text_BrendanLetsBattle, MSGBOX_DEFAULT
    switch VAR_STARTER_REGION
    case STARTER_REGION_KANTO, Route103_EventScript_StartNate_Kanto
    case STARTER_REGION_JOHTO, Route103_EventScript_StartNate_Johto
    case STARTER_REGION_HOENN, Route103_EventScript_StartNate_Hoenn
    case STARTER_REGION_SINNOH, Route103_EventScript_StartNate_Sinnoh
    case STARTER_REGION_UNOVA, Route103_EventScript_StartNate_Unova
    case STARTER_REGION_KALOS, Route103_EventScript_StartNate_Kalos
    case STARTER_REGION_ALOLA, Route103_EventScript_StartNate_Alola
    case STARTER_REGION_GALAR, Route103_EventScript_StartNate_Galar
    case STARTER_REGION_PALDEA, Route103_EventScript_StartNate_Paldea
    end

Route103_EventScript_RivalRosa::
    msgbox Route103_Text_MayRoute103Pokemon, MSGBOX_DEFAULT
    closemessage
    playbgm MUS_ENCOUNTER_MAY, TRUE
    applymovement LOCALID_ROUTE103_RIVAL, Common_Movement_FacePlayer
    waitmovement 0
    applymovement LOCALID_ROUTE103_RIVAL, Common_Movement_ExclamationMark
    waitmovement 0
    applymovement LOCALID_ROUTE103_RIVAL, Common_Movement_Delay48
    waitmovement 0
    msgbox Route103_Text_MayLetsBattle, MSGBOX_DEFAULT
    switch VAR_STARTER_REGION
    case STARTER_REGION_KANTO, Route103_EventScript_StartRosa_Kanto
    case STARTER_REGION_JOHTO, Route103_EventScript_StartRosa_Johto
    case STARTER_REGION_HOENN, Route103_EventScript_StartRosa_Hoenn
    case STARTER_REGION_SINNOH, Route103_EventScript_StartRosa_Sinnoh
    case STARTER_REGION_UNOVA, Route103_EventScript_StartRosa_Unova
    case STARTER_REGION_KALOS, Route103_EventScript_StartRosa_Kalos
    case STARTER_REGION_ALOLA, Route103_EventScript_StartRosa_Alola
    case STARTER_REGION_GALAR, Route103_EventScript_StartRosa_Galar
    case STARTER_REGION_PALDEA, Route103_EventScript_StartRosa_Paldea
    end

Route103_EventScript_RivalCalem::
    msgbox Route103_Text_BrendanRoute103Pokemon, MSGBOX_DEFAULT
    closemessage
    playbgm MUS_ENCOUNTER_BRENDAN, TRUE
    applymovement LOCALID_ROUTE103_RIVAL, Common_Movement_FacePlayer
    waitmovement 0
    applymovement LOCALID_ROUTE103_RIVAL, Common_Movement_ExclamationMark
    waitmovement 0
    applymovement LOCALID_ROUTE103_RIVAL, Common_Movement_Delay48
    waitmovement 0
    msgbox Route103_Text_BrendanLetsBattle, MSGBOX_DEFAULT
    switch VAR_STARTER_REGION
    case STARTER_REGION_KANTO, Route103_EventScript_StartCalem_Kanto
    case STARTER_REGION_JOHTO, Route103_EventScript_StartCalem_Johto
    case STARTER_REGION_HOENN, Route103_EventScript_StartCalem_Hoenn
    case STARTER_REGION_SINNOH, Route103_EventScript_StartCalem_Sinnoh
    case STARTER_REGION_UNOVA, Route103_EventScript_StartCalem_Unova
    case STARTER_REGION_KALOS, Route103_EventScript_StartCalem_Kalos
    case STARTER_REGION_ALOLA, Route103_EventScript_StartCalem_Alola
    case STARTER_REGION_GALAR, Route103_EventScript_StartCalem_Galar
    case STARTER_REGION_PALDEA, Route103_EventScript_StartCalem_Paldea
    end

Route103_EventScript_RivalSerena::
    msgbox Route103_Text_MayRoute103Pokemon, MSGBOX_DEFAULT
    closemessage
    playbgm MUS_ENCOUNTER_MAY, TRUE
    applymovement LOCALID_ROUTE103_RIVAL, Common_Movement_FacePlayer
    waitmovement 0
    applymovement LOCALID_ROUTE103_RIVAL, Common_Movement_ExclamationMark
    waitmovement 0
    applymovement LOCALID_ROUTE103_RIVAL, Common_Movement_Delay48
    waitmovement 0
    msgbox Route103_Text_MayLetsBattle, MSGBOX_DEFAULT
    switch VAR_STARTER_REGION
    case STARTER_REGION_KANTO, Route103_EventScript_StartSerena_Kanto
    case STARTER_REGION_JOHTO, Route103_EventScript_StartSerena_Johto
    case STARTER_REGION_HOENN, Route103_EventScript_StartSerena_Hoenn
    case STARTER_REGION_SINNOH, Route103_EventScript_StartSerena_Sinnoh
    case STARTER_REGION_UNOVA, Route103_EventScript_StartSerena_Unova
    case STARTER_REGION_KALOS, Route103_EventScript_StartSerena_Kalos
    case STARTER_REGION_ALOLA, Route103_EventScript_StartSerena_Alola
    case STARTER_REGION_GALAR, Route103_EventScript_StartSerena_Galar
    case STARTER_REGION_PALDEA, Route103_EventScript_StartSerena_Paldea
    end

Route103_EventScript_RivalElio::
    msgbox Route103_Text_BrendanRoute103Pokemon, MSGBOX_DEFAULT
    closemessage
    playbgm MUS_ENCOUNTER_BRENDAN, TRUE
    applymovement LOCALID_ROUTE103_RIVAL, Common_Movement_FacePlayer
    waitmovement 0
    applymovement LOCALID_ROUTE103_RIVAL, Common_Movement_ExclamationMark
    waitmovement 0
    applymovement LOCALID_ROUTE103_RIVAL, Common_Movement_Delay48
    waitmovement 0
    msgbox Route103_Text_BrendanLetsBattle, MSGBOX_DEFAULT
    switch VAR_STARTER_REGION
    case STARTER_REGION_KANTO, Route103_EventScript_StartElio_Kanto
    case STARTER_REGION_JOHTO, Route103_EventScript_StartElio_Johto
    case STARTER_REGION_HOENN, Route103_EventScript_StartElio_Hoenn
    case STARTER_REGION_SINNOH, Route103_EventScript_StartElio_Sinnoh
    case STARTER_REGION_UNOVA, Route103_EventScript_StartElio_Unova
    case STARTER_REGION_KALOS, Route103_EventScript_StartElio_Kalos
    case STARTER_REGION_ALOLA, Route103_EventScript_StartElio_Alola
    case STARTER_REGION_GALAR, Route103_EventScript_StartElio_Galar
    case STARTER_REGION_PALDEA, Route103_EventScript_StartElio_Paldea
    end

Route103_EventScript_RivalSelene::
    msgbox Route103_Text_MayRoute103Pokemon, MSGBOX_DEFAULT
    closemessage
    playbgm MUS_ENCOUNTER_MAY, TRUE
    applymovement LOCALID_ROUTE103_RIVAL, Common_Movement_FacePlayer
    waitmovement 0
    applymovement LOCALID_ROUTE103_RIVAL, Common_Movement_ExclamationMark
    waitmovement 0
    applymovement LOCALID_ROUTE103_RIVAL, Common_Movement_Delay48
    waitmovement 0
    msgbox Route103_Text_MayLetsBattle, MSGBOX_DEFAULT
    switch VAR_STARTER_REGION
    case STARTER_REGION_KANTO, Route103_EventScript_StartSelene_Kanto
    case STARTER_REGION_JOHTO, Route103_EventScript_StartSelene_Johto
    case STARTER_REGION_HOENN, Route103_EventScript_StartSelene_Hoenn
    case STARTER_REGION_SINNOH, Route103_EventScript_StartSelene_Sinnoh
    case STARTER_REGION_UNOVA, Route103_EventScript_StartSelene_Unova
    case STARTER_REGION_KALOS, Route103_EventScript_StartSelene_Kalos
    case STARTER_REGION_ALOLA, Route103_EventScript_StartSelene_Alola
    case STARTER_REGION_GALAR, Route103_EventScript_StartSelene_Galar
    case STARTER_REGION_PALDEA, Route103_EventScript_StartSelene_Paldea
    end

Route103_EventScript_RivalVictor::
    msgbox Route103_Text_BrendanRoute103Pokemon, MSGBOX_DEFAULT
    closemessage
    playbgm MUS_ENCOUNTER_BRENDAN, TRUE
    applymovement LOCALID_ROUTE103_RIVAL, Common_Movement_FacePlayer
    waitmovement 0
    applymovement LOCALID_ROUTE103_RIVAL, Common_Movement_ExclamationMark
    waitmovement 0
    applymovement LOCALID_ROUTE103_RIVAL, Common_Movement_Delay48
    waitmovement 0
    msgbox Route103_Text_BrendanLetsBattle, MSGBOX_DEFAULT
    switch VAR_STARTER_REGION
    case STARTER_REGION_KANTO, Route103_EventScript_StartVictor_Kanto
    case STARTER_REGION_JOHTO, Route103_EventScript_StartVictor_Johto
    case STARTER_REGION_HOENN, Route103_EventScript_StartVictor_Hoenn
    case STARTER_REGION_SINNOH, Route103_EventScript_StartVictor_Sinnoh
    case STARTER_REGION_UNOVA, Route103_EventScript_StartVictor_Unova
    case STARTER_REGION_KALOS, Route103_EventScript_StartVictor_Kalos
    case STARTER_REGION_ALOLA, Route103_EventScript_StartVictor_Alola
    case STARTER_REGION_GALAR, Route103_EventScript_StartVictor_Galar
    case STARTER_REGION_PALDEA, Route103_EventScript_StartVictor_Paldea
    end

Route103_EventScript_RivalGloria::
    msgbox Route103_Text_MayRoute103Pokemon, MSGBOX_DEFAULT
    closemessage
    playbgm MUS_ENCOUNTER_MAY, TRUE
    applymovement LOCALID_ROUTE103_RIVAL, Common_Movement_FacePlayer
    waitmovement 0
    applymovement LOCALID_ROUTE103_RIVAL, Common_Movement_ExclamationMark
    waitmovement 0
    applymovement LOCALID_ROUTE103_RIVAL, Common_Movement_Delay48
    waitmovement 0
    msgbox Route103_Text_MayLetsBattle, MSGBOX_DEFAULT
    switch VAR_STARTER_REGION
    case STARTER_REGION_KANTO, Route103_EventScript_StartGloria_Kanto
    case STARTER_REGION_JOHTO, Route103_EventScript_StartGloria_Johto
    case STARTER_REGION_HOENN, Route103_EventScript_StartGloria_Hoenn
    case STARTER_REGION_SINNOH, Route103_EventScript_StartGloria_Sinnoh
    case STARTER_REGION_UNOVA, Route103_EventScript_StartGloria_Unova
    case STARTER_REGION_KALOS, Route103_EventScript_StartGloria_Kalos
    case STARTER_REGION_ALOLA, Route103_EventScript_StartGloria_Alola
    case STARTER_REGION_GALAR, Route103_EventScript_StartGloria_Galar
    case STARTER_REGION_PALDEA, Route103_EventScript_StartGloria_Paldea
    end

Route103_EventScript_RivalFlorian::
    msgbox Route103_Text_BrendanRoute103Pokemon, MSGBOX_DEFAULT
    closemessage
    playbgm MUS_ENCOUNTER_BRENDAN, TRUE
    applymovement LOCALID_ROUTE103_RIVAL, Common_Movement_FacePlayer
    waitmovement 0
    applymovement LOCALID_ROUTE103_RIVAL, Common_Movement_ExclamationMark
    waitmovement 0
    applymovement LOCALID_ROUTE103_RIVAL, Common_Movement_Delay48
    waitmovement 0
    msgbox Route103_Text_BrendanLetsBattle, MSGBOX_DEFAULT
    switch VAR_STARTER_REGION
    case STARTER_REGION_KANTO, Route103_EventScript_StartFlorian_Kanto
    case STARTER_REGION_JOHTO, Route103_EventScript_StartFlorian_Johto
    case STARTER_REGION_HOENN, Route103_EventScript_StartFlorian_Hoenn
    case STARTER_REGION_SINNOH, Route103_EventScript_StartFlorian_Sinnoh
    case STARTER_REGION_UNOVA, Route103_EventScript_StartFlorian_Unova
    case STARTER_REGION_KALOS, Route103_EventScript_StartFlorian_Kalos
    case STARTER_REGION_ALOLA, Route103_EventScript_StartFlorian_Alola
    case STARTER_REGION_GALAR, Route103_EventScript_StartFlorian_Galar
    case STARTER_REGION_PALDEA, Route103_EventScript_StartFlorian_Paldea
    end

Route103_EventScript_RivalJuliana::
    msgbox Route103_Text_MayRoute103Pokemon, MSGBOX_DEFAULT
    closemessage
    playbgm MUS_ENCOUNTER_MAY, TRUE
    applymovement LOCALID_ROUTE103_RIVAL, Common_Movement_FacePlayer
    waitmovement 0
    applymovement LOCALID_ROUTE103_RIVAL, Common_Movement_ExclamationMark
    waitmovement 0
    applymovement LOCALID_ROUTE103_RIVAL, Common_Movement_Delay48
    waitmovement 0
    msgbox Route103_Text_MayLetsBattle, MSGBOX_DEFAULT
    switch VAR_STARTER_REGION
    case STARTER_REGION_KANTO, Route103_EventScript_StartJuliana_Kanto
    case STARTER_REGION_JOHTO, Route103_EventScript_StartJuliana_Johto
    case STARTER_REGION_HOENN, Route103_EventScript_StartJuliana_Hoenn
    case STARTER_REGION_SINNOH, Route103_EventScript_StartJuliana_Sinnoh
    case STARTER_REGION_UNOVA, Route103_EventScript_StartJuliana_Unova
    case STARTER_REGION_KALOS, Route103_EventScript_StartJuliana_Kalos
    case STARTER_REGION_ALOLA, Route103_EventScript_StartJuliana_Alola
    case STARTER_REGION_GALAR, Route103_EventScript_StartJuliana_Galar
    case STARTER_REGION_PALDEA, Route103_EventScript_StartJuliana_Paldea
    end

Route103_EventScript_StartRedBattleBULBASAUR::
	trainerbattle_no_intro TRAINER_RED_ROUTE_103_BULBASAUR, Route103_Text_RedDefeated
	goto Route103_EventScript_AfterRedBattle
	end
Route103_EventScript_StartRedBattleCHARMANDER::
	trainerbattle_no_intro TRAINER_RED_ROUTE_103_CHARMANDER, Route103_Text_RedDefeated
	goto Route103_EventScript_AfterRedBattle
	end
Route103_EventScript_StartRedBattleSQUIRTLE::
	trainerbattle_no_intro TRAINER_RED_ROUTE_103_SQUIRTLE, Route103_Text_RedDefeated
	goto Route103_EventScript_AfterRedBattle
	end

Route103_EventScript_StartLeafBattleBULBASAUR::
	trainerbattle_no_intro TRAINER_LEAF_ROUTE_103_BULBASAUR, Route103_Text_LeafDefeated
	goto Route103_EventScript_AfterLeafBattle
	end
Route103_EventScript_StartLeafBattleCHARMANDER::
	trainerbattle_no_intro TRAINER_LEAF_ROUTE_103_CHARMANDER, Route103_Text_LeafDefeated
	goto Route103_EventScript_AfterLeafBattle
	end
Route103_EventScript_StartLeafBattleSQUIRTLE::
	trainerbattle_no_intro TRAINER_LEAF_ROUTE_103_SQUIRTLE, Route103_Text_LeafDefeated
	goto Route103_EventScript_AfterLeafBattle
	end

Route103_EventScript_StartMayBattleBULBASAUR::
	trainerbattle_no_intro TRAINER_MAY_ROUTE_103_BULBASAUR, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end
Route103_EventScript_StartMayBattleCHARMANDER::
	trainerbattle_no_intro TRAINER_MAY_ROUTE_103_CHARMANDER, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end
Route103_EventScript_StartMayBattleSQUIRTLE::
	trainerbattle_no_intro TRAINER_MAY_ROUTE_103_SQUIRTLE, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartBrendanBattleBULBASAUR::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_103_BULBASAUR, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end
Route103_EventScript_StartBrendanBattleCHARMANDER::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_103_CHARMANDER, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end
Route103_EventScript_StartBrendanBattleSQUIRTLE::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_103_SQUIRTLE, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartRedBattleTREECKO::
	trainerbattle_no_intro TRAINER_RED_ROUTE_103_TREECKO, Route103_Text_RedDefeated
	goto Route103_EventScript_AfterRedBattle
	end

Route103_EventScript_StartRedBattleTORCHIC::
	trainerbattle_no_intro TRAINER_RED_ROUTE_103_TORCHIC, Route103_Text_RedDefeated
	goto Route103_EventScript_AfterRedBattle
	end

Route103_EventScript_StartRedBattleMUDKIP::
	trainerbattle_no_intro TRAINER_RED_ROUTE_103_MUDKIP, Route103_Text_RedDefeated
	goto Route103_EventScript_AfterRedBattle
	end

Route103_EventScript_StartLeafBattleTREECKO::
	trainerbattle_no_intro TRAINER_LEAF_ROUTE_103_TREECKO, Route103_Text_LeafDefeated
	goto Route103_EventScript_AfterLeafBattle
	end

Route103_EventScript_StartLeafBattleTORCHIC::
	trainerbattle_no_intro TRAINER_LEAF_ROUTE_103_TORCHIC, Route103_Text_LeafDefeated
	goto Route103_EventScript_AfterLeafBattle
	end

Route103_EventScript_StartLeafBattleMUDKIP::
	trainerbattle_no_intro TRAINER_LEAF_ROUTE_103_MUDKIP, Route103_Text_LeafDefeated
	goto Route103_EventScript_AfterLeafBattle
	end

Route103_EventScript_StartBrendanBattleCHIKORITA::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_103_CHIKORITA, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartBrendanBattleCYNDAQUIL::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_103_CYNDAQUIL, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartBrendanBattleTOTODILE::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_103_TOTODILE, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartBrendanBattleTURTWIG::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_103_TURTWIG, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartBrendanBattleCHIMCHAR::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_103_CHIMCHAR, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartBrendanBattlePIPLUP::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_103_PIPLUP, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartBrendanBattleSNIVY::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_103_SNIVY, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartBrendanBattleTEPIG::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_103_TEPIG, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartBrendanBattleOSHAWOTT::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_103_OSHAWOTT, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartBrendanBattleCHESPIN::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_103_CHESPIN, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartBrendanBattleFENNEKIN::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_103_FENNEKIN, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartBrendanBattleFROAKIE::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_103_FROAKIE, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartBrendanBattleROWLET::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_103_ROWLET, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartBrendanBattleLITTEN::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_103_LITTEN, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartBrendanBattlePOPPLIO::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_103_POPPLIO, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartBrendanBattleGROOKEY::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_103_GROOKEY, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartBrendanBattleSCORBUNNY::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_103_SCORBUNNY, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartBrendanBattleSOBBLE::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_103_SOBBLE, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartBrendanBattleSPRIGATITO::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_103_SPRIGATITO, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartBrendanBattleFUECOCO::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_103_FUECOCO, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartBrendanBattleQUAXLY::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_103_QUAXLY, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartMayBattleCHIKORITA::
	trainerbattle_no_intro TRAINER_MAY_ROUTE_103_CHIKORITA, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartMayBattleCYNDAQUIL::
	trainerbattle_no_intro TRAINER_MAY_ROUTE_103_CYNDAQUIL, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartMayBattleTOTODILE::
	trainerbattle_no_intro TRAINER_MAY_ROUTE_103_TOTODILE, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartMayBattleTURTWIG::
	trainerbattle_no_intro TRAINER_MAY_ROUTE_103_TURTWIG, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartMayBattleCHIMCHAR::
	trainerbattle_no_intro TRAINER_MAY_ROUTE_103_CHIMCHAR, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartMayBattlePIPLUP::
	trainerbattle_no_intro TRAINER_MAY_ROUTE_103_PIPLUP, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartMayBattleSNIVY::
	trainerbattle_no_intro TRAINER_MAY_ROUTE_103_SNIVY, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartMayBattleTEPIG::
	trainerbattle_no_intro TRAINER_MAY_ROUTE_103_TEPIG, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartMayBattleOSHAWOTT::
	trainerbattle_no_intro TRAINER_MAY_ROUTE_103_OSHAWOTT, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartMayBattleCHESPIN::
	trainerbattle_no_intro TRAINER_MAY_ROUTE_103_CHESPIN, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartMayBattleFENNEKIN::
	trainerbattle_no_intro TRAINER_MAY_ROUTE_103_FENNEKIN, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartMayBattleFROAKIE::
	trainerbattle_no_intro TRAINER_MAY_ROUTE_103_FROAKIE, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartMayBattleROWLET::
	trainerbattle_no_intro TRAINER_MAY_ROUTE_103_ROWLET, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartMayBattleLITTEN::
	trainerbattle_no_intro TRAINER_MAY_ROUTE_103_LITTEN, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartMayBattlePOPPLIO::
	trainerbattle_no_intro TRAINER_MAY_ROUTE_103_POPPLIO, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartMayBattleGROOKEY::
	trainerbattle_no_intro TRAINER_MAY_ROUTE_103_GROOKEY, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartMayBattleSCORBUNNY::
	trainerbattle_no_intro TRAINER_MAY_ROUTE_103_SCORBUNNY, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartMayBattleSOBBLE::
	trainerbattle_no_intro TRAINER_MAY_ROUTE_103_SOBBLE, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartMayBattleSPRIGATITO::
	trainerbattle_no_intro TRAINER_MAY_ROUTE_103_SPRIGATITO, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartMayBattleFUECOCO::
	trainerbattle_no_intro TRAINER_MAY_ROUTE_103_FUECOCO, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartMayBattleQUAXLY::
	trainerbattle_no_intro TRAINER_MAY_ROUTE_103_QUAXLY, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartRedBattleCHIKORITA::
	trainerbattle_no_intro TRAINER_RED_ROUTE_103_CHIKORITA, Route103_Text_RedDefeated
	goto Route103_EventScript_AfterRedBattle
	end

Route103_EventScript_StartRedBattleCYNDAQUIL::
	trainerbattle_no_intro TRAINER_RED_ROUTE_103_CYNDAQUIL, Route103_Text_RedDefeated
	goto Route103_EventScript_AfterRedBattle
	end

Route103_EventScript_StartRedBattleTOTODILE::
	trainerbattle_no_intro TRAINER_RED_ROUTE_103_TOTODILE, Route103_Text_RedDefeated
	goto Route103_EventScript_AfterRedBattle
	end

Route103_EventScript_StartRedBattleTURTWIG::
	trainerbattle_no_intro TRAINER_RED_ROUTE_103_TURTWIG, Route103_Text_RedDefeated
	goto Route103_EventScript_AfterRedBattle
	end

Route103_EventScript_StartRedBattleCHIMCHAR::
	trainerbattle_no_intro TRAINER_RED_ROUTE_103_CHIMCHAR, Route103_Text_RedDefeated
	goto Route103_EventScript_AfterRedBattle
	end

Route103_EventScript_StartRedBattlePIPLUP::
	trainerbattle_no_intro TRAINER_RED_ROUTE_103_PIPLUP, Route103_Text_RedDefeated
	goto Route103_EventScript_AfterRedBattle
	end

Route103_EventScript_StartRedBattleSNIVY::
	trainerbattle_no_intro TRAINER_RED_ROUTE_103_SNIVY, Route103_Text_RedDefeated
	goto Route103_EventScript_AfterRedBattle
	end

Route103_EventScript_StartRedBattleTEPIG::
	trainerbattle_no_intro TRAINER_RED_ROUTE_103_TEPIG, Route103_Text_RedDefeated
	goto Route103_EventScript_AfterRedBattle
	end

Route103_EventScript_StartRedBattleOSHAWOTT::
	trainerbattle_no_intro TRAINER_RED_ROUTE_103_OSHAWOTT, Route103_Text_RedDefeated
	goto Route103_EventScript_AfterRedBattle
	end

Route103_EventScript_StartRedBattleCHESPIN::
	trainerbattle_no_intro TRAINER_RED_ROUTE_103_CHESPIN, Route103_Text_RedDefeated
	goto Route103_EventScript_AfterRedBattle
	end

Route103_EventScript_StartRedBattleFENNEKIN::
	trainerbattle_no_intro TRAINER_RED_ROUTE_103_FENNEKIN, Route103_Text_RedDefeated
	goto Route103_EventScript_AfterRedBattle
	end

Route103_EventScript_StartRedBattleFROAKIE::
	trainerbattle_no_intro TRAINER_RED_ROUTE_103_FROAKIE, Route103_Text_RedDefeated
	goto Route103_EventScript_AfterRedBattle
	end

Route103_EventScript_StartRedBattleROWLET::
	trainerbattle_no_intro TRAINER_RED_ROUTE_103_ROWLET, Route103_Text_RedDefeated
	goto Route103_EventScript_AfterRedBattle
	end

Route103_EventScript_StartRedBattleLITTEN::
	trainerbattle_no_intro TRAINER_RED_ROUTE_103_LITTEN, Route103_Text_RedDefeated
	goto Route103_EventScript_AfterRedBattle
	end

Route103_EventScript_StartRedBattlePOPPLIO::
	trainerbattle_no_intro TRAINER_RED_ROUTE_103_POPPLIO, Route103_Text_RedDefeated
	goto Route103_EventScript_AfterRedBattle
	end

Route103_EventScript_StartRedBattleGROOKEY::
	trainerbattle_no_intro TRAINER_RED_ROUTE_103_GROOKEY, Route103_Text_RedDefeated
	goto Route103_EventScript_AfterRedBattle
	end

Route103_EventScript_StartRedBattleSCORBUNNY::
	trainerbattle_no_intro TRAINER_RED_ROUTE_103_SCORBUNNY, Route103_Text_RedDefeated
	goto Route103_EventScript_AfterRedBattle
	end

Route103_EventScript_StartRedBattleSOBBLE::
	trainerbattle_no_intro TRAINER_RED_ROUTE_103_SOBBLE, Route103_Text_RedDefeated
	goto Route103_EventScript_AfterRedBattle
	end

Route103_EventScript_StartRedBattleSPRIGATITO::
	trainerbattle_no_intro TRAINER_RED_ROUTE_103_SPRIGATITO, Route103_Text_RedDefeated
	goto Route103_EventScript_AfterRedBattle
	end

Route103_EventScript_StartRedBattleFUECOCO::
	trainerbattle_no_intro TRAINER_RED_ROUTE_103_FUECOCO, Route103_Text_RedDefeated
	goto Route103_EventScript_AfterRedBattle
	end

Route103_EventScript_StartRedBattleQUAXLY::
	trainerbattle_no_intro TRAINER_RED_ROUTE_103_QUAXLY, Route103_Text_RedDefeated
	goto Route103_EventScript_AfterRedBattle
	end

Route103_EventScript_StartLeafBattleCHIKORITA::
	trainerbattle_no_intro TRAINER_LEAF_ROUTE_103_CHIKORITA, Route103_Text_LeafDefeated
	goto Route103_EventScript_AfterLeafBattle
	end

Route103_EventScript_StartLeafBattleCYNDAQUIL::
	trainerbattle_no_intro TRAINER_LEAF_ROUTE_103_CYNDAQUIL, Route103_Text_LeafDefeated
	goto Route103_EventScript_AfterLeafBattle
	end

Route103_EventScript_StartLeafBattleTOTODILE::
	trainerbattle_no_intro TRAINER_LEAF_ROUTE_103_TOTODILE, Route103_Text_LeafDefeated
	goto Route103_EventScript_AfterLeafBattle
	end

Route103_EventScript_StartLeafBattleTURTWIG::
	trainerbattle_no_intro TRAINER_LEAF_ROUTE_103_TURTWIG, Route103_Text_LeafDefeated
	goto Route103_EventScript_AfterLeafBattle
	end

Route103_EventScript_StartLeafBattleCHIMCHAR::
	trainerbattle_no_intro TRAINER_LEAF_ROUTE_103_CHIMCHAR, Route103_Text_LeafDefeated
	goto Route103_EventScript_AfterLeafBattle
	end

Route103_EventScript_StartLeafBattlePIPLUP::
	trainerbattle_no_intro TRAINER_LEAF_ROUTE_103_PIPLUP, Route103_Text_LeafDefeated
	goto Route103_EventScript_AfterLeafBattle
	end

Route103_EventScript_StartLeafBattleSNIVY::
	trainerbattle_no_intro TRAINER_LEAF_ROUTE_103_SNIVY, Route103_Text_LeafDefeated
	goto Route103_EventScript_AfterLeafBattle
	end

Route103_EventScript_StartLeafBattleTEPIG::
	trainerbattle_no_intro TRAINER_LEAF_ROUTE_103_TEPIG, Route103_Text_LeafDefeated
	goto Route103_EventScript_AfterLeafBattle
	end

Route103_EventScript_StartLeafBattleOSHAWOTT::
	trainerbattle_no_intro TRAINER_LEAF_ROUTE_103_OSHAWOTT, Route103_Text_LeafDefeated
	goto Route103_EventScript_AfterLeafBattle
	end

Route103_EventScript_StartLeafBattleCHESPIN::
	trainerbattle_no_intro TRAINER_LEAF_ROUTE_103_CHESPIN, Route103_Text_LeafDefeated
	goto Route103_EventScript_AfterLeafBattle
	end

Route103_EventScript_StartLeafBattleFENNEKIN::
	trainerbattle_no_intro TRAINER_LEAF_ROUTE_103_FENNEKIN, Route103_Text_LeafDefeated
	goto Route103_EventScript_AfterLeafBattle
	end

Route103_EventScript_StartLeafBattleFROAKIE::
	trainerbattle_no_intro TRAINER_LEAF_ROUTE_103_FROAKIE, Route103_Text_LeafDefeated
	goto Route103_EventScript_AfterLeafBattle
	end

Route103_EventScript_StartLeafBattleROWLET::
	trainerbattle_no_intro TRAINER_LEAF_ROUTE_103_ROWLET, Route103_Text_LeafDefeated
	goto Route103_EventScript_AfterLeafBattle
	end

Route103_EventScript_StartLeafBattleLITTEN::
	trainerbattle_no_intro TRAINER_LEAF_ROUTE_103_LITTEN, Route103_Text_LeafDefeated
	goto Route103_EventScript_AfterLeafBattle
	end

Route103_EventScript_StartLeafBattlePOPPLIO::
	trainerbattle_no_intro TRAINER_LEAF_ROUTE_103_POPPLIO, Route103_Text_LeafDefeated
	goto Route103_EventScript_AfterLeafBattle
	end

Route103_EventScript_StartLeafBattleGROOKEY::
	trainerbattle_no_intro TRAINER_LEAF_ROUTE_103_GROOKEY, Route103_Text_LeafDefeated
	goto Route103_EventScript_AfterLeafBattle
	end

Route103_EventScript_StartLeafBattleSCORBUNNY::
	trainerbattle_no_intro TRAINER_LEAF_ROUTE_103_SCORBUNNY, Route103_Text_LeafDefeated
	goto Route103_EventScript_AfterLeafBattle
	end

Route103_EventScript_StartLeafBattleSOBBLE::
	trainerbattle_no_intro TRAINER_LEAF_ROUTE_103_SOBBLE, Route103_Text_LeafDefeated
	goto Route103_EventScript_AfterLeafBattle
	end

Route103_EventScript_StartLeafBattleSPRIGATITO::
	trainerbattle_no_intro TRAINER_LEAF_ROUTE_103_SPRIGATITO, Route103_Text_LeafDefeated
	goto Route103_EventScript_AfterLeafBattle
	end

Route103_EventScript_StartLeafBattleFUECOCO::
	trainerbattle_no_intro TRAINER_LEAF_ROUTE_103_FUECOCO, Route103_Text_LeafDefeated
	goto Route103_EventScript_AfterLeafBattle
	end

Route103_EventScript_StartLeafBattleQUAXLY::
	trainerbattle_no_intro TRAINER_LEAF_ROUTE_103_QUAXLY, Route103_Text_LeafDefeated
	goto Route103_EventScript_AfterLeafBattle
	end

Route103_EventScript_StartBrendanBattleTREECKO::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_103_TREECKO, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartBrendanBattleTORCHIC::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_103_TORCHIC, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartBrendanBattleMUDKIP::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_103_MUDKIP, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartMayBattleTREECKO::
	trainerbattle_no_intro TRAINER_MAY_ROUTE_103_TREECKO, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartMayBattleTORCHIC::
	trainerbattle_no_intro TRAINER_MAY_ROUTE_103_TORCHIC, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartMayBattleMUDKIP::
	trainerbattle_no_intro TRAINER_MAY_ROUTE_103_MUDKIP, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_AfterMayBattle::
	msgbox Route103_Text_MayTimeToHeadBack, MSGBOX_DEFAULT
	goto Route103_EventScript_RivalExit
	end

Route103_EventScript_AfterBrendanBattle::
	msgbox Route103_Text_BrendanTimeToHeadBack, MSGBOX_DEFAULT
	goto Route103_EventScript_RivalExit
	end

Route103_EventScript_AfterRedBattle::
	msgbox Route103_Text_RedTimeToHeadBack, MSGBOX_DEFAULT
	goto Route103_EventScript_RivalExit
	end

Route103_EventScript_AfterLeafBattle::
	msgbox Route103_Text_LeafTimeToHeadBack, MSGBOX_DEFAULT
	goto Route103_EventScript_RivalExit
	end

Route103_EventScript_RivalExit::
	closemessage
	switch VAR_FACING
	case DIR_SOUTH, Route103_EventScript_RivalExitFacingSouth
	case DIR_NORTH, Route103_EventScript_RivalExitFacingNorth
	case DIR_WEST, Route103_EventScript_RivalExitFacingEastOrWest
	case DIR_EAST, Route103_EventScript_RivalExitFacingEastOrWest
	end

Route103_EventScript_RivalExitFacingNorth::
	applymovement LOCALID_PLAYER, Route103_Movement_WatchRivalExitFacingNorth
	applymovement LOCALID_ROUTE103_RIVAL, Route103_Movement_RivalExitFacingNorth1
	waitmovement 0
	playse SE_LEDGE
	applymovement LOCALID_ROUTE103_RIVAL, Route103_Movement_RivalExitFacingNorth2
	waitmovement 0
	goto Route103_EventScript_RivalEnd
	end

Route103_EventScript_RivalExitFacingEastOrWest::
	applymovement LOCALID_PLAYER, Route103_Movement_WatchRivalExitFacingEastOrWest
	applymovement LOCALID_ROUTE103_RIVAL, Route103_Movement_RivalExit1
	waitmovement 0
	playse SE_LEDGE
	applymovement LOCALID_ROUTE103_RIVAL, Route103_Movement_RivalExit2
	waitmovement 0
	goto Route103_EventScript_RivalEnd
	end

Route103_EventScript_RivalExitFacingSouth::
	applymovement LOCALID_ROUTE103_RIVAL, Route103_Movement_RivalExit1
	waitmovement 0
	playse SE_LEDGE
	applymovement LOCALID_ROUTE103_RIVAL, Route103_Movement_RivalExit2
	waitmovement 0
	goto Route103_EventScript_RivalEnd
	end

Route103_EventScript_RivalEnd::
	removeobject LOCALID_ROUTE103_RIVAL
	setvar VAR_BIRCH_LAB_STATE, 4
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_RIVAL
	setflag FLAG_DEFEATED_RIVAL_ROUTE103
	setvar VAR_OLDALE_RIVAL_STATE, 1
	clearflag FLAG_HIDE_OLDALE_TOWN_RIVAL
	savebgm MUS_DUMMY
	fadedefaultbgm
	releaseall
	end

Route103_Movement_RivalExitFacingNorth1:
	walk_left
	walk_down
	step_end

Route103_Movement_RivalExitFacingNorth2:
	jump_2_down
	delay_16
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

Route103_Movement_WatchRivalExitFacingNorth:
	delay_16
	delay_4
	walk_in_place_faster_left
	delay_16
	walk_in_place_faster_down
	step_end

Route103_Movement_RivalExit1:
	walk_down
	step_end

Route103_Movement_RivalExit2:
	jump_2_down
	delay_16
	walk_down
	walk_down
	walk_down
	step_end

Route103_Movement_WatchRivalExitFacingEastOrWest:
	delay_16
	walk_in_place_faster_down
	step_end

Route103_EventScript_Boy::
	msgbox Route103_Text_ShouldHaveBroughtPotion, MSGBOX_NPC
	end

Route103_EventScript_Man::
	msgbox Route103_Text_ShortcutToOldale, MSGBOX_NPC
	end

Route103_EventScript_RouteSign::
	msgbox Route103_Text_RouteSign, MSGBOX_SIGN
	end

Route103_EventScript_Daisy::
	trainerbattle_single TRAINER_DAISY, Route103_Text_DaisyIntro, Route103_Text_DaisyDefeated
	msgbox Route103_Text_DaisyPostBattle, MSGBOX_AUTOCLOSE
	end

Route103_EventScript_Amy::
	trainerbattle_double TRAINER_AMY_AND_LIV_1, Route103_Text_AmyIntro, Route103_Text_AmyDefeated, Route103_Text_AmyNotEnoughPokemon, Route102_EventScript_AmyRegisterMatchCallAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route102_EventScript_AmyRematch
	msgbox Route103_Text_AmyPostBattle, MSGBOX_AUTOCLOSE
	end

Route102_EventScript_AmyRegisterMatchCallAfterBattle::
	msgbox Route103_Text_AmyLivRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_AMY_AND_LIV_1
	release
	end

Route102_EventScript_AmyRematch::
	trainerbattle_rematch_double TRAINER_AMY_AND_LIV_1, Route103_Text_AmyRematchIntro, Route103_Text_AmyRematchDefeated, Route103_Text_AmyRematchNotEnoughPokemon
	msgbox Route103_Text_AmyRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route103_EventScript_Liv::
	trainerbattle_double TRAINER_AMY_AND_LIV_1, Route103_Text_LivIntro, Route103_Text_LivDefeated, Route103_Text_LivNotEnoughPokemon, Route102_EventScript_LivRegisterMatchCallAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route102_EventScript_LivRematch
	msgbox Route103_Text_LivPostBattle, MSGBOX_AUTOCLOSE
	end

Route102_EventScript_LivRegisterMatchCallAfterBattle::
	msgbox Route103_Text_AmyLivRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_AMY_AND_LIV_1
	release
	end

Route102_EventScript_LivRematch::
	trainerbattle_rematch_double TRAINER_AMY_AND_LIV_1, Route103_Text_LivRematchIntro, Route103_Text_LivRematchDefeated, Route103_Text_LivRematchNotEnoughPokemon
	msgbox Route103_Text_LivRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route103_EventScript_Andrew::
	trainerbattle_single TRAINER_ANDREW, Route103_Text_AndrewIntro, Route103_Text_AndrewDefeated
	msgbox Route103_Text_AndrewPostBattle, MSGBOX_AUTOCLOSE
	end

Route103_EventScript_Miguel::
	trainerbattle_single TRAINER_MIGUEL_1, Route103_Text_MiguelIntro, Route103_Text_MiguelDefeated, Route102_EventScript_MiguelRegisterMatchCallAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route103_EventScript_MiguelRematch
	msgbox Route103_Text_MiguelPostBattle, MSGBOX_DEFAULT
	release
	end

Route102_EventScript_MiguelRegisterMatchCallAfterBattle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route103_Text_MiguelRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_MIGUEL_1
	release
	end

Route103_EventScript_MiguelRematch::
	trainerbattle_rematch TRAINER_MIGUEL_1, Route103_Text_MiguelRematchIntro, Route103_Text_MiguelRematchDefeated
	msgbox Route103_Text_MiguelRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route103_EventScript_Marcos::
	trainerbattle_single TRAINER_MARCOS, Route103_Text_MarcosIntro, Route103_Text_MarcosDefeated
	msgbox Route103_Text_MarcosPostBattle, MSGBOX_AUTOCLOSE
	end

Route103_EventScript_Rhett::
	trainerbattle_single TRAINER_RHETT, Route103_Text_RhettIntro, Route103_Text_RhettDefeated
	msgbox Route103_Text_RhettPostBattle, MSGBOX_AUTOCLOSE
	end

Route103_EventScript_Pete::
	trainerbattle_single TRAINER_PETE, Route103_Text_PeteIntro, Route103_Text_PeteDefeated
	msgbox Route103_Text_PetePostBattle, MSGBOX_AUTOCLOSE
	end

Route103_EventScript_Isabelle::
	trainerbattle_single TRAINER_ISABELLE, Route103_Text_IsabelleIntro, Route103_Text_IsabelleDefeated
	msgbox Route103_Text_IsabellePostBattle, MSGBOX_AUTOCLOSE
	end

Route103_EventScript_StartBrendan_Kanto::
    switch VAR_STARTER_MON
    case 0, Route103_EventScript_StartBrendanBattleCHARMANDER
    case 1, Route103_EventScript_StartBrendanBattleSQUIRTLE
    case 2, Route103_EventScript_StartBrendanBattleBULBASAUR
    end

Route103_EventScript_StartBrendan_Johto::
	switch VAR_STARTER_MON
	case 0, Route103_EventScript_StartBrendanBattleCHIKORITA
	case 1, Route103_EventScript_StartBrendanBattleCYNDAQUIL
	case 2, Route103_EventScript_StartBrendanBattleTOTODILE
	end

Route103_EventScript_StartBrendan_Hoenn::
	switch VAR_STARTER_MON
	case 0, Route103_EventScript_StartBrendanBattleTREECKO
	case 1, Route103_EventScript_StartBrendanBattleTORCHIC
	case 2, Route103_EventScript_StartBrendanBattleMUDKIP
	end

Route103_EventScript_StartBrendan_Sinnoh::
	switch VAR_STARTER_MON
	case 0, Route103_EventScript_StartBrendanBattleTURTWIG
	case 1, Route103_EventScript_StartBrendanBattleCHIMCHAR
	case 2, Route103_EventScript_StartBrendanBattlePIPLUP
	end

Route103_EventScript_StartBrendan_Unova::
	switch VAR_STARTER_MON
	case 0, Route103_EventScript_StartBrendanBattleSNIVY
	case 1, Route103_EventScript_StartBrendanBattleTEPIG
	case 2, Route103_EventScript_StartBrendanBattleOSHAWOTT
	end

Route103_EventScript_StartBrendan_Kalos::
	switch VAR_STARTER_MON
	case 0, Route103_EventScript_StartBrendanBattleCHESPIN
	case 1, Route103_EventScript_StartBrendanBattleFENNEKIN
	case 2, Route103_EventScript_StartBrendanBattleFROAKIE
	end

Route103_EventScript_StartBrendan_Alola::
	switch VAR_STARTER_MON
	case 0, Route103_EventScript_StartBrendanBattleROWLET
	case 1, Route103_EventScript_StartBrendanBattleLITTEN
	case 2, Route103_EventScript_StartBrendanBattlePOPPLIO
	end

Route103_EventScript_StartBrendan_Galar::
	switch VAR_STARTER_MON
	case 0, Route103_EventScript_StartBrendanBattleGROOKEY
	case 1, Route103_EventScript_StartBrendanBattleSCORBUNNY
	case 2, Route103_EventScript_StartBrendanBattleSOBBLE
	end

Route103_EventScript_StartBrendan_Paldea::
	switch VAR_STARTER_MON
	case 0, Route103_EventScript_StartBrendanBattleSPRIGATITO
	case 1, Route103_EventScript_StartBrendanBattleFUECOCO
	case 2, Route103_EventScript_StartBrendanBattleQUAXLY
	end

@ --- Analog für May ---

Route103_EventScript_StartMay_Kanto::
    switch VAR_STARTER_MON
    case 0, Route103_EventScript_StartMayBattleBULBASAUR
    case 1, Route103_EventScript_StartMayBattleCHARMANDER
    case 2, Route103_EventScript_StartMayBattleSQUIRTLE
    end

Route103_EventScript_StartMay_Johto::
	switch VAR_STARTER_MON
	case 0, Route103_EventScript_StartMayBattleCHIKORITA
	case 1, Route103_EventScript_StartMayBattleCYNDAQUIL
	case 2, Route103_EventScript_StartMayBattleTOTODILE
	end

Route103_EventScript_StartMay_Hoenn::
	switch VAR_STARTER_MON
	case 0, Route103_EventScript_StartMayBattleTREECKO
	case 1, Route103_EventScript_StartMayBattleTORCHIC
	case 2, Route103_EventScript_StartMayBattleMUDKIP
	end

Route103_EventScript_StartMay_Sinnoh::
	switch VAR_STARTER_MON
	case 0, Route103_EventScript_StartMayBattleTURTWIG
	case 1, Route103_EventScript_StartMayBattleCHIMCHAR
	case 2, Route103_EventScript_StartMayBattlePIPLUP
	end

Route103_EventScript_StartMay_Unova::
	switch VAR_STARTER_MON
	case 0, Route103_EventScript_StartMayBattleSNIVY
	case 1, Route103_EventScript_StartMayBattleTEPIG
	case 2, Route103_EventScript_StartMayBattleOSHAWOTT
	end

Route103_EventScript_StartMay_Kalos::
	switch VAR_STARTER_MON
	case 0, Route103_EventScript_StartMayBattleCHESPIN
	case 1, Route103_EventScript_StartMayBattleFENNEKIN
	case 2, Route103_EventScript_StartMayBattleFROAKIE
	end

Route103_EventScript_StartMay_Alola::
	switch VAR_STARTER_MON
	case 0, Route103_EventScript_StartMayBattleROWLET
	case 1, Route103_EventScript_StartMayBattleLITTEN
	case 2, Route103_EventScript_StartMayBattlePOPPLIO
	end

Route103_EventScript_StartMay_Galar::
	switch VAR_STARTER_MON
	case 0, Route103_EventScript_StartMayBattleGROOKEY
	case 1, Route103_EventScript_StartMayBattleSCORBUNNY
	case 2, Route103_EventScript_StartMayBattleSOBBLE
	end

Route103_EventScript_StartMay_Paldea::
	switch VAR_STARTER_MON
	case 0, Route103_EventScript_StartMayBattleSPRIGATITO
	case 1, Route103_EventScript_StartMayBattleFUECOCO
	case 2, Route103_EventScript_StartMayBattleQUAXLY
	end

Route103_EventScript_StartRed_Kanto::
    switch VAR_STARTER_MON
    case 0, Route103_EventScript_StartRedBattleCHARMANDER
    case 1, Route103_EventScript_StartRedBattleSQUIRTLE
    case 2, Route103_EventScript_StartRedBattleBULBASAUR
    end

Route103_EventScript_StartRed_Johto::
	switch VAR_STARTER_MON
	case 0, Route103_EventScript_StartRedBattleCHIKORITA
	case 1, Route103_EventScript_StartRedBattleCYNDAQUIL
	case 2, Route103_EventScript_StartRedBattleTOTODILE
	end

Route103_EventScript_StartRed_Hoenn::
	switch VAR_STARTER_MON
	case 0, Route103_EventScript_StartRedBattleTREECKO
	case 1, Route103_EventScript_StartRedBattleTORCHIC
	case 2, Route103_EventScript_StartRedBattleMUDKIP
	end

Route103_EventScript_StartRed_Sinnoh::
	switch VAR_STARTER_MON
	case 0, Route103_EventScript_StartRedBattleTURTWIG
	case 1, Route103_EventScript_StartRedBattleCHIMCHAR
	case 2, Route103_EventScript_StartRedBattlePIPLUP
	end

Route103_EventScript_StartRed_Unova::
	switch VAR_STARTER_MON
	case 0, Route103_EventScript_StartRedBattleSNIVY
	case 1, Route103_EventScript_StartRedBattleTEPIG
	case 2, Route103_EventScript_StartRedBattleOSHAWOTT
	end

Route103_EventScript_StartRed_Kalos::
	switch VAR_STARTER_MON
	case 0, Route103_EventScript_StartRedBattleCHESPIN
	case 1, Route103_EventScript_StartRedBattleFENNEKIN
	case 2, Route103_EventScript_StartRedBattleFROAKIE
	end

Route103_EventScript_StartRed_Alola::
	switch VAR_STARTER_MON
	case 0, Route103_EventScript_StartRedBattleROWLET
	case 1, Route103_EventScript_StartRedBattleLITTEN
	case 2, Route103_EventScript_StartRedBattlePOPPLIO
	end

Route103_EventScript_StartRed_Galar::
	switch VAR_STARTER_MON
	case 0, Route103_EventScript_StartRedBattleGROOKEY
	case 1, Route103_EventScript_StartRedBattleSCORBUNNY
	case 2, Route103_EventScript_StartRedBattleSOBBLE
	end

Route103_EventScript_StartRed_Paldea::
	switch VAR_STARTER_MON
	case 0, Route103_EventScript_StartRedBattleSPRIGATITO
	case 1, Route103_EventScript_StartRedBattleFUECOCO
	case 2, Route103_EventScript_StartRedBattleQUAXLY
	end

Route103_EventScript_StartLeaf_Kanto::
	switch VAR_STARTER_MON
	case 0, Route103_EventScript_StartLeafBattleSQUIRTLE
	case 1, Route103_EventScript_StartLeafBattleBULBASAUR
	case 2, Route103_EventScript_StartLeafBattleCHARMANDER
	end

Route103_EventScript_StartLeaf_Johto::
	switch VAR_STARTER_MON
	case 0, Route103_EventScript_StartLeafBattleCHIKORITA
	case 1, Route103_EventScript_StartLeafBattleCYNDAQUIL
	case 2, Route103_EventScript_StartLeafBattleTOTODILE
	end

Route103_EventScript_StartLeaf_Hoenn::
	switch VAR_STARTER_MON
	case 0, Route103_EventScript_StartLeafBattleTREECKO
	case 1, Route103_EventScript_StartLeafBattleTORCHIC
	case 2, Route103_EventScript_StartLeafBattleMUDKIP
	end

Route103_EventScript_StartLeaf_Sinnoh::
	switch VAR_STARTER_MON
	case 0, Route103_EventScript_StartLeafBattleTURTWIG
	case 1, Route103_EventScript_StartLeafBattleCHIMCHAR
	case 2, Route103_EventScript_StartLeafBattlePIPLUP
	end

Route103_EventScript_StartLeaf_Unova::
	switch VAR_STARTER_MON
	case 0, Route103_EventScript_StartLeafBattleSNIVY
	case 1, Route103_EventScript_StartLeafBattleTEPIG
	case 2, Route103_EventScript_StartLeafBattleOSHAWOTT
	end

Route103_EventScript_StartLeaf_Kalos::
	switch VAR_STARTER_MON
	case 0, Route103_EventScript_StartLeafBattleCHESPIN
	case 1, Route103_EventScript_StartLeafBattleFENNEKIN
	case 2, Route103_EventScript_StartLeafBattleFROAKIE
	end

Route103_EventScript_StartLeaf_Alola::
	switch VAR_STARTER_MON
	case 0, Route103_EventScript_StartLeafBattleROWLET
	case 1, Route103_EventScript_StartLeafBattleLITTEN
	case 2, Route103_EventScript_StartLeafBattlePOPPLIO
	end

Route103_EventScript_StartLeaf_Galar::
	switch VAR_STARTER_MON
	case 0, Route103_EventScript_StartLeafBattleGROOKEY
	case 1, Route103_EventScript_StartLeafBattleSCORBUNNY
	case 2, Route103_EventScript_StartLeafBattleSOBBLE
	end

Route103_EventScript_StartLeaf_Paldea::
	switch VAR_STARTER_MON
	case 0, Route103_EventScript_StartLeafBattleSPRIGATITO
	case 1, Route103_EventScript_StartLeafBattleFUECOCO
	case 2, Route103_EventScript_StartLeafBattleQUAXLY
	end

Route103_EventScript_StartEthan_Kanto::
	switch VAR_STARTER_MON
	case 0, Route103_EventScript_StartEthanBattleBULBASAUR
	case 1, Route103_EventScript_StartEthanBattleCHARMANDER
	case 2, Route103_EventScript_StartEthanBattleSQUIRTLE
	end

Route103_EventScript_StartEthanBattleBULBASAUR::
	trainerbattle_no_intro TRAINER_ETHAN_ROUTE_103_BULBASAUR, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartEthanBattleCHARMANDER::
	trainerbattle_no_intro TRAINER_ETHAN_ROUTE_103_CHARMANDER, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartEthanBattleSQUIRTLE::
	trainerbattle_no_intro TRAINER_ETHAN_ROUTE_103_SQUIRTLE, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartEthan_Johto::
	switch VAR_STARTER_MON
	case 0, Route103_EventScript_StartEthanBattleCHIKORITA
	case 1, Route103_EventScript_StartEthanBattleCYNDAQUIL
	case 2, Route103_EventScript_StartEthanBattleTOTODILE
	end

Route103_EventScript_StartEthanBattleCHIKORITA::
	trainerbattle_no_intro TRAINER_ETHAN_ROUTE_103_CHIKORITA, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartEthanBattleCYNDAQUIL::
	trainerbattle_no_intro TRAINER_ETHAN_ROUTE_103_CYNDAQUIL, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartEthanBattleTOTODILE::
	trainerbattle_no_intro TRAINER_ETHAN_ROUTE_103_TOTODILE, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartEthan_Hoenn::
	switch VAR_STARTER_MON
	case 0, Route103_EventScript_StartEthanBattleTREECKO
	case 1, Route103_EventScript_StartEthanBattleTORCHIC
	case 2, Route103_EventScript_StartEthanBattleMUDKIP
	end

Route103_EventScript_StartEthanBattleTREECKO::
	trainerbattle_no_intro TRAINER_ETHAN_ROUTE_103_TREECKO, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartEthanBattleTORCHIC::
	trainerbattle_no_intro TRAINER_ETHAN_ROUTE_103_TORCHIC, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartEthanBattleMUDKIP::
	trainerbattle_no_intro TRAINER_ETHAN_ROUTE_103_MUDKIP, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartEthan_Sinnoh::
	switch VAR_STARTER_MON
	case 0, Route103_EventScript_StartEthanBattleTURTWIG
	case 1, Route103_EventScript_StartEthanBattleCHIMCHAR
	case 2, Route103_EventScript_StartEthanBattlePIPLUP
	end

Route103_EventScript_StartEthanBattleTURTWIG::
	trainerbattle_no_intro TRAINER_ETHAN_ROUTE_103_TURTWIG, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartEthanBattleCHIMCHAR::
	trainerbattle_no_intro TRAINER_ETHAN_ROUTE_103_CHIMCHAR, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartEthanBattlePIPLUP::
	trainerbattle_no_intro TRAINER_ETHAN_ROUTE_103_PIPLUP, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartEthan_Unova::
	switch VAR_STARTER_MON
	case 0, Route103_EventScript_StartEthanBattleSNIVY
	case 1, Route103_EventScript_StartEthanBattleTEPIG
	case 2, Route103_EventScript_StartEthanBattleOSHAWOTT
	end

Route103_EventScript_StartEthanBattleSNIVY::
	trainerbattle_no_intro TRAINER_ETHAN_ROUTE_103_SNIVY, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartEthanBattleTEPIG::
	trainerbattle_no_intro TRAINER_ETHAN_ROUTE_103_TEPIG, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartEthanBattleOSHAWOTT::
	trainerbattle_no_intro TRAINER_ETHAN_ROUTE_103_OSHAWOTT, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartEthan_Kalos::
	switch VAR_STARTER_MON
	case 0, Route103_EventScript_StartEthanBattleCHESPIN
	case 1, Route103_EventScript_StartEthanBattleFENNEKIN
	case 2, Route103_EventScript_StartEthanBattleFROAKIE
	end

Route103_EventScript_StartEthanBattleCHESPIN::
	trainerbattle_no_intro TRAINER_ETHAN_ROUTE_103_CHESPIN, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartEthanBattleFENNEKIN::
	trainerbattle_no_intro TRAINER_ETHAN_ROUTE_103_FENNEKIN, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartEthanBattleFROAKIE::
	trainerbattle_no_intro TRAINER_ETHAN_ROUTE_103_FROAKIE, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartEthan_Alola::
	switch VAR_STARTER_MON
	case 0, Route103_EventScript_StartEthanBattleROWLET
	case 1, Route103_EventScript_StartEthanBattleLITTEN
	case 2, Route103_EventScript_StartEthanBattlePOPPLIO
	end

Route103_EventScript_StartEthanBattleROWLET::
	trainerbattle_no_intro TRAINER_ETHAN_ROUTE_103_ROWLET, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartEthanBattleLITTEN::
	trainerbattle_no_intro TRAINER_ETHAN_ROUTE_103_LITTEN, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartEthanBattlePOPPLIO::
	trainerbattle_no_intro TRAINER_ETHAN_ROUTE_103_POPPLIO, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartEthan_Galar::
	switch VAR_STARTER_MON
	case 0, Route103_EventScript_StartEthanBattleGROOKEY
	case 1, Route103_EventScript_StartEthanBattleSCORBUNNY
	case 2, Route103_EventScript_StartEthanBattleSOBBLE
	end

Route103_EventScript_StartEthanBattleGROOKEY::
	trainerbattle_no_intro TRAINER_ETHAN_ROUTE_103_GROOKEY, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartEthanBattleSCORBUNNY::
	trainerbattle_no_intro TRAINER_ETHAN_ROUTE_103_SCORBUNNY, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartEthanBattleSOBBLE::
	trainerbattle_no_intro TRAINER_ETHAN_ROUTE_103_SOBBLE, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartEthan_Paldea::
	switch VAR_STARTER_MON
	case 0, Route103_EventScript_StartEthanBattleSPRIGATITO
	case 1, Route103_EventScript_StartEthanBattleFUECOCO
	case 2, Route103_EventScript_StartEthanBattleQUAXLY
	end

Route103_EventScript_StartEthanBattleSPRIGATITO::
	trainerbattle_no_intro TRAINER_ETHAN_ROUTE_103_SPRIGATITO, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartEthanBattleFUECOCO::
	trainerbattle_no_intro TRAINER_ETHAN_ROUTE_103_FUECOCO, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartEthanBattleQUAXLY::
	trainerbattle_no_intro TRAINER_ETHAN_ROUTE_103_QUAXLY, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartLyra_Kanto::
	switch VAR_STARTER_MON
	case 0, Route103_EventScript_StartLyraBattleBULBASAUR
	case 1, Route103_EventScript_StartLyraBattleCHARMANDER
	case 2, Route103_EventScript_StartLyraBattleSQUIRTLE
	end

Route103_EventScript_StartLyraBattleBULBASAUR::
	trainerbattle_no_intro TRAINER_LYRA_ROUTE_103_BULBASAUR, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartLyraBattleCHARMANDER::
	trainerbattle_no_intro TRAINER_LYRA_ROUTE_103_CHARMANDER, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartLyraBattleSQUIRTLE::
	trainerbattle_no_intro TRAINER_LYRA_ROUTE_103_SQUIRTLE, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartLyra_Johto::
	switch VAR_STARTER_MON
	case 0, Route103_EventScript_StartLyraBattleCHIKORITA
	case 1, Route103_EventScript_StartLyraBattleCYNDAQUIL
	case 2, Route103_EventScript_StartLyraBattleTOTODILE
	end

Route103_EventScript_StartLyraBattleCHIKORITA::
	trainerbattle_no_intro TRAINER_LYRA_ROUTE_103_CHIKORITA, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartLyraBattleCYNDAQUIL::
	trainerbattle_no_intro TRAINER_LYRA_ROUTE_103_CYNDAQUIL, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartLyraBattleTOTODILE::
	trainerbattle_no_intro TRAINER_LYRA_ROUTE_103_TOTODILE, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartLyra_Hoenn::
	switch VAR_STARTER_MON
	case 0, Route103_EventScript_StartLyraBattleTREECKO
	case 1, Route103_EventScript_StartLyraBattleTORCHIC
	case 2, Route103_EventScript_StartLyraBattleMUDKIP
	end

Route103_EventScript_StartLyraBattleTREECKO::
	trainerbattle_no_intro TRAINER_LYRA_ROUTE_103_TREECKO, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartLyraBattleTORCHIC::
	trainerbattle_no_intro TRAINER_LYRA_ROUTE_103_TORCHIC, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartLyraBattleMUDKIP::
	trainerbattle_no_intro TRAINER_LYRA_ROUTE_103_MUDKIP, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartLyra_Sinnoh::
	switch VAR_STARTER_MON
	case 0, Route103_EventScript_StartLyraBattleTURTWIG
	case 1, Route103_EventScript_StartLyraBattleCHIMCHAR
	case 2, Route103_EventScript_StartLyraBattlePIPLUP
	end

Route103_EventScript_StartLyraBattleTURTWIG::
	trainerbattle_no_intro TRAINER_LYRA_ROUTE_103_TURTWIG, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartLyraBattleCHIMCHAR::
	trainerbattle_no_intro TRAINER_LYRA_ROUTE_103_CHIMCHAR, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartLyraBattlePIPLUP::
	trainerbattle_no_intro TRAINER_LYRA_ROUTE_103_PIPLUP, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartLyra_Unova::
	switch VAR_STARTER_MON
	case 0, Route103_EventScript_StartLyraBattleSNIVY
	case 1, Route103_EventScript_StartLyraBattleTEPIG
	case 2, Route103_EventScript_StartLyraBattleOSHAWOTT
	end

Route103_EventScript_StartLyraBattleSNIVY::
	trainerbattle_no_intro TRAINER_LYRA_ROUTE_103_SNIVY, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartLyraBattleTEPIG::
	trainerbattle_no_intro TRAINER_LYRA_ROUTE_103_TEPIG, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartLyraBattleOSHAWOTT::
	trainerbattle_no_intro TRAINER_LYRA_ROUTE_103_OSHAWOTT, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartLyra_Kalos::
	switch VAR_STARTER_MON
	case 0, Route103_EventScript_StartLyraBattleCHESPIN
	case 1, Route103_EventScript_StartLyraBattleFENNEKIN
	case 2, Route103_EventScript_StartLyraBattleFROAKIE
	end

Route103_EventScript_StartLyraBattleCHESPIN::
	trainerbattle_no_intro TRAINER_LYRA_ROUTE_103_CHESPIN, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartLyraBattleFENNEKIN::
	trainerbattle_no_intro TRAINER_LYRA_ROUTE_103_FENNEKIN, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartLyraBattleFROAKIE::
	trainerbattle_no_intro TRAINER_LYRA_ROUTE_103_FROAKIE, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartLyra_Alola::
	switch VAR_STARTER_MON
	case 0, Route103_EventScript_StartLyraBattleROWLET
	case 1, Route103_EventScript_StartLyraBattleLITTEN
	case 2, Route103_EventScript_StartLyraBattlePOPPLIO
	end

Route103_EventScript_StartLyraBattleROWLET::
	trainerbattle_no_intro TRAINER_LYRA_ROUTE_103_ROWLET, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartLyraBattleLITTEN::
	trainerbattle_no_intro TRAINER_LYRA_ROUTE_103_LITTEN, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartLyraBattlePOPPLIO::
	trainerbattle_no_intro TRAINER_LYRA_ROUTE_103_POPPLIO, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartLyra_Galar::
	switch VAR_STARTER_MON
	case 0, Route103_EventScript_StartLyraBattleGROOKEY
	case 1, Route103_EventScript_StartLyraBattleSCORBUNNY
	case 2, Route103_EventScript_StartLyraBattleSOBBLE
	end

Route103_EventScript_StartLyraBattleGROOKEY::
	trainerbattle_no_intro TRAINER_LYRA_ROUTE_103_GROOKEY, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartLyraBattleSCORBUNNY::
	trainerbattle_no_intro TRAINER_LYRA_ROUTE_103_SCORBUNNY, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartLyraBattleSOBBLE::
	trainerbattle_no_intro TRAINER_LYRA_ROUTE_103_SOBBLE, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartLyra_Paldea::
	switch VAR_STARTER_MON
	case 0, Route103_EventScript_StartLyraBattleSPRIGATITO
	case 1, Route103_EventScript_StartLyraBattleFUECOCO
	case 2, Route103_EventScript_StartLyraBattleQUAXLY
	end

Route103_EventScript_StartLyraBattleSPRIGATITO::
	trainerbattle_no_intro TRAINER_LYRA_ROUTE_103_SPRIGATITO, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartLyraBattleFUECOCO::
	trainerbattle_no_intro TRAINER_LYRA_ROUTE_103_FUECOCO, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartLyraBattleQUAXLY::
	trainerbattle_no_intro TRAINER_LYRA_ROUTE_103_QUAXLY, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartLucas_Kanto::
	switch VAR_STARTER_MON
	case 0, Route103_EventScript_StartLucasBattleBULBASAUR
	case 1, Route103_EventScript_StartLucasBattleCHARMANDER
	case 2, Route103_EventScript_StartLucasBattleSQUIRTLE
	end

Route103_EventScript_StartLucasBattleBULBASAUR::
	trainerbattle_no_intro TRAINER_LUCAS_ROUTE_103_BULBASAUR, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartLucasBattleCHARMANDER::
	trainerbattle_no_intro TRAINER_LUCAS_ROUTE_103_CHARMANDER, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartLucasBattleSQUIRTLE::
	trainerbattle_no_intro TRAINER_LUCAS_ROUTE_103_SQUIRTLE, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartLucas_Johto::
	switch VAR_STARTER_MON
	case 0, Route103_EventScript_StartLucasBattleCHIKORITA
	case 1, Route103_EventScript_StartLucasBattleCYNDAQUIL
	case 2, Route103_EventScript_StartLucasBattleTOTODILE
	end

Route103_EventScript_StartLucasBattleCHIKORITA::
	trainerbattle_no_intro TRAINER_LUCAS_ROUTE_103_CHIKORITA, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartLucasBattleCYNDAQUIL::
	trainerbattle_no_intro TRAINER_LUCAS_ROUTE_103_CYNDAQUIL, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartLucasBattleTOTODILE::
	trainerbattle_no_intro TRAINER_LUCAS_ROUTE_103_TOTODILE, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartLucas_Hoenn::
	switch VAR_STARTER_MON
	case 0, Route103_EventScript_StartLucasBattleTREECKO
	case 1, Route103_EventScript_StartLucasBattleTORCHIC
	case 2, Route103_EventScript_StartLucasBattleMUDKIP
	end

Route103_EventScript_StartLucasBattleTREECKO::
	trainerbattle_no_intro TRAINER_LUCAS_ROUTE_103_TREECKO, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartLucasBattleTORCHIC::
	trainerbattle_no_intro TRAINER_LUCAS_ROUTE_103_TORCHIC, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartLucasBattleMUDKIP::
	trainerbattle_no_intro TRAINER_LUCAS_ROUTE_103_MUDKIP, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartLucas_Sinnoh::
	switch VAR_STARTER_MON
	case 0, Route103_EventScript_StartLucasBattleTURTWIG
	case 1, Route103_EventScript_StartLucasBattleCHIMCHAR
	case 2, Route103_EventScript_StartLucasBattlePIPLUP
	end

Route103_EventScript_StartLucasBattleTURTWIG::
	trainerbattle_no_intro TRAINER_LUCAS_ROUTE_103_TURTWIG, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartLucasBattleCHIMCHAR::
	trainerbattle_no_intro TRAINER_LUCAS_ROUTE_103_CHIMCHAR, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartLucasBattlePIPLUP::
	trainerbattle_no_intro TRAINER_LUCAS_ROUTE_103_PIPLUP, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartLucas_Unova::
	switch VAR_STARTER_MON
	case 0, Route103_EventScript_StartLucasBattleSNIVY
	case 1, Route103_EventScript_StartLucasBattleTEPIG
	case 2, Route103_EventScript_StartLucasBattleOSHAWOTT
	end

Route103_EventScript_StartLucasBattleSNIVY::
	trainerbattle_no_intro TRAINER_LUCAS_ROUTE_103_SNIVY, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartLucasBattleTEPIG::
	trainerbattle_no_intro TRAINER_LUCAS_ROUTE_103_TEPIG, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartLucasBattleOSHAWOTT::
	trainerbattle_no_intro TRAINER_LUCAS_ROUTE_103_OSHAWOTT, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartLucas_Kalos::
	switch VAR_STARTER_MON
	case 0, Route103_EventScript_StartLucasBattleCHESPIN
	case 1, Route103_EventScript_StartLucasBattleFENNEKIN
	case 2, Route103_EventScript_StartLucasBattleFROAKIE
	end

Route103_EventScript_StartLucasBattleCHESPIN::
	trainerbattle_no_intro TRAINER_LUCAS_ROUTE_103_CHESPIN, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartLucasBattleFENNEKIN::
	trainerbattle_no_intro TRAINER_LUCAS_ROUTE_103_FENNEKIN, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartLucasBattleFROAKIE::
	trainerbattle_no_intro TRAINER_LUCAS_ROUTE_103_FROAKIE, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartLucas_Alola::
	switch VAR_STARTER_MON
	case 0, Route103_EventScript_StartLucasBattleROWLET
	case 1, Route103_EventScript_StartLucasBattleLITTEN
	case 2, Route103_EventScript_StartLucasBattlePOPPLIO
	end

Route103_EventScript_StartLucasBattleROWLET::
	trainerbattle_no_intro TRAINER_LUCAS_ROUTE_103_ROWLET, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartLucasBattleLITTEN::
	trainerbattle_no_intro TRAINER_LUCAS_ROUTE_103_LITTEN, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartLucasBattlePOPPLIO::
	trainerbattle_no_intro TRAINER_LUCAS_ROUTE_103_POPPLIO, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartLucas_Galar::
	switch VAR_STARTER_MON
	case 0, Route103_EventScript_StartLucasBattleGROOKEY
	case 1, Route103_EventScript_StartLucasBattleSCORBUNNY
	case 2, Route103_EventScript_StartLucasBattleSOBBLE
	end

Route103_EventScript_StartLucasBattleGROOKEY::
	trainerbattle_no_intro TRAINER_LUCAS_ROUTE_103_GROOKEY, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartLucasBattleSCORBUNNY::
	trainerbattle_no_intro TRAINER_LUCAS_ROUTE_103_SCORBUNNY, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartLucasBattleSOBBLE::
	trainerbattle_no_intro TRAINER_LUCAS_ROUTE_103_SOBBLE, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartLucas_Paldea::
	switch VAR_STARTER_MON
	case 0, Route103_EventScript_StartLucasBattleSPRIGATITO
	case 1, Route103_EventScript_StartLucasBattleFUECOCO
	case 2, Route103_EventScript_StartLucasBattleQUAXLY
	end

Route103_EventScript_StartLucasBattleSPRIGATITO::
	trainerbattle_no_intro TRAINER_LUCAS_ROUTE_103_SPRIGATITO, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartLucasBattleFUECOCO::
	trainerbattle_no_intro TRAINER_LUCAS_ROUTE_103_FUECOCO, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartLucasBattleQUAXLY::
	trainerbattle_no_intro TRAINER_LUCAS_ROUTE_103_QUAXLY, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartDawn_Kanto::
	switch VAR_STARTER_MON
	case 0, Route103_EventScript_StartDawnBattleBULBASAUR
	case 1, Route103_EventScript_StartDawnBattleCHARMANDER
	case 2, Route103_EventScript_StartDawnBattleSQUIRTLE
	end

Route103_EventScript_StartDawnBattleBULBASAUR::
	trainerbattle_no_intro TRAINER_DAWN_ROUTE_103_BULBASAUR, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartDawnBattleCHARMANDER::
	trainerbattle_no_intro TRAINER_DAWN_ROUTE_103_CHARMANDER, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartDawnBattleSQUIRTLE::
	trainerbattle_no_intro TRAINER_DAWN_ROUTE_103_SQUIRTLE, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartDawn_Johto::
	switch VAR_STARTER_MON
	case 0, Route103_EventScript_StartDawnBattleCHIKORITA
	case 1, Route103_EventScript_StartDawnBattleCYNDAQUIL
	case 2, Route103_EventScript_StartDawnBattleTOTODILE
	end

Route103_EventScript_StartDawnBattleCHIKORITA::
	trainerbattle_no_intro TRAINER_DAWN_ROUTE_103_CHIKORITA, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartDawnBattleCYNDAQUIL::
	trainerbattle_no_intro TRAINER_DAWN_ROUTE_103_CYNDAQUIL, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartDawnBattleTOTODILE::
	trainerbattle_no_intro TRAINER_DAWN_ROUTE_103_TOTODILE, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartDawn_Hoenn::
	switch VAR_STARTER_MON
	case 0, Route103_EventScript_StartDawnBattleTREECKO
	case 1, Route103_EventScript_StartDawnBattleTORCHIC
	case 2, Route103_EventScript_StartDawnBattleMUDKIP
	end

Route103_EventScript_StartDawnBattleTREECKO::
	trainerbattle_no_intro TRAINER_DAWN_ROUTE_103_TREECKO, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartDawnBattleTORCHIC::
	trainerbattle_no_intro TRAINER_DAWN_ROUTE_103_TORCHIC, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartDawnBattleMUDKIP::
	trainerbattle_no_intro TRAINER_DAWN_ROUTE_103_MUDKIP, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartDawn_Sinnoh::
	switch VAR_STARTER_MON
	case 0, Route103_EventScript_StartDawnBattleTURTWIG
	case 1, Route103_EventScript_StartDawnBattleCHIMCHAR
	case 2, Route103_EventScript_StartDawnBattlePIPLUP
	end

Route103_EventScript_StartDawnBattleTURTWIG::
	trainerbattle_no_intro TRAINER_DAWN_ROUTE_103_TURTWIG, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartDawnBattleCHIMCHAR::
	trainerbattle_no_intro TRAINER_DAWN_ROUTE_103_CHIMCHAR, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartDawnBattlePIPLUP::
	trainerbattle_no_intro TRAINER_DAWN_ROUTE_103_PIPLUP, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartDawn_Unova::
	switch VAR_STARTER_MON
	case 0, Route103_EventScript_StartDawnBattleSNIVY
	case 1, Route103_EventScript_StartDawnBattleTEPIG
	case 2, Route103_EventScript_StartDawnBattleOSHAWOTT
	end

Route103_EventScript_StartDawnBattleSNIVY::
	trainerbattle_no_intro TRAINER_DAWN_ROUTE_103_SNIVY, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartDawnBattleTEPIG::
	trainerbattle_no_intro TRAINER_DAWN_ROUTE_103_TEPIG, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartDawnBattleOSHAWOTT::
	trainerbattle_no_intro TRAINER_DAWN_ROUTE_103_OSHAWOTT, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartDawn_Kalos::
	switch VAR_STARTER_MON
	case 0, Route103_EventScript_StartDawnBattleCHESPIN
	case 1, Route103_EventScript_StartDawnBattleFENNEKIN
	case 2, Route103_EventScript_StartDawnBattleFROAKIE
	end

Route103_EventScript_StartDawnBattleCHESPIN::
	trainerbattle_no_intro TRAINER_DAWN_ROUTE_103_CHESPIN, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartDawnBattleFENNEKIN::
	trainerbattle_no_intro TRAINER_DAWN_ROUTE_103_FENNEKIN, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartDawnBattleFROAKIE::
	trainerbattle_no_intro TRAINER_DAWN_ROUTE_103_FROAKIE, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartDawn_Alola::
	switch VAR_STARTER_MON
	case 0, Route103_EventScript_StartDawnBattleROWLET
	case 1, Route103_EventScript_StartDawnBattleLITTEN
	case 2, Route103_EventScript_StartDawnBattlePOPPLIO
	end

Route103_EventScript_StartDawnBattleROWLET::
	trainerbattle_no_intro TRAINER_DAWN_ROUTE_103_ROWLET, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartDawnBattleLITTEN::
	trainerbattle_no_intro TRAINER_DAWN_ROUTE_103_LITTEN, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartDawnBattlePOPPLIO::
	trainerbattle_no_intro TRAINER_DAWN_ROUTE_103_POPPLIO, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartDawn_Galar::
	switch VAR_STARTER_MON
	case 0, Route103_EventScript_StartDawnBattleGROOKEY
	case 1, Route103_EventScript_StartDawnBattleSCORBUNNY
	case 2, Route103_EventScript_StartDawnBattleSOBBLE
	end

Route103_EventScript_StartDawnBattleGROOKEY::
	trainerbattle_no_intro TRAINER_DAWN_ROUTE_103_GROOKEY, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartDawnBattleSCORBUNNY::
	trainerbattle_no_intro TRAINER_DAWN_ROUTE_103_SCORBUNNY, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartDawnBattleSOBBLE::
	trainerbattle_no_intro TRAINER_DAWN_ROUTE_103_SOBBLE, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartDawn_Paldea::
	switch VAR_STARTER_MON
	case 0, Route103_EventScript_StartDawnBattleSPRIGATITO
	case 1, Route103_EventScript_StartDawnBattleFUECOCO
	case 2, Route103_EventScript_StartDawnBattleQUAXLY
	end

Route103_EventScript_StartDawnBattleSPRIGATITO::
	trainerbattle_no_intro TRAINER_DAWN_ROUTE_103_SPRIGATITO, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartDawnBattleFUECOCO::
	trainerbattle_no_intro TRAINER_DAWN_ROUTE_103_FUECOCO, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartDawnBattleQUAXLY::
	trainerbattle_no_intro TRAINER_DAWN_ROUTE_103_QUAXLY, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartHilbert_Kanto::
	switch VAR_STARTER_MON
	case 0, Route103_EventScript_StartHilbertBattleBULBASAUR
	case 1, Route103_EventScript_StartHilbertBattleCHARMANDER
	case 2, Route103_EventScript_StartHilbertBattleSQUIRTLE
	end

Route103_EventScript_StartHilbertBattleBULBASAUR::
	trainerbattle_no_intro TRAINER_HILBERT_ROUTE_103_BULBASAUR, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartHilbertBattleCHARMANDER::
	trainerbattle_no_intro TRAINER_HILBERT_ROUTE_103_CHARMANDER, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartHilbertBattleSQUIRTLE::
	trainerbattle_no_intro TRAINER_HILBERT_ROUTE_103_SQUIRTLE, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartHilbert_Johto::
	switch VAR_STARTER_MON
	case 0, Route103_EventScript_StartHilbertBattleCHIKORITA
	case 1, Route103_EventScript_StartHilbertBattleCYNDAQUIL
	case 2, Route103_EventScript_StartHilbertBattleTOTODILE
	end

Route103_EventScript_StartHilbertBattleCHIKORITA::
	trainerbattle_no_intro TRAINER_HILBERT_ROUTE_103_CHIKORITA, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartHilbertBattleCYNDAQUIL::
	trainerbattle_no_intro TRAINER_HILBERT_ROUTE_103_CYNDAQUIL, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartHilbertBattleTOTODILE::
	trainerbattle_no_intro TRAINER_HILBERT_ROUTE_103_TOTODILE, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartHilbert_Hoenn::
	switch VAR_STARTER_MON
	case 0, Route103_EventScript_StartHilbertBattleTREECKO
	case 1, Route103_EventScript_StartHilbertBattleTORCHIC
	case 2, Route103_EventScript_StartHilbertBattleMUDKIP
	end

Route103_EventScript_StartHilbertBattleTREECKO::
	trainerbattle_no_intro TRAINER_HILBERT_ROUTE_103_TREECKO, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartHilbertBattleTORCHIC::
	trainerbattle_no_intro TRAINER_HILBERT_ROUTE_103_TORCHIC, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartHilbertBattleMUDKIP::
	trainerbattle_no_intro TRAINER_HILBERT_ROUTE_103_MUDKIP, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartHilbert_Sinnoh::
	switch VAR_STARTER_MON
	case 0, Route103_EventScript_StartHilbertBattleTURTWIG
	case 1, Route103_EventScript_StartHilbertBattleCHIMCHAR
	case 2, Route103_EventScript_StartHilbertBattlePIPLUP
	end

Route103_EventScript_StartHilbertBattleTURTWIG::
	trainerbattle_no_intro TRAINER_HILBERT_ROUTE_103_TURTWIG, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartHilbertBattleCHIMCHAR::
	trainerbattle_no_intro TRAINER_HILBERT_ROUTE_103_CHIMCHAR, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartHilbertBattlePIPLUP::
	trainerbattle_no_intro TRAINER_HILBERT_ROUTE_103_PIPLUP, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartHilbert_Unova::
	switch VAR_STARTER_MON
	case 0, Route103_EventScript_StartHilbertBattleSNIVY
	case 1, Route103_EventScript_StartHilbertBattleTEPIG
	case 2, Route103_EventScript_StartHilbertBattleOSHAWOTT
	end

Route103_EventScript_StartHilbertBattleSNIVY::
	trainerbattle_no_intro TRAINER_HILBERT_ROUTE_103_SNIVY, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartHilbertBattleTEPIG::
	trainerbattle_no_intro TRAINER_HILBERT_ROUTE_103_TEPIG, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartHilbertBattleOSHAWOTT::
	trainerbattle_no_intro TRAINER_HILBERT_ROUTE_103_OSHAWOTT, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartHilbert_Kalos::
	switch VAR_STARTER_MON
	case 0, Route103_EventScript_StartHilbertBattleCHESPIN
	case 1, Route103_EventScript_StartHilbertBattleFENNEKIN
	case 2, Route103_EventScript_StartHilbertBattleFROAKIE
	end

Route103_EventScript_StartHilbertBattleCHESPIN::
	trainerbattle_no_intro TRAINER_HILBERT_ROUTE_103_CHESPIN, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartHilbertBattleFENNEKIN::
	trainerbattle_no_intro TRAINER_HILBERT_ROUTE_103_FENNEKIN, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartHilbertBattleFROAKIE::
	trainerbattle_no_intro TRAINER_HILBERT_ROUTE_103_FROAKIE, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartHilbert_Alola::
	switch VAR_STARTER_MON
	case 0, Route103_EventScript_StartHilbertBattleROWLET
	case 1, Route103_EventScript_StartHilbertBattleLITTEN
	case 2, Route103_EventScript_StartHilbertBattlePOPPLIO
	end

Route103_EventScript_StartHilbertBattleROWLET::
	trainerbattle_no_intro TRAINER_HILBERT_ROUTE_103_ROWLET, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartHilbertBattleLITTEN::
	trainerbattle_no_intro TRAINER_HILBERT_ROUTE_103_LITTEN, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartHilbertBattlePOPPLIO::
	trainerbattle_no_intro TRAINER_HILBERT_ROUTE_103_POPPLIO, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartHilbert_Galar::
	switch VAR_STARTER_MON
	case 0, Route103_EventScript_StartHilbertBattleGROOKEY
	case 1, Route103_EventScript_StartHilbertBattleSCORBUNNY
	case 2, Route103_EventScript_StartHilbertBattleSOBBLE
	end

Route103_EventScript_StartHilbertBattleGROOKEY::
	trainerbattle_no_intro TRAINER_HILBERT_ROUTE_103_GROOKEY, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartHilbertBattleSCORBUNNY::
	trainerbattle_no_intro TRAINER_HILBERT_ROUTE_103_SCORBUNNY, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartHilbertBattleSOBBLE::
	trainerbattle_no_intro TRAINER_HILBERT_ROUTE_103_SOBBLE, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartHilbert_Paldea::
	switch VAR_STARTER_MON
	case 0, Route103_EventScript_StartHilbertBattleSPRIGATITO
	case 1, Route103_EventScript_StartHilbertBattleFUECOCO
	case 2, Route103_EventScript_StartHilbertBattleQUAXLY
	end

Route103_EventScript_StartHilbertBattleSPRIGATITO::
	trainerbattle_no_intro TRAINER_HILBERT_ROUTE_103_SPRIGATITO, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartHilbertBattleFUECOCO::
	trainerbattle_no_intro TRAINER_HILBERT_ROUTE_103_FUECOCO, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartHilbertBattleQUAXLY::
	trainerbattle_no_intro TRAINER_HILBERT_ROUTE_103_QUAXLY, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartHilda_Kanto::
	switch VAR_STARTER_MON
	case 0, Route103_EventScript_StartHildaBattleBULBASAUR
	case 1, Route103_EventScript_StartHildaBattleCHARMANDER
	case 2, Route103_EventScript_StartHildaBattleSQUIRTLE
	end

Route103_EventScript_StartHildaBattleBULBASAUR::
	trainerbattle_no_intro TRAINER_HILDA_ROUTE_103_BULBASAUR, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartHildaBattleCHARMANDER::
	trainerbattle_no_intro TRAINER_HILDA_ROUTE_103_CHARMANDER, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartHildaBattleSQUIRTLE::
	trainerbattle_no_intro TRAINER_HILDA_ROUTE_103_SQUIRTLE, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartHilda_Johto::
	switch VAR_STARTER_MON
	case 0, Route103_EventScript_StartHildaBattleCHIKORITA
	case 1, Route103_EventScript_StartHildaBattleCYNDAQUIL
	case 2, Route103_EventScript_StartHildaBattleTOTODILE
	end

Route103_EventScript_StartHildaBattleCHIKORITA::
	trainerbattle_no_intro TRAINER_HILDA_ROUTE_103_CHIKORITA, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartHildaBattleCYNDAQUIL::
	trainerbattle_no_intro TRAINER_HILDA_ROUTE_103_CYNDAQUIL, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartHildaBattleTOTODILE::
	trainerbattle_no_intro TRAINER_HILDA_ROUTE_103_TOTODILE, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartHilda_Hoenn::
	switch VAR_STARTER_MON
	case 0, Route103_EventScript_StartHildaBattleTREECKO
	case 1, Route103_EventScript_StartHildaBattleTORCHIC
	case 2, Route103_EventScript_StartHildaBattleMUDKIP
	end

Route103_EventScript_StartHildaBattleTREECKO::
	trainerbattle_no_intro TRAINER_HILDA_ROUTE_103_TREECKO, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartHildaBattleTORCHIC::
	trainerbattle_no_intro TRAINER_HILDA_ROUTE_103_TORCHIC, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartHildaBattleMUDKIP::
	trainerbattle_no_intro TRAINER_HILDA_ROUTE_103_MUDKIP, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartHilda_Sinnoh::
	switch VAR_STARTER_MON
	case 0, Route103_EventScript_StartHildaBattleTURTWIG
	case 1, Route103_EventScript_StartHildaBattleCHIMCHAR
	case 2, Route103_EventScript_StartHildaBattlePIPLUP
	end

Route103_EventScript_StartHildaBattleTURTWIG::
	trainerbattle_no_intro TRAINER_HILDA_ROUTE_103_TURTWIG, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartHildaBattleCHIMCHAR::
	trainerbattle_no_intro TRAINER_HILDA_ROUTE_103_CHIMCHAR, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartHildaBattlePIPLUP::
	trainerbattle_no_intro TRAINER_HILDA_ROUTE_103_PIPLUP, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartHilda_Unova::
	switch VAR_STARTER_MON
	case 0, Route103_EventScript_StartHildaBattleSNIVY
	case 1, Route103_EventScript_StartHildaBattleTEPIG
	case 2, Route103_EventScript_StartHildaBattleOSHAWOTT
	end

Route103_EventScript_StartHildaBattleSNIVY::
	trainerbattle_no_intro TRAINER_HILDA_ROUTE_103_SNIVY, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartHildaBattleTEPIG::
	trainerbattle_no_intro TRAINER_HILDA_ROUTE_103_TEPIG, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartHildaBattleOSHAWOTT::
	trainerbattle_no_intro TRAINER_HILDA_ROUTE_103_OSHAWOTT, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartHilda_Kalos::
	switch VAR_STARTER_MON
	case 0, Route103_EventScript_StartHildaBattleCHESPIN
	case 1, Route103_EventScript_StartHildaBattleFENNEKIN
	case 2, Route103_EventScript_StartHildaBattleFROAKIE
	end

Route103_EventScript_StartHildaBattleCHESPIN::
	trainerbattle_no_intro TRAINER_HILDA_ROUTE_103_CHESPIN, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartHildaBattleFENNEKIN::
	trainerbattle_no_intro TRAINER_HILDA_ROUTE_103_FENNEKIN, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartHildaBattleFROAKIE::
	trainerbattle_no_intro TRAINER_HILDA_ROUTE_103_FROAKIE, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartHilda_Alola::
	switch VAR_STARTER_MON
	case 0, Route103_EventScript_StartHildaBattleROWLET
	case 1, Route103_EventScript_StartHildaBattleLITTEN
	case 2, Route103_EventScript_StartHildaBattlePOPPLIO
	end

Route103_EventScript_StartHildaBattleROWLET::
	trainerbattle_no_intro TRAINER_HILDA_ROUTE_103_ROWLET, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartHildaBattleLITTEN::
	trainerbattle_no_intro TRAINER_HILDA_ROUTE_103_LITTEN, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartHildaBattlePOPPLIO::
	trainerbattle_no_intro TRAINER_HILDA_ROUTE_103_POPPLIO, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartHilda_Galar::
	switch VAR_STARTER_MON
	case 0, Route103_EventScript_StartHildaBattleGROOKEY
	case 1, Route103_EventScript_StartHildaBattleSCORBUNNY
	case 2, Route103_EventScript_StartHildaBattleSOBBLE
	end

Route103_EventScript_StartHildaBattleGROOKEY::
	trainerbattle_no_intro TRAINER_HILDA_ROUTE_103_GROOKEY, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartHildaBattleSCORBUNNY::
	trainerbattle_no_intro TRAINER_HILDA_ROUTE_103_SCORBUNNY, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartHildaBattleSOBBLE::
	trainerbattle_no_intro TRAINER_HILDA_ROUTE_103_SOBBLE, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartHilda_Paldea::
	switch VAR_STARTER_MON
	case 0, Route103_EventScript_StartHildaBattleSPRIGATITO
	case 1, Route103_EventScript_StartHildaBattleFUECOCO
	case 2, Route103_EventScript_StartHildaBattleQUAXLY
	end

Route103_EventScript_StartHildaBattleSPRIGATITO::
	trainerbattle_no_intro TRAINER_HILDA_ROUTE_103_SPRIGATITO, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartHildaBattleFUECOCO::
	trainerbattle_no_intro TRAINER_HILDA_ROUTE_103_FUECOCO, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartHildaBattleQUAXLY::
	trainerbattle_no_intro TRAINER_HILDA_ROUTE_103_QUAXLY, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartNate_Kanto::
	switch VAR_STARTER_MON
	case 0, Route103_EventScript_StartNateBattleBULBASAUR
	case 1, Route103_EventScript_StartNateBattleCHARMANDER
	case 2, Route103_EventScript_StartNateBattleSQUIRTLE
	end

Route103_EventScript_StartNateBattleBULBASAUR::
	trainerbattle_no_intro TRAINER_NATE_ROUTE_103_BULBASAUR, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartNateBattleCHARMANDER::
	trainerbattle_no_intro TRAINER_NATE_ROUTE_103_CHARMANDER, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartNateBattleSQUIRTLE::
	trainerbattle_no_intro TRAINER_NATE_ROUTE_103_SQUIRTLE, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartNate_Johto::
	switch VAR_STARTER_MON
	case 0, Route103_EventScript_StartNateBattleCHIKORITA
	case 1, Route103_EventScript_StartNateBattleCYNDAQUIL
	case 2, Route103_EventScript_StartNateBattleTOTODILE
	end

Route103_EventScript_StartNateBattleCHIKORITA::
	trainerbattle_no_intro TRAINER_NATE_ROUTE_103_CHIKORITA, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartNateBattleCYNDAQUIL::
	trainerbattle_no_intro TRAINER_NATE_ROUTE_103_CYNDAQUIL, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartNateBattleTOTODILE::
	trainerbattle_no_intro TRAINER_NATE_ROUTE_103_TOTODILE, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartNate_Hoenn::
	switch VAR_STARTER_MON
	case 0, Route103_EventScript_StartNateBattleTREECKO
	case 1, Route103_EventScript_StartNateBattleTORCHIC
	case 2, Route103_EventScript_StartNateBattleMUDKIP
	end

Route103_EventScript_StartNateBattleTREECKO::
	trainerbattle_no_intro TRAINER_NATE_ROUTE_103_TREECKO, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartNateBattleTORCHIC::
	trainerbattle_no_intro TRAINER_NATE_ROUTE_103_TORCHIC, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartNateBattleMUDKIP::
	trainerbattle_no_intro TRAINER_NATE_ROUTE_103_MUDKIP, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartNate_Sinnoh::
	switch VAR_STARTER_MON
	case 0, Route103_EventScript_StartNateBattleTURTWIG
	case 1, Route103_EventScript_StartNateBattleCHIMCHAR
	case 2, Route103_EventScript_StartNateBattlePIPLUP
	end

Route103_EventScript_StartNateBattleTURTWIG::
	trainerbattle_no_intro TRAINER_NATE_ROUTE_103_TURTWIG, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartNateBattleCHIMCHAR::
	trainerbattle_no_intro TRAINER_NATE_ROUTE_103_CHIMCHAR, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartNateBattlePIPLUP::
	trainerbattle_no_intro TRAINER_NATE_ROUTE_103_PIPLUP, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartNate_Unova::
	switch VAR_STARTER_MON
	case 0, Route103_EventScript_StartNateBattleSNIVY
	case 1, Route103_EventScript_StartNateBattleTEPIG
	case 2, Route103_EventScript_StartNateBattleOSHAWOTT
	end

Route103_EventScript_StartNateBattleSNIVY::
	trainerbattle_no_intro TRAINER_NATE_ROUTE_103_SNIVY, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartNateBattleTEPIG::
	trainerbattle_no_intro TRAINER_NATE_ROUTE_103_TEPIG, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartNateBattleOSHAWOTT::
	trainerbattle_no_intro TRAINER_NATE_ROUTE_103_OSHAWOTT, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartNate_Kalos::
	switch VAR_STARTER_MON
	case 0, Route103_EventScript_StartNateBattleCHESPIN
	case 1, Route103_EventScript_StartNateBattleFENNEKIN
	case 2, Route103_EventScript_StartNateBattleFROAKIE
	end

Route103_EventScript_StartNateBattleCHESPIN::
	trainerbattle_no_intro TRAINER_NATE_ROUTE_103_CHESPIN, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartNateBattleFENNEKIN::
	trainerbattle_no_intro TRAINER_NATE_ROUTE_103_FENNEKIN, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartNateBattleFROAKIE::
	trainerbattle_no_intro TRAINER_NATE_ROUTE_103_FROAKIE, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartNate_Alola::
	switch VAR_STARTER_MON
	case 0, Route103_EventScript_StartNateBattleROWLET
	case 1, Route103_EventScript_StartNateBattleLITTEN
	case 2, Route103_EventScript_StartNateBattlePOPPLIO
	end

Route103_EventScript_StartNateBattleROWLET::
	trainerbattle_no_intro TRAINER_NATE_ROUTE_103_ROWLET, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartNateBattleLITTEN::
	trainerbattle_no_intro TRAINER_NATE_ROUTE_103_LITTEN, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartNateBattlePOPPLIO::
	trainerbattle_no_intro TRAINER_NATE_ROUTE_103_POPPLIO, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartNate_Galar::
	switch VAR_STARTER_MON
	case 0, Route103_EventScript_StartNateBattleGROOKEY
	case 1, Route103_EventScript_StartNateBattleSCORBUNNY
	case 2, Route103_EventScript_StartNateBattleSOBBLE
	end

Route103_EventScript_StartNateBattleGROOKEY::
	trainerbattle_no_intro TRAINER_NATE_ROUTE_103_GROOKEY, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartNateBattleSCORBUNNY::
	trainerbattle_no_intro TRAINER_NATE_ROUTE_103_SCORBUNNY, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartNateBattleSOBBLE::
	trainerbattle_no_intro TRAINER_NATE_ROUTE_103_SOBBLE, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartNate_Paldea::
	switch VAR_STARTER_MON
	case 0, Route103_EventScript_StartNateBattleSPRIGATITO
	case 1, Route103_EventScript_StartNateBattleFUECOCO
	case 2, Route103_EventScript_StartNateBattleQUAXLY
	end

Route103_EventScript_StartNateBattleSPRIGATITO::
	trainerbattle_no_intro TRAINER_NATE_ROUTE_103_SPRIGATITO, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartNateBattleFUECOCO::
	trainerbattle_no_intro TRAINER_NATE_ROUTE_103_FUECOCO, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartNateBattleQUAXLY::
	trainerbattle_no_intro TRAINER_NATE_ROUTE_103_QUAXLY, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartRosa_Kanto::
	switch VAR_STARTER_MON
	case 0, Route103_EventScript_StartRosaBattleBULBASAUR
	case 1, Route103_EventScript_StartRosaBattleCHARMANDER
	case 2, Route103_EventScript_StartRosaBattleSQUIRTLE
	end

Route103_EventScript_StartRosaBattleBULBASAUR::
	trainerbattle_no_intro TRAINER_ROSA_ROUTE_103_BULBASAUR, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartRosaBattleCHARMANDER::
	trainerbattle_no_intro TRAINER_ROSA_ROUTE_103_CHARMANDER, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartRosaBattleSQUIRTLE::
	trainerbattle_no_intro TRAINER_ROSA_ROUTE_103_SQUIRTLE, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartRosa_Johto::
	switch VAR_STARTER_MON
	case 0, Route103_EventScript_StartRosaBattleCHIKORITA
	case 1, Route103_EventScript_StartRosaBattleCYNDAQUIL
	case 2, Route103_EventScript_StartRosaBattleTOTODILE
	end

Route103_EventScript_StartRosaBattleCHIKORITA::
	trainerbattle_no_intro TRAINER_ROSA_ROUTE_103_CHIKORITA, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartRosaBattleCYNDAQUIL::
	trainerbattle_no_intro TRAINER_ROSA_ROUTE_103_CYNDAQUIL, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartRosaBattleTOTODILE::
	trainerbattle_no_intro TRAINER_ROSA_ROUTE_103_TOTODILE, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartRosa_Hoenn::
	switch VAR_STARTER_MON
	case 0, Route103_EventScript_StartRosaBattleTREECKO
	case 1, Route103_EventScript_StartRosaBattleTORCHIC
	case 2, Route103_EventScript_StartRosaBattleMUDKIP
	end

Route103_EventScript_StartRosaBattleTREECKO::
	trainerbattle_no_intro TRAINER_ROSA_ROUTE_103_TREECKO, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartRosaBattleTORCHIC::
	trainerbattle_no_intro TRAINER_ROSA_ROUTE_103_TORCHIC, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartRosaBattleMUDKIP::
	trainerbattle_no_intro TRAINER_ROSA_ROUTE_103_MUDKIP, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartRosa_Sinnoh::
	switch VAR_STARTER_MON
	case 0, Route103_EventScript_StartRosaBattleTURTWIG
	case 1, Route103_EventScript_StartRosaBattleCHIMCHAR
	case 2, Route103_EventScript_StartRosaBattlePIPLUP
	end

Route103_EventScript_StartRosaBattleTURTWIG::
	trainerbattle_no_intro TRAINER_ROSA_ROUTE_103_TURTWIG, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartRosaBattleCHIMCHAR::
	trainerbattle_no_intro TRAINER_ROSA_ROUTE_103_CHIMCHAR, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartRosaBattlePIPLUP::
	trainerbattle_no_intro TRAINER_ROSA_ROUTE_103_PIPLUP, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartRosa_Unova::
	switch VAR_STARTER_MON
	case 0, Route103_EventScript_StartRosaBattleSNIVY
	case 1, Route103_EventScript_StartRosaBattleTEPIG
	case 2, Route103_EventScript_StartRosaBattleOSHAWOTT
	end

Route103_EventScript_StartRosaBattleSNIVY::
	trainerbattle_no_intro TRAINER_ROSA_ROUTE_103_SNIVY, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartRosaBattleTEPIG::
	trainerbattle_no_intro TRAINER_ROSA_ROUTE_103_TEPIG, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartRosaBattleOSHAWOTT::
	trainerbattle_no_intro TRAINER_ROSA_ROUTE_103_OSHAWOTT, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartRosa_Kalos::
	switch VAR_STARTER_MON
	case 0, Route103_EventScript_StartRosaBattleCHESPIN
	case 1, Route103_EventScript_StartRosaBattleFENNEKIN
	case 2, Route103_EventScript_StartRosaBattleFROAKIE
	end

Route103_EventScript_StartRosaBattleCHESPIN::
	trainerbattle_no_intro TRAINER_ROSA_ROUTE_103_CHESPIN, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartRosaBattleFENNEKIN::
	trainerbattle_no_intro TRAINER_ROSA_ROUTE_103_FENNEKIN, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartRosaBattleFROAKIE::
	trainerbattle_no_intro TRAINER_ROSA_ROUTE_103_FROAKIE, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartRosa_Alola::
	switch VAR_STARTER_MON
	case 0, Route103_EventScript_StartRosaBattleROWLET
	case 1, Route103_EventScript_StartRosaBattleLITTEN
	case 2, Route103_EventScript_StartRosaBattlePOPPLIO
	end

Route103_EventScript_StartRosaBattleROWLET::
	trainerbattle_no_intro TRAINER_ROSA_ROUTE_103_ROWLET, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartRosaBattleLITTEN::
	trainerbattle_no_intro TRAINER_ROSA_ROUTE_103_LITTEN, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartRosaBattlePOPPLIO::
	trainerbattle_no_intro TRAINER_ROSA_ROUTE_103_POPPLIO, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartRosa_Galar::
	switch VAR_STARTER_MON
	case 0, Route103_EventScript_StartRosaBattleGROOKEY
	case 1, Route103_EventScript_StartRosaBattleSCORBUNNY
	case 2, Route103_EventScript_StartRosaBattleSOBBLE
	end

Route103_EventScript_StartRosaBattleGROOKEY::
	trainerbattle_no_intro TRAINER_ROSA_ROUTE_103_GROOKEY, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartRosaBattleSCORBUNNY::
	trainerbattle_no_intro TRAINER_ROSA_ROUTE_103_SCORBUNNY, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartRosaBattleSOBBLE::
	trainerbattle_no_intro TRAINER_ROSA_ROUTE_103_SOBBLE, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartRosa_Paldea::
	switch VAR_STARTER_MON
	case 0, Route103_EventScript_StartRosaBattleSPRIGATITO
	case 1, Route103_EventScript_StartRosaBattleFUECOCO
	case 2, Route103_EventScript_StartRosaBattleQUAXLY
	end

Route103_EventScript_StartRosaBattleSPRIGATITO::
	trainerbattle_no_intro TRAINER_ROSA_ROUTE_103_SPRIGATITO, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartRosaBattleFUECOCO::
	trainerbattle_no_intro TRAINER_ROSA_ROUTE_103_FUECOCO, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartRosaBattleQUAXLY::
	trainerbattle_no_intro TRAINER_ROSA_ROUTE_103_QUAXLY, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartCalem_Kanto::
	switch VAR_STARTER_MON
	case 0, Route103_EventScript_StartCalemBattleBULBASAUR
	case 1, Route103_EventScript_StartCalemBattleCHARMANDER
	case 2, Route103_EventScript_StartCalemBattleSQUIRTLE
	end

Route103_EventScript_StartCalemBattleBULBASAUR::
	trainerbattle_no_intro TRAINER_CALEM_ROUTE_103_BULBASAUR, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartCalemBattleCHARMANDER::
	trainerbattle_no_intro TRAINER_CALEM_ROUTE_103_CHARMANDER, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartCalemBattleSQUIRTLE::
	trainerbattle_no_intro TRAINER_CALEM_ROUTE_103_SQUIRTLE, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartCalem_Johto::
	switch VAR_STARTER_MON
	case 0, Route103_EventScript_StartCalemBattleCHIKORITA
	case 1, Route103_EventScript_StartCalemBattleCYNDAQUIL
	case 2, Route103_EventScript_StartCalemBattleTOTODILE
	end

Route103_EventScript_StartCalemBattleCHIKORITA::
	trainerbattle_no_intro TRAINER_CALEM_ROUTE_103_CHIKORITA, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartCalemBattleCYNDAQUIL::
	trainerbattle_no_intro TRAINER_CALEM_ROUTE_103_CYNDAQUIL, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartCalemBattleTOTODILE::
	trainerbattle_no_intro TRAINER_CALEM_ROUTE_103_TOTODILE, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartCalem_Hoenn::
	switch VAR_STARTER_MON
	case 0, Route103_EventScript_StartCalemBattleTREECKO
	case 1, Route103_EventScript_StartCalemBattleTORCHIC
	case 2, Route103_EventScript_StartCalemBattleMUDKIP
	end

Route103_EventScript_StartCalemBattleTREECKO::
	trainerbattle_no_intro TRAINER_CALEM_ROUTE_103_TREECKO, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartCalemBattleTORCHIC::
	trainerbattle_no_intro TRAINER_CALEM_ROUTE_103_TORCHIC, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartCalemBattleMUDKIP::
	trainerbattle_no_intro TRAINER_CALEM_ROUTE_103_MUDKIP, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartCalem_Sinnoh::
	switch VAR_STARTER_MON
	case 0, Route103_EventScript_StartCalemBattleTURTWIG
	case 1, Route103_EventScript_StartCalemBattleCHIMCHAR
	case 2, Route103_EventScript_StartCalemBattlePIPLUP
	end

Route103_EventScript_StartCalemBattleTURTWIG::
	trainerbattle_no_intro TRAINER_CALEM_ROUTE_103_TURTWIG, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartCalemBattleCHIMCHAR::
	trainerbattle_no_intro TRAINER_CALEM_ROUTE_103_CHIMCHAR, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartCalemBattlePIPLUP::
	trainerbattle_no_intro TRAINER_CALEM_ROUTE_103_PIPLUP, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartCalem_Unova::
	switch VAR_STARTER_MON
	case 0, Route103_EventScript_StartCalemBattleSNIVY
	case 1, Route103_EventScript_StartCalemBattleTEPIG
	case 2, Route103_EventScript_StartCalemBattleOSHAWOTT
	end

Route103_EventScript_StartCalemBattleSNIVY::
	trainerbattle_no_intro TRAINER_CALEM_ROUTE_103_SNIVY, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartCalemBattleTEPIG::
	trainerbattle_no_intro TRAINER_CALEM_ROUTE_103_TEPIG, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartCalemBattleOSHAWOTT::
	trainerbattle_no_intro TRAINER_CALEM_ROUTE_103_OSHAWOTT, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartCalem_Kalos::
	switch VAR_STARTER_MON
	case 0, Route103_EventScript_StartCalemBattleCHESPIN
	case 1, Route103_EventScript_StartCalemBattleFENNEKIN
	case 2, Route103_EventScript_StartCalemBattleFROAKIE
	end

Route103_EventScript_StartCalemBattleCHESPIN::
	trainerbattle_no_intro TRAINER_CALEM_ROUTE_103_CHESPIN, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartCalemBattleFENNEKIN::
	trainerbattle_no_intro TRAINER_CALEM_ROUTE_103_FENNEKIN, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartCalemBattleFROAKIE::
	trainerbattle_no_intro TRAINER_CALEM_ROUTE_103_FROAKIE, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartCalem_Alola::
	switch VAR_STARTER_MON
	case 0, Route103_EventScript_StartCalemBattleROWLET
	case 1, Route103_EventScript_StartCalemBattleLITTEN
	case 2, Route103_EventScript_StartCalemBattlePOPPLIO
	end

Route103_EventScript_StartCalemBattleROWLET::
	trainerbattle_no_intro TRAINER_CALEM_ROUTE_103_ROWLET, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartCalemBattleLITTEN::
	trainerbattle_no_intro TRAINER_CALEM_ROUTE_103_LITTEN, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartCalemBattlePOPPLIO::
	trainerbattle_no_intro TRAINER_CALEM_ROUTE_103_POPPLIO, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartCalem_Galar::
	switch VAR_STARTER_MON
	case 0, Route103_EventScript_StartCalemBattleGROOKEY
	case 1, Route103_EventScript_StartCalemBattleSCORBUNNY
	case 2, Route103_EventScript_StartCalemBattleSOBBLE
	end

Route103_EventScript_StartCalemBattleGROOKEY::
	trainerbattle_no_intro TRAINER_CALEM_ROUTE_103_GROOKEY, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartCalemBattleSCORBUNNY::
	trainerbattle_no_intro TRAINER_CALEM_ROUTE_103_SCORBUNNY, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartCalemBattleSOBBLE::
	trainerbattle_no_intro TRAINER_CALEM_ROUTE_103_SOBBLE, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartCalem_Paldea::
	switch VAR_STARTER_MON
	case 0, Route103_EventScript_StartCalemBattleSPRIGATITO
	case 1, Route103_EventScript_StartCalemBattleFUECOCO
	case 2, Route103_EventScript_StartCalemBattleQUAXLY
	end

Route103_EventScript_StartCalemBattleSPRIGATITO::
	trainerbattle_no_intro TRAINER_CALEM_ROUTE_103_SPRIGATITO, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartCalemBattleFUECOCO::
	trainerbattle_no_intro TRAINER_CALEM_ROUTE_103_FUECOCO, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartCalemBattleQUAXLY::
	trainerbattle_no_intro TRAINER_CALEM_ROUTE_103_QUAXLY, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartSerena_Kanto::
	switch VAR_STARTER_MON
	case 0, Route103_EventScript_StartSerenaBattleBULBASAUR
	case 1, Route103_EventScript_StartSerenaBattleCHARMANDER
	case 2, Route103_EventScript_StartSerenaBattleSQUIRTLE
	end

Route103_EventScript_StartSerenaBattleBULBASAUR::
	trainerbattle_no_intro TRAINER_SERENA_ROUTE_103_BULBASAUR, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartSerenaBattleCHARMANDER::
	trainerbattle_no_intro TRAINER_SERENA_ROUTE_103_CHARMANDER, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartSerenaBattleSQUIRTLE::
	trainerbattle_no_intro TRAINER_SERENA_ROUTE_103_SQUIRTLE, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartSerena_Johto::
	switch VAR_STARTER_MON
	case 0, Route103_EventScript_StartSerenaBattleCHIKORITA
	case 1, Route103_EventScript_StartSerenaBattleCYNDAQUIL
	case 2, Route103_EventScript_StartSerenaBattleTOTODILE
	end

Route103_EventScript_StartSerenaBattleCHIKORITA::
	trainerbattle_no_intro TRAINER_SERENA_ROUTE_103_CHIKORITA, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartSerenaBattleCYNDAQUIL::
	trainerbattle_no_intro TRAINER_SERENA_ROUTE_103_CYNDAQUIL, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartSerenaBattleTOTODILE::
	trainerbattle_no_intro TRAINER_SERENA_ROUTE_103_TOTODILE, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartSerena_Hoenn::
	switch VAR_STARTER_MON
	case 0, Route103_EventScript_StartSerenaBattleTREECKO
	case 1, Route103_EventScript_StartSerenaBattleTORCHIC
	case 2, Route103_EventScript_StartSerenaBattleMUDKIP
	end

Route103_EventScript_StartSerenaBattleTREECKO::
	trainerbattle_no_intro TRAINER_SERENA_ROUTE_103_TREECKO, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartSerenaBattleTORCHIC::
	trainerbattle_no_intro TRAINER_SERENA_ROUTE_103_TORCHIC, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartSerenaBattleMUDKIP::
	trainerbattle_no_intro TRAINER_SERENA_ROUTE_103_MUDKIP, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartSerena_Sinnoh::
	switch VAR_STARTER_MON
	case 0, Route103_EventScript_StartSerenaBattleTURTWIG
	case 1, Route103_EventScript_StartSerenaBattleCHIMCHAR
	case 2, Route103_EventScript_StartSerenaBattlePIPLUP
	end

Route103_EventScript_StartSerenaBattleTURTWIG::
	trainerbattle_no_intro TRAINER_SERENA_ROUTE_103_TURTWIG, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartSerenaBattleCHIMCHAR::
	trainerbattle_no_intro TRAINER_SERENA_ROUTE_103_CHIMCHAR, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartSerenaBattlePIPLUP::
	trainerbattle_no_intro TRAINER_SERENA_ROUTE_103_PIPLUP, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartSerena_Unova::
	switch VAR_STARTER_MON
	case 0, Route103_EventScript_StartSerenaBattleSNIVY
	case 1, Route103_EventScript_StartSerenaBattleTEPIG
	case 2, Route103_EventScript_StartSerenaBattleOSHAWOTT
	end

Route103_EventScript_StartSerenaBattleSNIVY::
	trainerbattle_no_intro TRAINER_SERENA_ROUTE_103_SNIVY, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartSerenaBattleTEPIG::
	trainerbattle_no_intro TRAINER_SERENA_ROUTE_103_TEPIG, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartSerenaBattleOSHAWOTT::
	trainerbattle_no_intro TRAINER_SERENA_ROUTE_103_OSHAWOTT, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartSerena_Kalos::
	switch VAR_STARTER_MON
	case 0, Route103_EventScript_StartSerenaBattleCHESPIN
	case 1, Route103_EventScript_StartSerenaBattleFENNEKIN
	case 2, Route103_EventScript_StartSerenaBattleFROAKIE
	end

Route103_EventScript_StartSerenaBattleCHESPIN::
	trainerbattle_no_intro TRAINER_SERENA_ROUTE_103_CHESPIN, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartSerenaBattleFENNEKIN::
	trainerbattle_no_intro TRAINER_SERENA_ROUTE_103_FENNEKIN, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartSerenaBattleFROAKIE::
	trainerbattle_no_intro TRAINER_SERENA_ROUTE_103_FROAKIE, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartSerena_Alola::
	switch VAR_STARTER_MON
	case 0, Route103_EventScript_StartSerenaBattleROWLET
	case 1, Route103_EventScript_StartSerenaBattleLITTEN
	case 2, Route103_EventScript_StartSerenaBattlePOPPLIO
	end

Route103_EventScript_StartSerenaBattleROWLET::
	trainerbattle_no_intro TRAINER_SERENA_ROUTE_103_ROWLET, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartSerenaBattleLITTEN::
	trainerbattle_no_intro TRAINER_SERENA_ROUTE_103_LITTEN, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartSerenaBattlePOPPLIO::
	trainerbattle_no_intro TRAINER_SERENA_ROUTE_103_POPPLIO, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartSerena_Galar::
	switch VAR_STARTER_MON
	case 0, Route103_EventScript_StartSerenaBattleGROOKEY
	case 1, Route103_EventScript_StartSerenaBattleSCORBUNNY
	case 2, Route103_EventScript_StartSerenaBattleSOBBLE
	end

Route103_EventScript_StartSerenaBattleGROOKEY::
	trainerbattle_no_intro TRAINER_SERENA_ROUTE_103_GROOKEY, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartSerenaBattleSCORBUNNY::
	trainerbattle_no_intro TRAINER_SERENA_ROUTE_103_SCORBUNNY, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartSerenaBattleSOBBLE::
	trainerbattle_no_intro TRAINER_SERENA_ROUTE_103_SOBBLE, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartSerena_Paldea::
	switch VAR_STARTER_MON
	case 0, Route103_EventScript_StartSerenaBattleSPRIGATITO
	case 1, Route103_EventScript_StartSerenaBattleFUECOCO
	case 2, Route103_EventScript_StartSerenaBattleQUAXLY
	end

Route103_EventScript_StartSerenaBattleSPRIGATITO::
	trainerbattle_no_intro TRAINER_SERENA_ROUTE_103_SPRIGATITO, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartSerenaBattleFUECOCO::
	trainerbattle_no_intro TRAINER_SERENA_ROUTE_103_FUECOCO, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartSerenaBattleQUAXLY::
	trainerbattle_no_intro TRAINER_SERENA_ROUTE_103_QUAXLY, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartElio_Kanto::
	switch VAR_STARTER_MON
	case 0, Route103_EventScript_StartElioBattleBULBASAUR
	case 1, Route103_EventScript_StartElioBattleCHARMANDER
	case 2, Route103_EventScript_StartElioBattleSQUIRTLE
	end

Route103_EventScript_StartElioBattleBULBASAUR::
	trainerbattle_no_intro TRAINER_ELIO_ROUTE_103_BULBASAUR, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartElioBattleCHARMANDER::
	trainerbattle_no_intro TRAINER_ELIO_ROUTE_103_CHARMANDER, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartElioBattleSQUIRTLE::
	trainerbattle_no_intro TRAINER_ELIO_ROUTE_103_SQUIRTLE, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartElio_Johto::
	switch VAR_STARTER_MON
	case 0, Route103_EventScript_StartElioBattleCHIKORITA
	case 1, Route103_EventScript_StartElioBattleCYNDAQUIL
	case 2, Route103_EventScript_StartElioBattleTOTODILE
	end

Route103_EventScript_StartElioBattleCHIKORITA::
	trainerbattle_no_intro TRAINER_ELIO_ROUTE_103_CHIKORITA, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartElioBattleCYNDAQUIL::
	trainerbattle_no_intro TRAINER_ELIO_ROUTE_103_CYNDAQUIL, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartElioBattleTOTODILE::
	trainerbattle_no_intro TRAINER_ELIO_ROUTE_103_TOTODILE, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartElio_Hoenn::
	switch VAR_STARTER_MON
	case 0, Route103_EventScript_StartElioBattleTREECKO
	case 1, Route103_EventScript_StartElioBattleTORCHIC
	case 2, Route103_EventScript_StartElioBattleMUDKIP
	end

Route103_EventScript_StartElioBattleTREECKO::
	trainerbattle_no_intro TRAINER_ELIO_ROUTE_103_TREECKO, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartElioBattleTORCHIC::
	trainerbattle_no_intro TRAINER_ELIO_ROUTE_103_TORCHIC, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartElioBattleMUDKIP::
	trainerbattle_no_intro TRAINER_ELIO_ROUTE_103_MUDKIP, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartElio_Sinnoh::
	switch VAR_STARTER_MON
	case 0, Route103_EventScript_StartElioBattleTURTWIG
	case 1, Route103_EventScript_StartElioBattleCHIMCHAR
	case 2, Route103_EventScript_StartElioBattlePIPLUP
	end

Route103_EventScript_StartElioBattleTURTWIG::
	trainerbattle_no_intro TRAINER_ELIO_ROUTE_103_TURTWIG, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartElioBattleCHIMCHAR::
	trainerbattle_no_intro TRAINER_ELIO_ROUTE_103_CHIMCHAR, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartElioBattlePIPLUP::
	trainerbattle_no_intro TRAINER_ELIO_ROUTE_103_PIPLUP, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartElio_Unova::
	switch VAR_STARTER_MON
	case 0, Route103_EventScript_StartElioBattleSNIVY
	case 1, Route103_EventScript_StartElioBattleTEPIG
	case 2, Route103_EventScript_StartElioBattleOSHAWOTT
	end

Route103_EventScript_StartElioBattleSNIVY::
	trainerbattle_no_intro TRAINER_ELIO_ROUTE_103_SNIVY, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartElioBattleTEPIG::
	trainerbattle_no_intro TRAINER_ELIO_ROUTE_103_TEPIG, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartElioBattleOSHAWOTT::
	trainerbattle_no_intro TRAINER_ELIO_ROUTE_103_OSHAWOTT, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartElio_Kalos::
	switch VAR_STARTER_MON
	case 0, Route103_EventScript_StartElioBattleCHESPIN
	case 1, Route103_EventScript_StartElioBattleFENNEKIN
	case 2, Route103_EventScript_StartElioBattleFROAKIE
	end

Route103_EventScript_StartElioBattleCHESPIN::
	trainerbattle_no_intro TRAINER_ELIO_ROUTE_103_CHESPIN, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartElioBattleFENNEKIN::
	trainerbattle_no_intro TRAINER_ELIO_ROUTE_103_FENNEKIN, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartElioBattleFROAKIE::
	trainerbattle_no_intro TRAINER_ELIO_ROUTE_103_FROAKIE, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartElio_Alola::
	switch VAR_STARTER_MON
	case 0, Route103_EventScript_StartElioBattleROWLET
	case 1, Route103_EventScript_StartElioBattleLITTEN
	case 2, Route103_EventScript_StartElioBattlePOPPLIO
	end

Route103_EventScript_StartElioBattleROWLET::
	trainerbattle_no_intro TRAINER_ELIO_ROUTE_103_ROWLET, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartElioBattleLITTEN::
	trainerbattle_no_intro TRAINER_ELIO_ROUTE_103_LITTEN, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartElioBattlePOPPLIO::
	trainerbattle_no_intro TRAINER_ELIO_ROUTE_103_POPPLIO, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartElio_Galar::
	switch VAR_STARTER_MON
	case 0, Route103_EventScript_StartElioBattleGROOKEY
	case 1, Route103_EventScript_StartElioBattleSCORBUNNY
	case 2, Route103_EventScript_StartElioBattleSOBBLE
	end

Route103_EventScript_StartElioBattleGROOKEY::
	trainerbattle_no_intro TRAINER_ELIO_ROUTE_103_GROOKEY, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartElioBattleSCORBUNNY::
	trainerbattle_no_intro TRAINER_ELIO_ROUTE_103_SCORBUNNY, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartElioBattleSOBBLE::
	trainerbattle_no_intro TRAINER_ELIO_ROUTE_103_SOBBLE, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartElio_Paldea::
	switch VAR_STARTER_MON
	case 0, Route103_EventScript_StartElioBattleSPRIGATITO
	case 1, Route103_EventScript_StartElioBattleFUECOCO
	case 2, Route103_EventScript_StartElioBattleQUAXLY
	end

Route103_EventScript_StartElioBattleSPRIGATITO::
	trainerbattle_no_intro TRAINER_ELIO_ROUTE_103_SPRIGATITO, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartElioBattleFUECOCO::
	trainerbattle_no_intro TRAINER_ELIO_ROUTE_103_FUECOCO, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartElioBattleQUAXLY::
	trainerbattle_no_intro TRAINER_ELIO_ROUTE_103_QUAXLY, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartSelene_Kanto::
	switch VAR_STARTER_MON
	case 0, Route103_EventScript_StartSeleneBattleBULBASAUR
	case 1, Route103_EventScript_StartSeleneBattleCHARMANDER
	case 2, Route103_EventScript_StartSeleneBattleSQUIRTLE
	end

Route103_EventScript_StartSeleneBattleBULBASAUR::
	trainerbattle_no_intro TRAINER_SELENE_ROUTE_103_BULBASAUR, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartSeleneBattleCHARMANDER::
	trainerbattle_no_intro TRAINER_SELENE_ROUTE_103_CHARMANDER, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartSeleneBattleSQUIRTLE::
	trainerbattle_no_intro TRAINER_SELENE_ROUTE_103_SQUIRTLE, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartSelene_Johto::
	switch VAR_STARTER_MON
	case 0, Route103_EventScript_StartSeleneBattleCHIKORITA
	case 1, Route103_EventScript_StartSeleneBattleCYNDAQUIL
	case 2, Route103_EventScript_StartSeleneBattleTOTODILE
	end

Route103_EventScript_StartSeleneBattleCHIKORITA::
	trainerbattle_no_intro TRAINER_SELENE_ROUTE_103_CHIKORITA, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartSeleneBattleCYNDAQUIL::
	trainerbattle_no_intro TRAINER_SELENE_ROUTE_103_CYNDAQUIL, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartSeleneBattleTOTODILE::
	trainerbattle_no_intro TRAINER_SELENE_ROUTE_103_TOTODILE, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartSelene_Hoenn::
	switch VAR_STARTER_MON
	case 0, Route103_EventScript_StartSeleneBattleTREECKO
	case 1, Route103_EventScript_StartSeleneBattleTORCHIC
	case 2, Route103_EventScript_StartSeleneBattleMUDKIP
	end

Route103_EventScript_StartSeleneBattleTREECKO::
	trainerbattle_no_intro TRAINER_SELENE_ROUTE_103_TREECKO, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartSeleneBattleTORCHIC::
	trainerbattle_no_intro TRAINER_SELENE_ROUTE_103_TORCHIC, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartSeleneBattleMUDKIP::
	trainerbattle_no_intro TRAINER_SELENE_ROUTE_103_MUDKIP, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartSelene_Sinnoh::
	switch VAR_STARTER_MON
	case 0, Route103_EventScript_StartSeleneBattleTURTWIG
	case 1, Route103_EventScript_StartSeleneBattleCHIMCHAR
	case 2, Route103_EventScript_StartSeleneBattlePIPLUP
	end

Route103_EventScript_StartSeleneBattleTURTWIG::
	trainerbattle_no_intro TRAINER_SELENE_ROUTE_103_TURTWIG, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartSeleneBattleCHIMCHAR::
	trainerbattle_no_intro TRAINER_SELENE_ROUTE_103_CHIMCHAR, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartSeleneBattlePIPLUP::
	trainerbattle_no_intro TRAINER_SELENE_ROUTE_103_PIPLUP, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartSelene_Unova::
	switch VAR_STARTER_MON
	case 0, Route103_EventScript_StartSeleneBattleSNIVY
	case 1, Route103_EventScript_StartSeleneBattleTEPIG
	case 2, Route103_EventScript_StartSeleneBattleOSHAWOTT
	end

Route103_EventScript_StartSeleneBattleSNIVY::
	trainerbattle_no_intro TRAINER_SELENE_ROUTE_103_SNIVY, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartSeleneBattleTEPIG::
	trainerbattle_no_intro TRAINER_SELENE_ROUTE_103_TEPIG, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartSeleneBattleOSHAWOTT::
	trainerbattle_no_intro TRAINER_SELENE_ROUTE_103_OSHAWOTT, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartSelene_Kalos::
	switch VAR_STARTER_MON
	case 0, Route103_EventScript_StartSeleneBattleCHESPIN
	case 1, Route103_EventScript_StartSeleneBattleFENNEKIN
	case 2, Route103_EventScript_StartSeleneBattleFROAKIE
	end

Route103_EventScript_StartSeleneBattleCHESPIN::
	trainerbattle_no_intro TRAINER_SELENE_ROUTE_103_CHESPIN, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartSeleneBattleFENNEKIN::
	trainerbattle_no_intro TRAINER_SELENE_ROUTE_103_FENNEKIN, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartSeleneBattleFROAKIE::
	trainerbattle_no_intro TRAINER_SELENE_ROUTE_103_FROAKIE, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartSelene_Alola::
	switch VAR_STARTER_MON
	case 0, Route103_EventScript_StartSeleneBattleROWLET
	case 1, Route103_EventScript_StartSeleneBattleLITTEN
	case 2, Route103_EventScript_StartSeleneBattlePOPPLIO
	end

Route103_EventScript_StartSeleneBattleROWLET::
	trainerbattle_no_intro TRAINER_SELENE_ROUTE_103_ROWLET, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartSeleneBattleLITTEN::
	trainerbattle_no_intro TRAINER_SELENE_ROUTE_103_LITTEN, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartSeleneBattlePOPPLIO::
	trainerbattle_no_intro TRAINER_SELENE_ROUTE_103_POPPLIO, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartSelene_Galar::
	switch VAR_STARTER_MON
	case 0, Route103_EventScript_StartSeleneBattleGROOKEY
	case 1, Route103_EventScript_StartSeleneBattleSCORBUNNY
	case 2, Route103_EventScript_StartSeleneBattleSOBBLE
	end

Route103_EventScript_StartSeleneBattleGROOKEY::
	trainerbattle_no_intro TRAINER_SELENE_ROUTE_103_GROOKEY, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartSeleneBattleSCORBUNNY::
	trainerbattle_no_intro TRAINER_SELENE_ROUTE_103_SCORBUNNY, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartSeleneBattleSOBBLE::
	trainerbattle_no_intro TRAINER_SELENE_ROUTE_103_SOBBLE, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartSelene_Paldea::
	switch VAR_STARTER_MON
	case 0, Route103_EventScript_StartSeleneBattleSPRIGATITO
	case 1, Route103_EventScript_StartSeleneBattleFUECOCO
	case 2, Route103_EventScript_StartSeleneBattleQUAXLY
	end

Route103_EventScript_StartSeleneBattleSPRIGATITO::
	trainerbattle_no_intro TRAINER_SELENE_ROUTE_103_SPRIGATITO, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartSeleneBattleFUECOCO::
	trainerbattle_no_intro TRAINER_SELENE_ROUTE_103_FUECOCO, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartSeleneBattleQUAXLY::
	trainerbattle_no_intro TRAINER_SELENE_ROUTE_103_QUAXLY, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartVictor_Kanto::
	switch VAR_STARTER_MON
	case 0, Route103_EventScript_StartVictorBattleBULBASAUR
	case 1, Route103_EventScript_StartVictorBattleCHARMANDER
	case 2, Route103_EventScript_StartVictorBattleSQUIRTLE
	end

Route103_EventScript_StartVictorBattleBULBASAUR::
	trainerbattle_no_intro TRAINER_VICTOR_ROUTE_103_BULBASAUR, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartVictorBattleCHARMANDER::
	trainerbattle_no_intro TRAINER_VICTOR_ROUTE_103_CHARMANDER, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartVictorBattleSQUIRTLE::
	trainerbattle_no_intro TRAINER_VICTOR_ROUTE_103_SQUIRTLE, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartVictor_Johto::
	switch VAR_STARTER_MON
	case 0, Route103_EventScript_StartVictorBattleCHIKORITA
	case 1, Route103_EventScript_StartVictorBattleCYNDAQUIL
	case 2, Route103_EventScript_StartVictorBattleTOTODILE
	end

Route103_EventScript_StartVictorBattleCHIKORITA::
	trainerbattle_no_intro TRAINER_VICTOR_ROUTE_103_CHIKORITA, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartVictorBattleCYNDAQUIL::
	trainerbattle_no_intro TRAINER_VICTOR_ROUTE_103_CYNDAQUIL, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartVictorBattleTOTODILE::
	trainerbattle_no_intro TRAINER_VICTOR_ROUTE_103_TOTODILE, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartVictor_Hoenn::
	switch VAR_STARTER_MON
	case 0, Route103_EventScript_StartVictorBattleTREECKO
	case 1, Route103_EventScript_StartVictorBattleTORCHIC
	case 2, Route103_EventScript_StartVictorBattleMUDKIP
	end

Route103_EventScript_StartVictorBattleTREECKO::
	trainerbattle_no_intro TRAINER_VICTOR_ROUTE_103_TREECKO, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartVictorBattleTORCHIC::
	trainerbattle_no_intro TRAINER_VICTOR_ROUTE_103_TORCHIC, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartVictorBattleMUDKIP::
	trainerbattle_no_intro TRAINER_VICTOR_ROUTE_103_MUDKIP, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartVictor_Sinnoh::
	switch VAR_STARTER_MON
	case 0, Route103_EventScript_StartVictorBattleTURTWIG
	case 1, Route103_EventScript_StartVictorBattleCHIMCHAR
	case 2, Route103_EventScript_StartVictorBattlePIPLUP
	end

Route103_EventScript_StartVictorBattleTURTWIG::
	trainerbattle_no_intro TRAINER_VICTOR_ROUTE_103_TURTWIG, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartVictorBattleCHIMCHAR::
	trainerbattle_no_intro TRAINER_VICTOR_ROUTE_103_CHIMCHAR, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartVictorBattlePIPLUP::
	trainerbattle_no_intro TRAINER_VICTOR_ROUTE_103_PIPLUP, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartVictor_Unova::
	switch VAR_STARTER_MON
	case 0, Route103_EventScript_StartVictorBattleSNIVY
	case 1, Route103_EventScript_StartVictorBattleTEPIG
	case 2, Route103_EventScript_StartVictorBattleOSHAWOTT
	end

Route103_EventScript_StartVictorBattleSNIVY::
	trainerbattle_no_intro TRAINER_VICTOR_ROUTE_103_SNIVY, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartVictorBattleTEPIG::
	trainerbattle_no_intro TRAINER_VICTOR_ROUTE_103_TEPIG, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartVictorBattleOSHAWOTT::
	trainerbattle_no_intro TRAINER_VICTOR_ROUTE_103_OSHAWOTT, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartVictor_Kalos::
	switch VAR_STARTER_MON
	case 0, Route103_EventScript_StartVictorBattleCHESPIN
	case 1, Route103_EventScript_StartVictorBattleFENNEKIN
	case 2, Route103_EventScript_StartVictorBattleFROAKIE
	end

Route103_EventScript_StartVictorBattleCHESPIN::
	trainerbattle_no_intro TRAINER_VICTOR_ROUTE_103_CHESPIN, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartVictorBattleFENNEKIN::
	trainerbattle_no_intro TRAINER_VICTOR_ROUTE_103_FENNEKIN, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartVictorBattleFROAKIE::
	trainerbattle_no_intro TRAINER_VICTOR_ROUTE_103_FROAKIE, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartVictor_Alola::
	switch VAR_STARTER_MON
	case 0, Route103_EventScript_StartVictorBattleROWLET
	case 1, Route103_EventScript_StartVictorBattleLITTEN
	case 2, Route103_EventScript_StartVictorBattlePOPPLIO
	end

Route103_EventScript_StartVictorBattleROWLET::
	trainerbattle_no_intro TRAINER_VICTOR_ROUTE_103_ROWLET, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartVictorBattleLITTEN::
	trainerbattle_no_intro TRAINER_VICTOR_ROUTE_103_LITTEN, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartVictorBattlePOPPLIO::
	trainerbattle_no_intro TRAINER_VICTOR_ROUTE_103_POPPLIO, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartVictor_Galar::
	switch VAR_STARTER_MON
	case 0, Route103_EventScript_StartVictorBattleGROOKEY
	case 1, Route103_EventScript_StartVictorBattleSCORBUNNY
	case 2, Route103_EventScript_StartVictorBattleSOBBLE
	end

Route103_EventScript_StartVictorBattleGROOKEY::
	trainerbattle_no_intro TRAINER_VICTOR_ROUTE_103_GROOKEY, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartVictorBattleSCORBUNNY::
	trainerbattle_no_intro TRAINER_VICTOR_ROUTE_103_SCORBUNNY, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartVictorBattleSOBBLE::
	trainerbattle_no_intro TRAINER_VICTOR_ROUTE_103_SOBBLE, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartVictor_Paldea::
	switch VAR_STARTER_MON
	case 0, Route103_EventScript_StartVictorBattleSPRIGATITO
	case 1, Route103_EventScript_StartVictorBattleFUECOCO
	case 2, Route103_EventScript_StartVictorBattleQUAXLY
	end

Route103_EventScript_StartVictorBattleSPRIGATITO::
	trainerbattle_no_intro TRAINER_VICTOR_ROUTE_103_SPRIGATITO, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartVictorBattleFUECOCO::
	trainerbattle_no_intro TRAINER_VICTOR_ROUTE_103_FUECOCO, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartVictorBattleQUAXLY::
	trainerbattle_no_intro TRAINER_VICTOR_ROUTE_103_QUAXLY, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartGloria_Kanto::
	switch VAR_STARTER_MON
	case 0, Route103_EventScript_StartGloriaBattleBULBASAUR
	case 1, Route103_EventScript_StartGloriaBattleCHARMANDER
	case 2, Route103_EventScript_StartGloriaBattleSQUIRTLE
	end

Route103_EventScript_StartGloriaBattleBULBASAUR::
	trainerbattle_no_intro TRAINER_GLORIA_ROUTE_103_BULBASAUR, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartGloriaBattleCHARMANDER::
	trainerbattle_no_intro TRAINER_GLORIA_ROUTE_103_CHARMANDER, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartGloriaBattleSQUIRTLE::
	trainerbattle_no_intro TRAINER_GLORIA_ROUTE_103_SQUIRTLE, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartGloria_Johto::
	switch VAR_STARTER_MON
	case 0, Route103_EventScript_StartGloriaBattleCHIKORITA
	case 1, Route103_EventScript_StartGloriaBattleCYNDAQUIL
	case 2, Route103_EventScript_StartGloriaBattleTOTODILE
	end

Route103_EventScript_StartGloriaBattleCHIKORITA::
	trainerbattle_no_intro TRAINER_GLORIA_ROUTE_103_CHIKORITA, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartGloriaBattleCYNDAQUIL::
	trainerbattle_no_intro TRAINER_GLORIA_ROUTE_103_CYNDAQUIL, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartGloriaBattleTOTODILE::
	trainerbattle_no_intro TRAINER_GLORIA_ROUTE_103_TOTODILE, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartGloria_Hoenn::
	switch VAR_STARTER_MON
	case 0, Route103_EventScript_StartGloriaBattleTREECKO
	case 1, Route103_EventScript_StartGloriaBattleTORCHIC
	case 2, Route103_EventScript_StartGloriaBattleMUDKIP
	end

Route103_EventScript_StartGloriaBattleTREECKO::
	trainerbattle_no_intro TRAINER_GLORIA_ROUTE_103_TREECKO, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartGloriaBattleTORCHIC::
	trainerbattle_no_intro TRAINER_GLORIA_ROUTE_103_TORCHIC, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartGloriaBattleMUDKIP::
	trainerbattle_no_intro TRAINER_GLORIA_ROUTE_103_MUDKIP, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartGloria_Sinnoh::
	switch VAR_STARTER_MON
	case 0, Route103_EventScript_StartGloriaBattleTURTWIG
	case 1, Route103_EventScript_StartGloriaBattleCHIMCHAR
	case 2, Route103_EventScript_StartGloriaBattlePIPLUP
	end

Route103_EventScript_StartGloriaBattleTURTWIG::
	trainerbattle_no_intro TRAINER_GLORIA_ROUTE_103_TURTWIG, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartGloriaBattleCHIMCHAR::
	trainerbattle_no_intro TRAINER_GLORIA_ROUTE_103_CHIMCHAR, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartGloriaBattlePIPLUP::
	trainerbattle_no_intro TRAINER_GLORIA_ROUTE_103_PIPLUP, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartGloria_Unova::
	switch VAR_STARTER_MON
	case 0, Route103_EventScript_StartGloriaBattleSNIVY
	case 1, Route103_EventScript_StartGloriaBattleTEPIG
	case 2, Route103_EventScript_StartGloriaBattleOSHAWOTT
	end

Route103_EventScript_StartGloriaBattleSNIVY::
	trainerbattle_no_intro TRAINER_GLORIA_ROUTE_103_SNIVY, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartGloriaBattleTEPIG::
	trainerbattle_no_intro TRAINER_GLORIA_ROUTE_103_TEPIG, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartGloriaBattleOSHAWOTT::
	trainerbattle_no_intro TRAINER_GLORIA_ROUTE_103_OSHAWOTT, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartGloria_Kalos::
	switch VAR_STARTER_MON
	case 0, Route103_EventScript_StartGloriaBattleCHESPIN
	case 1, Route103_EventScript_StartGloriaBattleFENNEKIN
	case 2, Route103_EventScript_StartGloriaBattleFROAKIE
	end

Route103_EventScript_StartGloriaBattleCHESPIN::
	trainerbattle_no_intro TRAINER_GLORIA_ROUTE_103_CHESPIN, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartGloriaBattleFENNEKIN::
	trainerbattle_no_intro TRAINER_GLORIA_ROUTE_103_FENNEKIN, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartGloriaBattleFROAKIE::
	trainerbattle_no_intro TRAINER_GLORIA_ROUTE_103_FROAKIE, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartGloria_Alola::
	switch VAR_STARTER_MON
	case 0, Route103_EventScript_StartGloriaBattleROWLET
	case 1, Route103_EventScript_StartGloriaBattleLITTEN
	case 2, Route103_EventScript_StartGloriaBattlePOPPLIO
	end

Route103_EventScript_StartGloriaBattleROWLET::
	trainerbattle_no_intro TRAINER_GLORIA_ROUTE_103_ROWLET, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartGloriaBattleLITTEN::
	trainerbattle_no_intro TRAINER_GLORIA_ROUTE_103_LITTEN, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartGloriaBattlePOPPLIO::
	trainerbattle_no_intro TRAINER_GLORIA_ROUTE_103_POPPLIO, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartGloria_Galar::
	switch VAR_STARTER_MON
	case 0, Route103_EventScript_StartGloriaBattleGROOKEY
	case 1, Route103_EventScript_StartGloriaBattleSCORBUNNY
	case 2, Route103_EventScript_StartGloriaBattleSOBBLE
	end

Route103_EventScript_StartGloriaBattleGROOKEY::
	trainerbattle_no_intro TRAINER_GLORIA_ROUTE_103_GROOKEY, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartGloriaBattleSCORBUNNY::
	trainerbattle_no_intro TRAINER_GLORIA_ROUTE_103_SCORBUNNY, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartGloriaBattleSOBBLE::
	trainerbattle_no_intro TRAINER_GLORIA_ROUTE_103_SOBBLE, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartGloria_Paldea::
	switch VAR_STARTER_MON
	case 0, Route103_EventScript_StartGloriaBattleSPRIGATITO
	case 1, Route103_EventScript_StartGloriaBattleFUECOCO
	case 2, Route103_EventScript_StartGloriaBattleQUAXLY
	end

Route103_EventScript_StartGloriaBattleSPRIGATITO::
	trainerbattle_no_intro TRAINER_GLORIA_ROUTE_103_SPRIGATITO, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartGloriaBattleFUECOCO::
	trainerbattle_no_intro TRAINER_GLORIA_ROUTE_103_FUECOCO, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartGloriaBattleQUAXLY::
	trainerbattle_no_intro TRAINER_GLORIA_ROUTE_103_QUAXLY, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartFlorian_Kanto::
	switch VAR_STARTER_MON
	case 0, Route103_EventScript_StartFlorianBattleBULBASAUR
	case 1, Route103_EventScript_StartFlorianBattleCHARMANDER
	case 2, Route103_EventScript_StartFlorianBattleSQUIRTLE
	end

Route103_EventScript_StartFlorianBattleBULBASAUR::
	trainerbattle_no_intro TRAINER_FLORIAN_ROUTE_103_BULBASAUR, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartFlorianBattleCHARMANDER::
	trainerbattle_no_intro TRAINER_FLORIAN_ROUTE_103_CHARMANDER, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartFlorianBattleSQUIRTLE::
	trainerbattle_no_intro TRAINER_FLORIAN_ROUTE_103_SQUIRTLE, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartFlorian_Johto::
	switch VAR_STARTER_MON
	case 0, Route103_EventScript_StartFlorianBattleCHIKORITA
	case 1, Route103_EventScript_StartFlorianBattleCYNDAQUIL
	case 2, Route103_EventScript_StartFlorianBattleTOTODILE
	end

Route103_EventScript_StartFlorianBattleCHIKORITA::
	trainerbattle_no_intro TRAINER_FLORIAN_ROUTE_103_CHIKORITA, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartFlorianBattleCYNDAQUIL::
	trainerbattle_no_intro TRAINER_FLORIAN_ROUTE_103_CYNDAQUIL, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartFlorianBattleTOTODILE::
	trainerbattle_no_intro TRAINER_FLORIAN_ROUTE_103_TOTODILE, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartFlorian_Hoenn::
	switch VAR_STARTER_MON
	case 0, Route103_EventScript_StartFlorianBattleTREECKO
	case 1, Route103_EventScript_StartFlorianBattleTORCHIC
	case 2, Route103_EventScript_StartFlorianBattleMUDKIP
	end

Route103_EventScript_StartFlorianBattleTREECKO::
	trainerbattle_no_intro TRAINER_FLORIAN_ROUTE_103_TREECKO, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartFlorianBattleTORCHIC::
	trainerbattle_no_intro TRAINER_FLORIAN_ROUTE_103_TORCHIC, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartFlorianBattleMUDKIP::
	trainerbattle_no_intro TRAINER_FLORIAN_ROUTE_103_MUDKIP, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartFlorian_Sinnoh::
	switch VAR_STARTER_MON
	case 0, Route103_EventScript_StartFlorianBattleTURTWIG
	case 1, Route103_EventScript_StartFlorianBattleCHIMCHAR
	case 2, Route103_EventScript_StartFlorianBattlePIPLUP
	end

Route103_EventScript_StartFlorianBattleTURTWIG::
	trainerbattle_no_intro TRAINER_FLORIAN_ROUTE_103_TURTWIG, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartFlorianBattleCHIMCHAR::
	trainerbattle_no_intro TRAINER_FLORIAN_ROUTE_103_CHIMCHAR, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartFlorianBattlePIPLUP::
	trainerbattle_no_intro TRAINER_FLORIAN_ROUTE_103_PIPLUP, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartFlorian_Unova::
	switch VAR_STARTER_MON
	case 0, Route103_EventScript_StartFlorianBattleSNIVY
	case 1, Route103_EventScript_StartFlorianBattleTEPIG
	case 2, Route103_EventScript_StartFlorianBattleOSHAWOTT
	end

Route103_EventScript_StartFlorianBattleSNIVY::
	trainerbattle_no_intro TRAINER_FLORIAN_ROUTE_103_SNIVY, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartFlorianBattleTEPIG::
	trainerbattle_no_intro TRAINER_FLORIAN_ROUTE_103_TEPIG, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartFlorianBattleOSHAWOTT::
	trainerbattle_no_intro TRAINER_FLORIAN_ROUTE_103_OSHAWOTT, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartFlorian_Kalos::
	switch VAR_STARTER_MON
	case 0, Route103_EventScript_StartFlorianBattleCHESPIN
	case 1, Route103_EventScript_StartFlorianBattleFENNEKIN
	case 2, Route103_EventScript_StartFlorianBattleFROAKIE
	end

Route103_EventScript_StartFlorianBattleCHESPIN::
	trainerbattle_no_intro TRAINER_FLORIAN_ROUTE_103_CHESPIN, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartFlorianBattleFENNEKIN::
	trainerbattle_no_intro TRAINER_FLORIAN_ROUTE_103_FENNEKIN, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartFlorianBattleFROAKIE::
	trainerbattle_no_intro TRAINER_FLORIAN_ROUTE_103_FROAKIE, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartFlorian_Alola::
	switch VAR_STARTER_MON
	case 0, Route103_EventScript_StartFlorianBattleROWLET
	case 1, Route103_EventScript_StartFlorianBattleLITTEN
	case 2, Route103_EventScript_StartFlorianBattlePOPPLIO
	end

Route103_EventScript_StartFlorianBattleROWLET::
	trainerbattle_no_intro TRAINER_FLORIAN_ROUTE_103_ROWLET, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartFlorianBattleLITTEN::
	trainerbattle_no_intro TRAINER_FLORIAN_ROUTE_103_LITTEN, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartFlorianBattlePOPPLIO::
	trainerbattle_no_intro TRAINER_FLORIAN_ROUTE_103_POPPLIO, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartFlorian_Galar::
	switch VAR_STARTER_MON
	case 0, Route103_EventScript_StartFlorianBattleGROOKEY
	case 1, Route103_EventScript_StartFlorianBattleSCORBUNNY
	case 2, Route103_EventScript_StartFlorianBattleSOBBLE
	end

Route103_EventScript_StartFlorianBattleGROOKEY::
	trainerbattle_no_intro TRAINER_FLORIAN_ROUTE_103_GROOKEY, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartFlorianBattleSCORBUNNY::
	trainerbattle_no_intro TRAINER_FLORIAN_ROUTE_103_SCORBUNNY, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartFlorianBattleSOBBLE::
	trainerbattle_no_intro TRAINER_FLORIAN_ROUTE_103_SOBBLE, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartFlorian_Paldea::
	switch VAR_STARTER_MON
	case 0, Route103_EventScript_StartFlorianBattleSPRIGATITO
	case 1, Route103_EventScript_StartFlorianBattleFUECOCO
	case 2, Route103_EventScript_StartFlorianBattleQUAXLY
	end

Route103_EventScript_StartFlorianBattleSPRIGATITO::
	trainerbattle_no_intro TRAINER_FLORIAN_ROUTE_103_SPRIGATITO, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartFlorianBattleFUECOCO::
	trainerbattle_no_intro TRAINER_FLORIAN_ROUTE_103_FUECOCO, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartFlorianBattleQUAXLY::
	trainerbattle_no_intro TRAINER_FLORIAN_ROUTE_103_QUAXLY, Route103_Text_BrendanDefeat
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartJuliana_Kanto::
	switch VAR_STARTER_MON
	case 0, Route103_EventScript_StartJulianaBattleBULBASAUR
	case 1, Route103_EventScript_StartJulianaBattleCHARMANDER
	case 2, Route103_EventScript_StartJulianaBattleSQUIRTLE
	end

Route103_EventScript_StartJulianaBattleBULBASAUR::
	trainerbattle_no_intro TRAINER_JULIANA_ROUTE_103_BULBASAUR, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartJulianaBattleCHARMANDER::
	trainerbattle_no_intro TRAINER_JULIANA_ROUTE_103_CHARMANDER, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartJulianaBattleSQUIRTLE::
	trainerbattle_no_intro TRAINER_JULIANA_ROUTE_103_SQUIRTLE, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartJuliana_Johto::
	switch VAR_STARTER_MON
	case 0, Route103_EventScript_StartJulianaBattleCHIKORITA
	case 1, Route103_EventScript_StartJulianaBattleCYNDAQUIL
	case 2, Route103_EventScript_StartJulianaBattleTOTODILE
	end

Route103_EventScript_StartJulianaBattleCHIKORITA::
	trainerbattle_no_intro TRAINER_JULIANA_ROUTE_103_CHIKORITA, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartJulianaBattleCYNDAQUIL::
	trainerbattle_no_intro TRAINER_JULIANA_ROUTE_103_CYNDAQUIL, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartJulianaBattleTOTODILE::
	trainerbattle_no_intro TRAINER_JULIANA_ROUTE_103_TOTODILE, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartJuliana_Hoenn::
	switch VAR_STARTER_MON
	case 0, Route103_EventScript_StartJulianaBattleTREECKO
	case 1, Route103_EventScript_StartJulianaBattleTORCHIC
	case 2, Route103_EventScript_StartJulianaBattleMUDKIP
	end

Route103_EventScript_StartJulianaBattleTREECKO::
	trainerbattle_no_intro TRAINER_JULIANA_ROUTE_103_TREECKO, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartJulianaBattleTORCHIC::
	trainerbattle_no_intro TRAINER_JULIANA_ROUTE_103_TORCHIC, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartJulianaBattleMUDKIP::
	trainerbattle_no_intro TRAINER_JULIANA_ROUTE_103_MUDKIP, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartJuliana_Sinnoh::
	switch VAR_STARTER_MON
	case 0, Route103_EventScript_StartJulianaBattleTURTWIG
	case 1, Route103_EventScript_StartJulianaBattleCHIMCHAR
	case 2, Route103_EventScript_StartJulianaBattlePIPLUP
	end

Route103_EventScript_StartJulianaBattleTURTWIG::
	trainerbattle_no_intro TRAINER_JULIANA_ROUTE_103_TURTWIG, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartJulianaBattleCHIMCHAR::
	trainerbattle_no_intro TRAINER_JULIANA_ROUTE_103_CHIMCHAR, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartJulianaBattlePIPLUP::
	trainerbattle_no_intro TRAINER_JULIANA_ROUTE_103_PIPLUP, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartJuliana_Unova::
	switch VAR_STARTER_MON
	case 0, Route103_EventScript_StartJulianaBattleSNIVY
	case 1, Route103_EventScript_StartJulianaBattleTEPIG
	case 2, Route103_EventScript_StartJulianaBattleOSHAWOTT
	end

Route103_EventScript_StartJulianaBattleSNIVY::
	trainerbattle_no_intro TRAINER_JULIANA_ROUTE_103_SNIVY, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartJulianaBattleTEPIG::
	trainerbattle_no_intro TRAINER_JULIANA_ROUTE_103_TEPIG, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartJulianaBattleOSHAWOTT::
	trainerbattle_no_intro TRAINER_JULIANA_ROUTE_103_OSHAWOTT, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartJuliana_Kalos::
	switch VAR_STARTER_MON
	case 0, Route103_EventScript_StartJulianaBattleCHESPIN
	case 1, Route103_EventScript_StartJulianaBattleFENNEKIN
	case 2, Route103_EventScript_StartJulianaBattleFROAKIE
	end

Route103_EventScript_StartJulianaBattleCHESPIN::
	trainerbattle_no_intro TRAINER_JULIANA_ROUTE_103_CHESPIN, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartJulianaBattleFENNEKIN::
	trainerbattle_no_intro TRAINER_JULIANA_ROUTE_103_FENNEKIN, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartJulianaBattleFROAKIE::
	trainerbattle_no_intro TRAINER_JULIANA_ROUTE_103_FROAKIE, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartJuliana_Alola::
	switch VAR_STARTER_MON
	case 0, Route103_EventScript_StartJulianaBattleROWLET
	case 1, Route103_EventScript_StartJulianaBattleLITTEN
	case 2, Route103_EventScript_StartJulianaBattlePOPPLIO
	end

Route103_EventScript_StartJulianaBattleROWLET::
	trainerbattle_no_intro TRAINER_JULIANA_ROUTE_103_ROWLET, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartJulianaBattleLITTEN::
	trainerbattle_no_intro TRAINER_JULIANA_ROUTE_103_LITTEN, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartJulianaBattlePOPPLIO::
	trainerbattle_no_intro TRAINER_JULIANA_ROUTE_103_POPPLIO, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartJuliana_Galar::
	switch VAR_STARTER_MON
	case 0, Route103_EventScript_StartJulianaBattleGROOKEY
	case 1, Route103_EventScript_StartJulianaBattleSCORBUNNY
	case 2, Route103_EventScript_StartJulianaBattleSOBBLE
	end

Route103_EventScript_StartJulianaBattleGROOKEY::
	trainerbattle_no_intro TRAINER_JULIANA_ROUTE_103_GROOKEY, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartJulianaBattleSCORBUNNY::
	trainerbattle_no_intro TRAINER_JULIANA_ROUTE_103_SCORBUNNY, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartJulianaBattleSOBBLE::
	trainerbattle_no_intro TRAINER_JULIANA_ROUTE_103_SOBBLE, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartJuliana_Paldea::
	switch VAR_STARTER_MON
	case 0, Route103_EventScript_StartJulianaBattleSPRIGATITO
	case 1, Route103_EventScript_StartJulianaBattleFUECOCO
	case 2, Route103_EventScript_StartJulianaBattleQUAXLY
	end

Route103_EventScript_StartJulianaBattleSPRIGATITO::
	trainerbattle_no_intro TRAINER_JULIANA_ROUTE_103_SPRIGATITO, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartJulianaBattleFUECOCO::
	trainerbattle_no_intro TRAINER_JULIANA_ROUTE_103_FUECOCO, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartJulianaBattleQUAXLY::
	trainerbattle_no_intro TRAINER_JULIANA_ROUTE_103_QUAXLY, Route103_Text_MayDefeat
	goto Route103_EventScript_AfterMayBattle
	end

Route103_Text_MayRoute103Pokemon:
	.string "{RIVAL}: Mal seh'n... Das POKéMON von\n"
	.string "ROUTE 103 besitzt...$"

Route103_Text_MayLetsBattle:
	.string "Oh, hi {PLAYER}{KUN}!\p"
	.string "...Oh... Ich seh' schon. Mein Vater hat dir\n"
	.string "ein POKéMON geschenkt.\p"
	.string "Wenn wir schon mal hier sind, lass uns\n"
	.string "doch kämpfen!\p"
	.string "Ich gebe dir einen Vorgeschmack auf\n"
	.string "das Leben als TRAINER.$"

Route103_Text_MayDefeat:
	.string "Wow! Das war spitze!\n"
	.string "{PLAYER}{KUN}, du bist ein Naturtalent!$"

Route103_Text_MayTimeToHeadBack:
	.string "{RIVAL}: Ich glaube, ich weiß jetzt, warum\n"
	.string "mein Vater dich ausgesucht hat.\p"
	.string "Ich meine, du hast dein POKéMON erst\n"
	.string "sehr kurze Zeit und es mag dich bereits.\p"
	.string "Du wirst es einfach haben, dich mit\n"
	.string "jeder Art von POKéMON anzufreunden.\p"
	.string "Nun wird es aber Zeit, zurück ins LABOR\n"
	.string "zu gehen!$"

Route103_Text_BrendanRoute103Pokemon:
	.string "{RIVAL}: So... Dieses und dieses lebt an\n"
	.string "der ROUTE 103...$"

Route103_Text_BrendanLetsBattle:
	.string "Hey, da ist ja {PLAYER}!\p"
	.string "...Oh ja. Mein Vater hat dir ein POKéMON\n"
	.string "geschenkt, nicht wahr?\p"
	.string "Wenn wir schon mal hier sind, lass uns\n"
	.string "doch einen kleinen Kampf austragen.\p"
	.string "Ich bringe dir bei, was ein TRAINER\n"
	.string "wissen muss.$"

Route103_Text_BrendanDefeat:
	.string "Hey, {PLAYER}, das war gar nicht so übel.$"

Route103_Text_BrendanTimeToHeadBack:
	.string "{RIVAL}: Ich denke, ich habe es kapiert.\n"
	.string "Ich weiß jetzt, warum mein Vater dich\l"
	.string "ausgesucht hat.\p"
	.string "Du hast dein POKéMON noch nicht lange,\n"
	.string "und doch mag es dich schon.\p"
	.string "{PLAYER}, ich glaube, du kannst mit jedem\n"
	.string "POKéMON Freundschaft schließen.\p"
	.string "Wir sollten nun zurück zum LABOR gehen.$"

Route103_Text_ShouldHaveBroughtPotion:
	.string "Mein POKéMON ist unglaublich müde...\n"
	.string "Ich hätte einen TRANK mitnehmen sollen.$"

Route103_Text_ShortcutToOldale:
	.string "Wenn du von hier das Meer überquerst,\n"
	.string "nimmst du eine Abkürzung nach\l"
	.string "ROSALTSTADT.\p"
	.string "Hahaha, ist das kein praktischer Tipp?$"

Route103_Text_RouteSign:
	.string "ROUTE 103\n"
	.string "{DOWN_ARROW} ROSALTSTADT$"

Route103_EventScript_Bisasam::
	msgbox Route103_Text_Bisasam, MSGBOX_NPC
	end

Route103_Text_RedRoute103Pokemon:
	.string "Hm... Ich schätze, auf ROUTE 103\n"
	.string "gibt es einige starke Pokémon.$"

Route103_Text_RedLetsBattle:
	.string "Oh, {PLAYER}. Du hast ein Pokémon?\p"
	.string "Dann wollen wir sehen, wie stark du bist.\p"
	.string "Ich zeig dir, wie man richtig kämpft.$"

Route103_Text_RedDefeated:
	.string "Nicht schlecht... Du bist stärker\n"
	.string "als gedacht.$"

Route103_Text_RedTimeToHeadBack:
	.string "Ich verstehe, warum man dich\n"
	.string "ausgewählt hat. Gute Arbeit.\p"
	.string "Zurück ins Labor, los geht’s.$"

Route103_Text_LeafRoute103Pokemon:
	.string "Also diese Pokémon hier sehen echt\n"
	.string "interessant aus...$"

Route103_Text_LeafLetsBattle:
	.string "Oh, hi {PLAYER}!\p"
	.string "Du hast auch ein Pokémon bekommen?\p"
	.string "Na dann - auf in den ersten Kampf!\p"
	.string "Ich hoffe, du bist bereit!$"

Route103_Text_LeafDefeated:
	.string "Wow! Das war knapp - Respekt!$"

Route103_Text_LeafTimeToHeadBack:
	.string "Du scheinst dich gut mit deinem\n"
	.string "Pokémon zu verstehen.\p"
	.string "Ich denke, du wirst weit kommen!\p"
	.string "Zurück zum Labor!$"

Route103_Text_Bisasam:
	.string "Hey {PLAYER}, ich bin ein\n"
	.string "Bote von diesem Rom Entwickler.\l"
	.string "Sein name ist Zauke07!\p"
	.string "Immer wenn du mich am ende einer\n"
	.string "Route Siehst, sprich mich an, denn\l"
	.string "ich habe einen Heißen Tipp für dich!\p"
	.string "Tipp:\p"
	.string "Auf dieser Route versteckt sich ein\n"
	.string "Starter aus der 1 Generation mit\l"
	.string "einer Spawnrate von 1%!\p"
	.string "Welches es ist, musst du selbst\n"
	.string "herausfinden :D !$"

Route103_Text_DebugStarterRegion:
	.string "Region = {STR_VAR_1}$"

Route103_Text_DebugStarterVarResult:
	.string "Starter = {STR_VAR_1}$"

Route103_Text_Debug_ShowRivalMessage:
	.string "DEBUG: RivalMessage-Script gestartet$"

Text_Debug_StyleResult:
	.string "DEBUG: VAR_TEMP_0 = {STR_VAR_1}$"

Text_Debug_StarterRegion:
	.string "DEBUG: StarterRegion = {STR_VAR_2}$"

Text_Debug_StyleStarterVars:
	.string "DEBUG: Style = {STR_VAR_1}, Region = {STR_VAR_2}$"

Route103_Text_Debug_UnknownStyle:
	.string "DEBUG: Style nicht erkannt$"

Route103_Text_Debug:
	.string "DEBUG: EventScript_Rival wurde gestartet$"


