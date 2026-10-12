// batch2482.cpp - decomp area 24, batch 2482.
#include "ff.h"

extern "C" u8 THISCALL ext_45f3c0(void *self, void *ld);  // ZGEOM::Load(ZLoadGame*), AL

// 0x454490 ZGATE::Load(ZLoadGame*), thiscall, ret 4, AL.
static u8 THISCALL gateLoad(u8 *self, void *ld) {
  u8 r = ext_45f3c0(self, ld);
  if (!r)
    return r;
  vcall<void>(ld, 0x68, (void *)(self + 0x5a));
  vcall<void>(ld, 0x40, (void *)(self + 0x5c));
  return 1;
}
PCREG(454490, gateLoad);

// 0x44a610 ZLIST::RemoveNotifyGeom(unsigned int), thiscall, ret 4. The child is reloaded after each call.
static void THISCALL listRemoveNotifyGeom(u8 *self, u32 arg) {
  if (*(u32 *)(self + 0x1c) == 0)
    return;
  u8 r = vcall<u8>(*(void **)(self + 0x1c), 0x40, arg);
  if (!r)
    return;
  u32 r2 = vcall<u32>(*(void **)(self + 0x1c), 0x14);
  if (r2 == 0) {
    void *child = *(void **)(self + 0x1c);
    if (child)
      vcall<void>(child, 0x0, 1u);
    *(u32 *)(self + 0x1c) = 0;
  }
}
PCREG(44a610, listRemoveNotifyGeom);
