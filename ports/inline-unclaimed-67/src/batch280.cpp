// batch280.cpp - unclaimed area 67, gap band: a counted-table index with a hook fallback.
#include "ff.h"

static inline u32 rdw(u32 p, u32 off) { return *(u32 *)(unsigned long)(p + off); }

// 0x5f4ec0, thiscall, ret 4 (arg k): esi = count - k; in range (unsigned esi-1 < count) returns base + 8*esi - 8; otherwise
// calls the hook at 0x7003b0 and returns its eax. A null hook traps in the original (int3), which the port does too.
static u32 THISCALL indexCounted4ec0(u8 *selfP, u32 k) {
  u32 self = (u32)(unsigned long)selfP;
  u32 cnt = rdw(self, 8);
  u32 esi = cnt - k;
  if ((u32)(esi - 1) < cnt)
    return rdw(self, 0) + esi * 8 - 8;
  u32 hook = *(u32 *)0x7003b0;
  if (hook == 0)
    __builtin_trap();
  return ((u32(*)(void))(unsigned long)hook)();
}
PCREG(5f4ec0, indexCounted4ec0);
