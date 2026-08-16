#include "global.h"
#include "text.h"
#include "text_window.h"
#include "window.h"
#include "palette.h"
#include "bg.h"
#include "graphics.h"
#include "menu.h"
#include "constants/rgb.h"

void Nyxthra_ApplyDarkModeToBorderPalette(u32 offset);
void Nyxthra_ApplyDarkModeToWindowPalette(u32 offset);

static const u16 sStdTextWindow_Gfx[]  = INCBIN_U16("graphics/text_window/std.4bpp");

const u8 gTextWindowFrame1_Gfx[] = INCBIN_U8("graphics/text_window/1.4bpp");
static const u8 sTextWindowFrame2_Gfx[] = INCBIN_U8("graphics/text_window/2.4bpp");
static const u8 sTextWindowFrame3_Gfx[] = INCBIN_U8("graphics/text_window/3.4bpp");
static const u8 sTextWindowFrame4_Gfx[] = INCBIN_U8("graphics/text_window/4.4bpp");
static const u8 sTextWindowFrame5_Gfx[] = INCBIN_U8("graphics/text_window/5.4bpp");
static const u8 sTextWindowFrame6_Gfx[] = INCBIN_U8("graphics/text_window/6.4bpp");
static const u8 sTextWindowFrame7_Gfx[] = INCBIN_U8("graphics/text_window/7.4bpp");
static const u8 sTextWindowFrame8_Gfx[] = INCBIN_U8("graphics/text_window/8.4bpp");
static const u8 sTextWindowFrame9_Gfx[] = INCBIN_U8("graphics/text_window/9.4bpp");
static const u8 sTextWindowFrame10_Gfx[] = INCBIN_U8("graphics/text_window/10.4bpp");
static const u8 sTextWindowFrame11_Gfx[] = INCBIN_U8("graphics/text_window/11.4bpp");
static const u8 sTextWindowFrame12_Gfx[] = INCBIN_U8("graphics/text_window/12.4bpp");
static const u8 sTextWindowFrame13_Gfx[] = INCBIN_U8("graphics/text_window/13.4bpp");
static const u8 sTextWindowFrame14_Gfx[] = INCBIN_U8("graphics/text_window/14.4bpp");
static const u8 sTextWindowFrame15_Gfx[] = INCBIN_U8("graphics/text_window/15.4bpp");
static const u8 sTextWindowFrame16_Gfx[] = INCBIN_U8("graphics/text_window/16.4bpp");
static const u8 sTextWindowFrame17_Gfx[] = INCBIN_U8("graphics/text_window/17.4bpp");
static const u8 sTextWindowFrame18_Gfx[] = INCBIN_U8("graphics/text_window/18.4bpp");
static const u8 sTextWindowFrame19_Gfx[] = INCBIN_U8("graphics/text_window/19.4bpp");
static const u8 sTextWindowFrame20_Gfx[] = INCBIN_U8("graphics/text_window/20.4bpp");

const u16 gTextWindowFrame1_Pal[] = INCBIN_U16("graphics/text_window/1.gbapal");
static const u16 sTextWindowFrame2_Pal[] = INCBIN_U16("graphics/text_window/2.gbapal");
static const u16 sTextWindowFrame3_Pal[] = INCBIN_U16("graphics/text_window/3.gbapal");
static const u16 sTextWindowFrame4_Pal[] = INCBIN_U16("graphics/text_window/4.gbapal");
static const u16 sTextWindowFrame5_Pal[] = INCBIN_U16("graphics/text_window/5.gbapal");
static const u16 sTextWindowFrame6_Pal[] = INCBIN_U16("graphics/text_window/6.gbapal");
static const u16 sTextWindowFrame7_Pal[] = INCBIN_U16("graphics/text_window/7.gbapal");
static const u16 sTextWindowFrame8_Pal[] = INCBIN_U16("graphics/text_window/8.gbapal");
static const u16 sTextWindowFrame9_Pal[] = INCBIN_U16("graphics/text_window/9.gbapal");
static const u16 sTextWindowFrame10_Pal[] = INCBIN_U16("graphics/text_window/10.gbapal");
static const u16 sTextWindowFrame11_Pal[] = INCBIN_U16("graphics/text_window/11.gbapal");
static const u16 sTextWindowFrame12_Pal[] = INCBIN_U16("graphics/text_window/12.gbapal");
static const u16 sTextWindowFrame13_Pal[] = INCBIN_U16("graphics/text_window/13.gbapal");
static const u16 sTextWindowFrame14_Pal[] = INCBIN_U16("graphics/text_window/14.gbapal");
static const u16 sTextWindowFrame15_Pal[] = INCBIN_U16("graphics/text_window/15.gbapal");
static const u16 sTextWindowFrame16_Pal[] = INCBIN_U16("graphics/text_window/16.gbapal");
static const u16 sTextWindowFrame17_Pal[] = INCBIN_U16("graphics/text_window/17.gbapal");
static const u16 sTextWindowFrame18_Pal[] = INCBIN_U16("graphics/text_window/18.gbapal");
static const u16 sTextWindowFrame19_Pal[] = INCBIN_U16("graphics/text_window/19.gbapal");
static const u16 sTextWindowFrame20_Pal[] = INCBIN_U16("graphics/text_window/20.gbapal");

