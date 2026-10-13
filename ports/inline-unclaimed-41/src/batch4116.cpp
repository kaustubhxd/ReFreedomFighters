// batch4116.cpp - unclaimed-41 batch 16 (slice 13): 0x5ec390 (name not in the map; GUESS).
#include "ff.h"

// 0x5ec390 (GUESS name): thiscall, five stack arguments (A, X, C, B, I; ret 0x14). Entry E = [[this+0x62] + 4*I].
// Stores A, C, B as words and X at E+0x20, +0x24, +0x26, +0x22; four floats at E+0x10, +0x14, +0x18, +0x1c; then copies
// those four dwords into [[ [this+0x3a]+4 ] + 40*I + 0xc .. +0x18]. If the words at E+0x28 and E+0x2a are not already C and B:
// store them, and E+8 = (float)C / (float)W4, E+0xc = (float)B / (float)W6, and this+0xa6 = 1.
static double signed_plus(s32 v) {
  return (double)v + (((u32)v >> 31) ? 4294967296.0 : 0.0);
}

static void THISCALL fn5ec390(u8 *self, u32 A, u32 X, u32 C, u32 B, u32 I) {
  s32 Ai = (s32)A, Xi = (s32)X, Ci = (s32)C, Bi = (s32)B;
  float half = G(float, 0x67a6ac);
  u8 *arr = *(u8 **)(self + 0x62);
  u8 *E = *(u8 **)(arr + 4 * I);
  *(u16 *)(E + 0x22) = (u16)X;
  *(u16 *)(E + 0x20) = (u16)A;
  *(u16 *)(E + 0x24) = (u16)C;
  *(u16 *)(E + 0x26) = (u16)B;
  float f0 = (float)signed_plus(Xi);
  s32 Y = *(s32 *)(self + 0x56);
  double dY = signed_plus(Y);
  *(float *)(E + 0x10) = (f0 + half) / (float)dY;
  double dB = signed_plus(Bi);
  float f2 = (float)dB;
  *(float *)(E + 0x14) = ((f2 + f0) - half) / (float)dY;
  double dA = signed_plus(Ai);
  float f4 = (float)dA;
  s32 Z = *(s32 *)(self + 0x52);
  double dZ = signed_plus(Z);
  *(float *)(E + 0x18) = (f4 + half) / (float)dZ;
  double dC = signed_plus(Ci);
  float f6 = (float)dC;
  double dZ2 = signed_plus(Z);
  *(float *)(E + 0x1c) = ((f6 + f4) - half) / (float)dZ2;
  u8 *q = *(u8 **)(*(u8 **)(self + 0x3a) + 4);
  u8 *dst = q + 40u * I;
  *(u32 *)(dst + 0xc) = *(u32 *)(E + 0x18);
  *(u32 *)(dst + 0x10) = *(u32 *)(E + 0x1c);
  *(u32 *)(dst + 0x14) = *(u32 *)(E + 0x14);
  *(u32 *)(dst + 0x18) = *(u32 *)(E + 0x10);
  u32 w28 = *(u16 *)(E + 0x28);
  u32 w2a = *(u16 *)(E + 0x2a);
  if (w28 == C && w2a == B)
    return;
  u32 w4 = *(u16 *)(E + 4);
  *(u16 *)(E + 0x28) = (u16)C;
  *(u16 *)(E + 0x2a) = (u16)B;
  float c_f = (float)Ci;
  *(float *)(E + 8) = c_f / (float)(s32)w4;
  u32 w6 = *(u16 *)(E + 6);
  *(float *)(E + 0xc) = (float)Bi / (float)(s32)w6;
  self[0xa6] = 1;
}
PCREG(5ec390, fn5ec390);
