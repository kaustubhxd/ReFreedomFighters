// batch38015.cpp - cascade s8 batch 38015: 0x40ceb0 (mixed-radix pass driver: one butterfly pass per factor).
#include "ff.h"

extern "C" void ext_40d690(s32 a, s32 b, s32 c, s32 d, u32 e, u32 f, u32 g, u32 h, u32 i, u32 j);   // cdecl, 10 args
extern "C" void ext_40d060(s32 a, s32 b, u32 c, u32 d, u32 e);                                    // cdecl, 5 args
extern "C" void ext_40d220(s32 a, s32 b, u32 c, u32 d, u32 e, u32 f, u32 g);                      // cdecl, 7 args

// 0x40ceb0, cdecl(n, buf1, buf2, work, plan): plan[1] = factor count k, plan[2..k+1] = factors. Walks the factors from the last to the first; for each, with m = X/f (X starts at n,
// then the previous m; the fourth argument of the radix-n pass is q*m) and stride q = n/X, runs the matching pass (radix 4 -> 0x40d220, radix 2 -> 0x40d060, else 0x40d690), alternating the roles of buf1 / buf2 through a
// ping-pong flag; the work pointer is advanced by the running offset. When the last pass left the data in buf2 it is copied back into buf1.
static void fn40ceb0(s32 n, u32 b1, u32 b2, u32 work, s32 *plan) {
  s32 count = plan[1];
  if (count <= 0) return;
  s32 T = 1;
  s32 *Y = plan + count + 1;
  s32 Xs = n;
  s32 X0 = n;
  do {
    s32 f = *Y;
    s32 m = X0 / f;
    s32 q = n / X0;
    Xs = Xs - (f - 1) * q;
    T = 1 - T;
    if (f == 4) {
      u32 p0 = work + (u32)Xs * 4 - 4;
      u32 p1 = work + (u32)(Xs + q) * 4 - 4;
      u32 p2 = work + (u32)(Xs + 2 * q) * 4 - 4;
      if (T == 0) ext_40d220(q, m, b1, b2, p0, p1, p2);
      else ext_40d220(q, m, b2, b1, p0, p1, p2);
    } else if (f == 2) {
      u32 p = work + (u32)Xs * 4 - 4;
      if (T == 0) ext_40d060(q, m, b1, b2, p);
      else ext_40d060(q, m, b2, b1, p);
    } else {
      if (q == 1) T = q - T;
      u32 p = work + (u32)Xs * 4 - 4;
      if (T == 0) {
        ext_40d690(q, f, m, q * m, b1, b1, b1, b2, b2, p);
        T = 1;
      } else {
        ext_40d690(q, f, m, q * m, b2, b2, b2, b1, b1, p);
        T = 0;
      }
    }
    Y--;
    count--;
    X0 = m;
  } while (count != 0);
  if (T != 1 && n > 0) {
    for (s32 i = 0; i < n; i++) ((u32 *)b1)[i] = ((u32 *)b2)[i];
  }
}
PCREG(40ceb0, fn40ceb0);
