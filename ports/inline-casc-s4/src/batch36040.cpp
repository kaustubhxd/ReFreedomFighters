// batch36040.cpp - cascade s4 batch 36040: 0x51f7c0, 0x539780, 0x53b100, 0x5aa190, 0x5d79f0 (tier F rows).
#include "ff.h"

typedef void(THISCALL *v0_t)(void *);
typedef void(THISCALL *v1_t)(void *, u32);
typedef void(THISCALL *v2_t)(void *, u32, u32);
typedef u8 *(THISCALL *v0o_t)(void *);
typedef u8 *(THISCALL *v1o_t)(void *, u32);
typedef u8 *(THISCALL *v2o_t)(void *, u32, u32);
typedef u32(THISCALL *v0r_t)(void *);
typedef u32(THISCALL *v1r_t)(void *, u32);
typedef void (*hook_t)();

static inline u32 rd(u8 *p) { return *(u32 *)p; }
static inline void wr(u8 *p, u32 v) { *(u32 *)p = v; }

extern "C" u32 THISCALL ext_517f20(void *self, void *s);   // ret 4
extern "C" void THISCALL ext_5274a0(void *self, void *s);  // ret 4
extern "C" void THISCALL ext_513510(void *self, void *s);  // ret 4

// 0x51f7c0, thiscall(s) ret 4 returns al (this = d): 0x517f20(d, s) false -> 0. Reads from the stream s: slot 0x40 -> d + 0x1654; slot 0x40 -> id, d[0x1658] = sys[0x9b]->slot 0x58(id); 0x40 -> d + 0x165c;
// 0x6c -> d + 0x1660, d + 0x166c, d + 0x1678; 0x5274a0(d + 0x1684, s); slot 0x48 -> d + 0x16d5; 0x6c -> d + 0x16d9; 0x513510(d + 0x16e5, s); return 1.
static u8 THISCALL fn51f7c0(u8 *d, u8 *s) {
  if (!(u8)ext_517f20(d, s)) return 0;
  void **vt = *(void ***)s;
  ((v1_t)vt[0x40 / 4])(s, (u32)(d + 0x1654));
  u32 id = 0;
  ((v1_t)vt[0x40 / 4])(s, (u32)&id);
  u8 *tab = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  wr(d + 0x1658, (u32)(*(v1o_t **)tab)[0x58 / 4](tab, id));
  ((v1_t)vt[0x40 / 4])(s, (u32)(d + 0x165c));
  ((v1_t)vt[0x6c / 4])(s, (u32)(d + 0x1660));
  ((v1_t)vt[0x6c / 4])(s, (u32)(d + 0x166c));
  ((v1_t)vt[0x6c / 4])(s, (u32)(d + 0x1678));
  ext_5274a0(d + 0x1684, s);
  ((v1_t)vt[0x48 / 4])(s, (u32)(d + 0x16d5));
  ((v1_t)vt[0x6c / 4])(s, (u32)(d + 0x16d9));
  ext_513510(d + 0x16e5, s);
  return 1;
}
PCREG(51f7c0, fn51f7c0);

