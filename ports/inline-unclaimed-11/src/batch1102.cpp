// batch1102.cpp - unclaimed-11 batch 2 (docs/20-unclaimed-11.md). Every function is thiscall.
#include "ff.h"

// CCheckVisible::CanSee, original code (ported in inline-ai as batch 700): called with the object at this+0x13c
// and the value at this+0x140 as the first argument, then the caller's argument.
extern "C" bool THISCALL ext_4a9cb0(void *, s32, u32);

// 0x5122c0, ZMoveOnSpline::CanSee(unsigned int) (high): when the dword at this+0x140 is -1, the result is false (xor al);
// otherwise it returns CCheckVisible::CanSee(this+0x13c object, this+0x140, arg) through 0x4a9cb0.
static bool THISCALL moveOnSplineCanSee(u8 *self, u32 a1) {
  s32 target = *(s32 *)(self + 0x140);
  if (target == -1) return false;
  return ext_4a9cb0(*(void **)(self + 0x13c), target, a1);
}
PCREG(5122c0, moveOnSplineCanSee);

// 0x4884a0, ZMovementBase::GetActiveAnim(...) (GUESS, five stack arguments, ret 0x14): returns the float at this+0xc in ST0.
static float THISCALL movementBaseGetActiveAnim(u8 *self, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5) {
  return bitsf(*(u32 *)(self + 0xc));
}
PCREG(4884a0, movementBaseGetActiveAnim);

// 0x4edce0, ZCollisionBase::LoadUniqueSubStripInfo(char*, unsigned int) (medium): stores the pointer argument at
// this+0x190, the count argument shifted right by 3 at this+0x194, and byte 1 at this+0x19c.
static void THISCALL collisionBaseLoadUniqueSubStripInfo(u8 *self, u8 *a1, u32 a2) {
  *(u32 *)(self + 0x194) = a2 >> 3;
  *(u8 **)(self + 0x190) = a1;
  self[0x19c] = 1;
}
PCREG(4edce0, collisionBaseLoadUniqueSubStripInfo);
