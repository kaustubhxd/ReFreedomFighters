#include "ff.h"
// batch3533.cpp - gap band claim 33 (docs/20-gap-band-561000.md): two constructors with byte/dword loops (GUESS names).
// Thiscall, no args: calls 0x561020 on this (stubbed), stores the vtable at +0, runs the loop and the field stores, returns this.

extern "C" void THISCALL ext_561020(u8 *self);

u8 *THISCALL gapCtor56c810(u8 *self) {
  ext_561020(self);
  *(u32 *)self = 0x6a7ef8;
  for (u32 i = 0; i < 4; i++) {
    *(u8 *)(self + 0x19c + i) = 0;
    *(u8 *)(self + 0x1a0 + i) = 0;
  }
  *(u32 *)(self + 0x1c2) = 0;
  *(u8 *)(self + 0x1a4) = 0;
  *(u32 *)(self + 0x1a5) = 0x679e54;
  *(u32 *)(self + 0x1a9) = 0x6a7ff0;
  *(u32 *)(self + 0x1ad) = 0x6a7ff4;
  *(u32 *)(self + 0x1b1) = 0x6a7ff8;
  *(u8 *)(self + 0x86) = 0;
  return self;
}
PCREG(56c810, gapCtor56c810);

u8 *THISCALL gapCtor57a440(u8 *self) {
  ext_561020(self);
  *(u32 *)self = 0x6a9dbc;
  *(u8 *)(self + 0x199) = 0;
  for (u32 i = 0; i < 4; i++) {
    *(u32 *)(self + 0x184 + 4 * i) = 0xffffffffu;
    *(u8 *)(self + 0x194 + i) = 0;
  }
  *(u8 *)(self + 0x198) = 0;
  return self;
}
PCREG(57a440, gapCtor57a440);
