// batch912.cpp - residue-9 slice, two bodies read in full.
//  0x4d2190 [thiscall, two stack args (a, b), ret 8, void]: slot +0x10 of this with b (one argument), then slot +0xc of this with the
//           address of a (one argument). Both callees pop their argument (the exe does not clean).
//  0x5f1490 [thiscall, one stack arg (flags byte), ret 4, returns this]: this's first word = 0x6b84a8; if bit 0 of the flag is set,
//           0x634273 (cdecl: this, 4), which the caller pops.
#include "ff.h"

#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))

extern "C" void ext_634273(void *obj, u32 n);      // stood in; cdecl (shared with batch905)

// 0x4d2190 (no name in the map).
static void THISCALL Pair4d2190(u8 *self, u32 a, u32 b) {
  vcall<void>(self, 0x10, b);
  u32 tmp = a;
  vcall<void>(self, 0xc, (void *)&tmp);
}
PCREG(4d2190, Pair4d2190);

// 0x5f1490 (no name in the map).
static u8 *THISCALL Init5f1490(u8 *self, u32 flag) {
  U32(self, 0) = 0x6b84a8u;
  if (flag & 1u) ext_634273(self, 4u);
  return self;
}
PCREG(5f1490, Init5f1490);
