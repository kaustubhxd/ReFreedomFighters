#include "ff.h"

static u32 THISCALL fn657550(u8 *self, u32 item, u32 key, u32 mask) {
  u32 current = key;
  while (current) {
    u8 *node = (u8 *)vcall<u32>(self, 0xc, current);
    if (G(u32, node + 0x2c) & mask) vcall<void>(self, 4, item, (u32)node);
    current = G(u32, node + 8);
  }
  return 0;
}

PCREG(657550, fn657550);
