#include "global.h"
#include "gba/m4a_internal.h"
#include "sound.h"
#include "battle.h"
#include "m4a.h"
#include "main.h"
#include "pokemon.h"
#include "constants/cries.h"
#include "constants/songs.h"
#include "task.h"
#include "test_runner.h"
#include "option_menu.h"

#include "window.h"
#include "list_menu.h"
#include "text.h"
#include "strings.h"
#include "menu.h"
#include "script.h"
#include "constants/sound.h"


struct Fanfare
{
    u16 songNum;
    u16 duration;
};

EWRAM_DATA struct MusicPlayerInfo *gMPlay_PokemonCry = NULL;
EWRAM_DATA u8 gPokemonCryBGMDuckingCounter = 0;

static u16 sCurrentMapMusic;
static u16 sNextMapMusic;
static u8 sMapMusicState;
static u8 sMapMusicFadeInSpeed;
static u16 sFanfareCounter;

COMMON_DATA bool8 gDisableMusic = 0;

extern struct ToneData gCryTable[];
extern struct ToneData gCryTable_Reverse[];

static void Task_Fanfare(u8 taskId);
static void CreateFanfareTask(void);
static void RestoreBGMVolumeAfterPokemonCry(void);

// The 1st argument in the table is the length of the fanfare, measured in frames. This is calculated by taking the duration of the midi file, multiplying by 59.72750056960583, and rounding up to the next nearest integer.
static const struct Fanfare sFanfares[] = {
    [FANFARE_LEVEL_UP]            = { MUS_LEVEL_UP,             80 },
    [FANFARE_OBTAIN_ITEM]         = { MUS_OBTAIN_ITEM,         160 },
    [FANFARE_EVOLVED]             = { MUS_EVOLVED,             220 },
    [FANFARE_OBTAIN_TMHM]         = { MUS_OBTAIN_TMHM,         220 },
    [FANFARE_HEAL]                = { MUS_HEAL,                160 },
    [FANFARE_OBTAIN_BADGE]        = { MUS_OBTAIN_BADGE,        340 },
    [FANFARE_MOVE_DELETED]        = { MUS_MOVE_DELETED,        180 },
    [FANFARE_OBTAIN_BERRY]        = { MUS_OBTAIN_BERRY,        120 },
    [FANFARE_AWAKEN_LEGEND]       = { MUS_AWAKEN_LEGEND,       710 },
    [FANFARE_SLOTS_JACKPOT]       = { MUS_SLOTS_JACKPOT,       250 },
    [FANFARE_SLOTS_WIN]           = { MUS_SLOTS_WIN,           150 },
    [FANFARE_TOO_BAD]             = { MUS_TOO_BAD,             160 },
    [FANFARE_RG_POKE_FLUTE]       = { MUS_RG_POKE_FLUTE,       450 },
    [FANFARE_RG_OBTAIN_KEY_ITEM]  = { MUS_RG_OBTAIN_KEY_ITEM,  170 },
    [FANFARE_RG_DEX_RATING]       = { MUS_RG_DEX_RATING,       196 },
    [FANFARE_OBTAIN_B_POINTS]     = { MUS_OBTAIN_B_POINTS,     313 },
    [FANFARE_OBTAIN_SYMBOL]       = { MUS_OBTAIN_SYMBOL,       318 },
    [FANFARE_REGISTER_MATCH_CALL] = { MUS_REGISTER_MATCH_CALL, 135 },
};

void InitMapMusic(void)
{
    gDisableMusic = FALSE;
    ResetMapMusic();
}

void MapMusicMain(void)
{
    switch (sMapMusicState)
    {
    case 0:
        break;
    case 1:
        sMapMusicState = 2;
        PlayBGM(sCurrentMapMusic);
        break;
    case 2:
    case 3:
    case 4:
        break;
    case 5:
        if (IsBGMStopped())
        {
            sNextMapMusic = 0;
            sMapMusicState = 0;
        }
        break;
    case 6:
        if (IsBGMStopped() && IsFanfareTaskInactive())
        {
            sCurrentMapMusic = sNextMapMusic;
            sNextMapMusic = 0;
            sMapMusicState = 2;
            PlayBGM(sCurrentMapMusic);
        }
        break;
    case 7:
        if (IsBGMStopped() && IsFanfareTaskInactive())
        {
            FadeInNewBGM(sNextMapMusic, sMapMusicFadeInSpeed);
            sCurrentMapMusic = sNextMapMusic;
            sNextMapMusic = 0;
            sMapMusicState = 2;
            sMapMusicFadeInSpeed = 0;
        }
        break;
    }
}

void ResetMapMusic(void)
{
    sCurrentMapMusic = 0;
    sNextMapMusic = 0;
    sMapMusicState = 0;
    sMapMusicFadeInSpeed = 0;
}

u16 GetCurrentMapMusic(void)
{
    return sCurrentMapMusic;
}

void PlayNewMapMusic(u16 songNum)
{
    sCurrentMapMusic = songNum;
    sNextMapMusic = 0;
    sMapMusicState = 1;
}

void StopMapMusic(void)
{
    sCurrentMapMusic = 0;
    sNextMapMusic = 0;
    sMapMusicState = 1;
}

void FadeOutMapMusic(u8 speed)
{
    if (IsNotWaitingForBGMStop())
        FadeOutBGM(speed);
    sCurrentMapMusic = 0;
    sNextMapMusic = 0;
    sMapMusicState = 5;
}

void FadeOutAndPlayNewMapMusic(u16 songNum, u8 speed)
{
    FadeOutMapMusic(speed);
    sCurrentMapMusic = 0;
    sNextMapMusic = songNum;
    sMapMusicState = 6;
}

void FadeOutAndFadeInNewMapMusic(u16 songNum, u8 fadeOutSpeed, u8 fadeInSpeed)
{
    FadeOutMapMusic(fadeOutSpeed);
    sCurrentMapMusic = 0;
    sNextMapMusic = songNum;
    sMapMusicState = 7;
    sMapMusicFadeInSpeed = fadeInSpeed;
}

static void UNUSED FadeInNewMapMusic(u16 songNum, u8 speed)
{
    FadeInNewBGM(songNum, speed);
    sCurrentMapMusic = songNum;
    sNextMapMusic = 0;
    sMapMusicState = 2;
    sMapMusicFadeInSpeed = 0;
}

bool8 IsNotWaitingForBGMStop(void)
{
    if (sMapMusicState == 6)
        return FALSE;
    if (sMapMusicState == 5)
        return FALSE;
    if (sMapMusicState == 7)
        return FALSE;
    return TRUE;
}

void PlayFanfareByFanfareNum(u8 fanfareNum)
{
    u16 songNum;
    m4aMPlayStop(&gMPlayInfo_BGM);
    songNum = sFanfares[fanfareNum].songNum;
    sFanfareCounter = sFanfares[fanfareNum].duration;
    m4aSongNumStart(songNum);
}

bool8 WaitFanfare(bool8 stop)
{
    if (sFanfareCounter)
    {
        sFanfareCounter--;
        return FALSE;
    }
    else
    {
        if (!stop)
            m4aMPlayContinue(&gMPlayInfo_BGM);
        else
            m4aSongNumStart(MUS_DUMMY);

        return TRUE;
    }
}

// Unused
void StopFanfareByFanfareNum(u8 fanfareNum)
{
    m4aSongNumStop(sFanfares[fanfareNum].songNum);
}

void PlayFanfare(u16 songNum)
{
    s32 i;
    for (i = 0; (u32)i < ARRAY_COUNT(sFanfares); i++)
    {
        if (sFanfares[i].songNum == songNum)
        {
            PlayFanfareByFanfareNum(i);
            CreateFanfareTask();
            return;
        }
    }

    // songNum is not in sFanfares
    // Play first fanfare in table instead
    PlayFanfareByFanfareNum(0);
    CreateFanfareTask();
}

bool8 IsFanfareTaskInactive(void)
{
    if (FuncIsActiveTask(Task_Fanfare) == TRUE)
        return FALSE;
    return TRUE;
}

static void Task_Fanfare(u8 taskId)
{
    if (gTestRunnerHeadless)
    {
        DestroyTask(taskId);
        sFanfareCounter = 0;
        return;
    }

    if (sFanfareCounter)
    {
        sFanfareCounter--;
    }
    else
    {
        m4aMPlayContinue(&gMPlayInfo_BGM);
        DestroyTask(taskId);
    }
}

static void CreateFanfareTask(void)
{
    if (FuncIsActiveTask(Task_Fanfare) != TRUE)
        CreateTask(Task_Fanfare, 80);
}

void FadeInNewBGM(u16 songNum, u8 speed)
{
    if (gDisableMusic)
        songNum = 0;
    if (songNum == MUS_NONE)
        songNum = 0;
    m4aSongNumStart(songNum);
    m4aMPlayImmInit(&gMPlayInfo_BGM);
    m4aMPlayVolumeControl(&gMPlayInfo_BGM, TRACKS_ALL, 0);
    m4aSongNumStop(songNum);
    m4aMPlayFadeIn(&gMPlayInfo_BGM, speed);
}

void FadeOutBGMTemporarily(u8 speed)
{
    m4aMPlayFadeOutTemporarily(&gMPlayInfo_BGM, speed);
}

bool8 IsBGMPausedOrStopped(void)
{
    if (gMPlayInfo_BGM.status & MUSICPLAYER_STATUS_PAUSE)
        return TRUE;
    if (!(gMPlayInfo_BGM.status & MUSICPLAYER_STATUS_TRACK))
        return TRUE;
    return FALSE;
}

void FadeInBGM(u8 speed)
{
    m4aMPlayFadeIn(&gMPlayInfo_BGM, speed);
}

void FadeOutBGM(u8 speed)
{
    m4aMPlayFadeOut(&gMPlayInfo_BGM, speed);
}

bool8 IsBGMStopped(void)
{
    if (!(gMPlayInfo_BGM.status & MUSICPLAYER_STATUS_TRACK))
        return TRUE;
    return FALSE;
}

void PlayCry_Normal(u16 species, s8 pan)
{
    m4aMPlayVolumeControl(&gMPlayInfo_BGM, TRACKS_ALL, 85);
    PlayCryInternal(species, pan, CRY_VOLUME, CRY_PRIORITY_NORMAL, CRY_MODE_NORMAL);
    gPokemonCryBGMDuckingCounter = 2;
    RestoreBGMVolumeAfterPokemonCry();
}

void PlayCry_NormalNoDucking(u16 species, s8 pan, s8 volume, u8 priority)
{
    PlayCryInternal(species, pan, volume, priority, CRY_MODE_NORMAL);
}

// Assuming it's not CRY_MODE_DOUBLES, this is equivalent to PlayCry_Normal except it allows other modes.
void PlayCry_ByMode(u16 species, s8 pan, u8 mode)
{
    if (mode == CRY_MODE_DOUBLES)
    {
        PlayCryInternal(species, pan, CRY_VOLUME, CRY_PRIORITY_NORMAL, mode);
    }
    else
    {
        m4aMPlayVolumeControl(&gMPlayInfo_BGM, TRACKS_ALL, 85);
        PlayCryInternal(species, pan, CRY_VOLUME, CRY_PRIORITY_NORMAL, mode);
        gPokemonCryBGMDuckingCounter = 2;
        RestoreBGMVolumeAfterPokemonCry();
    }
}

