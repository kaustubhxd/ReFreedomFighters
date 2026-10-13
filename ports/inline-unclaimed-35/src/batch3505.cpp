#include "ff.h"
// batch3505.cpp - area 35 claim 5 (docs/20-unclaimed-35.md): two leaves in slice 14. 0x4cd6e0 is a tail jump to vtable slot +4
// (LINKREFTAB::AddEnd); 0x4fa320 is a GUESS name (FUN_004fa320): it calls vtable slot +0x308 and returns true, with ret 8.

typedef u32(THISCALL *Slot1)(u8 *self, u32 a1);
typedef u32(THISCALL *Slot0)(u8 *self);

// 0x4cd6e0, LINKREFTAB::AddEnd(unsigned int) (low): tail jump to the vtable slot +4 with the same argument.
static u32 THISCALL linkRefTabAddEnd(u8 *self, u32 a1) {
  return ((Slot1)*(u32 *)(*(u32 *)self + 4))(self, a1);
}
PCREG(4cd6e0, linkRefTabAddEnd);

// 0x4fa320, GUESS FUN_004fa320: calls vtable slot +0x308 with no arguments, returns true. ret 8: two stack arguments unused.
static u8 THISCALL guessFa320(u8 *self, u32 a1, u32 a2) {
  (void)a1;
  (void)a2;
  ((Slot0)*(u32 *)(*(u32 *)self + 0x308))(self);
  return 1;
}
PCREG(4fa320, guessFa320);
