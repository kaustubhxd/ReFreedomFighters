// batch5734.cpp - unclaimed-57, band batch 34 (names GUESS).
// 0x5d8520 (thiscall, no args, returns this): 0x469870(this) (hooked, logged); dword this+4 |= 0x20; dword this+0x44 = 0; vtable 0x6b5f30;
//   dword this+0x50 = 0; dword this+0x4c = 0; byte this+0x54 = 1.
// 0x5d8840 (thiscall, three stack args (a, b, c), ret 0xc, returns this): 0x43de40(this, a, b, c) (thiscall, three args; unverified,
//   hooked and logged in the spec); vtable 0x6b5fc8; dword this+0x20 = 0; dword this+0x44 = 0.
#include "ff.h"

extern "C" void THISCALL ext_469870(u8 *self);                              // unverified, original code (logged in the spec)
extern "C" void THISCALL ext_43de40(u8 *self, u32 a, u32 b, u32 c);         // unverified, original code (logged in the spec)

static u8 *THISCALL unnamed5d8520(u8 *self) {
  ext_469870(self);
  *(u32 *)(self + 4) |= 0x20;
  *(u32 *)(self + 0x44) = 0;
  *(u32 *)self = 0x6b5f30;
  *(u32 *)(self + 0x50) = 0;
  *(u32 *)(self + 0x4c) = 0;
  self[0x54] = 1;
  return self;
}
PCREG(5d8520, unnamed5d8520);

static u8 *THISCALL unnamed5d8840(u8 *self, u32 a, u32 b, u32 c) {
  ext_43de40(self, a, b, c);
  *(u32 *)self = 0x6b5fc8;
  *(u32 *)(self + 0x20) = 0;
  *(u32 *)(self + 0x44) = 0;
  return self;
}
PCREG(5d8840, unnamed5d8840);
