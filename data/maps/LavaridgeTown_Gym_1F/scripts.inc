LavaridgeTown_Gym_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LavaridgeTown_Gym_1F_OnTransition
	.byte 0

LavaridgeTown_Gym_1F_OnTransition:
	call LavaridgeTown_Gym_1F_EventScript_SetTrainerTempVars
	call LavaridgeTown_Gym_1F_EventScript_CheckBuryTrainers
	end

@ Unclear where/if these temp vars are getting checked
LavaridgeTown_Gym_1F_EventScript_SetTrainerTempVars::
	setvar VAR_TEMP_B, 0
	setvar VAR_TEMP_C, 0
	setvar VAR_TEMP_D, 0
	setvar VAR_TEMP_E, 0
	setvar VAR_TEMP_F, 0
	goto_if_defeated TRAINER_COLE, LavaridgeTown_Gym_1F_EventScript_SetGeraldTempVar
	setvar VAR_TEMP_B, 1
LavaridgeTown_Gym_1F_EventScript_SetGeraldTempVar::
	goto_if_defeated TRAINER_GERALD, LavaridgeTown_Gym_1F_EventScript_SetAxleTempVar
	setvar VAR_TEMP_C, 1
LavaridgeTown_Gym_1F_EventScript_SetAxleTempVar::
	goto_if_defeated TRAINER_AXLE, LavaridgeTown_Gym_1F_EventScript_SetDanielleTempVar
	setvar VAR_TEMP_D, 1
LavaridgeTown_Gym_1F_EventScript_SetDanielleTempVar::
	goto_if_defeated TRAINER_DANIELLE, LavaridgeTown_Gym_1F_EventScript_EndSetTrainerTempVars
	setvar VAR_TEMP_E, 1
LavaridgeTown_Gym_1F_EventScript_EndSetTrainerTempVars::
	return

LavaridgeTown_Gym_1F_EventScript_CheckBuryTrainers::
	goto_if_defeated TRAINER_COLE, LavaridgeTown_Gym_1F_EventScript_CheckBuryGerald
	setobjectmovementtype LOCALID_COLE, MOVEMENT_TYPE_BURIED
LavaridgeTown_Gym_1F_EventScript_CheckBuryGerald::
	goto_if_defeated TRAINER_GERALD, LavaridgeTown_Gym_1F_EventScript_CheckBuryAxle
	setobjectmovementtype LOCALID_GERALD, MOVEMENT_TYPE_BURIED
LavaridgeTown_Gym_1F_EventScript_CheckBuryAxle::
	goto_if_defeated TRAINER_AXLE, LavaridgeTown_Gym_1F_EventScript_CheckBuryDanielle
	setobjectmovementtype LOCALID_AXLE, MOVEMENT_TYPE_BURIED
LavaridgeTown_Gym_1F_EventScript_CheckBuryDanielle::
	goto_if_defeated TRAINER_DANIELLE, LavaridgeTown_Gym_1F_EventScript_EndCheckBuryTrainers
	setobjectmovementtype LOCALID_DANIELLE, MOVEMENT_TYPE_BURIED
LavaridgeTown_Gym_1F_EventScript_EndCheckBuryTrainers::
	return

LavaridgeTown_Gym_1F_EventScript_Flannery::
	trainerbattle_single TRAINER_FLANNERY_1, LavaridgeTown_Gym_1F_Text_FlanneryIntro, LavaridgeTown_Gym_1F_Text_FlanneryDefeat, LavaridgeTown_Gym_1F_EventScript_FlanneryDefeated, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, LavaridgeTown_Gym_1F_EventScript_FlanneryRematch
	goto_if_unset FLAG_RECEIVED_TM_OVERHEAT, LavaridgeTown_Gym_1F_EventScript_GiveOverheat2
	msgbox LavaridgeTown_Gym_1F_Text_FlanneryPostBattle, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_Gym_1F_EventScript_FlanneryDefeated::
	message LavaridgeTown_Gym_1F_Text_ReceivedHeatBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox LavaridgeTown_Gym_1F_Text_ExplainHeatBadgeTakeThis, MSGBOX_DEFAULT
	setflag FLAG_WHITEOUT_TO_LAVARIDGE
	setflag FLAG_DEFEATED_LAVARIDGE_GYM
	setflag FLAG_BADGE04_GET
	addvar VAR_PETALBURG_GYM_STATE, 1
	call_if_eq VAR_PETALBURG_GYM_STATE, 6, Common_EventScript_ReadyPetalburgGymForBattle
	setvar VAR_0x8008, 4
	call Common_EventScript_SetGymTrainers
	setflag FLAG_HIDE_VERDANTURF_TOWN_WANDAS_HOUSE_WALLY
	setvar VAR_LAVARIDGE_TOWN_STATE, 1
	call LavaridgeTown_Gym_1F_EventScript_GiveOverheat
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox LavaridgeTown_Gym_1F_Text_RegisteredFlannery, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_FLANNERY_MATCH_CALL
	release
	end

