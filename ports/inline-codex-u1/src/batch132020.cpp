// Port derived from inline-fresh-10 batch1014; strict verification by codex-u1.
#include "ff.h"
#define F32(p,o) (*(u32*)((u8*)(p)+(o)))
#define FL(p,o) (*(float*)((u8*)(p)+(o)))
static u8 THISCALL SliderOnStateChanged(u8 *self, u32 id, u32 st) {
  if (id != F32(self, 0xab)) return 0;
  if (st == 1) {
    vcall<void>(vcall<void *>(self, 0x2c4), 0x350, 0xcu, 0x102u, self);
    vcall<void>(vcall<void *>(self, 0x2c4), 0x350, 0xcu, 0x103u, self);
    if (self[0xd3]) {
      self[0xd3] = 0;
      vcall<void>(self, 0x358);
    }
    return 0;
  }
  if (st == 2) {
    float t[2];
    vcall<void>(vcall<void *>(self, 0x2c4), 0x308, t);
    FL(self, 0xcf) = t[0];
    self[0xd3] = 1;
  } else if (st != 8) {
    return 0;
  }
  vcall<void>(vcall<void *>(self, 0x2c4), 0x34c, 0xcu, 0x102u, self, 0x41200000u, 1u);
  vcall<void>(vcall<void *>(self, 0x2c4), 0x34c, 0xcu, 0x103u, self, 0x41200000u, 1u);
  return 0;
}
PCREG(4f8120, SliderOnStateChanged);
