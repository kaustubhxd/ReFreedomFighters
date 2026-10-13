// batch1104.cpp - collision thread, batch 1104: ZCollisionBox::PushOutOfAllTris (0x4eaa80).
#include "ff.h"

extern "C" u32 THISCALL ext_4e99c0(u8 *self, u8 *impact, u8 *out, const float *p, const float *scale);  // FetchPushList
extern "C" void FASTCALL ext_43e920(float *dst, const float *a, const float *b);   // PSVECSubtract (batch 34)
extern "C" void FASTCALL ext_4e0d40(float *out, const float *a, float s);          // vscalar (batch 29)
extern "C" void FASTCALL ext_441940(float *v, const float *a);                     // PSVECAdd (batch 34)

// Signed distance of c from the push plane of entry e (direction e[0..2], point e[3..5]).
static inline float planeDist(const float *c, const float *e) {
  float d[3];
  ext_43e920(d, c, e + 3);
  return ((d[0] * e[0]) + (d[1] * e[1])) + (e[2] * d[2]);
}

// 0x4eaa80 ZCollisionBox::PushOutOfAllTris(ZSphereImpact *impact, float *pos, float *fallback, const float *scale),
// thiscall, ret 0x10, returns al = (any push entries). Works in unscaled box space c = pos / scale:
// 1. FetchPushList(impact, list, c, 1/scale) collects up to 0x400 push planes.
// 2. Up to 5 relaxation passes: for each plane c is behind (dist < 0), c += dir * (dist * -0.1); stops early when no
//    plane was behind or the deepest was within 0.001.
// 3. One full pass: c += dir * -dist for each plane still behind.
// 4. Up to 5 more passes with a damped step: -dist, or (-dist - 0.01) * 0.1 + 0.01 above 0.01.
// 5. pos = c * scale, or fallback (through 1/scale and back) when the deepest plane in the last pass is below -0.1.
static u8 THISCALL pushOutOfAllTris(u8 *self, u8 *impact, float *pos, const float *fallback, const float *S) {
  float list[0x400 * 6];
  float invS[3], c[3], mv[3];
  invS[0] = 1.0f / S[0];
  invS[1] = 1.0f / S[1];
  invS[2] = 1.0f / S[2];
  c[0] = pos[0] * invS[0];
  c[1] = pos[1] * invS[1];
  c[2] = pos[2] * invS[2];
  u32 n = ext_4e99c0(self, impact, (u8 *)list, c, invS);
  float minD = 0.0f;
  if (n) {
    for (u32 iter = 0; iter != 5; iter++) {
      minD = 0.0f;
      u8 any = 0;
      for (u32 k = 0; k < n; k++) {
        const float *e = list + 6 * k;
        float dist = planeDist(c, e);
        if (0.0f > dist) {
          any = 1;
          minD = (dist < minD) ? dist : minD;
          ext_4e0d40(mv, e, dist * -0.1f);
          ext_441940(c, mv);
        }
      }
      if (!any || minD >= -0.001f)
        break;
    }
    for (u32 k = 0; k < n; k++) {
      const float *e = list + 6 * k;
      float dist = planeDist(c, e);
      if (0.0f > dist) {
        ext_4e0d40(mv, e, bitsf(fbits(dist) ^ 0x80000000u));
        ext_441940(c, mv);
      }
    }
    for (u32 iter = 0; iter != 5; iter++) {
      minD = 0.0f;
      u8 any = 0;
      for (u32 k = 0; k < n; k++) {
        const float *e = list + 6 * k;
        float dist = planeDist(c, e);
        if (0.0f > dist) {
          any = 1;
          minD = (dist < minD) ? dist : minD;
          float m = bitsf(fbits(dist) ^ 0x80000000u);
          if (m > 0.01f)
            m = ((m - 0.01f) * 0.1f) + 0.01f;
          ext_4e0d40(mv, e, m);
          ext_441940(c, mv);
        }
      }
      if (!any || minD >= -0.001f)
        break;
    }
  }
  float r0, r1, r2;
  if (n && -0.1f > minD) {
    r0 = fallback[0] * invS[0];
    r1 = fallback[1] * invS[1];
    r2 = fallback[2] * invS[2];
  } else {
    r0 = c[0];
    r1 = c[1];
    r2 = c[2];
  }
  r0 = r0 * S[0];
  r1 = S[1] * r1;
  r2 = S[2] * r2;
  pos[0] = r0;
  pos[1] = r1;
  pos[2] = r2;
  return n != 0;
}
PCREG(4eaa80, pushOutOfAllTris);
