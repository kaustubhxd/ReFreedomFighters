// batch965.cpp - residue-05 (core todo), batch 965: ZFFActor::GetWeaponDrawn(unsigned int), 0x5a0050, thiscall, ret 4.
// X = render manager vslot 0x58(id); A = this vslot 0x504(); B = this vslot 0x500(). True (al = 1) when X is non-zero and
// equals A or B; false otherwise.
#include "ff.h"

// 0x5a0050 ZFFActor::GetWeaponDrawn(unsigned int).
static u8 THISCALL weaponDrawn(u8 *t, u32 id) {
  void *rm = *(void **)(*(u8 **)0x70039c + 0x9b);
  u32 x = vcall<u32>(rm, 0x58, id);
  u32 a = vcall<u32>(t, 0x504);
  u32 b = vcall<u32>(t, 0x500);
  if (x != 0 && (x == a || x == b))
    return 1;
  return 0;
}
PCREG(5a0050, weaponDrawn);
