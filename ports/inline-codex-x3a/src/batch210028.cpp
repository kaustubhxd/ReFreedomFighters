// batch210028.cpp - Sonnet-w3a: small BLOCKED rows (typed lookup offset, tag check with report, slot chain, serializers)
#include "ff.h"

extern "C" u32 THISCALL ext_4e1590(u8 *self);

static inline u32 ld32(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }
static inline u8 *mgr() { return (u8 *)ld32(G(u8 *, 0x70039c) + 0x9b); }

static u32 THISCALL fn5a4610(u8 *self, u32 a) {
  u8 *o = (u8 *)vcall<u32, u32>(mgr(), 0x58, a);  // @5a4610_a
  if (o) {
    if (!(vcall<u32, u32>(o, 0x1e0, 0x2007f9) & 0xff)) {  // @5a4610_b
      if (!(vcall<u32, u32>(o, 0x1e0, 0x2003e8) & 0xff)) return 0;  // @5a4610_c
    }
    int t = (int)(*(u32 *)(*(u8 **)(o + 0x54) + 4) - 3u);  // @5a4610_d
    if (t == -1 || t > 6) return 0;  // @5a4610_e
    return (u32)self + (u32)t * 18u + 0x61u;  // @5a4610_f
  }
  return 0;
}
PCREG(5a4610, fn5a4610);

static u32 THISCALL fn512940(u8 *self, u32 a, u32 b, u32 c) {
  u8 *o = (u8 *)vcall<u32, u32>(mgr(), 0x58, a);  // @512940_a
  u8 *x = (u8 *)vcall<u32, u32, u32>(o, 0x2c4, b, c);  // @512940_b
  u8 *vt = *(u8 **)x;
  vcall<u32>(x, 0x2c);  // @512940_c
  u32 edx = b ? b : (u32)self;  // @512940_d
  u32 v = vcall<u32, u8 *, u32, u32>(mgr(), 0x4c, self, edx, 1);  // @512940_e
  typedef u32 (THISCALL *F)(u8 *, u32);
  (*(F *)(vt + 0x2f0))(x, v);  // @512940_f
  vcall<u32, u32>(x, 0xbc, 0);  // @512940_g
  return (u32)x;
}
PCREG(512940, fn512940);

static u32 THISCALL fn5b7c00(u8 *self, u8 *a) {
  u32 loc = (u32)a;
  vcall<u32, u8 *>(a, 0x50, self + 4);  // @5b7c00_a
  vcall<u32, u8 *>(a, 0x50, self + 8);  // @5b7c00_b
  u8 *r = (u8 *)vcall<u32, u8 *>(a, 0x6c, self + 0xc);  // @5b7c00_c
  vcall<u32, u8 *>(r, 0x6c, self + 0x18);  // @5b7c00_d
  vcall<u32, u8 *>(a, 0x68, self + 0x28);  // @5b7c00_e
  vcall<u32, u8 *>(a, 0x40, self + 0x24);  // @5b7c00_f
  vcall<u32, u32 *>(a, 0x40, &loc);  // @5b7c00_g
  *(u32 *)self = loc;  // @5b7c00_h
  return loc;
}
PCREG(5b7c00, fn5b7c00);

static u32 THISCALL fn5d4020(u8 *self, u8 *a) {
  vcall<u32, u32>(a, 0x44, *(u32 *)(self + 0x80));  // @5d4020_a
  vcall<u32, u32>(a, 0x44, *(u32 *)(self + 0x58));
  vcall<u32, u32>(a, 0x44, *(u32 *)(self + 0x5c));  // @5d4020_b
  vcall<u32, u32>(a, 0x44, *(u32 *)(self + 0x60));
  vcall<u32, u32>(a, 0x44, *(u32 *)(self + 0x64));  // @5d4020_c
  vcall<u32, u32>(a, 0x3c, *(u32 *)(self + 0x68));  // @5d4020_d
  vcall<u32, u32>(a, 0x3c, *(u32 *)(self + 0x6c));
  vcall<u32, u32>(a, 0x3c, *(u32 *)(self + 0x70));  // @5d4020_e
  u32 r = vcall<u32, u32>(a, 0x3c, *(u32 *)(self + 0x74));  // @5d4020_f
  return (r & ~0xffu) | 1;
}
PCREG(5d4020, fn5d4020);

typedef u32 (*HookU)();
static u32 THISCALL fn4e0f60(u8 *self, u32 *out) {
  u8 *p = *(u8 **)(self + 8);
  u8 b = *p;
  bool ok = (b != 0xff && ((b & 0x3f) == 7 || (b & 0x3f) == 0xc || (b & 0x3f) == 9));  // @4e0f60_a
  if (!ok) {
    HookU h = G(HookU, 0x7003b0);
    if (!h) __asm__ volatile("int3");
    h();
    u8 *g = G(u8 *, 0x700390);
    typedef u32 (*F)(u8 *, u32);
    F f = *(F *)(*(u8 **)g + 0x24);
    f(g, 0x6970f8);  // @4e0f60_b
  }
  *out = *(u32 *)(self + 8) + 5;  // @4e0f60_c
  u32 n = ext_4e1590(self);  // @4e0f60_d
  *(u32 *)(self + 8) += n + 1;  // @4e0f60_e
  return n - 4;  // @4e0f60_f
}
PCREG(4e0f60, fn4e0f60);
