#include "ff.h"
// batch1515.cpp - unclaimed-15 claim 15 (docs/20-unclaimed-15.md): ZActionControlMap::Load(ZLoadGame*) (0x5b3e60).
// Name from the GC name map (high). Thiscall, one argument, ret 4, returns true.
// The load object's slots +0x40 and +0x50 are writer stubs in the harness: each stores a value through its pointer
// argument. The render manager's slot +0x58 is a logged stub. The exe's argument slot is written by the first load (it
// is the caller's stack word), so the port takes the parameter's address, as the exe does.

typedef u32(THISCALL *Slot1)(u8 *self, u32 a1);

static void callLoad(u8 *load, u32 index, u32 ptr) {
  u32 vt = *(u32 *)load;
  ((Slot1)*(u32 *)(vt + index))(load, ptr);
}

// 0x5b3e60, ZActionControlMap::Load(ZLoadGame*) (high).
static u8 THISCALL actionControlMapLoad(u8 *self, u32 zload) {
  u8 *esi = (u8 *)zload;
  *(u32 *)(self + 4) &= ~0x40u;
  callLoad(esi, 0x40, (u32)&zload);
  *(u32 *)(self + 0x4d) = zload;
  u32 l4 = 0;
  callLoad(esi, 0x40, (u32)&l4);
  u8 *rm = *(u8 **)0x70039c;
  u8 *obj = *(u8 **)(rm + 0x9b);
  u32 vt = *(u32 *)obj;
  *(u32 *)(self + 0x5f) = ((Slot1)*(u32 *)(vt + 0x58))(obj, l4);
  callLoad(esi, 0x50, (u32)(self + 0x238));
  callLoad(esi, 0x40, (u32)&zload);
  *(u32 *)(self + 0x250) = zload;
  u32 l8 = 0;
  callLoad(esi, 0x40, (u32)&l8);
  self[0x1b2] = (u8)l8;
  return 1;
}
PCREG(5b3e60, actionControlMapLoad);
