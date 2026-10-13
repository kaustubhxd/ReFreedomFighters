// batch293.cpp - unclaimed area 67: two helpers of 0x439380.
#include "ff.h"

extern "C" void ext_634273(u8 *p, u32 n);   // exe free-style helper, cdecl (two arguments, caller cleans), original code

static inline u32 rdw(u32 p, u32 off) { return *(u32 *)(unsigned long)(p + off); }

// 0x4cc1d0, thiscall, plain ret: returns the dword at [this].
static u32 THISCALL firstDword4cc1d0(u8 *selfP) { return rdw((u32)(unsigned long)selfP, 0); }
PCREG(4cc1d0, firstDword4cc1d0);

// 0x4cbec0, thiscall, plain ret: if [this] != this+4, releases [this] through ext 0x634273(ptr, 1).
static void THISCALL releaseIfNotSelf4cbec0(u8 *selfP) {
  u32 self = (u32)(unsigned long)selfP;
  u32 p = rdw(self, 0);
  if (p != self + 4)
    ext_634273((u8 *)(unsigned long)p, 1);
}
PCREG(4cbec0, releaseIfNotSelf4cbec0);
