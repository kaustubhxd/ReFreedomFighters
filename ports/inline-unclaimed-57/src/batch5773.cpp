// batch5773.cpp - unclaimed-57 (docs/20-unclaimed-57.md), batch 73: 0x5c33a0 (GUESS name unnamed_5c33a0), thiscall, one stack
// argument a (ret 4), returns al = 1. Order: clear bit 0x40 of this+4; a->vt[+0x68](this+0x114); a->vt[+0x50](this+0x115),
// (this+0x119), (this+0x11d), (this+0x121); a->vt[+0x68](this+0x125). Each slot takes one pointer into this. The slots run as
// fake vtable stubs in the spec.
#include "ff.h"

#define VT(o) (*(void ***)(o))

typedef void(THISCALL *SlotPtr)(u8 *self, u32 p);

// 0x5c33a0, thiscall, one stack argument (GUESS name)
static u8 THISCALL unnamed5c33a0(u8 *self, u8 *a) {
  *(u32 *)(self + 4) &= 0xffffffbfu;
  ((SlotPtr)VT(a)[0x68 / 4])(a, (u32)(unsigned long)(self + 0x114));
  ((SlotPtr)VT(a)[0x50 / 4])(a, (u32)(unsigned long)(self + 0x115));
  ((SlotPtr)VT(a)[0x50 / 4])(a, (u32)(unsigned long)(self + 0x119));
  ((SlotPtr)VT(a)[0x50 / 4])(a, (u32)(unsigned long)(self + 0x11d));
  ((SlotPtr)VT(a)[0x50 / 4])(a, (u32)(unsigned long)(self + 0x121));
  ((SlotPtr)VT(a)[0x68 / 4])(a, (u32)(unsigned long)(self + 0x125));
  return 1;
}
PCREG(5c33a0, unnamed5c33a0);
