#include "ff.h"

extern "C" void THISCALL ext_564b10(u8 *self);
extern "C" void THISCALL ext_563610(u8 *self, u32 value);

static void THISCALL fn565ab0(u8 *self) {
  ext_564b10(self);
  u32 engine = G(u32, 0x70039c);
  u8 *table = (u8 *)G(u32, engine + 0x9b);
  u32 resource = vcall<u32>((void *)table, 0x138);
  u32 item = vcall<u32>((void *)table, 0x4c, G(u32, self + 0x44), 0x10u);
  vcall<u32>((void *)resource, 0x60, 0x6a6c10u, item);
  ext_563610(self, 0x6a6c1cu);
  G(u8, self + 0x86) = 1;
}

PCREG(565ab0, fn565ab0);
