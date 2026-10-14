// batch33011.cpp - cascade h3 tier B: four more simple thunk functions
#include "ff.h"

extern "C" void THISCALL ext_4d7c30(u8 *self);
extern "C" void THISCALL ext_43ff00(u8 *self);
extern "C" void THISCALL ext_5fa590(u8 *self);
extern "C" void THISCALL ext_5355a0(u8 *self);

// 0x4d5760: thunk wrapper
static void THISCALL fn4d5760(u8 *self) {
  ext_4d7c30(self);
}
PCREG(4d5760, fn4d5760);

// 0x4f9e00: thunk wrapper
static void THISCALL fn4f9e00(u8 *self) {
  ext_43ff00(self);
}
PCREG(4f9e00, fn4f9e00);

// 0x50b7e0: thunk wrapper
static void THISCALL fn50b7e0(u8 *self) {
  ext_5fa590(self);
}
PCREG(50b7e0, fn50b7e0);

// 0x533100: thunk wrapper
static void THISCALL fn533100(u8 *self) {
  ext_5355a0(self);
}
PCREG(533100, fn533100);
