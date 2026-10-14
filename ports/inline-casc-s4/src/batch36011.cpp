// batch36011.cpp - cascade s4 batch 36011: 0x476970, 0x497160, 0x49c560, 0x4f0e10, 0x4f13f0 (tier F rows).
#include "ff.h"

typedef void(THISCALL *v0_t)(void *);
typedef void(THISCALL *v1_t)(void *, u32);
typedef u32(THISCALL *v1u_t)(void *, u32);
typedef u8(THISCALL *v1b_t)(void *, u32);
typedef void(THISCALL *v2_t)(void *, u32, u32);
typedef void(THISCALL *v3_t)(void *, u32, u32, u32);
typedef u8 *(THISCALL *v1o_t)(void *, u32);
typedef u32(THISCALL *v0r_t)(void *);

static inline u32 rd(u8 *p) { return *(u32 *)p; }
static inline void wr(u8 *p, u32 v) { *(u32 *)p = v; }

extern "C" u8 *ext_41e290(u32 size);  // cdecl allocator

// 0x476970, thiscall(no args): n = E[0x5c]; null returns. E[0x72] byte set: tail call E->slot 0x28(). Else E[0x64] = alloc(n*4 saturating to -1), E[0x68] = alloc(same), E[0x60] = n;
// list = ([0x70039c][0x9b])->slot 0x58(E[0x73])[0x50]; for each node: t = node[0x54]; E[0x64][i] = t; t[0x6c] = E; E[0x68][i] = tab->slot 0x4c(t).
static void THISCALL fn476970(u8 *E) {
  u32 n = rd(E + 0x5c);
  if (!n) return;
  if (E[0x72] != 0) {
    (*(v0_t **)E)[0x28 / 4](E);
    return;
  }
  u64 sz = (u64)n * 4;
  u32 size = (sz >> 32) ? 0xffffffffu : (u32)sz;
  wr(E + 0x64, (u32)ext_41e290(size));
  n = rd(E + 0x5c);
  sz = (u64)n * 4;
  size = (sz >> 32) ? 0xffffffffu : (u32)sz;
  wr(E + 0x68, (u32)ext_41e290(size));
  wr(E + 0x60, rd(E + 0x5c));
  u8 *tab = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  u8 *obj = (*(v1o_t **)tab)[0x58 / 4](tab, rd(E + 0x73));
  if (!obj) return;
  u8 *node = *(u8 **)(obj + 0x50);
  if (!node) return;
  u32 i = 0;
  do {
    u8 *t = *(u8 **)(node + 0x54);
    wr(*(u8 **)(E + 0x64) + 4 * i, (u32)t);
    wr(t + 0x6c, (u32)E);
    tab = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
    u32 v = (*(v1u_t **)tab)[0x4c / 4](tab, (u32)t);
    wr(*(u8 **)(E + 0x68) + 4 * i, v);
    i++;
    node = *(u8 **)(node + 0x60);
  } while (node);
}
PCREG(476970, fn476970);

// 0x497160, thiscall(a) ret 4, returns bool: a[0x3c] & 0x8000000 -> 0. i = (s32)(a - E[0x14][4]) / 0x70 - E[0x28] / 0x70 (unsigned); v = E[0x5d][i]; 0 -> 0;
// E[8]->slot 0x10(v) false -> 0; E[0xc][(E[8][0x10] & v)] = 0; [0x70038c]->slot 0x30(0x68e35c, (E[8][0x10] & v) * 4, 4) when non-null; returns 1.
static u8 THISCALL fn497160(u8 *E, u8 *a) {
  if (rd(a + 0x3c) & 0x8000000u) return 0;
  s32 d = (s32)((u32)a - rd(*(u8 **)(E + 0x14) + 4));
  s32 q = d / 0x70;
  u32 u = rd(E + 0x28) / 0x70u;
  s32 i = q - (s32)u;
  u32 v = ((u32 *)rd(E + 0x5d))[i];
  if (!v) return 0;
  u8 *o = *(u8 **)(E + 8);
  if (!(*(v1b_t **)o)[0x10 / 4](o, v)) return 0;
  o = *(u8 **)(E + 8);
  u32 m = rd(o + 0x10) & v;
  wr(*(u8 **)(E + 0xc) + 4 * m, 0);
  u8 *e2 = G(u8 *, 0x70038c);
  if (e2) {
    o = *(u8 **)(E + 8);
    (*(v3_t **)e2)[0x30 / 4](e2, 0x68e35cu, (rd(o + 0x10) & v) << 2, 4);
  }
  return 1;
}
PCREG(497160, fn497160);

extern "C" u32 THISCALL ext_49c980(void *self, u32 a, u32 b);                 // ret 8
extern "C" u32 THISCALL ext_49cbb0(void *self, u32 a, void *b, u32 c);        // ret 0xc
extern "C" u32 THISCALL ext_49ccc0(void *self, u32 a, void *b, u32 c);        // ret 0xc
extern "C" void THISCALL ext_4e6bf0(void *self, void *a);                     // ret 4

