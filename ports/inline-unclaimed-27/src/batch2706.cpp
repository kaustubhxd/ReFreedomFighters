#include "ff.h"
// batch2706.cpp - unclaimed-27 claim 6 (docs/20-unclaimed-27.md). Name from the GC name map (high).

// 0x45d720, ZGEOM::CopyExData(const ZGEOM*) (high). Thiscall, ret 4.
// Calls vtable slot +0x44 (no args). If src+0x10 is nonzero: calls slot +0x40; copies the dword at (src+0x10)+0xc to
// (this+0x10)+0xc; then, if that new dword is nonzero, checks it against an array at g9+0x1c5d (g9 = the global at 0x70039c
// field +0x9b): it must be >= the array base, the base must be nonzero, and it must lie below base + (size at base-8 & 0x1fffffff).
// Otherwise it calls slot +0xbc of the object at 0x70038c with the value. Then calls slot +0xfc with src and slot +4 with src.
// When src+0x10 is zero, none of the calls after slot +0x44 are made.
static void THISCALL zgeomCopyExData(u8 *self, u8 *src) {
  typedef void(THISCALL * noarg_fn)(u8 *);
  typedef void(THISCALL * arg1_fn)(u8 *, u32);
  ((noarg_fn)(*(u32 *)(*(u32 *)self + 0x44)))(self);

  if (*(u32 *)(src + 0x10) != 0) {
    ((noarg_fn)(*(u32 *)(*(u32 *)self + 0x40)))(self);

    u8 *a = *(u8 **)(self + 0x10);
    *(u32 *)(a + 0xc) = *(u32 *)(*(u8 **)(src + 0x10) + 0xc);

    u32 edx = *(u32 *)(*(u8 **)(self + 0x10) + 0xc);
    if (edx != 0) {
      u8 *g = (u8 *)(unsigned long)G(u32, 0x70039c);
      u8 *g9 = *(u8 **)(g + 0x9b);
      u32 base = *(u32 *)(g9 + 0x1c5d);
      bool ok = false;
      if (edx >= base && base != 0) {
        u32 end = base + (*(u32 *)(base - 8) & 0x1fffffffu);
        if (edx < end) ok = true;
      }
      if (!ok) {
        u8 *k = (u8 *)(unsigned long)G(u32, 0x70038c);
        ((arg1_fn)(*(u32 *)(*(u32 *)k + 0xbc)))(k, edx);
      }
    }

    ((arg1_fn)(*(u32 *)(*(u32 *)self + 0xfc)))(self, (u32)(unsigned long)src);
    ((arg1_fn)(*(u32 *)(*(u32 *)self + 4)))(self, (u32)(unsigned long)src);
  }
}
PCREG(45d720, zgeomCopyExData);
