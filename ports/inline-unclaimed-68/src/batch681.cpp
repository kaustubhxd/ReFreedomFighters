// batch681.cpp - unclaimed-68 batch 1 (claim 1, residue 7). Names from the GC name map (naming only, never committed).
#include "ff.h"

// 0x4827b0, ZPlayer::ControlsEnabled() const (high): returns the byte at this+0x600 in AL.
static u8 THISCALL playerControlsEnabled(const u8 *self) {
  return self[0x600];
}
PCREG(4827b0, playerControlsEnabled);

// 0x4831b0, ZPlayer::DisableT1() (high): sets the byte at this+0x5fe to 1.
static void THISCALL playerDisableT1(u8 *self) {
  self[0x5fe] = 1;
}
PCREG(4831b0, playerDisableT1);

// 0x513170, ZMoveOnSpline::GetVerticalVisionOffset() (high): returns the float constant at 0x67cd40 in ST0.
static float THISCALL moveOnSplineVerticalVisionOffset(const u8 *self) {
  (void)self;
  return G(float, 0x67cd40);
}
PCREG(513170, moveOnSplineVerticalVisionOffset);
