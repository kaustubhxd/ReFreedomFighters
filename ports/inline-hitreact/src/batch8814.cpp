// batch8814.cpp - hit-reaction thread, batch 8814: ConstrainedParticleSystem::ZeroOut, the ragdoll constraint solver (GameCube reference).
// docs/25-ragdoll-joints.md describes the GC version; this follows the PC code (0x547a70, 4651 bytes).
#include "ff.h"

extern "C" void FASTCALL ext_43e8e0(float *d, const float *a, const float *b);        // d = a + b (x87)
extern "C" void FASTCALL ext_43e960(float *v, const float *a);                        // v -= a (x87)
extern "C" void FASTCALL ext_43e920(float *d, const float *a, const float *b);        // PSVECSubtract d = a - b
extern "C" void FASTCALL ext_446ee0(float *d, const float *a, const float *b);        // vcross d = a x b
extern "C" void FASTCALL ext_4de440(float *out, const float *a, const float *b);      // mmmul (batch 8813)
extern "C" void FASTCALL ext_4de420(float *dst, const float *src);                    // mcpy (9 floats)
extern "C" void FASTCALL ext_451890(float *d, const float *v, float s);               // vaddscalar d += v * s
extern "C" void FASTCALL ext_4e0d40(float *out, const float *a, float s);             // vscalar3 out = a * s
// AdjustCone4 (batch 8811), AdjustCone5 (8812), AdjustCone6 (8810): ECX = ia, EDX = ib, stack ic, id, base, ax, ay, particles.
// (AdjustCone6 ignores ax.)
extern "C" void FASTCALL ext_542310(s32 ia, s32 ib, s32 ic, s32 id, const float *m, float ax, float ay, u8 *parts);
extern "C" void FASTCALL ext_5428f0(s32 ia, s32 ib, s32 ic, s32 id, const float *m, float ax, float ay, u8 *parts);
extern "C" void FASTCALL ext_542ee0(s32 ia, s32 ib, s32 ic, s32 id, const float *m, float ax, float ay, u8 *parts);
extern "C" void FASTCALL ext_543680(float *A, float *B, float wA, float wB, float minDist);   // minimum distance (batch 8813)
extern "C" void FASTCALL ext_5434d0(float *A, float *B, float wA, float wB, float dist);      // distance (batch 859)

// Joint-limit tables (static, filled by the ctor 0x540ed0 via MakeBaseTransformation): 8 base matrices of 9 floats at 0x711b98,
// alphax[8] at 0x711cb8, alphay[8] at 0x711cd8.
#define TBASE(k) ((const float *)(0x711b98 + 0x24 * (k)))
#define AX(k) G(float, 0x711cb8 + 4 * (k))
#define AY(k) G(float, 0x711cd8 + 4 * (k))

// The inlined vnorm: when any component is != 0 (a NaN counts), v *= 1 / sqrt(x*x + y*y + z*z), on the x87 (precision per the
// control word).
static inline void vnormIn(float *v) {
  if (v[0] != 0.0f || v[1] != 0.0f || v[2] != 0.0f) {
    long double x = v[0], y = v[1], z = v[2];
    long double l = fsqrt_x87(x * x + y * y + z * z);
    long double inv = 1.0L / l;
    v[0] = (float)((long double)v[0] * inv);
    v[1] = (float)((long double)v[1] * inv);
    v[2] = (float)((long double)v[2] * inv);
  }
}

static inline u8 *partP(u8 *self) { return *(u8 **)(self + 0xf); }
#define POS(i) ((float *)(partP(self) + (i) * 0x34 + 0xc))
#define MASS(i) (*(float *)(partP(self) + (i) * 0x34 + 0x30))

