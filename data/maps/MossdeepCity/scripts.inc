MossdeepCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MossdeepCity_OnTransition
	.byte 0

MossdeepCity_OnTransition:
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_1
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_2
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_3
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_4
	call_if_set FLAG_SYS_WEATHER_CTRL, Common_EventScript_SetAbnormalWeather
	end

MossdeepCity_EventScript_PokefanF::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM_DIVE, MossdeepCity_EventScript_PokefanFMagmaGone
	msgbox MossdeepCity_Text_SpaceCenterReceivedLetter, MSGBOX_DEFAULT
	release
	end

MossdeepCity_EventScript_PokefanFMagmaGone::
	msgbox MossdeepCity_Text_SpaceCenterLaunchingRockets, MSGBOX_DEFAULT
	release
	end

MossdeepCity_EventScript_Sailor::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM_DIVE, MossdeepCity_EventScript_SailorMagmaGone
	msgbox MossdeepCity_Text_MossdeepTargetedByMagma, MSGBOX_DEFAULT
	release
	end

MossdeepCity_EventScript_SailorMagmaGone::
	msgbox MossdeepCity_Text_FeelReliefOnLand, MSGBOX_DEFAULT
	release
	end

MossdeepCity_EventScript_NinjaBoy::
	msgbox MossdeepCity_Text_WailmerWatching, MSGBOX_NPC
	end

MossdeepCity_EventScript_ExpertM::
	msgbox MossdeepCity_Text_LifeNeedsSeaToLive, MSGBOX_NPC
	end

MossdeepCity_EventScript_Girl::
	msgbox MossdeepCity_Text_NiceIfWorldCoveredByFlowers, MSGBOX_NPC
	end

MossdeepCity_EventScript_Woman::
	lock
	faceplayer
	goto_if_set FLAG_CAUGHT_JIRACHI, MossdeepCity_EventScript_WomanJirachiCaught
	goto_if_set FLAG_MOSSDEEP_JIRACHI_REVEALED, MossdeepCity_EventScript_WomanJirachiRevealed
	msgbox MossdeepCity_Text_SpecialSpaceCenterRock, MSGBOX_DEFAULT
	release
	end

MossdeepCity_EventScript_WomanJirachiRevealed::
	msgbox MossdeepCity_Text_SpecialSpaceCenterRockAfterReveal, MSGBOX_DEFAULT
	release
	end

MossdeepCity_EventScript_WomanJirachiCaught::
	msgbox MossdeepCity_Text_SpecialSpaceCenterRockCaught, MSGBOX_DEFAULT
	release
	end

MossdeepCity_EventScript_WhiteRock::
	msgbox MossdeepCity_Text_ItsAWhiteRock, MSGBOX_SIGN
	end

MossdeepCity_EventScript_CrackedRock::
	lockall
	goto_if_set FLAG_CAUGHT_JIRACHI, MossdeepCity_EventScript_CrackedRockCaughtAlready
	goto_if_set FLAG_DEFEATED_JIRACHI_ROCK_ENCOUNTER, MossdeepCity_EventScript_CrackedRockEmpty
	msgbox MossdeepCity_Text_RockHint, MSGBOX_DEFAULT
	closemessage
	specialvar VAR_RESULT, FindFieldMoveMonForJirachiRock
	goto_if_eq VAR_RESULT, PARTY_SIZE, MossdeepCity_EventScript_CrackedRockNothingHappens
	bufferpartymonnick STR_VAR_1, VAR_RESULT
	msgbox MossdeepCity_Text_MetagrossUsesRockSmash, MSGBOX_DEFAULT
	closemessage
	setvar VAR_0x8004, 1
	setvar VAR_0x8005, 1
	setvar VAR_0x8006, 8
	setvar VAR_0x8007, 4
	special ShakeCamera
	waitstate
	fadescreen FADE_TO_WHITE
	delay 20
	playse SE_M_ROCK_THROW
	setflag FLAG_MOSSDEEP_JIRACHI_REVEALED
	fadescreen FADE_FROM_WHITE
	msgbox MossdeepCity_Text_RockHasCracked, MSGBOX_DEFAULT
	closemessage
	setwildbattle SPECIES_JIRACHI, 30
	special ForceShinyScriptedWildMon
	dowildbattle
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, MossdeepCity_EventScript_JirachiCaughtNow
	msgbox MossdeepCity_Text_JirachiEscaped, MSGBOX_DEFAULT
	special InitJirachiRoamer
	setflag FLAG_DEFEATED_JIRACHI_ROCK_ENCOUNTER
	releaseall
	end

