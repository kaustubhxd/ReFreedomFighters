// u69_71.cpp - area 69, group 71 (slice 8). A two-level table lookup on a pair of bytes (a bit test). No callees.
#include "ff.h"

// 0x624600, cdecl (ignored, p): the bytes v = p[0] and w = p[1]. t = byte 0x6bfc20[(v >> 2) & 7]; e = (v & 3) + 4*t;
// the dword at 0x6bf720 + 4*(((w >> 5) & 1) + 2*e) is ANDed with 1 << (w & 31); the result is returned.
static u32 bitTest624600(u32 ignored, u8 *p) {
  u32 v = p[0];
  u32 w = p[1];
  u32 t = *(const u8 *)(0x6bfc20 + ((v >> 2) & 7));
  u32 e = (v & 3) + t * 4;
  u32 idx = ((w >> 5) & 1) + e * 2;
  u32 word = *(const u32 *)(0x6bf720 + 4 * idx);
  return word & (1u << (w & 31));
}
PCREG(624600, bitTest624600);
