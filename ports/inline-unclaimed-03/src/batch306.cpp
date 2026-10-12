// batch306.cpp - unclaimed-03 batch 6 (docs/20-unclaimed-03.md): ZCollisionBase::LoadUniqueSubStripInfo(char*, unsigned int)
// at 0x4edce0. Name from the GC name map (medium, GUESS); body from the PC bytes. No calls.
#include "ff.h"

// 0x4edce0, ZCollisionBase::LoadUniqueSubStripInfo(char*, unsigned int) (medium): stores the second argument shifted right
// by 3 at this+0x194, stores the first argument at this+0x190, and sets the byte at this+0x19c to 1. Callee pops 8.
static void THISCALL collisionLoadUniqueSubStripInfo(u8 *self, u32 a1, u32 a2) {
  *(u32 *)(self + 0x194) = a2 >> 3;
  *(u32 *)(self + 0x190) = a1;
  self[0x19c] = 1;
}
PCREG(4edce0, collisionLoadUniqueSubStripInfo);