// Used when releasing multiple Pokémon at once in battle.
void PlayCry_ReleaseDouble(u16 species, s8 pan, u8 mode)
{
    if (mode == CRY_MODE_DOUBLES)
    {
        PlayCryInternal(species, pan, CRY_VOLUME, CRY_PRIORITY_NORMAL, mode);
    }
    else
    {
        if (!(gBattleTypeFlags & BATTLE_TYPE_MULTI))
            m4aMPlayVolumeControl(&gMPlayInfo_BGM, TRACKS_ALL, 85);
        PlayCryInternal(species, pan, CRY_VOLUME, CRY_PRIORITY_NORMAL, mode);
    }
}

// Duck the BGM but don't restore it. Not present in R/S
void PlayCry_DuckNoRestore(u16 species, s8 pan, u8 mode)
{
    if (mode == CRY_MODE_DOUBLES)
    {
        PlayCryInternal(species, pan, CRY_VOLUME, CRY_PRIORITY_NORMAL, mode);
    }
    else
    {
        m4aMPlayVolumeControl(&gMPlayInfo_BGM, TRACKS_ALL, 85);
        PlayCryInternal(species, pan, CRY_VOLUME, CRY_PRIORITY_NORMAL, mode);
        gPokemonCryBGMDuckingCounter = 2;
    }
}

void PlayCry_Script(u16 species, u8 mode)
{
    m4aMPlayVolumeControl(&gMPlayInfo_BGM, TRACKS_ALL, 85);
    PlayCryInternal(species, 0, CRY_VOLUME, CRY_PRIORITY_NORMAL, mode);
    gPokemonCryBGMDuckingCounter = 2;
    RestoreBGMVolumeAfterPokemonCry();
}

void PlayCryInternal(u16 species, s8 pan, s8 volume, u8 priority, u8 mode)
{
    bool32 reverse;
    u32 release;
    u32 length;
    u32 pitch;
    u32 chorus;

    // Set default values
    // May be overridden depending on mode.
    length = 210;
    reverse = FALSE;
    release = 0;
    pitch = 15360;
    chorus = 0;

    switch (mode)
    {
    case CRY_MODE_NORMAL:
        break;
    case CRY_MODE_DOUBLES:
        length = 20;
        release = 225;
        break;
    case CRY_MODE_ENCOUNTER:
        release = 225;
        pitch = 15600;
        chorus = 20;
        volume = 90;
        break;
    case CRY_MODE_HIGH_PITCH:
        length = 50;
        release = 200;
        pitch = 15800;
        chorus = 20;
        volume = 90;
        break;
    case CRY_MODE_ECHO_START:
        length = 25;
        reverse = TRUE;
        release = 100;
        pitch = 15600;
        chorus = 192;
        volume = 90;
        break;
    case CRY_MODE_FAINT:
        release = 200;
        pitch = 14440;
        break;
    case CRY_MODE_ECHO_END:
        release = 220;
        pitch = 15555;
        chorus = 192;
        volume = 70;
        break;
    case CRY_MODE_ROAR_1:
        length = 10;
        release = 100;
        pitch = 14848;
        break;
    case CRY_MODE_ROAR_2:
        length = 60;
        release = 225;
        pitch = 15616;
        break;
    case CRY_MODE_GROWL_1:
        length = 15;
        reverse = TRUE;
        release = 125;
        pitch = 15200;
        break;
    case CRY_MODE_GROWL_2:
        length = 100;
        release = 225;
        pitch = 15200;
        break;
    case CRY_MODE_WEAK_DOUBLES:
        length = 20;
        release = 225;
        // fallthrough
    case CRY_MODE_WEAK:
        pitch = 15000;
        break;
    case CRY_MODE_DYNAMAX:
        length = 255;
        release = 255;
        pitch = 12150;
        chorus = 200;
        break;
    }

    SetPokemonCryVolume(volume);
    SetPokemonCryPanpot(pan);
    SetPokemonCryPitch(pitch);
    SetPokemonCryLength(length);
    SetPokemonCryProgress(0);
    SetPokemonCryRelease(release);
    SetPokemonCryChorus(chorus);
    SetPokemonCryPriority(priority);

    enum PokemonCry cryId = GetCryIdBySpecies(species);
    if (cryId != CRY_NONE)
    {
        cryId--;
        gMPlay_PokemonCry = SetPokemonCryTone(reverse ? &gCryTable_Reverse[cryId] : &gCryTable[cryId]);
    }
}

bool8 IsCryFinished(void)
{
    if (FuncIsActiveTask(Task_DuckBGMForPokemonCry) == TRUE)
    {
        return FALSE;
    }
    else
    {
        ClearPokemonCrySongs();
        return TRUE;
    }
}

void StopCryAndClearCrySongs(void)
{
    m4aMPlayStop(gMPlay_PokemonCry);
    ClearPokemonCrySongs();
}

void StopCry(void)
{
    m4aMPlayStop(gMPlay_PokemonCry);
}

bool8 IsCryPlayingOrClearCrySongs(void)
{
    if (IsPokemonCryPlaying(gMPlay_PokemonCry))
    {
        return TRUE;
    }
    else
    {
        ClearPokemonCrySongs();
        return FALSE;
    }
}

bool8 IsCryPlaying(void)
{
    if (IsPokemonCryPlaying(gMPlay_PokemonCry))
        return TRUE;
    else
        return FALSE;
}

void Task_DuckBGMForPokemonCry(u8 taskId)
{
    if (gPokemonCryBGMDuckingCounter)
    {
        gPokemonCryBGMDuckingCounter--;
        return;
    }

    if (!IsPokemonCryPlaying(gMPlay_PokemonCry))
    {
        m4aMPlayVolumeControl(&gMPlayInfo_BGM, TRACKS_ALL, 256);
        DestroyTask(taskId);
    }
}

static void RestoreBGMVolumeAfterPokemonCry(void)
{
    if (FuncIsActiveTask(Task_DuckBGMForPokemonCry) != TRUE)
        CreateTask(Task_DuckBGMForPokemonCry, 80);
}

void PlayBGM(u16 songNum)
{
    if (gDisableMusic)
        songNum = 0;
    if (songNum == MUS_NONE)
        songNum = 0;
    m4aSongNumStart(songNum);
}

void PlaySE(u16 songNum)
{
    m4aSongNumStart(songNum);
}

void PlaySE12WithPanning(u16 songNum, s8 pan)
{
    m4aSongNumStart(songNum);
    m4aMPlayImmInit(&gMPlayInfo_SE1);
    m4aMPlayImmInit(&gMPlayInfo_SE2);
    m4aMPlayPanpotControl(&gMPlayInfo_SE1, TRACKS_ALL, pan);
    m4aMPlayPanpotControl(&gMPlayInfo_SE2, TRACKS_ALL, pan);
}

void PlaySE1WithPanning(u16 songNum, s8 pan)
{
    m4aSongNumStart(songNum);
    m4aMPlayImmInit(&gMPlayInfo_SE1);
    m4aMPlayPanpotControl(&gMPlayInfo_SE1, TRACKS_ALL, pan);
}

void PlaySE2WithPanning(u16 songNum, s8 pan)
{
    m4aSongNumStart(songNum);
    m4aMPlayImmInit(&gMPlayInfo_SE2);
    m4aMPlayPanpotControl(&gMPlayInfo_SE2, TRACKS_ALL, pan);
}

void SE12PanpotControl(s8 pan)
{
    m4aMPlayPanpotControl(&gMPlayInfo_SE1, TRACKS_ALL, pan);
    m4aMPlayPanpotControl(&gMPlayInfo_SE2, TRACKS_ALL, pan);
}

bool8 IsSEPlaying(void)
{
    if ((gMPlayInfo_SE1.status & MUSICPLAYER_STATUS_PAUSE) && (gMPlayInfo_SE2.status & MUSICPLAYER_STATUS_PAUSE))
        return FALSE;
    if (!(gMPlayInfo_SE1.status & MUSICPLAYER_STATUS_TRACK) && !(gMPlayInfo_SE2.status & MUSICPLAYER_STATUS_TRACK))
        return FALSE;
    return TRUE;
}

bool8 IsBGMPlaying(void)
{
    if (gMPlayInfo_BGM.status & MUSICPLAYER_STATUS_PAUSE)
        return FALSE;
    if (!(gMPlayInfo_BGM.status & MUSICPLAYER_STATUS_TRACK))
        return FALSE;
    return TRUE;
}

bool8 IsSpecialSEPlaying(void)
{
    if (gMPlayInfo_SE3.status & MUSICPLAYER_STATUS_PAUSE)
        return FALSE;
    if (!(gMPlayInfo_SE3.status & MUSICPLAYER_STATUS_TRACK))
        return FALSE;
    return TRUE;
}

//TestLabor 

static const struct ListMenuItem sMusicListItems_Menu1[];
static const struct ListMenuItem sMusicListItems_Menu2[];
static const struct ListMenuItem sMusicListItems_Menu3[];

