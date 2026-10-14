// batch5765.cpp - unclaimed-57 (docs/20-unclaimed-57.md), batch 65: 0x5d8f40 (GUESS name unnamed_5d8f40), thiscall, one stack
// argument (the archive object ar, ret 4), returns al = 1. Order: base 0x45f960(this, ar) (hooked, logged); ar->vt[+0x3c](this+0x28);
// ar->vt[+0x44](this+0x2c), (this+0x30), (this+0x3c), (this+0x40) (dword values); ar->vt[+0x4c](float this+0x38). Each slot call passes
// the value itself, not a pointer. The base and the slots run as hooked stubs in the spec.
#include "ff.h"

#define VT(o) (*(void ***)(o))

typedef void(THISCALL *SlotVal)(u8 *self, u32 v);
typedef void(THISCALL *SlotFl)(u8 *self, float v);

extern "C" void THISCALL ext_45f960(u8 *self, u8 *ar);  // base helper, original code (hooked in the spec)

// 0x5d8f40, thiscall, one stack argument (the archive object), ret 4 (GUESS name)
static u8 THISCALL unnamed5d8f40(u8 *self, u8 *ar) {
  ext_45f960(self, ar);
  ((SlotVal)VT(ar)[0x3c / 4])(ar, *(u32 *)(self + 0x28));
  ((SlotVal)VT(ar)[0x44 / 4])(ar, *(u32 *)(self + 0x2c));
  ((SlotVal)VT(ar)[0x44 / 4])(ar, *(u32 *)(self + 0x30));
  ((SlotVal)VT(ar)[0x44 / 4])(ar, *(u32 *)(self + 0x3c));
  ((SlotVal)VT(ar)[0x44 / 4])(ar, *(u32 *)(self + 0x40));
  ((SlotFl)VT(ar)[0x4c / 4])(ar, *(float *)(self + 0x38));
  return 1;
}
PCREG(5d8f40, unnamed5d8f40);
