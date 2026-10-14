// batch36081.cpp - cascade s4 batch 36081: 0x630dd0 (tier F row).
#include "ff.h"

// 0x630dd0, cdecl(a, p, n): p is an array of 4-byte entries whose u16 at +2 is a symbol; n is signed.
// p[n + 1] gets the sentinel 0xffff; n < 0 -> done. Otherwise n + 1 steps of a run-length statistics pass over the symbols s[0..n]:
// limit/min start 7/4 (0x8a/3 when s[0] is 0); run length r counts equal neighbours while r < limit; at a run end (symbol cur, next symbol nx):
// r < min -> a.h[0xa74 + cur * 4] += r; else when cur != 0 -> (cur != prev run symbol: a.h[0xa74 + cur * 4]++), a.h[0xab4]++;
// else (cur == 0) r <= 10 -> a.h[0xab8]++ else a.h[0xabc]++. Then r = 0, prev = cur; nx == 0 -> limit 0x8a, min 3; nx == cur -> 6 / 3; else 7 / 4.
extern "C" void fn630dd0(u8 *a, u8 *p, s32 n) {
  s32 v0 = *(u16 *)(p + 2);
  *(u16 *)(p + n * 4 + 6) = 0xffff;
  s32 limit = v0 ? 7 : 0x8a;
  s32 mn = (v0 != 0) + 3;
  s32 prev = -1;
  if (n < 0) return;
  u8 *q = p + 6;
  s32 left = n + 1;
  s32 r = 0;
  s32 nx = v0;
  do {
    s32 cur = nx;
    r++;
    nx = *(u16 *)q;
    if (!(r < limit && cur == nx)) {
      if (r < mn) {
        *(u16 *)(a + 0xa74 + cur * 4) += (u16)r;
      } else if (cur != 0) {
        if (cur != prev) (*(u16 *)(a + 0xa74 + cur * 4))++;
        (*(u16 *)(a + 0xab4))++;
      } else if (r <= 10) {
        (*(u16 *)(a + 0xab8))++;
      } else {
        (*(u16 *)(a + 0xabc))++;
      }
      r = 0;
      prev = cur;
      if (nx == 0) {
        limit = 0x8a;
        mn = 3;
      } else if (cur == nx) {
        limit = 6;
        mn = 3;
      } else {
        limit = 7;
        mn = 4;
      }
    }
    q += 4;
    left--;
  } while (left != 0);
}
PCREG(630dd0, fn630dd0);
