FortreeCity_House5_MapScripts::
	.byte 0

FortreeCity_House5_EventScript_PokefanF::
	msgbox FortreeCity_House5_Text_TreeHousesAreGreat, MSGBOX_NPC
	end

FortreeCity_House5_EventScript_Man::
	msgbox FortreeCity_House5_Text_AdaptedToNature, MSGBOX_NPC
	end

FortreeCity_House5_EventScript_Zigzagoon::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ZIGZAGOON, CRY_MODE_NORMAL
	msgbox FortreeCity_House5_Text_Zigzagoon, MSGBOX_DEFAULT
	waitmoncry
	release
	end

FortreeCity_House5_Text_TreeHousesAreGreat::
	.string "Die Baumhäuser hier in BAUMHAUSEN\n"
	.string "sind der absolute Hammer!\p"
	.string "Wer in 'ner normalen Bude wohnt, hat\n"
	.string "die Kontrolle über sein Leben verloren.\l"
	.string "Hier oben ist man unter sich!$"

FortreeCity_House5_Text_AdaptedToNature::
	.string "Wir hängen hier am Tropf der Natur,\n"
	.string "ob du's glaubst oder nicht.\p"
	.string "Nur ignorante Stadt-Deppen versuchen,\n"
	.string "der Welt ihren Willen aufzuzwingen.\l"
	.string "Friss den Matsch oder geh weg!$"

FortreeCity_House5_Text_Zigzagoon::
	.string "ZIGZACHS: Bufuu! (Verpiss dich!)$"

