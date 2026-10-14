// batch842.cpp - area 50 (residue-10 list): ZItemTemplateWeapon::Save(ZSaveGame*) [high, vt 4].
// The base group is saved first (ZGROUP::Save, 0x441790, hooked), then the weapon fields go to the save stream through
// its virtuals: +0x6c(int +0x70), +0x70(ptr +0xdb), +0x68(ptr +0xff), +0x4c(float +0x10b), +0x4c(float +0x10f),
// +0x64 for the four words +0x11b, +0x11f, +0x123, +0x127. Returns true.
#include "ff.h"

#define F32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define FF(p, o) (*(float *)((u8 *)(p) + (o)))

extern "C" void THISCALL ext_441790(void *self, void *stream);   // ZGROUP::Save (not ported here)

static bool THISCALL ZItemTemplateWeapon_Save(u8 *self, void *s) {
  ext_441790(self, s);
  vcall<void>(s, 0x6c, F32(self, 0x70));
  vcall<void>(s, 0x70, self + 0xdb);
  vcall<void>(s, 0x68, self + 0xff);
  vcall<void>(s, 0x4c, FF(self, 0x10b));
  vcall<void>(s, 0x4c, FF(self, 0x10f));
  vcall<void>(s, 0x64, F32(self, 0x11b));
  vcall<void>(s, 0x64, F32(self, 0x11f));
  vcall<void>(s, 0x64, F32(self, 0x123));
  vcall<void>(s, 0x64, F32(self, 0x127));
  return true;
}
PCREG(470720, ZItemTemplateWeapon_Save);
