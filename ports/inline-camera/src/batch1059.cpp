// batch1059.cpp - CCameraBox::CopyData(ZEventBase *src) (0x582730, low confidence in the class map). Camera thread,
// 2026-10-11.
#include "cam.h"

// 0x582730 (thiscall, one stack arg): the word at +0x48 is copied from the source.
static THISCALL void CCameraBox_CopyData(u8 *self, u8 *src) {
  at<u32>(self, 0x48) = at<u32>(src, 0x48);
}
PCREG(582730, CCameraBox_CopyData);
