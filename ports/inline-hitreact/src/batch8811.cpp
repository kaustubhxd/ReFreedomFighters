// batch8811.cpp - hit-reaction thread, batch 8811: the ragdoll elliptic-cone joint limit AdjustCone4 , called by
// ConstrainedParticleSystem::ZeroOut 0x547a70.
#include "ff.h"

extern "C" void FASTCALL ext_43e920(float *d, const float *a, const float *b);     // PSVECSubtract d = a - b
extern "C" void FASTCALL ext_459fc0(float *d, const float *v, const float *m);     // vmtmul d = v * M^T (x87)
extern "C" void FASTCALL ext_441970(float *d, const float *v, const float *m);     // vmmul d = v * M (x87)
extern "C" void FASTCALL ext_441940(float *d, const float *s);                     // PSVECAdd d += s
extern "C" float FASTCALL ext_44e630(float *dst, const float *src);                // vnorm, length in ST0
extern "C" void FASTCALL ext_446ee0(float *d, const float *a, const float *b);     // vcross d = a x b
extern "C" void FASTCALL ext_43e8e0(float *d, const float *a, const float *b);     // d = a + b
extern "C" u8 FASTCALL ext_547860(const float *m, const float *b, float *out);     // 3x3 Cramer solver (rows m[0..2], m[3..5], m[6..8])
extern "C" void THISCALL ext_4e0d00(float *v, float s);                            // vscalar in place
extern "C" void FASTCALL ext_4e0d40(float *out, const float *a, float s);          // vscalar3 out = a * s
extern "C" void FASTCALL ext_451890(float *d, const float *v, float s);            // vaddscalar d += v * s

// 0x542310 AdjustCone4 , fastcall: ECX = joint particle ia, EDX = ib, stack: ic, id, const float* M (3x3 cone frame),
// float a, float b (the cone's x / y slopes), u8* parts (0x34-byte particle records: position +0xc, mass +0x30); ret 0x18.
// A = parts[ia] is the cone apex; the triangle A, B, C (parts[ib], parts[ic]) carries the frame; D = parts[id] is the limited end.
//  l = M^T (D - A); s = (l.x a, l.y b, 0). Inside the cone (l.z^2 >= |s|^2 and l.z > 0, ordered compares) -> nothing.
//  n = normalize(s) with n.x /= a, n.y /= b, n.z = 1; w = M n + A (a point on the cone's rim line); f = w - A, e = D - A;
//  |f|^2 < 1e-8 ([0x6a3130]) -> nothing. q = A + f (e.f / |f|^2) (D projected onto the rim line); h = normalize(D - q), L = |D - q|.
//  r1 = B - A, r2 = C - A, r3 = r1 x r2, cen = r3 + A; o = solve([r1; r2; r3], q - A) (fail -> nothing); wA = 1 - (o1 + o0 + o2)
//  (barycentric weights of q in the triangle, o2 the normal part). u_i = P_i - cen for P = A, B, C; k = solve([u0; u1; u2], h) (fail
//  -> nothing); u_i *= k_i. vA = h wA / mA + u0 o2 / mA, vB = h o0 / mB + u1 o2 / mB, vC = h o1 / mC + u2 o2 / mC (per-particle
//  responses); c = (vB - vA) x r2 + r1 x (vC - vA) + vA; t = vA wA + vB o0 + vC o1 + c o2; den = t.h - (-1 [0x67af2c]) / mD.
//  |den| (double) < 1/8192 ([0x685278]) -> nothing. s = L 0.75 ([0x684ce4]) / den; A += vA s, B += vB s, C += vC s, D += h (-(s / mD)).
// Scalar SSE ops pinned to the exe's operand order (x86 returns the first operand's NaN when both are NaN).
#if defined(__i386__)
static inline float sadd(float a, float b) { asm("addss %1, %0" : "+x"(a) : "x"(b)); return a; }
static inline float ssub(float a, float b) { asm("subss %1, %0" : "+x"(a) : "x"(b)); return a; }
static inline float smul(float a, float b) { asm("mulss %1, %0" : "+x"(a) : "x"(b)); return a; }
static inline float sdiv(float a, float b) { asm("divss %1, %0" : "+x"(a) : "x"(b)); return a; }
#else   // wasm build (hitreact.wasm): same values; only a NaN's payload/sign could differ from the x86 operand order
static inline float sadd(float a, float b) { return a + b; }
static inline float ssub(float a, float b) { return a - b; }
static inline float smul(float a, float b) { return a * b; }
static inline float sdiv(float a, float b) { return a / b; }
#endif

