// batch505.cpp - unclaimed-05 batch 5 (claim 5, slice floor(addr/16) mod 20 = 4). Names from the GC name map (naming
// only, never committed).
#include "ff.h"

// Original code of the callees (the bodies are not ported here; each one is the exe's own function).
extern "C" void THISCALL ext_43f900(u8 *self, u8 *dblk);           // base CopyDataBlock(DBLK*), ret 4
extern "C" void THISCALL ext_4e12e0(u8 *dblk, u8 *ptr, u32 one);   // data-block copy of a field at ptr, ret 8
extern "C" void THISCALL ext_4e1b30(u8 *dblk);                      // data-block finish, ret 0
extern "C" void THISCALL ext_4e11e0(u8 *dblk, u8 *ptr, u32 one);   // data-block copy of a field at ptr, ret 8

// 0x46d240, ZItemWeapon::CopyDataBlock(DBLK*) (high): base copy (0x43f900), then field copies from this+0x60 and this+0xba
// each followed by the finish call (0x4e1b30), all on the data block; ret 4.
static void THISCALL itemWeaponCopyDataBlock(u8 *self, u8 *dblk) {
  ext_43f900(self, dblk);
  ext_4e12e0(dblk, self + 0x60, 1);
  ext_4e1b30(dblk);
  ext_4e11e0(dblk, self + 0xba, 1);
  ext_4e1b30(dblk);
}
PCREG(46d240, itemWeaponCopyDataBlock);
