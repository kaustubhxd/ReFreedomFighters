// batch380.cpp - 0x411076 (gap band). cdecl(out, a, b) returning out. Cross product a x b (3-vectors of floats); each component is
// computed in extended precision (long double, the x87 stack) and rounded to float once when stored:
// out[0] = b.z*a.y - a.z*b.y; out[1] = a.z*b.x - b.z*a.x; out[2] = a.x*b.y - b.x*a.y.
#include "ff.h"

static float *crossProduct3(float *out, const float *a, const float *b) {
  float t0 = (float)((long double)b[2] * (long double)a[1] - (long double)a[2] * (long double)b[1]);
  float t1 = (float)((long double)a[2] * (long double)b[0] - (long double)b[2] * (long double)a[0]);
  float t2 = (float)((long double)a[0] * (long double)b[1] - (long double)b[0] * (long double)a[1]);
  out[0] = t0;
  out[1] = t1;
  out[2] = t2;
  return out;
}
PCREG(411076, crossProduct3);
