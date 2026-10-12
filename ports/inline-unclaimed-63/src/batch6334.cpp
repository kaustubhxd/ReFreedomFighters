// batch6334.cpp - unclaimed-63 gap-band batch 34: 0x4dca60 (A+D set; no GC name), thiscall, one pointer argument, ret 4.
//   Compares the six dwords at this with the six dwords at the argument (24 bytes). If they all match, return.
//   Otherwise copy the 0x24 bytes of the argument into this (the 0x4de420 copy, original code), set bit 0x100000 in [this+0x3c],
//   then call slot 0 of the object at [[[0x70039c]+0x9b]+0x5d31] with ECX = that object and one stack argument, this.
//   The callee pops its argument (ret 4), since the function ends with ret 4 and no stack adjustment after the call.
#include "ff.h"

typedef void(THISCALL * call1_fn)(void *, u8 *);

// 0x4dca60 (A+D set).
static void THISCALL unnamed4dca60(u8 *self, u8 *arg) {
  u32 *a = (u32 *)arg;
  u32 *s = (u32 *)self;
  for (u32 i = 0; i < 6; i++) {
    if (s[i] != a[i]) {
      // mismatch: copy 0x24 bytes (four dwords, the 16-byte blocks at +0 and +0x10, then the dword at +0x20)
      for (u32 k = 0; k < 9; k++)
        s[k] = a[k];
      *(u32 *)(self + 0x3c) |= 0x100000u;
      u32 eng = G(u32, 0x70039c);
      u32 db = *(u32 *)(eng + 0x9b);
      u8 *obj = (u8 *)*(u32 *)(db + 0x5d31);
      ((call1_fn)(*(u32 *)(*(u32 *)obj)))((void *)obj, self);
      return;
    }
  }
}
PCREG(4dca60, unnamed4dca60);
