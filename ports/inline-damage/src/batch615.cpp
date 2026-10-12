// batch615.cpp - damage thread, batch 615: DistanceBoxAndPoint (explosion and fire falloff distance).
#include "ff.h"

// |x| the way the exe does it: widen to double, clear the sign bit (mask at 0x67cd50), narrow again.
static inline float absViaDouble(float x) {
  double d = (double)x;
  u64 b = __builtin_bit_cast(u64, d) & 0x7fffffffffffffffull;
  asm("" : "+r"(b));
  return (float)__builtin_bit_cast(double, b);
}

static inline float sqrtf_d(float x) { return (float)crt::sqrt((double)x); }

// 0x4e2120 DistanceBoxAndPoint(const float* p, const float* halfSize) (GC 8026d5a0), fastcall, result in ST0.
// p is relative to the box centre. Per axis d = |p| - half size. Axes with d < 0 are inside; the result is the
// length of the outside part: one outside axis -> that d (with two axes inside it can be negative: the depth of the
// remaining axis), two -> hypot, three -> sqrt of the sum. The order of the tests (x, then z/y) is the exe's.
static float FASTCALL distanceBoxAndPoint(const float *p, const float *s) {
  float dx = absViaDouble(p[0]) - s[0];
  float dy = absViaDouble(p[1]) - s[1];
  float dz = absViaDouble(p[2]) - s[2];
  if (0.0f > dx) {
    if (0.0f > dz) return dy;
    if (0.0f > dy) return dz;
    return sqrtf_d(dz * dz + dy * dy);
  }
  if (0.0f > dy) {
    if (0.0f > dz) return dx;
    if (0.0f > dx) return dz;
    return sqrtf_d(dz * dz + dx * dx);
  }
  if (0.0f > dz) {
    if (0.0f > dx) return dy;
    if (0.0f > dy) return dx;
    return sqrtf_d(dy * dy + dx * dx);
  }
  return sqrtf_d(dy * dy + dx * dx + dz * dz);
}
PCREG(4e2120, distanceBoxAndPoint);
