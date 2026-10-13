// batch1118.cpp - unclaimed-11 batch 19 (gap band 0x5a1000-0x5c1000): GUESS, eight dword stack arguments (ret 0x20).
#include "ff.h"

// 0x5ab020, GUESS: arguments 1..4 (16 bytes) to this+0x8af, arguments 5..8 (16 bytes) to this+0x8bf.
static void THISCALL guessStoreEightArgs(u8 *self, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7, u32 a8) {
  u32 first[4] = {a1, a2, a3, a4};
  u32 second[4] = {a5, a6, a7, a8};
  __builtin_memcpy(self + 0x8af, first, 16);
  __builtin_memcpy(self + 0x8bf, second, 16);
}
PCREG(5ab020, guessStoreEightArgs);
