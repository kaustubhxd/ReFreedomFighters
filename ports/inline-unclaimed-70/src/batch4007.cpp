// batch4007.cpp - area 70 (residue 9), batch 4007: a 36-byte copy with a flag (0x4dcb90) and a vtable-setting member
// with two slot-0x14 calls (0x5f0450, callee GUESS).
#include "ff.h"

// 0x4dcb90 (name GUESS): thiscall, ret 4. Copies 36 bytes from the argument to this (the exe's mcpy at 0x4de420: two
// 16-byte moves and one dword, ported here as nine dwords), then sets bit 0x100000 in the dword at +0x3c.
static void THISCALL copyMatrixSetFlag(u8 *self, const u8 *src) {
  for (int i = 0; i < 9; i++)
    *(u32 *)(self + 4 * i) = *(const u32 *)(src + 4 * i);
  *(u32 *)(self + 0x3c) |= 0x100000u;
}
PCREG(4dcb90, copyMatrixSetFlag);

// 0x5f0450 (name GUESS): thiscall, ret 4, returns this. Stores the vtable 0x6b8284 at this, then this+0xc = obj's slot
// 0x14 with the constant 0x6aaa88, and this+0x10 = obj's slot 0x14 with the constant 0x6b1e6c.
static u8 *THISCALL vtableAndTwoLookups(u8 *self, u8 *obj) {
  *(u32 *)self = 0x6b8284u;
  *(u32 *)(self + 0xc) = vcall<u32>(obj, 0x14, 0x6aaa88u);
  *(u32 *)(self + 0x10) = vcall<u32>(obj, 0x14, 0x6b1e6cu);
  return self;
}
PCREG(5f0450, vtableAndTwoLookups);
