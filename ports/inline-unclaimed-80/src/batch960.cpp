#include "ff.h"
// batch960.cpp - unclaimed-80 gap band (docs/20-unclaimed-80.md): 0x428870 (high). Thiscall with one stack argument n, ret 4, returns al.
// If [self+0xd] == 0 return 0. Otherwise loop: o = [self+0xd]; ecx = [o]; hr = call [ecx+0x1c] with ecx and one stack argument o (callee-cleaned).
// If hr is 0x8007001e or 0x8007000c: ecx = esi; esi = esi - 1; if ecx != 0 go round again (esi starts at n). After the loop, if hr is not a
// retry code set the byte at self+0x45 to 1. Return 1.

typedef u32(THISCALL *tc1)(u8 *, u32);

static u8 THISCALL zg428870(u8 *self, u32 n) {
  if (*(u32 *)(self + 0xd) == 0) return 0;
  u32 esi = n;
  u32 hr;
  for (;;) {
    u8 *o = *(u8 **)(self + 0xd);
    u32 ecxv = *(u32 *)o;
    hr = ((tc1)(*(u32 *)(ecxv + 0x1c)))((u8 *)ecxv, (u32)o);
    if (hr == 0x8007001e || hr == 0x8007000c) {
      u32 ecx = esi;
      esi = esi - 1;
      if (ecx != 0) continue;
    }
    break;
  }
  if (hr != 0x8007001e && hr != 0x8007000c) *(u8 *)(self + 0x45) = 1;
  return 1;
}
PCREG(428870, zg428870);
