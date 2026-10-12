// batch1955.cpp - unclaimed-66 batch 65 (gap band, GUESS name). THISCALL(this), one stack argument (flags), ret 4; returns this in eax.
//   [this] = 0x69fb3c; 0x511950(ECX = this+0x2d8) (recording stub); 0x512070(ECX = this) (exe code bound; see batch 37);
//   if (flags & 1): if (flags & 4) == 0: 0x45c510(this) (cdecl, one argument); else 0x4690b0(this, 0x171d) (cdecl, two arguments).
#include "ff.h"

extern "C" void THISCALL ext_511950(u8 *self);   // no arguments (recording stub in the spec)
extern "C" void THISCALL ext_512070(u8 *self);   // no arguments (exe code bound, batch 37)
extern "C" void ext_45c510(u8 *self);            // cdecl, one argument (recording stub in the spec)
extern "C" void ext_4690b0(u8 *self, u32 v);     // cdecl, two arguments (recording stub in the spec)

// 0x51f4e0, GUESS FUN_0051f4e0 (batch 65).
static u32 THISCALL gapFn51f4e0(u8 *self, u32 flags) {
  *(u32 *)self = 0x69fb3c;
  ext_511950(self + 0x2d8);
  ext_512070(self);
  if (flags & 1) {
    if (!(flags & 4)) ext_45c510(self);
    else ext_4690b0(self, 0x171d);
  }
  return (u32)self;
}
PCREG(51f4e0, gapFn51f4e0);
