// batch5735.cpp - unclaimed-57, band batch 35 (names GUESS).
// 0x5dd020 (thiscall, no args, returns this): 0x469870(this) (hooked, logged); dword this+4 |= 0x20; dword this+0x44 = 0; vtable 0x6b6cec;
//   byte this+0x48 = 0; dword this+0x75 = 0; byte this+0x79 = 0; dword this+0x7a = 0.
// 0x5d5940 (thiscall, no args): 0x5f09b0(dword this+0x19) (thiscall, the value as ECX; unverified, hooked in the spec); if byte this+0x31 is
//   0 return; n = dword this+0x2d; if n >= 2 (unsigned) return; n = n + 1; dword this+0x2d = n; if n != 2 return; this->vt[+0x114](0x10)
//   (thiscall, one argument; unverified, stubbed in the spec).
#include "ff.h"

#define VT(o) (*(void ***)(o))

extern "C" void THISCALL ext_469870(u8 *self);      // unverified, original code (logged in the spec)
extern "C" void THISCALL ext_5f09b0(u8 *ecx);       // unverified, original code (hooked in the spec)
typedef void(THISCALL *Slot1)(u8 *self, u32 a);

static u8 *THISCALL unnamed5dd020(u8 *self) {
  ext_469870(self);
  *(u32 *)(self + 4) |= 0x20;
  *(u32 *)(self + 0x44) = 0;
  *(u32 *)self = 0x6b6cec;
  self[0x48] = 0;
  *(u32 *)(self + 0x75) = 0;
  self[0x79] = 0;
  *(u32 *)(self + 0x7a) = 0;
  return self;
}
PCREG(5dd020, unnamed5dd020);

static void THISCALL unnamed5d5940(u8 *self) {
  ext_5f09b0((u8 *)(unsigned long)*(u32 *)(self + 0x19));
  if (self[0x31] == 0) return;
  u32 n = *(u32 *)(self + 0x2d);
  if (n >= 2) return;
  n = n + 1;
  *(u32 *)(self + 0x2d) = n;
  if (n != 2) return;
  ((Slot1)VT(self)[0x114 / 4])(self, 0x10);
}
PCREG(5d5940, unnamed5d5940);
