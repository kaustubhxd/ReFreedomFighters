// batch36017.cpp - cascade s4 batch 36017: 0x5fa4f0, 0x5a3000, 0x597c40, 0x6279e0 (tier F rows).
#include "ff.h"

typedef void(THISCALL *v1_t)(void *, u32);
typedef void(THISCALL *v2_t)(void *, u32, u32);
typedef void(THISCALL *v3_t)(void *, u32, u32, u32);
typedef u8 *(THISCALL *v2o_t)(void *, u32, u32);
typedef u8(THISCALL *v1b_t)(void *, u32);
typedef u32(THISCALL *v1u_t)(void *, u32);
typedef u8 *(THISCALL *v1o_t)(void *, u32);

static inline u32 rd(u8 *p) { return *(u32 *)p; }
static inline void wr(u8 *p, u32 v) { *(u32 *)p = v; }

// 0x5fa4f0, thiscall(s) ret 4 (this = E): d = E[4]; s->slot 0x2c(d[0x14]); for i < E[4][0x14]: s->slot 0x3c(E[4][0xc][i]); s->slot 0x2c(E[4][8]);
// for i < E[4][8]: o = E[4][0][i]; o->slot 0xc(s, E).
static void THISCALL fn5fa4f0(u8 *E, u8 *s) {
  u8 *d = *(u8 **)(E + 4);
  (*(v1_t **)s)[0x2c / 4](s, rd(d + 0x14));
  d = *(u8 **)(E + 4);
  if (rd(d + 0x14) > 0) {
    u32 i = 0;
    do {
      (*(v1_t **)s)[0x3c / 4](s, ((u32 *)rd(d + 0xc))[i]);
      d = *(u8 **)(E + 4);
      i++;
    } while (i < rd(d + 0x14));
  }
  d = *(u8 **)(E + 4);
  (*(v1_t **)s)[0x2c / 4](s, rd(d + 8));
  d = *(u8 **)(E + 4);
  if (rd(d + 8) > 0) {
    u32 i = 0;
    do {
      u8 *o = ((u8 **)rd(d))[i];
      (*(v2_t **)o)[0xc / 4](o, (u32)s, (u32)E);
      d = *(u8 **)(E + 4);
      i++;
    } while (i < rd(d + 8));
  }
}
PCREG(5fa4f0, fn5fa4f0);

extern "C" void THISCALL ext_598e10(void *self, u32 a, u32 b, u32 c);  // ret 0xc

// 0x5a3000, thiscall(no args) (this = E): id = E[0x784] (unaligned) and E[0x92e] must be non-null. x = [[0x70039c]+0x9b]->slot 0x58(id); a = x->slot 0x1e0(0x2007f9);
// n = tab->slot 0x154(a ? 0x6adee8 : 0x6a6088, 0); b = x->slot 0x1e0(*(u32 *)(n+0x23)); returns when b == 0.
// a: x[0x783] = 1. Then E[0x92e][0x852]->0x598e10(x, 5, 0.1f).
static void THISCALL fn5a3000(u8 *E) {
  u32 id = rd(E + 0x784);
  if (!id) return;
  if (rd(E + 0x92e) == 0) return;
  u8 *tab = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  u8 *x = (*(v1o_t **)tab)[0x58 / 4](tab, id);
  u8 a = (*(v1b_t **)x)[0x1e0 / 4](x, 0x2007f9u);
  tab = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  u8 *n = (*(v2o_t **)tab)[0x154 / 4](tab, a ? 0x6adee8u : 0x6a6088u, 0);
  u8 b = (*(v1b_t **)x)[0x1e0 / 4](x, rd(n + 0x23));
  if (!b) return;
  if (a) x[0x783] = 1;
  u8 *h = *(u8 **)(*(u8 **)(E + 0x92e) + 0x852);
  ext_598e10(h, (u32)x, 5, 0x3dcccccdu);
}
PCREG(5a3000, fn5a3000);

extern "C" u32 THISCALL ext_594040(void *self, u32 a, u32 b);  // ret 8
extern "C" u8 *THISCALL ext_597720(void *self, u32 *out);      // ret 4
extern "C" void THISCALL ext_5967b0(void *self, u8 *p);        // ret 4

// 0x597c40, thiscall(no args) (this = E): E[0xdd] = 0x594040(E[0x1d0b], 0x11, 1). E[0x4f7] != 0: loc = {0x6ad2f4, id, 0, 0, 0}; E[0x1d0b]->slot 0x84(&loc[2]);
// while E[0x1fba] != E[0x1fae]: p = 0x597720(E, &tmp); null stops; loc[0] = 0x6ad2f4, loc[1] = [[0x70039c]+0x9b]->slot 0x4c(E[0x1d0b]); E[0x1d0b]->slot 0x12c(p, u16 E[0x1d2d], loc); 0x5967b0(E, p).
static void THISCALL fn597c40(u8 *E) {
  u32 loc[5];
  u32 tmp;
  u32 r = ext_594040(*(u8 **)(E + 0x1d0b), 0x11, 1);
  wr(E + 0xdd, r);
  if (rd(E + 0x4f7) == 0) return;
  u8 *o = *(u8 **)(E + 0x1d0b);
  loc[2] = loc[3] = loc[4] = 0;
  (*(v1_t **)o)[0x84 / 4](o, (u32)&loc[2]);
  if (rd(E + 0x1fba) == rd(E + 0x1fae)) return;
  do {
    u8 *p = ext_597720(E, &tmp);
    if (!p) return;
    u8 *tab = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
    loc[0] = 0x6ad2f4;
    loc[1] = (*(v1u_t **)tab)[0x4c / 4](tab, rd(E + 0x1d0b));
    o = *(u8 **)(E + 0x1d0b);
    (*(v3_t **)o)[0x12c / 4](o, (u32)p, *(u16 *)(E + 0x1d2d), (u32)loc);
    ext_5967b0(E, p);
  } while (rd(E + 0x1fba) != rd(E + 0x1fae));
}
PCREG(597c40, fn597c40);

extern "C" u32 ext_62c640(u32 a, u32 b);  // cdecl

// 0x6279e0, cdecl(A, p, end, out): scans pairs (kind, idx) from p to end; value(pair) = kind == 0 ? A[0x4c + idx] : 0x62c640(kind, idx).
// p == end -> -1. First pair's value - 0x18 > 1 (unsigned): *out = p, return 0. Otherwise advance; each later pair: value 0x12 -> *out = p + 2, return 10; value - 0x18 > 1 -> *out = p, return 0; running off end -> -1.
static inline u32 pairValue(u8 *A, u8 *p) {
  u8 kind = p[0];
  u32 idx = p[1];
  if (kind == 0) return A[0x4c + idx];
  return ext_62c640(kind, idx);
}
static u32 fn6279e0(u8 *A, u8 *p, u8 *end, u8 **out) {
  if (p == end) return 0xffffffffu;
  u32 v = pairValue(A, p);
  if (v - 0x18 > 1) {
    *out = p;
    return 0;
  }
  p += 2;
  if (p == end) return 0xffffffffu;
  for (;;) {
    v = pairValue(A, p);
    if (v == 0x12) {
      *out = p + 2;
      return 10;
    }
    if (v - 0x18 > 1) {
      *out = p;
      return 0;
    }
    p += 2;
    if (p == end) return 0xffffffffu;
  }
}
PCREG(6279e0, fn6279e0);
