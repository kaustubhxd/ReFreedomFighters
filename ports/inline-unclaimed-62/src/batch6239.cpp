// batch6239 - unclaimed-62 claim 32 (gap band 0x561000-0x581000): two thiscall functions with two stack arguments.
//   0x573490  calls 0x562e90 (thiscall, the same two arguments, ret 8; stubbed by address in the spec: GUESS, body not ported), then
//             this[0x180] = 0 and returns al = 0.
//   0x57bd70  calls 0x565020 (thiscall, the same two arguments, ret 8; stubbed by address in the spec: GUESS, body not ported) and
//             returns al = 0.
#include "ff.h"

extern "C" void THISCALL ext_562e90(void *self, u32 a, u32 b);   // exe: thiscall, two stack arguments (ret 8)
extern "C" void THISCALL ext_565020(void *self, u32 a, u32 b);   // exe: thiscall, two stack arguments (ret 8)

static u8 THISCALL fn573490(u8 *self, u32 a, u32 b) {
  ext_562e90(self, a, b);
  self[0x180] = 0;
  return 0;
}

static u8 THISCALL fn57bd70(u8 *self, u32 a, u32 b) {
  ext_565020(self, a, b);
  return 0;
}

PCREG(573490, fn573490);
PCREG(57bd70, fn57bd70);
