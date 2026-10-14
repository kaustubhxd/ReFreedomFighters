// batch972.cpp - area 56 band, claim A38 (0x526ff0).
#include "ff.h"

// A38 0x526ff0: *out = this->d4; if this->d19 == 2 return 1; else three virtual calls (slots 0x30, 0x28, 0x24),
// *out = this->d4 again, and return the byte this->b18.
static u8 THISCALL f526ff0(u8 *self, u32 *out) {
  *out = *(u32 *)(self + 4);
  if (*(u32 *)(self + 0x19) == 2) return 1;
  u8 *vt = *(u8 **)self;
  ((void(THISCALL *)(u8 *))(*(u32 *)(vt + 0x30)))(self);
  vt = *(u8 **)self;
  ((void(THISCALL *)(u8 *))(*(u32 *)(vt + 0x28)))(self);
  vt = *(u8 **)self;
  ((void(THISCALL *)(u8 *))(*(u32 *)(vt + 0x24)))(self);
  *out = *(u32 *)(self + 4);
  return *(u8 *)(self + 0x18);
}
PCREG(526ff0, f526ff0);
