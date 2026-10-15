// batch1066.cpp - ZFFCam::AdjustForObstacles (0x5c97f0; the ZFFCam variant, not the ZFFCamera1 one in batch 1006).
// Camera thread, 2026-10-11.
#include "cam.h"

extern "C" THISCALL void ext_4e0d80(float *v, float len);            // vsetlen: scale v to length len
extern "C" FASTCALL void ext_43e8e0(float *d, const float *a, const float *b);  // d = a + b (vector add)

// 0x5c97f0 ZFFCam::AdjustForObstacles(void) (thiscall): the offset vector (+0x78, +0x7c, +0x80) is rescaled to the
// length (the per-index record's float at +0xd9, minus +0x2fa), stored as +0x2f6, then added to +0x30c into +0x444,
// and the object at +0x44 gets it through its slot 0x78. The original's three self-copies are no-ops and are not made.
static THISCALL void ZFFCam_AdjustForObstacles(u8 *self) {
  float v[3] = {at<float>(self, 0x78), at<float>(self, 0x7c), at<float>(self, 0x80)};
  u32 idx = at<u32>(self, 0x64) * 0x82u;
  float len = at<float>(self, idx + 0xd9) - at<float>(self, 0x2fa);
  at<float>(self, 0x2f6) = len;
  ext_4e0d80(v, len);
  float *dst = (float *)(self + 0x444);
  ext_43e8e0(dst, (const float *)(self + 0x30c), v);
  vcall<void>(at<u8 *>(self, 0x44), 0x78, (void *)dst);
}
PCREG(5c97f0, ZFFCam_AdjustForObstacles);
