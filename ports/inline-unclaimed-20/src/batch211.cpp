// batch211.cpp - unclaimed area 20 (docs/20-unclaimed-20.md), slice floor(addr/16) mod 20 == 19. A pure function (no calls):
// a search over an array of 8-byte entries {u32 value, u32 key} stored at [this+4] with count [this+8].
#include "ff.h"

// 0x4cd9b0, thiscall(x, unused) ret 8. Scan entries i = 0..n-1 (e = base + 8*i):
//   key < x: skip; key == x: return e's value after moving the last entry into e and setting [this+8] = n-1;
//   key > x: remember e if no candidate yet or the remembered key is greater than this key.
// After the scan: no candidate -> return 0xffffffff; else key -= x, value += x, and the old value is returned. Name GUESS.
static u32 THISCALL pickAndSubtract_4cd9b0(u8 *self, u32 x, u32) {
  u32 *base = *(u32 **)(self + 4);
  u32 n = *(u32 *)(self + 8);
  u32 *best = nullptr;
  for (u32 i = 0; i < n; ++i) {
    u32 *e = base + 2 * i;
    u32 key = e[1];
    if (key < x) continue;
    if (key == x) {
      u32 c = n - 1;
      *(u32 *)(self + 8) = c;
      u32 *last = base + 2 * c;
      u32 old = e[0];
      e[0] = last[0];
      e[1] = last[1];
      return old;
    }
    if (!best || best[1] > key) best = e;
  }
  if (!best) return 0xffffffffu;
  u32 old = best[0];
  best[1] -= x;
  best[0] = old + x;
  return old;
}
PCREG(4cd9b0, pickAndSubtract_4cd9b0);
