// batch13010.cpp - fresh slice 13, batch 10 (docs/20-fresh-13.md), 2026-10-12. Two GUESS functions (no name map entries).
//
// 0x655110: thiscall, three arguments forwarded to this->vtbl[+0x230] (the epilogue is a bare `pop ebp; ret 0xc` with no
// esp restore, so the callee pops 0xc). Then flag bits on the system object *(0x70039c) (GUESS: two timer/state records at
// +0xa11 and +0x13fd with flag bytes +0xa15/+0xad8 and +0x1401/+0x13f7): set 0x80 and 0x20, clear 0x80 in the paired
// bytes; bit 0x10 is set when ticks(+0x40) - trunc(+0xa11 * 1024) < 256 (signed), else cleared; then both +0xa11 and
// +0x13fd = ticks / 1024 (float).
//
// 0x656b50: stdcall (dst, src) (ret 8, ecx unused). Copies a cone/range record (GUESS): +0x10/+0x14 raw, +0x18 =
// min(src+0x18, src+0x1c - 1), +0x1c, +0x20 = 1 / (+0x1c - +0x18), +0x24/+0x28 raw, +0x30 = cos(+0x28), +0x2c = cos(+0x24)
// (CRT _libm_sse2_cos_precise, double), +0x34 = 1 when +0x24 - +0x28 == 0, else 1 / (+0x30 - +0x2c).
#include "ff.h"

#define AT(T, p, off) (*(T *)((u8 *)(p) + (off)))

typedef void(THISCALL *V3)(void *self, u32 a, u32 b, u32 c);

static void THISCALL fn655110(u8 *self, u32 a, u32 b, u32 c) {
  ((V3)(*(u32 *)(*(u32 *)self + 0x230)))(self, a, b, c);
  AT(u8, G(u32, 0x70039c), 0xa15) |= 0x80;
  AT(u8, G(u32, 0x70039c), 0xad8) &= 0x7f;
  AT(u8, G(u32, 0x70039c), 0xa15) |= 0x20;
  AT(u8, G(u32, 0x70039c), 0x1401) |= 0x80;
  AT(u8, G(u32, 0x70039c), 0x13f7) &= 0x7f;
  AT(u8, G(u32, 0x70039c), 0x1401) |= 0x20;
  u8 *sys = (u8 *)G(u32, 0x70039c);
  s32 t = _mm_cvttss_si32(_mm_set_ss(AT(float, sys, 0xa11) * G(float, 0x678620)));
  if ((s32)(AT(u32, sys, 0x40) - (u32)t) < 0x100) {
    AT(u8, sys, 0xa15) |= 0x10;
    AT(u8, G(u32, 0x70039c), 0x1401) |= 0x10;
  } else {
    AT(u8, sys, 0xa15) &= 0xef;
    AT(u8, G(u32, 0x70039c), 0x1401) &= 0xef;
  }
  u8 *s2 = (u8 *)G(u32, 0x70039c);
  AT(float, s2, 0xa11) = (float)AT(s32, s2, 0x40) * G(float, 0x6785e4);
  s2 = (u8 *)G(u32, 0x70039c);
  AT(float, s2, 0x13fd) = (float)AT(s32, s2, 0x40) * G(float, 0x6785e4);
}
PCREG(655110, fn655110);

static void STDCALL fn656b50(u8 *dst, u8 *src) {
  float one = G(float, 0x678858);
  AT(u32, dst, 0x10) = AT(u32, src, 0x10);
  AT(u32, dst, 0x14) = AT(u32, src, 0x14);
  float x1 = AT(float, src, 0x1c) - one;
  float x2 = AT(float, src, 0x18);
  if (x2 > x1)
    AT(float, dst, 0x18) = x1;
  else
    AT(float, dst, 0x18) = x2;
  float e = AT(float, src, 0x1c);
  AT(float, dst, 0x1c) = e;
  AT(float, dst, 0x20) = one / (e - AT(float, dst, 0x18));
  AT(u32, dst, 0x28) = AT(u32, src, 0x28);
  AT(u32, dst, 0x24) = AT(u32, src, 0x24);
  AT(float, dst, 0x30) = (float)crt::cos((double)AT(float, src, 0x28));
  float c24 = (float)crt::cos((double)AT(float, src, 0x24));
  AT(float, dst, 0x2c) = c24;
  if (AT(float, src, 0x24) - AT(float, src, 0x28) == G(float, 0x6785d0))
    AT(u32, dst, 0x34) = 0x3f800000;
  else
    AT(float, dst, 0x34) = G(float, 0x678858) / (AT(float, dst, 0x30) - c24);
}
PCREG(656b50, fn656b50);
