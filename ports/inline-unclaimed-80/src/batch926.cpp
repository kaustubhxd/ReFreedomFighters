#include "ff.h"
// batch926.cpp - unclaimed-80 claim 6 (docs/20-unclaimed-80.md). CEntityTracker::Save(ZSaveGame*) (0x5c07f0, high, vtable).
// Clears bit 0x40 at this+4. Calls the save object's slots: +0x60 (byte at +0x68), +0x64 (dword +0x64), +0x3c (dwords +0x54,
// +0x58, +0x5c), +0x4c (float bits +0x60). Then, for i < count (+0x54, nothing when zero), with e = arr(+0x50) + 0x17*i:
// +0x64 (dword e), +0x68 (pointer e+4), +0x60 (byte e+0x10), +0x4c (float bits e+0x11), +0x40 (word e+0x15), +0x3c (dword
// ptr[i] from the array at +0x4c). Returns true (al = 1). Every call is thiscall with one argument.

static void saveSlot(u8 *save, u32 off, u32 arg) {
  typedef void(THISCALL * s_fn)(u8 *, u32);
  ((s_fn)(*(u32 *)(*(u32 *)save + off)))(save, arg);
}

static u8 THISCALL entityTrackerSave(u8 *self, u8 *save) {
  *(u32 *)(self + 4) &= 0xffffffbfu;
  saveSlot(save, 0x60, self[0x68]);
  saveSlot(save, 0x64, *(u32 *)(self + 0x64));
  saveSlot(save, 0x3c, *(u32 *)(self + 0x54));
  saveSlot(save, 0x3c, *(u32 *)(self + 0x58));
  saveSlot(save, 0x3c, *(u32 *)(self + 0x5c));
  saveSlot(save, 0x4c, *(u32 *)(self + 0x60));
  u32 count = *(u32 *)(self + 0x54);
  for (u32 i = 0; i < count; i++) {
    u8 *e = *(u8 **)(self + 0x50) + i * 0x17;
    saveSlot(save, 0x64, *(u32 *)e);
    saveSlot(save, 0x68, (u32)(e + 4));
    saveSlot(save, 0x60, e[0x10]);
    saveSlot(save, 0x4c, *(u32 *)(e + 0x11));
    saveSlot(save, 0x40, *(u16 *)(e + 0x15));
    saveSlot(save, 0x3c, (*(u32 **)(self + 0x4c))[i]);
  }
  return 1;
}
PCREG(5c07f0, entityTrackerSave);
