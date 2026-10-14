// batch5834.cpp - residue 9, 0x489490 (ZMovementBaseMove::Move(const float*, const float*, float*, float*, float), gc name map), thiscall, five stack arguments, ret 0x14.
// this+0x21 = 0 (dword); this->vt[+0x40](a1..a5); this->vt[+0x48](a1..a5).
#include "ff.h"

#define VT(o) (*(void ***)(o))

typedef void(THISCALL *Slot5)(u8 *self, u32 a, u32 b, u32 c, u32 d, u32 e);

// 0x489490, thiscall, five stack arguments (ZMovementBaseMove::Move)
static void THISCALL unnamed489490(u8 *self, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5) {
  *(u32 *)(self + 0x21) = 0;
  ((Slot5)VT(self)[0x40 / 4])(self, a1, a2, a3, a4, a5);
  ((Slot5)VT(self)[0x48 / 4])(self, a1, a2, a3, a4, a5);
}
PCREG(489490, unnamed489490);
