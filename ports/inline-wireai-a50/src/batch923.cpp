// batch923.cpp - residue-9 slice: 0x45a190 [thiscall (ECX = this), one stack arg (a flag dword), ret 4, returns this]. Body read in full.
// 0x45a0e0 on this (thiscall, no args; an SEH-framed routine, stood in). If bit 0 of the flag is set: if bit 2 is set, 0x4690b0 (cdecl:
// this, 0x60; the caller pops 8); else 0x45c510 (cdecl: this; an SEH-framed routine, stood in; the caller pops 4). Returns this.
#include "ff.h"

extern "C" void THISCALL ext_45a0e0(void *self);     // stood in (SEH frame not reproduced)
extern "C" void ext_4690b0(void *self, u32 n);       // stood in (cdecl)
extern "C" void ext_45c510(void *self);              // stood in (cdecl; SEH frame not reproduced)

// 0x45a190 (no name in the map).
static u8 *THISCALL Init45a190(u8 *self, u32 flag) {
  ext_45a0e0(self);
  if (flag & 1u) {
    if (flag & 4u) ext_4690b0(self, 0x60u);
    else ext_45c510(self);
  }
  return self;
}
PCREG(45a190, Init45a190);
