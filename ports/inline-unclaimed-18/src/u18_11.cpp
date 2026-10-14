// u18_11.cpp - area 18, group 11 (unclaimed-18 thread).
#include "ff.h"

extern "C" void THISCALL ext_441790(void *self, void *saveGame);  // ZGROUP::Save(ZSaveGame*) (ret 4; original code)

// 0x454950, ZInstance::Save(ZSaveGame*) (GC map high). thiscall, one stack arg (ret 4); returns true (AL). Saves the group
// base, then calls slot 0x3c of the save object with the dword at this+0x5c.
static bool THISCALL instanceSave(u8 *self, u8 *saveGame) {
  ext_441790(self, saveGame);
  vcall<void>(saveGame, 0x3c, *(u32 *)(self + 0x5c));
  return true;
}
PCREG(454950, instanceSave);
