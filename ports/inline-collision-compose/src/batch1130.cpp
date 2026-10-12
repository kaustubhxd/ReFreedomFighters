// batch1130.cpp - collision thread, batch 1130: ZCollisionBase::LockCollisionBox (0x4edd10).
#include "ff.h"

// 0x4edd10 ZCollisionBase::LockCollisionBox(char *a, unsigned b) [medium], thiscall, ret 8, returns this+4 (the box).
// Its helpers, with ECX = box = this+4 (both verified by reading the bytes, not by a checker run):
//   0x4ea380: word at box+0xa4 = 0x100 (word at this+0xa8);
//   0x4eb060(a, b): dword at box+0xc = a (this+0x10), dword at box+0x10 = b (this+0x14), ret 8.
// Then this+0xc = 0, and the box pointer (this+4) is returned.
static u8 *THISCALL lockCollisionBox(u8 *self, u32 a, u32 b) {
  u8 *box = self + 4;
  *(u16 *)(box + 0xa4) = 0x100;
  *(u32 *)(box + 0xc) = a;
  *(u32 *)(box + 0x10) = b;
  *(u32 *)(self + 0xc) = 0;
  return box;
}
PCREG(4edd10, lockCollisionBox);
