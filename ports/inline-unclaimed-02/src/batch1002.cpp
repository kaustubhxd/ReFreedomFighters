#include "ff.h"
// batch1002.cpp - unclaimed-02 batch 2 (docs/20-unclaimed-02.md). Names from the GC name map (naming only).

// 0x5e71c0, ZFFHeroMovementCloseCombat::TerminateControl(bool) (high). Calls the virtual slot +0x220 of the object
// at this+0x36d with the constant 0 (the argument is not read), then clears bit 0x10000000 in the dword at +0x417 of
// the object at this+0x36d (re-read after the call), clears the byte at this+0x5ac and returns true (al = 1).
static u8 THISCALL heroMovementCloseCombatTerminateControl(u8 *self, u8 a1) {
  (void)a1;
  vcall<void, u32>(*(u8 **)(self + 0x36d), 0x220, 0u);
  *(u32 *)(*(u8 **)(self + 0x36d) + 0x417) &= 0xefffffffu;
  self[0x5ac] = 0;
  return 1;
}
PCREG(5e71c0, heroMovementCloseCombatTerminateControl);

// 0x5e7210, ZFFHeroMovementGuide::TerminateControl(bool) (medium, GUESS name): clears the dword at this+0x550, clears
// bit 0x400000 in the dword at +0x417 of the object pointed to by this+4, returns true (al = 1). The argument is not read.
static u8 THISCALL heroMovementGuideTerminateControl(u8 *self, u8 a1) {
  (void)a1;
  u8 *obj = *(u8 **)(self + 4);
  *(u32 *)(self + 0x550) = 0;
  *(u32 *)(obj + 0x417) &= 0xffbfffffu;
  return 1;
}
PCREG(5e7210, heroMovementGuideTerminateControl);
