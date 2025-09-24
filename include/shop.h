#ifndef GUARD_SHOP_H
#define GUARD_SHOP_H

extern struct ItemSlot gMartPurchaseHistory[3];

void CreatePokemartMenu(const u16 *itemsForSale);
void CreateDecorationShop1Menu(const u16 *itemsForSale);
void CreateDecorationShop2Menu(const u16 *itemsForSale);
void CB2_ExitSellMenu(void);
void GetJokeText(u8 jokeChoice);
void GetJokeOffset0(void);
void GetJokeOffset1(void);
void GetJokeOffset2(void);

#endif // GUARD_SHOP_H
