#include "ff.h"
// batch2732.cpp - unclaimed-27 batch 34 (docs/20-unclaimed-27.md). FUN_59ad40, name unknown (GUESS). SEH frame not reproduced (tagged).
// 0x59ac70 is hooked in the spec (stub, NOT verified). 0x4690b0 is exe code (plain ret, cdecl, two arguments: the caller cleans).
extern "C" void THISCALL ext_59ac70(u8 *self);
extern "C" void ext_4690b0(u8 *p, u32 line);

// 0x59ad40 (GUESS): thiscall, one argument (flags), ret 4, returns this.
static u8 *THISCALL funcCallAndAssert(u8 *self, u32 flags) {
  ext_59ac70(self);
  if (flags & 1u) {
    if (flags & 4u) {
      ext_4690b0(self, 0x132cfu);
    } else {
      void (*hook)(void) = (void (*)(void))(unsigned long)G(u32, 0x7003b0);
      if (hook) hook();   // the exe traps (int3) when the hook is null; the spec never sets it null
    }
  }
  return self;
}
PCREG(59ad40, funcCallAndAssert);
