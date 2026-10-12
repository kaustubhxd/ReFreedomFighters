#include "ff.h"
// batch943.cpp - unclaimed-80 (docs/20-unclaimed-80.md): GUESS FUN_45bab0 (0x45bab0, no name in the map; a wrapper). Thiscall, three
// stack arguments (a1, index, float bits), ret 12. X = [this + 4*index + 0x8d8]. If X is nonzero: zero a 16-byte local, then call
// 0x45bb10 (original code, thiscall, five stack arguments: a1, X, the float, the float again, the local's address; ret 20) hooked by the spec.
// The cookie check (0x633654) is omitted.

extern "C" void THISCALL ext_45bb10(u8 *self, u32 a1, u32 x, u32 f0, u32 f1, u32 *local);

static void THISCALL guessFun45bab0(u8 *self, u32 a1, u32 index, u32 fbits) {
  u8 *x = *(u8 **)(self + index * 4 + 0x8d8);
  if (x == 0)
    return;
  u32 local[4] = {0, 0, 0, 0};
  ext_45bb10(self, a1, (u32)x, fbits, fbits, local);
}
PCREG(45bab0, guessFun45bab0);
