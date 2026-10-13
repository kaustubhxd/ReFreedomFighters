// batch1119.cpp - unclaimed-11 batch 20 (gap band 0x5bf7f0): GUESS, word-matching counters. Always returns 0.
#include "ff.h"

// 0x5bf7f0, GUESS (no name). The first matching word wins: +0x55 increments the dword at +0x59; +0x57 decrements it when
// it is positive; +0x66 increments the dword at +0x6a; +0x68 decrements that when positive. No match: nothing.
static u32 THISCALL guessWordCounters(u8 *self, u16 w, u32 unused) {
  if (w == *(u16 *)(self + 0x55)) {
    ++*(s32 *)(self + 0x59);
  } else if (w == *(u16 *)(self + 0x57)) {
    if (*(s32 *)(self + 0x59) > 0) --*(s32 *)(self + 0x59);
  } else if (w == *(u16 *)(self + 0x66)) {
    ++*(s32 *)(self + 0x6a);
  } else if (w == *(u16 *)(self + 0x68)) {
    if (*(s32 *)(self + 0x6a) > 0) --*(s32 *)(self + 0x6a);
  }
  return 0;
}
PCREG(5bf7f0, guessWordCounters);
