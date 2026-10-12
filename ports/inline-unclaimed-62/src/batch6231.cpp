// batch6231 - unclaimed-62 claim 24 (short leaves from the exe's function list): two small thiscall functions with one argument.
//   0x54f0b0  this+0xc = arg; then a tail jump through the vtable's slot 0x18 with the same argument (ret of the callee passes through).
//             The port makes the same call and returns; the callee pops the argument as the tail jump would.
//   0x4d1df0  returns ST0: the float at the pointer given by the vtable's slot 0x3c (one argument, the arg) on this.
#include "ff.h"

static float rdf(const u8 *p) { float v; __builtin_memcpy(&v, p, 4); return v; }

static void THISCALL fn54f0b0(u8 *self, u32 a) {
  __builtin_memcpy(self + 0xc, &a, 4);
  vcall<void>(self, 0x18, a);
}

static float THISCALL fn4d1df0(u8 *self, u32 a) {
  u32 p = vcall<u32>(self, 0x3c, a);
  return rdf((const u8 *)p);
}

PCREG(54f0b0, fn54f0b0);
PCREG(4d1df0, fn4d1df0);
