// batch42011.cpp - Sonnet t3: tier H, float return (x87 st0).
#include "ff.h"

// 0x4dfe60, fastcall(out = ecx, in = edx), plain ret, returns float in st0: out = in (2 floats); when x == 0 && y == 0 returns 0; otherwise len = float(sqrt(double(x*x + y*y)));
// len == 0 (ordered) returns 0 with out = in; else out = in * (K / len), returns len. NaN inputs take the normalise path.
static float FASTCALL fn4dfe60(float *out, float *in) {
  float x = in[0], y = in[1];
  out[0] = x;
  out[1] = y;
  if (x == 0.0f && y == 0.0f) return 0.0f;
  float len = (float)crt::sqrt((double)(x * x + y * y));
  if (len == 0.0f) return 0.0f;
  float inv = G(float, 0x678858) / len;
  out[0] = x * inv;
  out[1] = y * inv;
  return len;
}
PCREG(4dfe60, fn4dfe60);
