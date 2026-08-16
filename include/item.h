#ifndef GUARD_ITEM_H
#define GUARD_ITEM_H

#include "constants/item.h"
#include "constants/item_effects.h"
#include "constants/items.h"
#include "constants/moves.h"
#include "constants/tms_hms.h"
#include "constants/item_effects.h"
#include "constants/hold_effects.h"
#include "randomizer.h"

/* Each of these TM_HM enums corresponds an index in the list of TMs + HMs item ids in
 * gTMHMItemMoveIds. The index for an item can be retrieved with GetItemTMHMIndex below.
 */
#define UNPACK_TM_HM_ENUM(_tmHm) CAT(ENUM_TM_HM_, _tmHm),
enum TMHMIndex
{
    FOREACH_TMHM(UNPACK_TM_HM_ENUM)
    NUM_TECHNICAL_MACHINES = ITEM_TM100 - ITEM_TM01 + 1,
    NUM_HIDDEN_MACHINES = ITEM_HM08 - ITEM_HM01 + 1,
    NUM_ALL_MACHINES = NUM_TECHNICAL_MACHINES + NUM_HIDDEN_MACHINES,
};
#undef UNPACK_TM_HM_ENUM

enum PACKED ItemSortType
{
    ITEM_TYPE_UNCATEGORIZED,
    ITEM_TYPE_FIELD_USE,
    ITEM_TYPE_LEVEL_UP_ITEM,
    ITEM_TYPE_HEALTH_RECOVERY,
    ITEM_TYPE_STATUS_RECOVERY,
    ITEM_TYPE_PP_RECOVERY,
    ITEM_TYPE_NATURE_MINT,
    ITEM_TYPE_STAT_BOOST_DRINK,
    ITEM_TYPE_STAT_BOOST_FEATHER,
    ITEM_TYPE_STAT_BOOST_MOCHI,
    ITEM_TYPE_BATTLE_ITEM,
    ITEM_TYPE_FLUTE,
    ITEM_TYPE_X_ITEM,
    ITEM_TYPE_AUX_ITEM,
    ITEM_TYPE_EVOLUTION_STONE,
    ITEM_TYPE_EVOLUTION_ITEM,
    ITEM_TYPE_SPECIAL_HELD_ITEM,
    ITEM_TYPE_MEGA_STONE,
    ITEM_TYPE_Z_CRYSTAL,
    ITEM_TYPE_TERA_SHARD,
    ITEM_TYPE_HELD_ITEM,
    ITEM_TYPE_TYPE_BOOST_HELD_ITEM,
    ITEM_TYPE_CONTEST_HELD_ITEM,
    ITEM_TYPE_EV_BOOST_HELD_ITEM,
    ITEM_TYPE_GEM,
    ITEM_TYPE_PLATE,
    ITEM_TYPE_MEMORY,
    ITEM_TYPE_DRIVE,
    ITEM_TYPE_INCENSE,
    ITEM_TYPE_NECTAR,
    ITEM_TYPE_GROWTH,
    ITEM_TYPE_SHARD,
    ITEM_TYPE_SELLABLE,
    ITEM_TYPE_RELIC,
    ITEM_TYPE_FOSSIL,
    ITEM_TYPE_MAIL,
};

typedef void (*ItemUseFunc)(u8);

struct ItemInfo
{
    u32 price;
    u16 secondaryId;
    ItemUseFunc fieldUseFunc;
    const u8 *description;
    const u8 *effect;
    const u8 *name;
    const u8 *pluralName;
    u8 holdEffect;
    u8 holdEffectParam;
    u8 importance:2;
    u8 notConsumed:1;
    enum Pocket pocket:5;
    enum ItemSortType sortType;
    u8 type;
    u8 battleUsage;
    u8 flingPower;
    const u32 *iconPic;
    const u16 *iconPalette;
};

struct ALIGNED(2) BagPocket
{
    struct ItemSlot *itemSlots;
    u16 capacity:10;
    enum Pocket id:6;
};

struct TmHmIndexKey
{
    enum Item itemId;
    enum Move moveId;
};

