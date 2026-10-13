// batch8484.cpp - residue 6 batch 84 (GUESS names): FUN_004e4fe0 and FUN_004d1c60.
#include "ff.h"

// 0x4e4fe0 (GUESS FUN_004e4fe0): stores the argument's 32 bits at this+0x1d (movss copies the bits unchanged). Ret 4.
static void THISCALL guess4e4fe0(u8 *self, u32 a) {
  *(u32 *)(self + 0x1d) = a;
}
PCREG(4e4fe0, guess4e4fe0);

// 0x4d1c60 (GUESS FUN_004d1c60): p = vtable slot +0x3c on this with the argument; returns the byte at p. Ret 4.
static u8 THISCALL guess4d1c60(u8 *self, u32 a) {
  u8 *p = (u8 *)vcall<u32>(self, 0x3c, a);
  return *p;
}
PCREG(4d1c60, guess4d1c60);
