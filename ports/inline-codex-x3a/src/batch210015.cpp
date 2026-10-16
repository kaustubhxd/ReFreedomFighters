// batch210015.cpp - Sonnet-w3a: small BLOCKED rows (vtable fan-out, field init, state-dependent slot chains)
#include "ff.h"

extern "C" u32 THISCALL ext_527190(u8 *self, u8 *a);
extern "C" u32 THISCALL ext_43fc30(u8 *self, u32 a, u32 b);
extern "C" u32 THISCALL ext_59c620(u8 *self);
extern "C" u32 THISCALL ext_561cb0(u8 *self, u32 a, u32 b);

static inline u32 ld32(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }

static u32 THISCALL fn5274f0(u8 *self, u8 *a) {
  vcall<u32, u8 *>(a, 0x68, self + 4);  // @5274f0_a
  vcall<u32, u8 *>(a, 0x68, self + 0x10);  // @5274f0_b
  vcall<u32, u8 *>(a, 0x68, self + 0x1c);  // @5274f0_c
  u32 r = ext_527190(self + 0x28, a);  // @5274f0_d
  return (r & ~0xffu) | 1;
}
PCREG(5274f0, fn5274f0);

static u32 THISCALL fn444450(u8 *self, u8 *a, u32 b) {
  u32 r = ext_43fc30(self, (u32)a, b);  // @444450_a
  (void)r;
  u8 *m = *(u8 **)(a + 0x54);
  if (!m) return 0;
  u8 *inner = *(u8 **)(m + 0xc);
  if (ld32(inner + 0x23) != 0x200015) return (u32)inner;  // @444450_b
  u8 *vt = *(u8 **)self;
  u32 e = vcall<u32, u8 *>((u8 *)ld32(G(u8 *, 0x70039c) + 0x9b), 0x50, a);  // @444450_c
  typedef u32 (THISCALL *F)(u8 *, u32);
  return (*(F *)(vt + 0x35c))(self, e);  // @444450_d
}
PCREG(444450, fn444450);

static u8 *THISCALL fn5c2a00(u8 *self) {
  u32 e8 = (u32)(self + 0xe8);
  *(u32 *)(self + 0x13c) = 0;  // @5c2a00_a
  *(u32 *)(self + 0xf8) = 0;
  *(u32 *)(self + 0x140) = 0;
  *(u32 *)(self + 0x188) = 0;
  *(u32 *)(self + 0x144) = 0;
  *(u32 *)(self + 0x18c) = 0;
  *(u32 *)(self + 0x1d4) = 0;
  *(u32 *)(self + 0x190) = 0;
  *(u32 *)(self + 0x1d8) = 0;
  *(u32 *)(self + 0x220) = 0;
  *(u32 *)(self + 0x1dc) = 0;  // @5c2a00_b
  *(u32 *)(self + 0x224) = 0;
  *(u32 *)(self + 0x26c) = 0;
  *(u32 *)(self + 0x228) = 0;
  *(u32 *)(self + 0x270) = 0;
  *(u32 *)(self + 0x2b8) = 0;
  *(u32 *)(self + 0x274) = 0;
  *(u32 *)(self + 0x2bc) = 0;
  *(u32 *)(self + 0x2c0) = 0;
  *(u32 *)(self + 0x2c4) = 0;
  *(u32 *)(self + 0x140) = e8;  // @5c2a00_c
  *(u32 *)(self + 0x18c) = e8;
  *(u32 *)(self + 0x1d8) = e8;
  *(u32 *)(self + 0x224) = e8;
  *(u32 *)(self + 0x270) = e8;
  *(u32 *)(self + 0x2bc) = e8;  // @5c2a00_d
  *(u32 *)(self + 4) = 0;  // @5c2a00_e
  return self;
}
PCREG(5c2a00, fn5c2a00);

static u32 THISCALL fn562e20(u8 *self) {
  if (self[0x84]) return ext_59c620(*(u8 **)(self + 0x94));  // @562e20_a
  if (*(u32 *)(self + 0x48) != 0) {
    if (self[0x86]) {
      u8 *o = (u8 *)vcall<u32>(self, 0x84);  // @562e20_b
      vcall<u32>(o, 0x300);  // @562e20_c
    }
    u8 *o2 = (u8 *)vcall<u32>(self, 0x84);  // @562e20_d
    return vcall<u32, u32>(o2, 0x2f8, *(u32 *)(self + 0x48));  // @562e20_e
  }
  u8 *o3 = (u8 *)vcall<u32>(self, 0x84);  // @562e20_f
  return vcall<u32>(o3, 0x300);  // @562e20_g
}
PCREG(562e20, fn562e20);

static u32 THISCALL fn57bc10(u8 *self, u32 a, u8 *b) {
  u32 ax = vcall<u32, u32, u32, u32, u32>((u8 *)ld32(G(u8 *, 0x70039c) + 0x9b), 0x114, 0x6aa4bc, 0, 0x6aa490, 0x50);  // @57bc10_a
  if ((u16)a == (u16)ax) {
    if (b) __builtin_memcpy(self + 0xcb2, b, 4);  // @57bc10_b
    return 0;
  }
  return ext_561cb0(self, a, (u32)b);  // @57bc10_c
}
PCREG(57bc10, fn57bc10);

static u32 THISCALL fn44c370(u8 *self) {
  if (*(u32 *)(self + 0x1c) != 0 && self[0x20] == 0) {
    u8 *o = (u8 *)vcall<u32, u32, u32>(G(u8 *, 0x700390), 0x20, 0x67fe5c, 0x12b);  // @44c370_a
    u32 p = *(u32 *)(self + 4);
    if (!p) p = 0x67c8e8;  // @44c370_b
    typedef u32 (*F)(u8 *, u32, u32);
    F f = *(F *)(*(u8 **)o + 0x30);
    f(o, 0x67feb0, p);  // @44c370_c
  }
  u8 *eng = G(u8 *, 0x70039c);
  u32 r = (u32)eng;
  u8 *c = (u8 *)ld32(eng + 0x1a9f);
  if (c) r = vcall<u32, u32>(c, 0x50, *(u32 *)(self + 0x1c));  // @44c370_d
  self[0x20] = 0;  // @44c370_e
  return r;
}
PCREG(44c370, fn44c370);
