#include "ff.h"
// batch3544.cpp - slice 14, batch 44 (docs/20-gap-band-561000.md): 0x472420 and 0x497720 (GUESS names). Thiscall, one arg, ret 4.
// Stubbed in the harness: the vtable +8 slot of the sub-object at this+0x34f (thiscall, two args) and 0x497610 (thiscall, one arg).

typedef void(THISCALL *TV2)(u8 *self, u32 a0, u32 a1);

extern "C" u32 THISCALL ext_497610(u8 *self, u32 a0);

void THISCALL gapMethod472420(u8 *self, u32 a0) {
  u8 *sub = self + 0x34f;
  u32 vt = *(u32 *)(self + 0x34f);
  ((TV2)*(u32 *)(vt + 8))(sub, (u32)self, a0);
}
PCREG(472420, gapMethod472420);

u32 THISCALL gapMethod497720(u8 *self, u32 a0) {
  if (*(u32 *)(self + 0x24) == 0)
    return 0;
  {
    u8 *inner = *(u8 **)(self + 0x14);
    u32 lim = *(u32 *)(inner + 4) + *(u32 *)(self + 0x28);
    if (lim > a0)
      return 0;
  }
  {
    u32 p = ext_497610(self, a0);
    *(u32 *)p = 0;
    return p;
  }
}
PCREG(497720, gapMethod497720);
