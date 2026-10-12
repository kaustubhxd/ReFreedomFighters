// batch289.cpp - unclaimed area 67, gap band: tail call slot 0x28 of a stack object argument with argument 1.
#include "ff.h"

typedef u32 (THISCALL *F1)(u8 *self, u32 a);
static inline u32 rdw(u32 p, u32 off) { return *(u32 *)(unsigned long)(p + off); }

// 0x5f17b0, stdcall (ret 4, one argument a). See docs/20-unclaimed-67.md batch 289.
static u32 STDCALL tailSlot28(u32 a) {
  if (a == 0)
    return 0;
  return ((F1)rdw(rdw(a, 0), 0x28))((u8 *)(unsigned long)a, 1);
}
PCREG(5f17b0, tailSlot28);
