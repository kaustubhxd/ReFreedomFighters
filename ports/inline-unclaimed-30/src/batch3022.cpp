// batch3022.cpp - unclaimed-30 claim 2 (residue 10): ZItemAmmo::Load(ZLoadGame*) [map 0x46f5a0; thiscall, ret 4, returns al]. The base
// class load (0x46f520, exe code, thiscall with the load object) decides: false returns false; true calls the load object's slot 0x48
// with this+0x8e and returns true.
#include "ff.h"

extern "C" u8 THISCALL ext_46f520(u8 *self, u8 *load);   // base class load (exe code; ret 4; returns al)

static u8 THISCALL itemAmmoLoad(u8 *self, u8 *load) {
  if (!ext_46f520(self, load)) return 0;
  vcall<void>(load, 0x48, (void *)(self + 0x8e));
  return 1;
}
PCREG(46f5a0, itemAmmoLoad);
