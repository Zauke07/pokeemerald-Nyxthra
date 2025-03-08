Common_EventScript_SetupRivalGfxId::
    checkplayerstyle
    compare VAR_RESULT, STYLE_BRENDAN
    goto_if_eq EventScript_SetupRivalGfxIdMay
    compare VAR_RESULT, STYLE_MAY
    goto_if_eq EventScript_SetupRivalGfxIdBrendan
    compare VAR_RESULT, STYLE_RED
    goto_if_eq EventScript_SetupRivalGfxIdLeaf
    compare VAR_RESULT, STYLE_LEAF
    goto_if_eq EventScript_SetupRivalGfxIdRed
    compare VAR_RESULT, STYLE_ETHAN
    goto_if_eq EventScript_SetupRivalGfxIdLyra
    compare VAR_RESULT, STYLE_LYRA
    goto_if_eq EventScript_SetupRivalGfxIdEthan
    compare VAR_RESULT, STYLE_LUCAS
    goto_if_eq EventScript_SetupRivalGfxIdDawn
    compare VAR_RESULT, STYLE_DAWN
    goto_if_eq EventScript_SetupRivalGfxIdLucas
    compare VAR_RESULT, STYLE_HILBERT
    goto_if_eq EventScript_SetupRivalGfxIdHilda
    compare VAR_RESULT, STYLE_HILDA
    goto_if_eq EventScript_SetupRivalGfxIdHilbert
    compare VAR_RESULT, STYLE_NATE
    goto_if_eq EventScript_SetupRivalGfxIdRosa
    compare VAR_RESULT, STYLE_ROSA
    goto_if_eq EventScript_SetupRivalGfxIdNate
    compare VAR_RESULT, STYLE_CALEM
    goto_if_eq EventScript_SetupRivalGfxIdSerena
    compare VAR_RESULT, STYLE_SERENA
    goto_if_eq EventScript_SetupRivalGfxIdCalem
    compare VAR_RESULT, STYLE_ELIO
    goto_if_eq EventScript_SetupRivalGfxIdSelene
    compare VAR_RESULT, STYLE_SELENE
    goto_if_eq EventScript_SetupRivalGfxIdElio
    compare VAR_RESULT, STYLE_VICTOR
    goto_if_eq EventScript_SetupRivalGfxIdGloria
    compare VAR_RESULT, STYLE_GLORIA
    goto_if_eq EventScript_SetupRivalGfxIdVictor
    compare VAR_RESULT, STYLE_FLORIAN
    goto_if_eq EventScript_SetupRivalGfxIdJuliana
    compare VAR_RESULT, STYLE_JULIANA
    goto_if_eq EventScript_SetupRivalGfxIdFlorian

    end

EventScript_SetupRivalGfxIdMay::
    setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RIVAL_MAY_NORMAL
    return

EventScript_SetupRivalGfxIdBrendan::
    setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RIVAL_BRENDAN_NORMAL
    return

EventScript_SetupRivalGfxIdRed::
    setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RIVAL_RED
    return

EventScript_SetupRivalGfxIdLeaf::
    setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RIVAL_LEAF
    return

EventScript_SetupRivalGfxIdEthan::
    setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RIVAL_ETHAN
    return

EventScript_SetupRivalGfxIdLyra::
    setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RIVAL_LYRA
    return

EventScript_SetupRivalGfxIdLucas::
    setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RIVAL_LUCAS
    return

EventScript_SetupRivalGfxIdDawn::
    setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RIVAL_DAWN
    return

EventScript_SetupRivalGfxIdHilbert::
    setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RIVAL_HILBERT
    return

EventScript_SetupRivalGfxIdHilda::
    setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RIVAL_HILDA
    return

EventScript_SetupRivalGfxIdNate::
    setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RIVAL_NATE
    return

EventScript_SetupRivalGfxIdRosa::
    setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RIVAL_ROSA
    return

EventScript_SetupRivalGfxIdCalem::
    setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RIVAL_CALEM
    return

EventScript_SetupRivalGfxIdSerena::
    setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RIVAL_SERENA
    return

EventScript_SetupRivalGfxIdElio::
    setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RIVAL_ELIO
    return

