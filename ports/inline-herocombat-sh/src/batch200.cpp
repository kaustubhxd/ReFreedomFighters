// batch200.cpp - ladder tree (inline-ladder thread, 2026-10-11): spline arc length.
#include "ff.h"

// 0x45fe90, thiscall, one float stack arg h, ret 4, float return in ST0. Name used here: ParametricCurve::ArcLength
// (no GC name: the map has no match; the role is clear from the body). this is the cubic record of the ladder spline
// (coefficient groups at +4, +0x14, +0x24 as in GetSplineVelocity 0x460570). Trapezoid rule over t in [0, 1] with step
// h on the speed |P'(t)|, where P'(t) = (c1*2t + c0*3t*t) + c2 per axis. The running sum is kept in the float at
// +0x34 (zeroed first); the last partial step uses (1 - t) instead of h. Returns the sum.
// Constants from the exe: 1.0 at 0x678858, 3.0 at 0x680a68, 0.5 at 0x67a6ac.
static inline float speed(const float *f, float tt, float s2) {
  float x = f[2] * s2 + f[1] * tt;
  x = x + f[3];
  float y = f[6] * s2 + f[5] * tt;
  y = y + f[7];
  float z = f[10] * s2 + f[9] * tt;
  z = z + f[11];
  float s = y * y + x * x;
  s = s + z * z;
  return (float)crt::sqrt((double)s);
}

static float THISCALL arcLength(u8 *self, float h) {
  float *f = (float *)self;
  float c3x = f[3], c3y = f[7], c3z = f[11];     // read once at entry, as the exe does
  // t = 0: every product is coefficient * 0.0 (kept, so inf/NaN coefficients behave as in the exe)
  float x = f[1] * 0.0f + f[2] * 0.0f;
  x = x + c3x;
  float y = f[5] * 0.0f + f[6] * 0.0f;
  y = y + c3y;
  float z = f[9] * 0.0f + f[10] * 0.0f;
  z = z + c3z;
  *(u32 *)(self + 0x34) = 0;
  float s = y * y + x * x;
  s = s + z * z;
  float prev = (float)crt::sqrt((double)s);
  float omh = 1.0f - h;
  float t = 0.0f;
  if (omh >= 0.0f) {
    do {
      t = t + h;
      float tt = (t * 3.0f) * t;
      float s2 = t + t;
      float cur = speed(f, tt, s2);
      f[13] = ((cur + prev) * 0.5f) * h + f[13];
      prev = cur;
    } while (omh >= t);
  }
  // t = 1: P'(1) = (c1 + c1) + c0*3 + c2
  x = (f[2] + f[2]) + f[1] * 3.0f;
  x = x + c3x;
  y = (f[6] + f[6]) + f[5] * 3.0f;
  y = y + c3y;
  z = (f[10] + f[10]) + f[9] * 3.0f;
  z = z + c3z;
  s = y * y + x * x;
  s = s + z * z;
  float last = (float)crt::sqrt((double)s);
  float r = ((last + prev) * 0.5f) * (1.0f - t) + f[13];
  f[13] = r;
  return r;
}
PCREG(45fe90, arcLength);
