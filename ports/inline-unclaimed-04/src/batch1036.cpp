// batch1036.cpp - unclaimed-04 batch 36 (docs/20-unclaimed-04.md): 0x45b530, thiscall, one flag argument (ret 4), returns this.
#include "ff.h"

extern "C" void THISCALL ext_43de70(void *self);       // base, hooked by address in the spec (GUESS)
extern "C" void __attribute__((cdecl)) ext_45c510(void *p);  // helper, hooked by address in the spec (GUESS)

// 0x45b530
static u8 *THISCALL unk45b530(u8 *self, u32 flags) {
  *(u32 *)self = 0x684358;
  ext_43de70(self);
  if ((flags & 1) && !(flags & 4)) ext_45c510(self);
  return self;
}
PCREG(45b530, unk45b530);
