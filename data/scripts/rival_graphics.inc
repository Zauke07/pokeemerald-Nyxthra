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
@    compare VAR_RESULT, STYLE_NATE
@    goto_if_eq EventScript_SetupRivalGfxIdRosa
@    compare VAR_RESULT, STYLE_ROSA
@    goto_if_eq EventScript_SetupRivalGfxIdNate
@    compare VAR_RESULT, STYLE_CALEM
@    goto_if_eq EventScript_SetupRivalGfxIdSerena
@    compare VAR_RESULT, STYLE_SERENA
@    goto_if_eq EventScript_SetupRivalGfxIdCalem
@    compare VAR_RESULT, STYLE_ELIO
@    goto_if_eq EventScript_SetupRivalGfxIdSelene
@    compare VAR_RESULT, STYLE_SELENE
@    goto_if_eq EventScript_SetupRivalGfxIdElio
@    compare VAR_RESULT, STYLE_VICTOR
@    goto_if_eq EventScript_SetupRivalGfxIdGloria
@    compare VAR_RESULT, STYLE_GLORIA
@    goto_if_eq EventScript_SetupRivalGfxIdVictor
@    compare VAR_RESULT, STYLE_FLORIAN
@    goto_if_eq EventScript_SetupRivalGfxIdJuliana
@    compare VAR_RESULT, STYLE_JULIANA
@    goto_if_eq EventScript_SetupRivalGfxIdFlorian

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
    goto_if_eq EventScript_SetupRivalOnMachBikeGfxIdMay
    compare VAR_RESULT, STYLE_MAY
    goto_if_eq EventScript_SetupRivalOnMachBikeGfxIdBrendan
    compare VAR_RESULT, STYLE_RED
    goto_if_eq EventScript_SetupRivalOnMachBikeGfxIdLeaf
    compare VAR_RESULT, STYLE_LEAF
    goto_if_eq EventScript_SetupRivalOnMachBikeGfxIdRed
    compare VAR_RESULT, STYLE_ETHAN
    goto_if_eq EventScript_SetupRivalOnMachBikeGfxIdLyra
    compare VAR_RESULT, STYLE_LYRA
    goto_if_eq EventScript_SetupRivalOnMachBikeGfxIdEthan
    compare VAR_RESULT, STYLE_LUCAS
    goto_if_eq EventScript_SetupRivalOnMachBikeGfxIdDawn
    compare VAR_RESULT, STYLE_DAWN
    goto_if_eq EventScript_SetupRivalOnMachBikeGfxIdLucas
    compare VAR_RESULT, STYLE_HILBERT
    goto_if_eq EventScript_SetupRivalOnMachBikeGfxIdHilda
    compare VAR_RESULT, STYLE_HILDA
    goto_if_eq EventScript_SetupRivalOnMachBikeGfxIdHilbert
