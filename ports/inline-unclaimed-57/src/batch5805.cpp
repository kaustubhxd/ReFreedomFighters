// batch5805.cpp - unclaimed-57 (docs/20-unclaimed-57.md), batch 105: 0x5da540 (GUESS name unnamed_5da540), thiscall, no stack args, plain ret.
// e = 0x5da470(this) (batch 99; hooked in the spec); if e == 0 return. p = (engine 0x70039c)+0x190f; p->vt[+0xb8](e); u = sub->vt[+0x58](this+0x5a)
// (sub = (engine)+0x9b); if u: e->vt[+0x27c](this+0x5a); u+0x30 |= 0x400; e+0x48 |= 0x218000. If this+0x62 != 0: e+0x30 = 5; e->vt[+0x280](2500.0f).
// Then c1 = (p && p->byte[+0x81] != 0) ? G(0x67da0c) : (x = sub->vt[+0x134](); flag = 0; x->vt[+0x90](0x67d9dc, &flag); flag ? G(0x67da0c) : 0.0f).
// this+0x76 = c1; this+0x7a = 0; this+0x82 = 1.0f; this+0x7e = G(0x678858) - 2 c1. The callee slots run as fake vtables in the spec.
#include "ff.h"

#define VT(o) (*(void ***)(o))

typedef u32(THISCALL *SlotA)(u8 *self, u32 a);
typedef u32(THISCALL *SlotN)(u8 *self);
typedef void(THISCALL *SlotF)(u8 *self, float f);
typedef void(THISCALL *Slot2)(u8 *self, u32 a, u32 b);

extern "C" u32 THISCALL ext_5da470(u8 *self);  // batch 99 function, original code (hooked in the spec)

// 0x5da540, thiscall, no stack args (GUESS name)
static void THISCALL unnamed5da540(u8 *self) {
  u8 *e = (u8 *)(unsigned long)ext_5da470(self);
  if (!e) return;
  u8 *eng = G(u8 *, 0x70039c);
  u8 *p = *(u8 **)(eng + 0x190f);
  ((SlotA)VT(p)[0xb8 / 4])(p, (u32)(unsigned long)e);
  eng = G(u8 *, 0x70039c);
  u8 *sub = *(u8 **)(eng + 0x9b);
  u32 v = *(u32 *)(self + 0x5a);
  u8 *u = (u8 *)(unsigned long)((SlotA)VT(sub)[0x58 / 4])(sub, v);
  if (u) {
    ((SlotA)VT(e)[0x27c / 4])(e, *(u32 *)(self + 0x5a));
    *(u32 *)(u + 0x30) |= 0x400;
    *(u32 *)(e + 0x48) |= 0x218000;
  }
  if (*(u32 *)(self + 0x62) != 0) {
    *(u32 *)(e + 0x30) = 5;
    ((SlotF)VT(e)[0x280 / 4])(e, 2500.0f);
  }
  eng = G(u8 *, 0x70039c);
  p = *(u8 **)(eng + 0x190f);
  float c1;
  if (p != 0 && *(u8 *)(p + 0x81) != 0) {
    c1 = G(float, 0x67da0c);
  } else {
    sub = *(u8 **)(eng + 0x9b);
    u8 *x = (u8 *)(unsigned long)((SlotN)VT(sub)[0x134 / 4])(sub);
    u8 flag = 0;
    ((Slot2)VT(x)[0x90 / 4])(x, 0x67d9dc, (u32)(unsigned long)&flag);
    c1 = flag != 0 ? G(float, 0x67da0c) : 0.0f;
  }
  *(float *)(self + 0x76) = c1;
  *(u32 *)(self + 0x7a) = 0;
  *(u32 *)(self + 0x82) = 0x3f800000u;
  *(float *)(self + 0x7e) = G(float, 0x678858) - (c1 + c1);
}
PCREG(5da540, unnamed5da540);
