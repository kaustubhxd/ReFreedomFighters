// batch1613.cpp - unclaimed-16 batch 13 (docs/20-unclaimed-16.md): ZFFActor::GetCloseCombatStrength() (high). The exe
// returns the word at this+0x7a4 in AX only (mov ax, [ecx+0x7a4]); the upper half of EAX is whatever it held, so the
// spec compares AX only (opt-in 'ax' return mode, see pilot-ax-return.patch).
#include "ff.h"

// 0x59fcf0: returns the word at this+0x7a4.
static u32 THISCALL ffActorGetCloseCombatStrength(u8 *self) {
  return *(u16 *)(self + 0x7a4);
}
PCREG(59fcf0, ffActorGetCloseCombatStrength);
