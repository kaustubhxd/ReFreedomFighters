// batch291.cpp - unclaimed area 67: 0x5f49e0, helper of 0x5fc260 (thiscall, plain ret).
#include "ff.h"

extern "C" u32 ext_5fa630(void);   // getter for the global at 0x724270, original code (plain ret)

typedef u32 (THISCALL *F1)(u8 *self, u32 a);
static inline u32 rdw(u32 p, u32 off) { return *(u32 *)(unsigned long)(p + off); }

// 0x5f49e0, thiscall, plain ret. See docs/20-unclaimed-67.md batch 291.
static u32 THISCALL callVslot1c(u8 *selfP) {
  u32 self = (u32)(unsigned long)selfP;
  u32 g = ext_5fa630();
  u32 arg = rdw(self, 0x24);
  return ((F1)rdw(rdw(g, 0), 0x1c))((u8 *)(unsigned long)g, arg);
}
PCREG(5f49e0, callVslot1c);
