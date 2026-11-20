@ MtPyre_6F_2 - Verborgene Gruft im Pyroberg (Darkrai-Event)
@ Raetsel: Die vier Graeber im Kreuz um die Mitte der unteren Halle
@ in der Reihenfolge Westen (0,10) -> Sueden (6,12) -> Osten (12,10) -> Norden (6,8)
@ beruehren. Danach oeffnet sich in der Nische hinter dem Nordgrab ein
@ schwarzes Loch und Darkrai erscheint.
@ Darkrai kommt bei jedem neuen Betreten wieder, bis es gefangen wurde
@ (FLAG_CAUGHT_DARKRAI). Nach Sieg, Flucht oder Wegrennen: "Darkrai ist geflohen…".
@ Metatiles: Grab 0x2EE, erwachtes Grab 0x3D7.

MtPyre_6F_2_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MtPyre_6F_2_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, MtPyre_6F_2_OnResume
	.byte 0

MtPyre_6F_2_OnTransition:
	setvar VAR_TEMP_1, 0
	setvar VAR_TEMP_2, 0
	setflag FLAG_TEMP_13
	setflag FLAG_TEMP_14
	call MtPyre_6F_2_EventScript_ResetGraves
	end

MtPyre_6F_2_OnResume:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, MtPyre_6F_2_EventScript_TryRemoveDarkrai
	end

MtPyre_6F_2_EventScript_TryRemoveDarkrai::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject LOCALID_MT_PYRE_6F_2_DARKRAI
	removeobject LOCALID_MT_PYRE_6F_2_BLACK_HOLE
	return

MtPyre_6F_2_EventScript_ResetGraves::
	setmetatile 0, 10, 0x2EE, TRUE
	setmetatile 6, 12, 0x2EE, TRUE
	setmetatile 12, 10, 0x2EE, TRUE
	setmetatile 6, 8, 0x2EE, TRUE
	return

@ -------------------------------------------------------------------------
@ Gedenktafel (oben) und der Mann in der Gruft
@ -------------------------------------------------------------------------
MtPyre_6F_2_EventScript_Tablet::
	lockall
	goto_if_set FLAG_CAUGHT_DARKRAI, MtPyre_6F_2_EventScript_TabletCaught
	msgbox MtPyre_6F_2_Text_Riddle, MSGBOX_DEFAULT
	releaseall
	end

MtPyre_6F_2_EventScript_TabletCaught::
	msgbox MtPyre_6F_2_Text_TabletCaught, MSGBOX_DEFAULT
	releaseall
	end

MtPyre_6F_2_EventScript_DevilMan::
	lock
	faceplayer
	goto_if_set FLAG_CAUGHT_DARKRAI, MtPyre_6F_2_EventScript_DevilManCaught
	msgbox MtPyre_6F_2_Text_DevilMan, MSGBOX_DEFAULT
	release
	end

MtPyre_6F_2_EventScript_DevilManCaught::
	msgbox MtPyre_6F_2_Text_DevilManCaught, MSGBOX_DEFAULT
	release
	end

@ -------------------------------------------------------------------------
@ Graeber: Reihenfolge West (1), Sued (2), Ost (3), Nord (4)
@ -------------------------------------------------------------------------
MtPyre_6F_2_EventScript_GraveWest::
	lockall
	call MtPyre_6F_2_EventScript_CheckGraveInactive
	goto_if_eq VAR_TEMP_1, 0, MtPyre_6F_2_EventScript_ActivateWest
	goto MtPyre_6F_2_EventScript_WrongOrder

MtPyre_6F_2_EventScript_ActivateWest::
	setvar VAR_TEMP_1, 1
	setmetatile 0, 10, 0x3D7, TRUE
	special DrawWholeMapView
	playse SE_PIN
	msgbox MtPyre_6F_2_Text_WestAwakens, MSGBOX_DEFAULT
	releaseall
	end

MtPyre_6F_2_EventScript_GraveSouth::
	lockall
	call MtPyre_6F_2_EventScript_CheckGraveInactive
	goto_if_eq VAR_TEMP_1, 1, MtPyre_6F_2_EventScript_ActivateSouth
	goto MtPyre_6F_2_EventScript_WrongOrder

MtPyre_6F_2_EventScript_ActivateSouth::
	setvar VAR_TEMP_1, 2
	setmetatile 6, 12, 0x3D7, TRUE
	special DrawWholeMapView
	playse SE_PIN
	msgbox MtPyre_6F_2_Text_SouthAwakens, MSGBOX_DEFAULT
	releaseall
	end

MtPyre_6F_2_EventScript_GraveEast::
	lockall
	call MtPyre_6F_2_EventScript_CheckGraveInactive
	goto_if_eq VAR_TEMP_1, 2, MtPyre_6F_2_EventScript_ActivateEast
	goto MtPyre_6F_2_EventScript_WrongOrder

