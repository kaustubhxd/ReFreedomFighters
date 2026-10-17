// batch5783.cpp - unclaimed-57 (docs/20-unclaimed-57.md), batch 83: 0x5c6370 (GUESS name unnamed_5c6370), thiscall, two stack arguments
// (flag, obj; ret 8), no return value. The function does not use this. Order: if obj == 0 return; local = 0; obj->vt[+0x4c](&local) (fake);
// h = obj->vt[+0x5c](&local) (fake); if local == 0 return; loop: r = (engine 0x70039c)+0x9b ->vt[+0x58](h) (fake); if r: if flag low byte
// == 0 r->vt[+0x28]() else r->vt[+0x2c]() (fakes); h = obj->vt[+0x5c](&local) (fake); while local != 0.
#include "ff.h"

#define VT(o) (*(void ***)(o))

typedef u32(THISCALL *SlotA)(u8 *self, u32 a);
typedef void(THISCALL *SlotN)(u8 *self);

// 0x5c6370, thiscall, two stack arguments (GUESS name)
static void THISCALL unnamed5c6370(u8 *self, u32 flag, u8 *obj) {
  (void)self;
  if (!obj) return;
  u32 local = 0;
  ((SlotA)VT(obj)[0x4c / 4])(obj, (u32)(unsigned long)&local);
  u32 h = ((SlotA)VT(obj)[0x5c / 4])(obj, (u32)(unsigned long)&local);
  if (!local) return;
  u8 bl = (u8)flag;
  do {
    u8 *eng = G(u8 *, 0x70039c);
    u8 *sub = *(u8 **)(eng + 0x9b);
    u8 *r = (u8 *)(unsigned long)((SlotA)VT(sub)[0x58 / 4])(sub, h);
    if (r) {
      if (bl == 0) ((SlotN)VT(r)[0x28 / 4])(r);
      else ((SlotN)VT(r)[0x2c / 4])(r);
    }
    h = ((SlotA)VT(obj)[0x5c / 4])(obj, (u32)(unsigned long)&local);
  } while (local);
}
PCREG(5c6370, unnamed5c6370);
