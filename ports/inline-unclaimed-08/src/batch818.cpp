// batch818.cpp - unclaimed-08 batch 18: CRigidBody::ProjectSphereOutFromPlane (residue 7, ragdoll; coordinator's instruction).
// Stdcall, ten stack arguments (ret 0x28): A, B, C, D, K, F, G, H (float[3] pointers), I (float[3]), J (float).
// Original, in outline: C = D. dot = D.I (summed as (D1*I1 + I0*D0) + I2*D2). If 0 > dot: K += I*(-n) with
// n = K.I (helper 0x451890), then K is zeroed when 9 > |K|^2 and else scaled by 0.9; same for F (with n = F.I) and G (with
// n = K.I after the K update, helper on G); H += I*(-n) with n = K.I, then zeroed or scaled by 0.9. Then C = (K + F + G + H) * 0.25
// (helpers 0x43e8e0 and 0x441940 on C). Then, on both paths, A = I*J + B (helper 0x443ef0).
// Helpers 0x451890, 0x441940, 0x43e8e0 and 0x443ef0 are x87 code, so they run as original code (ext). The arithmetic of
// the function itself is single precision SSE (mulss/addss), reproduced directly.
#include "ff.h"

extern "C" void FASTCALL ext_451890(float *dst, const float *src, float s);   // dst += src * s (x87), ret 4
extern "C" void FASTCALL ext_441940(float *dst, const float *src);              // dst += src (x87)
extern "C" void FASTCALL ext_43e8e0(float *dst, const float *src, const float *p); // dst = src + *p (x87), ret 4
extern "C" void FASTCALL ext_443ef0(float *dst, const float *addend, const float *p, float s); // dst = p * s + addend (x87), ret 8

// Zero when 9 > |v|^2 (ordered), else v *= 0.9f. Same compare as the original's comiss/jbe.
static void zeroOrScale(float *v) {
  float len2 = ((v[0] * v[0]) + (v[1] * v[1])) + (v[2] * v[2]);
  if (9.0f > len2) {
    v[0] = 0.0f; v[1] = 0.0f; v[2] = 0.0f;
  } else {
    v[0] *= 0.9f; v[1] *= 0.9f; v[2] *= 0.9f;
  }
}

// dot of a and b in the original's summation order: (a1*b1 + b0*a0) + b2*a2 (the operands of each product as in the PC code).
static float dotIn(const float *a, const float *b) {
  return ((a[1] * b[1]) + (b[0] * a[0])) + (b[2] * a[2]);
}

// The n of each step: ((v0*i0) + (i1*v1)) + (i2*v2).
static float dotV(const float *v, const float *i) {
  return ((v[0] * i[0]) + (i[1] * v[1])) + (i[2] * v[2]);
}

// 0x5403f0, CRigidBody::ProjectSphereOutFromPlane(...) (high name).
static void STDCALL projectSphereOutFromPlane(float *A, float *B, float *C, const float *D, float *K, float *F,
                                              float *G, float *H, const float *I, float J) {
  for (int k = 0; k < 3; k++) *(u32 *)(C + k) = *(const u32 *)(D + k);
  float dot = dotIn(D, I);
  if (0.0f > dot) {
    float n = dotV(K, I);
    ext_451890(K, I, -n);
    zeroOrScale(K);
    float m = dotV(F, I);
    ext_451890(F, I, -m);
    zeroOrScale(F);
    float n2 = dotV(K, I);
    ext_451890(G, I, -n2);
    zeroOrScale(G);
    float n3 = dotV(K, I);
    ext_451890(H, I, -n3);
    zeroOrScale(H);
    ext_43e8e0(C, K, F);
    ext_441940(C, G);
    ext_441940(C, H);
    C[0] *= 0.25f; C[1] *= 0.25f; C[2] *= 0.25f;
  }
  ext_443ef0(A, B, I, J);
}
PCREG(5403f0, projectSphereOutFromPlane);
