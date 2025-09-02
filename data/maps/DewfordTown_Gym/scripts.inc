DewfordTown_Gym_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, DewfordTown_Gym_OnTransition
	.byte 0

DewfordTown_Gym_OnTransition:
	call DewfordTown_Gym_EventScript_SetFlashLevel
	end

DewfordTown_Gym_EventScript_SetFlashLevel::
	goto_if_defeated TRAINER_BRAWLY_1, DewfordTown_Gym_EventScript_SetLightsOn
	call DewfordTown_Gym_EventScript_CountTrainersDefeated
	copyvar VAR_0x8001, VAR_0x8000
	goto_if_eq VAR_0x8000, 0, DewfordTown_Gym_EventScript_SetFlashLevel7
	goto_if_eq VAR_0x8000, 1, DewfordTown_Gym_EventScript_SetFlashLevel6
	goto_if_eq VAR_0x8000, 2, DewfordTown_Gym_EventScript_SetFlashLevel5
	goto_if_eq VAR_0x8000, 3, DewfordTown_Gym_EventScript_SetFlashLevel4
	goto_if_eq VAR_0x8000, 4, DewfordTown_Gym_EventScript_SetFlashLevel3
	goto_if_eq VAR_0x8000, 5, DewfordTown_Gym_EventScript_SetFlashLevel2
	goto DewfordTown_Gym_EventScript_SetFlashLevel1

DewfordTown_Gym_EventScript_SetLightsOn::
	setflashlevel 0
	return

@ Brightest
DewfordTown_Gym_EventScript_SetFlashLevel1::
	setflashlevel 1
	return

DewfordTown_Gym_EventScript_SetFlashLevel2::
	setflashlevel 2
	return

DewfordTown_Gym_EventScript_SetFlashLevel3::
	setflashlevel 3
	return

DewfordTown_Gym_EventScript_SetFlashLevel4::
	setflashlevel 4
	return

DewfordTown_Gym_EventScript_SetFlashLevel5::
	setflashlevel 5
	return

DewfordTown_Gym_EventScript_SetFlashLevel6::
	setflashlevel 6
	return

@ Darkest
DewfordTown_Gym_EventScript_SetFlashLevel7::
	setflashlevel 7
	return

DewfordTown_Gym_EventScript_BrightenRoom::
	call DewfordTown_Gym_EventScript_CountTrainersDefeated
	nop1
	goto_if_eq VAR_0x8000, VAR_0x8001, DewfordTown_Gym_EventScript_NoLightChange
	copyvar VAR_0x8001, VAR_0x8000
	goto_if_eq VAR_0x8000, 1, DewfordTown_Gym_EventScript_AnimateFlash1Trainer
	goto_if_eq VAR_0x8000, 2, DewfordTown_Gym_EventScript_AnimateFlash2Trainers
	goto_if_eq VAR_0x8000, 3, DewfordTown_Gym_EventScript_AnimateFlash3Trainers
	goto_if_eq VAR_0x8000, 4, DewfordTown_Gym_EventScript_AnimateFlash4Trainers
	goto_if_eq VAR_0x8000, 5, DewfordTown_Gym_EventScript_AnimateFlash5Trainers
	goto_if_eq VAR_0x8000, 6, DewfordTown_Gym_EventScript_AnimateFlash6Trainers

DewfordTown_Gym_EventScript_NoLightChange::
	return

@ NOTE: A little confusingly, a larger animateflash param value is a smaller flash radius
DewfordTown_Gym_EventScript_AnimateFlash1Trainer::
	playse SE_SWITCH
	animateflash 6
	call DewfordTown_Gym_EventScript_SetFlashLevel
	return

DewfordTown_Gym_EventScript_AnimateFlash2Trainers::
	playse SE_SWITCH
	animateflash 5
	call DewfordTown_Gym_EventScript_SetFlashLevel
	return

DewfordTown_Gym_EventScript_AnimateFlash3Trainers::
	playse SE_SWITCH
	animateflash 4
	call DewfordTown_Gym_EventScript_SetFlashLevel
	return

DewfordTown_Gym_EventScript_AnimateFlash4Trainers::
	playse SE_SWITCH
	animateflash 3
	call DewfordTown_Gym_EventScript_SetFlashLevel
	return

