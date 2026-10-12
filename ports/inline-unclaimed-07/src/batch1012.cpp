// batch1012.cpp - unclaimed-07 batch 12 (docs/20-unclaimed-07.md, slice 6): CActionController::Add.
// Name from the GC name map (medium). Body from the PC bytes. Globals: the engine object at 0x70038c.
#include "ff.h"

// 0x49f8a0, CActionController::Add(CAction*) (medium), thiscall, one argument, ret 4.
//   a == 0: edx = 0. Otherwise, when slot +0x20 of the engine object g gives non-zero (a is known): edx = 0.
//   Otherwise, when g+8 is non-null and g+0xc <= a < g+0x10 (unsigned): edx = (g+8)() with ECX = a (no arguments).
//   Otherwise: when the dword at a-4 is 0, slot +0xac(a) is called on g; then edx = [a-4].
//   Then, when edx is not in this's list at +0x70 (count at +0x88c, scanned count+1 entries), it is appended (count+1,
//   and +0x8ac = 1.0f).
//   Then for each object in this's list at +0x5c (count at +0x48), the same append into the object's list at +4
//   (count at +0x820), and the object's +0x840 = 1.0f.
static void THISCALL actionControllerAdd(u8 *self, u32 a) {
  u8 *g = G(u8 *, 0x70038c);
  u32 edx;
  if (a == 0) {
    edx = 0;
  } else if (vcall<u32>(g, 0x20, a)) {
    edx = 0;
  } else {
    u32 fn = *(u32 *)(g + 8);
    if (fn != 0 && a >= *(u32 *)(g + 0xc) && a < *(u32 *)(g + 0x10)) {
      typedef u32(THISCALL * fn_t)(void *);
      edx = ((fn_t)fn)((void *)a);
    } else {
      if (*(u32 *)(a - 4) == 0)
        vcall<void>(g, 0xac, a);
      edx = *(u32 *)(a - 4);
    }
  }

  s32 esi = (s32)*(u32 *)(self + 0x88c) + 1;
  bool found = false;
  if (esi > 0) {
    for (s32 i = 0; i < esi; i++) {
      if (*(u32 *)(self + 0x70 + 4 * i) == edx) {
        found = true;
        break;
      }
    }
  }
  if (!found) {
    *(u32 *)(self + 0x88c) += 1;
    u32 idx = *(u32 *)(self + 0x88c);
    *(u32 *)(self + 0x70 + 4 * idx) = edx;
    *(u32 *)(self + 0x8ac) = 0x3f800000u;
  }

  for (s32 b = 0; b < (s32)*(u32 *)(self + 0x48); b++) {
    u8 *obj = *(u8 **)(self + 0x5c + 4 * b);
    s32 n = (s32)*(u32 *)(obj + 0x820) + 1;
    bool f = false;
    if (n > 0) {
      for (s32 j = 0; j < n; j++) {
        if (*(u32 *)(obj + 4 + 4 * j) == edx) {
          f = true;
          break;
        }
      }
    }
    if (!f) {
      *(u32 *)(obj + 0x820) += 1;
      u32 idx = *(u32 *)(obj + 0x820);
      *(u32 *)(obj + 4 + 4 * idx) = edx;
      *(u32 *)(obj + 0x840) = 0x3f800000u;
    }
  }
}
PCREG(49f8a0, actionControllerAdd);
