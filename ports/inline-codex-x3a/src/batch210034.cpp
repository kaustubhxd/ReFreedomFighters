// batch210034.cpp - Sonnet-w3a: small BLOCKED rows (field reads + engine lookups, list dispatch by flag, list walk with report)
#include "ff.h"

extern "C" u32 THISCALL ext_4e5e60(u8 *self);
extern "C" u32 THISCALL ext_45dcd0(u8 *self, u32 a, u32 b, u32 c, u32 d, u32 e);

static inline void st32(u8 *p, u32 v) { __builtin_memcpy(p, &v, 4); }
static inline u32 ld32(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }
static inline u8 *mgr() { return (u8 *)ld32(G(u8 *, 0x70039c) + 0x9b); }

static u32 THISCALL fn5dd4b0(u8 *self, u8 *a) {
  st32(self + 0x49, ext_4e5e60(a));  // @5dd4b0_a
  st32(self + 0x4d, ext_4e5e60(a));
  st32(self + 0x51, ext_4e5e60(a));  // @5dd4b0_b
  st32(self + 0x55, ext_4e5e60(a));
  st32(self + 0x59, ext_4e5e60(a));  // @5dd4b0_c
  st32(self + 0x5d, ext_4e5e60(a));
  u32 r;
  r = vcall<u32, u32>(mgr(), 0x58, ld32(self + 0x49)); st32(self + 0x61, r);  // @5dd4b0_d
  r = vcall<u32, u32>(mgr(), 0x58, ld32(self + 0x4d)); st32(self + 0x65, r);  // @5dd4b0_e
  r = vcall<u32, u32>(mgr(), 0x58, ld32(self + 0x51)); st32(self + 0x69, r);
  r = vcall<u32, u32>(mgr(), 0x58, ld32(self + 0x55)); st32(self + 0x6d, r);  // @5dd4b0_f
  r = vcall<u32, u32>(mgr(), 0x58, ld32(self + 0x59)); st32(self + 0x71, r);  // @5dd4b0_g
  return r;
}
PCREG(5dd4b0, fn5dd4b0);

static u32 THISCALL fn44e590(u8 *self, u32 flag) {
  if ((u8)flag) {  // @44e590_a
    for (u32 i = 0; i < *(u32 *)(self + 0x1c); i++) {
      u8 *e = (*(u8 ***)(self + 0x20))[i];
      u8 *o = (u8 *)vcall<u32, u32>(mgr(), 0x58, *(u32 *)(e + 0x10));  // @44e590_b
      if (o) vcall<u32, u32, u32>(o, 0x294, *(u32 *)(self + 8), *(u32 *)(e + 0xc));  // @44e590_c
    }
    return 0;
  }
  for (u32 i = 0; i < *(u32 *)(self + 0x1c); i++) {
    u8 *e = (*(u8 ***)(self + 0x20))[i];
    u8 *o = (u8 *)vcall<u32, u32>(mgr(), 0x58, *(u32 *)(e + 0x10));  // @44e590_d
    if (o) vcall<u32, u32, u32, u32, u32>(o, 0x290, *(u32 *)(self + 8), *(u32 *)(e + 0xc), 0, 0);  // @44e590_e
  }
  return 0;
}
PCREG(44e590, fn44e590);

static u32 THISCALL fn43ff00(u8 *self, u32 a, u32 b, u32 c, u32 d, u32 e) {
  u32 ebx = ext_45dcd0(self, a, b, c, d, 0);  // @43ff00_a
  if ((u8)e && ebx) {  // @43ff00_b
    for (u8 *p = *(u8 **)(self + 0x50); p; p = *(u8 **)(p + 0x60)) {  // @43ff00_c
      u8 *m = *(u8 **)(p + 0x54);
      if (!m) {
        u8 *g = G(u8 *, 0x700390);
        u8 *o = (u8 *)vcall<u32, u32, u32>(g, 0x20, 0x67cbbc, 0x1a3);  // @43ff00_d
        typedef u32 (*F)(u8 *, u32);
        F f = *(F *)(*(u8 **)o + 0x2c);
        f(o, 0x67cce8);  // @43ff00_e
      } else {
        u32 x = **(u32 **)(m + 0xc);
        u32 name = *(u32 *)(m + 4);
        if (!name) name = 0x67c8e8;  // @43ff00_f
        vcall<u32, u32, u32, u32, u32, u32>(m, 0x1b8, ebx, 0, name, x, 1);  // @43ff00_g
      }
    }
  }
  return ebx;
}
PCREG(43ff00, fn43ff00);
