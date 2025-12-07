MeteorFalls_1F_1R_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, MeteorFalls_1F_1R_OnLoad
	.byte 0

MeteorFalls_1F_1R_OnLoad:
	call_if_set FLAG_SYS_GAME_CLEAR, MeteorFalls_1F_1R_EventScript_OpenStevensCave
	end

MeteorFalls_1F_1R_EventScript_OpenStevensCave::
	setmetatile 4, 1, METATILE_MeteorFalls_CaveEntrance_Top, TRUE
	setmetatile 3, 2, METATILE_MeteorFalls_CaveEntrance_Left, TRUE
	setmetatile 4, 2, METATILE_MeteorFalls_CaveEntrance_Bottom, FALSE
	setmetatile 5, 2, METATILE_MeteorFalls_CaveEntrance_Right, TRUE
	return

MeteorFalls_1F_1R_EventScript_MagmaStealsMeteoriteScene::
	lockall
	playbgm MUS_ENCOUNTER_MAGMA, FALSE
	applymovement LOCALID_PLAYER, Common_Movement_FaceDown
	waitmovement 0
	delay 30
	applymovement LOCALID_METEOR_FALLS_MAGMA_GRUNT_1, Common_Movement_WalkInPlaceDown
	waitmovement 0
	msgbox MeteorFalls_1F_1R_Text_WithThisMeteorite, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_METEOR_FALLS_MAGMA_GRUNT_1, Common_Movement_WalkInPlaceFasterUp
	applymovement LOCALID_METEOR_FALLS_MAGMA_GRUNT_2, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_METEOR_FALLS_MAGMA_GRUNT_1, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_METEOR_FALLS_MAGMA_GRUNT_1, Common_Movement_Delay48
	waitmovement 0
	msgbox MeteorFalls_1F_1R_Text_DontExpectMercyFromMagma, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_METEOR_FALLS_MAGMA_GRUNT_1, MeteorFalls_1F_1R_Movement_MagmaGruntApproachPlayer
	waitmovement 0
	msgbox MeteorFalls_1F_1R_Text_HoldItRightThereMagma, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	applymovement LOCALID_METEOR_FALLS_MAGMA_GRUNT_1, Common_Movement_WalkInPlaceFasterLeft
	applymovement LOCALID_METEOR_FALLS_MAGMA_GRUNT_2, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	addobject LOCALID_METEOR_FALLS_ARCHIE
	addobject LOCALID_METEOR_FALLS_AQUA_GRUNT_1
	addobject LOCALID_METEOR_FALLS_AQUA_GRUNT_2
	playbgm MUS_ENCOUNTER_AQUA, FALSE
	applymovement LOCALID_METEOR_FALLS_ARCHIE, MeteorFalls_1F_1R_Movement_ArchieArrive
	applymovement LOCALID_METEOR_FALLS_AQUA_GRUNT_1, MeteorFalls_1F_1R_Movement_AquaGrunt1Arrive
	applymovement LOCALID_METEOR_FALLS_AQUA_GRUNT_2, MeteorFalls_1F_1R_Movement_AquaGrunt2Arrive
	waitmovement 0
	applymovement LOCALID_METEOR_FALLS_MAGMA_GRUNT_1, Common_Movement_WalkInPlaceFasterLeft
	applymovement LOCALID_METEOR_FALLS_MAGMA_GRUNT_2, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox MeteorFalls_1F_1R_Text_BeSeeingYouTeamAqua, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, MeteorFalls_1F_1R_Movement_PushPlayerOutOfWay
	applymovement LOCALID_METEOR_FALLS_MAGMA_GRUNT_1, MeteorFalls_1F_1R_Movement_MagmaGrunt1Exit
	applymovement LOCALID_METEOR_FALLS_MAGMA_GRUNT_2, MeteorFalls_1F_1R_Movement_MagmaGrunt2Exit
	waitmovement 0
	removeobject LOCALID_METEOR_FALLS_MAGMA_GRUNT_1
	removeobject LOCALID_METEOR_FALLS_MAGMA_GRUNT_2
	applymovement LOCALID_METEOR_FALLS_ARCHIE, MeteorFalls_1F_1R_Movement_ArchieApproachPlayer
	waitmovement 0
	msgbox MeteorFalls_1F_1R_Text_ArchieSeenYouBefore, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_METEOR_FALLS_AQUA_GRUNT_1, MeteorFalls_1F_1R_Movement_AquaGrunt1ApproachArchie
	applymovement LOCALID_METEOR_FALLS_AQUA_GRUNT_2, MeteorFalls_1F_1R_Movement_AquaGrunt2ApproachArchie
	waitmovement 0
	msgbox MeteorFalls_1F_1R_Text_BossWeShouldChaseMagma, MSGBOX_DEFAULT
	applymovement LOCALID_METEOR_FALLS_ARCHIE, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox MeteorFalls_1F_1R_Text_ArchieYesNoTellingWhatMagmaWillDo, MSGBOX_DEFAULT
	applymovement LOCALID_METEOR_FALLS_ARCHIE, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox MeteorFalls_1F_1R_Text_ArchieFarewell, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_METEOR_FALLS_ARCHIE, MeteorFalls_1F_1R_Movement_ArchieExit
	applymovement LOCALID_METEOR_FALLS_AQUA_GRUNT_1, MeteorFalls_1F_1R_Movement_AquaGrunt1Exit
	applymovement LOCALID_METEOR_FALLS_AQUA_GRUNT_2, MeteorFalls_1F_1R_Movement_AquaGrunt2Exit
	waitmovement 0
	fadedefaultbgm
	removeobject LOCALID_METEOR_FALLS_ARCHIE
	removeobject LOCALID_METEOR_FALLS_AQUA_GRUNT_1
	removeobject LOCALID_METEOR_FALLS_AQUA_GRUNT_2
	setflag FLAG_HIDE_ROUTE_112_TEAM_MAGMA
	setflag FLAG_MET_ARCHIE_METEOR_FALLS
	setflag FLAG_HIDE_FALLARBOR_TOWN_BATTLE_TENT_SCOTT
	setvar VAR_METEOR_FALLS_STATE, 1
	releaseall
	end

