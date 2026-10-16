// batch210004.cpp - Sonnet-w3a: small BLOCKED rows (vtable dispatchers, forwarders, member chains)
#include "ff.h"

extern "C" u32 ext_42abbd(u32 a, u32 b, u32 c, u32 d, u32 e);
extern "C" u32 THISCALL ext_4d24e0(u8 *self, u32 a, u32 b, u32 c, u32 d);
extern "C" u32 THISCALL ext_4e5f10(u8 *self);
extern "C" u32 THISCALL ext_4e6420(u8 *self);
extern "C" u32 THISCALL ext_5acac0(u8 *self, u32 a);
extern "C" u32 THISCALL ext_5fcb80(u8 *self, u32 a, u32 b, u32 c, u32 d, u32 e);
extern "C" u32 ext_634273(u32 p, u32 flags);
extern "C" u32 THISCALL ext_6363a0(u8 *self);

static u8 *THISCALL fn46e660(u8 *self) {
  u8 *r = (u8 *)vcall<u32, u32, u32>(self, 0x25c, 0x68886c, 0);  // @46e660
  return r ? r : self;
}
PCREG(46e660, fn46e660);

static u32 fn42abee(u32 a, u32 b, u32 c) {
  return ext_42abbd(a, 0xffffffff, b, 0, c);  // @42abee
}
PCREG(42abee, fn42abee);

static u32 THISCALL fn45c680(u8 *self, u32 a) {
  if ((u8)a != 0) return vcall<u32>(self, 0x34);  // @45c680_a
  return vcall<u32, u32>(self, 0x30, 1);  // @45c680_b
}
PCREG(45c680, fn45c680);

static u32 THISCALL fn4d3cf0(u8 *self, u32 a, u32 b, u32 c) {
  return ext_4d24e0(self, a, 4, b, c << 2);  // @4d3cf0
}
PCREG(4d3cf0, fn4d3cf0);

static u32 STDCALL fn4d6010(u32 unused) {
  (void)unused;
  u8 *g = G(u8 *, 0x700390);
  u8 *r = (u8 *)vcall<u32, u32, u32>(g, 0x20, 0x696924, 0x394);  // @4d6010_a
  typedef u32 (*F)(u8 *, u32);
  F f = *(F *)(*(u8 **)r + 0x2c);
  return f(r, 0x696a64);  // @4d6010_b
}
PCREG(4d6010, fn4d6010);

static u32 THISCALL fn4da340(u8 *self, u32 a, u32 b, u32 c, u32 d) {
  u8 *m = *(u8 **)(self + 0x54);
  if (!m) return 0;
  return vcall<u32, u32, u32, u32, u32>(m, 0x124, a, b, c, d);  // @4da340
}
PCREG(4da340, fn4da340);

static u32 THISCALL fn4e5e40(u8 *self) {
  u32 r1 = ext_4e5f10(self);  // @4e5e40_a
  u32 r2 = ext_4e6420(self);  // @4e5e40_b
  return (r2 & 0xffff0000u) | (r1 & 0xffffu);
}
PCREG(4e5e40, fn4e5e40);

static u32 THISCALL fn5ef050(u8 *self, u32 a) {
  self[0x10] = (u8)a;  // @5ef050_a
  (*(u8 **)(self + 4))[0x35] = (u8)a;  // @5ef050_b
  (*(u8 **)(self + 8))[0x35] = (u8)a;  // @5ef050_c
  return ext_5acac0(*(u8 **)(self + 0xc), a);  // @5ef050_d
}
PCREG(5ef050, fn5ef050);

static u32 THISCALL fn5fb530(u8 *self, u32 a, u32 b, u32 c, u32 d) {
  return ext_5fcb80(*(u8 **)(self + 4), a, b, c, d, self[0x40]);  // @5fb530
}
PCREG(5fb530, fn5fb530);

static u32 THISCALL fn636400(u8 *self) {
  *(u32 *)self = 0x6c1fec;  // @636400_vt
  if (self[0x31]) {
    u32 p;
    __builtin_memcpy(&p, self + 0x2d, 4);
    ext_634273(p, 4);  // @636400_c
  }
  return ext_6363a0(self);
}
PCREG(636400, fn636400);

static u8 *THISCALL fn437050(u8 *self, u32 a) {
  u8 *r = (u8 *)vcall<u32, u32>(self, 0x58, a);  // @437050
  if (r) {
    u32 f = *(u32 *)r;
    r[0xc] = 1;  // @437050_s
    if (f == 0) r[0x2e] &= 0xbf;  // @437050_m
  }
  return r;
}
PCREG(437050, fn437050);
