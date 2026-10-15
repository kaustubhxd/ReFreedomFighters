// batch5703.cpp - unclaimed-57 (docs/20-unclaimed-57.md), batch 3: ZFFHERO::CreateMovementGuide() (0x590d40), thiscall, no
// arguments, ret. Allocates 0x5fd bytes; a null result returns 0; otherwise the movement-guide constructor 0x5e1040 runs on the block
// with (the hero, 5) and the block is returned. Operator new (0x41e290) is an unverified callee, hooked in the spec; the
// constructor 0x5e1040 runs as ORIGINAL code (it calls 0x5e0e10, verified in area 10 batch 6, and then sets fields).
#include "ff.h"

extern "C" u8 *ext_41e290(u32 size);                              // operator new, original code (hooked in the spec)
extern "C" u8 *THISCALL ext_5e1040(u8 *self, u8 *hero, u32 a2);  // ZFFHeroMovementGuide ctor, original code

// 0x590d40, ZFFHERO::CreateMovementGuide() (medium name)
static u8 *THISCALL heroCreateMovementGuide(u8 *self) {
  u8 *p = ext_41e290(0x5fd);
  if (!p) return 0;
  return ext_5e1040(p, self, 5);
}
PCREG(590d40, heroCreateMovementGuide);
