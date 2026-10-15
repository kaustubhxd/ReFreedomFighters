#include "ff.h"

static u8 *THISCALL fn46ed50(u8 *self) {
  u32 index = *(u32 *)(self + 0xa0);
  u32 *items = *(u32 **)(self + 0x98);
  u32 element = items[index];
  u32 next = index + 1;
  if (next == *(u32 *)(self + 0x9c)) next = 0;
  *(u32 *)(self + 0xa0) = next;
  u8 *engine = G(u8 *, 0x70039c);
  u8 *table = *(u8 **)(engine + 0x9b);
  u8 *item = vcall<u8 *>(table, 0x58, element);
  u8 *sub = *(u8 **)(item + 8);
  u32 state = *(u32 *)(sub + 0x3c);
  if (((state >> 10) & 1) != 0) vcall<void>(item, 0x2c);
  return item;
}

PCREG(46ed50, fn46ed50);
