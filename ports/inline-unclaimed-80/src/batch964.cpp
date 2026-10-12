#include "ff.h"
// batch964.cpp - unclaimed-80 gap band (docs/20-unclaimed-80.md): 0x428710 and 0x428740 (high). Thiscall with one stack argument (ret 4),
// returns self. Call the base destructor 0x435b30 (claimed elsewhere; hooked by address in the spec) with ecx = self; if the argument's low
// bit is set, the sized free ext_634273(self, N) (cdecl, the caller pops): N = 0x1b2 for 0x428710, 0x46 for 0x428740.

extern "C" void THISCALL ext_435b30(u8 *self);
extern "C" void ext_634273(u8 *p, u32 n);

static u8 *THISCALL zg428710(u8 *self, u32 a1) {
  ext_435b30(self);
  if (a1 & 1) ext_634273(self, 0x1b2);
  return self;
}
PCREG(428710, zg428710);

static u8 *THISCALL zg428740(u8 *self, u32 a1) {
  ext_435b30(self);
  if (a1 & 1) ext_634273(self, 0x46);
  return self;
}
PCREG(428740, zg428740);
