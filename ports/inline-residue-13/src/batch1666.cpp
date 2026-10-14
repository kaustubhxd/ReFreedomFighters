// batch1666.cpp - 0x468f20 (GUESS, residue 13 gap band, 2026-10-12). ret 4 (one argument: the reader/obj). Reads eight
// 4-byte values through the object's vslot 0x10 (dest, 4) into this+4, +8, +0x14, +0x18, +0xc, +0x10, +0x1c and +0x38,
// in that order, and returns 1. GUESS: the slot 0x10 and the field names.
#include "ff.h"

#define AT(T, p, off) (*(T *)((u8 *)(p) + (off)))

u8 THISCALL GUESS_468f20(u8 *self, u8 *obj) {
  static const u32 offs[8] = {0x4, 0x8, 0x14, 0x18, 0xc, 0x10, 0x1c, 0x38};
  for (int i = 0; i < 8; i++) vcall<void>(obj, 0x10, (u32)(self + offs[i]), (u32)4);
  return 1;
}
PCREG(468f20, GUESS_468f20);
