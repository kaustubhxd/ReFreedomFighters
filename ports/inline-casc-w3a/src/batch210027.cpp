// batch210027.cpp - Sonnet-w3a: small BLOCKED rows (tree walk, state-switch lookup, string ring buffer, assert-report, float-to-int setters)
#include "ff.h"

extern "C" u32 THISCALL ext_5003d0(u8 *self, u32 a);
extern "C" u32 THISCALL ext_5002f0(u8 *self, u32 a);
extern "C" u32 THISCALL ext_59d150(u8 *self, u32 a, u32 b);
extern "C" u32 ext_634273(u32 p, u32 flags);
extern "C" u32 ext_41e290(u32 n);
extern "C" u32 THISCALL ext_4e7ce0(u8 *self, int a);
extern "C" u32 THISCALL ext_4e7c50(u8 *self, int a);

static inline u32 ld32(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }
static inline u8 *mgr() { return (u8 *)ld32(G(u8 *, 0x70039c) + 0x9b); }

static u32 THISCALL fn441420(u8 *self, u8 **a) {
  if (*(u32 *)(self + 0x4c) == 0) {  // @441420_a
    u8 *v = *a;
    if (v == *(u8 **)(self + 8)) {  // @441420_b
      *a = 0;
      return (u32)v;
    }
  }
  u8 *esi = *a;
  u8 *meta = *(u8 **)(esi + 0x54);
  u32 key = meta ? ld32(*(u8 **)(meta + 0xc) + 0x23) : 0x200002;  // @441420_c
  if (key & 0x100000) {  // @441420_d
    u32 e = *(u32 *)(*(u8 **)(esi + 0x54) + 0x50);
    if (e) {
      *a = (u8 *)e;
      return e;
    }
  }
  for (;;) {
    u8 *cur = *a;
    u32 t = *(u32 *)(cur + 0x60);
    if (t) {  // @441420_e
      *a = (u8 *)t;
      return t;
    }
    u32 e = *(u32 *)(cur + 0x50);  // @441420_f
    *a = (u8 *)e;
    if (e == *(u32 *)(self + 8)) {
      *a = 0;
      return e;
    }
    if (!e) return e;
  }
}
PCREG(441420, fn441420);

static u32 THISCALL fn557ba0(u8 *self, u8 *a) {
  u32 state = *(u32 *)(*(u8 **)(*(u8 **)(self + 0x1c) + 0x54) + 8);  // @557ba0_a
  u32 edi;
  if (state == 2) edi = 0;  // @557ba0_b
  else if (state == 3) edi = 1;
  else return ext_5002f0((u8 *)ext_5003d0(*(u8 **)(a + 8), 0), 0);  // @557ba0_c
  u32 *x = (u32 *)ext_5003d0(*(u8 **)(a + 4), 0);  // @557ba0_d
  u32 al = ext_59d150((u8 *)ld32(G(u8 *, 0x7003b8) + 0x2c15), edi, *x) & 0xff;  // @557ba0_e
  return ext_5002f0((u8 *)ext_5003d0(*(u8 **)(a + 8), 0), al == 0);  // @557ba0_f
}
PCREG(557ba0, fn557ba0);

static u32 THISCALL fn4d4050(u8 *self, const u8 *s) {
  u32 idx = ld32(self + 0x10d3);
  u32 p = ld32(self + idx * 4 + 0xfb7);
  if (p) ext_634273(p, 1);  // @4d4050_a
  u32 n = 0;
  while (s[n]) n++;
  u8 *buf = (u8 *)ext_41e290(n + 1);  // @4d4050_b
  idx = ld32(self + 0x10d3);
  __builtin_memcpy(self + idx * 4 + 0xfb7, &buf, 4);  // @4d4050_c
  for (u32 i = 0; i <= n; i++) buf[i] = s[i];  // @4d4050_d
  idx = ld32(self + 0x10d3) + 1;
  __builtin_memcpy(self + 0x10d3, &idx, 4);
  if ((int)idx >= 0x14) {  // @4d4050_e
    idx = 0;
    __builtin_memcpy(self + 0x10d3, &idx, 4);
  }
  __builtin_memcpy(self + 0x10d7, &idx, 4);  // @4d4050_f
  return idx;
}
PCREG(4d4050, fn4d4050);

typedef u32 (*HookU)();
static u32 THISCALL fn508100(u8 *self, u8 *a) {
  u32 *x = (u32 *)ext_5003d0(*(u8 **)(a + 4), 0);  // @508100_a
  int v = (int)*x;
  if (v <= 0) {  // @508100_b
    u8 *g = G(u8 *, 0x700390);
    u8 *o = (u8 *)vcall<u32, u32, u32>(g, 0x20, 0x69cff0, 0xfe);  // @508100_c
    u8 *w = (u8 *)vcall<u32>(*(u8 **)(self + 0x18), 0x20);  // @508100_d
    u32 name = *(u32 *)(w + 4);
    if (!name) name = 0x67c8e8;  // @508100_e
    typedef u32 (*F)(u8 *, u32, u32);
    F f = *(F *)(*(u8 **)o + 0x2c);
    return f(o, 0x69d078, name);  // @508100_f
  }
  u32 t = *(u32 *)(mgr() + 0x44) + (u32)v;  // @508100_g
  return vcall<u32, u32>(*(u8 **)(self + 0x18), 0x69c, t);  // @508100_h
}
PCREG(508100, fn508100);

static u32 THISCALL fn4e78c0(u8 *self, u8 *a) {
  vcall<u32, u8 *>(a, 0x58, self);  // @4e78c0_a
  vcall<u32, u8 *>(a, 0x50, self + 4);  // @4e78c0_b
  u32 r = vcall<u32, u8 *>(a, 0x68, self + 8);  // @4e78c0_c
  vcall<u32, u8 *>(a, 0x50, self + 0xd);  // @4e78c0_d
  r = vcall<u32, u8 *>(a, 0x50, self + 0x11);
  if (ld32(self + 9) != 0) {  // @4e78c0_e
    float f1, f2;
    __builtin_memcpy(&f1, self + 0xd, 4);
    ext_4e7ce0(self, (int)f1);  // @4e78c0_f
    __builtin_memcpy(&f2, self + 0x11, 4);
    r = ext_4e7c50(self, (int)f2);  // @4e78c0_g
  }
  return r;
}
PCREG(4e78c0, fn4e78c0);
