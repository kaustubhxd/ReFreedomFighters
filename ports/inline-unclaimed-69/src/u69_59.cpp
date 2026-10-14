// u69_59.cpp - area 69, group 59 (slice 8). A constructor over a base constructor 0x54cc50 (other area, GUESS stub; thiscall, one stack arg, ret 4 assumed).
#include "ff.h"

extern "C" void THISCALL ext_54cc50(void *self, u32 a);

// 0x549280, thiscall one stack arg (ret 4), returns this. Calls the base constructor with the same arg, then sets the vtable 0x6a32b4, the dword +0x40b1 = 0x6a3298,
// the dword +0x63c7 = 0x8000, the dwords +0x40c6, +0x40be, +0x40c2 = 0, the byte +0x63c6 = 0, and the dword +4 = 0x40000.
static u8 *THISCALL ctor6a32b4_549280(u8 *self, u32 a) {
  ext_54cc50(self, a);
  *(u32 *)self = 0x6a32b4;
  *(u32 *)(self + 0x40b1) = 0x6a3298;
  *(u32 *)(self + 0x63c7) = 0x8000;
  *(u32 *)(self + 0x40c6) = 0;
  self[0x63c6] = 0;
  *(u32 *)(self + 0x40be) = 0;
  *(u32 *)(self + 0x40c2) = 0;
  *(u32 *)(self + 4) = 0x40000;
  return self;
}
PCREG(549280, ctor6a32b4_549280);
