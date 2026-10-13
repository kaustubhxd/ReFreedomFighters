// batch4005.cpp - area 70 (residue 9), batch 4005: two members that read through 0x5003d0 (exe, ret 4, one stack word).
#include "ff.h"

extern "C" u8 *THISCALL ext_5003d0(u8 *self, u32 idx);   // exe callee: one stack word (idx), ret 4, returns a pointer

// 0x5083d0 (name GUESS): thiscall, ret 4. r = 0x5003d0([a+4], 0); v = *(float *)r * 100.0f; then the object at
// this+0x18 gets its slot 0x5fc virtual called with v (one float argument, the callee pops it).
static void THISCALL readScaleCall(u8 *self, u8 *a) {
  u8 *r = ext_5003d0(*(u8 **)(a + 4), 0);
  float v = *(const float *)r * 100.0f;
  vcall<void>(*(u8 **)(self + 0x18), 0x5fc, v);
}
PCREG(5083d0, readScaleCall);

// 0x508290 (name GUESS): thiscall, ret 4. r = 0x5003d0([a+4], 0); the dword at r is stored at +0x678 of the object at
// this+0x18.
static void THISCALL readStoreDword(u8 *self, u8 *a) {
  u8 *r = ext_5003d0(*(u8 **)(a + 4), 0);
  *(u32 *)(*(u8 **)(self + 0x18) + 0x678) = *(const u32 *)r;
}
PCREG(508290, readStoreDword);
