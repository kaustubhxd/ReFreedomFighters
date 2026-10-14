// batch5728.cpp - unclaimed-57, band batch 28 (names GUESS).
// 0x5c5260 (thiscall, no args, returns this): 0x469870(this) (hooked, logged); dword this+4 |= 0x20; dword this+0x44 = 0; vtable 0x6b4180;
//   dword this+0x14e = 0; byte this+0x152 = 0.
// 0x5e0df0 (thiscall, no args): sub = dword this+0x1d0f; if sub is non-zero, 0x5a83e0(sub, float this+0x1d17) (thiscall, one float
//   argument; unverified, hooked and logged in the spec).
#include "ff.h"

extern "C" void THISCALL ext_469870(u8 *self);            // unverified, original code (logged in the spec)
extern "C" void THISCALL ext_5a83e0(u8 *self, float a);   // unverified, original code (logged in the spec)

static u8 *THISCALL unnamed5c5260(u8 *self) {
  ext_469870(self);
  *(u32 *)(self + 4) |= 0x20;
  *(u32 *)(self + 0x44) = 0;
  *(u32 *)self = 0x6b4180;
  *(u32 *)(self + 0x14e) = 0;
  self[0x152] = 0;
  return self;
}
PCREG(5c5260, unnamed5c5260);

static void THISCALL unnamed5e0df0(u8 *self) {
  u32 sub = *(u32 *)(self + 0x1d0f);
  if (sub != 0) {
    float f = *(float *)(self + 0x1d17);
    ext_5a83e0((u8 *)(unsigned long)sub, f);
  }
}
PCREG(5e0df0, unnamed5e0df0);
