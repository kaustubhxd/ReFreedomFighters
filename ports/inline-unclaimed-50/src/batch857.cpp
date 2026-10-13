// batch857.cpp - area 50 (residue-9 candidate): 0x545690 [109 instr, FASTCALL with five stack args (ret 0x14), returns bool;
// no name in the map (GUESS "ray parameter against a sphere: clamp t, then the point's length test")].
// V1 = P - Q, V2 = A - Q (both from the exe's vector subtract 0x43e920). t = V1 . V2 and s = |V2|^2:
//   t < 0 : *B = 0, the point is P - Q;      t > s : *B = 1, the point is P - A;
//   otherwise *B = t/s and the point is P - X, where X = V2*(t/s) + Q comes from 0x443ef0 (exe, x87) in the output vector.
// Then E = P - X, the length test |E|^2 <= C^2 (else false), D = sqrt(|E|^2), and E is scaled by 1/D through 0x4e0d00 when
// D > 1e-6, or 0x547430 (stood in by the harness) runs on E otherwise. The sqrt is the CRT import at 0x676330.
#include "ff.h"

extern "C" void FASTCALL ext_43e920(float *d, const float *a, const float *b);                  // d = a - b (exe)
extern "C" void FASTCALL ext_443ef0(float *out, const float *q, const float *v, float ratio);   // out = v*ratio + q (exe)
extern "C" void THISCALL ext_4e0d00(float *v, float s);                                          // v *= s (exe)
extern "C" void THISCALL ext_547430(void *e);                                                    // post step (stood in)

// 0x545690 (name GUESS).
static bool FASTCALL Fn545690(float *P, float *Q, float *A, float *Bo, float *Cp, float *Dp, float *E) {
  u8 fr[0x40];
  for (u32 i = 0; i < sizeof fr; i++) fr[i] = 0;
  float *V1 = (float *)(fr + 0x10);        // esp+0x10 of the exe frame
  float *V2 = (float *)(fr + 0x04);        // esp+0x04
  float *O1 = (float *)(fr + 0x1c);        // the output of 0x443ef0
  ext_43e920(V1, P, Q);
  ext_43e920(V2, A, Q);
  float a0 = V2[0], a1 = V2[1], a2 = V2[2];
  float t = V1[0] * a0;
  t = t + V1[1] * a1;
  t = t + V1[2] * a2;
  float s = a0 * a0;
  s = s + a1 * a1;
  s = s + a2 * a2;
  *Bo = t;

  u8 *X;
  if (0.0f > t) {
    *Bo = 0.0f;
    X = (u8 *)Q;
  } else if (t > s) {
    *Bo = 1.0f;
    X = (u8 *)A;
  } else {
    float ratio = t / s;
    *Bo = ratio;
    ext_443ef0(O1, Q, V2, ratio);
    X = (u8 *)O1;                           // the exe passes esp+0x24 after the call: the output vector
  }
  ext_43e920(E, P, (float *)X);

  float e0 = E[0] * E[0];
  float e1 = E[1] * E[1];
  float e2 = E[2] * E[2];
  float len2 = e0 + e1;
  len2 = len2 + e2;
  float c = *Cp;
  float cc = c * c;
  if (len2 > cc) return false;

  typedef double(VECTORCALL * sqrt_t)(double);
  double dd = (*(sqrt_t *)0x676330)((double)len2);   // _libm_sse2_sqrt_precise (VECTORCALL, via the import slot)
  float dist = (float)dd;
  *Dp = dist;
  if (dist > G(float, 0x681370)) {
    float inv = G(float, 0x678858) / dist;          // 1.0 / dist
    ext_4e0d00(E, inv);
  } else {
    ext_547430(E);
  }
  return true;
}
PCREG(545690, Fn545690);
