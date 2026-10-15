// batch1055.cpp - ZShakeCamera::ZShakeCamera (0x5d3360). Camera thread, 2026-10-11.
#include "cam.h"

extern "C" THISCALL void ext_469870(void *self);   // base constructor

// 0x5d3360 ZShakeCamera::ZShakeCamera(void) (thiscall): base constructor, flags |= 0x20, vtable 0x6b501c, two
// manager lookups through slot 0x114 (the first with 0x6b4ce4, the second with 0x682e18; both take 0x6b50a0 and
// 0x20 / 0x22): word results at +0x48 and +0x52, the float 0.5 at +0x4a, and the byte at +0x54 cleared.
static THISCALL u8 *ZShakeCamera_Ctor(u8 *self) {
  ext_469870(self);
  at<u32>(self, 4) |= 0x20;
  at<u32>(self, 0x44) = 0;
  at<u32>(self, 0) = 0x6b501c;
  at<u16>(self, 0x48) = (u16)vcall<u32>(SYS9B, 0x114, (u32)0x6b4ce4, (u32)0, (u32)0x6b50a0, (u32)0x20);
  at<u32>(self, 0x4a) = 0x3f000000u;
  at<u16>(self, 0x52) = (u16)vcall<u32>(SYS9B, 0x114, (u32)0x682e18, (u32)0, (u32)0x6b50a0, (u32)0x22);
  at<u8>(self, 0x54) = 0;
  return self;
}
PCREG(5d3360, ZShakeCamera_Ctor);
