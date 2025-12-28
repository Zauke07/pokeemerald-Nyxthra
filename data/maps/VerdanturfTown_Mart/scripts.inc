VerdanturfTown_Mart_MapScripts::
	.byte 0

VerdanturfTown_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart VerdanturfTown_Mart_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
VerdanturfTown_Mart_Pokemart:
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_NEST_BALL
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_BURN_HEAL
	.2byte ITEM_ICE_HEAL
	.2byte ITEM_REPEL
	.2byte ITEM_X_SP_ATK
	.2byte ITEM_FLUFFY_TAIL
	pokemartlistend

VerdanturfTown_Mart_EventScript_Boy::
	msgbox VerdanturfTown_Mart_Text_XSpecialIsCrucial, MSGBOX_NPC
	end

VerdanturfTown_Mart_EventScript_ExpertF::
	msgbox VerdanturfTown_Mart_Text_NoStrategyGuidesForBattleTent, MSGBOX_NPC
	end

VerdanturfTown_Mart_EventScript_Lass::
	msgbox VerdanturfTown_Mart_Text_NestBallOnWeakenedPokemon, MSGBOX_NPC
	end

VerdanturfTown_Mart_Text_XSpecialIsCrucial::
	.string "X-SPEZIAL ist für Versager wie dich\n"
	.string "eigentlich Pflicht.\p"
	.string "Es pumpt die Attacken künstlich auf,\n"
	.string "damit du überhaupt mal triffst.\l"
	.string "Nach dem Kampf ist der Effekt aber weg.\l"
	.string "Genau wie dein mickriges Taschengeld!$"

VerdanturfTown_Mart_Text_NoStrategyGuidesForBattleTent::
	.string "Echte Strategie-Ratgeber für das\n"
	.string "KAMPFCAMP verkaufen die hier nicht.\p"
	.string "Wahrscheinlich, weil die meisten Idioten\n"
	.string "hier eh nicht lesen können.\l"
	.string "Musst wohl selbst schauen, wie du\l"
	.string "da drin nicht komplett abkackst.$"

VerdanturfTown_Mart_Text_NestBallOnWeakenedPokemon::
	.string "Der NESTBALL ist perfekt für Luschen-\n"
	.string "POKéMON auf niedrigem Level.\p"
	.string "Gibt’s nur hier in diesem Kaff.\n"
	.string "Passt ja auch: Ein Ball für Babys in\l"
	.string "einem Dorf voller Heulsusen.$"


