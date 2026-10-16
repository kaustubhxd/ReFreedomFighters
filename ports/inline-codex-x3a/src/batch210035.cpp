// batch210035.cpp - Sonnet-w3a: small BLOCKED rows (iterator step with assert, engine lookup store, pool slot find-or-create)
#include "ff.h"

extern "C" u32 THISCALL ext_5003d0(u8 *self, u32 a);
extern "C" u32 THISCALL ext_5002f0(u8 *self, u32 a);
extern "C" u32 THISCALL ext_506040(u8 *self);
extern "C" u32 THISCALL ext_4cfbe0(u8 *self);

static inline u32 ld32(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }
typedef u32 (*HookU)();

static u32 THISCALL fn4cf2d0(u8 *self, u8 **e) {
  if ((int)*(u32 *)(self + 0xc) < 0) {  // @4cf2d0_a
    u8 *g = G(u8 *, 0x700390);
    u8 *o = (u8 *)vcall<u32, u32, u32>(g, 0x20, 0x695b7c, 0x188);  // @4cf2d0_b
    typedef u32 (*F)(u8 *, u32);
    F f = *(F *)(*(u8 **)o + 0x2c);
    f(o, 0x695bc8);  // @4cf2d0_c
    HookU h = G(HookU, 0x7003b0);
    if (!h) __asm__ volatile("int3");
    h();
  }
  if (*(u32 *)((u8 *)e + 4) == *(u32 *)(self + 0x10)) {  // @4cf2d0_d
    u8 *cur = e[0];
    *(u32 *)((u8 *)e + 4) = 0;
    e[0] = *(u8 **)(cur + 4);  // @4cf2d0_e
  }
  u8 *ecx = e[0];
  if (!ecx) return 0;
  u32 edi = *(u32 *)((u8 *)e + 4);
  if (edi == *(u32 *)(*(u8 **)(self + 8) + 8) && *(u32 *)(ecx + 4) == 0) {  // @4cf2d0_f
    e[0] = 0;
    return 0;
  }
  u32 r = (u32)(ecx + 0x10) + edi * 4;  // @4cf2d0_g
  *(u32 *)((u8 *)e + 4) = *(u32 *)(self + 0x18) + edi;  // @4cf2d0_h
  return r;
}
PCREG(4cf2d0, fn4cf2d0);

static u32 STDCALL fn511090(u8 *a) {
  u8 *eng = G(u8 *, 0x70039c);
  u8 *e = (u8 *)ld32(eng + 0x1a9f);
  if (!e) return ext_5002f0((u8 *)ext_5003d0(*(u8 **)(a + 8), 0), 0);  // @511090_a
  u8 *vt = *(u8 **)e;
  u8 *x = (u8 *)ext_5003d0(*(u8 **)(a + 4), 0);  // @511090_b
  u32 y = ext_506040(x);  // @511090_c
  typedef u32 (THISCALL *F)(u8 *, u32);
  u32 r = (*(F *)(vt + 0x6c))((u8 *)ld32(G(u8 *, 0x70039c) + 0x1a9f), y);  // @511090_d
  u8 *z = (u8 *)ext_5003d0(*(u8 **)(a + 8), 0);  // @511090_e
  if (z[4] <= 1) {  // @511090_f
    *(u32 *)z = r;  // @511090_g
    z[4] = 1;
    return (u32)z;
  }
  u8 *g = G(u8 *, 0x700390);
  u8 *o = (u8 *)vcall<u32, u32, u32>(g, 0x20, 0x69c8e0, 0xc4);  // @511090_h
  typedef u32 (*F3)(u8 *, u32, u32);
  F3 f = *(F3 *)(*(u8 **)o + 0x2c);
  f(o, 0x69c6b0, 0x69c938);  // @511090_i
  HookU h = G(HookU, 0x7003b0);
  if (!h) __asm__ volatile("int3");
  return h();
}
PCREG(511090, fn511090);

static u32 THISCALL fn4d0590(u8 *self, u32 a) {
  u8 *sub = self + 0x1cc;
  u8 *p = (u8 *)vcall<u32, u32, u32>(sub, 0xc, a + 0x10, 0);  // @4d0590_a
  if (!p) {
    p = (u8 *)ext_4cfbe0(self);  // @4d0590_b
    if (!p) {
      u8 *g = G(u8 *, 0x700390);
      u8 *o = (u8 *)vcall<u32, u32, u32>(g, 0x20, 0x695dc0, 0x432);  // @4d0590_c
      typedef u32 (*F3)(u8 *, u32, u32);
      F3 f = *(F3 *)(*(u8 **)o + 0x2c);
      f(o, 0x695e98, a);  // @4d0590_d
      vcall<u32>(G(u8 *, 0x70038c), 0x78);  // @4d0590_e
      HookU h = G(HookU, 0x7003b0);
      if (!h) __asm__ volatile("int3");
      h();
      h = G(HookU, 0x7003b0);
      if (!h) __asm__ volatile("int3");
      h();
      return 0;
    }
  }
  u8 *q = (u8 *)ld32(p + 0x11);
  if ((int)*(u32 *)(q + 8) < (int)a) {  // @4d0590_f
    HookU h = G(HookU, 0x7003b0);
    if (!h) __asm__ volatile("int3");
    h();
  }
  return (u32)p;
}
PCREG(4d0590, fn4d0590);
