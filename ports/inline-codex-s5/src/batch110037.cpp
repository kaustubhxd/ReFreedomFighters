// batch5818.cpp - unclaimed-57 (docs/20-unclaimed-57.md), batch 118: 0x5d4ff0 (GUESS name unnamed_5d4ff0), thiscall, no stack args, plain ret. x87 rows:
// the products and sums are done in long double (x87 extended, the same instructions as the original; FPCW is the emulator's 0x27f), rounded to float once.
// Block 1 (this+0x48 == -1024): v = eng->vt[+0x1c0](0x6b5428, 0x19) (returns st0); b = (float)(v * G(0x67c1a0)); this+0x48 = eng+0x40 - trunc(b * G(0x67862c)).
// Block 2: o = (this+0x44)->vt[+0x50c](); if o == 0 return; if eng+0x40 <= this+0x48 return; if o->vt[+0x35c]() == 0: o->vt[+0x360](0x64);
// if !o->vt[+0x354](): o->vt[+0x2d0](6, 0); o->vt[+0x2d0](0, 0); o->vt[+0x2d0](3, 0); o->vt[+0x2d0](0, 0);
// w = eng->vt[+0x1c0](0x6b5428, 0x26); r = (float)(w * G(0x67a6ac) + G(0x67a6ac)); this+0x48 = eng+0x40 - trunc(r * G(0x67862c)).
#include "ff.h"

#define VT(o) (*(void ***)(o))

typedef float(THISCALL *SlotF2)(u8 *self, u32 a, u32 b);  // returns st0
typedef u32(THISCALL *SlotN)(u8 *self);
typedef void(THISCALL *Slot1)(u8 *self, u32 a);
typedef void(THISCALL *Slot2)(u8 *self, u32 a, u32 b);

// 0x5d4ff0, thiscall, no stack args (GUESS name)
static void THISCALL unnamed5d4ff0(u8 *self) {
  if (*(u32 *)(self + 0x48) == 0xfffffc00u) {
    u8 *eng = G(u8 *, 0x70039c);
    float v = ((SlotF2)VT(eng)[0x1c0 / 4])(eng, 0x6b5428, 0x19);
    float b = (float)((long double)v * (long double)G(float, 0x67c1a0));
    eng = G(u8 *, 0x70039c);
    s32 c = _mm_cvttss_si32(_mm_set_ss(b * G(float, 0x67862c)));
    *(u32 *)(self + 0x48) = *(u32 *)(eng + 0x40) - (u32)c;
  }
  u8 *obj = *(u8 **)(self + 0x44);
  u8 *o = (u8 *)(unsigned long)((SlotN)VT(obj)[0x50c / 4])(obj);
  if (o == 0) return;
  u8 *eng = G(u8 *, 0x70039c);
  if ((s32)*(u32 *)(eng + 0x40) <= (s32)*(u32 *)(self + 0x48)) return;
  if (((SlotN)VT(o)[0x35c / 4])(o) == 0) ((Slot1)VT(o)[0x360 / 4])(o, 0x64);
  if (!(u8)((SlotN)VT(o)[0x354 / 4])(o)) {
    ((Slot2)VT(o)[0x2d0 / 4])(o, 6, 0);
    ((Slot2)VT(o)[0x2d0 / 4])(o, 0, 0);
  }
  ((Slot2)VT(o)[0x2d0 / 4])(o, 3, 0);
  ((Slot2)VT(o)[0x2d0 / 4])(o, 0, 0);
  eng = G(u8 *, 0x70039c);
  float w = ((SlotF2)VT(eng)[0x1c0 / 4])(eng, 0x6b5428, 0x26);
  float k = G(float, 0x67a6ac);
  float r = (float)((long double)w * (long double)k + (long double)k);
  eng = G(u8 *, 0x70039c);
  s32 c2 = _mm_cvttss_si32(_mm_set_ss(r * G(float, 0x67862c)));
  *(u32 *)(self + 0x48) = *(u32 *)(eng + 0x40) - (u32)c2;
}
PCREG(5d4ff0, unnamed5d4ff0);
