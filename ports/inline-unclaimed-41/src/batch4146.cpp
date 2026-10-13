// batch4146.cpp - unclaimed-41 batch 46 (core-todo residue-19): 0x59efb0 ZFFActor::CreateItemFromItemTemplate(unsigned int) (thiscall, one
// stack argument id, ret 4; returns eax). C = this.vt[0x6c8](id); if C is null, return it. Else I = C.vt[0x2c4](render-manager object's
// +0xadc, "MEDI"); V = rm.o.vt[0x4c](this, +0xadc, 1); I.vt[0x2f0](V); if I.vt[0x1e0](0x1007d2): r = I.vt[0x328]() (and if r is non-null,
// w = I.vt[0x328]().vt[0x31c](), I.vt[0x360](w)), then I.vt[0x358](1). Returns I.
#include "ff.h"

typedef u32(THISCALL * f0_t)(u8 *);
typedef u32(THISCALL * f1_t)(u8 *, u32);
typedef u32(THISCALL * f2_t)(u8 *, u32, u32);
typedef u32(THISCALL * f3_t)(u8 *, u32, u32, u32);

static u32 vslot(u8 *o, u32 off) {
  return *(u32 *)(*(u8 **)o + off);
}

static u8 *THISCALL fn59efb0(u8 *self, u32 id) {
  u8 *C = (u8 *)((f1_t)vslot(self, 0x6c8))(self, id);
  if (C == 0)
    return C;
  u8 *rm = G(u8 *, 0x70039c);
  u8 *o = *(u8 **)(rm + 0x9b);
  u8 *I = (u8 *)((f2_t)vslot(C, 0x2c4))(C, *(u32 *)(o + 0xadc), 0x4954454du);
  u8 *ob = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  u32 V = ((f3_t)vslot(ob, 0x4c))(ob, (u32)self, *(u32 *)(ob + 0xadc), 1u);
  ((f1_t)vslot(I, 0x2f0))(I, V);
  if ((((f1_t)vslot(I, 0x1e0))(I, 0x1007d2u) & 0xff) != 0) {
    u32 r = ((f0_t)vslot(I, 0x328))(I);
    if (r != 0) {
      u8 *x = (u8 *)((f0_t)vslot(I, 0x328))(I);
      u32 w = ((f0_t)vslot(x, 0x31c))(x);
      ((f1_t)vslot(I, 0x360))(I, w);
    }
    ((f1_t)vslot(I, 0x358))(I, 1u);
  }
  return I;
}
PCREG(59efb0, fn59efb0);
