// batch6301.cpp - unclaimed-63 batch 1 (docs/20-unclaimed-63.md): three leaves at 0x484ce0, 0x4ce520 and 0x4545e0. Names from
// the GC name map (naming only); bodies from the PC bytes. No calls, no stubs.
#include "ff.h"

// 0x484ce0, ZPlayer::RegisterMovement(ZMovementBase*) (high): idx = [a+0x10]; stores a at this+0x45d + 4*idx; if [this+0x459]
// is below idx, sets [this+0x459] = idx (unsigned). Callee pops 4.
static void THISCALL playerRegisterMovement(u8 *self, u8 *a) {
  u32 idx = *(u32 *)(a + 0x10);
  *(u32 *)(self + 0x45d + idx * 4) = (u32)a;
  if (*(u32 *)(self + 0x459) < idx)
    *(u32 *)(self + 0x459) = idx;
}
PCREG(484ce0, playerRegisterMovement);

// 0x4ce520, LINKREFTAB::GetPrevRefPtr(unsigned int*) (high): n = [this+0x18]; v = arr[n-2] (the dword at arr + 4n - 8).
// If v is zero, returns 0; otherwise returns v + 4*(2 - n) (unsigned). Callee pops 4.
static u32 THISCALL linkRefTabGetPrevRefPtr(u8 *self, u32 *arr) {
  u32 n = *(u32 *)(self + 0x18);
  u32 v = *(u32 *)((u8 *)arr + n * 4 - 8);
  if (v == 0)
    return 0;
  return v + (2 - n) * 4;
}
PCREG(4ce520, linkRefTabGetPrevRefPtr);

// 0x4545e0, ZItemTemplate::SetItemHands(ITEMHANDS) (low, GUESS): stores the argument at this+0x5c. Callee pops 4.
static void THISCALL itemTemplateSetItemHands(u8 *self, u32 hands) {
  *(u32 *)(self + 0x5c) = hands;
}
PCREG(4545e0, itemTemplateSetItemHands);