static const u16 sTextWindowPalettes[][16] =
{
    INCBIN_U16("graphics/text_window/message_box.gbapal"),
    INCBIN_U16("graphics/text_window/text_pal1.gbapal"),
    INCBIN_U16("graphics/text_window/text_pal2.gbapal"),
    INCBIN_U16("graphics/text_window/text_pal3.gbapal"),
    INCBIN_U16("graphics/text_window/text_pal4.gbapal")
};

// static u16 sNyxthraDarkWindowPaletteBuffer[16];
static bool8 sNyxthraNpcDialoguePaletteOverride = FALSE;

void SetNpcDialogueDarkModePaletteOverride(bool8 enable)
{
    sNyxthraNpcDialoguePaletteOverride = enable;
}

bool8 IsNpcDialogueDarkModePaletteOverrideEnabled(void)
{
    return sNyxthraNpcDialoguePaletteOverride;
}

static const u8 *Nyxthra_GetMessageBoxGfxVariant(void)
{
    return gMessageBox_Gfx;
}

void Nyxthra_ApplyDarkModeToPaletteRange(u32 offset, u32 colorCount)
{
    u32 i;

    if (gSaveBlock2Ptr == NULL || !gSaveBlock2Ptr->optionsUITheme)
        return;

    for (i = 1; i < colorCount; i++)  // i=0 immer auslassen: Index 0 = Transparenz
    {
        u16 color = gPlttBufferUnfaded[offset + i];
        u8 r = (color >> 0) & 0x1F;
        u8 g = (color >> 5) & 0x1F;
        u8 b = (color >> 10) & 0x1F;

        if ((u16)(r + g + b) >= 72)
        {
            gPlttBufferUnfaded[offset + i] = RGB(16, 18, 20);
            gPlttBufferFaded[offset + i]   = RGB(16, 18, 20);
        }
        else if ((u16)(r + g + b) >= 54)
        {
            gPlttBufferUnfaded[offset + i] = RGB(11, 13, 15);
            gPlttBufferFaded[offset + i]   = RGB(11, 13, 15);
        }
    }
}

/*
const u16 *Nyxthra_GetDarkWindowPaletteVariant(const u16 *src)
{
    u32 i;

    // Wenn der Dark Mode aus ist, lade die normale Palette
    if (gSaveBlock2Ptr == NULL || !gSaveBlock2Ptr->optionsUITheme)
        return src;

    // Kopiere die Ursprungs-Palette in den Buffer
    for (i = 0; i < 16; i++)
        sNyxthraDarkWindowPaletteBuffer[i] = src[i];

    // Fuer alle Fenster nur den Fuellhintergrund abdunkeln.
    // Textfarben bleiben unveraendert; NPC-Dialog wird nun separat
    // via Nyxthra_ApplyDarkModeToMessageBoxPalette (post-load) behandelt.
    sNyxthraDarkWindowPaletteBuffer[1] = RGB(8, 9, 11);
    sNyxthraDarkWindowPaletteBuffer[14] = RGB(8, 9, 11); // Lücke (Gap) abdunkeln

    return sNyxthraDarkWindowPaletteBuffer;
}
*/

