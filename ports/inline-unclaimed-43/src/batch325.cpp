// batch325.cpp - 0x4407a0 (area 71 leaf, residue 10). thiscall (this = ECX), one stack argument, ret 4.
// Body: this slot 0x2c0(arg, 0x800).
#include "ff.h"

static void THISCALL callSlot2c0(u8 *self, u32 arg) {
  vcall<void>((void *)self, 0x2c0, arg, 0x800u);
}
PCREG(4407a0, callSlot2c0);
