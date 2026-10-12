// batch2420.cpp - decomp area 24, batch 2420: STATICREFTAB::AddUnique(unsigned int) (0x4ce030), thiscall, ret 4.
// Calls the global function pointer at 0x7003b0 with no pushed argument (the original pushes none; its own argument is
// not used, so the callee's first stack word is this function's return address, which differs between builds and is
// not passed on). Then returns 0. A null pointer is an int3 in the original; the port traps the same way.
#include "ff.h"

// 0x4ce030
static u32 THISCALL staticRefTabAddUnique(u8 *self, u32 id) {
  (void)self;
  (void)id;
  typedef void (*fn0)(void);
  fn0 fn = *(fn0 *)0x7003b0;
  if (!fn)
    __builtin_trap();
  fn();
  return 0;
}
PCREG(4ce030, staticRefTabAddUnique);
