// batch36054.cpp - cascade s4 batch 36054: 0x4d1060 (tier F row).
#include "ff.h"

static inline u32 rd(u8 *p) { return *(u32 *)p; }
static inline void wr(u8 *p, u32 v) { *(u32 *)p = v; }

// 0x4d1060, thiscall(size) ret 4 returns eax (this = a): best-fit allocator over a free table (a[0] = entries {addr, size} of 8 bytes, a[8] = count). size == 0 -> 0. need = (size + 7) & ~3.
// Scan for the entry with the smallest leftover (size - need, unsigned) among those with size >= need; stop at the first leftover < 8. None -> 0. alloc = leftover >= 8 ? need : need + leftover; *addr = alloc (header);
// entry.addr += alloc; entry.size -= alloc; empty entry: count--, the last entry moves into its slot. Returns addr + 4.
static u32 THISCALL fn4d1060(u8 *a, u32 size) {
  if (!size) return 0;
  u8 *tab = *(u8 **)a;
  u32 cnt = rd(a + 8);
  u32 need = (size + 7) & 0xfffffffcu;
  u8 *best = 0;
  u32 bestleft = 0xffffffffu;
  u32 i = 0;
  if (cnt == 0) return 0;
  u8 *e = tab;
  do {
    u32 sz = rd(e + 4);
    if (!(need > sz)) {
      u32 left = sz - need;
      if (left < bestleft) {
        best = e;
        bestleft = left;
        if (left < 8) break;
      }
    }
    i++;
    e += 8;
  } while (i < cnt);
  if (!best) return 0;
  u8 *addr = *(u8 **)best;
  u32 alloc = bestleft >= 8 ? need : bestleft + need;
  wr(addr, alloc);
  wr(best, rd(best) + alloc);
  wr(best + 4, rd(best + 4) - alloc);
  if (rd(best + 4) == 0) {
    wr(a + 8, rd(a + 8) - 1);
    u8 *last = *(u8 **)a + rd(a + 8) * 8;
    if (best != last) {
      wr(best, rd(last));
      wr(best + 4, rd(last + 4));
    }
  }
  return (u32)(addr + 4);
}
PCREG(4d1060, fn4d1060);
