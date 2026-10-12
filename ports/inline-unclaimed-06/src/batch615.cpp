// batch615.cpp - unclaimed-06 claims 16 to 18 (docs/20-unclaimed-06.md): three pure leaves (no callees). Thiscall.
// Names: 0x4837d0 from the GC name map (high); 0x4364d0 and 0x560310 are GUESS (no name in the map).
#include "ff.h"

// 0x4837d0, ZPlayer::GetActiveMovementType() const (high): loads the pointer at this+0x455, returns the dword at its +0x10.
static u32 THISCALL playerGetActiveMovementType(u8 *self) {
  u8 *p = *(u8 **)(self + 0x455);
  return *(u32 *)(p + 0x10);
}
PCREG(4837d0, playerGetActiveMovementType);

// 0x4364d0, GUESS FUN_4364d0 (thiscall, no arguments): stores 0 at this+4, returns this, stores 0 byte at this+8.
static u8 *THISCALL guessInit4364d0(u8 *self) {
  *(u32 *)(self + 4) = 0;
  u8 *r = self;
  self[8] = 0;
  return r;
}
PCREG(4364d0, guessInit4364d0);

// 0x560310, GUESS FUN_560310 (thiscall with no arguments used): stores 0 to the global at 0x71419c. ret plain.
static void THISCALL guessZeroGlobal560310(u8 *self) {
  (void)self;
  G(u32, 0x71419c) = 0;
}
PCREG(560310, guessZeroGlobal560310);
