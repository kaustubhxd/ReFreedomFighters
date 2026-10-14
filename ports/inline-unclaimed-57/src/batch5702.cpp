// batch5702.cpp - unclaimed-57 (docs/20-unclaimed-57.md), batch 2: CHitpointControl::Save(ZSaveGame*) (0x584f40), thiscall, one
// argument (the save object), returns al = 1, ret 4. Clears bit 0x40 of this+4; save->vt[+0x4c](float bits of this+0x64);
// save->vt[+0x4c](float bits of this+0x57); save->vt[+0x3c](dword this+0x6c). The three slots are unverified callees, stubbed in
// the spec. The floats are passed by their bits (a plain copy, no float operation).
#include "ff.h"

#define VT(o) (*(void ***)(o))

typedef void(THISCALL *SlotSave)(u8 *self, u32 a);

// 0x584f40, CHitpointControl::Save(ZSaveGame*) (high)
static u8 THISCALL hitpointControlSave(u8 *self, u8 *save) {
  *(u32 *)(self + 4) &= 0xffffffbfu;
  ((SlotSave)VT(save)[0x4c / 4])(save, *(u32 *)(self + 0x64));
  ((SlotSave)VT(save)[0x4c / 4])(save, *(u32 *)(self + 0x57));
  ((SlotSave)VT(save)[0x3c / 4])(save, *(u32 *)(self + 0x6c));
  return 1;
}
PCREG(584f40, hitpointControlSave);
