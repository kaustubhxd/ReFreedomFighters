// batch5785.cpp - unclaimed-57 (docs/20-unclaimed-57.md), batch 85: 0x5c4b70 (GUESS name unnamed_5c4b70), thiscall, no stack args, plain ret.
// Order: x = (engine 0x70039c)+0x9b ->vt[+0x134](); flag = 0 (byte); x->vt[+0x90](0x68a9d4, &flag) (fake); if flag != 0 return;
// y = (engine)+0x9b ->vt[+0x138](); local = 0; y->vt[+0x88](0x681320, &local) (fake); this+0x60 = (engine)+0x9b ->vt[+0x58](local) (fake).
#include "ff.h"

#define VT(o) (*(void ***)(o))

typedef u32(THISCALL *SlotNone)(u8 *self);
typedef void(THISCALL *Slot2)(u8 *self, u32 a, u32 b);
typedef u32(THISCALL *Slot1)(u8 *self, u32 a);

// 0x5c4b70, thiscall, no stack args (GUESS name)
static void THISCALL unnamed5c4b70(u8 *self) {
  u8 *eng = G(u8 *, 0x70039c);
  u8 *sub = *(u8 **)(eng + 0x9b);
  u8 *x = (u8 *)(unsigned long)((SlotNone)VT(sub)[0x134 / 4])(sub);
  u8 flag = 0;
  ((Slot2)VT(x)[0x90 / 4])(x, 0x68a9d4, (u32)(unsigned long)&flag);
  if (flag != 0) return;
  eng = G(u8 *, 0x70039c);
  sub = *(u8 **)(eng + 0x9b);
  u8 *y = (u8 *)(unsigned long)((SlotNone)VT(sub)[0x138 / 4])(sub);
  u32 local = 0;
  ((Slot2)VT(y)[0x88 / 4])(y, 0x681320, (u32)(unsigned long)&local);
  eng = G(u8 *, 0x70039c);
  sub = *(u8 **)(eng + 0x9b);
  *(u32 *)(self + 0x60) = ((Slot1)VT(sub)[0x58 / 4])(sub, local);
}
PCREG(5c4b70, unnamed5c4b70);
