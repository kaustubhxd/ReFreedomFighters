// batch321.cpp - 0x5eeb80 (area 43, 2026-10-12). thiscall (this = ECX), one stack argument, ret 4. Stores the argument
// dword at this+0x11 (unaligned).
#include "ff.h"

#define U32(p, off) (*(u32 *)((u8 *)(p) + (off)))

static void THISCALL storeAt11(u8 *self, u32 v) {
  U32(self, 0x11) = v;
}
PCREG(5eeb80, storeAt11);
