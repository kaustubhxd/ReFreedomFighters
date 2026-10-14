// batch939.cpp - unclaimed-09 batch 31: ZActorIf::RemoveFromMovingGroup(OpaqueCallParameters_t&) (core list; docs/20-unclaimed-09.md,
// claim 33). thiscall, one stack argument, ret 4. All calls are GUESS recording stubs in the spec (unverified callees).
#include "ff.h"

extern "C" u8 *THISCALL ext_5003d0(u8 *self, u32 k);
extern "C" void THISCALL ext_4dbe30(u8 *self, u32 a);
extern "C" void THISCALL ext_4dc440(u8 *self, u32 a);
extern "C" void THISCALL ext_5002f0(u8 *self, u32 v);

typedef u8 *(THISCALL *Obj0)(u8 *self);
typedef u8 *(THISCALL *GetB)(u8 *self, u32 a);
typedef u32(THISCALL *M4c)(u8 *self, u32 a);
typedef void(THISCALL *V3)(u8 *self, u32 a, u32 b, u32 c);
typedef void(THISCALL *V1)(u8 *self, u32 a);
typedef void(THISCALL *V2)(u8 *self, u8 *a, u8 *b);

static u32 slot(u8 *obj, u32 off) {
  return *(u32 *)(*(u32 *)obj + off);
}

static u8 *engine() {
  return *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
}

// 0x507b40, ZActorIf::RemoveFromMovingGroup(OpaqueCallParameters_t&) (list name): see docs/20-unclaimed-09.md claim 33.
static void THISCALL removeFromMovingGroup(u8 *self, u8 *p) {
  // Order as in the original: three keyed lookups (k = 0, 1, 2), then the calls on this.+0x18 and the results.
  u8 *e0 = ext_5003d0(*(u8 **)(p + 4), 0);
  u32 a0 = *(u32 *)e0;
  u8 *m = engine();
  u8 *b = ((GetB)slot(m, 0x58))(m, a0);
  u8 *e1 = ext_5003d0(*(u8 **)(p + 4), 1);
  u32 a1 = *(u32 *)e1;
  m = engine();
  u8 *c = ((GetB)slot(m, 0x58))(m, a1);
  u8 *e2 = ext_5003d0(*(u8 **)(p + 4), 2);
  u32 flag = *(u32 *)e2;
  u8 *x = *(u8 **)(self + 0x18);
  u8 *y = ((Obj0)slot(x, 0x20))(x);
  u8 *z = ((Obj0)slot(y, 0x20))(y);
  ((V3)slot(b, 0x288))(b, (u32)y, 0, 1);
  ext_4dbe30(*(u8 **)(y + 8), 1);
  ext_4dc440(*(u8 **)(y + 8), 1);
  if (flag) *(u8 *)(*(u8 **)(self + 0x18) + 0x6fe) = 1;
  x = *(u8 **)(self + 0x18);
  ((V1)slot(x, 0x654))(x, 1);
  u8 l10[12];
  u8 l34[12];
  ((V2)slot(c, 0x80))(c, l34, l10);
  x = *(u8 **)(self + 0x18);
  ((V2)slot(x, 0x370))(x, l34, l10);
  m = engine();
  u32 v = ((M4c)slot(m, 0x4c))(m, (u32)z);
  u8 *q = ext_5003d0(*(u8 **)(p + 8), 0);
  ext_5002f0(q, v);  // the caller's leftover push (v) is this callee's one argument (ret 4)
}
PCREG(507b40, removeFromMovingGroup);
