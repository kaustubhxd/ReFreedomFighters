// batch1067.cpp - ZFFCam::CalcCollisionParameters (0x5c9910; the ZFFCam variant, see batch 1007 for ZFFCamera1).
// Camera thread, 2026-10-11.
#include "cam.h"

extern "C" FASTCALL void ext_441940(float *d, const float *s);                  // d += s
extern "C" FASTCALL void ext_43e920(float *d, const float *a, const float *b);  // d = a - b
extern "C" THISCALL void ext_4e0d00(float *v, float s);                         // v *= s
extern "C" FASTCALL void ext_451890(float *d, const float *s, float k);         // d += s * k

// Any nonzero or NaN component: the vector is normalized (the original's jp tests).
static inline bool needs_norm(const float *v) {
  return !(v[0] == 0.0f && v[1] == 0.0f && v[2] == 0.0f);
}

// x87 normalize, as in batch 1040 (extended-precision length and reciprocal).
static void normalize3(float *v) {
  long double s = (long double)v[0] * v[0];
  s = s + (long double)v[1] * v[1];
  s = s + (long double)v[2] * v[2];
  long double inv = 1.0L / fsqrt_x87(s);
  v[0] = (float)(v[0] * inv);
  v[1] = (float)(v[1] * inv);
  v[2] = (float)(v[2] * inv);
}

// 0x5c9910 ZFFCam::CalcCollisionParameters(void) (thiscall): five collision rays from the offset vector (+0x78..+0x80)
// and the radius r (+0x2fa): rays at +0xee, +0x170, +0x1f2, +0x274, each pushed through the object's slot 0x88 (at +0x44)
// and then offset by +0x6c (the copy of +0x30c..+0x314); the offset (+0x444 - +0x30c) is normalized into +0x2fe and
// scaled by r; the result is copied to +0x78 and to +0xfa, +0x17c, +0x1fe, +0x280 and added back with 1.0.
static THISCALL void ZFFCam_CalcCollisionParameters(u8 *self) {
  float r = at<float>(self, 0x2fa);
  at<float>(self, 0x6c) = at<float>(self, 0x30c);
  at<float>(self, 0x70) = at<float>(self, 0x310);
  at<float>(self, 0x74) = at<float>(self, 0x314);
  // the four ray records: (r, r, 0), (-r, r, 0), (-r, -r, 0), (r, -r, 0)
  float *ray0 = (float *)(self + 0xee);
  ray0[0] = r;
  ray0[1] = r;
  at<u32>(self, 0xf6) = 0;
  at<float>(self, 0x170) = -r;
  at<float>(self, 0x174) = r;
  at<u32>(self, 0x178) = 0;
  float *ray2 = (float *)(self + 0x1f2);
  ray2[0] = -r;
  ray2[1] = -r;
  at<u32>(self, 0x1fa) = 0;
  float *ray3 = (float *)(self + 0x274);
  ray3[0] = r;
  ray3[1] = -r;
  at<u32>(self, 0x27c) = 0;
  // the object at +0x44 gets each ray (its slot 0x88)
  vcall<void>(at<u8 *>(self, 0x44), 0x88, (void *)(self + 0xee));
  vcall<void>(at<u8 *>(self, 0x44), 0x88, (void *)(self + 0x170));
  vcall<void>(at<u8 *>(self, 0x44), 0x88, (void *)(self + 0x1f2));
  vcall<void>(at<u8 *>(self, 0x44), 0x88, (void *)(self + 0x274));
  // each ray is moved by the offset copy (+0x6c)
  ext_441940((float *)(self + 0xee), (const float *)(self + 0x6c));
  ext_441940((float *)(self + 0x170), (const float *)(self + 0x6c));
  ext_441940((float *)(self + 0x1f2), (const float *)(self + 0x6c));
  ext_441940((float *)(self + 0x274), (const float *)(self + 0x6c));
  ext_43e920((float *)(self + 0x78), (const float *)(self + 0x444), (const float *)(self + 0x30c));
  for (int i = 0; i < 3; i++) at<float>(self, 0x2fe + 4 * i) = at<float>(self, 0x78 + 4 * i);
  float *nv = (float *)(self + 0x2fe);
  if (needs_norm(nv)) normalize3(nv);
  ext_4e0d00(nv, at<float>(self, 0x2fa));
  ext_441940((float *)(self + 0x78), nv);
  at<u32>(self, 0xfa) = at<u32>(self, 0x78);
  at<u32>(self, 0xfe) = at<u32>(self, 0x7c);
  at<u32>(self, 0x102) = at<u32>(self, 0x80);
  at<u32>(self, 0x17c) = at<u32>(self, 0x78);
  at<u32>(self, 0x180) = at<u32>(self, 0x7c);
  at<u32>(self, 0x184) = at<u32>(self, 0x80);
  at<u32>(self, 0x1fe) = at<u32>(self, 0x78);
  at<u32>(self, 0x202) = at<u32>(self, 0x7c);
  at<u32>(self, 0x206) = at<u32>(self, 0x80);
  at<u32>(self, 0x280) = at<u32>(self, 0x78);
  at<u32>(self, 0x284) = at<u32>(self, 0x7c);
  at<u32>(self, 0x288) = at<u32>(self, 0x80);
  ext_451890((float *)(self + 0x78), nv, 1.0f);
}
PCREG(5c9910, ZFFCam_CalcCollisionParameters);
