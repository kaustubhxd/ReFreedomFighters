// batch219.cpp - core residue 0 (decomp-pilot/core-todo/residue-00.txt). A destructor: sets the vtable and releases the
// object with the original 0x634273 (cdecl free-style, size 8) when flags & 1. Name from the name map: ZLnkAction::~ZLnkAction.
#include "ff.h"

extern "C" void ext_634273(u8 *p, u32 n);   // original release, cdecl (stubbed in the harness; stores its arguments)

// 0x460c80, thiscall(flags) (ret 4): [this] = vtable 0x685294; if flags & 1: ext_634273(this, 8); returns this.
static u8 *THISCALL ZLnkActionDtor_460c80(u8 *self, u32 flags) {
  *(u32 *)self = 0x685294u;
  if (flags & 1) ext_634273(self, 8);
  return self;
}
PCREG(460c80, ZLnkActionDtor_460c80);
