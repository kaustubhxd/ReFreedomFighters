// batch67540.cpp - cascade s6 batch 67540: 0x5c8fc0.
#include "ff.h"

#define D32(p, o) (*(u32 *)((u8 *)(p) + (o)))

// 0x5c8fc0, thiscall(stream) ret 4, returns 1: loads the object's fields from a stream object: clears flag 0x40 of this[4], reads (slot 0x50 / 0x40, one destination address each) the dwords at
// +0x48..+0x64 (slot 0x50), +0x68..+0x78 (slot 0x40), one more through slot 0x40 into a local that is mapped through the object table (sys[0x9b] slot 0x58) into this[0x7c], then +0x80, +0x88
// (slot 0x40) and +0x8c (slot 0x50).
static u32 THISCALL fn5c8fc0(u8 *self, u8 *st) {
  u32 v;
  D32(self, 4) &= 0xffffffbfu;
  for (u32 o = 0x48; o <= 0x64; o += 4) vcall<void>(st, 0x50, (u32)(self + o));
  for (u32 o = 0x68; o <= 0x78; o += 4) vcall<void>(st, 0x40, (u32)(self + o));
  vcall<void>(st, 0x40, (u32)&v);
  D32(self, 0x7c) = vcall<u32>(*(u8 **)(*(u8 **)0x70039c + 0x9b), 0x58, v);
  vcall<void>(st, 0x40, (u32)(self + 0x80));
  vcall<void>(st, 0x40, (u32)(self + 0x88));
  vcall<void>(st, 0x50, (u32)(self + 0x8c));
  return 1;
}
PCREG(5c8fc0, fn5c8fc0);
