// batch1029.cpp - ZCamHelper recruit scouting: GetRecruitPosPrecisionAim, GetRecruitScoutPosColi.
// The original Find3DPointerPos / Find3DPointerShadowPos are called through ext_ (exe code), so only this
// function's own logic is compared. Camera thread, 2026-10-11.
#include "cam.h"

extern "C" THISCALL u32 ext_5ceed0(void *self, float *out, const float *o, const float *d, u32 mask, u32 a, u32 b);
extern "C" THISCALL void ext_5cefc0(void *self, float *p, const float *d, float h, u32 n);
extern "C" FASTCALL void ext_4e0d80(float *v, float len);
extern "C" FASTCALL void ext_4e09b0(float *v);
extern "C" FASTCALL float ext_4e0870(const float *a, const float *b);
extern "C" FASTCALL long double ext_44c840(float *v);
extern "C" FASTCALL void ext_441940(float *v, const float *a);

static inline void copy3(float *d, const float *s) {
  d[0] = s[0];
  d[1] = s[1];
  d[2] = s[2];
}

// Horizontal aim direction: -(camera-helper facing) when scheme 1, else the aim direction; y forced to 0.
static inline void horiz_aim(void *self, float *d) {
  if (at<u32>(self, 0xa4c) == 1) {
    d[0] = at<float>(self, 0xcdd);
    d[1] = at<float>(self, 0xce1);
    d[2] = at<float>(self, 0xce5);
    ext_4e09b0(d);
  } else {
    d[0] = at<float>(self, 0xa72);
    d[2] = at<float>(self, 0xa7a);
  }
  d[1] = 0.0f;
}

// 0x5cfa00 ZCamHelper::GetRecruitPosPrecisionAim(float* out): the aim point, if it lies within
// (camera distance + 25000 - 100) of the camera eye; the point is then pulled to the ground by a shadow ray.
static THISCALL u32 ZCamHelper_GetRecruitPosPrecisionAim(void *self, float *out) {
  float lim = (float)vcall<long double>(ptr(self, 0xb54), 0xac) + G(float, 0x6b4fc4);  // + 25000
  float *dir = &at<float>(self, 0xa72);
  ext_4e0d80(dir, lim);
  ext_5ceed0(self, &at<float>(self, 0xa7e), &at<float>(self, 0xcad), dir, 0x10, 1, 0);
  float dist = ext_4e0870(&at<float>(self, 0xa7e), &at<float>(self, 0xcad));
  if (dist > lim - G(float, 0x67cd40)) return 0;  // minus 100
  float *p = &at<float>(self, 0xa8a);
  copy3(p, &at<float>(self, 0xa7e));
  ext_5cefc0(self, p, dir, 50.0f, 2);
  copy3(out, p);
  return 1;
}
PCREG(5cfa00, ZCamHelper_GetRecruitPosPrecisionAim);

// 0x5cfb10 ZCamHelper::GetRecruitScoutPosColi(float* out): where a recruit should scout. Two rays from above and
// below the focus, shadowed to the ground; the nearer (to the focus) is taken, unless the hero's tracked object
// (+0xecb, vslot 0x220) accepts the farther one first. If nothing qualifies a ray is cast from the focus-ish
// point toward the aim, pushed 0.1 down, and shadowed.
static THISCALL void ZCamHelper_GetRecruitScoutPosColi(void *self, float *out) {
  float dir[3];
  horiz_aim(self, dir);
  ext_4e0d80(dir, 6400.0f);
  float f34[3] = {at<float>(self, 0xc71), at<float>(self, 0xc75) + G(float, 0x67da2c), at<float>(self, 0xc79)};  // +200
  float e28[3], e1c[3];
  ext_5ceed0(self, e28, f34, dir, 0x10, 1, 0);
  ext_5cefc0(self, e28, dir, 250.0f, 2);
  f34[1] = at<float>(self, 0xc75) - G(float, 0x67da24);  // -30
  ext_5ceed0(self, e1c, f34, dir, 0x10, 1, 0);
  ext_5cefc0(self, e1c, dir, 250.0f, 2);
  float d1c = ext_4e0870(&at<float>(self, 0xc71), e1c);
  float d28 = ext_4e0870(&at<float>(self, 0xc71), e28);
  u8 *tracked = ptr(ptr(self, 0x44), 0xecb);
  bool ok28 = false, ok1c = false;
  if (!tracked) {
    ok1c = true;
  } else if (d28 > d1c) {
    ok28 = vcall<bool>(tracked, 0x220, e28);
    if (!ok28) ok1c = vcall<bool>(tracked, 0x220, e1c);
  } else {
    ok1c = vcall<bool>(tracked, 0x220, e1c);
    if (!ok1c) ok28 = vcall<bool>(tracked, 0x220, e28);
  }
  if (ok1c) {
    copy3(out, e1c);
    return;
  }
  if (ok28) {
    copy3(out, e28);
    return;
  }
  // Fallback: aim ray from f34 (y = focus + 200 - 30 = y - 30) along the normalized direction, 0.1 down.
  // The exe zeroes dir.y again here (0x5cfd0a, mov [ebp-0xc], 0) before vnorm (fix 2026-10-11, VM re-run thread).
  dir[1] = 0.0f;
  (void)ext_44c840(dir);
  float v[3] = {0.0f, -0.1f, 0.0f};
  ext_441940(dir, v);
  ext_4e0d80(dir, 6000.0f);
  ext_5ceed0(self, out, f34, dir, 0x10, 1, 0);
  ext_5cefc0(self, out, dir, 50.0f, 2);
}
PCREG(5cfb10, ZCamHelper_GetRecruitScoutPosColi);
