// batch71000.cpp - cascade t2 (Haiku): tier H float functions 0x5d6960.
#include "ff.h"

// 0x43e920: fastcall(edx, ecx, [esp]) ret 4, computes v1 - v2, stores in v3
extern "C" void FASTCALL ext_43e920(u8 *v2, u8 *result, u8 *v1);

// 0x634dbe: stdcall, takes double, returns void
extern "C" void STDCALL ext_634dbe(double d);

// 0x5d6960, fastcall(v1, v2, v3, thresh) ret 0x10:
// Compute diff = v1 - v2 using ext_43e920. NaN-check each component of diff.
// If any NaN, magnitude = 1.0. Else magnitude = sqrt(diff.x^2 + diff.y^2 + diff.z^2).
// Normalize diff by dividing by magnitude.
// Compute dot = diff . v3 = diff.x*v3[0] + diff.y*v3[1] + diff.z*v3[2].
// Convert dot to double, call ext_634dbe, then compare result < thresh.

static int FASTCALL fn5d6960(u8 *v1, u8 *v2, u8 *v3, float thresh) {
  // Compute diff = v1 - v2
  float diff[3];
  ext_43e920(v2, (u8 *)diff, v1);

  float x = diff[0], y = diff[1], z = diff[2];

  // Check for NaN in any component
  int has_nan = 0;
  if (x != x || y != y || z != z) {  // NaN check
    has_nan = 1;
  }

  // Compute magnitude
  float magnitude;
  if (has_nan) {
    magnitude = 1.0f;
  } else {
    magnitude = (float)crt::sqrt((double)(x*x + y*y + z*z));
  }

  // Normalize diff
  if (magnitude != 0.0f) {
    x /= magnitude;
    y /= magnitude;
    z /= magnitude;
  }

  // Compute dot product with v3
  float *v3f = (float *)v3;
  float dot = x * v3f[0] + y * v3f[1] + z * v3f[2];

  // Convert to double and call ext_634dbe
  double d = (double)dot;
  ext_634dbe(d);

  // Return 1 if thresh > dot_result, else 0
  return thresh > (float)d ? 1 : 0;
}
PCREG(5d6960, fn5d6960);
