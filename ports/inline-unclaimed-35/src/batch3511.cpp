#include "ff.h"
// batch3511.cpp - area 35 claim 11 (docs/20-unclaimed-35.md): four GUESS-named leaves in slice 14. The vtable slots they call are
// logged stubs in the harness. 0x61bce0 is cdecl: its first stack argument is the object used as this.

typedef u32(THISCALL *Slot1)(u8 *self, u32 a1);
typedef u32(THISCALL *Slot2)(u8 *self, u32 a1, u32 a2);

// 0x524760, GUESS FUN_524760: stores the two arguments at this + 0x18 and + 0x1c.
static void THISCALL guessStorePair(u8 *self, u32 a1, u32 a2) {
  *(u32 *)(self + 0x18) = a1;
  *(u32 *)(self + 0x1c) = a2;
}
PCREG(524760, guessStorePair);

// 0x499a20, GUESS FUN_499a20: calls vtable slot +0x28 of this with the argument; returns this.
static u8 *THISCALL guessCallSlot28(u8 *self, u32 a1) {
  ((Slot1)*(u32 *)(*(u32 *)self + 0x28))(self, a1);
  return self;
}
PCREG(499a20, guessCallSlot28);

// 0x600260, GUESS FUN_600260: this + 4 = first argument, this + 8 = first + second.
static void THISCALL guessStoreSum(u8 *self, u32 a1, u32 a2) {
  *(u32 *)(self + 4) = a1;
  *(u32 *)(self + 8) = a1 + a2;
}
PCREG(600260, guessStoreSum);

// 0x61bce0, GUESS FUN_61bce0 (cdecl): the first stack argument is the object; calls its vtable slot +0x24 with the other two.
static void guessCdeclCallSlot24(u8 *obj, u32 a1, u32 a2) {
  ((Slot2)*(u32 *)(*(u32 *)obj + 0x24))(obj, a1, a2);
}
PCREG(61bce0, guessCdeclCallSlot24);
