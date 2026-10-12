// batch6241 - unclaimed-62 claim 34 (gap band 0x561000-0x581000): constructor 0x572e40 [thiscall, no argument, returns this]:
// calls the base constructor 0x561020 (GUESS stub by address in the spec), then this[0] = 0x6a8ab0 and this[0x180] = 0 byte.
#include "ff.h"

extern "C" void THISCALL ext_561020(void *self);   // exe: base constructor (thiscall, no argument)

static void wr32u(u8 *p, u32 v) { __builtin_memcpy(p, &v, 4); }

static u8 *THISCALL fn572e40(u8 *self) {
  ext_561020(self);
  wr32u(self, 0x6a8ab0);
  self[0x180] = 0;
  return self;
}

PCREG(572e40, fn572e40);