static const struct TilesPal sWindowFrames[WINDOW_FRAMES_COUNT] =
{
    {gTextWindowFrame1_Gfx, gTextWindowFrame1_Pal},
    {sTextWindowFrame2_Gfx, sTextWindowFrame2_Pal},
    {sTextWindowFrame3_Gfx, sTextWindowFrame3_Pal},
    {sTextWindowFrame4_Gfx, sTextWindowFrame4_Pal},
    {sTextWindowFrame5_Gfx, sTextWindowFrame5_Pal},
    {sTextWindowFrame6_Gfx, sTextWindowFrame6_Pal},
    {sTextWindowFrame7_Gfx, sTextWindowFrame7_Pal},
    {sTextWindowFrame8_Gfx, sTextWindowFrame8_Pal},
    {sTextWindowFrame9_Gfx, sTextWindowFrame9_Pal},
    {sTextWindowFrame10_Gfx, sTextWindowFrame10_Pal},
    {sTextWindowFrame11_Gfx, sTextWindowFrame11_Pal},
    {sTextWindowFrame12_Gfx, sTextWindowFrame12_Pal},
    {sTextWindowFrame13_Gfx, sTextWindowFrame13_Pal},
    {sTextWindowFrame14_Gfx, sTextWindowFrame14_Pal},
    {sTextWindowFrame15_Gfx, sTextWindowFrame15_Pal},
    {sTextWindowFrame16_Gfx, sTextWindowFrame16_Pal},
    {sTextWindowFrame17_Gfx, sTextWindowFrame17_Pal},
    {sTextWindowFrame18_Gfx, sTextWindowFrame18_Pal},
    {sTextWindowFrame19_Gfx, sTextWindowFrame19_Pal},
    {sTextWindowFrame20_Gfx, sTextWindowFrame20_Pal}
};

static const u16 sTextWindowDexNavFrame[] = INCBIN_U16("graphics/text_window/dexnav_pal.gbapal");
static const struct TilesPal sDexNavWindowFrame = {gTextWindowFrame1_Gfx, sTextWindowDexNavFrame};

// code
const struct TilesPal *GetWindowFrameTilesPal(u8 id)
{
    if (id >= WINDOW_FRAMES_COUNT)
        return &sWindowFrames[0];
    else
        return &sWindowFrames[id];
}

static void Nyxthra_ApplyDarkModeToMessageBoxPalette(u32 offset)
{
    if (gSaveBlock2Ptr == NULL || !gSaveBlock2Ptr->optionsUITheme)
        return;

    // Index 1: Hintergrund der Box (dunkel)
    gPlttBufferUnfaded[offset + 1] = RGB(8, 9, 11);
    gPlttBufferFaded[offset + 1]   = RGB(8, 9, 11);

    // Index 3: Schatten der Schrift (schwarz)
    gPlttBufferUnfaded[offset + 3] = RGB(0, 0, 0);
    gPlttBufferFaded[offset + 3]   = RGB(0, 0, 0);

    // Index 15: Unsere neue Schriftfarbe (strahlend weiß)
    gPlttBufferUnfaded[offset + 15] = RGB(31, 31, 31);
    gPlttBufferFaded[offset + 15]   = RGB(31, 31, 31);

    // WICHTIG: Keine Überschreibungen mehr für Index 2, 13 oder 14! 
    // Der Rahmen bleibt unangetastet.
}

void LoadMessageBoxGfx(u8 windowId, u16 destOffset, u8 palOffset)
{
    LoadBgTiles(GetWindowAttribute(windowId, WINDOW_BG), Nyxthra_GetMessageBoxGfxVariant(), 0x1C0, destOffset);
    LoadPalette(gMessageBox_Pal, palOffset, PLTT_SIZE_4BPP);
    Nyxthra_ApplyDarkModeToMessageBoxPalette(palOffset);
}

void LoadStdWindowGfx(u8 windowId, u16 destOffset, u8 palOffset)
{
    LoadBgTiles(GetWindowAttribute(windowId, WINDOW_BG), sStdTextWindow_Gfx, 0x120, destOffset);
    LoadPalette(GetTextWindowPalette(3), palOffset, PLTT_SIZE_4BPP);
    Nyxthra_ApplyDarkModeToWindowPalette(palOffset);
}

void LoadSignBoxGfx(u8 windowId, u16 destOffset, u8 palOffset)
{
    LoadBgTiles(GetWindowAttribute(windowId, WINDOW_BG), gSignpostWindow_Gfx, 0x1C0, destOffset);
    LoadPalette(GetTextWindowPalette(1), palOffset, PLTT_SIZE_4BPP);
    Nyxthra_ApplyDarkModeToWindowPalette(palOffset);
}

void LoadUserWindowBorderGfx_(u8 windowId, u16 destOffset, u8 palOffset)
{
    LoadUserWindowBorderGfx(windowId, destOffset, palOffset);
}

void LoadWindowGfx(u8 windowId, u8 frameId, u16 destOffset, u8 palOffset)
{
    LoadBgTiles(GetWindowAttribute(windowId, WINDOW_BG), sWindowFrames[frameId].tiles, 0x120, destOffset);
    LoadPalette(sWindowFrames[frameId].pal, palOffset, PLTT_SIZE_4BPP);
    Nyxthra_ApplyDarkModeToBorderPalette(palOffset);
}

