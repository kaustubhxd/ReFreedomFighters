// batch951.cpp - residue-03 (core todo), batch 951: ZWeaponTest::CreateWeapons, 0x46d5f0, thiscall no args, void.
// Releases the previous weapon (vslot 0x210 on [this+0x1e0], arg 1), creates the new one (vslot 0x2c4 on the
// [this+0x4c + 4*[this+0x370]] object with args ([this+0x44], 'MEIT'), stored at [this+0x1e0], vslot 0x358 with arg 1),
// then builds a vector (0, 0, pi/2) and calls 0x4de7a0 (ECX) and 0x4de7e0 (fastcall ECX, EDX) on it and
// vslot 0x2d4 on the new weapon with (vector, out[3]). Exe helpers run as is; the vtable slots are stood in.
#include "ff.h"

extern "C" void THISCALL ext_4de7a0(void *self);                 // exe, no args
extern "C" void FASTCALL ext_4de7e0(void *a, void *b);           // exe, fastcall (ECX, EDX)

#define D(p, o) (*(u32 *)((u8 *)(p) + (o)))

// 0x46d5f0 ZWeaponTest::CreateWeapons().
static void THISCALL weaponsCreate(u8 *t) {
  u8 loc40[0x40];
  u32 loc10[3] = {0, 0, 0x3fc90fdbu};
  u32 loc1c[3] = {0, 0, 0};
  u32 idx = D(t, 0x370);
  u8 *ed = (u8 *)D(t, 0x4c + 4 * idx);
  u8 *old = (u8 *)D(t, 0x1e0);
  if (old) {
    vcall<void>(old, 0x210, 1u);
    D(t, 0x1e0) = 0;
  }
  u32 w = vcall<u32>(ed, 0x2c4, D(t, 0x44), 0x4954454du);
  D(t, 0x1e0) = w;
  vcall<void>((void *)w, 0x358, 1u);
  ext_4de7a0(loc40);
  ext_4de7e0(loc40, loc10);
  vcall<void>((void *)w, 0x2d4, (u32)loc40, (u32)loc1c);
}
PCREG(46d5f0, weaponsCreate);
