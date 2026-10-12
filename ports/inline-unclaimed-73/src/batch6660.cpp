// batch6660.cpp - area 73 batch 66 (gap band, GUESS name): FUN_4e8770.
#include "ff.h"

// 0x4e8770 (GUESS FUN_4e8770): ret 4, returns a dword. T = this+8, X = A+8 where A is the argument. When X != T the result is
// vtable slot +0x10 on this with X. Otherwise the walk starts at e = A's first dword and runs while e != T and the node after e
// links back to the previous node (node's +8 == node); the final e is returned.
static u32 THISCALL guess4e8770(u8 *self, u8 *a) {
  u32 t = *(u32 *)(self + 8);
  u32 x = *(u32 *)(a + 8);
  if (x != t)
    return vcall<u32>(self, 0x10, x);
  u32 node = (u32)a;
  u32 e = *(u32 *)node;
  if (e != t) {
    for (;;) {
      if (node != *(u32 *)(e + 8))
        break;
      node = e;
      e = *(u32 *)e;
      if (e == t)
        break;
    }
  }
  return e;
}
PCREG(4e8770, guess4e8770);
