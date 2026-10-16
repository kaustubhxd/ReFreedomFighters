#include "ff.h"
// batch2802.cpp - unclaimed-28 batch 2 (docs/20-unclaimed-28.md). Names from the GC name map (naming only).

// 0x584eb0, CFireController::Save(ZSaveGame*) (high). Clears bit 0x40 at this+4. Slot +0x3c with the dword at this+0x4c. Then,
// for each record of 28 bytes starting at this+0x50 (count = dword at this+0x4c, re-read on every pass): slot +0x4c with the
// float at record+0x14, slot +0x3c with the dwords at record+0, record+4 and record+0x18, slot +0x68 with record+8. The
// loop is skipped when the count is zero. Returns true.
static u8 THISCALL fireControllerSave(u8 *self, u8 *sg) {
  *(u32 *)(self + 4) &= 0xffffffbfu;
  vcall<void, u32>(sg, 0x3c, *(u32 *)(self + 0x4c));
  u8 *rec = self + 0x50;
  if (rec != self + 0x50 + 28u * *(u32 *)(self + 0x4c)) {
    do {
      vcall<void, float>(sg, 0x4c, *(float *)(rec + 0x14));
      vcall<void, u32>(sg, 0x3c, *(u32 *)rec);
      vcall<void, u32>(sg, 0x3c, *(u32 *)(rec + 4));
      vcall<void, u32>(sg, 0x3c, *(u32 *)(rec + 0x18));
      vcall<void, u8 *>(sg, 0x68, rec + 8);
      rec += 0x1c;
    } while (rec != self + 0x50 + 28u * *(u32 *)(self + 0x4c));
  }
  return 1;
}
PCREG(584eb0, fireControllerSave);

// 0x4b83b0, CTelePortList::Save(ZSaveGame*) (high). Clears bit 0x40 at this+4. Slot +0x3c with the dwords at this+0x4c,
// this+0x50 and this+0x48, in that order. Returns true.
static u8 THISCALL telePortListSave(u8 *self, u8 *sg) {
  *(u32 *)(self + 4) &= 0xffffffbfu;
  vcall<void, u32>(sg, 0x3c, *(u32 *)(self + 0x4c));
  vcall<void, u32>(sg, 0x3c, *(u32 *)(self + 0x50));
  vcall<void, u32>(sg, 0x3c, *(u32 *)(self + 0x48));
  return 1;
}
PCREG(4b83b0, telePortListSave);
