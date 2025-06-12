BabyBootCamp_MapScripts::
    .byte 0

BabyBootCamp_EventScript_AlteDame::
    lock
    faceplayer
    goto_if_unset FLAG_BADGE01_GET, BabyBootCamp_EventScript_AlteDame_NoBadge
    goto_if_set FLAG_GOT_EGG_ALTE_DAME, BabyBootCamp_EventScript_AlteDame_AlreadyGiven
    getpartysize
    goto_if_eq VAR_RESULT, PARTY_SIZE, BabyBootCamp_EventScript_AlteDame_NoRoomForEgg
    msgbox BabyBootCamp_Text_AlteDame_GiveEgg, MSGBOX_DEFAULT
    giveegg SPECIES_TOGEPI
    setflag FLAG_GOT_EGG_ALTE_DAME
    playfanfare MUS_OBTAIN_ITEM
    message BabyBootCamp_Text_AlteDame_TakeCare
    waitfanfare
    release
    end

BabyBootCamp_EventScript_AlteDame_NoBadge::
    msgbox BabyBootCamp_Text_AlteDame_NoBadge, MSGBOX_DEFAULT
    release
    end

BabyBootCamp_EventScript_AlteDame_AlreadyGiven::
    msgbox BabyBootCamp_Text_AlteDame_AlreadyGiven, MSGBOX_DEFAULT
    release
    end

BabyBootCamp_EventScript_AlteDame_NoRoomForEgg::
    msgbox BabyBootCamp_Text_AlteDame_NoRoomForEgg, MSGBOX_DEFAULT
    release
    end

BabyBootCamp_Text_AlteDame_GiveEgg::
    .string "Ich habe hier ein Ei für dich.\n"
    .string "Was da wohl schlüpfen wird?$"

BabyBootCamp_Text_AlteDame_NoBadge::
    .string "Oh {PLAYER}, ich sehe den ersten Orden\n"
    .string "gar nicht... Komm wieder, wenn du ihn\l"
    .string "hast, dann gebe ich dir ein Pokémon-Ei.$"

BabyBootCamp_Text_AlteDame_TakeCare::
    .string "Pass gut darauf auf.$"

BabyBootCamp_Text_AlteDame_AlreadyGiven::
    .string "Ich habe dir bereits ein Ei gegeben.\n"
    .string "Pass gut darauf auf.$"

BabyBootCamp_Text_AlteDame_NoRoomForEgg::
    .string "Du hast dein Team voll, komme wieder\n"
    .string "wenn du Platz für das Ei hast du Spasti!$"

BabyBootCamp_EventScript_Bard::
    lock
    faceplayer
    goto_if_unset FLAG_BADGE02_GET, BabyBootCamp_EventScript_Bard_NoBadge
    goto_if_set FLAG_GOT_EGG_BARD, BabyBootCamp_EventScript_Bard_AlreadyGiven
    getpartysize
    goto_if_eq VAR_RESULT, PARTY_SIZE, BabyBootCamp_EventScript_Bard_NoRoomForEgg
    msgbox BabyBootCamp_Text_Bard_GiveEgg, MSGBOX_DEFAULT
    giveegg SPECIES_MUNCHLAX
    setflag FLAG_GOT_EGG_BARD
    playfanfare MUS_OBTAIN_ITEM
    msgbox BabyBootCamp_Text_Bard_TakeCare, MSGBOX_DEFAULT
    waitfanfare
    release
    end

BabyBootCamp_EventScript_Bard_NoBadge::
    msgbox BabyBootCamp_Text_Bard_NoBadge, MSGBOX_DEFAULT
    release
    end

BabyBootCamp_EventScript_Bard_AlreadyGiven::
    msgbox BabyBootCamp_Text_Bard_AlreadyGiven, MSGBOX_DEFAULT
    release
    end

BabyBootCamp_EventScript_Bard_NoRoomForEgg::
    msgbox BabyBootCamp_Text_Bard_NoRoomForEgg, MSGBOX_DEFAULT
    release
    end

