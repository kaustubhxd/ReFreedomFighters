// batch1102.cpp - collision thread, batch 1102: 0x4e9380, sphere against one triangle (used by
// ZCollisionBox::FetchPushList 0x4e99c0).
#include "ff.h"

static inline s32 sbits(float f) { return (s32)fbits(f); }
static inline float fneg(float f) { return bitsf(fbits(f) ^ 0x80000000u); }

extern "C" u8 STDCALL ext_4eb100(const float *m, const float *b, float *x);   // solve3 (batch 1101)
extern "C" u32 THISCALL ext_4e9780(void *self, const float *p, const float *a, const float *b, float *t,
                                   const float *radius, float *dist, float *dir, u32 rA, u32 rB, u32 rMid);

// 0x4e9380 (unnamed; guessed SphereTriangle) thiscall, ret 0x14: (const float tri[9], const float *p, float radius,
// float *push, float *depth), returns al.
// 1. n = (v2 - v0) x (v1 - v0). If |n|^2 < 2^-26 (or NaN) returns false. n is normalised.
// 2. Solves [n; e1; e2] x = p - v0 (solve3). When it succeeds with x1 >= 0, x2 >= 0 (sign bits), x1 + x2 < 1
//    (integer compare) and radius >= |x0|: push = n * (x0 < 0 ? 1 : -1) (by the sign bit), depth = radius - |x0|,
//    returns true. |x0| is taken in double, as the exe does.
// 3. Otherwise tests the edges v1-v2, v0-v1, v2-v0 with the sphere-segment test (0x4e9780). Each hit sets
//    push = -dir and depth = radius - dist; the first two also shrink the test radius to dist. Returns whether any
//    edge hit.
static u8 THISCALL sphereTri(void *self, const float *tri, const float *p, float radius, float *push, float *depth) {
  float e1x = tri[3] - tri[0];
  float e2y = tri[7] - tri[1];
  float e2z = tri[8] - tri[2];
  float e1y = tri[4] - tri[1];
  float e1z = tri[5] - tri[2];
  float e2x = tri[6] - tri[0];
  float nx = (e2y * e1z) - (e2z * e1y);
  float ny = (e2z * e1x) - (e2x * e1z);
  float nz = (e2x * e1y) - (e2y * e1x);
  float len2 = ((ny * ny) + (nx * nx)) + (nz * nz);
  if (!(len2 >= bitsf(0x32800000u)))
    return 0;
  float len = (float)crt::sqrt((double)len2);
  float inv = 1.0f / len;
  nx = nx * inv;
  ny = ny * inv;
  nz = nz * inv;
  float m[9] = {nx, ny, nz, e1x, e1y, e1z, e2x, e2y, e2z};
  float dir[3], x[3];
  dir[0] = p[0] - tri[0];
  dir[1] = p[1] - tri[1];
  dir[2] = p[2] - tri[2];
  if (ext_4eb100(m, dir, x)) {
    float x0 = x[0], x1 = x[1], x2 = x[2];
    float s12 = x2 + x1;
    if (sbits(x1) >= 0 && sbits(x2) >= 0 && sbits(s12) < (s32)0x3f800000) {
      float sign = bitsf((~fbits(x0) & 0xbf800000u) | 0x3f800000u);
      float ax = (float)bitsf64(f64bits((double)x0) & 0x7fffffffffffffffull);
      if (radius >= ax) {
        push[0] = nx * sign;
        push[1] = ny * sign;
        push[2] = nz * sign;
        *depth = radius - ax;
        return 1;
      }
    }
  }
  float r = radius, dist, t;
  u8 hit = 0;
  if (ext_4e9780(self, p, tri + 3, tri + 6, &t, &r, &dist, dir, 0x10, 0x20, 2)) {
    hit = 1;
    r = dist;
    *depth = radius - dist;
    push[0] = fneg(dir[0]);
    push[1] = fneg(dir[1]);
    push[2] = fneg(dir[2]);
  }
  if (ext_4e9780(self, p, tri, tri + 3, &t, &r, &dist, dir, 8, 0x10, 1)) {
    r = dist;
    hit = 1;
    *depth = radius - dist;
    push[0] = fneg(dir[0]);
    push[1] = fneg(dir[1]);
    push[2] = fneg(dir[2]);
  }
  if (ext_4e9780(self, p, tri + 6, tri, &t, &r, &dist, dir, 0x20, 8, 4)) {
    *depth = radius - dist;
    push[0] = fneg(dir[0]);
    push[1] = fneg(dir[1]);
    push[2] = fneg(dir[2]);
    return 1;
  }
  return hit;
}
PCREG(4e9380, sphereTri);
