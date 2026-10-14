// batch5737.cpp - unclaimed-57, band batch 37 (name GUESS): 0x5de3e0, thiscall, no args, ret. Stores this at dword (dword 0x7003b8) + 0x2c4d.
// o = dword this+0x114; v = dword o+0x676; sub = dword (dword 0x70039c) + 0x9b; r1 = sub->vt[+0x58](v); this+0x134 = r1;
// r2 = r1->vt[+0x100](0x67d9e8); this+0x130 = r2. Both slots are unverified callees, stubbed in the spec.
#include "ff.h"

#define VT(o) (*(void ***)(o))
#define G(T, addr) (*(T *)(addr))

typedef u32(THISCALL *Slot58)(u8 *self, u32 a);
typedef u32(THISCALL *Slot100)(u8 *self, u32 a);

static void THISCALL unnamed5de3e0(u8 *self) {
  u8 *g = G(u8 *, 0x7003b8);
  *(u32 *)(g + 0x2c4d) = (u32)(unsigned long)self;
  u8 *o = *(u8 **)(self + 0x114);
  u32 v = *(u32 *)(o + 0x676);
  u8 *eng = G(u8 *, 0x70039c);
  u8 *sub = *(u8 **)(eng + 0x9b);
  u32 r1 = ((Slot58)VT(sub)[0x58 / 4])(sub, v);
  *(u32 *)(self + 0x134) = r1;
  u8 *r = (u8 *)(unsigned long)r1;
  u32 r2 = ((Slot100)VT(r)[0x100 / 4])(r, 0x67d9e8);
  *(u32 *)(self + 0x130) = r2;
}
PCREG(5de3e0, unnamed5de3e0);
