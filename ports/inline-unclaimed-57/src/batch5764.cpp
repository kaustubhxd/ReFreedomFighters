// batch5764.cpp - unclaimed-57 (docs/20-unclaimed-57.md), batch 64: 0x5d8ee0 (GUESS name unnamed_5d8ee0), thiscall, one stack
// argument (the archive object ar, ret 4), returns al = 1. Order: base 0x45f3c0(this, ar) (hooked, logged); then virtual calls on ar
// with a field pointer each: ar->vt[+0x40](this+0x28); ar->vt[+0x48](this+0x2c); ar->vt[+0x48](this+0x30); ar->vt[+0x48](this+0x3c);
// ar->vt[+0x48](this+0x40); ar->vt[+0x50](this+0x38). The virtual slots and the base run as hooked stubs in the spec.
#include "ff.h"

#define VT(o) (*(void ***)(o))

typedef void(THISCALL *SlotPtr)(u8 *self, u32 p);

extern "C" void THISCALL ext_45f3c0(u8 *self, u8 *ar);  // base helper, original code (hooked in the spec)

// 0x5d8ee0, thiscall, one stack argument (the archive object), ret 4 (GUESS name)
static u8 THISCALL unnamed5d8ee0(u8 *self, u8 *ar) {
  ext_45f3c0(self, ar);
  ((SlotPtr)VT(ar)[0x40 / 4])(ar, (u32)(unsigned long)(self + 0x28));
  ((SlotPtr)VT(ar)[0x48 / 4])(ar, (u32)(unsigned long)(self + 0x2c));
  ((SlotPtr)VT(ar)[0x48 / 4])(ar, (u32)(unsigned long)(self + 0x30));
  ((SlotPtr)VT(ar)[0x48 / 4])(ar, (u32)(unsigned long)(self + 0x3c));
  ((SlotPtr)VT(ar)[0x48 / 4])(ar, (u32)(unsigned long)(self + 0x40));
  ((SlotPtr)VT(ar)[0x50 / 4])(ar, (u32)(unsigned long)(self + 0x38));
  return 1;
}
PCREG(5d8ee0, unnamed5d8ee0);
