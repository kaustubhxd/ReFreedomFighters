// batch2431.cpp - decomp area 24, batch 2431: ZDamageBox::~ZDamageBox(unsigned char) (0x5daff0), thiscall, ret 4.
// SEH frame not reproduced: the original installs an exception frame on fs:[0] and restores it; this port does not.
// Body call (0x5daf20), then when bit 0 of the flag is set: ZRenderGC::SetState(this, 0x89) (0x4690b0, cdecl) if bit 2
// is set, else the global function pointer at 0x7003b0 (cdecl, no arguments; a null pointer is an int3 in the original).
// Returns this.
#include "ff.h"

extern "C" void THISCALL ext_5daf20(void *self);      // ZDamageBox body (thiscall)
extern "C" void ext_4690b0(void *self, u32 state);    // ZRenderGC::SetState (cdecl)

// 0x5daff0 (SEH frame not reproduced)
static u8 *THISCALL zDamageBoxDtor(u8 *self, u32 flag) {
  ext_5daf20(self);
  if (flag & 1) {
    if (flag & 4) {
      ext_4690b0(self, 0x89);
    } else {
      typedef void (*fn0)(void);
      fn0 fn = *(fn0 *)0x7003b0;
      if (!fn)
        __builtin_trap();
      fn();
    }
  }
  return self;
}
PCREG(5daff0, zDamageBoxDtor);
