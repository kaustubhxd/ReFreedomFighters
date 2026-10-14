// batch2903.cpp - unclaimed-29: batch 3 (docs/20-unclaimed-29.md, claim 3, slice 8). Thiscall, one stack argument (the load object).
// Every call here is a virtual call on the load object or on an object it returns.
#include "ff.h"

typedef u32(THISCALL *LoadVirtFn)(u8 *self, u32 a);

// call virtual slot `slot` of obj with one stack argument
static u32 vcall1(u8 *obj, u32 slot, u32 arg) {
  const u32 vtbl = *(const u32 *)obj;
  return ((LoadVirtFn)(*(const u32 *)(vtbl + slot)))(obj, arg);
}

// 0x4c3680, ZWindControl::Load(ZLoadGame*) (high): clears bit 0x40 of the dword at +4; load slot +0x70 with the dword at +0x48;
// then the load's slot +0x50 with &+0x4c gives an object X, whose slot +0x50 gets &+0x50; the load's slot +0x50 with &+0x54
// gives an object Y, whose slot +0x50 gets &+0x5c. Returns true.
static bool THISCALL windControlLoad(u8 *self, u8 *load) {
  *(u32 *)(self + 4) &= 0xffffffbfu;
  vcall1(load, 0x70, *(const u32 *)(self + 0x48));
  u8 *x = (u8 *)vcall1(load, 0x50, (u32)(self + 0x4c));
  vcall1(x, 0x50, (u32)(self + 0x50));
  u8 *y = (u8 *)vcall1(load, 0x50, (u32)(self + 0x54));
  vcall1(y, 0x50, (u32)(self + 0x5c));
  return true;
}
PCREG(4c3680, windControlLoad);
