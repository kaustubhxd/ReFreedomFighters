// batch5775.cpp - unclaimed-57 (docs/20-unclaimed-57.md), batch 75: 0x5d91a0 (GUESS name unnamed_5d91a0), thiscall, no stack args,
// plain ret. Order: if this+0x4c != 1 return; d = (int)(engine 0x70039c)+0x40 - this+0x48 - 0x200; f = (float)d * G(0x6785e4); if
// !(f > G(0x6785d0)) return; o = this+0x44; this+0x4c = 0; o->vt[+0x254](); obj = (engine)+0x9b ->vt[+0x58](this+0x54); if !obj return;
// tail call: obj->vt[+0x254](). The slot calls run through fake vtables in the spec.
#include "ff.h"

#define VT(o) (*(void ***)(o))

typedef void(THISCALL *SlotN)(u8 *self);
typedef u32(THISCALL *SlotA)(u8 *self, u32 a);

// 0x5d91a0, thiscall, no stack args (GUESS name)
static void THISCALL unnamed5d91a0(u8 *self) {
  if (*(u32 *)(self + 0x4c) != 1) return;
  u8 *eng = G(u8 *, 0x70039c);
  s32 d = (s32)(*(u32 *)(eng + 0x40) - *(u32 *)(self + 0x48) - 0x200u);
  float f = (float)d * G(float, 0x6785e4);
  if (!(f > G(float, 0x6785d0))) return;
  u8 *o = *(u8 **)(self + 0x44);
  *(u32 *)(self + 0x4c) = 0;
  ((SlotN)VT(o)[0x254 / 4])(o);
  eng = G(u8 *, 0x70039c);
  u8 *sub = *(u8 **)(eng + 0x9b);
  u8 *obj = (u8 *)(unsigned long)((SlotA)VT(sub)[0x58 / 4])(sub, *(u32 *)(self + 0x54));
  if (!obj) return;
  ((SlotN)VT(obj)[0x254 / 4])(obj);
}
PCREG(5d91a0, unnamed5d91a0);
