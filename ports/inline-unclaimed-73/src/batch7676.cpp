// batch7676.cpp - area 73 batch 76 (unmentioned band rows, GUESS names): FUN_4f4a70 and FUN_4f6280.
#include "ff.h"

extern "C" void THISCALL ext_43ea20(u8 *self);
extern "C" void THISCALL ext_4ee4e0(u8 *self);
extern "C" void __attribute__((cdecl)) ext_45c510(void *p);
extern "C" void __attribute__((cdecl)) ext_4690b0(void *p, u32 n);

// 0x4f4a70 (GUESS FUN_4f4a70): ret 4, returns this. 0x43ea20 on this (no arguments); flag bit 0 gives 0x4690b0(this, 0x97) when bit 2
// is set, else 0x45c510(this).
static u8 *THISCALL guess4f4a70(u8 *self, u32 flags) {
  ext_43ea20(self);
  if (flags & 1) {
    if (flags & 4)
      ext_4690b0(self, 0x97u);
    else
      ext_45c510(self);
  }
  return self;
}
PCREG(4f4a70, guess4f4a70);

// 0x4f6280 (GUESS FUN_4f6280): ret 4, returns this. 0x4ee4e0 on this (no arguments); flag bit 0 gives 0x4690b0(this, 0xa3) when bit 2
// is set, else 0x45c510(this).
static u8 *THISCALL guess4f6280(u8 *self, u32 flags) {
  ext_4ee4e0(self);
  if (flags & 1) {
    if (flags & 4)
      ext_4690b0(self, 0xa3u);
    else
      ext_45c510(self);
  }
  return self;
}
PCREG(4f6280, guess4f6280);
