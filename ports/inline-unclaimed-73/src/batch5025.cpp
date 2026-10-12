// batch5025.cpp - area 73 batch 50 (gap band, GUESS name): FUN_4f00d0.
#include "ff.h"

// 0x4f00d0 (GUESS FUN_4f00d0): ret 0, returns a dword. index = this+0x1c. An index of 7 or more is returned unchanged;
// otherwise the result is vtable slot +0x240 on this with (index, the byte at this+0x8e zero-extended).
static u32 THISCALL guess4f00d0(u8 *self) {
  u32 idx = *(u32 *)(self + 0x1c);
  if (idx >= 7)
    return idx;
  u32 b = self[0x8e];
  return vcall<u32>(self, 0x240, idx, b);
}
PCREG(4f00d0, guess4f00d0);
