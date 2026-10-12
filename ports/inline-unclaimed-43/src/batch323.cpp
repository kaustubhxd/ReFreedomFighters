// batch323.cpp - 0x484fe0 (area 71 leaf, residue 10). thiscall (this = ECX), one stack argument (a byte, the low byte of the
// dword pushed), ret 4. Stores that byte at this+0x42c.
#include "ff.h"

static void THISCALL storeByteAt42c(u8 *self, u32 v) {
  self[0x42c] = (u8)v;
}
PCREG(484fe0, storeByteAt42c);
