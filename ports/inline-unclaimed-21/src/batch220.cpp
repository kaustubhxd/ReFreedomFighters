// batch220.cpp - core residue 0 (decomp-pilot/core-todo/residue-00.txt). Calls the original initializer 0x58b5a0 (SEH frame,
// stubbed in the harness) on this, then a release chosen by flags: flags & 1 and flags & 4 -> 0x4690b0(this, 0xf62) (a bare
// ret in the exe); flags & 1 and not flags & 4 -> 0x45c510(this) (stubbed). Returns this. Name GUESS.
#include "ff.h"

extern "C" void THISCALL ext_58b5a0(u8 *self);     // original initializer, thiscall, no stack words (stubbed in the harness)
extern "C" void ext_45c510(u8 *p);                  // original release, cdecl one word (stubbed in the harness)
extern "C" void ext_4690b0(u8 *p, u32 n);           // original release, cdecl two words (a bare ret in the exe)

// 0x58b740, thiscall(flags) (ret 4): ext_58b5a0(this); if flags & 1: (flags & 4 ? ext_4690b0(this, 0xf62) : ext_45c510(this)).
// Returns this.
static u8 *THISCALL initRelease_58b740(u8 *self, u32 flags) {
  ext_58b5a0(self);
  if (flags & 1) {
    if (flags & 4) ext_4690b0(self, 0xf62u);
    else ext_45c510(self);
  }
  return self;
}
PCREG(58b740, initRelease_58b740);
