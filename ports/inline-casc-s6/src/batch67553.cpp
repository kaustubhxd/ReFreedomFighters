// batch67553.cpp - cascade s6 batch 67553: 0x4acb30.
#include "ff.h"

#define D32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define D16(p, o) ((u32) * (u16 *)((u8 *)(p) + (o)))

// 0x4acb30, thiscall(stream) ret 4, returns 1: saves the object's fields to a stream object: clears flag 0x40 of this[4], writes the words +0x48, 4a, 4c, 4e, 50, 52, 56, 54, 58, 5a, 5c, 5e, 60,
// 62, 66 through slot 0x40, the dword +0x6a through slot 0x3c, the address this+0x11a through slot 0x6c and finally the word +0x64 through slot 0x40.
static u32 THISCALL fn4acb30(u8 *self, u8 *st) {
  D32(self, 4) &= 0xffffffbfu;
  static const u32 offs[] = {0x48, 0x4a, 0x4c, 0x4e, 0x50, 0x52, 0x56, 0x54, 0x58, 0x5a, 0x5c, 0x5e, 0x60, 0x62, 0x66};
  for (u32 o : offs) vcall<void>(st, 0x40, D16(self, o));
  vcall<void>(st, 0x3c, D32(self, 0x6a));
  vcall<void>(st, 0x6c, (u32)(self + 0x11a));
  vcall<void>(st, 0x40, D16(self, 0x64));
  return 1;
}
PCREG(4acb30, fn4acb30);
