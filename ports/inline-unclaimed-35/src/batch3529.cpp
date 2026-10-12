#include "ff.h"
// batch3529.cpp - gap band 0x561000-0x581000 claim 29 (docs/20-gap-band-561000.md): four constructors (GUESS names).
// Thiscall, no args: calls 0x561020 on this (stubbed in the harness), stores the vtable at +0, returns this.

extern "C" void THISCALL ext_561020(u8 *self);

u8 *THISCALL gapCtor569380(u8 *self) {
  ext_561020(self);
  *(u32 *)self = 0x6a746c;
  return self;
}
PCREG(569380, gapCtor569380);

u8 *THISCALL gapCtor56db70(u8 *self) {
  ext_561020(self);
  *(u32 *)self = 0x6a81d8;
  return self;
}
PCREG(56db70, gapCtor56db70);

u8 *THISCALL gapCtor571960(u8 *self) {
  ext_561020(self);
  *(u32 *)self = 0x6a8824;
  return self;
}
PCREG(571960, gapCtor571960);

u8 *THISCALL gapCtor5773f0(u8 *self) {
  ext_561020(self);
  *(u32 *)self = 0x6a95c8;
  return self;
}
PCREG(5773f0, gapCtor5773f0);
