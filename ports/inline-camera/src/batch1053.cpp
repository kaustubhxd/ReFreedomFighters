// batch1053.cpp - ZFFCamera1::~ZFFCamera1 (0x5cac20). Camera thread, 2026-10-11.
#include "cam.h"

#define CDECL __attribute__((cdecl))

typedef void (*relfn)(void);

extern "C" THISCALL void ext_4f6b20(void *self);         // base class destructor
extern "C" CDECL void ext_4690b0(void *self, u32 n);     // reset helper, called with 0x7ba here

// 0x5cac20 ZFFCamera1::~ZFFCamera1(u32 flags) (thiscall, one stack arg): the owner at +0x5a8 is handed to the
// sys object's slot 0x1a8, then deleted through its own slot 0 (flag 1), the base destructor 0x4f6b20 runs, and bit 0
// of flags releases: bit 2 calls the reset helper with 0x7ba, else the callback in the global at 0x7003b0 (an unset
// callback traps, int3). SEH bookkeeping is not ported.
static THISCALL u8 *ZFFCamera1_Dtor(u8 *self, u32 flags) {
  u8 *owner = at<u8 *>(self, 0x5a8);
  at<u32>(self, 0) = 0x6b4be8;
  vcall<void>(G(u8 *, 0x70039c), 0x1a8, owner);
  owner = at<u8 *>(self, 0x5a8);
  if (owner) vcall<void>(owner, 0, 1u);
  ext_4f6b20(self);
  if (flags & 1) {
    if (flags & 4) {
      ext_4690b0(self, 0x7ba);
    } else {
      relfn release = G(relfn, 0x7003b0);
      if (!release) __builtin_trap();
      release();
    }
  }
  return self;
}
PCREG(5cac20, ZFFCamera1_Dtor);
