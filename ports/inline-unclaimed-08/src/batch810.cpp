// batch810.cpp - unclaimed-08 batch 10: ZFFPRIVATESTDOBJ::Save(ZSaveGame*) (high). Slice: floor(addr/16) mod 20 = 7.
// Original: the base save 0x45f960 (original code; it writes this+0x14, and this+0x10's +0x18 when this+0x10 is set,
// through the save game's vtable +0x3c), then the save game's vtable +0x64 with this+0x1c and +0x3c with this+0x18,
// and it returns true (al = 1).
#include "ff.h"

extern "C" void THISCALL ext_45f960(void *, void *);  // base save: this (ecx), save game (one argument)

// 0x5aabb0, ZFFPRIVATESTDOBJ::Save(ZSaveGame*) (high). Thiscall, one argument, ret 4, returns true.
static u8 THISCALL privStdObjSave(u8 *self, u8 *saveGame) {
  ext_45f960(self, saveGame);
  vcall<void>(saveGame, 0x64, *(u32 *)(self + 0x1c));
  vcall<void>(saveGame, 0x3c, *(u32 *)(self + 0x18));
  return 1;
}
PCREG(5aabb0, privStdObjSave);
