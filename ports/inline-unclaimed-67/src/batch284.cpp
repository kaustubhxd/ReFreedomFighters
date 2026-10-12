// batch284.cpp - unclaimed area 67, gap band: range search over a linked list; hook fallback.
#include "ff.h"

typedef u32 (*HookFn)(void);
static inline u32 rdw(u32 p, u32 off) { return *(u32 *)(unsigned long)(p + off); }

// 0x5f4990, thiscall, plain ret. See docs/20-unclaimed-67.md batch 284.
static u32 THISCALL rangeSearch4990(u8 *selfP) {
  u32 self = (u32)(unsigned long)selfP;
  u32 e = rdw(self, 0x96);
  if (e != 0) {
    u32 d = rdw(self, 0xa6);
    for (;;) {
      if (!(rdw(e, 0x54) > d)) {
        if (rdw(e, 0x58) > d)
          return d + (rdw(e, 0x48) - rdw(e, 0x54));
      }
      e = rdw(e, 0x9c);
      if (e == 0)
        break;
    }
  }
  u32 hook = *(u32 *)0x7003b0;
  if (hook == 0)
    __builtin_trap();
  return ((HookFn)(unsigned long)hook)();
}
PCREG(5f4990, rangeSearch4990);
