// batch2444.cpp - decomp area 24, batch 2444 (gap band).
#include "ff.h"

// 0x44b850 (GUESS owner), thiscall, ret 4: slot 0x12c of the sys table object with (this+0x30, argument).
static void THISCALL sysSlot12cAt30(u8 *self, u32 arg) {
  u8 *sys = G(u8 *, 0x70039c);
  void *tab = *(void **)(sys + 0x1a9f);
  u32 r = vcall<u32>(tab, 0x12c, *(u32 *)(self + 0x30), arg);
  *(u32 *)(self + 0x40) |= 1u;
  *(u32 *)(self + 0x30) = r;
}
PCREG(44b850, sysSlot12cAt30);

// 0x44b880 (GUESS owner), thiscall, ret 4: the same with this+0x34.
static void THISCALL sysSlot12cAt34(u8 *self, u32 arg) {
  u8 *sys = G(u8 *, 0x70039c);
  void *tab = *(void **)(sys + 0x1a9f);
  u32 r = vcall<u32>(tab, 0x12c, *(u32 *)(self + 0x34), arg);
  *(u32 *)(self + 0x40) |= 1u;
  *(u32 *)(self + 0x34) = r;
}
PCREG(44b880, sysSlot12cAt34);
