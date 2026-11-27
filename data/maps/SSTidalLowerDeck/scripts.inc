SSTidalLowerDeck_MapScripts::
	.byte 0

SSTidalLowerDeck_EventScript_Phillip::
	trainerbattle_single TRAINER_PHILLIP, SSTidalLowerDeck_Text_PhillipIntro, SSTidalLowerDeck_Text_PhillipDefeat
	msgbox SSTidalLowerDeck_Text_PhillipPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalLowerDeck_EventScript_Leonard::
	trainerbattle_single TRAINER_LEONARD, SSTidalLowerDeck_Text_LeonardIntro, SSTidalLowerDeck_Text_LeonardDefeat
	msgbox SSTidalLowerDeck_Text_LeonardPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalLowerDeck_Text_PhillipIntro:
	.string "Arrrgh! Ich hab die Nase voll und bin\n"
	.string "totmüde vom Putzen dieses riesigen\l"
	.string "Kahns!\p"
	.string "Lass uns schnell kämpfen!$"

SSTidalLowerDeck_Text_PhillipDefeat:
	.string "Brüderchen, ich habe verloren!$"

SSTidalLowerDeck_Text_PhillipPostBattle:
	.string "Wir sind die PUTZ-BRÜDER!\p"
	.string "Der Alte kippt das Putzmittel aus,\n"
	.string "und der Junge schrubbt.$"

SSTidalLowerDeck_Text_LeonardIntro:
	.string "Hier ist der Boden des Schiffsrumpfs.\n"
	.string "Hier ist jede Menge Platz.\l"
	.string "Für einen Pokémon-Kampf reicht es.$"

SSTidalLowerDeck_Text_LeonardDefeat:
	.string "Großer Bruder, ich habe verloren!$"

SSTidalLowerDeck_Text_LeonardPostBattle:
	.string "Wir sind die PUTZ-BRÜDER!\p"
	.string "Der Alte kippt das Putzmittel aus,\n"
	.string "und der Junge schrubbt.$"

