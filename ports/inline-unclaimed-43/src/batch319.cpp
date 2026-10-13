// batch319.cpp - 0x469580 (area 43, 2026-10-12). thiscall (this = ECX), no stack arguments, returns a dword (eax).
// Body: p = this->[0x40]; return p ? dword at p+0x1f : 0. (Unaligned read.)
#include "ff.h"

#define U32(p, off) (*(u32 *)((u8 *)(p) + (off)))

static u32 THISCALL dwordAt1f(u8 *self) {
  u32 p = U32(self, 0x40);
  if (p == 0)
    return 0;
  return U32(p, 0x1f);
}
PCREG(469580, dwordAt1f);
