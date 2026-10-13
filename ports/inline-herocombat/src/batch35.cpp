// batch35.cpp - walk-tree lift, inline session batch 35 (Haiku, night): vnorm, vcross and ZMovementBase::DeltaTime.
// Under the 53-bit precision control (FPCW 0x27f) the x87 operations are IEEE double operations, so the ports compute in double
// and store once to float, which gives the same bits as the x87 code for the chains used here.
#include "ff.h"

// 0x44c840, thiscall (this in ECX), plain ret, returns the length in ST0 (a float). If all three components compare equal to
// 0.0 (ordered), the result is 0 and nothing is written. Otherwise the length L = sqrt((x*x + y*y) + z*z) is computed (crt::sqrt,
// correctly rounded like fsqrt), each component is scaled by 1.0 / L and stored as float, and the result is (float) L.
// Name vnorm.
static float THISCALL vnorm(float *v) {
  if (v[0] == 0.0f && v[1] == 0.0f && v[2] == 0.0f)
    return 0.0f;
  double x = v[0], y = v[1], z = v[2];
  double sum = ((x * x) + (y * y)) + (z * z);
  double len = crt::sqrt(sum);
  double inv = 1.0 / len;
  v[0] = (float)(x * inv);
  v[1] = (float)(y * inv);
  v[2] = (float)(z * inv);
  return (float)len;
}
PCREG(44c840, vnorm);

// 0x446ee0, fastcall (dst in ECX, a in EDX), one stack arg b, ret 4. The exe pushes six products (each exact in double) and combines
// them with three subtractions, then stores the three results. dst.x = a.y*b.z - a.z*b.y; dst.y = a.z*b.x - a.x*b.z;
// dst.z = a.x*b.y - a.y*b.x (the standard a x b). All reads happen before the stores. Name vcross.
static void FASTCALL vcross(float *dst, const float *a, const float *b) {
  double ax = a[0], ay = a[1], az = a[2];
  double bx = b[0], by = b[1], bz = b[2];
  double rx = (ay * bz) - (az * by);
  double ry = (az * bx) - (ax * bz);
  double rz = (ax * by) - (ay * bx);
  dst[0] = (float)rx;
  dst[1] = (float)ry;
  dst[2] = (float)rz;
}
PCREG(446ee0, vcross);

// 0x488460, thiscall, no args, plain ret, returns in ST0. If the float at this+0x18 equals 0.0 (ordered), the result is the float at
// +0x48 of the object whose pointer is the global at 0x70039c. Otherwise the result is the float at this+0x18. Name
// ZMovementBase::DeltaTime.
static float THISCALL deltaTime(u8 *self) {
  float x = *(float *)(self + 0x18);
  if (x == 0.0f) {
    u8 *g = G(u8 *, 0x70039c);
    return *(float *)(g + 0x48);
  }
  return x;
}
PCREG(488460, deltaTime);
