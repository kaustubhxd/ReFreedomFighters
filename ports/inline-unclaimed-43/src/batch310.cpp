// batch310.cpp - ZPlayer::CreateMovementGuide() (area 43, 2026-10-12). 0x4829e0, thiscall (this = ECX), no arguments, ret 0.
// GameCube reference (name map, medium). Body: p = new(0x3bf) (exe __builtin_new, cdecl); if p != 0: ZMovementGuide(p, this, 5)
// (exe ctor 0x4877a0, thiscall with two stack arguments). The exe also installs and removes an SEH frame on fs:[0]
// around this; the net effect on the TEB word is nothing, and the port does not reproduce the frame (no exception path).
#include "ff.h"

extern "C" void *ext_41e290(unsigned long size);                  // __builtin_new (cdecl, 1 stack argument)
extern "C" void THISCALL ext_4877a0(void *obj, u8 *player, unsigned long n);   // ZMovementGuide ctor (ret 8)

static void THISCALL playerCreateMovementGuide(u8 *self) {
  void *p = ext_41e290(0x3bf);
  if (p != 0)
    ext_4877a0(p, self, 5);
}
PCREG(4829e0, playerCreateMovementGuide);
