// batch210013.cpp - Sonnet-w3a: small BLOCKED rows (table tail-dispatchers with assert fallback, field copy, slot loops)
#include "ff.h"

extern "C" u32 THISCALL ext_563110(u8 *self, u32 a, u32 b);
extern "C" u32 FASTCALL ext_4d1220(u8 *self, u32 edx);

static inline void st32(u8 *p, u32 v) { __builtin_memcpy(p, &v, 4); }
static inline u32 ld32(const u8 *p) { u32 v; __builtin_memcpy(&v, p, 4); return v; }

typedef u32 (*HookU)();
typedef u32 (THISCALL *DispFn)(u8 *, u8 *);

static u32 THISCALL fn50a440(u8 *self, u8 *a) {
  u32 idx = *(u16 *)(a + 0x10);
  if (idx < G(u32, 0x701128)) return G(DispFn, 0x701130 + idx * 4)(self, a);  // @50a440_a
  u8 *g = G(u8 *, 0x700390);
  u8 *o = (u8 *)vcall<u32, u32, u32>(g, 0x20, 0x69d214, 0x73);  // @50a440_b
  typedef u32 (*F)(u8 *, u32, u32);
  F f = *(F *)(*(u8 **)o + 0x2c);
  f(o, 0x69c6b0, 0x69ca40);  // @50a440_c
  HookU h = G(HookU, 0x7003b0);
  if (!h) __asm__ volatile("int3");
  return h();
}
PCREG(50a440, fn50a440);

static u32 THISCALL fn50b5c0(u8 *self, u8 *a) {
  u32 idx = *(u16 *)(a + 0x10);
  if (idx < G(u32, 0x7011f8)) return G(DispFn, 0x701200 + idx * 4)(self, a);  // @50b5c0_a
  u8 *g = G(u8 *, 0x700390);
  u8 *o = (u8 *)vcall<u32, u32, u32>(g, 0x20, 0x69d350, 0x79);  // @50b5c0_b
  typedef u32 (*F)(u8 *, u32, u32);
  F f = *(F *)(*(u8 **)o + 0x2c);
  f(o, 0x69c6b0, 0x69ca40);  // @50b5c0_c
  HookU h = G(HookU, 0x7003b0);
  if (!h) __asm__ volatile("int3");
  return h();
}
PCREG(50b5c0, fn50b5c0);

static u32 THISCALL fn50d820(u8 *self, u8 *a) {
  u32 idx = *(u16 *)(a + 0x10);
  if (idx < G(u32, 0x7012c8)) return G(DispFn, 0x7012d0 + idx * 4)(self, a);  // @50d820_a
  u8 *g = G(u8 *, 0x700390);
  u8 *o = (u8 *)vcall<u32, u32, u32>(g, 0x20, 0x69d420, 0x7d);  // @50d820_b
  typedef u32 (*F)(u8 *, u32, u32);
  F f = *(F *)(*(u8 **)o + 0x2c);
  f(o, 0x69c6b0, 0x69ca40);  // @50d820_c
  HookU h = G(HookU, 0x7003b0);
  if (!h) __asm__ volatile("int3");
  return h();
}
PCREG(50d820, fn50d820);

static u32 THISCALL fn510ed0(u8 *self, u8 *a) {
  u32 idx = *(u16 *)(a + 0x10);
  if (idx < G(u32, 0x701398)) return G(DispFn, 0x7013a0 + idx * 4)(self, a);  // @510ed0_a
  u8 *g = G(u8 *, 0x700390);
  u8 *o = (u8 *)vcall<u32, u32, u32>(g, 0x20, 0x69db34, 0xab);  // @510ed0_b
  typedef u32 (*F)(u8 *, u32, u32);
  F f = *(F *)(*(u8 **)o + 0x2c);
  f(o, 0x69c6b0, 0x69ca40);  // @510ed0_c
  HookU h = G(HookU, 0x7003b0);
  if (!h) __asm__ volatile("int3");
  return h();
}
PCREG(510ed0, fn510ed0);

static u32 THISCALL fn565020(u8 *self, u32 a, u32 b) {
  vcall<u32>(self, 0xf8);  // @565020_a
  u8 *m = (u8 *)ld32(self + 0xc5e);
  vcall<u32, u32>(m, 0x2c, ld32(self + 0xc66));  // @565020_b
  u32 r = ext_563110(self, a, b);  // @565020_c
  if ((u8)b) {
    r = vcall<u32, u32>(self, 0xfc, 0);  // @565020_d
    st32(self + 0xc9a, 0xa);  // @565020_e
    st32(self + 0xc96, 0);
    self[0x18b] = 0;  // @565020_f
  }
  return r & ~0xffu;
}
PCREG(565020, fn565020);

static u32 THISCALL fn56f190(u8 *self, u8 *a) {
  static const u16 offs[] = {0x19d, 0x1a1, 0x1a9, 0x199, 0x1a5, 0x1ad, 0x1b1, 0x1b5, 0x1b9, 0x1bd, 0x1c5};
  u32 v = 0;
  for (unsigned i = 0; i < 11; i++) {
    v = ld32(a + offs[i]);  // @56f190_a
    st32(self + offs[i], v);
  }
  return v;
}
PCREG(56f190, fn56f190);

static u32 THISCALL fn640400(u8 *self) {
  vcall<u32>(self, 0xb4);  // @640400_a
  vcall<u32>(self, 0xbc);  // @640400_b
  u32 r = vcall<u32>(self, 0xc8);  // @640400_c
  if (*(u32 *)(self + 0xec) != 0) {
    u32 i = 0;
    u8 *p = self + 0xf0;
    do {
      r = vcall<u32>(*(u8 **)p, 0x40);  // @640400_d
      i++;
      p += 4;
    } while (i != *(u32 *)(self + 0xec));  // @640400_e
  }
  return r;
}
PCREG(640400, fn640400);

static u32 FASTCALL fn4d1100(u8 *self, u32 edx) {
  u32 r = ext_4d1220(self, edx);  // @4d1100_a
  if (r == *(u32 *)(self + 0xc)) return (r & ~0xffu) | 1;  // @4d1100_b
  u8 *g = G(u8 *, 0x700390);
  u8 *o = (u8 *)vcall<u32, u32, u32>(g, 0x20, 0x695ec0, 0x46);  // @4d1100_c
  typedef u32 (*F)(u8 *, u32, u32);
  F f = *(F *)(*(u8 **)o + 0x2c);
  return f(o, 0x695ef0, *(u32 *)(self + 0xc) - r) & ~0xffu;  // @4d1100_d
}
PCREG(4d1100, fn4d1100);
