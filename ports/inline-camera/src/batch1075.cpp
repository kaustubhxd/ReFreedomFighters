// batch1075.cpp - ZCameraOverlay::CopyData(const ZGEOM *src) (0x458300, high confidence in the class map). Camera/view
// thread, 2026-10-12.
#include "cam.h"

// 0x458300 (thiscall, one stack arg): when the source's slot 0x1e0 (argument 0x2000fa) says so, the overlay copies its
// settings (byte +0xbc; dwords +0xa0, +0xa4, +0xa8, +0xb8, +0xbd, +0x88, +0x8c, +0x90, +0x94, +0x98, +0x9c, +0x80).
static THISCALL void ZCameraOverlay_CopyData(u8 *self, u8 *src) {
  if (!(vcall<u32>(src, 0x1e0, (u32)0x2000fa) & 0xff)) return;
  at<u8>(self, 0xbc) = at<u8>(src, 0xbc);
  at<u32>(self, 0xa0) = at<u32>(src, 0xa0);
  at<u32>(self, 0xa4) = at<u32>(src, 0xa4);
  at<u32>(self, 0xa8) = at<u32>(src, 0xa8);
  at<u32>(self, 0xb8) = at<u32>(src, 0xb8);
  at<u32>(self, 0xbd) = at<u32>(src, 0xbd);
  at<u32>(self, 0x88) = at<u32>(src, 0x88);
  at<u32>(self, 0x8c) = at<u32>(src, 0x8c);
  at<u32>(self, 0x90) = at<u32>(src, 0x90);
  at<u32>(self, 0x94) = at<u32>(src, 0x94);
  at<u32>(self, 0x98) = at<u32>(src, 0x98);
  at<u32>(self, 0x9c) = at<u32>(src, 0x9c);
  at<u32>(self, 0x80) = at<u32>(src, 0x80);
}
PCREG(458300, ZCameraOverlay_CopyData);
