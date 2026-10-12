#include "ff.h"
// batch2805.cpp - unclaimed-28 batch 5 (docs/20-unclaimed-28.md). Name from the GC name map (naming only).

// 0x5c27b0, ZFenceGate::Load(ZLoadGame*) (high). Clears bit 0x40 at this+4. The load game's slot +0x68 with this+0x25a
// returns an object; that object's slot +0x68 with this+0x25b returns another; that one's slot +0x40 is called with this+0x50.
// Returns true (al = 1). The load game arrives on the stack.
static u8 THISCALL fenceGateLoad(u8 *self, u8 *ld) {
  *(u32 *)(self + 4) &= 0xffffffbfu;
  u8 *o1 = vcall<u8 *, u8 *>(ld, 0x68, self + 0x25a);
  u8 *o2 = vcall<u8 *, u8 *>(o1, 0x68, self + 0x25b);
  vcall<void, u8 *>(o2, 0x40, self + 0x50);
  return 1;
}
PCREG(5c27b0, fenceGateLoad);
