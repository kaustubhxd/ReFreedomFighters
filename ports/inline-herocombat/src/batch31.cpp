// batch31.cpp - walk-tree lift, inline session batch 31 (Haiku, evening): vsetlen and its CRT sqrt.
#include "ff.h"

// 0x4e0d80, thiscall, one float stack arg (s), ret 4. Let (a0, a1, a2) be the three floats at this. len2 = ((a0*a0) + (a1*a1))
// + (a2*a2) in float; len = (float) sqrt((double) len2), with the sqrt going through the CRT libm import at 0x634d7c (a thunk
// to _libm_sse2_sqrt_precise). The three floats are scaled by s / len only when len is not equal to 0.0 in an ordered compare.
// A NaN length takes the scaling path. Name vsetlen.
static void THISCALL vsetlen(float *v, float s) {
  float a0 = v[0], a1 = v[1], a2 = v[2];
  float len2 = a0 * a0 + a1 * a1;
  len2 = len2 + a2 * a2;
  float len = (float)crt::sqrt((double)len2);
  if (len == 0.0f)
    return;
  float r = s / len;
  v[0] = a0 * r;
  v[1] = a1 * r;
  v[2] = a2 * r;
}
PCREG(4e0d80, vsetlen);
