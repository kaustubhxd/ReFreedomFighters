#include "ff.h"
// batch2726.cpp - unclaimed-27 batch 26 (gap band; docs/20-unclaimed-27.md). Name unknown (GUESS).
// The original's SEH frame is not ported: the harness has no exceptions. Tagged.
// 0x54f870 is original code (bound by build.sh): stdcall, two arguments (begin, size), ret 8.
extern "C" void STDCALL ext_54f870(u32 begin, u32 size);

// 0x5855c0 (GUESS): thiscall, no arguments, void. n = (dword at this+8 - dword at this+0) / 72 (signed, truncating); when n is
// nonzero, calls 0x54f870(begin, 72 * n).
static void THISCALL funcReleaseBy72(u8 *self) {
  u32 begin = *(u32 *)(self + 0);
  s32 diff = (s32)(*(u32 *)(self + 8) - begin);
  s32 n = diff / 72;
  if (n != 0) ext_54f870(begin, (u32)(n * 72));
}
PCREG(5855c0, funcReleaseBy72);
