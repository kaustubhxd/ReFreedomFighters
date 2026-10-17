// batch848.cpp - gap band entry-table reset (docs/20-unclaimed-gap-621.md). Names are GUESS.
#include "ff.h"

extern "C" void __attribute__((cdecl)) ext_634273(u8 *p, u32 n);   // hooked (GUESS): delete-like
extern "C" u8 *__attribute__((cdecl)) ext_41e290(u32 n);           // hooked (GUESS): new
typedef u32 (THISCALL *vcount_t)(u8 *self);

// 0x639c50: thiscall(n) ret 4 - releases the table of 0x14-byte entries at this[0x14] (entries with a nonzero flag byte at +0xc free their
// pointer at +0x10; the count comes from vt[0x34]() and is re-read each step), then reallocates it for n entries (size saturating at
// 0xffffffff) and clears byte +0xc and dwords +0x10 and +0 of each entry while n is positive (signed)
static void THISCALL resetTable_639c50(u8 *self, u32 n) {
  u32 i = 0;
  if ((*(vcount_t *)(*(u8 **)self + 0x34))(self) != 0) {
    do {
      u8 *arr = *(u8 **)(self + 0x14);
      if (arr[i * 0x14 + 0xc] != 0) ext_634273(*(u8 **)(arr + i * 0x14 + 0x10), 1);
      i++;
    } while (i < (*(vcount_t *)(*(u8 **)self + 0x34))(self));
  }
  if (*(u32 *)(self + 0x14)) ext_634273(*(u8 **)(self + 0x14), 0x14);
  *(u32 *)(self + 0x10) = n;
  u64 sz = (u64)n * 0x14;
  *(u8 **)(self + 0x14) = ext_41e290(sz >> 32 ? 0xffffffffu : (u32)sz);
  if ((s32)*(u32 *)(self + 0x10) > 0) {
    u32 k = 0;
    do {
      u8 *p = *(u8 **)(self + 0x14);
      p[k * 0x14 + 0xc] = 0;
      p = *(u8 **)(self + 0x14);
      *(u32 *)(p + k * 0x14 + 0x10) = 0;
      p = *(u8 **)(self + 0x14);
      *(u32 *)(p + k * 0x14) = 0;
      k++;
    } while ((s32)k < (s32)*(u32 *)(self + 0x10));
  }
}
PCREG(639c50, resetTable_639c50);
