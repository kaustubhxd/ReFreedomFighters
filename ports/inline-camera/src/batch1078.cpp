// batch1078.cpp - the view-entry fill 0x60f040 (name from the call in ZCameraViewEntryGC::Update, 0x6160e0). Camera/view
// thread, 2026-10-12.
#include "cam.h"

// 0x60f040 (ecx = out, edx = a, one stack arg b; ret 4): out gets a's words 0x18, 0x1c, 0x20 (+0, +4, +8), zero, a's
// 0xc, 0x10, 0x14 (+0x10, +0x14, +0x18), zero, a's 0, 4, 8 (+0x20, +0x24, +0x28), zero, b's three words (+0x30, +0x34, +0x38)
// and 1.0 (+0x3c).
static FASTCALL void ZViewFill_60f040(u8 *out, const u8 *a, const u8 *b) {
  at<u32>(out, 0x00) = at<u32>(a, 0x18);
  at<u32>(out, 0x04) = at<u32>(a, 0x1c);
  at<u32>(out, 0x08) = at<u32>(a, 0x20);
  at<u32>(out, 0x0c) = 0;
  at<u32>(out, 0x10) = at<u32>(a, 0x0c);
  at<u32>(out, 0x14) = at<u32>(a, 0x10);
  at<u32>(out, 0x18) = at<u32>(a, 0x14);
  at<u32>(out, 0x1c) = 0;
  at<u32>(out, 0x20) = at<u32>(a, 0x00);
  at<u32>(out, 0x24) = at<u32>(a, 0x04);
  at<u32>(out, 0x28) = at<u32>(a, 0x08);
  at<u32>(out, 0x2c) = 0;
  at<u32>(out, 0x30) = at<u32>(b, 0x00);
  at<u32>(out, 0x34) = at<u32>(b, 0x04);
  at<u32>(out, 0x38) = at<u32>(b, 0x08);
  at<u32>(out, 0x3c) = 0x3f800000u;   // 1.0f
}
PCREG(60f040, ZViewFill_60f040);
