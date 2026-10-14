// batch1043.cpp - ZCAMERA::Init. Camera thread, 2026-10-11.
#include "cam.h"

// 0x445ff0 ZCAMERA::Init(void *a1): the two integers from a1's slots 0xd8 and 0xdc are stored as floats at +0x50
// and +0x54 (cvtdq2ps: signed int to float).
static THISCALL void ZCAMERA_Init(u8 *self, u8 *a1) {
  at<float>(self, 0x50) = (float)vcall<s32>(a1, 0xd8);
  at<float>(self, 0x54) = (float)vcall<s32>(a1, 0xdc);
}
PCREG(445ff0, ZCAMERA_Init);
