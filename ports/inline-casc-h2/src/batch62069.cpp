#include "ff.h"

extern "C" void THISCALL ext_4614d0(u8 *self, u32 a, u32 b, u32 c);

static u32 THISCALL fn486480(u8 *self) {
  u8 *first = (u8 *)G(u32, self + 0xc);
  vcall<u32>(first, 0x10);
  u32 value = G(u32, self + 0x10);
  if (!value) return vcall<u32>(self, 0xc);
  u8 *action = (u8 *)G(u32, self + 8);
  u8 *resource = (u8 *)vcall<u32>(action, 0x228, value, 1u, 0u, 0x41200000u, 0x3f800000u);
  ext_4614d0(resource, 0x41200000u, 0x465710u, 0u);
  return 1;
}

PCREG(486480, fn486480);
