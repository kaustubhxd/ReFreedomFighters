// u69_45.cpp - area 69, group 45 (slice 8). SEH tag: the original sets up an fs:[0] exception frame and tears it down; the port does not reproduce the frame (it has no effect on the returned value or on the fields checked here).
#include "ff.h"

extern "C" void THISCALL ext_4c4a70(void *self);  // thiscall, no args; other area with its own SEH frame (stubbed in the spec: GUESS)
extern "C" void ext_4690b0(void *self, u32 code); // empty cdecl (the caller pops both args)

// 0x4c4b10, thiscall one stack arg (flags, ret 4), returns self. Calls 0x4c4a70(self). If bit 0 of flags is set: with bit 2 set, calls 0x4690b0(self, 0x6e); otherwise calls the function pointer at global 0x7003b0 when it is non-null.
// SEH frame not reproduced.
static u8 *THISCALL checkedCall4c4b10(u8 *self, u32 flags) {
  ext_4c4a70(self);
  if (flags & 1) {
    if (flags & 4) {
      ext_4690b0(self, 0x6e);
    } else {
      void (*fp)(void) = *(void (**)(void)) 0x7003b0;
      if (fp)
        fp();
    }
  }
  return self;
}
PCREG(4c4b10, checkedCall4c4b10);
