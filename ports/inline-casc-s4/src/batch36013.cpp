// batch36013.cpp - cascade s4 batch 36013: 0x5aee60, 0x5ed0b0, 0x403ee0, 0x427320, 0x57f750 (tier F rows).
#include "ff.h"

typedef void(THISCALL *v1_t)(void *, u32);
typedef u32(THISCALL *v0r_t)(void *);
typedef u32(THISCALL *v1u_t)(void *, u32);
typedef u8(THISCALL *v0b_t)(void *);
typedef u8 *(THISCALL *v1o_t)(void *, u32);
typedef u8 *(THISCALL *v0o_t)(void *);
typedef u8 *(THISCALL *v2o_t)(void *, u32, u32);
typedef u32(THISCALL *v2o_t2)(void *, u32, u32);
typedef void(THISCALL *v2_t)(void *, u32, u32);

static inline u32 rd(u8 *p) { return *(u32 *)p; }
static inline void wr(u8 *p, u32 v) { *(u32 *)p = v; }

// 0x5aee60, thiscall(id) ret 4 (this = E): t = [[0x70039c]+0x9b]; o = t->slot 0x58(id); n = o[0x18]->slot 0x14(); for i in 0..n-1 (signed): r = o[0x18]->slot 0x30(i);
// c = t->slot 0x58(r); p = c->slot 0x100(0x6b0f30); when p: x = p+0x48; E[0] < 0x14 and x not already among E[1..E[0]] -> E[1+E[0]] = x, E[0]++.
static void THISCALL fn5aee60(u8 *E, u32 id) {
  u8 *t = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  u8 *o = (*(v1o_t **)t)[0x58 / 4](t, id);
  u8 *lst = *(u8 **)(o + 0x18);
  s32 n = (s32)(*(v0r_t **)lst)[0x14 / 4](lst);
  if (n <= 0) return;
  for (s32 i = 0; i < n; i++) {
    u8 *t1 = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
    void **vt = *(void ***)t1;
    lst = *(u8 **)(o + 0x18);
    u32 r = (*(v1u_t **)lst)[0x30 / 4](lst, (u32)i);
    t1 = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
    u8 *c = ((v1o_t)vt[0x58 / 4])(t1, r);
    u8 *p = (*(v1o_t **)c)[0x100 / 4](c, 0x6b0f30u);
    if (!p) continue;
    u8 *x = p + 0x48;
    u32 cnt = rd(E);
    if (cnt >= 0x14) continue;
    bool dup = false;
    for (u32 k = 0; k < cnt; k++)
      if (*(u8 **)(E + 4 + 4 * k) == x) { dup = true; break; }
    if (dup) continue;
    wr(E + 4 + 4 * cnt, (u32)x);
    wr(E, rd(E) + 1);
  }
}
PCREG(5aee60, fn5aee60);

extern "C" void THISCALL ext_5ebf10(void *self, void *s);                  // ret 4
extern "C" u8 *ext_41e290(u32 size);                                       // cdecl
extern "C" void THISCALL ext_5fe3b0(void *self, u32 where, u32 *item);     // ret 8

// 0x5ed0b0, thiscall(s) ret 4 (this = E): 0x5ebf10(E, s); s->slot 0x6c(E+0xa7); E[0xbb] = E[0xb7] = E[0xb3] = E[0xc3] = 0; E[0xa6] = 1; E[0xbf] = 0x41200000;
// s->slot 0x40(&n); for i < n: p = alloc(0x10); s->slot 0x18(p, 0x10); vec = E+0xcb: vec[4] != vec[8]: store p at vec[4] when non-null, vec[4] += 4; else 0x5fe3b0(vec, vec[4], &p).
static void THISCALL fn5ed0b0(u8 *E, u8 *s) {
  u32 n;
  ext_5ebf10(E, s);
  (*(v1_t **)s)[0x6c / 4](s, (u32)(E + 0xa7));
  wr(E + 0xbb, 0);
  wr(E + 0xb7, 0);
  wr(E + 0xb3, 0);
  wr(E + 0xc3, 0);
  E[0xa6] = 1;
  wr(E + 0xbf, 0x41200000);
  (*(v1_t **)s)[0x40 / 4](s, (u32)&n);
  u8 *vec = E + 0xcb;
  for (u32 i = 0; i < n; i++) {
    u32 p = (u32)ext_41e290(0x10);
    (*(v2_t **)s)[0x18 / 4](s, p, 0x10);
    u32 cur = rd(vec + 4);
    if (cur == rd(vec + 8)) {
      ext_5fe3b0(vec, cur, &p);
    } else {
      if (cur) wr((u8 *)cur, p);
      wr(vec + 4, rd(vec + 4) + 4);
    }
  }
}
PCREG(5ed0b0, fn5ed0b0);

extern "C" void ext_634d52(u32 p);  // free, cdecl

