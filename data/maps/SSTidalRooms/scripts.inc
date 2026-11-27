SSTidalRooms_MapScripts::
	.byte 0

SSTidalRooms_EventScript_SnatchGiver::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TM_SNATCH, SSTidalRooms_EventScript_ExplainSnatch
	msgbox SSTidalRooms_Text_NotSuspiciousTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_TM_SNATCH
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM_SNATCH
	msgbox SSTidalRooms_Text_ExplainSnatch, MSGBOX_DEFAULT
	release
	end

SSTidalRooms_EventScript_ExplainSnatch::
	msgbox SSTidalRooms_Text_ExplainSnatch, MSGBOX_DEFAULT
	release
	end

SSTidalRooms_EventScript_Bed::
	lockall
	msgbox SSTidalRooms_Text_TakeRestOnBed, MSGBOX_DEFAULT
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	call SSTidalRooms_EventScript_ProgessCruiseAfterBed
	releaseall
	end

SSTidalRooms_EventScript_Colton::
	trainerbattle_single TRAINER_COLTON, SSTidalRooms_Text_ColtonIntro, SSTidalRooms_Text_ColtonDefeat
	msgbox SSTidalRooms_Text_ColtonPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalRooms_EventScript_Micah::
	trainerbattle_single TRAINER_MICAH, SSTidalRooms_Text_MicahIntro, SSTidalRooms_Text_MicahDefeat
	msgbox SSTidalRooms_Text_MicahPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalRooms_EventScript_Thomas::
	trainerbattle_single TRAINER_THOMAS, SSTidalRooms_Text_ThomasIntro, SSTidalRooms_Text_ThomasDefeat
	msgbox SSTidalRooms_Text_ThomasPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalRooms_EventScript_Jed::
	trainerbattle_double TRAINER_LEA_AND_JED, SSTidalRooms_Text_JedIntro, SSTidalRooms_Text_JedDefeat, SSTidalRooms_Text_JedNotEnoughMons
	msgbox SSTidalRooms_Text_JedPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalRooms_EventScript_Lea::
	trainerbattle_double TRAINER_LEA_AND_JED, SSTidalRooms_Text_LeaIntro, SSTidalRooms_Text_LeaDefeat, SSTidalRooms_Text_LeaNotEnoughMons
	msgbox SSTidalRooms_Text_LeaPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalRooms_EventScript_Garret::
	trainerbattle_single TRAINER_GARRET, SSTidalRooms_Text_GarretIntro, SSTidalRooms_Text_GarretDefeat
	msgbox SSTidalRooms_Text_GarretPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalRooms_EventScript_Naomi::
	trainerbattle_single TRAINER_NAOMI, SSTidalRooms_Text_NaomiIntro, SSTidalRooms_Text_NaomiDefeat
	msgbox SSTidalRooms_Text_NaomiPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalRooms_Text_TakeRestOnBed:
	.string "Da ist ein Bett…\n"
	.string "Ruhen wir uns aus.$"

SSTidalRooms_Text_ColtonIntro:
	.string "Ich segle oft nach SEEGRASULB CITY.\p"
	.string "Ich besuche nämlich gern\n"
	.string "Wettbewerbe.$"

SSTidalRooms_Text_ColtonDefeat:
	.string "Das war ein schöner Kampf!$"

SSTidalRooms_Text_ColtonPostBattle:
	.string "Ich bin so aufgeregt, wenn ich mir\n"
	.string "vorstelle, welche Pokémon ich im\l"
	.string "nächsten Wettbewerb sehe. Die\l"
	.string "Vorfreude begeistert mich!$"

SSTidalRooms_Text_MicahIntro:
	.string "Sind deine Freunde stark?$"

SSTidalRooms_Text_MicahDefeat:
	.string "Deine Freunde sind tatsächlich stark.$"

SSTidalRooms_Text_MicahPostBattle:
	.string "Freunde müssen keine Menschen sein.\n"
	.string "Für mich sind Pokémon wertvolle\l"
	.string "Freunde!$"

