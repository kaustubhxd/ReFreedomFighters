// batch7070.cpp - area 73 batch 70 (gap band, tail-jump rows): FUN_4f3e50 and FUN_4f7ea0.
// Tail-jump rule: arity = the target's ret imm / 4. 0x43ff00 is `ret 0x14`, so five arguments. The target is outside the
// decompiled set and is called by address; the spec hooks it and logs the arguments.
#include "ff.h"

extern "C" void THISCALL ext_43ff00(u8 *self, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5);
extern "C" void THISCALL ext_4f9e00(u8 *self, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5);

// 0x4f3e50 (GUESS FUN_4f3e50): the fifth argument is set to 0, then the call continues in 0x43ff00.
static void THISCALL guess4f3e50(u8 *self, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5) {
  (void)a5;
  ext_43ff00(self, a1, a2, a3, a4, 0u);
}
PCREG(4f3e50, guess4f3e50);

// 0x4f7ea0 (GUESS FUN_4f7ea0): the fifth argument becomes 1 when it was non-zero, else 0; the call continues in the thunk 0x4f9e00.
static void THISCALL guess4f7ea0(u8 *self, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5) {
  u32 v = a5 != 0 ? 1u : 0u;
  ext_4f9e00(self, a1, a2, a3, a4, v);
}
PCREG(4f7ea0, guess4f7ea0);
