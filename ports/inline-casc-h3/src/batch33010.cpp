// batch33010.cpp - cascade h3 tier B: four simple thunk functions
#include "ff.h"

extern "C" void THISCALL ext_4702b0(u8 *self);
extern "C" void THISCALL ext_4bb7c0(u8 *self);
extern "C" void THISCALL ext_4c1060(u8 *self);
extern "C" void THISCALL ext_4c4e90(u8 *self);

// 0x468310: thunk wrapper
static void THISCALL fn468310(u8 *self) {
  ext_4702b0(self);
}
PCREG(468310, fn468310);

// 0x49e670: thunk wrapper
static void THISCALL fn49e670(u8 *self) {
  ext_4bb7c0(self);
}
PCREG(49e670, fn49e670);

// 0x4bf4c0: thunk wrapper
static void THISCALL fn4bf4c0(u8 *self) {
  ext_4c1060(self);
}
PCREG(4bf4c0, fn4bf4c0);

// 0x4c4df0: thunk wrapper
static void THISCALL fn4c4df0(u8 *self) {
  ext_4c4e90(self);
}
PCREG(4c4df0, fn4c4df0);
