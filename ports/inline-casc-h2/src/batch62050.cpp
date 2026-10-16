#include "ff.h"

extern "C" void THISCALL ext_562e90(u8 *self, u32 a, u32 b);

static u32 THISCALL fn57b610(u8 *self, u32 a, u32 b) {
  ext_562e90(self, a, b);
  u32 child = vcall<u32>(self, 0x84);
  vcall<u32>((void *)child, 0x350, 0x10000u, 0u, G(u32, self + 0x44));
  u32 engine = G(u32, 0x70039c);
  u32 result = vcall<u32>((void *)engine, 0xbc);
  vcall<u32>((void *)result, 0x74);
  return 0;
}

PCREG(57b610, fn57b610);
