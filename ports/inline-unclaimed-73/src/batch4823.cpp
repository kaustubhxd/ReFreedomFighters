// batch4823.cpp - area 73 batch 48 (gap band, GUESS names): FUN_4e8140 and FUN_4e6bf0.
#include "ff.h"

// 0x4e8140 (GUESS FUN_4e8140): ret 4, returns a dword. p = vtable slot +8 on this with (arg, 0); returns the dword at
// p+0x11 when p is non-null, otherwise 0.
static u32 THISCALL guess4e8140(u8 *self, u32 arg) {
  u8 *p = (u8 *)vcall<u32>(self, 0x08, arg, 0u);
  if (!p)
    return 0;
  return *(u32 *)(p + 0x11);
}
PCREG(4e8140, guess4e8140);

// 0x4e6bf0 (GUESS FUN_4e6bf0): ret 4. Decrements this+0x10, then stores the unsigned quotient (arg - this[0]) / this[0xc]
// as a word into the array at this+4, at the new index. The quotient is truncated to 16 bits.
static void THISCALL guess4e6bf0(u8 *self, u32 arg) {
  *(u32 *)(self + 0x10) -= 1;
  u32 q = (arg - *(u32 *)self) / *(u32 *)(self + 0xc);
  u32 idx = *(u32 *)(self + 0x10);
  u16 *arr = *(u16 **)(self + 4);
  arr[idx] = (u16)q;
}
PCREG(4e6bf0, guess4e6bf0);
