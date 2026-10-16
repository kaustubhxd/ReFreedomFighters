// batch210009.cpp - Sonnet-w3a: small BLOCKED rows (member chains, string-slot ctor init, dtor with flags)
#include "ff.h"

extern "C" u32 ext_634273(u32 p, u32 flags);
extern "C" u32 THISCALL ext_5ac940(u8 *self, u32 a);
extern "C" u32 THISCALL ext_5acac0(u8 *self, u32 a);
extern "C" u32 THISCALL ext_5e3e90(u8 *self);
extern "C" u32 THISCALL ext_57c2b0(u8 *self, u32 a);
extern "C" u32 THISCALL ext_562c20(u8 *self, u32 a);
extern "C" u32 THISCALL ext_5003d0(u8 *self, u32 a);
extern "C" u32 THISCALL ext_59e050(u8 *self, u32 a);
extern "C" u32 THISCALL ext_5002f0(u8 *self, u32 a);

static inline void st32(u8 *p, u32 v) { __builtin_memcpy(p, &v, 4); }

static u32 THISCALL fn5ab2a0(u8 *self, u32 a) {
  u8 *m = *(u8 **)(self + 0x648);
  if (a == 0) return ext_5acac0(m, a);  // @5ab2a0_a
  ext_5ac940(m, a);  // @5ab2a0_b
  return ext_5acac0(*(u8 **)(self + 0x648), 1);  // @5ab2a0_c
}
PCREG(5ab2a0, fn5ab2a0);

static u32 THISCALL fn5e4740(u8 *self) {
  ext_5e3e90(self);  // @5e4740_a
  u32 r = vcall<u32, u32>(self, 0x58, 0x6b7df4);  // @5e4740_b
  st32(self + 0x559, r);  // @5e4740_c
  r = vcall<u32, u32>(self, 0x58, 0x6b7e00);  // @5e4740_d
  st32(self + 0x55d, r);
  r = vcall<u32, u32>(self, 0x58, 0x6b7e14);  // @5e4740_e
  st32(self + 0x561, r);  // @5e4740_f
  *(u16 *)(self + 0x371) = 0x101;  // @5e4740_g
  return r;
}
PCREG(5e4740, fn5e4740);

static u8 *THISCALL fn435bc0(u8 *self, u32 flags) {
  u32 p = *(u32 *)(self + 8);
  *(u32 *)self = 0x67a630;  // @435bc0_vt
  if (p) ext_634273(p, 1);  // @435bc0_a
  if (flags & 1) ext_634273((u32)self, 0xd);  // @435bc0_b
  return self;
}
PCREG(435bc0, fn435bc0);

static u32 THISCALL fn57c270(u8 *self, u32 a) {
  u32 r = vcall<u32>(self, 0xd8);  // @57c270_a
  if ((u8)r) return r & ~0xffu;  // @57c270_b
  ext_57c2b0(self, 0x103);  // @57c270_c
  return ext_562c20(self, a);  // @57c270_d
}
PCREG(57c270, fn57c270);

static u32 THISCALL fn558310(u8 *self, u8 *a) {
  u32 *r = (u32 *)ext_5003d0(*(u8 **)(a + 4), 0);  // @558310_a
  u32 al = ext_59e050(*(u8 **)(self + 0x1c), *r) & 0xff;  // @558310_b
  u8 *r2 = (u8 *)ext_5003d0(*(u8 **)(a + 8), 0);  // @558310_c
  return ext_5002f0(r2, al);  // @558310_d
}
PCREG(558310, fn558310);
