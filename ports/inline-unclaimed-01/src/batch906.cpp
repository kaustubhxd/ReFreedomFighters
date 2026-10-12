#include "ff.h"
// batch906.cpp - unclaimed-01 claim 5 (docs/20-unclaimed-01.md). Name from the GC name map (high confidence).

// 0x5db100, ZDamageBox::CopyData(ZEventBase*) (high): copies the dword at src+0x48, src+0x4c and src+0x50, the 16-byte
// blocks at src+0x54, +0x64 and +0x74, and the byte at +0x88. If the copied +0x48 dword is nonzero, calls vtable slot
// +0xc of this (thiscall, no arguments). Void, ret 4.
static void THISCALL damageBoxCopyData(u8 *self, u8 *src) {
  u32 link = *(u32 *)(src + 0x48);
  *(u32 *)(self + 0x48) = link;
  *(u32 *)(self + 0x4c) = *(u32 *)(src + 0x4c);
  *(u32 *)(self + 0x50) = *(u32 *)(src + 0x50);
  for (u32 i = 0; i < 16; i++)
    self[0x54 + i] = src[0x54 + i];
  for (u32 i = 0; i < 16; i++)
    self[0x64 + i] = src[0x64 + i];
  for (u32 i = 0; i < 16; i++)
    self[0x74 + i] = src[0x74 + i];
  self[0x88] = src[0x88];
  if (link != 0) {
    typedef void(THISCALL * slot_fn)(u8 *);
    slot_fn f = *(slot_fn *)(*(u32 *)self + 0xc);
    f(self);
  }
}
PCREG(5db100, damageBoxCopyData);
