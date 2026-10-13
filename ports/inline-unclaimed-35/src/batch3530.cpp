#include "ff.h"
// batch3530.cpp - gap band claim 30 (docs/20-gap-band-561000.md): four constructors (GUESS names).
// Thiscall, no args: calls 0x561020 on this (stubbed), stores the vtable at +0, returns this.

extern "C" void THISCALL ext_561020(u8 *self);

u8 *THISCALL gapCtor57abc0(u8 *self) {
  ext_561020(self);
  *(u32 *)self = 0x6a9f20;
  return self;
}
PCREG(57abc0, gapCtor57abc0);

u8 *THISCALL gapCtor57aea0(u8 *self) {
  ext_561020(self);
  *(u32 *)self = 0x6aa0d4;
  return self;
}
PCREG(57aea0, gapCtor57aea0);

u8 *THISCALL gapCtor57c100(u8 *self) {
  ext_561020(self);
  *(u32 *)self = 0x6aa670;
  return self;
}
PCREG(57c100, gapCtor57c100);

u8 *THISCALL gapCtor57f1b0(u8 *self) {
  ext_561020(self);
  *(u32 *)self = 0x6aadc8;
  return self;
}
PCREG(57f1b0, gapCtor57f1b0);
