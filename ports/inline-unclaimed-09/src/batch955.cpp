// batch955.cpp - area 56 band (claim A14): 0x53c1f0, returns null for an argument of 0 or 0x80000000, else this + (n+1)*8.
#include "ff.h"

// 0x53c1f0 (unnamed; band list).
static u8 *THISCALL indexAddr53c1f0(u8 *self, u32 n) {
  if (n == 0 || n == 0x80000000u) return 0;
  return self + (u32)(n + 1) * 8u;
}
PCREG(53c1f0, indexAddr53c1f0);