extern const u8 gQuestionMarksItemName[];
extern const struct ItemInfo gItemsInfo[];
extern struct BagPocket gBagPockets[];
extern const struct TmHmIndexKey gTMHMItemMoveIds[];

#define UNPACK_ITEM_TO_TM_INDEX(_tm) case CAT(ITEM_TM_, _tm): return CAT(ENUM_TM_HM_, _tm) + 1;
#define UNPACK_ITEM_TO_HM_INDEX(_hm) case CAT(ITEM_HM_, _hm): return CAT(ENUM_TM_HM_, _hm) + 1;
#define UNPACK_ITEM_TO_TM_MOVE_ID(_tm) case CAT(ITEM_TM_, _tm): return CAT(MOVE_, _tm);
#define UNPACK_ITEM_TO_HM_MOVE_ID(_hm) case CAT(ITEM_HM_, _hm): return CAT(MOVE_, _hm);
#define UNPACK_TM_MOVE_TO_ITEM_ID(_move) case CAT(MOVE_, _move): return CAT(ITEM_TM_, _move);
#define UNPACK_HM_MOVE_TO_ITEM_ID(_move) case CAT(MOVE_, _move): return CAT(ITEM_HM_, _move);

static inline enum TMHMIndex GetItemTMHMIndex(enum Item item)
{
    if (item >= ITEM_TM01 && item <= ITEM_TM100)
        return item - ITEM_TM01 + 1;

    if (item >= ITEM_HM01 && item <= ITEM_HM08)
        return NUM_TECHNICAL_MACHINES + (item - ITEM_HM01 + 1);

    return 0;
}

static inline enum Move GetItemTMHMMoveId(enum Item item)
{
    enum TMHMIndex index = GetItemTMHMIndex(item);
    enum Move move;

    if (index == 0 || index > NUM_ALL_MACHINES)
        return MOVE_NONE;

    move = gTMHMItemMoveIds[index].moveId;

    if (move == MOVE_NONE)
        return MOVE_NONE;

    // HM moves are never randomized - they are required for story progression
    if (item >= ITEM_HM_CUT && item <= ITEM_HM_DIVE)
        return move;
    return Randomizer_GetMove(move, RANDOMIZER_MODE_TMHM);
}

static inline enum Item GetTMHMItemIdFromMoveId(enum Move move)
{
    enum TMHMIndex index;
    enum Move currentMove;

    for (index = 1; index <= NUM_ALL_MACHINES; index++)
    {
        currentMove = gTMHMItemMoveIds[index].moveId;
        if (currentMove == MOVE_NONE)
            continue;

        if (!(gTMHMItemMoveIds[index].itemId >= ITEM_HM_CUT && gTMHMItemMoveIds[index].itemId <= ITEM_HM_DIVE))
            currentMove = Randomizer_GetMove(currentMove, RANDOMIZER_MODE_TMHM);

        if (currentMove == move)
            return gTMHMItemMoveIds[index].itemId;
    }

    return ITEM_NONE;
}

#undef UNPACK_ITEM_TO_TM_INDEX
#undef UNPACK_ITEM_TO_HM_INDEX
#undef UNPACK_ITEM_TO_TM_MOVE_ID
#undef UNPACK_ITEM_TO_HM_MOVE_ID
#undef UNPACK_TM_MOVE_TO_ITEM_ID
#undef UNPACK_HM_MOVE_TO_ITEM_ID

static inline enum Item GetTMHMItemId(enum TMHMIndex index)
{
    if (index == 0 || index > NUM_ALL_MACHINES)
        return ITEM_NONE;

    return gTMHMItemMoveIds[index].itemId;
}

static inline u16 GetTMHMMoveId(enum TMHMIndex index)
{
    if (index == 0 || index > NUM_ALL_MACHINES)
        return MOVE_NONE;

    if (gTMHMItemMoveIds[index].moveId == MOVE_NONE)
        return MOVE_NONE;

    // HM moves are never randomized - they are required for story progression
    if (gTMHMItemMoveIds[index].itemId >= ITEM_HM_CUT && gTMHMItemMoveIds[index].itemId <= ITEM_HM_DIVE)
        return gTMHMItemMoveIds[index].moveId;
    return Randomizer_GetMove(gTMHMItemMoveIds[index].moveId, RANDOMIZER_MODE_TMHM);
}