EventScript_SetupRivalGfxIdSelene::
    setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RIVAL_SELENE
    return

EventScript_SetupRivalGfxIdVictor::
    setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RIVAL_VICTOR
    return

EventScript_SetupRivalGfxIdGloria::
    setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RIVAL_GLORIA
    return

EventScript_SetupRivalGfxIdFlorian::
    setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RIVAL_FLORIAN
    return

EventScript_SetupRivalGfxIdJuliana::
    setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RIVAL_JULIANA
    return

Common_EventScript_SetupRivalOnBikeGfxId::
    checkplayerstyle
    compare VAR_RESULT, STYLE_BRENDAN
    goto_if_eq EventScript_SetupRivalOnBikeGfxIdMay
    compare VAR_RESULT, STYLE_MAY
    goto_if_eq EventScript_SetupRivalOnBikeGfxIdBrendan
    compare VAR_RESULT, STYLE_RED
    goto_if_eq EventScript_SetupRivalOnBikeGfxIdLeaf
    compare VAR_RESULT, STYLE_LEAF
    goto_if_eq EventScript_SetupRivalOnBikeGfxIdRed
    compare VAR_RESULT, STYLE_ETHAN
    goto_if_eq EventScript_SetupRivalOnBikeGfxIdLyra
    compare VAR_RESULT, STYLE_LYRA
    goto_if_eq EventScript_SetupRivalOnBikeGfxIdEthan
    compare VAR_RESULT, STYLE_LUCAS
    goto_if_eq EventScript_SetupRivalOnBikeGfxIdDawn
    compare VAR_RESULT, STYLE_DAWN
    goto_if_eq EventScript_SetupRivalOnBikeGfxIdLucas
    compare VAR_RESULT, STYLE_HILBERT
    goto_if_eq EventScript_SetupRivalOnBikeGfxIdHilda
    compare VAR_RESULT, STYLE_HILDA
    goto_if_eq EventScript_SetupRivalOnBikeGfxIdHilbert
    compare VAR_RESULT, STYLE_NATE
    goto_if_eq EventScript_SetupRivalOnBikeGfxIdRosa
    compare VAR_RESULT, STYLE_ROSA
    goto_if_eq EventScript_SetupRivalOnBikeGfxIdNate
    compare VAR_RESULT, STYLE_CALEM
    goto_if_eq EventScript_SetupRivalOnBikeGfxIdSerena
    compare VAR_RESULT, STYLE_SERENA
    goto_if_eq EventScript_SetupRivalOnBikeGfxIdCalem
    compare VAR_RESULT, STYLE_ELIO
    goto_if_eq EventScript_SetupRivalOnBikeGfxIdSelene
    compare VAR_RESULT, STYLE_SELENE
    goto_if_eq EventScript_SetupRivalOnBikeGfxIdElio
    compare VAR_RESULT, STYLE_VICTOR
    goto_if_eq EventScript_SetupRivalOnBikeGfxIdGloria
    compare VAR_RESULT, STYLE_GLORIA
    goto_if_eq EventScript_SetupRivalOnBikeGfxIdVictor
    compare VAR_RESULT, STYLE_FLORIAN
    goto_if_eq EventScript_SetupRivalOnBikeGfxIdJuliana
    compare VAR_RESULT, STYLE_JULIANA
    goto_if_eq EventScript_SetupRivalOnBikeGfxIdFlorian

end

EventScript_SetupRivalOnBikeGfxIdMay::
    setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RIVAL_MAY_BIKE
    return

EventScript_SetupRivalOnBikeGfxIdBrendan::
    setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RIVAL_BRENDAN_BIKE
    return

EventScript_SetupRivalOnBikeGfxIdRed::
    setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RIVAL_RED_BIKE
    return

EventScript_SetupRivalOnBikeGfxIdLeaf::
    setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RIVAL_LEAF_BIKE
    return

EventScript_SetupRivalOnBikeGfxIdEthan::
    setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RIVAL_ETHAN_BIKE
    return

EventScript_SetupRivalOnBikeGfxIdLyra::
    setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RIVAL_LYRA_BIKE
    return

EventScript_SetupRivalOnBikeGfxIdLucas::
    setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RIVAL_LUCAS_BIKE
    return