LavaridgeTown_Gym_1F_EventScript_GiveOverheat2::
	giveitem ITEM_TM_OVERHEAT
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox LavaridgeTown_Gym_1F_Text_ExplainOverheat, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_OVERHEAT
	release
	end

LavaridgeTown_Gym_1F_EventScript_GiveOverheat::
	giveitem ITEM_TM_OVERHEAT
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox LavaridgeTown_Gym_1F_Text_ExplainOverheat, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_OVERHEAT
	return

LavaridgeTown_Gym_1F_EventScript_FlanneryRematch::
	trainerbattle_rematch_double TRAINER_FLANNERY_1, LavaridgeTown_Gym_1F_Text_FlanneryPreRematch, LavaridgeTown_Gym_1F_Text_FlanneryRematchDefeat, LavaridgeTown_Gym_1F_Text_FlanneryRematchNeedTwoMons
	msgbox LavaridgeTown_Gym_1F_Text_FlanneryPostRematch, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_1F_EventScript_Cole::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, LOCALID_COLE, TRAINER_COLE, LavaridgeTown_Gym_1F_Text_ColeIntro, LavaridgeTown_Gym_1F_Text_ColeDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript, OBJ_ID_NONE, TRAINER_NONE, NULL, NULL, NULL, NULL, NULL, FALSE, TRUE, FALSE, FALSE
	msgbox LavaridgeTown_Gym_1F_Text_ColePostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_EventScript_CheckTrainerScript::
	call LavaridgeTown_Gym_1F_EventScript_SetTrainerTempVars
	release
	special ShouldTryGetTrainerScript
	goto_if_eq VAR_RESULT, 1, EventScript_GotoTrainerScript
	end

LavaridgeTown_Gym_1F_EventScript_Axle::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, LOCALID_AXLE, TRAINER_AXLE, LavaridgeTown_Gym_1F_Text_AxleIntro, LavaridgeTown_Gym_1F_Text_AxleDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript, OBJ_ID_NONE, TRAINER_NONE, NULL, NULL, NULL, NULL, NULL, FALSE, TRUE, FALSE, FALSE
	msgbox LavaridgeTown_Gym_1F_Text_AxlePostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_B1F_EventScript_Keegan::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, LOCALID_KEEGAN, TRAINER_KEEGAN, LavaridgeTown_Gym_B1F_Text_KeeganIntro, LavaridgeTown_Gym_B1F_Text_KeeganDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript, OBJ_ID_NONE, TRAINER_NONE, NULL, NULL, NULL, NULL, NULL, FALSE, TRUE, FALSE, FALSE
	msgbox LavaridgeTown_Gym_B1F_Text_KeeganPostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_1F_EventScript_Danielle::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, LOCALID_DANIELLE, TRAINER_DANIELLE, LavaridgeTown_Gym_1F_Text_DanielleIntro, LavaridgeTown_Gym_1F_Text_DanielleDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript, OBJ_ID_NONE, TRAINER_NONE, NULL, NULL, NULL, NULL, NULL, FALSE, TRUE, FALSE, FALSE
	msgbox LavaridgeTown_Gym_1F_Text_DaniellePostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_1F_EventScript_Gerald::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, LOCALID_GERALD, TRAINER_GERALD, LavaridgeTown_Gym_1F_Text_GeraldIntro, LavaridgeTown_Gym_1F_Text_GeraldDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript, OBJ_ID_NONE, TRAINER_NONE, NULL, NULL, NULL, NULL, NULL, FALSE, TRUE, FALSE, FALSE
	msgbox LavaridgeTown_Gym_1F_Text_GeraldPostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_B1F_EventScript_Jace::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, LOCALID_JACE, TRAINER_JACE, LavaridgeTown_Gym_B1F_Text_JaceIntro, LavaridgeTown_Gym_B1F_Text_JaceDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript, OBJ_ID_NONE, TRAINER_NONE, NULL, NULL, NULL, NULL, NULL, FALSE, TRUE, FALSE, FALSE
	msgbox LavaridgeTown_Gym_B1F_Text_JacePostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_B1F_EventScript_Jeff::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, LOCALID_JEFF, TRAINER_JEFF, LavaridgeTown_Gym_B1F_Text_JeffIntro, LavaridgeTown_Gym_B1F_Text_JeffDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript, OBJ_ID_NONE, TRAINER_NONE, NULL, NULL, NULL, NULL, NULL, FALSE, TRUE, FALSE, FALSE
	msgbox LavaridgeTown_Gym_B1F_Text_JeffPostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_B1F_EventScript_Eli::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, LOCALID_ELI, TRAINER_ELI, LavaridgeTown_Gym_B1F_Text_EliIntro, LavaridgeTown_Gym_B1F_Text_EliDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript, OBJ_ID_NONE, TRAINER_NONE, NULL, NULL, NULL, NULL, NULL, FALSE, TRUE, FALSE, FALSE
	msgbox LavaridgeTown_Gym_B1F_Text_EliPostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_1F_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_LAVARIDGE_GYM, LavaridgeTown_Gym_1F_EventScript_GymGuidePostVictory
	msgbox LavaridgeTown_Gym_1F_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_Gym_1F_EventScript_GymGuidePostVictory::
	msgbox LavaridgeTown_Gym_1F_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_Gym_1F_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE04_GET, LavaridgeTown_Gym_1F_EventScript_GymStatueCertified
	goto LavaridgeTown_Gym_1F_EventScript_GymStatue
	end

