// batch809.cpp - core gameplay batch 809 (docs/20-unclaimed-65.md, batch 809): 0x45f9a0, a thiscall with two stack words (ret 8). When
// this->+0x10 and its +0x1c are both set, it calls slot 0x5c of the global object 0x7003a4 with ecx = that object and three stack words
// (the callee pops them: the exe has no add esp after the call).
#include "ff.h"

typedef void(THISCALL *F3)(u8 *self, u32 a, u32 b, u32 c);

static void THISCALL fn45f9a0(u8 *self, u32 a, u32 b) {
  u8 *p = *(u8 **)(self + 0x10);
  if (p == 0) return;
  u8 *q = *(u8 **)(p + 0x1c);
  if (q == 0) return;
  u8 *y = *(u8 **)(q + 4);
  const u32 x = *(const u32 *)(y + 4);
  u8 *obj = G(u8 *, 0x7003a4);
  ((F3)(*(const u32 *)(*(const u32 *)obj + 0x5c)))(obj, x, a, b);
}

PCREG(45f9a0, fn45f9a0);