BabyBootCamp_Text_Bard_GiveEgg::
    .string "Ich habe hier ein Ei für dich.\n"
    .string "Was da wohl schlüpfen wird?$"

BabyBootCamp_Text_Bard_NoBadge::
    .string "Oh {PLAYER}, ich sehe den zweiten Orden\n"
    .string "gar nicht... Komm wieder, wenn du ihn\l"
    .string "hast, dann gebe ich dir ein Pokémon-Ei.$"

BabyBootCamp_Text_Bard_TakeCare::
    .string "Pass gut darauf auf.$"

BabyBootCamp_Text_Bard_AlreadyGiven::
    .string "Ich habe dir bereits ein Ei gegeben.\n"
    .string "Pass gut darauf auf.$"

BabyBootCamp_Text_Bard_NoRoomForEgg::
    .string "Du hast dein Team voll, komme wieder\n"
    .string "wenn du Platz für das Ei hast du\l"
    .string "Miststück!$"

BabyBootCamp_EventScript_Artist::
    lock
    faceplayer
    goto_if_unset FLAG_BADGE03_GET, BabyBootCamp_EventScript_Artist_NoBadge
    goto_if_set FLAG_GOT_EGG_ARTIST, BabyBootCamp_EventScript_Artist_AlreadyGiven
    getpartysize
    goto_if_eq VAR_RESULT, PARTY_SIZE, BabyBootCamp_EventScript_Artist_NoRoomForEgg
    msgbox BabyBootCamp_Text_Artist_GiveEgg, MSGBOX_DEFAULT
    giveegg SPECIES_MANTYKE
    setflag FLAG_GOT_EGG_ARTIST
    playfanfare MUS_OBTAIN_ITEM
    msgbox BabyBootCamp_Text_Artist_TakeCare, MSGBOX_DEFAULT
    waitfanfare
    release
    end

BabyBootCamp_EventScript_Artist_NoBadge::
    msgbox BabyBootCamp_Text_Artist_NoBadge, MSGBOX_DEFAULT
    release
    end

BabyBootCamp_EventScript_Artist_AlreadyGiven::
    msgbox BabyBootCamp_Text_Artist_AlreadyGiven, MSGBOX_DEFAULT
    release
    end

BabyBootCamp_EventScript_Artist_NoRoomForEgg::
    msgbox BabyBootCamp_Text_Artist_NoRoomForEgg, MSGBOX_DEFAULT
    release
    end

BabyBootCamp_Text_Artist_GiveEgg::
    .string "Ich habe hier ein Ei für dich.\n"
    .string "Was da wohl schlüpfen wird?$"

BabyBootCamp_Text_Artist_NoBadge::
    .string "Oh {PLAYER}, ich sehe den dritten Orden\n"
    .string "gar nicht... Komm wieder, wenn du ihn\l"
    .string "hast, dann gebe ich dir ein Pokémon-Ei.$"

BabyBootCamp_Text_Artist_TakeCare::
    .string "Pass gut darauf auf.$"

BabyBootCamp_Text_Artist_AlreadyGiven::
    .string "Ich habe dir bereits ein Ei gegeben.\n"
    .string "Pass gut darauf auf.$"

BabyBootCamp_Text_Artist_NoRoomForEgg::
    .string "Du hast dein Team voll, komme wieder\n"
    .string "wenn du Platz für das Ei hast du Penner!$"

BabyBootCamp_EventScript_Beauty::
    lock
    faceplayer
    goto_if_unset FLAG_BADGE04_GET, BabyBootCamp_EventScript_Beauty_NoBadge
    goto_if_set FLAG_GOT_EGG_BEAUTY, BabyBootCamp_EventScript_Beauty_AlreadyGiven
    getpartysize
    goto_if_eq VAR_RESULT, PARTY_SIZE, BabyBootCamp_EventScript_Beauty_NoRoomForEgg
    msgbox BabyBootCamp_Text_Beauty_GiveEgg, MSGBOX_DEFAULT
    giveegg SPECIES_SMOOCHUM
    setflag FLAG_GOT_EGG_BEAUTY
    playfanfare MUS_OBTAIN_ITEM
    msgbox BabyBootCamp_Text_Beauty_TakeCare, MSGBOX_DEFAULT
    waitfanfare
    release
    end

