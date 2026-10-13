// batch1057.cpp - CCameraBox::End (0x5c7d90, high confidence in the class map) and CCameraBox::FrameUpdate
// (0x5c7da0, low confidence). Camera thread, 2026-10-11.
#include "cam.h"

#define CDECL __attribute__((cdecl))

extern "C" CDECL void ext_634273(void *p, u32 size);   // sized delete (the CRT free the original calls)

// 0x5c7d90 CCameraBox::End(void) (thiscall, no args): frees the 8-byte block at +0x4c.
static THISCALL void CCameraBox_End(u8 *self) {
  ext_634273(at<void *>(self, 0x4c), 8);
}
PCREG(5c7d90, CCameraBox_End);

// 0x5c7da0 CCameraBox::FrameUpdate(void) (thiscall, no args): virtual slot 0x68 with (0x10, 0).
static THISCALL void CCameraBox_FrameUpdate(u8 *self) {
  vcall<void>(self, 0x68, (u32)0x10, (u32)0);
}
PCREG(5c7da0, CCameraBox_FrameUpdate);
