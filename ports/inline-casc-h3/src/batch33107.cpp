// batch33107.cpp - h3 (Sonnet) batch 33107: tier H float/SSE functions
#include "ff.h"

// 0x5a3690: thiscall(i, j) ret 8: array of 16-byte entries at this+4, count at [this]: i == j: shift entries k+1 -> k for k in i .. count-2, count--; else copy (count-j) entries from j to i (forward) and count += i - j
static void THISCALL fn5a3690(u8 *self, u32 i, u32 j) {
  u32 *cnt = (u32 *)self;
  if (i == j) {
    u32 k = i;
    if (k < *cnt - 1) {
      do {
        __builtin_memcpy(self + 4 + 16 * k, self + 4 + 16 * k + 16, 16);
        k++;
      } while (k < *cnt - 1);
    }
    *cnt -= 1;
    return;
  }
  u32 n = *cnt - j;
  if (n != 0) {
    u8 *dst = self + 4 + 16 * i;
    u8 *src = self + 4 + 16 * j;
    for (; n != 0; n--) {
      __builtin_memcpy(dst, src, 16);
      dst += 16;
      src += 16;
    }
  }
  *cnt += i - j;
}
PCREG(5a3690, fn5a3690);

// 0x504b60: thiscall(a, f1, f2, f3, f4) ret 0x14: a == 0 -> 0; o=[this+0x14]; o->slot 0x80(l34, l10) fills two stack structs; return (u8) o->slot 0x37c(a, f1, f2, l34, l10, f3, f4)
static u32 THISCALL fn504b60(u8 *self, u32 a, u32 f1, u32 f2, u32 f3, u32 f4) {
  if (a == 0) return 0;
  u32 l34[9];
  u32 l10[3];
  u8 *o = *(u8 **)(self + 0x14);
  vcall<u32>(o, 0x80, (u32)l34, (u32)l10);
  o = *(u8 **)(self + 0x14);
  u8 r = vcall<u8>(o, 0x37c, a, f1, f2, (u32)l34, (u32)l10, f3, f4);
  return (u32)r;
}
PCREG(504b60, fn504b60);
