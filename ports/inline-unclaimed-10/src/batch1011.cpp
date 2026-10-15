// batch1011.cpp - unclaimed-10, batch 7 (docs/20-unclaimed-10.md): ZFFHERO::CreateMovementBaseMove() (0x590cd0), thiscall,
// no arguments (ret). Allocates 0x54c bytes; a null result returns 0; otherwise it runs the hero movement-base constructor
// (0x5e0e10) on the block with (the hero, 3) and returns the block.
// Unverified callees run as ORIGINAL code through ext_ bindings: operator new 0x41e290 (cdecl, one argument; hooked in the
// spec) and the constructor 0x5e0e10 (verified in batch 6, but called here as the original code).
#include "ff.h"

extern "C" u8 *ext_41e290(u32 size);                              // operator new, original code (hooked in the spec)
extern "C" u8 *THISCALL ext_5e0e10(u8 *self, u8 *hero, u32 a2);  // movement-base ctor, original code

// 0x590cd0, ZFFHERO::CreateMovementBaseMove() (medium, GUESS on the name)
static u8 *THISCALL heroCreateMovementBaseMove(u8 *self) {
  u8 *p = ext_41e290(0x54c);
  if (!p) return 0;
  ext_5e0e10(p, self, 3);
  return p;
}
PCREG(590cd0, heroCreateMovementBaseMove);
