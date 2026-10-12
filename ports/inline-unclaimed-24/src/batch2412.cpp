// batch2412.cpp - decomp area 24, batch 2412: ZFFMortar::Save(ZSaveGame*) (0x5dd570), thiscall, ret 4, AL = 1.
// Clears flag 0x40 of the object, writes six bytes (+0x48, +0x75, +0x76, +0x77, +0x78, +0x79) through the saver's
// slot 0x60, then the dword at +0x7a (unaligned) through slot 0x3c.
#include "ff.h"

// 0x5dd570
static u8 THISCALL mortarSave(u8 *self, void *sg) {
  *(u32 *)(self + 4) &= 0xffffffbfu;
  vcall<void>(sg, 0x60, (u32)self[0x48]);
  vcall<void>(sg, 0x60, (u32)self[0x75]);
  vcall<void>(sg, 0x60, (u32)self[0x76]);
  vcall<void>(sg, 0x60, (u32)self[0x77]);
  vcall<void>(sg, 0x60, (u32)self[0x78]);
  vcall<void>(sg, 0x60, (u32)self[0x79]);
  vcall<void>(sg, 0x3c, *(u32 *)(self + 0x7a));
  return 1;
}
PCREG(5dd570, mortarSave);
