// batch1046.cpp - ZCAMERA::CopyData(const ZCAMERA *src). Camera thread, 2026-10-11.
#include "cam.h"

// The tail jump of the original goes to the base class copy at 0x45d5b0 with the same arguments.
extern "C" THISCALL void ext_45d5b0(void *self, void *src);

// 0x445750 ZCAMERA::CopyData(u8 *src) (thiscall, one stack arg): copies the render settings from src to self
// (the viewport +0x171..0x181, FOV +0x5c, near/far +0x60/+0x64, +0x68, +0x6c, the positions +0x30/+0x34/+0x38,
// +0x1c, +0x48/+0x4c, +0x70/+0x74, and the byte at +0x170), then runs the base copy.
static THISCALL void ZCAMERA_CopyData(u8 *self, u8 *src) {
  at<u32>(self, 0x171) = at<u32>(src, 0x171);
  at<u32>(self, 0x175) = at<u32>(src, 0x175);
  at<u32>(self, 0x179) = at<u32>(src, 0x179);
  at<u32>(self, 0x17d) = at<u32>(src, 0x17d);
  at<u32>(self, 0x181) = at<u32>(src, 0x181);
  at<u32>(self, 0x5c) = at<u32>(src, 0x5c);
  at<u32>(self, 0x60) = at<u32>(src, 0x60);
  at<u32>(self, 0x6c) = at<u32>(src, 0x6c);
  at<u32>(self, 0x30) = at<u32>(src, 0x30);
  at<u32>(self, 0x34) = at<u32>(src, 0x34);
  at<u32>(self, 0x38) = at<u32>(src, 0x38);
  at<u32>(self, 0x1c) = at<u32>(src, 0x1c);
  at<u32>(self, 0x4c) = at<u32>(src, 0x4c);
  at<u32>(self, 0x48) = at<u32>(src, 0x48);
  at<u32>(self, 0x64) = at<u32>(src, 0x64);
  at<u32>(self, 0x68) = at<u32>(src, 0x68);
  at<u32>(self, 0x70) = at<u32>(src, 0x70);
  at<u32>(self, 0x74) = at<u32>(src, 0x74);
  at<u8>(self, 0x170) = at<u8>(src, 0x170);
  ext_45d5b0(self, src);
}
PCREG(445750, ZCAMERA_CopyData);
