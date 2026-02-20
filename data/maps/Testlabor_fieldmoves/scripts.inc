Testlabor_fieldmoves_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Testlabor_fieldmoves_OnTransition
	.byte 0

Testlabor_fieldmoves_OnTransition:
	call Common_EventScript_SetupRivalGfxId
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_RIVAL_LYRA_FIELD_MOVE
	setvar VAR_OBJ_GFX_ID_2, OBJ_EVENT_GFX_RIVAL_ETHAN_FIELD_MOVE
	setvar VAR_OBJ_GFX_ID_3, OBJ_EVENT_GFX_RIVAL_LUCAS_FIELD_MOVE
	setvar VAR_OBJ_GFX_ID_4, OBJ_EVENT_GFX_RIVAL_DAWN_FIELD_MOVE
	setvar VAR_OBJ_GFX_ID_5, OBJ_EVENT_GFX_RIVAL_HILBERT_FIELD_MOVE
	setvar VAR_OBJ_GFX_ID_6, OBJ_EVENT_GFX_RIVAL_HILDA_FIELD_MOVE
	setvar VAR_OBJ_GFX_ID_7, OBJ_EVENT_GFX_RIVAL_LYRA
	setvar VAR_OBJ_GFX_ID_8, OBJ_EVENT_GFX_RIVAL_ETHAN
	setvar VAR_OBJ_GFX_ID_9, OBJ_EVENT_GFX_RIVAL_LUCAS
	setvar VAR_OBJ_GFX_ID_A, OBJ_EVENT_GFX_RIVAL_DAWN
	setvar VAR_OBJ_GFX_ID_B, OBJ_EVENT_GFX_RIVAL_HILBERT
	setvar VAR_OBJ_GFX_ID_C, OBJ_EVENT_GFX_RIVAL_HILDA
	setvar VAR_OBJ_GFX_ID_D, OBJ_EVENT_GFX_RIVAL_LYRA_MACH_BIKE
	setvar VAR_OBJ_GFX_ID_E, OBJ_EVENT_GFX_RIVAL_ETHAN_ACRO_BIKE
	setvar VAR_OBJ_GFX_ID_F, OBJ_EVENT_GFX_RIVAL_LUCAS_MACH_BIKE
	end

Testlabor_fieldmoves_EventScript_GalarBea::
	lock
	faceplayer
	msgbox Testlabor_fieldmoves_Text_Hier, MSGBOX_DEFAULT
	giveitem ITEM_HM01
	giveitem ITEM_HM03
	giveitem ITEM_HM04
	giveitem ITEM_HM06
	giveitem ITEM_HM08
	giveitem ITEM_MACH_BIKE
	giveitem ITEM_ACRO_BIKE
	givemon SPECIES_ZIGZAGOON, 1
	givemon SPECIES_TENTACOOL, 1
	release
	end

Testlabor_fieldmoves_EventScript_RivalVar0::
	lock
	faceplayer
	msgbox Testlabor_fieldmoves_Text_RivalVar0, MSGBOX_DEFAULT
	release
	end

Testlabor_fieldmoves_EventScript_RivalVar1::
	lock
	faceplayer
	msgbox Testlabor_fieldmoves_Text_RivalVar1_LyraFM, MSGBOX_DEFAULT
	release
	end

Testlabor_fieldmoves_EventScript_RivalVar2::
	lock
	faceplayer
	msgbox Testlabor_fieldmoves_Text_RivalVar2_EthanFM, MSGBOX_DEFAULT
	release
	end

Testlabor_fieldmoves_EventScript_RivalVar3::
	lock
	faceplayer
	msgbox Testlabor_fieldmoves_Text_RivalVar3_LucasFM, MSGBOX_DEFAULT
	release
	end

Testlabor_fieldmoves_EventScript_RivalVar4::
	lock
	faceplayer
	msgbox Testlabor_fieldmoves_Text_RivalVar4_DawnFM, MSGBOX_DEFAULT
	release
	end

Testlabor_fieldmoves_EventScript_RivalVar5::
	lock
	faceplayer
	msgbox Testlabor_fieldmoves_Text_RivalVar5_HilbertFM, MSGBOX_DEFAULT
	release
	end

Testlabor_fieldmoves_EventScript_RivalVar6::
	lock
	faceplayer
	msgbox Testlabor_fieldmoves_Text_RivalVar6_HildaFM, MSGBOX_DEFAULT
	release
	end

Testlabor_fieldmoves_EventScript_RivalVar7::
	lock
	faceplayer
	msgbox Testlabor_fieldmoves_Text_RivalVar7_LyraNormal, MSGBOX_DEFAULT
	release
	end

