// batch5701.cpp - unclaimed-57 (docs/20-unclaimed-57.md), batch 1: ZFFSearchLightAddActors::Load(ZLoadGame*) (0x5c5cc0),
// thiscall, one argument (the ZLoadGame), ret 4, returns al = 1. Clears bit 0x40 of this+4; load->vt[+0x40](this+0x48);
// load->vt[+0x48](this+0x4c). The two load slots are unverified callees, stubbed in the spec.
#include "ff.h"

#define VT(o) (*(void ***)(o))

typedef void(THISCALL *SlotLoad)(u8 *self, u32 a);

// 0x5c5cc0, ZFFSearchLightAddActors::Load(ZLoadGame*) (high)
static u8 THISCALL searchLightAddActorsLoad(u8 *self, u8 *load) {
  *(u32 *)(self + 4) &= 0xffffffbfu;
  ((SlotLoad)VT(load)[0x40 / 4])(load, (u32)(unsigned long)(self + 0x48));
  ((SlotLoad)VT(load)[0x48 / 4])(load, (u32)(unsigned long)(self + 0x4c));
  return 1;
}
PCREG(5c5cc0, searchLightAddActorsLoad);
