#include "ff.h"
// batch956.cpp - unclaimed-80 gap band (docs/20-unclaimed-80.md): 0x4288c0 and 0x428830 (high). Thiscall, no arguments, returns al.
// If [self+0xd] == 0 return 0. Otherwise loop: o = [self+0xd]; ecx = [o]; hr = call [ecx+0x1c] with ecx and one stack argument o (the
// callee cleans it); if hr is 0x8007001e or 0x8007000c, go round again; else set the byte flag (self+0x45 for 0x4288c0, self+0x1b1 for
// 0x428830) to 1 and return 1. The call is an indirect call through memory at ecx+0x1c, as in the exe.

typedef u32(THISCALL *tc1)(u8 *, u32);

static u8 THISCALL zgRetry4288c0(u8 *self) {
  if (*(u32 *)(self + 0xd) == 0) return 0;
  for (;;) {
    u8 *o = *(u8 **)(self + 0xd);
    u32 ecxv = *(u32 *)o;
    u32 hr = ((tc1)(*(u32 *)(ecxv + 0x1c)))((u8 *)ecxv, (u32)o);
    if (hr == 0x8007001e || hr == 0x8007000c) continue;
    *(u8 *)(self + 0x45) = 1;
    return 1;
  }
}
PCREG(4288c0, zgRetry4288c0);

static u8 THISCALL zgRetry428830(u8 *self) {
  if (*(u32 *)(self + 0xd) == 0) return 0;
  for (;;) {
    u8 *o = *(u8 **)(self + 0xd);
    u32 ecxv = *(u32 *)o;
    u32 hr = ((tc1)(*(u32 *)(ecxv + 0x1c)))((u8 *)ecxv, (u32)o);
    if (hr == 0x8007001e || hr == 0x8007000c) continue;
    *(u8 *)(self + 0x1b1) = 1;
    return 1;
  }
}
PCREG(428830, zgRetry428830);
