// batch66031.cpp - cascade s4 batch 66031: 0x61ffb0 (tier F row).
#include "ff.h"

typedef u8 *(*alloc_t)(u32);
typedef u8 *(*realloc_t)(u8 *, u32);

static inline u32 rd(u8 *p) { return *(u32 *)p; }
static inline void wr(u8 *p, u32 v) { *(u32 *)p = v; }

// 0x61ffb0, cdecl(c), returns the new node index or -1 (c = context with allocator c[0xc] (size) and reallocator c[0x10] (ptr, size)): c[0x1fc] == 0 -> c[0x1fc] = alloc(c[0x260] * 4) (null -> -1), *c[0x1fc] = 0.
// c[0x1f4] (count) >= c[0x1f0] (capacity): c[0x1e8] set -> capacity doubled and realloc(arr, capacity * 28), else capacity 0x20 and alloc(0x380); c[0x1e8] = result (null -> -1).
// idx = c[0x1f4]++; node = arr + idx * 28. c[0x1f8] (stack depth) != 0: parent = arr[c[0x1fc][depth - 1]]: parent[0x10] set -> arr[parent[0x10]][0x18] = idx; parent[0x14] == 0 -> parent[0xc] = idx; parent[0x10] = idx; parent[0x14]++.
// node[0x18] = node[0x14] = node[0x10] = node[0xc] = 0; return idx.
extern "C" s32 fn61ffb0(u8 *c) {
  if (rd(c + 0x1fc) == 0) {
    u8 *p = (*(alloc_t *)(c + 0xc))(rd(c + 0x260) << 2);
    wr(c + 0x1fc, (u32)p);
    if (!p) return -1;
    wr(p, 0);
  }
  u32 cap = rd(c + 0x1f0);
  if (!(rd(c + 0x1f4) < cap)) {
    u8 *arr = *(u8 **)(c + 0x1e8);
    u8 *n;
    if (arr) {
      cap += cap;
      wr(c + 0x1f0, cap);
      n = (*(realloc_t *)(c + 0x10))(arr, cap * 28);
    } else {
      wr(c + 0x1f0, 0x20);
      n = (*(alloc_t *)(c + 0xc))(0x380);
    }
    wr(c + 0x1e8, (u32)n);
    if (!n) return -1;
  }
  u32 idx = rd(c + 0x1f4);
  u32 depth = rd(c + 0x1f8);
  u8 *arr = *(u8 **)(c + 0x1e8);
  wr(c + 0x1f4, idx + 1);
  u8 *node = arr + idx * 28;
  if (depth) {
    u32 pi = ((u32 *)*(u8 **)(c + 0x1fc))[depth - 1];
    u8 *par = arr + pi * 28;
    u32 tail = rd(par + 0x10);
    if (tail) wr(arr + tail * 28 + 0x18, idx);
    u32 cnt = rd(par + 0x14);
    if (cnt == 0) wr(par + 0xc, idx);
    cnt++;
    wr(par + 0x10, idx);
    wr(par + 0x14, cnt);
  }
  wr(node + 0x18, 0);
  wr(node + 0x14, 0);
  wr(node + 0x10, 0);
  wr(node + 0xc, 0);
  return (s32)idx;
}
PCREG(61ffb0, fn61ffb0);
