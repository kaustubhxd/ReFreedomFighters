// batch36032.cpp - cascade s4 batch 36032: 0x4e6a80, 0x553d00 (tier F rows).
#include "ff.h"

typedef void(THISCALL *v1_t)(void *, u32);
typedef void(THISCALL *v2_t)(void *, u32, u32);
typedef u8 *(THISCALL *v0o_t)(void *);
typedef u8 *(THISCALL *v1o_t)(void *, u32);
typedef u32(THISCALL *v1r_t)(void *, u32);
typedef u8 *(THISCALL *v2o_t)(void *, u32, u32);

static inline u32 rd(u8 *p) { return *(u32 *)p; }
static inline void wr(u8 *p, u32 v) { *(u32 *)p = v; }

// 0x4e6a80, fastcall(a = ecx, lo = edx, hi on the stack) ret 4: quicksort of u32 (unsigned) elements a[lo..hi] with a pivot from a global LCG at 0x6e7b9c:
// g = G; G = g + 3 + rol(g, g & 31); pivot = a[lo + (G & 0xffffff) % (hi - lo + 1)] (signed idiv). Hoare partition, recurse on [lo, j] when lo < j, loop on [i, hi] when i < hi.
static void FASTCALL fn4e6a80(u32 *a, s32 lo, s32 hi) {
  for (;;) {
    u32 g = G(u32, 0x6e7b9c);
    u32 cl = g & 0x1f;
    u32 rot = (g << cl) | (cl ? (g >> (32 - cl)) : 0);
    g = g + 3 + rot;
    G(u32, 0x6e7b9c) = g;
    s32 cnt = hi - lo + 1;
    s32 r = (s32)(G(u32, 0x6e7b9c) & 0xffffff);
    u32 piv = a[lo + r % cnt];
    s32 i = lo, j = hi;
    do {
      while (a[i] < piv) i++;
      while (a[j] > piv) j--;
      if (i > j) break;
      u32 t = a[i];
      a[i] = a[j];
      a[j] = t;
      i++;
      j--;
    } while (i <= j);
    if (lo < j) fn4e6a80(a, lo, j);
    if (i < hi) lo = i;
    else return;
  }
}
PCREG(4e6a80, fn4e6a80);

// 0x553d00, thiscall() returns eax (this = s): s[0xc] = 0; tab = sys[0x9b]; o = tab->slot 0x138(); o->slot 0x88(0x6a5c04, &id) (id = 0 first); r = tab->slot 0x58(id);
// r == 0: logger(0x6a57fc, 0x426) prints 0x6a5c1c, return 0. Else l = r[0x10][8]; if l: it; l->slot 0x4c(&it); v = r[0x10][8]->slot 0x5c(&it); if it[0]: s[0xc] = G[0x70038c]->slot 0xcc(v). return s[0xc].
static u32 THISCALL fn553d00(u8 *s) {
  wr(s + 0xc, 0);
  u8 *tab = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  u8 *o = (*(v0o_t **)tab)[0x138 / 4](tab);
  u32 id = 0;
  (*(v2_t **)o)[0x88 / 4](o, 0x6a5c04u, (u32)&id);
  tab = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  u8 *r = (*(v1o_t **)tab)[0x58 / 4](tab, id);
  if (!r) {
    u8 *db = G(u8 *, 0x700390);
    u8 *lo = (*(v2o_t **)db)[0x20 / 4](db, 0x6a57fcu, 0x426u);
    void *fn = *(void **)((u8 *)*(void ***)lo + 0x2c);
    ((void (*)(u8 *, u32))fn)(lo, 0x6a5c1cu);
    return 0;
  }
  u8 *l = *(u8 **)(*(u8 **)(r + 0x10) + 8);
  if (l) {
    u32 it[4];
    (*(v1_t **)l)[0x4c / 4](l, (u32)it);
    u8 *l2 = *(u8 **)(*(u8 **)(r + 0x10) + 8);
    u32 v = (*(v1r_t **)l2)[0x5c / 4](l2, (u32)it);
    if (it[0] != 0) {
      u8 *g = G(u8 *, 0x70038c);
      wr(s + 0xc, (*(v1r_t **)g)[0xcc / 4](g, v));
    }
  }
  return rd(s + 0xc);
}
PCREG(553d00, fn553d00);
