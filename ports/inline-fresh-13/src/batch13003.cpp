// batch13003.cpp - fresh slice 13, batch 3 (docs/20-fresh-13.md), 2026-10-12.
// ZDrawArray<T, T, ZArrayBlock>::CalculateUsedArray(T** out, unsigned) for two element types (name map high; the second
// argument is unused, ret 8). The array is a list of blocks from this+8 (next at +8, list ends at null or back at the
// first block). Each block holds its free list head (word +2, 0xffff ends it, the next index is the first word of the free
// element) and its elements from +0x10 with a fixed stride: 0x34 bytes for ZGateViewEntry (0x649950) and 0x10 for
// ZTextureDrawEntry (0x649f90). Steps:
//   1. number the blocks in their byte +1 (the first block's old value is kept; at 0xff blocks the hook at 0x7003b0 runs,
//      int3 when null);
//   2. n = this->vtbl[+0x28]() elements per block; a 64 KB stack map of blocks*n bytes is cleared (memset 0x634d10);
//   3. every free element is marked in the map; 4. every unmarked element's address is appended to out[];
//   5. every block's byte +1 gets the first block's old value back.
// The exe's stack cookie and alloca probe are not reproduced.
#include "ff.h"

extern "C" char ext_634d10[];
typedef u32(THISCALL *Count0)(void *self);
typedef void *(*Memset3)(void *d, int v, u32 n);
typedef void (*Hook0)(void);

template <u32 STRIDE>
static void THISCALL calcUsed(u8 *self, u32 *out, u32 unused) {
  u8 map[0x10000];
  u8 *first = *(u8 **)(self + 8);
  if (!first)
    return;
  u8 saved = first[1];
  u8 bl = 0;
  u8 *b = first;
  do {
    if (bl == 0xff) {
      u32 h = G(u32, 0x7003b0);
      if (!h)
        __builtin_debugtrap();
      ((Hook0)h)();
    }
    b[1] = bl;
    bl++;
    b = *(u8 **)(b + 8);
  } while (b != *(u8 **)(self + 8) && b);
  u32 n = ((Count0)(*(u32 *)(*(u32 *)self + 0x28)))(self);
  ((Memset3)(void *)ext_634d10)(map, 0, (u32)bl * n);
  u8 *head = *(u8 **)(self + 8);
  b = head;
  if (b) {
    do {
      u16 idx = *(u16 *)(b + 2);
      if (idx != 0xffff) {
        u8 *base = map + (u32)b[1] * n;
        do {
          base[idx] = 1;
          idx = *(u16 *)(b + 0x10 + (u32)idx * STRIDE);
        } while (idx != 0xffff);
      }
      b = *(u8 **)(b + 8);
    } while (b != head && b);
  }
  u32 k = 0, m = 0;
  b = head;
  if (b) {
    do {
      u8 *p = b + 0x10;
      for (u32 i = 0; i < n; i++) {
        if (!map[m++])
          out[k++] = (u32)p;
        p += STRIDE;
      }
      b = *(u8 **)(b + 8);
    } while (b != *(u8 **)(self + 8) && b);
  }
  b = *(u8 **)(self + 8);
  if (b) {
    do {
      b[1] = saved;
      b = *(u8 **)(b + 8);
    } while (b != *(u8 **)(self + 8) && b);
  }
}
static void THISCALL calcUsedGate(u8 *self, u32 *out, u32 unused) { calcUsed<0x34>(self, out, unused); }
static void THISCALL calcUsedTexture(u8 *self, u32 *out, u32 unused) { calcUsed<0x10>(self, out, unused); }
PCREG(649950, calcUsedGate);
PCREG(649f90, calcUsedTexture);
