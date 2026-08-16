SafariZone_EventScript_OutOfBallsMidBattle::
	setvar VAR_SAFARI_ZONE_STATE, 1
	special ExitSafariMode
	setwarp MAP_ROUTE121_SAFARI_ZONE_ENTRANCE, 255, 2, 5
	end

SafariZone_EventScript_Exit::
	setvar VAR_SAFARI_ZONE_STATE, 1
	special ExitSafariMode
	warp MAP_ROUTE121_SAFARI_ZONE_ENTRANCE, 255, 2, 5
	waitstate
	end

SafariZone_EventScript_RetirePrompt::
	lockall
	msgbox SafariZone_Text_WouldYouLikeToExit, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SafariZone_EventScript_Retire
	releaseall
	end

SafariZone_EventScript_Retire::
	goto SafariZone_EventScript_Exit

SafariZone_EventScript_TimesUp::
	lockall
	playse SE_DING_DONG
	message SafariZone_Text_TimesUp
	waitmessage
	waitbuttonpress
	releaseall
	goto SafariZone_EventScript_Exit

SafariZone_EventScript_OutOfBalls::
	lockall
	playse SE_DING_DONG
	message SafariZone_Text_OutOfBalls
	waitmessage
	waitbuttonpress
	releaseall
	goto SafariZone_EventScript_Exit

EventScript_PokeBlockFeeder::
	lockall
	special GetPokeblockFeederInFront
	goto_if_ne VAR_RESULT, 0xFFFF, SafariZone_EventScript_PokeblockPresent
	msgbox SafariZone_Text_PlacePokeblockOnFeeder, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SafariZone_EventScript_ChoosePokeblock
	releaseall
	end

SafariZone_EventScript_ChoosePokeblock::
	fadescreen FADE_TO_BLACK
	special OpenPokeblockCaseOnFeeder
	waitstate
	goto_if_ne VAR_RESULT, 0xFFFF, SafariZone_EventScript_PokeblockPlaced
#ifdef BUGFIX
	releaseall  @ Only gets called from EventScript_PokeBlockFeeder which uses lockall.
#endif
	end

SafariZone_EventScript_PokeblockPlaced::
	message SafariZone_Text_PokeblockWasPlaced
	waitmessage
	waitbuttonpress
	releaseall
	end

SafariZone_EventScript_PokeblockPresent::
	message SafariZone_Text_PokeblockStillHere
	waitmessage
	waitbuttonpress
	releaseall
	end

SafariZone_Text_WouldYouLikeToExit::
	.string "Willst du dich jetzt schon verpissen?$"

SafariZone_Text_TimesUp::
	.string "Ding-dong! Zeit ist um!\n"
	.string "Dein SAFARI-Spiel ist gelaufen.$"

SafariZone_Text_OutOfBalls::
	.string "Du hast keine SAFARI-BÄLLE mehr.\n"
	.string "Dein SAFARI-Spiel ist vorbei.$"

SafariZone_Text_PlacePokeblockOnFeeder::
	.string "Willst du einen {POKEBLOCK} in den\n"
	.string "{POKEBLOCK}-FUTTERNAPF werfen?$"

SafariZone_Text_PokeblockStillHere::
	.string "Der {STR_VAR_1}, den du vorhin\n"
	.string "da gelassen hast, gammelt noch hier rum.$"

SafariZone_Text_PokeblockWasPlaced::
	.string "Der {STR_VAR_1} wurde in den\n"
	.string "{POKEBLOCK}-FUTTERNAPF geklatscht.$"

SafariZone_South_Text_StillHaveTimeExit::
	.string "Du hast noch Zeit übrig. Willst du die\n"
	.string "SAFARI-ZONE wirklich schon verlassen?$"

SafariZone_South_Text_EnjoyTheRestOfYourAdventure::
	.string "Dann viel Spaß noch beim Rumrennen!$"

SafariZone_South_Text_ExitEarlyThankYouForPlaying::
	.string "Alles klar.\p"
	.string "Her mit den restlichen BÄLLEN.\n"
	.string "Wir sehen uns beim nächsten Mal,\l"
	.string "wenn du wieder Geld loswerden willst.$"

