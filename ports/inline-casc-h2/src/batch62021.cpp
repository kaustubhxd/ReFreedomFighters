#include "ff.h"

extern "C" void THISCALL ext_43ea20(u8 *self);
extern "C" void ext_45c510(u32 self);

// 0x4f9970: run the object cleanup, then select the release branch by flags.
static u8 *THISCALL fn4f9970(u8 *self, u32 flags) {
  ext_43ea20(self);
  if ((flags & 1) && !(flags & 4)) ext_45c510((u32)self);
  // 0x4690b0 is a bare RET; this path only discards its caller-pushed args.
  return self;
}

PCREG(4f9970, fn4f9970);