MeteorFalls_1F_1R_Movement_MagmaGruntApproachPlayer:
	walk_right
	walk_right
	walk_in_place_faster_up
	step_end

MeteorFalls_1F_1R_Movement_MagmaGrunt1Exit:
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

MeteorFalls_1F_1R_Movement_MagmaGrunt2Exit:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

MeteorFalls_1F_1R_Movement_ArchieArrive:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MeteorFalls_1F_1R_Movement_AquaGrunt1Arrive:
	delay_16
	delay_16
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MeteorFalls_1F_1R_Movement_AquaGrunt2Arrive:
	delay_16
	delay_16
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MeteorFalls_1F_1R_Movement_ArchieExit:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MeteorFalls_1F_1R_Movement_ArchieApproachPlayer:
	walk_right
	walk_right
	walk_up
	walk_up
	walk_in_place_faster_left
	step_end

MeteorFalls_1F_1R_Movement_AquaGrunt1Exit:
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MeteorFalls_1F_1R_Movement_AquaGrunt1ApproachArchie:
	walk_right
	walk_right
	walk_right
	walk_in_place_faster_up
	step_end

MeteorFalls_1F_1R_Movement_AquaGrunt2Exit:
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MeteorFalls_1F_1R_Movement_AquaGrunt2ApproachArchie:
	walk_right
	walk_right
	walk_right
	walk_in_place_faster_up
	step_end

MeteorFalls_1F_1R_Movement_PushPlayerOutOfWay:
	walk_in_place_faster_down
	delay_4
	walk_in_place_faster_right
	lock_facing_direction
	walk_left
	unlock_facing_direction
	face_right
	step_end

MeteorFalls_1F_1R_EventScript_ProfCozmo::
	lock
	faceplayer
	goto_if_set FLAG_MET_PROF_COZMO, MeteorFalls_1F_1R_EventScript_MetCozmo
	setflag FLAG_MET_PROF_COZMO
	msgbox MeteorFalls_1F_1R_Text_MeetProfCozmo, MSGBOX_DEFAULT
	release
	end

MeteorFalls_1F_1R_EventScript_MetCozmo::
	msgbox MeteorFalls_1F_1R_Text_WhatsTeamMagmaDoingAtMtChimney, MSGBOX_DEFAULT
	release
	end

MeteorFalls_1F_1R_Text_WithThisMeteorite:
	.string "{COLOR RED}Hehehe!\p"
	.string "Mit diesem METEORIT wird dieses Ding\n"
	.string "am SCHLOTBERG…{COLOR WHITE}$"

MeteorFalls_1F_1R_Text_DontExpectMercyFromMagma:
	.string "{COLOR RED}Heh?\p"
	.string "Ich weiß nicht, wer du bist, aber wenn\n"
	.string "du dich {COLOR LIGHT_RED}TEAM MAGMA{COLOR RED} in den Weg stellst,\n"
	.string "erwarte keine Gnade!{COLOR WHITE}$"

