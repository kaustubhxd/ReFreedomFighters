// batch1048.cpp - ZCAMERA::~ZCAMERA (deleting-flag form). Camera thread, 2026-10-11.
#include "cam.h"

#define CDECL __attribute__((cdecl))

extern "C" THISCALL void ext_45c3e0(void *self);        // base class destructor (keeps the base's own vtable store)
extern "C" CDECL void ext_45c510(void *self);           // frees self through the manager (slot 0x14 of mgr+8)
extern "C" CDECL void ext_4690b0(void *self, u32 n);    // reset helper, called with 0x197

// 0x445340 ZCAMERA::~ZCAMERA(u32 flags) (thiscall, one stack arg): the vtable is set to ZCAMERA's, the base
// destructor runs, then bit 0 of flags frees the object: bit 2 set uses the reset helper (0x197), else the free helper.
static THISCALL u8 *ZCAMERA_Dtor(u8 *self, u32 flags) {
  at<u32>(self, 0) = 0x67d748;
  ext_45c3e0(self);
  if (flags & 1) {
    if (flags & 4) ext_4690b0(self, 0x197);
    else ext_45c510(self);
  }
  return self;
}
PCREG(445340, ZCAMERA_Dtor);
