// batch1048.cpp - unclaimed-04 batch 48 (docs/20-unclaimed-04.md): two thiscall functions with two stack arguments (ret 8).
// The helpers are original code bound to their exe addresses; the spec hooks them by address (GUESS: bodies not ported).
#include "ff.h"

extern "C" void THISCALL ext_562e90(void *self, u32 a, u32 b);  // helper, hooked by address (GUESS)
extern "C" void THISCALL ext_56f2d0(void *self);                // helper, hooked by address (GUESS)
extern "C" void THISCALL ext_573930(void *self, u32 a, u32 b);  // helper, hooked by address (GUESS)
extern "C" void THISCALL ext_574ff0(void *self);                // helper, hooked by address (GUESS)

// 0x56fa70. The flag is the low byte of b. Returns 0 (al).
static u8 THISCALL unk56fa70(u8 *self, u32 a, u32 b) {
  ext_562e90(self, a, b);
  if ((u8)b != 0) {
    ext_56f2d0(self);
    self[0x1ed] = 0;
  }
  self[0x196] = 0;
  return 0;
}
PCREG(56fa70, unk56fa70);

// 0x574e30. Returns nothing.
static void THISCALL unk574e30(u8 *self, u32 a, u32 b) {
  if (self[0x88] != 0) {
    ext_573930(self, a, b);
    if (b == 2 && self[0x21b] != 0) ext_574ff0(self);
  }
}
PCREG(574e30, unk574e30);