MossdeepCity_EventScript_CrackedRockNothingHappens::
	msgbox MossdeepCity_Text_RockNothingHappens, MSGBOX_DEFAULT
	releaseall
	end

MossdeepCity_EventScript_JirachiCaughtNow::
	setflag FLAG_CAUGHT_JIRACHI
	msgbox MossdeepCity_Text_JirachiCaughtNow, MSGBOX_DEFAULT
	releaseall
	end

MossdeepCity_EventScript_CrackedRockEmpty::
	msgbox MossdeepCity_Text_JirachiRockEmpty, MSGBOX_DEFAULT
	releaseall
	end

MossdeepCity_EventScript_CrackedRockCaughtAlready::
	msgbox MossdeepCity_Text_JirachiRockCaughtAlready, MSGBOX_DEFAULT
	releaseall
	end

MossdeepCity_EventScript_GymSign::
	msgbox MossdeepCity_Text_GymSign, MSGBOX_SIGN
	end

MossdeepCity_EventScript_CitySign::
	msgbox MossdeepCity_Text_CitySign, MSGBOX_SIGN
	end

MossdeepCity_EventScript_SpaceCenterSign::
	msgbox MossdeepCity_Text_SpaceCenterSign, MSGBOX_SIGN
	end

MossdeepCity_EventScript_VisitedMossdeep::
	setflag FLAG_VISITED_MOSSDEEP_CITY
	setvar VAR_TEMP_1, 1
	end

MossdeepCity_EventScript_TeamMagmaEnterSpaceCenter::
	lockall
	applymovement LOCALID_MOSSDEEP_MAXIE, MossdeepCity_Movement_MaxieGestureToSpaceCenter
	waitmovement 0
	applymovement LOCALID_MOSSDEEP_GRUNT_1, MossdeepCity_Movement_GruntFaceSpaceCenter
	applymovement LOCALID_MOSSDEEP_GRUNT_2, MossdeepCity_Movement_GruntFaceSpaceCenter
	applymovement LOCALID_MOSSDEEP_GRUNT_3, MossdeepCity_Movement_GruntFaceSpaceCenter
	applymovement LOCALID_MOSSDEEP_GRUNT_4, MossdeepCity_Movement_GruntFaceSpaceCenter
	waitmovement 0
	applymovement LOCALID_MOSSDEEP_MAXIE, MossdeepCity_Movement_MaxieEnterSpaceCenter
	applymovement LOCALID_MOSSDEEP_GRUNT_1, MossdeepCity_Movement_Grunt1EnterSpaceCenter
	applymovement LOCALID_MOSSDEEP_GRUNT_2, MossdeepCity_Movement_Grunt2EnterSpaceCenter
	applymovement LOCALID_MOSSDEEP_GRUNT_3, MossdeepCity_Movement_Grunt3EnterSpaceCenter
	applymovement LOCALID_MOSSDEEP_GRUNT_4, MossdeepCity_Movement_Grunt4EnterSpaceCenter
	waitmovement 0
	removeobject LOCALID_MOSSDEEP_MAXIE
	removeobject LOCALID_MOSSDEEP_GRUNT_1
	removeobject LOCALID_MOSSDEEP_GRUNT_2
	removeobject LOCALID_MOSSDEEP_GRUNT_3
	removeobject LOCALID_MOSSDEEP_GRUNT_4
	delay 30
	setvar VAR_MOSSDEEP_CITY_STATE, 2
	setflag FLAG_HIDE_MOSSDEEP_CITY_TEAM_MAGMA
	releaseall
	end

MossdeepCity_Movement_MaxieGestureToSpaceCenter:
	delay_16
	face_right
	delay_16
	delay_16
	delay_16
	delay_16
	face_left
	delay_16
	delay_16
	step_end

