// batch36038.cpp - cascade s4 batch 36038: 0x5d4660, 0x5f5090, 0x615220, 0x64d7d0, 0x4055a0 (tier F rows).
#include "ff.h"

typedef void(THISCALL *v0_t)(void *);
typedef void(THISCALL *v1_t)(void *, u32);
typedef void(THISCALL *v2_t)(void *, u32, u32);
typedef void(THISCALL *v3_t)(void *, u32, u32, u32);
typedef u8 *(THISCALL *v0o_t)(void *);
typedef u8 *(THISCALL *v1o_t)(void *, u32);
typedef u8 *(THISCALL *v2o_t)(void *, u32, u32);
typedef u8 *(THISCALL *v3o_t)(void *, u32, u32, u32);
typedef u32(THISCALL *v7r_t)(void *, u32, u32, u32, u32, u32, u32, u32);
typedef void (*hook_t)();

static inline u32 rd(u8 *p) { return *(u32 *)p; }
static inline void wr(u8 *p, u32 v) { *(u32 *)p = v; }

// 0x615220, thiscall(p) ret 4: pool slot release like 0x616000 with record size 0x8c.
static void THISCALL fn615220(u8 *E, u8 *p) {
  wr(E + 0xc, rd(E + 0xc) - 1);
  u8 *b = (*(v1o_t **)E)[0x2c / 4](E, (u32)p);
  p[5] &= 0xfd;
  u16 cx = *(u16 *)(b + 2);
  b[0]--;
  *(u16 *)p = cx;
  s32 d = (s32)((u32)p - (u32)b) - 0x10;
  *(u16 *)(b + 2) = (u16)(d / 0x8c);
  if (b[0] == 0) {
    if (*(u8 **)(E + 8) == b) {
      u8 *n = *(u8 **)(b + 8);
      if (n == b) n = 0;
      *(u8 **)(E + 8) = n;
    }
    u8 *n1 = *(u8 **)(b + 8);
    wr(n1 + 0xc, rd(b + 0xc));
    u8 *n2 = *(u8 **)(b + 0xc);
    wr(n2 + 8, rd(b + 8));
    (*(v1_t **)E)[0x34 / 4](E, (u32)b);
    return;
  }
  if (b == *(u8 **)(E + 8)) return;
  u8 *n1 = *(u8 **)(b + 8);
  wr(n1 + 0xc, rd(b + 0xc));
  u8 *n2 = *(u8 **)(b + 0xc);
  wr(n2 + 8, rd(b + 8));
  u8 *head = *(u8 **)(E + 8);
  wr(b + 8, (u32)head);
  u8 *tail = *(u8 **)(head + 0xc);
  wr(b + 0xc, (u32)tail);
  wr(tail + 8, (u32)b);
  wr(head + 0xc, (u32)b);
  wr(E + 8, (u32)b);
}
PCREG(615220, fn615220);

// 0x64d7d0, thiscall(p) ret 4: the same with record size 0x78 and the bit cleared in p[9] instead of p[5].
static void THISCALL fn64d7d0(u8 *E, u8 *p) {
  wr(E + 0xc, rd(E + 0xc) - 1);
  u8 *b = (*(v1o_t **)E)[0x2c / 4](E, (u32)p);
  p[9] &= 0xfd;
  u16 cx = *(u16 *)(b + 2);
  b[0]--;
  *(u16 *)p = cx;
  s32 d = (s32)((u32)p - (u32)b) - 0x10;
  *(u16 *)(b + 2) = (u16)(d / 0x78);
  if (b[0] == 0) {
    if (*(u8 **)(E + 8) == b) {
      u8 *n = *(u8 **)(b + 8);
      if (n == b) n = 0;
      *(u8 **)(E + 8) = n;
    }
    u8 *n1 = *(u8 **)(b + 8);
    wr(n1 + 0xc, rd(b + 0xc));
    u8 *n2 = *(u8 **)(b + 0xc);
    wr(n2 + 8, rd(b + 8));
    (*(v1_t **)E)[0x34 / 4](E, (u32)b);
    return;
  }
  if (b == *(u8 **)(E + 8)) return;
  u8 *n1 = *(u8 **)(b + 8);
  wr(n1 + 0xc, rd(b + 0xc));
  u8 *n2 = *(u8 **)(b + 0xc);
  wr(n2 + 8, rd(b + 8));
  u8 *head = *(u8 **)(E + 8);
  wr(b + 8, (u32)head);
  u8 *tail = *(u8 **)(head + 0xc);
  wr(b + 0xc, (u32)tail);
  wr(tail + 8, (u32)b);
  wr(head + 0xc, (u32)b);
  wr(E + 8, (u32)b);
}
PCREG(64d7d0, fn64d7d0);

extern "C" void THISCALL ext_4de7a0(void *self);               // plain ret
extern "C" void THISCALL ext_4dc630(void *self, u32 a, u32 b);  // ret 8
extern "C" void THISCALL ext_4dbe30(void *self, u32 a);         // ret 4
extern "C" void THISCALL ext_4dc440(void *self, u32 a);         // ret 4

