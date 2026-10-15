// batch1051.cpp - ZShakeCamera destructor (0x5d4920). Camera thread, 2026-10-11.
#include "cam.h"

#define CDECL __attribute__((cdecl))

typedef void (*relfn)(void);

extern "C" CDECL void ext_4690b0(void *self, u32 n);   // reset helper, called with 0x60 here

// 0x5d4920 ZShakeCamera::~ZShakeCamera(u32 flags) (thiscall, one stack arg). The object leaves the manager list
// (slot 0x34 of sys+0x9b, with self), its fields are cleared, and bit 0 of flags releases it: bit 2 calls the reset
// helper with 0x65, else the release callback in the global at 0x7003b0 (an unset callback traps, int3).
// The SEH frame of the original is compiler bookkeeping and is not ported.
static THISCALL u8 *ZShakeCamera_Dtor(u8 *self, u32 flags) {
  at<u32>(self, 0x44) = 0;
  at<u32>(self, 0x30) = 0;
  at<u32>(self, 0) = 0x686874;
  vcall<void>(SYS9B, 0x34, self);
  if (flags & 1) {
    if (flags & 4) {
      ext_4690b0(self, 0x65);
    } else {
      relfn release = G(relfn, 0x7003b0);
      if (!release) __builtin_trap();   // the original's int3 when the callback is unset
      release();
    }
  }
  return self;
}
PCREG(5d4920, ZShakeCamera_Dtor);
