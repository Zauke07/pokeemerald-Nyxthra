Common_EventScript_SetupRivalGfxId::
    checkplayerstyle
    special ShowFieldMessageVarObjGfxId0AndStyle
    compare VAR_RESULT, STYLE_BRENDAN
    goto_if_eq EventScript_SetupRivalGfxIdMay     @ Brendan → May als Rivale
    compare VAR_RESULT, STYLE_MAY
    goto_if_eq EventScript_SetupRivalGfxIdBrendan @ May → Brendan als Rivale
    compare VAR_RESULT, STYLE_RED
    goto_if_eq EventScript_SetupRivalGfxIdLeaf    @ Red → Leaf als Rivalin
    compare VAR_RESULT, STYLE_LEAF
    goto_if_eq EventScript_SetupRivalGfxIdRed     @ Leaf → Red als Rivale
    end

EventScript_SetupRivalGfxIdRed::
    setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RIVAL_RED
    special ShowFieldMessageVarObjGfxId0AndStyle
    msgbox RivalDebugText_Red, MSGBOX_SIGN
    return

EventScript_SetupRivalGfxIdLeaf::
    setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RIVAL_LEAF
    special ShowFieldMessageVarObjGfxId0AndStyle
    msgbox RivalDebugText_Leaf, MSGBOX_SIGN
    return

EventScript_SetupRivalGfxIdBrendan::
    setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RIVAL_BRENDAN_NORMAL
    special ShowFieldMessageVarObjGfxId0AndStyle
    msgbox RivalDebugText_Brendan, MSGBOX_SIGN
    return

EventScript_SetupRivalGfxIdMay::
    setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RIVAL_MAY_NORMAL
    special ShowFieldMessageVarObjGfxId0AndStyle
    msgbox RivalDebugText_May, MSGBOX_SIGN
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
    end

EventScript_SetupRivalGfxIdMay_Switch::
    setobjectgfxid LOCALID_RIVAL, OBJ_EVENT_GFX_RIVAL_MAY_NORMAL
    return

EventScript_SetupRivalGfxIdBrendan_Switch::
    setobjectgfxid LOCALID_RIVAL, OBJ_EVENT_GFX_RIVAL_BRENDAN_NORMAL
    return

EventScript_SetupRivalGfxIdRed_Switch::
    setobjectgfxid LOCALID_RIVAL, OBJ_EVENT_GFX_RIVAL_RED
    return

EventScript_SetupRivalGfxIdLeaf_Switch::
    setobjectgfxid LOCALID_RIVAL, OBJ_EVENT_GFX_RIVAL_LEAF
    return

Common_EventScript_SetupRivalOnBikeGfxId::
    checkplayerstyle
    compare VAR_RESULT, STYLE_BRENDAN
    goto_if_eq EventScript_SetupRivalOnBikeGfxIdMay
    compare VAR_RESULT, STYLE_RED
    goto_if_eq EventScript_SetupRivalOnBikeGfxIdLeaf
    compare VAR_RESULT, STYLE_MAY
    goto_if_eq EventScript_SetupRivalOnBikeGfxIdBrendan
    compare VAR_RESULT, STYLE_LEAF
    goto_if_eq EventScript_SetupRivalOnBikeGfxIdRed
    end

EventScript_SetupRivalOnBikeGfxIdMay::
    setvar VAR_OBJ_GFX_ID_3, OBJ_EVENT_GFX_RIVAL_MAY_MACH_BIKE
    return

EventScript_SetupRivalOnBikeGfxIdBrendan::
    setvar VAR_OBJ_GFX_ID_3, OBJ_EVENT_GFX_RIVAL_BRENDAN_MACH_BIKE
    return

EventScript_SetupRivalOnBikeGfxIdRed::
    setvar VAR_OBJ_GFX_ID_3, OBJ_EVENT_GFX_RIVAL_RED_MACH_BIKE
    return

EventScript_SetupRivalOnBikeGfxIdLeaf::
    setvar VAR_OBJ_GFX_ID_3, OBJ_EVENT_GFX_RIVAL_LEAF_MACH_BIKE
    return

Common_EventScript_SetupRivalMusic::
    getplayerstyle
    switch VAR_RESULT
        case STYLE_BRENDAN, Common_EventScript_PlayMayMusic
        case STYLE_RED,     Common_EventScript_PlayMayMusic
        case STYLE_MAY,     Common_EventScript_PlayBrendanMusic
        case STYLE_LEAF,    Common_EventScript_PlayBrendanMusic
    end

Common_EventScript_PlayMayMusic::
    playbgm MUS_ENCOUNTER_MAY, FALSE
    return

Common_EventScript_PlayBrendanMusic::
    playbgm MUS_ENCOUNTER_BRENDAN, FALSE
    return

@ Dieses Script wird automatisch vom Objekt beim Mapload ausgeführt
EventScript_AutoSetRivalGfxIdFromPlayerStyle::
    call Common_EventScript_SetupRivalGfxId_FromPlayerStyle
    return

RivalDebugText_Red:
    .string " Setze Red (Rivale = Leaf)$"

RivalDebugText_Leaf:
    .string " Setze Leaf (Rivale = Red)$"

RivalDebugText_Brendan:
    .string " Setze Brendan (Rivale = May)$"

RivalDebugText_May:
    .string "Setze May (Rivale = Brendan)$"
