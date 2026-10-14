// batch956.cpp - 0x519ab0 (no name in the map), read in full (2026-10-12). Thiscall (ECX = this), one arg (a), ret 4, void. The stack-cookie prologue
// and the check call 0x633654 are NOT reproduced (tagged, as in batch 930). Let o = [a+4]. Accessor 0x5003d0 (stood in) on ECX = o with indices
// 1, 2, 3, 0 gives q1, q2, q3, q0. L[0] = *q1, L[1] = *q2, L[2] = *q3 (floats). Then slot +0x32c of this+0x14 with two stack words: the float *q0
// and the pointer to L (the callee's ret is assumed 8).
#include "ff.h"

#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define FP(p, o) (*(void **)((u8 *)(p) + (o)))

extern "C" void *THISCALL ext_5003d0(void *self, u32 idx);   // stood in (one arg, returns a pointer)

// 0x519ab0 (no name in the map).
static void THISCALL Apply519ab0(u8 *self, u8 *a) {
  void *o = FP(a, 4);
  float L[3];
  L[0] = *(float *)ext_5003d0(o, 1u);
  L[1] = *(float *)ext_5003d0(o, 2u);
  L[2] = *(float *)ext_5003d0(o, 3u);
  float v0 = *(float *)ext_5003d0(o, 0u);
  vcall<void>(FP(self, 0x14), 0x32c, v0, (u32)(unsigned long)L);
}
PCREG(519ab0, Apply519ab0);
