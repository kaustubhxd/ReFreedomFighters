// batch1148.cpp - unclaimed-11 batch 49 (slice 10): 0x44fde0, GUESS (segment/sphere test; fastcall, ret 0x14, returns al).
#include "ff.h"

extern "C" void FASTCALL ext_43e920(float *d, const float *a, const float *b);              // PSVECSubtract d = a - b (exe)
extern "C" void FASTCALL ext_443ef0(float *d, const float *a, const float *v, float s);     // vaddscalar d = a + v * s (exe)
extern "C" void THISCALL ext_4e0d00(float *v, float s);                                    // vscalar in place (exe)
extern "C" void THISCALL ext_451250(float *v);                                             // GUESS: random unit vector (stubbed)

// Floats are compared as signed ints, like the PC (cmp on the stored bits).
static bool FASTCALL guessSegmentSphere(const float *a, const float *b, const float *c, float *outT, const float *radius,
                                        float *outDist, float *outVec) {
  float cb[3], ab[3], p[3];
  ext_43e920(ab, a, b);
  ext_43e920(cb, c, b);
  float lenSq = cb[0] * cb[0] + cb[1] * cb[1] + cb[2] * cb[2];
  float dot = ab[0] * cb[0] + ab[1] * cb[1] + ab[2] * cb[2];
  *outT = dot;
  s32 bits = *(s32 *)outT;
  const float *closest;
  if (bits < 0) {
    *outT = 0.0f;
    closest = b;
  } else if (bits > (s32)fbits(lenSq)) {
    *outT = 1.0f;
    closest = c;
  } else {
    float t = dot / lenSq;
    *outT = t;
    ext_443ef0(p, b, cb, t);
    closest = p;
  }
  ext_43e920(outVec, a, closest);
  float l2 = outVec[0] * outVec[0] + outVec[1] * outVec[1] + outVec[2] * outVec[2];
  float r = *radius;
  if ((s32)fbits(l2) > (s32)fbits(r * r)) return false;
  *outDist = (float)crt::sqrt((double)l2);
  if (*(s32 *)outDist > 0x358637bd) ext_4e0d00(outVec, 1.0f / *outDist);  // 0x358637bd = 1e-6; 1.0 from 0x678858
  else ext_451250(outVec);
  return true;
}
PCREG(44fde0, guessSegmentSphere);
