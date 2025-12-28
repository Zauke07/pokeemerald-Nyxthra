MeteorFalls_1F_2R_MapScripts::
	.byte 0

MeteorFalls_1F_2R_EventScript_Nicolas::
	trainerbattle_single TRAINER_NICOLAS_1, MeteorFalls_1F_2R_Text_NicolasIntro, MeteorFalls_1F_2R_Text_NicolasDefeat, MeteorFalls_1F_2R_EventScript_RegisterNicolas
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MeteorFalls_1F_2R_EventScript_RematchNicolas
	msgbox MeteorFalls_1F_2R_Text_NicolasPostBattle, MSGBOX_DEFAULT
	release
	end

MeteorFalls_1F_2R_EventScript_RegisterNicolas::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox MeteorFalls_1F_2R_Text_NicolasRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_NICOLAS_1
	release
	end

MeteorFalls_1F_2R_EventScript_RematchNicolas::
	trainerbattle_rematch TRAINER_NICOLAS_1, MeteorFalls_1F_2R_Text_NicolasRematchIntro, MeteorFalls_1F_2R_Text_NicolasRematchDefeat
	msgbox MeteorFalls_1F_2R_Text_NicolasPostRematch, MSGBOX_AUTOCLOSE
	end

MeteorFalls_1F_2R_EventScript_John::
	trainerbattle_double TRAINER_JOHN_AND_JAY_1, MeteorFalls_1F_2R_Text_JohnIntro, MeteorFalls_1F_2R_Text_JohnDefeat, MeteorFalls_1F_2R_Text_JohnNotEnoughMons, MeteorFalls_1F_2R_EventScript_RegisterJohn
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MeteorFalls_1F_2R_EventScript_RematchJohn
	msgbox MeteorFalls_1F_2R_Text_JohnPostBattle, MSGBOX_DEFAULT
	release
	end

MeteorFalls_1F_2R_EventScript_RegisterJohn::
	msgbox MeteorFalls_1F_2R_Text_JohnRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_JOHN_AND_JAY_1
	release
	end

MeteorFalls_1F_2R_EventScript_RematchJohn::
	trainerbattle_rematch_double TRAINER_JOHN_AND_JAY_1, MeteorFalls_1F_2R_Text_JohnRematchIntro, MeteorFalls_1F_2R_Text_JohnRematchDefeat, MeteorFalls_1F_2R_Text_JohnRematchNotEnoughMons
	msgbox MeteorFalls_1F_2R_Text_JohnPostRematch, MSGBOX_AUTOCLOSE
	end

MeteorFalls_1F_2R_EventScript_Jay::
	trainerbattle_double TRAINER_JOHN_AND_JAY_1, MeteorFalls_1F_2R_Text_JayIntro, MeteorFalls_1F_2R_Text_JayDefeat, MeteorFalls_1F_2R_Text_JayNotEnoughMons, MeteorFalls_1F_2R_EventScript_RegisterJay
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MeteorFalls_1F_2R_EventScript_RematchJay
	msgbox MeteorFalls_1F_2R_Text_JayPostBattle, MSGBOX_DEFAULT
	release
	end

MeteorFalls_1F_2R_EventScript_RegisterJay::
	msgbox MeteorFalls_1F_2R_Text_JohnRegister, MSGBOX_DEFAULT  @ John speaks for both during register
	register_matchcall TRAINER_JOHN_AND_JAY_1
	release
	end

MeteorFalls_1F_2R_EventScript_RematchJay::
	trainerbattle_rematch_double TRAINER_JOHN_AND_JAY_1, MeteorFalls_1F_2R_Text_JayRematchIntro, MeteorFalls_1F_2R_Text_JayRematchDefeat, MeteorFalls_1F_2R_Text_JayRematchNotEnoughMons
	msgbox MeteorFalls_1F_2R_Text_JayPostRematch, MSGBOX_AUTOCLOSE
	end

MeteorFalls_1F_2R_Text_NicolasIntro::
	.string "Hier trainieren die DRACHEN-Profis.\n"
	.string "Nichts für kleine Lichter wie dich!\p"
	.string "Sogar der CHAMP schaut hier vorbei.\n"
	.string "Checkst du jetzt, dass du hier völlig\l"
	.string "fehl am Platz bist?$"

MeteorFalls_1F_2R_Text_NicolasDefeat::
	.string "Urgh!\n"
	.string "Hast du gecheatet oder was?!$"

MeteorFalls_1F_2R_Text_NicolasPostBattle::
	.string "Der Weg an die Spitze ist hart.\p"
	.string "Irgendwann feg ich dich und den\n"
	.string "Rest dieser Versager-Welt weg!$"

MeteorFalls_1F_2R_Text_NicolasRegister::
	.string "Ich muss analysieren, wie du mich\n"
	.string "überrumpelt hast. POKéNAV, her damit!$"

