// batch2430.cpp - decomp area 24, batch 2430.
#include "ff.h"

// 0x514530 ZMoveOnSpline::StopRollingSound(), thiscall, plain ret. Slot 0x2ec with the handle, then the handle is cleared.
static void THISCALL moveOnSplineStopRollingSound(u8 *self) {
  u32 h = *(u32 *)(self + 0x1d9);
  if (h) {
    vcall<void>(self, 0x2ec, h);
    *(u32 *)(self + 0x1d9) = 0;
  }
}
PCREG(514530, moveOnSplineStopRollingSound);

// 0x5390b0 (GUESS owner), thiscall, plain ret, AL = 1. Slot 0xa8, then slot 0x1bc with this+0x53b2.
static u8 THISCALL twoCallSetter(u8 *self) {
  vcall<void>(self, 0xa8);
  vcall<void>(self, 0x1bc, (void *)(self + 0x53b2));
  return 1;
}
PCREG(5390b0, twoCallSetter);

// 0x513130 ZMoveOnSpline::GetRefToPath(), thiscall, plain ret. The table is read before slot 0x1c is called (as the
// original keeps its vtable in a register).
static u32 THISCALL moveOnSplineGetRefToPath(u8 *self) {
  u8 *sys = G(u8 *, 0x70039c);
  void *tab = *(void **)(sys + 0x9b);
  void *a = *(void **)(self + 0x5c);
  u32 h = vcall<u32>(a, 0x1c);
  return vcall<u32>(tab, 0x4c, h);
}
PCREG(513130, moveOnSplineGetRefToPath);
