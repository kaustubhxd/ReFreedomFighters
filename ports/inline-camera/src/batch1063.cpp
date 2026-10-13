// batch1063.cpp - ZCAMERA accessor at 0x445e80 (named ZCAMERA::ForceLightUpdate in the class map; the body is a
// getter). Camera thread, 2026-10-11.
#include "cam.h"

// 0x445e80 (thiscall, no args): the byte at +0x170, returned in al.
static THISCALL u8 ZCAMERA_GetByte170(u8 *self) {
  return at<u8>(self, 0x170);
}
PCREG(445e80, ZCAMERA_GetByte170);
