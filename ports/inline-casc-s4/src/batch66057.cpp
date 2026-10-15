// batch66057.cpp - cascade s4 batch 66057: 0x410140 (tier F row).
#include "ff.h"

// 0x410140, cdecl(pp) returns the 64-bit value edx:eax: q = *pp; the bytes q[0xd] (most significant) down to q[6] (least significant) assembled big-endian.
extern "C" u64 fn410140(u8 **pp) {
  u8 *q = *pp;
  u64 v = 0;
  for (int i = 0xd; i >= 6; i--) v = (v << 8) | q[i];
  return v;
}
PCREG(410140, fn410140);
