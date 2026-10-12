#include "ff.h"
// batch944.cpp - unclaimed-80 (docs/20-unclaimed-80.md): ZGROUP::SendCommandRecursive(unsigned short, void*, ZGEOM*) (0x441820, high).
// Thiscall, three stack arguments (a1, a2, a3), ret 12. First: this's vtable slot +0x128 with (a1, a2, a3) (the exe reaches it through
// the thunk 0x45faf0, a tail jump; modelled as a direct thiscall of the slot with callee cleanup). Then for each node of the list at
// this+0x50 (next at +0x60, object at +0x54, if nonzero): object's vtable slot +0x138 with (a1, a2, a3) (thiscall, callee-cleaned).

static void THISCALL sendCommandRecursive(u8 *self, u32 a1, u32 a2, u32 a3) {
  typedef void(THISCALL * c3_fn)(u8 *, u32, u32, u32);
  ((c3_fn)(*(u32 *)(*(u32 *)self + 0x128)))(self, a1, a2, a3);
  u8 *n = *(u8 **)(self + 0x50);
  while (n != 0) {
    u8 *obj = *(u8 **)(n + 0x54);
    if (obj != 0)
      ((c3_fn)(*(u32 *)(*(u32 *)obj + 0x138)))(obj, a1, a2, a3);
    n = *(u8 **)(n + 0x60);
  }
}
PCREG(441820, sendCommandRecursive);
