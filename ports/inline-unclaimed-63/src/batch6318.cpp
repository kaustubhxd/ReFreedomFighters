// batch6318.cpp - unclaimed-63 batch 18 (docs/20-unclaimed-63.md): 0x51aa60 (GUESS, no GC name), a thunk: sets the vptr
// [this] = 0x69f364 and tail-jumps to 0x519430 with this in ECX (the base-class constructor, original code, stubbed by the spec).
// The tail jump is written as a call followed by return; 0x519430 takes no stack arguments, so the stack is the same.
#include "ff.h"

extern "C" void THISCALL ext_519430(void *self);   // original base constructor, stubbed by the spec

// 0x51aa60 (GUESS thunk).
static void THISCALL unnamed51aa60(u8 *self) {
  *(u32 *)self = 0x69f364u;
  ext_519430(self);
}
PCREG(51aa60, unnamed51aa60);
