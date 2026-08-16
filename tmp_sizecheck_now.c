#include "gba/gba.h"
#include "global.h"
#include "save.h"
#include "pokemon_storage_system.h"
unsigned char size_SaveBlock1[sizeof(struct SaveBlock1)];
unsigned char size_PokemonStorage[sizeof(struct PokemonStorage)];
unsigned char size_SaveBlock2[sizeof(struct SaveBlock2)];
unsigned char limit_SaveBlock1[SECTOR_DATA_SIZE * (SECTOR_ID_SAVEBLOCK1_END - SECTOR_ID_SAVEBLOCK1_START + 1)];
unsigned char limit_PokemonStorage[SECTOR_DATA_SIZE * (SECTOR_ID_PKMN_STORAGE_END - SECTOR_ID_PKMN_STORAGE_START + 1)];
