#include "ff.h"
// batch2724.cpp - unclaimed-27 batch 24 (gap band; docs/20-unclaimed-27.md). Name unknown (GUESS).
// The original's SEH frame is not ported: the harness has no exceptions. Tagged.
// 0x54f870 is original code (bound by build.sh): stdcall, two arguments, ret 8.
extern "C" void STDCALL ext_54f870(u32 begin, u32 size);

// 0x5896b0 (GUESS): thiscall, no arguments, void. Stores the vtable 0x6abbcc at this+0. Then, for c = this+0x4a0: n = (dword at
// c+8 - dword at c) >> 2 (signed); when n is nonzero, calls 0x54f870(begin, n << 2).
static void THISCALL funcStoreVtableAndRelease(u8 *self) {
  *(u32 *)(self + 0) = 0x6abbccu;
  u8 *c = self + 0x4a0;
  u32 begin = *(u32 *)(c + 0);
  s32 n = ((s32)(*(u32 *)(c + 8) - begin)) >> 2;
  if (n != 0) ext_54f870(begin, (u32)n << 2);
}
PCREG(5896b0, funcStoreVtableAndRelease);
