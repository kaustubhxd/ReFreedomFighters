#include "ff.h"
// batch7913.cpp - unclaimed-79 batch 13 (docs/20-unclaimed-79.md, gap band). Name from the GC name map (high).

// 0x484eb0, ZPlayer::SetActiveMovement(unsigned int) (high). Calls the virtual slot +0x640 with the argument and stores the
// result (eax) at this+0x455. Callee pops 4 bytes.
static void THISCALL playerSetActiveMovement(u8 *self, u32 m) {
  *(u32 *)(self + 0x455) = vcall<u32, u32>(self, 0x640, m);
}
PCREG(484eb0, playerSetActiveMovement);
