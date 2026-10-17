// batch5763.cpp - unclaimed-57 (docs/20-unclaimed-57.md), batch 63: 0x5d89f0 (GUESS name unnamed_5d89f0), thiscall, no stack
// arguments (plain ret), no return value. Order: a = (engine 0x70039c)+0x9b ->vt[+0x58](this+0x28); if a != 0: r1 = a->vt[+0x254](a, 0),
// r2 = a->vt[+0x274](a); then b = ((engine)+0x1aa3)->+0x18; this+0x34 = b->vt[+0x108](b, r1, r2, 5). The slot calls run through
// the fake vtables in the spec (logged, fixed results); a null a skips the rest.
#include "ff.h"

#define VT(o) (*(void ***)(o))

typedef u32(THISCALL *SlotA)(u8 *self, u32 a);
typedef u32(THISCALL *SlotN)(u8 *self);
typedef u32(THISCALL *SlotB)(u8 *self, u32 a, u32 b, u32 c);

// 0x5d89f0, thiscall, no stack args (GUESS name)
static void THISCALL unnamed5d89f0(u8 *self) {
  u8 *eng = G(u8 *, 0x70039c);
  u8 *sub = *(u8 **)(eng + 0x9b);
  u32 a = ((SlotA)VT(sub)[0x58 / 4])(sub, *(u32 *)(self + 0x28));
  if (a) {
    u8 *obj = (u8 *)(unsigned long)a;
    u32 r1 = ((SlotA)VT(obj)[0x254 / 4])(obj, 0);
    u32 r2 = ((SlotN)VT(obj)[0x274 / 4])(obj);
    u8 *holder = *(u8 **)(eng + 0x1aa3);
    u8 *b = *(u8 **)(holder + 0x18);
    *(u32 *)(self + 0x34) = ((SlotB)VT(b)[0x108 / 4])(b, r1, r2, 5);
  }
}
PCREG(5d89f0, unnamed5d89f0);
