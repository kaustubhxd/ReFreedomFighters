// u69_41.cpp - area 69, group 41 (slice 8). Multi-call chain: calls A, calls B only when the byte at self+0x1a3 is non-zero, then jumps to C with ECX = self. A, B, C are other areas' functions (GUESS stubs in the spec).
#include "ff.h"

extern "C" u32 THISCALL ext_5706f0(void *self);  // thiscall, no args, ret 0 (other area)
extern "C" u32 THISCALL ext_563a50(void *self);  // thiscall, no args, ret 0 (other area)
extern "C" u32 THISCALL ext_5709d0(void *self);  // thiscall, no args, ret 0 (other area)

// 0x570880, thiscall no args (ret). Calls 0x5706f0(self); if the byte at self+0x1a3 is non-zero, calls 0x563a50(self); then jumps to 0x5709d0 with ECX = self.
static u32 THISCALL chain570880(u8 *self) {
  ext_5706f0(self);
  if (self[0x1a3])
    ext_563a50(self);
  return ext_5709d0(self);
}
PCREG(570880, chain570880);
