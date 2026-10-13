// batch317.cpp - 0x5edbe0 (area 43, 2026-10-12). thiscall (this = ECX), three stack arguments (the third is not read), ret 0xc.
// Body: if this->[0xe7] != a or this->[0xef] != b: this->[0xd7] = 0, this->[0xe7] = a, this->[0xef] = b, byte this->[0xa6] = 1.
#include "ff.h"

#define U32(p, off) (*(u32 *)((u8 *)(p) + (off)))

static void THISCALL setPairIfChanged(u8 *self, u32 a, u32 b, u32 c) {
  (void)c;
  if (U32(self, 0xe7) == a && U32(self, 0xef) == b)
    return;
  U32(self, 0xd7) = 0;
  U32(self, 0xe7) = a;
  U32(self, 0xef) = b;
  self[0xa6] = 1;
}
PCREG(5edbe0, setPairIfChanged);
