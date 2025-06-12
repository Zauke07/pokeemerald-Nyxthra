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
	.string "Hi, wie geht's?\p"
	.string "Hör zu, mein Freund!\n"
	.string "Würdest du gerne CHAMP werden?\p"
	.string "Ich bin kein TRAINER. Ich nicht. Aber\n"
	.string "ich kann dir trotzdem einen nützlichen\l"
	.string "Rat geben.\p"
	.string "Also, abgemacht! Wir werden zusammen\n"
	.string "nach der POKéMON MEISTERSCHAFT\l"
	.string "streben!\p"
	.string "Als TRAINER musst du die ORDEN der\n"
	.string "ARENEN sammeln, habe ich Recht?\p"
	.string "Aber die ARENALEITER sind nicht gerade\n"
	.string "einfach zu besiegen!\p"
	.string "Und hier komme ich ins Spiel!\n"
	.string "Ich werde dir einen Expertentipp geben!\p"
	.string "FELIZIA, die ARENALEITERIN, setzt\n"
	.string "GESTEINS-POKéMON ein.\p"
	.string "Ein GESTEINS-POKéMON ist sehr zäh,\n"
	.string "hat aber gegen WASSER- und PFLANZEN-\l"
	.string "Attacken keine Chance.\p"
	.string "Komm wieder vorbei, wenn du die ARENA-\n"
	.string "LEITERIN besiegt hast.\p"
	.string "Nun zeig, was du drauf hast!$"

RustboroCity_Gym_Text_GymGuidePostVictory:
	.string "Hui! Was für ein atemberaubender Sieg!\n"
	.string "Meine Zurufe müssen gewirkt haben!\p"
	.string "Großartig!\n"
	.string "Schau mal auf deinen TRAINERPASS.\p"
	.string "Der STEINORDEN, den du gerade bekommen\n"
	.string "hast, müsste dort schon vermerkt sein.\p"
	.string "Nun hast du den ersten Schritt zur\n"
	.string "MEISTERSCHAFT schon erfolgreich\l"
	.string "hinter dir!\p"
	.string "Ein großartiges Gefühl!$"

RustboroCity_Gym_Text_JoshIntro:
	.string "Unterschätze die TRAINER einer ARENA\n"
	.string "nicht! Ich zeige dir, warum wir die\l"
	.string "Besten sind!$"

RustboroCity_Gym_Text_JoshDefeat:
	.string "Du warst viel zu gut für mich...$"

RustboroCity_Gym_Text_JoshPostBattle:
	.string "Du hast noch gar nicht gesehen, was\n"
	.string "GESTEINS-POKéMON alles können.$"

RustboroCity_Gym_Text_TommyIntro:
	.string "Wenn du mich nicht besiegen kannst,\n"
	.string "hast du keine Chance gegen FELIZIA.$"

RustboroCity_Gym_Text_TommyDefeat:
	.string "Wow! Du hast wirklich Talent!$"

RustboroCity_Gym_Text_TommyPostBattle:
	.string "FELIZIA ist um ein Vielfaches stärker\n"
	.string "als ich.\p"
	.string "Du solltest dich besser wappnen!$"

RustboroCity_Gym_Text_MarcIntro:
	.string "Wir sind vielleicht mitten in der Stadt,\n"
	.string "aber na und?\p"
	.string "Meine GESTEIN-POKéMON brauchen Platz zum\n"
	.string "Toben!$"

RustboroCity_Gym_Text_MarcDefeat:
	.string "Oh, Mann oh Mann!\n"
	.string "Unser Herausforderer ist ein zäher Kunde!$"

RustboroCity_Gym_Text_MarcPostBattle:
	.string "Ich muss unserem ANFÜHRER Respekt zollen.\p"
	.string "Es erforderte Klugheit und Verstand von ihr,\n"
	.string "in ihrem jungen Alter den GESTEIN-Typ zu wählen.$"

RustboroCity_Gym_Text_RoxanneIntro:
	.string "Hallo, ich bin FELIZIA, die LEITERIN der\n"
	.string "ARENA von METAROST CITY.\p"
	.string "Ich wurde ARENALEITERIN, um mein\n"
	.string "Wissen, das ich in der POKéMON TRAINER-\l"
	.string "SCHULE erworben habe, umzusetzen.\p"
	.string "Würdest du mir bitte zeigen, wie du\n"
	.string "kämpfst und mit welchen POKéMON?$"

RustboroCity_Gym_Text_RoxanneDefeat:
	.string "So...\n"
	.string "Ich habe verloren...\p"
	.string "Es scheint, ich muss noch eine ganze\n"
	.string "Menge lernen...\p"
	.string "Ich verstehe schon.\p"
	.string "Die Regeln der POKéMON LIGA schreiben\n"
	.string "vor, dass TRAINER, die einen ARENA-\l"
	.string "LEITER besiegt haben, dieses erhalten.\p"
	.string "Bitte nimm den offiziellen POKéMON LIGA\n"
	.string "STEINORDEN an!$"

