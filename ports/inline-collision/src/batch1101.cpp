// batch1101.cpp - collision thread, batch 1101: leaves of ZCollisionBox::FetchPushList (0x4e99c0).
#include "ff.h"

static inline s32 sbits(float f) { return (s32)fbits(f); }
static const u32 kEps = 0x358637bd;   // 1e-6f, compared as integer bits (the exe's idiom for |x| < 1e-6)

// 0x4eb100 (unnamed; guessed Solve3x3) (const float *m, const float *b, float *x), ret 0xc, ECX unused.
// Cramer's rule in single precision, in the exe's exact operation order. Returns false and leaves x alone when
// |det| < 1e-6 (integer compare of the bits, so a NaN determinant goes on). x[0] and x[1] are stored before the next
// lane reads b, as in the exe.
static u8 STDCALL solve3(const float *m, const float *b, float *x) {
  float det = (((((m[0] * m[4]) * m[8]) + ((m[1] * m[5]) * m[6])) + ((m[2] * m[3]) * m[7])) - ((m[2] * m[4]) * m[6]))
              - ((m[3] * m[1]) * m[8]);
  det = det - ((m[0] * m[5]) * m[7]);
  if (sbits(bitsf(fbits(det) & 0x7fffffff)) < (s32)kEps)
    return 0;
  float inv = 1.0f / det;
  x[0] = (((((b[0] * m[4]) * m[8]) + ((b[1] * m[5]) * m[6])) + ((b[2] * m[3]) * m[7])) - ((b[2] * m[4]) * m[6]) -
          ((b[1] * m[3]) * m[8])) - ((b[0] * m[5]) * m[7]);
  float b2 = b[2];
  x[1] = (((((m[1] * b2) * m[6]) + ((m[0] * b[1]) * m[8])) + ((m[2] * b[0]) * m[7])) - ((m[2] * b[1]) * m[6]) -
          ((m[1] * b[0]) * m[8])) - ((m[0] * b2) * m[7]);
  float m5 = m[5];
  float x2 = (((((m[0] * m[4]) * b[2]) + ((m[1] * m5) * b[0])) + ((m[2] * m[3]) * b[1])) - ((m[2] * m[4]) * b[0]) -
              ((m[1] * m[3]) * b[2])) - ((m[0] * m5) * b[1]);
  x[0] = x[0] * inv;
  x[1] = x[1] * inv;
  x[2] = x2 * inv;
  return 1;
}
PCREG(4eb100, solve3);

typedef long double(THISCALL *vcallRandF)(void *self, const char *file, u32 line);

// 0x4eaf10 (unnamed; guessed RandomUnitVector) (float *v), thiscall (this unused), ret 4. Draws v = (r - 0.5) per
// lane from the engine's random-float slot 0x1c0 of [0x70039c] (file 0x697650, line 0x4af) until |v| >= 1e-6
// (integer compare), then normalises v (the z lane is scaled from its saved copy, not re-read from v).
static void THISCALL randUnitVec(void *self, float *v) {
  (void)self;
  float z, len;
  do {
    u8 *sys = G(u8 *, 0x70039c);
    v[0] = (float)(((vcallRandF)(*(void ***)sys)[0x1c0 / 4])(sys, (const char *)0x697650u, 0x4afu) - 0.5L);
    sys = G(u8 *, 0x70039c);
    v[1] = (float)(((vcallRandF)(*(void ***)sys)[0x1c0 / 4])(sys, (const char *)0x697650u, 0x4afu) - 0.5L);
    sys = G(u8 *, 0x70039c);
    z = (float)(((vcallRandF)(*(void ***)sys)[0x1c0 / 4])(sys, (const char *)0x697650u, 0x4afu) - 0.5L);
    float s = (v[0] * v[0]) + (v[1] * v[1]);
    v[2] = z;
    len = (float)crt::sqrt((double)(s + (z * z)));
  } while (sbits(len) < (s32)kEps);
  float inv = 1.0f / len;
  v[0] = v[0] * inv;
  v[1] = inv * v[1];
  v[2] = z * inv;
}
PCREG(4eaf10, randUnitVec);

extern "C" void THISCALL ext_4eaf10(void *self, float *v);

// 0x4e9780 (unnamed; guessed SphereVsSegment) thiscall, ret 0x28:
// (p, a, b, float *t, const float *radius, float *dist, float *dir, rA, rB, rMid). Closest point on segment a-b to p:
// t = dot(p - a, b - a) / |b - a|^2, with t < 0 (sign bit) giving 0 and the dot above |b - a|^2 (integer compare)
// giving 1. dir = p - closest. When |dir|^2 > r^2 (integer compare) returns 0. Otherwise *dist = |dir|; dir is
// normalised, or replaced by a random unit vector when |dir| < 1e-6. Returns rA, rB or rMid for the three cases.
static u32 THISCALL sphereSeg(void *self, const float *p, const float *a, const float *b, float *t, const float *radius,
                              float *dist, float *dir, u32 rA, u32 rB, u32 rMid) {
  float a1 = a[1];
  float p1 = p[1] - a1;
  float d0 = b[0] - a[0];
  float d1 = b[1] - a1;
  float d2 = b[2] - a[2];
  float p0 = p[0] - a[0];
  float p2 = p[2] - a[2];
  float len2 = ((d1 * d1) + (d0 * d0)) + (d2 * d2);
  float dot = ((d1 * p1) + (d0 * p0)) + (d2 * p2);
  *t = dot;
  u32 ret;
  float o2;
  if (sbits(*t) < 0) {
    ret = rA;
    *t = 0.0f;
    dir[0] = p[0] - a[0];
    dir[1] = p[1] - a[1];
    o2 = p[2] - a[2];
  } else if (sbits(*t) > sbits(len2)) {
    ret = rB;
    *t = 1.0f;
    dir[0] = p[0] - b[0];
    dir[1] = p[1] - b[1];
    o2 = p[2] - b[2];
  } else {
    float q = dot / len2;
    ret = rMid;
    *t = q;
    float c0 = (q * d0) + a[0];
    float c1 = (q * d1) + a[1];
    float c2 = (q * d2) + a[2];
    dir[0] = p[0] - c0;
    dir[1] = p[1] - c1;
    o2 = p[2] - c2;
  }
  float e1 = dir[1], e0 = dir[0];
  dir[2] = o2;
  float dd = ((e0 * e0) + (e1 * e1)) + (o2 * o2);
  float rr = *radius * *radius;
  if (sbits(dd) > sbits(rr))
    return 0;
  float len = (float)crt::sqrt((double)dd);
  *dist = len;
  if (sbits(*dist) > (s32)kEps) {
    float inv = 1.0f / len;
    dir[0] = dir[0] * inv;
    float y = dir[1] * inv;
    float z = inv * dir[2];
    dir[1] = y;
    dir[2] = z;
    return ret;
  }
  ext_4eaf10(self, dir);
  return ret;
}
PCREG(4e9780, sphereSeg);
