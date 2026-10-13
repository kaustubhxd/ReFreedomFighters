// batch1065.cpp - ZCAMERA::SetViewport(const float *v) (0x446e60, medium confidence in the class map). Camera thread,
// 2026-10-11.
#include "cam.h"

// 0x446e60 (thiscall, one stack arg): the viewport (x, y, width, height) goes to +0x171, +0x175, +0x179 (dwords) and
// +0x17d (float); the aspect at +0x181 is height / width (float division of the stored values).
static THISCALL void ZCAMERA_SetViewport(u8 *self, const u32 *v) {
  at<u32>(self, 0x171) = v[0];
  at<u32>(self, 0x175) = v[1];
  at<u32>(self, 0x179) = v[2];
  at<u32>(self, 0x17d) = v[3];
  at<float>(self, 0x181) = at<float>(self, 0x17d) / at<float>(self, 0x179);
}
PCREG(446e60, ZCAMERA_SetViewport);
