// batch282.cpp - unclaimed area 67, gap band: two-selector store into the record at [this+0xc].
#include "ff.h"

static inline u32 rdw(u32 p, u32 off) { return *(u32 *)(unsigned long)(p + off); }

// 0x5f28e0, thiscall, ret 8 (args a, v): a == 0 stores v at [[this+0xc]+0xa0]; a == 1 stores v at [[this+0xc]+0xa4].
static void THISCALL storeSelected28e0(u8 *selfP, u32 a, u32 v) {
  u32 p = rdw((u32)(unsigned long)selfP, 0xc);
  if (a == 0)
    *(u32 *)(unsigned long)(p + 0xa0) = v;
  else if (a == 1)
    *(u32 *)(unsigned long)(p + 0xa4) = v;
}
PCREG(5f28e0, storeSelected28e0);
