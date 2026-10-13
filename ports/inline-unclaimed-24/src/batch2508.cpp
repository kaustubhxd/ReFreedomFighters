// batch2508.cpp - decomp area 24, batch 2508. 0x46d6c0 ZItemTemplateWeapon::DestroyItem (GUESS signature), stdcall(obj), ret 4.
// Null obj: ret 4. Otherwise obj becomes ECX and slot 0x210 of its vtable is tail-jumped to with the argument replaced by 1;
// modelled as call-and-return (the callee is a thiscall taking one argument and popping it: the ret 4 of the null path shows
// the function itself pops one dword, so the target must too).
#include "ff.h"

static void STDCALL destroyItem(u8 *obj) {
  if (!obj) return;
  typedef void(THISCALL * fn)(void *, u32);
  (*(fn **)obj)[0x210 / 4](obj, 1);
}
PCREG(46d6c0, destroyItem);
