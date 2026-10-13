#include "ff.h"
// batch2713.cpp - unclaimed-27 batch 13 (docs/20-unclaimed-27.md). FUN_466c00: GUESS name (no GC name), owner unknown.

// 0x466c00 (GUESS): thiscall, no arguments, void, ret 0. Calls vtable slot +0x2b4 with the constant 0x17 (one argument;
// the callee cleans, the caller does not).
static void THISCALL funcCallSlot2b4With17(u8 *self) {
  typedef void(THISCALL * slot2b4_fn)(u8 *, u32);
  ((slot2b4_fn)(*(u32 *)(*(u32 *)self + 0x2b4)))(self, 0x17u);
}
PCREG(466c00, funcCallSlot2b4With17);
