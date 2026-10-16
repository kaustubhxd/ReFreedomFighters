// batch210024.cpp - Sonnet-w3a: small BLOCKED rows (flag lookup chain, slot fan-out, conditional slot, dtor with flags, field reader)
#include "ff.h"

extern "C" u32 THISCALL ext_5003d0(u8 *self, u32 a);
extern "C" u32 THISCALL ext_5002f0(u8 *self, u32 a);
extern "C" u32 THISCALL ext_5c5620(u8 *self);
extern "C" u32 THISCALL ext_5c5810(u8 *self);
extern "C" u32 ext_41e2c0(u32 p);
extern "C" u32 ext_634273(u32 p, u32 flags);
extern "C" u32 THISCALL ext_43de70(u8 *self);
extern "C" u32 ext_45c510(u8 *self);
extern "C" u32 ext_4690b0(u8 *self, u32 a);
extern "C" u32 STDCALL ext_610100(u8 *a);
extern "C" u32 THISCALL ext_4e12e0(u8 *self, u8 *p, u32 n);
extern "C" u32 THISCALL ext_4e11e0(u8 *self, u8 *p, u32 n);
extern "C" u32 THISCALL ext_4e12f0(u8 *self, u8 *p, u32 n);

static inline u32 ld32(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }
static inline u8 *mgr() { return (u8 *)ld32(G(u8 *, 0x70039c) + 0x9b); }

static u32 THISCALL fn55cec0(u8 *self, u8 *a) {
  ext_5002f0((u8 *)ext_5003d0(*(u8 **)(a + 8), 0), 0);  // @55cec0_a
  u32 v = ld32(*(u8 **)(self + 0x1c) + 0x78a);  // @55cec0_b
  u8 *o = (u8 *)vcall<u32, u32>(mgr(), 0x58, v);  // @55cec0_c
  if (!o) return 0;
  u8 *p = (u8 *)vcall<u32>(o, 0x2e8);  // @55cec0_d
  if (!p) return 0;
  u32 q = vcall<u32>(p, 0x300);  // @55cec0_e
  return ext_5002f0((u8 *)ext_5003d0(*(u8 **)(a + 8), 0), q == 2);  // @55cec0_f
}
PCREG(55cec0, fn55cec0);

static u32 THISCALL fn5c33a0(u8 *self, u8 *a) {
  *(u32 *)(self + 4) &= 0xffffffbfu;  // @5c33a0_a
  vcall<u32, u8 *>(a, 0x68, self + 0x114);  // @5c33a0_b
  vcall<u32, u8 *>(a, 0x50, self + 0x115);  // @5c33a0_c
  vcall<u32, u8 *>(a, 0x50, self + 0x119);
  vcall<u32, u8 *>(a, 0x50, self + 0x11d);  // @5c33a0_d
  vcall<u32, u8 *>(a, 0x50, self + 0x121);
  u32 r = vcall<u32, u8 *>(a, 0x68, self + 0x125);  // @5c33a0_e
  return (r & ~0xffu) | 1;
}
PCREG(5c33a0, fn5c33a0);

static u32 THISCALL fn5c55a0(u8 *self) {
  if (ext_5c5620(self)) {  // @5c55a0_a
    ext_5c5810(self);  // @5c55a0_b
    u8 *m = *(u8 **)(self + 0x44);
    vcall<u32, u8 *, u32, u32>(m, 0x130, m, *(u16 *)(self + 0x14c), 0);  // @5c55a0_c
    u8 *m2 = *(u8 **)(self + 0x44);
    u8 *vt = *(u8 **)m2;
    u32 ax = vcall<u32, u32, u32, u32, u32, u32>(mgr(), 0x114, 0x6ab71c, 0, 0x6b4204, 0x57, 0) & 0xffff;  // @5c55a0_d
    typedef u32 (THISCALL *F)(u8 *, u8 *, u32);
    (*(F *)(vt + 0x130))(m2, m2, ax);  // @5c55a0_e
  }
  return vcall<u32, u32, u32>(self, 0x68, 0x10, 0);  // @5c55a0_f
}
PCREG(5c55a0, fn5c55a0);

static u8 *THISCALL fn5d88d0(u8 *self, u32 flags) {
  u32 p = *(u32 *)(self + 0x20);
  *(u32 *)self = 0x6b5fc8;  // @5d88d0_v
  if (p) ext_41e2c0(p);  // @5d88d0_a
  u32 q = *(u32 *)(self + 0x24);
  if (q) ext_634273(q, 8);  // @5d88d0_b
  *(u32 *)(self + 0x24) = 0;  // @5d88d0_c
  *(u32 *)(self + 0x20) = 0;
  ext_43de70(self);  // @5d88d0_d
  if (flags & 1) {
    if (!(flags & 4)) {
      ext_45c510(self);  // @5d88d0_e
      return self;
    }
    ext_4690b0(self, 0x48);  // @5d88d0_f
  }
  return self;
}
PCREG(5d88d0, fn5d88d0);

static u32 THISCALL fn5d8cf0(u8 *self, u8 *a) {
  ext_610100(a);  // @5d8cf0_a
  ext_4e12e0(a, self + 0x28, 1);  // @5d8cf0_b
  ext_4e11e0(a, self + 0x2c, 1);  // @5d8cf0_c
  ext_4e11e0(a, self + 0x30, 1);
  ext_4e11e0(a, self + 0x3c, 1);  // @5d8cf0_d
  ext_4e11e0(a, self + 0x40, 1);
  return ext_4e12f0(a, self + 0x38, 1);  // @5d8cf0_e
}
PCREG(5d8cf0, fn5d8cf0);
