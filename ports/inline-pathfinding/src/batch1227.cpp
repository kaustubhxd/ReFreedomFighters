// batch1227.cpp - pathfinding tree: ZPathfinderControl::CopyData(ZEventBase* src) [map high; ; vtable slot 4].
// thiscall, ret 4. Copies the four event fields (+0x4c, +0x4e, +0x50 as u16, +0x52 as u8) from the event, replaces the
// owned REFTAB at +0x48 with a new REFTAB(2, 0) (0x1c bytes) and adds every ref of the event's REFTAB to it.
// The old REFTAB is deleted first (vtable slot 0, flag 1). The exe's SEH frame is not reproduced.
#include "pf.h"

extern "C" void THISCALL ext_4ccbe0(void *obj, u32 a, u32 b);   // REFTAB(int, int) constructor (ret 8)

static void THISCALL pfcCopyData(u8 *self, u8 *src) {
  *(u16 *)(self + 0x4c) = *(u16 *)(src + 0x4c);
  *(u16 *)(self + 0x4e) = *(u16 *)(src + 0x4e);
  *(u16 *)(self + 0x50) = *(u16 *)(src + 0x50);
  self[0x52] = src[0x52];
  u8 *old = *(u8 **)(self + 0x48);
  if (old) vcall<void>(old, 0, 1);
  u8 *list = (u8 *)ext_41e290(0x1c);
  if (list) ext_4ccbe0(list, 2, 0);
  *(u8 **)(self + 0x48) = list;
  u8 *srcList = *(u8 **)(src + 0x48);
  if (!srcList) return;
  u32 it[4] = {0, 0, 0, 0};
  vcall<void>(srcList, 0x4c, it);
  u32 ref = vcall<u32>(srcList, 0x5c, it);
  while (it[0]) {
    vcall<void>(*(void **)(self + 0x48), 4, ref);
    ref = vcall<u32>(srcList, 0x5c, it);
  }
}
PCREG(4c5530, pfcCopyData);
