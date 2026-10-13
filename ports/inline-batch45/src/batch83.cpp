// batch83.cpp - wrench tree, inline session batch 83 (2026-10-12, docs/41): vdist2 (0x4e0830), the squared distance
// GotControl's target test uses.
#include "ff.h"

extern "C" void FASTCALL ext_43e920(float *d, const float *a, const float *b);   // d = a - b

// 0x4e0830 vdist2(const float *a, const float *b), fastcall (a in ECX, b in EDX), plain ret, result in ST0 (a float).
// d = a - b (0x43e920), then (d.x * d.x + d.y * d.y) + d.z * d.z in SSE single precision, stored as float and loaded.
static float FASTCALL vdist2(const float *a, const float *b) {
  float d[3];
  ext_43e920(d, a, b);
  float s = d[0] * d[0] + d[1] * d[1];
  s = s + d[2] * d[2];
  return s;
}
PCREG(4e0830, vdist2);
