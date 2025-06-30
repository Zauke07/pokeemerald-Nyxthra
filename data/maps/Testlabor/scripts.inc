.set LOCALID_MUSIC_NPC_1, 5
.set LOCALID_MUSIC_NPC_2, 6
.set LOCALID_MUSIC_NPC_3, 7

Testlabor_MapScripts::
    map_script MAP_SCRIPT_ON_TRANSITION, Testlabor_OnTransition
    .byte 0

Testlabor_OnTransition:
    end

EventScript_Testlabor_MusicNPC1::
    msgbox gText_PlayMusicChoice, MSGBOX_DEFAULT
    waitbuttonpress
    closemessage
    playmusictest1
    end

EventScript_Testlabor_MusicNPC2::
    msgbox gText_PlayMusicChoice, MSGBOX_DEFAULT
    waitbuttonpress
    closemessage
    playmusictest2
    end

EventScript_Testlabor_MusicNPC3::
    msgbox gText_PlayMusicChoice, MSGBOX_DEFAULT
    waitbuttonpress
    closemessage
    playmusictest3
    end

EventScript_Testlabor_Bed::
    lockall
    msgbox Testlabor_Bed_Text_TakeRest, MSGBOX_DEFAULT
    closemessage
    call Common_EventScript_OutOfCenterPartyHeal
    releaseall
    end

Testlabor_Bed_Text_TakeRest:
    .string "Digga, deine Mons sehen aus wie'n\n"
    .string "verkehrter Döner bei 30 Grad…\p"
    .string "Wenn Prof. Birk das sieht, zieht er dir\n"
    .string "den Pokédex ab und blockiert dich.\p"
    .string "Leg dich hin, aber mach keinen Mucks.\n"
    .string "Ich hab schon schwächere Trainer gefickt.\p"
    .string "Und wehe du sabberst… das Kissen hat\n"
    .string "mehr Niveau als dein ganzes Team.\p"
    .string "Du bist der Grund, warum Gift-\n"
    .string "Pokémon überhaupt erfunden wurden.\p"
    .string "Selbst Team Rocket würde dich\n"
    .string "aus Mitleid durchwinken.\p"
    .string "Wurdest du vom Bus überfahren oder\n"
    .string "hat dich ’ne Trainerin zerstört?\p"
    .string "Leg dich hin, du Pokémon-Pleite,\n"
    .string "bevor du noch XP verlierst.\p"
    .string "Aber wehe, du pinkelst ins Bett…\n"
    .string "Dann klatsch ich dich höchstpersönlich.$"

EventScript_Testlabor_CharacterSelectNPC::
    lock
    faceplayer
    msgbox Text_CharakterAuswahlIntro, MSGBOX_YESNO
    compare VAR_RESULT, NO
    goto_if_eq EventScript_Testlabor_CharAuswahlAbbruch

    special StartCharacterStyleSelection
    waitstate
    end

EventScript_Testlabor_CharAuswahlAbbruch::
    getplayerstyle
    bufferstylenamevar1
    msgbox Text_CharakterAuswahlDebug, MSGBOX_DEFAULT
    waitbuttonpress
    closemessage
    release
    end

Text_CharakterAuswahlIntro:
    .string "Möchtest du deinen Charakter ändern?$"

Text_CharakterAuswahlDebug:
    .string "Okay! Du bist jetzt Stil {STR_VAR_1}.$"

