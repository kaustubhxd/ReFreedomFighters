// batch9002.cpp - wire-ai thread (2026-10-13): 0x5457f0 (DistPointLineVar, the point-to-segment test the ragdoll's limb capsules use),
// re-lifted as plain C. Area 81's lift (batch1027) wrapped it in x86 asm because it modelled 0x443ef0 as popping one stack word and so
// left a "stray word" on the stack; 0x443ef0 (vaddscalar4, inline-batch45 batch65) ends with ret 8 and pops both of its stack arguments,
// so the stack is balanced and the exe's exit registers are its ordinary saved ones. Here every callee is exe code in the spec except the
// random unit vector 0x547430 (hooked).
#include "ff.h"

extern "C" void FASTCALL ext_43e920(float *d, const float *a, const float *b);                 // d = a - b
extern "C" void FASTCALL ext_443ef0(float *d, const float *a, const float *v, float s);         // d = a + v * s (x87)
extern "C" void THISCALL ext_4e0d00(float *v, float s);                                        // v *= s
extern "C" void THISCALL ext_547430(float *v);                                                 // random unit vector

// 0x5457f0, fastcall (ecx = P, edx = A; stack B, t*, rMax*, dist*, dir*), ret 0x14, returns the bool in al.
// V1 = P - A, V2 = B - A; *t = D = V1 . V2; D < 0 or D > |V2|^2 -> false (NaN passes both); *t = D / |V2|^2; X = A + V2 * t;
// dir = X - P; |dir|^2 > rMax^2 -> false; *dist = r = (float) sqrt(|dir|^2) (CRT, correctly rounded); r > 1e-6: dir *= 1 / r, else
// dir = random unit vector; true.
static u8 FASTCALL distPointLineVar(const float *P, const float *A, const float *B, float *t, const float *rMax, float *dist, float *dir) {
  float V1[3], V2[3], X[3];
  ext_43e920(V1, P, A);
  ext_43e920(V2, B, A);
  float sA = V2[0] * V2[0] + V2[1] * V2[1];
  sA = sA + V2[2] * V2[2];
  float D = V1[0] * V2[0] + V1[1] * V2[1];
  D = D + V1[2] * V2[2];
  *t = D;
  if (0.0f > D) return 0;
  if (D > sA) return 0;
  float tt = D / sA;
  *t = tt;
  ext_443ef0(X, A, V2, tt);
  ext_43e920(dir, X, P);
  float se = dir[0] * dir[0] + dir[1] * dir[1];
  se = se + dir[2] * dir[2];
  float rr = *rMax * *rMax;
  if (se > rr) return 0;
  float r = (float)crt::sqrt((double)se);
  *dist = r;
  if (r > bitsf(0x358637bdu))   // 0x681370 1e-6
    ext_4e0d00(dir, 1.0f / r);
  else
    ext_547430(dir);
  return 1;
}
PCREG(5457f0, distPointLineVar);