RustboroCity_Gym_Text_ReceivedStoneBadge:
	.string "{PLAYER} hat den STEINORDEN von\n"
	.string "FELIZIA erhalten.$"

RustboroCity_Gym_Text_StoneBadgeInfoTakeThis:
	.string "Der STEINORDEN erhöht die Kraft der\n"
	.string "ATTACKEN deiner POKéMON.\p"
	.string "Außerdem sind sie nun in der Lage, die\n"
	.string "VM ZERSCHNEIDER auch außerhalb eines\l"
	.string "Kampfes einzusetzen.\p"
	.string "Dies möchte ich dir auch noch geben.$"

RustboroCity_Gym_Text_ExplainRockTomb:
	.string "Diese TM39 enthält FELSGRAB.\p"
	.string "Sie richtet nicht nur durch das Fallen\n"
	.string "von Steinen Schaden an, sondern\l"
	.string "reduziert auch die INITIATIVE.\p"
	.string "Sobald du eine TM aktivierst, wird die\n"
	.string "Attacke einem POKéMON beigebracht.\p"
	.string "Aber vergiss nicht, dass eine TM nur\n"
	.string "einmal beigebracht werden kann. Ihr\l"
	.string "Einsatz will also überlegt sein.$"

RustboroCity_Gym_Text_RoxannePostBattle:
	.string "Da du so stark bist, solltest du auch die\n"
	.string "anderen ARENALEITER herausfordern.\p"
	.string "Du lernst wertvolle Dinge dazu, wenn du\n"
	.string "gegen viele TRAINER antrittst.$"

RustboroCity_Gym_Text_GymStatue:
	.string "POKéMON ARENA von METAROST CITY$"

RustboroCity_Gym_Text_GymStatueCertified:
	.string "POKéMON ARENA von METAROST CITY\p"
	.string "FELIZIAS ANERKANNTE TRAINER:\n"
	.string "{PLAYER}$"

RustboroCity_Gym_Text_RoxanneRegisterCall:
	.string "… … … … … …\n"
	.string "… … … … … Piep!\p"
	.string "FELIZIA: Oh, hallo, {PLAYER}?\n"
	.string "Hier spricht FELIZIA aus FAUSTAUHAFEN.\p"
	.string "Ich habe von BRAWLY gehört, dass du\n"
	.string "dich mit rasendem Tempo durch die\n"
	.string "Ränge der TRAINER bewegst.\p"
	.string "Nun, ich möchte nicht denken, dass ich\l"
	.string "dich nicht schlagen kann.\p"
	.string "Ich verspreche, ich werde mein ARENA\n"
	.string "so verbessern, dass du uns wieder\n"
	.string "herausfordern kannst.\p"
	.string "Ich hoffe, du freust dich genauso sehr\n"
	.string "auf diese Gelegenheit wie ich!\p"
	.string "… … … … … …\n"
	.string "… … … … … Klick!$"

RustboroCity_Gym_Text_RegisteredRoxanne:
	.string "Registrierte ARENALEITERIN FELIZIA\n"
	.string "im POKéNAV.$"

RustboroCity_Gym_Text_RoxannePreRematch:
	.string "FELIZIA: Es freut mich, dich wiederzusehen.\n"
	.string "Ich bin FELIZIA, die ARENALEITERIN hier.\p"
	.string "Ich bin sicher, wir haben seit unserem\n"
	.string "letzten Treffen viele Kämpfe erlebt.\p"
	.string "Ich würde gerne sehen, wie viel besser\n"
	.string "wir geworden sind. Lass uns kämpfen!$"

RustboroCity_Gym_Text_RoxanneRematchDefeat:
	.string "Grr…\n"
	.string "Wieder habe ich verloren…$"

RustboroCity_Gym_Text_RoxannePostRematch:
	.string "FELIZIA: Ich habe immer noch viel zu lernen,\n"
	.string "wenn es um Kämpfe mit POKéMON geht.\p"
	.string "Dieses Bewusstsein lässt mich das\n"
	.string "Kämpfen umso mehr lieben!$"

RustboroCity_Gym_Text_RoxanneRematchNeedTwoMons:
	.string "FELIZIA: Es freut mich, dich wiederzusehen.\n"
	.string "Ich bin FELIZIA, die ARENALEITERIN hier.\p"
	.string "Ich bin sicher, wir haben seit unserem\n"
	.string "letzten Treffen viele Kämpfe erlebt.\p"
	.string "Ich würde gerne sehen, wie viel besser\n"
	.string "wir geworden sind…\p"
	.string "Oh, nein…\n"
	.string "Du hast nur ein POKéMON dabei?\p"
	.string "Bitte komm zurück, wenn du mindestens\n"
	.string "noch ein weiteres POKéMON hast.$"
