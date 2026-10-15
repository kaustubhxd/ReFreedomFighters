// batch5801.cpp - unclaimed-57 (docs/20-unclaimed-57.md), batch 101: 0x5d6d40 (GUESS name unnamed_5d6d40), thiscall, two stack arguments (w = the
// low word of the first, arg2; ret 8), no return value. Branch A (w == this+0x50 word): obj = this+0x44; obj->vt[+0xbc](0); if arg2 == 0:
// this+0x5c = 3, return. Else: this+0x58 = (engine 0x70039c)+0x40 dword (unless the address is the same); this+0x54 = [engine+0x40] minus
// trunc((float)arg2 * G(0x67d9fc) * G(0x67862c)) (unless this+0x54 is the local's address); this+0x5c = 1, return. Branch B (w == this+0x52
// word): if arg2 == 0: obj->vt[+0x250](0); obj->vt[+0xbc](1); this+0x5c = 0, return. Else: this+0x58 = [engine+0x40]; this+0x54 = [engine+0x40]
// minus trunc((float)arg2 * ...) as in A; this+0x5c = 2. Neither: return. The address comparisons are kept as in the original.
#include "ff.h"

#define VT(o) (*(void ***)(o))

typedef void(THISCALL *SlotI)(u8 *self, u32 a);

// 0x5d6d40, thiscall, two stack arguments (GUESS name)
static void THISCALL unnamed5d6d40(u8 *self, u32 a16, u32 arg2) {
  u16 w = (u16)a16;
  u32 loc = 0;  // stands in for the original's [ebp-4] / [ebp-8] locals (their addresses are compared, never equal to a field)
  if (w == *(u16 *)(self + 0x50)) {
    u8 *obj = *(u8 **)(self + 0x44);
    ((SlotI)VT(obj)[0xbc / 4])(obj, 0);
    if (arg2 == 0) {
      *(u32 *)(self + 0x5c) = 3;
      return;
    }
    u8 *eng = G(u8 *, 0x70039c);
    if (self + 0x58 != eng + 0x40) *(u32 *)(self + 0x58) = *(u32 *)(eng + 0x40);
    eng = G(u8 *, 0x70039c);
    if (self + 0x54 != (u8 *)&loc) {
      float f = (float)(s32)arg2 * G(float, 0x67d9fc);
      f = f * G(float, 0x67862c);
      s32 t = _mm_cvttss_si32(_mm_set_ss(f));
      *(u32 *)(self + 0x54) = *(u32 *)(eng + 0x40) - (u32)t;
    }
    *(u32 *)(self + 0x5c) = 1;
    return;
  }
  if (w == *(u16 *)(self + 0x52)) {
    if (arg2 == 0) {
      u8 *obj = *(u8 **)(self + 0x44);
      ((SlotI)VT(obj)[0x250 / 4])(obj, 0);
      ((SlotI)VT(obj)[0xbc / 4])(obj, 1);
      *(u32 *)(self + 0x5c) = 0;
      return;
    }
    u8 *eng = G(u8 *, 0x70039c);
    if (self + 0x58 != eng + 0x40) *(u32 *)(self + 0x58) = *(u32 *)(eng + 0x40);
    eng = G(u8 *, 0x70039c);
    if (self + 0x54 != (u8 *)&loc) {
      float f = (float)(s32)arg2 * G(float, 0x67d9fc);
      f = f * G(float, 0x67862c);
      s32 t = _mm_cvttss_si32(_mm_set_ss(f));
      *(u32 *)(self + 0x54) = *(u32 *)(eng + 0x40) - (u32)t;
    }
    *(u32 *)(self + 0x5c) = 2;
  }
}
PCREG(5d6d40, unnamed5d6d40);
