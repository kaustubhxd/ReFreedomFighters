#include "ff.h"
// batch3542.cpp - gap band claim 42 (docs/20-gap-band-561000.md): 0x563710 and 0x5678e0 (GUESS names). Thiscall, two args, ret 8.
// Stubbed in the harness: 0x563650, 0x5af130 (returns a per-call sequence), 0x5aedf0, and arg0's vtable +0x1e0.

typedef u32(THISCALL *TU1)(u8 *self, u32 a0);
typedef u32(THISCALL *TU0)(u8 *self);

extern "C" void THISCALL ext_563650(u8 *self, u32 a0, u32 a1);
extern "C" u32 THISCALL ext_5af130(u8 *self, u32 a0);
extern "C" void THISCALL ext_5aedf0(u8 *self, u32 a0);

void THISCALL gapMethod563710(u8 *self, u32 a0, u32 a1) {
  if (a0 == 0)
    return;
  if ((u8)((TU1)*(u32 *)(*(u32 *)a0 + 0x1e0))((u8 *)a0, 0x100033) == 0)
    return;
  ext_563650(self, a0, a1);
}
PCREG(563710, gapMethod563710);

u32 THISCALL gapMethod5678e0(u8 *self, u32 a0, u32 a1) {
  u32 r = ext_5af130((u8 *)a1, a0);
  if (r == 0 && a0 != 0) {
    u32 r2 = ext_5af130(self + 0x180, a0);
    if (r2 != 0) {
      ext_5aedf0((u8 *)a1, r2);
      return a0;
    }
  }
  return 0;
}
PCREG(5678e0, gapMethod5678e0);
