#include "ff.h"
// batch1011.cpp - unclaimed-02 batch 11 (docs/20-unclaimed-02.md). Name from the GC name map (naming only).

// 0x438290, ZInputActions::ConvertScanCode(int) (high). Stdcall-like: one stack argument, returned in eax, no this.
// If the byte at (system interface +0x6e) is nonzero, returns the argument. Otherwise walks a table of 8-byte records
// that starts at 0x6e492c (key) with values at 0x6e4928 + 8k: when the key equals the argument, returns that record's
// value; the walk ends on a zero key, and then the argument is returned. The argument is also returned when the first key
// is negative (signed compare) or zero.
static u32 STDCALL inputActionsConvertScanCode(s32 arg) {
  u8 *sys = G(u8 *, 0x70039c);
  if (sys[0x6e] != 0)
    return (u32)arg;
  u32 edx = (u32)arg;
  u32 eax = G(u32, 0x6e492c);
  u32 ecx = 0;
  if ((s32)eax > (s32)edx || eax == 0)
    return edx;
  for (;;) {
    if (eax == edx)
      return G(u32, 0x6e4928 + ecx * 8);
    eax = G(u32, 0x6e4934 + ecx * 8);
    ++ecx;
    if (eax == 0)
      return edx;
  }
}
PCREG(438290, inputActionsConvertScanCode);
