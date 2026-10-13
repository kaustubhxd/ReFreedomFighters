// batch4004.cpp - area 70 (residue 9), batch 4004: a pure backward scan (0x59e650) and a tail-jump wrapper (0x5a8510).
#include "ff.h"

// 0x59e650 (name GUESS): thiscall, ret 4 (signed arg). While the count at +0x7ce is non-zero, the 16-byte entry at
// +0x7c2 + 16 * count has its dword key read; if the key <= arg (signed), stop; else count--. Writes the final count back.
static void THISCALL scanCountDown(u8 *self, s32 arg) {
  while (*(u32 *)(self + 0x7ce) != 0) {
    u32 count = *(u32 *)(self + 0x7ce);
    s32 key = *(const s32 *)(self + 0x7c2 + 16 * count);
    if (key <= arg)
      break;
    *(u32 *)(self + 0x7ce) = count - 1;
  }
}
PCREG(59e650, scanCountDown);

// 0x5a8510 (name GUESS): thiscall, ret 8. When the first argument is non-zero: the object at +0x634 gets byte +4 = 1 and
// byte +0x98 = the low byte of the second argument, then its slot 0x14 virtual is tail-called with (first, -1), so the
// callee's own ret 8 pops those two arguments. Otherwise nothing happens.
static void THISCALL tailSlot14(u8 *self, u32 a1, u32 a2) {
  if (a1) {
    u8 *o = *(u8 **)(self + 0x634);
    o[4] = 1;
    o[0x98] = (u8)a2;
    vcall<void>(*(u8 **)(self + 0x634), 0x14, a1, 0xffffffffu);
  }
}
PCREG(5a8510, tailSlot14);
