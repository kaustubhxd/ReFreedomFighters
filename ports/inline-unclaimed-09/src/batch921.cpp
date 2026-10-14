// batch921.cpp - unclaimed-09 batch 13: ZMoveToPlayer::Init2() (docs/20-unclaimed-09.md, claim 13).
// thiscall, no arguments, plain ret. Every virtual call is an unverified callee, stubbed in the spec. The original's
// stack cookie check is compiler boilerplate and is not reproduced.
#include "ff.h"

typedef u8 *(THISCALL *ObjCall)(u8 *self);                    // vt+0x138 (A), vt+0x20 (X)
typedef u8 *(THISCALL *ObjCallArg)(u8 *self, u32 a);          // vt+0x58 (A, takes the out value)
typedef void(THISCALL *Call88)(u8 *self, u32 a, u32 *out);    // vt+0x88 (r1)
typedef u8(THISCALL *Pred1e0)(u8 *self, u32 a);               // vt+0x1e0 (C), returns al
typedef void(THISCALL *Call2Ptr)(u8 *self, u32 *a, u32 *b);   // vt+0x80 (D), vt+0x94 (E)
typedef void(THISCALL *Call3)(u8 *self, u32 a, u32 b, u32 c); // vt+0x28c (F)
typedef void(THISCALL *Call0)(u8 *self);                      // vt+0x58 (this)

static u32 slot(u8 *obj, u32 off) {
  return *(u32 *)(*(u32 *)obj + off);
}

// 0x4bbac0, ZMoveToPlayer::Init2() (high): see docs/20-unclaimed-09.md claim 13 for the call sequence.
static void THISCALL moveToPlayerInit2(u8 *self) {
  u8 *a = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  u8 *r1 = ((ObjCall)slot(a, 0x138))(a);
  u32 out = 0;
  ((Call88)slot(r1, 0x88))(r1, 0x681320, &out);
  u8 *b = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  u8 *x = ((ObjCallArg)slot(b, 0x58))(b, out);
  if (x) {
    u8 *c = ((ObjCall)slot(x, 0x20))(x);
    if (((Pred1e0)slot(c, 0x1e0))(c, 0x100001)) {
      u8 *d = *(u8 **)(self + 0x44);
      u32 l34 = 0, l10 = 0;
      ((Call2Ptr)slot(d, 0x80))(d, &l34, &l10);
      u8 *e = ((ObjCall)slot(x, 0x20))(x);
      ((Call2Ptr)slot(e, 0x94))(e, &l34, &l10);
      u8 *f = ((ObjCall)slot(x, 0x20))(x);
      ((Call3)slot(f, 0x28c))(f, *(u32 *)(d + 8), 0, 1);
    }
  }
  ((Call0)slot(self, 0x58))(self);
}
PCREG(4bbac0, moveToPlayerInit2);
