// batch35063.cpp - cascade s5 batch 35063: 0x405f20 (GUESS table-driven automaton step: look up the start state, then follow transitions).
#include "ff.h"

extern "C" s32 ext_410cf0(u32 a, u32 b);   // cdecl, two args
extern "C" void ext_410db0(u32 a, u32 b);  // cdecl, two args
extern "C" s32 ext_410ec0(u32 a);          // cdecl, one arg

// 0x405f20, cdecl(a, b) returns EAX. T = [a+0x14] with tables [0], [4] (indexed by the start index), [8] (key), [0xc], [0x10] (transitions). r = 0x410cf0(b, T[8]); r >= 0: s = T[0][r], 0x410db0(b, T[4][r]),
// and a state s <= 0 returns -s at once; r < 0 starts with s = 0. Then loop while s > 0 (signed): c = 0x410ec0(b); -1 returns -1; c == 0 gives s = T[0xc][s], c == 1 gives s = T[0x10][s]. Returns -s.
static s32 fn405f20(u8 *a, u32 b) {
  u32 *T = *(u32 **)(a + 0x14);
  s32 s = 0;
  s32 r = ext_410cf0(b, T[2]);
  if (r >= 0) {
    s = ((s32 *)T[0])[r];
    ext_410db0(b, ((u32 *)T[1])[r]);
    if (s <= 0) return -s;
  }
  for (;;) {
    s32 c = ext_410ec0(b);
    if (c == -1) return -1;
    if (c == 0) s = ((s32 *)T[3])[s];
    else if (c == 1) s = ((s32 *)T[4])[s];
    if (s <= 0) return -s;
  }
}
PCREG(405f20, fn405f20);
