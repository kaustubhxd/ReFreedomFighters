#include "ff.h"
// batch1511.cpp - unclaimed-15 claim 11 (docs/20-unclaimed-15.md): ZOnScreenDisplay::Load2() (0x5aa0e0). Name from the GC
// name map (medium). Thiscall, no arguments, ret 0. The render calls are code stubs in the harness (not logged).

typedef u32(THISCALL *Slot0)(u8 *self);
typedef u32(THISCALL *Slot2)(u8 *self, u32 a1, u32 a2);

// 0x5aa0e0, ZOnScreenDisplay::Load2() (medium).
static void THISCALL onScreenDisplayLoad2(u8 *self) {
  u8 *g = *(u8 **)0x7003b8;
  *(u32 *)(self + 0x8a3) = *(u32 *)(g + 0x4ac);
  u8 *rm = *(u8 **)0x70039c;
  u8 *obj = *(u8 **)(rm + 0x9b);
  u8 *x = (u8 *)((Slot0)*(u32 *)(*(u32 *)obj + 0x134))(obj);
  u32 local = 0;
  ((Slot2)*(u32 *)(*(u32 *)x + 0x88))(x, 0x68fcec, (u32)&local);
  *(u32 *)(self + 0x8d0) = local;
}
PCREG(5aa0e0, onScreenDisplayLoad2);
