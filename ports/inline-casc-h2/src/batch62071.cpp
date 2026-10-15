#include "ff.h"

static u8 *THISCALL fn5b7dd0(u8 *self) {
  G(u32, self) = 0;
  G(u32, self + 4) = 0x47c35000u;
  G(u32, self + 8) = 0;
  G(u32, self + 0xc) = 0;
  u8 *table = (u8 *)G(u32, G(u32, 0x70039c) + 0x9b);
  u8 *resource = (u8 *)vcall<u32>(table, 0x138);
  u32 out = 0;
  vcall<void>(resource, 0x88, 0x6a6700u, (u32)&out);
  G(u32, self + 0xc) = vcall<u32>(table, 0x58, out);
  return self;
}

PCREG(5b7dd0, fn5b7dd0);
