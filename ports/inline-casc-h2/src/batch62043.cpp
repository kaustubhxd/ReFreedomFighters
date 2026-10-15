#include "ff.h"

static u32 THISCALL fn4b0ef0(u8 *self, u32 context) {
  G(u32, self + 4) &= ~0x40u;
  void *obj = (void *)context;
  vcall<u32>(obj, 0x44, G(u32, self + 0x48));
  vcall<u32>(obj, 0x54, G(u32, self + 0x50));
  vcall<u32>(obj, 0x60, (u32)G(u8, self + 0x6c));
  return 1;
}

PCREG(4b0ef0, fn4b0ef0);
