// batch1040.cpp - unclaimed-04 batch 40 (docs/20-unclaimed-04.md): 0x5ffb70, thiscall, one 16-bit key argument (ret 4).
#include "ff.h"

// 0x5ffb70: walk the tree from root+1; keep the last node whose key is >= the search key (following +5), else follow +9.
// If the kept node's key is above the search key, fall back to the root. A root result returns 0, else the dword at +0xf.
static u32 THISCALL unk5ffb70TreeFind(u8 *self, u32 keyArg) {
  u16 key = (u16)keyArg;
  u8 *root = *(u8 **)(self + 0x118);
  u8 *best = root;
  u8 *n = *(u8 **)(root + 1);
  while (n != 0) {
    if (*(u16 *)(n + 0xd) < key) {
      n = *(u8 **)(n + 9);
    } else {
      best = n;
      n = *(u8 **)(n + 5);
    }
  }
  if (best != root && key < *(u16 *)(best + 0xd)) best = root;
  if (best == root) return 0;
  return *(u32 *)(best + 0xf);
}
PCREG(5ffb70, unk5ffb70TreeFind);
