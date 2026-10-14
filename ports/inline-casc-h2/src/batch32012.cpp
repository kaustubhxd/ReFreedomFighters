// batch32012.cpp - h2 batch 32012: tier B tail jump functions (variant 2)
#include "ff.h"

extern "C" void ext_5626c0(u8 *self);
extern "C" void ext_571f20(u8 *self);

// 0x571f10, thiscall(self): call 0x5626c0, jmp 0x571f20 (tail call)
static void THISCALL fn571f10(u8 *self) {
  ext_5626c0(self);
  ext_571f20(self);
}
PCREG(571f10, fn571f10);
