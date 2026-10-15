#include "ff.h"

extern "C" u32 THISCALL ext_5003d0(u8 *reader, u32 slot);

static u32 THISCALL fn51ea20(u8 *self, u8 *arg) {
  u8 *reader = (u8 *)G(u32, arg + 4);
  u32 p = ext_5003d0(reader, 0);
  u32 v = G(u32, p);
  G(u32, G(u32, self + 0x18) + 0x28e) = v;
  p = ext_5003d0(reader, 1);
  v = G(u32, p);
  G(u32, G(u32, self + 0x18) + 0x292) = v;
  p = ext_5003d0(reader, 2);
  v = G(u32, p);
  G(u32, G(u32, self + 0x18) + 0x296) = v;
  return v;
}

PCREG(51ea20, fn51ea20);
