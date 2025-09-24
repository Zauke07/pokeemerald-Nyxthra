RustboroCity_PokemonSchool_MapScripts::
	.byte 0

RustboroCity_PokemonSchool_EventScript_Blackboard::
	lockall
	msgbox RustboroCity_PokemonSchool_Text_BlackboardListsStatusChanges, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic
	end

RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic::
	message RustboroCity_PokemonSchool_Text_ReadWhichTopic
	waitmessage
	multichoicegrid 8, 1, MULTI_STATUS_INFO, 3, FALSE
	switch VAR_RESULT
	case 0, RustboroCity_PokemonSchool_EventScript_Poison
	case 1, RustboroCity_PokemonSchool_EventScript_Paralysis
	case 2, RustboroCity_PokemonSchool_EventScript_Sleep
	case 3, RustboroCity_PokemonSchool_EventScript_Burn
	case 4, RustboroCity_PokemonSchool_EventScript_Freeze
	case 5, RustboroCity_PokemonSchool_EventScript_ExitTopicSelect
	case MULTI_B_PRESSED, RustboroCity_PokemonSchool_EventScript_ExitTopicSelect
	end

RustboroCity_PokemonSchool_EventScript_Poison::
	msgbox RustboroCity_PokemonSchool_Text_ExplainPoison, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic
	end

RustboroCity_PokemonSchool_EventScript_Paralysis::
	msgbox RustboroCity_PokemonSchool_Text_ExplainParalysis, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic
	end

RustboroCity_PokemonSchool_EventScript_Sleep::
	msgbox RustboroCity_PokemonSchool_Text_ExplainSleep, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic
	end

RustboroCity_PokemonSchool_EventScript_Burn::
	msgbox RustboroCity_PokemonSchool_Text_ExplainBurn, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic
	end

RustboroCity_PokemonSchool_EventScript_Freeze::
	msgbox RustboroCity_PokemonSchool_Text_ExplainFreeze, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic
	end

RustboroCity_PokemonSchool_EventScript_ExitTopicSelect::
	releaseall
	end

RustboroCity_PokemonSchool_EventScript_GameboyKid1::
	msgbox RustboroCity_PokemonSchool_Text_TradingRightNow, MSGBOX_NPC
	end

RustboroCity_PokemonSchool_EventScript_GameboyKid2::
	msgbox RustboroCity_PokemonSchool_Text_AlwaysWantedSeedot, MSGBOX_NPC
	end

RustboroCity_PokemonSchool_EventScript_RichBoy::
	msgbox RustboroCity_PokemonSchool_Text_PokemontCantUseManMadeItems, MSGBOX_NPC
	end

RustboroCity_PokemonSchool_EventScript_Lass::
	msgbox RustboroCity_PokemonSchool_Text_ConfusedPokemonAttacksItself, MSGBOX_NPC
	end

RustboroCity_PokemonSchool_EventScript_SchoolKidM::
	msgbox RustboroCity_PokemonSchool_Text_PokemonHealItselfWithBerry, MSGBOX_NPC
	end

RustboroCity_PokemonSchool_EventScript_StudentNotebook::
	msgbox RustboroCity_PokemonSchool_Text_StudentsNotes, MSGBOX_SIGN
	end

RustboroCity_PokemonSchool_EventScript_Teacher::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_QUICK_CLAW, RustboroCity_PokemonSchool_EventScript_GaveQuickClaw
	call_if_eq VAR_FACING, DIR_EAST, RustboroCity_PokemonSchool_EventScript_TeacherCheckOnStudentsEast
	call_if_eq VAR_FACING, DIR_WEST, RustboroCity_PokemonSchool_EventScript_TeacherCheckOnStudentsWest
	msgbox RustboroCity_PokemonSchool_Text_StudentsWhoDontStudyGetQuickClaw, MSGBOX_DEFAULT
	giveitem ITEM_QUICK_CLAW
	goto_if_eq VAR_RESULT, 0, Common_EventScript_ShowBagIsFull
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	setflag FLAG_RECEIVED_QUICK_CLAW
	release
	end

RustboroCity_PokemonSchool_EventScript_TeacherCheckOnStudentsEast::
	applymovement VAR_LAST_TALKED, RustboroCity_PokemonSchool_Movement_TeacherCheckOnStudentsEast
	waitmovement 0
	return

RustboroCity_PokemonSchool_EventScript_TeacherCheckOnStudentsWest::
	applymovement VAR_LAST_TALKED, RustboroCity_PokemonSchool_Movement_TeacherCheckOnStudentsWest
	waitmovement 0
	return

RustboroCity_PokemonSchool_EventScript_GaveQuickClaw::
	msgbox RustboroCity_PokemonSchool_Text_ExplainQuickClaw, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	release
	end

