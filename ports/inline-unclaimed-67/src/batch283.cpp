// batch283.cpp - unclaimed area 67, gap band: string cursor advance past the next NUL.
#include "ff.h"

static inline u32 rdw(u32 p, u32 off) { return *(u32 *)(unsigned long)(p + off); }

// 0x5f2e60, thiscall, ret 4 (argument out): *out = cursor = [this+8]; if *cursor != 0, walk to the NUL (storing the cursor at
// [this+8] at each step); finally [this+8] is incremented by one.
static void THISCALL cursorPastNul(u8 *selfP, u32 out) {
  u32 self = (u32)(unsigned long)selfP;
  u32 p = rdw(self, 8);
  *(u32 *)(unsigned long)out = p;
  if (*(u8 *)(unsigned long)p != 0) {
    do {
      p++;
      *(u32 *)(selfP + 8) = p;
    } while (*(u8 *)(unsigned long)p != 0);
  }
  *(u32 *)(selfP + 8) = rdw(self, 8) + 1;
}
PCREG(5f2e60, cursorPastNul);
