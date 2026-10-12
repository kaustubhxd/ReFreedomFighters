#include "ff.h"
// batch1004.cpp - unclaimed-02 batch 4 (docs/20-unclaimed-02.md). Name from the GC name map (naming only).

// 0x584d00, CExplode::Save(ZSaveGame*) (high). Clears bit 0x40 in the dword at this+4, then calls the save game's
// virtual slot +0x3c with the dword at this+0x5e. Returns true (al = 1). The save game arrives on the stack.
static u8 THISCALL explodeSave(u8 *self, u8 *sg) {
  *(u32 *)(self + 4) &= 0xffffffbfu;
  vcall<void, u32>(sg, 0x3c, *(u32 *)(self + 0x5e));
  return 1;
}
PCREG(584d00, explodeSave);
