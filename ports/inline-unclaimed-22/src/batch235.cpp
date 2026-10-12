// batch235.cpp - area 59 (residue 18), docs/20-unclaimed-59.md. Walks a list at this+0x50 (next at +0x60): for each node,
// the global's object gets slot 0x50(node) -> b; if A->vt[0x28](b) is zero, the global's object gets slot 0x58(b) -> obj and
// obj->vt[0x1e4](A, B). First, 0x45eeb0(this, A, B) (ret 8). Name GUESS.
#include "ff.h"

extern "C" void THISCALL ext_45eeb0(u8 *self, u8 *a, u32 b);   // original, thiscall, two stack words (ret 8)

// 0x440aa0, thiscall(A, B) ret 8.
static void THISCALL walkList_440aa0(u8 *self, u8 *A, u32 B) {
  ext_45eeb0(self, A, B);
  u8 *p = *(u8 **)(self + 0x50);
  while (p) {
    u8 *rm = *(u8 **)0x70039cu;
    u8 *o = *(u8 **)(rm + 0x9b);
    u32 b = vcall<u32>(o, 0x50, (u32)p);
    if (!vcall<u32>(A, 0x28, b)) {
      u8 *rm2 = *(u8 **)0x70039cu;
      u8 *o2 = *(u8 **)(rm2 + 0x9b);
      u8 *obj = (u8 *)vcall<u32>(o2, 0x58, b);
      vcall<void>(obj, 0x1e4, (u32)A, B);
    }
    p = *(u8 **)(p + 0x60);
  }
}
PCREG(440aa0, walkList_440aa0);
