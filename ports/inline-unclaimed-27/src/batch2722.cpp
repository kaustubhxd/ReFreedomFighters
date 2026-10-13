#include "ff.h"
// batch2722.cpp - unclaimed-27 batch 22 (gap band; docs/20-unclaimed-27.md). Name unknown (GUESS).
// The original's SEH frame (fs:[0] record, cookie) is not ported: the harness has no exceptions. Tagged.
// 0x63418c is original code (bound by build.sh): stdcall with four arguments (pointer, size, count, function), ret 0x10.
extern "C" void STDCALL ext_63418c(u32 p, u32 size, u32 count, u32 fn);

// 0x5895b0 (GUESS): thiscall, no arguments, void, ret 0. Calls 0x63418c(this+4, 0xf4, 0x20, 0x4690b0).
static void THISCALL funcArrayHelper(u8 *self) {
  ext_63418c((u32)(unsigned long)(self + 4), 0xf4u, 0x20u, 0x4690b0u);
}
PCREG(5895b0, funcArrayHelper);
