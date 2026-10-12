// batch6352.cpp - unclaimed-63 gap-band batch 52: 0x4d9430 (A+D+E set; SEH frame not reproduced), thiscall, no stack arguments, plain ret.
//   The original installs an fs:[0] frame (handler 0x6692b0); the port keeps only the body.
//   If this[+0x68] != 0 and [[[0x70039c]+0x9b]+0x5d35] = obj != 0: obj->vtbl[+0x10](this).
//   0x4dc630(this, 0, 0x8000) (arguments in push order: 0x8000 then 0) (thiscall, two stack arguments; other area's code, stubbed). If [0x70039c][+0x190f] = obj2 != 0:
//   obj2->vtbl[+0x188](this). L = this[+0x54]. edi = 0x200002.
//   If L != 0: edi = [[L+0xc] + 0x23]; if this[+0x3c] >= 0 (signed): 0x4dc630(this, 0, 0x80000000); if this[+0x54] != 0:
//     this[+0x54]->vtbl[+0x210](1).
//   Else (L == 0): if this[+0x3c] & 0x40000: if this[+0x64] != 0 and (this[+0x3c] & 0xff) != 0: r = 0x4daff0(this[+0x50][+0x54][+8]);
//     if r != 0: r->vtbl[+0x320](this); this[+0x64] = 0. Then 0x4dae60(this) (thiscall, no arguments).
//   Tail (only when L == 0): if this[+0x50] != 0 and its [+0x54] = c2 != 0: c2->vtbl[+0x290](this, 1) (thiscall, two arguments).
//   When L != 0 the original jumps past the tail, in both sign cases.
//   If this[+0x3c] & 0x40000: 0x4dae60(this). this[+0x54] = 0. [[[0x70039c]+0x9b]+8]->vtbl[+0x24](edi) (thiscall, one argument).
//   0x4dc630(this, 0, 0x4000000).
#include "ff.h"

extern "C" void THISCALL ext_4dc630(void *self, u32 a, u32 b);   // thiscall, two stack arguments, other area's code, stubbed
extern "C" u32 THISCALL ext_4daff0(void *self);                  // thiscall, no arguments, returns an object, stubbed
extern "C" void THISCALL ext_4dae60(void *self);                 // thiscall, no arguments, stubbed

typedef void(THISCALL * a1_fn)(void *, u32);
typedef void(THISCALL * a2_fn)(void *, u32, u32);

// 0x4d9430 (A+D+E set).
static void THISCALL unnamed4d9430(u8 *self) {
  if (*(u32 *)(self + 0x68) != 0) {
    u32 eng = G(u32, 0x70039c);
    u32 db = *(u32 *)(eng + 0x9b);
    u32 obj = *(u32 *)(db + 0x5d35);
    if (obj != 0)
      ((a1_fn)(*(u32 *)(*(u32 *)obj + 0x10)))((void *)obj, (u32)self);
  }
  ext_4dc630((void *)self, 0u, 0x8000u);
  u32 eng2 = G(u32, 0x70039c);
  u32 obj2 = *(u32 *)(eng2 + 0x190f);
  if (obj2 != 0)
    ((a1_fn)(*(u32 *)(*(u32 *)obj2 + 0x188)))((void *)obj2, (u32)self);
  u32 L = *(u32 *)(self + 0x54);
  u32 edi = 0x200002u;
  if (L != 0) {
    edi = *(u32 *)(*(u32 *)(L + 0xc) + 0x23);
    if ((int)*(u32 *)(self + 0x3c) >= 0) {
      ext_4dc630((void *)self, 0x80000000u, 0u);
      u32 L2 = *(u32 *)(self + 0x54);
      if (L2 != 0)
        ((a1_fn)(*(u32 *)(*(u32 *)L2 + 0x210)))((void *)L2, 1u);
    }
  } else {
    if (*(u32 *)(self + 0x3c) & 0x40000u) {
      if (*(u32 *)(self + 0x64) != 0 && (*(u32 *)(self + 0x3c) & 0xffu) != 0) {
        u32 p = *(u32 *)(self + 0x50);
        u32 c = *(u32 *)(p + 0x54);
        u32 r = ext_4daff0((void *)*(u32 *)(c + 8));
        if (r != 0) {
          ((a1_fn)(*(u32 *)(*(u32 *)r + 0x320)))((void *)r, (u32)self);
          *(u32 *)(self + 0x64) = 0;
        }
      }
      ext_4dae60((void *)self);
    }
    u32 p2 = *(u32 *)(self + 0x50);
    if (p2 != 0) {
      u32 c2 = *(u32 *)(p2 + 0x54);
      if (c2 != 0)
        ((a2_fn)(*(u32 *)(*(u32 *)c2 + 0x290)))((void *)c2, (u32)self, 1u);
    }
  }
  if (*(u32 *)(self + 0x3c) & 0x40000u)
    ext_4dae60((void *)self);
  *(u32 *)(self + 0x54) = 0;
  u32 eng3 = G(u32, 0x70039c);
  u32 db3 = *(u32 *)(eng3 + 0x9b);
  u32 o1 = *(u32 *)(db3 + 8);
  ((a1_fn)(*(u32 *)(*(u32 *)o1 + 0x24)))((void *)o1, edi);
  ext_4dc630((void *)self, 0x4000000u, 0u);
}
PCREG(4d9430, unnamed4d9430);
