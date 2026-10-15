// batch67518.cpp - cascade s6 batch 67518: 0x468fa0.
#include "ff.h"

extern "C" u32 THISCALL ext_41e680(u8 *self);   // returns a key for this object (plain ret)

#define D32(p, o) (*(u32 *)((u8 *)(p) + (o)))

static inline void rd(u8 *s, u32 dst) { vcall<void>(s, 0x18, dst, 4u); }

// 0x468fa0, thiscall(stream) ret 4, returns 1: loads six header dwords from the stream (slot 0x18 = read(dst, size 4)) into +4, +8, two locals A and B, +0xc, +0x10, +0x1c, +0x38,
// then passes B to slot 0x64 and ~B / 0 to slot 0x68 of this and stores A at +0x14. With bit 3 of A set the registry embedded in the table object at +0xcc is asked for its current
// object (slot 8); if there is one the key from 0x41e680 selects an entry (slot 4) which, when found, is re-registered (slot 0 with the entry and the dword at +0x10).
static u8 THISCALL fn468fa0(u8 *self, u8 *s) {
  u32 A, B;
  rd(s, (u32)(self + 4));
  rd(s, (u32)(self + 8));
  rd(s, (u32)&A);
  rd(s, (u32)&B);
  rd(s, (u32)(self + 0xc));
  rd(s, (u32)(self + 0x10));
  rd(s, (u32)(self + 0x1c));
  rd(s, (u32)(self + 0x38));
  vcall<void>(self, 0x64, B);
  vcall<void>(self, 0x68, ~B, 0u);
  D32(self, 0x14) = A;
  if (A & 8) {
    u8 *sub = *(u8 **)(*(u8 **)0x70039c + 0x9b) + 0xcc;
    if (vcall<u32>(sub, 8)) {
      u32 key = ext_41e680(self);
      u8 *obj = (u8 *)vcall<u32>(sub, 4, key);
      if (obj) vcall<void>(sub, 0, (u32)obj, D32(self, 0x10));
    }
  }
  return 1;
}
PCREG(468fa0, fn468fa0);
