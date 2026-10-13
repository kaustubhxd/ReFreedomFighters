// batch8810.cpp - hit-reaction thread, batch 8810: AdjustCone6, one of the ragdoll joint limits ZeroOut applies (taken over from area 50,
// 2026-10-12 14:40 UTC). docs/25-ragdoll-joints.md describes the GC version (a planar wedge |a . Lq| <= L2).
#include "ff.h"

extern "C" void FASTCALL ext_43e920(float *d, const float *a, const float *b);        // PSVECSubtract d = a - b
extern "C" void FASTCALL ext_459fc0(float *out, const float *v, const float *m);      // vmtmul
extern "C" void FASTCALL ext_441970(float *out, const float *v, const float *m);      // vmmul
extern "C" void FASTCALL ext_441940(float *d, const float *s);                        // PSVECAdd d += s
extern "C" float FASTCALL ext_44e630(float *dst, const float *src);                   // vnorm, length in ST0
extern "C" void FASTCALL ext_446ee0(float *d, const float *a, const float *b);        // vcross d = a x b
extern "C" void FASTCALL ext_43e8e0(float *d, const float *a, const float *b);        // d = a + b
extern "C" u8 FASTCALL ext_547860(const float *m, const float *b, float *out);       // 3x3 Cramer solver (batch 8809)
extern "C" void THISCALL ext_4e0d00(float *v, float s);                               // vscalar in place
extern "C" void FASTCALL ext_4e0d40(float *out, const float *a, float s);             // vscalar3 out = a * s
extern "C" void FASTCALL ext_451890(float *d, const float *v, float s);               // vaddscalar d += v * s

