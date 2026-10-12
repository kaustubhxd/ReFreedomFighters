// batch7171.cpp - area 73 batch 71 (gap band, tail-jump rows): FUN_4f6b80 and FUN_4f7a00.
// Arity from the target: 0x43ea20 is `ret 0x14`, five arguments, passed straight through. The target is called by address.
#include "ff.h"

extern "C" void THISCALL ext_43ea20(u8 *self, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5);
extern "C" void THISCALL ext_4ccfe0(u8 *self);

// 0x4f6b80 (GUESS FUN_4f6b80): vtable word 0x69aaf0. A non-null object at this+0x93 gets vtable slot +0x210(1); then this+0x93
// is cleared and the call continues in 0x43ea20 with the same five arguments.
static void THISCALL guess4f6b80(u8 *self, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5) {
  *(u32 *)self = 0x69aaf0;
  u8 *obj = *(u8 **)(self + 0x93);
  if (obj)
    vcall<void>(obj, 0x210, 1u);
  *(u32 *)(self + 0x93) = 0;
  ext_43ea20(self, a1, a2, a3, a4, a5);
}
PCREG(4f6b80, guess4f6b80);

// 0x4f7a00 (GUESS FUN_4f7a00): vtable word 0x69ae94; 0x4ccfe0 on this+0xb3 (no arguments); then the tail call to 0x43ea20.
static void THISCALL guess4f7a00(u8 *self, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5) {
  *(u32 *)self = 0x69ae94;
  ext_4ccfe0(self + 0xb3);
  ext_43ea20(self, a1, a2, a3, a4, a5);
}
PCREG(4f7a00, guess4f7a00);
