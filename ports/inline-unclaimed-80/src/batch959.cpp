#include "ff.h"
// batch959.cpp - unclaimed-80 gap band (docs/20-unclaimed-80.md): 0x49da60 (high). Stdcall with one stack argument (unused), ret 4.
// [self+0x18] += 1; if it is above 0xc8 (unsigned) and the byte at self+0x28 is zero: call 0x49da90 (ecx = self, no arguments; GUESS
// label, hooked by address in the spec), then [self+0x18] = 0.

extern "C" void THISCALL ext_49da90(u8 *self);

static void THISCALL zg49da60(u8 *self, u32 a1) {
  *(u32 *)(self + 0x18) += 1;
  if (*(u32 *)(self + 0x18) > 0xc8 && *(u8 *)(self + 0x28) == 0) {
    ext_49da90(self);
    *(u32 *)(self + 0x18) = 0;
  }
}
PCREG(49da60, zg49da60);
