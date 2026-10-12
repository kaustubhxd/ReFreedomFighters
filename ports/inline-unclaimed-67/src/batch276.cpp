// batch276.cpp - unclaimed area 67, gap band: 0x5fc010 (first vtable entry of the object at [this+0x30], if its count is nonzero).
#include "ff.h"

static inline u32 rdw(u32 p, u32 off) { return *(u32 *)(unsigned long)(p + off); }

// 0x5fc010, thiscall, plain ret.
static u32 THISCALL firstVtableEntry(u8 *selfP) {
  u32 self = (u32)(unsigned long)selfP;
  *(u32 *)(selfP + 0x34) = 0;
  u32 obj = rdw(self, 0x30);
  if (rdw(obj, 8) != 0)
    return rdw(rdw(obj, 0), 0);
  return 0;
}
PCREG(5fc010, firstVtableEntry);