@     compare VAR_RESULT, STYLE_NATE
@    goto_if_eq EventScript_SetupRivalOnMachBikeGfxIdRosa
@    compare VAR_RESULT, STYLE_ROSA
@    goto_if_eq EventScript_SetupRivalOnMachBikeGfxIdNate
@    compare VAR_RESULT, STYLE_CALEM
@    goto_if_eq EventScript_SetupRivalOnMachBikeGfxIdSerena
@    compare VAR_RESULT, STYLE_SERENA
@    goto_if_eq EventScript_SetupRivalOnMachBikeGfxIdCalem
@    compare VAR_RESULT, STYLE_ELIO
@    goto_if_eq EventScript_SetupRivalOnMachBikeGfxIdSelene
@    compare VAR_RESULT, STYLE_SELENE
@    goto_if_eq EventScript_SetupRivalOnMachBikeGfxIdElio
@    compare VAR_RESULT, STYLE_VICTOR
@    goto_if_eq EventScript_SetupRivalOnMachBikeGfxIdGloria
@    compare VAR_RESULT, STYLE_GLORIA
@    goto_if_eq EventScript_SetupRivalOnMachBikeGfxIdVictor
@    compare VAR_RESULT, STYLE_FLORIAN
@    goto_if_eq EventScript_SetupRivalOnMachBikeGfxIdJuliana
@    compare VAR_RESULT, STYLE_JULIANA
@    goto_if_eq EventScript_SetupRivalOnMachBikeGfxIdFlorian

    checkplayerstyle
    compare VAR_RESULT, STYLE_BRENDAN
    goto_if_eq EventScript_SetupRivalOnAcroBikeGfxIdMay
    compare VAR_RESULT, STYLE_MAY
    goto_if_eq EventScript_SetupRivalOnAcroBikeGfxIdBrendan
    compare VAR_RESULT, STYLE_RED
    goto_if_eq EventScript_SetupRivalOnAcroBikeGfxIdLeaf
    compare VAR_RESULT, STYLE_LEAF
    goto_if_eq EventScript_SetupRivalOnAcroBikeGfxIdRed
    compare VAR_RESULT, STYLE_ETHAN
    goto_if_eq EventScript_SetupRivalOnAcroBikeGfxIdLyra
    compare VAR_RESULT, STYLE_LYRA
    goto_if_eq EventScript_SetupRivalOnAcroBikeGfxIdEthan
    compare VAR_RESULT, STYLE_LUCAS
    goto_if_eq EventScript_SetupRivalOnAcroBikeGfxIdDawn
    compare VAR_RESULT, STYLE_DAWN
    goto_if_eq EventScript_SetupRivalOnAcroBikeGfxIdLucas
    compare VAR_RESULT, STYLE_HILBERT
    goto_if_eq EventScript_SetupRivalOnAcroBikeGfxIdHilda
    compare VAR_RESULT, STYLE_HILDA
    goto_if_eq EventScript_SetupRivalOnAcroBikeGfxIdHilbert
@     compare VAR_RESULT, STYLE_NATE
@    goto_if_eq EventScript_SetupRivalOnAcroBikeGfxIdRosa
@    compare VAR_RESULT, STYLE_ROSA
@    goto_if_eq EventScript_SetupRivalOnAcroBikeGfxIdNate
@    compare VAR_RESULT, STYLE_CALEM
@    goto_if_eq EventScript_SetupRivalOnAcroBikeGfxIdSerena
@    compare VAR_RESULT, STYLE_SERENA
@    goto_if_eq EventScript_SetupRivalOnAcroBikeGfxIdCalem
@    compare VAR_RESULT, STYLE_ELIO
@    goto_if_eq EventScript_SetupRivalOnAcroBikeGfxIdSelene
@    compare VAR_RESULT, STYLE_SELENE
@    goto_if_eq EventScript_SetupRivalOnAcroBikeGfxIdElio
@    compare VAR_RESULT, STYLE_VICTOR
@    goto_if_eq EventScript_SetupRivalOnAcroBikeGfxIdGloria
@    compare VAR_RESULT, STYLE_GLORIA
@    goto_if_eq EventScript_SetupRivalOnAcroBikeGfxIdVictor
@    compare VAR_RESULT, STYLE_FLORIAN
@    goto_if_eq EventScript_SetupRivalOnAcroBikeGfxIdJuliana
@    compare VAR_RESULT, STYLE_JULIANA
@    goto_if_eq EventScript_SetupRivalOnAcroBikeGfxIdFlorian

end

EventScript_SetupRivalOnMachBikeGfxIdMay::
    setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RIVAL_MAY_MACH_BIKE
    return

EventScript_SetupRivalOnMachBikeGfxIdBrendan::
    setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RIVAL_BRENDAN_MACH_BIKE
    return

EventScript_SetupRivalOnMachBikeGfxIdRed::
    setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RIVAL_RED_MACH_BIKE
    return

