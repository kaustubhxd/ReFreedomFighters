// batch6346.cpp - unclaimed-63 gap-band batch 46: 0x4dc1e0 (A+D+E set; no GC name), thiscall, one stack argument X, ret 4.
//   w = this->u16[+0x5c]. If w != 0: O1 = [[[0x70039c]+0x9b]+8]; r = O1->vtbl[+0x5c](w) (thiscall, callee pops 4); if r != 0 and w != 0:
//     c = O1->vtbl[+0x5c](w) again; n = byte [c+0x1c]; scan c[0..n-1] (dwords): if one equals X, then ob = O1->vtbl[+0x5c](w) and
//     0x4dc140 on ob with X (thiscall, one argument, callee pops 4); stop the scan.
//   Then X->vtbl[+0x36c](this) (thiscall, one argument, callee pops 4) and 0x4da770 on this with X (thiscall, one argument).
//   The callees 0x4dc140 and 0x4da770 are original code, stubbed by the spec. All calls pop their own argument (the function
//   ends with pops and ret 4, so the callees must).
#include "ff.h"

extern "C" void THISCALL ext_4dc140(void *self, u32 x);   // thiscall, one argument, original, stubbed by the spec
extern "C" void THISCALL ext_4da770(void *self, u32 x);   // thiscall, one argument, original, stubbed by the spec

typedef u32(THISCALL * q5c_fn)(void *, u32);
typedef void(THISCALL * one_fn)(void *, u32);

// 0x4dc1e0 (A+D+E set).
static void THISCALL unnamed4dc1e0(u8 *self, u32 x) {
  u16 w = *(u16 *)(self + 0x5c);
  u32 o1 = 0;
  if (w != 0) {
    u32 eng = G(u32, 0x70039c);
    u32 db = *(u32 *)(eng + 0x9b);
    o1 = *(u32 *)(db + 8);
    u32 r = ((q5c_fn)(*(u32 *)(*(u32 *)o1 + 0x5c)))((void *)o1, (u32)w);
    if (r != 0) {
      u32 c = ((q5c_fn)(*(u32 *)(*(u32 *)o1 + 0x5c)))((void *)o1, (u32)w);
      u32 n = *(u8 *)(c + 0x1c);
      for (u32 i = 0; i < n; i++) {
        if (*(u32 *)(c + 4 * i) == x) {
          u32 ob = ((q5c_fn)(*(u32 *)(*(u32 *)o1 + 0x5c)))((void *)o1, (u32)w);
          ext_4dc140((void *)ob, x);
          break;
        }
      }
    }
  }
  u32 vt = *(u32 *)x;
  ((one_fn)(*(u32 *)(vt + 0x36c)))((void *)x, (u32)self);
  ext_4da770((void *)self, x);
}
PCREG(4dc1e0, unnamed4dc1e0);
