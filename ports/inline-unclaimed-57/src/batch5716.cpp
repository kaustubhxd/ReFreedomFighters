// batch5716.cpp - unclaimed-57 (docs/20-unclaimed-57.md), batch 16: 0x563d40 (GUESS, unnamed), stdcall, three arguments (a1, p, lim),
// ret 0xc, returns eax. *p = *p + 1; if the new *p is signed-less-than lim, return it; otherwise *p = a1 and return a1.
#include "ff.h"

static u32 STDCALL unnamed563d40(u32 a1, u32 *p, u32 lim) {
  (*p)++;
  u32 v = *p;
  if ((s32)v < (s32)lim) return v;
  *p = a1;
  return a1;
}
PCREG(563d40, unnamed563d40);
