// batch4002.cpp - area 70 (residue 9), batch 4002: two single-virtual wrappers (virtual targets are GUESS; the spec stubs
// them, so the check covers each wrapper's own logic).
#include "ff.h"

// 0x463010 (wrapper, name GUESS): thiscall, plain ret. Pushes this, calls the slot 0x58 virtual of the object at +0x6c
// with ECX = that object and the pushed this as one stack argument (the callee pops it, ret 4), and returns its eax.
static u32 THISCALL wrapSlot58(u8 *self) {
  return vcall<u32>(*(u8 **)(self + 0x6c), 0x58, self);
}
PCREG(463010, wrapSlot58);

// 0x481510 (wrapper, name GUESS): thiscall, ret 8. When the second argument has bit 0x1000 set, calls the slot 0x1c
// virtual (no arguments) of the object at +0x455.
static void THISCALL wrapSlot1cFlag(u8 *self, u32 a, u32 flag) {
  (void)a;
  if (flag & 0x1000)
    vcall<void>(*(u8 **)(self + 0x455), 0x1c);
}
PCREG(481510, wrapSlot1cFlag);
