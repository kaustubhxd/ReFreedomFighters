// batch1129.cpp - collision thread, batch 1129: ZCollisionBase::UnlockCollisionBox (0x4ede70).
#include "ff.h"

// 0x4ede70 ZCollisionBase::UnlockCollisionBox(ZCollisionBox *box) [medium], thiscall, ret 4. It forwards to 0x4eb340
// with ECX = this+4, which clears the byte at (this+4)+0xa5 = this+0xa9 (the byte IsCollisionBoxLocked reads in batch
// 1127). The box argument is popped by the ret 4 and not used.
static void THISCALL unlockCollisionBox(u8 *self, u8 *box) {
  (void)box;
  self[0xa9] = 0;
}
PCREG(4ede70, unlockCollisionBox);
