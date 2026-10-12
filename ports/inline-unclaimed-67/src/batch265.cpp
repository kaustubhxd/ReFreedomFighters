// batch265.cpp - unclaimed area 67, slice floor(addr/16) mod 20 == 6 (FUN_ names; bodies from the PC bytes).
#include "ff.h"

typedef void (THISCALL *V1)(u8 *self, u32 a);
static inline u32 rdw(u32 p, u32 off) { return *(u32 *)(unsigned long)(p + off); }

// 0x557860, plain ret, no this: if the global at 0x713f04 is set, calls its slot 4 with argument 0, then clears the global.
static void readFreeGlobal713f04(void) {
  u32 obj = rdw(0x713f04, 0);
  if (obj) {
    ((V1)rdw(rdw(obj, 0), 4))((u8 *)(unsigned long)obj, 0);
  }
  *(u32 *)0x713f04 = 0;
}
PCREG(557860, readFreeGlobal713f04);

// 0x42ad20, thiscall, plain ret: if [this+0xc] is set, calls its slot 0 with argument 1, then sets [this+0xc] to 0.
static void THISCALL releaseAtC(u8 *selfP) {
  u32 self = (u32)(unsigned long)selfP;
  u32 obj = rdw(self, 0xc);
  if (obj)
    ((V1)rdw(rdw(obj, 0), 0))((u8 *)(unsigned long)obj, 1);
  *(u32 *)(selfP + 0xc) = 0;
}
PCREG(42ad20, releaseAtC);

// 0x4cdca0, thiscall, plain ret: as 0x42ad20 with [this+0x1c].
static void THISCALL releaseAt1c(u8 *selfP) {
  u32 self = (u32)(unsigned long)selfP;
  u32 obj = rdw(self, 0x1c);
  if (obj) {
    ((V1)rdw(rdw(obj, 0), 0))((u8 *)(unsigned long)obj, 1);
    *(u32 *)(selfP + 0x1c) = 0;
  }
}
PCREG(4cdca0, releaseAt1c);
