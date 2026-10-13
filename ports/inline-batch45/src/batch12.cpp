// batch12.cpp - first-level functions, inline session batch 12 (Haiku, overnight).
#include "ff.h"

// 0x45dc60, thiscall (ret 4): with a nonzero argument sets bit 0 of the flags at this+0x14; with zero clears bit 0
// when the low nibble of the flags is 1. Name unknown.
static void THISCALL flagUpdate(u8 *self, u32 arg) {
  u32 *flags = (u32 *)(self + 0x14);
  if ((u8)arg != 0) {
    if ((*flags & 1) == 0)
      *flags |= 1;
  } else {
    u32 v = *flags;
    if ((v & 0xf) == 1)
      *flags = v & 0xfffffffeu;
  }
}
PCREG(45dc60, flagUpdate);

// 0x5df750, thiscall (ret 0x10, returns this): constructor. Stores four arguments at +4, +8, +0xc, +0x10, sets the
// vtable word 0x6b7338, and clears +0x14, +0x1c and the byte at +0x20. Name unknown.
static u32 THISCALL initFour(u8 *self, u32 a1, u32 a2, u32 a3, u32 a4) {
  *(u32 *)(self + 4) = a1;
  *(u32 *)(self + 8) = a2;
  *(u32 *)(self + 0xc) = a3;
  *(u32 *)(self + 0x10) = a4;
  *(u32 *)self = 0x6b7338u;
  *(u32 *)(self + 0x14) = 0;
  *(u32 *)(self + 0x1c) = 0;
  self[0x20] = 0;
  return (u32)self;
}
PCREG(5df750, initFour);

// 0x485d30, thiscall (ret 0x14, returns this): constructor. Stores five arguments at +4, +0xc, +0x10, +0x14, +0x18,
// sets the vtable word 0x68cbe4 and clears +8. Name unknown.
static u32 THISCALL initFive(u8 *self, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5) {
  *(u32 *)(self + 4) = a1;
  *(u32 *)(self + 0xc) = a2;
  *(u32 *)(self + 0x10) = a3;
  *(u32 *)(self + 0x14) = a4;
  *(u32 *)(self + 0x18) = a5;
  *(u32 *)self = 0x68cbe4u;
  *(u32 *)(self + 8) = 0;
  return (u32)self;
}
PCREG(485d30, initFive);

// 0x4d1c00, thiscall (ret 4): walks a singly linked list from this+0x24 (next pointer at +0x30) and returns the index
// of the first node equal to the argument, or -1 when none matches. Name unknown.
static s32 THISCALL findIndex(u8 *self, u32 target) {
  u32 node = *(u32 *)(self + 0x24);
  u32 idx = 0;
  if (node == 0)
    return -1;
  while (node != target) {
    node = *(u32 *)(node + 0x30);
    idx++;
    if (node == 0)
      return -1;
  }
  return (s32)idx;
}
PCREG(4d1c00, findIndex);
