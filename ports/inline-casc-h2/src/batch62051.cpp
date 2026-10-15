#include "ff.h"

static u32 THISCALL fn473960(u8 *self) {
  u32 child = vcall<u32>(self, 0x504);
  vcall<u32>(self, 0x54c, 0u, 1u);
  vcall<u32>((void *)child, 0x2d0, 0u, 0u);
  vcall<u32>((void *)child, 0x2f0, 0u, 0u, 1u);
  return vcall<u32>((void *)child, 0x210, 1u);
}

PCREG(473960, fn473960);
