// batch66062.cpp - cascade s4 batch 66062: 0x4e3f60 (tier F row).
#include "ff.h"

typedef u8 *(THISCALL *v2o_t)(void *, u32, u32);

static inline u32 rd(u8 *p) { return *(u32 *)p; }
static inline void wr(u8 *p, u32 v) { *(u32 *)p = v; }

extern "C" u8 *THISCALL ext_4e6b80(void *self, u32 *out);          // ret 4
extern "C" void THISCALL ext_4e4a50(void *self, u32 a, u32 b);     // ret 8

// 0x4e3f60, thiscall(a) ret 4 (this = s; a = quad-tree style cursor: a[4] node to link, a[8] level, a[0xc] last level, a[0x10] / a[0x18] occupancy masks, *a = pool {base +0, size +8, count +0x10, stride +0xc}):
// while a[8] != a[0xc]: a[8]++; m = ~((0x10000 >> a[8]) - 1) (arithmetic shift); sel = (a[0x10] & m != 0) | (a[0x18] & m != 0) << 1; both masks &= ~m; slot = s + sel * 2 (u16): when 0 and the pool is full (pool[0x10] == pool[8]): log (0x6972d8, 0x11c) 0x697300 and stop;
// when 0 otherwise: *slot = low 16 bits of 0x4e6b80(pool, &tmp) tmp; 0x4e4a50(that result, pool, s); then s = base + *slot * stride.
// Finally node = a[4]; s[0xc] chain: node[0] = s[0xc]; s[0xc]->[4] = node (when set); node[4] = 0; s[0xc] = node; node[0x18] = s.
static void THISCALL fn4e3f60(u8 *s, u8 *a) {
  if (rd(a + 8) != rd(a + 0xc)) {
    for (;;) {
      wr(a + 8, rd(a + 8) + 1);
      u32 k = rd(a + 8);
      s32 mm = 0x10000 >> (k & 31);
      u32 m = ~(u32)(mm - 1);
      u32 c = rd(a + 0x10), d = rd(a + 0x18);
      u32 sel = ((c & m) != 0 ? 1u : 0u) | ((d & m) != 0 ? 2u : 0u);
      u32 nb = ~m;
      wr(a + 0x18, d & nb);
      wr(a + 0x10, c & nb);
      u16 *slot = (u16 *)(s + sel * 2);
      if (*slot == 0) {
        u8 *pool = *(u8 **)a;
        if (rd(pool + 0x10) == rd(pool + 8)) {
          u8 *db = G(u8 *, 0x700390);
          u8 *lo = (*(v2o_t **)db)[0x20 / 4](db, 0x6972d8u, 0x11cu);
          void *fn = *(void **)((u8 *)*(void ***)lo + 0x30);
          ((void (*)(u8 *, u32))fn)(lo, 0x697300u);
          break;
        }
        u32 tmp;
        u8 *r = ext_4e6b80(pool, &tmp);
        *slot = (u16)tmp;
        ext_4e4a50(r, (u32)pool, (u32)s);
      }
      u8 *pool = *(u8 **)a;
      s = (u8 *)((u32)*slot * rd(pool + 0xc) + rd(pool));
      if (rd(a + 8) == rd(a + 0xc)) break;
    }
  }
  u8 *head = *(u8 **)(s + 0xc);
  u8 *node = *(u8 **)(a + 4);
  if (head) wr(head + 4, (u32)node);
  wr(node, rd(s + 0xc));
  wr(node + 4, 0);
  wr(s + 0xc, (u32)node);
  wr(node + 0x18, (u32)s);
}
PCREG(4e3f60, fn4e3f60);
