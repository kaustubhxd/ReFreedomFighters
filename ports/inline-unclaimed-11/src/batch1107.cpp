// batch1107.cpp - unclaimed-11 batch 7 (core-todo residue-10): CCheckInsideBox::Save(ZSaveGame*) (0x5b82e0, high).
// Thiscall, one argument (ret 4), returns true. Clears bit 0x40 of this+4, then five virtual save calls in order:
// slot 0x3c with +0x48, slot 0x3c with +0x4c, slot 0x64 with +0x50, slot 0x64 with +0x54, slot 0x3c with +0x5c.
#include "ff.h"

typedef void(THISCALL *saveFn)(void *self, u32 value);

// 0x5b82e0, CCheckInsideBox::Save(ZSaveGame*) (high).
static bool THISCALL checkInsideBoxSave(u8 *self, u8 *save) {
  *(u32 *)(self + 4) &= ~0x40u;
  void **vt = *(void ***)save;
  ((saveFn)vt[0x3c / 4])(save, *(u32 *)(self + 0x48));
  ((saveFn)vt[0x3c / 4])(save, *(u32 *)(self + 0x4c));
  ((saveFn)vt[0x64 / 4])(save, *(u32 *)(self + 0x50));
  ((saveFn)vt[0x64 / 4])(save, *(u32 *)(self + 0x54));
  ((saveFn)vt[0x3c / 4])(save, *(u32 *)(self + 0x5c));
  return true;
}
PCREG(5b82e0, checkInsideBoxSave);
