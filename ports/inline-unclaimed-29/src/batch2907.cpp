// batch2907.cpp - unclaimed-29: batch 7 (docs/20-unclaimed-29.md, claim 7, slice 8). Thiscall, no stack arguments (ret).
// The name is medium confidence (GUESS). Every call is virtual; the out flags are read back after each call.
#include "ff.h"

typedef u32(THISCALL *VirtArg1)(u8 *self, u32 a);
typedef u32(THISCALL *VirtArg0)(u8 *self);

static u32 vcall1(u8 *obj, u32 slot, u32 arg) {
  return ((VirtArg1)(*(const u32 *)(*(const u32 *)obj + slot)))(obj, arg);
}

static u32 vcall0(u8 *obj, u32 slot) {
  return ((VirtArg0)(*(const u32 *)(*(const u32 *)obj + slot)))(obj);
}

// the render object at [0x70039c]+0x9b, then its +0xadc object
static u8 *renderObject() {
  u8 *rr = *(u8 **)(G(u8 *, 0x70039c) + 0x9b);
  return *(u8 **)(rr + 0xadc);
}

// 0x5c6640, ZFFSearchLightGroup::DeleteDebugGeom() (medium): walks the list at +0x50 (render +0x220 on each item), the list at
// +0x54 (render +0x240 on each item) and the list at +0x58 (item +0x210 with 1 when the item is non-null, after +0x44). Each walk
// starts with virtual +0x4c, takes its item from virtual +0x5c with the out flag, repeats while the flag is set, and ends with +0xc.
static void THISCALL searchLightGroupDeleteDebugGeom(u8 *self) {
  u32 out = 0;
  u8 *l1 = *(u8 **)(self + 0x50);
  vcall1(l1, 0x4c, (u32)&out);
  u32 item = vcall1(l1, 0x5c, (u32)&out);
  while (out) {
    vcall1(renderObject(), 0x220, item);
    item = vcall1(l1, 0x5c, (u32)&out);
  }
  vcall0(l1, 0xc);

  u8 *l2 = *(u8 **)(self + 0x54);
  vcall1(l2, 0x4c, (u32)&out);
  item = vcall1(l2, 0x5c, (u32)&out);
  while (out) {
    vcall1(renderObject(), 0x240, item);
    item = vcall1(l2, 0x5c, (u32)&out);
  }
  vcall0(l2, 0xc);

  u8 *l3 = *(u8 **)(self + 0x58);
  vcall1(l3, 0x4c, (u32)&out);
  item = vcall1(l3, 0x5c, (u32)&out);
  if (out) {
    do {
      if (item) vcall1((u8 *)item, 0x210, 1);
      vcall1(l3, 0x44, (u32)&out);
      item = vcall1(l3, 0x5c, (u32)&out);
    } while (out);
  }
  vcall0(l3, 0xc);
}
PCREG(5c6640, searchLightGroupDeleteDebugGeom);