Route121_SafariZoneEntrance_Text_WelcomeToSafariZone::
	.string "Willkommen in der SAFARI-ZONE!\p"
	.string "Hier kannst du POKéMON glotzen, die in\n"
	.string "HOENN eigentlich nichts zu suchen haben.\p"
	.string "Du siehst sie in ihrem natürlichen\n"
	.string "Habitatz…… oder was wir dafür halten.\p"
	.string "Und das Beste: Wir lassen jeden rein,\n"
	.string "der zahlt!\p"
	.string "Fang dir so viele du willst!\n"
	.string "Komm rein und lass dich nicht fressen!$"

Route121_SafariZoneEntrance_Text_WouldYouLikeToPlay::
	.string "Willkommen in der SAFARI-ZONE!\p"
	.string "Alles, was du fangen kannst, für nur\n"
	.string "500¥! Bock auf 'ne Runde SAFARI?$"

Route121_SafariZoneEntrance_Text_FirstTimeInfo::
	.string "Pass auf: Am Eingang kriegst du 30\n"
	.string "SAFARI-BÄLLE in die Hand gedrückt.\p"
	.string "Das Spiel ist vorbei, wenn du alle BÄLLE\n"
	.string "verballert hast oder 500 Schritte\l"
	.string "gelaufen bist.\p"
	.string "Und jetzt rein mit dir!$"

Route121_SafariZoneEntrance_Text_NotEnoughMoney::
	.string "Du hast nicht genug Kohle.\n"
	.string "Zisch ab!$"

Route121_SafariZoneEntrance_Text_PCIsFull::
	.string "Entschuldige mal!\n"
	.string "Dein PC-BOX-Speicher ist voll gemüllt.$"

Route121_SafariZoneEntrance_Text_YouNeedPokeblockCase::
	.string "He du! Ohne {POKEBLOCK}-BOX kommst du hier\n"
	.string "nicht weit.\p"
	.string "Die POKéMON hier sind wählerisch. Hol\n"
	.string "dir erst eine BOX in der WETTBEWERBS-\l"
	.string "HALLE von SEEGRASULB CITY!$"

SafariZone_South_Text_Man::
	.string "Ich will ja tiefer rein, aber ich\n"
	.string "hab mein RAD vergessen. Wie dumm……\p"
	.string "Irgendwie hab ich das Gefühl, dass die\n"
	.string "geilen POKéMON alle da hinten hocken.$"

SafariZone_Northwest_Text_Man::
	.string "(Keuch, Schnauf)……\n"
	.string "Ich bin endlich…… hier draußen……\p"
	.string "Aber ich bin so im Eimer, ich krieg\n"
	.string "kein POKéMON mehr gefangen……$"

SafariZone_Northeast_Text_Girl::
	.string "Oh, Mann!\n"
	.string "Ich fang hier absolut gar nichts!\p"
	.string "Wenn ich nicht bald was erwische, war\n"
	.string "der Eintritt voll für'n Arsch!$"

SafariZone_South_Text_Boy::
	.string "Wusstest du schon?\p"
	.string "Wenn du so einen {POKEBLOCK} in diesen Kasten\n"
	.string "da wirfst, kommen die Viecher angerannt\l"
	.string "wie zum Fressen.$"

SafariZone_Southwest_Text_Woman::
	.string "Manchmal werfe ich POKéMON einen\n"
	.string "{POKEBLOCK} hin und die ignorieren\l"
	.string "mich einfach.\p"
	.string "Haben die Viecher echt so 'nen\n"
	.string "anspruchsvollen Gaumen? Nervig!$"

SafariZone_North_Text_Fisherman::
	.string "Ich suche hier nach Wasser-POKéMON,\n"
	.string "die nicht so Standard sind wie Goldini.\p"
	.string "Wo ist hier eigentlich der verdammte See?$"

SafariZone_North_Text_Man::
	.string "Ich fang mir hier den ganzen seltenen\n"
	.string "Scheiß und tausch ihn dann gegen richtig\l"
	.string "gutes Zeug von meinen Kumpels ein!$"

SafariZone_South_Text_Youngster::
	.string "Ich hab 'nen {POKEBLOCK} in den Napf gelegt.\n"
	.string "Aber der ist schon wieder weg.\p"
	.string "Die müssen das Ding gefressen haben,\n"
	.string "als ich gerade nicht hingeguckt habe……$"

