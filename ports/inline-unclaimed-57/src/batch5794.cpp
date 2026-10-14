// batch5794.cpp - unclaimed-57 (docs/20-unclaimed-57.md), batch 94: 0x5d9210 (GUESS name unnamed_5d9210), thiscall, no stack args, plain ret.
// Order: 0x5d92e0(this, this+0x44 value) (hooked: ported in batch 84); o = this+0x44; o->vt[+0x254](); t = (engine)+0x9b ->vt[+0x58](this+0x54);
// if t: 0x5d92e0(this, t) (hooked). Then f1 = (p = (engine)+0x190f, p != 0 && p->byte[+0x81] != 0) ? G(0x67da0c) : (x = sub->vt[+0x134](); flag = 0;
// x->vt[+0x90](0x67d9dc, &flag); flag != 0 ? G(0x67da0c) : 0.0f). Stores: this+0x58 = f1; this+0x5c = 0; this+0x64 = 1.0f; this+0x60 = G(0x678858) - 2*f1.
// The slot calls run through fake vtables in the spec.
#include "ff.h"

#define VT(o) (*(void ***)(o))

typedef u32(THISCALL *SlotN)(u8 *self);
typedef u32(THISCALL *SlotA)(u8 *self, u32 a);
typedef void(THISCALL *Slot2)(u8 *self, u32 a, u32 b);

extern "C" void THISCALL ext_5d92e0(u8 *self, u32 a);  // ported in batch 84, original code (hooked in the spec)

// 0x5d9210, thiscall, no stack args (GUESS name)
static void THISCALL unnamed5d9210(u8 *self) {
  ext_5d92e0(self, *(u32 *)(self + 0x44));
  u8 *o = *(u8 **)(self + 0x44);
  ((SlotN)VT(o)[0x254 / 4])(o);
  u8 *eng = G(u8 *, 0x70039c);
  u8 *sub = *(u8 **)(eng + 0x9b);
  u32 t = ((SlotA)VT(sub)[0x58 / 4])(sub, *(u32 *)(self + 0x54));
  if (t) ext_5d92e0(self, t);
  eng = G(u8 *, 0x70039c);
  u8 *p = *(u8 **)(eng + 0x190f);
  float f1;
  if (p && *(u8 *)(p + 0x81) != 0) {
    f1 = G(float, 0x67da0c);
  } else {
    sub = *(u8 **)(eng + 0x9b);
    u8 *x = (u8 *)(unsigned long)((SlotN)VT(sub)[0x134 / 4])(sub);
    u8 flag = 0;
    ((Slot2)VT(x)[0x90 / 4])(x, 0x67d9dc, (u32)(unsigned long)&flag);
    f1 = flag != 0 ? G(float, 0x67da0c) : 0.0f;
  }
  *(float *)(self + 0x58) = f1;
  *(u32 *)(self + 0x5c) = 0;
  *(u32 *)(self + 0x64) = 0x3f800000u;
  *(float *)(self + 0x60) = G(float, 0x678858) - (f1 + f1);
}
PCREG(5d9210, unnamed5d9210);
