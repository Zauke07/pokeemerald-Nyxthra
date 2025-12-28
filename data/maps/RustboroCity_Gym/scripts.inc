RustboroCity_Gym_MapScripts::
	.byte 0

RustboroCity_Gym_EventScript_Roxanne::
	trainerbattle_single TRAINER_ROXANNE_1, RustboroCity_Gym_Text_RoxanneIntro, RustboroCity_Gym_Text_RoxanneDefeat, RustboroCity_Gym_EventScript_RoxanneDefeated, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_Gym_EventScript_RoxanneRematch
	goto_if_unset FLAG_RECEIVED_TM_ROCK_TOMB, RustboroCity_Gym_EventScript_GiveRockTomb
	msgbox RustboroCity_Gym_Text_RoxannePostBattle, MSGBOX_DEFAULT
	release
	end

RustboroCity_Gym_EventScript_RoxanneDefeated::
	message RustboroCity_Gym_Text_ReceivedStoneBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox RustboroCity_Gym_Text_StoneBadgeInfoTakeThis, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_RUSTBORO_GYM
	setflag FLAG_BADGE01_GET
	setvar VAR_RUSTBORO_CITY_STATE, 1
	addvar VAR_PETALBURG_GYM_STATE, 1
	setvar VAR_0x8008, 1
	call Common_EventScript_SetGymTrainers
	call_if_eq VAR_PETALBURG_GYM_STATE, 6, Common_EventScript_ReadyPetalburgGymForBattle
	goto RustboroCity_Gym_EventScript_GiveRockTomb
	end

RustboroCity_Gym_EventScript_GiveRockTomb::
	giveitem ITEM_TM_ROCK_TOMB
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM_ROCK_TOMB
	msgbox RustboroCity_Gym_Text_ExplainRockTomb, MSGBOX_DEFAULT
	release
	end

RustboroCity_Gym_EventScript_RoxanneRematch::
	trainerbattle_rematch_double TRAINER_ROXANNE_1, RustboroCity_Gym_Text_RoxannePreRematch, RustboroCity_Gym_Text_RoxanneRematchDefeat, RustboroCity_Gym_Text_RoxanneRematchNeedTwoMons
	msgbox RustboroCity_Gym_Text_RoxannePostRematch, MSGBOX_AUTOCLOSE
	end

RustboroCity_Gym_EventScript_Josh::
	trainerbattle_single TRAINER_JOSH, RustboroCity_Gym_Text_JoshIntro, RustboroCity_Gym_Text_JoshDefeat
	msgbox RustboroCity_Gym_Text_JoshPostBattle, MSGBOX_AUTOCLOSE
	end

RustboroCity_Gym_EventScript_Tommy::
	trainerbattle_single TRAINER_TOMMY, RustboroCity_Gym_Text_TommyIntro, RustboroCity_Gym_Text_TommyDefeat
	msgbox RustboroCity_Gym_Text_TommyPostBattle, MSGBOX_AUTOCLOSE
	end

RustboroCity_Gym_EventScript_Marc::
	trainerbattle_single TRAINER_MARC, RustboroCity_Gym_Text_MarcIntro, RustboroCity_Gym_Text_MarcDefeat
	msgbox RustboroCity_Gym_Text_MarcPostBattle, MSGBOX_AUTOCLOSE
	end

RustboroCity_Gym_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_RUSTBORO_GYM, RustboroCity_Gym_EventScript_GymGuidePostVictory
	msgbox RustboroCity_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

RustboroCity_Gym_EventScript_GymGuidePostVictory::
	msgbox RustboroCity_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

RustboroCity_Gym_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE01_GET, RustboroCity_Gym_EventScript_GymStatueCertified
	goto RustboroCity_Gym_EventScript_GymStatue
	end

RustboroCity_Gym_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE01_GET, RustboroCity_Gym_EventScript_GymStatueCertified
	goto RustboroCity_Gym_EventScript_GymStatue
	end

RustboroCity_Gym_EventScript_GymStatueCertified::
	msgbox RustboroCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

RustboroCity_Gym_EventScript_GymStatue::
	msgbox RustboroCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

RustboroCity_Gym_EventScript_RegisterRoxanne::
	lockall
	pokenavcall RustboroCity_Gym_Text_RoxanneRegisterCall
	waitmessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox RustboroCity_Gym_Text_RegisteredRoxanne, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_ROXANNE_MATCH_CALL
	clearflag FLAG_ENABLE_ROXANNE_FIRST_CALL
	releaseall
	end

RustboroCity_Gym_Text_GymGuideAdvice:
	.string "Na, alles klar?\p"
	.string "Willst du CHAMP werden?\n"
	.string "Ich bin zwar kein TRAINER, aber…\p"
	.string "Ich kann dir trotzdem nen heißen Tipp\n"
	.string "geben, Kumpel!\p"
	.string "Wir arbeiten zusammen an deinem Weg\n"
	.string "zur MEISTERSCHAFT, okay?\p"
	.string "Also - du brauchst ORDEN, klar.\n"
	.string "Aber die ARENALEITER sind harte Nüsse!\p"
	.string "Hier kommt mein Expertenrat:\p"
	.string "FELIZIA setzt GESTEINS-POKéMON ein.\n"
	.string "Die sind zäh, aber schwach gegen WASSER\n"
	.string "und PFLANZEN.\p"
	.string "Besieg sie und komm wieder - ich bin\n"
	.string "gespannt, wie du dich schlägst!$"

