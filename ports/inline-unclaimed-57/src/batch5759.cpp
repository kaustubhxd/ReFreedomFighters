// batch5759.cpp - unclaimed-57 (docs/20-unclaimed-57.md), batch 59: 0x5c7cb0 (GUESS name unnamed_5c7cb0), thiscall, one stack
// argument that the code never reads (ret 4), returns al = 1. Order: clear bit 0x40 of this+4; call the assert hook at 0x7003b0
// (the original falls to int3 when it is null; the spec always sets it, so that branch is not exercised); store the dword from
// 0x4e5ea0(NULL) at this+0x48; store the low word from 0x4e5e40(NULL) at this+0x4c. Both readers run through the hooks in the spec.
#include "ff.h"

extern "C" u32 THISCALL ext_4e5ea0(u8 *self);  // reader, original code (hooked in the spec: the original faults on a null ecx)
extern "C" u32 THISCALL ext_4e5e40(u8 *self);  // reader, original code (hooked in the spec)

// 0x5c7cb0, thiscall, one stack argument (unused), ret 4 (GUESS name)
static u8 THISCALL unnamed5c7cb0(u8 *self, u32 unused) {
  (void)unused;
  *(u32 *)(self + 4) &= 0xffffffbfu;
  u32 hook = G(u32, 0x7003b0);
  if (hook) ((void (*)(void))hook)();
  *(u32 *)(self + 0x48) = ext_4e5ea0(0);
  *(u16 *)(self + 0x4c) = (u16)ext_4e5e40(0);
  return 1;
}
PCREG(5c7cb0, unnamed5c7cb0);
