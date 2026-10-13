// batch334.cpp - 0x58b6a0 (area 71 leaf, residue 10). thiscall (this = ECX), no stack arguments, returns a byte (al).
// Body: out = 0; this->[0] slot 0x90(this->[4], &out); return out.
#include "ff.h"

#define U32(p, off) (*(u32 *)((u8 *)(p) + (off)))

static u8 THISCALL callSlot90ReturnByte(u8 *self) {
  u8 out = 0;
  vcall<void>((void *)(unsigned long)U32(self, 0), 0x90, U32(self, 4), (void *)&out);
  return out;
}
PCREG(58b6a0, callSlot90ReturnByte);
