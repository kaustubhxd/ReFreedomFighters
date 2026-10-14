// batch8812.cpp - hit-reaction thread, batch 8812: the ragdoll knee wedge limit AdjustCone5 (called by ConstrainedParticleSystem::ZeroOut
// 0x547a70; sibling AdjustCone6 0x542ee0 is batch 8810).
#include "ff.h"

extern "C" void FASTCALL ext_43e920(float *d, const float *a, const float *b);      // PSVECSubtract d = a - b
extern "C" void FASTCALL ext_459fc0(float *d, const float *v, const float *m);      // vmtmul d = v * transpose(m)
extern "C" void FASTCALL ext_441970(float *d, const float *v, const float *m);      // vmmul d = v * m
extern "C" void FASTCALL ext_441940(float *d, const float *s);                      // PSVECAdd d += s
extern "C" float FASTCALL ext_44e630(float *dst, const float *src);                 // vnorm, length in ST0
extern "C" void FASTCALL ext_446ee0(float *d, const float *a, const float *b);      // vcross d = a x b
extern "C" void FASTCALL ext_43e8e0(float *d, const float *a, const float *b);      // d = a + b
extern "C" u8 FASTCALL ext_547860(const float *m, const float *b, float *out);      // 3x3 Cramer solver
extern "C" void THISCALL ext_4e0d00(float *v, float s);                             // vscalar in place
extern "C" void FASTCALL ext_4e0d40(float *out, const float *a, float s);           // vscalar3 out = a * s
extern "C" void FASTCALL ext_451890(float *d, const float *v, float s);             // vaddscalar d += v * s

