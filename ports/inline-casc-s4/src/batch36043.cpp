// batch36043.cpp - cascade s4 batch 36043: 0x444910, 0x4c4fc0, 0x4ca820, 0x4acd10, 0x43f900 (tier F rows).
#include "ff.h"

typedef void(THISCALL *v0_t)(void *);
typedef void(THISCALL *v1_t)(void *, u32);
typedef void(THISCALL *v2_t)(void *, u32, u32);
typedef void(THISCALL *v3_t)(void *, u32, u32, u32);
typedef u8 *(THISCALL *v0o_t)(void *);
typedef u8 *(THISCALL *v1o_t)(void *, u32);
typedef u8 *(THISCALL *v2o_t)(void *, u32, u32);
typedef u32(THISCALL *v0r_t)(void *);
typedef u32(THISCALL *v1r_t)(void *, u32);
typedef u32(THISCALL *v4r_t)(void *, u32, u32, u32, u32);

static inline u32 rd(u8 *p) { return *(u32 *)p; }
static inline void wr(u8 *p, u32 v) { *(u32 *)p = v; }

extern "C" void THISCALL ext_440ce0(void *it, u32 a);   // ret 4, fills {cur, p, end}
extern "C" u8 *THISCALL ext_4dafb0(void *self);          // plain ret

// 0x444910, thiscall(out, lim) ret 8 returns eax (this = s): it = 0x440ce0(&it, s[0xbc]) gives cur, p, end; p == 0 -> return out. Loop: lo = p[0] & ~7, hi = p[1] & ~7, p += 8 bytes; for q in [lo, hi] step 0x70: lim <= out -> return out;
// x = q (or 0x4dafb0(q) when q[0x3c] & 0x40000000); x[0x3c] & 0x10004000 == 0 -> *out++ = q. When p == end: follow cur: !cur or !(cur[8] & 1) or !(cur = cur[0xc]) -> return; skip nodes with kind byte < 2; else p = cur + 0xc (+4 when odd), end = cur + (kind + 3) * 4. p == 0 -> return.
static u32 THISCALL fn444910(u8 *s, u32 *out, u32 *lim) {
  u32 it[3];
  ext_440ce0(it, rd(s + 0xbc));
  u8 *p = (u8 *)it[1];
  if (!p) return (u32)out;
  u8 *cur = (u8 *)it[0];
  u8 *end = (u8 *)it[2];
  for (;;) {
    u32 lo = rd(p) & 0xfffffff8u;
    u32 hi = rd(p + 4) & 0xfffffff8u;
    p += 8;
    u32 q = lo;
    if (q <= hi) {
      for (;;) {
        if (lim <= out) return (u32)out;
        u8 *x = (u8 *)q;
        if (rd((u8 *)q + 0x3c) & 0x40000000u) x = ext_4dafb0((void *)q);
        if (!(rd(x + 0x3c) & 0x10004000u)) {
          *out = q;
          out++;
        }
        q += 0x70;
        if (!(q <= hi)) break;
      }
    }
    if (p == end) {
      if (!cur) return (u32)out;
      for (;;) {
        if (!(cur[8] & 1)) return (u32)out;
        cur = *(u8 **)(cur + 0xc);
        if (!cur) return (u32)out;
        if (cur[8] >= 2) break;
      }
      u8 al = cur[8];
      p = cur + 0xc;
      if (al & 1) p += 4;
      end = cur + ((u32)al + 3) * 4;
    }
    if (!p) return (u32)out;
  }
}
PCREG(444910, fn444910);

