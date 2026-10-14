// batch1077.cpp - ZCameraViewEntry::Update(ZViewBase *src) (0x64de00, medium confidence in the class map). Camera/view
// thread, 2026-10-12.
#include "cam.h"

// Copies a 36-byte matrix (the same bytes as the exe's 0x4de420: nine dwords).
static inline void copy36(u8 *dst, const u8 *src) {
  for (int k = 0; k < 9; k++) at<u32>(dst, 4 * k) = at<u32>(src, 4 * k);
}

// 0x64de00 (thiscall, one stack arg): the view's matrix at src+0x18229 goes to +0x10, the dwords at src+0x1824d, +0x18251,
// +0x18255 to +0x34, +0x38, +0x3c; the matrix at src+0x181f9 goes to +0x40; the dwords at src+0x1821d, +0x18221, +0x18225
// go to +0x64, +0x68, +0x6c.
static THISCALL void ZCameraViewEntry_Update(u8 *self, u8 *src) {
  copy36(self + 0x10, src + 0x18229);
  at<u32>(self, 0x34) = at<u32>(src, 0x1824d);
  at<u32>(self, 0x38) = at<u32>(src, 0x18251);
  at<u32>(self, 0x3c) = at<u32>(src, 0x18255);
  copy36(self + 0x40, src + 0x181f9);
  at<u32>(self, 0x64) = at<u32>(src, 0x1821d);
  at<u32>(self, 0x68) = at<u32>(src, 0x18221);
  at<u32>(self, 0x6c) = at<u32>(src, 0x18225);
}
PCREG(64de00, ZCameraViewEntry_Update);