MeteorFalls_1F_1R_Text_HoldItRightThereMagma:
	.string "{COLOR BLUE}Halt! {COLOR LIGHT_RED}TEAM MAGMA{COLOR BLUE}, kein Schritt weiter!\p"
	.string "Ihr täuscht euch, wenn ihr glaubt,\n"
	.string "die Welt nach eurem Willen formen zu\n"
	.string "können!{COLOR WHITE}$"

MeteorFalls_1F_1R_Text_BeSeeingYouTeamAqua:
	.string "{COLOR RED}Hehehe!\n"
	.string "Sogar {COLOR LIGHT_BLUE}TEAM AQUA{COLOR RED} mischt jetzt mit!\p"
	.string "Aber es ist zu lästig, sich mit euch\n"
	.string "allen herumzuschlagen…\p"
	.string "Ist auch egal!\p"
	.string "Wir haben den METEORIT, also auf\n"
	.string "zum SCHLOTBERG!\p"
	.string "Hehehe! Man sieht sich, ihr\n"
	.string "{COLOR LIGHT_BLUE}TEAM AQUA{COLOR RED}-Trottel!{COLOR WHITE}$"

MeteorFalls_1F_1R_Text_ArchieSeenYouBefore:
	.string "{COLOR BLUE}ARCHIE: Habe ich dich nicht schon einmal\n"
	.string "gesehen? Im MUSEUM von GRAPHITPORT?\p"
	.string "Ah, dein Name ist also {PLAYER}.{COLOR BLUE}\p"
	.string "Damals hielt ich dich für einen\n"
	.string "Handlanger von {COLOR LIGHT_RED}TEAM MAGMA{COLOR BLUE}.\p"
	.string "Hm… du bist ein seltsamer Trainer.\p"
	.string "{COLOR LIGHT_RED}TEAM MAGMA{COLOR BLUE} ist eine gefährliche Gruppe\n"
	.string "fanatischer Extremisten.\p"
	.string "Sie richten Verwüstung an und behaupten,\n"
	.string "damit die Landmasse zu vergrößern.\p"
	.string "Sie sind die Rivalen von uns,\n"
	.string "dem meerliebenden {COLOR LIGHT_BLUE}TEAM AQUA{COLOR BLUE}!{COLOR WHITE}$"

MeteorFalls_1F_1R_Text_BossWeShouldChaseMagma:
	.string "{COLOR BLUE}BOSS, wir sollten {COLOR LIGHT_RED}TEAM MAGMA{COLOR BLUE}\n"
	.string "sofort verfolgen…{COLOR WHITE}$"

MeteorFalls_1F_1R_Text_ArchieYesNoTellingWhatMagmaWillDo:
	.string "{COLOR BLUE}ARCHIE: Ja, natürlich müssen wir das!\n"
	.string "Wir müssen uns beeilen.\p"
	.string "Es ist nicht abzusehen, was\n"
	.string "{COLOR LIGHT_RED}TEAM MAGMA{COLOR BLUE} am SCHLOTBERG vorhat!{COLOR WHITE}$"

MeteorFalls_1F_1R_Text_ArchieFarewell:
	.string "{COLOR BLUE}ARCHIE: {PLAYER}, du solltest ebenfalls\n"
	.string "ein Auge auf {COLOR LIGHT_RED}TEAM MAGMA{COLOR BLUE} haben.\p"
	.string "Leb wohl!{COLOR WHITE}$"

MeteorFalls_1F_1R_Text_MeetProfCozmo:
	.string "I-Ich bin COZMO…\n"
	.string "Ich bin ein PROFESSOR…\p"
	.string "{COLOR LIGHT_RED}TEAM MAGMA{COLOR DARK_GRAY} hat mich gebeten, sie\n"
	.string "zu den METEORFÄLLEN zu führen…\p"
	.string "Aber sie haben mich hereingelegt.\n"
	.string "Sie haben mir sogar den METEORIT\n"
	.string "abgenommen…\p"
	.string "Und dann tauchte eine andere, ähnliche\n"
	.string "Gruppe auf - {COLOR LIGHT_BLUE}TEAM AQUA{COLOR DARK_GRAY}.\p"
	.string "Danach… ich verstehe nichts mehr.\p"
	.string "Aber {COLOR LIGHT_RED}TEAM MAGMA{COLOR DARK_GRAY}…\p"
	.string "Was haben sie mit diesem METEORIT\n"
	.string "am SCHLOTBERG vor?$"

MeteorFalls_1F_1R_Text_WhatsTeamMagmaDoingAtMtChimney:
	.string "PROF. COZMO: Aber {COLOR LIGHT_RED}TEAM MAGMA{COLOR DARK_GRAY}…\p"
	.string "Was haben sie mit diesem METEORIT\n"
	.string "am SCHLOTBERG vor?$"

