#include "ff.h"

// 0x46eaa0: 2 insns, thiscall: getter at +0x78
u32 THISCALL fn_46eaa0(u8 *self) {
  return *(u32 *)(self + 0x78);
}
PCREG(46eaa0, fn_46eaa0);

// 0x45ede0: 5 insns, thiscall: load ecx from [ecx+8] and tail-jump to 0x4db270
extern "C" void THISCALL ext_4db270(u8 *self);
void THISCALL fn_45ede0(u8 *self) {
  self = *(u8 **)(self + 8);
  ext_4db270(self);
}
PCREG(45ede0, fn_45ede0);

// 0x45f060: 5 insns, thiscall: load ecx from [ecx+8] and tail-jump to 0x4db780
extern "C" void THISCALL ext_4db780(u8 *self);
void THISCALL fn_45f060(u8 *self) {
  self = *(u8 **)(self + 8);
  ext_4db780(self);
}
PCREG(45f060, fn_45f060);

// 0x45fc80: 5 insns, thiscall: load ecx from [ecx+8] and tail-jump to 0x4dcac0
extern "C" void THISCALL ext_4dcac0(u8 *self);
void THISCALL fn_45fc80(u8 *self) {
  self = *(u8 **)(self + 8);
  ext_4dcac0(self);
}
PCREG(45fc80, fn_45fc80);

// 0x46d8c0: 5 insns, thiscall: conditional setter
void THISCALL fn_46d8c0(u8 *self) {
  *(u32 *)(self + 0xc4) = 0;
  if (*(u32 *)(self + 0xba) == 0) {
    self[0xbf] = 0;
  }
}
PCREG(46d8c0, fn_46d8c0);
