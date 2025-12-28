Route114_FossilManiacsTunnel_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route114_FossilManiacsTunnel_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, Route114_FossilManiacsTunnel_OnLoad
	.byte 0

Route114_FossilManiacsTunnel_OnTransition:
	call_if_set FLAG_SYS_GAME_CLEAR, Route114_FossilManiacsTunnel_EventScript_MoveFossilManiac
	end

Route114_FossilManiacsTunnel_EventScript_MoveFossilManiac::
	setobjectxyperm LOCALID_FOSSIL_MANIAC, 6, 5
	setobjectmovementtype LOCALID_FOSSIL_MANIAC, MOVEMENT_TYPE_FACE_DOWN
	return

Route114_FossilManiacsTunnel_OnLoad:
	call_if_unset FLAG_SYS_GAME_CLEAR, Route114_FossilManiacsTunnel_EventScript_CloseDesertUnderpass
	end

Route114_FossilManiacsTunnel_EventScript_CloseDesertUnderpass::
	setmetatile 6, 1, METATILE_Fallarbor_RedRockWall, TRUE
	setmetatile 6, 2, METATILE_Fallarbor_RedRockWall, TRUE
	return

Route114_FossilManiacsTunnel_EventScript_ManiacMentionCaveIn::
	lockall
	applymovement LOCALID_FOSSIL_MANIAC, Common_Movement_WalkInPlaceFasterUp
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox Route114_FossilManiacsTunnel_Text_NotSafeThatWay, MSGBOX_DEFAULT
	setvar VAR_FOSSIL_MANIAC_STATE, 2
	releaseall
	end

Route114_FossilManiacsTunnel_EventScript_FossilManiac::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_REVIVED_FOSSIL_MON, Route114_FossilManiacsTunnel_EventScript_PlayerRevivedFossil
	checkitem ITEM_ROOT_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, Route114_FossilManiacsTunnel_EventScript_PlayerHasFossil
	checkitem ITEM_CLAW_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, Route114_FossilManiacsTunnel_EventScript_PlayerHasFossil
	msgbox Route114_FossilManiacsTunnel_Text_LookInDesertForFossils, MSGBOX_DEFAULT
	release
	end

Route114_FossilManiacsTunnel_EventScript_PlayerHasFossil::
	msgbox Route114_FossilManiacsTunnel_Text_DevonCorpRevivingFossils, MSGBOX_DEFAULT
	release
	end

Route114_FossilManiacsTunnel_EventScript_PlayerRevivedFossil::
	msgbox Route114_FossilManiacsTunnel_Text_FossilsAreWonderful, MSGBOX_DEFAULT
	release
	end

Route114_FossilManiacsTunnel_Text_LookInDesertForFossils::
	.string "Ich bin der FOSSIL-MANIAC… Ich bin\n"
	.string "ein ziemlich krasser Typ, der Steine\l"
	.string "viel geiler findet als Menschen…\p"
	.string "Was glotzt du so? Willst’n Fossil?\p"
	.string "Vergiss es! Alles, was hier im Dreck\n"
	.string "liegt, gehört MIR! Verpiss dich!\p"
	.string "Wenn du unbedingt im Sand spielen\n"
	.string "willst, geh in die Wüste und such dir\l"
	.string "deinen eigenen Müll. Mit viel Glück\l"
	.string "findest du da was, du Schnorrer…$"

Route114_FossilManiacsTunnel_Text_DevonCorpRevivingFossils::
	.string "Du hast echt ein FOSSIL gefunden?\n"
	.string "Was für ’n unverschämtes Glück…\p"
	.string "Was hast du jetzt damit vor, Kleiner?\p"
	.string "Ich hab gehört, die Bonzen von DEVON\n"
	.string "versuchen, aus den Steinen POKéMON\l"
	.string "rauszupressen…\p"
	.string "Ich liebe meine FOSSILIEN so sehr, ich\n"
	.string "würde sie niemals so einer Tortur\l"
	.string "aussetzen. Die bleiben schön im Regal!$"

Route114_FossilManiacsTunnel_Text_FossilsAreWonderful::
	.string "FOSSILIEN sind so… sexy…\n"
	.string "Einfach nur geiler, alter Dreck…$"

Route114_FossilManiacsTunnel_Text_NotSafeThatWay::
	.string "Oh…\n"
	.string "Pass auf, wo du hinstolperst…\p"
	.string "Ich hab hier ein bisschen zu wild\n"
	.string "rumgegraben und die Wand gesprengt…\p"
	.string "Jetzt klafft da dieses riesige Loch…\p"
	.string "Ich war da nicht drin. Sieht nicht so\n"
	.string "aus, als gäbe es da was Wertvolles.\l"
	.string "Also zisch ab und nerv wen anders!$"
