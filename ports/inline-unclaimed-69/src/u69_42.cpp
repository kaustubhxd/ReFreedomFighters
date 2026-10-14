// u69_42.cpp - area 69, group 42 (slice 8). Multi-call chain: calls A, calls B, then jumps to C with ECX = self. A, B, C are other areas' functions (GUESS stubs in the spec).
#include "ff.h"

extern "C" u32 THISCALL ext_436450(void *self);  // thiscall, no args, ret 0 (other area)
extern "C" u32 THISCALL ext_4362f0(void *self);  // thiscall, no args, ret 0 (other area)
extern "C" u32 THISCALL ext_4298b0(void *self);  // thiscall, no args, ret 0 (other area)

// 0x42a480, thiscall no args (ret). Calls 0x436450(self), then 0x4362f0(self), then jumps to 0x4298b0 with ECX = self.
static u32 THISCALL chain42a480(u8 *self) {
  ext_436450(self);
  ext_4362f0(self);
  return ext_4298b0(self);
}
PCREG(42a480, chain42a480);
