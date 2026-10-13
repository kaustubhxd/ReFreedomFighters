#include "ff.h"
// batch2739.cpp - unclaimed-27 batch 41 (docs/20-unclaimed-27.md). FUN_581200, name unknown (GUESS). SEH frame not reproduced (tagged).
// 0x469870 is hooked in the spec (thiscall, no args; stub, NOT verified). The engine slot +0x114 (four stack arguments, callee cleans,
// ret 0x10) is a stub in the spec.
extern "C" void THISCALL ext_469870(u8 *self);
typedef u32(THISCALL * slot114_fn)(u8 *, u32, u32, u32, u32);

// 0x581200 (GUESS): thiscall, no arguments, returns this.
static u8 *THISCALL funcInitWordsFromEngine(u8 *self) {
  ext_469870(self);
  *(u32 *)(self + 4) |= 0x20u;
  *(u32 *)(self + 0x44) = 0;
  *(u32 *)(self + 0) = 0x6ab540u;
  *(u32 *)(self + 0x5e) = 0;

  u8 *g = (u8 *)(unsigned long)G(u32, 0x70039c);
  u8 *eng = *(u8 **)(g + 0x9b);
  u32 r1 = ((slot114_fn)(*(u32 *)(*(u32 *)eng + 0x114)))(eng, 0x69eaacu, 0u, 0x6ab6d4u, 0x109u);
  G(u16, 0x714288) = (u16)r1;

  g = (u8 *)(unsigned long)G(u32, 0x70039c);
  eng = *(u8 **)(g + 0x9b);
  u32 r2 = ((slot114_fn)(*(u32 *)(*(u32 *)eng + 0x114)))(eng, 0x692b00u, 0u, 0x6ab6d4u, 0x10au);
  G(u16, 0x71428c) = (u16)r2;
  return self;
}
PCREG(581200, funcInitWordsFromEngine);
