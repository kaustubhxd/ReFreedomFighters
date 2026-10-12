// batch281.cpp - unclaimed area 67, gap band: pop from an 8-byte record stack; hook when empty.
#include "ff.h"

typedef u32 (*HookFn)(void);
static inline u32 rdw(u32 p, u32 off) { return *(u32 *)(unsigned long)(p + off); }

// 0x5f4ff0, thiscall, plain ret: when the count is zero, tail-calls the hook at 0x7003b0 (a null hook traps in the original,
// which the port does too); otherwise pops: count -= 1, clears the byte at base + 8*count + 4 and returns the dword at base + 8*count.
static u32 THISCALL popRecord(u8 *selfP) {
  u32 self = (u32)(unsigned long)selfP;
  u32 n = rdw(self, 8);
  if (n == 0) {
    u32 hook = *(u32 *)0x7003b0;
    if (hook == 0)
      __builtin_trap();
    return ((HookFn)(unsigned long)hook)();
  }
  n -= 1;
  *(u32 *)(self + 8) = n;
  u32 base = rdw(self, 0);
  *(u8 *)(unsigned long)(base + n * 8 + 4) = 0;
  return *(u32 *)(unsigned long)(base + n * 8);
}
PCREG(5f4ff0, popRecord);
