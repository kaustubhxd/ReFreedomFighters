#include "ff.h"

static u32 THISCALL fn64c1e0(u8 *self, u8 *data) {
  u32 first = G(u32, data + 0xc);
  if (first) {
    u32 manager = G(u32, self + 0x1005d);
    u8 *table = (u8 *)G(u32, manager + 0x234);
    vcall<void>(table, 0xc, first);
    G(u32, data + 0xc) = 0;
  }
  u8 *node = (u8 *)G(u32, data + 0x1c);
  while (node) {
    u8 *flags = (u8 *)G(u32, node + 8);
    G(u32, flags + 0x14) &= ~G(u32, self + 0x10059);
    node = (u8 *)G(u32, node + 0x1c);
  }
  G(u32, data + 0x1c) = 0;
  return 0;
}

PCREG(64c1e0, fn64c1e0);
