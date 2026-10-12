#include "ff.h"
// batch918.cpp - unclaimed-01 claim 17 (docs/20-unclaimed-01.md). ZLnkAction::~ZLnkAction() (0x460c80, medium: the name
// comes from the map's dtor entry). The delete it calls (0x634273, cdecl: pointer and size) is original code, stubbed by
// the spec with a logging cdecl stub.

extern "C" void ext_634273(void *p, u32 n);   // operator delete (cdecl), original code

// Sets the vtable word 0x685294, deletes the object (size 8) when bit 0 of the argument is set, and returns this.
static u32 THISCALL lnkActionDtor(u8 *self, u32 flag) {
  *(u32 *)self = 0x685294u;
  if ((flag & 1) != 0)
    ext_634273(self, 8u);
  return (u32)self;
}
PCREG(460c80, lnkActionDtor);