static const struct ListMenuItem sMusicListItems_Menu1[] =
{
    {gText_MUS_DUMMY, MUS_DUMMY},
    {gText_MUS_CAUGHT, MUS_CAUGHT},
    {gText_MUS_VICTORY_WILD, MUS_VICTORY_WILD},
    {gText_MUS_VICTORY_LEAGUE, MUS_VICTORY_LEAGUE},
    {gText_MUS_C_COMM_CENTER, MUS_C_COMM_CENTER},
    {gText_MUS_C_VS_LEGEND_BEAST, MUS_C_VS_LEGEND_BEAST},
    {gText_MUS_ROUTE110, MUS_ROUTE110},
    {gText_MUS_PETALBURG, MUS_PETALBURG},
    {gText_MUS_GYM, MUS_GYM},
    {gText_MUS_PETALBURG_WOODS, MUS_PETALBURG_WOODS},
    {gText_MUS_OBTAIN_ITEM, MUS_OBTAIN_ITEM},
    {gText_MUS_LILYCOVE_MUSEUM, MUS_LILYCOVE_MUSEUM},
    {gText_MUS_EVOLUTION, MUS_EVOLUTION},
    {gText_MUS_ENCOUNTER_MALE, MUS_ENCOUNTER_MALE},
    {gText_MUS_BIRCH_LAB, MUS_BIRCH_LAB},
    {gText_MUS_OBTAIN_BERRY, MUS_OBTAIN_BERRY},
    {gText_MUS_TOO_BAD, MUS_TOO_BAD},
    {gText_MUS_LINK_CONTEST_P2, MUS_LINK_CONTEST_P2},
    {gText_MUS_RUSTBORO, MUS_RUSTBORO},
    {gText_MUS_ROUTE104, MUS_ROUTE104},
    {gText_MUS_LITTLEROOT, MUS_LITTLEROOT},
    {gText_MUS_LILYCOVE, MUS_LILYCOVE},
    {gText_MUS_UNDERWATER, MUS_UNDERWATER},
    {gText_MUS_TITLE, MUS_TITLE},
    {gText_MUS_ENCOUNTER_MAY, MUS_ENCOUNTER_MAY},
    {gText_MUS_ROUTE113, MUS_ROUTE113},
    {gText_MUS_ENCOUNTER_BRENDAN, MUS_ENCOUNTER_BRENDAN},
    {gText_MUS_CONTEST, MUS_CONTEST},
    {gText_MUS_ABNORMAL_WEATHER, MUS_ABNORMAL_WEATHER},
    {gText_MUS_HALL_OF_FAME_ROOM, MUS_HALL_OF_FAME_ROOM},
    {gText_MUS_ENCOUNTER_ELITE_FOUR, MUS_ENCOUNTER_ELITE_FOUR},
    {gText_MUS_CREDITS, MUS_CREDITS},
    {gText_MUS_B_PYRAMID_TOP, MUS_B_PYRAMID_TOP},
    {gText_MUS_VS_RAYQUAZA, MUS_VS_RAYQUAZA},
    {gText_MUS_B_DOME_LOBBY, MUS_B_DOME_LOBBY},
    {gText_MUS_VS_TRAINER, MUS_VS_TRAINER},
    {gText_MUS_VS_CHAMPION, MUS_VS_CHAMPION},
    {gText_MUS_RG_GYM, MUS_RG_GYM},
    {gText_MUS_RG_CYCLING, MUS_RG_CYCLING},
    {gText_MUS_RG_ENCOUNTER_BOY, MUS_RG_ENCOUNTER_BOY},
    {gText_MUS_RG_POKE_MANSION, MUS_RG_POKE_MANSION},
    {gText_MUS_RG_ROUTE1, MUS_RG_ROUTE1},
    {gText_MUS_RG_ROUTE3, MUS_RG_ROUTE3},
    {gText_MUS_RG_VS_GYM_LEADER, MUS_RG_VS_GYM_LEADER},
    {gText_MUS_RG_VS_CHAMPION, MUS_RG_VS_CHAMPION},
    {gText_MUS_RG_POKE_CENTER, MUS_RG_POKE_CENTER},
    {gText_MUS_RG_POKE_TOWER, MUS_RG_POKE_TOWER},
    {gText_MUS_RG_SEVII_45, MUS_RG_SEVII_45},
    {gText_PH_FACE_HELD, PH_FACE_HELD},
    {gText_PH_CLOTH_BLEND, PH_CLOTH_BLEND},
    {gText_PH_DRESS_HELD, PH_DRESS_HELD},
    {gText_PH_KIT_SOLO, PH_KIT_SOLO},
    {gText_PH_CHOICE_BLEND, PH_CHOICE_BLEND},
    {gText_PH_GOOSE_SOLO, PH_GOOSE_SOLO},
    {gText_PH_NURSE_HELD, PH_NURSE_HELD},
    {gText_MUS_HG_VS_GYM_LEADER_KANTO, MUS_HG_VS_GYM_LEADER_KANTO},
    {gText_MUS_HG_VS_SUICUNE, MUS_HG_VS_SUICUNE},
    {gText_MUS_HG_ROUTE34, MUS_HG_ROUTE34},
    {gText_MUS_HG_ENCOUNTER_RIVAL, MUS_HG_ENCOUNTER_RIVAL}
};

static const struct ListMenuItem sMusicListItems_Menu2[] =
{
    {gText_MUS_HG_ENCOUNTER_KIMONO_GIRL, MUS_HG_ENCOUNTER_KIMONO_GIRL},
    {gText_MUS_HG_ENCOUNTER_BOY_2, MUS_HG_ENCOUNTER_BOY_2},
    {gText_MUS_HG_TITLE, MUS_HG_TITLE},
    {gText_MUS_HG_END, MUS_HG_END},
    {gText_MUS_HG_NEW_BARK, MUS_HG_NEW_BARK},
    {gText_MUS_HG_GAME_CORNER, MUS_HG_GAME_CORNER},
    {gText_MUS_HG_BUG_CONTEST_PREP, MUS_HG_BUG_CONTEST_PREP},
    {gText_MUS_HG_ROCKET_TAKEOVER, MUS_HG_ROCKET_TAKEOVER},
    {gText_MUS_HG_CARD_FLIP, MUS_HG_CARD_FLIP},
    {gText_MUS_HG_B_TOWER, MUS_HG_B_TOWER},
    {gText_MUS_HG_B_TOWER_RECEPTION, MUS_HG_B_TOWER_RECEPTION},
    {gText_MUS_HG_GYM, MUS_HG_GYM},
    {gText_MUS_HG_LEVEL_UP, MUS_HG_LEVEL_UP},
    {gText_MUS_DP_ROUTE201_DAY, MUS_DP_ROUTE201_DAY},
    {gText_MUS_DP_ROUTE206_DAY, MUS_DP_ROUTE206_DAY},
    {gText_MUS_DP_ROUTE210_DAY, MUS_DP_ROUTE210_DAY},
    {gText_MUS_DP_LAKE_CAVERNS, MUS_DP_LAKE_CAVERNS},
    {gText_MUS_DP_VS_WILD, MUS_DP_VS_WILD},
    {gText_MUS_DP_VS_GYM_LEADER, MUS_DP_VS_GYM_LEADER},
    {gText_MUS_DP_VS_UXIE_MESPRIT_AZELF, MUS_DP_VS_UXIE_MESPRIT_AZELF},
    {gText_MUS_DP_VS_GALACTIC_BOSS, MUS_DP_VS_GALACTIC_BOSS},
    {gText_MUS_DP_VS_CHAMPION, MUS_DP_VS_CHAMPION},
    {gText_MUS_DP_VS_ARCEUS, MUS_DP_VS_ARCEUS},
    {gText_MUS_DP_VS_GALACTIC_COMMANDER, MUS_DP_VS_GALACTIC_COMMANDER},
    {gText_MUS_DP_ENCOUNTER_BOY, MUS_DP_ENCOUNTER_BOY},
    {gText_MUS_DP_ENCOUNTER_HIKER, MUS_DP_ENCOUNTER_HIKER},
    {gText_MUS_DP_ENCOUNTER_SUSPICIOUS, MUS_DP_ENCOUNTER_SUSPICIOUS},
    {gText_MUS_DP_ENCOUNTER_GIRL, MUS_DP_ENCOUNTER_GIRL},
    {gText_MUS_DP_ENCOUNTER_ELITE_FOUR, MUS_DP_ENCOUNTER_ELITE_FOUR},
    {gText_MUS_DP_ENCOUNTER_CHAMPION, MUS_DP_ENCOUNTER_CHAMPION},
    {gText_MUS_DP_VICTORY_TRAINER, MUS_DP_VICTORY_TRAINER},
    {gText_MUS_DP_VICTORY_ELITE_FOUR, MUS_DP_VICTORY_ELITE_FOUR},
    {gText_MUS_DP_HALL_OF_ORIGIN, MUS_DP_HALL_OF_ORIGIN},
    {gText_MUS_DP_HEAL, MUS_DP_HEAL},
    {gText_MUS_DP_INSIDE_POKEMON_LEAGUE, MUS_DP_INSIDE_POKEMON_LEAGUE},
    {gText_MUS_DP_SANDGEM_DAY, MUS_DP_SANDGEM_DAY},
    {gText_MUS_DP_GYM, MUS_DP_GYM},
    {gText_MUS_DP_EVOLVED, MUS_DP_EVOLVED},
    {gText_MUS_DP_GTS, MUS_DP_GTS},
    {gText_MUS_DP_LEVEL_UP, MUS_DP_LEVEL_UP},
    {gText_MUS_DP_GALACTIC_HQ_BASEMENT, MUS_DP_GALACTIC_HQ_BASEMENT},
    {gText_MUS_PL_MYSTERY_GIFT, MUS_PL_MYSTERY_GIFT},
    {gText_MUS_PL_VS_GIRATINA, MUS_PL_VS_GIRATINA},
    {gText_MUS_PL_DISTORTION_WORLD, MUS_PL_DISTORTION_WORLD},
    {gText_MUS_EXTRA_START, MUS_EXTRA_START},
    {gText_MUS_ROUTE118, MUS_ROUTE118},
    {gText_MUS_DEBUG_TEST, MUS_DEBUG_TEST},
    {gText_MUS_MOVE_DELETED_SLOW, MUS_MOVE_DELETED_SLOW},
    {gText_PH_FACE_BLEND, PH_FACE_BLEND},
    {gText_PH_CLOTH_HELD, PH_CLOTH_HELD},
    {gText_PH_DRESS_BLEND, PH_DRESS_BLEND},
    {gText_PH_FLEECE_HELD, PH_FLEECE_HELD},
    {gText_PH_KIT_BLEND, PH_KIT_BLEND},
    {gText_PH_PRICE_SOLO, PH_PRICE_SOLO},
    {gText_PH_LOT_BLEND, PH_LOT_BLEND},
    {gText_PH_THOUGHT_HELD, PH_THOUGHT_HELD},
    {gText_PH_CHOICE_SOLO, PH_CHOICE_SOLO},
    {gText_PH_MOUTH_HELD, PH_MOUTH_HELD},
    {gText_PH_GOOSE_BLEND, PH_GOOSE_BLEND},
    {gText_PH_STRUT_SOLO, PH_STRUT_SOLO},
    {gText_PH_CURE_BLEND, PH_CURE_BLEND},
    {gText_PH_NURSE_SOLO, PH_NURSE_SOLO},
    {gText_MUS_NONE, MUS_NONE}
};

