// u69_50.cpp - area 69, group 50 (slice 8). An interval list: self+4 is the array P of (start, len) dword pairs, self+8 is its count N. No callees.
#include "ff.h"

// 0x4cda40, thiscall two stack args (x, len; ret 8), returns bool in al. Removes [x, x+len) from the interval that contains x:
// len 0 returns 1 at once; an empty list returns 0; with no interval containing x, returns 0.
// Otherwise: a start below x keeps the start and shrinks the length to x - start, and when x+len is inside the interval it adds [x+len, end) as a new entry at P[N];
// a start equal to x moves the start to x+len (when x+len is inside), otherwise the entry is removed by moving the last entry into its slot.
static u8 THISCALL removeRange4cda40(u8 *self, u32 x, u32 len) {
  if (len == 0)
    return 1;
  u32 *P = *(u32 **)(self + 4);
  u32 N = *(u32 *)(self + 8);
  if (N == 0)
    return 0;
  u32 i = 0;
  for (; i < N; ++i) {
    u32 start = P[2 * i];
    u32 end = start + P[2 * i + 1];
    if (start <= x && x < end)
      break;
  }
  if (i == N)
    return 0;
  u32 *entry = P + 2 * i;
  u32 start = entry[0];
  u32 end = start + entry[1];
  u32 y = x + len;
  if (start < x) {
    entry[0] = start;
    entry[1] = x - start;
    if (y >= end)
      return 1;
    u32 *fresh = P + 2 * N;
    *(u32 *)(self + 8) = N + 1;
    fresh[0] = y;
    fresh[1] = end - y;
    return 1;
  }
  if (y < end) {
    entry[0] = y;
    entry[1] = end - y;
    return 1;
  }
  u32 last = N - 1;
  *(u32 *)(self + 8) = last;
  entry[0] = P[2 * last];
  entry[1] = P[2 * last + 1];
  return 1;
}
PCREG(4cda40, removeRange4cda40);
