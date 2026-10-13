#include "ff.h"
// batch3506.cpp - area 35 claim 6 (docs/20-unclaimed-35.md): ZActor::EnableMovePool(bool) (0x478460). Name from the GC name map
// (high). Thiscall, one argument, ret 4. The pool is the global at 0x7003b8: count at +0x4b0, entries (pointers) at +0x4b4.
// The loop scans exactly count entries (0x12d * 4 == 0x4b4). Stubbed in the harness: this's slot +0x20, the object's slot +0x80,
// and the render sub-object's slot +0x4c, all logged.

typedef u32(THISCALL *SlotA)(u8 *self);
typedef u32(THISCALL *Slot1)(u8 *self, u32 a1);
typedef u32(THISCALL *Slot2)(u8 *self, u32 a1, u32 a2);

static u8 *objectFromSlot20(u8 *self) {
  return (u8 *)((SlotA)*(u32 *)(*(u32 *)self + 0x20))(self);
}

static u32 renderSubCall4c(u32 arg) {
  u8 *rm = *(u8 **)0x70039c;
  u8 *sub = *(u8 **)(rm + 0x9b);
  return ((Slot1)*(u32 *)(*(u32 *)sub + 0x4c))(sub, arg);
}

// 0x478460, ZActor::EnableMovePool(bool) (high).
static void THISCALL actorEnableMovePool(u8 *self, u32 enable) {
  if (!(u8)enable) {
    // The exe evaluates slot +0x20 and the render slot +0x4c once per pool entry (inside the loop body).
    u8 *g = *(u8 **)0x7003b8;
    u32 n = *(u32 *)(g + 0x4b0);
    for (u32 i = 0; i < n; ++i) {
      u32 r = renderSubCall4c((u32)objectFromSlot20(self));
      g = *(u8 **)0x7003b8;
      u32 *slot = (u32 *)(g + 0x4b4 + 4 * i);
      if (**(u32 **)slot == r) {
        *slot = *(u32 *)(g + 0x4b4 + 4 * (n - 1));
        *(u32 *)(g + 0x4b0) = n - 1;
        break;
      }
    }
    self[0x5d2] = 0;
    return;
  }
  u32 r = renderSubCall4c((u32)objectFromSlot20(self));
  *(u32 *)(self + 0x5d3) = r;
  u8 *g = *(u8 **)0x7003b8;
  u32 n = *(u32 *)(g + 0x4b0);
  for (u32 i = 0; i < n; ++i) {
    u32 *entry = *(u32 **)(g + 0x4b4 + 4 * i);
    if (*entry == r)
      return;
  }
  *(u32 *)(self + 0x613) = 0x7e967699;
  *(u32 *)(self + 0x617) = 0x7e967699;
  *(u32 *)(self + 0x61b) = 0x7e967699;
  *(u32 *)(self + 0x5d7) = (u32)self;
  *(u32 *)(self + 0x60b) = 0x41f00000;
  *(u32 *)(self + 0x60f) = 0x42c80000;
  self[0x61f] = 1;
  *(u32 *)(self + 0x620) = 0xfffffc00;
  u8 *o2 = objectFromSlot20(self);
  ((Slot2)*(u32 *)(*(u32 *)o2 + 0x80))(o2, (u32)(self + 0x5e7), (u32)(self + 0x5db));
  g = *(u8 **)0x7003b8;
  n = *(u32 *)(g + 0x4b0);
  *(u32 *)(g + 0x4b4 + 4 * n) = (u32)(self + 0x5d3);
  *(u32 *)(g + 0x4b0) = n + 1;
  self[0x5d2] = 1;
}
PCREG(478460, actorEnableMovePool);
