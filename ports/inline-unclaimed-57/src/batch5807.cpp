// batch5807.cpp - unclaimed-57 (docs/20-unclaimed-57.md), batch 107: 0x5d7e00 (GUESS name unnamed_5d7e00), thiscall, no stack args, plain ret.
// S = (engine 0x70039c)+0x9b + 0x1c: if S != 0: S->vt[+0x54](&l0); if S->vt[+0x74](&l0) then repeat that call until it returns 0 (S re-read each time).
// T = this+0x14e: if T != 0: T->vt[+0x4c](&l1); h = T->vt[+0x5c](&l1); while l1 != 0: U = sub->vt[+0x58](h); U->vt[+0x100](0x691564); h = T->vt[+0x5c](&l1).
// this+0x1cc = 1 (byte); if this+0x1c4 != engine+0x40: this+0x1c4 = dword (engine+0x40); 0x5d7bc0(this) (area 49's function, hooked in the spec).
#include "ff.h"

#define VT(o) (*(void ***)(o))

typedef u32(THISCALL *SlotA)(u8 *self, u32 a);
typedef u32(THISCALL *SlotU)(u8 *self, u32 a);

extern "C" void THISCALL ext_5d7bc0(u8 *self);  // area 49's function, original code (hooked in the spec)

// 0x5d7e00, thiscall, no stack args (GUESS name)
static void THISCALL unnamed5d7e00(u8 *self) {
  u8 *eng = G(u8 *, 0x70039c);
  u8 *sub = *(u8 **)(eng + 0x9b);
  u8 *S = sub + 0x1c;
  if (S != 0) {
    u32 l0 = 0;
    ((SlotA)VT(S)[0x54 / 4])(S, (u32)(unsigned long)&l0);
    eng = G(u8 *, 0x70039c);
    sub = *(u8 **)(eng + 0x9b);
    S = sub + 0x1c;
    if (((SlotA)VT(S)[0x74 / 4])(S, (u32)(unsigned long)&l0)) {
      do {
        eng = G(u8 *, 0x70039c);
        sub = *(u8 **)(eng + 0x9b);
        S = sub + 0x1c;
      } while (((SlotA)VT(S)[0x74 / 4])(S, (u32)(unsigned long)&l0));
    }
  }
  u8 *T = *(u8 **)(self + 0x14e);
  if (T != 0) {
    u32 l1 = 0;
    ((SlotA)VT(T)[0x4c / 4])(T, (u32)(unsigned long)&l1);
    u32 h = ((SlotA)VT(T)[0x5c / 4])(T, (u32)(unsigned long)&l1);
    if (l1 != 0) {
      do {
        eng = G(u8 *, 0x70039c);
        sub = *(u8 **)(eng + 0x9b);
        u8 *U = (u8 *)(unsigned long)((SlotA)VT(sub)[0x58 / 4])(sub, h);
        ((SlotA)VT(U)[0x100 / 4])(U, 0x691564);
        T = *(u8 **)(self + 0x14e);
        h = ((SlotA)VT(T)[0x5c / 4])(T, (u32)(unsigned long)&l1);
      } while (l1 != 0);
    }
  }
  *(u8 *)(self + 0x1cc) = 1;
  eng = G(u8 *, 0x70039c);
  if (self + 0x1c4 != eng + 0x40) *(u32 *)(self + 0x1c4) = *(u32 *)(eng + 0x40);
  ext_5d7bc0(self);
}
PCREG(5d7e00, unnamed5d7e00);