// 0x49c560, thiscall(a) ret 4 (this = E): k = a[0x68]; r = 0x49c980(E, E[0x39], k); count = (r >> 16) + (u16)r; for each i < count: o = E[0x39][i]; o[0x3c] |= 0x1000000; m = o[0x68];
// 0x49cbb0(E, m, a, 1) & 1 -> 0x49ccc0(E, m, a, 1). Then t = E[0x1d] + 4k; head = t[0]; t[1] = 1; for each node (via +0xc): 0x4e6bf0(E+4, node); t[0] = 0; a[0x3c] |= 0x1000000.
static void THISCALL fn49c560(u8 *E, u8 *a) {
  u32 k = rd(a + 0x68);
  u32 r = ext_49c980(E, rd(E + 0x39), k);
  u32 count = (r >> 16) + (r & 0xffff);
  if (count != 0) {
    u32 i = 0;
    do {
      u8 *o = ((u8 **)rd(E + 0x39))[i];
      wr(o + 0x3c, rd(o + 0x3c) | 0x1000000u);
      u32 m = rd(o + 0x68);
      u32 ok = ext_49cbb0(E, m, a, 1);
      if (ok & 1) ext_49ccc0(E, m, a, 1);
      i++;
    } while (i < count);
  }
  u32 *t = (u32 *)rd(E + 0x1d) + k;
  u8 *head = (u8 *)t[0];
  t[1] = 1;
  while (head) {
    u8 *x = head;
    head = *(u8 **)(x + 0xc);
    ext_4e6bf0(E + 4, x);
  }
  t[0] = 0;
  wr(a + 0x3c, rd(a + 0x3c) | 0x1000000u);
}
PCREG(49c560, fn49c560);

// 0x4f0e10, thiscall(s) ret 4 (this = E): s->slot 0x3c(E[0x2e]); n = E[0x2e]; zero returns. s->slot 0x10(E[0x2a], n*40); s->slot 0x3c(E[0x32]);
// for i < E[0x32]: rec = E[0x3a] + 8i; local = {rec[0], (s32)(rec[4] - E[0x2a]) / 40}; s->slot 0x10(&local, 8). Then s->slot 0x10(E[0x36], E[0x32]*4).
static void THISCALL fn4f0e10(u8 *E, u8 *s) {
  u32 loc[2];
  (*(v1_t **)s)[0x3c / 4](s, rd(E + 0x2e));
  u32 n = rd(E + 0x2e);
  if (!n) return;
  (*(v2_t **)s)[0x10 / 4](s, rd(E + 0x2a), n * 40);
  (*(v1_t **)s)[0x3c / 4](s, rd(E + 0x32));
  for (u32 i = 0; i < rd(E + 0x32); i++) {
    u8 *rec = *(u8 **)(E + 0x3a);
    loc[0] = rd(rec + 8 * i);
    s32 x = (s32)(rd(rec + 8 * i + 4) - rd(E + 0x2a));
    loc[1] = (u32)(x / 40);
    (*(v2_t **)s)[0x10 / 4](s, (u32)loc, 8);
  }
  (*(v2_t **)s)[0x10 / 4](s, rd(E + 0x36), rd(E + 0x32) * 4);
}
PCREG(4f0e10, fn4f0e10);

typedef u8 *(*strncpy_t)(u8 *, const u8 *, u32);

// 0x4f13f0, thiscall(src, len) ret 8 (this = E): frees E[0x97] through [0x70039c]->slot 0xfc and clears it. src && len: E[0x97] = eng->slot 0xf8(len + 1), strncpy(E[0x97], src, len),
// E[0x97][len] = 0, frees E[0x9b] (slot 0xfc) and clears it, returns E->slot 0x278(). Else E->slot 0x230(), frees E[0x9b], clears it, returns 1.
static u32 THISCALL fn4f13f0(u8 *E, u8 *src, u32 len) {
  u32 p = rd(E + 0x97);
  u8 *eng = G(u8 *, 0x70039c);
  if (p) {
    (*(v1_t **)eng)[0xfc / 4](eng, p);
    wr(E + 0x97, 0);
  }
  if (src && len) {
    eng = G(u8 *, 0x70039c);
    u32 buf = (*(v1u_t **)eng)[0xf8 / 4](eng, len + 1);
    wr(E + 0x97, buf);
    G(strncpy_t, 0x67642c)((u8 *)buf, src, len);
    ((u8 *)rd(E + 0x97))[len] = 0;
    u32 q = rd(E + 0x9b);
    if (q) {
      eng = G(u8 *, 0x70039c);
      (*(v1_t **)eng)[0xfc / 4](eng, q);
    }
    wr(E + 0x9b, 0);
    return (*(v0r_t **)E)[0x278 / 4](E);
  }
  (*(v0_t **)E)[0x230 / 4](E);
  u32 q = rd(E + 0x9b);
  if (q) {
    eng = G(u8 *, 0x70039c);
    (*(v1_t **)eng)[0xfc / 4](eng, q);
  }
  wr(E + 0x9b, 0);
  return 1;
}
PCREG(4f13f0, fn4f13f0);
