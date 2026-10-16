// batch5767.cpp - unclaimed-57 (docs/20-unclaimed-57.md), batch 67: 0x5d58e0 (GUESS name unnamed_5d58e0), thiscall, two stack
// arguments (a1 word-compared, a2; ret 8), no return value. Order: r = (engine 0x70039c)+0x9b ->vt[+0x114](0x6b586c, 0, 0x6b583c, 0x83)
// (hooked; the low word of r is compared with the low word of a1); if equal: this->vt[+0x110](0x10, 0); p = dword this+0x25; if p:
// p->vt[+0x2c](); this+0x18 = 1 (byte). Always: 0x45d380(this, a1, a2) (hooked, logged).
#include "ff.h"

#define VT(o) (*(void ***)(o))

typedef u32(THISCALL *SlotEng)(u8 *self, u32 a, u32 b, u32 c, u32 d);
typedef void(THISCALL *Slot2)(u8 *self, u32 a, u32 b);
typedef void(THISCALL *SlotN)(u8 *self);

extern "C" void THISCALL ext_45d380(u8 *self, u32 a, u32 b);  // base method, original code (hooked in the spec)

// 0x5d58e0, thiscall, two stack arguments (GUESS name)
static void THISCALL unnamed5d58e0(u8 *self, u32 a1, u32 a2) {
  u8 *eng = G(u8 *, 0x70039c);
  u8 *sub = *(u8 **)(eng + 0x9b);
  u32 r = ((SlotEng)VT(sub)[0x114 / 4])(sub, 0x6b586c, 0, 0x6b583c, 0x83);
  if ((u16)a1 == (u16)r) {
    ((Slot2)VT(self)[0x110 / 4])(self, 0x10, 0);
    u8 *p = (u8 *)(unsigned long)*(u32 *)(self + 0x25);
    if (p) ((SlotN)VT(p)[0x2c / 4])(p);
    *(u8 *)(self + 0x18) = 1;
  }
  ext_45d380(self, a1, a2);
}
PCREG(5d58e0, unnamed5d58e0);
