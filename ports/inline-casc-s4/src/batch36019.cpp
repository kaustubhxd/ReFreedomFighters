// batch36019.cpp - cascade s4 batch 36019: 0x4c2040, 0x4d2a90, 0x4f0d70, 0x536270, 0x4f7620 (tier F rows).
#include "ff.h"

typedef void(THISCALL *v1_t)(void *, u32);
typedef void(THISCALL *v2_t)(void *, u32, u32);
typedef void(THISCALL *v3_t)(void *, u32, u32, u32);
typedef void(THISCALL *v5_t)(void *, u32, u32, u32, u32, u32);
typedef u32(THISCALL *v1u_t)(void *, u32);
typedef u8 *(THISCALL *v0o_t)(void *);
typedef u8 *(THISCALL *v2o_t)(void *, u32, u32);
typedef void(THISCALL *v0_t)(void *);
typedef u32 (*hook_t)();

static inline u32 rd(u8 *p) { return *(u32 *)p; }
static inline void wr(u8 *p, u32 v) { *(u32 *)p = v; }
static inline void sl(u8 *s, u32 off, u8 *dst) { (*(v1_t **)s)[off / 4](s, (u32)dst); }

extern "C" void THISCALL ext_4c0a90(void *self, u32 a);  // ret 4

// 0x4c2040, thiscall(s) ret 4, returns 1 (this = E): E[4] &= ~0x40; s: slot 0x68 -> +0x1b9, +0x1ba; slot 0x50 -> +0x1c7; slot 0x40 -> +0x1cb, +0x1cf; slot 0x44 -> +0x1b1, +0x1b3, +0x1b5, +0x1b7;
// then the assert hook (int3 when null) and 0x4c0a90(E, 0).
static u8 THISCALL fn4c2040(u8 *E, u8 *s) {
  wr(E + 4, rd(E + 4) & 0xffffffbfu);
  sl(s, 0x68, E + 0x1b9);
  sl(s, 0x68, E + 0x1ba);
  sl(s, 0x50, E + 0x1c7);
  sl(s, 0x40, E + 0x1cb);
  sl(s, 0x40, E + 0x1cf);
  sl(s, 0x44, E + 0x1b1);
  sl(s, 0x44, E + 0x1b3);
  sl(s, 0x44, E + 0x1b5);
  sl(s, 0x44, E + 0x1b7);
  hook_t h = G(hook_t, 0x7003b0);
  if (!h) __asm__ volatile("int3");
  h();
  ext_4c0a90(E, 0);
  return 1;
}
PCREG(4c2040, fn4c2040);

typedef int(*memicmp_t)(const void *, const void *, u32);

// 0x4d2a90, thiscall(name, len) ret 8, returns bool (this = E): len == 0 -> strlen(name) + 1; c = E + 0x4008: c->slot 0x4c(&loc); r = c->slot 0x5c(&loc);
// while loc != 0: r[0] == len and _memicmp(name, r + 0xc, len) == 0 returns 1; r = c->slot 0x5c(&loc). Returns 0.
static u8 THISCALL fn4d2a90(u8 *E, const u8 *name, u32 len) {
  u32 loc[3];
  if (len == 0) {
    u32 n = 0;
    while (name[n]) n++;
    len = n + 1;
  }
  u8 *c = E + 0x4008;
  (*(v1_t **)c)[0x4c / 4](c, (u32)loc);
  u8 *r = (u8 *)(*(v1u_t **)c)[0x5c / 4](c, (u32)loc);
  if (loc[0] == 0) return 0;
  do {
    if (rd(r) == len) {
      if (G(memicmp_t, 0x67640c)(name, r + 0xc, len) == 0) return 1;
    }
    r = (u8 *)(*(v1u_t **)c)[0x5c / 4](c, (u32)loc);
  } while (loc[0] != 0);
  return 0;
}
PCREG(4d2a90, fn4d2a90);

extern "C" void THISCALL ext_45f960(void *self, void *s);  // ret 4

