// batch6238 - unclaimed-62 claim 31 (gap band 0x561000-0x581000): eight constructors with one shape:
//   call the base constructor 0x561020 (thiscall, no argument; stubbed by address in the spec: GUESS, its body is not ported here),
//   then this[0] = a vtable, and return this (eax).
#include "ff.h"

extern "C" void THISCALL ext_561020(void *self);   // exe: base constructor (thiscall, no argument)

static void wr32u(u8 *p, u32 v) { __builtin_memcpy(p, &v, 4); }

template <u32 VT> static u8 *THISCALL ctorShape(u8 *self) {
  ext_561020(self);
  wr32u(self, VT);
  return self;
}
PCREG(569380, ctorShape<0x6a746c>);
PCREG(56db70, ctorShape<0x6a81d8>);
PCREG(571960, ctorShape<0x6a8824>);
PCREG(5773f0, ctorShape<0x6a95c8>);
PCREG(57a3b0, ctorShape<0x6a9c80>);
PCREG(57abc0, ctorShape<0x6a9f20>);
PCREG(57c100, ctorShape<0x6aa670>);
PCREG(57f1b0, ctorShape<0x6aadc8>);
