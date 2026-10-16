// batch210017.cpp - Sonnet-w3a: small BLOCKED rows (engine compare then member slots, conditional field copy, byte out-param, serializer slots)
#include "ff.h"

extern "C" u32 THISCALL ext_45d380(u8 *self, u32 a, u32 b);
extern "C" u32 THISCALL ext_442c00(u8 *self, u8 *a);

static inline u32 ld32(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }
static inline u8 *mgr() { return (u8 *)ld32(G(u8 *, 0x70039c) + 0x9b); }

static u32 THISCALL fn5d58e0(u8 *self, u32 a, u32 b) {
  u32 ax = vcall<u32, u32, u32, u32, u32>(mgr(), 0x114, 0x6b586c, 0, 0x6b583c, 0x83);  // @5d58e0_a
  if ((u16)a == (u16)ax) {
    vcall<u32, u32, u32>(self, 0x110, 0x10, 0);  // @5d58e0_b
    u8 *m = (u8 *)ld32(self + 0x25);
    if (m) vcall<u32>(m, 0x2c);  // @5d58e0_c
    self[0x18] = 1;  // @5d58e0_d
  }
  return ext_45d380(self, a, b);  // @5d58e0_e
}
PCREG(5d58e0, fn5d58e0);

static u32 THISCALL fn444310(u8 *self, u8 *a) {
  u32 al = vcall<u32, u32>(a, 0x1e0, 0x100021) & 0xff;  // @444310_a
  if (al) {
    *(u32 *)(self + 0x98) = *(u32 *)(a + 0x98);  // @444310_b
    *(u32 *)(self + 0x94) = *(u32 *)(a + 0x94);
    *(u32 *)(self + 0x90) = *(u32 *)(a + 0x90);  // @444310_c
    *(u32 *)(self + 0x8c) = *(u32 *)(a + 0x8c);
    vcall<u32, u8 *>(G(u8 *, 0x70038c), 0xbc, self + 0x90);  // @444310_d
  }
  return ext_442c00(self, a);  // @444310_e
}
PCREG(444310, fn444310);

static u32 fn561be0() {
  u8 *g = (u8 *)vcall<u32>(mgr(), 0x134);  // @561be0_a
  volatile u8 local = 0;
  u32 r = vcall<u32, u32, volatile u8 *>(g, 0x90, 0x6a66d8, &local);  // @561be0_b
  if (local != 0) return r & ~0xffu;  // @561be0_c
  u8 *o = (u8 *)vcall<u32>(G(u8 *, 0x70039c), 0xbc);  // @561be0_d
  u32 e = vcall<u32>(o, 0xe0);  // @561be0_e
  return (e & ~0xffu) | ((e & 0xff) ? 1 : 0);  // @561be0_f
}
PCREG(561be0, fn561be0);

static u32 THISCALL fn59d3a0(u8 *self, u8 *a) {
  vcall<u32, u8 *, u32>(a, 0x18, self + 4, 4);  // @59d3a0_a
  vcall<u32, u8 *, u32>(a, 0x18, self + 8, 4);  // @59d3a0_b
  vcall<u32, u8 *>(a, 0x40, self + 0xc);  // @59d3a0_c
  u32 r = vcall<u32, u8 *>(a, 0x40, self + 0x10);  // @59d3a0_d
  return (r & ~0xffu) | 1;
}
PCREG(59d3a0, fn59d3a0);
