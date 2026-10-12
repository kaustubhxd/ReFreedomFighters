// batch1911.cpp - unclaimed-66 batch 11: two of the skipped functions (GUESS names; bodies from the bytes). Thiscall.
#include "ff.h"

// 0x64fb90, GUESS FUN_0064fb90: ucomiss this+0x70 with 0.0f (0x6785d0), then lahf and test ah,0x44: the jump is taken
// (result 0) only when the compare is ordered-equal (ZF=1, PF=0). Unordered (NaN) gives 1, as do less and greater.
static u32 THISCALL leaf64fb90(u8 *self) {
  float x = *(float *)(self + 0x70);
  return (x == 0.0f) ? 0u : 1u;
}
PCREG(64fb90, leaf64fb90);

// 0x499c10, GUESS FUN_00499c10: vtable +0x10 of this with two arguments: the address of the function's own stack argument
// (its slot) and 2 (pushed second, so it is the second argument). The callee pops 8. Returns this. ret 4.
static u8 *THISCALL leaf499c10(u8 *self, u32 arg) {
  vcall<void>(self, 0x10, (void *)&arg, (u32)2);
  return self;
}
PCREG(499c10, leaf499c10);
