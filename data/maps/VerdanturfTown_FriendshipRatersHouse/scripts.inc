VerdanturfTown_FriendshipRatersHouse_MapScripts::
	.byte 0

VerdanturfTown_FriendshipRatersHouse_EventScript_FriendshipRater::
	lock
	faceplayer
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_SeeHowMuchPokemonLikesYou, MSGBOX_DEFAULT
	specialvar VAR_RESULT, GetLeadMonFriendshipScore
	switch VAR_RESULT
	case FRIENDSHIP_NONE, VerdanturfTown_FriendshipRatersHouse_EventScript_DetestsYou
	case FRIENDSHIP_1_TO_49, VerdanturfTown_FriendshipRatersHouse_EventScript_VeryWary
	case FRIENDSHIP_50_TO_99, VerdanturfTown_FriendshipRatersHouse_EventScript_NotUsedToYou
	case FRIENDSHIP_100_TO_149, VerdanturfTown_FriendshipRatersHouse_EventScript_GettingUsedToYou
	case FRIENDSHIP_150_TO_199, VerdanturfTown_FriendshipRatersHouse_EventScript_LikesYouQuiteALot
	case FRIENDSHIP_200_TO_254, VerdanturfTown_FriendshipRatersHouse_EventScript_VeryHappy
	case FRIENDSHIP_MAX, VerdanturfTown_FriendshipRatersHouse_EventScript_AdoresYou
	release
	end

VerdanturfTown_FriendshipRatersHouse_EventScript_DetestsYou::
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_DetestsYou, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_FriendshipRatersHouse_EventScript_VeryWary::
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_VeryWary, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_FriendshipRatersHouse_EventScript_NotUsedToYou::
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_NotUsedToYou, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_FriendshipRatersHouse_EventScript_GettingUsedToYou::
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_GettingUsedToYou, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_FriendshipRatersHouse_EventScript_LikesYouQuiteALot::
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_LikesYouQuiteALot, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_FriendshipRatersHouse_EventScript_VeryHappy::
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_VeryHappy, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_FriendshipRatersHouse_EventScript_AdoresYou::
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_AdoresYou, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_FriendshipRatersHouse_EventScript_Pikachu::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_PIKACHU, CRY_MODE_NORMAL
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_Pikachu, MSGBOX_DEFAULT
	waitmoncry
	release
	end

VerdanturfTown_FriendshipRatersHouse_Text_SeeHowMuchPokemonLikesYou::
	.string "Was willst du? Zeig mir dein Vieh.\n"
	.string "Ich sag dir dann, wie sehr es unter\l"
	.string "deiner miesen Behandlung leidet.\p"
	.string "Oh.\n"
	.string "Dieses POKéMON…$"

VerdanturfTown_FriendshipRatersHouse_Text_AdoresYou::
	.string "Es liebt dich abgöttisch. Warum auch\n"
	.string "immer. Wahrscheinlich hat es das\l"
	.string "Stockholm-Syndrom.\l"
	.string "Echt traurig, sowas mitanzusehen.$"

VerdanturfTown_FriendshipRatersHouse_Text_VeryHappy::
	.string "Es scheint glücklich zu sein.\n"
	.string "Vielleicht ist es auch einfach nur\l"
	.string "bescheuert und merkt nicht, was du\l"
	.string "für ein Vogel bist.$"

VerdanturfTown_FriendshipRatersHouse_Text_LikesYouQuiteALot::
	.string "Es mag dich wohl ganz okay.\n"
	.string "Es will wahrscheinlich nur mehr Futter\l"
	.string "und ein warmes Bett. Erwarte nicht,\l"
	.string "dass es für dich stirbt.$"

VerdanturfTown_FriendshipRatersHouse_Text_GettingUsedToYou::
	.string "Es gewöhnt sich langsam an deine Fratze.\n"
	.string "Noch hat es die Hoffnung nicht aufgegeben,\l"
	.string "dass du irgendwann mal was raffst.$"

VerdanturfTown_FriendshipRatersHouse_Text_NotUsedToYou::
	.string "Dem Teil bist du völlig egal.\n"
	.string "Es würde nicht mal zucken, wenn du\l"
	.string "über eine Klippe springst.$"

VerdanturfTown_FriendshipRatersHouse_Text_VeryWary::
	.string "Es starrt dich an, als würde es dir\n"
	.string "nachts die Kehle durchschneiden.\p"
	.string "Diese Bösartigkeit in den Augen…\n"
	.string "Es hasst dich abgrundtief!$"

VerdanturfTown_FriendshipRatersHouse_Text_DetestsYou::
	.string "Soll ich ehrlich sein? Dein POKéMON\n"
	.string "findet dich absolut zum Kotzen.\p"
	.string "Wenn ich es wäre, würde ich dich\n"
	.string "einfach im Schlaf auffressen.$"

VerdanturfTown_FriendshipRatersHouse_Text_Pikachu:
	.string "PIKACHU: Pika pika!$"

