// batch5718.cpp - unclaimed-57 (docs/20-unclaimed-57.md), batch 18: 0x4f1100 (GUESS, unnamed), thiscall, one stack argument (a), ret 4.
// Compares nine dwords at a with the dwords at (dword this+8). On the first mismatch it calls 0x45fc70 (thiscall, one argument a,
// unverified: hooked and logged in the spec) and sets byte this+0x90 = 1. No return value.
#include "ff.h"

extern "C" void THISCALL ext_45fc70(u8 *self, u32 a);  // mismatch handler, original code (hooked in the spec)

static void THISCALL unnamed4f1100(u8 *self, u32 a) {
  u32 *p = (u32 *)(unsigned long)a;
  u32 *q = *(u32 **)(self + 8);
  for (u32 k = 0; k < 9; k++) {
    if (p[k] != q[k]) {
      ext_45fc70(self, a);
      self[0x90] = 1;
      return;
    }
  }
}
PCREG(4f1100, unnamed4f1100);
