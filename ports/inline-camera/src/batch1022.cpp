// batch1022.cpp - ZCamHelper input actions (called from ZActionControlMap::FireGameActions with an axis value
// 0..127). Camera thread, 2026-10-11.
#include "cam.h"

// Axis fields: +0xb27 move forward/back (fresh flag +0xb30), +0xb2b move sideways (+0xb2f), +0xb1f look x
// (+0xb33), +0xb23 look y (+0xb34). Values are v/127 with the sign of the direction. +0xa70 / +0xa71 record that
// the look axis was already pushed the same way (MovePointerOni then cuts the turn speed on that axis).
#define K127 G(float, 0x67af20)    // 127
#define KM127 G(float, 0x67af30)   // -127
#define EPS G(float, 0x679540)     // 1/8192

// 0x5d0ba0 ZCamHelper::MoveBackward(int): the first move input of the frame wins.
static THISCALL void ZCamHelper_MoveBackward(void *self, s32 v) {
  if (at<u8>(self, 0xb30)) return;
  at<u8>(self, 0xb30) = 1;
  at<float>(self, 0xb27) = (float)v / KM127;
}
PCREG(5d0ba0, ZCamHelper_MoveBackward);

// 0x5d0c30 ZCamHelper::MoveForward(int)
static THISCALL void ZCamHelper_MoveForward(void *self, s32 v) {
  if (at<u8>(self, 0xb30)) return;
  at<u8>(self, 0xb30) = 1;
  at<float>(self, 0xb27) = (float)v / K127;
}
PCREG(5d0c30, ZCamHelper_MoveForward);

// 0x5d0c60 ZCamHelper::MoveLeft(int)
static THISCALL void ZCamHelper_MoveLeft(void *self, s32 v) {
  at<u8>(self, 0xb2f) = 1;
  at<float>(self, 0xb2b) = (float)v / KM127;
}
PCREG(5d0c60, ZCamHelper_MoveLeft);

// 0x5d1190 (unnamed) ZCamHelper::MoveRight(int) (GC has MoveLeft only in the map; inferred by symmetry)
static THISCALL void ZCamHelper_MoveRight(void *self, s32 v) {
  at<u8>(self, 0xb2f) = 1;
  at<float>(self, 0xb2b) = (float)v / K127;
}
PCREG(5d1190, ZCamHelper_MoveRight);

// 0x5d1300 (unnamed) look y negative (inferred LookUp): b23 = -(v/127); +0xa71 = old b23 >= eps.
static THISCALL void ZCamHelper_LookYNeg(void *self, s32 v) {
  if (!v) return;
  at<u8>(self, 0xa71) = at<float>(self, 0xb23) >= EPS;
  at<u8>(self, 0xb34) = 1;
  at<float>(self, 0xb23) = -((float)v / K127);
}
PCREG(5d1300, ZCamHelper_LookYNeg);

// 0x5d1350 (unnamed) look x negative: b1f = v/-127; +0xa70 = old b1f >= eps.
static THISCALL void ZCamHelper_LookXNeg(void *self, s32 v) {
  if (!v) return;
  at<u8>(self, 0xa70) = at<float>(self, 0xb1f) >= EPS;
  at<u8>(self, 0xb33) = 1;
  at<float>(self, 0xb1f) = (float)v / KM127;
}
PCREG(5d1350, ZCamHelper_LookXNeg);

// 0x5d13a0 (unnamed) look x positive: b1f = v/127; +0xa70 = eps >= old b1f.
static THISCALL void ZCamHelper_LookXPos(void *self, s32 v) {
  if (!v) return;
  at<u8>(self, 0xa70) = EPS >= at<float>(self, 0xb1f);
  at<u8>(self, 0xb33) = 1;
  at<float>(self, 0xb1f) = (float)v / K127;
}
PCREG(5d13a0, ZCamHelper_LookXPos);

// 0x5d13f0 (unnamed) look y positive: b23 = v/127; +0xa71 = eps >= old b23.
static THISCALL void ZCamHelper_LookYPos(void *self, s32 v) {
  if (!v) return;
  at<u8>(self, 0xa71) = EPS >= at<float>(self, 0xb23);
  at<u8>(self, 0xb34) = 1;
  at<float>(self, 0xb23) = (float)v / K127;
}
PCREG(5d13f0, ZCamHelper_LookYPos);