EventScript_SetupRivalOnMachBikeGfxIdLeaf::
    setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RIVAL_LEAF_MACH_BIKE
    return

EventScript_SetupRivalOnMachBikeGfxIdEthan::
    setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RIVAL_ETHAN_MACH_BIKE
    return

EventScript_SetupRivalOnMachBikeGfxIdLyra::
    setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RIVAL_LYRA_MACH_BIKE
    return

EventScript_SetupRivalOnMachBikeGfxIdLucas::
    setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RIVAL_LUCAS_MACH_BIKE
    return

EventScript_SetupRivalOnMachBikeGfxIdDawn::
    setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RIVAL_DAWN_MACH_BIKE
    return

EventScript_SetupRivalOnMachBikeGfxIdHilbert::
    setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RIVAL_HILBERT_MACH_BIKE
    return

EventScript_SetupRivalOnMachBikeGfxIdHilda::
    setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RIVAL_HILDA_MACH_BIKE
    return

EventScript_SetupRivalOnMachBikeGfxIdNate::
    setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RIVAL_NATE_MACH_BIKE
    return

EventScript_SetupRivalOnMachBikeGfxIdRosa::
    setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RIVAL_ROSA_MACH_BIKE
    return

EventScript_SetupRivalOnMachBikeGfxIdCalem::
    setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RIVAL_CALEM_MACH_BIKE
    return

EventScript_SetupRivalOnMachBikeGfxIdSerena::
    setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RIVAL_SERENA_MACH_BIKE
    return

EventScript_SetupRivalOnMachBikeGfxIdElio::
    setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RIVAL_ELIO_MACH_BIKE
    return

EventScript_SetupRivalOnMachBikeGfxIdSelene::
    setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RIVAL_SELENE_MACH_BIKE
    return

EventScript_SetupRivalOnMachBikeGfxIdVictor::
    setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RIVAL_VICTOR_MACH_BIKE
    return

EventScript_SetupRivalOnMachBikeGfxIdGloria::
    setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RIVAL_GLORIA_MACH_BIKE
    return

EventScript_SetupRivalOnMachBikeGfxIdFlorian::
    setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RIVAL_FLORIAN_MACH_BIKE
    return

EventScript_SetupRivalOnMachBikeGfxIdJuliana::
    setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RIVAL_JULIANA_MACH_BIKE
    return

EventScript_SetupRivalOnAcroBikeGfxIdMay::
    setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RIVAL_MAY_ACRO_BIKE
    return

EventScript_SetupRivalOnAcroBikeGfxIdBrendan::
    setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RIVAL_BRENDAN_ACRO_BIKE
    return

EventScript_SetupRivalOnAcroBikeGfxIdRed::
    setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RIVAL_RED_ACRO_BIKE
    return

EventScript_SetupRivalOnAcroBikeGfxIdLeaf::
    setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RIVAL_LEAF_ACRO_BIKE
    return

EventScript_SetupRivalOnAcroBikeGfxIdEthan::
    setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RIVAL_ETHAN_ACRO_BIKE
    return

EventScript_SetupRivalOnAcroBikeGfxIdLyra::
    setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RIVAL_LYRA_ACRO_BIKE
    return

EventScript_SetupRivalOnAcroBikeGfxIdLucas::
    setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RIVAL_LUCAS_ACRO_BIKE
    return

EventScript_SetupRivalOnAcroBikeGfxIdDawn::
    setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RIVAL_DAWN_ACRO_BIKE
    return

EventScript_SetupRivalOnAcroBikeGfxIdHilbert::
    setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RIVAL_HILBERT_ACRO_BIKE
    return

EventScript_SetupRivalOnAcroBikeGfxIdHilda::
    setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RIVAL_HILDA_ACRO_BIKE
    return

EventScript_SetupRivalOnAcroBikeGfxIdNate::
    setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RIVAL_NATE_ACRO_BIKE
    return

