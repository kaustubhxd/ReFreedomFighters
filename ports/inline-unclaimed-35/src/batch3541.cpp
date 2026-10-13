#include "ff.h"
// batch3541.cpp - gap band claim 41 (docs/20-gap-band-561000.md): 0x5636c0 and 0x56a8b0 (GUESS names). Thiscall, two args, ret 8.
// Stubbed in the harness: M.vt+0x58, R.vt+0x1e0, 0x563650, this.vt+0x84, O.vt+0x350, 0x562e90.

typedef u32(THISCALL *TU1)(u8 *self, u32 a0);
typedef u32(THISCALL *TU0)(u8 *self);
typedef u32(THISCALL *TU3)(u8 *self, u32 a0, u32 a1, u32 a2);

extern "C" void THISCALL ext_563650(u8 *self, u32 a0, u32 a1);
extern "C" void THISCALL ext_562e90(u8 *self, u32 a0, u32 a1);

void THISCALL gapMethod5636c0(u8 *self, u32 a0, u32 a1) {
  u8 *M = *(u8 **)(*(u32 *)0x70039c + 0x9b);
  u8 *r = (u8 *)((TU1)*(u32 *)(*(u32 *)M + 0x58))(M, a0);
  if (r == 0)
    return;
  if ((u8)((TU1)*(u32 *)(*(u32 *)r + 0x1e0))(r, 0x100033) == 0)
    return;
  ext_563650(self, (u32)r, a1);
}
PCREG(5636c0, gapMethod5636c0);

u32 THISCALL gapMethod56a8b0(u8 *self, u32 a0, u32 a1) {
  ext_562e90(self, a0, a1);
  if (*(u32 *)(self + 0x1c5) == 4) {
    u8 *o = (u8 *)((TU0)*(u32 *)(*(u32 *)self + 0x84))(self);
    ((TU3)*(u32 *)(*(u32 *)o + 0x350))(o, 0x100000, 0, *(u32 *)(self + 0x44));
  }
  return 0;
}
PCREG(56a8b0, gapMethod56a8b0);
