// batch172.cpp - unclaimed area 17, slice floor(addr/16) mod 20 == 16.
#include "ff.h"

extern "C" void THISCALL ext_43de70(u8 *self);   // base teardown of ZGlobalColiObj, original code
extern "C" void ext_45c510(u8 *self);            // deferred release, original code (cdecl, one argument)

// 0x460c40, thiscall, ret 4 (one stack argument: flags, only the low byte is read). Scalar deleting destructor shape:
// runs the base teardown ext_43de70, then if flags bit 0 is set and bit 2 is clear, ext_45c510(this). Returns this.
// Map name ZGlobalColiObj::~ZGlobalColiObj, not checked against the body beyond the flag tests.
static u8 *THISCALL globalColiObjDtor(u8 *self, u32 flags) {
  ext_43de70(self);
  u8 f = (u8)flags;
  if (f & 1) {
    if (!(f & 4))
      ext_45c510(self);
  }
  return self;
}
PCREG(460c40, globalColiObjDtor);
