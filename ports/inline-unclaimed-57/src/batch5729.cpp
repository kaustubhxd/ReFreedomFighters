// batch5729.cpp - unclaimed-57, band batch 29 (names GUESS): four constructor-like thiscall functions, no args, return this.
// Each: 0x469870(this) (unverified, hooked and logged in the spec); dword this+4 |= 0x20; dword this+0x44 = 0; vtable at this+0.
#include "ff.h"

extern "C" void THISCALL ext_469870(u8 *self);  // unverified, original code (logged in the spec)

// 0x5d5570 (GUESS): vtable 0x6b557c.
static u8 *THISCALL unnamed5d5570(u8 *self) {
  ext_469870(self);
  *(u32 *)(self + 4) |= 0x20;
  *(u32 *)(self + 0x44) = 0;
  *(u32 *)self = 0x6b557c;
  return self;
}
PCREG(5d5570, unnamed5d5570);

// 0x5d5c90 (GUESS): vtable 0x6b58c8.
static u8 *THISCALL unnamed5d5c90(u8 *self) {
  ext_469870(self);
  *(u32 *)(self + 4) |= 0x20;
  *(u32 *)(self + 0x44) = 0;
  *(u32 *)self = 0x6b58c8;
  return self;
}
PCREG(5d5c90, unnamed5d5c90);

// 0x5dac20 (GUESS): vtable 0x6b6680.
static u8 *THISCALL unnamed5dac20(u8 *self) {
  ext_469870(self);
  *(u32 *)(self + 4) |= 0x20;
  *(u32 *)(self + 0x44) = 0;
  *(u32 *)self = 0x6b6680;
  return self;
}
PCREG(5dac20, unnamed5dac20);

// 0x5c5a40 (GUESS): vtable 0x6b431c.
static u8 *THISCALL unnamed5c5a40(u8 *self) {
  ext_469870(self);
  *(u32 *)(self + 4) |= 0x20;
  *(u32 *)(self + 0x44) = 0;
  *(u32 *)self = 0x6b431c;
  return self;
}
PCREG(5c5a40, unnamed5c5a40);

