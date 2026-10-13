// batch43.cpp - walk-tree leaf, inline session batch 43 (Haiku, night): 0x4dd930, a segment-versus-box slab test.
#include "ff.h"

static float absf(float x) { return x < 0.0f ? -x : x; }

// 0x4dd930, fastcall (P in ECX, D in EDX), one stack arg Q, ret 4, result in al. The dominant axis of D (largest |component|,
// the first one wins ties, the order matches the exe's compares) selects the two other axes s and t. Each value is a float
// op, stored as float. The test returns false when -2^-13 > X or -2^-13 > Y, where X and Y come from the exe's cross
// terms; otherwise it returns !(-2^-13 > Z). A NaN never satisfies "-2^-13 > value", so NaN paths return true.
static u8 FASTCALL segBoxTest(const float *P, const float *D, const float *Q) {
  float best = absf(D[0]);
  s32 s = 1, t = 2;
  float a1 = absf(D[1]);
  if (a1 > best) {
    s = 2;
    best = a1;
    t = 0;
  }
  float a2 = absf(D[2]);
  if (a2 > best) {
    s = 0;
    t = 1;
  }
  float A = P[s + 3];
  float B = P[t];
  float C = P[s + 6] - A;
  float Dd = B - P[t + 3];
  float E = A - P[s];
  float F = P[t + 6] - P[t + 3];
  float G1 = (F * E) + (C * Dd);
  float H = Q[s] - A;
  float I = Q[t] - P[t + 3];
  float X = ((I * E) + (H * Dd)) * G1;
  const float eps = -0.0001220703125f;
  if (eps > X)
    return 0;
  float Y = ((((P[t + 3] - P[t + 6]) * H) + (C * I))) * G1;
  if (eps > Y)
    return 0;
  float Z = ((P[s] - P[s + 6]) * (Q[t] - B) + (Q[s] - P[s]) * (P[t + 6] - B)) * G1;
  return !(eps > Z);
}
PCREG(4dd930, segBoxTest);
