// batch957.cpp - 0x5197e0 (no name in the map), read in full (2026-10-12). Thiscall (ECX = this), one arg (a), ret 4, void.
// Let o = [a+4]. Accessor 0x5003d0 (stood in) on ECX = o. If the dword at acc(0) is 0, return. Else p1 = acc(1), p0 = acc(0);
// r = slot +0x2fc of this+0x14 with (dword *p0, float *p1), returning a float in st0 (callee ret 8 assumed). Then p2 = acc(2);
// slot +0x2f8 of this+0x14 (re-read) with (r, *p2 != 0) (callee ret 8 assumed).
#include "ff.h"

#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define FP(p, o) (*(void **)((u8 *)(p) + (o)))

extern "C" void *THISCALL ext_5003d0(void *self, u32 idx);   // stood in (one arg, returns a pointer)

// 0x5197e0 (no name in the map).
static void THISCALL Apply5197e0(u8 *self, u8 *a) {
  if (U32(ext_5003d0(FP(a, 4), 0u), 0) == 0) return;
  float *p1 = (float *)ext_5003d0(FP(a, 4), 1u);
  u32 d0 = U32(ext_5003d0(FP(a, 4), 0u), 0);
  float r = vcall<float>(FP(self, 0x14), 0x2fc, d0, *p1);
  u32 f = U32(ext_5003d0(FP(a, 4), 2u), 0) != 0;
  vcall<void>(FP(self, 0x14), 0x2f8, r, f);
}
PCREG(5197e0, Apply5197e0);
