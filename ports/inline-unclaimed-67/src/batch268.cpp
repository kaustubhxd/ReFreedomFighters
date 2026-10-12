// batch268.cpp - unclaimed area 67, slice floor(addr/16) mod 20 == 6 (FUN_ names; bodies from the PC bytes).
#include "ff.h"

static inline u32 rdw(u32 p, u32 off) { return *(u32 *)(unsigned long)(p + off); }

// 0x435ae0, thiscall, plain ret: constructor. Vtable word 0x67a5d8, field resets, flags, global 0x7003a0 = this; returns this.
static u32 THISCALL ctorBlock(u8 *selfP) {
  u32 self = (u32)(unsigned long)selfP;
  *(u32 *)(self + 0x00) = 0x67a5d8u;
  *(u32 *)(self + 0x0c) = 0;
  *(u32 *)(self + 0x1c) = 0;
  *(u32 *)(self + 0x60) = 0;
  *(u32 *)(self + 0x74) = 0;
  *(u32 *)(self + 0x6c) = 0;
  *(u16 *)(self + 0x7a) = 1;
  *(u32 *)(self + 0x68) = 0;
  *(u32 *)(self + 0x64) = 0;
  *(u8 *)(self + 0x78) = 1;
  *(u32 *)0x7003a0 = self;
  *(u8 *)(self + 0x79) = 1;
  return self;
}
PCREG(435ae0, ctorBlock);

// 0x5edc20, thiscall, ret 0xc (three stack arguments; the third is unused): when [this+0xeb] != a or [this+0xf3] != b,
// resets [this+0xdb], stores a and b, and sets the byte at [this+0xa6].
static void THISCALL setPair(u8 *selfP, u32 a, u32 b, u32 c) {
  (void)c;
  u32 self = (u32)(unsigned long)selfP;
  if (rdw(self, 0xeb) == a && rdw(self, 0xf3) == b)
    return;
  *(u32 *)(selfP + 0xdb) = 0;
  *(u32 *)(selfP + 0xeb) = a;
  *(u32 *)(selfP + 0xf3) = b;
  *(u8 *)(selfP + 0xa6) = 1;
}
PCREG(5edc20, setPair);