// 0x542ee0 AdjustCone6 , fastcall: ECX = ia, EDX = ib, stack: ic, id, base matrix m, (unused), a, particle array; ret 0x18.
// Particles (0x34 bytes): position +0xc, mass +0x30. With A, B, C, D the four particles:
//  Lq = vmtmul(D - A, m); returns when Lq.z < 0, or when Lq.z > |Lq.y * a| (as doubles) and Lq.z > 0 (inside). Otherwise the
//  point is moved onto the wedge edge: t = (+-Lq.y * a - Lq.z) / (a * a + 1) by the sign of Lq.y (Lq.y >= 0: +); t > 0: Lq.z += t,
//  Lq.y -= t * a (or += for the negative side); else Lq.y = +-1e-6 (sign of Lq.y; + on the positive side), Lq.z = a * 1e-6.
//  T = A + vmmul(Lq, m); e = D - T; |e|^2 < 1e-11 -> return; n = e / |e|, len = |e|.
//  Triangle A, B, C with normal N = (B - A) x (C - A): (u, v, w) = solve([B - A; C - A; N], T - A) (singular -> return); wA = 1 - (v + u + w);
//  P = A + N; (s0, s1, s2) = solve([A - P; B - P; C - P], n) (singular -> return); A - P, B - P, C - P scaled by s0, s1, s2.
//  Any of A, B, C, D with mass 0 -> return. Mass-weighted displacements: GA = n * (wA / mA) + (A - P)s0 * (w / mA), GB = n * (u / mB) +
//  (B - P)s1 * (w / mB), GC = n * (v / mC) + (C - P)s2 * (w / mC); GN = (GB - GA) x (C - A) + (B - A) x (GC - GA) + GA;
//  J = GA * wA + GB * u + GC * v + GN * w; den = J . n - (-1 / mD); |den| < 1e-6 -> return; k = len * 0.75 / den;
//  A += GA k, B += GB k, C += GC k, D -= n (k / mD).
static void FASTCALL adjustCone6(s32 ia, s32 ib, s32 ic, s32 id, const float *m, u32, float a, u8 *base) {
  u8 *pA = base + ia * 0x34, *pC = base + ic * 0x34, *pB = base + ib * 0x34, *pD = base + id * 0x34;
  float *A = (float *)(pA + 0xc), *B = (float *)(pB + 0xc), *C = (float *)(pC + 0xc), *D = (float *)(pD + 0xc);
  float dA[3], q[3];
  ext_43e920(dA, D, A);
  ext_459fc0(q, dA, m);
  float qy = q[1], qz = q[2];
  float qa = qy * a;
  float zero = 0.0f;
  if ((double)qz > __builtin_fabs((double)qa)) {
    if (qz > zero) return;
  }
  if (zero > qz) return;
  float a2 = a * a + G(float, 0x678858);
  float ny, nz;
  if (!(qy < zero) && !(qy != qy)) {   // comiss qy, 0; jb (below or unordered) -> the negative side
    float t = (qa - qz) / a2;
    if (t > zero) {
      nz = qz + t;
      ny = qy - t * a;
      goto have;
    }
    ny = bitsf(0x358637bd);
  } else {
    float t = (-qa - qz) / a2;
    if (t > zero) {
      nz = qz + t;
      ny = t * a + qy;
      goto have;
    }
    ny = (qy >= zero) ? bitsf(0x358637bd) : bitsf(0xb58637bd);   // comiss qy, 0; jae (NaN -> -1e-6)
  }
  nz = a * G(float, 0x681370);
have:
  float nv[3], T[3], e[3], n[3];
  nv[0] = q[0]; nv[1] = ny; nv[2] = nz;
  ext_441970(T, nv, m);
  ext_441940(T, A);
  ext_43e920(e, D, T);
  float l2 = e[0] * e[0] + e[1] * e[1];
  l2 = l2 + e[2] * e[2];
  if (G(float, 0x6a312c) > l2) return;
  float len = ext_44e630(n, e);
  float M1[9], M2[9], uvw[3], s[3], P[3], tA[3];
  ext_43e920(M1, B, A);
  ext_43e920(M1 + 3, C, A);
  ext_446ee0(M1 + 6, M1, M1 + 3);
  ext_43e8e0(P, M1 + 6, A);
  ext_43e920(tA, T, A);
  if (!ext_547860(M1, tA, uvw)) return;
  float wA = G(float, 0x678858) - ((uvw[1] + uvw[0]) + uvw[2]);
  ext_43e920(M2, A, P);
  ext_43e920(M2 + 3, B, P);
  ext_43e920(M2 + 6, C, P);
  if (!ext_547860(M2, n, s)) return;
  ext_4e0d00(M2, s[0]);
  ext_4e0d00(M2 + 3, s[1]);
  ext_4e0d00(M2 + 6, s[2]);
  float mA = *(float *)(pA + 0x30);
  if (mA == 0.0f) return;
  if (*(float *)(pB + 0x30) == 0.0f) return;
  if (*(float *)(pC + 0x30) == 0.0f) return;
  float GA[3], GB[3], GC[3], d1[3], d2[3], GN[3], c2[3], J[3];
  ext_4e0d40(GA, n, wA / mA);
  ext_451890(GA, M2, uvw[2] / *(float *)(pA + 0x30));
  ext_4e0d40(GB, n, uvw[0] / *(float *)(pB + 0x30));
  ext_451890(GB, M2 + 3, uvw[2] / *(float *)(pB + 0x30));
  ext_4e0d40(GC, n, uvw[1] / *(float *)(pC + 0x30));
  ext_451890(GC, M2 + 6, uvw[2] / *(float *)(pC + 0x30));
  ext_43e920(d1, GB, GA);
  ext_43e920(d2, GC, GA);
  ext_446ee0(GN, d1, M1 + 3);
  ext_446ee0(c2, M1, d2);
  ext_441940(GN, c2);
  ext_441940(GN, GA);
  ext_4e0d40(J, GA, wA);
  ext_451890(J, GB, uvw[0]);
  ext_451890(J, GC, uvw[1]);
  ext_451890(J, GN, uvw[2]);
  float mD = *(float *)(pD + 0x30);
  if (mD == G(float, 0x6785d0)) return;
  float den = J[0] * n[0] + J[1] * n[1];
  den = den + J[2] * n[2];
  den = den - G(float, 0x67af2c) / mD;
  if (G(double, 0x67fad0) > __builtin_fabs((double)den)) return;
  float k = len * G(float, 0x684ce4) / den;
  ext_451890(A, GA, k);
  ext_451890(B, GB, k);
  ext_451890(C, GC, k);
  ext_451890(D, n, -(k / *(float *)(pD + 0x30)));
}
PCREG(542ee0, adjustCone6);
