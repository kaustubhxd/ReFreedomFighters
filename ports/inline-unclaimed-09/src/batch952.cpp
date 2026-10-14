// batch952.cpp - area 56 band (claim A11): 0x533c20, a bool wrapper around 0x539780 (thiscall, no arguments, plain ret).
#include "ff.h"

extern "C" u32 THISCALL ext_539780(u8 *self);

// 0x533c20: returns whether the low byte of 0x539780(this) is non-zero (the original tests al only).
static u8 THISCALL boolWrap533c20(u8 *self) {
  return (u8)ext_539780(self) != 0;
}
PCREG(533c20, boolWrap533c20);