// 0x539780, thiscall() returns al (this = s): s[0x50ba] == 0 -> 0. p = s[0x51a9]; p == 0: logger(0x6a1e2c, 0x18c) prints 0x6a1e98 (cdecl), return 0.
// delta = p - s[0x51a5]; delta > (s32)s[0xd]: logger(0x195) prints 0x6a1ee0, delta; return 0. *p == 0x10000: s->slot 0x1a0(), return 1.
// otherwise logger(0x19d) prints 0x6a1f28, assert hook (int3 without one), s->slot 0x1a0(), return 1.
static u8 THISCALL fn539780(u8 *s) {
  if (s[0x50ba] == 0) return 0;
  u8 *p = *(u8 **)(s + 0x51a9);
  if (!p) {
    u8 *db = G(u8 *, 0x700390);
    u8 *lo = (*(v2o_t **)db)[0x20 / 4](db, 0x6a1e2cu, 0x18cu);
    void *fn = *(void **)((u8 *)*(void ***)lo + 0x2c);
    ((void (*)(u8 *, u32))fn)(lo, 0x6a1e98u);
    return 0;
  }
  s32 delta = (s32)((u32)p - rd(s + 0x51a5));
  if (delta > (s32)rd(s + 0xd)) {
    u8 *db = G(u8 *, 0x700390);
    u8 *lo = (*(v2o_t **)db)[0x20 / 4](db, 0x6a1e2cu, 0x195u);
    void *fn = *(void **)((u8 *)*(void ***)lo + 0x2c);
    ((void (*)(u8 *, u32, u32))fn)(lo, 0x6a1ee0u, (u32)delta);
    return 0;
  }
  if (rd(p) != 0x10000) {
    u8 *db = G(u8 *, 0x700390);
    u8 *lo = (*(v2o_t **)db)[0x20 / 4](db, 0x6a1e2cu, 0x19du);
    void *fn = *(void **)((u8 *)*(void ***)lo + 0x2c);
    ((void (*)(u8 *, u32))fn)(lo, 0x6a1f28u);
    hook_t h = G(hook_t, 0x7003b0);
    if (!h) __asm__ volatile("int3");
    h();
  }
  (*(v0_t **)s)[0x1a0 / 4](s);
  return 1;
}
PCREG(539780, fn539780);

extern "C" u32 THISCALL ext_53aa10(void *self, u32 a, u32 b);   // ret 8
extern "C" void THISCALL ext_53ac90(void *self, u32 a);         // ret 4
extern "C" void THISCALL ext_53aa80(void *self, u32 *out);      // ret 4

// 0x53b100, thiscall() plain ret (this = d): d[0x12] = 0x53aa10(d, d[0x12], 1); w = d[0x16] = 0x53aa10(d, d[0x16], 0); d[0xa] = 0; 0x53ac90(d, w); 0x53ac90(d, d[0x12]); d[0xa]++;
// 0x53aa80(d, &v); l = d[0]: v == sys[0x40]: l->slot 0xc(); return. l != 0: iterate l (slot 0x4c(&it), e = slot 0x64(&it) until 0): (s32)e[0x20] < (s32)v -> l->slot 0x44(&it) (remove).
static void THISCALL fn53b100(u8 *d) {
  wr(d + 0x12, ext_53aa10(d, rd(d + 0x12), 1));
  u32 w = ext_53aa10(d, rd(d + 0x16), 0);
  wr(d + 0x16, w);
  wr(d + 0xa, 0);
  ext_53ac90(d, w);
  ext_53ac90(d, rd(d + 0x12));
  wr(d + 0xa, rd(d + 0xa) + 1);
  u32 v = 0;
  ext_53aa80(d, &v);
  u8 *l = *(u8 **)d;
  if ((s32)v == (s32)rd(G(u8 *, 0x70039c) + 0x40)) {
    (*(v0_t **)l)[0xc / 4](l);
    return;
  }
  if (!l) return;
  u32 it[4];
  (*(v1_t **)l)[0x4c / 4](l, (u32)it);
  l = *(u8 **)d;
  u8 *e = (*(v1o_t **)l)[0x64 / 4](l, (u32)it);
  while (e) {
    if ((s32)rd(e + 0x20) < (s32)v) {
      l = *(u8 **)d;
      (*(v1_t **)l)[0x44 / 4](l, (u32)it);
    }
    l = *(u8 **)d;
    e = (*(v1o_t **)l)[0x64 / 4](l, (u32)it);
  }
}
PCREG(53b100, fn53b100);

extern "C" void *ext_41e290(u32 n);   // cdecl

