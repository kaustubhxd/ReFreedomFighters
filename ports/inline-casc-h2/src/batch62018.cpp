#include "ff.h"

extern "C" void THISCALL ext_43de70(u8 *self);
extern "C" void ext_45c510(u32 self);

// 0x460c40: begin teardown, then choose the release path from flag bits 0 and 2.
static u8 *THISCALL fn460c40(u8 *self, u32 flags) {
  ext_43de70(self);
  if ((flags & 1) && !(flags & 4)) ext_45c510((u32)self);
  // The 0x4690b0 path is a bare RET after caller-pushed arguments.
  return self;
}

PCREG(460c40, fn460c40);
