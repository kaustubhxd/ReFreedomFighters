// batch5774.cpp - unclaimed-57 (docs/20-unclaimed-57.md), batch 74: 0x5c2ec0 (GUESS name unnamed_5c2ec0), thiscall, no stack args,
// plain ret. Order: x = (engine 0x70039c)+0x9b ->vt[+0x134](); loc = 0; x->vt[+0x88](0x6b3d60, &loc) (fake: writes loc); if loc:
// x2 = (engine)+0x9b ->vt[+0x134](); x2->vt[+0x6c](this+0xe8, 0x6b3d74, 5) (fake, logged). The slot calls run through fake vtables in the spec.
#include "ff.h"

#define VT(o) (*(void ***)(o))

typedef u32(THISCALL *SlotNone)(u8 *self);
typedef void(THISCALL *Slot88)(u8 *self, u32 a, u32 out);
typedef void(THISCALL *Slot6c)(u8 *self, u32 p, u32 a, u32 b);

// 0x5c2ec0, thiscall, no stack args (GUESS name)
static void THISCALL unnamed5c2ec0(u8 *self) {
  u8 *eng = G(u8 *, 0x70039c);
  u8 *sub = *(u8 **)(eng + 0x9b);
  u8 *x = (u8 *)(unsigned long)((SlotNone)VT(sub)[0x134 / 4])(sub);
  u32 loc = 0;
  ((Slot88)VT(x)[0x88 / 4])(x, 0x6b3d60, (u32)(unsigned long)&loc);
  if (loc) {
    eng = G(u8 *, 0x70039c);
    sub = *(u8 **)(eng + 0x9b);
    u8 *x2 = (u8 *)(unsigned long)((SlotNone)VT(sub)[0x134 / 4])(sub);
    ((Slot6c)VT(x2)[0x6c / 4])(x2, (u32)(unsigned long)(self + 0xe8), 0x6b3d74, 5);
  }
}
PCREG(5c2ec0, unnamed5c2ec0);
