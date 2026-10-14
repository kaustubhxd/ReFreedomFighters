// batch947.cpp - 0x513860 (no name in the map), read in full (2026-10-12). Thiscall (ECX = this), no args, plain ret.
// If the dword at this+0x138 is 0: tail-jump to 0x45f410 with ECX = this (stood in; no args).
// Else: walk the list from this+0x50 (each node's object is node+0x54 and the next node is node+0x60): call slot +0x28 of the object (no args).
// Then obj = manager (the dword at 0x70039c, its slot +0x9b) slot +0x58 with one arg (this+0x123). Call slot +0x2c of obj (no args), then
// slot +0xbc of obj with one arg 1. Returns with this+0x138 unchanged.
#include "ff.h"

#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define FP(p, o) (*(void **)((u8 *)(p) + (o)))

extern "C" void THISCALL ext_45f410(void *self);   // stood in (no args; tail-jumped to)

// 0x513860 (no name in the map).
static void THISCALL Apply513860(u8 *self) {
  if (U32(self, 0x138) == 0) {
    ext_45f410(self);
    return;
  }
  u8 *node = (u8 *)FP(self, 0x50);
  while (node) {
    vcall<void>(FP(node, 0x54), 0x28);
    node = (u8 *)FP(node, 0x60);
  }
  void *mgr = FP(G(u8 *, 0x70039c), 0x9b);
  void *obj = vcall<void *>(mgr, 0x58, U32(self, 0x123));
  vcall<void>(obj, 0x2c);
  vcall<void>(obj, 0xbc, 1u);
}
PCREG(513860, Apply513860);