LavaridgeTown_Gym_1F_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE04_GET, LavaridgeTown_Gym_1F_EventScript_GymStatueCertified
	goto LavaridgeTown_Gym_1F_EventScript_GymStatue
	end

LavaridgeTown_Gym_1F_EventScript_GymStatueCertified::
	msgbox LavaridgeTown_Gym_1F_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

LavaridgeTown_Gym_1F_EventScript_GymStatue::
	msgbox LavaridgeTown_Gym_1F_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

LavaridgeTown_Gym_1F_Text_GymGuideAdvice:
	.string "Na, wie sieht's aus, zukünftiger CHAMP?\p"
	.string "Flavia, die Arenaleiterin, steht auf\n"
	.string "Feuer-Pokémon.\p"
	.string "Aber nicht nur das... die Frau ist\n"
	.string "spitz wie ein Vulkan kurz vorm Ausbruch.\p"
	.string "Pass auf, dass du dir nicht die Finger\n"
	.string "verbrennst! Mach sie ordentlich nass,\l"
	.string "und dann zeig ihr, wo der Hammer hängt!$"

LavaridgeTown_Gym_1F_Text_GymGuidePostVictory:
	.string "Alter Schwede! Da bin ich ja nur vom\n"
	.string "Zusehen schon feucht geworden!$"

LavaridgeTown_Gym_1F_Text_ColeIntro:
	.string "Aua, aua, fuck!\n"
	.string "Verdammt, ist das heiß hier!$"

LavaridgeTown_Gym_1F_Text_ColeDefeat:
	.string "Mir läuft der Schweiß in die Ritze...$"

LavaridgeTown_Gym_1F_Text_ColePostBattle:
	.string "Im heißen Sand zu buddeln regt die\n"
	.string "Durchblutung an.\p"
	.string "Besonders in bestimmten Körperteilen,\n"
	.string "wenn du verstehst, was ich meine...$"

LavaridgeTown_Gym_1F_Text_AxleIntro:
	.string "Ich versuche hier gerade Druck abzubauen.\n"
	.string "Also nerv mich nicht!$"

LavaridgeTown_Gym_1F_Text_AxleDefeat:
	.string "Hoffentlich röstet Flavia dir die Eier!$"

LavaridgeTown_Gym_1F_Text_AxlePostBattle:
	.string "Puuuh...\p"
	.string "Wenn man hier zu lange im Sand liegt,\n"
	.string "schrumpft alles zusammen...$"