BabyBootCamp_EventScript_Beauty_NoBadge::
    msgbox BabyBootCamp_Text_Beauty_NoBadge, MSGBOX_DEFAULT
    release
    end

BabyBootCamp_EventScript_Beauty_AlreadyGiven::
    msgbox BabyBootCamp_Text_Beauty_AlreadyGiven, MSGBOX_DEFAULT
    release
    end

BabyBootCamp_EventScript_Beauty_NoRoomForEgg::
    msgbox BabyBootCamp_Text_Beauty_NoRoomForEgg, MSGBOX_DEFAULT
    release
    end

BabyBootCamp_Text_Beauty_GiveEgg::
    .string "Ich habe hier ein Ei für dich.\n"
    .string "Was da wohl schlüpfen wird?$"

BabyBootCamp_Text_Beauty_NoBadge::
    .string "Oh {PLAYER}, ich sehe den vierten Orden\n"
    .string "gar nicht... Komm wieder, wenn du ihn\l"
    .string "hast, dann gebe ich dir ein Pokémon-Ei.$"

BabyBootCamp_Text_Beauty_TakeCare::
    .string "Pass gut darauf auf.$"

BabyBootCamp_Text_Beauty_AlreadyGiven::
    .string "Ich habe dir bereits ein Ei gegeben.\n"
    .string "Pass gut darauf auf.$"

BabyBootCamp_Text_Beauty_NoRoomForEgg::
    .string "Du hast dein Team voll, komme wieder\n"
    .string "wenn du Platz für das Ei hast du Huen-\l"
    .string "sohn!$"

BabyBootCamp_EventScript_Belt::
    lock
    faceplayer
    goto_if_unset FLAG_BADGE05_GET, BabyBootCamp_EventScript_Belt_NoBadge
    goto_if_set FLAG_GOT_EGG_BELT, BabyBootCamp_EventScript_Belt_AlreadyGiven
    getpartysize
    goto_if_eq VAR_RESULT, PARTY_SIZE, BabyBootCamp_EventScript_Belt_NoRoomForEgg
    msgbox BabyBootCamp_Text_Belt_GiveEgg, MSGBOX_DEFAULT
    giveegg SPECIES_RIOLU
    setflag FLAG_GOT_EGG_BELT
    playfanfare MUS_OBTAIN_ITEM
    msgbox BabyBootCamp_Text_Belt_TakeCare, MSGBOX_DEFAULT
    waitfanfare
    release
    end

BabyBootCamp_EventScript_Belt_NoBadge::
    msgbox BabyBootCamp_Text_Belt_NoBadge, MSGBOX_DEFAULT
    release
    end

BabyBootCamp_EventScript_Belt_AlreadyGiven::
    msgbox BabyBootCamp_Text_Belt_AlreadyGiven, MSGBOX_DEFAULT
    release
    end

BabyBootCamp_EventScript_Belt_NoRoomForEgg::
    msgbox BabyBootCamp_Text_Belt_NoRoomForEgg, MSGBOX_DEFAULT
    release
    end

BabyBootCamp_Text_Belt_GiveEgg::
    .string "Ich habe hier ein Ei für dich.\n"
    .string "Was da wohl schlüpfen wird?$"

BabyBootCamp_Text_Belt_NoBadge::
    .string "Oh {PLAYER}, ich sehe den fünften Orden\n"
    .string "gar nicht... Komm wieder, wenn du ihn\l"
    .string "hast, dann gebe ich dir ein Pokémon-Ei.$"

BabyBootCamp_Text_Belt_TakeCare::
    .string "Pass gut darauf auf.$"

BabyBootCamp_Text_Belt_AlreadyGiven::
    .string "Ich habe dir bereits ein Ei gegeben.\n"
    .string "Pass gut darauf auf.$"