static void FASTCALL adjustCone4(s32 ia, s32 ib, s32 ic, s32 id, const float *M, float a, float b, u8 *parts) {
  u8 *pA = parts + ia * 0x34, *pB = parts + ib * 0x34, *pC = parts + ic * 0x34, *pD = parts + id * 0x34;
  float *A = (float *)(pA + 0xc), *D = (float *)(pD + 0xc);
  float d[3], l[3], s[3], n[3], w[3], e[3], f[3], q[3], g[3], h[3], m1[9], cen[3], rhs[3], o[3], m2[9], k[3];
  float vA[3], vB[3], vC[3], dB[3], dC[3], c1[3], c2[3], t[3];
  ext_43e920(d, D, A);
  ext_459fc0(l, d, M);
  s[0] = smul(l[0], a);
  s[1] = smul(l[1], b);
  s[2] = 0.0f;
  float sum = sadd(smul(s[1], s[1]), smul(s[0], s[0]));
  float z2 = smul(l[2], l[2]);
  if (z2 >= sum && l[2] > 0.0f) return;
  ext_44e630(n, s);
  n[0] = sdiv(n[0], a);
  n[2] = 1.0f;
  n[1] = sdiv(n[1], b);
  ext_441970(w, n, M);
  ext_441940(w, A);
  ext_43e920(e, D, A);
  ext_43e920(f, w, A);
  float ff = sadd(sadd(smul(f[0], f[0]), smul(f[1], f[1])), smul(f[2], f[2]));
  if (G(float, 0x6a3130) > ff) return;
  q[0] = A[0];
  q[1] = A[1];
  q[2] = A[2];
  float ef = sadd(sadd(smul(e[0], f[0]), smul(e[1], f[1])), smul(e[2], f[2]));
  ext_451890(q, f, sdiv(ef, ff));
  ext_43e920(g, D, q);
  float L = ext_44e630(h, g);
  ext_43e920(m1, (float *)(pB + 0xc), A);
  ext_43e920(m1 + 3, (float *)(pC + 0xc), A);
  ext_446ee0(m1 + 6, m1, m1 + 3);
  ext_43e8e0(cen, m1 + 6, A);
  ext_43e920(rhs, q, A);
  if (!ext_547860(m1, rhs, o)) return;
  float wA = ssub(G(float, 0x678858), sadd(sadd(o[1], o[0]), o[2]));
  ext_43e920(m2, A, cen);
  ext_43e920(m2 + 3, (float *)(pB + 0xc), cen);
  ext_43e920(m2 + 6, (float *)(pC + 0xc), cen);
  if (!ext_547860(m2, h, k)) return;
  ext_4e0d00(m2, k[0]);
  ext_4e0d00(m2 + 3, k[1]);
  ext_4e0d00(m2 + 6, k[2]);
  ext_4e0d40(vA, h, sdiv(wA, *(float *)(pA + 0x30)));
  ext_451890(vA, m2, o[2] / *(float *)(pA + 0x30));
  ext_4e0d40(vB, h, o[0] / *(float *)(pB + 0x30));
  ext_451890(vB, m2 + 3, o[2] / *(float *)(pB + 0x30));
  ext_4e0d40(vC, h, o[1] / *(float *)(pC + 0x30));
  ext_451890(vC, m2 + 6, o[2] / *(float *)(pC + 0x30));
  ext_43e920(dB, vB, vA);
  ext_43e920(dC, vC, vA);
  ext_446ee0(c1, dB, m1 + 3);
  ext_446ee0(c2, m1, dC);
  ext_441940(c1, c2);
  ext_441940(c1, vA);
  ext_4e0d40(t, vA, wA);
  ext_451890(t, vB, o[0]);
  ext_451890(t, vC, o[1]);
  ext_451890(t, c1, o[2]);
  float den = sadd(sadd(smul(t[0], h[0]), smul(t[1], h[1])), smul(t[2], h[2]));
  den = ssub(den, sdiv(G(float, 0x67af2c), *(float *)(pD + 0x30)));
  if (G(double, 0x685278) > __builtin_fabs((double)den)) return;
  float sc = sdiv(smul(L, G(float, 0x684ce4)), den);
  ext_451890(A, vA, sc);
  ext_451890((float *)(pB + 0xc), vB, sc);
  ext_451890((float *)(pC + 0xc), vC, sc);
  ext_451890(D, h, -sdiv(sc, *(float *)(pD + 0x30)));
}
PCREG(542310, adjustCone4);
