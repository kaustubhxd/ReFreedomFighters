#include "ff.h"

extern "C" u32 THISCALL ext_612030(u8 *self, u32 value, u32 extra);

static u32 THISCALL fn6120f0(u8 *self, u32 key, u32 extra1, u32 extra2) {
  if (key == 0 || key == 0x800)
    return ext_612030(self, 0x724ae8u, extra2);
  u8 *nested = (u8 *)G(u32, self + 0x13e7);
  u32 value = vcall<u32>((void *)nested, 4, key, extra1);
  return ext_612030(self, value, extra2);
}

PCREG(6120f0, fn6120f0);
