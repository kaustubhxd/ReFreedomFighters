#include "ff.h"
// batch8024.cpp - unclaimed-79 unclaimed small row (docs/20-unclaimed-79.md). Name GUESS (no GC name).

// 0x48f540 (GUESS): thiscall (ret 8). m = a1, or a2+0x30 when a1 is zero; calls slot +0x14c of m with a2 when m is nonzero.
// Then slot 0 of a2 with 0, then slot +0x48 of the object at this+8 with a2.
static void THISCALL f_48f540(u8 *self, u32 a1, u32 a2) {
  u8 *esi = (u8 *)(unsigned long)a2;
  u8 *m = (u8 *)(unsigned long)a1;
  bool go = true;
  if (m == 0) {
    if (esi == 0) {
      go = false;
    } else {
      m = *(u8 **)(esi + 0x30);
      if (m == 0) go = false;
    }
  }
  if (go) vcall<void, u32>(m, 0x14c, a2);
  vcall<void, u32>(esi, 0, 0u);
  vcall<void, u32>(*(u8 **)(self + 0x8), 0x48, a2);
}
PCREG(48f540, f_48f540);
