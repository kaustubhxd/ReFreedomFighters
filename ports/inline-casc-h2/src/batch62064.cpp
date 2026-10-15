#include "ff.h"

extern "C" u32 THISCALL ext_5625c0(u8 *self, u32 value);

static u32 THISCALL fn56a090(u8 *self, u32 value) {
  if (G(u32, self + 0x1c5) == 7) {
    u8 *component = (u8 *)vcall<u32>(self, 0x84);
    u32 enabled = vcall<u32>(component + 0xcb, 0x14);
    if (enabled == 1) {
      u8 *table = (u8 *)G(u32, G(u32, 0x70039c) + 0x9b);
      u8 *resource = (u8 *)vcall<u32>(table, 0x138);
      u32 *out = (u32 *)((u8 *)__builtin_frame_address(0) + 8);
      *out = 0;
      vcall<void>(resource, 0x88, 0x6a6c28u, (u32)out);
      value = *out;
    }
  }
  return ext_5625c0(self, value);
}

PCREG(56a090, fn56a090);
