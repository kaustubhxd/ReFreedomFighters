// batch4011.cpp - area 70 (residue 9), batch 4011: 0x4e0be0, a rotation of a vector by the sines and cosines of the
// source vector's components (names GUESS). sin is the CRT thunk 0x634d76 (IAT 0x676338), cos is 0x634d70 (IAT 0x676320).
#include "ff.h"

// 0x4e0be0 (name GUESS): fastcall (ECX = destination vec, EDX = source vec), plain ret. With s_i, c_i = sin, cos of
// src[i] (each rounded to float), the destination d = (d0, d1, d2) becomes:
//   x' = (d0*c2 - d1*s2) * ... (see below); computed in the exe's float order:
//   A = d0*c2 - d1*s2;  B = d1*c2 + d0*s2;  C = d2*s0;  D = d2*c0;
//   y' = B*c0 - C;  D2 = D + B*s0;
//   x' = A*c1 + D2*s1;  z' = D2*c1 - A*s1;
static void FASTCALL rotateByTrig(float *dst, const float *src) {
  float s0 = (float)crt::sin((double)src[0]), c0 = (float)crt::cos((double)src[0]);
  float s1 = (float)crt::sin((double)src[1]), c1 = (float)crt::cos((double)src[1]);
  float s2 = (float)crt::sin((double)src[2]), c2 = (float)crt::cos((double)src[2]);
  float d0 = dst[0], d1 = dst[1], d2 = dst[2];
  float A = (d0 * c2) - (d1 * s2);
  float B = (d1 * c2) + (d0 * s2);
  float C = d2 * s0;
  float D = d2 * c0;
  dst[0] = A;
  dst[1] = (B * c0) - C;
  float D2 = D + (B * s0);
  float H = A * c1;
  float P = A * s1;
  dst[0] = H + (D2 * s1);
  dst[2] = (D2 * c1) - P;
}
PCREG(4e0be0, rotateByTrig);
