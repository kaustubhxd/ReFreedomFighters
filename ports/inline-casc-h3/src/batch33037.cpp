// batch33037.cpp - h3 cascade batch 33037: four tier B call+or+init patterns
#include "ff.h"

extern "C" void THISCALL ext_469870(u8 *self);  // thiscall, ret 0

// 0x5bbc00: thiscall (no args): call 0x469870, OR field, clear fields, set vtable, return this
static u8 *THISCALL fn5bbc00(u8 *self) {
  ext_469870(self);
  *(u32 *)(self + 0x4) |= 0x20;
  *(u32 *)(self + 0x44) = 0;
  *(u32 *)self = 0x6b2c54;
  return self;
}
PCREG(5bbc00, fn5bbc00);

// 0x5c5a40: same pattern with different vtable
static u8 *THISCALL fn5c5a40(u8 *self) {
  ext_469870(self);
  *(u32 *)(self + 0x4) |= 0x20;
  *(u32 *)(self + 0x44) = 0;
  *(u32 *)self = 0x6b431c;
  return self;
}
PCREG(5c5a40, fn5c5a40);

// 0x5d5570: same pattern with different vtable
static u8 *THISCALL fn5d5570(u8 *self) {
  ext_469870(self);
  *(u32 *)(self + 0x4) |= 0x20;
  *(u32 *)(self + 0x44) = 0;
  *(u32 *)self = 0x6b557c;
  return self;
}
PCREG(5d5570, fn5d5570);

// 0x5dac20: same pattern with different vtable
static u8 *THISCALL fn5dac20(u8 *self) {
  ext_469870(self);
  *(u32 *)(self + 0x4) |= 0x20;
  *(u32 *)(self + 0x44) = 0;
  *(u32 *)self = 0x6b6680;
  return self;
}
PCREG(5dac20, fn5dac20);
