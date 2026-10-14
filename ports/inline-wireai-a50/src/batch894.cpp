// batch894.cpp - gap band slice: 0x420030 [15 instr, thiscall, one stack arg (a flag byte), ret 4, returns this]. Calls 0x41fed0 on
// this, then if bit 0 of the flag is set calls 0x634273 (cdecl, this and 0x2683), and returns this.
#include "ff.h"

extern "C" void THISCALL ext_41fed0(void *self);                 // stood in by the harness
extern "C" void ext_634273(void *obj, u32 n);                    // cdecl (stood in); exe pops its two words

// 0x420030 (name GUESS "Flush420030").
static u8 *THISCALL Flush420030(u8 *self, u32 flag) {
  ext_41fed0(self);
  if (flag & 1u) ext_634273(self, 0x2683u);
  return self;
}
PCREG(420030, Flush420030);
