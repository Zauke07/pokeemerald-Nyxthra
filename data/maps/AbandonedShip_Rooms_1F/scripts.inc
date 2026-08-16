AbandonedShip_Rooms_1F_MapScripts::
	.byte 0

AbandonedShip_Rooms_1F_EventScript_Gentleman::
	msgbox AbandonedShip_Rooms_1F_Text_TakingALookAround, MSGBOX_NPC
	end

AbandonedShip_Rooms_1F_EventScript_Demetrius::
	trainerbattle_single TRAINER_DEMETRIUS, AbandonedShip_Rooms_1F_Text_DemetriusIntro, AbandonedShip_Rooms_1F_Text_DemetriusDefeat
	msgbox AbandonedShip_Rooms_1F_Text_DemetriusPostBattle, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Rooms_1F_EventScript_Thalia::
	trainerbattle_single TRAINER_THALIA_1, AbandonedShip_Rooms_1F_Text_ThaliaIntro, AbandonedShip_Rooms_1F_Text_ThaliaDefeat, AbandonedShip_Rooms_1F_EventScript_RegisterThalia
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, AbandonedShip_Rooms_1F_EventScript_ThaliaRematch
	msgbox AbandonedShip_Rooms_1F_Text_ThaliaPostBattle, MSGBOX_DEFAULT
	release
	end

AbandonedShip_Rooms_1F_EventScript_RegisterThalia::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox AbandonedShip_Rooms_1F_Text_ThaliaRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_THALIA_1
	release
	end

AbandonedShip_Rooms_1F_EventScript_ThaliaRematch::
	trainerbattle_rematch TRAINER_THALIA_1, AbandonedShip_Rooms_1F_Text_ThaliaRematchIntro, AbandonedShip_Rooms_1F_Text_ThaliaRematchDefeat
	msgbox AbandonedShip_Rooms_1F_Text_ThaliaPostRematch, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Rooms_1F_Text_TakingALookAround:
	.string "Schiffe dieser Art sind selten, also\n"
	.string "schaue ich mich hier mal um.\p"
	.string "Hmhm…\n"
	.string "Sieht so aus, als gäbe es noch weitere Kabinen…$"

AbandonedShip_Rooms_1F_Text_ThaliaIntro:
	.string "Was bringt dich bitte dazu,\n"
	.string "ausgerechnet hierherzukommen? Du bist echt neugierig!$"

AbandonedShip_Rooms_1F_Text_ThaliaDefeat:
	.string "Nicht nur neugierig, sondern auch stark…$"

AbandonedShip_Rooms_1F_Text_ThaliaPostBattle:
	.string "Der Mann nebenan…\p"
	.string "Er behauptet, er schaut sich nur um,\n"
	.string "aber ich traue der Sache nicht.$"

AbandonedShip_Rooms_1F_Text_ThaliaRegister:
	.string "Du bist echt ein harter TRAINER!\n"
	.string "Ich registriere dich als Andenken!$"

AbandonedShip_Rooms_1F_Text_ThaliaRematchIntro:
	.string "Was bringt dich bitte dazu,\n"
	.string "schon wieder hier aufzutauchen? Du bist echt nicht zu bremsen!$"

AbandonedShip_Rooms_1F_Text_ThaliaRematchDefeat:
	.string "Bist du nicht ein bisschen zu stark?$"

AbandonedShip_Rooms_1F_Text_ThaliaPostRematch:
	.string "Ich bin sicher, der Typ führt was im Schilde!\n"
	.string "Der benimmt sich einfach zu verdächtig!$"

AbandonedShip_Rooms_1F_Text_DemetriusIntro:
	.string "Waaah!\n"
	.string "Ich wurde gefunden! …Hä?$"

AbandonedShip_Rooms_1F_Text_DemetriusDefeat:
	.string "Oh… du bist gar nicht meine Mom.$"

AbandonedShip_Rooms_1F_Text_DemetriusPostBattle:
	.string "Ich hab Ärger mit meiner Mom, deshalb bin ich abgehauen.\n"
	.string "Bitte verrat nicht, wo ich hocke, okay?$"