MtPyre_6F_2_EventScript_ActivateEast::
	setvar VAR_TEMP_1, 3
	setmetatile 12, 10, 0x3D7, TRUE
	special DrawWholeMapView
	playse SE_PIN
	msgbox MtPyre_6F_2_Text_EastAwakens, MSGBOX_DEFAULT
	releaseall
	end

MtPyre_6F_2_EventScript_GraveNorth::
	lockall
	call MtPyre_6F_2_EventScript_CheckGraveInactive
	goto_if_eq VAR_TEMP_1, 3, MtPyre_6F_2_EventScript_ActivateNorth
	goto MtPyre_6F_2_EventScript_WrongOrder

MtPyre_6F_2_EventScript_ActivateNorth::
	setvar VAR_TEMP_1, 4
	setmetatile 6, 8, 0x3D7, TRUE
	special DrawWholeMapView
	playse SE_PIN
	msgbox MtPyre_6F_2_Text_NorthAwakens, MSGBOX_DEFAULT
	goto MtPyre_6F_2_EventScript_BlackHoleCutscene

@ Wenn das Raetsel schon geloest, der Besuch vorbei oder Darkrai gefangen ist.
MtPyre_6F_2_EventScript_CheckGraveInactive::
	goto_if_set FLAG_CAUGHT_DARKRAI, MtPyre_6F_2_EventScript_GraveQuiet
	goto_if_eq VAR_TEMP_2, 1, MtPyre_6F_2_EventScript_GraveQuiet
	goto_if_eq VAR_TEMP_1, 4, MtPyre_6F_2_EventScript_GraveQuiet
	return

MtPyre_6F_2_EventScript_GraveQuiet::
	msgbox MtPyre_6F_2_Text_GraveQuiet, MSGBOX_DEFAULT
	releaseall
	end

MtPyre_6F_2_EventScript_WrongOrder::
	playse SE_FAILURE
	waitse
	setvar VAR_0x8004, 1
	setvar VAR_0x8005, 1
	setvar VAR_0x8006, 8
	setvar VAR_0x8007, 5
	special ShakeCamera
	waitstate
	msgbox MtPyre_6F_2_Text_WrongOrder, MSGBOX_DEFAULT
	setvar VAR_TEMP_1, 0
	call MtPyre_6F_2_EventScript_ResetGraves
	special DrawWholeMapView
	releaseall
	end

@ -------------------------------------------------------------------------
@ Schwarzes Loch, Darkrai erscheint, Kampf
@ -------------------------------------------------------------------------
MtPyre_6F_2_EventScript_BlackHoleCutscene::
	delay 20
	msgbox MtPyre_6F_2_Text_VeilTears, MSGBOX_DEFAULT
	closemessage
	fadeoutbgm 1
	@ Violetter Albtraum-Schein breitet sich vom Loch aus, der Boden bebt
	setvar VAR_RESULT, 4
	playse SE_ORB
	special DoOrbEffect
	delay 30
	playse SE_M_NIGHTMARE
	waitstate
	@ Das schwarze Loch reißt auf
	clearflag FLAG_TEMP_14
	addobject LOCALID_MT_PYRE_6F_2_BLACK_HOLE
	playse SE_M_CONFUSE_RAY
	delay 60
	@ Darkrai steht zuerst im Loch und tritt dann heraus vor das Nordgrab
	clearflag FLAG_TEMP_13
	addobject LOCALID_MT_PYRE_6F_2_DARKRAI
	delay 24
	applymovement LOCALID_MT_PYRE_6F_2_DARKRAI, MtPyre_6F_2_Movement_DarkraiEmerge
	waitmovement 0
	@ Der Ruf, dann verblasst der Schein mit einem letzten Beben
	playmoncry SPECIES_DARKRAI, CRY_MODE_ENCOUNTER
	waitmoncry
	special FadeOutOrbEffect
	waitstate
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 2
	setvar VAR_0x8006, 12
	setvar VAR_0x8007, 3
	special ShakeCamera
	waitstate
	msgbox MtPyre_6F_2_Text_DarkraiAppears, MSGBOX_DEFAULT
	closemessage
	goto MtPyre_6F_2_EventScript_StartDarkraiBattle

@ Falls Darkrai nach dem Auftritt noch angesprochen wird
MtPyre_6F_2_EventScript_Darkrai::
	lockall
	playmoncry SPECIES_DARKRAI, CRY_MODE_ENCOUNTER
	waitmoncry
	goto MtPyre_6F_2_EventScript_StartDarkraiBattle

MtPyre_6F_2_EventScript_BlackHole::
	lockall
	msgbox MtPyre_6F_2_Text_BlackHoleHum, MSGBOX_DEFAULT
	releaseall
	end

