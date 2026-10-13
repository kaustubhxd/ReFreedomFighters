// batch370.cpp - 0x41f650 (gap band). thiscall (this = ECX), no arguments. Loop: p = this->[0x18]; while p != 0:
// this slot 0x10(p + 0x20) (vcall); p = this->[0x18].
#include "ff.h"

#define U32(p, off) (*(u32 *)((u8 *)(p) + (off)))

static void THISCALL walkListSlot10(u8 *self) {
  u32 p = U32(self, 0x18);
  while (p != 0) {
    vcall<void>((void *)self, 0x10, p + 0x20u);
    p = U32(self, 0x18);
  }
}
PCREG(41f650, walkListSlot10);
