// batch32013.cpp - h2 batch 32013: tier B tail jump functions (variant 3)
#include "ff.h"

extern "C" void ext_573da0(u8 *self);
extern "C" void ext_575230(u8 *self);

// 0x575150, thiscall(self): call 0x573da0, jmp 0x575230 (tail call)
static void THISCALL fn575150(u8 *self) {
  ext_573da0(self);
  ext_575230(self);
}
PCREG(575150, fn575150);
