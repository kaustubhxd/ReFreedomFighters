// batch40.cpp - ladder-tree leaf, inline session batch 40 (Haiku, night): 0x460570 GetSplineVelocity (GetSplinePos 0x4604f0 is already in batch 21).
#include "ff.h"

// 0x460570, ParametricCurve::GetSplineVelocity(float out[3]&, float t) const, thiscall, two stack args, ret 8.
// The derivative of the same cubic: tt = (3t)*t, s2 = t+t. Each component is (c1*s2 + c0*tt) + c2 with the coefficient
// groups as in GetSplinePos. If all three results have magnitude below 2^-13 (a double compare, NaN never qualifies), the
// velocity is set to (0, 0, 1).
static void THISCALL getSplineVelocity(u8 *self, float *out, float t) {
  const float *f = (const float *)self;
  float tt = (3.0f * t) * t;
  float s2 = t + t;
  float x = f[2] * s2;
  x = x + f[1] * tt;
  x = x + f[3];
  out[0] = x;
  float y = f[6] * s2;
  y = y + f[5] * tt;
  y = y + f[7];
  out[1] = y;
  float z = f[10] * s2;
  z = z + f[9] * tt;
  z = z + f[11];
  out[2] = z;
  const double eps = 0.0001220703125;
  double a0 = (double)out[0];
  if (a0 < 0.0) a0 = -a0;
  double a1 = (double)out[1];
  if (a1 < 0.0) a1 = -a1;
  double a2 = (double)out[2];
  if (a2 < 0.0) a2 = -a2;
  if (eps > a0 && eps > a1 && eps > a2) {
    out[0] = 0.0f;
    out[1] = 0.0f;
    out[2] = 1.0f;
  }
}
PCREG(460570, getSplineVelocity);
