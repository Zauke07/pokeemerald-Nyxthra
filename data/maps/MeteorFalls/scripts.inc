MeteorFalls_MapScripts::
	.byte 0

MeteorFalls_EventScript_Pikachu::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_PIKACHU, CRY_MODE_NORMAL
	msgbox MeteorFalls_Text_Pikachu, MSGBOX_DEFAULT
	waitmoncry
	release
	end

MeteorFalls_Text_Pikachu:
	.string "Pikachu: Pika Pika!$"

MeteorFalls_EventScript_Ash::
	lock
	faceplayer
	dotimebasedevents
	goto_if_set FLAG_DAILY_FOUGHT_ASH, MeteorFalls_EventScript_Ash_ComeBackTomorrow
	goto_if_set FLAG_DEFEATED_ASH_ONCE, MeteorFalls_EventScript_Ash_RematchIntro
	msgbox MeteorFalls_Text_Ash_FirstIntro, MSGBOX_DEFAULT
	goto MeteorFalls_EventScript_Ash_StartBattle

MeteorFalls_EventScript_Ash_RematchIntro:
	msgbox MeteorFalls_Text_Ash_RematchIntro, MSGBOX_DEFAULT
	goto MeteorFalls_EventScript_Ash_StartBattle

MeteorFalls_EventScript_Ash_StartBattle:
	trainerbattle_no_intro TRAINER_ASH_TEST, MeteorFalls_Text_Ash_Defeat
	goto MeteorFalls_EventScript_Ash_AfterBattle
	end

MeteorFalls_EventScript_Ash_AfterBattle:
	msgbox MeteorFalls_Text_Ash_PostBattle, MSGBOX_DEFAULT
	setflag FLAG_DAILY_FOUGHT_ASH
	setflag FLAG_DEFEATED_ASH_ONCE
	release
	end

MeteorFalls_EventScript_Ash_ComeBackTomorrow:
	msgbox MeteorFalls_Text_Ash_ComeBackTomorrow, MSGBOX_DEFAULT
	release
	end

MeteorFalls_Text_Ash_FirstIntro:
	.string "Ash: Hey! Du siehst aus, als wärst du\n"
	.string "ein richtig starker Trainer.\p"
	.string "Ich bin Ash aus Alabastia - man nennt\n"
	.string "mich schon Champ von KANTO und JOHTO!\p"
	.string "Ich reise durch alle Regionen und kämpfe\n"
	.string "gegen die stärksten Trainer.\p"
	.string "Eines Tages werde ich POKéMON-MEISTER!\n"
	.string "Zeig mir, wie weit du schon bist!\p"
	.string "Ash: Okay! Lass uns einen Kampf liefern,\n"
	.string "den wir nie vergessen werden!\p"
	.string "Pikachu, wir geben niemals auf!$"

MeteorFalls_Text_Ash_RematchIntro:
	.string "Ash: Hey {PLAYER}! Schön, dich wiederzusehen!\n"
	.string "Ich hab auf ein Rematch gewartet.\p"
	.string "Pikachu und ich wollen immer stärker\n"
	.string "werden - also gib diesmal alles!$"

MeteorFalls_Text_Ash_Defeat:
	.string "Ash: Wow… das war ein unfassbar starker\n"
	.string "Kampf. Du hast mich echt überrascht!$"

MeteorFalls_Text_Ash_PostBattle:
	.string "Ash: Genau solche Kämpfe liebe ich.\n"
	.string "Man spürt richtig, wie man stärker wird.\p"
	.string "Ich hab in so vielen Regionen gekämpft,\n"
	.string "aber Trainer wie dich trifft man selten.\p"
	.string "Pikachu und ich werden weiter trainieren.\n"
	.string "Beim nächsten Mal geben wir\l"
	.string "noch mehr Gas!$"

MeteorFalls_Text_Ash_ComeBackTomorrow:
	.string "Ash: Heute hatten wir schon unseren\n"
	.string "Kampf.\p"
	.string "Ich will in jedem Duell meine volle\n"
	.string "Kraft geben.\p"
	.string "Komm morgen wieder - dann sind Pikachu\n"
	.string "und ich bereit für Runde zwei!$"
