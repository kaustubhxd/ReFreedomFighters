// batch327.cpp - 0x4876a0 (area 71 leaf, residue 10). thiscall (this = ECX), two stack arguments (a at [ebp+8], b at
// [ebp+0xc]), ret 8, returns this. Stores: this+0x10 = b, this+4 = a, [this] = vtable 0x68cf50, byte +0x1c = 1, dwords
// +0xc, +0x14, +0x18, +0x8 = 0.
#include "ff.h"

#define U32(p, off) (*(u32 *)((u8 *)(p) + (off)))

static u8 *THISCALL initPairRecord(u8 *self, u32 a, u32 b) {
  U32(self, 0x10) = b;
  U32(self, 0x4) = a;
  U32(self, 0x0) = 0x68cf50u;
  self[0x1c] = 1;
  U32(self, 0xc) = 0;
  U32(self, 0x14) = 0;
  U32(self, 0x18) = 0;
  U32(self, 0x8) = 0;
  return self;
}
PCREG(4876a0, initPairRecord);
