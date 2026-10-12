// batch290.cpp - unclaimed area 67, gap band: store the low byte of v into the record, or call the hook.
#include "ff.h"

static inline u32 rdw(u32 p, u32 off) { return *(u32 *)(unsigned long)(p + off); }

// 0x5f1b90, thiscall, ret 4 (argument v). See docs/20-unclaimed-67.md batch 290.
static u32 THISCALL storeByteOrHook1b90(u8 *selfP, u32 v) {
  u32 self = (u32)(unsigned long)selfP;
  u32 holder = rdw(self, 0xc);
  u32 o = rdw(holder, 0);
  if (o != 0) {
    *(u8 *)(unsigned long)(o + 0x18) = (u8)v;
    return (holder & 0xffffff00u) | (v & 0xffu);
  }
  u32 hook = *(u32 *)0x7003b0;
  if (hook == 0)
    __builtin_trap();
  return ((u32(*)(u32))(unsigned long)hook)(v);
}
PCREG(5f1b90, storeByteOrHook1b90);
