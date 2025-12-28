FallarborTown_Mart_MapScripts::
	.byte 0

FallarborTown_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart FallarborTown_Mart_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
FallarborTown_Mart_Pokemart:
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_ESCAPE_ROPE
	.2byte ITEM_SUPER_REPEL
	.2byte ITEM_X_SP_ATK
	.2byte ITEM_X_SPEED
	.2byte ITEM_X_ATTACK
	.2byte ITEM_X_DEFENSE
	.2byte ITEM_DIRE_HIT
	.2byte ITEM_GUARD_SPEC
	pokemartlistend

FallarborTown_Mart_EventScript_Woman::
	msgbox FallarborTown_Mart_Text_DecidingSkittyEvolve, MSGBOX_NPC
	end

FallarborTown_Mart_EventScript_PokefanM::
	msgbox FallarborTown_Mart_Text_SellNuggetIFound, MSGBOX_NPC
	end

FallarborTown_Mart_EventScript_Skitty::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SKITTY, CRY_MODE_NORMAL
	msgbox FallarborTown_Mart_Text_Skitty, MSGBOX_DEFAULT
	waitmoncry
	release
	end

FallarborTown_Mart_Text_DecidingSkittyEvolve::
	.string "Ich kann mich echt nicht entscheiden,\n"
	.string "ob ich mein ENECO entwickeln soll.\p"
	.string "Ich müsste nur diesen MONSTEIN drauf-\n"
	.string "werfen, aber das ist so ein Drama…\p"
	.string "Klar, es wäre dann viel stärker und\n"
	.string "würde nicht bei jedem Windstoß umkippen.\p"
	.string "Aber es sieht danach so… anders aus.\n"
	.string "Passt das dann überhaupt noch zu\l"
	.string "meiner Tasche? Echt schwierig!$"

FallarborTown_Mart_Text_Skitty::
	.string "ENECO: Miyao? (Lass mich bloß in Ruh!)$"

FallarborTown_Mart_Text_SellNuggetIFound::
	.string "Diesen NUGGET hab ich hier gefunden…\n"
	.string "Ich werd den Klumpen wohl verkaufen,\l"
	.string "weil er sonst zu nichts gut ist.\p"
	.string "Wenigstens kann ich mir von der Kohle\n"
	.string "was Ordentliches kaufen, statt in\l"
	.string "diesem staubigen Loch zu versauern.$"

