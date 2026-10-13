// batch2492.cpp - decomp area 24, batch 2492 (residue 3, smallest first).
#include "ff.h"

extern "C" void THISCALL ext_4cb7f0(void *self, u32 v);  // thiscall, one argument (callee pops 4, assumed)

// 0x654df0 (GUESS name): slot 0x230 of this with the three arguments (callee pops 12); then the system object's flag bytes:
// +0xa1f |= 0x80, +0xa1f |= 0x20, +0xad8 &= 0x7f, +0x1406 |= 0x80, +0x1406 |= 0x20, +0x13f7 &= 0x7f.
static void THISCALL guessFlagsAfterCall(u8 *self, u32 a, u32 b, u32 c) {
  vcall<void>(self, 0x230, a, b, c);
  u8 *sys = G(u8 *, 0x70039c);
  *(u8 *)(sys + 0xa1f) |= 0x80;
  sys = G(u8 *, 0x70039c);
  *(u8 *)(sys + 0xa1f) |= 0x20;
  sys = G(u8 *, 0x70039c);
  *(u8 *)(sys + 0xad8) &= 0x7f;
  sys = G(u8 *, 0x70039c);
  *(u8 *)(sys + 0x1406) |= 0x80;
  sys = G(u8 *, 0x70039c);
  *(u8 *)(sys + 0x1406) |= 0x20;
  sys = G(u8 *, 0x70039c);
  *(u8 *)(sys + 0x13f7) &= 0x7f;
}
PCREG(654df0, guessFlagsAfterCall);

// 0x4cb970 (GUESS name): slot 0x25c of the table's +0xadc object with (0x685f44, 0); when that is nonzero, slot 0x4c of the table with
// it; then the helper 0x4cb7f0 on this with that result (callee pops 4).
static void THISCALL guessTableLookupThenHelper(u8 *self) {
  u8 *sys = G(u8 *, 0x70039c);
  u8 *tbl = *(u8 **)(sys + 0x9b);
  u32 r = vcall<u32>(*(void **)(tbl + 0xadc), 0x25c, (u32)0x685f44, 0u);
  if (r) {
    u32 r2 = vcall<u32>(*(void **)(G(u8 *, 0x70039c) + 0x9b), 0x4c, r);
    ext_4cb7f0(self, r2);
  }
}
PCREG(4cb970, guessTableLookupThenHelper);
