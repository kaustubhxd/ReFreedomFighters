// batch1124.cpp - unclaimed-11 batch 25 (gap band): five GUESS constructors over the base constructor 0x469870.
#include "ff.h"

extern "C" void THISCALL ext_469870(void *self);

// Shared shape: base constructor, then flag |= 0x20 at +4, dword 0 at +0x44, vtable at +0. Returns this.
static u8 *constructOver(u8 *self, u32 vtable) {
  ext_469870(self);
  *(u32 *)(self + 4) |= 0x20;
  *(u32 *)(self + 0x44) = 0;
  *(u32 *)self = vtable;
  return self;
}

// 0x5b7580, GUESS (vtable 0x6b2304)
static u8 *THISCALL guessCtor5b7580(u8 *self) { return constructOver(self, 0x6b2304); }
PCREG(5b7580, guessCtor5b7580);

// 0x5b7960, GUESS (vtable 0x6b245c)
static u8 *THISCALL guessCtor5b7960(u8 *self) { return constructOver(self, 0x6b245c); }
PCREG(5b7960, guessCtor5b7960);

// 0x5bbc00, GUESS (vtable 0x6b2c54)
static u8 *THISCALL guessCtor5bbc00(u8 *self) { return constructOver(self, 0x6b2c54); }
PCREG(5bbc00, guessCtor5bbc00);

// 0x5bc4b0, GUESS (vtable 0x6b2f30)
static u8 *THISCALL guessCtor5bc4b0(u8 *self) { return constructOver(self, 0x6b2f30); }
PCREG(5bc4b0, guessCtor5bc4b0);

// 0x5bdb00, GUESS (vtable 0x6b34b4)
static u8 *THISCALL guessCtor5bdb00(u8 *self) { return constructOver(self, 0x6b34b4); }
PCREG(5bdb00, guessCtor5bdb00);
