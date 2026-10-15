// batch5812.cpp - unclaimed-57 (docs/20-unclaimed-57.md), batch 112: 0x5dd990 (GUESS name unnamed_5dd990), thiscall, two stack arguments (a16: low word
// compared; v dword; ret 8), returns 0. Branch 1 (w == this+0x48): obj->vt[+0xbc](0); if v == 0: obj->vt[+0x250](1), this+0x5c = 3; else this+0x50 =
// engine+0x40 (unless the same address), this+0x4c = engine+0x40 - trunc((float)v * G(0x67d9fc) * G(0x67862c)), this+0x5c = 1. Branch 2 (w == this+0x4a):
// if v == 0: obj->vt[+0xbc](1), this+0x5c = v; else obj->vt[+0xbc](0), obj->vt[+0x250](0xfe), the same two stores, this+0x5c = 2.
#include "ff.h"

#define VT(o) (*(void ***)(o))

typedef void(THISCALL *SlotI)(u8 *self, u32 a);

// 0x5dd990, thiscall, two stack arguments (GUESS name)
static u32 THISCALL unnamed5dd990(u8 *self, u32 a16, u32 v) {
  u16 w = (u16)a16;
  u32 loc = 0;  // stands in for the original's [ebp-4] / [ebp-8] locals (their addresses are compared, never equal to a field)
  if (w == *(u16 *)(self + 0x48)) {
    u8 *obj = *(u8 **)(self + 0x44);
    ((SlotI)VT(obj)[0xbc / 4])(obj, 0);
    if (v == 0) {
      obj = *(u8 **)(self + 0x44);
      ((SlotI)VT(obj)[0x250 / 4])(obj, 1);
      *(u32 *)(self + 0x5c) = 3;
      return 0;
    }
    u8 *eng = G(u8 *, 0x70039c);
    if (self + 0x50 != eng + 0x40) *(u32 *)(self + 0x50) = *(u32 *)(eng + 0x40);
    eng = G(u8 *, 0x70039c);
    if (self + 0x4c != (u8 *)&loc) {
      float f = (float)(s32)v * G(float, 0x67d9fc);
      f = f * G(float, 0x67862c);
      s32 t = _mm_cvttss_si32(_mm_set_ss(f));
      *(u32 *)(self + 0x4c) = *(u32 *)(eng + 0x40) - (u32)t;
    }
    *(u32 *)(self + 0x5c) = 1;
    return 0;
  }
  if (w == *(u16 *)(self + 0x4a)) {
    u8 *obj = *(u8 **)(self + 0x44);
    if (v == 0) {
      ((SlotI)VT(obj)[0xbc / 4])(obj, 1);
      *(u32 *)(self + 0x5c) = v;
      return 0;
    }
    ((SlotI)VT(obj)[0xbc / 4])(obj, 0);
    obj = *(u8 **)(self + 0x44);
    ((SlotI)VT(obj)[0x250 / 4])(obj, 0xfe);
    u8 *eng = G(u8 *, 0x70039c);
    if (self + 0x50 != eng + 0x40) *(u32 *)(self + 0x50) = *(u32 *)(eng + 0x40);
    eng = G(u8 *, 0x70039c);
    if (self + 0x4c != (u8 *)&loc) {
      float f = (float)(s32)v * G(float, 0x67d9fc);
      f = f * G(float, 0x67862c);
      s32 t = _mm_cvttss_si32(_mm_set_ss(f));
      *(u32 *)(self + 0x4c) = *(u32 *)(eng + 0x40) - (u32)t;
    }
    *(u32 *)(self + 0x5c) = 2;
  }
  return 0;
}
PCREG(5dd990, unnamed5dd990);