BabyBootCamp_Text_Belt_NoRoomForEgg::
    .string "Du hast dein Team voll, komme wieder\n"
    .string "wenn du Platz für das Ei hast.$"

BabyBootCamp_EventScript_Boy_1::
    lock
    faceplayer
    goto_if_unset FLAG_BADGE06_GET, BabyBootCamp_EventScript_Boy_1_NoBadge
    goto_if_set FLAG_GOT_EGG_BOY_1, BabyBootCamp_EventScript_Boy_1_AlreadyGiven
    getpartysize
    goto_if_eq VAR_RESULT, PARTY_SIZE, BabyBootCamp_EventScript_Boy_1_NoRoomForEgg
    msgbox BabyBootCamp_Text_Boy_1_GiveEgg, MSGBOX_DEFAULT
    giveegg SPECIES_PICHU
    setflag FLAG_GOT_EGG_BOY_1
    playfanfare MUS_OBTAIN_ITEM
    msgbox BabyBootCamp_Text_Boy_1_TakeCare, MSGBOX_DEFAULT
    waitfanfare
    release
    end

BabyBootCamp_EventScript_Boy_1_NoBadge::
    msgbox BabyBootCamp_Text_Boy_1_NoBadge, MSGBOX_DEFAULT
    release
    end

BabyBootCamp_EventScript_Boy_1_AlreadyGiven::
    msgbox BabyBootCamp_Text_Boy_1_AlreadyGiven, MSGBOX_DEFAULT
    release
    end

BabyBootCamp_EventScript_Boy_1_NoRoomForEgg::
    msgbox BabyBootCamp_Text_Boy_1_NoRoomForEgg, MSGBOX_DEFAULT
    release
    end

BabyBootCamp_Text_Boy_1_GiveEgg::
    .string "Ich habe hier ein Ei für dich.\n"
    .string "Was da wohl schlüpfen wird?$"

BabyBootCamp_Text_Boy_1_NoBadge::
    .string "Oh {PLAYER}, ich sehe den sechsten Orden\n"
    .string "gar nicht... Komm wieder, wenn du ihn\l"
    .string "hast, dann gebe ich dir ein Pokémon-Ei.$"

BabyBootCamp_Text_Boy_1_TakeCare::
    .string "Pass gut darauf auf.$"

BabyBootCamp_Text_Boy_1_AlreadyGiven::
    .string "Ich habe dir bereits ein Ei gegeben.\n"
    .string "Pass gut darauf auf.$"

BabyBootCamp_Text_Boy_1_NoRoomForEgg::
    .string "Du hast dein Team voll, komme wieder\n"
    .string "wenn du Platz für das Ei hast, du Affe!$"

BabyBootCamp_EventScript_Boy_2::
    lock
    faceplayer
    goto_if_unset FLAG_BADGE07_GET, BabyBootCamp_EventScript_Boy_2_NoBadge
    goto_if_set FLAG_GOT_EGG_BOY_2, BabyBootCamp_EventScript_Boy_2_AlreadyGiven
    getpartysize
    goto_if_eq VAR_RESULT, PARTY_SIZE, BabyBootCamp_EventScript_Boy_2_NoRoomForEgg
    msgbox BabyBootCamp_Text_Boy_2_GiveEgg, MSGBOX_DEFAULT
    giveegg SPECIES_TYROGUE
    setflag FLAG_GOT_EGG_BOY_2
    playfanfare MUS_OBTAIN_ITEM
    msgbox BabyBootCamp_Text_Boy_2_TakeCare, MSGBOX_DEFAULT
    waitfanfare
    release
    end

BabyBootCamp_EventScript_Boy_2_NoBadge::
    msgbox BabyBootCamp_Text_Boy_2_NoBadge, MSGBOX_DEFAULT
    release
    end

BabyBootCamp_EventScript_Boy_2_AlreadyGiven::
    msgbox BabyBootCamp_Text_Boy_2_AlreadyGiven, MSGBOX_DEFAULT
    release
    end

BabyBootCamp_EventScript_Boy_2_NoRoomForEgg::
    msgbox BabyBootCamp_Text_Boy_2_NoRoomForEgg, MSGBOX_DEFAULT
    release
    end

