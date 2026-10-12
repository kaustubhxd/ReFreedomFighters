// batch331.cpp - 0x5966e0 (area 71 leaf, residue 10). thiscall (this = ECX), one stack argument, returns bool (al).
// Body: if this->[0x9d3] == arg and byte this->[0x66c] != 0: return true; else false.
#include "ff.h"

#define U32(p, off) (*(u32 *)((u8 *)(p) + (off)))

static bool THISCALL sameIdAndFlag(u8 *self, u32 id) {
  if (U32(self, 0x9d3) == id && self[0x66c] != 0)
    return true;
  return false;
}
PCREG(5966e0, sameIdAndFlag);
