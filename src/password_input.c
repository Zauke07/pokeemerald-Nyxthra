#include "global.h"
#include "task.h"
#include "main.h"
#include "event_data.h"
#include "script.h"
#include "string_util.h"
#include "text.h"
#include "field_screen_effect.h"
#include "window.h"
#include "strings.h"
#include "menu.h"
#include "password_input.h"
#include "text.h"

#define PASSWORD_LENGTH 4

static u8 sEnteredDigits[PASSWORD_LENGTH];
static u8 sCurrentDigitIndex;
static u8 sWindowId_Password;

static void Task_HandlePasswordInput(u8 taskId);

bool8 ShowTestPasswordMenu(void)
{
    sCurrentDigitIndex = 0;
    for (int i = 0; i < PASSWORD_LENGTH; i++)
        sEnteredDigits[i] = 0;

    CreateTask(Task_HandlePasswordInput, 0);
    return TRUE; // Script wartet
}

static void Task_HandlePasswordInput(u8 taskId)
{
    if (!gTasks[taskId].data[7]) // Fenster nur einmal erstellen
    {
        struct WindowTemplate template = {
            .bg = 0,
            .tilemapLeft = 1,
            .tilemapTop = 1,
            .width = 10,
            .height = 2,
            .paletteNum = 15,
            .baseBlock = 0x1F0
        };
        sWindowId_Password = AddWindow(&template);
        FillWindowPixelBuffer(sWindowId_Password, PIXEL_FILL(1));
        PutWindowTilemap(sWindowId_Password);
        CopyWindowToVram(sWindowId_Password, COPYWIN_FULL);
        gTasks[taskId].data[7] = 1;
    }

    if (JOY_NEW(A_BUTTON))
    {
        sCurrentDigitIndex++;
        if (sCurrentDigitIndex >= PASSWORD_LENGTH)
        {
            int result = 0;
            for (int i = 0; i < PASSWORD_LENGTH; i++)
                result = result * 10 + sEnteredDigits[i];

            VarSet(VAR_RESULT, result);
            ClearWindowTilemap(sWindowId_Password);
            RemoveWindow(sWindowId_Password);
            ScriptContext_Enable();
            DestroyTask(taskId);
            return;
        }
    }
    else if (JOY_NEW(B_BUTTON))
    {
        VarSet(VAR_RESULT, -1);
        ClearWindowTilemap(sWindowId_Password);
        RemoveWindow(sWindowId_Password);
        ScriptContext_Enable();
        DestroyTask(taskId);
        return;
    }
    else if (JOY_NEW(DPAD_UP))
    {
        sEnteredDigits[sCurrentDigitIndex]++;
        if (sEnteredDigits[sCurrentDigitIndex] > 9)
            sEnteredDigits[sCurrentDigitIndex] = 0;
    }
    else if (JOY_NEW(DPAD_DOWN))
    {
        if (sEnteredDigits[sCurrentDigitIndex] == 0)
            sEnteredDigits[sCurrentDigitIndex] = 9;
        else
            sEnteredDigits[sCurrentDigitIndex]--;
    }

    // Anzeige im Fenster aktualisieren
    ConvertIntToDecimalStringN(gStringVar1,
        sEnteredDigits[0] * 1000 +
        sEnteredDigits[1] * 100 +
        sEnteredDigits[2] * 10 +
        sEnteredDigits[3],
        STR_CONV_MODE_LEADING_ZEROS, 4);
    
    FillWindowPixelBuffer(sWindowId_Password, PIXEL_FILL(1));
    AddTextPrinterParameterized(sWindowId_Password, FONT_NORMAL, gStringVar1, 8, 1, 0, NULL);
}
