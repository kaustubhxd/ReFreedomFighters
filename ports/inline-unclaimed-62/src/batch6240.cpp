// batch6240 - unclaimed-62 claim 33 (gap band 0x561000-0x581000): two thiscall functions.
//   0x565840  calls the base constructor 0x564460 (thiscall, no argument; GUESS stub), then this[0] = 0x6a6b00, this[0x180] = 0x6a6c0c,
//             this[0x87] = 0 byte; returns this.
//   0x565b60  calls 0x565020 (thiscall, the two arguments, ret 8; GUESS stub), then 0x564600 (thiscall, argument 7; GUESS stub), returns al 0.
#include "ff.h"

extern "C" void THISCALL ext_564460(void *self);                 // exe: base constructor (thiscall, no argument)
extern "C" void THISCALL ext_564600(void *self, u32 a);          // exe: thiscall, one stack argument
extern "C" void THISCALL ext_565020(void *self, u32 a, u32 b);   // exe: thiscall, two stack arguments (ret 8)

static void wr32u(u8 *p, u32 v) { __builtin_memcpy(p, &v, 4); }

static u8 *THISCALL fn565840(u8 *self) {
  ext_564460(self);
  wr32u(self, 0x6a6b00);
  wr32u(self + 0x180, 0x6a6c0c);
  self[0x87] = 0;
  return self;
}

static u8 THISCALL fn565b60(u8 *self, u32 a, u32 b) {
  ext_565020(self, a, b);
  ext_564600(self, 7);
  return 0;
}

PCREG(565840, fn565840);
PCREG(565b60, fn565b60);
