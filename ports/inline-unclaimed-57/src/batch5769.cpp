// batch5769.cpp - unclaimed-57 (docs/20-unclaimed-57.md), batch 69: 0x5c2f30 (GUESS name unnamed_5c2f30), thiscall, no stack
// arguments, no return value (plain ret). Order: x = (engine 0x70039c)+0x9b ->vt[+0x134](); x->vt[+0x14](0x6b3d74, 5, this+0xe8, 0x10);
// x2 = (engine)+0x9b ->vt[+0x134](); x2->vt[+0x5c](0x6b3d60, 1, 2). The slot calls run through fake vtables in the spec.
#include "ff.h"

#define VT(o) (*(void ***)(o))

typedef u32(THISCALL *SlotNone)(u8 *self);
typedef void(THISCALL *Slot4)(u8 *self, u32 a, u32 b, u32 c, u32 d);
typedef void(THISCALL *Slot3)(u8 *self, u32 a, u32 b, u32 c);

// 0x5c2f30, thiscall, no stack args (GUESS name)
static void THISCALL unnamed5c2f30(u8 *self) {
  u8 *eng = G(u8 *, 0x70039c);
  u8 *sub = *(u8 **)(eng + 0x9b);
  u8 *x = (u8 *)(unsigned long)((SlotNone)VT(sub)[0x134 / 4])(sub);
  ((Slot4)VT(x)[0x14 / 4])(x, 0x6b3d74, 5, (u32)(unsigned long)(self + 0xe8), 0x10);
  eng = G(u8 *, 0x70039c);
  sub = *(u8 **)(eng + 0x9b);
  u8 *x2 = (u8 *)(unsigned long)((SlotNone)VT(sub)[0x134 / 4])(sub);
  ((Slot3)VT(x2)[0x5c / 4])(x2, 0x6b3d60, 1, 2);
}
PCREG(5c2f30, unnamed5c2f30);
