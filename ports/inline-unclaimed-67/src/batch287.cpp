// batch287.cpp - unclaimed area 67, gap band: pop a float record (result in st0); hook when empty.
#include "ff.h"

typedef float (THISCALL *FloatHook)(void);
static inline u32 rdw(u32 p, u32 off) { return *(u32 *)(unsigned long)(p + off); }

// 0x5f5020, thiscall, plain ret, float result in st0. See docs/20-unclaimed-67.md batch 287.
static float THISCALL popFloat5020(u8 *selfP) {
  u32 self = (u32)(unsigned long)selfP;
  u32 n = rdw(self, 8);
  if (n == 0) {
    u32 hook = *(u32 *)0x7003b0;
    if (hook == 0)
      __builtin_trap();
    return ((FloatHook)(unsigned long)hook)();
  }
  n -= 1;
  *(u32 *)(selfP + 8) = n;
  u32 base = rdw(self, 0);
  float v = *(float *)(unsigned long)(base + n * 8);
  *(u8 *)(unsigned long)(base + n * 8 + 4) = 0;
  return v;
}
PCREG(5f5020, popFloat5020);
