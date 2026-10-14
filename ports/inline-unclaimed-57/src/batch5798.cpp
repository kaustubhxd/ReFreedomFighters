// batch5798.cpp - unclaimed-57 (docs/20-unclaimed-57.md), batch 98: 0x5d9e20 (GUESS name unnamed_5d9e20), thiscall, no stack args, plain ret.
// Block 1: e1 = sub->vt[+0x58](this+0x48) (sub = (engine 0x70039c)+0x9b); e1->vt[+0x27c](this+0x4c); e2 = sub->vt[+0x58](this+0x4c);
// e2+0x30 |= 0x400; e1+0x48 = 0x218000; e1+0x30 = 0; e1->vt[+0x250](). Block 2 with c = this+0x50, d = this+0x54: e3 = sub->vt[+0x58](c);
// e3->vt[+0x27c](d); e4 = sub->vt[+0x58](d); e4+0x30 |= 0x400; e3+0x48 = 0x218000; e3+0x30 = 0; e3->vt[+0x250](). Finally this+0x88,
// +0x90, +0x94, +0x8c = 0. The engine is reloaded before each lookup, as the original does. The slots run as fake vtables in the spec.
#include "ff.h"

#define VT(o) (*(void ***)(o))

typedef u32(THISCALL *SlotA)(u8 *self, u32 a);
typedef void(THISCALL *SlotV)(u8 *self, u32 v);
typedef void(THISCALL *SlotN)(u8 *self);

// 0x5d9e20, thiscall, no stack args (GUESS name)
static void THISCALL unnamed5d9e20(u8 *self) {
  u8 *eng = G(u8 *, 0x70039c);
  u8 *sub = *(u8 **)(eng + 0x9b);
  u32 a = *(u32 *)(self + 0x48);
  u32 b = *(u32 *)(self + 0x4c);
  u8 *e1 = (u8 *)(unsigned long)((SlotA)VT(sub)[0x58 / 4])(sub, a);
  ((SlotV)VT(e1)[0x27c / 4])(e1, b);
  eng = G(u8 *, 0x70039c);
  sub = *(u8 **)(eng + 0x9b);
  u8 *e2 = (u8 *)(unsigned long)((SlotA)VT(sub)[0x58 / 4])(sub, b);
  *(u32 *)(e2 + 0x30) |= 0x400;
  *(u32 *)(e1 + 0x48) = 0x218000;
  *(u32 *)(e1 + 0x30) = 0;
  ((SlotN)VT(e1)[0x250 / 4])(e1);
  eng = G(u8 *, 0x70039c);
  sub = *(u8 **)(eng + 0x9b);
  u32 c = *(u32 *)(self + 0x50);
  u32 d = *(u32 *)(self + 0x54);
  u8 *e3 = (u8 *)(unsigned long)((SlotA)VT(sub)[0x58 / 4])(sub, c);
  ((SlotV)VT(e3)[0x27c / 4])(e3, d);
  eng = G(u8 *, 0x70039c);
  sub = *(u8 **)(eng + 0x9b);
  u8 *e4 = (u8 *)(unsigned long)((SlotA)VT(sub)[0x58 / 4])(sub, d);
  *(u32 *)(e4 + 0x30) |= 0x400;
  *(u32 *)(e3 + 0x48) = 0x218000;
  *(u32 *)(e3 + 0x30) = 0;
  ((SlotN)VT(e3)[0x250 / 4])(e3);
  *(u32 *)(self + 0x88) = 0;
  *(u32 *)(self + 0x90) = 0;
  *(u32 *)(self + 0x94) = 0;
  *(u32 *)(self + 0x8c) = 0;
}
PCREG(5d9e20, unnamed5d9e20);
