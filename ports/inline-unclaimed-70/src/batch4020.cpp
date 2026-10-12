// batch4020.cpp - area 70 (slice 4/5), batch 4020: two pure initialisers (names GUESS).
#include "ff.h"

// 0x5aef10 (name GUESS): thiscall, no arguments, plain ret. Zeroes the sixteen dwords at [this+0x00 .. +0x3c].
static void THISCALL zero16(u32 *self) {
  for (int i = 0; i < 16; i++) self[i] = 0;
}
PCREG(5aef10, zero16);

// 0x487650 (name GUESS): thiscall (ECX = this), two stack arguments (a at [ebp+8], b at [ebp+0xc]), ret 8. Stores a at +4
// and b at +0x10, zeroes +8, +0xc, +0x14 and +0x18, stores the vtable 0x68d14c at [this], clears the byte at +0x1c and
// returns this.
static u8 *THISCALL init487650(u8 *self, u32 a, u32 b) {
  u32 *d = (u32 *)self;
  d[1] = a;
  d[4] = b;
  d[3] = 0;
  d[5] = 0;
  d[6] = 0;
  d[2] = 0;
  d[0] = 0x68d14c;
  self[0x1c] = 0;
  return self;
}
PCREG(487650, init487650);