// 0x5aa190, thiscall(s) ret 4 (this = d): s->slot 0x40(d) (reads the count d[0]); d[4] = malloc(d[0] * 4), d[8] = malloc(d[0] * 4) (saturating to -1 on overflow);
// for i < d[0]: s->slot 0x40(&id); d[4][i] = sys[0x9b]->slot 0x58(id); s->slot 0x40(&id); d[8][i] = sys[0x9b]->slot 0x58(id).
static void THISCALL fn5aa190(u8 *d, u8 *s) {
  (*(v1_t **)s)[0x40 / 4](s, (u32)d);
  u64 p1 = (u64)rd(d) * 4;
  wr(d + 4, (u32)ext_41e290((p1 >> 32) ? 0xffffffffu : (u32)p1));
  u64 p2 = (u64)rd(d) * 4;
  wr(d + 8, (u32)ext_41e290((p2 >> 32) ? 0xffffffffu : (u32)p2));
  u32 i = 0;
  if (rd(d) == 0) return;
  do {
    u32 *a = *(u32 **)(d + 4);
    u32 id1 = 0, id2 = 0;
    (*(v1_t **)s)[0x40 / 4](s, (u32)&id1);
    u8 *tab = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
    a[i] = (u32)(*(v1o_t **)tab)[0x58 / 4](tab, id1);
    u32 *b = *(u32 **)(d + 8);
    (*(v1_t **)s)[0x40 / 4](s, (u32)&id2);
    tab = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
    b[i] = (u32)(*(v1o_t **)tab)[0x58 / 4](tab, id2);
    i++;
  } while (i < rd(d));
}
PCREG(5aa190, fn5aa190);

extern "C" u32 FASTCALL ext_4cc850(u32 a, u32 b);   // 0 = match

// 0x5d79f0, thiscall() plain ret (this = d): tab = sys[0x9b]; d[0x1cd] = tab->slot 0x58(d[0x1de]); d[0x1d1] = tab->slot 0x58(d[0x1e2]); d[0x1c3] = (0x4cc850(tab->slot 0xb0(), 0x6b5dd4) == 0);
// o = tab->slot 0x58(d[0x1d6]): d[0x14e] = o ? o[0x18] : 0; o = tab->slot 0x58(d[0x1da]): d[0x152] = o ? o[0x18] : 0; d[0x156] = 0; G[0x7003a0][0x79] = 0;
// q = tab->slot 0x138(); x = tab->slot 0x4c(d[0x44], 0x10); q->slot 0x60(0x6b588c, x).
static void THISCALL fn5d79f0(u8 *d) {
  u8 *tab = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  wr(d + 0x1cd, (u32)(*(v1o_t **)tab)[0x58 / 4](tab, rd(d + 0x1de)));
  tab = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  wr(d + 0x1d1, (u32)(*(v1o_t **)tab)[0x58 / 4](tab, rd(d + 0x1e2)));
  tab = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  u32 a = (u32)(*(v0o_t **)tab)[0xb0 / 4](tab);
  d[0x1c3] = (ext_4cc850(a, 0x6b5dd4u) == 0);
  tab = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  u8 *o = (*(v1o_t **)tab)[0x58 / 4](tab, rd(d + 0x1d6));
  if (o) wr(d + 0x14e, rd(o + 0x18));
  else wr(d + 0x14e, 0);
  tab = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  o = (*(v1o_t **)tab)[0x58 / 4](tab, rd(d + 0x1da));
  if (o) wr(d + 0x152, rd(o + 0x18));
  else wr(d + 0x152, 0);
  wr(d + 0x156, 0);
  G(u8 *, 0x7003a0)[0x79] = 0;
  tab = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  u8 *q = (*(v0o_t **)tab)[0x138 / 4](tab);
  tab = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  u8 *x = (*(v2o_t **)tab)[0x4c / 4](tab, rd(d + 0x44), 0x10);
  (*(v2_t **)q)[0x60 / 4](q, 0x6b588cu, (u32)x);
}
PCREG(5d79f0, fn5d79f0);
