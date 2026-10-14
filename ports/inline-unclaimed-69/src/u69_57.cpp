// u69_57.cpp - area 69, group 57 (slice 8). A constructor that calls its base constructor 0x43de40 (other area, GUESS stub in the spec), then sets fields.
#include "ff.h"

extern "C" void THISCALL ext_43de40(void *self, u32 a, u32 b, u32 c);  // base ctor, thiscall, three stack args, ret 0xc

// 0x4ee240, thiscall three stack args (ret 0xc), returns this. Calls the base constructor with the same three args, then sets the vtable 0x697e9c and
// the fields: +0x18 = -1, +0x1c = 0, word +0x20 = 0x8011, dwords +0x2a, +0x2e, +0x32, +0x3a = 0, +0x8e = 0x8ff, floats +0x22 and +0x26 = 1.0,
// dwords +0x3e and +0x42 = 0, and +0x46, +0x4a, +0x4e = 0x7e967699.
static u8 *THISCALL ctor697e9c4ee240(u8 *self, u32 a, u32 b, u32 c) {
  ext_43de40(self, a, b, c);
  *(u32 *)self = 0x697e9c;
  *(u32 *)(self + 0x18) = 0xffffffff;
  *(u32 *)(self + 0x1c) = 0;
  *(u16 *)(self + 0x20) = 0x8011;
  *(u32 *)(self + 0x2a) = 0;
  *(u32 *)(self + 0x2e) = 0;
  *(u32 *)(self + 0x32) = 0;
  *(u32 *)(self + 0x3a) = 0;
  *(u32 *)(self + 0x8e) = 0x8ff;
  *(u32 *)(self + 0x22) = 0x3f800000;
  *(u32 *)(self + 0x26) = 0x3f800000;
  *(u32 *)(self + 0x3e) = 0;
  *(u32 *)(self + 0x42) = 0;
  *(u32 *)(self + 0x46) = 0x7e967699;
  *(u32 *)(self + 0x4a) = 0x7e967699;
  *(u32 *)(self + 0x4e) = 0x7e967699;
  return self;
}
PCREG(4ee240, ctor697e9c4ee240);
