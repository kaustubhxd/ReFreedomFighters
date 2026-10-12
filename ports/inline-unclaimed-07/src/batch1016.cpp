// batch1016.cpp - unclaimed-07 batch 16 (docs/20-unclaimed-07.md, slice 6): ZPlayer::Save.
// Name from the GC name map (high). Body from the PC bytes.
#include "ff.h"

// 0x4753c0: the save-ready check (thiscall, one argument, returns al; original code, hooked in the spec).
extern "C" u32 THISCALL ext_4753c0(u8 *self, u8 *s);

// 0x484d20, ZPlayer::Save(ZSaveGame*) (high), thiscall, ret 4. Returns false when ext_4753c0(this, s) is false. Otherwise
// writes the saved fields through s (vtable slots): +0x3c(this+0x413), +0x44(this+0x417), +0x60(byte +0x42c),
// +0x68(this+0x445), +0x4c(float +0x596), +0x70(this+0x59a), +0x68(this+0x5be), +0x70(this+0x4f5), +0x68(this+0x519),
// +0x3c(this+0x5ca), +0x70(this+0x5ce), +0x68(this+0x5f2), +0x60(byte +0x5fe), +0x60(byte +0x5ff), +0x60(byte +0x601),
// +0x60(byte +0x600), +0x44(this+0x602), +0x44(this+0x606), +0x44(this+0x60a), +0x3c(this+0x60e), +0x4c(float +0x4dd);
// then for i = 1..count (count = this+0x459) the object at this+0x461 + 4*(i-1), when non-null, gets its slot +0x34(s).
// Returns true.
static bool THISCALL zPlayerSave(u8 *self, u8 *s) {
  if (!(u8)ext_4753c0(self, s))
    return false;
  vcall<void>(s, 0x3c, *(u32 *)(self + 0x413));
  vcall<void>(s, 0x44, *(u32 *)(self + 0x417));
  vcall<void>(s, 0x60, (u32)*(u8 *)(self + 0x42c));
  vcall<void>(s, 0x68, (u32)(self + 0x445));
  vcall<void>(s, 0x4c, *(float *)(self + 0x596));
  vcall<void>(s, 0x70, (u32)(self + 0x59a));
  vcall<void>(s, 0x68, (u32)(self + 0x5be));
  vcall<void>(s, 0x70, (u32)(self + 0x4f5));
  vcall<void>(s, 0x68, (u32)(self + 0x519));
  vcall<void>(s, 0x3c, *(u32 *)(self + 0x5ca));
  vcall<void>(s, 0x70, (u32)(self + 0x5ce));
  vcall<void>(s, 0x68, (u32)(self + 0x5f2));
  vcall<void>(s, 0x60, (u32)*(u8 *)(self + 0x5fe));
  vcall<void>(s, 0x60, (u32)*(u8 *)(self + 0x5ff));
  vcall<void>(s, 0x60, (u32)*(u8 *)(self + 0x601));
  vcall<void>(s, 0x60, (u32)*(u8 *)(self + 0x600));
  vcall<void>(s, 0x44, *(u32 *)(self + 0x602));
  vcall<void>(s, 0x44, *(u32 *)(self + 0x606));
  vcall<void>(s, 0x44, *(u32 *)(self + 0x60a));
  vcall<void>(s, 0x3c, *(u32 *)(self + 0x60e));
  vcall<void>(s, 0x4c, *(float *)(self + 0x4dd));
  u32 count = *(u32 *)(self + 0x459);
  for (u32 i = 1; i <= count; i++) {
    u8 *child = *(u8 **)(self + 0x461 + 4 * (i - 1));
    if (child)
      vcall<void>(child, 0x34, (u32)s);
  }
  return true;
}
PCREG(484d20, zPlayerSave);
