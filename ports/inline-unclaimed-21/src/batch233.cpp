// batch233.cpp - small leaves, slice 0/1. 0x557d00 (name GUESS): thiscall(a) (ret 4). Four lookups 0x5003d0(a->[4], k) for
// k = 0..3 (ret 4, one word each): b = [r0], d = [r1], s = [r2], q = [r3]; w = 0x59db50(this->[0x1c], b, d, s, q) (stubbed,
// ret 0x10); r = 0x5003d0(a->[8], 0); 0x5002f0(r, w) (ret 4, stores w into [r], [r+4] = 1). Returns void.
#include "ff.h"

extern "C" u8 *THISCALL ext_5003d0(u8 *self, u32 zero);                        // one stack word, ret 4 (stubbed)
extern "C" u32 THISCALL ext_59db50(u8 *self, u32 p1, u32 p2, u32 p3, u32 p4);  // four stack words, ret 0x10 (stubbed)
extern "C" void THISCALL ext_5002f0(u8 *self, u32 word);                       // one stack word, ret 4 (stubbed)

// 0x557d00, thiscall(a) (ret 4).
static void THISCALL lookupCall_557d00(u8 *self, u8 *a) {
  u32 b = *(u32 *)ext_5003d0(*(u8 **)(a + 4), 0);
  u32 d = *(u32 *)ext_5003d0(*(u8 **)(a + 4), 1);
  u32 s = *(u32 *)ext_5003d0(*(u8 **)(a + 4), 2);
  u32 q = *(u32 *)ext_5003d0(*(u8 **)(a + 4), 3);
  u32 w = ext_59db50(*(u8 **)(self + 0x1c), b, d, s, q);
  u8 *r = ext_5003d0(*(u8 **)(a + 8), 0);
  ext_5002f0(r, w);
}
PCREG(557d00, lookupCall_557d00);
