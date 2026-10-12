// batch229.cpp - unclaimed area 22 (docs/20-unclaimed-22.md), slice floor(addr/16) mod 20 == 1. Single-precision frame math
// with one tan call (0x634dac is a thunk to the libm slot that ff.h calls crt::tan). Name GUESS.
#include "ff.h"

// 0x5a5dd0, thiscall(out, f1, f2, P, B) ret 0x14:
//   t = 2 * P->[8]->[0x44]; r = t / this[0x2f4]; if this[0x658] != 0 and this[0x8d0] == 2: r *= c1 (c1 = [0x67a6ac]);
//   c = B[0x5c] * c1; f = (float)(K / tan(c)) with K = [0x68c740] (double); s = (t * f) / r; m = s / f;
//   out[0] = m * f1; out[1] = -((m * f2) / B[0x40]); out[2] = s.
static void THISCALL frameFromTan_5a5dd0(u8 *self, float *out, float f1, float f2, u8 *P, u8 *B) {
  const float c1 = G(float, 0x67a6ac);
  float x = *(float *)(*(u8 **)(P + 8) + 0x44);
  float t = x + x;
  float r = t / *(float *)(self + 0x2f4);
  if (self[0x658] != 0 && *(u32 *)(self + 0x8d0) == 2) r = r * c1;
  float c = *(float *)(B + 0x5c) * c1;
  double tanv = crt::tan((double)c);
  double kd = G(double, 0x68c740) / tanv;
  float f = (float)kd;
  float s = (t * f) / r;
  float m = s / f;
  out[0] = m * f1;
  float m0 = (m * f2) / *(float *)(B + 0x40);
  out[1] = bitsf(fbits(m0) ^ G(u32, 0x67af40));
  out[2] = s;
}
PCREG(5a5dd0, frameFromTan_5a5dd0);
