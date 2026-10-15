// batch5787.cpp - unclaimed-57 (docs/20-unclaimed-57.md), batch 87: 0x5de4c0 (GUESS name unnamed_5de4c0), thiscall, one stack argument obj
// (ret 4), returns al = 1. Order: clear bit 0x40 of this+4; obj->vt[+0x10](this+0x48, 0xcc); obj->vt[+0x64](dword this+0x114);
// obj->vt[+0x4c](float this+0x118); obj->vt[+0x4c](float this+0x11c); obj->vt[+0x10](this+0x120, 0xc); obj->vt[+0x4c](float this+0x12c).
// The slots run as fake vtable stubs in the spec.
#include "ff.h"

#define VT(o) (*(void ***)(o))

typedef void(THISCALL *SlotPV)(u8 *self, u32 p, u32 v);
typedef void(THISCALL *SlotV)(u8 *self, u32 v);
typedef void(THISCALL *SlotF)(u8 *self, float f);

// 0x5de4c0, thiscall, one stack argument (GUESS name)
static u8 THISCALL unnamed5de4c0(u8 *self, u8 *obj) {
  *(u32 *)(self + 4) &= 0xffffffbfu;
  ((SlotPV)VT(obj)[0x10 / 4])(obj, (u32)(unsigned long)(self + 0x48), 0xcc);
  ((SlotV)VT(obj)[0x64 / 4])(obj, *(u32 *)(self + 0x114));
  ((SlotF)VT(obj)[0x4c / 4])(obj, *(float *)(self + 0x118));
  ((SlotF)VT(obj)[0x4c / 4])(obj, *(float *)(self + 0x11c));
  ((SlotPV)VT(obj)[0x10 / 4])(obj, (u32)(unsigned long)(self + 0x120), 0xc);
  ((SlotF)VT(obj)[0x4c / 4])(obj, *(float *)(self + 0x12c));
  return 1;
}
PCREG(5de4c0, unnamed5de4c0);
