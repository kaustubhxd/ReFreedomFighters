// batch846.cpp - gap band UTF-16 scanners with jump tables (docs/20-unclaimed-gap-621.md). Names are GUESS.
#include "ff.h"

// Shared walk: cvt[0x4c + b] is a per-byte class table. A UTF-16 unit whose high byte is 0 takes its class from cvt[0x4c + low];
// high bytes 0xd8..0xdb give class 7, 0xdc..0xdf class 8, 0xff gives 0 when low >= 0xfe (else 0x1d), every other high byte
// class 0x1d. Class - 5 selects the step: 0 -> 2 bytes, 1 -> 3, 2 -> 4, 17..22 and 24 -> 2, anything else (including classes below 5
// and above 0x1d) ends the scan and returns the bytes consumed. Reproduces the two jump tables at 0x622c44/0x622c7c and 0x625bc0/0x625bf8.
static u32 scanUnits(const u8 *cvt, const u8 *p0, bool bigEndian) {
  const u8 *p = p0;
  for (;;) {
    u32 hi = bigEndian ? p[0] : p[1];
    u32 lo = bigEndian ? p[1] : p[0];
    u32 t;
    if (hi == 0) {
      t = cvt[0x4c + lo];
    } else {
      u32 idx = hi - 0xd8;
      if (idx > 0x27) {
        t = 0x1d;
      } else {
        u32 cat = idx < 4 ? 0 : idx < 8 ? 1 : idx == 0x27 ? 2 : 3;
        if (cat == 0) t = 7;
        else if (cat == 1) t = 8;
        else if (cat == 2) t = lo < 0xfe ? 0x1d : 0;
        else t = 0x1d;
      }
    }
    u32 k = t - 5;
    if (k > 0x18) break;
    u32 step;
    if (k == 0) step = 2;
    else if (k == 1) step = 3;
    else if (k == 2) step = 4;
    else if (k <= 16) break;
    else if (k <= 22) step = 2;
    else if (k == 23) break;
    else step = 2;
    p += step;
  }
  return (u32)(p - p0);
}

// 0x622bb0: cdecl(cvt, p) - scanUnits, big-endian unit order (high byte first)
static u32 __attribute__((cdecl)) scanBE_622bb0(const u8 *cvt, const u8 *p) { return scanUnits(cvt, p, true); }
PCREG(622bb0, scanBE_622bb0);

// 0x625b30: cdecl(cvt, p) - scanUnits, little-endian unit order (high byte second)
static u32 __attribute__((cdecl)) scanLE_625b30(const u8 *cvt, const u8 *p) { return scanUnits(cvt, p, false); }
PCREG(625b30, scanLE_625b30);

// 0x622310: cdecl(cvt, s1, s2) -> 0 or 1. Walks s1 by the unit classes of cvt[0x4c + byte] (class - 5: 0 -> 2 bytes, 1 -> 3, 2 -> 4,
// 17..22 and 24 -> 1; any other class ends the walk), requiring the same bytes in s2. At the end: 1 when *s1 == *s2, else the class of
// *s2 decides: out of range or one of the ending classes (k 3..16, 23) gives 1, a stepping class gives 0 (a prefix test).
static u32 __attribute__((cdecl)) matchPrefix_622310(const u8 *cvt, const u8 *s1, const u8 *s2) {
  for (;;) {
    u32 k = (u32)cvt[0x4c + *s1] - 5;
    u32 n = 0;
    if (k <= 0x18) {
      if (k == 0) n = 2;
      else if (k == 1) n = 3;
      else if (k == 2) n = 4;
      else if ((k >= 17 && k <= 22) || k == 24) n = 1;
    }
    if (!n) break;
    for (u32 j = 0; j < n; j++)
      if (s1[j] != s2[j]) return 0;
    s1 += n;
    s2 += n;
  }
  if (*s1 == *s2) return 1;
  u32 k2 = (u32)cvt[0x4c + *s2] - 5;
  if (k2 > 0x18) return 1;
  return (k2 >= 3 && k2 <= 16) || k2 == 23 ? 1 : 0;
}
PCREG(622310, matchPrefix_622310);
