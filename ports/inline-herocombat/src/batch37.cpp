// batch37.cpp - shoot-tree leaves, inline session batch 37 (Haiku, night): 0x4db840 and 0x4da360.
#include "ff.h"

// 0x4db840, thiscall, no stack args, plain ret. Reads the dword at +0x23 of the object at (this+0x54)+0xc when this+0x54
// is nonzero; otherwise returns the constant 0x200002.
static u32 THISCALL getWordFromChild(u8 *self) {
  u8 *p = *(u8 **)(self + 0x54);
  if (p == 0)
    return 0x200002u;
  u8 *q = *(u8 **)(p + 0xc);
  return *(u32 *)(q + 0x23);
}
PCREG(4db840, getWordFromChild);

// 0x4da360, thiscall, two stack args (a0 at [ebp+8], a1 at [ebp+0xc]), ret 8. The low byte of ((~a1) & dword(this+0x3c)) | a0
// replaces the byte at this+0x3c (the other three bytes are kept). If a0's low byte is nonzero, the same function runs on
// each object in the sibling list that starts at this+0x50 and continues through each object's own +0x50, with args (a0, 0).
static void THISCALL setFlagTree(u8 *self, u32 a0, u32 a1) {
  u32 mem = *(u32 *)(self + 0x3c);
  u32 v = ((~a1) & mem) | a0;
  u8 low = (u8)(v & 0xffu);
  *(u8 *)(self + 0x3c) = 0;
  *(u32 *)(self + 0x3c) |= (u32)low;
  if ((u8)(a0 & 0xffu) != 0) {
    u8 *c = *(u8 **)(self + 0x50);
    while (c != 0) {
      setFlagTree(c, a0, 0);
      c = *(u8 **)(c + 0x50);
    }
  }
}
PCREG(4da360, setFlagTree);