DewfordTown_Gym_EventScript_AnimateFlash5Trainers::
	playse SE_SWITCH
	animateflash 2
	call DewfordTown_Gym_EventScript_SetFlashLevel
	return

DewfordTown_Gym_EventScript_AnimateFlash6Trainers::
	playse SE_SWITCH
	animateflash 1
	call DewfordTown_Gym_EventScript_SetFlashLevel
	return

DewfordTown_Gym_EventScript_AnimateFlashFullBrightness::
	playse SE_SWITCH
	animateflash 0
	call DewfordTown_Gym_EventScript_SetFlashLevel
	return

DewfordTown_Gym_EventScript_CountTrainersDefeated::
	setvar VAR_0x8000, 0
	goto_if_not_defeated TRAINER_TAKAO, DewfordTown_Gym_EventScript_CheckJocelyn
	addvar VAR_0x8000, 1
DewfordTown_Gym_EventScript_CheckJocelyn::
	goto_if_not_defeated TRAINER_JOCELYN, DewfordTown_Gym_EventScript_CheckLaura
	addvar VAR_0x8000, 1
DewfordTown_Gym_EventScript_CheckLaura::
	goto_if_not_defeated TRAINER_LAURA, DewfordTown_Gym_EventScript_CheckBrenden
	addvar VAR_0x8000, 1
DewfordTown_Gym_EventScript_CheckBrenden::
	goto_if_not_defeated TRAINER_BRENDEN, DewfordTown_Gym_EventScript_CheckCristian
	addvar VAR_0x8000, 1
DewfordTown_Gym_EventScript_CheckCristian::
	goto_if_not_defeated TRAINER_CRISTIAN, DewfordTown_Gym_EventScript_CheckLilith
	addvar VAR_0x8000, 1
DewfordTown_Gym_EventScript_CheckLilith::
	goto_if_not_defeated TRAINER_LILITH, DewfordTown_Gym_EventScript_StopCountingTrainers
	addvar VAR_0x8000, 1
DewfordTown_Gym_EventScript_StopCountingTrainers::
	return

DewfordTown_Gym_EventScript_Brawly::
	trainerbattle_single TRAINER_BRAWLY_1, DewfordTown_Gym_Text_BrawlyIntro, DewfordTown_Gym_Text_BrawlyDefeat, DewfordTown_Gym_EventScript_BrawlyDefeated, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, DewfordTown_Gym_EventScript_BrawlyRematch
	goto_if_unset FLAG_RECEIVED_TM_BULK_UP, DewfordTown_Gym_EventScript_GiveBulkUp2
	msgbox DewfordTown_Gym_Text_BrawlyPostBattle, MSGBOX_DEFAULT
	release
	end

DewfordTown_Gym_EventScript_BrawlyDefeated::
	call DewfordTown_Gym_EventScript_AnimateFlashFullBrightness
	message DewfordTown_Gym_Text_ReceivedKnuckleBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox DewfordTown_Gym_Text_KnuckleBadgeInfoTakeThis, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_DEWFORD_GYM
	setflag FLAG_BADGE02_GET
	addvar VAR_PETALBURG_GYM_STATE, 1
	call_if_eq VAR_PETALBURG_GYM_STATE, 6, Common_EventScript_ReadyPetalburgGymForBattle
	setvar VAR_0x8008, 2
	call Common_EventScript_SetGymTrainers
	call DewfordTown_Gym_EventScript_GiveBulkUp
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox DewfordTown_Gym_Text_RegisteredBrawly, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_BRAWLY_MATCH_CALL
	setvar VAR_ROXANNE_CALL_STEP_COUNTER, 0
	setflag FLAG_ENABLE_ROXANNE_FIRST_CALL
	release
	end

DewfordTown_Gym_EventScript_GiveBulkUp::
	giveitem ITEM_TM_BULK_UP
	goto_if_eq VAR_RESULT, 0, Common_EventScript_BagIsFull
	msgbox DewfordTown_Gym_Text_ExplainBulkUp, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_BULK_UP
	return

