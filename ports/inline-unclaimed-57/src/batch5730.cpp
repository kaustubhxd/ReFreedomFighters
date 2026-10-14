// batch5730.cpp - unclaimed-57, band batch 30 (names GUESS): four constructor-like thiscall functions, no args, return this.
// Each: 0x469870(this) (unverified, hooked and logged in the spec); dword this+4 |= 0x20; dword this+0x44 = 0; vtable at this+0.
#include "ff.h"

extern "C" void THISCALL ext_469870(u8 *self);  // unverified, original code (logged in the spec)

// 0x5d38a0 (GUESS): vtable 0x6b5108.
static u8 *THISCALL unnamed5d38a0(u8 *self) {
  ext_469870(self);
  *(u32 *)(self + 4) |= 0x20;
  *(u32 *)(self + 0x44) = 0;
  *(u32 *)self = 0x6b5108;
  return self;
}
PCREG(5d38a0, unnamed5d38a0);

// 0x5d6a40 (GUESS): vtable 0x6b5ae4.
static u8 *THISCALL unnamed5d6a40(u8 *self) {
  ext_469870(self);
  *(u32 *)(self + 4) |= 0x20;
  *(u32 *)(self + 0x44) = 0;
  *(u32 *)self = 0x6b5ae4;
  return self;
}
PCREG(5d6a40, unnamed5d6a40);

// 0x5dd5e0 (GUESS): vtable 0x6b6e38.
static u8 *THISCALL unnamed5dd5e0(u8 *self) {
  ext_469870(self);
  *(u32 *)(self + 4) |= 0x20;
  *(u32 *)(self + 0x44) = 0;
  *(u32 *)self = 0x6b6e38;
  return self;
}
PCREG(5dd5e0, unnamed5dd5e0);

// 0x5c7ac0 (GUESS): vtable 0x6b47b0.
static u8 *THISCALL unnamed5c7ac0(u8 *self) {
  ext_469870(self);
  *(u32 *)(self + 4) |= 0x20;
  *(u32 *)(self + 0x44) = 0;
  *(u32 *)self = 0x6b47b0;
  return self;
}
PCREG(5c7ac0, unnamed5c7ac0);

