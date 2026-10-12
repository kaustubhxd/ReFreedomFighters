// batch238.cpp - small leaves, slice 0/1. 0x501550 (name GUESS): thiscall(a) (ret 4). V = {f(r0), f(r1), f(r2)} where r_k =
// 0x5003d0(a->[4], k) (k = 2, 1, 0 in that push order; the floats are read in the order 0, 1, 2); O = [this+0xc]:
// O->vt[0x8c](&V); then for k = 0, 1, 2: p = 0x5003d0(a->[8], k); p[4] = 2; *(float *)p = V[k] (read after the call).
// The exe's error branch (a block byte other than 0 or 2) is not taken: the spec keeps those bytes at 0 or 2.
#include "ff.h"

extern "C" u8 *THISCALL ext_5003d0(u8 *self, u32 zero);   // one stack word, ret 4 (stubbed)

typedef void(THISCALL *SlotPtr)(u8 *, float *);

static u32 vslot18(u8 *obj, u32 off) { return *(u32 *)(*(u32 *)obj + off); }

static void THISCALL vecStore_501550(u8 *self, u8 *a) {
  u8 *r2 = ext_5003d0(*(u8 **)(a + 4), 2);
  u8 *r1 = ext_5003d0(*(u8 **)(a + 4), 1);
  u8 *r0 = ext_5003d0(*(u8 **)(a + 4), 0);
  float V[3];
  V[0] = *(float *)r0;
  V[1] = *(float *)r1;
  V[2] = *(float *)r2;
  u8 *O = *(u8 **)(self + 0xc);
  ((SlotPtr)vslot18(O, 0x8c))(O, V);
  for (u32 k = 0; k < 3; ++k) {
    u8 *p = ext_5003d0(*(u8 **)(a + 8), k);
    p[4] = 2;
    *(float *)p = V[k];
  }
}
PCREG(501550, vecStore_501550);
