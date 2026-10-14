// batch5736.cpp - unclaimed-57, band batch 36 (names GUESS).
// 0x5c4530 (thiscall, no args, returns this): 0x469870(this) (hooked, logged); dword this+4 |= 0x20; dword this+0x44 = 0; vtable 0x6b4088;
//   dword this+0x5c = 0; dword this+0x58 = 0; dword this+0x4c = 0; dword this+0x60 = 0; dword this+0x54 = 0.
// 0x5d5730 (thiscall, three stack args (a, b, c), ret 0xc, returns this): 0x43de40(this, a, b, c) (hooked, logged; callee pops 12);
//   vtable 0x6b5610; byte this+0x18 = 0; dword this+0x19 = 0; dword this+0x25 = 0; dword this+0x29 = 0; dword this+0x2d = 0;
//   byte this+0x31 = 0; dword this+0x32 = 0.
#include "ff.h"

extern "C" void THISCALL ext_469870(u8 *self);                      // unverified, original code (logged in the spec)
extern "C" void THISCALL ext_43de40(u8 *self, u32 a, u32 b, u32 c);  // unverified, original code (logged in the spec)

static u8 *THISCALL unnamed5c4530(u8 *self) {
  ext_469870(self);
  *(u32 *)(self + 4) |= 0x20;
  *(u32 *)(self + 0x44) = 0;
  *(u32 *)self = 0x6b4088;
  *(u32 *)(self + 0x5c) = 0;
  *(u32 *)(self + 0x58) = 0;
  *(u32 *)(self + 0x4c) = 0;
  *(u32 *)(self + 0x60) = 0;
  *(u32 *)(self + 0x54) = 0;
  return self;
}
PCREG(5c4530, unnamed5c4530);

static u8 *THISCALL unnamed5d5730(u8 *self, u32 a, u32 b, u32 c) {
  ext_43de40(self, a, b, c);
  *(u32 *)self = 0x6b5610;
  self[0x18] = 0;
  *(u32 *)(self + 0x19) = 0;
  *(u32 *)(self + 0x25) = 0;
  *(u32 *)(self + 0x29) = 0;
  *(u32 *)(self + 0x2d) = 0;
  self[0x31] = 0;
  *(u32 *)(self + 0x32) = 0;
  return self;
}
PCREG(5d5730, unnamed5d5730);
