// batch2498.cpp - decomp area 24, batch 2498 (residue 3, smallest first).
#include "ff.h"

// 0x4ce7b0 (GUESS name, bitset free-slot search). Array at +4 (dwords), mask m at +8, index at +0xc, counter at +0x10. Each pass: take the
// index i; the new index is (arr[i] & (m-1)), or -1 when that equals i; arr[i] = ((arr[i] + m) & -m) | i. The pass repeats while
// (arr[i] & -m) is zero. The counter is incremented and the result is arr[i] & (m-1). Thiscall, plain ret.
static u32 THISCALL bitsetFindFree(u8 *self) {
  u32 *arr = *(u32 **)(self + 4);
  u32 m = *(u32 *)(self + 8);
  u32 negm = 0u - m;
  u32 i;
  do {
    i = *(u32 *)(self + 0xc);
    u32 a = (m - 1) & arr[i];
    if (a == i)
      a = 0xffffffffu;
    *(u32 *)(self + 0xc) = a;
    arr[i] = ((arr[i] + m) & negm) | i;
    arr = *(u32 **)(self + 4);
    m = *(u32 *)(self + 8);
    negm = 0u - m;
  } while ((arr[i] & negm) == 0);
  (*(u32 *)(self + 0x10))++;
  return arr[i] & (m - 1);
}
PCREG(4ce7b0, bitsetFindFree);