SSTidalRooms_Text_ThomasIntro:
	.string "Kind…\n"
	.string "Hast du an die Tür geklopft?$"

SSTidalRooms_Text_ThomasDefeat:
	.string "Eine Niederlage nimmt man ohne Eile\n"
	.string "oder Panik hin.$"

SSTidalRooms_Text_ThomasPostBattle:
	.string "In keiner Lage aus der Fassung zu\n"
	.string "geraten, ist der Verhaltenskodex des\l"
	.string "GENTLEMANS.$"

SSTidalRooms_Text_JedIntro:
	.string "JED: Mir ist das ein bisschen peinlich,\n"
	.string "aber… Wir zeigen dir unsere\l"
	.string "Turtelkraft!$"

SSTidalRooms_Text_JedDefeat:
	.string "JED: Seufz…$"

SSTidalRooms_Text_JedPostBattle:
	.string "JED: Zum ersten Mal hat unsere\n"
	.string "Turtelkraft nicht gesiegt!\l"
	.string "Du musst ein toller Trainer sein!$"

SSTidalRooms_Text_JedNotEnoughMons:
	.string "JED: Du hast nur ein Pokémon?\n"
	.string "Ist das nicht viel zu einsam?$"

SSTidalRooms_Text_LeaIntro:
	.string "LEA: Ich komme mir ein bisschen albern\n"
	.string "vor, aber… Wir zeigen dir unsere\l"
	.string "Turtelkraft!$"

SSTidalRooms_Text_LeaDefeat:
	.string "LEA: Menno!$"

SSTidalRooms_Text_LeaPostBattle:
	.string "LEA: Das glaube ich nicht!\n"
	.string "Unsere Turtelkraft hat versagt…\l"
	.string "Du musst ein toller Trainer sein!$"

SSTidalRooms_Text_LeaNotEnoughMons:
	.string "LEA: Ich wollte kämpfen…\n"
	.string "Aber du hast ja nicht mal zwei Pokémon…$"

SSTidalRooms_Text_GarretIntro:
	.string "Ah, du kommst gerade recht.\p"
	.string "Mir ist langweilig, weißt du.\n"
	.string "Du darfst mich unterhalten.$"

SSTidalRooms_Text_GarretDefeat:
	.string "…Das genügt.$"

SSTidalRooms_Text_GarretPostBattle:
	.string "Vielleicht bringe ich Vater dazu, mir\n"
	.string "eine Yacht zu kaufen.\l"
	.string "Eine Yacht für mich und meine Pokémon!$"

SSTidalRooms_Text_NaomiIntro:
	.string "Oh, was für ein reizender Trainer.\n"
	.string "Möchtest du Tee trinken?\l"
	.string "Oder lieber kämpfen?$"

SSTidalRooms_Text_NaomiDefeat:
	.string "Ich verstehe.\n"
	.string "Du bist der aktive Typ.$"

SSTidalRooms_Text_NaomiPostBattle:
	.string "Eine Weltreise auf einem Luxusliner hat\n"
	.string "ihren Reiz, muss ich sagen…\p"
	.string "Aber ich gebe zu, dass es auch etwas\n"
	.string "Reizvolles hat, Hoenn mit der Fähre zu\l"
	.string "bereisen.$"

SSTidalRooms_Text_NotSuspiciousTakeThis:
	.string "Äh… Hi! Ich… ich verhalte mich nicht\n"
	.string "verdächtig! Äh… Das kannst du haben!\l"
	.string "Gratis!\p"
	.string "Ehrlich, ich habe es niemandem GEKLAUT!\n"
	.string "So etwas würde ich nie tun! Es ist\l"
	.string "sauber! Du kannst es benutzen!$"

SSTidalRooms_Text_ExplainSnatch:
	.string "KLAUBER stiehlt die Vorteile bestimmter\n"
	.string "Attacken, bevor ein Gegner oder\l"
	.string "Verbündeter sie nutzen kann.$"

