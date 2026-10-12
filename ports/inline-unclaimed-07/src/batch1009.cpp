// batch1009.cpp - unclaimed-07 batch 9 (docs/20-unclaimed-07.md, slice 6): ZItem::GetMainItemRootTM.
// Name from the GC name map (high). Body from the PC bytes.
#include "ff.h"

// 0x46e8e0, ZItem::GetMainItemRootTM(float*, float*) (high). When the flag 0x200000 in the dword at [[this+8]+0x3c] is
// clear: slot +0x2e0(a1, a2) then slot +0x98(a1, a2) on this. When it is set: root = slot +0x2f4 on this (returns when
// null); chk = root slot +0x1e0(0x1007da); o = [this+8]. When chk is non-zero: root = root slot +0x2f4, o = [old root+8].
// Then root slot +0x2a4(o, a1, a2) and root slot +0x98(a1, a2).
static void THISCALL itemGetMainItemRootTM(u8 *self, u32 a1, u32 a2) {
  u8 *o1 = *(u8 **)(self + 8);
  if (!(*(u32 *)(o1 + 0x3c) & 0x200000u)) {
    vcall<void>(self, 0x2e0, a1, a2);
    vcall<void>(self, 0x98, a1, a2);
    return;
  }
  u8 *root = (u8 *)vcall<u32>(self, 0x2f4);
  if (!root)
    return;
  u32 o = *(u32 *)(self + 8);
  u32 chk = vcall<u32>(root, 0x1e0, 0x1007dau);
  if ((u8)chk) {
    u8 *old = root;
    root = (u8 *)vcall<u32>(old, 0x2f4);
    o = *(u32 *)(old + 8);
  }
  vcall<void>(root, 0x2a4, o, a1, a2);
  vcall<void>(root, 0x98, a1, a2);
}
PCREG(46e8e0, itemGetMainItemRootTM);
