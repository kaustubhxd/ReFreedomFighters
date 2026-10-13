#include "ff.h"
// batch975.cpp - unclaimed-80 residue-19 (docs/20-unclaimed-80.md), batch 53: 0x6160b0 (thiscall, self in ecx, stack arguments a and b, ret 8).
// If [a+0x10] == 0 return. r = 0x659000(a, 1) (thiscall, ecx = a, one argument, callee-cleaned; GUESS, hooked by address in the spec).
// Then 0x612030([self+0x182a5], [r+0xc]) (thiscall, ecx = the field, one argument, callee-cleaned; GUESS, hooked by address).

extern "C" u32 THISCALL ext_659000(u8 *self, u32 a1);
extern "C" u32 THISCALL ext_612030(u8 *self, u32 a1);

static void THISCALL zg6160b0(u8 *self, u8 *a, u32 b) {
  if (*(u32 *)(a + 0x10) == 0) return;
  u32 r = ext_659000(a, 1);
  u8 *field = *(u8 **)(self + 0x182a5);
  ext_612030(field, *(u32 *)(r + 0xc));
}
PCREG(6160b0, zg6160b0);
