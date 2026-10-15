// batch981.cpp - residue-10 (core todo), batch 981: ZItemTemplateWeapon::Load(ZLoadGame*), 0x46f6e0, thiscall, ret 4, returns 1.
// The base 0x440e10 (stood in) first. Then L vslot 0x70(this+0x70), L vslots 0x74(&this+0xdb), 0x6c(&this+0xff), 0x50(&this+0x10b)
// and 0x50(&this+0x10f); then four reads through L vslot 0x40 into a local, each answered by the render manager's vslot 0x58, stored
// at this+0x11b, +0x11f, +0x123 and +0x127.
#include "ff.h"

extern "C" void THISCALL ext_440e10(void *self, void *ld);   // base load (stood in)

#define D(p, o) (*(u32 *)((u8 *)(p) + (o)))

// 0x46f6e0 ZItemTemplateWeapon::Load(ZLoadGame*).
static u8 THISCALL templateWeaponLoad(u8 *t, u8 *L) {
  ext_440e10(t, L);
  vcall<void>(L, 0x70, D(t, 0x70));
  vcall<void>(L, 0x74, (u32)(t + 0xdb));
  vcall<void>(L, 0x6c, (u32)(t + 0xff));
  vcall<void>(L, 0x50, (u32)(t + 0x10b));
  vcall<void>(L, 0x50, (u32)(t + 0x10f));
  void *rm = *(void **)(*(u8 **)0x70039c + 0x9b);
  u32 slot = 0;
  vcall<void>(L, 0x40, (u32)&slot);
  D(t, 0x11b) = vcall<u32>(rm, 0x58, slot);
  vcall<void>(L, 0x40, (u32)&slot);
  D(t, 0x11f) = vcall<u32>(rm, 0x58, slot);
  vcall<void>(L, 0x40, (u32)&slot);
  D(t, 0x123) = vcall<u32>(rm, 0x58, slot);
  vcall<void>(L, 0x40, (u32)&slot);
  D(t, 0x127) = vcall<u32>(rm, 0x58, slot);
  return 1;
}
PCREG(46f6e0, templateWeaponLoad);
