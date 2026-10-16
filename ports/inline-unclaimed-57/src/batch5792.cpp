// batch5792.cpp - unclaimed-57 (docs/20-unclaimed-57.md), batch 92: 0x5d3eb0 (GUESS name unnamed_5d3eb0), thiscall, no stack args, plain ret.
// Order: this+0x80 = -1; w1 = (engine 0x70039c)+0x9b ->vt[+0x114](0x6af14c, 0, 0x6b518c, 0x41) (low word to this+0x78); w2 = same with
// (0x6b51c8, 0, 0x6b518c, 0x42) (to this+0x7a); w3 = (0x6a61b0, 0, 0x6b518c, 0x43) (to +0x7c); w4 = (0x6a619c, 0, 0x6b518c, 0x44) (to +0x7e);
// dword this+0x85 = 0 (unaligned); dword this+0x48 = 0. The slot calls run through a fake vtable in the spec.
#include "ff.h"

#define VT(o) (*(void ***)(o))

typedef u32(THISCALL *SlotEng)(u8 *self, u32 a, u32 b, u32 c, u32 d);

// 0x5d3eb0, thiscall, no stack args (GUESS name)
static void THISCALL unnamed5d3eb0(u8 *self) {
  *(u32 *)(self + 0x80) = 0xffffffffu;
  u8 *eng = G(u8 *, 0x70039c);
  u8 *sub = *(u8 **)(eng + 0x9b);
  *(u16 *)(self + 0x78) = (u16)((SlotEng)VT(sub)[0x114 / 4])(sub, 0x6af14c, 0, 0x6b518c, 0x41);
  eng = G(u8 *, 0x70039c);
  sub = *(u8 **)(eng + 0x9b);
  *(u16 *)(self + 0x7a) = (u16)((SlotEng)VT(sub)[0x114 / 4])(sub, 0x6b51c8, 0, 0x6b518c, 0x42);
  eng = G(u8 *, 0x70039c);
  sub = *(u8 **)(eng + 0x9b);
  *(u16 *)(self + 0x7c) = (u16)((SlotEng)VT(sub)[0x114 / 4])(sub, 0x6a61b0, 0, 0x6b518c, 0x43);
  eng = G(u8 *, 0x70039c);
  sub = *(u8 **)(eng + 0x9b);
  *(u16 *)(self + 0x7e) = (u16)((SlotEng)VT(sub)[0x114 / 4])(sub, 0x6a619c, 0, 0x6b518c, 0x44);
  *(u32 *)(self + 0x85) = 0;
  *(u32 *)(self + 0x48) = 0;
}
PCREG(5d3eb0, unnamed5d3eb0);