MtPyre_6F_2_EventScript_StartDarkraiBattle::
	setvar VAR_LAST_TALKED, LOCALID_MT_PYRE_6F_2_DARKRAI
	setwildbattle SPECIES_DARKRAI, 50
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, MtPyre_6F_2_EventScript_CaughtDarkrai
	goto MtPyre_6F_2_EventScript_DarkraiFled

MtPyre_6F_2_EventScript_CaughtDarkrai::
	setflag FLAG_CAUGHT_DARKRAI
	setflag FLAG_TEMP_13
	setflag FLAG_TEMP_14
	removeobject LOCALID_MT_PYRE_6F_2_DARKRAI
	removeobject LOCALID_MT_PYRE_6F_2_BLACK_HOLE
	releaseall
	end

MtPyre_6F_2_EventScript_DarkraiFled::
	fadescreenswapbuffers FADE_TO_BLACK
	setflag FLAG_TEMP_13
	setflag FLAG_TEMP_14
	removeobject LOCALID_MT_PYRE_6F_2_DARKRAI
	removeobject LOCALID_MT_PYRE_6F_2_BLACK_HOLE
	fadescreenswapbuffers FADE_FROM_BLACK
	setvar VAR_TEMP_2, 1
	msgbox MtPyre_6F_2_Text_DarkraiFled, MSGBOX_DEFAULT
	releaseall
	end

MtPyre_6F_2_Movement_DarkraiEmerge:
	walk_slow_down
	step_end

@ -------------------------------------------------------------------------
@ Texte
@ -------------------------------------------------------------------------
MtPyre_6F_2_Text_Riddle:
	.string "Eine alte Gedenktafel. Die Schrift\n"
	.string "scheint im Dunkeln zu atmen.\p"
	.string "“Vier Gräber bewachen die Mitte\n"
	.string "der unteren Halle.\p"
	.string "Wenn die Sonne im Westen stirbt,\n"
	.string "legt sich der Mittagsschatten\l"
	.string "über den Süden.\p"
	.string "Ein trügerisches Licht erwacht\n"
	.string "im Osten, doch die tiefste Nacht\l"
	.string "wartet im Norden.\p"
	.string "Dann reißt der Schleier…”$"

MtPyre_6F_2_Text_TabletCaught:
	.string "Die Schrift auf der Tafel ist\n"
	.string "verblasst. Der Albtraum ist vorbei.$"

MtPyre_6F_2_Text_DevilMan:
	.string "Hehehe… Du hast den Weg in die\n"
	.string "verborgene Gruft gefunden.\p"
	.string "Hier unten schläft ein Albtraum.\n"
	.string "Die Gräber in der Halle unter uns\l"
	.string "halten ihn gefangen.\p"
	.string "Lies die Tafel an der Wand, wenn\n"
	.string "du ihn wecken willst… Hehehe…$"

MtPyre_6F_2_Text_DevilManCaught:
	.string "Die Gruft ist still geworden…\n"
	.string "Du hast den Albtraum gebändigt.$"

MtPyre_6F_2_Text_WestAwakens:
	.string "“Hier stirbt die Sonne.”\p"
	.string "Der letzte Sonnenhauch erlischt…$"

MtPyre_6F_2_Text_SouthAwakens:
	.string "“Hier ruht der Mittagsschatten.”\p"
	.string "Ein kalter Schatten legt sich\n"
	.string "über die Gräber…$"

MtPyre_6F_2_Text_EastAwakens:
	.string "“Hier lügt das Licht.”\p"
	.string "Ein trügerisches Licht zuckt auf…\n"
	.string "und stirbt.$"

MtPyre_6F_2_Text_NorthAwakens:
	.string "“Hier wartet die tiefste Nacht.”\p"
	.string "Die Dunkelheit verschlingt\n"
	.string "den Raum…$"

MtPyre_6F_2_Text_WrongOrder:
	.string "Die Schatten verstummen…\n"
	.string "Die Gräber erlöschen.$"

MtPyre_6F_2_Text_GraveQuiet:
	.string "Das Grab bleibt still.$"

MtPyre_6F_2_Text_VeilTears:
	.string "Der Schleier reißt!\n"
	.string "Etwas reißt ein Loch in die Nacht…$"

MtPyre_6F_2_Text_DarkraiAppears:
	.string "Darkrai steigt aus dem\n"
	.string "schwarzen Loch empor!$"

MtPyre_6F_2_Text_BlackHoleHum:
	.string "Das schwarze Loch summt leise.\n"
	.string "Ein Albtraum pulsiert darin.$"

MtPyre_6F_2_Text_DarkraiFled:
	.string "Darkrai ist geflohen…$"
