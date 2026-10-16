// batch808.cpp - gap band 0x621000-0x641000 (docs/20-unclaimed-gap-621.md). Names are GUESS.
#include "ff.h"

// 0x62b290, cdecl(st, p, end, out) returns int.
static u32 __attribute__((cdecl)) scanTokB_62b290(const u8 *st, const u8 *p, const u8 *end, const u8 **out) {
  const u8 *tab = st + 0x4c;
  if (p == end) return 0xffffffffu;
  if ((u8)(tab[*p] - 0x18) > 1) {
    *out = p;
    return 0;
  }
  const u8 *q = p;
  for (;;) {
    q++;
    if (q == end) return 0xffffffffu;
    u8 k = tab[*q];
    if (k == 0x12) {
      *out = q + 1;
      return 10;
    }
    if ((u8)(k - 0x18) > 1) {
      *out = q;
      return 0;
    }
  }
}
PCREG(62b290, scanTokB_62b290);

// 0x62ad60, cdecl(st, p, end, out) returns int. A 'x' tail-calls 0x62b290 (same arguments moved forward by one byte).
static u32 __attribute__((cdecl)) scanTokA_62ad60(const u8 *st, const u8 *p, const u8 *end, const u8 **out) {
  const u8 *tab = st + 0x4c;
  if (p == end) return 0xffffffffu;
  if (*p == 0x78) return scanTokB_62b290(st, p + 1, end, out);
  if (tab[*p] != 0x19) {
    *out = p;
    return 0;
  }
  const u8 *q = p;
  for (;;) {
    q++;
    if (q == end) return 0xffffffffu;
    u8 k = tab[*q];
    if (k == 0x12) {
      *out = q + 1;
      return 10;
    }
    if (k != 0x19) {
      *out = q;
      return 0;
    }
  }
}
PCREG(62ad60, scanTokA_62ad60);
