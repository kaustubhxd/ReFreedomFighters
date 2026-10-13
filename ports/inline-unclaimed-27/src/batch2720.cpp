#include "ff.h"
// batch2720.cpp - unclaimed-27 batch 20 (gap band; docs/20-unclaimed-27.md). Name unknown (GUESS).
// The SEH frame of the original (fs:[0] record and cookie) is not ported: the harness has no exceptions. Tagged.
// 0x54f870 is original code (bound by build.sh): stdcall, two arguments (begin, size), ret 8.
extern "C" void STDCALL ext_54f870(u32 begin, u32 size);

// 0x589560 (GUESS): thiscall, no arguments, void. n = (dword at this+8 - dword at this+0) >> 6 (signed arithmetic shift); when
// n is nonzero, calls 0x54f870(begin, n << 6).
static void THISCALL funcDestroyRange(u8 *self) {
  u32 begin = *(u32 *)(self + 0);
  s32 n = ((s32)(*(u32 *)(self + 8) - begin)) >> 6;
  if (n != 0) ext_54f870(begin, (u32)n << 6);
}
PCREG(589560, funcDestroyRange);
