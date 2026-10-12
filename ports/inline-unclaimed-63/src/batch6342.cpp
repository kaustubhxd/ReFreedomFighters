// batch6342.cpp - unclaimed-63 gap-band batch 42: 0x4dcac0 (A+D+E set; no GC name), thiscall, two stack arguments a1, a2, ret 8.
//   If this[+0x24], [+0x28], [+0x2c] equal a2[0], a2[1], a2[2], and the six dwords of this (+0 to +0x14) equal a1's, return.
//   Otherwise: store a2's three dwords at this[+0x24], [+0x28], [+0x2c]; copy the 0x24 bytes of a1 into this (the 0x4de420 copy,
//   original code); this[+0x3c] |= 0x100000; call slot 0 of the object at [[[0x70039c]+0x9b]+0x5d31] with ECX = that object and one
//   stack argument, this (the callee pops 4, as in 0x4dca60).
#include "ff.h"

typedef void(THISCALL * call1_fn)(void *, u8 *);

// 0x4dcac0 (A+D+E set).
static void THISCALL unnamed4dcac0(u8 *self, u8 *a1, u8 *a2) {
  u32 *s = (u32 *)self;
  u32 *a = (u32 *)a2;
  u32 *x = (u32 *)a1;
  bool same = s[9] == a[0] && s[10] == a[1] && s[11] == a[2];
  if (same) {
    for (u32 i = 0; i < 6; i++) {
      if (s[i] != x[i]) {
        same = false;
        break;
      }
    }
  }
  if (same)
    return;
  s[9] = a[0];
  s[10] = a[1];
  s[11] = a[2];
  for (u32 k = 0; k < 9; k++)
    s[k] = x[k];
  *(u32 *)(self + 0x3c) |= 0x100000u;
  u32 eng = G(u32, 0x70039c);
  u32 db = *(u32 *)(eng + 0x9b);
  u8 *obj = (u8 *)*(u32 *)(db + 0x5d31);
  ((call1_fn)(*(u32 *)(*(u32 *)obj)))((void *)obj, self);
}
PCREG(4dcac0, unnamed4dcac0);
