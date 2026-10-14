// batch32083.cpp - cascade h2 (): eight tier C vtable-slot / import wrappers (third batch).
#include "ff.h"

extern "C" u32 THISCALL ext_533e00(u8 *self);   // thiscall, plain ret
typedef u32 (STDCALL *imp2_t)(u32, u32);
typedef u32 (*fn0_t)();

// 0x4efdd0, thiscall(a, b, c, d) ret 0x10: slot 0x224 of this with (a, b, c, d, byte [this+0x8f]).
static u32 THISCALL fn4efdd0(u8 *self, u32 a, u32 b, u32 c, u32 d) {
  return vcall<u32>(self, 0x224, a, b, c, d, (u32)self[0x8f]);
}
PCREG(4efdd0, fn4efdd0);

// 0x535570, thiscall no args: r = 0x533e00(this+0x8b); r == 0 -> 0; else slot 0x60 of the engine table ([[0x70039c]+0x9b]) with r.
static u32 THISCALL fn535570(u8 *self) {
  u32 r = ext_533e00(self + 0x8b);
  if (!r) return 0;
  u8 *tbl = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  return vcall<u32>(tbl, 0x60, r);
}
PCREG(535570, fn535570);

// 0x5c7720, thiscall(o) ret 4, returns true: [this+4] &= ~0x40; slot 0x60 of o with byte [this+0x54].
static bool THISCALL fn5c7720(u8 *self, void *o) {
  *(u32 *)(self + 4) &= 0xffffffbf;
  vcall<void>(o, 0x60, (u32)self[0x54]);
  return true;
}
PCREG(5c7720, fn5c7720);

// 0x421ea0, stdcall(p) ret 4: p != 0 -> f = import 0x6760b4([p+8], 0x678174); f != 0 -> f().
static void STDCALL fn421ea0(u8 *p) {
  if (!p) return;
  u32 f = G(imp2_t, 0x6760b4)(*(u32 *)(p + 8), 0x678174);
  if (f) ((fn0_t)f)();
}
PCREG(421ea0, fn421ea0);

// 0x445390, thiscall no args: bit 0x20 of [this+0x48] clear -> o = [[0x70039c]+0x190f] (unaligned); o != 0 -> slot 0x2c of o; then set the bit.
static void THISCALL fn445390(u8 *self) {
  if (*(u32 *)(self + 0x48) & 0x20) return;
  u8 *eng = G(u8 *, 0x70039c);
  u32 ov = eng[0x190f] | (eng[0x1910] << 8) | (eng[0x1911] << 16) | ((u32)eng[0x1912] << 24);
  if (ov) vcall<void>((void *)ov, 0x2c);
  *(u32 *)(self + 0x48) |= 0x20;
}
PCREG(445390, fn445390);

// 0x466870, thiscall(a, b, c) ret 0xc: slot 0x10 of [this+0x6c] with (b, c, a, this).
static u32 THISCALL fn466870(u8 *self, u32 a, u32 b, u32 c) {
  void *o = *(void **)(self + 0x6c);
  return vcall<u32>(o, 0x10, b, c, a, (u32)self);
}
PCREG(466870, fn466870);

// 0x470c20, thiscall(a) ret 4: [this+0xb6] = slot 0x4c of the engine table with a (unaligned store).
static void THISCALL fn470c20(u8 *self, u32 a) {
  u8 *tbl = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  u32 v = vcall<u32>(tbl, 0x4c, a);
  self[0xb6] = v; self[0xb7] = v >> 8; self[0xb8] = v >> 16; self[0xb9] = v >> 24;
}
PCREG(470c20, fn470c20);

// 0x4759f0, thiscall(a) ret 4: o = slot 0x504 of this; o != 0 -> slot 0x2d0 of o with (a, 0), its result is returned; else o (0).
static u32 THISCALL fn4759f0(void *self, u32 a) {
  void *o = vcall<void *>(self, 0x504);
  if (!o) return 0;
  return vcall<u32>(o, 0x2d0, a, 0u);
}
PCREG(4759f0, fn4759f0);