EventScript_SetupRivalOnBikeGfxIdDawn::
    setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RIVAL_DAWN_BIKE
    return

EventScript_SetupRivalOnBikeGfxIdHilbert::
    setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RIVAL_HILBERT_BIKE
    return

EventScript_SetupRivalOnBikeGfxIdHilda::
    setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RIVAL_HILDA_BIKE
    return

EventScript_SetupRivalOnBikeGfxIdNate::
    setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RIVAL_NATE_BIKE
    return

EventScript_SetupRivalOnBikeGfxIdRosa::
    setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RIVAL_ROSA_BIKE
    return

EventScript_SetupRivalOnBikeGfxIdCalem::
    setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RIVAL_CALEM_BIKE
    return

EventScript_SetupRivalOnBikeGfxIdSerena::
    setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RIVAL_SERENA_BIKE
    return

EventScript_SetupRivalOnBikeGfxIdElio::
    setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RIVAL_ELIO_BIKE
    return

EventScript_SetupRivalOnBikeGfxIdSelene::
    setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RIVAL_SELENE_BIKE
    return

EventScript_SetupRivalOnBikeGfxIdVictor::
    setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RIVAL_VICTOR_BIKE
    return

EventScript_SetupRivalOnBikeGfxIdGloria::
    setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RIVAL_GLORIA_BIKE
    return

EventScript_SetupRivalOnBikeGfxIdFlorian::
    setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RIVAL_FLORIAN_BIKE
    return

EventScript_SetupRivalOnBikeGfxIdJuliana::
    setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RIVAL_JULIANA_BIKE
    return

Common_EventScript_SetupRivalMusic::
    checkplayerstyle
    compare VAR_RESULT, STYLE_BRENDAN
    goto_if_eq EventScript_PlayMayMusic
    compare VAR_RESULT, STYLE_MAY
    goto_if_eq EventScript_PlayBrendanMusic
    compare VAR_RESULT, STYLE_RED
    goto_if_eq EventScript_PlayMayMusic
    compare VAR_RESULT, STYLE_LEAF
    goto_if_eq EventScript_PlayBrendanMusic
    compare VAR_RESULT, STYLE_ETHAN
    goto_if_eq EventScript_PlayMayMusic
    compare VAR_RESULT, STYLE_LYRA
    goto_if_eq EventScript_PlayBrendanMusic
    compare VAR_RESULT, STYLE_LUCAS
    goto_if_eq EventScript_PlayMayMusic
    compare VAR_RESULT, STYLE_DAWN
    goto_if_eq EventScript_PlayBrendanMusic
    compare VAR_RESULT, STYLE_HILBERT
    goto_if_eq EventScript_PlayMayMusic
    compare VAR_RESULT, STYLE_HILDA
    goto_if_eq EventScript_PlayBrendanMusic
    compare VAR_RESULT, STYLE_NATE
    goto_if_eq EventScript_PlayMayMusic
    compare VAR_RESULT, STYLE_ROSA
    goto_if_eq EventScript_PlayBrendanMusic
    compare VAR_RESULT, STYLE_CALEM
    goto_if_eq EventScript_PlayMayMusic
    compare VAR_RESULT, STYLE_SERENA
    goto_if_eq EventScript_PlayBrendanMusic
    compare VAR_RESULT, STYLE_ELIO
    goto_if_eq EventScript_PlayMayMusic
    compare VAR_RESULT, STYLE_SELENE
    goto_if_eq EventScript_PlayBrendanMusic
    compare VAR_RESULT, STYLE_VICTOR
    goto_if_eq EventScript_PlayMayMusic
    compare VAR_RESULT, STYLE_GLORIA
    goto_if_eq EventScript_PlayBrendanMusic
    compare VAR_RESULT, STYLE_FLORIAN
    goto_if_eq EventScript_PlayMayMusic
    compare VAR_RESULT, STYLE_JULIANA
    goto_if_eq EventScript_PlayBrendanMusic

end

EventScript_PlayMayMusic::
    playbgm MUS_ENCOUNTER_MAY, TRUE
    return

EventScript_PlayBrendanMusic::
    playbgm MUS_ENCOUNTER_BRENDAN, TRUE
    return
