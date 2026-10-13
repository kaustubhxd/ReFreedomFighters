#include "ff.h"
// batch2752.cpp - unclaimed-27 batch 52 (residue 6). FUN_004f3fe0 (GUESS): thiscall, two stack arguments (unused), ret 8.
// Calls vtable slot +0xbc of this with one argument 0 (thiscall, callee pops), then returns false (xor al, al).
static u8 THISCALL funcVcallBc(u8 *self, u32 a, u32 b) {
  (void)a; (void)b;
  typedef u32(THISCALL * F)(u8 *, u32);
  (*(F **)self)[0xbc / 4](self, 0);
  return 0;
}
PCREG(4f3fe0, funcVcallBc);
