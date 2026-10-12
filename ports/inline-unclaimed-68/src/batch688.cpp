// batch688.cpp - unclaimed-68 batch 8 (claim 7). Name: GUESS FUN_4cf1f0 (see docs/20-unclaimed-68.md).
#include "ff.h"

// Virtual slot +0x64 (thiscall, one argument, pointer in EAX).
typedef u8 *(THISCALL *VSlot64)(u8 *self, u32 arg);

// 0x4cf1f0 (GUESS): r = slot +0x64 (arg); returns 0 when r is null, else the dword at r. Thiscall, ret 4.
static u32 THISCALL guessFun4cf1f0(u8 *self, u32 arg) {
  u8 *r = ((VSlot64)*(u32 *)(*(u8 **)self + 0x64))(self, arg);
  if (!r) return 0;
  return *(u32 *)r;
}
PCREG(4cf1f0, guessFun4cf1f0);
