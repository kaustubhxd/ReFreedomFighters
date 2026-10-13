// batch356.cpp - 0x41f160 (gap band). thiscall (this = ECX), no arguments; zeroes the dwords at this+8, this+0xc, this+0x10.
#include "ff.h"

#define U32(p, off) (*(u32 *)((u8 *)(p) + (off)))

static void THISCALL zeroThreeAt8(u8 *self) {
  U32(self, 0x8) = 0;
  U32(self, 0xc) = 0;
  U32(self, 0x10) = 0;
}
PCREG(41f160, zeroThreeAt8);