// The inlined AdjustPlane2(i1, i2, base): s = (x2 - x1) . base row 0; s <= 0 (or NaN): k = s * m2 / (m1 + m2), x1 += row0 * (k * 0.75),
// x2 += row0 * ((k - s) * 0.75). `swap` selects the hip-right sum order (row0.y * d.y first).
static inline void plane2(u8 *self, s32 i1, s32 i2, const float *M, bool swap) {
  float *x1 = POS(i1), *x2 = POS(i2);
  float m1 = MASS(i1), m2 = MASS(i2);
  float d[3];
  ext_43e920(d, x2, x1);
  float s;
  if (swap) s = M[1] * d[1] + M[0] * d[0];
  else s = d[0] * M[0] + d[1] * M[1];
  s = s + d[2] * M[2];
  if (s > 0.0f) return;
  float k = s * m2 / (m1 + m2);
  ext_451890(x1, M, k * G(float, 0x684ce4));
  ext_451890(x2, M, (k - s) * G(float, 0x684ce4));
}

// Legs (or feet) must not cross: s = (xb - xa) . B; 10 > s: xa += B * ((s * 0.5 - 5) * 0.1), xb += B * ((5 - s * 0.5) * 0.1).
static inline void separate(u8 *self, s32 ia, s32 ib, const float *B) {
  float d[3];
  ext_43e920(d, POS(ib), POS(ia));
  float s = d[1] * B[1] + d[0] * B[0];
  s = s + d[2] * B[2];
  if (G(float, 0x680a70) > s) {
    float h = s * G(float, 0x67a6ac);
    ext_451890(POS(ia), B, (h - G(float, 0x679544)) * G(float, 0x67a284));
    ext_451890(POS(ib), B, (G(float, 0x679544) - h) * G(float, 0x67a284));
  }
}

