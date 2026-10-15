// batch43001.cpp - t4 (Sonnet) batch 43001: tier H float/SSE functions
#include "ff.h"

extern "C" float THISCALL ext_4e5e80(u8 *a);                    // float in st0
extern "C" double VECTORCALL ext_634db2(double, double);        // CRT pow thunk
extern "C" void THISCALL ext_52cea0(u8 *self, u32 a);           // thiscall ret 4
extern "C" void THISCALL ext_52cf60(u8 *self, u32 a);           // thiscall ret 4

// 0x5272e0, thiscall no args: v = [this+0x14]; p = [this+4] + [sys+0x48] * [this+0x10] * v (stored back); when v < 0 and p <= [this+8] + K,
// or v > 0 and p > [this+8] - K (K = float at 0x679540): [this+0x19] = 2 (dword, unaligned), byte [this+0x18] = 1, [this+4] = [this+8]
static void THISCALL fn5272e0(u8 *self) {
  float v = *(float *)(self + 0x14);
  float p = *(float *)(G(u8 *, 0x70039c) + 0x48) * *(float *)(self + 0x10);
  p = p * v + *(float *)(self + 4);
  *(float *)(self + 4) = p;
  float t = *(float *)(self + 8);
  float k = G(float, 0x679540);
  if (0.0f > v) {
    if (t + k >= p) {
      u8 *d = self + 0x19;
      d[0] = 2; d[1] = 0; d[2] = 0; d[3] = 0;
      self[0x18] = 1;
      *(float *)(self + 4) = t;
    }
  } else if (v > 0.0f) {
    if (p > t - k) {
      u8 *d = self + 0x19;
      d[0] = 2; d[1] = 0; d[2] = 0; d[3] = 0;
      self[0x18] = 1;
      *(float *)(self + 4) = t;
    }
  }
}
PCREG(5272e0, fn5272e0);

// 0x52a300, thiscall(a) ret 4, returns this: 0x52cea0(this, a), 0x52cea0(this+0x51, a), 0x52cf60(this+0xa2, a); then copies the constant
// blocks 0x6a0efc (16 bytes) -> this+0x51, byte 0x6a0f0c -> this+0x61, 0x6a0f10 (16) -> this, 0x6a0f20 (8) -> this+0x10, byte 0x6a0f28 -> this+0x18
static u8 *THISCALL fn52a300(u8 *self, u32 a) {
  ext_52cea0(self, a);
  ext_52cea0(self + 0x51, a);
  ext_52cf60(self + 0xa2, a);
  u8 *s;
  s = (u8 *)0x6a0efc;
  for (int i = 0; i < 16; i++) self[0x51 + i] = s[i];
  self[0x61] = *(u8 *)0x6a0f0c;
  s = (u8 *)0x6a0f10;
  for (int i = 0; i < 16; i++) self[i] = s[i];
  s = (u8 *)0x6a0f20;
  for (int i = 0; i < 8; i++) self[0x10 + i] = s[i];
  self[0x18] = *(u8 *)0x6a0f28;
  return self;
}
PCREG(52a300, fn52a300);

// 0x4b0f90, thiscall(a) ret 4: [this+0x5c], [this+0x58], [this+0x54] = three floats from a->0x4e5e80(); f = fourth; [this+0x64] = (float)(K3 / pow(K2, (double)f / K1))
// (K1 float at 0x67da20, K2 double at 0x692790, K3 double at 0x678610)
static void THISCALL fn4b0f90(u8 *self, u8 *a) {
  float f0 = ext_4e5e80(a);
  *(float *)(self + 0x5c) = f0;
  float f1 = ext_4e5e80(a);
  *(float *)(self + 0x58) = f1;
  float f2 = ext_4e5e80(a);
  *(float *)(self + 0x54) = f2;
  float f3 = ext_4e5e80(a);
  double e = (double)f3 / (double)G(float, 0x67da20);
  double r = G(double, 0x678610) / ext_634db2(G(double, 0x692790), e);
  *(float *)(self + 0x64) = (float)r;
}
PCREG(4b0f90, fn4b0f90);
