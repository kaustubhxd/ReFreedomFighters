// batch1913.cpp - unclaimed-66 batch 13: GUESS FUN_0057bd90, a class constructor: calls the base constructor 0x561020
// (the base constructor 0x561020 is an accepted GUESS stub in the spec; its body is a separate job).
#include "ff.h"

void THISCALL baseCtor561020(u8 *self);   // batch 1918: the real base constructor (no longer a stub)

// 0x57bd90, GUESS FUN_0057bd90.
static u8 *THISCALL classCtorOver561020(u8 *self) {
  baseCtor561020(self);
  *(u32 *)self = 0x6aa4f4;
  return self;
}
PCREG(57bd90, classCtorOver561020);