DewfordTown_Gym_EventScript_GiveBulkUp2:
	giveitem ITEM_TM_BULK_UP
	goto_if_eq VAR_RESULT, 0, Common_EventScript_ShowBagIsFull
	msgbox DewfordTown_Gym_Text_ExplainBulkUp, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_BULK_UP
	release
	end

DewfordTown_Gym_EventScript_BrawlyRematch::
	trainerbattle_rematch_double TRAINER_BRAWLY_1, DewfordTown_Gym_Text_BrawlyPreRematch, DewfordTown_Gym_Text_BrawlyRematchDefeat, DewfordTown_Gym_Text_BrawlyRematchNeedTwoMons
	msgbox DewfordTown_Gym_Text_BrawlyPostRematch, MSGBOX_AUTOCLOSE
	end

DewfordTown_Gym_EventScript_Takao::
	trainerbattle_single TRAINER_TAKAO, DewfordTown_Gym_Text_TakaoIntro, DewfordTown_Gym_Text_TakaoDefeat, DewfordTown_Gym_EventScript_TakaoBrightenRoom
	msgbox DewfordTown_Gym_Text_TakaoPostBattle, MSGBOX_AUTOCLOSE
	end

DewfordTown_Gym_EventScript_TakaoBrightenRoom::
	call DewfordTown_Gym_EventScript_BrightenRoom
	release
	end

DewfordTown_Gym_EventScript_Jocelyn::
	trainerbattle_single TRAINER_JOCELYN, DewfordTown_Gym_Text_JocelynIntro, DewfordTown_Gym_Text_JocelynDefeat, DewfordTown_Gym_EventScript_JocelynBrightenRoom
	msgbox DewfordTown_Gym_Text_JocelynPostBattle, MSGBOX_AUTOCLOSE
	end

DewfordTown_Gym_EventScript_JocelynBrightenRoom::
	call DewfordTown_Gym_EventScript_BrightenRoom
	release
	end

DewfordTown_Gym_EventScript_Laura::
	trainerbattle_single TRAINER_LAURA, DewfordTown_Gym_Text_LauraIntro, DewfordTown_Gym_Text_LauraDefeat, DewfordTown_Gym_EventScript_LauraBrightenRoom
	msgbox DewfordTown_Gym_Text_LauraPostBattle, MSGBOX_AUTOCLOSE
	end

DewfordTown_Gym_EventScript_LauraBrightenRoom::
	call DewfordTown_Gym_EventScript_BrightenRoom
	release
	end

DewfordTown_Gym_EventScript_Brenden::
	trainerbattle_single TRAINER_BRENDEN, DewfordTown_Gym_Text_BrendenIntro, DewfordTown_Gym_Text_BrendenDefeat, DewfordTown_Gym_EventScript_BrendenBrightenRoom
	msgbox DewfordTown_Gym_Text_BrendenPostBattle, MSGBOX_AUTOCLOSE
	end

DewfordTown_Gym_EventScript_BrendenBrightenRoom::
	call DewfordTown_Gym_EventScript_BrightenRoom
	release
	end

DewfordTown_Gym_EventScript_Cristian::
	trainerbattle_single TRAINER_CRISTIAN, DewfordTown_Gym_Text_CristianIntro, DewfordTown_Gym_Text_CristianDefeat, DewfordTown_Gym_EventScript_CristianBrightenRoom
	msgbox DewfordTown_Gym_Text_CristianPostBattle, MSGBOX_AUTOCLOSE
	end

DewfordTown_Gym_EventScript_CristianBrightenRoom::
	call DewfordTown_Gym_EventScript_BrightenRoom
	release
	end

DewfordTown_Gym_EventScript_Lilith::
	trainerbattle_single TRAINER_LILITH, DewfordTown_Gym_Text_LilithIntro, DewfordTown_Gym_Text_LilithDefeat, DewfordTown_Gym_EventScript_LilithBrightenRoom
	msgbox DewfordTown_Gym_Text_LilithPostBattle, MSGBOX_AUTOCLOSE
	end

DewfordTown_Gym_EventScript_LilithBrightenRoom::
	call DewfordTown_Gym_EventScript_BrightenRoom
	release
	end

DewfordTown_Gym_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_DEWFORD_GYM, DewfordTown_Gym_EventScript_GymGuidePostVictory
	msgbox DewfordTown_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

