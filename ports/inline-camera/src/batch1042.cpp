// batch1042.cpp - ZCAMERA::Draw. Camera thread, 2026-10-11.
#include "cam.h"

// 0x445ca0 ZCAMERA::Draw(void *a1, u32 a2, u32 a3, u32 a4): only when the camera is active (flags+0x14 bit 0).
// The half field of view gives tan(fov / 2) * 200 for vec[0], vec[0] / aspect for vec[1] and 200 for vec[2].
// a1 gets vec through virtual slot 0xc0 (a3, a4, vec), then a draw through slot 0xbc (a3, a4, a2, flag bit 3).
static THISCALL void ZCAMERA_Draw(u8 *self, u8 *a1, u32 a2, u32 a3, u32 a4) {
  if (!(at<u8>(self, 0x14) & 1)) return;
  float t = (float)crt::tan((double)(at<float>(self, 0x5c) * 0.5f));
  float vec[3];
  vec[0] = t * 200.0f;
  vec[1] = vec[0] / at<float>(self, 0x40);
  vec[2] = 200.0f;
  vcall<void>(a1, 0xc0, a3, a4, vec);
  vcall<void>(a1, 0xbc, a3, a4, a2, (u32)((at<u8>(self, 0x14) >> 3) & 1));
}
PCREG(445ca0, ZCAMERA_Draw);