EventScript_SetupRivalOnAcroBikeGfxIdRosa::
    setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RIVAL_ROSA_ACRO_BIKE
    return

EventScript_SetupRivalOnAcroBikeGfxIdCalem::
    setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RIVAL_CALEM_ACRO_BIKE
    return

EventScript_SetupRivalOnAcroBikeGfxIdSerena::
    setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RIVAL_SERENA_ACRO_BIKE
    return

EventScript_SetupRivalOnAcroBikeGfxIdElio::
    setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RIVAL_ELIO_ACRO_BIKE
    return

EventScript_SetupRivalOnAcroBikeGfxIdSelene::
    setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RIVAL_SELENE_ACRO_BIKE
    return

EventScript_SetupRivalOnAcroBikeGfxIdVictor::
    setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RIVAL_VICTOR_ACRO_BIKE
    return

EventScript_SetupRivalOnAcroBikeGfxIdGloria::
    setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RIVAL_GLORIA_ACRO_BIKE
    return

EventScript_SetupRivalOnAcroBikeGfxIdFlorian::
    setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RIVAL_FLORIAN_ACRO_BIKE
    return

EventScript_SetupRivalOnAcroBikeGfxIdJuliana::
    setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RIVAL_JULIANA_ACRO_BIKE
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
@     compare VAR_RESULT, STYLE_NATE
@    goto_if_eq EventScript_PlayMayMusic
@    compare VAR_RESULT, STYLE_ROSA
@    goto_if_eq EventScript_PlayBrendanMusic
@    compare VAR_RESULT, STYLE_CALEM
@    goto_if_eq EventScript_PlayMayMusic
@    compare VAR_RESULT, STYLE_SERENA
@    goto_if_eq EventScript_PlayBrendanMusic
@    compare VAR_RESULT, STYLE_ELIO
@    goto_if_eq EventScript_PlayMayMusic
@    compare VAR_RESULT, STYLE_SELENE
@    goto_if_eq EventScript_PlayBrendanMusic
@    compare VAR_RESULT, STYLE_VICTOR
@    goto_if_eq EventScript_PlayMayMusic
@    compare VAR_RESULT, STYLE_GLORIA
@    goto_if_eq EventScript_PlayBrendanMusic
@    compare VAR_RESULT, STYLE_FLORIAN
@    goto_if_eq EventScript_PlayMayMusic
@    compare VAR_RESULT, STYLE_JULIANA
@    goto_if_eq EventScript_PlayBrendanMusic

end

EventScript_PlayMayMusic::
    playbgm MUS_ENCOUNTER_MAY, TRUE
    return

EventScript_PlayBrendanMusic::
    playbgm MUS_ENCOUNTER_BRENDAN, TRUE
    return

Common_EventScript_SetupRivalGfxId_FromPlayerStyle::
    checkplayerstyle
    compare VAR_RESULT, STYLE_BRENDAN
    goto_if_eq EventScript_SetupRivalGfxIdMay_Switch
    compare VAR_RESULT, STYLE_RED
    goto_if_eq EventScript_SetupRivalGfxIdLeaf_Switch
    compare VAR_RESULT, STYLE_MAY
    goto_if_eq EventScript_SetupRivalGfxIdBrendan_Switch
    compare VAR_RESULT, STYLE_LEAF
    goto_if_eq EventScript_SetupRivalGfxIdRed_Switch
    compare VAR_RESULT, STYLE_ETHAN
    goto_if_eq EventScript_SetupRivalGfxIdLyra_Switch
    compare VAR_RESULT, STYLE_LYRA
    goto_if_eq EventScript_SetupRivalGfxIdEthan_Switch
    compare VAR_RESULT, STYLE_LUCAS
    goto_if_eq EventScript_SetupRivalGfxIdDawn_Switch
    compare VAR_RESULT, STYLE_DAWN
    goto_if_eq EventScript_SetupRivalGfxIdLucas_Switch
    compare VAR_RESULT, STYLE_HILBERT
    goto_if_eq EventScript_SetupRivalGfxIdHilda_Switch
    compare VAR_RESULT, STYLE_HILDA
    goto_if_eq EventScript_SetupRivalGfxIdHilbert_Switch
