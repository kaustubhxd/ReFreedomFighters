// batch801.cpp - gap band batch 801 (docs/20-gap-band-401000.md): 0x420450, thiscall, void. Single-precision SSE arithmetic (the exe uses
// mulss, cvttss2si and cvtdq2ps; plain C float with contraction off gives the same results).
#include "ff.h"

typedef int i32;

static void THISCALL fn420450(u8 *self) {
  const float c0 = G(float, 0x678620);
  const float f1 = *(float *)(self + 0x2c) * c0;
  const u32 ecx = *(const u32 *)(self + 0x40);
  const i32 e1 = (i32)f1;
  const i32 edx = (i32)ecx - e1;
  const float f2 = *(float *)(self + 0xa03) * c0;
  const i32 e2 = (i32)f2;
  if (e2 < edx) {
    *(float *)(self + 0x2c) = (float)(i32)ecx * G(float, 0x6785e4);
    u8 *c = self + 0xa0b;
    for (u32 k = 0; k < 0x100; ++k, c += 5) {
      if (*c & 1) *c &= 0xcf;
    }
    c = self + 0xf0b;
    for (u32 k = 0; k < 0x200; ++k, c += 5) {
      if (*c & 1) *c &= 0xcf;
    }
  }
}

PCREG(420450, fn420450);
