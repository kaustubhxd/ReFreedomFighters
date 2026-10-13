#include "ff.h"
// batch3540.cpp - gap band claim 40 (docs/20-gap-band-561000.md): 0x566e50 (GUESS name). Thiscall, two args, ret 8.
// Stubbed in the harness: the manager's M vtable +0x114 (four args, returns a word) and 0x561cb0 (thiscall, two args).

typedef u32(THISCALL *TU4)(u8 *self, u32 a0, u32 a1, u32 a2, u32 a3);

extern "C" void THISCALL ext_561cb0(u8 *self, u32 a0, u32 a1);

void THISCALL gapMethod566e50(u8 *self, u32 a0, u32 a1) {
  u8 *M = *(u8 **)(*(u32 *)0x70039c + 0x9b);
  u32 r16 = (u16)((TU4)*(u32 *)(*(u32 *)M + 0x114))(M, 0x6a6ffc, 0, 0x6a6fd0, 0xc4);
  if ((u16)a0 == (u16)r16)
    *(u32 *)(self + 0x188) = *(u32 *)a1;
  ext_561cb0(self, a0, a1);
}
PCREG(566e50, gapMethod566e50);
