// batch278.cpp - unclaimed area 67, gap band 0x5e1000-0x601000.
#include "ff.h"

static inline u32 rdw(u32 p, u32 off) { return *(u32 *)(unsigned long)(p + off); }

// 0x5f2c30, thiscall, ret 4 (arg v).
static void THISCALL setFields2c30(u8 *selfP, u32 v) {
  *(u32 *)(selfP + 4) = 0;
  *(u32 *)(selfP + 0x10) = v;
  *(u32 *)(selfP + 0xc) = 0;
  *(u32 *)(selfP + 8) = 0;
}
PCREG(5f2c30, setFields2c30);

// 0x5f0630, thiscall, plain ret: constructor; returns this.
static u32 THISCALL ctor5f0630(u8 *selfP) {
  *(u32 *)selfP = 0x6b82c4u;
  *(u32 *)(selfP + 0x7c) = 0;
  *(u32 *)(selfP + 0x80) = 0;
  *(u32 *)(selfP + 0x84) = 0;
  *(u32 *)(selfP + 0x78) = 0;
  *(u32 *)(selfP + 0x88) = 0;
  return (u32)(unsigned long)selfP;
}
PCREG(5f0630, ctor5f0630);

// 0x5f2b50, thiscall, ret 4 (arg a): a == 0 clears the dword at [[this+0xc]+0xa0]; a == 1 clears [[this+0xc]+0xa4];
// other values do nothing.
static void THISCALL clearA0(u8 *selfP, u32 a) {
  u32 p = rdw((u32)(unsigned long)selfP, 0xc);
  if (a == 0)
    *(u32 *)(unsigned long)(p + 0xa0) = 0;
  else if (a == 1)
    *(u32 *)(unsigned long)(p + 0xa4) = 0;
}
PCREG(5f2b50, clearA0);
