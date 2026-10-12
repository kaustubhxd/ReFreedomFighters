#include "ff.h"
// batch910.cpp - unclaimed-01 claim 9 (docs/20-unclaimed-01.md). COpenWindow::Save(ZSaveGame*) (0x5c3dc0, high).

// Clears bit 0x40 of the dword at this+4. Calls vtable slot +0x60 of the save object with the zero-extended byte at
// this+0x48, then vtable slot +0x3c with the (unaligned) dword at this+0x49. Returns true (al = 1). Both calls are
// thiscall with one argument.
static u8 THISCALL openWindowSave(u8 *self, u8 *save) {
  *(u32 *)(self + 4) &= 0xffffffbfu;
  typedef void(THISCALL * slot_fn)(u8 *, u32);
  slot_fn f60 = *(slot_fn *)(*(u32 *)save + 0x60);
  f60(save, (u32)self[0x48]);
  slot_fn f3c = *(slot_fn *)(*(u32 *)save + 0x3c);
  f3c(save, *(u32 *)(self + 0x49));
  return 1;
}
PCREG(5c3dc0, openWindowSave);
