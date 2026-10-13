// batch1116.cpp - unclaimed-11 batch 17 (slice 10, full list): two GUESS leaves (no GC names).
#include "ff.h"


// 0x64dde0, GUESS: copies the 16 bytes at *arg to this+0x10061 (four dwords, as movups does).
static void THISCALL guessCopy16(u8 *self, const u8 *src) {
  __builtin_memcpy(self + 0x10061, src, 16);
}
PCREG(64dde0, guessCopy16);