Route121_SafariZoneEntrance_Text_TrainerTip::
	.string "SAFARI-ZONE TRAINER-TIPPS!\p"
	.string "Wirf den POKéMON {POKEBLOCK}S vor den Latz,\n"
	.string "damit sie nicht sofort abhauen!$"

SafariZone_Southwest_Text_RestHouseSign::
	.string "“Leg deine Käsemuscheln hoch.”\n"
	.string "RASTHAUS$"

SafariZone_RestHouse_Text_Youngster::
	.string "Ich hab zwar keine {POKEBLOCK}S, aber ich\n"
	.string "hab trotzdem ordentlich was gefangen.\p"
	.string "Man muss sich einfach nur näher ran-\n"
	.string "schleichen, bevor man den BALL wirft!$"

SafariZone_RestHouse_Text_PsychicM::
	.string "Mit {POKEBLOCK}S hauen die Viecher nicht so\n"
	.string "schnell ab.\p"
	.string "Aber verschwende das Zeug nicht an\n"
	.string "POKéMON, die eh zu dumm zum Fliehen sind.$"

SafariZone_RestHouse_Text_FatMan::
	.string "Wenn du Futter in den Napf legst,\n"
	.string "lockst du sie an.\p"
	.string "Ich glaub, POKéMON mit demselben\n"
	.string "schrägen Wesen stehen auf\l"
	.string "dasselbe Zeug.$"

SafariZone_South_Text_AreaOffLimits1::
SafariZone_South_Text_AreaOffLimits2::
	.string "Hier wird noch gebaut. Du kommst hier\n"
	.string "nicht rein, verpiss dich!$"

SafariZone_Southeast_Text_ExpansionIsFinished::
	.string "Der Umbau der SAFARI-ZONE ist endlich\n"
	.string "fertig.\p"
	.string "Viel Spaß in dem neuen Bereich.$"

SafariZone_Southeast_Text_LittleGirl::
	.string "Boah! Krass! Ich hab diese POKéMON\n"
	.string "noch nie vorher gesehen!$"

SafariZone_Southeast_Text_FatMan::
	.string "Die POKéMON hier sind alle neu für mich.\p"
	.string "Und ich darf sie mir einfach krallen!\n"
	.string "Voll geil!$"

SafariZone_Southeast_Text_RichBoy::
	.string "Die POKéMON hier kommen wohl von\n"
	.string "irgendwo anders her, nicht aus HOENN.$"

SafariZone_Northeast_Text_Boy::
	.string "Ich hab nur noch zwei BÄLLE übrig……\p"
	.string "Jetzt muss ich mich echt entscheiden,\n"
	.string "welches Vieh ich damit abwerfe.$"

SafariZone_Northeast_Text_Woman::
	.string "Man sagt, hier gibt's PIKACHU.\n"
	.string "Wo steckt die gelbe Ratte?$"

SafariZone_South_Text_Robball::
	.string "Tipp:\p"
	.string "Auf dieser Route versteckt sich ein\n"
	.string "Starter aus der 7 Generation mit\l"
	.string "einer Spawnrate von 1%!\p"
	.string "Welches es ist, musst du selbst\n"
	.string "herausfinden :D !$"

SafariZone_South_Text_RobballRandomizer::
	.string "Tipp:\p"
	.string "Wild-Randomizer ist aktiv.\n"
	.string "Der feste 1%-Starter-Hinweis\l"
	.string "gilt deshalb hier nicht.\p"
	.string "Die Wild-Spawns werden über deinen\n"
	.string "Seed neu gemappt!$"

SafariZone_Southwest_Text_Chimpep::
	.string "Tipp:\p"
	.string "Auf dieser Route versteckt sich ein\n"
	.string "Starter aus der 8 Generation mit\l"
	.string "einer Spawnrate von 1%!\p"
	.string "Welches es ist, musst du selbst\n"
	.string "herausfinden :D !$"

SafariZone_Southwest_Text_ChimpepRandomizer::
	.string "Tipp:\p"
	.string "Wild-Randomizer ist aktiv.\n"
	.string "Der feste 1%-Starter-Hinweis\l"
	.string "gilt deshalb hier nicht.\p"
	.string "Die Wild-Spawns werden über deinen\n"
	.string "Seed neu gemappt!$"

