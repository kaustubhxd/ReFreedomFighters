// u69_51.cpp - area 69, group 51 (slice 8). The companion of 0x4cda40 for the same interval list (self+4 = P, 8-byte (start, len) entries; self+8 = N). No callees.
#include "ff.h"

// 0x4ce1c0, thiscall two stack args (x, len; ret 8), void. Adds [x, x+len) to the list, merging with a neighbour:
// scanning in order, an entry that starts at y = x+len takes the new range on its left (MERGE_RIGHT, then absorbs a later entry that ends at x);
// an entry that ends at x takes the new range on its right (MERGE_LEFT, then absorbs a later entry that starts at y); with neither, (x, len) is appended at P[N].
// The absorbed entry is removed by moving the last entry into its slot.
static void THISCALL insertRange4ce1c0(u8 *self, u32 x, u32 len) {
  u32 *P = *(u32 **)(self + 4);
  u32 N = *(u32 *)(self + 8);
  u32 y = x + len;
  for (u32 i = 0; i < N; ++i) {
    u32 *E = P + 2 * i;
    if (E[0] == y) {
      E[1] += len;
      E[0] -= len;
      for (u32 k = i + 1; k < N; ++k) {
        u32 *Ek = P + 2 * k;
        if (Ek[0] + Ek[1] == x) {
          E[0] -= Ek[1];
          E[1] += Ek[1];
          N -= 1;
          *(u32 *)(self + 8) = N;
          Ek[0] = P[2 * N];
          Ek[1] = P[2 * N + 1];
          return;
        }
      }
      return;
    }
    if (E[0] + E[1] == x) {
      E[1] += len;
      if (i + 1 >= N)
        return;
      for (u32 k = i + 1; k < N; ++k) {
        u32 *Ek = P + 2 * k;
        if (Ek[0] == y) {
          E[1] += Ek[1];
          N -= 1;
          *(u32 *)(self + 8) = N;
          Ek[0] = P[2 * N];
          Ek[1] = P[2 * N + 1];
          return;
        }
      }
      return;
    }
  }
  P[2 * N] = x;
  P[2 * N + 1] = len;
  *(u32 *)(self + 8) = N + 1;
}
PCREG(4ce1c0, insertRange4ce1c0);