// 0x5d4660, thiscall() (this = s): when s[0x6b]: v = {0, 0, 0}; blk (a 3x3 matrix, 0x24 bytes) set by 0x4de7a0; o = s[0x6b]->slot 0x1bc(sys[0x9b][0xadc], blk, v, 0, 0, 0, 0); s[0x48] = o;
// 0x4dc630(o[8], 0x2008000, 0); o->slot 0x2c(); o->slot 0xbc(0); 0x4dbe30(o[8], 1); 0x4dc440(o[8], 1); o->slot 0x234(0xff0000); o->slot 0x23c(100.0f); o->slot 0x240(500.0f).
static void THISCALL fn5d4660(u8 *s) {
  u8 *list = *(u8 **)(s + 0x6b);
  if (!list) return;
  u32 blk[9];
  u32 v[3] = {0, 0, 0};
  ext_4de7a0(blk);
  u8 *tab = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  u8 *o = (u8 *)(*(v7r_t **)list)[0x1bc / 4](list, rd(tab + 0xadc), (u32)blk, (u32)v, 0, 0, 0, 0);
  wr(s + 0x48, (u32)o);
  ext_4dc630(*(u8 **)(o + 8), 0x2008000u, 0);
  o = *(u8 **)(s + 0x48);
  (*(v0_t **)o)[0x2c / 4](o);
  o = *(u8 **)(s + 0x48);
  (*(v1_t **)o)[0xbc / 4](o, 0);
  ext_4dbe30(*(u8 **)(*(u8 **)(s + 0x48) + 8), 1);
  ext_4dc440(*(u8 **)(*(u8 **)(s + 0x48) + 8), 1);
  o = *(u8 **)(s + 0x48);
  (*(v1_t **)o)[0x234 / 4](o, 0xff0000u);
  o = *(u8 **)(s + 0x48);
  (*(v1_t **)o)[0x23c / 4](o, 0x42c80000u);
  o = *(u8 **)(s + 0x48);
  (*(v1_t **)o)[0x240 / 4](o, 0x43fa0000u);
}
PCREG(5d4660, fn5d4660);

extern "C" u8 *THISCALL ext_6000b0(void *self, u32 a);   // ret 4

// 0x5f5090, thiscall(a, b) ret 8 returns eax (this = s): t = [0x724270]; r = t->slot 0x38(s, a, b); r == 0: x = 0x6000b0(s[4][0x96], a); x == 0 -> return 0;
// t2 = [0x724270]; n = t2->slot 0x38(s, 0x6b87b0, x[8]); n == 0: logger(0x6b8a64, 0x284) prints (cdecl 3 args) 0x69c6b0, 0x6b8b9c, assert hook, return 0 (int3 when no hook).
// else n->slot 0x48(b_saved = x, s[4]); r = n. Then r[8] = s; return r.
static u32 THISCALL fn5f5090(u8 *s, u32 a, u32 b) {
  u8 *t = G(u8 *, 0x724270);
  u8 *r = (*(v3o_t **)t)[0x38 / 4](t, (u32)s, a, b);
  if (!r) {
    u8 *x = ext_6000b0(*(u8 **)(*(u8 **)(s + 4) + 0x96), a);
    if (!x) return 0;
    t = G(u8 *, 0x724270);
    u8 *n = (*(v3o_t **)t)[0x38 / 4](t, (u32)s, 0x6b87b0u, rd(x + 8));
    if (!n) {
      u8 *db = G(u8 *, 0x700390);
      u8 *lo = (*(v2o_t **)db)[0x20 / 4](db, 0x6b8a64u, 0x284u);
      void *fn = *(void **)((u8 *)*(void ***)lo + 0x2c);
      ((void (*)(u8 *, u32, u32))fn)(lo, 0x69c6b0u, 0x6b8b9cu);
      hook_t h = G(hook_t, 0x7003b0);
      if (!h) __asm__ volatile("int3");
      h();
      return 0;
    }
    (*(v2_t **)n)[0x48 / 4](n, (u32)x, rd(s + 4));
    r = n;
  }
  wr(r + 8, (u32)s);
  return (u32)r;
}
PCREG(5f5090, fn5f5090);

extern "C" void ext_634d52(void *p);   // cdecl (free)

// 0x4055a0, cdecl(p): p[0x30] == 0: return. Frees p[0x20] and p[8] when set. q = p[0x24] when set: free(q[0]), free(q[1]), free(q[2]), free(q[3]), zero the 6 dwords at q, free(q).
// r = p[0x28] when set: free(r[0]), free(r[1]), zero r[0..3], free(r). Finally zero the 13 dwords at p.
static void fn4055a0(u8 *p) {
  if (rd(p + 0x30) == 0) return;
  if (rd(p + 0x20)) ext_634d52(*(void **)(p + 0x20));
  if (rd(p + 8)) ext_634d52(*(void **)(p + 8));
  u8 *q = *(u8 **)(p + 0x24);
  if (q) {
    ext_634d52(*(void **)q);
    ext_634d52(*(void **)(*(u8 **)(p + 0x24) + 4));
    ext_634d52(*(void **)(*(u8 **)(p + 0x24) + 8));
    ext_634d52(*(void **)(*(u8 **)(p + 0x24) + 0xc));
    u32 *z = *(u32 **)(p + 0x24);
    for (int i = 0; i < 6; i++) z[i] = 0;
    ext_634d52(*(void **)(p + 0x24));
  }
  u8 *r = *(u8 **)(p + 0x28);
  if (r) {
    ext_634d52(*(void **)r);
    ext_634d52(*(void **)(*(u8 **)(p + 0x28) + 4));
    u8 *r2 = *(u8 **)(p + 0x28);
    wr(r2, 0);
    wr(r2 + 4, 0);
    wr(r2 + 8, 0);
    wr(r2 + 0xc, 0);
    ext_634d52(*(void **)(p + 0x28));
  }
  u32 *w = (u32 *)p;
  for (int i = 0; i < 13; i++) w[i] = 0;
}
PCREG(4055a0, fn4055a0);