void LoadUserWindowBorderGfx(u8 windowId, u16 destOffset, u8 palOffset)
{
    LoadWindowGfx(windowId, gSaveBlock2Ptr->optionsWindowFrameType, destOffset, palOffset);
}

void DrawTextBorderOuter(u8 windowId, u16 tileNum, u8 palNum)
{
    u8 bgLayer = GetWindowAttribute(windowId, WINDOW_BG);
    u16 tilemapLeft = GetWindowAttribute(windowId, WINDOW_TILEMAP_LEFT);
    u16 tilemapTop = GetWindowAttribute(windowId, WINDOW_TILEMAP_TOP);
    u16 width = GetWindowAttribute(windowId, WINDOW_WIDTH);
    u16 height = GetWindowAttribute(windowId, WINDOW_HEIGHT);

    FillBgTilemapBufferRect(bgLayer, tileNum + 0, tilemapLeft - 1,      tilemapTop - 1,         1,      1,      palNum);
    FillBgTilemapBufferRect(bgLayer, tileNum + 1, tilemapLeft,          tilemapTop - 1,         width,  1,      palNum);
    FillBgTilemapBufferRect(bgLayer, tileNum + 2, tilemapLeft + width,  tilemapTop - 1,         1,      1,      palNum);
    FillBgTilemapBufferRect(bgLayer, tileNum + 3, tilemapLeft - 1,      tilemapTop,             1,      height, palNum);
    FillBgTilemapBufferRect(bgLayer, tileNum + 5, tilemapLeft + width,  tilemapTop,             1,      height, palNum);
    FillBgTilemapBufferRect(bgLayer, tileNum + 6, tilemapLeft - 1,      tilemapTop + height,    1,      1,      palNum);
    FillBgTilemapBufferRect(bgLayer, tileNum + 7, tilemapLeft,          tilemapTop + height,    width,  1,      palNum);
    FillBgTilemapBufferRect(bgLayer, tileNum + 8, tilemapLeft + width,  tilemapTop + height,    1,      1,      palNum);
}

void DrawTextBorderInner(u8 windowId, u16 tileNum, u8 palNum)
{
    u8 bgLayer = GetWindowAttribute(windowId, WINDOW_BG);
    u16 tilemapLeft = GetWindowAttribute(windowId, WINDOW_TILEMAP_LEFT);
    u16 tilemapTop = GetWindowAttribute(windowId, WINDOW_TILEMAP_TOP);
    u16 width = GetWindowAttribute(windowId, WINDOW_WIDTH);
    u16 height = GetWindowAttribute(windowId, WINDOW_HEIGHT);

    FillBgTilemapBufferRect(bgLayer, tileNum + 0, tilemapLeft,              tilemapTop,                 1,          1,          palNum);
    FillBgTilemapBufferRect(bgLayer, tileNum + 1, tilemapLeft + 1,          tilemapTop,                 width - 2,  1,          palNum);
    FillBgTilemapBufferRect(bgLayer, tileNum + 2, tilemapLeft + width - 1,  tilemapTop,                 1,          1,          palNum);
    FillBgTilemapBufferRect(bgLayer, tileNum + 3, tilemapLeft,              tilemapTop + 1,             1,          height - 2, palNum);
    FillBgTilemapBufferRect(bgLayer, tileNum + 5, tilemapLeft + width - 1,  tilemapTop + 1,             1,          height - 2, palNum);
    FillBgTilemapBufferRect(bgLayer, tileNum + 6, tilemapLeft,              tilemapTop + height - 1,    1,          1,          palNum);
    FillBgTilemapBufferRect(bgLayer, tileNum + 7, tilemapLeft + 1,          tilemapTop + height - 1,    width -     2,  1,      palNum);
    FillBgTilemapBufferRect(bgLayer, tileNum + 8, tilemapLeft + width - 1,  tilemapTop + height - 1,    1,          1,          palNum);
}

void rbox_fill_rectangle(u8 windowId)
{
    u8 bgLayer = GetWindowAttribute(windowId, WINDOW_BG);
    u16 tilemapLeft = GetWindowAttribute(windowId, WINDOW_TILEMAP_LEFT);
    u16 tilemapTop = GetWindowAttribute(windowId, WINDOW_TILEMAP_TOP);
    u16 width = GetWindowAttribute(windowId, WINDOW_WIDTH);
    u16 height = GetWindowAttribute(windowId, WINDOW_HEIGHT);

    FillBgTilemapBufferRect(bgLayer, 0, tilemapLeft - 1, tilemapTop - 1, width + 2, height + 2, 0x11);
}

