// batch689.cpp - unclaimed-68 batch 9 (claim 8). Names from the GC name map (naming only, never committed).
#include "ff.h"

// CRT sized operator delete, cdecl (pointer, size), original code; the spec hooks and logs it.
extern "C" void __attribute__((cdecl)) ext_634273(void *p, u32 size);

// 0x4cdf30, REFTAB32::DeleteBlock(TabBlk*) (medium): thiscall, ret 4. The inline block at this+0x1c is never freed; any other
// block is freed with the sized delete, size 0x10.
static void THISCALL refTab32DeleteBlock(u8 *self, u8 *block) {
  if (block != self + 0x1c) ext_634273(block, 0x10);
}
PCREG(4cdf30, refTab32DeleteBlock);
