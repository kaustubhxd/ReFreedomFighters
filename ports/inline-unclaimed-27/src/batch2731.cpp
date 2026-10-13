#include "ff.h"
// batch2731.cpp - unclaimed-27 batch 33 (docs/20-unclaimed-27.md). FUN_589840, name unknown (GUESS). The exe's SEH frame is not
// reproduced (tagged; no exceptions in the harness). Its callees are hooked in the spec (stubs, NOT verified).
extern "C" void STDCALL ext_54f870(u32 begin, u32 size);
extern "C" void ext_634273(u8 *p, u32 size);   // CRT free, cdecl: the caller cleans (two arguments)

// 0x589840 (GUESS): thiscall, one argument (flags), ret 4, returns this.
static u8 *THISCALL funcResetAndRelease(u8 *self, u32 flags) {
  *(u32 *)(self + 0) = 0x6abbccu;
  u8 *c = self + 0x4a0;
  u32 begin = *(u32 *)(c + 0);
  s32 n = ((s32)(*(u32 *)(c + 8) - begin)) >> 2;
  if (n != 0) ext_54f870(begin, (u32)n << 2);
  if (flags & 1u) ext_634273(self, 0xab9u);
  return self;
}
PCREG(589840, funcResetAndRelease);
