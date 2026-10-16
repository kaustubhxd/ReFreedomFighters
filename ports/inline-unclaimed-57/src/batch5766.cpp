// batch5766.cpp - unclaimed-57 (docs/20-unclaimed-57.md), batch 66: 0x5d5620 (GUESS name unnamed_5d5620), thiscall, no stack arguments.
// Original ends with a tail jump (jmp [vt+0x250]) through the first object, which takes no arguments, so the port calls it last and returns.
// Order: e = engine->+0x9b ->vt[+0x58](this+0x48); e->vt[+0x27c](this+0x4c); o = engine->+0x9b ->vt[+0x58](this+0x4c); o->+0x30 |= 0x400;
// e->+0x48 = 0x218000; e->+0x30 = 0; e->vt[+0x250](e). The slot calls run through fake vtables in the spec.
#include "ff.h"

#define VT(o) (*(void ***)(o))

typedef u32(THISCALL *SlotA)(u8 *self, u32 a);
typedef void(THISCALL *SlotV)(u8 *self, u32 a);
typedef void(THISCALL *SlotN)(u8 *self);

// 0x5d5620, thiscall, no stack args (GUESS name)
static void THISCALL unnamed5d5620(u8 *self) {
  u8 *eng = G(u8 *, 0x70039c);
  u8 *sub = *(u8 **)(eng + 0x9b);
  u8 *e = (u8 *)(unsigned long)((SlotA)VT(sub)[0x58 / 4])(sub, *(u32 *)(self + 0x48));
  ((SlotV)VT(e)[0x27c / 4])(e, *(u32 *)(self + 0x4c));
  u8 *o = (u8 *)(unsigned long)((SlotA)VT(sub)[0x58 / 4])(sub, *(u32 *)(self + 0x4c));
  *(u32 *)(o + 0x30) |= 0x400;
  *(u32 *)(e + 0x48) = 0x218000;
  *(u32 *)(e + 0x30) = 0;
  ((SlotN)VT(e)[0x250 / 4])(e);
}
PCREG(5d5620, unnamed5d5620);