BabyBootCamp_Text_Boy_2_GiveEgg::
    .string "Ich habe hier ein Ei für dich.\n"
    .string "Was da wohl schlüpfen wird?$"

BabyBootCamp_Text_Boy_2_NoBadge::
    .string "Oh {PLAYER}, ich sehe den siebten Orden\n"
    .string "gar nicht... Komm wieder, wenn du ihn\l"
    .string "hast, dann gebe ich dir ein Pokémon-Ei.$"

BabyBootCamp_Text_Boy_2_TakeCare::
    .string "Pass gut darauf auf.$"

BabyBootCamp_Text_Boy_2_AlreadyGiven::
    .string "Ich habe dir bereits ein Ei gegeben.\n"
    .string "Pass gut darauf auf.$"

BabyBootCamp_Text_Boy_2_NoRoomForEgg::
    .string "Du hast dein Team voll, komme wieder\n"
    .string "wenn du Platz für das Ei hast, du\l"
    .string "Trottel!$"

BabyBootCamp_EventScript_Boy_3::
    lock
    faceplayer
    goto_if_unset FLAG_BADGE08_GET, BabyBootCamp_EventScript_Boy_3_NoBadge
    goto_if_set FLAG_GOT_EGG_BOY_3, BabyBootCamp_EventScript_Boy_3_AlreadyGiven
    getpartysize
    goto_if_eq VAR_RESULT, PARTY_SIZE, BabyBootCamp_EventScript_Boy_3_NoRoomForEgg
    msgbox BabyBootCamp_Text_Boy_3_GiveEgg, MSGBOX_DEFAULT
    giveegg SPECIES_PHIONE
    setflag FLAG_GOT_EGG_BOY_3
    playfanfare MUS_OBTAIN_ITEM
    msgbox BabyBootCamp_Text_Boy_3_TakeCare, MSGBOX_DEFAULT
    waitfanfare
    release
    end

BabyBootCamp_EventScript_Boy_3_NoBadge::
    msgbox BabyBootCamp_Text_Boy_3_NoBadge, MSGBOX_DEFAULT
    release
    end

BabyBootCamp_EventScript_Boy_3_AlreadyGiven::
    msgbox BabyBootCamp_Text_Boy_3_AlreadyGiven, MSGBOX_DEFAULT
    release
    end

BabyBootCamp_EventScript_Boy_3_NoRoomForEgg::
    msgbox BabyBootCamp_Text_Boy_3_NoRoomForEgg, MSGBOX_DEFAULT
    release
    end

BabyBootCamp_Text_Boy_3_GiveEgg::
    .string "Ich habe hier ein Ei für dich.\n"
    .string "Was da wohl schlüpfen wird?$"

BabyBootCamp_Text_Boy_3_NoBadge::
    .string "Oh {PLAYER}, ich sehe den achten Orden\n"
    .string "gar nicht... Komm wieder, wenn du ihn\l"
    .string "hast, dann gebe ich dir ein Pokémon-Ei.$"

BabyBootCamp_Text_Boy_3_TakeCare::
    .string "Pass gut darauf auf.$"

BabyBootCamp_Text_Boy_3_AlreadyGiven::
    .string "Ich habe dir bereits ein Ei gegeben.\n"
    .string "Pass gut darauf auf.$"

BabyBootCamp_Text_Boy_3_NoRoomForEgg::
    .string "Du hast dein Team voll, komme wieder\n"
    .string "wenn du Platz für das Ei hast, du\l"
    .string "Versager!$"

BabyBootCamp_EventScript_BugCatcher::
    lock
    faceplayer
    goto_if_unset FLAG_SYS_GAME_CLEAR, BabyBootCamp_EventScript_BugCatcher_NoLeague
    goto_if_set FLAG_GOT_EGG_BUG_CATCHER, BabyBootCamp_EventScript_BugCatcher_AlreadyGiven
    getpartysize
    goto_if_eq VAR_RESULT, PARTY_SIZE, BabyBootCamp_EventScript_BugCatcher_NoRoomForEgg
    msgbox BabyBootCamp_Text_BugCatcher_GiveEgg, MSGBOX_DEFAULT
    giveegg SPECIES_MANAPHY
    setflag FLAG_GOT_EGG_BUG_CATCHER
    playfanfare MUS_OBTAIN_ITEM
    msgbox BabyBootCamp_Text_BugCatcher_TakeCare, MSGBOX_DEFAULT
    waitfanfare
    release
    end

