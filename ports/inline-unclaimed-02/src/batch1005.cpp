#include "ff.h"
// batch1005.cpp - unclaimed-02 batch 5 (docs/20-unclaimed-02.md). Name from the GC name map (naming only).
// The callee at 0x5833e0 (CExplode::Explode, not ported) runs as original code; the harness stubs it with a logger.

extern "C" void THISCALL ext_5833e0(u8 *self, u32 a, u32 b);

// 0x584450, CExplode::Init2() (high). Reads the dword at (this+0x44)->+8 ->+0x3c; if bit 10 of it is clear and the byte
// at this+0x5d is nonzero, calls ext_5833e0(this, 0, 0) (thiscall, two stack arguments, callee pops). Plain ret.
static void THISCALL explodeInit2(u8 *self) {
  u32 v = *(u32 *)(*(u8 **)(*(u8 **)(self + 0x44) + 8) + 0x3c);
  if (((v >> 10) & 1) == 0 && self[0x5d] != 0)
    ext_5833e0(self, 0u, 0u);
}
PCREG(584450, explodeInit2);
