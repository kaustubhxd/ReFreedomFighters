// batch755.cpp - unclaimed area 75 (docs/20-unclaimed-75.md), slice floor(addr/16) mod 20 == 13.
#include "ff.h"

extern "C" u32 THISCALL ext_513340(u8 *self, u32 v);   // original predicate, thiscall, one stack word, ret 4 (returns al)

typedef u32(THISCALL *VtOneArg)(u8 *, u32);

// 0x513090, thiscall() void. Array of object pointers at this+0xde, count at [this+0xda]. Walk the entries: if
// ext_513340(this, v) is nonzero, move the last entry into this slot and drop the count (the slot is checked again);
// otherwise, if edi == 0 or v->vt[0x1e0](v, 0x80200014) is nonzero, edi = v, and advance. Finally the render object's
// vt[0x4c](obj, edi). Name GUESS (compact an array of pointers).
static void THISCALL compactPointers_513090(u8 *self) {
  u32 &count = *(u32 *)(self + 0xda);
  u32 edi = 0;
  u32 *esi = (u32 *)(self + 0xde);
  while (true) {
    u32 *end = (u32 *)(self + 0xde + 4 * count);
    if (esi == end) break;
    u32 v = *esi;
    if (ext_513340(self, v) != 0) {
      *esi = *(u32 *)(self + 0xde + 4 * (count - 1));
      --count;
      continue;
    }
    if (edi == 0) {
      edi = v;
    } else {
      VtOneArg f1e0 = (VtOneArg)(*(u32 *)(*(u32 *)v + 0x1e0));
      if (f1e0((u8 *)v, 0x80200014u) != 0) edi = v;
    }
    ++esi;
  }
  u8 *rm = *(u8 **)0x70039cu;
  u8 *obj = *(u8 **)(rm + 0x9b);
  VtOneArg f4c = (VtOneArg)(*(u32 *)(*(u32 *)obj + 0x4c));
  f4c(obj, edi);
}
PCREG(513090, compactPointers_513090);
