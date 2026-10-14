// batch940.cpp - 0x5edb20 (no name in the map), read in full (2026-10-12). Thiscall (ECX = this), three stack words, ret 0xc (the third word is
// never read), void. Args: a (ebp+8, float), b (ebp+0xc, float). If this+0xd7 == a and this+0xdb == b, both ordered-equal, it returns with no change.
// Otherwise it stores a at this+0xd7, b at this+0xdb and sets the byte at this+0xa6 to 1. NaN never compares equal, so it always stores.
#include "ff.h"

#define U8(p, o) (*(u8 *)((u8 *)(p) + (o)))
#define F32(p, o) (*(float *)((u8 *)(p) + (o)))

// 0x5edb20 (no name in the map).
static void THISCALL Set5edb20(u8 *self, float a, float b, u32 unused) {
  (void)unused;
  if (F32(self, 0xd7) == a && F32(self, 0xdb) == b) return;
  F32(self, 0xd7) = a;
  F32(self, 0xdb) = b;
  U8(self, 0xa6) = 1;
}
PCREG(5edb20, Set5edb20);