static const struct ListMenuItem sMusicListItems_Menu3[] =
{
    {gText_MUS_RG_TITLE, MUS_RG_TITLE},
    {gText_MUS_RG_HEAL, MUS_RG_HEAL},
    {gText_MUS_RG_GAME_CORNER, MUS_RG_GAME_CORNER},
    {gText_MUS_RG_ROCKET_HIDEOUT, MUS_RG_ROCKET_HIDEOUT},
/*    {gText_MUS_RG_INTRO_FIGHT, MUS_RG_INTRO_FIGHT},
    {gText_MUS_RG_POKE_CENTER, MUS_RG_POKE_CENTER},
    {gText_MUS_RG_CYCLING, MUS_RG_CYCLING},
    {gText_MUS_RG_MT_MOON, MUS_RG_MT_MOON},
    {gText_MUS_RG_PALLET, MUS_RG_PALLET},
    {gText_MUS_RG_LAVENDER, MUS_RG_LAVENDER},
    {gText_MUS_RG_CELADON, MUS_RG_CELADON},
    {gText_MUS_RG_VERMILLION, MUS_RG_VERMILLION},
    {gText_MUS_RG_VICTORY_TRAINER, MUS_RG_VICTORY_TRAINER},
    {gText_MUS_RG_VS_TRAINER, MUS_RG_VS_TRAINER},
    {gText_MUS_RG_VS_WILD, MUS_RG_VS_WILD},
    {gText_MUS_RG_VS_CHAMPION, MUS_RG_VS_CHAMPION},
    {gText_MUS_RG_FUCHSIA, MUS_RG_FUCHSIA},
    {gText_MUS_RG_SILPH, MUS_RG_SILPH},
    {gText_MUS_RG_POKE_TOWER, MUS_RG_POKE_TOWER},
    {gText_MUS_RG_SS_ANNE, MUS_RG_SS_ANNE},
    {gText_MUS_RG_OAK_LAB, MUS_RG_OAK_LAB},
    {gText_MUS_RG_OAK, MUS_RG_OAK},
    {gText_MUS_RG_GAME_FREAK, MUS_RG_GAME_FREAK},
    {gText_MUS_RG_HALL_OF_FAME, MUS_RG_HALL_OF_FAME},
    {gText_MUS_RG_CREDITS, MUS_RG_CREDITS},
    {gText_MUS_RG_CAUGHT, MUS_RG_CAUGHT},
    {gText_MUS_RG_NEW_GAME_INTRO, MUS_RG_NEW_GAME_INTRO},
    {gText_MUS_RG_NEW_GAME_EXIT, MUS_RG_NEW_GAME_EXIT},
    {gText_MUS_RG_ENCOUNTER_GIRL, MUS_RG_ENCOUNTER_GIRL},
    {gText_MUS_RG_ENCOUNTER_BOY, MUS_RG_ENCOUNTER_BOY},
    {gText_MUS_RG_ENCOUNTER_ROCKET, MUS_RG_ENCOUNTER_ROCKET},
    {gText_MUS_RG_ENCOUNTER_RIVAL, MUS_RG_ENCOUNTER_RIVAL},
    {gText_MUS_RG_ENCOUNTER_GYM_LEADER, MUS_RG_ENCOUNTER_GYM_LEADER},
    {gText_MUS_RG_ENCOUNTER_DEOXYS, MUS_RG_ENCOUNTER_DEOXYS},
    {gText_MUS_RG_DEX_RATING, MUS_RG_DEX_RATING},
    {gText_MUS_RG_PHOTO, MUS_RG_PHOTO},
    {gText_MUS_RG_POKE_JUMP, MUS_RG_POKE_JUMP},
    {gText_MUS_RG_UNION_ROOM, MUS_RG_UNION_ROOM},
    {gText_MUS_RG_NET_CENTER, MUS_RG_NET_CENTER},
    {gText_MUS_RG_BERRY_PICK, MUS_RG_BERRY_PICK},
    {gText_MUS_RG_MYSTERY_GIFT, MUS_RG_MYSTERY_GIFT},
    {gText_MUS_RG_TRAINER_TOWER, MUS_RG_TRAINER_TOWER},
    {gText_MUS_RG_VICTORY_ROAD, MUS_RG_VICTORY_ROAD},
    {gText_MUS_RG_VICTORY_WILD, MUS_RG_VICTORY_WILD},
    {gText_MUS_RG_VICTORY_GYM_LEADER, MUS_RG_VICTORY_GYM_LEADER},
    {gText_MUS_RG_VS_GYM_LEADER, MUS_RG_VS_GYM_LEADER},
    {gText_MUS_RG_CAUGHT_INTRO, MUS_RG_CAUGHT_INTRO},
    {gText_MUS_RG_OBTAIN_KEY_ITEM, MUS_RG_OBTAIN_KEY_ITEM},
    {gText_MUS_RG_RIVAL_EXIT, MUS_RG_RIVAL_EXIT},
    {gText_MUS_RG_POKE_MANSION, MUS_RG_POKE_MANSION},
    {gText_MUS_RG_SLOW_PALLET, MUS_RG_SLOW_PALLET},
    {gText_MUS_RG_SEVII_ROUTE, MUS_RG_SEVII_ROUTE},
    {gText_MUS_RG_SEVII_DUNGEON, MUS_RG_SEVII_DUNGEON},
    {gText_MUS_RG_SEVII_123, MUS_RG_SEVII_123},
    {gText_MUS_RG_SEVII_45, MUS_RG_SEVII_45},
    {gText_MUS_RG_SEVII_67, MUS_RG_SEVII_67},
    {gText_MUS_RG_POKE_FLUTE, MUS_RG_POKE_FLUTE},
    {gText_MUS_RG_VS_DEOXYS, MUS_RG_VS_DEOXYS},
    {gText_MUS_RG_VS_MEWTWO, MUS_RG_VS_MEWTWO},
    {gText_MUS_RG_VS_LEGEND, MUS_RG_VS_LEGEND},
    {gText_MUS_RG_MT_MOON, MUS_RG_MT_MOON},
    {gText_MUS_RG_VIRIDIAN_FOREST, MUS_RG_VIRIDIAN_FOREST},
    {gText_MUS_RG_ROUTE1, MUS_RG_ROUTE1},
    {gText_MUS_RG_ROUTE3, MUS_RG_ROUTE3},
    {gText_MUS_RG_ROUTE11, MUS_RG_ROUTE11},
    {gText_MUS_RG_ROUTE24, MUS_RG_ROUTE24},
    {gText_MUS_EVOLVED, MUS_EVOLVED},
    {gText_MUS_LEVEL_UP, MUS_LEVEL_UP},
    {gText_MUS_HEAL, MUS_HEAL},
    {gText_MUS_OBTAIN_BADGE, MUS_OBTAIN_BADGE},
    {gText_MUS_OBTAIN_TMHM, MUS_OBTAIN_TMHM},*/
    {gText_MUS_EVOLUTION_INTRO, MUS_EVOLUTION_INTRO},
};

// Menü 1 (z. B. Hoenn)
#define MAX_VISIBLE_MUSIC_ENTRIES 6
#define MUSIC_MENU_WIDTH 20
#define MUSIC_MENU_HEIGHT (MAX_VISIBLE_MUSIC_ENTRIES + 2)

static u8 sMusicWindowId1;
static u8 sMusicListTaskId1;
static void Task_MusicChoiceMenu_1(u8 taskId);

void CreateMusicTestMenu_1(void)
{
    struct WindowTemplate windowTemplate = {
        .bg = 0,
        .tilemapLeft = 2,  // Position links vom Textfenster
        .tilemapTop = 2,   // Genug Platz über dem Textfenster
        .width = MUSIC_MENU_WIDTH,   // Breite wie Debug
        .height = MUSIC_MENU_HEIGHT, // Höhe basierend auf maxShowed
        .paletteNum = STD_WINDOW_PALETTE_NUM,
        .baseBlock = STD_WINDOW_BASE_TILE_NUM,
    };

    struct ListMenuTemplate listTemplate = {
        .items = sMusicListItems_Menu1,
        .totalItems = ARRAY_COUNT(sMusicListItems_Menu1),
        .maxShowed = MAX_VISIBLE_MUSIC_ENTRIES,
        .windowId = 0, // wird unten ersetzt
        .header_X = 0,
        .item_X = 1,
        .cursor_X = 0,
        .fontId = FONT_NORMAL,
        .lettersSpacing = 1,
        .itemVerticalPadding = 1,
        .fillValue = 1,
        .cursorPal = 1,
        .cursorShadowPal = 2,
        .moveCursorFunc = NULL,
        .itemPrintFunc = NULL,
        .cursorKind = CURSOR_BLACK_ARROW,
    };

    sMusicWindowId1 = AddWindow(&windowTemplate);
    listTemplate.windowId = sMusicWindowId1;

    SetStandardWindowBorderStyle(sMusicWindowId1, TRUE);
    FillWindowPixelBuffer(sMusicWindowId1, PIXEL_FILL(1));
    PutWindowTilemap(sMusicWindowId1);
    CopyWindowToVram(sMusicWindowId1, COPYWIN_FULL);

    LoadMessageBoxAndFrameGfx(0, TRUE);
    DrawDialogueFrame(0, TRUE);
    AddTextPrinterParameterized(0, FONT_NORMAL, gText_PlayMusicChoice, 0, 1, 0, NULL);

    sMusicListTaskId1 = ListMenuInit(&listTemplate, 0, 0);
    CopyWindowToVram(sMusicWindowId1, COPYWIN_FULL);
    CreateTask(Task_MusicChoiceMenu_1, 0);
}

static void Task_MusicChoiceMenu_1(u8 taskId)
{
    s32 input = ListMenu_ProcessInput(sMusicListTaskId1);
    if (input >= 0)
    {
        PlayBGM(sMusicListItems_Menu1[input].id);
    }
    else if (input == LIST_CANCEL)
    {
        ClearWindowTilemap(sMusicWindowId1);
        RemoveWindow(sMusicWindowId1);
        DestroyTask(taskId);
        ScriptContext_Enable();
    }
}

bool8 ScrCmd_playmusictest1(struct ScriptContext *ctx)
{
    ScriptContext_Stop();
    CreateMusicTestMenu_1();
    return TRUE;
}


// Menü 2 (z. B. Johto)
static u8 sMusicWindowId2;
static u8 sMusicListTaskId2;
static void Task_MusicChoiceMenu_2(u8 taskId);

void CreateMusicTestMenu_2(void)
{
    struct WindowTemplate windowTemplate = {
        .bg = 0, .tilemapLeft = 1, .tilemapTop = 2,
        .width = 12, .height = MAX_VISIBLE_MUSIC_ENTRIES * 2 + 2,
        .paletteNum = STD_WINDOW_PALETTE_NUM,
        .baseBlock = STD_WINDOW_BASE_TILE_NUM,
    };
    struct ListMenuTemplate listTemplate = {
        .items = sMusicListItems_Menu2,
        .totalItems = ARRAY_COUNT(sMusicListItems_Menu2),
        .maxShowed = MAX_VISIBLE_MUSIC_ENTRIES,
        .windowId = 0,
        .header_X = 0, .item_X = 8, .cursor_X = 0,
        .fontId = FONT_NORMAL, .lettersSpacing = 1, .itemVerticalPadding = 1,
        .fillValue = 1, .cursorPal = 1, .cursorShadowPal = 2,
        .moveCursorFunc = NULL, .itemPrintFunc = NULL,
        .cursorKind = 1,
    };
    sMusicWindowId2 = AddWindow(&windowTemplate);
    listTemplate.windowId = sMusicWindowId2;

    SetStandardWindowBorderStyle(sMusicWindowId2, TRUE);
    FillWindowPixelBuffer(sMusicWindowId2, PIXEL_FILL(1));
    PutWindowTilemap(sMusicWindowId2);
    CopyWindowToVram(sMusicWindowId2, COPYWIN_FULL);
    LoadMessageBoxAndFrameGfx(0, TRUE);
    DrawDialogueFrame(0, TRUE);
    AddTextPrinterParameterized(0, FONT_NORMAL, gText_PlayMusicChoice, 0, 1, 0, NULL);

    sMusicListTaskId2 = ListMenuInit(&listTemplate, 0, 0);
    CopyWindowToVram(sMusicWindowId2, COPYWIN_FULL);
    CreateTask(Task_MusicChoiceMenu_2, 0);
}

static void Task_MusicChoiceMenu_2(u8 taskId)
{
    s32 input = ListMenu_ProcessInput(sMusicListTaskId2);
    if (input >= 0)
    {
        PlayBGM(sMusicListItems_Menu2[input].id);
    }
    else if (input == LIST_CANCEL)
    {
        ClearWindowTilemap(sMusicWindowId2);
        RemoveWindow(sMusicWindowId2);
        DestroyTask(taskId);
        ScriptContext_Enable();
    }
}

