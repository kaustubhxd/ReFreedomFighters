// batch222.cpp - core residue 5 (decomp-pilot/core-todo/residue-05.txt). Calls the original initializer 0x5a54b0 (stubbed)
// on this; then, if flags & 1: flags & 4 ? ext_4690b0(this, 0x8d8) (a bare ret in the exe) : ext_45c510(this) (stubbed).
// Returns this. Name GUESS.
#include "ff.h"

extern "C" void THISCALL ext_5a54b0(u8 *self);   // original initializer, thiscall, no stack words (stubbed in the harness)
extern "C" void ext_45c510(u8 *p);                // original release, cdecl one word (stubbed in the harness)
extern "C" void ext_4690b0(u8 *p, u32 n);         // original release, cdecl two words (a bare ret in the exe)

// 0x5a5690, thiscall(flags) (ret 4).
static u8 *THISCALL initRelease_5a5690(u8 *self, u32 flags) {
  ext_5a54b0(self);
  if (flags & 1) {
    if (flags & 4) ext_4690b0(self, 0x8d8u);
    else ext_45c510(self);
  }
  return self;
}
PCREG(5a5690, initRelease_5a5690);
