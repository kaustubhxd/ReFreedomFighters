// batch931.cpp - unclaimed-09 batch 23: ZStartAnim::Init() (core-todo residue-10; docs/20-unclaimed-09.md, claim 25).
// thiscall, no arguments, plain ret. Every virtual call is an unverified callee, stubbed in the spec.
#include "ff.h"

typedef u8 *(THISCALL *GetWithArg)(u8 *self, u32 a);   // global+0x9b .vt[0x58](h)
typedef u8 *(THISCALL *GetNoArg)(u8 *self);            // this+0x44 .vt[0x20]()
typedef u32(THISCALL *Pair)(u8 *self, u32 *a, u32 *b); // vt+0x80 (x) and vt+0x7c (z); a = &l34, b = &l10
typedef void(THISCALL *Load22c)(u8 *self, u8 *a, u32 b);  // vt+0x22c (this+0x44)
typedef u32(THISCALL *NoArg)(u8 *self);                // this vt+0x58

static u32 slot(u8 *obj, u32 off) {
  return *(u32 *)(*(u32 *)obj + off);
}

// 0x485b30, ZStartAnim::Init() (list name): when this+0x48 is set and the global's object returns a non-null x, x.vt[0x80]
// fills two locals, and z = this+0x44.vt[0x20]() gets them through vt[0x7c]; then this+0x44.vt[0x22c](this+0x4c, 5);
// then this.vt[0x58]().
static void THISCALL startAnimInit(u8 *self) {
  u32 l10 = 0, l34 = 0;
  u32 h = *(u32 *)(self + 0x48);
  if (h) {
    u8 *m = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
    u8 *x = ((GetWithArg)slot(m, 0x58))(m, h);
    if (x) {
      ((Pair)slot(x, 0x80))(x, &l34, &l10);
      u8 *y = *(u8 **)(self + 0x44);
      u8 *z = ((GetNoArg)slot(y, 0x20))(y);
      ((Pair)slot(z, 0x7c))(z, &l34, &l10);
    }
  }
  u8 *y2 = *(u8 **)(self + 0x44);
  ((Load22c)slot(y2, 0x22c))(y2, self + 0x4c, 5);
  ((NoArg)slot(self, 0x58))(self);
}
PCREG(485b30, startAnimInit);
