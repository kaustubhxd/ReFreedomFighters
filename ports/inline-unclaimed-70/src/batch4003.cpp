// batch4003.cpp - area 70 (residue 9), batch 4003: one store routine and two single-virtual members (virtual targets GUESS).
#include "ff.h"

// 0x469550 (store routine, name GUESS): thiscall, ret 8. Args (a, b): +0x14 of this = dword at a+0x2b (unaligned);
// +0x40 of this = a; +8 of this = b, or when b == -1 the dword at a+0x27.
static void THISCALL storeFromArg(u8 *self, u8 *a, s32 b) {
  *(u32 *)(self + 0x14) = *(const u32 *)(a + 0x2b);
  *(u8 **)(self + 0x40) = a;
  *(u32 *)(self + 8) = (b == -1) ? *(const u32 *)(a + 0x27) : (u32)b;
}
PCREG(469550, storeFromArg);

// 0x45c850 (name GUESS): thiscall, ret 8. Calls the slot 0x108 virtual of this with (a, b) (pushed b then a, so the
// callee sees a first); when it returns non-null, sets bit 2 of the dword at its +4.
static void THISCALL callSlot108(u8 *self, u8 *a, u32 b) {
  u8 *r = vcall<u8 *>(self, 0x108, a, b);
  if (r)
    *(u32 *)(r + 4) |= 2;
}
PCREG(45c850, callSlot108);

// 0x4cf210 (name GUESS): thiscall, ret 4. Calls the slot 0x60 virtual of this with the argument; returns 0 when that is
// null, else the dword at the returned pointer.
static u32 THISCALL callSlot60(u8 *self, u32 a) {
  u32 r = vcall<u32>(self, 0x60, a);
  if (!r)
    return 0;
  return *(const u32 *)r;
}
PCREG(4cf210, callSlot60);
