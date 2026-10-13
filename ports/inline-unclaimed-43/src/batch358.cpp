// batch358.cpp - 0x410540 (gap band). cdecl, two arguments: s (a block: +4 limit, +8 used) and n (signed).
// Returns -1 if used + n > limit (signed compare), else sets used = used + n and returns 0.
#include "ff.h"

static s32 advanceIfRoom(u32 *s, s32 n) {
  s32 ecx = (s32)(s[2] + (u32)n);
  if (ecx > (s32)s[1])
    return -1;
  s[2] = (u32)ecx;
  return 0;
}
PCREG(410540, advanceIfRoom);
