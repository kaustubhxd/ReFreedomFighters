// batch1020.cpp - unclaimed-07 batch 20 (slice 6, small leaves from the full list): ZFFHintBox::Save and
// CMPCheckInsideHill::CopyData. Names from the GC name map (high). Bodies from the PC bytes.
#include "ff.h"

// 0x5b7760, ZFFHintBox::Save(ZSaveGame*) (high), thiscall, ret 4: clears bit 0x40 at this+4; save slot +0x44(this+0x4c);
// save slot +0x3c(this+0x48); returns true (ret=None, al only).
static bool THISCALL ffHintBoxSave(u8 *self, u8 *s) {
  *(u32 *)(self + 4) &= 0xffffffbfu;
  vcall<void>(s, 0x44, *(u32 *)(self + 0x4c));
  vcall<void>(s, 0x3c, *(u32 *)(self + 0x48));
  return true;
}
PCREG(5b7760, ffHintBoxSave);

// 0x5d3aa0, CMPCheckInsideHill::CopyData(ZEventBase*) (high), thiscall, ret 4: copies the dwords at src+0x4c and src+0x50
// to this+0x4c and this+0x50.
static void THISCALL mpCheckInsideHillCopyData(u8 *self, u8 *src) {
  *(u32 *)(self + 0x4c) = *(u32 *)(src + 0x4c);
  *(u32 *)(self + 0x50) = *(u32 *)(src + 0x50);
}
PCREG(5d3aa0, mpCheckInsideHillCopyData);
