// batch1027.cpp - unclaimed-04 batch 28 (docs/20-unclaimed-04.md): two slice-3 functions (GUESS labels).
#include "ff.h"

typedef void(THISCALL *vt148_t)(void *self, u32 dst, u32 src);

// 0x403ab0: cdecl. A[i] = B[i] when B[i] < A[i] (x87 fcomp sets C0 for less-than and for unordered, so NaN copies too).
static void __attribute__((cdecl)) unk403ab0MinCopy(float *a, float *b) {
  for (u32 i = 0; i < 0x38; i++) {
    float bv = b[i];
    if (!(bv >= a[i])) a[i] = bv;
  }
}
PCREG(403ab0, unk403ab0MinCopy);

// 0x6565b0: thiscall, two stack arguments (dst, src). Vtable slot 0x148 with (dst, src), then three dwords copied.
static void THISCALL unk6565b0VtCopy(u8 *self, u8 *dst, u8 *src) {
  ((vt148_t)(*(u32 *)(*(u32 *)self + 0x148)))(self, (u32)dst, (u32)src);
  *(u32 *)(dst + 0x18) = *(u32 *)(src + 0x18);
  *(u32 *)(dst + 0x1c) = *(u32 *)(src + 0x1c);
  *(u32 *)(dst + 0x20) = *(u32 *)(src + 0x20);
}
PCREG(6565b0, unk6565b0VtCopy);
