// batch799.cpp - gap band 0x621000-0x641000 (docs/20-unclaimed-gap-621.md). Names are GUESS.
#include "ff.h"

// 0x622270, cdecl(unused, p, end) returns int: classifies a token of length end - p.
static u32 __attribute__((cdecl)) tokenCode_622270(u32 unused, const u8 *p, const u8 *end) {
  (void)unused;
  u32 n = (u32)(end - p);
  if (n == 2) {
    if (p[1] != 't') return 0;
    if (p[0] == 'g') return 0x3eu;
    if (p[0] == 'l') return 0x3cu;
    return 0;
  }
  if (n == 3) {
    if (p[0] == 'a' && p[1] == 'm' && p[2] == 'p') return 0x26u;
    return 0;
  }
  if (n == 4) {
    if (p[0] == 'a') return (p[1] == 'p' && p[2] == 'o' && p[3] == 's') ? 0x27u : 0u;
    if (p[0] == 'q') return (p[1] == 'u' && p[2] == 'o' && p[3] == 't') ? 0x22u : 0u;
    return 0;
  }
  return 0;
}
PCREG(622270, tokenCode_622270);

// 0x6228a0, cdecl(unused, s, end, pat) returns 0 or 1: pat must match s exactly up to end.
static u32 __attribute__((cdecl)) matchToEnd_6228a0(u32 unused, const u8 *s, const u8 *end, const u8 *pat) {
  (void)unused;
  if (*pat == 0) return s == end ? 1u : 0u;
  const u8 *q = s;
  u32 k = 0;
  for (;;) {
    if (q == end) return 0;
    if (*q != pat[k]) return 0;
    q++;
    k++;
    if (pat[k] == 0) return q == end ? 1u : 0u;
  }
}
PCREG(6228a0, matchToEnd_6228a0);
