// batch954.cpp - area 56 band (claim A13): 0x524350, zeroes three dwords, stores a constant at +0xc, returns this. No callees.
#include "ff.h"

// 0x524350 (unnamed; band list).
static u8 *THISCALL initTriple524350(u8 *self) {
  *(u32 *)(self + 0) = 0;
  *(u32 *)(self + 4) = 0;
  *(u32 *)(self + 8) = 0;
  *(u32 *)(self + 0xc) = 0xfe967699u;
  return self;
}
PCREG(524350, initTriple524350);
