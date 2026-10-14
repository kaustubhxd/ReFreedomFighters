// batch6506.cpp - unclaimed-65: batch 6 (docs/20-unclaimed-65.md, claim 6). Thiscall, no stack arguments (ret). Callees are
// virtual calls on the list and operator delete (0x634273, cdecl) as the harness stubs them.
#include "ff.h"

extern "C" void ext_634273(void *p, u32 size);

typedef u32(THISCALL *Slot1Fn)(u8 *self, u32 a);

static u32 vcall1(u8 *obj, u32 slot, u32 arg) {
  return ((Slot1Fn)(*(const u32 *)(*(const u32 *)obj + slot)))(obj, arg);
}

// 0x4388a0, ZInputAction::FreeActionDependencies() (residue 18): when the list at +0x3e is set: its slot +0x4c with an out flag;
// then the node walk: node = slot +0x64 (out); while node is nonzero, the item at [node] (if nonzero) is deleted with size 1, and
// the walk takes the next node (slot +0x64 again). Then the list's slot 0 is called with 1, and +0x3e is cleared.
static void THISCALL freeActionDependencies(u8 *self) {
  u8 *list = *(u8 **)(self + 0x3e);
  if (list) {
    u32 out = 0;
    vcall1(list, 0x4c, (u32)&out);
    u32 node = vcall1(list, 0x64, (u32)&out);
    while (node) {
      const u32 item = *(const u32 *)node;
      if (item) ext_634273((void *)item, 1);
      list = *(u8 **)(self + 0x3e);
      node = vcall1(list, 0x64, (u32)&out);
    }
    list = *(u8 **)(self + 0x3e);
    if (list) vcall1(list, 0x0, 1);
  }
  *(u32 *)(self + 0x3e) = 0;
}
PCREG(4388a0, freeActionDependencies);
