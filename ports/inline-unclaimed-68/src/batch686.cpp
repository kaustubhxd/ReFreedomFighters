// batch686.cpp - unclaimed-68 batch 6 (claim 5). Names from the GC name map, GUESS where marked (naming only, never committed).
#include "ff.h"

// 0x5efdf0 (GUESS FUN_5efdf0): sets the dword at this+0x94 to 1.
static void THISCALL guessFun5efdf0(u8 *self) {
  *(u32 *)(self + 0x94) = 1;
}
PCREG(5efdf0, guessFun5efdf0);

// 0x5ed9b0 (GUESS FUN_5ed9b0): returns the dword at this+0xe3 in EAX.
static u32 THISCALL guessFun5ed9b0(const u8 *self) {
  return *(const u32 *)(self + 0xe3);
}
PCREG(5ed9b0, guessFun5ed9b0);

// 0x597fb0, ZGameOSD::HideHintMessage() (high): ecx = this+0x1d0f, then ecx = that object's +0x634, then the flag at +0x94
// of that object is set to 1 (the original reaches the last step through the tail jumps 0x5a8500 and 0x5efdf0).
static void THISCALL gameOsdHideHintMessage(u8 *self) {
  u8 *hint = *(u8 **)(self + 0x1d0f);
  u8 *target = *(u8 **)(hint + 0x634);
  *(u32 *)(target + 0x94) = 1;
}
PCREG(597fb0, gameOsdHideHintMessage);