// 0x4c4fc0, thiscall() plain ret (this = s): ax = (u16)sys[0x9b]->slot 0x114(0x68fee8, 0, 0x6941a0, 0x120); l = s[0x54]; none -> return. Iterate l (slot 0x4c(&it), e = slot 0x5c(&it) while it[0]):
// o = sys[0x9b]->slot 0x58(e); o: c = o[8]; while c: x = c[0x54]; x -> s[0x44]->slot 0x130(x, ax, 0x186a0); o->slot 0x50(&c) (advance); c = the advanced value.
static void THISCALL fn4c4fc0(u8 *s) {
  u8 *tab = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  u32 ax = (u16)(*(v4r_t **)tab)[0x114 / 4](tab, 0x68fee8u, 0, 0x6941a0u, 0x120u);
  u8 *l = *(u8 **)(s + 0x54);
  if (!l) return;
  u32 it[3];
  (*(v1_t **)l)[0x4c / 4](l, (u32)it);
  l = *(u8 **)(s + 0x54);
  u32 e = (*(v1r_t **)l)[0x5c / 4](l, (u32)it);
  if (it[0] == 0) return;
  do {
    tab = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
    u8 *o = (*(v1o_t **)tab)[0x58 / 4](tab, e);
    if (o) {
      u8 *c = *(u8 **)(o + 8);
      if (c) {
        do {
          u8 *x = *(u8 **)(c + 0x54);
          if (x) {
            u8 *w = *(u8 **)(s + 0x44);
            (*(v3_t **)w)[0x130 / 4](w, (u32)x, ax, 0x186a0u);
          }
          (*(v1_t **)o)[0x50 / 4](o, (u32)&c);
        } while (c);
      }
    }
    l = *(u8 **)(s + 0x54);
    e = (*(v1r_t **)l)[0x5c / 4](l, (u32)it);
  } while (it[0] != 0);
}
PCREG(4c4fc0, fn4c4fc0);

extern "C" void ext_634273(u32 a, u32 b);   // cdecl

// 0x4ca820, thiscall() plain ret (this = s): t = s[0x44]; s[0x48] (byte) -> t = t->slot 0x20(). name = s[0x49] (unaligned): name and *name != 0: o = sys[0x9b]->slot 0x138(); x = sys[0x9b]->slot 0x4c(t, 2); o->slot 0x60(name, x).
// else: o->slot 0x60(s[0x44][4], x). Then name = s[0x49]; name -> ext_634273(name, 1). s->slot 0x58().
static void THISCALL fn4ca820(u8 *s) {
  u8 *t = *(u8 **)(s + 0x44);
  if (s[0x48]) t = (*(v0o_t **)t)[0x20 / 4](t);
  u8 *name = *(u8 **)(s + 0x49);
  if (name && name[0] != 0) {
    u8 *tab = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
    u8 *o = (*(v0o_t **)tab)[0x138 / 4](tab);
    tab = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
    u8 *x = (*(v2o_t **)tab)[0x4c / 4](tab, (u32)t, 2);
    (*(v2_t **)o)[0x60 / 4](o, rd(s + 0x49), (u32)x);
  } else {
    u8 *tab = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
    u8 *o = (*(v0o_t **)tab)[0x138 / 4](tab);
    u32 a = rd(*(u8 **)(s + 0x44) + 4);
    tab = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
    u8 *x = (*(v2o_t **)tab)[0x4c / 4](tab, (u32)t, 2);
    (*(v2_t **)o)[0x60 / 4](o, a, (u32)x);
  }
  u32 n = rd(s + 0x49);
  if (n) ext_634273(n, 1);
  (*(v0_t **)s)[0x58 / 4](s);
}
PCREG(4ca820, fn4ca820);

extern "C" u32 FASTCALL ext_4cc850(u32 a, u32 b);    // 0 = match
extern "C" u32 THISCALL ext_41e680(void *self);      // plain ret