MossdeepCity_Movement_GruntFaceSpaceCenter:
	face_right
	delay_16
	delay_16
	delay_16
	step_end

MossdeepCity_Movement_MaxieEnterSpaceCenter:
	walk_down
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MossdeepCity_Movement_Grunt1EnterSpaceCenter:
	delay_16
	delay_8
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MossdeepCity_Movement_Grunt2EnterSpaceCenter:
	delay_16
	delay_8
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MossdeepCity_Movement_Grunt3EnterSpaceCenter:
	delay_16
	delay_8
	walk_down
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MossdeepCity_Movement_Grunt4EnterSpaceCenter:
	delay_16
	delay_8
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MossdeepCity_EventScript_Man::
	lock
	faceplayer
	msgbox MossdeepCity_Text_SurfExhilarating, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

MossdeepCity_EventScript_KingsRockBoy::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_KINGS_ROCK, MossdeepCity_EventScript_ReceivedKingsRock
	msgbox MossdeepCity_Text_WantKingsRockStevenGaveMe, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MossdeepCity_EventScript_DeclineKingsRock
	msgbox MossdeepCity_Text_YouCanKeepIt, MSGBOX_DEFAULT
	giveitem ITEM_KINGS_ROCK
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_KINGS_ROCK
	release
	end

MossdeepCity_EventScript_ReceivedKingsRock::
	msgbox MossdeepCity_Text_StevensHouseOverThere, MSGBOX_DEFAULT
	release
	end

MossdeepCity_EventScript_DeclineKingsRock::
	msgbox MossdeepCity_Text_WhatToDoWithWeirdRock, MSGBOX_DEFAULT
	release
	end

MossdeepCity_EventScript_BlackBelt::
	msgbox MossdeepCity_Text_SootopolisNewGymLeader, MSGBOX_NPC
	end

MossdeepCity_EventScript_Scott::
	lock
	faceplayer
	msgbox MossdeepCity_Text_ScottSomethingWrongWithTown, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_FACING, DIR_NORTH, MossdeepCity_EventScript_ScottExitNorth
	call_if_eq VAR_FACING, DIR_EAST, MossdeepCity_EventScript_ScottExitEast
	addvar VAR_SCOTT_STATE, 1
	removeobject LOCALID_MOSSDEEP_SCOTT
	release
	end

MossdeepCity_EventScript_ScottExitNorth::
	applymovement LOCALID_PLAYER, MossdeepCity_Movement_PlayerWatchScottExit
	applymovement LOCALID_MOSSDEEP_SCOTT, MossdeepCity_Movement_ScottExitNorth
	waitmovement 0
	return

MossdeepCity_EventScript_ScottExitEast::
	applymovement LOCALID_PLAYER, MossdeepCity_Movement_PlayerWatchScottExit
	applymovement LOCALID_MOSSDEEP_SCOTT, MossdeepCity_Movement_ScottExitEast
	waitmovement 0
	return

MossdeepCity_Movement_PlayerWatchScottExit:
	delay_16
	delay_16
	walk_in_place_faster_left
	step_end

MossdeepCity_Movement_ScottExitNorth:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

MossdeepCity_Movement_ScottExitEast:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

MossdeepCity_Text_WantKingsRockStevenGaveMe:
	.string "Ich hab das Teil von TROY bekommen,\n"
	.string "aber keine Ahnung, was der Schrott soll.\p"
	.string "Soll wohl ein KING-STEIN sein.\n"
	.string "Willst du den Müll haben?$"

MossdeepCity_Text_YouCanKeepIt:
	.string "Warum willst du das Ding überhaupt?\n"
	.string "Du bist echt schräg drauf.\p"
	.string "Behalt ihn ruhig, aber sag TROY nix\n"
	.string "davon. Der kriegt sonst 'nen Heulkrampf.$"

MossdeepCity_Text_StevensHouseOverThere:
	.string "TROYS Bude ist direkt da drüben!$"

MossdeepCity_Text_WhatToDoWithWeirdRock:
	.string "Sag ich doch! Was zur Hölle soll man\n"
	.string "mit so einem komischen Stein anfangen?$"

