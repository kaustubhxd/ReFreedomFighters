#include "ff.h"
// batch3510.cpp - area 35 claim 10 (docs/20-unclaimed-35.md): four GUESS-named leaves in slice 14 (names from the residue list
// only; the GC name map has none). 0x436060 calls vtable slot 0 of the object at this+0x65 with one argument (stubbed in the
// harness, logged).

typedef u32(THISCALL *Slot1)(u8 *self, u32 a1);

// 0x5eeba0, GUESS FUN_5eeba0: stores the low byte of the argument at this + 0x4d.
static void THISCALL guessStoreByte(u8 *self, u32 a1) {
  self[0x4d] = (u8)a1;
}
PCREG(5eeba0, guessStoreByte);

// 0x490920, GUESS FUN_490920: increments the dword at this + 0x5d41.
static void THISCALL guessIncrement(u8 *self) {
  *(u32 *)(self + 0x5d41) += 1;
}
PCREG(490920, guessIncrement);

// 0x5fa5e0, GUESS FUN_5fa5e0: vtable 0x6b91dc at this; clears the global dword at 0x724270.
static void THISCALL guessSetVtable(u8 *self) {
  *(u32 *)self = 0x6b91dc;
  *(u32 *)0x724270 = 0;
}
PCREG(5fa5e0, guessSetVtable);

// 0x436060, GUESS FUN_436060: if this+0x65 is non-null, calls its slot 0 with 0 (one argument); returns true.
static u8 THISCALL guessCallSlot0(u8 *self, u32 a1) {
  (void)a1;
  u8 *o = *(u8 **)(self + 0x65);
  if (o)
    ((Slot1)*(u32 *)(*(u32 *)o + 0))(o, 0);
  return 1;
}
PCREG(436060, guessCallSlot0);
