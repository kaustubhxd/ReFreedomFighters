// batch214.cpp - unclaimed area 20 (docs/20-unclaimed-20.md), slice floor(addr/16) mod 20 == 19. A pure function (no calls):
// a sum over a byte buffer of length n: the first n/4 dwords, then the signed bytes after them, plus n (mod 2^32).
#include "ff.h"

typedef int i32;
typedef signed char i8;

// 0x4d8db0, stdcall(p, n): cnt = n >> 2 (arithmetic). result = n + sum of the dwords p[0..cnt-1] + sum of the signed bytes
// p[4*cnt .. n-1] (mod 2^32). The original's SSE loop and scalar tail give this sum. Contract: n >= 0; for negative n the
// original reads outside p without a check (not a defined input), so the spec does not generate it. Name GUESS.
static u32 STDCALL sumDwordsAndBytes_4d8db0(const u8 *p, i32 n) {
  i32 cnt = n >> 2;
  u32 s = (u32)n;
  for (i32 i = 0; i < cnt; ++i) s += *(const u32 *)(p + 4 * i);
  for (i32 k = 4 * cnt; k < n; ++k) s += (u32)(i32)(i8)p[k];
  return s;
}
PCREG(4d8db0, sumDwordsAndBytes_4d8db0);
