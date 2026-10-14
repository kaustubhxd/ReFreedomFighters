// batch1079.cpp - ZCameraOverlay::~ZCameraOverlay (0x4572d0, high confidence in the class map). Camera/view thread,
// 2026-10-12.
#include "cam.h"

#define CDECL __attribute__((cdecl))

extern "C" THISCALL void ext_451a00(void *self);          // base class destructor (0x6813c0 vtable)
extern "C" CDECL void ext_634273(void *p, u32 size);      // sized delete
extern "C" CDECL void ext_45c510(void *self);             // free helper
extern "C" CDECL void ext_4690b0(void *self, u32 n);      // reset helper, called with 0xd9 here

// 0x4572d0 ZCameraOverlay::~ZCameraOverlay(u32 flags) (thiscall, one stack arg): the vtable is 0x6830e0; the block at +0x84
// (its word at +4 is freed with size 0x28, then the block with size 8); the base destructor 0x451a00 runs; bit 0 of flags
// releases: bit 2 calls the reset helper with 0xd9, else the free helper.
static THISCALL u8 *ZCameraOverlay_Dtor(u8 *self, u32 flags) {
  u8 *blk = at<u8 *>(self, 0x84);
  at<u32>(self, 0) = 0x6830e0;
  if (blk) {
    ext_634273(at<void *>(blk, 4), 0x28);
    ext_634273((void *)blk, 8);
  }
  ext_451a00(self);
  if (flags & 1) {
    if (flags & 4) ext_4690b0(self, 0xd9);
    else ext_45c510(self);
  }
  return self;
}
PCREG(4572d0, ZCameraOverlay_Dtor);
