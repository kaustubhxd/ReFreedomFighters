// batch6504.cpp - unclaimed-65: batch 4 (docs/20-unclaimed-65.md, claim 4). Thiscall, one stack argument (ret 4).
#include "ff.h"

typedef u32(THISCALL *Slot1Fn)(u8 *self, u32 a);

static u32 vcall1(u8 *obj, u32 slot, u32 arg) {
  return ((Slot1Fn)(*(const u32 *)(*(const u32 *)obj + slot)))(obj, arg);
}

// 0x438c60, ZInputActions::GetActionMap(ZActionMapDefinition*) (residue 18, vtable): the list at +0x1214 gives its first item
// through slot +0x5c with the out flag (after its slot +0x4c). While the flag is set, an item whose dword +0x15 equals the
// argument is returned; otherwise the next item is taken. Returns 0 when the flag is clear (or the list is null).
static u8 *THISCALL inputActionsGetActionMap(u8 *self, u32 arg) {
  u8 *list = *(u8 **)(self + 0x1214);
  if (!list) return nullptr;
  u32 out = 0;
  vcall1(list, 0x4c, (u32)&out);
  u8 *item = (u8 *)vcall1(list, 0x5c, (u32)&out);
  if (!out) return nullptr;
  for (;;) {
    if (*(const u32 *)(item + 0x15) == arg) return item;
    item = (u8 *)vcall1(list, 0x5c, (u32)&out);
    if (!out) return nullptr;
  }
}
PCREG(438c60, inputActionsGetActionMap);