// 0x547a70 ConstrainedParticleSystem::ZeroOut(int n) (GameCube reference), fastcall: ECX = this, EDX = n; plain ret.
// Fields (PC, packed): +0xf particles (0x34 bytes: position +0xc, mass +0x30), +0x13 distance constraints and +0x2c their count,
// +0x17 minimum-distance constraints and +0x30 their count (both lists 0xc per entry: s32 i, s32 j, float length), +0x50 joint flag.
// n times: when the flag byte is set, the joint-limit block (hip frame A = vnorm(p8 + p9 - p5 - p6), B = vnorm(p9 - p8),
// C = vnorm(B x A); base = mmmul(t_k, frame) per joint; AdjustPlane2 inlined; AdjustCone4/5/6; the leg rule for p12/p13 and p14/p15);
// then 4 passes of: every minimum-distance constraint (0x543680(x_i, x_j, m_i, m_j, len)), every distance constraint
// (0x5434d0(x_i, x_j, m_i, m_j, len)).
static void FASTCALL zeroOut(u8 *self, s32 n) {
  if (n <= 0) return;
  do {
    if (self[0x50]) {
      float hip[9], kr[9], kl[9], sh[9], el[9], mir[9], er[9], M[9];
      float *A = hip, *B = hip + 3, *C = hip + 6;
      ext_43e8e0(A, POS(8), POS(9));
      ext_43e960(A, POS(5));
      ext_43e960(A, POS(6));
      vnormIn(A);
      ext_43e920(B, POS(9), POS(8));
      vnormIn(B);
      ext_446ee0(C, B, A);
      vnormIn(C);
      // right hip
      ext_4de440(M, TBASE(0), hip);
      plane2(self, 8, 12, M, true);
      ext_542310(8, 5, 9, 12, M, AX(0), AY(0), partP(self));
      // left hip
      ext_4de440(M, TBASE(1), hip);
      plane2(self, 9, 13, M, false);
      ext_542310(9, 6, 8, 13, M, AX(1), AY(1), partP(self));
      // right knee: rows D = vnorm(p12 - p8), F = D x E, E = vnorm(B x D)
      ext_43e920(kr, POS(12), POS(8));
      vnormIn(kr);
      ext_446ee0(kr + 6, B, kr);
      vnormIn(kr + 6);
      ext_446ee0(kr + 3, kr, kr + 6);
      ext_4de440(M, TBASE(2), kr);
      ext_5428f0(12, 8, 9, 14, M, AX(2), AY(2), partP(self));
      ext_542ee0(12, 8, 9, 14, M, AX(2), AY(2), partP(self));
      // left knee
      ext_43e920(kl, POS(13), POS(9));
      vnormIn(kl);
      ext_446ee0(kl + 6, B, kl);
      vnormIn(kl + 6);
      ext_446ee0(kl + 3, kl, kl + 6);
      ext_4de440(M, TBASE(3), kl);
      ext_5428f0(13, 9, 8, 15, M, AX(3), AY(3), partP(self));
      ext_542ee0(13, 9, 8, 15, M, AX(3), AY(3), partP(self));
      // left shoulder: J = vnorm(p3 - p2), K = vnorm(p2 + p3 - p5 - p6), L = K x J, K = J x L
      float *J = sh, *K = sh + 3, *L = sh + 6;
      ext_43e920(J, POS(3), POS(2));
      vnormIn(J);
      ext_43e8e0(K, POS(2), POS(3));
      ext_43e960(K, POS(5));
      ext_43e960(K, POS(6));
      vnormIn(K);
      ext_446ee0(L, K, J);
      ext_446ee0(K, J, L);
      ext_4de440(M, TBASE(4), sh);
      plane2(self, 3, 7, M, false);
      ext_542310(3, 6, 1, 7, M, AX(4), AY(4), partP(self));
      // left elbow: rows N = vnorm(p7 - p3), Q = N x O, O = vnorm(B x N)
      ext_43e920(el, POS(7), POS(3));
      vnormIn(el);
      ext_446ee0(el + 6, B, el);
      vnormIn(el + 6);
      ext_446ee0(el + 3, el, el + 6);
      ext_4de440(M, TBASE(5), el);
      ext_542ee0(7, 3, 6, 11, M, AX(5), AY(5), partP(self));
      // right shoulder: rows -J, -K, L (the mcpy is overwritten by the mmmul)
      ext_4e0d40(mir, J, bitsf(0xbf800000));
      ext_4e0d40(mir + 3, K, bitsf(0xbf800000));
      ((u32 *)mir)[6] = ((u32 *)L)[0];
      ((u32 *)mir)[7] = ((u32 *)L)[1];
      ((u32 *)mir)[8] = ((u32 *)L)[2];
      ext_4de420(M, TBASE(6));
      ext_4de440(M, TBASE(6), mir);
      plane2(self, 2, 4, M, false);
      ext_542310(2, 5, 1, 4, M, AX(6), AY(6), partP(self));
      // right elbow: rows R = vnorm(p4 - p2), T = R x S, S = vnorm(B x R)
      ext_43e920(er, POS(4), POS(2));
      vnormIn(er);
      ext_446ee0(er + 6, B, er);
      vnormIn(er + 6);
      ext_446ee0(er + 3, er, er + 6);
      ext_4de440(M, TBASE(7), er);
      ext_542ee0(4, 2, 5, 10, M, AX(7), AY(7), partP(self));
      // legs and feet must not cross
      separate(self, 12, 13, B);
      separate(self, 14, 15, B);
    }
    for (s32 pass = 4; pass != 0; pass--) {
      u8 *e = *(u8 **)(self + 0x17);
      for (s32 i = 0; i < *(s32 *)(self + 0x30); i++, e += 0xc) {
        u8 *pj = partP(self) + *(s32 *)(e + 4) * 0x34;
        u8 *pi = partP(self) + *(s32 *)e * 0x34;
        ext_543680((float *)(pi + 0xc), (float *)(pj + 0xc), *(float *)(pi + 0x30), *(float *)(pj + 0x30), *(float *)(e + 8));
      }
      e = *(u8 **)(self + 0x13);
      for (s32 i = 0; i < *(s32 *)(self + 0x2c); i++, e += 0xc) {
        u8 *pj = partP(self) + *(s32 *)(e + 4) * 0x34;
        u8 *pi = partP(self) + *(s32 *)e * 0x34;
        ext_5434d0((float *)(pi + 0xc), (float *)(pj + 0xc), *(float *)(pi + 0x30), *(float *)(pj + 0x30), *(float *)(e + 8));
      }
    }
  } while (--n);
}
PCREG(547a70, zeroOut);
