// batch288.cpp - unclaimed area 67, gap band: optional back-link, then the 0x5fb910 store through the object at [[this+0xc]+4].
#include "ff.h"

static inline u32 rdw(u32 p, u32 off) { return *(u32 *)(unsigned long)(p + off); }
static inline void wrw(u32 p, u32 off, u32 v) { *(u32 *)(unsigned long)(p + off) = v; }

// 0x5f1780, thiscall, ret 4 (arg a). See docs/20-unclaimed-67.md batch 288.
static void THISCALL linkThenStore1780(u8 *selfP, u32 a) {
  u32 self = (u32)(unsigned long)selfP;
  u32 o1 = rdw(self, 0xc);
  u32 o2 = rdw(o1, 4);
  if (a != 0)
    wrw(a, 4, o2);
  wrw(o2, 0x30, a);
}
PCREG(5f1780, linkThenStore1780);
