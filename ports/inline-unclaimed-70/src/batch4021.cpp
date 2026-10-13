// batch4021.cpp - area 70 (slice 4/5), batch 4021: 0x59e610 (pop while the top entry is not below the argument) and 0x4a2f90
// (two word globals from render-manager calls). Names GUESS.
#include "ff.h"

// 0x59e610 (name GUESS): thiscall (ECX = this), one stack argument v, ret 4. While the count at [this+0x7ce] is non-zero and
// the signed dword at [this + 0x7c2 + 16*count] is not below v, the count is decremented (not below zero); stops when the
// count is zero or the test fails.
static void THISCALL popWhileNotLess(u8 *self, u32 v) {
  if (*(u32 *)(self + 0x7ce) == 0) return;
  for (;;) {
    u32 n = *(u32 *)(self + 0x7ce);
    s32 top = *(s32 *)(self + 0x7c2 + n * 16);
    if (top < (s32)v) return;
    if (n != 0) {
      n--;
      *(u32 *)(self + 0x7ce) = n;
    }
    if (*(u32 *)(self + 0x7ce) == 0) return;
  }
}
PCREG(59e610, popWhileNotLess);

// 0x4a2f90 (name GUESS): no arguments, plain ret. The render manager of the engine global (0x70039c, +0x9b) answers slot
// 0x114 with four arguments; the two results (low words) go to 0x7002e8 and 0x7002ec.
static void THISCALL setTwoWords4a2f90(void) {
  u8 *sys = G(u8 *, 0x70039c);
  void *rm = *(void **)(sys + 0x9b);
  G(u16, 0x7002e8) = (u16)vcall<u32>(rm, 0x114, 0x67b508u, 0u, 0x68f94cu, 0xa0u);
  G(u16, 0x7002ec) = (u16)vcall<u32>(rm, 0x114, 0x68f9e8u, 0u, 0x68f94cu, 0xa1u);
}
PCREG(4a2f90, setTwoWords4a2f90);
