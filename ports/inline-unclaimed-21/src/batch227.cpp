// batch227.cpp - small leaves, slices 0/1. Names GUESS. Callees stubbed in the harness; 0x5003d0 and 0x5002f0 are both
// ret 4 with one stack word (the value pushed by the caller, consumed by the callee); see docs/20-unclaimed-21.md.
#include "ff.h"

extern "C" u32 THISCALL ext_513090(u8 *self);                 // original, thiscall, no stack words (stubbed; returns eax)
extern "C" u8 *THISCALL ext_5003d0(u8 *self, u32 zero);       // original, thiscall, one stack word, ret 4 (stubbed)
extern "C" void THISCALL ext_5002f0(u8 *self, u32 word);      // original, thiscall, one stack word, ret 4 (stubbed)
extern "C" void THISCALL ext_5a2cb0(u8 *self, u32 w1, u32 w2);   // original, thiscall, two stack words, ret 8 (stubbed)

static u32 vslot10(u8 *obj, u32 off) { return *(u32 *)(*(u32 *)obj + off); }

// 0x519640, thiscall(a) (ret 4): w = 0x513090(this->[0x14]); r = 0x5003d0(a->[8], 0); 0x5002f0(r, w).
static void THISCALL resultStore_519640(u8 *self, u8 *a) {
  u32 w = ext_513090(*(u8 **)(self + 0x14));
  u8 *r = ext_5003d0(*(u8 **)(a + 8), 0);
  ext_5002f0(r, w);
}
PCREG(519640, resultStore_519640);

// 0x506b80, thiscall(a) (ret 4): w = this->[0x18]->vt[0x680](); r = 0x5003d0(a->[8], 0); 0x5002f0(r, w).
static void THISCALL vslotStore_506b80(u8 *self, u8 *a) {
  u8 *e = *(u8 **)(self + 0x18);
  u32 w = ((u32(THISCALL *)(u8 *))vslot10(e, 0x680))(e);
  u8 *r = ext_5003d0(*(u8 **)(a + 8), 0);
  ext_5002f0(r, w);
}
PCREG(506b80, vslotStore_506b80);

// 0x55c800, thiscall(a) (ret 4): p1 = 0x5003d0(a->[4], 0); v = *p1; p2 = 0x5003d0(a->[4], 1);
// 0x5a2cb0(this->[0x1c], v, *p2) (ret 8).
static void THISCALL pairCall_55c800(u8 *self, u8 *a) {
  u8 *p1 = ext_5003d0(*(u8 **)(a + 4), 0);
  u32 v = *(u32 *)p1;
  u8 *p2 = ext_5003d0(*(u8 **)(a + 4), 1);
  ext_5a2cb0(*(u8 **)(self + 0x1c), v, *(u32 *)p2);
}
PCREG(55c800, pairCall_55c800);