Testlabor_fieldmoves_EventScript_RivalVar8::
	lock
	faceplayer
	msgbox Testlabor_fieldmoves_Text_RivalVar8_EthanNormal, MSGBOX_DEFAULT
	release
	end

Testlabor_fieldmoves_EventScript_RivalVar9::
	lock
	faceplayer
	msgbox Testlabor_fieldmoves_Text_RivalVar9_LucasNormal, MSGBOX_DEFAULT
	release
	end

Testlabor_fieldmoves_EventScript_RivalVarA::
	lock
	faceplayer
	msgbox Testlabor_fieldmoves_Text_RivalVarA_DawnNormal, MSGBOX_DEFAULT
	release
	end

Testlabor_fieldmoves_EventScript_RivalVarB::
	lock
	faceplayer
	msgbox Testlabor_fieldmoves_Text_RivalVarB_HilbertNormal, MSGBOX_DEFAULT
	release
	end

Testlabor_fieldmoves_EventScript_RivalVarC::
	lock
	faceplayer
	msgbox Testlabor_fieldmoves_Text_RivalVarC_HildaNormal, MSGBOX_DEFAULT
	release
	end

Testlabor_fieldmoves_EventScript_RivalVarD::
	lock
	faceplayer
	msgbox Testlabor_fieldmoves_Text_RivalVarD_LyraMach, MSGBOX_DEFAULT
	release
	end

Testlabor_fieldmoves_EventScript_RivalVarE::
	lock
	faceplayer
	msgbox Testlabor_fieldmoves_Text_RivalVarE_EthanAcro, MSGBOX_DEFAULT
	release
	end

Testlabor_fieldmoves_EventScript_RivalVarF::
	lock
	faceplayer
	msgbox Testlabor_fieldmoves_Text_RivalVarF_LucasMach, MSGBOX_DEFAULT
	release
	end

Testlabor_fieldmoves_Text_Hier:
	.string "Test-Setup geladen.\nAlle Variablen gesetzt.$"

Testlabor_fieldmoves_Text_RivalVar0:
	.string "VAR 0 (Standard):\nIch bin der dynamische Rival.$"

Testlabor_fieldmoves_Text_RivalVar1_LyraFM:
	.string "VAR 1:\nIch sollte LYRA (Field Move) sein.$"

Testlabor_fieldmoves_Text_RivalVar2_EthanFM:
	.string "VAR 2:\nIch sollte ETHAN (Field Move) sein.$"

Testlabor_fieldmoves_Text_RivalVar3_LucasFM:
	.string "VAR 3:\nIch sollte LUCAS (Field Move) sein.$"

Testlabor_fieldmoves_Text_RivalVar4_DawnFM:
	.string "VAR 4:\nIch sollte DAWN (Field Move) sein.$"

Testlabor_fieldmoves_Text_RivalVar5_HilbertFM:
	.string "VAR 5:\nIch sollte HILBERT (Field Move) sein.$"

Testlabor_fieldmoves_Text_RivalVar6_HildaFM:
	.string "VAR 6:\nIch sollte HILDA (Field Move) sein.$"

Testlabor_fieldmoves_Text_RivalVar7_LyraNormal:
	.string "VAR 7:\nIch sollte LYRA (Normal) sein.$"

Testlabor_fieldmoves_Text_RivalVar8_EthanNormal:
	.string "VAR 8:\nIch sollte ETHAN (Normal) sein.$"

Testlabor_fieldmoves_Text_RivalVar9_LucasNormal:
	.string "VAR 9:\nIch sollte LUCAS (Normal) sein.$"

Testlabor_fieldmoves_Text_RivalVarA_DawnNormal:
	.string "VAR A:\nIch sollte DAWN (Normal) sein.$"

Testlabor_fieldmoves_Text_RivalVarB_HilbertNormal:
	.string "VAR B:\nIch sollte HILBERT (Normal) sein.$"

Testlabor_fieldmoves_Text_RivalVarC_HildaNormal:
	.string "VAR C:\nIch sollte HILDA (Normal) sein.$"

Testlabor_fieldmoves_Text_RivalVarD_LyraMach:
	.string "VAR D:\nIch sollte LYRA (Eilrad) sein.$"

Testlabor_fieldmoves_Text_RivalVarE_EthanAcro:
	.string "VAR E:\nIch sollte ETHAN (Kunstrad) sein.$"

Testlabor_fieldmoves_Text_RivalVarF_LucasMach:
	.string "VAR F:\nIch sollte LUCAS (Eilrad) sein.$"

