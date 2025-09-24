#include "global.h"
#include "battle.h"
#include "event_data.h"
#include "caps.h"
#include "pokemon.h"


u32 GetCurrentLevelCap(void)
{
    static const u32 sLevelCapFlagMap[][GENDER_COUNT] =
    {
        {FLAG_BADGE01_GET, 20},
        {FLAG_BADGE02_GET, 30},
        {FLAG_BADGE03_GET, 40},
        {FLAG_BADGE04_GET, 50},
        {FLAG_BADGE05_GET, 60},
        {FLAG_BADGE06_GET, 70},
        {FLAG_BADGE07_GET, 80},
        {FLAG_BADGE08_GET, 100},
        {FLAG_BADGE09_GET, 110},
        {FLAG_BADGE10_GET, 120},
        {FLAG_BADGE11_GET, 130},
        {FLAG_BADGE12_GET, 140},
        {FLAG_BADGE13_GET, 150},
        {FLAG_BADGE14_GET, 160},
        {FLAG_BADGE15_GET, 180},
        {FLAG_BADGE16_GET, 200},
    };
    
    u32 i;
    
    if (B_LEVEL_CAP_TYPE == LEVEL_CAP_FLAG_LIST)
    {
        for (i = 0; i < ARRAY_COUNT(sLevelCapFlagMap); i++)
        {
            if (!FlagGet(sLevelCapFlagMap[i][0]))
                return sLevelCapFlagMap[i][1];
        }
    }
    else if (B_LEVEL_CAP_TYPE == LEVEL_CAP_VARIABLE)
    {
        return VarGet(B_LEVEL_CAP_VARIABLE);
    }
    
    return MAX_LEVEL;
}

u32 GetSoftLevelCapExpValue(u32 level, u32 expValue)
{
    static const u32 sExpScalingDown[5] = { 4, 8, 16, 32, 64 };
    static const u32 sExpScalingUp[5]   = { 16, 8, 4, 2, 1 };

    u32 levelDifference;
    u32 currentLevelCap = GetCurrentLevelCap();

    if (B_EXP_CAP_TYPE == EXP_CAP_NONE)
        return expValue;

    if (level < currentLevelCap)
    {
        if (B_LEVEL_CAP_EXP_UP)
        {
            levelDifference = currentLevelCap - level;
            if (levelDifference > ARRAY_COUNT(sExpScalingUp) - 1)
                return expValue + (expValue / sExpScalingUp[ARRAY_COUNT(sExpScalingUp) - 1]);
            else
                return expValue + (expValue / sExpScalingUp[levelDifference]);
        }
        else
        {
            return expValue;
        }
    }
    else if (B_EXP_CAP_TYPE == EXP_CAP_HARD)
    {
        return 0;
    }
    else if (B_EXP_CAP_TYPE == EXP_CAP_SOFT)
    {
        levelDifference = level - currentLevelCap;
        if (levelDifference > ARRAY_COUNT(sExpScalingDown) - 1)
            return expValue / sExpScalingDown[ARRAY_COUNT(sExpScalingDown) - 1];
        else
            return expValue / sExpScalingDown[levelDifference];
    }
    else
    {
       return expValue;
    }
}

u32 GetCurrentEVCap(void)
{

    static const u16 sEvCapFlagMap[][GENDER_COUNT] =
    {
        // Define EV caps for each milestone
        {FLAG_BADGE01_GET, MAX_TOTAL_EVS * 1 / 17},
        {FLAG_BADGE02_GET, MAX_TOTAL_EVS * 2 / 17},
        {FLAG_BADGE03_GET, MAX_TOTAL_EVS * 3 / 17},
        {FLAG_BADGE04_GET, MAX_TOTAL_EVS * 4 / 17},
        {FLAG_BADGE05_GET, MAX_TOTAL_EVS * 5 / 17},
        {FLAG_BADGE06_GET, MAX_TOTAL_EVS * 6 / 17},
        {FLAG_BADGE07_GET, MAX_TOTAL_EVS * 7 / 17},
        {FLAG_BADGE08_GET, MAX_TOTAL_EVS * 8 / 17},
        {FLAG_BADGE09_GET, MAX_TOTAL_EVS * 9 / 17},
        {FLAG_BADGE10_GET, MAX_TOTAL_EVS * 10 / 17},
        {FLAG_BADGE11_GET, MAX_TOTAL_EVS * 11 / 17},
        {FLAG_BADGE12_GET, MAX_TOTAL_EVS * 12 / 17},
        {FLAG_BADGE13_GET, MAX_TOTAL_EVS * 13 / 17},
        {FLAG_BADGE14_GET, MAX_TOTAL_EVS * 14 / 17},
        {FLAG_BADGE15_GET, MAX_TOTAL_EVS * 15 / 17},
        {FLAG_BADGE16_GET, MAX_TOTAL_EVS * 16 / 17},
    };

    if (B_EV_CAP_TYPE == EV_CAP_FLAG_LIST)
    {
        for (u32 evCap = 0; evCap < ARRAY_COUNT(sEvCapFlagMap); evCap++)
        {
            if (!FlagGet(sEvCapFlagMap[evCap][0]))
                return sEvCapFlagMap[evCap][1];
        }
    }
    else if (B_EV_CAP_TYPE == EV_CAP_VARIABLE)
    {
        return VarGet(B_EV_CAP_VARIABLE);
    }
    else if (B_EV_CAP_TYPE == EV_CAP_NO_GAIN)
    {
        return 0;
    }

    return MAX_TOTAL_EVS;
}