MeteorFalls_1F_2R_Text_NicolasRematchIntro::
	.string "Wir haben uns den Arsch aufgerissen,\n"
	.string "um die Nummer eins zu werden.\p"
	.string "Zeig mal, ob du immer noch so viel\n"
	.string "unverdientes Glück hast!$"

MeteorFalls_1F_2R_Text_NicolasRematchDefeat::
	.string "Verdammt!\n"
	.string "Das darf doch nicht wahr sein!$"

MeteorFalls_1F_2R_Text_NicolasPostRematch::
	.string "Du hast deine Viecher wohl doch nicht\n"
	.string "nur im Center geparkt.\p"
	.string "Solange du so ein Brocken bist, hab\n"
	.string "ich wenigstens jemanden zum Treten!$"

MeteorFalls_1F_2R_Text_JohnIntro::
	.string "JOHANNES: Wir kämpfen seit Ewigkeiten\n"
	.string "als Duo. Gegen uns hast du keine\l"
	.string "Chance, du Grünschnabel!$"

MeteorFalls_1F_2R_Text_JohnDefeat::
	.string "JOHANNES: Oh, nein.\n"
	.string "Alte, wir haben geloost!$"

MeteorFalls_1F_2R_Text_JohnPostBattle::
	.string "JOHANNES: Wir sind seit 50 Jahren\n"
	.string "verheiratet.\p"
	.string "Und wenn ich so drüber nachdenke:\n"
	.string "Ich hab immer noch nicht gegen meine\l"
	.string "Frau gewonnen. Nervt extrem!$"

MeteorFalls_1F_2R_Text_JohnNotEnoughMons::
	.string "JOHANNES: Na, sieh mal einer an!\p"
	.string "Willst du dich echt mit uns anlegen?\n"
	.string "Dann bring gefälligst mehr POKéMON mit!$"

MeteorFalls_1F_2R_Text_JohnRegister::
	.string "JOHANNES: Kleiner, falls wir mal wieder\n"
	.string "Bock haben dich zu plätten, meld dich!$"

MeteorFalls_1F_2R_Text_JayIntro::
	.string "JAY: 50 Jahre Ehe, mein Kind.\p"
	.string "Unser Band ist so fest, das kriegt\n"
	.string "selbst so ’ne Pfeife wie du nicht kaputt.$"

MeteorFalls_1F_2R_Text_JayDefeat::
	.string "JAY: Oh, Schatz.\n"
	.string "Wegen dir haben wir verloren!$"

MeteorFalls_1F_2R_Text_JayPostBattle::
	.string "JAY: 50 Jahre Ehehölle…\p"
	.string "Wenn wir uns zoffen, klären wir das\n"
	.string "immer mit ’nem Kampf. Deswegen ist\l"
	.string "unser Haus auch eine Ruine.$"

MeteorFalls_1F_2R_Text_JayNotEnoughMons::
	.string "JAY: Was bist du denn für ’n Zwerg?\p"
	.string "Wenn du kämpfen willst, brauchst du\n"
	.string "mehr als nur ein POKéMON, Schätzchen.$"

MeteorFalls_1F_2R_Text_JohnRematchIntro::
	.string "JOHANNES: Wir ziehen das als Team durch.\n"
	.string "Mach dich bereit für ’ne Packung!$"

MeteorFalls_1F_2R_Text_JohnRematchDefeat::
	.string "JOHANNES: Na toll.\n"
	.string "Wieder verloren, Frau!$"

MeteorFalls_1F_2R_Text_JohnPostRematch::
	.string "JOHANNES: 50 Jahre Ehe…\p"
	.string "Eigentlich haben wir uns jeden Tag\n"
	.string "nur gegenseitig die POKéMON um die\l"
	.string "Ohren gehauen. Pure Leidenschaft!$"

MeteorFalls_1F_2R_Text_JayRematchIntro::
	.string "JAY: 50 Jahre halten wir’s schon aus.\p"
	.string "Wir haben uns gegenseitig so richtig\n"
	.string "hart gemacht. Das überlebst du nicht!$"

MeteorFalls_1F_2R_Text_JayRematchDefeat::
	.string "JAY: Ach, du liebe Zeit.\n"
	.string "Mein Mann war mal wieder zu langsam!$"

MeteorFalls_1F_2R_Text_JayPostRematch::
	.string "JAY: 50 Jahre verheiratet…\n"
	.string "Da passiert so einiges.\p"
	.string "Ich hoffe, ich kann ihn noch ein paar\n"
	.string "Jahre im Kampf demütigen!$"

MeteorFalls_1F_2R_Text_JohnRematchNotEnoughMons::
	.string "JOHANNES: Ey, Grünschnabel!\p"
	.string "Wir kämpfen nur gegen Leute, die auch\n"
	.string "genug POKéMON am Start haben.\l"
	.string "Komm wieder, wenn du vollzählig bist!$"

MeteorFalls_1F_2R_Text_JayRematchNotEnoughMons::
	.string "JAY: Ohne ein volles Team brauchst du\n"
	.string "uns gar nicht erst dumm kommen!$"
