// batch22.cpp - first-level functions, inline session batch 22 (Haiku, overnight).
#include "ff.h"

// 0x48db70, thiscall (no stack args, returns EAX): the top two bits of this+4 pick a field. When they are 01, 10 or 11
// the difference (this+4 & 0x3fffffff) - this+8 is taken, otherwise this+4 - 8. A zero difference returns 0. Else
// 01 returns this+0xc, 11 returns this+0x10, and anything else returns 1. Name unknown.
static u32 THISCALL decodeSlot(u8 *self) {
  u32 w = *(u32 *)(self + 4);
  u32 top = w & 0xc0000000u;
  u32 d;
  if (top == 0x40000000u || top == 0x80000000u || top == 0xc0000000u)
    d = (w & 0x3fffffffu) - *(u32 *)(self + 8);
  else
    d = w - 8;
  if (d == 0)
    return 0;
  if (top == 0x40000000u)
    return *(u32 *)(self + 0xc);
  if (top == 0xc0000000u)
    return *(u32 *)(self + 0x10);
  return 1;
}
PCREG(48db70, decodeSlot);

// 0x485ca0, thiscall (nine stack args, ret 0x24, returns this): stores the args into this+4 .. this+0x24 (a6 goes to
// +0x18 and a5 to +0x1c), sets the vtable word at this to 0x68cd8c and the word at +0x28 to 0. Name unknown.
static u8 *THISCALL initRec9(u8 *self, u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7, u32 a8) {
  *(u32 *)(self + 4) = a0;
  *(u32 *)(self + 8) = a1;
  *(u32 *)(self + 0xc) = a2;
  *(u32 *)(self + 0x10) = a3;
  *(u32 *)(self + 0x14) = a4;
  *(u32 *)(self + 0x18) = a6;
  *(u32 *)(self + 0x1c) = a5;
  *(u32 *)(self + 0x20) = a7;
  *(u32 *)(self + 0x24) = a8;
  *(u32 *)self = 0x68cd8c;
  *(u32 *)(self + 0x28) = 0;
  return self;
}
PCREG(485ca0, initRec9);

// 0x485e30, thiscall (ten stack args, ret 0x28, returns this): stores the args into this+4 .. this+0x28 (a7 goes to
// +0x24 and a8 to +0x20), sets the vtable word at this to 0x68cd3c and the word at +0x2c to 0. Name unknown.
static u8 *THISCALL initRec10(u8 *self, u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7, u32 a8,
                              u32 a9) {
  *(u32 *)(self + 4) = a0;
  *(u32 *)(self + 8) = a1;
  *(u32 *)(self + 0xc) = a2;
  *(u32 *)(self + 0x10) = a3;
  *(u32 *)(self + 0x14) = a4;
  *(u32 *)(self + 0x18) = a5;
  *(u32 *)(self + 0x1c) = a6;
  *(u32 *)(self + 0x20) = a8;
  *(u32 *)(self + 0x24) = a7;
  *(u32 *)(self + 0x28) = a9;
  *(u32 *)self = 0x68cd3c;
  *(u32 *)(self + 0x2c) = 0;
  return self;
}
PCREG(485e30, initRec10);