bool8 ScrCmd_playmusictest2(struct ScriptContext *ctx)
{
    ScriptContext_Stop();
    CreateMusicTestMenu_2();
    return TRUE;
}

// Menü 3 (z. B. Sinnoh)
static u8 sMusicWindowId3;
static u8 sMusicListTaskId3;
static void Task_MusicChoiceMenu_3(u8 taskId);

void CreateMusicTestMenu_3(void)
{
    struct WindowTemplate windowTemplate = {
        .bg = 0, .tilemapLeft = 1, .tilemapTop = 2,
        .width = 12, .height = MAX_VISIBLE_MUSIC_ENTRIES * 2 + 2,
        .paletteNum = STD_WINDOW_PALETTE_NUM,
        .baseBlock = STD_WINDOW_BASE_TILE_NUM,
    };
    struct ListMenuTemplate listTemplate = {
        .items = sMusicListItems_Menu3,
        .totalItems = ARRAY_COUNT(sMusicListItems_Menu3),
        .maxShowed = MAX_VISIBLE_MUSIC_ENTRIES,
        .windowId = 0,
        .header_X = 0, .item_X = 8, .cursor_X = 0,
        .fontId = FONT_NORMAL, .lettersSpacing = 1, .itemVerticalPadding = 1,
        .fillValue = 1, .cursorPal = 1, .cursorShadowPal = 2,
        .moveCursorFunc = NULL, .itemPrintFunc = NULL,
        .cursorKind = 1,
    };
    sMusicWindowId3 = AddWindow(&windowTemplate);
    listTemplate.windowId = sMusicWindowId3;

    SetStandardWindowBorderStyle(sMusicWindowId3, TRUE);
    FillWindowPixelBuffer(sMusicWindowId3, PIXEL_FILL(1));
    PutWindowTilemap(sMusicWindowId3);
    CopyWindowToVram(sMusicWindowId3, COPYWIN_FULL);
    LoadMessageBoxAndFrameGfx(0, TRUE);
    DrawDialogueFrame(0, TRUE);
    AddTextPrinterParameterized(0, FONT_NORMAL, gText_PlayMusicChoice, 0, 1, 0, NULL);

    sMusicListTaskId3 = ListMenuInit(&listTemplate, 0, 0);
    CopyWindowToVram(sMusicWindowId3, COPYWIN_FULL);
    CreateTask(Task_MusicChoiceMenu_3, 0);
}

static void Task_MusicChoiceMenu_3(u8 taskId)
{
    s32 input = ListMenu_ProcessInput(sMusicListTaskId3);
    if (input >= 0)
    {
        PlayBGM(sMusicListItems_Menu3[input].id);
    }
    else if (input == LIST_CANCEL)
    {
        ClearWindowTilemap(sMusicWindowId3);
        RemoveWindow(sMusicWindowId3);
        DestroyTask(taskId);
        ScriptContext_Enable();
    }
}

bool8 ScrCmd_playmusictest3(struct ScriptContext *ctx)
{
    ScriptContext_Stop();
    CreateMusicTestMenu_3();
    return TRUE;
}


