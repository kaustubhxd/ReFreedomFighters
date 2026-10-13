#include "ff.h"
// batch1006.cpp - unclaimed-02 batch 6 (docs/20-unclaimed-02.md). Name from the GC name map (naming only).

// 0x49f210, CMsgForwardToActors::Save(ZSaveGame*) (high). Clears bit 0x40 at this+4. Then on the save game (sg):
// slot +0x40 with the word at this+0x48 (zero-extended), slot +0x40 with the word at this+0x4a, slot +0x4c with the
// float at this+0x4c, slot +0x3c with the dword at this+0x50. Returns true (al = 1). The save game arrives on the stack.
static u8 THISCALL msgForwardToActorsSave(u8 *self, u8 *sg) {
  *(u32 *)(self + 4) &= 0xffffffbfu;
  vcall<void, u32>(sg, 0x40, (u32)*(u16 *)(self + 0x48));
  vcall<void, u32>(sg, 0x40, (u32)*(u16 *)(self + 0x4a));
  vcall<void, float>(sg, 0x4c, *(float *)(self + 0x4c));
  vcall<void, u32>(sg, 0x3c, *(u32 *)(self + 0x50));
  return 1;
}
PCREG(49f210, msgForwardToActorsSave);