DewfordTown_Gym_EventScript_GymGuidePostVictory::
	msgbox DewfordTown_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

DewfordTown_Gym_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE02_GET, DewfordTown_Gym_EventScript_GymStatueCertified
	goto DewfordTown_Gym_EventScript_GymStatue
	end

DewfordTown_Gym_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE02_GET, DewfordTown_Gym_EventScript_GymStatueCertified
	goto DewfordTown_Gym_EventScript_GymStatue
	end

DewfordTown_Gym_EventScript_GymStatueCertified::
	msgbox DewfordTown_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Gym_EventScript_GymStatue::
	msgbox DewfordTown_Gym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Gym_Text_GymGuideAdvice:
	.string "Na, auf dem Weg zum CHAMP, {PLAYER}?\p"
	.string "FAUSTAUHAVENs ARENALEITER KAMILLO\n"
	.string "setzt auf KAMPF-Pokémon.\p"
	.string "Wenn du NORMAL-Typen mitbringst,\n"
	.string "wirst du es schwer haben!\p"
	.string "KAMPF schlägt NORMAL - einfache Regel.\p"
	.string "Und als wäre das nicht genug: Die ARENA\n"
	.string "ist stockdunkel wie eine Höhle!\p"
	.string "Doch je mehr TRAINER du besiegst,\n"
	.string "desto heller wird es.\p"
	.string "Lass dich nicht einschüchtern - zeig,\n"
	.string "was du drauf hast!$"

DewfordTown_Gym_Text_GymGuidePostVictory:
	.string "Uff… Jetzt ist es mir fast zu hell!\p"
	.string "Aber deine Zukunft wird heller strahlen\n"
	.string "als jede Lampe hier! Glückwunsch!$"

DewfordTown_Gym_Text_TakaoIntro:
	.string "Nur rohe Kraft zählt!\n"
	.string "Los, zeig mir, was du hast!$"

DewfordTown_Gym_Text_TakaoDefeat:
	.string "Nicht… genug… Power…$"

DewfordTown_Gym_Text_TakaoPostBattle:
	.string "Gegen dein Talent war meine rohe Kraft\n"
	.string "nutzlos. Deine Technik beeindruckt mich!$"

DewfordTown_Gym_Text_JocelynIntro:
	.string "Du willst KAMILLO sehen?\n"
	.string "Da musst du erstmal an mir vorbei!$"

DewfordTown_Gym_Text_JocelynDefeat:
	.string "Was?! So schnell… verloren…?$"

DewfordTown_Gym_Text_JocelynPostBattle:
	.string "Ich nehme diese Niederlage als Ansporn.\p"
	.string "Eines Tages werde ich selbst eine\n"
	.string "ARENALEITERIN… oder CHAMP!$"

DewfordTown_Gym_Text_LauraIntro:
	.string "Du forderst MICH heraus?!\n"
	.string "Gleich fließen Tränen - deine\l"
    .string "wohlgemerkt!$"

DewfordTown_Gym_Text_LauraDefeat:
	.string "Waaah!\n"
	.string "Ich… Ich hab verloren!$"

DewfordTown_Gym_Text_LauraPostBattle:
	.string "Die Dunkelheit hier härtet mich ab.\p"
	.string "Aber… Ich habe KAMILLOs Gesicht\n"
	.string "noch nie gesehen. Schon seltsam…$"

DewfordTown_Gym_Text_LilithIntro:
	.string "Huhuhu… Wer tappt da im Dunkeln?\n"
	.string "Willst du verloren gehen?$"

DewfordTown_Gym_Text_LilithDefeat:
	.string "Tch… Kein Interesse mehr an dir.$"

DewfordTown_Gym_Text_LilithPostBattle:
	.string "Manchmal ist eine Niederlage nötig,\n"
	.string "um neu durchzustarten.$"

DewfordTown_Gym_Text_BrendenIntro:
	.string "Ich bin ein Seemann mit Verstand!\n"
	.string "Ich zeig dir, was Köpfchen bringt!$"

DewfordTown_Gym_Text_BrendenDefeat:
	.string "Das… war nicht der Plan.\n"
	.string "Ich verliere sonst nie!$"

