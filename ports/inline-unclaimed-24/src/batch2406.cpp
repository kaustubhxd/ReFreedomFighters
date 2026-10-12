// batch2406.cpp - decomp area 24, batch 2406: ZDiscoMove::Save(ZSaveGame*) (0x4ca570), thiscall, ret 4.
// Clears flag 0x40 of the object, then writes seven 3-float blocks (+0x48..+0x90 and +0xa1, +0xad) through the
// saver's slot 0x68, a byte (+0x9c) through slot 0x60 and a dword (+0x9d, unaligned) through slot 0x3c.
#include "ff.h"

// 0x4ca570
static void THISCALL discoMoveSave(u8 *self, void *sg) {
  *(u32 *)(self + 4) &= 0xffffffbfu;
  vcall<void>(sg, 0x68, self + 0x48);
  vcall<void>(sg, 0x68, self + 0x54);
  vcall<void>(sg, 0x68, self + 0x60);
  vcall<void>(sg, 0x68, self + 0x6c);
  vcall<void>(sg, 0x68, self + 0x78);
  vcall<void>(sg, 0x68, self + 0x84);
  vcall<void>(sg, 0x68, self + 0x90);
  vcall<void>(sg, 0x60, (u32)self[0x9c]);
  vcall<void>(sg, 0x3c, *(u32 *)(self + 0x9d));
  vcall<void>(sg, 0x68, self + 0xa1);
  vcall<void>(sg, 0x68, self + 0xad);
}
PCREG(4ca570, discoMoveSave);
