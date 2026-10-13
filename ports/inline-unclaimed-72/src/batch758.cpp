// batch758.cpp - area 72, bottom-up helpers for ZActionPushButton::Execute (2026-10-12). x87 sums and differences mirrored with
// long double (the exe computes in extended precision and stores floats).
#include "ff.h"

// 0x43e920 PSVECSubtract(ecx = out, edx = a, stack = b) [low]: out = a - b.
static void FASTCALL psvec_sub(float *out, const float *a, const float *b) {
  for (int i = 0; i < 3; i++)
    out[i] = (float)((long double)a[i] - (long double)b[i]);
}
PCREG(43e920, psvec_sub);

// 0x441a60 vmtmul(ecx = out, edx = m) [high]: out = matrix m applied to the vector in out, extended precision.
static void FASTCALL vmtmul_port(float *out, const float *m) {
  long double c0 = out[0], c1 = out[1], c2 = out[2];
  long double r0 = c0 * m[6];
  r0 += c1 * m[7];
  r0 += c2 * m[8];
  long double r1 = c0 * m[3];
  r1 += c1 * m[4];
  r1 += c2 * m[5];
  long double r2 = c0 * m[0];
  r2 += c1 * m[1];
  r2 += c2 * m[2];
  out[0] = (float)r0;
  out[1] = (float)r1;
  out[2] = (float)r2;
}
PCREG(441a60, vmtmul_port);
