// batch1409.cpp - unclaimed-14 batch 9 (slice 13): ZFFFlak::Save(ZSaveGame*).
#include "ff.h"

// 0x5dcfd0, ZFFFlak::Save(ZSaveGame*) (high): thiscall, one stack argument (the save object), returns true (al = 1).
// Clears bit 0x40 of the dword at +4; calls the save object's vtable slot +0x4c with the float bits at +0x48, then slot
// +0x4c with the float bits at +0x4c, then slot +0x3c with the dword at +0x58. Each call's one argument is popped by
// the callee (ret 4), so the port's plain calls leave the stack as the PC does.
static u8 THISCALL flakSave(u8 *self, u8 *save) {
  *(u32 *)(self + 4) &= ~0x40u;
  typedef void(THISCALL * slot_fn)(u8 *, u32);
  u32 v1 = *(u32 *)(self + 0x48);
  (*(slot_fn *)(*(u32 *)save + 0x4c))(save, v1);
  u32 v2 = *(u32 *)(self + 0x4c);
  (*(slot_fn *)(*(u32 *)save + 0x4c))(save, v2);
  (*(slot_fn *)(*(u32 *)save + 0x3c))(save, *(u32 *)(self + 0x58));
  return 1;
}
PCREG(5dcfd0, flakSave);
