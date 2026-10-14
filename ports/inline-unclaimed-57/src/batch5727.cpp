// batch5727.cpp - unclaimed-57, band batch 27 (names GUESS): two constructor-like thiscall functions, no args, return this in eax.
// Each calls 0x469870 (thiscall, no args; unverified, hooked and logged in the spec), then: dword this+4 |= 0x20; dword this+0x44 = 0;
// vtable at this+0; then
//   0x5d48e0: byte this+0x5c = 0; dword this+0x5d = 0;   with vtable 0x6b5304;
//   0x5d6c70: dword this+0x54 = 0; dword this+0x58 = 0;  with vtable 0x6b5bc4.
#include "ff.h"

extern "C" void THISCALL ext_469870(u8 *self);  // unverified, original code (logged in the spec)

static u8 *THISCALL unnamed5d48e0(u8 *self) {
  ext_469870(self);
  *(u32 *)(self + 4) |= 0x20;
  *(u32 *)(self + 0x44) = 0;
  *(u32 *)self = 0x6b5304;
  self[0x5c] = 0;
  *(u32 *)(self + 0x5d) = 0;
  return self;
}
PCREG(5d48e0, unnamed5d48e0);

static u8 *THISCALL unnamed5d6c70(u8 *self) {
  ext_469870(self);
  *(u32 *)(self + 4) |= 0x20;
  *(u32 *)(self + 0x44) = 0;
  *(u32 *)self = 0x6b5bc4;
  *(u32 *)(self + 0x54) = 0;
  *(u32 *)(self + 0x58) = 0;
  return self;
}
PCREG(5d6c70, unnamed5d6c70);
