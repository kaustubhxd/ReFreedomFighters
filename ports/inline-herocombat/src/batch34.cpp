// batch34.cpp - walk-tree lift, inline session batch 34 (Haiku, night): PSVECAdd and PSVECSubtract (x87 in the exe).
#include "ff.h"

// 0x441940, fastcall (dst in ECX, src in EDX), plain ret. dst[i] = dst[i] + src[i] for three floats. The exe does this on the x87
// stack and stores after all three sums are computed. With the 53-bit precision control (0x27f) each sum is a single float add,
// and a float add rounded through double gives the same bits as SSE addss, so this port uses float ops.
static void FASTCALL psVecAdd(float *dst, const float *src) {
  float s0 = dst[0] + src[0];
  float s1 = dst[1] + src[1];
  float s2 = dst[2] + src[2];
  dst[0] = s0;
  dst[1] = s1;
  dst[2] = s2;
}
PCREG(441940, psVecAdd);

// 0x43e920, fastcall (dst in ECX, src in EDX), one stack arg a, ret 4. dst[i] = src[i] - a[i] for three floats; same x87 order
// as psVecAdd (all sums before the stores).
static void FASTCALL psVecSubtract(float *dst, const float *src, const float *a) {
  float s0 = src[0] - a[0];
  float s1 = src[1] - a[1];
  float s2 = src[2] - a[2];
  dst[0] = s0;
  dst[1] = s1;
  dst[2] = s2;
}
PCREG(43e920, psVecSubtract);
