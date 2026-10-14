// batch753.cpp - unclaimed area 75 (docs/20-unclaimed-75.md), slice floor(addr/16) mod 20 == 13.
#include "ff.h"

// 0x5a3690, thiscall(a, b) ret 8. Entries are 16 bytes at this+4, the count is the dword at [this].
// If a == b: while a < count-1, entry[a] = entry[a+1] and a++; then count--.
// Else: k = count - b; if k != 0, entry[a+i] = entry[b+i] for i < k (ascending); then count += a - b.
// Name GUESS (remove-or-shift entries).
static void THISCALL removeOrShift_5a3690(u8 *self, u32 a, u32 b) {
  u32 &count = *(u32 *)self;
  u8 *base = self + 4;
  if (a == b) {
    u32 idx = a;
    while (idx < count - 1) {
      for (int j = 0; j < 16; ++j) base[16 * idx + j] = base[16 * (idx + 1) + j];
      ++idx;
    }
    --count;
  } else {
    u32 k = count - b;
    for (u32 i = 0; i < k; ++i) {
      for (int j = 0; j < 16; ++j) base[16 * (a + i) + j] = base[16 * (b + i) + j];
    }
    count += a - b;
  }
}
PCREG(5a3690, removeOrShift_5a3690);
