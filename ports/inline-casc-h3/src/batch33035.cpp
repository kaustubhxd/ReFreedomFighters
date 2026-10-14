// batch33035.cpp - h3 cascade batch 33035: four tier B call+conditional patterns
#include "ff.h"

extern "C" void THISCALL ext_48a880(u8 *self);           // thiscall, ret 0
extern "C" void THISCALL ext_4e50a0(u8 *self, u32 arg);  // thiscall, ret 4
extern "C" void THISCALL ext_51ab90(u8 *self);           // thiscall, ret 0
extern "C" void THISCALL ext_534d50(u8 *self, u32 arg);  // thiscall, ret 4
extern "C" void STDCALL ext_634273(u8 *p, u32 n);        // cdecl, ret 8

// 0x48ab70: thiscall(arg) ret 4: call 0x48a880, if arg&1 call 0x634273, return this
static u8 *THISCALL fn48ab70(u8 *self, u32 arg) {
  ext_48a880(self);
  if (arg & 1) ext_634273(self, 0x5da5);
  return self;
}
PCREG(48ab70, fn48ab70);

// 0x4e5050: thiscall(arg) ret 4: set vtable 0x697360, if arg&1 call 0x634273, return this
static u8 *THISCALL fn4e5050(u8 *self, u32 arg) {
  *(u32 *)self = 0x697360;
  if (arg & 1) ext_634273(self, 0x2c);
  return self;
}
PCREG(4e5050, fn4e5050);

// 0x51ab40: thiscall(arg) ret 4: call 0x51ab90, if arg&1 call 0x634273, return this
static u8 *THISCALL fn51ab40(u8 *self, u32 arg) {
  ext_51ab90(self);
  if (arg & 1) ext_634273(self, 0x138);
  return self;
}
PCREG(51ab40, fn51ab40);

// 0x534d00: thiscall(arg) ret 4: call 0x534d50, if arg&1 call 0x634273, return this
static u8 *THISCALL fn534d00(u8 *self, u32 arg) {
  ext_534d50(self, 0);
  if (arg & 1) ext_634273(self, 0x8c);
  return self;
}
PCREG(534d00, fn534d00);
