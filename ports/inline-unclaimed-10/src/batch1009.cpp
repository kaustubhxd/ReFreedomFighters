// batch1009.cpp - unclaimed-10, batch 5 (docs/20-unclaimed-10.md): ZMovementBaseMove::Move, the move dispatch of the
// player's movement base. Thiscall with five stack arguments (ret 0x14). The two virtual slots it calls (+0x40, +0x48 of
// the object's vtable) are unverified callees: the spec stubs them with logging handlers (see the doc).
#include "ff.h"

typedef void(THISCALL *MoveSlot)(u8 *self, const void *a1, const void *a2, void *a3, void *a4, void *a5);

// 0x489490, ZMovementBaseMove::Move(const float*, const float*, float*, float*, float*) (high): clears the dword at
// this+0x21, calls virtual slot +0x40 with the five arguments in order, then calls virtual slot +0x48 the same way
// (the vtable is read again for the second call, as in the original).
static void THISCALL movementBaseMoveMove(u8 *self, const void *a1, const void *a2, void *a3, void *a4, void *a5) {
  *(u32 *)(self + 0x21) = 0;
  ((MoveSlot)((*(void ***)self)[0x40 / 4]))(self, a1, a2, a3, a4, a5);
  ((MoveSlot)((*(void ***)self)[0x48 / 4]))(self, a1, a2, a3, a4, a5);
}
PCREG(489490, movementBaseMoveMove);
