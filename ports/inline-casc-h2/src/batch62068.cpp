#include "ff.h"

static void THISCALL fn463f60(u8 *self) {
  u32 count = G(u32, self + 0x20);
  for (u32 i = 0; i < count; ++i) vcall<void>(self, 0x340, i, 0u);
  u8 *entry = (u8 *)G(u32, self + 0x1c);
  for (u32 i = 0; i < count; ++i, entry += 0x18) {
    G(u32, entry + 4) &= 0xfffffffcu;
    G(u32, entry) = 0;
    G(u32, entry + 0x10) = 0;
    G(u32, entry + 0x14) = 0;
  }
}

PCREG(463f60, fn463f60);
