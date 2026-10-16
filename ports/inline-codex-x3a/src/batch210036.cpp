// batch210036.cpp - Sonnet-w3a: small BLOCKED rows (tag-checked reader, string lookup copy, vector copy chain)
#include "ff.h"

extern "C" u32 THISCALL ext_4e1590(u8 *self);
extern "C" u32 THISCALL ext_512590(u8 *self);

static inline void st32(u8 *p, u32 v) { __builtin_memcpy(p, &v, 4); }
static inline u32 ld32(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }
typedef u32 (*HookU)();

static u32 THISCALL fn4e0fd0(u8 *self, u8 *out) {
  u8 b = **(u8 **)(self + 8);
  if (b == 0xff || (b & 0x3f) != 9) {  // @4e0fd0_a
    HookU h = G(HookU, 0x7003b0);
    if (!h) __asm__ volatile("int3");
    h();
    u8 *g = G(u8 *, 0x700390);
    typedef u32 (*F)(u8 *, u32);
    F f = *(F *)(*(u8 **)g + 0x24);
    f(g, 0x6970f8);  // @4e0fd0_b
  }
  u32 n = ext_4e1590(self);  // @4e0fd0_c
  u8 *base = *(u8 **)(self + 8);
  int edi = ((int)n >> 2);  // @4e0fd0_d
  if (edi != 0) {
    for (int i = 0; i != edi; i++) {
      u32 v = ld32(base + i * 4 + 5);  // @4e0fd0_e
      if (v) vcall<u32, u32>(out, 4, v);  // @4e0fd0_f
    }
  }
  *(u32 *)(self + 8) += n + 1;  // @4e0fd0_g
  return n - 4;  // @4e0fd0_h
}
PCREG(4e0fd0, fn4e0fd0);

static u32 STDCALL fn565190(u8 *a, u8 *b, u32 *c, u32 d) {
  if (!b) return 0;
  u8 *m = *(u8 **)(ld32(G(u8 *, 0x70039c) + 0x9b) + 0xae4);
  u8 *s = (u8 *)vcall<u32, u32, u8 *>(m, 0, 0x6a6a1c, b);  // @565190_a
  typedef u32 (*F)(u8 *, u8 *, u8 *, u32);
  if (c) {  // @565190_b
    u8 *w = (u8 *)vcall<u32>(G(u8 *, 0x70039c), 0x190);  // @565190_c
    F f = *(F *)(*(u8 **)w + 0x198);
    return f(w, a, s, *c);  // @565190_d
  }
  if (d) {
    u8 *w = (u8 *)vcall<u32>(G(u8 *, 0x70039c), 0x190);  // @565190_e
    F f = *(F *)(*(u8 **)w + 0x198);
    return f(w, a, s, d);  // @565190_f
  }
  u8 *src = s;
  u8 al;
  u8 *dst = a;
  do {
    al = *src++;
    *dst++ = al;  // @565190_g
  } while (al);
  return ((u32)s & ~0xffu) | al;
}
PCREG(565190, fn565190);

static u32 THISCALL fn51c140(u8 *self) {
  ext_512590(self);  // @51c140_a
  u8 *eng = G(u8 *, 0x70039c);
  if (ld32(eng + 0x1a9f) != 0) {  // @51c140_b
    u32 x = ld32(self + 0x12f);
    if (x) {  // @51c140_c
      u32 r = vcall<u32, u32, u32>((u8 *)ld32(eng + 0x1a9f), 0x60, x, 0x69f924);  // @51c140_d
      st32(self + 0x491, r);
      u32 r2 = vcall<u32, u32, u32>((u8 *)ld32(G(u8 *, 0x70039c) + 0x1a9f), 0x60, ld32(self + 0x12f), 0x69f92c);  // @51c140_e
      st32(self + 0x495, r2);  // @51c140_f
    }
  }
  u8 *vt = *(u8 **)self;
  u8 *p6c = self + 0x6c;
  typedef u32 (THISCALL *F2)(u8 *, u8 *, u8 *);
  (*(F2 *)(vt + 0x80))(self, p6c, self + 0x60);  // @51c140_g
  u8 *edi = self + 0x216, *edx = self + 0x222;
  st32(edi, ld32(p6c)); st32(edi + 4, ld32(p6c + 4)); st32(edi + 8, ld32(p6c + 8));  // @51c140_h
  st32(edx, ld32(edi)); st32(edx + 4, ld32(edi + 4)); st32(edx + 8, ld32(edi + 8));
  st32(self + 0x21a, 0);  // @51c140_i
  st32(edx, ld32(edi)); st32(edx + 4, ld32(edi + 4)); st32(edx + 8, ld32(edi + 8));  // @51c140_j
  return vcall<u32, u8 *, u8 *>(self + 0x34e, 4, edi, edx);  // @51c140_k
}
PCREG(51c140, fn51c140);
