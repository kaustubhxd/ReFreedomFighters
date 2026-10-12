// batch5440.cpp - area 73 batch 54 (gap band, GUESS names): FUN_4f4080, FUN_4f5960, FUN_4f6250, FUN_4fac70, FUN_4f4cd0.
#include "ff.h"

extern "C" void THISCALL ext_4ee240(u8 *self, u32 a, u32 b, u32 c);
extern "C" void THISCALL ext_4ee210(u8 *self, u32 a, u32 b, u32 c);
extern "C" void THISCALL ext_4fac70(u8 *self, u32 a, u32 b, u32 c);
extern "C" void THISCALL ext_4fa2f0(u8 *self, u32 a1);

// 0x4f4080 (GUESS FUN_4f4080): ret 0xc, returns this. Calls base 0x4ee240(this, a, b, c), then stores vtable word 0x6993dc.
static u8 *THISCALL guess4f4080(u8 *self, u32 a, u32 b, u32 c) {
  ext_4ee240(self, a, b, c);
  *(u32 *)self = 0x6993dc;
  return self;
}
PCREG(4f4080, guess4f4080);

// 0x4f5960 (GUESS FUN_4f5960): ret 0xc, returns this. Base 0x4ee210, vtable word 0x69a370.
static u8 *THISCALL guess4f5960(u8 *self, u32 a, u32 b, u32 c) {
  ext_4ee210(self, a, b, c);
  *(u32 *)self = 0x69a370;
  return self;
}
PCREG(4f5960, guess4f5960);

// 0x4f6250 (GUESS FUN_4f6250): ret 0xc, returns this. Base 0x4fac70, vtable word 0x69a694.
static u8 *THISCALL guess4f6250(u8 *self, u32 a, u32 b, u32 c) {
  ext_4fac70(self, a, b, c);
  *(u32 *)self = 0x69a694;
  return self;
}
PCREG(4f6250, guess4f6250);

// 0x4fac70 (GUESS FUN_4fac70): ret 0xc, returns this. Base 0x4ee240, vtable word 0x69be1c.
static u8 *THISCALL guess4fac70(u8 *self, u32 a, u32 b, u32 c) {
  ext_4ee240(self, a, b, c);
  *(u32 *)self = 0x69be1c;
  return self;
}
PCREG(4fac70, guess4fac70);

// 0x4f4cd0 (GUESS FUN_4f4cd0): ret 4 on the early paths, tail-jump to 0x4fa2f0 otherwise (arity 1, the tail target's
// stack argument passes straight through). The early-return eax is the caller's, not reproduced, so the port is void.
static void THISCALL guess4f4cd0(u8 *self, u32 a1) {
  if (*(u32 *)(self + 0x8f) == 1)
    return;
  u32 v = *(u32 *)(self + 0x70);
  if (v == 0x20 || v == 2)
    return;
  ext_4fa2f0(self, a1);
}
PCREG(4f4cd0, guess4f4cd0);
