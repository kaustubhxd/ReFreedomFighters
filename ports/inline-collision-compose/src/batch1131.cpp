// batch1131.cpp - collision thread, batch 1131: ZCollisionBase::LoadUniqueSubStripInfo (0x4edce0).
#include "ff.h"

// 0x4edce0 ZCollisionBase::LoadUniqueSubStripInfo(char *data, unsigned size) [medium], thiscall, ret 8.
// Stores the data pointer at +0x190, size >> 3 at +0x194, and sets the byte at +0x19c to 1.
static void THISCALL loadUniqueSubStripInfo(u8 *self, u8 *data, u32 size) {
  *(u32 *)(self + 0x194) = size >> 3;
  *(u8 **)(self + 0x190) = data;
  self[0x19c] = 1;
}
PCREG(4edce0, loadUniqueSubStripInfo);
