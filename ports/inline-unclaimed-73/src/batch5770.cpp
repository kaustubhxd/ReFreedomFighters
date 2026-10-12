// batch5770.cpp - area 73 batch 57 (gap band, GUESS names): FUN_4e7d90, FUN_4e6830, FUN_4f4ec0, FUN_4f0420.
#include "ff.h"

extern "C" void __attribute__((cdecl)) ext_634273(void *p, u32 size);
extern "C" void THISCALL ext_4ee240(u8 *self, u32 a, u32 b, u32 c);

// 0x4e7d90 (GUESS FUN_4e7d90): plain ret, returns this. Vtable word 0x6975e4; the dword at this+0xc is 0 and the list head
// (this+4 and this+8) points at it; +0x1c byte, +0x18, +0x10 and +0x14 are cleared.
static u8 *THISCALL guess4e7d90(u8 *self) {
  u32 *head = (u32 *)(self + 0xc);
  *(u32 *)self = 0x6975e4;
  *head = 0;
  *(u32 *)(self + 8) = (u32)head;
  *(u32 *)(self + 4) = (u32)head;
  self[0x1c] = 0;
  *(u32 *)(self + 0x18) = 0;
  *(u32 *)(self + 0x10) = 0;
  *(u32 *)(self + 0x14) = 0;
  return self;
}
PCREG(4e7d90, guess4e7d90);

// 0x4e6830 (GUESS FUN_4e6830): ret 4, returns this. Vtable word 0x697510; frees this+4 (size 4) through the delete helper;
// when the argument's low bit is set, frees this (size 0x18).
static u8 *THISCALL guess4e6830(u8 *self, u32 flags) {
  *(u32 *)self = 0x697510;
  ext_634273(*(void **)(self + 4), 4u);
  if (flags & 1)
    ext_634273(self, 0x18u);
  return self;
}
PCREG(4e6830, guess4e6830);

// 0x4f4ec0 (GUESS FUN_4f4ec0): ret 0xc, returns this. Base 0x4ee240(this, a, b, c), vtable word 0x699f78, dword +0xb7 = 8.
static u8 *THISCALL guess4f4ec0(u8 *self, u32 a, u32 b, u32 c) {
  ext_4ee240(self, a, b, c);
  *(u32 *)self = 0x699f78;
  *(u32 *)(self + 0xb7) = 8;
  return self;
}
PCREG(4f4ec0, guess4f4ec0);

// 0x4f0420 (GUESS FUN_4f0420): ret 4, returns a word. When the array pointer at this+0x36 is non-null, the object at
// g_sys+0x1aa3 gives its +0x18 object, whose vtable slot +0xc is called with array[arg]; the word at +4 of the result is
// returned (zero-extended). Otherwise it returns 0.
static u32 THISCALL guess4f0420(u8 *self, u32 arg) {
  u32 *arr = *(u32 **)(self + 0x36);
  if (!arr)
    return 0;
  u8 *a = *(u8 **)(G(u8 *, 0x70039c) + 0x1aa3);
  u8 *b = *(u8 **)(a + 0x18);
  u8 *r = (u8 *)vcall<u32>(b, 0x0c, arr[arg]);
  return *(u16 *)(r + 4);
}
PCREG(4f0420, guess4f0420);
