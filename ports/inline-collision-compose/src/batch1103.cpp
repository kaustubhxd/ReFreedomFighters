// batch1103.cpp - collision thread, batch 1103: ZCollisionBox::FetchPushList (0x4e99c0).
#include "ff.h"

static inline s32 sbits(float f) { return (s32)fbits(f); }
static inline float fneg(float f) { return bitsf(fbits(f) ^ 0x80000000u); }

extern "C" u8 THISCALL ext_4e9380(void *self, const float *tri, const float *p, float radius, float *push, float *depth);
extern "C" void FASTCALL ext_43e920(float *dst, const float *a, const float *b);   // PSVECSubtract (batch 34)
extern "C" void FASTCALL ext_446ee0(float *dst, const float *a, const float *b);   // vcross (batch 35)
extern "C" void THISCALL ext_4e09b0(float *v);                                     // vneg (batch 29)
extern "C" void FASTCALL ext_4e0d40(float *out, const float *a, float s);          // vscalar (batch 29)
extern "C" void FASTCALL ext_441940(float *v, const float *a);                     // PSVECAdd (batch 34)

// ZCollisionBox (layout from this body): +0 last surface word (written on a floor hit), +8 strip count,
// +0xc first strip, +0x10 / +0x14 bounding-box array words (+0x14 is the array; the box count is
// ((+0x10) - (+0x14) + (+0xc)) / 24, as the exe computes it), boxes are 24 bytes (min xyz, max xyz).
// A strip is a 0x18-byte header (+0 vertex count N, +8 / +0xc / +0x10 surface words) followed by N vertices
// (12 bytes each); its triangles are (V[j], V[j+1], V[j+2]) for j < N - 2. The next strip follows the vertices.
// Push entries (SPushTriangle) are 24 bytes: push direction, then the pushed-out centre.

static inline bool vecEq(const float *a, const float *b) { return a[0] == b[0] && a[1] == b[1] && a[2] == b[2]; }