const u16 *GetTextWindowPalette(u8 id)
{
    switch (id)
    {
    case 0:
        id = 0x00;
        break;
    case 1:
        id = 0x10;
        break;
    case 2:
        id = 0x20;
        break;
    case 3:
        id = 0x30;
        break;
    case 4:
    default:
        id = 0x40;
        break;
    }

    return (const u16 *)(sTextWindowPalettes) + id;
}

const u16 *GetOverworldTextboxPalettePtr(void)
{
    return gMessageBox_Pal;
}

// Wendet Dark-Mode-Palette auf ein bereits geladenes Text-Fenster an (Direkt im VRAM!)
void Nyxthra_ApplyDarkModeToWindowPalette(u32 offset)
{
    u32 i;

    if (gSaveBlock2Ptr == NULL || !gSaveBlock2Ptr->optionsUITheme)
        return;

    // Index 1 wird in den Textboxen als Fuellfarbe genutzt (Hintergrund)
    gPlttBufferUnfaded[offset + 1] = RGB(8, 9, 11);
    gPlttBufferFaded[offset + 1]   = RGB(8, 9, 11);

    // Wir scannen den gesamten Rahmen (alles ab Index 4, damit die Textfarben 2 und 3 sicher sind!)
    for (i = 4; i < 16; i++)
    {
        u16 c = gPlttBufferUnfaded[offset + i];
        u8 r = (c >> 0) & 0x1F;
        u8 g = (c >> 5) & 0x1F;
        u8 b = (c >> 10) & 0x1F;
        
        u8 max = r;
        u8 min = r;
        if (g > max) max = g;
        if (b > max) max = b;
        if (g < min) min = g;
        if (b < min) min = b;

        // DER ULTIMATIVE FILTER: 
        // Ist die Farbe neutral/grau (max - min <= 5) UND nicht komplett schwarz (>= 40)?
        if ((u16)(r + g + b) >= 40 && (max - min) <= 5)
        {
            // RADIKAL ALLES AUF DEN DUNKLEN HINTERGRUND SETZEN!
            // Das killt den fetten grauen Balken in der Speicher-Box sofort.
            gPlttBufferUnfaded[offset + i] = RGB(8, 9, 11);
            gPlttBufferFaded[offset + i]   = RGB(8, 9, 11);
        }
    }
}

// Da Rahmenpaletten je nach Frame unterschiedlich aufgebaut sind, werden hier nur
// sehr helle neutrale (nahe weiss/grau) Eintraege abgedunkelt; Akzentfarben bleiben.
void Nyxthra_ApplyDarkModeToBorderPalette(u32 offset)
{
    u32 i;

    if (gSaveBlock2Ptr == NULL || !gSaveBlock2Ptr->optionsUITheme)
        return;

    // Nur helle Toene scannen
    for (i = 1; i < 16; i++)
    {
        u16 c = gPlttBufferUnfaded[offset + i];
        u8 r = (c >> 0) & 0x1F;
        u8 g = (c >> 5) & 0x1F;
        u8 b = (c >> 10) & 0x1F;

        u8 max = r;
        u8 min = r;

        if (g > max)
            max = g;
        if (b > max)
            max = b;
        if (g < min)
            min = g;
        if (b < min)
            min = b;

        if ((u16)(r + g + b) >= 80 && (max - min) <= 3)
        {
            gPlttBufferUnfaded[offset + i] = RGB(8, 9, 11);
            gPlttBufferFaded[offset + i]   = RGB(8, 9, 11);
        }
    }
}
// Effectively LoadUserWindowBorderGfx but specifying the bg directly instead of a window from that bg
void LoadUserWindowBorderGfxOnBg(u8 bg, u16 destOffset, u8 palOffset)
{
    LoadBgTiles(bg, sWindowFrames[gSaveBlock2Ptr->optionsWindowFrameType].tiles, 0x120, destOffset);
    LoadPalette(GetWindowFrameTilesPal(gSaveBlock2Ptr->optionsWindowFrameType)->pal, palOffset, PLTT_SIZE_4BPP);
    Nyxthra_ApplyDarkModeToBorderPalette(palOffset);
}

void LoadDexNavWindowGfx(u8 windowId, u16 destOffset, u8 palOffset)
{
    LoadBgTiles(GetWindowAttribute(windowId, WINDOW_BG), sDexNavWindowFrame.tiles, 0x120, destOffset);
    LoadPalette(sDexNavWindowFrame.pal, palOffset, 32);
}
