@ Nyxthra: Rosalhöhle UG - von Team Rocket freigebohrter Stollen.
Rosalhoehle_B1F_MapScripts::
	.byte 0

Rosalhoehle_B1F_EventScript_Rocket1::
	trainerbattle_single TRAINER_ROSAL_ROCKET_1, Rosalhoehle_B1F_Text_Rocket1Intro, Rosalhoehle_B1F_Text_Rocket1Defeat
	msgbox Rosalhoehle_B1F_Text_Rocket1After, MSGBOX_AUTOCLOSE
	end

Rosalhoehle_B1F_EventScript_Rocket2::
	trainerbattle_single TRAINER_ROSAL_ROCKET_2, Rosalhoehle_B1F_Text_Rocket2Intro, Rosalhoehle_B1F_Text_Rocket2Defeat
	msgbox Rosalhoehle_B1F_Text_Rocket2After, MSGBOX_AUTOCLOSE
	end

Rosalhoehle_B1F_EventScript_Rocket3::
	trainerbattle_single TRAINER_ROSAL_ROCKET_3, Rosalhoehle_B1F_Text_Rocket3Intro, Rosalhoehle_B1F_Text_Rocket3Defeat
	msgbox Rosalhoehle_B1F_Text_Rocket3After, MSGBOX_AUTOCLOSE
	end

Rosalhoehle_B1F_EventScript_DrillMarks::
	msgbox Rosalhoehle_B1F_Text_DrillMarks, MSGBOX_SIGN
	end

Rosalhoehle_B1F_Text_Rocket1Intro:
	.string "Halt! Dieser Stollen ist Sperrgebiet\n"
	.string "von Team ROCKET!\p"
	.string "Ein Kind wie du hat hier unten\n"
	.string "nichts verloren!$"

Rosalhoehle_B1F_Text_Rocket1Defeat:
	.string "Was?! Von einem Kind besiegt…$"

Rosalhoehle_B1F_Text_Rocket1After:
	.string "Wir graben hier nicht nach Gold.\n"
	.string "Wir graben nach etwas viel Besserem.\p"
	.string "Mehr verrate ich dir nicht!$"

Rosalhoehle_B1F_Text_Rocket2Intro:
	.string "Du hast unsere Bohrgeräusche\n"
	.string "gehört, was?\p"
	.string "Neugier ist gefährlich, Kleines!$"

Rosalhoehle_B1F_Text_Rocket2Defeat:
	.string "Ich hab mir die Nägel\n"
	.string "abgebrochen… und verloren!$"

Rosalhoehle_B1F_Text_Rocket2After:
	.string "Unter dieser Stadt liegt eine Ader\n"
	.string "aus NYX-KRISTALL.\p"
	.string "Die Steine leuchten nachts violett.\n"
	.string "Davon hat hier oben keiner Ahnung!$"

Rosalhoehle_B1F_Text_Rocket3Intro:
	.string "Ich bewache den Weg nach unten.\n"
	.string "Zum Labor kommst du nicht!$"

Rosalhoehle_B1F_Text_Rocket3Defeat:
	.string "Ugh… JESSIE wird mich\n"
	.string "dafür fertigmachen…$"

Rosalhoehle_B1F_Text_Rocket3After:
	.string "Unten arbeitet JESSIE an einem\n"
	.string "Gerät, das Pokémon verwandeln kann.\p"
	.string "Die Pokémon sehen danach seltsam\n"
	.string "aus… und irgendwie leer.$"

Rosalhoehle_B1F_Text_DrillMarks:
	.string "Frische Bohrspuren im Fels…\p"
	.string "In den Rissen glitzert ein\n"
	.string "schwach violetter Kristall.$"
