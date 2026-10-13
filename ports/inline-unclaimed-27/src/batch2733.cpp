#include "ff.h"
// batch2733.cpp - unclaimed-27 batch 35 (docs/20-unclaimed-27.md). FUN_598cf0, name unknown (GUESS). SEH frame not reproduced (tagged).
// 0x598a50 is hooked in the spec (stub, NOT verified). 0x4690b0 is exe code (cdecl, plain ret; hooked in the spec to record its args).
extern "C" void THISCALL ext_598a50(u8 *self);
extern "C" void ext_4690b0(u8 *p, u32 line);

// 0x598cf0 (GUESS): thiscall, one argument (flags), ret 4, returns this.
static u8 *THISCALL funcCallAndAssertB(u8 *self, u32 flags) {
  ext_598a50(self);
  if (flags & 1u) {
    if (flags & 4u) {
      ext_4690b0(self, 0x22e7u);
    } else {
      void (*hook)(void) = (void (*)(void))(unsigned long)G(u32, 0x7003b0);
      if (hook) hook();   // the exe traps (int3) when the hook is null; the spec never sets it null
    }
  }
  return self;
}
PCREG(598cf0, funcCallAndAssertB);
