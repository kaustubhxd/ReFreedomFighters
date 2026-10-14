// batch33000.cpp - cascade h3: four small 2-instruction thiscall members
#include "ff.h"

extern "C" void THISCALL ext_43de70(u8 *self);               // tail jump target, no arg
extern "C" void THISCALL ext_465660(u8 *self);               // tail jump target, no arg

// 0x445e70: read member at offset 0x192
static u32 THISCALL fn445e70(u8 *self) {
  return *(u32 *)(self + 0x192);
}
PCREG(445e70, fn445e70);

// 0x45b4d0: set self[0] to vtable, then tail jump ext_43de70
static void THISCALL fn45b4d0(u8 *self) {
  *(u32 *)self = 0x684358;
  ext_43de70(self);
}
PCREG(45b4d0, fn45b4d0);

// 0x466620: set bits in self[0x136]
static void THISCALL fn466620(u8 *self) {
  *(u32 *)(self + 0x136) |= 0x20000;
}
PCREG(466620, fn466620);

// 0x468080: set self[0] to vtable, then tail jump ext_465660
static void THISCALL fn468080(u8 *self) {
  *(u32 *)self = 0x6860b0;
  ext_465660(self);
}
PCREG(468080, fn468080);
