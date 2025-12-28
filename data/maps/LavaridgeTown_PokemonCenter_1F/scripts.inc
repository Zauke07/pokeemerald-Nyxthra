LavaridgeTown_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LavaridgeTown_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

LavaridgeTown_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_LAVARIDGE_TOWN
	call Common_EventScript_UpdateBrineyLocation
	end

LavaridgeTown_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_LAVARIDGE_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

LavaridgeTown_PokemonCenter_1F_EventScript_Youngster::
	msgbox LavaridgeTown_PokemonCenter_1F_Text_HotSpringCanInvigorate, MSGBOX_NPC
	end

LavaridgeTown_PokemonCenter_1F_EventScript_Woman::
	msgbox LavaridgeTown_PokemonCenter_1F_Text_TrainersPokemonSpendTimeTogether, MSGBOX_NPC
	end

LavaridgeTown_PokemonCenter_1F_EventScript_Gentleman::
	msgbox LavaridgeTown_PokemonCenter_1F_Text_TrainersShouldRestToo, MSGBOX_NPC
	end

LavaridgeTown_PokemonCenter_1F_Text_TrainersPokemonSpendTimeTogether::
	.string "Ich glaub ja, dass POKéMON zahmer werden,\n"
	.string "wenn man ständig mit ihnen abhängt.\p"
	.string "Je länger, desto besser.\n"
	.string "Dann merken sie wohl irgendwann nicht\l"
	.string "mehr, was du für 'n Vogel bist.$"

LavaridgeTown_PokemonCenter_1F_Text_HotSpringCanInvigorate::
	.string "Schon fast unheimlich, wie man sich\n"
	.string "wieder wie ein Mensch fühlt, wenn man\l"
	.string "in der heißen Suppe da draußen hockt.\p"
	.string "Eigentlich müsste ich meine POKéMON\n"
	.string "da auch mal reinschmeißen, damit sie\l"
	.string "endlich aufhören zu schwächeln.$"

LavaridgeTown_PokemonCenter_1F_Text_TrainersShouldRestToo::
	.string "Hohoho! Ey, Kleiner, durch die Hintertür\n"
	.string "kommst du direkt zu den Quellen.\p"
	.string "Wenn deine Viecher schon hier drin\n"
	.string "gepäppelt werden, solltest du deinen\l"
	.string "Hintern auch mal im Wasser parken.$"