LavaridgeTown_Gym_B1F_Text_KeeganIntro:
	.string "Na, schon außer Puste?\n"
	.string "Bist wohl keine Ausdauer gewohnt, was?\p"
	.string "Wer bei Flavia landen will, muss aber\n"
	.string "länger durchhalten können!$"

LavaridgeTown_Gym_B1F_Text_KeeganDefeat:
	.string "Zu früh gekommen... äh, verloren.$"

LavaridgeTown_Gym_B1F_Text_KeeganPostBattle:
	.string "Du hast echt Ausdauer...\n"
	.string "Aber Flavia ist ein anderes Kaliber.\p"
	.string "Die reitet dich gnadenlos in den Boden,\n"
	.string "wenn du nicht aufpasst!$"

LavaridgeTown_Gym_1F_Text_GeraldIntro:
	.string "Halten deine Pokémon 200 Grad aus?\n"
	.string "Oder machen sie vorher schlapp?$"

LavaridgeTown_Gym_1F_Text_GeraldDefeat:
	.string "Das war mir nicht heiß genug...$"

LavaridgeTown_Gym_1F_Text_GeraldPostBattle:
	.string "Magma hat über 1000 Grad.\p"
	.string "Du hast mich besiegt, also solltest du\n"
	.string "auch Flavias Hitze aushalten können.$"

LavaridgeTown_Gym_1F_Text_DanielleIntro:
	.string "Ähm...\n"
	.string "Okay, ich mach dich heiß!$"

LavaridgeTown_Gym_1F_Text_DanielleDefeat:
	.string "Oh, du bist ja richtig wild...$"

LavaridgeTown_Gym_1F_Text_DaniellePostBattle:
	.string "Ich will mal genau so ein scharfes Luder\n"
	.string "werden wie Flavia.$"

LavaridgeTown_Gym_B1F_Text_JaceIntro:
	.string "Komm schon, mach hin!\n"
	.string "Ich bin schon ganz feucht... äh, heiß!$"

LavaridgeTown_Gym_B1F_Text_JaceDefeat:
	.string "Das war ein totaler Abturner...$"

LavaridgeTown_Gym_B1F_Text_JacePostBattle:
	.string "So wie du abgehst, hast du vielleicht\n"
	.string "echt 'ne Chance bei unserer Leiterin.$"

LavaridgeTown_Gym_B1F_Text_JeffIntro:
	.string "Siehst du die wilden Flammen?\n"
	.string "Genau so brennt es bei mir untenrum!$"

LavaridgeTown_Gym_B1F_Text_JeffDefeat:
	.string "Da lief wohl was schief... autsch.$"

LavaridgeTown_Gym_B1F_Text_JeffPostBattle:
	.string "Na und? Scheiß drauf!\n"
	.string "Ich kann barfuß über heiße Kohlen laufen!\p"
	.string "...Mach das bloß nicht nach, das brennt\n"
	.string "wie die Hölle!$"

LavaridgeTown_Gym_B1F_Text_EliIntro:
	.string "Ich steh total auf große Berge.\n"
	.string "Besonders auf Flavias... äh, Vulkane.$"

LavaridgeTown_Gym_B1F_Text_EliDefeat:
	.string "Toll, da hab ich wohl komplett\n"
	.string "die Kontrolle verloren.$"

LavaridgeTown_Gym_B1F_Text_EliPostBattle:
	.string "Ich häng hier nur rum, weil Flavia so\n"
	.string "verdammt heiß ist.\p"
	.string "Hehehe, was für eine Aussicht...$"

LavaridgeTown_Gym_1F_Text_FlanneryIntro:
	.string "Willkommen... Ne, Moment.\p"
	.string "Hey, du kleiner Lutscher! Schön, dass du\n"
	.string "dich in mein heißes Loch getraut hast!\p"
	.string "Mir wurde das anvertraut... Ne, scheiße.\p"
	.string "Ich bin Flavia, und ich bin hier der Boss,\n"
	.string "du kleine Nutte!\p"
	.string "Ähm...\n"
	.string "Unterschätz mich bloß nicht, nur weil ich\l"
	.string "das hier noch nicht so lange mache!\p"
	.string "Ich werde dir jetzt mal ein paar richtig\n"
	.string "heiße Stellungen zeigen!\l"
	.string "Bereit, ordentlich ins Schwitzen zu kommen?$"

