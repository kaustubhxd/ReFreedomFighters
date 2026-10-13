// batch326.cpp - 0x5edc60 (area 71 leaf, residue 10). thiscall (this = ECX), one stack argument, ret 4.
// Body: if this->[0xdf] != arg: this->[0xdf] = arg; this->byte[0xa6] = 1.
#include "ff.h"

#define U32(p, off) (*(u32 *)((u8 *)(p) + (off)))

static void THISCALL setIfChanged(u8 *self, u32 v) {
  if (U32(self, 0xdf) == v)
    return;
  U32(self, 0xdf) = v;
  self[0xa6] = 1;
}
PCREG(5edc60, setIfChanged);
