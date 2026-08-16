MossdeepCity_House1_MapScripts::
	.byte 0

MossdeepCity_House1_EventScript_BlackBelt::
	lock
	faceplayer
	bufferleadmonspeciesname STR_VAR_1
	msgbox MossdeepCity_House1_Text_HmmYourPokemon, MSGBOX_DEFAULT
	specialvar VAR_RESULT, GetPokeblockNameByMonNature
	goto_if_eq VAR_RESULT, 0, MossdeepCity_House1_EventScript_NeutralNature
	msgbox MossdeepCity_House1_Text_ItLikesXPokeblocks, MSGBOX_DEFAULT
	release
	end

MossdeepCity_House1_EventScript_NeutralNature::
	msgbox MossdeepCity_House1_Text_DoesntLikeOrDislikePokeblocks, MSGBOX_DEFAULT
	release
	end

MossdeepCity_House1_EventScript_Woman::
	msgbox MossdeepCity_House1_Text_HusbandCanTellPokeblockMonLikes, MSGBOX_NPC
	end

MossdeepCity_House1_Text_HmmYourPokemon:
	.string "Ey!\n"
	.string "Dein hässliches {STR_VAR_1}…$"

MossdeepCity_House1_Text_ItLikesXPokeblocks:
	.string "Das Vieh frisst am liebsten {STR_VAR_1},\n"
	.string "hab ich recht?\p"
	.string "Scheiß drauf, ich weiß es einfach!\n"
	.string "Das Ding geiert komplett auf\l"
	.string "{STR_VAR_1}! Richtiger Fettsack!$"

MossdeepCity_House1_Text_DoesntLikeOrDislikePokeblocks:
	.string "Dem Vieh ist es komplett scheißegal,\n"
	.string "was für {POKEBLOCK} du ihm in die Fresse\l"
	.string "stopfst. Hat null Geschmack, das Opfer.$"

MossdeepCity_House1_Text_HusbandCanTellPokeblockMonLikes:
	.string "Mein Macker ist komplett hängen\n"
	.string "geblieben. Der sieht auf einen Blick,\l"
	.string "welche {POKEBLOCK} dein Vieh am liebsten\l"
	.string "in seinen Schlund reinorgelt.$"

