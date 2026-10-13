// batch4131.cpp - unclaimed-41 batch 31 (core-todo residue-19): 0x55f9f0 FUN_55f9f0 (GUESS name; thiscall, no arguments, ret 0).
// The body is mov eax, 0x6a4b80; ret: a constant getter.
#include "ff.h"

static u32 THISCALL fn55f9f0(u8 *self) {
  (void)self;
  return 0x6a4b80u;
}
PCREG(55f9f0, fn55f9f0);
