#include "ff.h"
// batch1513.cpp - unclaimed-15 claim 13 (docs/20-unclaimed-15.md): ZFFHeroIf::CenterPrint(OpaqueCallParameters_t&) (0x55f5e0).
// Name from the GC name map (medium). Thiscall, one argument, ret 4. The callees 0x5003d0, 0x506040, 0x589c20 and 0x59a580
// are stubbed in the harness (thiscall; they clean their own arguments). The hero's slot +0x1e0 is a logged vtable slot.

typedef u32(THISCALL *Slot1)(u8 *self, u32 a1);

extern "C" u32 THISCALL ext_5003d0(u8 *self, u32 a0, u32 a1, u32 a2);   // stubbed
extern "C" u32 THISCALL ext_506040(u8 *self);                            // stubbed
extern "C" u32 THISCALL ext_589c20(u8 *self, u32 a0, u32 a1);            // stubbed
extern "C" u32 THISCALL ext_59a580(u8 *self);                            // stubbed

// 0x55f5e0, ZFFHeroIf::CenterPrint(OpaqueCallParameters_t&) (medium).
static void THISCALL heroIfCenterPrint(u8 *self, u32 a1) {
  u8 *hero = *(u8 **)(self + 0x18);
  u32 vt = *(u32 *)hero;
  if (!((Slot1)*(u32 *)(vt + 0x1e0))(hero, 0x2003e8))
    return;
  hero = *(u8 **)(self + 0x18);
  u8 bl = (u8)*(u32 *)(hero + 0x684);
  u32 x = ext_5003d0(*(u8 **)(a1 + 4), 0, 0xffffffffu, 0);
  u32 y = ext_506040((u8 *)x);
  bl = (u8)(bl - 1);
  u32 z = ext_589c20(*(u8 **)0x7003b8, (u32)bl, y);
  ext_59a580((u8 *)z);
}
PCREG(55f5e0, heroIfCenterPrint);