MossdeepCity_Text_WailmerWatching:
	.string "Hier um MOOSBACH rum kann man wilde\n"
	.string "WAILMER beobachten.\p"
	.string "Das nennt man... äh...\n"
	.string "Wie hieß der Scheiß noch mal...\p"
	.string "WAI, WAI, WAI...\p"
	.string "WAILMER-Watching! Krass, oder?$"

MossdeepCity_Text_SpaceCenterReceivedLetter:
	.string "Das SPACE CENTER ballert hier ständig\n"
	.string "riesige Raketen ins All.\p"
	.string "Aber gerade herrscht da drin totale\n"
	.string "Panik wegen so einem Drohbrief.$"

MossdeepCity_Text_SpaceCenterLaunchingRockets:
	.string "Das SPACE CENTER auf der Insel ballert\n"
	.string "hier ständig fette Raketen ins All.$"

MossdeepCity_Text_MossdeepTargetedByMagma:
	.string "Ein Kumpel von der Marine meinte,\n"
	.string "TEAM AQUA hätte sich in SEEGRASULB\l"
	.string "breitgemacht.\p"
	.string "Er meinte auch, dass irgendwer kam und\n"
	.string "mit denen den Boden aufgewischt hat!\p"
	.string "Aber jetzt hat TEAM MAGMA ein Auge auf\n"
	.string "unser MOOSBACH geworfen.\p"
	.string "Wenn du wissen willst, was die Spinner\n"
	.string "planen, geh zum SPACE CENTER.$"

MossdeepCity_Text_FeelReliefOnLand:
	.string "Ich bin Seemann, also ist mir das Meer\n"
	.string "natürlich wichtiger als alles andere.\p"
	.string "Aber weißt du was? Wenn ich nach 'nem\n"
	.string "langen Trip wieder festen Boden unter\l"
	.string "den Füßen hab, bin ich echt froh.$"

MossdeepCity_Text_NiceIfWorldCoveredByFlowers:
	.string "Wär das nicht geil?\p"
	.string "Wenn die ganze Welt so mit Pflanzen\n"
	.string "und Blumen zugeballert wäre wie hier?$"

MossdeepCity_Text_LifeNeedsSeaToLive:
	.string "Alles Leben braucht das Meer, auch wenn\n"
	.string "wir uns an Land breitgemacht haben.\p"
	.string "Am Ende werden wir eh alle zu Erde\n"
	.string "und landen wieder im Dreck.\p"
	.string "Land und Meer sind halt eins.\n"
	.string "Guck dir die Küste an, dann checkst du's.$"

MossdeepCity_Text_SurfExhilarating:
	.string "Mit 'nem Schiff fahren ist ja ganz nett.\p"
	.string "Aber mit POKéMON und SURFER über\n"
	.string "die Wellen zu brettern...\p"
	.string "Das ist der wahre Kick! Gibst du mir\n"
	.string "recht, kleiner Hobby-Trainer?$"

MossdeepCity_Text_SpecialSpaceCenterRock:
	.string "Der Stein hier ist den Nerds vom\n"
	.string "SPACE CENTER heilig.\p"
	.string "Die haben den hier hingestellt, damit\n"
	.string "ihre Raketen nicht abstürzen.\p"
	.string "Woran glaubst du eigentlich?\n"
	.string "Wünschst du dir was bei Sternschnuppen?\p"
	.string "Ich nehm lieber Wunschzettel. Da hat\n"
	.string "man wenigstens was in der Hand.$"

MossdeepCity_Text_ItsAWhiteRock:
	.string "Ein makellos weißer Stein.\n"
	.string "Er wirkt seltsam... warm.$"

MossdeepCity_Text_SpecialSpaceCenterRockAfterReveal:
	.string "Hast du das Beben eben gespürt?!\p"
	.string "Der heilige Stein hat auf einmal\n"
	.string "einen Riss bekommen!\p"
	.string "Die Nerds vom SPACE CENTER drehen\n"
	.string "völlig durch deswegen.\p"
	.string "Manche behaupten, sie hätten etwas\n"
	.string "Goldenes durch die Luft fliegen sehen...$"

