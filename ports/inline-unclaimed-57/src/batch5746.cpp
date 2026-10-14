// batch5746.cpp - unclaimed-57, band batch 46 (name GUESS): 0x5d3a10, thiscall, two stack args (w, a), ret 8, returns 0. If (word)w equals
// the word at this+0x7a, dword this+0x48 = a. Leaf (no calls).
#include "ff.h"

static u32 THISCALL unnamed5d3a10(u8 *self, u32 w, u32 a) {
  if ((u16)w == *(u16 *)(self + 0x7a)) *(u32 *)(self + 0x48) = a;
  return 0;
}
PCREG(5d3a10, unnamed5d3a10);
