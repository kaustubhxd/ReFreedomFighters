// batch1060.cpp - CCameraBox::Load2 (0x4cb110, low confidence in the class map: the body is shared with another GC
// function by identical-code folding). Camera thread, 2026-10-11.
#include "cam.h"

// 0x4cb110 (thiscall, no args): virtual slot 0x64 with the argument 0x10.
static THISCALL void CCameraBox_Load2(u8 *self) {
  vcall<void>(self, 0x64, (u32)0x10);
}
PCREG(4cb110, CCameraBox_Load2);
