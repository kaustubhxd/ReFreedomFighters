// batch1610.cpp - unclaimed-16 batch 10 (docs/20-unclaimed-16.md): 0x4a0940. The GC name map says CAction::Initialize
// with eight arguments, but the body takes one argument (ret 4) and tail-jumps to 0x4a20e0 (UpdateObjectsInRange in the
// map). So the name is a GUESS: CAction::Update. Body: if the byte at this+0x64 is zero, tail-jump to 0x4a20e0(this, arg).
// Otherwise, if bit 10 of the dword at (dword at (dword this+0x44) + 8) + 0x3c is set, return; else tail-jump.
#include "ff.h"

extern "C" void THISCALL ext_4a20e0(u8 *self, u32 a1); // original code (stubbed in the spec, not verified)

static void THISCALL actionUpdateGuess(u8 *self, u32 a1) {
  if (self[0x64] != 0) {
    u8 *p = *(u8 **)(self + 0x44);
    u8 *q = *(u8 **)(p + 8);
    u32 x = *(u32 *)(q + 0x3c);
    if ((x >> 10) & 1)
      return;
  }
  ext_4a20e0(self, a1);
}
PCREG(4a0940, actionUpdateGuess);
