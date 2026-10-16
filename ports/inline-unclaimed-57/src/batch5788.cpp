// batch5788.cpp - unclaimed-57 (docs/20-unclaimed-57.md), batch 88: 0x5de430 (GUESS name unnamed_5de430), thiscall, one stack argument obj
// (ret 4), returns al = 1. Order: clear bit 0x40 of this+4; obj->vt[+0x18](this+0x48, 0xcc); obj->vt[+0x40](&slot) where slot is the stack
// argument's own slot (the callee may change it); this+0x114 = (engine 0x70039c)+0x9b ->vt[+0x58](slot); obj->vt[+0x50](this+0x118);
// obj->vt[+0x50](this+0x11c); obj->vt[+0x18](this+0x120, 0xc); obj->vt[+0x50](this+0x12c). The vtable calls go through the register copy
// of obj (esi in the original), not the slot. The slots run as fake vtable stubs in the spec.
#include "ff.h"

#define VT(o) (*(void ***)(o))

typedef void(THISCALL *SlotPV)(u8 *self, u32 p, u32 v);
typedef void(THISCALL *SlotP)(u8 *self, u32 p);
typedef u32(THISCALL *SlotA)(u8 *self, u32 a);

// 0x5de430, thiscall, one stack argument (GUESS name)
static u8 THISCALL unnamed5de430(u8 *self, u8 *obj) {
  u32 slot = (u32)(unsigned long)obj;  // the stack argument's own slot: the callee may write it
  *(u32 *)(self + 4) &= 0xffffffbfu;
  ((SlotPV)VT(obj)[0x18 / 4])(obj, (u32)(unsigned long)(self + 0x48), 0xcc);
  ((SlotP)VT(obj)[0x40 / 4])(obj, (u32)(unsigned long)&slot);
  u8 *eng = G(u8 *, 0x70039c);
  u8 *sub = *(u8 **)(eng + 0x9b);
  *(u32 *)(self + 0x114) = ((SlotA)VT(sub)[0x58 / 4])(sub, slot);
  ((SlotP)VT(obj)[0x50 / 4])(obj, (u32)(unsigned long)(self + 0x118));
  ((SlotP)VT(obj)[0x50 / 4])(obj, (u32)(unsigned long)(self + 0x11c));
  ((SlotPV)VT(obj)[0x18 / 4])(obj, (u32)(unsigned long)(self + 0x120), 0xc);
  ((SlotP)VT(obj)[0x50 / 4])(obj, (u32)(unsigned long)(self + 0x12c));
  return 1;
}
PCREG(5de430, unnamed5de430);
