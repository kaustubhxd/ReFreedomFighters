#include "ff.h"
// batch3545.cpp - slice 14, batch 45 (docs/20-gap-band-561000.md): 0x656f20 and 0x4286e0 (GUESS names). Thiscall, one arg, ret 4.
// Stubbed in the harness: this.vt+0xc (indexed log, returns R), 0x435b50 (thiscall, no args), 0x634273 (cdecl, two args).

typedef u32(THISCALL *TU1)(u8 *self, u32 a0);
typedef u32(THISCALL *TU0)(u8 *self);

extern "C" void THISCALL ext_435b50(u8 *self);
extern "C" void ext_634273(u32 a0, u32 a1);

void THISCALL gapMethod656f20(u8 *self, u32 a0) {
  u32 vt = *(u32 *)self;
  u32 r = ((TU1)*(u32 *)(vt + 0xc))(self, a0);
  u32 v = *(u32 *)(r + 0x90);
  ((TU1)*(u32 *)(*(u32 *)self + 0xc))(self, v);
}
PCREG(656f20, gapMethod656f20);

u8 *THISCALL gapMethod4286e0(u8 *self, u32 a0) {
  *(u32 *)self = 0x678e50;
  ext_435b50(self);
  if ((a0 & 1) != 0)
    ext_634273((u32)self, 0x76);
  return self;
}
PCREG(4286e0, gapMethod4286e0);
