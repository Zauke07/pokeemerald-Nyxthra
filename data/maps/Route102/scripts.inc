Route102_MapScripts::
	.byte 0

Route102_EventScript_LittleBoy::
	msgbox Route102_Text_ImNotVeryTall, MSGBOX_NPC
	end

Route102_EventScript_RouteSignOldale::
	msgbox Route102_Text_RouteSignOldale, MSGBOX_SIGN
	end

Route102_EventScript_RouteSignPetalburg::
	msgbox Route102_Text_RouteSignPetalburg, MSGBOX_SIGN
	end

Route102_EventScript_Boy::
	msgbox Route102_Text_CatchWholeBunchOfPokemon, MSGBOX_NPC
	end

Route102_EventScript_Calvin::
	trainerbattle_single TRAINER_CALVIN_1, Route102_Text_CalvinIntro, Route102_Text_CalvinDefeated, Route102_EventScript_CalvinRegisterMatchCallAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route102_EventScript_CalvinRematch
	setvar VAR_0x8004, TRAINER_CALVIN_1
	specialvar VAR_RESULT, IsTrainerRegistered
	goto_if_eq VAR_RESULT, FALSE, Route102_EventScript_CalvinTryRegister
	msgbox Route102_Text_CalvinPostBattle, MSGBOX_DEFAULT
	release
	end

Route102_EventScript_CalvinRegisterMatchCallAfterBattle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	goto_if_set FLAG_HAS_MATCH_CALL, Route102_EventScript_CalvinRegisterMatchCall
	release
	end

Route102_EventScript_CalvinRegisterMatchCall::
	msgbox Route102_Text_CalvinRegisterShort, MSGBOX_DEFAULT
	register_matchcall TRAINER_CALVIN_1
	release
	end

Route102_EventScript_CalvinTryRegister::
	goto_if_set FLAG_HAS_MATCH_CALL, Route102_EventScript_CalvinRegister
	msgbox Route102_Text_CalvinPostBattle, MSGBOX_DEFAULT
	release
	end

Route102_EventScript_CalvinRegister::
	msgbox Route102_Text_CalvinRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_CALVIN_1
	release
	end

Route102_EventScript_CalvinRematch::
	trainerbattle_rematch TRAINER_CALVIN_1, Route102_Text_CalvinRematchIntro, Route102_Text_CalvinRematchDefeated
	msgbox Route102_Text_CalvinRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route102_EventScript_Rick::
	trainerbattle_single TRAINER_RICK, Route102_Text_RickIntro, Route102_Text_RickDefeated
	msgbox Route102_Text_RickPostBattle, MSGBOX_AUTOCLOSE
	end

Route102_EventScript_Tiana::
	trainerbattle_single TRAINER_TIANA, Route102_Text_TianaIntro, Route102_Text_TianaDefeated
	msgbox Route102_Text_TianaPostBattle, MSGBOX_AUTOCLOSE
	end

Route102_EventScript_Allen::
	trainerbattle_single TRAINER_ALLEN, Route102_Text_AllenIntro, Route102_Text_AllenDefeated
	msgbox Route102_Text_AllenPostBattle, MSGBOX_AUTOCLOSE
	end

Route102_Text_WatchMeCatchPokemon:
	.string "HEIKO: {PLAYER}...\n"
	.string "Pokémon verstecken sich oft im hohen\l"
	.string "Gras, so wie hier, oder?\p"
	.string "Bleib kurz stehen und schau zu, ob ich\n"
	.string "das richtig hinkriege, ja?\p"
	.string "...Whoa!$"

Route102_Text_WallyIDidIt:
	.string "HEIKO: Ich hab’s wirklich geschafft...\n"
	.string "Es hat geklappt! Mein erstes Pokémon!$"

Route102_Text_LetsGoBack:
	.string "{PLAYER}, danke dir echt!\n"
	.string "Lass uns zurück zur ARENA gehen.$"

Route102_Text_ImNotVeryTall:
	.string "Was glotzt du so?! Ja, ich bin klein.\p"
	.string "Aber ich trete dir trotzdem in die Eier,\n"
	.string "du kleiner Hurensohn-Trainer!\p"
	.string "Und wehe, du lachst... Ich schwör,\n"
	.string "ich hol meine Brüder. Du Opfer.$"

Route102_Text_CatchWholeBunchOfPokemon:
	.string "Ich will voll viele Pokémon fangen!\p"
	.string "Aber hey... Manche sagen, irgendwo\n"
	.string "laufen Leute rum, die Pokémon klauen...\n"
	.string "Glaubst du das?$"

Route102_Text_RouteSignOldale:
	.string "ROUTE 102\n"
	.string "{RIGHT_ARROW} ROSALTSTADT\n"
	.string "(“Die Höhle flüstert” - sagt man dort.)$"

Route102_Text_RouteSignPetalburg:
	.string "ROUTE 102\n"
	.string "{LEFT_ARROW} BLÜTENBURG CITY\n"
	.string "(Bleib wachsam - mysteriöse Gestalten\n"
	.string "wurden in der Nähe gesehen.)$"

Route102_EventScript_Shiggy::
    msgbox Route102_Text_Shiggy, MSGBOX_NPC
    end

Route102_Text_Shiggy:
    .string "Hey {PLAYER}, ich bin ein\n"
	.string "Bote von diesem Rom Entwickler.\l"
	.string "Sein Name ist Zauke07!\p"
	.string "Immer wenn du mich am Ende einer\n"
	.string "Route siehst, sprich mich an, denn\l"
	.string "ich habe einen heißen Tipp für dich!\p"
	.string "Tipp:\p"
	.string "Auf dieser Route versteckt sich ein\n"
	.string "Starter aus der 1 Generation mit\l"
	.string "einer Spawnrate von 1%!\p"
	.string "Welches es ist, musst du selbst\n"
	.string "herausfinden :D !$"

