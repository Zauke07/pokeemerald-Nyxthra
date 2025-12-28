PetalburgCity_House1_MapScripts::
	.byte 0

PetalburgCity_House1_EventScript_Man::
	msgbox PetalburgCity_House1_Text_TravelingIsWonderful, MSGBOX_NPC
	end

PetalburgCity_House1_EventScript_Woman::
	msgbox PetalburgCity_House1_Text_GoOnAdventure, MSGBOX_NPC
	end

PetalburgCity_House1_Text_TravelingIsWonderful:
	.string "Mein Junge… Reisen war früher das Größte!\p"
	.string "Ich bin über Berge gekraxelt und hab\n"
	.string "in Höhlen gepennt. Ganz ohne Navi!\p"
	.string "Damals… da gab’s noch keine PokéNavs!\p"
	.string "Oder… was war das Ding nochmal…?\n"
	.string "Egal. Abenteuer halt!$"
    .string "Aber heute? Heute ist alles viel zu\n"
    .string "Teuer. Und die Kinder sind viel zu\n"
    .string "verwöhnt. Früher war alles besser!$"

PetalburgCity_House1_Text_GoOnAdventure:
	.string "Seufz…\p"
	.string "Mein Mann lebt komplett in der Vergangenheit.\p"
	.string "Ich bin 38, er ist 70 - frag nicht, wie\n"
	.string "das passiert ist. Liebe oder so.\p"
	.string "Und unser Sohn?\n"
	.string "Hängt nur am GameBoy und redet vom\n"
	.string "“iPhone Wecker“, um schlafende Pokémon\n"
	.string "aufzuwecken. Hilfe.$"

PetalburgCity_House1_EventScript_iPhoneWecker::
	msgbox PetalburgCity_Text_iPhoneWecker, MSGBOX_NPC
	end

PetalburgCity_Text_iPhoneWecker:
	.string "Ich hab voll den Trick:\p"
	.string "Wenn ein Pokémon schläft, einfach den\n"
	.string "iPhone Wecker auf volle Pulle stellen!\p"
	.string "Das wirkt sogar bei Relaxo… Vielleicht.\p"
	.string "Ich darf noch kein echtes Pokémon haben…\n"
	.string "Aber bald! Dann krieg ich Glurak in Shiny!$"
