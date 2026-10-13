#include "ff.h"
// batch3512.cpp - area 35 claim 12 (docs/20-unclaimed-35.md): four leaves in slice 14. The vtable slots they call are logged stubs
// in the harness (no arguments). 0x61c5a0 is cdecl: its first stack argument is the object.

typedef u32(THISCALL *Slot0)(u8 *self);

// 0x42f8a0, GUESS FUN_42f8a0: byte at this + 0x1b59 = 1; dword at this + 0x1b49 = first argument (three arguments, ret 0xc).
static void THISCALL guessFlagAndStore(u8 *self, u32 a0, u32 a1, u32 a2) {
  (void)a1;
  (void)a2;
  self[0x1b59] = 1;
  *(u32 *)(self + 0x1b49) = a0;
}
PCREG(42f8a0, guessFlagAndStore);

// 0x4fa6e0, ZScrollbar::SetBarSize(int) (high): stores the argument at this + 0xab, then calls vtable slot +0x358.
static void THISCALL scrollbarSetBarSize(u8 *self, u32 a1) {
  *(u32 *)(self + 0xab) = a1;
  ((Slot0)*(u32 *)(*(u32 *)self + 0x358))(self);
}
PCREG(4fa6e0, scrollbarSetBarSize);

// 0x61c5a0, GUESS FUN_61c5a0 (cdecl): the first stack argument is the object; stores the second at +0x50, zeroes +0x128.
static void guessCdeclStore(u8 *obj, u32 a1) {
  *(u32 *)(obj + 0x50) = a1;
  *(u32 *)(obj + 0x128) = 0;
}
PCREG(61c5a0, guessCdeclStore);

// 0x431f60, GUESS FUN_431f60: calls vtable slots +0x70 and +0x24 of this, then tail-jumps to slot +0x28.
static void THISCALL guessCallChain(u8 *self) {
  ((Slot0)*(u32 *)(*(u32 *)self + 0x70))(self);
  ((Slot0)*(u32 *)(*(u32 *)self + 0x24))(self);
  ((Slot0)*(u32 *)(*(u32 *)self + 0x28))(self);
}
PCREG(431f60, guessCallChain);
