#include "ff.h"
// batch8013.cpp - unclaimed-79 gap-band group (docs/20-unclaimed-79.md). Names GUESS (no GC name).

// 0x48f730 (GUESS): thiscall, decrements the dword at this+0x5d39 if it is nonzero.
static void THISCALL f_48f730(u8 *self) {
  u32 v = *(u32 *)(self + 0x5d39);
  if (v != 0) *(u32 *)(self + 0x5d39) = v - 1;
}
PCREG(48f730, f_48f730);

// 0x491e80 (GUESS): thiscall (ret 8). Asks its vtable slot +0x158 for a list head with its first argument, then scans the
// list (next at +0xc) for a node whose dword at +0x23 equals the second argument. Returns 1 if found, else 0.
static u8 THISCALL f_491e80(u8 *self, u32 a, u32 k) {
  u8 *n = (u8 *)(unsigned long)vcall<u32, u32>(self, 0x158, a);
  if (n == 0) return 0;
  while (1) {
    if (*(u32 *)(n + 0x23) == k) return 1;
    n = *(u8 **)(n + 0xc);
    if (n == 0) return 0;
  }
}
PCREG(491e80, f_491e80);