BabyBootCamp_EventScript_BugCatcher_NoLeague::
    msgbox BabyBootCamp_Text_BugCatcher_NoLeague, MSGBOX_DEFAULT
    release
    end

BabyBootCamp_EventScript_BugCatcher_AlreadyGiven::
    msgbox BabyBootCamp_Text_BugCatcher_AlreadyGiven, MSGBOX_DEFAULT
    release
    end

BabyBootCamp_EventScript_BugCatcher_NoRoomForEgg::
    msgbox BabyBootCamp_Text_BugCatcher_NoRoomForEgg, MSGBOX_DEFAULT
    release
    end

BabyBootCamp_Text_BugCatcher_GiveEgg::
    .string "Ich habe hier ein Ei für dich.\n"
    .string "Was da wohl schlüpfen wird?$"

BabyBootCamp_Text_BugCatcher_NoLeague::
    .string "Oh {PLAYER}, du musst erst die Pokémon\n"
    .string "Liga besiegen, bevor ich dir ein\l"
    .string "Pokémon-Ei geben kann.$"

BabyBootCamp_Text_BugCatcher_TakeCare::
    .string "Pass gut darauf auf.$"

BabyBootCamp_Text_BugCatcher_AlreadyGiven::
    .string "Ich habe dir bereits ein Ei gegeben.\n"
    .string "Pass gut darauf auf.$"

BabyBootCamp_Text_BugCatcher_NoRoomForEgg::
    .string "Du hast dein Team voll, komme wieder\n"
    .string "wenn du Platz für das Ei hast du Idiot!$"

BabyBootCamp_EventScript_SecretWall::
    lockall
    braillemsgbox BabyBootCamp_Braille_SecretMessage
    msgbox BabyBootCamp_Text_SecretMessage, MSGBOX_DEFAULT
    releaseall
    end

BabyBootCamp_Text_SecretMessage::
    .string "Hier verbirgt sich ein Geheimnis.\n"
    .string "Nur die Würdigen werden es enthüllen.$"

BabyBootCamp_EventScript_Test::
    lockall
    checkflag FLAG_BADGE01_GET
    goto_if_set FLAG_BADGE01_GET, BabyBootCamp_EventScript_Test_CheckNextBadge
    msgbox BabyBootCamp_Text_Test_GiveStoneBadge, MSGBOX_DEFAULT
    call Common_EventScript_PlayGymBadgeFanfare
    setflag FLAG_BADGE01_GET
    releaseall
    end

BabyBootCamp_EventScript_Test_CheckNextBadge::
    checkflag FLAG_BADGE02_GET
    goto_if_set FLAG_BADGE02_GET, BabyBootCamp_EventScript_Test_CheckNextBadge2
    msgbox BabyBootCamp_Text_Test_GiveKnuckleBadge, MSGBOX_DEFAULT
    call Common_EventScript_PlayGymBadgeFanfare
    setflag FLAG_BADGE02_GET
    releaseall
    end

BabyBootCamp_EventScript_Test_CheckNextBadge2::
    checkflag FLAG_BADGE03_GET
    goto_if_set FLAG_BADGE03_GET, BabyBootCamp_EventScript_Test_CheckNextBadge3
    msgbox BabyBootCamp_Text_Test_GiveDynamoBadge, MSGBOX_DEFAULT
    call Common_EventScript_PlayGymBadgeFanfare
    setflag FLAG_BADGE03_GET
    releaseall
    end

