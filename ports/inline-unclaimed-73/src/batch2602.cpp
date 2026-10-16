// batch2602.cpp - area 73 batch 2 (residue 12): ZRepositionCharacter::Load(ZLoadGame*) (0x5c4240, docs/20-unclaimed-73.md).
#include "ff.h"

// 0x5c4240, ZRepositionCharacter::Load(ZLoadGame*) (high), thiscall, ret 4: clears bit 0x40 at this+4; load slot +0x70(this+0x48);
// load slot +0x40(this+0x4c) (writes into this+0x4c); load slot +0x40(&slot) where slot starts as the load pointer; then the
// render-control object at g_sys+0x9b, slot +0x58(slot), stored at this+0x50. Returns true (al).
static bool THISCALL repositionCharacterLoad(u8 *self, u32 load) {
  *(u32 *)(self + 4) &= 0xffffffbfu;
  vcall<void>((void *)load, 0x70, *(u32 *)(self + 0x48));
  vcall<void>((void *)load, 0x40, (u32)(self + 0x4c));
  u32 slot = load;
  vcall<void>((void *)load, 0x40, &slot);
  u8 *sys = G(u8 *, 0x70039c);
  u8 *ctl = *(u8 **)(sys + 0x9b);
  *(u32 *)(self + 0x50) = vcall<u32>(ctl, 0x58, slot);
  return true;
}
PCREG(5c4240, repositionCharacterLoad);
