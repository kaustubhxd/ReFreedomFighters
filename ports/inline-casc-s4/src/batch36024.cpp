// batch36024.cpp - cascade s4 batch 36024: 0x63f220, 0x64f760, 0x41f7f0, 0x46b760, 0x44cd90 (tier F rows).
#include "ff.h"

typedef void(THISCALL *v0_t)(void *);
typedef void(THISCALL *v1_t)(void *, u32);
typedef void(THISCALL *v2_t)(void *, u32, u32);
typedef u32(THISCALL *v0u_t)(void *);
typedef u32(THISCALL *v1u_t)(void *, u32);
typedef u32(THISCALL *v2u_t)(void *, u32, u32);
typedef u8 *(THISCALL *v0o_t)(void *);
typedef u8 *(THISCALL *v1o_t)(void *, u32);
typedef u32 (*hook_t)();

static inline u32 rd(u8 *p) { return *(u32 *)p; }
static inline void wr(u8 *p, u32 v) { *(u32 *)p = v; }
static inline u8 *tabOf() { return *(u8 **)(G(u8 *, 0x70039c) + 0x9b); }

extern "C" void THISCALL ext_63ef90(void *self, void *node);              // ret 4
extern "C" void THISCALL ext_4db6c0(void *self, u32 a, u32 b);            // ret 8
extern "C" u32 THISCALL ext_4ce7b0(void *self);                           // plain ret

// 0x63f220, thiscall(a) ret 4, returns the node (this = E): idx = u16 a[0x5a]; non-zero: node = E[0x68][idx & 0xfff]; node[5] & 1 returns it, else 0x63ef90(E, node) and returns it.
// Zero: node = E[0x230]->slot 8(); null returns 0. node[0x38] = a; 0x4db6c0(a, node+8, node+0x2c); n = (0x4ce7b0(E+0xb990) + 1) & 0xfff (zero: assert hook);
// E[0x68][n] = node; a[0x5a] = (u16)n; 0x63ef90(E, node); returns node.
static u8 *THISCALL fn63f220(u8 *E, u8 *a) {
  u16 idx16 = *(u16 *)(a + 0x5a);
  u8 *node;
  if (idx16 != 0) {
    node = ((u8 **)rd(E + 0x68))[idx16 & 0xfffu];
    if (node[5] & 1) return node;
    ext_63ef90(E, node);
    return node;
  }
  u8 *pool = *(u8 **)(E + 0x230);
  node = (*(v0o_t **)pool)[8 / 4](pool);
  if (!node) return 0;
  wr(node + 0x38, (u32)a);
  ext_4db6c0(a, (u32)(node + 8), (u32)(node + 0x2c));
  u32 n = (ext_4ce7b0(E + 0xb990) + 1) & 0xfffu;
  if (n == 0) {
    hook_t h = G(hook_t, 0x7003b0);
    if (!h) __asm__ volatile("int3");
    else h();
  }
  ((u8 **)rd(E + 0x68))[n] = node;
  *(u16 *)(a + 0x5a) = (u16)n;
  ext_63ef90(E, node);
  return node;
}
PCREG(63f220, fn63f220);

extern "C" void THISCALL ext_64f6a0(void *self, u32 a);  // ret 4

// 0x64f760, thiscall(no args) (this = E): g = [0x70038c]; x = g->slot 0x48(0xff60a0); E->slot 0x3c(); c = E[0xbd] (unaligned): c[5] == 0: c->slot 8(); E->slot 0xa4(0) == 0 and l = E[0x8c] non-null:
// l->slot 0x4c(&loc); r = l->slot 0x5c(&loc); while loc != 0: t = tab->slot 0x58(r); t: 0x64f6a0(E, t); r = l->slot 0x5c(&loc). Finally [0x70038c]->slot 0x48(x).
static void THISCALL fn64f760(u8 *E) {
  u32 loc[3];
  u8 *g = G(u8 *, 0x70038c);
  u32 x = (*(v1u_t **)g)[0x48 / 4](g, 0xff60a0u);
  (*(v0_t **)E)[0x3c / 4](E);
  u8 *c = *(u8 **)(E + 0xbd);
  if (c[5] == 0) {
    (*(v0_t **)c)[8 / 4](c);
    u32 r0 = (*(v1u_t **)E)[0xa4 / 4](E, 0);
    if (r0 == 0) {
      u8 *l = *(u8 **)(E + 0x8c);
      if (l) {
        (*(v1_t **)l)[0x4c / 4](l, (u32)loc);
        u32 r = (*(v1u_t **)l)[0x5c / 4](l, (u32)loc);
        if (loc[0] != 0) {
          do {
            u8 *tab = tabOf();
            u8 *t = (*(v1o_t **)tab)[0x58 / 4](tab, r);
            if (t) ext_64f6a0(E, (u32)t);
            r = (*(v1u_t **)l)[0x5c / 4](l, (u32)loc);
          } while (loc[0] != 0);
        }
      }
    }
  }
  g = G(u8 *, 0x70038c);
  (*(v1_t **)g)[0x48 / 4](g, x);
}
PCREG(64f760, fn64f760);

typedef void *(*malloc_t)(u32);
extern "C" void *memset_634d10(void *, int, u32) asm("ext_634d10");
extern "C" u8 *THISCALL ext_4d0700(void *self, u32 a);   // ret 4
extern "C" void THISCALL ext_41f190(void *self, u32 a);  // ret 4