// 0x403ee0, cdecl(p): p null returns. free(p[0x14], p[0x18], p[0x1c]) each when non-null. p[8] non-null: for ei in 0..16: for j in 0..10: free(((u32 *)p[8][ei])[j]); free(p[8][ei]); then free(p[8]).
// Then free(p[0x10]), free(p[0xc]) and clears 13 dwords at p.
static void fn403ee0(u8 *p) {
  if (!p) return;
  if (rd(p + 0x14)) ext_634d52(rd(p + 0x14));
  if (rd(p + 0x18)) ext_634d52(rd(p + 0x18));
  if (rd(p + 0x1c)) ext_634d52(rd(p + 0x1c));
  if (rd(p + 8)) {
    for (s32 ei = 0; ei < 0x44; ei += 4) {
      for (s32 j = 0; j < 0x2c; j += 4) ext_634d52(*(u32 *)(*(u8 **)(*(u8 **)(p + 8) + ei) + j));
      ext_634d52(*(u32 *)(*(u8 **)(p + 8) + ei));
    }
    ext_634d52(rd(p + 8));
  }
  ext_634d52(rd(p + 0x10));
  ext_634d52(rd(p + 0xc));
  for (int k = 0; k < 13; k++) ((u32 *)p)[k] = 0;
}
PCREG(403ee0, fn403ee0);

typedef u32(STDCALL *gfs_t)(u32, u32);

// 0x427320, thiscall(a, flag) ret 8 (this = E): flag byte zero: b = E->slot 0x130(a); o = E->slot 0x70(b); o: v = o->slot 0x10(b); v != -1 returns v.
// Then h = E->slot 8(a); null returns -1; sz = GetFileSize(h, 0); -1: log (db slot 0x20(0x6789ac, 0xb5), o->slot 0x2c(o, 0x678af8) cdecl); E->slot 0x1c(h); returns sz.
static u32 THISCALL fn427320(u8 *E, u32 a, u32 flag) {
  if (!(u8)flag) {
    u32 b = (*(v1u_t **)E)[0x130 / 4](E, a);
    u8 *o = (*(v1o_t **)E)[0x70 / 4](E, b);
    if (o) {
      u32 v = (*(v1u_t **)o)[0x10 / 4](o, b);
      if (v != 0xffffffffu) return v;
    }
  }
  u32 h = (*(v1u_t **)E)[8 / 4](E, a);
  if (!h) return 0xffffffffu;
  u32 sz = G(gfs_t, 0x67608c)(h, 0);
  if (sz == 0xffffffffu) {
    u8 *db = G(u8 *, 0x700390);
    u8 *o = (*(v2o_t **)db)[0x20 / 4](db, 0x6789acu, 0xb5u);
    void **vt2 = *(void ***)o;
    void *fn = *(void **)((u8 *)vt2 + 0x2c);
    __asm__ volatile("pushl %[s]\n\tpushl %[o]\n\tcall *%[f]\n\taddl $8, %%esp"
                     : "+c"(vt2)
                     : [s] "i"(0x678af8), [o] "r"(o), [f] "r"(fn)
                     : "eax", "edx", "memory", "cc");
  }
  (*(v1_t **)E)[0x1c / 4](E, h);
  return sz;
}
PCREG(427320, fn427320);

extern "C" void THISCALL ext_563710(void *self, u32 a, const char *b);  // ret 8
typedef void (*cdecl5_t)(void *, char *, u32, u32, u32);

// 0x57f750, thiscall(no args) (this = E): eng = [0x70039c]; o = [eng+0x9b][0xae4]; r1 = o->slot 0(0x6a67e8, 0x67a018); b = eng->slot 0xbc()->slot 0xb8();
// r2 = o->slot 0(0x6a67e8, b ? 0x6a7c24 : 0x6a7c28); y = eng->slot 0x190(); y->slot 0x198 cdecl (y, buf, 0x6965cc, r1, r2); 0x563710(E, E[0x184], buf).
static void THISCALL fn57f750(u8 *E) {
  char buf[0x104];
  u8 *eng = G(u8 *, 0x70039c);
  u8 *o = *(u8 **)(*(u8 **)(eng + 0x9b) + 0xae4);
  u32 r1 = (*(v2o_t2 **)o)[0](o, 0x6a67e8u, 0x67a018u);
  eng = G(u8 *, 0x70039c);
  u8 *w = (*(v0o_t **)eng)[0xbc / 4](eng);
  u8 b = (*(v0b_t **)w)[0xb8 / 4](w);
  eng = G(u8 *, 0x70039c);
  o = *(u8 **)(*(u8 **)(eng + 0x9b) + 0xae4);
  u32 r2 = (*(v2o_t2 **)o)[0](o, 0x6a67e8u, b ? 0x6a7c24u : 0x6a7c28u);
  eng = G(u8 *, 0x70039c);
  u8 *y = (*(v0o_t **)eng)[0x190 / 4](eng);
  void *fn = *(void **)((u8 *)*(void ***)y + 0x198);
  ((cdecl5_t)fn)(y, buf, 0x6965ccu, r1, r2);
  ext_563710(E, rd(E + 0x184), buf);
}
PCREG(57f750, fn57f750);