DewfordTown_Gym_Text_BrendenPostBattle:
	.string "Du hast das Zeug, dem ARENALEITER\n"
	.string "die Stirn zu bieten. Geh weiter.$"

DewfordTown_Gym_Text_CristianIntro:
	.string "Willst du weiter?\n"
	.string "Dann musst du erst an mir vorbei!$"

DewfordTown_Gym_Text_CristianDefeat:
	.string "Grrr…\n"
	.string "Du warst einfach stärker.$"

DewfordTown_Gym_Text_CristianPostBattle:
	.string "Geh schon! Du verdienst den ORDEN.$"

DewfordTown_Gym_Text_BrawlyIntro:
	.string "Ich bin KAMILLO -\n"
	.string "der Wellenbrecher von FAUSTAUHAVEN!\p"
	.string "Ich hab in dieser finsteren Höhle meine\n"
	.string "Stärke geschärft - wie ein Fels in\l"
    .string "der Brandung.\p"
	.string "Willst du gegen mich antreten?\n"
	.string "Dann zeig, aus welchem Holz du\l"
    .string "geschnitzt bist!$"

DewfordTown_Gym_Text_BrawlyDefeat:
	.string "Whoa!\n"
	.string "Du bist echt 'ne Welle über mir gerollt!\p"
	.string "Okay, ich erkenne deine Stärke an.\n"
	.string "Hier, nimm den ORDEN dieser ARENA!$"

DewfordTown_Gym_Text_ReceivedKnuckleBadge:
	.string "{PLAYER} erhält den KNÖCHELORDEN von\n"
	.string "KAMILLO.$"

DewfordTown_Gym_Text_KnuckleBadgeInfoTakeThis:
	.string "Mit dem KNÖCHELORDEN gehorchen dir\n"
	.string "Pokémon bis Level 30 - auch getauschte.\p"
	.string "Außerdem kannst du nun BLITZ außerhalb\n"
	.string "von Kämpfen einsetzen.\p"
	.string "Und hier - eine TECHNISCHE MASCHINE\n"
	.string "für dich!$"

DewfordTown_Gym_Text_ExplainBulkUp:
	.string "Die TM08 enthält PROTZER.\p"
	.string "Erhöht ANGRIFF und VERTEIDIGUNG -\n"
	.string "ideal, um im Kampf standhaft zu bleiben.$"

DewfordTown_Gym_Text_RegisteredBrawly:
	.string "ARENALEITER KAMILLO wurde\n"
	.string "im PokéNav eingetragen.$"

DewfordTown_Gym_Text_BrawlyPostBattle:
	.string "Du wirst mal wie eine große Welle\n"
	.string "sein - mitreißend, beeindruckend,\n"
	.string "unausweichlich für jeden TRAINER.$"

DewfordTown_Gym_Text_GymStatue:
	.string "Pokémon ARENA von FAUSTAUHAVEN$"

DewfordTown_Gym_Text_GymStatueCertified:
	.string "Pokémon ARENA von FAUSTAUHAVEN\p"
	.string "ANERKANNTE TRAINER:\n"
	.string "{PLAYER}$"

DewfordTown_Gym_Text_BrawlyPreRematch:
	.string "KAMILLO: Eine Welle ebbt ab… doch sie\n"
	.string "kehrt zurück - stärker als je zuvor.\p"
	.string "Ich wusste, du kommst wieder.\n"
	.string "Zeig, wie weit du gekommen bist!$"

DewfordTown_Gym_Text_BrawlyRematchDefeat:
	.string "Schon wieder mitgerissen…\n"
	.string "Du bist wie ein Sturm.$"

DewfordTown_Gym_Text_BrawlyPostRematch:
	.string "KAMILLO: Kämpfe sind wie das Meer -\n"
	.string "tief, wild und endlos.\p"
	.string "Du meisterst sie mit Stil.$"

DewfordTown_Gym_Text_BrawlyRematchNeedTwoMons:
	.string "KAMILLO: Die Welle ist zurück - aber…\n"
	.string "Du hast nur ein kampfbereites Pokémon.\p"
	.string "Komm wieder, wenn du zwei oder mehr\n"
	.string "einsatzbereit hast!$"
