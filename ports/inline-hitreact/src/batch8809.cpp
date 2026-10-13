// batch8809.cpp - hit-reaction thread, batch 8809: the 3x3 solver the ragdoll joint limits and capsule contact use (taken over from area
// 50, 2026-10-12 14:40 UTC).
#include "ff.h"

// 0x547860 (no name in the map; GC: the Cramer solver under AdjustCone4/5/6, CollideSolidCappedCylinderAndTriangle, CRigidBody), fastcall:
// ECX = 3x3 matrix m (row-major floats), EDX = b, stack: out; ret 4; returns al. det = ((m0 m4 m8 + m1 m5 m6) + m2 m3 m7) - m2 m4 m6 -
// m3 m1 m8 - m0 m5 m7 (each product left to right, as written); |det| (as a double) below 1e-6 (double at 0x67fad0) -> false. Else
// out = Cramer's rule with 1 / det: x = (b0 m4 m8 + b1 m5 m6 + b2 m3 m7 - b2 m4 m6 - b1 m3 m8 - b0 m5 m7) / det, y = (m1 b2 m6 + m0 b1 m8
// + m2 b0 m7 - m2 b1 m6 - m1 b0 m8 - m0 b2 m7) / det, z = (m0 m4 b2 + m1 m5 b0 + m2 m3 b1 - m2 m4 b0 - m1 m3 b2 - m0 m5 b1) / det; true.
static u8 FASTCALL solve3(const float *m, const float *b, float *out) {
  float det = m[0] * m[4] * m[8] + m[1] * m[5] * m[6];
  det = det + m[2] * m[3] * m[7];
  det = det - m[2] * m[4] * m[6];
  det = det - m[3] * m[1] * m[8];
  det = det - m[0] * m[5] * m[7];
  double ad = __builtin_fabs((double)det);
  if (G(double, 0x67fad0) > ad) return 0;
  float inv = G(float, 0x678858) / det;
  float x = b[0] * m[4] * m[8] + b[1] * m[5] * m[6];
  x = x + b[2] * m[3] * m[7];
  x = x - b[2] * m[4] * m[6];
  x = x - b[1] * m[3] * m[8];
  x = x - b[0] * m[5] * m[7];
  out[0] = x * inv;
  float y = m[1] * b[2] * m[6] + m[0] * b[1] * m[8];
  y = y + m[2] * b[0] * m[7];
  y = y - m[2] * b[1] * m[6];
  y = y - m[1] * b[0] * m[8];
  y = y - m[0] * b[2] * m[7];
  out[1] = y * inv;
  float z = m[0] * m[4] * b[2] + m[1] * m[5] * b[0];
  z = z + m[2] * m[3] * b[1];
  z = z - m[2] * m[4] * b[0];
  z = z - m[1] * m[3] * b[2];
  z = z - m[0] * m[5] * b[1];
  out[2] = z * inv;
  return 1;
}
PCREG(547860, solve3);