// 0x4acd10, thiscall() plain ret (this = s): l = s[0x44][0x10][8]; none -> return. Iterate l (slot 0x4c, e = slot 0x5c while it[0]): o = [0x70038c]->slot 0xcc(e); n = o->slot 0x14(); n && 0x4cc850(o->slot 0x14(), 0x67a110) == 0:
// sub = s + 0x11a: (*(void ***)sub)[0x28](sub, o[0x106]) nonzero -> t = ext_41e680(o); d = s + 0x1c6: (*(void ***)d)[1](d, t).
static void THISCALL fn4acd10(u8 *s) {
  u8 *l = *(u8 **)(*(u8 **)(*(u8 **)(s + 0x44) + 0x10) + 8);
  if (!l) return;
  u32 it[3];
  (*(v1_t **)l)[0x4c / 4](l, (u32)it);
  l = *(u8 **)(*(u8 **)(*(u8 **)(s + 0x44) + 0x10) + 8);
  u32 e = (*(v1r_t **)l)[0x5c / 4](l, (u32)it);
  if (it[0] == 0) return;
  do {
    u8 *g = G(u8 *, 0x70038c);
    u8 *o = (*(v1o_t **)g)[0xcc / 4](g, e);
    if ((*(v0r_t **)o)[0x14 / 4](o)) {
      u32 r = (*(v0r_t **)o)[0x14 / 4](o);
      if (ext_4cc850(r, 0x67a110u) == 0) {
        u8 *sub = s + 0x11a;
        if ((*(v1r_t **)sub)[0x28 / 4](sub, rd(o + 0x106))) {
          u8 *d = s + 0x1c6;
          void **vt = *(void ***)d;
          u32 t = ext_41e680(o);
          ((v1_t)vt[1])(d, t);
        }
      }
    }
    l = *(u8 **)(*(u8 **)(*(u8 **)(s + 0x44) + 0x10) + 8);
    e = (*(v1r_t **)l)[0x5c / 4](l, (u32)it);
  } while (it[0] != 0);
}
PCREG(4acd10, fn4acd10);

extern "C" void STDCALL ext_610100(u32 a);                         // ret 4
extern "C" u32 THISCALL ext_4e1600(void *a);                       // plain ret, low byte = kind
extern "C" void THISCALL ext_4e11e0(void *a, u32 *p, u32 f);       // ret 8
extern "C" void THISCALL ext_4e12f0(void *a, u8 *p, u32 f);        // ret 8
extern "C" void THISCALL ext_4e1b30(void *a);                      // plain ret

// 0x43f900, thiscall(a) ret 4 (this = d): 0x610100(a); kind = 0x4e1600(a) (low byte): 3 -> 0x4e11e0(a, &t, 1). d[0x58] = 1.0f; kind 2 -> 0x4e12f0(a, d + 0x58, 1). d[0x30] |= 0x3000000.
// kind 3 -> 0x4e11e0(a, &u, 1); u == 0 -> d[0x30] &= ~0x1000000. kind 3 -> 0x4e11e0(a, &u, 1); u == 0 -> d[0x30] &= ~0x2000000. v = 0; kind 3 -> 0x4e11e0(a, &v, 1). 0x4e1b30(a).
static void THISCALL fn43f900(u8 *d, u8 *a) {
  ext_610100((u32)a);
  u32 t = 1;
  if ((u8)ext_4e1600(a) == 3) ext_4e11e0(a, &t, 1);
  wr(d + 0x58, 0x3f800000);
  if ((u8)ext_4e1600(a) == 2) ext_4e12f0(a, d + 0x58, 1);
  wr(d + 0x30, rd(d + 0x30) | 0x3000000);
  u32 u;
  if ((u8)ext_4e1600(a) == 3) {
    ext_4e11e0(a, &u, 1);
    if (u == 0) wr(d + 0x30, rd(d + 0x30) & 0xfeffffffu);
  }
  if ((u8)ext_4e1600(a) == 3) {
    ext_4e11e0(a, &u, 1);
    if (u == 0) wr(d + 0x30, rd(d + 0x30) & 0xfdffffffu);
  }
  u32 v = 0;
  if ((u8)ext_4e1600(a) == 3) ext_4e11e0(a, &v, 1);
  ext_4e1b30(a);
}
PCREG(43f900, fn43f900);
