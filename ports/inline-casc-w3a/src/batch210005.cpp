// batch210005.cpp - Sonnet-w3a: small BLOCKED rows (tag arithmetic, recursive flag AND, ctors/dtors, slot chains, assert paths)
#include "ff.h"

extern "C" u32 ext_634273(u32 p, u32 flags);
extern "C" u32 THISCALL ext_4d8430(u8 *self);
extern "C" u32 THISCALL ext_5003d0(u8 *self, u32 a);
extern "C" u32 THISCALL ext_5a20d0(u8 *self, u32 a, u32 b);
extern "C" u32 THISCALL ext_45d5b0(u8 *self, u8 *a);

static u32 THISCALL fn4e5330(u8 *self) {
  u8 *e = *(u8 **)(self + 4);
  u32 t = *(u32 *)(e + 4) & 0xc0000000u;  // @4e5330
  u32 off = 8;
  if (t != 0) off = *(u32 *)(e + 8);  // @4e5330_b
  return off + (u32)e;
}
PCREG(4e5330, fn4e5330);

static u8 THISCALL fn439670(u8 *self) {
  u8 al = self[0xc];
  if (!al) return 0;
  if (*(u32 *)self == 3) return al;  // @439670_a
  return fn439670(*(u8 **)(self + 8)) & self[0xc];  // @439670_b
}
PCREG(439670, fn439670);

static u32 THISCALL fn57c190(u8 *self) {
  u8 *eng = G(u8 *, 0x70039c);
  u8 *a = (u8 *)vcall<u32>(eng, 0xbc);  // @57c190_a
  vcall<u32>(a, 0x74);  // @57c190_b
  return vcall<u32, u32>(self, 0xd0, 0);  // @57c190_c
}
PCREG(57c190, fn57c190);

static u32 THISCALL fn591ae0(u8 *self) {
  u32 cur;
  __builtin_memcpy(&cur, self + 0x85e, 4);
  if (cur == 0) {
    u8 *c = *(u8 **)(self + 0x84e);
    if (c) {
      u32 v = vcall<u32, u32>(c, 0x100, 0x6ad00c);  // @591ae0_a
      __builtin_memcpy(self + 0x85e, &v, 4);  // @591ae0_s
    }
  }
  u32 r;
  __builtin_memcpy(&r, self + 0x85e, 4);
  return r;
}
PCREG(591ae0, fn591ae0);

static u8 *THISCALL fn5f0340(u8 *self, u8 *p) {
  *(u32 *)self = 0x6b823c;  // @5f0340_vt
  *(u32 *)(self + 0xc) = vcall<u32, u32>(p, 0x14, 0x6b1e6c);  // @5f0340_c
  return self;
}
PCREG(5f0340, fn5f0340);

static u8 *THISCALL fn485ed0(u8 *self, u32 flags) {
  *(u32 *)self = 0x685294;  // @485ed0_vt
  if (flags & 1) ext_634273((u32)self, 0x30);  // @485ed0_c
  return self;
}
PCREG(485ed0, fn485ed0);

static u8 *THISCALL fn48ab40(u8 *self, u32 flags) {
  ext_4d8430(self);  // @48ab40_a
  if (flags & 1) ext_634273((u32)self, 0x108);  // @48ab40_c
  return self;
}
PCREG(48ab40, fn48ab40);

static u8 *THISCALL fn4ccba0(u8 *self) {
  *(u32 *)(self + 0x10) = 0x20;  // @4ccba0_a
  *(u32 *)(self + 0x14) = 0;
  *(u32 *)(self + 0x18) = 1;
  *(u32 *)(self + 0xc) = 0x20;
  *(u32 *)(self + 4) = 0;
  *(u32 *)(self + 8) = 0;
  *(u32 *)self = 0x6957bc;  // @4ccba0_b
  return self;
}
PCREG(4ccba0, fn4ccba0);

static u32 THISCALL fn55b290(u8 *self, u8 *a) {
  u32 *r = (u32 *)ext_5003d0(*(u8 **)(a + 4), 0);  // @55b290_a
  return ext_5a20d0(*(u8 **)(self + 0x1c), *r, 0);  // @55b290_b
}
PCREG(55b290, fn55b290);

static u32 THISCALL fn55c910(u8 *self, u8 *a) {
  u16 *r = (u16 *)ext_5003d0(*(u8 **)(a + 4), 0);  // @55c910_a
  return vcall<u32, u32>(*(u8 **)(self + 0x1c), 0x6a4, *r);  // @55c910_b
}
PCREG(55c910, fn55c910);

static u32 THISCALL fn5de9a0(u8 *self, u8 *a) {
  u8 *t = (u8 *)vcall<u32, u8 *>(a, 0x50, self);  // @5de9a0_a
  return vcall<u32, u8 *>(t, 0x40, self + 4);  // @5de9a0_b
}
PCREG(5de9a0, fn5de9a0);

static u32 THISCALL fn43f8c0(u8 *self, u8 *a) {
  *(u32 *)(self + 0x3c) = *(u32 *)(a + 0x3c);  // @43f8c0_a
  u32 v40 = *(u32 *)(a + 0x40);
  *(u32 *)(self + 0x30) &= 0x800;
  *(u32 *)(self + 0x40) = v40;  // @43f8c0_b
  *(u32 *)(self + 0x30) |= *(u32 *)(a + 0x30) & 0xfffff7ffu;  // @43f8c0_c
  *(u32 *)(self + 0x38) = *(u32 *)(a + 0x38);
  return ext_45d5b0(self, a);
}
PCREG(43f8c0, fn43f8c0);

typedef void (*Hook)();
static u32 STDCALL fn48b4f0(u32 a, u32 b) {
  (void)a; (void)b;
  u8 *g = G(u8 *, 0x700390);
  u8 *o = (u8 *)vcall<u32, u32, u32>(g, 0x20, 0x68d798, 0x1420);  // @48b4f0_a
  typedef u32 (*F)(u8 *, u32);
  F f = *(F *)(*(u8 **)o + 0x2c);
  f(o, 0x68e17c);  // @48b4f0_b
  Hook h = G(Hook, 0x7003b0);
  if (!h) __asm__ volatile("int3");
  h();
  return 0;
}
PCREG(48b4f0, fn48b4f0);

static u32 STDCALL fn5f9530(u32 a, u32 b) {
  (void)a; (void)b;
  u8 *g = G(u8 *, 0x700390);
  u8 *o = (u8 *)vcall<u32, u32, u32>(g, 0x20, 0x6b8a64, 0x2a3);  // @5f9530_a
  typedef u32 (*F)(u8 *, u32, u32);
  F f = *(F *)(*(u8 **)o + 0x2c);
  f(o, 0x69c6b0, 0x69c7f0);  // @5f9530_b
  typedef u32 (*H)();
  H h = G(H, 0x7003b0);
  if (!h) __asm__ volatile("int3");
  return h();
}
PCREG(5f9530, fn5f9530);