// 0x4e99c0 ZCollisionBox::FetchPushList(ZSphereImpact *impact, SPushTriangle *out, float *p, float *scale),
// thiscall, ret 0x10, returns the number of push entries (at most 0x400).
// For each strip (skipped when its box, scaled, is farther than its scaled half-diagonal + 1 from p) and each
// non-degenerate triangle, scaled by `scale`: sphere-triangle test with radius 1.25. On a hit:
//  - floor (|n.y| > 0.7 for the triangle's own normal) with p inside the triangle's XZ outline and above its plane,
//    and the push pointing down (push.y < -0.7): push = (0, -1, 0) and depth = -(depth / push.y);
//  - wall (|push.y| < 0.7): the push is made horizontal and depth divided by its dot with the old push;
//  - with push.y < -0.7 and depth > 0.25 the strip's surface words go to the impact (+0, +4, byte +8 = 1) and
//    +0x10 to this+0;
// then depth moves 2^-13 away from zero, and the entry is (-push, p - push * (depth - 0.25)).
static u32 THISCALL fetchPushList(u8 *self, u8 *impact, u8 *out, const float *p, const float *S) {
  u32 count = 0;
  u8 *cur = *(u8 **)(self + 0xc);
  s32 nbox = (s32)(*(u32 *)(self + 0x10) - *(u32 *)(self + 0x14) + *(u32 *)(self + 0xc)) / 24;
  if (*(u32 *)(self + 8) == 0)
    return 0;
  const float *box = (const float *)(*(u8 **)(self + 0x14) + 0xc);
  u32 i = 0;
  for (;;) {
    if (count == 0x400)
      return 0x400;
    u8 *next = 0;
    bool skip = false;
    if (i < (u32)nbox) {
      float cx = (box[-3] + box[0]) * 0.5f;
      float cy = (box[-2] + box[1]) * 0.5f;
      float cz = (box[2] + box[-1]) * 0.5f;
      float hx = (box[0] - cx) * S[0];
      float hy = (box[1] - cy) * S[1];
      float hz = (box[2] - cz) * S[2];
      float r = (float)crt::sqrt((double)(((hy * hy) + (hx * hx)) + (hz * hz)));
      box += 6;
      float dx = (cx * S[0]) - p[0];
      float dy = (cy * S[1]) - p[1];
      float dz = (cz * S[2]) - p[2];
      float rad = r + 1.0f;
      float dd = ((dy * dy) + (dx * dx)) + (dz * dz);
      if (dd > rad * rad) {
        skip = true;
        next = cur + *(u32 *)cur * 12 + 0x18;
      }
    }
    if (!skip) {
      const float *V = (const float *)(cur + 0x18);
      u32 ntri = *(u32 *)cur - 2;
      float *entry = (float *)(out + count * 24 + 0xc);
      for (u32 j = 0; j != ntri; j++, V += 3) {
        if (count == 0x400)
          break;
        if (vecEq(V, V + 3) || vecEq(V, V + 6) || vecEq(V + 3, V + 6))
          continue;
        float T[9];
        for (int k = 0; k < 9; k++)
          T[k] = S[k % 3] * V[k];
        float push[3], depth;
        if (!ext_4e9380(self, T, p, 1.25f, push, &depth))
          continue;
        float E1[3], E2[3], E3[3], N[3], D0[3], D1[3], D2[3];
        ext_43e920(E1, T + 3, T);
        ext_43e920(E2, T + 6, T + 3);
        ext_446ee0(N, E1, E2);
        if (N[0] != 0.0f || N[1] != 0.0f || N[2] != 0.0f) {
          long double len = fsqrt_x87(((long double)N[0] * N[0] + (long double)N[1] * N[1]) + (long double)N[2] * N[2]);
          long double inv = 1.0L / len;
          N[0] = (float)(N[0] * inv);
          N[1] = (float)(N[1] * inv);
          N[2] = (float)(N[2] * inv);
        }
        float ny = N[1];
        float dv, py = 0.0f;
        bool floorHit = false;
        if (-0.7f > ny || ny > 0.7f) {
          ext_43e920(E3, T, T + 6);
          float a0 = fneg(E1[2]), a2 = E1[0], b0 = fneg(E2[2]), b2 = E2[0], c0 = fneg(E3[2]), c2 = E3[0];
          ext_43e920(D0, T, p);
          ext_43e920(D1, T + 3, p);
          ext_43e920(D2, T + 6, p);
          float s0 = ((D0[0] * a0) + (D0[1] * 0.0f)) + (D0[2] * a2);
          float s1 = ((D1[0] * b0) + (D1[1] * 0.0f)) + (D1[2] * b2);
          float s2 = ((D2[0] * c0) + (D2[1] * 0.0f)) + (D2[2] * c2);
          bool inside = (s0 <= 0.0f && s1 <= 0.0f && s2 <= 0.0f) || (s0 >= 0.0f && s1 >= 0.0f && s2 >= 0.0f);
          if (inside) {
            float d = ((N[1] * T[1]) + (N[0] * T[0])) + (N[2] * T[2]);
            float h = fneg((fneg(d) + ((p[2] * N[2]) + (p[0] * N[0]))) / N[1]);
            if (p[1] > h && -0.7f > push[1]) {
              dv = fneg(depth / push[1]);
              push[0] = 0.0f;
              push[1] = -1.0f;
              push[2] = 0.0f;
              floorHit = true;
            }
          }
        }
        if (!floorHit) {
          py = push[1];
          if (py > -0.7f && 0.7f > py) {
            float len = (float)crt::sqrt((double)(((push[0] * push[0]) + 0.0f) + (push[2] * push[2])));
            float inv = (len != 0.0f) ? 1.0f / len : 0.0f;
            float nx = push[0] * inv, nyy = inv * 0.0f, nz = push[2] * inv;
            float c = ((nyy * push[1]) + (nx * push[0])) + (nz * push[2]);
            push[0] = nx;
            push[1] = nyy;
            push[2] = nz;
            dv = depth / c;
            py = nyy;
          } else {
            dv = depth;
          }
        }
        if ((floorHit || -0.7f > py) && dv > 0.25f) {
          *(u32 *)self = *(u32 *)(cur + 0x10);
          impact[8] = 1;
          *(u32 *)(impact + 4) = *(u32 *)(cur + 0xc);
          *(u32 *)impact = *(u32 *)(cur + 8);
        }
        dv = (dv > 0.0f) ? dv + 0.0001220703125f : dv - 0.0001220703125f;
        ext_4e09b0(push);
        ext_4e0d40(entry, push, dv - 0.25f);
        ext_441940(entry, p);
        entry[-3] = push[0];
        entry[-2] = push[1];
        entry[-1] = push[2];
        count++;
        entry += 6;
      }
      next = (u8 *)V + 0x18;
    }
    cur = next;
    i++;
    if (i == *(u32 *)(self + 8))
      return count;
  }
}
PCREG(4e99c0, fetchPushList);