BabyBootCamp_EventScript_Test_CheckNextBadge3::
    checkflag FLAG_BADGE04_GET
    goto_if_set FLAG_BADGE04_GET, BabyBootCamp_EventScript_Test_CheckNextBadge4
    msgbox BabyBootCamp_Text_Test_GiveHeatBadge, MSGBOX_DEFAULT
    call Common_EventScript_PlayGymBadgeFanfare
    setflag FLAG_BADGE04_GET
    releaseall
    end

BabyBootCamp_EventScript_Test_CheckNextBadge4::
    checkflag FLAG_BADGE05_GET
    goto_if_set FLAG_BADGE05_GET, BabyBootCamp_EventScript_Test_CheckNextBadge5
    msgbox BabyBootCamp_Text_Test_GiveBalanceBadge, MSGBOX_DEFAULT
    call Common_EventScript_PlayGymBadgeFanfare
    setflag FLAG_BADGE05_GET
    releaseall
    end

BabyBootCamp_EventScript_Test_CheckNextBadge5::
    checkflag FLAG_BADGE06_GET
    goto_if_set FLAG_BADGE06_GET, BabyBootCamp_EventScript_Test_CheckNextBadge6
    msgbox BabyBootCamp_Text_Test_GiveFeatherBadge, MSGBOX_DEFAULT
    call Common_EventScript_PlayGymBadgeFanfare
    setflag FLAG_BADGE06_GET
    releaseall
    end

BabyBootCamp_EventScript_Test_CheckNextBadge6::
    checkflag FLAG_BADGE07_GET
    goto_if_set FLAG_BADGE07_GET, BabyBootCamp_EventScript_Test_CheckNextBadge7
    msgbox BabyBootCamp_Text_Test_GiveMindBadge, MSGBOX_DEFAULT
    call Common_EventScript_PlayGymBadgeFanfare
    setflag FLAG_BADGE07_GET
    releaseall
    end

BabyBootCamp_EventScript_Test_CheckNextBadge7::
    checkflag FLAG_BADGE08_GET
    goto_if_set FLAG_BADGE08_GET, BabyBootCamp_EventScript_Test_GiveGameClear
    msgbox BabyBootCamp_Text_Test_GiveRainBadge, MSGBOX_DEFAULT
    call Common_EventScript_PlayGymBadgeFanfare
    setflag FLAG_BADGE08_GET
    releaseall
    end

BabyBootCamp_EventScript_Test_GiveGameClear::
    checkflag FLAG_SYS_GAME_CLEAR
    goto_if_set FLAG_SYS_GAME_CLEAR, BabyBootCamp_EventScript_Test_NoMoreBadges
    msgbox BabyBootCamp_Text_Test_GameClear, MSGBOX_DEFAULT
    setflag FLAG_SYS_GAME_CLEAR
    releaseall
    end

BabyBootCamp_EventScript_Test_NoMoreBadges::
    msgbox BabyBootCamp_Text_Test_NoMoreBadges, MSGBOX_DEFAULT
    releaseall
    end

BabyBootCamp_Text_Test_GiveStoneBadge::
    .string "Hier hast du den Steinorden.$"

BabyBootCamp_Text_Test_GiveKnuckleBadge::
    .string "Hier hast du den Faustenorden.$"

BabyBootCamp_Text_Test_GiveDynamoBadge::
    .string "Hier hast du den Dynamoorden.$"

BabyBootCamp_Text_Test_GiveHeatBadge::
    .string "Hier hast du den Hitzeorden.$"

BabyBootCamp_Text_Test_GiveBalanceBadge::
    .string "Hier hast du den Gleichgewichtsorden.$"

BabyBootCamp_Text_Test_GiveFeatherBadge::
    .string "Hier hast du den Federorden.$"

BabyBootCamp_Text_Test_GiveMindBadge::
    .string "Hier hast du den Seelenorden.$"

BabyBootCamp_Text_Test_GiveRainBadge::
    .string "Hier hast du den Regenorden.$"

BabyBootCamp_Text_Test_GameClear::
    .string "Du bist jetzt Champ!$"

BabyBootCamp_Text_Test_NoMoreBadges::
    .string "Ich habe nix mehr für dich.$"

