// batch1917.cpp - unclaimed-66 batch 17: two slice-5 leaves (GUESS names; bodies from the bytes). Thiscall.
#include "ff.h"

// 0x45ed90, GUESS FUN_0045ed90: eax = [this+0x10]; if eax != 0 return [eax+0x10], else return 0.
static u32 THISCALL leaf45ed90(u8 *self) {
  u8 *p = *(u8 **)(self + 0x10);
  if (p) return *(u32 *)(p + 0x10);
  return 0;
}
PCREG(45ed90, leaf45ed90);

// 0x49e0d0, GUESS FUN_0049e0d0: q = [this]; if (byte[q] & 1) return q + 1, else return the constant 0x677b5a.
static u8 *THISCALL leaf49e0d0(u8 *self) {
  u8 *q = *(u8 **)self;
  if (q[0] & 1) return q + 1;
  return (u8 *)0x677b5a;
}
PCREG(49e0d0, leaf49e0d0);
