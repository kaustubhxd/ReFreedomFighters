// batch1049.cpp - ZFFCameraClass::~ZFFCameraClass (deleting-flag form). Camera thread, 2026-10-11.
#include "cam.h"

#define CDECL __attribute__((cdecl))

extern "C" THISCALL void ext_445330(void *self);        // base class destructor (the ZCAMERA base; stubbed in the spec)
extern "C" CDECL void ext_45c510(void *self);           // free helper (shared with batch1048)

// 0x5b21b0 ZFFCameraClass::~ZFFCameraClass(u32 flags) (thiscall, one stack arg): vtable 0x6b1650, base destructor,
// then bit 0 frees: bit 2 set skips the free (the original calls the reset helper 0x4690b0 with 0x1cc instead).
extern "C" CDECL void ext_4690b0(void *self, u32 n);

static THISCALL u8 *ZFFCameraClass_Dtor(u8 *self, u32 flags) {
  at<u32>(self, 0) = 0x6b1650;
  ext_445330(self);
  if (flags & 1) {
    if (flags & 4) ext_4690b0(self, 0x1cc);
    else ext_45c510(self);
  }
  return self;
}
PCREG(5b21b0, ZFFCameraClass_Dtor);
