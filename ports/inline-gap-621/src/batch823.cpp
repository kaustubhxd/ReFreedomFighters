// batch823.cpp - standing assignment, residue 19 (docs/20-unclaimed-gap-621.md). Names are GUESS.
#include "ff.h"

// 0x63eab0: thiscall(arg) ret 4 - simple array getter
// Returns [this[0x68] + (arg & 0xfff) * 4]
static u32 THISCALL array_getter_63eab0(u8 *self, u32 arg) {
  u32 *base = *(u32 **)(self + 0x68);
  u32 index = arg & 0xfff;
  return base[index];
}
PCREG(63eab0, array_getter_63eab0);
