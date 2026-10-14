// batch2905.cpp - unclaimed-29: batch 5 (docs/20-unclaimed-29.md, claim 5, slice 8). Thiscall, one stack argument (the load object).
// The stack argument slot is written by the load's slot +0x40 and read back by a later render-object call, so the port keeps
// it in a local that the load can write through.
#include "ff.h"

typedef u32(THISCALL *SlotFn1)(u8 *self, u32 a);

// call virtual slot `slot` of obj with one argument; returns eax
static u32 vcall1(u8 *obj, u32 slot, u32 arg) {
  const u32 vtbl = *(const u32 *)obj;
  return ((SlotFn1)(*(const u32 *)(vtbl + slot)))(obj, arg);
}

// 0x5b8180, CCheckInsideBox::Load(ZLoadGame*) (high): clears bit 0x40 of +4; load slot +0x40 with &+0x48 and &+0x4c; then
// load slot +0x40 with &tmp, where tmp starts as the load argument; the render object (global 0x70039c, +0x9b) slot +0x58
// with tmp gives the dword stored at +0x50; load slot +0x40 with &tmp again; the same slot +0x58 gives the dword at +0x54; load
// slot +0x40 with &+0x5c. Returns true.
static bool THISCALL checkInsideBoxLoad(u8 *self, u8 *load) {
  *(u32 *)(self + 4) &= 0xffffffbfu;
  vcall1(load, 0x40, (u32)(self + 0x48));
  vcall1(load, 0x40, (u32)(self + 0x4c));
  u32 tmp = (u32)load;
  vcall1(load, 0x40, (u32)&tmp);
  u8 *rm = G(u8 *, 0x70039c);
  u8 *obj = *(u8 **)(rm + 0x9b);
  *(u32 *)(self + 0x50) = vcall1(obj, 0x58, tmp);
  vcall1(load, 0x40, (u32)&tmp);
  obj = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  *(u32 *)(self + 0x54) = vcall1(obj, 0x58, tmp);
  vcall1(load, 0x40, (u32)(self + 0x5c));
  return true;
}
PCREG(5b8180, checkInsideBoxLoad);
