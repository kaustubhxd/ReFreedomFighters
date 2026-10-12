// batch7272.cpp - area 73 batch 72 (gap band, GUESS name): FUN_4ee570.
#include "ff.h"

extern "C" void THISCALL ext_43ea20(u8 *self);
extern "C" void __attribute__((cdecl)) ext_45c510(void *p);
extern "C" void __attribute__((cdecl)) ext_4690b0(void *p, u32 n);

// 0x4ee570 (GUESS FUN_4ee570): ret 4, returns this. 0x43ea20 is called on this with no arguments. When the flag's low bit is set,
// bit 2 selects 0x4690b0(this, 0x60) and otherwise 0x45c510(this) is called (both cdecl).
static u8 *THISCALL guess4ee570(u8 *self, u32 flags) {
  ext_43ea20(self);
  if (flags & 1) {
    if (flags & 4)
      ext_4690b0(self, 0x60u);
    else
      ext_45c510(self);
  }
  return self;
}
PCREG(4ee570, guess4ee570);
