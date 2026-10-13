#include "ff.h"
// batch2737.cpp - unclaimed-27 batch 39 (docs/20-unclaimed-27.md). FUN_589600, name unknown (GUESS). SEH frame not reproduced (tagged).
// 0x63418c (stdcall, four arguments, ret 0x10) and 0x54f870 (stdcall, two arguments, ret 8) are hooked in the spec (stubs, NOT verified).
extern "C" void STDCALL ext_63418c(u32 p, u32 size, u32 count, u32 fn);
extern "C" void STDCALL ext_54f870(u32 begin, u32 size);

// 0x589600 (GUESS): thiscall, no arguments, void.
static void THISCALL funcArrayRelease(u8 *self) {
  *(u32 *)(self + 0) = 0x6abbdcu;
  ext_63418c((u32)(unsigned long)(self + 0xd91), 0xf4u, 0x20u, 0x4690b0u);
  u32 b1 = *(u32 *)(self + 0xb55);
  s32 n1 = ((s32)(*(u32 *)(self + 0xb5d) - b1)) >> 6;
  if (n1 != 0) ext_54f870(b1, (u32)n1 << 6);
  *(u32 *)(self + 0) = 0x6abbccu;
  u32 b2 = *(u32 *)(self + 0x4a0);
  s32 n2 = ((s32)(*(u32 *)(self + 0x4a8) - b2)) >> 2;
  if (n2 != 0) ext_54f870(b2, (u32)n2 << 2);
}
PCREG(589600, funcArrayRelease);
