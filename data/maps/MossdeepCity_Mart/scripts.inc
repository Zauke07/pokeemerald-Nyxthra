MossdeepCity_Mart_MapScripts::
	.byte 0

MossdeepCity_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart MossdeepCity_Mart_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
MossdeepCity_Mart_Pokemart:
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_NET_BALL
	.2byte ITEM_DIVE_BALL
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_REVIVE
	.2byte ITEM_MAX_REPEL
	.2byte ITEM_X_ATTACK
	.2byte ITEM_X_DEFENSE
	pokemartlistend

MossdeepCity_Mart_EventScript_Woman::
	msgbox MossdeepCity_Mart_Text_ReviveIsFantastic, MSGBOX_NPC
	end

MossdeepCity_Mart_EventScript_Boy::
	msgbox MossdeepCity_Mart_Text_MaxRepelLastsLongest, MSGBOX_NPC
	end

MossdeepCity_Mart_EventScript_Sailor::
	msgbox MossdeepCity_Mart_Text_NetAndDiveBallsRare, MSGBOX_NPC
	end

MossdeepCity_Mart_Text_ReviveIsFantastic:
	.string "Beleber ist komplett OP!\p"
	.string "Pump das Zeug in ein abgekratztes Pokémon\n"
	.string "und das Vieh spawnt direkt neu.\p"
	.string "Aber chill mal, das füllt null AP auf.\n"
	.string "Dein Opfer-Team muss also trotzdem\l"
	.string "Attacken sparen, du Lappen.$"

MossdeepCity_Mart_Text_MaxRepelLastsLongest:
	.string "Top-Schutz ist quasi Deo gegen diese\n"
	.string "ganzen nervigen Trash-Mobs.\p"
	.string "Von den ganzen Sprays hier hält das am\n"
	.string "längsten. Perfekt für Noobs wie dich,\l"
	.string "die vor jedem Kampf heulend wegrennen.$"

MossdeepCity_Mart_Text_NetAndDiveBallsRare:
	.string "Netzbälle und Tauchbälle sind richtig rare\n"
	.string "Items. Die werden nur hier in Moosbach\l"
	.string "zusammengeklöppelt.\p"
	.string "Netzbälle sind der Shit gegen eklige\n"
	.string "Käfer und diese nassen Wasser-Viecher.\p"
	.string "Und der Tauchball ist dein bester Bro,\n"
	.string "wenn du Monster aus der tiefsten\l"
	.string "Meeresritze kratzen willst.$"