// 0x4f0d70, thiscall(s) ret 4, returns 1 (this = E): 0x45f960(E, s); E[0x18] = (E[0x18] & 0xffffff) | (E[0x8e] << 24); s->slot 0x3c(E[0x18]); s->slot 0x3c(E[0x1c]);
// s->slot 0x10(E+0x20, 1), (E+0x21, 1), (E+0x22, 8), (E+0x3e, 8); b = (E[0x91] << 4) | E[0x8f]; s->slot 0x10(&b, 1); E->slot 0x234(s).
static u8 THISCALL fn4f0d70(u8 *E, u8 *s) {
  ext_45f960(E, s);
  u32 v = (rd(E + 0x18) & 0xffffffu) | ((u32)E[0x8e] << 24);
  wr(E + 0x18, v);
  (*(v1_t **)s)[0x3c / 4](s, v);
  (*(v1_t **)s)[0x3c / 4](s, rd(E + 0x1c));
  (*(v2_t **)s)[0x10 / 4](s, (u32)(E + 0x20), 1);
  (*(v2_t **)s)[0x10 / 4](s, (u32)(E + 0x21), 1);
  (*(v2_t **)s)[0x10 / 4](s, (u32)(E + 0x22), 8);
  (*(v2_t **)s)[0x10 / 4](s, (u32)(E + 0x3e), 8);
  u8 b = (u8)((u8)(E[0x91] << 4) | E[0x8f]);
  (*(v2_t **)s)[0x10 / 4](s, (u32)&b, 1);
  (*(v1_t **)E)[0x234 / 4](E, (u32)s);
  return 1;
}
PCREG(4f0d70, fn4f0d70);

// 0x536270, thiscall(no args) (this = E): logs (0x6a1e2c, 0x2aa, 0x6a200c); r = E[0x5302] (unaligned) + *E[0x5302]; six E->slot 0x1b4(r[0x18+4k], r[4k], fmt_k) calls with
// fmt 0x692b64, 0x679a14, 0x6a2030, 0x679a08, 0x6a203c, 0x6a2050; logs (0x6a1e2c, 0x2b2, 0x6a200c).
static inline void log1(u32 file, u32 line, u32 fmt) {
  u8 *db = G(u8 *, 0x700390);
  u8 *o = (*(v2o_t **)db)[0x20 / 4](db, file, line);
  void **vt2 = *(void ***)o;
  void *fn = *(void **)((u8 *)vt2 + 0x2c);
  __asm__ volatile("pushl %[f2]\n\tpushl %[o]\n\tcall *%[f]\n\taddl $8, %%esp"
                   : "+c"(vt2) : [f2] "r"(fmt), [o] "r"(o), [f] "r"(fn) : "eax", "edx", "memory", "cc");
}
static void THISCALL fn536270(u8 *E) {
  log1(0x6a1e2c, 0x2aa, 0x6a200c);
  u8 *base = *(u8 **)(E + 0x5302);
  u8 *r = base + rd(base);
  static const u32 fmts[6] = {0x692b64, 0x679a14, 0x6a2030, 0x679a08, 0x6a203c, 0x6a2050};
  for (u32 k = 0; k < 6; k++) (*(v3_t **)E)[0x1b4 / 4](E, rd(r + 0x18 + 4 * k), rd(r + 4 * k), fmts[k]);
  log1(0x6a1e2c, 0x2b2, 0x6a200c);
}
PCREG(536270, fn536270);

// 0x4f7620, thiscall(a) ret 4 (this = E): E[0x8f] (unaligned) non-null: x = E->slot 0x2c4(); y = tab->slot 0x4c(E[0x8f]); x->slot 0x350(0x80000, y, E).
// E[0x8f] = a; a non-null: y2 = tab->slot 0x4c(E); a->slot 0x2e8(y2); x2 = E->slot 0x2c4(); y3 = tab->slot 0x4c(E[0x8f]); x2->slot 0x34c(0x80000, y3, E, 0x41200000, 1). Finally E->slot 0x370().
static void THISCALL fn4f7620(u8 *E, u8 *a) {
  u8 *tab;
  if (rd(E + 0x8f) != 0) {
    u8 *x = (*(v0o_t **)E)[0x2c4 / 4](E);
    tab = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
    u32 y = (*(v1u_t **)tab)[0x4c / 4](tab, rd(E + 0x8f));
    (*(v3_t **)x)[0x350 / 4](x, 0x80000, y, (u32)E);
  }
  wr(E + 0x8f, (u32)a);
  if (a) {
    void **avt = *(void ***)a;
    tab = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
    u32 y2 = (*(v1u_t **)tab)[0x4c / 4](tab, (u32)E);
    ((v1_t)avt[0x2e8 / 4])(a, y2);
    u8 *x2 = (*(v0o_t **)E)[0x2c4 / 4](E);
    tab = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
    u32 y3 = (*(v1u_t **)tab)[0x4c / 4](tab, rd(E + 0x8f));
    (*(v5_t **)x2)[0x34c / 4](x2, 0x80000, y3, (u32)E, 0x41200000, 1);
  }
  (*(v0_t **)E)[0x370 / 4](E);
}
PCREG(4f7620, fn4f7620);
