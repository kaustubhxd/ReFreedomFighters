// Port derived from inline-fresh-18 batch1812; strict verification by codex-u1.
#include "ff.h"
extern "C" void ext_4045a0(float*,s32,s32);
static inline bool ltu(float a, float b) { return !(a >= b); }   // C0 set: less or unordered
static inline bool equ(float a, float b) { return !(a < b || a > b); }
static void f404460(u8 *p, float *seed, float *flr) {
  s32 lp = *(s32 *)(p + 0x28);
  ext_4045a0(seed, lp, *(s32 *)(p + 0x2c));
  s32 pos = **(s32 **)(p + 0x18) - (lp >> 1) - *(s32 *)(p + 0x20);
  s32 lin = 0;
  if (*(s32 *)p > 1) {
    do {
      u32 mn = fbits(seed[pos]);
      s32 *oct = *(s32 **)(p + 0x18);
      s32 end = ((oct[lin + 1] + oct[lin]) >> 1) - *(s32 *)(p + 0x20);
      u32 lim = *(u32 *)(*(u8 **)(p + 4) + 0x7c);
      if (bitsf(mn) > bitsf(lim)) mn = lim;
      const float ni = G(float, 0x6be090);
      while (pos + 1 <= end) {
        pos++;
        float s = seed[pos];
        if ((s > ni && ltu(s, bitsf(mn))) || equ(bitsf(mn), ni)) mn = fbits(s);
      }
      s32 e2 = *(s32 *)(p + 0x20) + pos;
      for (; lin < *(s32 *)p && (*(s32 **)(p + 0x18))[lin] <= e2; lin++)
        if (ltu(flr[lin], bitsf(mn))) *(u32 *)&flr[lin] = mn;
    } while (lin + 1 < *(s32 *)p);
  }
  u32 mn = *(u32 *)&seed[*(s32 *)(p + 0x2c) - 1];
  for (; lin < *(s32 *)p; lin++)
    if (ltu(flr[lin], bitsf(mn))) *(u32 *)&flr[lin] = mn;
}
PCREG(404460, f404460);
