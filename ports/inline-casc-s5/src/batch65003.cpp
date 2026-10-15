#include "ff.h"

// 0x4045a0 vorbis psy seed_chase(seeds, linesper, n) (libvorbis psy.c): stack of falling seeds (overlapping
// ones popped), then each stack entry fills the seeds up to the next rise or linesper past it. x87 compares:
// unordered counts as "less" in the push test and as "<=" in the pop test.
static void f4045a0(float *seeds, s32 lp, s32 n) {
  s32 *ps = (s32 *)__builtin_alloca(n * 4);
  u32 *as = (u32 *)__builtin_alloca(n * 4);
  s32 st = 0;
  for (s32 i = 0; i < n; i++) {
    if (st >= 2) {
      for (;;) {
        if (!(seeds[i] >= bitsf(as[st - 1]))) break;
        if (i >= ps[st - 1] + lp) break;
        if (st <= 1) break;
        if (bitsf(as[st - 1]) > bitsf(as[st - 2])) break;
        if (i >= ps[st - 2] + lp) break;
        st--;
      }
    }
    ps[st] = i;
    as[st] = *(u32 *)&seeds[i];
    st++;
  }
  s32 pos = 0;
  for (s32 i = 0; i < st; i++) {
    s32 end;
    if (i < st - 1 && bitsf(as[i + 1]) > bitsf(as[i])) end = ps[i + 1];
    else end = ps[i] + lp + 1;
    if (end > n) end = n;
    for (; pos < end; pos++) *(u32 *)&seeds[pos] = as[i];
  }
}
PCREG(4045a0, f4045a0);
