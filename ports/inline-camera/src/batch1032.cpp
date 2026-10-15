// batch1032.cpp - ZCamHelper scalar deleting destructor (0x5cd4e0). Camera thread, 2026-10-11.
// The base destructor body (0x5cd450) is original code (ext_), so only the flag handling is compared here.
#include "cam.h"

extern "C" THISCALL void ext_5cd450(void *self);  // ZCamHelper dtor body (original)
extern "C" void ext_4690b0(void *p, u32 x);       // the empty engine call (cdecl, returns with ret)

// Flags (the deleting-dtor argument): bit 0 = free the object, bit 2 = skip the free hook (a no-op call here).
// Freeing calls the delete hook at 0x7003b0; with no hook the original executes int3 (an assert).
static THISCALL u8 *ZCamHelper_DeleteDtor(u8 *self, u32 flags) {
  ext_5cd450(self);
  if (flags & 1) {
    if (flags & 4) {
      ext_4690b0(self, 0xe20);
    } else {
      typedef void (*hookfn)();
      hookfn hook = G(hookfn, 0x7003b0);
      if (!hook) __builtin_debugtrap();
      hook();
    }
  }
  return self;
}
PCREG(5cd4e0, ZCamHelper_DeleteDtor);
