// batch34014.cpp - cascade tier E, batch 34014: 0x476ae0, thiscall(a1, 4 unused) ret 0x14: step a ring index and fetch the next object from the
// engine's table (slot 0x58), then configure it through its own slots and register it with a1 (slot 0x288).
#include "ff.h"

// 0x476ae0: --[this+0x60]; obj = engine->table->slot0x58(array[this+0x68][idx]); reload idx from [this+0x5c] when it hit 0; when obj != null:
// obj->slot0x2c(), obj->slot0x138(word [this+0x70], 0, 0), a1->slot0x288(obj, 0, 1). Returns obj.
static u8 *THISCALL fn476ae0(u8 *self, u8 *a1, u32, u32, u32, u32) {
  *(s32 *)(self + 0x60) -= 1;
  u8 *eng = G(u8 *, 0x70039c);
  u32 idx = *(u32 *)(self + 0x60);
  u8 *tbl = *(u8 **)(eng + 0x9b);
  u32 *arr = *(u32 **)(self + 0x68);
  u8 *obj = vcall<u8 *>(tbl, 0x58, arr[idx]);
  if (*(u32 *)(self + 0x60) == 0) *(u32 *)(self + 0x60) = *(u32 *)(self + 0x5c);
  if (obj) {
    vcall<void>(obj, 0x2c);
    vcall<void>(obj, 0x138, (u32) * (u16 *)(self + 0x70), 0u, 0u);
    vcall<void>(a1, 0x288, obj, 0u, 1u);
  }
  return obj;
}
PCREG(476ae0, fn476ae0);
