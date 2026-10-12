// batch4722.cpp - area 73 batch 22 (gap band, GUESS names): FUN_4f3ff0 and FUN_4e83b0.
#include "ff.h"

// 0x4f3ff0 (GUESS FUN_4f3ff0): ret 4. r = render control (g_sys+0x9b) slot +0x4c(arg); this+0x60 = r.
static void THISCALL guess4f3ff0(u8 *self, u32 arg) {
  u8 *ctl = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  *(u32 *)(self + 0x60) = vcall<u32>(ctl, 0x4c, arg);
}
PCREG(4f3ff0, guess4f3ff0);

// 0x4e83b0 (GUESS FUN_4e83b0): ret 4, returns a pointer. Walks from the argument through +8 until a node whose +8 equals this+8;
// returns the node before it (the argument itself when its +8 already equals this+8).
static u32 THISCALL guess4e83b0(u8 *self, u32 arg) {
  u32 target = *(u32 *)(self + 8);
  u32 c = arg;
  u32 n = *(u32 *)(c + 8);
  if (n != target) {
    do {
      c = n;
      n = *(u32 *)(c + 8);
    } while (n != target);
  }
  return c;
}
PCREG(4e83b0, guess4e83b0);
