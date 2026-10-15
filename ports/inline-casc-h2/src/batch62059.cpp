#include "ff.h"

static u32 THISCALL fn4b14a0(u8 *self, u32 key, u32 value) {
  if ((u16)key == G(u16, self + 0x48)) {
    u32 engine = G(u32, 0x70039c);
    u8 *table = (u8 *)G(u32, engine + 0x9b);
    u32 found = vcall<u32>((void *)table, 0x4c, G(u32, self + 0x44));
    u8 *child = (u8 *)G(u32, self + 0x44);
    vcall<u32>((void *)child, 0x12c, G(u32, self + 0x4c), (u16)G(u16, self + 0x4a), found);
    vcall<u32>((void *)child, 0x12c, G(u32, self + 0x4c), (u16)G(u16, self + 0x48), value);
  }
  return 0;
}

PCREG(4b14a0, fn4b14a0);
