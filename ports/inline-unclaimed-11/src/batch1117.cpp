// batch1117.cpp - unclaimed-11 batch 18 (gap band 0x5a1000-0x5c1000): two GUESS leaves.
#include "ff.h"

// 0x5ac640, GUESS (name possibly CMessageBasics::SetPositionScreenY): dword arg1 to this+0xd, dword arg2 to this+0x15.
static void THISCALL guessStorePair(u8 *self, u32 a1, u32 a2) {
  *(u32 *)(self + 0xd) = a1;
  *(u32 *)(self + 0x15) = a2;
}
PCREG(5ac640, guessStorePair);

// 0x5aaaf0, GUESS (no name): clears the byte at [[this+0x474]+0x35] and [[this+0x478]+0x35].
static void THISCALL guessClearTwoFlags(u8 *self) {
  u8 *a = *(u8 **)(self + 0x474);
  a[0x35] = 0;
  u8 *b = *(u8 **)(self + 0x478);
  b[0x35] = 0;
}
PCREG(5aaaf0, guessClearTwoFlags);