SafariZone_Northwest_Text_Hopplo::
	.string "Tipp:\p"
	.string "Auf dieser Route versteckt sich ein\n"
	.string "Starter aus der 8 Generation mit\l"
	.string "einer Spawnrate von 1%!\p"
	.string "Welches es ist, musst du selbst\n"
	.string "herausfinden :D !$"

SafariZone_Northwest_Text_HopploRandomizer::
	.string "Tipp:\p"
	.string "Wild-Randomizer ist aktiv.\n"
	.string "Der feste 1%-Starter-Hinweis\l"
	.string "gilt deshalb hier nicht.\p"
	.string "Die Wild-Spawns werden über deinen\n"
	.string "Seed neu gemappt!$"

SafariZone_North_Text_Memmeon::
	.string "Tipp:\p"
	.string "Auf dieser Route versteckt sich ein\n"
	.string "Starter aus der 8 Generation mit\l"
	.string "einer Spawnrate von 1%!\p"
	.string "Welches es ist, musst du selbst\n"
	.string "herausfinden :D !$"

SafariZone_North_Text_MemmeonRandomizer::
	.string "Tipp:\p"
	.string "Wild-Randomizer ist aktiv.\n"
	.string "Der feste 1%-Starter-Hinweis\l"
	.string "gilt deshalb hier nicht.\p"
	.string "Die Wild-Spawns werden über deinen\n"
	.string "Seed neu gemappt!$"

SafariZone_Northeast_Text_Krokel::
	.string "Tipp:\p"
	.string "Auf dieser Route versteckt sich ein\n"
	.string "Starter aus der 9 Generation mit\l"
	.string "einer Spawnrate von 1%!\p"
	.string "Welches es ist, musst du selbst\n"
	.string "herausfinden :D !$"

SafariZone_Northeast_Text_KrokelRandomizer::
	.string "Tipp:\p"
	.string "Wild-Randomizer ist aktiv.\n"
	.string "Der feste 1%-Starter-Hinweis\l"
	.string "gilt deshalb hier nicht.\p"
	.string "Die Wild-Spawns werden über deinen\n"
	.string "Seed neu gemappt!$"

SafariZone_Southeast_Text_Felori::
	.string "Tipp:\p"
	.string "Auf dieser Route versteckt sich ein\n"
	.string "Starter aus der 9 Generation mit\l"
	.string "einer Spawnrate von 1%!\p"
	.string "Welches es ist, musst du selbst\n"
	.string "herausfinden :D !$"

SafariZone_Southeast_Text_FeloriRandomizer::
	.string "Tipp:\p"
	.string "Wild-Randomizer ist aktiv.\n"
	.string "Der feste 1%-Starter-Hinweis\l"
	.string "gilt deshalb hier nicht.\p"
	.string "Die Wild-Spawns werden über deinen\n"
	.string "Seed neu gemappt!$"

Route121_SafariZoneEntrance_Text_WelcomeFirstTime:
	.string "Willkommen in der SAFARI-ZONE.\n"
	.string "Willst du hier echt rumgurken? Passt\l"
	.string "bloß auf meine POKéMON auf!$"

Route121_SafariZoneEntrance_Text_ComeInAndEnjoy:
	.string "Ja, ja, geh schon rein und nerv die\n"
	.string "Viecher nicht so sehr.$"

Route121_SafariZoneEntrance_Text_PlayAnotherTime:
	.string "Dann eben nicht. Zisch ab und verschwende\n"
	.string "nicht meine Zeit!$"

Route121_SafariZoneEntrance_Text_ThatWillBe500Please:
	.string "Das macht 500 Pokedollar Eintritt.\n"
	.string "Rück die Kohle sofort raus!$"

Route121_SafariZoneEntrance_Text_HereAreYourSafariBalls:
	.string "Hier, nimm diese dämlichen BÄLLE.$"

Route121_SafariZoneEntrance_Text_Received30SafariBalls:
	.string "{PLAYER} hat 30 SAFARI-BÄLLE erhalten.\n"
	.string "Was für'ne Verschwendung...$"

Route121_SafariZoneEntrance_Text_PleaseEnjoyYourself:
	.string "Viel Spaß beim Versagen! Komm bloß nicht\n"
	.string "zu früh wieder zurück.$"

SafariZone_South_Text_GoodLuck:
	.string "Viel Glück da drin. Du wirst es echt\n"
	.string "brauchen, so wie du aussiehst!$"
