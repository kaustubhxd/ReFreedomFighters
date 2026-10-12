// batch5550.cpp - area 73 batch 55 (gap band, GUESS names): FUN_4fe0c0, FUN_4f3260, FUN_4f04a0.
#include "ff.h"

// 0x4fe0c0 (GUESS FUN_4fe0c0): ret 4. Copies four words from the argument object to this (offsets 0x49, 0x4b, 0x4d, 0x4f).
static void THISCALL guess4fe0c0(u8 *self, u8 *src) {
  *(u16 *)(self + 0x49) = *(u16 *)(src + 0x49);
  *(u16 *)(self + 0x4b) = *(u16 *)(src + 0x4b);
  *(u16 *)(self + 0x4d) = *(u16 *)(src + 0x4d);
  *(u16 *)(self + 0x4f) = *(u16 *)(src + 0x4f);
}
PCREG(4fe0c0, guess4fe0c0);

// 0x4f3260 (GUESS FUN_4f3260): ret 4, returns the old byte. Stores the argument's low byte at this+0x5fc, calls vtable
// slot +0x334 with the byte at this+0x5fb (zero-extended), and returns the byte the store replaced.
static u8 THISCALL guess4f3260(u8 *self, u32 arg) {
  u8 old = self[0x5fc];
  self[0x5fc] = (u8)arg;
  vcall<void>(self, 0x334, (u32)self[0x5fb]);
  return old;
}
PCREG(4f3260, guess4f3260);

// 0x4f04a0 (GUESS FUN_4f04a0): plain ret. s = the string pointer at this+0x9b. A leading '%' gives vtable +0x284 with s+1;
// otherwise vtable +0x288 with (0x677b5a, s) (the literal is the exe's string constant, passed as the first argument).
static void THISCALL guess4f04a0(u8 *self) {
  u8 *s = *(u8 **)(self + 0x9b);
  if (*s == '%') {
    vcall<void>(self, 0x284, (u32)(s + 1));
    return;
  }
  vcall<void>(self, 0x288, 0x677b5au, (u32)s);
}
PCREG(4f04a0, guess4f04a0);
