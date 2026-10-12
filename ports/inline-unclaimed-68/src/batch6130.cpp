// batch6130.cpp - unclaimed-68 batch 14 (claim 13). Name: GUESS FUN_4cc130 (string equality; see docs/20-unclaimed-68.md).
#include "ff.h"

// 0x4cc130 (GUESS): thiscall, one stack argument, ret 4. s1 = *(char**)this, s2 = *(char**)arg. Compares two bytes per step; returns
// 1 when the strings are equal (including both ending at the same place) and 0 at the first difference.
static u32 THISCALL guessFun4cc130(u8 *self, u8 *arg) {
  const u8 *s1 = *(const u8 **)self;
  const u8 *s2 = *(const u8 **)arg;
  for (;;) {
    if (s1[0] != s2[0]) return 0;
    if (s1[0] == 0) return 1;
    if (s1[1] != s2[1]) return 0;
    u8 d = s1[1];
    s1 += 2;
    s2 += 2;
    if (d == 0) return 1;
  }
}
PCREG(4cc130, guessFun4cc130);