void BagPocket_SetSlotData(struct BagPocket *pocket, u32 pocketPos, struct ItemSlot newSlot);
struct ItemSlot BagPocket_GetSlotData(struct BagPocket *pocket, u32 pocketPos);

static inline void BagPocket_SetSlotItemIdAndCount(struct BagPocket *pocket, u32 pocketPos, enum Item itemId, u16 quantity)
{
    BagPocket_SetSlotData(pocket, pocketPos, (struct ItemSlot) {itemId, quantity});
}

static inline u16 GetBagItemId(enum Pocket pocketId, u32 pocketPos)
{
    return BagPocket_GetSlotData(&gBagPockets[pocketId], pocketPos).itemId;
}

static inline u16 GetBagItemQuantity(enum Pocket pocketId, u32 pocketPos)
{
    return BagPocket_GetSlotData(&gBagPockets[pocketId], pocketPos).quantity;
}

static inline struct ItemSlot GetBagItemIdAndQuantity(enum Pocket pocketId, u32 pocketPos)
{
    return BagPocket_GetSlotData(&gBagPockets[pocketId], pocketPos);
}

void ApplyNewEncryptionKeyToBagItems(u32 newKey);
void SetBagItemsPointers(void);
u8 *CopyItemName(enum Item itemId, u8 *dst);
u8 *CopyItemNameHandlePlural(enum Item itemId, u8 *dst, u32 quantity);
bool32 IsBagPocketNonEmpty(enum Pocket pocketId);
bool32 CheckBagHasItem(enum Item itemId, u16 count);
bool32 HasAtLeastOneBerry(void);
bool32 HasAtLeastOnePokeBall(void);
bool32 CheckBagHasSpace(enum Item itemId, u16 count);
u32 GetFreeSpaceForItemInBag(enum Item itemId);
bool32 AddBagItem(enum Item itemId, u16 count);
bool32 RemoveBagItem(enum Item itemId, u16 count);
void RemoveBagItemFromSlot(struct BagPocket *pocket, u16 slotId, u16 count);
u8 CountUsedPCItemSlots(void);
bool32 CheckPCHasItem(enum Item itemId, u16 count);
bool32 AddPCItem(enum Item itemId, u16 count);
void RemovePCItem(u8 index, u16 count);
void CompactPCItems(void);
void SwapRegisteredBike(void);
void CompactItemsInBagPocket(enum Pocket pocketId);
void MoveItemSlotInPocket(enum Pocket pocketId, u32 from, u32 to);
void MoveItemSlotInPC(struct ItemSlot *itemSlots, u32 from, u32 to);
void ClearBag(void);
u16 CountTotalItemQuantityInBag(enum Item itemId);
bool32 AddPyramidBagItem(enum Item itemId, u16 count);
bool32 RemovePyramidBagItem(enum Item itemId, u16 count);
const u8 *GetItemName(enum Item itemId);
u32 GetItemPrice(enum Item itemId);
const u8 *GetItemEffect(enum Item itemId);
enum HoldEffect GetItemHoldEffect(enum Item itemId);
u32 GetItemHoldEffectParam(enum Item itemId);
const u8 *GetItemDescription(enum Item itemId);
u8 GetItemImportance(enum Item itemId);
u8 GetItemConsumability(enum Item itemId);
enum Pocket GetItemPocket(enum Item itemId);
enum ItemType GetItemType(enum Item itemId);
ItemUseFunc GetItemFieldFunc(enum Item itemId);
enum EffectItem GetItemBattleUsage(enum Item itemId);
u32 GetItemSecondaryId(enum Item itemId);
u32 GetItemFlingPower(enum Item itemId);
u32 GetItemStatus1Mask(enum Item itemId);
bool32 ItemHasVolatileFlag(enum Item itemId, enum Volatile volatile);
u32 GetItemSellPrice(enum Item itemId);
bool32 IsHoldEffectChoice(enum HoldEffect holdEffect);

#endif // GUARD_ITEM_H