// 0x5428f0 AdjustCone5(ix1, ix2, ix3, ix5, base, ax, ay, particles) (), fastcall: ECX = ix1, EDX = ix2, stack ix3, ix5,
// base (3x3 matrix), ax, ay (unused here; Cone6 uses it), particles (0x34-byte records, position +0xc, mass +0x30); ret 0x18.
//  - L = (x5 - x1) * transpose(base). Planar wedge |ax * L0| <= L2: return when (double)L2 > |(double)(ax * L0)| and L2 > 0 (inside),
//    or when 0 > L2 (behind).
//  - den = ax * ax + 1. L0 >= 0: t = (ax L0 - L2) / den; t > 0: L' = (L0 - t ax, L1, L2 + t); else (1e-6, L1, ax * 1e-6).
//    L0 < 0 or NaN: t = (-(ax L0) - L2) / den; t > 0: L' = (t ax + L0, L1, L2 + t); else (L0 >= 0 ? 1e-6 : -1e-6, L1, ax * 1e-6).
//  - W = L' * base + x1; D = x5 - W; return when 1e-11 > |D|^2; n = unit(D), len = |D|.
//  - e1 = x2 - x1, e2 = x3 - x1, x4 = (e1 x e2) + x1; barycentric bc = solve(rows e1, e2, e1 x e2; W - x1) (fail: return);
//    w0 = 1 - (bc1 + bc0 + bc2).
//  - Q_i = x_i - x4 (i = 1, 2, 3); g = solve(rows Q; n) (fail: return); Q_i *= g_i.
//  - any of m1, m2, m3 == 0: return. X0 = n w0/m1 + Q0 bc2/m1, X1 = n bc0/m2 + Q1 bc2/m2, X2 = n bc1/m3 + Q2 bc2/m3.
//  - Y = (X1 - X0) x e2 + e1 x (X2 - X0) + X0; G = X0 w0 + X1 bc0 + X2 bc1 + Y bc2.
//  - m5 == 0: return. den = G.n - (-1 / m5); |(double)den| < 1e-6: return. k = len * 0.75 / den.
//  - x1 += X0 k, x2 += X1 k, x3 += X2 k, x5 += n * -(k / m5).
static void FASTCALL adjustCone5(s32 ix1, s32 ix2, s32 ix3, s32 ix5, const float *base, float ax, float ay, u8 *parts) {
  (void)ay;
  u8 *p1 = parts + ix1 * 0x34;
  u8 *p3 = parts + ix3 * 0x34;
  u8 *p2 = parts + ix2 * 0x34;
  u8 *p5 = parts + ix5 * 0x34;
  float *x1 = (float *)(p1 + 0xc), *x2 = (float *)(p2 + 0xc), *x3 = (float *)(p3 + 0xc), *x5 = (float *)(p5 + 0xc);
  float t1[3], L[3];
  ext_43e920(t1, x5, x1);
  ext_459fc0(L, t1, base);
  float L0 = L[0], L2 = L[2];
  float aL0 = L0 * ax;
  if ((double)L2 > __builtin_fabs((double)aL0) && L2 > 0.0f) return;
  if (0.0f > L2) return;
  float den = ax * ax + G(float, 0x678858);
  float Lp[3];
  if (L0 >= 0.0f) {
    float t = (aL0 - L2) / den;
    if (t > 0.0f) {
      Lp[2] = L2 + t;
      Lp[0] = L0 - t * ax;
    } else {
      Lp[0] = bitsf(0x358637bd);
      Lp[2] = ax * G(float, 0x681370);
    }
  } else {
    float t = (-aL0 - L2) / den;
    if (t > 0.0f) {
      Lp[2] = L2 + t;
      Lp[0] = t * ax + L0;
    } else {
      Lp[0] = L0 >= 0.0f ? bitsf(0x358637bd) : bitsf(0xb58637bd);
      Lp[2] = ax * G(float, 0x681370);
    }
  }
  Lp[1] = L[1];
  float W[3], D[3];
  ext_441970(W, Lp, base);
  ext_441940(W, x1);
  ext_43e920(D, x5, W);
  float l2 = D[0] * D[0] + D[1] * D[1];
  l2 = l2 + D[2] * D[2];
  if (G(float, 0x6a312c) > l2) return;
  float n[3];
  float len = ext_44e630(n, D);
  float M[9];   // rows e1, e2, e1 x e2
  ext_43e920(M, x2, x1);
  ext_43e920(M + 3, x3, x1);
  ext_446ee0(M + 6, M, M + 3);
  float x4[3], r[3], bc[3];
  ext_43e8e0(x4, M + 6, x1);
  ext_43e920(r, W, x1);
  if (!ext_547860(M, r, bc)) return;
  float w0 = G(float, 0x678858) - (bc[1] + bc[0] + bc[2]);
  float Q[9], g[3];
  ext_43e920(Q, x1, x4);
  ext_43e920(Q + 3, x2, x4);
  ext_43e920(Q + 6, x3, x4);
  if (!ext_547860(Q, n, g)) return;
  ext_4e0d00(Q, g[0]);
  ext_4e0d00(Q + 3, g[1]);
  ext_4e0d00(Q + 6, g[2]);
  float m1 = *(float *)(p1 + 0x30);
  if (m1 == 0.0f) return;
  if (*(float *)(p2 + 0x30) == 0.0f) return;
  if (*(float *)(p3 + 0x30) == 0.0f) return;
  float X0[3], X1[3], X2[3];
  ext_4e0d40(X0, n, w0 / m1);
  ext_451890(X0, Q, bc[2] / *(float *)(p1 + 0x30));
  ext_4e0d40(X1, n, bc[0] / *(float *)(p2 + 0x30));
  ext_451890(X1, Q + 3, bc[2] / *(float *)(p2 + 0x30));
  ext_4e0d40(X2, n, bc[1] / *(float *)(p3 + 0x30));
  ext_451890(X2, Q + 6, bc[2] / *(float *)(p3 + 0x30));
  float A[3], B[3], Y[3], Z[3];
  ext_43e920(A, X1, X0);
  ext_43e920(B, X2, X0);
  ext_446ee0(Y, A, M + 3);
  ext_446ee0(Z, M, B);
  ext_441940(Y, Z);
  ext_441940(Y, X0);
  float Gv[3];
  ext_4e0d40(Gv, X0, w0);
  ext_451890(Gv, X1, bc[0]);
  ext_451890(Gv, X2, bc[1]);
  ext_451890(Gv, Y, bc[2]);
  float m5 = *(float *)(p5 + 0x30);
  if (m5 == G(float, 0x6785d0)) return;
  float d = Gv[0] * n[0] + Gv[1] * n[1];
  d = d + Gv[2] * n[2];
  d = d - G(float, 0x67af2c) / m5;
  if (G(double, 0x67fad0) > __builtin_fabs((double)d)) return;
  float k = len * G(float, 0x684ce4) / d;
  ext_451890(x1, X0, k);
  ext_451890(x2, X1, k);
  ext_451890(x3, X2, k);
  ext_451890(x5, n, -(k / *(float *)(p5 + 0x30)));
}
PCREG(5428f0, adjustCone5);
