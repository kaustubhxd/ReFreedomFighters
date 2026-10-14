// batch38028.cpp - cascade s8 batch 38028: 0x40e270 (mixed-radix pass driver, forward factor order; sibling of 0x40ceb0).
#include "ff.h"

extern "C" void ext_40eda0(s32 a, s32 b, s32 c, s32 d, u32 e, u32 f, u32 g, u32 h, u32 i, u32 j);   // cdecl, 10 args (generic radix)
extern "C" void ext_40e5e0(s32 a, s32 b, u32 c, u32 d, u32 e, u32 f);                              // cdecl, 6 args (radix 3)
extern "C" void ext_40e430(s32 a, s32 b, u32 c, u32 d, u32 e);                                      // cdecl, 5 args (radix 2)
extern "C" void ext_40e8b0(s32 a, s32 b, u32 c, u32 d, u32 e, u32 f, u32 g);                       // cdecl, 7 args (radix 4)

// 0x40e270, cdecl(n, buf1, buf2, work, plan): plan[1] = factor count k, plan[2..k+1] = factors, processed from the FIRST to the last. With stride q (starts at 1) and factor f the pass
// size is m = n / (f*q); radix 4 -> 0x40e8b0, 3 -> 0x40e5e0, 2 -> 0x40e430, anything else -> 0x40eda0 (which also gets q*m; its toggle only flips the buffers when m == 1). The ping-pong
// flag T starts at 0 and decides which of buf1 / buf2 is source or destination; the work pointer is advanced by the running offset (starts at 1, += (f-1)*m). When T is set afterwards the
// n dwords of buf2 are copied back into buf1.
static void fn40e270(s32 n, u32 b1, u32 b2, u32 work, s32 *plan) {
  s32 count = plan[1];
  if (count <= 0) return;
  s32 T = 0;
  s32 *Y = plan + 2;
  s32 Xs = 1;
  s32 q = 1;
  do {
    s32 f = *Y;
    s32 s2 = f * q;
    s32 m = n / s2;
    s32 mq = m * q;
    if (f == 4) {
      u32 p0 = work + (u32)Xs * 4 - 4;
      u32 p1 = work + (u32)(Xs + m) * 4 - 4;
      u32 p2 = work + (u32)(Xs + 2 * m) * 4 - 4;
      if (T != 0) ext_40e8b0(m, q, b2, b1, p0, p1, p2);
      else ext_40e8b0(m, q, b1, b2, p0, p1, p2);
      T = 1 - T;
    } else if (f == 2) {
      u32 p = work + (u32)Xs * 4 - 4;
      if (T != 0) ext_40e430(m, q, b2, b1, p);
      else ext_40e430(m, q, b1, b2, p);
      T = 1 - T;
    } else if (f == 3) {
      u32 p1 = work + (u32)Xs * 4 - 4;
      u32 p2 = work + (u32)(m + Xs) * 4 - 4;
      if (T != 0) ext_40e5e0(m, q, b2, b1, p1, p2);
      else ext_40e5e0(m, q, b1, b2, p1, p2);
      T = 1 - T;
    } else {
      u32 p = work + (u32)Xs * 4 - 4;
      if (T != 0) ext_40eda0(m, f, q, mq, b2, b2, b2, b1, b1, p);
      else ext_40eda0(m, f, q, mq, b1, b1, b1, b2, b2, p);
      if (m == 1) T = 1 - T;
    }
    Xs += (f - 1) * m;
    Y++;
    q = s2;
    count--;
  } while (count != 0);
  if (T != 0 && n > 0) {
    for (s32 i = 0; i < n; i++) ((u32 *)b1)[i] = ((u32 *)b2)[i];
  }
}
PCREG(40e270, fn40e270);
