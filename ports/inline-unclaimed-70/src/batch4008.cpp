// batch4008.cpp - area 70 (residue 9), batch 4008: 0x440f10 (five stack args, ECX unused; calls the render manager's slot 0x58
// (GUESS stub) and, when that is non-null, the exe's 0x65f4b0 (plain `ret 0x14`, so a no-op) with the five arguments).
#include "ff.h"

extern "C" void THISCALL ext_65f4b0(u8 *self, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5);   // exe: ret 0x14, no effect

static inline u8 *renderManager() { return *(u8 **)(G(u8 *, 0x70039c) + 0x9b); }

// 0x440f10 (name GUESS): stdcall (five dword args, callee pops 0x14), returns al. r = slot 0x58 of the render manager with
// the dword at its +0x14; when r is null, returns 0; otherwise calls 0x65f4b0(r, a1..a5) and returns 1.
static u8 STDCALL callRenderSlot58(u32 a1, u32 a2, u32 a3, u32 a4, u32 a5) {
  u8 *rm = renderManager();
  u8 *r = vcall<u8 *>(rm, 0x58, *(u32 *)(rm + 0x14));
  if (!r)
    return 0;
  ext_65f4b0(r, a1, a2, a3, a4, a5);
  return 1;
}
PCREG(440f10, callRenderSlot58);
