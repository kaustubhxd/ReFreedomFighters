// batch5784.cpp - unclaimed-57 (docs/20-unclaimed-57.md), batch 84: 0x5d92e0 (GUESS name unnamed_5d92e0), thiscall with one stack argument a
// (ret 4), no return value; ECX is not used. Order: e = a->vt[+0x20](); e+0x30 |= 0x400; r = e->vt[+0x25c](0x6b6318, 0); if r: floats
// {50.0f, 50.0f} on the stack, r->vt[+0x258](&floats, 0); s = (engine 0x70039c)+0x9b ->vt[+0x4c](e); a+0x48 |= 0x210000; a->vt[+0x27c](s).
// The slot calls run through fake vtables in the spec.
#include "ff.h"

#define VT(o) (*(void ***)(o))

typedef u32(THISCALL *SlotA)(u8 *self, u32 a);
typedef u32(THISCALL *SlotNone)(u8 *self);
typedef u32(THISCALL *Slot2)(u8 *self, u32 a, u32 b);

// 0x5d92e0, thiscall, one stack argument (GUESS name); ECX unused
static void THISCALL unnamed5d92e0(u8 *self, u8 *a) {
  (void)self;
  u8 *e = (u8 *)(unsigned long)((SlotNone)VT(a)[0x20 / 4])(a);
  *(u32 *)(e + 0x30) |= 0x400;
  u32 r = ((Slot2)VT(e)[0x25c / 4])(e, 0x6b6318, 0);
  if (r) {
    float fl[2] = {50.0f, 50.0f};
    ((Slot2)VT((u8 *)(unsigned long)r)[0x258 / 4])((u8 *)(unsigned long)r, (u32)(unsigned long)fl, 0);
  }
  u8 *eng = G(u8 *, 0x70039c);
  u8 *sub = *(u8 **)(eng + 0x9b);
  u32 s = ((SlotA)VT(sub)[0x4c / 4])(sub, (u32)(unsigned long)e);
  *(u32 *)(a + 0x48) |= 0x210000;
  ((SlotA)VT(a)[0x27c / 4])(a, s);
}
PCREG(5d92e0, unnamed5d92e0);
