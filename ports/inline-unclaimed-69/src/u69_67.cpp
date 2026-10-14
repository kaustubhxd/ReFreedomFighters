// u69_67.cpp - area 69, group 67 (slice 8). A wrapper that appends an entry (ZGeometryDecal::AddPrimArray) over the helper 0x65e350 (other area; GUESS stub in the spec).
#include "ff.h"

extern "C" void THISCALL ext_65e350(void *self, u32 a, u32 b);   // thiscall, two stack args, ret 8

// 0x65e300, thiscall two stack args (ret 8). If the count at +0xc8 is 16, returns -1. Otherwise calls 0x65e350 with ECX = self + 4*(3*count + 1) and the two args,
// adds 1 to the count (read again after the call), and returns the count read after the call.
static s32 THISCALL addPrim65e300(u8 *self, u32 a, u32 b) {
  u32 cnt = *(u32 *)(self + 0xc8);
  if (cnt == 0x10)
    return -1;
  ext_65e350(self + 4 * (3 * cnt + 1), a, b);
  u32 old = *(u32 *)(self + 0xc8);
  *(u32 *)(self + 0xc8) = old + 1;
  return (s32)old;
}
PCREG(65e300, addPrim65e300);
