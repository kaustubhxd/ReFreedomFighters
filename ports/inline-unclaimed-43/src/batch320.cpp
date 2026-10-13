// batch320.cpp - 0x4dcd00 (area 43, 2026-10-12). thiscall (this = ECX), one stack argument, ret 4. Stores the argument
// at this+0x50.
#include "ff.h"

#define U32(p, off) (*(u32 *)((u8 *)(p) + (off)))

static void THISCALL storeAt50(u8 *self, u32 v) {
  U32(self, 0x50) = v;
}
PCREG(4dcd00, storeAt50);
