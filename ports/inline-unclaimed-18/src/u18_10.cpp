// u18_10.cpp - area 18, group 10 (unclaimed-18 thread).
#include "ff.h"

// 0x4fa0d0, ZScrollbar::GetPosition() const (GC map high). thiscall; returns the float +0xa7 divided by the integer at
// +0xab (converted to float), in ST0. The division is single precision (SSE), then the value goes to ST0.
static float THISCALL scrollbarGetPosition(u8 *self) {
  float d = (float)*(s32 *)(self + 0xab);
  float v = *(float *)(self + 0xa7);
  return v / d;
}
PCREG(4fa0d0, scrollbarGetPosition);

// 0x5144d0, ZMoveOnSpline::StartRollingSound() (GC map high). thiscall; while the cached handle at +0x1d9 is zero, it is set
// to the result of slot 0x2e8 with the argument at +0x1d5; returns the handle.
static u32 THISCALL moveOnSplineStartRollingSound(u8 *self) {
  if (*(u32 *)(self + 0x1d9) == 0)
    *(u32 *)(self + 0x1d9) = vcall<u32>(self, 0x2e8, *(u32 *)(self + 0x1d5));
  return *(u32 *)(self + 0x1d9);
}
PCREG(5144d0, moveOnSplineStartRollingSound);