RustboroCity_PokemonSchool_Movement_TeacherCheckOnStudentsWest:
	walk_left
	walk_down
	walk_down
	walk_right
	walk_in_place_faster_down
	delay_16
	delay_16
	delay_16
	walk_down
	walk_in_place_faster_left
	delay_16
	delay_16
	walk_right
	delay_16
	delay_16
	delay_8
	walk_up
	walk_left
	walk_left
	walk_up
	walk_up
	walk_right
	step_end

RustboroCity_PokemonSchool_Movement_TeacherCheckOnStudentsEast:
	walk_right
	walk_right
	walk_down
	walk_down
	walk_left
	walk_left
	walk_in_place_faster_down
	delay_16
	delay_16
	delay_16
	walk_down
	walk_in_place_faster_left
	delay_16
	delay_16
	walk_right
	delay_16
	delay_16
	delay_8
	walk_up
	walk_right
	walk_up
	walk_up
	walk_left
	walk_left
	step_end

RustboroCity_PokemonSchool_EventScript_Scott::
	lock
	faceplayer
	goto_if_set FLAG_MET_SCOTT_AFTER_OBTAINING_STONE_BADGE, RustboroCity_PokemonSchool_EventScript_ScottWatchStudents
	goto_if_set FLAG_MET_SCOTT_RUSTBORO, RustboroCity_PokemonSchool_EventScript_ScottSpokeAlready
	goto_if_set FLAG_BADGE01_GET, RustboroCity_PokemonSchool_EventScript_ScottGreetHasBadge
	msgbox RustboroCity_PokemonSchool_Text_ScottMetAlreadyCut, MSGBOX_DEFAULT
	addvar VAR_SCOTT_STATE, 1
	setflag FLAG_MET_SCOTT_RUSTBORO
	release
	end

RustboroCity_PokemonSchool_EventScript_ScottSpokeAlready::
	goto_if_set FLAG_BADGE01_GET, RustboroCity_PokemonSchool_EventScript_ScottNoticeBadge
	msgbox RustboroCity_PokemonSchool_Text_StudentTalentLevelUnknown, MSGBOX_DEFAULT
	release
	end

RustboroCity_PokemonSchool_EventScript_ScottGreetHasBadge::
	msgbox RustboroCity_PokemonSchool_Text_ScottMetAlreadyStoneBadge, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_MetScottAfterBadge
	end

RustboroCity_PokemonSchool_EventScript_ScottNoticeBadge::
	msgbox RustboroCity_PokemonSchool_Text_ScottStoneBadge, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_MetScottAfterBadge
	end

RustboroCity_PokemonSchool_EventScript_MetScottAfterBadge::
	addvar VAR_SCOTT_STATE, 1
	setflag FLAG_MET_SCOTT_AFTER_OBTAINING_STONE_BADGE
	release
	end

RustboroCity_PokemonSchool_EventScript_ScottWatchStudents::
	msgbox RustboroCity_PokemonSchool_Text_StudentTalentLevelUnknown, MSGBOX_DEFAULT
	release
	end

RustboroCity_PokemonSchool_Text_BlackboardListsStatusChanges:
	.string "Die Tafel hier? Vollgeklatscht mit all\n"
	.string "den miesen Zuständen, die Pokémon\l"
	.string "nerven. Schulstoff halt.$"

RustboroCity_PokemonSchool_Text_ReadWhichTopic:
	.string "Jo, was willst du lernen? Oder einfach\n"
	.string "alles skippen wie sonst auch?$"

RustboroCity_PokemonSchool_Text_ExplainPoison:
	.string "Vergiftung? Nervigster Mist.\n"
	.string "Die KP tickern runter wie mein Akku.\p"
	.string "Selbst nach'm Fight krepelt dein Pokémon\n"
	.string "weiter. Kein Witz.\p"
	.string "GEGENGIFT rein und Ruhe ist.$"

RustboroCity_PokemonSchool_Text_ExplainParalysis:
	.string "Paralyse? Stell dir vor, dein Pokémon\n"
	.string "hängt wie WLAN bei Regen.\p"
	.string "Langsam, unzuverlässig, peinlich.\n"
	.string "Para-Heiler hilft. Meistens.$"

RustboroCity_PokemonSchool_Text_ExplainSleep:
	.string "Wenn dein Pokémon pennt, macht's\n"
	.string "nix mehr. Einfach... Pause.\p"
	.string "Kann von selbst wach werden oder auch\n"
	.string "nicht. Wie du montags früh.$\p"
	.string "iPhone Wecker drauf, weiter geht’s.$"

