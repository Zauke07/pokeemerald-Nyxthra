JokeNpc_EventScript_Main::
    lock
    faceplayer
    msgbox gJokeNpc_Text_Greeting, MSGBOX_DEFAULT
    multichoice 22, 2, MULTI_JOKE_NPC, TRUE
    switch VAR_RESULT
    case 0, JokeNpc_EventScript_TellJoke1
    case 1, JokeNpc_EventScript_TellJoke2
    case 2, JokeNpc_EventScript_TellJoke3
    end

JokeNpc_EventScript_TellJoke1::
    special GetJokeOffset0
    msgbox gStringVar1, MSGBOX_SIGN
    end

JokeNpc_EventScript_TellJoke2::
    special GetJokeOffset1
    msgbox gStringVar1, MSGBOX_SIGN
    end

JokeNpc_EventScript_TellJoke3::
    special GetJokeOffset2
    msgbox gStringVar1, MSGBOX_SIGN
    end
