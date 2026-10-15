#include "ff.h"

static void THISCALL fn6493f0(u8 *self) {
  u8 *list = self + 0x101c1;
  G(u32, list) = 0;
  vcall<u32>(self, 0x34, (u32)list);
  u32 count = G(u32, list);
  for (u32 i = 0; i < count; ++i) {
    u32 item = G(u32, list + 4 + i * 4);
    u32 index = G(u16, item + 0x12);
    G(u32, self + 0x28 + index * 8) |= 0x78000000;
  }
  G(u32, self + 0x24) = (u32)(self + 0x28);
}

PCREG(6493f0, fn6493f0);