LavaridgeTown_Gym_1F_Text_FlanneryDefeat:
	.string "Oh fuck...\n"
	.string "Da war ich wohl zu feucht fröhlich...\p"
	.string "Ich... ich bin noch gar nicht so lange\n"
	.string "Leiterin hier.\p"
	.string "Ich hab versucht, den dicken Macker zu\n"
	.string "markieren, aber das bin ich gar nicht.\p"
	.string "Ich muss das auf meine eigene, dreckige\n"
	.string "Art machen.\p"
	.string "Danke, dass du mich so hart rangenommen\n"
	.string "hast, das hab ich echt gebraucht.\p"
	.string "Hier, als Belohnung für deine... Leistung.$"

LavaridgeTown_Gym_1F_Text_ReceivedHeatBadge:
	.string "{PLAYER} hat den Hitzeorden von Flavia\n"
	.string "bekommen.$"

LavaridgeTown_Gym_1F_Text_ExplainHeatBadgeTakeThis:
	.string "Mit dem Hitzeorden gehorchen dir alle\n"
	.string "Pokémon bis Level 50 aufs Wort.\l"
	.string "Auch die getauschten Biester.\p"
	.string "Außerdem kannst du jetzt STÄRKE\n"
	.string "außerhalb von Kämpfen benutzen.\p"
	.string "Hier, nimm auch meine Nummer... äh,\n"
	.string "ich meine, nimm das hier!$"

LavaridgeTown_Gym_1F_Text_ExplainOverheat:
	.string "Die TM50 ist Hitzekoller.\p"
	.string "Das ballert richtig rein und tut dem\n"
	.string "Gegner ordentlich weh.\p"
	.string "Aber danach ist bei deinem Pokémon erstmal\n"
	.string "die Luft raus, der SPEZIAL-ANGRIFF sinkt.\l"
	.string "Für 'nen Quickie geil, für lange Nummern\l"
	.string "eher ungeeignet.$"

LavaridgeTown_Gym_1F_Text_RegisteredFlannery:
	.string "Arenaleiterin Flavia wurde im POKéNAV\n"
	.string "registriert.$"

LavaridgeTown_Gym_1F_Text_FlanneryPostBattle:
	.string "Deine Ausdauer erinnert mich an jemanden...\p"
	.string "Oh! Ich weiß! Du gehst genauso hart ran\n"
	.string "wie Norman aus Blütenburg!$"

LavaridgeTown_Gym_1F_Text_GymStatue:
	.string "Pokémon-Arena Von Bad Lavastadt$"

LavaridgeTown_Gym_1F_Text_GymStatueCertified:
	.string "Pokémon-Arena Von Bad Lavastadt\p"
	.string "Flavias Geprüfte Stecher:\n"
	.string "{PLAYER}$"

LavaridgeTown_Gym_1F_Text_FlanneryPreRematch:
	.string "Flavia: Mich kriegt man nicht so leicht\n"
	.string "klein.\p"
	.string "Ich steh auf Pokémon.\n"
	.string "Ich steh aufs Kämpfen.\l"
	.string "Und... ich steh auf dich!\p"
	.string "Lass uns noch 'ne heiße Runde einlegen!$"

LavaridgeTown_Gym_1F_Text_FlanneryRematchDefeat:
	.string "Puuuh!\n"
	.string "Ich bin kurz vorm Höhepunkt!$"

LavaridgeTown_Gym_1F_Text_FlanneryPostRematch:
	.string "Flavia: Bin zwar wieder die Unterlegene,\n"
	.string "aber voll und ganz befriedigt.\p"
	.string "So krass durchgeschwitzt war ich echt\n"
	.string "schon ewig nicht mehr.\p"
	.string "Das müssen wir unbedingt wiederholen,\n"
	.string "ruf mich an!$"

LavaridgeTown_Gym_1F_Text_FlanneryRematchNeedTwoMons:
	.string "Flavia: Mich kriegt man nicht so leicht\n"
	.string "klein.\p"
	.string "Ich steh auf Pokémon.\n"
	.string "Ich steh aufs Kämpfen.\l"
	.string "Und... ich steh auf dich!\p"
	.string "Lass uns noch 'ne heiße Runde einlegen!\p"
	.string "Oh, Moment mal. Hast du nur ein einziges\n"
	.string "Pokémon dabei?\p"
	.string "Sorry Süßer, aber für mich brauchst du\n"
	.string "schon mindestens zwei Pokémon, sonst\l"
	.string "lohnt sich das gar nicht.$"
