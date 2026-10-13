#include "ff.h"
// batch977.cpp - unclaimed-80 residue-19 (docs/20-unclaimed-80.md), batch 55: 0x575930 (thiscall, self in ecx, one stack argument a, ret 4).
// If [self+0x216] != 0 and a == 1 and 0x575800(self) (thiscall, GUESS) returns nonzero: return 1 (al). Otherwise return 0x574250(self, a)
// (thiscall, one argument, GUESS, callee-cleaned; eax passes through).

extern "C" u8 THISCALL ext_575800(u8 *self);
extern "C" u32 THISCALL ext_574250(u8 *self, u32 a);

static u32 THISCALL zg575930(u8 *self, u32 a) {
  if (*(u8 *)(self + 0x216) != 0 && a == 1) {
    if (ext_575800(self) != 0) return 1;
  }
  return ext_574250(self, a);
}
PCREG(575930, zg575930);
