#include "ff.h"
// batch1386.cpp - unclaimed-13 claim 5 (docs/20-unclaimed-13.md). Name from the GC name map (medium).

// 0x583380, CHitpointControl::End() (medium, GUESS name): ecx is the value to remove. The global object at 0x7003b8 holds
// a dword count at +0xb61 and a dword array at +0xb65. Finds the value in the array; if found at index i, shifts the
// later entries down by one and decrements the count. Nothing is found, nothing changes. fastcall (value in ecx),
// void, ret 0.
static void FASTCALL hitpointControlRemove(u32 value) {
  u8 *base = (u8 *)(unsigned long)G(u32, 0x7003b8) + 0xb61;
  u32 count = *(u32 *)base;
  u32 *items = (u32 *)(base + 4);
  u32 i = 0;
  while (i < count && items[i] != value) i++;
  if (i == count) return;
  for (u32 j = i; j + 1 < count; j++) items[j] = items[j + 1];
  *(u32 *)base = count - 1;
}
PCREG(583380, hitpointControlRemove);
