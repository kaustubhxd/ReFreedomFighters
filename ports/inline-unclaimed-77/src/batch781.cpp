// batch781.cpp - unclaimed-77 claim 11 (docs/20-unclaimed-77.md): CEntityTracker::UpdateEntity(ZEntityInfo*) (medium). Thiscall, one
// argument, ret 4. The virtual slots 0x57c and 0x80 are stubbed in the harness (GUESS). The CRT security-cookie check at the end
// (0x633654) is NOT reproduced: it checks a cookie this function never changes.
#include "ff.h"

// 0x5c0900, CEntityTracker::UpdateEntity(ZEntityInfo*) (medium).
static void THISCALL entityTrackerUpdateEntity(u8 *self, u8 *info) {
  u8 *O = *(u8 **)info;
  u8 *D = *(u8 **)(O + 0x54);
  u32 slot = (*(u32 *)(D + 8) == 4) ? 0x80u : 0x57cu;
  void **vt = *(void ***)O;
  u32 outbuf[4] = {0, 0, 0, 0};   // the exe passes a stack local here; the callee's output is not used afterwards
  ((void (THISCALL *)(void *, u32 *, u8 *))(*(void **)((u8 *)vt + slot)))(O, outbuf, info + 4);

  u32 *A = *(u32 **)(self + 0x4c);
  u8 *B = *(u8 **)(self + 0x50);
  u32 m = *(u32 *)(self + 0x54);

  // loop 1: while the count word of info is nonzero
  if (*(u16 *)(info + 0x15) != 0) {
    for (;;) {
      u32 cnt = *(u16 *)(info + 0x15);
      float x = *(float *)(info + 4);
      u8 *r1 = B + A[cnt - 1] * 0x17u;
      if (x > *(float *)(r1 + 4)) {
        break;
      }
      u32 edx = A[cnt];
      u32 w = *(u16 *)(r1 + 0x15);
      A[cnt] = A[w];
      A[w] = edx;
      *(u16 *)(info + 0x15) = (u16)(*(u16 *)(info + 0x15) - 1);
      *(u16 *)(r1 + 0x15) = (u16)(*(u16 *)(r1 + 0x15) + 1);
      if (*(u16 *)(info + 0x15) == 0) {
        break;
      }
    }
  }

  // loop 2: while the count word of info is below m - 1
  u32 lim = m - 1;
  if (*(u16 *)(info + 0x15) < lim) {
    for (;;) {
      u32 cnt = *(u16 *)(info + 0x15);
      u8 *r2 = B + A[cnt + 1] * 0x17u;
      float x = *(float *)(info + 4);
      if (*(float *)(r2 + 4) > x) {
        break;
      }
      u32 edx = A[cnt];
      u32 w = *(u16 *)(r2 + 0x15);
      A[cnt] = A[w];
      A[w] = edx;
      *(u16 *)(info + 0x15) = (u16)(*(u16 *)(info + 0x15) + 1);
      *(u16 *)(r2 + 0x15) = (u16)(*(u16 *)(r2 + 0x15) - 1);
      if (!(*(u16 *)(info + 0x15) < lim)) {
        break;
      }
    }
  }
  // (the CRT security-cookie check at 0x633654 is not reproduced)
}
PCREG(5c0900, entityTrackerUpdateEntity);