// Liste aller Musikstücke
/*
static const struct ListMenuItem sMusicListItems[] =
{
    {gText_MUS_DUMMY, MUS_DUMMY},
    {gText_MUS_LITTLEROOT_TEST, MUS_LITTLEROOT_TEST},
    {gText_MUS_GSC_ROUTE38, MUS_GSC_ROUTE38},
    {gText_MUS_CAUGHT, MUS_CAUGHT},
    {gText_MUS_VICTORY_WILD, MUS_VICTORY_WILD},
    {gText_MUS_VICTORY_GYM_LEADER, MUS_VICTORY_GYM_LEADER},
    {gText_MUS_VICTORY_LEAGUE, MUS_VICTORY_LEAGUE},
    {gText_MUS_C_COMM_CENTER, MUS_C_COMM_CENTER},
    {gText_MUS_GSC_PEWTER, MUS_GSC_PEWTER},
    {gText_MUS_C_VS_LEGEND_BEAST, MUS_C_VS_LEGEND_BEAST},
    {gText_MUS_ROUTE101, MUS_ROUTE101},
    {gText_MUS_ROUTE110, MUS_ROUTE110},
    {gText_MUS_ROUTE120, MUS_ROUTE120},
    {gText_MUS_PETALBURG, MUS_PETALBURG},
    {gText_MUS_OLDALE, MUS_OLDALE},
    {gText_MUS_GYM, MUS_GYM},
    {gText_MUS_SURF, MUS_SURF},
    {gText_MUS_PETALBURG_WOODS, MUS_PETALBURG_WOODS},
    {gText_MUS_LEVEL_UP, MUS_LEVEL_UP},
    {gText_MUS_HEAL, MUS_HEAL},
    {gText_MUS_OBTAIN_BADGE, MUS_OBTAIN_BADGE},
    {gText_MUS_OBTAIN_ITEM, MUS_OBTAIN_ITEM},
    {gText_MUS_EVOLVED, MUS_EVOLVED},
    {gText_MUS_OBTAIN_TMHM, MUS_OBTAIN_TMHM},
    {gText_MUS_LILYCOVE_MUSEUM, MUS_LILYCOVE_MUSEUM},
    {gText_MUS_ROUTE122, MUS_ROUTE122},
    {gText_MUS_OCEANIC_MUSEUM, MUS_OCEANIC_MUSEUM},
    {gText_MUS_EVOLUTION_INTRO, MUS_EVOLUTION_INTRO},
    {gText_MUS_EVOLUTION, MUS_EVOLUTION},
    {gText_MUS_MOVE_DELETED, MUS_MOVE_DELETED},
    {gText_MUS_ENCOUNTER_GIRL, MUS_ENCOUNTER_GIRL},
    {gText_MUS_ENCOUNTER_MALE, MUS_ENCOUNTER_MALE},
    {gText_MUS_ABANDONED_SHIP, MUS_ABANDONED_SHIP},
    {gText_MUS_FORTREE, MUS_FORTREE},
    {gText_MUS_BIRCH_LAB, MUS_BIRCH_LAB},
    {gText_MUS_B_TOWER_RS, MUS_B_TOWER_RS},
    {gText_MUS_ENCOUNTER_SWIMMER, MUS_ENCOUNTER_SWIMMER},
    {gText_MUS_CAVE_OF_ORIGIN, MUS_CAVE_OF_ORIGIN},
    {gText_MUS_OBTAIN_BERRY, MUS_OBTAIN_BERRY},
    {gText_MUS_AWAKEN_LEGEND, MUS_AWAKEN_LEGEND},
    {gText_MUS_SLOTS_JACKPOT, MUS_SLOTS_JACKPOT},
    {gText_MUS_SLOTS_WIN, MUS_SLOTS_WIN},
    {gText_MUS_TOO_BAD, MUS_TOO_BAD},
    {gText_MUS_ROULETTE, MUS_ROULETTE},
    {gText_MUS_LINK_CONTEST_P1, MUS_LINK_CONTEST_P1},
    {gText_MUS_LINK_CONTEST_P2, MUS_LINK_CONTEST_P2},
    {gText_MUS_LINK_CONTEST_P3, MUS_LINK_CONTEST_P3},
    {gText_MUS_LINK_CONTEST_P4, MUS_LINK_CONTEST_P4},
    {gText_MUS_ENCOUNTER_RICH, MUS_ENCOUNTER_RICH},
    {gText_MUS_VERDANTURF, MUS_VERDANTURF},
    {gText_MUS_RUSTBORO, MUS_RUSTBORO},
    {gText_MUS_POKE_CENTER, MUS_POKE_CENTER},
    {gText_MUS_ROUTE104, MUS_ROUTE104},
    {gText_MUS_ROUTE119, MUS_ROUTE119},
    {gText_MUS_CYCLING, MUS_CYCLING},
    {gText_MUS_POKE_MART, MUS_POKE_MART},
    {gText_MUS_LITTLEROOT, MUS_LITTLEROOT},
    {gText_MUS_MT_CHIMNEY, MUS_MT_CHIMNEY},
    {gText_MUS_ENCOUNTER_FEMALE, MUS_ENCOUNTER_FEMALE},
    {gText_MUS_LILYCOVE, MUS_LILYCOVE},
    {gText_MUS_DESERT, MUS_DESERT},
    {gText_MUS_HELP, MUS_HELP},
    {gText_MUS_UNDERWATER, MUS_UNDERWATER},
    {gText_MUS_VICTORY_TRAINER, MUS_VICTORY_TRAINER},
    {gText_MUS_TITLE, MUS_TITLE},
    {gText_MUS_INTRO, MUS_INTRO},
    {gText_MUS_ENCOUNTER_MAY, MUS_ENCOUNTER_MAY},
    {gText_MUS_ENCOUNTER_INTENSE, MUS_ENCOUNTER_INTENSE},
    {gText_MUS_ENCOUNTER_COOL, MUS_ENCOUNTER_COOL},
    {gText_MUS_ROUTE113, MUS_ROUTE113},
    {gText_MUS_ENCOUNTER_AQUA, MUS_ENCOUNTER_AQUA},
    {gText_MUS_FOLLOW_ME, MUS_FOLLOW_ME},
    {gText_MUS_ENCOUNTER_BRENDAN, MUS_ENCOUNTER_BRENDAN},
    {gText_MUS_EVER_GRANDE, MUS_EVER_GRANDE},
    {gText_MUS_ENCOUNTER_SUSPICIOUS, MUS_ENCOUNTER_SUSPICIOUS},
    {gText_MUS_VICTORY_AQUA_MAGMA, MUS_VICTORY_AQUA_MAGMA},
    {gText_MUS_CABLE_CAR, MUS_CABLE_CAR},
    {gText_MUS_GAME_CORNER, MUS_GAME_CORNER},
    {gText_MUS_DEWFORD, MUS_DEWFORD},
    {gText_MUS_SAFARI_ZONE, MUS_SAFARI_ZONE},
    {gText_MUS_VICTORY_ROAD, MUS_VICTORY_ROAD},
    {gText_MUS_AQUA_MAGMA_HIDEOUT, MUS_AQUA_MAGMA_HIDEOUT},
    {gText_MUS_SAILING, MUS_SAILING},
    {gText_MUS_MT_PYRE, MUS_MT_PYRE},
    {gText_MUS_SLATEPORT, MUS_SLATEPORT},
    {gText_MUS_MT_PYRE_EXTERIOR, MUS_MT_PYRE_EXTERIOR},
    {gText_MUS_SCHOOL, MUS_SCHOOL},
    {gText_MUS_HALL_OF_FAME, MUS_HALL_OF_FAME},
    {gText_MUS_FALLARBOR, MUS_FALLARBOR},
    {gText_MUS_SEALED_CHAMBER, MUS_SEALED_CHAMBER},
    {gText_MUS_CONTEST_WINNER, MUS_CONTEST_WINNER},
    {gText_MUS_CONTEST, MUS_CONTEST},
    {gText_MUS_ENCOUNTER_MAGMA, MUS_ENCOUNTER_MAGMA},
    {gText_MUS_INTRO_BATTLE, MUS_INTRO_BATTLE},
    {gText_MUS_ABNORMAL_WEATHER, MUS_ABNORMAL_WEATHER},
    {gText_MUS_WEATHER_GROUDON, MUS_WEATHER_GROUDON},
    {gText_MUS_SOOTOPOLIS, MUS_SOOTOPOLIS},
    {gText_MUS_CONTEST_RESULTS, MUS_CONTEST_RESULTS},
    {gText_MUS_HALL_OF_FAME_ROOM, MUS_HALL_OF_FAME_ROOM},
    {gText_MUS_TRICK_HOUSE, MUS_TRICK_HOUSE},
    {gText_MUS_ENCOUNTER_TWINS, MUS_ENCOUNTER_TWINS},
    {gText_MUS_ENCOUNTER_ELITE_FOUR, MUS_ENCOUNTER_ELITE_FOUR},
    {gText_MUS_ENCOUNTER_HIKER, MUS_ENCOUNTER_HIKER},
    {gText_MUS_CONTEST_LOBBY, MUS_CONTEST_LOBBY},
    {gText_MUS_ENCOUNTER_INTERVIEWER, MUS_ENCOUNTER_INTERVIEWER},
    {gText_MUS_ENCOUNTER_CHAMPION, MUS_ENCOUNTER_CHAMPION},
    {gText_MUS_CREDITS, MUS_CREDITS},
    {gText_MUS_END, MUS_END},
    {gText_MUS_B_FRONTIER, MUS_B_FRONTIER},
    {gText_MUS_B_ARENA, MUS_B_ARENA},
    {gText_MUS_OBTAIN_B_POINTS, MUS_OBTAIN_B_POINTS},
    {gText_MUS_REGISTER_MATCH_CALL, MUS_REGISTER_MATCH_CALL},
    {gText_MUS_B_PYRAMID, MUS_B_PYRAMID},
    {gText_MUS_B_PYRAMID_TOP, MUS_B_PYRAMID_TOP},
    {gText_MUS_B_PALACE, MUS_B_PALACE},
    {gText_MUS_RAYQUAZA_APPEARS, MUS_RAYQUAZA_APPEARS},
    {gText_MUS_B_TOWER, MUS_B_TOWER},
    {gText_MUS_OBTAIN_SYMBOL, MUS_OBTAIN_SYMBOL},
    {gText_MUS_B_DOME, MUS_B_DOME},
    {gText_MUS_B_PIKE, MUS_B_PIKE},
    {gText_MUS_B_FACTORY, MUS_B_FACTORY},
    {gText_MUS_VS_RAYQUAZA, MUS_VS_RAYQUAZA},
    {gText_MUS_VS_FRONTIER_BRAIN, MUS_VS_FRONTIER_BRAIN},
    {gText_MUS_VS_MEW, MUS_VS_MEW},
    {gText_MUS_B_DOME_LOBBY, MUS_B_DOME_LOBBY},
    {gText_MUS_VS_WILD, MUS_VS_WILD},
    {gText_MUS_VS_AQUA_MAGMA, MUS_VS_AQUA_MAGMA},
    {gText_MUS_VS_TRAINER, MUS_VS_TRAINER},
    {gText_MUS_VS_GYM_LEADER, MUS_VS_GYM_LEADER},
    {gText_MUS_VS_CHAMPION, MUS_VS_CHAMPION},
    {gText_MUS_VS_REGI, MUS_VS_REGI},
    {gText_MUS_VS_KYOGRE_GROUDON, MUS_VS_KYOGRE_GROUDON},
    {gText_MUS_VS_RIVAL, MUS_VS_RIVAL},
    {gText_MUS_VS_ELITE_FOUR, MUS_VS_ELITE_FOUR},
    {gText_MUS_VS_AQUA_MAGMA_LEADER, MUS_VS_AQUA_MAGMA_LEADER},
    {gText_MUS_RG_FOLLOW_ME, MUS_RG_FOLLOW_ME},
    {gText_MUS_RG_GAME_CORNER, MUS_RG_GAME_CORNER},
    {gText_MUS_RG_ROCKET_HIDEOUT, MUS_RG_ROCKET_HIDEOUT},
    {gText_MUS_RG_GYM, MUS_RG_GYM},
    {gText_MUS_RG_JIGGLYPUFF, MUS_RG_JIGGLYPUFF},
    {gText_MUS_RG_INTRO_FIGHT, MUS_RG_INTRO_FIGHT},
    {gText_MUS_RG_TITLE, MUS_RG_TITLE},
    {gText_MUS_RG_CINNABAR, MUS_RG_CINNABAR},
    {gText_MUS_RG_LAVENDER, MUS_RG_LAVENDER},
    {gText_MUS_RG_HEAL, MUS_RG_HEAL},
    {gText_MUS_RG_CYCLING, MUS_RG_CYCLING},
    {gText_MUS_RG_ENCOUNTER_ROCKET, MUS_RG_ENCOUNTER_ROCKET},
    {gText_MUS_RG_ENCOUNTER_GIRL, MUS_RG_ENCOUNTER_GIRL},
    {gText_MUS_RG_ENCOUNTER_BOY, MUS_RG_ENCOUNTER_BOY},
    {gText_MUS_RG_HALL_OF_FAME, MUS_RG_HALL_OF_FAME},
    {gText_MUS_RG_VIRIDIAN_FOREST, MUS_RG_VIRIDIAN_FOREST},
    {gText_MUS_RG_MT_MOON, MUS_RG_MT_MOON},
    {gText_MUS_RG_POKE_MANSION, MUS_RG_POKE_MANSION},
    {gText_MUS_RG_CREDITS, MUS_RG_CREDITS},
    {gText_MUS_RG_ROUTE1, MUS_RG_ROUTE1},
    {gText_MUS_RG_ROUTE24, MUS_RG_ROUTE24},
    {gText_MUS_RG_ROUTE3, MUS_RG_ROUTE3},
    {gText_MUS_RG_ROUTE11, MUS_RG_ROUTE11},
    {gText_MUS_RG_VICTORY_ROAD, MUS_RG_VICTORY_ROAD},
    {gText_MUS_RG_VS_GYM_LEADER, MUS_RG_VS_GYM_LEADER},
    {gText_MUS_RG_VS_TRAINER, MUS_RG_VS_TRAINER},
    {gText_MUS_RG_VS_WILD, MUS_RG_VS_WILD},
    {gText_MUS_RG_VS_CHAMPION, MUS_RG_VS_CHAMPION},
    {gText_MUS_RG_PALLET, MUS_RG_PALLET},
    {gText_MUS_RG_OAK_LAB, MUS_RG_OAK_LAB},
    {gText_MUS_RG_OAK, MUS_RG_OAK},
    {gText_MUS_RG_POKE_CENTER, MUS_RG_POKE_CENTER},
    {gText_MUS_RG_SS_ANNE, MUS_RG_SS_ANNE},
    {gText_MUS_RG_SURF, MUS_RG_SURF},
    {gText_MUS_RG_POKE_TOWER, MUS_RG_POKE_TOWER},
    {gText_MUS_RG_SILPH, MUS_RG_SILPH},
    {gText_MUS_RG_FUCHSIA, MUS_RG_FUCHSIA},
    {gText_MUS_RG_CELADON, MUS_RG_CELADON},
    {gText_MUS_RG_VICTORY_TRAINER, MUS_RG_VICTORY_TRAINER},
    {gText_MUS_RG_VICTORY_WILD, MUS_RG_VICTORY_WILD},
    {gText_MUS_RG_VICTORY_GYM_LEADER, MUS_RG_VICTORY_GYM_LEADER},
    {gText_MUS_RG_VERMILLION, MUS_RG_VERMILLION},
    {gText_MUS_RG_PEWTER, MUS_RG_PEWTER},
    {gText_MUS_RG_ENCOUNTER_RIVAL, MUS_RG_ENCOUNTER_RIVAL},
    {gText_MUS_RG_RIVAL_EXIT, MUS_RG_RIVAL_EXIT},
    {gText_MUS_RG_DEX_RATING, MUS_RG_DEX_RATING},
    {gText_MUS_RG_OBTAIN_KEY_ITEM, MUS_RG_OBTAIN_KEY_ITEM},
    {gText_MUS_RG_CAUGHT_INTRO, MUS_RG_CAUGHT_INTRO},
    {gText_MUS_RG_PHOTO, MUS_RG_PHOTO},
    {gText_MUS_RG_GAME_FREAK, MUS_RG_GAME_FREAK},
    {gText_MUS_RG_CAUGHT, MUS_RG_CAUGHT},
    {gText_MUS_RG_NEW_GAME_INSTRUCT, MUS_RG_NEW_GAME_INSTRUCT},
    {gText_MUS_RG_NEW_GAME_INTRO, MUS_RG_NEW_GAME_INTRO},
    {gText_MUS_RG_NEW_GAME_EXIT, MUS_RG_NEW_GAME_EXIT},
    {gText_MUS_RG_POKE_JUMP, MUS_RG_POKE_JUMP},
    {gText_MUS_RG_UNION_ROOM, MUS_RG_UNION_ROOM},
    {gText_MUS_RG_NET_CENTER, MUS_RG_NET_CENTER},
    {gText_MUS_RG_MYSTERY_GIFT, MUS_RG_MYSTERY_GIFT},
    {gText_MUS_RG_BERRY_PICK, MUS_RG_BERRY_PICK},
    {gText_MUS_RG_SEVII_CAVE, MUS_RG_SEVII_CAVE},
    {gText_MUS_RG_TEACHY_TV_SHOW, MUS_RG_TEACHY_TV_SHOW},
    {gText_MUS_RG_SEVII_ROUTE, MUS_RG_SEVII_ROUTE},
    {gText_MUS_RG_SEVII_DUNGEON, MUS_RG_SEVII_DUNGEON},
    {gText_MUS_RG_SEVII_123, MUS_RG_SEVII_123},
    {gText_MUS_RG_SEVII_45, MUS_RG_SEVII_45},
    {gText_MUS_RG_SEVII_67, MUS_RG_SEVII_67},
    {gText_MUS_RG_POKE_FLUTE, MUS_RG_POKE_FLUTE},
    {gText_MUS_RG_VS_DEOXYS, MUS_RG_VS_DEOXYS},
    {gText_MUS_RG_VS_MEWTWO, MUS_RG_VS_MEWTWO},
    {gText_MUS_RG_VS_LEGEND, MUS_RG_VS_LEGEND},
    {gText_MUS_RG_ENCOUNTER_GYM_LEADER, MUS_RG_ENCOUNTER_GYM_LEADER},
    {gText_MUS_RG_ENCOUNTER_DEOXYS, MUS_RG_ENCOUNTER_DEOXYS},
    {gText_MUS_RG_TRAINER_TOWER, MUS_RG_TRAINER_TOWER},
    {gText_MUS_RG_SLOW_PALLET, MUS_RG_SLOW_PALLET},
    {gText_MUS_RG_TEACHY_TV_MENU, MUS_RG_TEACHY_TV_MENU},
    {gText_PH_TRAP_BLEND, PH_TRAP_BLEND},
    {gText_PH_TRAP_HELD, PH_TRAP_HELD},
    {gText_PH_TRAP_SOLO, PH_TRAP_SOLO},
    {gText_PH_FACE_BLEND, PH_FACE_BLEND},
    {gText_PH_FACE_HELD, PH_FACE_HELD},
    {gText_PH_FACE_SOLO, PH_FACE_SOLO},
    {gText_PH_CLOTH_BLEND, PH_CLOTH_BLEND},
    {gText_PH_CLOTH_HELD, PH_CLOTH_HELD},
    {gText_PH_CLOTH_SOLO, PH_CLOTH_SOLO},
    {gText_PH_DRESS_BLEND, PH_DRESS_BLEND},
    {gText_PH_DRESS_HELD, PH_DRESS_HELD},
    {gText_PH_DRESS_SOLO, PH_DRESS_SOLO},
    {gText_PH_FLEECE_BLEND, PH_FLEECE_BLEND},
    {gText_PH_FLEECE_HELD, PH_FLEECE_HELD},
    {gText_PH_FLEECE_SOLO, PH_FLEECE_SOLO},
    {gText_PH_KIT_BLEND, PH_KIT_BLEND},
    {gText_PH_KIT_HELD, PH_KIT_HELD},
    {gText_PH_KIT_SOLO, PH_KIT_SOLO},
    {gText_PH_PRICE_BLEND, PH_PRICE_BLEND},
    {gText_PH_PRICE_HELD, PH_PRICE_HELD},
    {gText_PH_PRICE_SOLO, PH_PRICE_SOLO},
    {gText_PH_LOT_BLEND, PH_LOT_BLEND},
    {gText_PH_LOT_HELD, PH_LOT_HELD},
    {gText_PH_LOT_SOLO, PH_LOT_SOLO},
    {gText_PH_GOAT_BLEND, PH_GOAT_BLEND},
    {gText_PH_GOAT_HELD, PH_GOAT_HELD},
    {gText_PH_GOAT_SOLO, PH_GOAT_SOLO},
    {gText_PH_THOUGHT_BLEND, PH_THOUGHT_BLEND},
    {gText_PH_THOUGHT_HELD, PH_THOUGHT_HELD},
    {gText_PH_THOUGHT_SOLO, PH_THOUGHT_SOLO},
    {gText_PH_CHOICE_BLEND, PH_CHOICE_BLEND},
    {gText_PH_CHOICE_HELD, PH_CHOICE_HELD},
    {gText_PH_CHOICE_SOLO, PH_CHOICE_SOLO},
    {gText_PH_MOUTH_BLEND, PH_MOUTH_BLEND},
    {gText_PH_MOUTH_HELD, PH_MOUTH_HELD},
    {gText_PH_MOUTH_SOLO, PH_MOUTH_SOLO},
    {gText_PH_FOOT_BLEND, PH_FOOT_BLEND},
    {gText_PH_FOOT_HELD, PH_FOOT_HELD},
    {gText_PH_FOOT_SOLO, PH_FOOT_SOLO},
    {gText_PH_GOOSE_BLEND, PH_GOOSE_BLEND},
    {gText_PH_GOOSE_HELD, PH_GOOSE_HELD},
    {gText_PH_GOOSE_SOLO, PH_GOOSE_SOLO},
    {gText_PH_STRUT_BLEND, PH_STRUT_BLEND},
    {gText_PH_STRUT_HELD, PH_STRUT_HELD},
    {gText_PH_STRUT_SOLO, PH_STRUT_SOLO},
    {gText_PH_CURE_BLEND, PH_CURE_BLEND},
    {gText_PH_CURE_HELD, PH_CURE_HELD},
    {gText_PH_CURE_SOLO, PH_CURE_SOLO},
    {gText_PH_NURSE_BLEND, PH_NURSE_BLEND},
    {gText_PH_NURSE_HELD, PH_NURSE_HELD},
    {gText_PH_NURSE_SOLO, PH_NURSE_SOLO},
    {gText_MUS_HG_START, MUS_HG_START},
    {gText_MUS_HG_VS_WILD, MUS_HG_VS_WILD},
    {gText_MUS_HG_VS_TRAINER, MUS_HG_VS_TRAINER},
    {gText_MUS_HG_VS_TRAINER_KANTO, MUS_HG_VS_TRAINER_KANTO},
    {gText_MUS_HG_VS_GYM_LEADER, MUS_HG_VS_GYM_LEADER},
    {gText_MUS_HG_VS_GYM_LEADER_KANTO, MUS_HG_VS_GYM_LEADER_KANTO},
    {gText_MUS_HG_VS_CHAMPION, MUS_HG_VS_CHAMPION},
    {gText_MUS_HG_VS_FRONTIER_BRAIN, MUS_HG_VS_FRONTIER_BRAIN},
    {gText_MUS_HG_VICTORY_FRONTIER_BRAIN, MUS_HG_VICTORY_FRONTIER_BRAIN},
    {gText_MUS_HG_VICTORY_TRAINER, MUS_HG_VICTORY_TRAINER},
    {gText_MUS_HG_VICTORY_GYM_LEADER, MUS_HG_VICTORY_GYM_LEADER},
    {gText_MUS_HG_VS_RIVAL, MUS_HG_VS_RIVAL},
    {gText_MUS_HG_VS_ROCKET, MUS_HG_VS_ROCKET},
    {gText_MUS_HG_VS_SUICUNE, MUS_HG_VS_SUICUNE},
    {gText_MUS_HG_VS_ENTEI, MUS_HG_VS_ENTEI},
    {gText_MUS_HG_VS_RAIKOU, MUS_HG_VS_RAIKOU},
    {gText_MUS_HG_VS_HO_OH, MUS_HG_VS_HO_OH},
    {gText_MUS_HG_VS_LUGIA, MUS_HG_VS_LUGIA},
    {gText_MUS_HG_ROUTE29, MUS_HG_ROUTE29},
    {gText_MUS_HG_ROUTE30, MUS_HG_ROUTE30},
    {gText_MUS_HG_ROUTE34, MUS_HG_ROUTE34},
    {gText_MUS_HG_ROUTE38, MUS_HG_ROUTE38},
    {gText_MUS_HG_ROUTE42, MUS_HG_ROUTE42},
    {gText_MUS_HG_ROUTE47, MUS_HG_ROUTE47},
    {gText_MUS_HG_ICE_PATH, MUS_HG_ICE_PATH},
    {gText_MUS_HG_ENCOUNTER_RIVAL, MUS_HG_ENCOUNTER_RIVAL},
    {gText_MUS_HG_ENCOUNTER_GIRL_1, MUS_HG_ENCOUNTER_GIRL_1},
    {gText_MUS_HG_ENCOUNTER_BOY_1, MUS_HG_ENCOUNTER_BOY_1},
    {gText_MUS_HG_ENCOUNTER_SUSPICIOUS_1, MUS_HG_ENCOUNTER_SUSPICIOUS_1},
    {gText_MUS_HG_ENCOUNTER_SAGE, MUS_HG_ENCOUNTER_SAGE},
    {gText_MUS_HG_ENCOUNTER_KIMONO_GIRL, MUS_HG_ENCOUNTER_KIMONO_GIRL},
    {gText_MUS_HG_ENCOUNTER_ROCKET, MUS_HG_ENCOUNTER_ROCKET},
    {gText_MUS_HG_ENCOUNTER_GIRL_2, MUS_HG_ENCOUNTER_GIRL_2},
    {gText_MUS_HG_ENCOUNTER_BOY_2, MUS_HG_ENCOUNTER_BOY_2},
    {gText_MUS_HG_ENCOUNTER_SUSPICIOUS_2, MUS_HG_ENCOUNTER_SUSPICIOUS_2},
    {gText_MUS_HG_TITLE, MUS_HG_TITLE},
    {gText_MUS_HG_CREDITS, MUS_HG_CREDITS},
    {gText_MUS_HG_END, MUS_HG_END},
    {gText_MUS_HG_NEW_BARK, MUS_HG_NEW_BARK},
    {gText_MUS_HG_NATIONAL_PARK, MUS_HG_NATIONAL_PARK},
    {gText_MUS_HG_DANCE_THEATER, MUS_HG_DANCE_THEATER},
    {gText_MUS_HG_GAME_CORNER, MUS_HG_GAME_CORNER},
    {gText_MUS_HG_GAME_CORNER_WIN, MUS_HG_GAME_CORNER_WIN},
    {gText_MUS_HG_TEAM_ROCKET_HQ, MUS_HG_TEAM_ROCKET_HQ},
    {gText_MUS_HG_BUG_CONTEST_PREP, MUS_HG_BUG_CONTEST_PREP},
    {gText_MUS_HG_BUG_CATCHING_CONTEST, MUS_HG_BUG_CATCHING_CONTEST},
    {gText_MUS_HG_BUG_CONTEST_1ST_PLACE, MUS_HG_BUG_CONTEST_1ST_PLACE},
    {gText_MUS_HG_BUG_CONTEST_2ND_PLACE, MUS_HG_BUG_CONTEST_2ND_PLACE},
    {gText_MUS_HG_BUG_CONTEST_3RD_PLACE, MUS_HG_BUG_CONTEST_3RD_PLACE},
    {gText_MUS_HG_ROCKET_TAKEOVER, MUS_HG_ROCKET_TAKEOVER},
    {gText_MUS_HG_ELM_LAB, MUS_HG_ELM_LAB},
    {gText_MUS_HG_KIMONO_GIRL, MUS_HG_KIMONO_GIRL},
    {gText_MUS_HG_CARD_FLIP, MUS_HG_CARD_FLIP},
    {gText_MUS_HG_CARD_FLIP_GAME_OVER, MUS_HG_CARD_FLIP_GAME_OVER},
    {gText_MUS_HG_B_ARCADE, MUS_HG_B_ARCADE},
    {gText_MUS_HG_B_CASTLE, MUS_HG_B_CASTLE},
    {gText_MUS_HG_B_FACTORY, MUS_HG_B_FACTORY},
    {gText_MUS_HG_B_HALL, MUS_HG_B_HALL},
    {gText_MUS_HG_B_TOWER, MUS_HG_B_TOWER},
    {gText_MUS_HG_B_TOWER_RECEPTION, MUS_HG_B_TOWER_RECEPTION},
    {gText_MUS_HG_EVOLUTION, MUS_HG_EVOLUTION},
    {gText_MUS_HG_EVOLVED, MUS_HG_EVOLVED},
    {gText_MUS_HG_GYM, MUS_HG_GYM},
    {gText_MUS_HG_LEVEL_UP, MUS_HG_LEVEL_UP},
    {gText_MUS_HG_MAGNET_TRAIN, MUS_HG_MAGNET_TRAIN},
    {gText_MUS_HG_SINJOU_RUINS, MUS_HG_SINJOU_RUINS},
    {gText_MUS_HG_VICTORY_WILD, MUS_HG_VICTORY_WILD},
    {gText_MUS_DP_START, MUS_DP_START},
    {gText_MUS_DP_ROUTE201_DAY, MUS_DP_ROUTE201_DAY},
    {gText_MUS_DP_ROUTE203_DAY, MUS_DP_ROUTE203_DAY},
    {gText_MUS_DP_ROUTE205_DAY, MUS_DP_ROUTE205_DAY},
    {gText_MUS_DP_ROUTE206_DAY, MUS_DP_ROUTE206_DAY},
    {gText_MUS_DP_ROUTE209_DAY, MUS_DP_ROUTE209_DAY},
    {gText_MUS_DP_ROUTE210_DAY, MUS_DP_ROUTE210_DAY},
    {gText_MUS_DP_ROUTE216_DAY, MUS_DP_ROUTE216_DAY},
    {gText_MUS_DP_ROUTE228_DAY, MUS_DP_ROUTE228_DAY},
    {gText_MUS_DP_ETERNA_FOREST, MUS_DP_ETERNA_FOREST},
    {gText_MUS_DP_MT_CORONET, MUS_DP_MT_CORONET},
    {gText_MUS_DP_SPEAR_PILLAR, MUS_DP_SPEAR_PILLAR},
    {gText_MUS_DP_LAKE_CAVERNS, MUS_DP_LAKE_CAVERNS},
    {gText_MUS_DP_TITLE, MUS_DP_TITLE},
    {gText_MUS_DP_VS_WILD, MUS_DP_VS_WILD},
    {gText_MUS_DP_VS_GYM_LEADER, MUS_DP_VS_GYM_LEADER},
    {gText_MUS_DP_VS_UXIE_MESPRIT_AZELF, MUS_DP_VS_UXIE_MESPRIT_AZELF},
    {gText_MUS_DP_VS_TRAINER, MUS_DP_VS_TRAINER},
    {gText_MUS_DP_VS_GALACTIC_BOSS, MUS_DP_VS_GALACTIC_BOSS},
    {gText_MUS_DP_VS_DIALGA_PALKIA, MUS_DP_VS_DIALGA_PALKIA},
    {gText_MUS_DP_VS_CHAMPION, MUS_DP_VS_CHAMPION},
    {gText_MUS_DP_VS_GALACTIC, MUS_DP_VS_GALACTIC},
    {gText_MUS_DP_VS_RIVAL, MUS_DP_VS_RIVAL},
    {gText_MUS_DP_VS_ARCEUS, MUS_DP_VS_ARCEUS},
    {gText_MUS_DP_VS_LEGEND, MUS_DP_VS_LEGEND},
    {gText_MUS_DP_VS_GALACTIC_COMMANDER, MUS_DP_VS_GALACTIC_COMMANDER},
    {gText_MUS_DP_VS_ELITE_FOUR, MUS_DP_VS_ELITE_FOUR},
    {gText_MUS_DP_ENCOUNTER_BOY, MUS_DP_ENCOUNTER_BOY},
    {gText_MUS_DP_ENCOUNTER_TWINS, MUS_DP_ENCOUNTER_TWINS},
    {gText_MUS_DP_ENCOUNTER_INTENSE, MUS_DP_ENCOUNTER_INTENSE},
    {gText_MUS_DP_ENCOUNTER_GALACTIC, MUS_DP_ENCOUNTER_GALACTIC},
    {gText_MUS_DP_ENCOUNTER_LADY, MUS_DP_ENCOUNTER_LADY},
    {gText_MUS_DP_ENCOUNTER_HIKER, MUS_DP_ENCOUNTER_HIKER},
    {gText_MUS_DP_ENCOUNTER_RICH, MUS_DP_ENCOUNTER_RICH},
    {gText_MUS_DP_ENCOUNTER_SAILOR, MUS_DP_ENCOUNTER_SAILOR},
    {gText_MUS_DP_ENCOUNTER_SUSPICIOUS, MUS_DP_ENCOUNTER_SUSPICIOUS},
    {gText_MUS_DP_ENCOUNTER_ACE_TRAINER, MUS_DP_ENCOUNTER_ACE_TRAINER},
    {gText_MUS_DP_ENCOUNTER_GIRL, MUS_DP_ENCOUNTER_GIRL},
    {gText_MUS_DP_ENCOUNTER_CYCLIST, MUS_DP_ENCOUNTER_CYCLIST},
    {gText_MUS_DP_ENCOUNTER_ARTIST, MUS_DP_ENCOUNTER_ARTIST},
    {gText_MUS_DP_ENCOUNTER_ELITE_FOUR, MUS_DP_ENCOUNTER_ELITE_FOUR},
    {gText_MUS_DP_ENCOUNTER_CHAMPION, MUS_DP_ENCOUNTER_CHAMPION},
    {gText_MUS_DP_VICTORY_WILD, MUS_DP_VICTORY_WILD},
    {gText_MUS_DP_VICTORY_TRAINER, MUS_DP_VICTORY_TRAINER},
    {gText_MUS_DP_VICTORY_GYM_LEADER, MUS_DP_VICTORY_GYM_LEADER},
    {gText_MUS_DP_VICTORY_CHAMPION, MUS_DP_VICTORY_CHAMPION},
    {gText_MUS_DP_VICTORY_GALACTIC, MUS_DP_VICTORY_GALACTIC},
    {gText_MUS_DP_VICTORY_ELITE_FOUR, MUS_DP_VICTORY_ELITE_FOUR},
    {gText_MUS_DP_HALL_OF_ORIGIN, MUS_DP_HALL_OF_ORIGIN},
    {gText_MUS_DP_FLOAROMA_DAY, MUS_DP_FLOAROMA_DAY},
    {gText_MUS_DP_HALL_OF_FAME, MUS_DP_HALL_OF_FAME},
    {gText_MUS_DP_HEAL, MUS_DP_HEAL},
    {gText_MUS_DP_FIGHT_AREA_DAY, MUS_DP_FIGHT_AREA_DAY},
    {gText_MUS_DP_INSIDE_POKEMON_LEAGUE, MUS_DP_INSIDE_POKEMON_LEAGUE},
    {gText_MUS_DP_SANDGEM_DAY, MUS_DP_SANDGEM_DAY},
    {gText_MUS_DP_SNOWPOINT_DAY, MUS_DP_SNOWPOINT_DAY},
    {gText_MUS_DP_SOLACEON_DAY, MUS_DP_SOLACEON_DAY},
    {gText_MUS_DP_UNDERGROUND, MUS_DP_UNDERGROUND},
    {gText_MUS_DP_GYM, MUS_DP_GYM},
    {gText_MUS_DP_EVOLUTION, MUS_DP_EVOLUTION},
    {gText_MUS_DP_EVOLVED, MUS_DP_EVOLVED},
    {gText_MUS_DP_GTS, MUS_DP_GTS},
    {gText_MUS_DP_LAKE, MUS_DP_LAKE},
    {gText_MUS_DP_LEVEL_UP, MUS_DP_LEVEL_UP},
    {gText_MUS_DP_LEGEND_APPEARS, MUS_DP_LEGEND_APPEARS},
    {gText_MUS_DP_GALACTIC_ETERNA_BUILDING, MUS_DP_GALACTIC_ETERNA_BUILDING},
    {gText_MUS_DP_GALACTIC_HQ, MUS_DP_GALACTIC_HQ},
    {gText_MUS_DP_GALACTIC_HQ_BASEMENT, MUS_DP_GALACTIC_HQ_BASEMENT},
    {gText_MUS_DP_AMITY_SQUARE, MUS_DP_AMITY_SQUARE},
    {gText_MUS_DP_OLD_CHATEAU, MUS_DP_OLD_CHATEAU},
    {gText_MUS_DP_ROWAN, MUS_DP_ROWAN},
    {gText_MUS_DP_OREBURGH_MINE, MUS_DP_OREBURGH_MINE},
    {gText_MUS_PL_START, MUS_PL_START},
    {gText_MUS_PL_MYSTERY_GIFT, MUS_PL_MYSTERY_GIFT},
    {gText_MUS_PL_VS_GIRATINA, MUS_PL_VS_GIRATINA},
    {gText_MUS_PL_DISTORTION_WORLD, MUS_PL_DISTORTION_WORLD},
    {gText_MUS_PL_LOOKER, MUS_PL_LOOKER},
    {gText_MUS_PL_VS_REGI, MUS_PL_VS_REGI},
    {gText_MUS_EXTRA_START, MUS_EXTRA_START},
    {gText_MUS_MOVE_DELETED_SLOW, MUS_MOVE_DELETED_SLOW},
    {gText_MUS_DEBUG_TEST, MUS_DEBUG_TEST},
    {gText_MUS_ROUTE118, MUS_ROUTE118},
    {gText_MUS_NONE, MUS_NONE},
};


void CreateMusicTestMenu(void)
{
    struct WindowTemplate windowTemplate =
    {
        .bg = 0,
        .tilemapLeft = 1,
        .tilemapTop = 2,
        .width = 18,
        .height = 15,
        .paletteNum = STD_WINDOW_PALETTE_NUM,
        .baseBlock = STD_WINDOW_BASE_TILE_NUM,
    };

    struct ListMenuTemplate listTemplate =
    {
        .items = sMusicListItems,
        .totalItems = ARRAY_COUNT(sMusicListItems),
        .maxShowed = MAX_VISIBLE_MUSIC_ENTRIES,
        .windowId = 0, // wird gleich ersetzt
        .header_X = 0,
        .item_X = 8,
        .cursor_X = 0,
        .fontId = FONT_NORMAL,
        .lettersSpacing = 1,
        .itemVerticalPadding = 1,
        .fillValue = 1,
        .cursorPal = 1,
        .cursorShadowPal = 2,
        .moveCursorFunc = NULL,
        .itemPrintFunc = NULL,
        .cursorKind = 1,
    };

    sMusicWindowId = AddWindow(&windowTemplate);
    listTemplate.windowId = sMusicWindowId;

    SetStandardWindowBorderStyle(sMusicWindowId, TRUE);
    FillWindowPixelBuffer(sMusicWindowId, PIXEL_FILL(1));
    PutWindowTilemap(sMusicWindowId);
    CopyWindowToVram(sMusicWindowId, COPYWIN_FULL);

    // Hinweistext
    LoadMessageBoxAndFrameGfx(0, TRUE);
    DrawDialogueFrame(0, TRUE);
    AddTextPrinterParameterized(0, FONT_NORMAL, gText_PlayMusicChoice, 0, 1, 0, NULL);

    sMusicListTaskId = ListMenuInit(&listTemplate, 0, 0);
    CreateTask(Task_MusicChoiceMenu, 0);
}

static void Task_MusicChoiceMenu(u8 taskId)
{
    s32 input = ListMenu_ProcessInput(sMusicListTaskId);

    if (input >= 0)
    {
        PlaySE(SE_SELECT);
        PlayBGM(sMusicListItems[input].id);
    }
    else if (input == LIST_CANCEL)
    {
        PlaySE(SE_SELECT); // optional
    }
    else
    {
        return; // Kein vollständiger Input - warte
    }

    // Menü immer schließen - egal ob Auswahl oder Abbruch
    DestroyListMenuTask(sMusicListTaskId, NULL, NULL);
    ClearStdWindowAndFrameToTransparent(sMusicWindowId, TRUE);
    ClearWindowTilemap(sMusicWindowId);
    RemoveWindow(sMusicWindowId);
    ClearDialogWindowAndFrameToTransparent(0, TRUE);
    ScriptContext_Enable();
    DestroyTask(taskId);
}

bool8 ScrCmd_playmusictest(struct ScriptContext *ctx)
{
    ScriptContext_Stop();
    CreateMusicTestMenu();
    return TRUE;
}
*/
