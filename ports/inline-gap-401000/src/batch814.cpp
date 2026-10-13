// batch814.cpp - core gameplay batch 814 (docs/20-unclaimed-65.md, batch 814): 0x6352f0, thiscall with one stack pointer argument (ret 4).
// If this+0x38 is zero, it writes zero through the pointer. Otherwise it calls slot 0x30 of the object o = [[[[0x70039c]+0x9b]+8]+4]
// with ecx = o and one argument (this+0x38)-1, and writes the result through the pointer.
#include "ff.h"

typedef u32(THISCALL *F1)(u8 *self, u32 a);

static void THISCALL fn6352f0(u8 *self, u32 *out) {
  const u32 n = *(const u32 *)(self + 0x38);
  if (n == 0) {
    *out = 0;
    return;
  }
  u8 *r9 = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  u8 *a = *(u8 **)(r9 + 8);
  u8 *o = *(u8 **)(a + 4);
  *out = ((F1)(*(const u32 *)(*(const u32 *)o + 0x30)))(o, n - 1);
}

PCREG(6352f0, fn6352f0);