RustboroCity_Gym_Text_GymGuidePostVictory:
	.string "Wow, was für ein Kampf!\n"
	.string "Du hast sie echt weggeklatscht!\p"
	.string "Check mal deinen TRAINERPASS -\n"
	.string "der STEINORDEN ist jetzt eingetragen.\p"
	.string "Der erste Schritt Richtung CHAMP -\n"
	.string "geschafft! Glückwunsch!$"

RustboroCity_Gym_Text_JoshIntro:
	.string "Denk nicht, dass wir hier einfach sind!\n"
	.string "Ich zeig dir, was wir draufhaben!$"

RustboroCity_Gym_Text_JoshDefeat:
	.string "Okay… das war echt heftig…$"

RustboroCity_Gym_Text_JoshPostBattle:
	.string "Du hast noch nicht mal alles gesehen,\n"
	.string "was GESTEINS-POKéMON können!$"

RustboroCity_Gym_Text_TommyIntro:
	.string "Wenn du mich nicht schaffst, hast du\n"
	.string "gegen FELIZIA null Chance!$"

RustboroCity_Gym_Text_TommyDefeat:
	.string "Wow… du bist echt gut!$"

RustboroCity_Gym_Text_TommyPostBattle:
	.string "FELIZIA ist noch mal 'ne andere Liga.\p"
	.string "Bereite dich besser vor!$"

RustboroCity_Gym_Text_MarcIntro:
	.string "Die Stadt ist eng? Egal!\n"
	.string "Meine POKéMON brauchen Action!$"

RustboroCity_Gym_Text_MarcDefeat:
	.string "Uff… ganz schön zäh, du!$"

RustboroCity_Gym_Text_MarcPostBattle:
	.string "Ich respektiere FELIZIA total.\p"
	.string "Den GESTEIN-Typ zu wählen war schlau -\n"
	.string "gerade in ihrem Alter.$"

RustboroCity_Gym_Text_RoxanneIntro:
	.string "Hi, ich bin FELIZIA,\n"
	.string "LEITERIN der METAROST ARENA.\p"
	.string "Ich will zeigen, was ich in der TRAINER-\n"
	.string "SCHULE gelernt habe!\p"
	.string "Lass uns sehen, wie du kämpfst!$"

RustboroCity_Gym_Text_RoxanneDefeat:
	.string "Oh… verloren…\p"
	.string "Ich hab wohl noch viel zu lernen.\p"
	.string "Aber okay - Regeln sind Regeln.\p"
	.string "Nimm diesen offiziellen STEINORDEN\n"
	.string "der POKéMON LIGA!$"

RustboroCity_Gym_Text_ReceivedStoneBadge:
	.string "{PLAYER} erhält den STEINORDEN von\n"
	.string "FELIZIA!$"

RustboroCity_Gym_Text_StoneBadgeInfoTakeThis:
	.string "Mit dem STEINORDEN werden deine\n"
	.string "ATTACKEN stärker.\p"
	.string "Und ZERSCHNEIDER kannst du jetzt\n"
	.string "auch außerhalb von Kämpfen einsetzen.\p"
	.string "Hier, das sollst du auch noch kriegen.$"

RustboroCity_Gym_Text_ExplainRockTomb:
	.string "Das ist TM39 - FELSGRAB.\p"
	.string "Fügt Schaden zu und senkt INITIATIVE.\p"
	.string "TM einsetzen = ATTACKE lernen.\n"
	.string "Aber Achtung - nur 1× verwendbar!$"

RustboroCity_Gym_Text_RoxannePostBattle:
	.string "Du bist echt stark.\n"
	.string "Geh ruhig in andere ARENEN!\p"
	.string "Je mehr du kämpfst, desto mehr lernst du!$"

RustboroCity_Gym_Text_GymStatue:
	.string "POKéMON ARENA - METAROST CITY$"

RustboroCity_Gym_Text_GymStatueCertified:
	.string "POKéMON ARENA - METAROST CITY\p"
	.string "Anerkannte TRAINER:\n"
	.string "{PLAYER}$"

RustboroCity_Gym_Text_RoxanneRegisterCall:
	.string "… … … … … …\n"
	.string "… … … … … Beep!\p"
	.string "FELIZIA: Hi, {PLAYER}?\p"
	.string "Ich hab gehört, du rockst grad alles.\p"
	.string "Ich will nicht hinten anstehen!\p"
	.string "Ich trainier mein ARENA-Team - sei\n"
	.string "bereit, mich bald wieder herauszufordern!\p"
	.string "Ich freu mich drauf! Bye!$"

RustboroCity_Gym_Text_RegisteredRoxanne:
	.string "FELIZIA wurde im POKéNAV registriert.$"

RustboroCity_Gym_Text_RoxannePreRematch:
	.string "FELIZIA: Willkommen zurück!\n"
	.string "Lass uns sehen, was wir gelernt haben!\p"
	.string "Ich bin bereit - du auch?\n"
	.string "Auf geht's!$"

RustboroCity_Gym_Text_RoxanneRematchDefeat:
	.string "Oh Mann…\n"
	.string "Schon wieder verloren…$"

RustboroCity_Gym_Text_RoxannePostRematch:
	.string "Ich liebe Kämpfe noch mehr, je mehr\n"
	.string "ich über POKéMON lerne!$"

RustboroCity_Gym_Text_RoxanneRematchNeedTwoMons:
	.string "FELIZIA: Oh… du hast nur ein POKéMON?\p"
	.string "Bring bitte noch eins mit,\n"
	.string "dann können wir kämpfen.$"
