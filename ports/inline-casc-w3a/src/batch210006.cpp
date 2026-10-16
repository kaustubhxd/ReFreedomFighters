// batch210006.cpp - Sonnet-w3a: small BLOCKED rows (ctors with base call, stack-arg pointers, lazy init, handler call)
#include "ff.h"

extern "C" u32 THISCALL ext_45c3a0(u8 *self, u32 a, u32 b, u32 c);
extern "C" u32 THISCALL ext_5e0e10(u8 *self, u32 a, u32 b);
extern "C" u32 STDCALL ext_466340(u8 *p);
extern "C" u32 THISCALL ext_4e11e0(u8 *self, u32 *pa, u32 b);
extern "C" u32 THISCALL ext_4e1b30(u8 *self);
extern "C" u32 THISCALL ext_4e3dc0(u8 *self, u32 *s);
extern "C" u32 THISCALL ext_5003d0(u8 *self, u32 a);
extern "C" u32 THISCALL ext_5a20d0(u8 *self, u32 a, u32 b);
extern "C" u32 THISCALL ext_5a0da0(u8 *self);
extern "C" u32 THISCALL ext_4daf90(u8 *self, u32 a);
extern "C" u32 THISCALL ext_4e5ea0(u8 *self);
extern "C" u32 THISCALL ext_4e5e40(u8 *self);

static u8 *THISCALL fn43de40(u8 *self, u32 a, u32 b, u32 c) {
  ext_45c3a0(self, a, b, c);  // @43de40_a
  *(u32 *)self = 0x67c3a4;  // @43de40_vt
  return self;
}
PCREG(43de40, fn43de40);

static u8 *THISCALL fn5e1160(u8 *self, u32 a, u32 b) {
  ext_5e0e10(self, a, b);  // @5e1160_a
  *(u32 *)self = 0x6b788c;  // @5e1160_vt
  self[0x54c] = 0;  // @5e1160_b
  return self;
}
PCREG(5e1160, fn5e1160);

static u32 STDCALL fn4681a0(u8 *p) {
  u32 loc = (u32)p;
  ext_466340(p);  // @4681a0_a
  ext_4e11e0(p, &loc, 1);  // @4681a0_b
  return ext_4e1b30(p);  // @4681a0_c
}
PCREG(4681a0, fn4681a0);

static u32 THISCALL fn5d8440(u8 *self) {
  volatile u32 local;
  u8 *dst = self + 0xb3;
  if (dst != (u8 *)&local) {
    u32 v = *(u32 *)(G(u8 *, 0x70039c) + 0x40) + 0x800;  // @5d8440_a
    __builtin_memcpy(dst, &v, 4);
  }
  u8 *p = G(u8 *, 0x7003a0);
  p[0x79] = 0;  // @5d8440_b
  return (u32)p;
}
PCREG(5d8440, fn5d8440);

static u32 THISCALL fn4e3e40(u8 *self, u32 a) {
  u8 *e = *(u8 **)(self + 0x14);
  u32 s[3];
  s[0] = (u32)(e + 0x14);  // @4e3e40_a
  s[1] = *(u32 *)e + (u32)e;  // @4e3e40_b
  s[2] = a;  // @4e3e40_c
  return ext_4e3dc0(e + 0x14, s);
}
PCREG(4e3e40, fn4e3e40);

static u32 THISCALL fn55b260(u8 *self, u8 *a) {
  u32 *r = (u32 *)ext_5003d0(*(u8 **)(a + 4), 0);  // @55b260_a
  ext_5a20d0(*(u8 **)(self + 0x1c), *r, 0);  // @55b260_b
  return ext_5a0da0(*(u8 **)(self + 0x1c));  // @55b260_c
}
PCREG(55b260, fn55b260);

static u32 THISCALL fn4875a0(u8 *self, u32 a) {
  u8 *m = *(u8 **)(self + 4);
  if (!m) return 0;
  ext_4daf90(*(u8 **)(m + 8), a);  // @4875a0_a
  return vcall<u32, u32>(*(u8 **)(self + 4), 0x84, a);  // @4875a0_b
}
PCREG(4875a0, fn4875a0);

typedef void (*Hook)();
static u32 THISCALL fn5c7cb0(u8 *self, u32 unused) {
  (void)unused;
  *(u32 *)(self + 4) &= 0xffffffbfu;  // @5c7cb0_a
  Hook h = G(Hook, 0x7003b0);
  if (!h) __asm__ volatile("int3");
  h();
  u32 r = ext_4e5ea0(0);  // @5c7cb0_b
  *(u32 *)(self + 0x48) = r;
  u32 e = ext_4e5e40(0);
  *(u16 *)(self + 0x4c) = (u16)e;  // @5c7cb0_c
  return (e & ~0xffu) | 1;  // @5c7cb0_d
}
PCREG(5c7cb0, fn5c7cb0);
