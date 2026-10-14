// batch32011.cpp - h2 batch 32011: tier B tail jump functions
#include "ff.h"

extern "C" void ext_5626c0(u8 *self);
extern "C" void ext_5709d0(u8 *self);

// 0x570920, thiscall(self): call 0x5626c0, jmp 0x5709d0 (tail call)
static void THISCALL fn570920(u8 *self) {
  ext_5626c0(self);
  ext_5709d0(self);
}
PCREG(570920, fn570920);
