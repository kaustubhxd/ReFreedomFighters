// batch6540.cpp - unclaimed-68 batch 54 (claims 54 and 55, residue rows). Names are GUESS (no name-map entry).
#include "ff.h"

typedef u32(THISCALL *VSlot58Str)(u8 *self, u32 key);

// 0x488ba0, GUESS FUN_488ba0: thiscall, no arguments, plain ret. this+0x1d = vt[+0x58](0x68d420) (the dword result).
static void THISCALL guessFn488ba0(u8 *self) {
  *(u32 *)(self + 0x1d) = ((VSlot58Str)*(u32 *)(*(u8 **)self + 0x58))(self, 0x68d420u);
}
PCREG(488ba0, guessFn488ba0);

// 0x5c2790, GUESS FUN_5c2790 (the notes also name it a global list append): fastcall (ecx = the value), plain ret.
// list = [0x7003b8]; n = list->dword[+0xbe5]; list->dword[+0xbe9 + 4n] = value; list->dword[+0xbe5] = n + 1.
static void FASTCALL guessFn5c2790(u32 value) {
  u8 *list = G(u8 *, 0x7003b8);
  u32 n = *(u32 *)(list + 0xbe5);
  *(u32 *)(list + 0xbe9 + 4 * n) = value;
  *(u32 *)(list + 0xbe5) = n + 1;
}
PCREG(5c2790, guessFn5c2790);
