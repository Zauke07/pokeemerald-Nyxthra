RustboroCity_Flat2_2F_MapScripts::
	.byte 0

RustboroCity_Flat2_2F_EventScript_OldMan::
	msgbox RustboroCity_Flat2_2F_Text_DevonWasTinyInOldDays, MSGBOX_NPC
	end

RustboroCity_Flat2_2F_EventScript_NinjaBoy::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_PREMIER_BALL_RUSTBORO, RustboroCity_Flat2_2F_EventScript_GavePremierBall
	msgbox RustboroCity_Flat2_2F_Text_MyDaddyMadeThisYouCanHaveIt, MSGBOX_DEFAULT
	giveitem ITEM_PREMIER_BALL
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_PREMIER_BALL_RUSTBORO
	release
	end

RustboroCity_Flat2_2F_EventScript_GavePremierBall::
	msgbox RustboroCity_Flat2_2F_Text_GoingToWorkAtDevonToo, MSGBOX_DEFAULT
	release
	end

RustboroCity_Flat2_2F_Text_DevonWasTinyInOldDays:
	.string "Weißt du... Früher war DEVON mal klein.\n"
	.string "So richtig winzig. Ein Büro, ein\l"
	.string "Kaffeekocher, und ein Traum.$"

RustboroCity_Flat2_2F_Text_MyDaddyMadeThisYouCanHaveIt:
	.string "Mein Papa arbeitet bei DEVON!\p"
	.string "Er hat das hier gebaut - cool, oder?\n"
	.string "Ich weiß nicht mal, wie man es benutzt…\l"
	.string "Also kannst du es haben.$"

RustboroCity_Flat2_2F_Text_GoingToWorkAtDevonToo:
	.string "Mein Papa arbeitet für DEVON.\p"
	.string "Und wenn ich groß bin, arbeite ich da auch!\n"
	.string "Oder ich gründe NEO-DEVON!$"
