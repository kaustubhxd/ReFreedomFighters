// batch954.cpp - residue-03 (core todo), batch 954: ZDamageBox::Save(ZSaveGame*), 0x5db4f0, thiscall, ret 4, returns true.
// Clears flag 0x40 of [this+4]; saves [this+0x48] (vslot 0x64), [this+0x4c] and [this+0x50] (vslot 0x4c floats); the
// object at [this+0x84] answers vslot 0x14 (saved with vslot 0x3c); then walks it with vslot 0x4c(&loc) and vslot 0x5c(&loc)
// (loc is the "more" flag, the returned object is the entry), saving each entry's float at +9 (vslot 0x4c) and dword at +0
// (vslot 0x3c). The exe's first 0x5c test and the loop's bottom test are both on loc.
#include "ff.h"

#define D(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define F(p, o) (*(float *)((u8 *)(p) + (o)))

// 0x5db4f0 ZDamageBox::Save(ZSaveGame*).
static u8 THISCALL dmgBoxSave(u8 *t, u8 *sg) {
  D(t, 4) &= ~0x40u;
  vcall<void>(sg, 0x64, D(t, 0x48));
  vcall<void>(sg, 0x4c, F(t, 0x4c));
  vcall<void>(sg, 0x4c, F(t, 0x50));
  void *x = (void *)D(t, 0x84);
  vcall<void>(sg, 0x3c, vcall<u32>(x, 0x14));
  u32 loc = 0;
  vcall<void>(x, 0x4c, (u32)&loc);
  u8 *e = (u8 *)vcall<u32>(x, 0x5c, (u32)&loc);
  if (loc) {
    do {
      vcall<void>(sg, 0x4c, F(e, 9));
      vcall<void>(sg, 0x3c, D(e, 0));
      e = (u8 *)vcall<u32>(x, 0x5c, (u32)&loc);
    } while (loc);
  }
  return 1;
}
PCREG(5db4f0, dmgBoxSave);
