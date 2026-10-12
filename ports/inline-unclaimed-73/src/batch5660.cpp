// batch5660.cpp - area 73 batch 56 (gap band, GUESS names): FUN_4f5920, FUN_4f3c00, FUN_4e8bd0, FUN_4f4d30.
#include "ff.h"

extern "C" void THISCALL ext_4ee210(u8 *self, u32 a, u32 b, u32 c);
extern "C" u8 THISCALL ext_560360(u8 *self, u32 a);

// 0x4f5920 (GUESS FUN_4f5920): ret 8. When this+0xbb == a and this+0xbf == b it returns; otherwise it stores b at +0xbf and
// a at +0xbb, then calls vtable slot +0x27c.
static void THISCALL guess4f5920(u8 *self, u32 a, u32 b) {
  if (*(u32 *)(self + 0xbb) == a && *(u32 *)(self + 0xbf) == b)
    return;
  *(u32 *)(self + 0xbf) = b;
  *(u32 *)(self + 0xbb) = a;
  vcall<void>(self, 0x27c);
}
PCREG(4f5920, guess4f5920);

// 0x4f3c00 (GUESS FUN_4f3c00): ret 0xc, returns this. Base 0x4ee210(this, a, b, c), then vtable word 0x69909c, then +0x60 = 0.
static u8 *THISCALL guess4f3c00(u8 *self, u32 a, u32 b, u32 c) {
  ext_4ee210(self, a, b, c);
  *(u32 *)self = 0x69909c;
  *(u32 *)(self + 0x60) = 0;
  return self;
}
PCREG(4f3c00, guess4f3c00);

// 0x4e8bd0 (GUESS FUN_4e8bd0): plain ret, returns this. Clears the fields listed below.
static u8 *THISCALL guess4e8bd0(u8 *self) {
  *(u32 *)(self + 0x14) = 0;
  *(u16 *)(self + 0xa4) = 0;
  *(u32 *)(self + 0x60) = 0;
  *(u32 *)(self + 0x64) = 0;
  *(u32 *)(self + 0xc) = 0;
  *(u32 *)(self + 0x10) = 0;
  return self;
}
PCREG(4e8bd0, guess4e8bd0);

// 0x4f4d30 (GUESS FUN_4f4d30): ret 4, returns a bool. A 1 argument with this+0x70 == 2 gives vtable +0x2ec(1) and 1; any
// other case tail-jumps to 0x560360 with the same argument (arity 1, the target's ret 4).
static u8 THISCALL guess4f4d30(u8 *self, u32 a1) {
  if (a1 == 1 && *(u32 *)(self + 0x70) == 2) {
    vcall<void>(self, 0x2ec, 1u);
    return 1;
  }
  return ext_560360(self, a1);
}
PCREG(4f4d30, guess4f4d30);
