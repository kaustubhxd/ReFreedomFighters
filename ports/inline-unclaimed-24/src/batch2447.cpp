// batch2447.cpp - decomp area 24, batch 2447 (gap band).
#include "ff.h"

// 0x45c140 ZBloodSplatters::RunMark(int), thiscall, ret 4: slot 0xb8 of the sys table, called with no pushed argument; the
// caller's argument is left on the stack and popped by this function's ret 4.
static void THISCALL bloodSplattersRunMark(u8 *self, u32 arg) {
  (void)self;
  (void)arg;
  u8 *sys = G(u8 *, 0x70039c);
  u8 *tab = *(u8 **)(sys + 0x9b);
  void **vt = *(void ***)tab;
  typedef void(THISCALL * fn0)(void *);
  ((fn0)(vt[0xb8 / 4]))(tab);
}
PCREG(45c140, bloodSplattersRunMark);
