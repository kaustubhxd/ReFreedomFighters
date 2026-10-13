// batch4142.cpp - unclaimed-41 batch 42 (core-todo residue-19): 0x46a4f0 ZItem::~ZItem() (thiscall, no arguments, plain ret).
// SEH frame not reproduced (the fs:[0] push, save and restore are not modelled; fs:[0] writes are not compared). The /GS cookie check is
// not reproduced.
#include "ff.h"

extern "C" void THISCALL ext_43ea20(u8 *self);      // member teardown, no arguments (stub, GUESS)

typedef u32(THISCALL * f1_t)(u8 *, u32);

static u32 vslot(u8 *o, u32 off) {
  return *(u32 *)(*(u8 **)o + off);
}

static void releaseOne(u8 *obj) {
  if (obj != 0)
    ((f1_t)vslot(obj, 0))(obj, 1u);      // vt[0] with one argument (callee pops)
}

static void THISCALL fn46a4f0(u8 *self) {
  *(u32 *)self = 0x686c08u;
  u8 *L = *(u8 **)(self + 0x6c);
  if (L != 0) {
    u32 l18 = 0;
    ((f1_t)vslot(L, 0x4c))(L, (u32)&l18);
    u32 X = ((f1_t)vslot(*(u8 **)(self + 0x6c), 0x64))(*(u8 **)(self + 0x6c), (u32)&l18);
    while (X != 0) {
      u8 *rm = G(u8 *, 0x70039c);
      u8 *o = *(u8 **)(rm + 0x9b);
      u8 *Y = (u8 *)((f1_t)vslot(o, 0x58))(o, *(u32 *)X);
      if (Y != 0)
        ((f1_t)vslot(Y, 0x210))(Y, 1u);
      u8 *L2 = *(u8 **)(self + 0x6c);
      X = ((f1_t)vslot(L2, 0x64))(L2, (u32)&l18);
    }
  }
  releaseOne(*(u8 **)(self + 0x70));
  releaseOne(*(u8 **)(self + 0x6c));
  releaseOne(*(u8 **)(self + 0x78));
  releaseOne(*(u8 **)(self + 0x74));
  ext_43ea20(self);
}
PCREG(46a4f0, fn46a4f0);
