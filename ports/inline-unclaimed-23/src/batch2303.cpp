// batch2303.cpp - unclaimed-23 batch 3 (docs/20-unclaimed-23.md): ZActorIf::SetVisRangeSpeed(OpaqueCallParameters_t&) at
// 0x5084a0. Name from the GC name map (high). Calls: o = [[0x70039c]+0x9b]: o->vtbl[+0x4c](A) with A = this+0x18 (value
// to local8); 0x5003d0 (original, thiscall, one argument 0) on [params+4], then a float read through its result (dead: the
// PC stores it in a local that is never read); o->vtbl[+0x114](0x690484, 0, 0x69cff0, 0x121, &local8) returns r (16 bits used);
// o->vtbl[+0x58]([A+0x73a], zero-extended r) returns r2; A->vtbl[+0x130](r2). Callee pops as the PC implies; ret 4.
#include "ff.h"

extern "C" u32 THISCALL ext_5003d0(void *self, u32 a);   // original code, stubbed by the spec

typedef u32(THISCALL * call1_fn)(void *, u32);
typedef u32(THISCALL * call5_fn)(void *, u32, u32, u32, u32, u32 *);
typedef u32(THISCALL * call2_fn)(void *, u32, u32);
typedef void(THISCALL * call1v_fn)(void *, u32);

// 0x5084a0 (high). The float read through the 0x5003d0 result is kept (a load can fault), but its value is not used.
static void THISCALL actorIfSetVisRangeSpeed(u8 *self, u32 params) {
  u32 rm = G(u32, 0x70039c);
  void *o = (void *)*(u32 *)(rm + 0x9b);
  u32 a = *(u32 *)(self + 0x18);
  u32 local8 = ((call1_fn)(*(u32 *)(*(u32 *)o + 0x4c)))(o, a);
  void *p = (void *)*(u32 *)(params + 4);
  u32 f = *(u32 *)ext_5003d0(p, 0);
  (void)f;
  (void)local8;
  u32 r = ((call5_fn)(*(u32 *)(*(u32 *)o + 0x114)))(o, 0x690484, 0, 0x69cff0, 0x121, &local8);
  u32 r16 = (u16)r;
  u32 r2 = ((call2_fn)(*(u32 *)(*(u32 *)o + 0x58)))(o, *(u32 *)(a + 0x73a), r16);
  ((call1v_fn)(*(u32 *)(*(u32 *)a + 0x130)))((void *)a, r2);
}
PCREG(5084a0, actorIfSetVisRangeSpeed);
