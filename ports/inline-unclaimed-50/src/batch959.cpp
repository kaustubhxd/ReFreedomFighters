// batch959.cpp - 0x519bf0 (no name in the map), read in full (2026-10-12). Thiscall (ECX = this), one arg (a), ret 4, void.
// Let o = [a+4]. Accessor 0x5003d0 (stood in) on ECX = o with indices 3, 2, 1, 0 gives p3, p2, p1, p0.
// Then slot +0x2cc of this+0x14 with four floats on the stack, in order (first to last) *p0, *p1, *p2, *p3
// (the callee's ret is assumed 0x10).
#include "ff.h"

#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define FP(p, o) (*(void **)((u8 *)(p) + (o)))

extern "C" void *THISCALL ext_5003d0(void *self, u32 idx);   // stood in (one arg, returns a pointer)

// 0x519bf0 (no name in the map).
static void THISCALL Apply519bf0(u8 *self, u8 *a) {
  void *o = FP(a, 4);
  void *p3 = ext_5003d0(o, 3u);
  void *p2 = ext_5003d0(o, 2u);
  void *p1 = ext_5003d0(o, 1u);
  void *p0 = ext_5003d0(o, 0u);
  float f0 = *(float *)p0;
  float f1 = *(float *)p1;
  float f2 = *(float *)p2;
  float f3 = *(float *)p3;
  vcall<void>(FP(self, 0x14), 0x2cc, f0, f1, f2, f3);
}
PCREG(519bf0, Apply519bf0);
