// batch14.cpp - first-level functions, inline session batch 14 (Haiku, overnight).
#include "ff.h"

// 0x613830, thiscall (no stack args, returns the index claimed or 0): finds the first entry from index 1 to 0x7ff whose
// dword (entries 0x44 bytes, first one at this+0x80) is zero, sets dword this+0x3c+0x44*index to 1 and returns the
// index; returns 0 when none is free. Name unknown.
static u32 THISCALL claimSlot(u8 *self) {
  u32 idx = 1;
  u8 *p = self + 0x80;
  while (*(u32 *)p != 0) {
    idx++;
    p += 0x44;
    if (idx >= 0x800)
      return 0;
  }
  *(u32 *)(self + 0x3c + idx * 0x44u) = 1;
  return idx;
}
PCREG(613830, claimSlot);

// 0x5acfb0, thiscall (no stack args, returns the count): counts the set bits 0..30 of the dword at this+0x72.
// Name unknown.
static u32 THISCALL countBits31(u8 *self) {
  u32 bits = *(u32 *)(self + 0x72);
  u32 mask = 1;
  u32 count = 0;
  for (u32 n = 0x1f; n != 0; n--) {
    if ((bits & mask) != 0)
      count++;
    mask = (mask << 1) | (mask >> 31);
  }
  return count;
}
PCREG(5acfb0, countBits31);

// 0x658f70, thiscall (no stack args, returns a size): 0 when the flag bit 4 at this+0x3c is clear. Otherwise the
// size is (count * 0x84 + 0xf + base) rounded down to a multiple of 16, where count is the byte at this+0x3f and
// base is 0 when count is 0 and this+0x48 + 0x90 otherwise. Name unknown.
static u32 THISCALL entrySize(u8 *self) {
  if ((self[0x3c] & 4) == 0)
    return 0;
  u32 count = self[0x3f];
  u32 base = 0;
  if (count != 0)
    base = *(u32 *)(self + 0x48) + 0x90u;
  return (count * 0x84u + 0xfu + base) & 0xfffffff0u;
}
PCREG(658f70, entrySize);
