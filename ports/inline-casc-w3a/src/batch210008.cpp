// batch210008.cpp - Sonnet-w3a: small BLOCKED rows (table dispatchers with index rebasing, assert-fail tail, ctors)
#include "ff.h"

extern "C" u32 THISCALL ext_504560(u8 *self, u8 *a);
extern "C" u32 THISCALL ext_51b600(u8 *self, u8 *a);
extern "C" u32 THISCALL ext_5fa270(u8 *self, u8 *a);
extern "C" u32 THISCALL ext_564fd0(u8 *self, u32 a);
extern "C" u32 THISCALL ext_564600(u8 *self, u32 a);
extern "C" u32 THISCALL ext_43de40(u8 *self, u32 a, u32 b, u32 c);

typedef u32 (THISCALL *DispFn)(u8 *, u8 *);

static u32 THISCALL fn5060b0(u8 *self, u8 *a) {
  u32 idx = *(u16 *)(a + 0x10);
  u32 n = G(u32, 0x700f7c);
  if (idx < n) return G(DispFn, 0x700f80 + idx * 4)(self, a);  // @5060b0_a
  *(u16 *)(a + 0x10) = (u16)(idx - n);  // @5060b0_b
  return ext_504560(self, a);  // @5060b0_c
}
PCREG(5060b0, fn5060b0);

static u32 THISCALL fn51ff40(u8 *self, u8 *a) {
  u32 idx = *(u16 *)(a + 0x10);
  u32 n = G(u32, 0x7019a8);
  if (idx < n) return G(DispFn, 0x7019b0 + idx * 4)(self, a);  // @51ff40_a
  *(u16 *)(a + 0x10) = (u16)(idx - n);  // @51ff40_b
  return ext_51b600(self, a);  // @51ff40_c
}
PCREG(51ff40, fn51ff40);

static u32 THISCALL fn603d90(u8 *self, u8 *a) {
  u32 idx = *(u16 *)(a + 0x10);
  u32 n = G(u32, 0x724698);
  if (idx < n) return G(DispFn, 0x7246a0 + idx * 4)(self, a);  // @603d90_a
  *(u16 *)(a + 0x10) = (u16)(idx - n);  // @603d90_b
  return ext_5fa270(self, a);  // @603d90_c
}
PCREG(603d90, fn603d90);

static u32 THISCALL fn6053c0(u8 *self, u8 *a) {
  u32 idx = *(u16 *)(a + 0x10);
  u32 n = G(u32, 0x724768);
  if (idx < n) return G(DispFn, 0x724770 + idx * 4)(self, a);  // @6053c0_a
  *(u16 *)(a + 0x10) = (u16)(idx - n);  // @6053c0_b
  return ext_5fa270(self, a);  // @6053c0_c
}
PCREG(6053c0, fn6053c0);

typedef u32 (*HookU)();
static u32 fn602d30() {
  u32 v = G(u32, 0x724694);
  if (v) return v;
  u8 *g = G(u8 *, 0x700390);
  u8 *o = (u8 *)vcall<u32, u32, u32>(g, 0x20, 0x6b98c8, 0x27);  // @602d30_a
  typedef u32 (*F)(u8 *, u32, u32);
  F f = *(F *)(*(u8 **)o + 0x2c);
  f(o, 0x69c6b0, 0x6b98fc);  // @602d30_b
  HookU h = G(HookU, 0x7003b0);
  if (!h) __asm__ volatile("int3");
  return h();
}
PCREG(602d30, fn602d30);

static u8 *THISCALL fn52cec0(u8 *self, u32 a, u32 b) {
  *(u32 *)(self + 4) = a;  // @52cec0_a
  *(u32 *)(self + 8) = b;  // @52cec0_b
  *(u32 *)(self + 0xc) = 0;
  u8 *eng = G(u8 *, 0x70039c);
  *(u32 *)self = vcall<u32, u32, u32>(eng, 0x1c8, 0x6a13d8, 0x23);  // @52cec0_c
  self[0x10] = 1;  // @52cec0_d
  return self;
}
PCREG(52cec0, fn52cec0);

static u8 THISCALL fn565b20(u8 *self, u32 a) {
  ext_564fd0(self, a);  // @565b20_a
  u8 r = (u8)vcall<u32>(self, 0xd8);  // @565b20_b
  if (!r && a == 1) ext_564600(self, 7);  // @565b20_c
  return 0;
}
PCREG(565b20, fn565b20);

static u8 *THISCALL fn573650(u8 *self, u32 a, u32 b, u32 c) {
  ext_43de40(self, a, b, c);  // @573650_a
  *(u32 *)self = 0x6a8d30;  // @573650_vt
  *(u32 *)(self + 0x28) = 0;  // @573650_b
  *(u32 *)(self + 0x18) = 0;
  *(u32 *)(self + 0x1c) = 0;
  *(u32 *)(self + 0x20) = 0;
  *(u32 *)(self + 0x24) = 0;  // @573650_c
  return self;
}
PCREG(573650, fn573650);
