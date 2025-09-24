GraniteCave_B1F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CaveHole_CheckFallDownHole
	map_script MAP_SCRIPT_ON_TRANSITION, CaveHole_FixCrackedGround
	map_script MAP_SCRIPT_ON_RESUME, GraniteCave_B1F_SetHoleWarp
	.byte 0

GraniteCave_B1F_SetHoleWarp:
	setstepcallback STEP_CB_CRACKED_FLOOR
	setholewarp MAP_GRANITE_CAVE_B2F
	end

GraniteCave_B1F_EventScript_BrailleSage::
	msgbox GraniteCave_B1F_Text_BrailleSage, MSGBOX_DEFAULT
	closemessage
	end

GraniteCave_B1F_Text_BrailleSage:
	.string "…Du spürst die Dunkelheit dieser\n"
	.string "Höhle, nicht wahr?\p"
	.string "Hier sind Zeichen verborgen…\n"
	.string "die alte Blindenschrift.\p"
	.string "Manche sagen, sie sei unverständlich.\n"
	.string "Aber wer schlau ist, sucht bei Google:\l"
	.string "“Pokémon Smaragd Braille Schrift”\p"
	.string "Auf PokéWiki findest du das Alphabet.\p"
	.string "Doch nimm dir Papier und Stift -\n"
	.string "denn Wissen will niedergeschrieben\l"
	.string "werden…$"
