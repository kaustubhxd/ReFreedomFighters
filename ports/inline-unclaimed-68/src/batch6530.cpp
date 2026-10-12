// batch6530.cpp - unclaimed-68 batch 53 (claim 53, gap band). Name is a GUESS (CAction::Init2, low; from the working notes).
#include "ff.h"

// 0x4a1270: a checksum stub with no stack arguments, exe code run as is (its effects are not modelled; GUESS).
extern "C" void THISCALL ext_4a1270(u8 *self);

// 0x4a1130, CAction::Init2() (GUESS name): thiscall, no arguments, plain ret. If the byte at this+0x63 is zero, set it to 1 and
// tail-jump to 0x4a1270 (called here and returned from, which is the same thing with no stack arguments).
static void THISCALL actionInit2(u8 *self) {
  if (self[0x63] == 0) {
    self[0x63] = 1;
    ext_4a1270(self);
  }
}
PCREG(4a1130, actionInit2);