MossdeepCity_Text_SpecialSpaceCenterRockCaught:
	.string "Du hast es also wirklich gefangen,\n"
	.string "was aus dem Stein kam?\p"
	.string "Vielleicht sollte ich mir doch keine\n"
	.string "Wunschzettel mehr schreiben.\p"
	.string "Sternschnuppen scheinen ja doch\n"
	.string "manchmal wahr zu werden.$"

MossdeepCity_Text_RockHint:
	.string "Der Stein fühlt sich warm an und\n"
	.string "scheint auf etwas zu warten.\p"
	.string "Nur die geballte Kraft eines ganz\n"
	.string "besonderen, glänzenden Stahlkolosses\l"
	.string "könnte ihn wohl aufbrechen...$"

MossdeepCity_Text_RockNothingHappens:
	.string "Nichts passiert.\n"
	.string "Der Stein bleibt unversehrt.$"

MossdeepCity_Text_MetagrossUsesRockSmash:
	.string "{STR_VAR_1} setzt ZERTRÜMMERER ein!$"

MossdeepCity_Text_RockHasCracked:
	.string "Als der Blitz verklingt, siehst du\n"
	.string "einen tiefen Riss im weißen Stein.\p"
	.string "Ein schwaches, goldenes Leuchten\n"
	.string "dringt aus dem Inneren hervor...$"

MossdeepCity_Text_JirachiEscaped:
	.string "Jirachi schlüpft aus deinem Griff\n"
	.string "und schießt in den Himmel davon!\p"
	.string "Es scheint, als würde es jetzt\n"
	.string "irgendwo in der Gegend umherstreifen...$"

MossdeepCity_Text_JirachiCaughtNow:
	.string "Jirachi kuschelt sich zufrieden in\n"
	.string "seinen Ball.\p"
	.string "Es fühlt sich an, als hätte sich\n"
	.string "gerade dein größter Wunsch erfüllt.$"

MossdeepCity_Text_JirachiRockEmpty:
	.string "Der Riss im Stein ist leer.\n"
	.string "Was auch immer hier war, es ist\l"
	.string "längst über alle Berge.$"

MossdeepCity_Text_JirachiRockCaughtAlready:
	.string "Der Riss im Stein ist leer und\n"
	.string "still.\p"
	.string "Aber irgendwie fühlt es sich hier\n"
	.string "trotzdem warm und friedlich an.$"

MossdeepCity_Text_GymSign:
	.string "POKéMON ARENA von MOOSBACH CITY\n"
	.string "LEITER: TATE & LIZA\p"
	.string "“Die mystische Doppel-Klatsche!”$"

MossdeepCity_Text_CitySign:
	.string "MOOSBACH CITY\n"
	.string "“Slogan: Liebt eure POKéMON, verdammt!”$"

MossdeepCity_Text_SpaceCenterSign:
	.string "MOOSBACH SPACE CENTER\n"
	.string "“Näher kommst du dem Weltraum nicht.”$"

MossdeepCity_Text_ScottSomethingWrongWithTown:
	.string "SCOTT: {PLAYER}{KUN}, alles fit?\n"
	.string "Bei mir läuft's bestens!\p"
	.string "Ich hab gehört, die ARENALEITER hier\n"
	.string "sollen echt was draufhaben. Wollte\l"
	.string "mir das Spektakel mal ansehen.\p"
	.string "Aber irgendwas stimmt hier nicht.\p"
	.string "Alle labern nur über Drohbriefe und\n"
	.string "das SPACE CENTER...\p"
	.string "Naja, geht mich zum Glück nix an.$"

MossdeepCity_Text_SootopolisNewGymLeader:
	.string "Ahh... herrlich, wie die Wellen mir\n"
	.string "über die Füße schwappen...\p"
	.string "Wo wir gerade bei Wellen sind: Kennst\n"
	.string "du die Inselstadt XENEROVILLE?\p"
	.string "Die Arena dort hat wohl 'nen neuen\n"
	.string "Typen als Leiter bekommen.\p"
	.string "Man sagt, der neue LEITER war früher\n"
	.string "mal der Mentor von WASSILI.$"

