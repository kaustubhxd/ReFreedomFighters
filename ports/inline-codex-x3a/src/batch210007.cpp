// batch210007.cpp - Sonnet-w3a: small BLOCKED rows (dtors with owned buffers, ctor fills, field copy, assert-fail, init tail)
#include "ff.h"

extern "C" u32 ext_634273(u32 p, u32 flags);
extern "C" u32 THISCALL ext_4cee80(u8 *self, u32 a);
extern "C" u32 ext_630c50(u8 *a);
extern "C" u32 THISCALL ext_6363a0(u8 *self);
extern "C" u32 THISCALL ext_43de70(u8 *self);
extern "C" u32 THISCALL ext_4e0e90(u8 *self, u32 a);
extern "C" u32 THISCALL ext_4e1590(u8 *self);

static inline void st32(u8 *p, u32 v) { __builtin_memcpy(p, &v, 4); }
static inline u32 ld32(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }

static u32 THISCALL fn4cef60(u8 *self, u32 a) {
  u32 r = vcall<u32, u32>(self, 0x78, a);  // @4cef60_a
  if (*(u32 *)(self + 0x28) == r) *(u32 *)(self + 0x28) = 0;  // @4cef60_b
  return ext_4cee80(self, a);  // @4cef60_c
}
PCREG(4cef60, fn4cef60);

typedef void (*Hook)();
static u32 STDCALL fn5f5160(u32 a, u32 b, u32 c) {
  (void)a; (void)b; (void)c;
  u8 *g = G(u8 *, 0x700390);
  u8 *o = (u8 *)vcall<u32, u32, u32>(g, 0x20, 0x6b8a64, 0x2ac);  // @5f5160_a
  typedef u32 (*F)(u8 *, u32, u32);
  F f = *(F *)(*(u8 **)o + 0x2c);
  f(o, 0x69c6b0, 0x69c7f0);  // @5f5160_b
  Hook h = G(Hook, 0x7003b0);
  if (!h) __asm__ volatile("int3");
  h();
  return 0;
}
PCREG(5f5160, fn5f5160);

static u8 *THISCALL fn636280(u8 *self) {
  *(u32 *)(self + 0x1c) = 0;
  *(u32 *)(self + 4) = 0x44585433;  // @636280_a
  *(u32 *)(self + 8) = 0;
  *(u32 *)(self + 0xc) = 0;
  *(u32 *)(self + 0x10) = 0;
  *(u32 *)(self + 0x14) = 0;
  *(u32 *)(self + 0x18) = 0;
  self[0x28] = 0;
  st32(self + 0x29, 0);  // @636280_b
  *(u32 *)self = 0x6c2214;  // @636280_vt
  return self;
}
PCREG(636280, fn636280);

static u32 FASTCALL fn4dfd10(u8 *d, u8 *s) {
  *(u32 *)(d + 0x18) = *(u32 *)(s + 0x18);  // @4dfd10_a
  *(u32 *)(d + 0xc) = *(u32 *)(s + 0x1c);
  *(u32 *)(d + 0) = *(u32 *)(s + 0x20);
  *(u32 *)(d + 0x1c) = *(u32 *)(s + 0xc);  // @4dfd10_b
  *(u32 *)(d + 0x10) = *(u32 *)(s + 0x10);
  *(u32 *)(d + 4) = *(u32 *)(s + 0x14);
  *(u32 *)(d + 0x20) = *(u32 *)(s + 0);  // @4dfd10_c
  *(u32 *)(d + 0x14) = *(u32 *)(s + 4);
  *(u32 *)(d + 8) = *(u32 *)(s + 8);
  return *(u32 *)(s + 8);
}
PCREG(4dfd10, fn4dfd10);

static u32 STDCALL fn5c7a00(u8 *a) {
  u8 *eng = G(u8 *, 0x70039c);
  u8 *m = (u8 *)ld32(eng + 0x9b);
  u32 r = vcall<u32, u32>(m, 0x58, *(u32 *)(a + 0x20));  // @5c7a00_a
  if (r) r = vcall<u32, u32>((u8 *)r, 0x210, 1);  // @5c7a00_b
  *(u32 *)(a + 0x20) = 0;  // @5c7a00_c
  return r;
}
PCREG(5c7a00, fn5c7a00);

static u32 fn630000(u8 *a) {
  *(u32 *)(a + 0xb18) = 0x6f447c;  // @630000_a
  *(u32 *)(a + 0xb10) = (u32)(a + 0x8c);
  *(u32 *)(a + 0xb1c) = (u32)(a + 0x980);
  *(u32 *)(a + 0xb28) = (u32)(a + 0xa74);  // @630000_b
  *(u32 *)(a + 0xb24) = 0x6f4490;
  *(u32 *)(a + 0xb30) = 0x6f44a4;  // @630000_c
  *(u16 *)(a + 0x16b0) = 0;
  *(u32 *)(a + 0x16b4) = 0;
  *(u32 *)(a + 0x16ac) = 8;  // @630000_d
  return ext_630c50(a);
}
PCREG(630000, fn630000);

static u32 THISCALL fn636430(u8 *self) {
  *(u32 *)self = 0x6c2080;  // @636430_v1
  if (self[0x3a]) ext_634273(ld32(self + 0x36), 1);  // @636430_a
  *(u32 *)self = 0x6c1fec;  // @636430_v2
  if (self[0x31]) ext_634273(ld32(self + 0x2d), 4);  // @636430_b
  return ext_6363a0(self);
}
PCREG(636430, fn636430);

static u32 THISCALL fn43bbe0(u8 *self, u8 *a) {
  a[0xa0] = 0;  // @43bbe0_a
  st32(a + 0xa1, 0);
  *(u16 *)(a + 0xa5) = 0;
  *(u32 *)(a + 0x80) = 0xffffffffu;  // @43bbe0_b
  *(u32 *)(a + 0x90) = 0xffffffffu;
  *(u32 *)(a + 0x84) = 0xffffffffu;
  *(u32 *)(a + 0x94) = 0xffffffffu;
  *(u32 *)(a + 0x88) = 0xffffffffu;
  *(u32 *)(a + 0x98) = 0xffffffffu;
  *(u32 *)(a + 0x8c) = 0xffffffffu;
  *(u32 *)(a + 0x9c) = 0xffffffffu;  // @43bbe0_c
  st32(self + 0x247, 0);  // @43bbe0_d
  st32(self + 0x243, 0);
  st32(a + 0xa7, 0);
  st32(a + 0xab, 0);  // @43bbe0_e
  return (u32)a;
}
PCREG(43bbe0, fn43bbe0);

static u32 THISCALL fn457290(u8 *self) {
  u32 p = *(u32 *)(self + 0xd0);
  *(u32 *)self = 0x6832f8;  // @457290_vt
  if (p) ext_634273(p, 0x10);  // @457290_a
  u32 q = *(u32 *)(self + 0xcc);
  if (q) ext_634273(q, 0x18);  // @457290_b
  return ext_43de70(self);
}
PCREG(457290, fn457290);

static u32 THISCALL fn4e1b30(u8 *self) {
  u32 r0 = ext_4e0e90(self, 6);  // @4e1b30_a
  u8 *e = *(u8 **)(self + 8);
  u8 b = *e;
  if (b == 0xff) return (r0 & ~0xffu) | 0xff;
  b &= 0x3f;
  if (b == 0xff) return (r0 & ~0xffu) | 0xff;
  u32 n = ext_4e1590(self) + 1 + (u32)e;  // @4e1b30_b
  *(u32 *)(self + 8) = n;  // @4e1b30_c
  return n;
}
PCREG(4e1b30, fn4e1b30);