RustboroCity_PokemonSchool_Text_ExplainBurn:
	.string "Verbrannt? Angriff wird Müll,\n"
	.string "KP schmilzen dahin.\p"
	.string "Wie wenn man sich beim Zocken Pizza\n"
	.string "auf die Hand kippt. FEUERHEILER regelt.$"

RustboroCity_PokemonSchool_Text_ExplainFreeze:
	.string "Eingefroren ist hart.\n"
	.string "Dein Pokémon macht gar nix mehr.\p"
	.string "Selbst nach dem Kampf bleibt’s Eiszeit.\n"
	.string "EISHEILER rein oder hoffen auf Sonne.$"

RustboroCity_PokemonSchool_Text_StudentsWhoDontStudyGetQuickClaw:
	.string "Wer pennt im Unterricht,\n"
	.string "kriegt von mir die FLINKKLAUE in den\p"
	.string "Nacken! Wie du die nutzt, zeigt, ob du\n"
	.string "was drauf hast oder halt lost bist.$"

RustboroCity_PokemonSchool_Text_ExplainQuickClaw:
	.string "FLINKKLAUE? Gibt deinem Pokémon Speed,\n"
	.string "vielleicht greift’s dann mal zuerst an.\p"
	.string "Es gibt noch zig andere Items.\n"
	.string "Aber du checkst eh nur TikTok.$"

RustboroCity_PokemonSchool_Text_TradingRightNow:
	.string "Ey, ich bin grad mitten im Tausch,\n"
	.string "mach keinen Stress.$"

RustboroCity_PokemonSchool_Text_AlwaysWantedSeedot:
	.string "Endlich ein SAMURZEL!\n"
	.string "Hab dafür fünf TAUBSIs geopfert. Worth.$"

RustboroCity_PokemonSchool_Text_PokemontCantUseManMadeItems:
	.string "Pokémon können Zeug tragen, klar.\n"
	.string "Aber so'n TRANK? Da glotzen sie nur blöd.$"

RustboroCity_PokemonSchool_Text_ConfusedPokemonAttacksItself:
	.string "Verwirrung? Dein Pokémon schmiert sich\n"
	.string "selbst eine rein. Sad life.\p"
	.string "Aber keine Sorge - nach dem Kampf ist\n"
	.string "wieder alles chillig.$"

RustboroCity_PokemonSchool_Text_PokemonHealItselfWithBerry:
	.string "Trägt dein Pokémon 'ne BEERE, gönnt es\n"
	.string "sich einfach selbst 'ne Heilung.\p"
	.string "Smart. Nicht wie du in Mathe.$"

RustboroCity_PokemonSchool_Text_StudentsNotes:
	.string "Schülerheft - ja, sowas gab’s mal…\p"
	.string "Pokémon fängt man mit BÄLLEN. Wow.\p"
	.string "Sechs Pokémon sind erlaubt. Logisch.\p"
	.string "TRAINER = der Typ, der kämpft und so.\p"
	.string "Und dann geht's in die ARENEN, wo man\n"
	.string "auf die Fresse kriegt. Classic.$"

RustboroCity_PokemonSchool_Text_ScottMetAlreadyCut:
	.string "Yo! Kenn ich dich nicht aus BLÜTENBURG?\p"
	.string "Ich bin SCOTT. Laufende Sonnenbrille.\p"
	.string "Ich such krasse TRAINER. Vielleicht\n"
	.string "bist du kein kompletter Lappen?\p"
	.string "Bring deinem Mon erstmal ZERSCHNEIDER\n"
	.string "bei. Oder geh heim.$"

RustboroCity_PokemonSchool_Text_StudentTalentLevelUnknown:
	.string "SCOTT: Hm...\n"
	.string "Talent hier? Keinen blassen Schimmer.\n"
	.string "Aber hey, Hoffnung stirbt zuletzt.$"

RustboroCity_PokemonSchool_Text_ScottStoneBadge:
	.string "SCOTT: Warte… IST DAS DER STEINORDEN?!?\p"
	.string "Nicht übel, Respekt.\p"
	.string "Würd dich gern mal kämpfen sehen.\n"
	.string "Aber bitte nicht mit Level 5 ZIGZACHS.$"

RustboroCity_PokemonSchool_Text_ScottMetAlreadyStoneBadge:
	.string "Ey! Wir kennen uns doch aus BLÜTENBURG!\p"
	.string "Ich bin SCOTT, der Typ mit den Shades.\p"
	.string "Ich such Trainer, die wissen,\n"
	.string "wo vorne und hinten ist.\p"
	.string "Und du hast schon den STEINORDEN?\n"
	.string "Okay, das ist heftig.$\p"
	.string "Jetzt will ich dich kämpfen sehen -\n"
	.string "aber bitte ohne Splash-Spam.$"