@     compare VAR_RESULT, STYLE_NATE
@    goto_if_eq EventScript_SetupRivalGfxIdRosa_Switch
@    compare VAR_RESULT, STYLE_ROSA
@    goto_if_eq EventScript_SetupRivalGfxIdNate_Switch
@    compare VAR_RESULT, STYLE_CALEM
@    goto_if_eq EventScript_SetupRivalGfxIdSerena_Switch
@    compare VAR_RESULT, STYLE_SERENA
@    goto_if_eq EventScript_SetupRivalGfxIdCalem_Switch
@    compare VAR_RESULT, STYLE_ELIO
@    goto_if_eq EventScript_SetupRivalGfxIdSelene_Switch
@    compare VAR_RESULT, STYLE_SELENE
@    goto_if_eq EventScript_SetupRivalGfxIdElio_Switch
@    compare VAR_RESULT, STYLE_VICTOR
@    goto_if_eq EventScript_SetupRivalGfxIdGloria_Switch
@    compare VAR_RESULT, STYLE_GLORIA
@    goto_if_eq EventScript_SetupRivalGfxIdVictor_Switch
@    compare VAR_RESULT, STYLE_FLORIAN
@    goto_if_eq EventScript_SetupRivalGfxIdJuliana_Switch
@    compare VAR_RESULT, STYLE_JULIANA
@    goto_if_eq EventScript_SetupRivalGfxIdFlorian_Switch
    end

EventScript_SetupRivalGfxIdMay_Switch::
    setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RIVAL_MAY_NORMAL
    return

EventScript_SetupRivalGfxIdBrendan_Switch::
    setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RIVAL_BRENDAN_NORMAL
    return

EventScript_SetupRivalGfxIdRed_Switch::
    setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RIVAL_RED
    return

EventScript_SetupRivalGfxIdLeaf_Switch::
    setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RIVAL_LEAF
    return

EventScript_SetupRivalGfxIdEthan_Switch::
    setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RIVAL_ETHAN
    return

EventScript_SetupRivalGfxIdLyra_Switch::
    setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RIVAL_LYRA
    return

EventScript_SetupRivalGfxIdLucas_Switch::
    setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RIVAL_LUCAS
    return

EventScript_SetupRivalGfxIdDawn_Switch::
    setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RIVAL_DAWN
    return

EventScript_SetupRivalGfxIdHilbert_Switch::
    setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RIVAL_HILBERT
    return

EventScript_SetupRivalGfxIdHilda_Switch::
    setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RIVAL_HILDA
    return

EventScript_SetupRivalGfxIdNate_Switch::
    setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RIVAL_NATE
    return

EventScript_SetupRivalGfxIdRosa_Switch::
    setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RIVAL_ROSA
    return

EventScript_SetupRivalGfxIdCalem_Switch::
    setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RIVAL_CALEM
    return

EventScript_SetupRivalGfxIdSerena_Switch::
    setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RIVAL_SERENA
    return

EventScript_SetupRivalGfxIdElio_Switch::
    setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RIVAL_ELIO
    return

EventScript_SetupRivalGfxIdSelene_Switch::
    setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RIVAL_SELENE
    return

EventScript_SetupRivalGfxIdVictor_Switch::
    setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RIVAL_VICTOR
    return

EventScript_SetupRivalGfxIdGloria_Switch::
    setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RIVAL_GLORIA
    return

EventScript_SetupRivalGfxIdFlorian_Switch::
    setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RIVAL_FLORIAN
    return

EventScript_SetupRivalGfxIdJuliana_Switch::
    setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RIVAL_JULIANA
    return
