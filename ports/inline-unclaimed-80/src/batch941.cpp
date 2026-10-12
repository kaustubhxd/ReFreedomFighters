#include "ff.h"
// batch941.cpp - unclaimed-80 (docs/20-unclaimed-80.md): ZGROUP::CorrectCenSizeRecur() (0x43fa70, high). Thiscall, no arguments, void.
// Walks the list at this+0x50 (next at +0x60, object at +0x54). For each node: flags = obj ? dword at (*(obj+0xc)) + 0x23 : 0x200002;
// if flags has bit 0x100000, call the object's vtable slot +0x27c (thiscall, no arguments). Then this's vtable slot +0x280 (tail jump
// in the exe; a call-and-return here, since it takes no arguments).

static void THISCALL correctCenSizeRecur(u8 *self) {
  typedef void(THISCALL * v0_fn)(u8 *);
  u8 *n = *(u8 **)(self + 0x50);
  while (n != 0) {
    u8 *obj = *(u8 **)(n + 0x54);
    u32 flags;
    if (obj != 0) {
      u8 *q = *(u8 **)(obj + 0xc);
      flags = *(u32 *)(q + 0x23);
    } else {
      flags = 0x200002u;
    }
    if ((flags & 0x100000u) == 0)
      break;   // the exe jumps to the tail here: the walk ends at the first node without the bit
    ((v0_fn)(*(u32 *)(*(u32 *)obj + 0x27c)))(obj);
    n = *(u8 **)(n + 0x60);
  }
  ((v0_fn)(*(u32 *)(*(u32 *)self + 0x280)))(self);
}
PCREG(43fa70, correctCenSizeRecur);
