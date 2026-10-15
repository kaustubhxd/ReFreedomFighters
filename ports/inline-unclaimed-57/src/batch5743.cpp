// batch5743.cpp - unclaimed-57, band batch 43 (name GUESS): 0x5d8c90, thiscall, one stack arg (arg), ret 4. 0x45d5b0(arg) (thiscall, one
// argument; unverified, hooked and logged); r = arg->vt[+0x1e0](0x20044c) (thiscall, one argument; stubbed); if al is zero return; else
// dwords this+0x18, +0x1c, +0x20, +0x24, +0x28, +0x2c, +0x30 = the same offsets of arg.
#include "ff.h"

#define VT(o) (*(void ***)(o))

extern "C" void THISCALL ext_45d5b0(u8 *self, u8 *arg);  // unverified, original code (hooked and logged in the spec)
typedef u8(THISCALL *SlotCheck)(u8 *self, u32 a);

static void THISCALL unnamed5d8c90(u8 *self, u8 *arg) {
  ext_45d5b0(self, arg);
  u8 r = ((SlotCheck)VT(arg)[0x1e0 / 4])(arg, 0x20044c);
  if ((r & 0xff) == 0) return;
  for (u32 k = 0x18; k <= 0x30; k += 4) *(u32 *)(self + k) = *(u32 *)(arg + k);
}
PCREG(5d8c90, unnamed5d8c90);
