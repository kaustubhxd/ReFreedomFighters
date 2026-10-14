// batch8816.cpp - hit-reaction thread, batch 8816: PullTriangleCyl2, the response of a ragdoll limb capsule that touched a triangle
// (ConstrainedParticleSystem::CollideLineBetweenParticles3 calls it after CollideSolidCappedCylinderAndTriangle found a contact).
#include "ff.h"

#define VT(o, off) ((*(void ***)(o))[(off) / 4])

extern "C" void FASTCALL ext_451890(float *d, const float *v, float s);                 // vaddscalar d += v * s
extern "C" void FASTCALL ext_4e0d40(float *out, const float *a, float s);               // vscalar3 out = a * s
extern "C" float THISCALL ext_44c840(float *v);                                         // vnorm in place, length in ST0
extern "C" void FASTCALL ext_443ef0(float *d, const float *a, const float *v, float s); // vaddscalar4 d = a + v * s
extern "C" void THISCALL ext_4e0d00(float *v, float s);                                 // vscalar in place
extern "C" void FASTCALL ext_546980(const float *pos, u8 b, float vol, u32 id, u32 z);  // PlayBodySound (not verified)

typedef u8 *(THISCALL *vPU)(void *self, u32 a);

static inline float neg(float x) { volatile float v = x; return bitsf(fbits(v) ^ 0x80000000u); }   // xorps with the sign mask 0x67af40 (volatile: clang must not fold the flip into a product)

// 0x547080 PullTriangleCyl2(const float[2]* tri, float, float, float, float* PA, float* PB, float wA, float wB, float* QA, float* QB,
// SSauColi* sau, bool silent, u32 id) (). fastcall: ECX = tri (not read on PC), EDX = PA, the rest on the stack; ret 0x2c.
// sau: +0 normal n, +0xc t (where along the capsule A..B), +0x10 depth. PA / PB are the capsule end positions, QA / QB their
// displacements (velocities), wA / wB their inverse masses.
//  den = (1 - t) wA (1 - t) + t wB t; |den| (double) < 0.001 -> nothing. inv = 1 / den, dd = depth inv.
//  PA += n ((t - 1) dd wA); PB += n -(dd t wB). v = QA (1 - t) + QB t. n is normalised in place. s = n . v.
//  s > 0 (moving into the face): if s > 1, unless silent, PlayBodySound(PA (1 - t) + PB t, false, min(1, s / 12), id, 0).
//    k = s inv; QA += n ((t - 1) k wA); QB += n -(k t wB) (the normal part removed).
//    g = v - n s (tangential), l = |g| (g normalised); s2 = 2 s. Friction: l > 1 and l > s2 -> QA += g ((t - 1) s2 inv),
//    QB += g -(s2 t inv) (and PA (1 - t) + PB t is computed again, unused); else QA += g ((t - 1) l inv), QB += g -(l t inv).
//  Then the geom of `id` (render manager slot 0x58, +8): when its +0x3c has 0x40040000 set (hard): PA -= n depth, PB -= n depth,
//  QA *= -0.9, QB *= -0.9.
static void FASTCALL pullTriangleCyl2(const float *, float *PA, float, float, float, float *PB, float wA, float wB, float *QA,
                                      float *QB, float *sau, u8 silent, u32 id) {
  float one = G(float, 0x678858);
  float t = sau[3];
  float u = one - t;
  float den = u * wA * u;
  den = den + t * wB * t;
  if (G(double, 0x6a3140) > __builtin_fabs((double)den)) return;
  float inv = one / den;
  float dd = sau[4] * inv;
  float tm1 = t - one;
  ext_451890(PA, sau, tm1 * dd * wA);
  ext_451890(PB, sau, neg(dd * sau[3] * wB));
  float v[3], c[3], g[3];
  ext_4e0d40(v, QA, one - sau[3]);
  ext_451890(v, QB, sau[3]);
  ext_44c840(sau);
  float s = sau[1] * v[1] + sau[0] * v[0];
  s = s + sau[2] * v[2];
  if (!(s > G(float, 0x6785d0))) goto hard;
  if (s > G(float, 0x678858)) {
    ext_4e0d40(c, PA, G(float, 0x678858) - sau[3]);
    ext_451890(c, PB, sau[3]);
    if (!silent) {
      float vol = __builtin_ia32_minss(_mm_set_ss(G(float, 0x678858)), _mm_set_ss(s / G(float, 0x680a74)))[0];
      ext_546980(c, 0, vol, id, 0);
    }
  }
  {
    float k = s * inv;
    ext_451890(QA, sau, (sau[3] - G(float, 0x678858)) * k * wA);
    ext_451890(QB, sau, neg(k * sau[3] * wB));
    float s2 = s + s;
    ext_443ef0(g, v, sau, neg(s));
    float l = ext_44c840(g);
    float o = G(float, 0x678858);
    if (l > o && l > s2) {
      ext_451890(QA, g, (sau[3] - o) * s2 * inv);
      ext_451890(QB, g, neg(s2 * sau[3] * inv));
      ext_4e0d40(c, PA, G(float, 0x678858) - sau[3]);
      ext_451890(c, PB, sau[3]);
    } else {
      ext_451890(QA, g, (sau[3] - o) * l * inv);
      ext_451890(QB, g, neg(l * sau[3] * inv));
    }
  }
hard:
  void *rm = *(void **)(G(u8 *, 0x70039c) + 0x9b);
  u8 *ob = ((vPU)VT(rm, 0x58))(rm, id);
  u8 *geom = *(u8 **)(ob + 8);
  if (*(u32 *)(geom + 0x3c) & 0x40040000) {
    ext_451890(PA, sau, neg(sau[4]));
    ext_451890(PB, sau, neg(sau[4]));
    ext_4e0d00(QA, bitsf(0xbf666666));
    ext_4e0d00(QB, bitsf(0xbf666666));
  }
}
PCREG(547080, pullTriangleCyl2);
