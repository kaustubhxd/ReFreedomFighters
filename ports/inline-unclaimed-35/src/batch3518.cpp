#include "ff.h"
// batch3518.cpp - area 35 claim 18 (docs/20-unclaimed-35.md): 0x5f3e20 (GUESS name). Thiscall, no args, ret 0.
// Stubbed in the harness: 0x5f5620 (thiscall, one arg; logged, returns a per-case eax).

extern "C" u32 THISCALL ext_5f5620(u8 *self, u32 a0);

// 0x5f3e20, GUESS FUN_5f3e20 (thiscall): calls 0x5f5620 with this and the dword at (the object at this+0x96)+0x38; stores the
// result at this+0xa6.
static void THISCALL guessCallStore(u8 *self) {
  u8 *o = *(u8 **)(self + 0x96);
  u32 a = *(u32 *)(o + 0x38);
  *(u32 *)(self + 0xa6) = ext_5f5620(self, a);
}
PCREG(5f3e20, guessCallStore);
