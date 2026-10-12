#include "ff.h"
// batch922.cpp - unclaimed-80 claim 2 (docs/20-unclaimed-80.md). CCheckInside::TimeUpdate() (0x4afc30, name from the map).
// 0x4af6d0 (returns the object, thiscall no args), 0x4af500 (thiscall, one argument, ret 4) and 0x4af5b0 (thiscall, one argument) are
// original code; the spec stubs them. Returns nothing; clears the byte at +0x5f.

extern "C" u32 THISCALL ext_4af6d0(u8 *self);
extern "C" void THISCALL ext_4af500(u8 *self, u8 *x);
extern "C" void THISCALL ext_4af5b0(u8 *self, u8 *x);

static void THISCALL checkInsideTimeUpdate(u8 *self) {
  u8 *x = (u8 *)ext_4af6d0(self);
  if (x == 0)
    return;
  typedef u8(THISCALL * fn)(u8 *, u32);
  fn f = *(fn *)(*(u32 *)x + 0x1e0);
  u8 al = f(x, 0x800001au);
  if (al != 0)
    ext_4af5b0(self, x);
  else
    ext_4af500(self, x);
  self[0x5f] = 0;
}
PCREG(4afc30, checkInsideTimeUpdate);
