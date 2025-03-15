#include "global.h"
#include "constants/items.h"
#include "constants/layouts.h"

#include "berry.h"
#include "load_save.h"
#include "item.h"
#include "malloc.h"
#include "money.h"
#include "play_time.h"
#include "random.h"

#include "rogue_save.h"
#include "rogue.h"
#include "constants/rogue.h"
#include "rogue_controller.h"
#include "rogue.h"

#ifdef IGNORE_THIS_FILE

#define ROGUE_SAVE_BLOCK_CAPACITY (sizeof(struct BoxPokemon) * IN_BOX_COUNT * LEFTOVER_BOXES_COUNT)

enum
{
    ROGUE_SAVE_FORMAT_UNKNOWN,
    ROGUE_SAVE_FORMAT_READ,
    ROGUE_SAVE_FORMAT_WRITE,
};

struct SaveBlockStream
{
    void* data;
    size_t offset;
    size_t size;
    u32 encryptionKey;
    bool8 isWriteMode;
};

STATIC_ASSERT(sizeof(struct RogueSaveBlock) < ROGUE_SAVE_BLOCK_CAPACITY, RogueSaveBlockSize);

static void FlipEncryptMemory(void* ptr, size_t size, u32 encryptionKey)
{
    if(encryptionKey)
    {
        size_t i;
        u8* write;
        u8* encryptionBytes = (u8*)&encryptionKey;

        for(i = 0; i < size; ++i)
        {
            write = (u8*)(ptr) + i;
            *write = *write ^ encryptionBytes[i % 4];
        }
    }
}

static bool8 UNUSED_RELEASE IsSerializeRangeValid(struct SaveBlockStream* block, size_t size)
{
    void* startAddr = block->data + block->offset;
    void* endAddr = startAddr + size;
    return (size_t)endAddr < (size_t)(block->data + block->size);
}

static void SerializeData(struct SaveBlockStream* block, void* ptr, size_t size)
{
    void* addr = block->data + block->offset;
    AGB_ASSERT(IsSerializeRangeValid(block, size));

    if(block->isWriteMode)
    {
        memcpy(addr, ptr, size);

        FlipEncryptMemory(addr, size, block->encryptionKey);
    }
    else
    {
        memcpy(ptr, addr, size);

        FlipEncryptMemory(ptr, size, block->encryptionKey);
    }

    block->offset += size;
}

static void SerializeArray(struct SaveBlockStream* block, void* ptr, size_t elementSize, size_t arraySize)
{
    u16 serializedSize = arraySize;
    SerializeData(block, &serializedSize, sizeof(serializedSize));

    if(serializedSize <= arraySize)
    {
        SerializeData(block, ptr, elementSize * serializedSize);
    }
    else
    {
        // Fire this as a warning but tbh it's probably fine
        // This happens if we reduce an array
        AGB_ASSERT(FALSE);

        // We have more data in the save than we now have capacity for
        SerializeData(block, ptr, elementSize * arraySize); // grab as much as we can
        block->offset += elementSize * (serializedSize - arraySize); // skip over the rest of the data
    }
}

void RogueSave_UpdatePointers()
{
    void* ptr = &gPokemonStoragePtr->boxes[TOTAL_BOXES_COUNT][0];
    gRogueSaveBlock = (struct RogueSaveBlock*)ptr;
}

u16 RogueSave_GetVersionIdFor(u16 saveVersion)
{
    switch (saveVersion)
    {
    case 0:
        return SAVE_VER_ID_1_X;

    case 1:
        return SAVE_VER_ID_2_0_PRERELEASE;

    case 2:
        return SAVE_VER_ID_2_0;
    
    default:
        AGB_ASSERT(FALSE);
        return SAVE_VER_ID_UNKNOWN;
    }
}

u16 RogueSave_GetVersionId()
{
    return RogueSave_GetVersionIdFor(gRogueSaveBlock->saveVersion);
}

#endif