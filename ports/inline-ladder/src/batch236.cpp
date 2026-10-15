// batch236.cpp - ZLNKWHANDS::GetPickupAction (inline-ladder thread, 2026-10-11).
#include "ff.h"

// 0x4744c0 ZLNKWHANDS::GetPickupAction(HANDPICKUP&, HANDPICKUP&, HANDSPICKUP&, ITEMHANDS, ITEMHANDS, ITEMHANDS, bool) const
// [GameCube reference, high; ZActor slot 287], thiscall, ret 0x1c, returns 0 (EAX). The one body: call the assert hook at
// 0x7003b0 when set, else int3. Same shape as the other assert stubs of this class (weapons batches).
static u32 THISCALL handsGetPickupAction(void *, void *, void *, void *, u32, u32, u32, u32) {
  typedef void (*hook_t)();
  hook_t h = G(hook_t, 0x7003b0);
  if (h)
    h();
  else
    __asm__ volatile("int3");
  return 0;
}
PCREG(4744c0, handsGetPickupAction);
