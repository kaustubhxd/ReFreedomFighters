// batch5789.cpp - unclaimed-57 (docs/20-unclaimed-57.md), batch 89: 0x5c3310 (GUESS name unnamed_5c3310), thiscall, one stack argument obj
// (ret 4), returns al = 1. Order: clear bit 0x40 of this+4; obj->vt[+0x60](byte this+0x114); obj->vt[+0x4c](float this+0x115);
// obj->vt[+0x4c](float this+0x119); obj->vt[+0x4c](float this+0x11d); obj->vt[+0x4c](float this+0x121); obj->vt[+0x60](byte this+0x125).
// The float reads are unaligned (x86). The slots run as fake vtable stubs in the spec.
#include "ff.h"

#define VT(o) (*(void ***)(o))

typedef void(THISCALL *SlotV)(u8 *self, u32 v);
typedef void(THISCALL *SlotF)(u8 *self, float f);

// 0x5c3310, thiscall, one stack argument (GUESS name)
static u8 THISCALL unnamed5c3310(u8 *self, u8 *obj) {
  *(u32 *)(self + 4) &= 0xffffffbfu;
  ((SlotV)VT(obj)[0x60 / 4])(obj, (u32)*(u8 *)(self + 0x114));
  ((SlotF)VT(obj)[0x4c / 4])(obj, *(float *)(self + 0x115));
  ((SlotF)VT(obj)[0x4c / 4])(obj, *(float *)(self + 0x119));
  ((SlotF)VT(obj)[0x4c / 4])(obj, *(float *)(self + 0x11d));
  ((SlotF)VT(obj)[0x4c / 4])(obj, *(float *)(self + 0x121));
  ((SlotV)VT(obj)[0x60 / 4])(obj, (u32)*(u8 *)(self + 0x125));
  return 1;
}
PCREG(5c3310, unnamed5c3310);