// 0x41f7f0, thiscall(sz) ret 4, returns the data pointer (this = E): E->slot 0xec(); E[0x30] zero: p = malloc(sz + 0x24), p[0x18] = sz | 0x80000000; else p = 0x4d0700(E[0x31], sz + 0x24), p[0x18] = sz | 0xc0000000.
// p[4] = E[0x1c]; p[0] = 0; E[0x1c] ? E[0x1c][0] = p : E[0x18] = p; E[0x1c] = p; memset(p + 0x20, 0xed, sz); *(p + 0x20 + sz) = 0x87654321; p[0xc] = p[8] = 0; p[0x14] = 1; p[0x1c] = 0;
// 0x41f190(E, p + 0x20); p[4] non-null: 0x41f190(E, p[4] + 0x20); E->slot 0xe8(); returns p + 0x20.
static u8 *THISCALL fn41f7f0(u8 *E, u32 sz) {
  (*(v0_t **)E)[0xec / 4](E);
  u8 *p;
  if (E[0x30] == 0) {
    p = (u8 *)G(malloc_t, 0x6762f0)(sz + 0x24);
    wr(p + 0x18, sz | 0x80000000u);
  } else {
    p = ext_4d0700(*(u8 **)(E + 0x31), sz + 0x24);
    wr(p + 0x18, sz | 0xc0000000u);
  }
  wr(p + 4, rd(E + 0x1c));
  wr(p, 0);
  u8 *tail = *(u8 **)(E + 0x1c);
  if (tail) wr(tail, (u32)p);
  else wr(E + 0x18, (u32)p);
  wr(E + 0x1c, (u32)p);
  memset_634d10(p + 0x20, 0xed, sz);
  wr(p + sz + 0x20, 0x87654321u);
  u8 *data = p + 0x20;
  wr(p + 0xc, 0);
  wr(p + 8, 0);
  wr(p + 0x14, 1);
  wr(p + 0x1c, 0);
  ext_41f190(E, (u32)data);
  u8 *prev = *(u8 **)(p + 4);
  if (prev) ext_41f190(E, (u32)(prev + 0x20));
  (*(v0_t **)E)[0xe8 / 4](E);
  return data;
}
PCREG(41f7f0, fn41f7f0);

typedef int(*stricmp_t)(const char *, const char *);

// 0x46b760, thiscall(key, name) ret 8, returns bool (this = E): c = E[0x70] null -> 0; c->slot 0x4c(&loc); r = c->slot 0x64(&loc); for each r (null ends -> 0): r[0] == key and (name == 0, or the engine object
// for r[4] (tab slot 0x58) has a name (obj[4] or 0x67c8e8) equal to name (_stricmp) -> 1; a missing object moves on to the next element.
static u8 THISCALL fn46b760(u8 *E, u32 key, const char *name) {
  u32 loc[3];
  u8 *c = *(u8 **)(E + 0x70);
  if (!c) return 0;
  (*(v1_t **)c)[0x4c / 4](c, (u32)loc);
  c = *(u8 **)(E + 0x70);
  u8 *r = (*(v1o_t **)c)[0x64 / 4](c, (u32)loc);
  if (!r) return 0;
  do {
    if (rd(r) == key) {
      if (!name) return 1;
      u8 *tab = tabOf();
      u8 *o = (*(v1o_t **)tab)[0x58 / 4](tab, rd(r + 4));
      if (o) {
        u32 nm = rd(o + 4);
        const char *s = (const char *)(nm ? nm : 0x67c8e8u);
        if (G(stricmp_t, 0x676414)(name, s) == 0) return 1;
      }
    }
    c = *(u8 **)(E + 0x70);
    r = (*(v1o_t **)c)[0x64 / 4](c, (u32)loc);
  } while (r);
  return 0;
}
PCREG(46b760, fn46b760);

// 0x44cd90, thiscall(no args) (this = E): x = tab->slot 0x138(); n = tab->slot 0x50(E[8], 0x10); x->slot 0x60(0x680a44, n); builds four linked entries inside E:
// E[0x20] = E+0x28, E[0x28] = E+0x38, E[0x20][4/8/0xc] = E+0x58 / +0x78 / +0x98, and per entry e (E+0x38, +0x58, +0x78, +0x98): e[0x18] = 0, e[0x1c] = E+0x118/0x238/0x358/0x478, e[0x14] = E+0x598/0x7d8/0xa18/0xc58; E[0x24] = 0.
static void THISCALL fn44cd90(u8 *E) {
  u8 *tab = tabOf();
  u8 *x = (*(v0o_t **)tab)[0x138 / 4](tab);
  void **xvt = *(void ***)x;
  tab = tabOf();
  u32 n = (*(v2u_t **)tab)[0x50 / 4](tab, rd(E + 8), 0x10);
  ((v2_t)xvt[0x60 / 4])(x, 0x680a44, n);
  wr(E + 0x20, (u32)(E + 0x28));
  wr(E + 0x28, (u32)(E + 0x38));
  u8 *e0 = E + 0x38;
  wr(e0 + 0x1c, (u32)(E + 0x118));
  wr(e0 + 0x14, (u32)(E + 0x598));
  wr(e0 + 0x18, 0);
  static const u16 eo[3] = {0x58, 0x78, 0x98};
  static const u16 lo[3] = {0x238, 0x358, 0x478};
  static const u16 po[3] = {0x7d8, 0xa18, 0xc58};
  for (int k = 0; k < 3; k++) {
    u8 *e = E + eo[k];
    u8 *tbl = *(u8 **)(E + 0x20);
    wr(tbl + 4 * (k + 1), (u32)e);
    wr(e + 0x18, 0);
    wr(e + 0x1c, (u32)(E + lo[k]));
    wr(e + 0x14, (u32)(E + po[k]));
  }
  wr(E + 0x24, 0);
}
PCREG(44cd90, fn44cd90);
