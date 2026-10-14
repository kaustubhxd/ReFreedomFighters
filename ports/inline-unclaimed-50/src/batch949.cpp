// batch949.cpp - 0x51b120 (no name in the map), read in full (2026-10-12). Thiscall (ECX = this), one arg (a pointer p), ret 4, void.
// The object is o = [p+4]. Three calls to 0x5003d0 (thiscall, ECX = o, one arg; stood in): with 2 gives ebx, with 1 gives esi, with 0 gives eax.
// Then the object at this+0x1c: slot +0x38c with three stack words: float *eax, float *esi, dword *ebx (the callee pops 12; ret 0xc assumed).
#include "ff.h"

#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define FP(p, o) (*(void **)((u8 *)(p) + (o)))

extern "C" void *THISCALL ext_5003d0(void *self, u32 idx);   // stood in (one arg, returns a pointer)

// 0x51b120 (no name in the map).
static void THISCALL Apply51b120(u8 *self, u8 *p) {
  void *o = (void *)U32(p, 4);
  void *pb = ext_5003d0(o, 2u);
  void *ps = ext_5003d0(o, 1u);
  void *pa = ext_5003d0(o, 0u);
  u32 dw = *(u32 *)pb;
  float ys = *(float *)ps;
  float xa = *(float *)pa;
  vcall<void>(FP(self, 0x1c), 0x38c, xa, ys, dw);
}
PCREG(51b120, Apply51b120);
