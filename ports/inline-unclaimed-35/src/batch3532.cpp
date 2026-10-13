#include "ff.h"
// batch3532.cpp - gap band claim 32 (docs/20-gap-band-561000.md): four constructors with field zeroing (GUESS names).
// Thiscall, no args: calls 0x561020 on this (stubbed), stores the vtable at +0, zeroes the listed fields, returns this.

extern "C" void THISCALL ext_561020(u8 *self);

u8 *THISCALL gapCtor5696b0(u8 *self) {
  ext_561020(self);
  *(u32 *)self = 0x6a7600;
  *(u8 *)(self + 0x1bc) = 0;
  *(u32 *)(self + 0x19c) = 0;
  *(u32 *)(self + 0x1a0) = 0;
  *(u32 *)(self + 0x1a4) = 0;
  *(u32 *)(self + 0x1a8) = 0;
  *(u32 *)(self + 0x1ac) = 0;
  *(u32 *)(self + 0x1b0) = 0;
  *(u32 *)(self + 0x1bd) = 0;
  *(u32 *)(self + 0x1c1) = 0;
  *(u32 *)(self + 0x1c9) = 0;
  return self;
}
PCREG(5696b0, gapCtor5696b0);

u8 *THISCALL gapCtor56e990(u8 *self) {
  ext_561020(self);
  *(u32 *)self = 0x6a83e8;
  *(u8 *)(self + 0x198) = 1;
  *(u8 *)(self + 0x1c9) = 0;
  *(u32 *)(self + 0x4b2) = 0;
  return self;
}
PCREG(56e990, gapCtor56e990);

u8 *THISCALL gapCtor572e40(u8 *self) {
  ext_561020(self);
  *(u32 *)self = 0x6a8ab0;
  *(u8 *)(self + 0x180) = 0;
  return self;
}
PCREG(572e40, gapCtor572e40);

u8 *THISCALL gapCtor573590(u8 *self) {
  ext_561020(self);
  *(u32 *)self = 0x6a8c30;
  *(u32 *)(self + 0x180) = 0;
  *(u32 *)(self + 0x184) = 0;
  *(u32 *)(self + 0x1b0) = 0;
  *(u32 *)(self + 0x1b4) = 0;
  *(u32 *)(self + 0x1c8) = 0;
  *(u32 *)(self + 0x1ec) = 0;
  *(u16 *)(self + 0x1f0) = 0;
  *(u32 *)(self + 0x190) = 0;
  *(u32 *)(self + 0x194) = 0;
  *(u32 *)(self + 0x198) = 0;
  *(u32 *)(self + 0x19c) = 0;
  *(u32 *)(self + 0x1a0) = 0;
  *(u32 *)(self + 0x1a4) = 0;
  *(u32 *)(self + 0x1a8) = 0;
  *(u32 *)(self + 0x1ac) = 0;
  *(u32 *)(self + 0x1fe) = 0;
  return self;
}
PCREG(573590, gapCtor573590);
