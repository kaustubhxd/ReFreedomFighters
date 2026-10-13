// batch3202.cpp - area 45 (residue 4), batch 3202: two residue-04 members that make one virtual call each.
// The virtual targets' classes are GUESS; the spec stubs them and the check covers this function's own logic.
#include "ff.h"

// 0x5e71c0 ZFFHeroMovementCloseCombat::TerminateControl(bool) [vtable] (residue-04.txt): calls the object at +0x36d
// with slot 0x220 and the argument 0; then clears bit 28 of the dword at (+0x36d)+0x417; clears the byte at +0x5ac;
// returns true. The bool argument is popped by ret 4 and not used.
static u8 THISCALL terminateControl(u8 *self, u8 flag) {
  (void)flag;
  vcall<void>(*(u8 **)(self + 0x36d), 0x220, 0u);
  u8 *o = *(u8 **)(self + 0x36d);
  *(u32 *)(o + 0x417) &= 0xefffffffu;
  self[0x5ac] = 0;
  return 1;
}
PCREG(5e71c0, terminateControl);

// 0x47aa80 ZActor::OnViewEnter() [vtable] (residue-04.txt), thiscall, plain ret: a counter at +0x640 is bumped; when it
// was zero and the object at +8 has no bit 0x800 in its flag word (+0x3c), the virtual at slot 0xbc is called with 0.
static void THISCALL onViewEnter(u8 *self) {
  u32 old = *(u32 *)(self + 0x640);
  *(u32 *)(self + 0x640) = old + 1;
  if (old == 0) {
    u8 *g = *(u8 **)(self + 8);
    if (!(*(u32 *)(g + 0x3c) & 0x800))
      vcall<void>(self, 0xbc, old);
  }
}
PCREG(47aa80, onViewEnter);
