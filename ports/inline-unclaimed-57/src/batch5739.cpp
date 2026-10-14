// batch5739.cpp - unclaimed-57, band batch 39 (name GUESS): 0x5d7ef0, thiscall, two stack args (idx, rec), ret 8. A list of 12-byte records
// B(j) = this + 12*j, count = dword this+0. If idx < count: k = count - 1; for j = k down to idx+1: B(j+1)+4 (8 bytes) = B(j)+4 and
// B(j+1)+0xc (dword) = B(j)+0xc; then B(idx+1)+4 = B(idx)+4 and B(idx+1)+0xc = B(idx)+0xc (the hole fill, as the original does). Then
// B(idx)+4 (8 bytes) = rec[0..8) and B(idx)+0xc (dword) = rec+8; count = count + 1. No calls.
#include "ff.h"

static u8 *rec12(u8 *self, u32 j) { return self + 12 * j; }

static void THISCALL unnamed5d7ef0(u8 *self, u32 idx, u8 *rec) {
  u32 c = *(u32 *)self;
  if (idx < c) {
    u32 k = c - 1;
    if (k != idx) {
      for (u32 j = k; j > idx; --j) {
        u8 *src = rec12(self, j);
        u8 *dst = rec12(self, j + 1);
        *(u64 *)(dst + 4) = *(u64 *)(src + 4);
        *(u32 *)(dst + 0xc) = *(u32 *)(src + 0xc);
      }
    }
    u8 *src = rec12(self, idx);
    u8 *dst = rec12(self, idx + 1);
    *(u64 *)(dst + 4) = *(u64 *)(src + 4);
    *(u32 *)(dst + 0xc) = *(u32 *)(src + 0xc);
  }
  u8 *b = rec12(self, idx);
  *(u64 *)(b + 4) = *(u64 *)(rec + 0);
  *(u32 *)(b + 0xc) = *(u32 *)(rec + 8);
  *(u32 *)self = *(u32 *)self + 1;
}
PCREG(5d7ef0, unnamed5d7ef0);
