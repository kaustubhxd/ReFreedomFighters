// batch1035.cpp - unclaimed-04 batch 35 (docs/20-unclaimed-04.md): two pure pattern-pair matchers (cdecl, three pointers).
#include "ff.h"

// 0x622b70: pairs (0, c): s[0] must be 0 and s[1] must be the pattern byte; result is (s == e) when the pattern ends.
// four stack arguments: the first is not read (the exe reads [ebp+0xc], [ebp+0x10] and [ebp+0x14])
static u32 __attribute__((cdecl)) unk622b70PairZeroFirst(u32 unused, const u8 *s, const u8 *e, const u8 *p) {
  (void)unused;
  u8 al = *p;
  if (al == 0) return s == e;
  for (;;) {
    if (s == e) return 0;
    if (s[0] != 0) return 0;
    if (s[1] != al) return 0;
    al = p[1];
    p++;
    s += 2;
    if (al == 0) break;
  }
  return s == e;
}
PCREG(622b70, unk622b70PairZeroFirst);

// 0x625af0: pairs (c, 0): s[1] must be 0 and s[0] must be the pattern byte; result is (s == e) when the pattern ends.
static u32 __attribute__((cdecl)) unk625af0PairZeroSecond(u32 unused, const u8 *s, const u8 *e, const u8 *p) {
  (void)unused;
  u8 al = *p;
  if (al == 0) return s == e;
  for (;;) {
    if (s == e) return 0;
    if (s[1] != 0) return 0;
    if (s[0] != al) return 0;
    al = p[1];
    p++;
    s += 2;
    if (al == 0) break;
  }
  return s == e;
}
PCREG(625af0, unk625af0PairZeroSecond);
