#include "ff.h"
// batch905.cpp - unclaimed-01 claim 4 (docs/20-unclaimed-01.md). Names from the GC name map (naming only).

// 0x489340, ZMovementGuide::GotControl() (medium, GUESS name): sets bit 0x400000 in the dword at +0x417 of the object
// pointed to by this+4. void, ret 0.
static void THISCALL movementGuideGotControl(u8 *self) {
  u8 *obj = *(u8 **)(self + 4);
  *(u32 *)(obj + 0x417) |= 0x400000u;
}
PCREG(489340, movementGuideGotControl);

// 0x5aaae0, ZFFPRIVATESTDOBJ::OverrideViewMatrix() (medium, GUESS name): returns 1 when the dword at this+0x18 is
// nonzero, else 0. The result is in al.
static u8 THISCALL ffPrivateStdObjOverrideViewMatrix(u8 *self) {
  return *(u32 *)(self + 0x18) != 0 ? 1 : 0;
}
PCREG(5aaae0, ffPrivateStdObjOverrideViewMatrix);

// 0x5e7180, ZFFHeroMovementBaseMove::TerminateControl(bool) (high): clears the byte at this+0x54b, returns true (al = 1).
// The argument is not read.
static u8 THISCALL heroMovementBaseMoveTerminateControl(u8 *self, u32 a1) {
  (void)a1;
  self[0x54b] = 0;
  return 1;
}
PCREG(5e7180, heroMovementBaseMoveTerminateControl);

// 0x489d60, ZMovementGuide::TerminateControl(bool) (medium, GUESS name): clears the dword at this+0x371, clears bit
// 0x400000 in the dword at +0x417 of the object pointed to by this+4, returns true (al = 1). The argument is not read.
static u8 THISCALL movementGuideTerminateControl(u8 *self, u32 a1) {
  (void)a1;
  u8 *obj = *(u8 **)(self + 4);
  *(u32 *)(self + 0x371) = 0;
  *(u32 *)(obj + 0x417) &= 0xffbfffffu;
  return 1;
}
PCREG(489d60, movementGuideTerminateControl);
