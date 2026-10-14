// batch32084.cpp - cascade h2 (): eight tier C wrappers (fourth batch).
#include "ff.h"

extern "C" u32 THISCALL ext_51d0d0(u8 *self);                 // thiscall, plain ret
extern "C" u32 THISCALL ext_5003d0(u8 *self, u32 a);          // thiscall ret 4
extern "C" u32 THISCALL ext_5002f0(u8 *self, u32 a);          // thiscall ret 4
extern "C" void ext_634d10(void *p, u32 v, u32 n);            // memset-style, cdecl
extern "C" u32 FASTCALL ext_4de420(void *dst, const void *src);  // 36-byte copy (verified), eax = last dword copied

// 0x51ecd0, thiscall(a) ret 4: v = 0x51d0d0([this+0x18]); r = 0x5003d0([a+8], 0); returns 0x5002f0(r, v).
static u32 THISCALL fn51ecd0(u8 *self, u8 *a) {
  u32 v = ext_51d0d0(*(u8 **)(self + 0x18));
  u32 r = ext_5003d0(*(u8 **)(a + 8), 0);
  return ext_5002f0((u8 *)r, v);
}
PCREG(51ecd0, fn51ecd0);

// 0x5228b0, thiscall(a) ret 4: v = slot 0x394 of [this+0x1c]; r = 0x5003d0([a+8], 0); returns 0x5002f0(r, v).
static u32 THISCALL fn5228b0(u8 *self, u8 *a) {
  u32 v = vcall<u32>(*(void **)(self + 0x1c), 0x394);
  u32 r = ext_5003d0(*(u8 **)(a + 8), 0);
  return ext_5002f0((u8 *)r, v);
}
PCREG(5228b0, fn5228b0);

// 0x5c7f30, thiscall(o) ret 4, returns true: slot 0x68 of o with this+0x1d.
static bool THISCALL fn5c7f30(u8 *self, void *o) {
  vcall<void>(o, 0x68, (u32)(self + 0x1d));
  return true;
}
PCREG(5c7f30, fn5c7f30);

// 0x50d770 / 0x560320, stdcall(ignored) ret 4: memset(block, 0, 0xc8); counter = 0; object = global; object != 0 -> slot 0 of it with 1; global = 0.
static void STDCALL fn50d770(u32) {
  ext_634d10((void *)0x7012d0, 0, 0xc8);
  void *o = G(void *, 0x7012cc);
  G(u32, 0x7012c8) = 0;
  if (o) vcall<void>(o, 0, 1u);
  G(u32, 0x7012cc) = 0;
}
PCREG(50d770, fn50d770);
static void STDCALL fn560320(u32) {
  ext_634d10((void *)0x7141a0, 0, 0xc8);
  void *o = G(void *, 0x71419c);
  G(u32, 0x714198) = 0;
  if (o) vcall<void>(o, 0, 1u);
  G(u32, 0x71419c) = 0;
}
PCREG(560320, fn560320);

// 0x5f9700, thiscall(a, ignored) ret 8, returns this: [this] = 0x69c968; slot 0x5c of a with this+4.
static u8 *THISCALL fn5f9700(u8 *self, void *a, u32) {
  *(u32 *)self = 0x69c968;
  vcall<void>(a, 0x5c, (u32)(self + 4));
  return self;
}
PCREG(5f9700, fn5f9700);

// 0x656f80, thiscall(a) ret 4: r = slot 0xc of this with a; returns slot 0xc of this with [r+0x88].
static u32 THISCALL fn656f80(void *self, u32 a) {
  u8 *r = vcall<u8 *>(self, 0xc, a);
  return vcall<u32>(self, 0xc, *(u32 *)(r + 0x88));
}
PCREG(656f80, fn656f80);

// 0x464730, thiscall(a) ret 4: e = [this+8]; word [e+0x5a] != 0 -> r = slot 0x58 of [this+0x6c] with this; return 0x4de420(r, a) (copy of 36 bytes, eax = its eax); else eax = e.
static u32 THISCALL fn464730(u8 *self, u8 *a) {
  u8 *e = *(u8 **)(self + 8);
  if (e[0x5a] | e[0x5b]) {
    u8 *r = vcall<u8 *>(*(void **)(self + 0x6c), 0x58, (u32)self);
    return ext_4de420(r, a);
  }
  return (u32)e;
}
PCREG(464730, fn464730);
