// batch4419.cpp - area 73 batch 19 (gap band, GUESS names): FUN_4f4de0, FUN_4f6e50, FUN_4e4fc0, FUN_4f03a0, FUN_4f4580.
#include "ff.h"

// 0x4f9af0: thiscall, no arguments (original code, hooked in the spec).
extern "C" void THISCALL ext_4f9af0(u8 *self);

// 0x4f4de0 (GUESS FUN_4f4de0): when [this+0x70] != 0x20 and [this+0x8f] != 1: vtable slot +0x2ec(1); plain ret.
static void THISCALL guess4f4de0(u8 *self) {
  if (*(u32 *)(self + 0x70) != 0x20u && *(u32 *)(self + 0x8f) != 1u)
    vcall<void>(self, 0x2ec, 1u);
}
PCREG(4f4de0, guess4f4de0);

// 0x4f6e50 (GUESS FUN_4f6e50): helper 0x4f9af0(this), then vtable slot +0x384 with the dword at this+0x8f; plain ret.
static void THISCALL guess4f6e50(u8 *self) {
  ext_4f9af0(self);
  vcall<void>(self, 0x384, *(u32 *)(self + 0x8f));
}
PCREG(4f6e50, guess4f6e50);

// 0x4e4fc0 (GUESS FUN_4e4fc0): copies three dwords from the argument pointer to this+0x21, +0x25, +0x29; ret 4.
static void THISCALL guess4e4fc0(u8 *self, u32 src) {
  u32 *s = (u32 *)src;
  *(u32 *)(self + 0x21) = s[0];
  *(u32 *)(self + 0x25) = s[1];
  *(u32 *)(self + 0x29) = s[2];
}
PCREG(4e4fc0, guess4e4fc0);

// 0x4f03a0 (GUESS FUN_4f03a0): copies this+0x22, +0x26, +0x2a to the three dwords at the argument pointer; ret 4.
static void THISCALL guess4f03a0(u8 *self, u32 dst) {
  u32 *d = (u32 *)dst;
  d[0] = *(u32 *)(self + 0x22);
  d[1] = *(u32 *)(self + 0x26);
  d[2] = *(u32 *)(self + 0x2a);
}
PCREG(4f03a0, guess4f03a0);

// 0x4f4580 (GUESS FUN_4f4580): ecx = [this+0x9f]; r = slot +0x27c(arg); returns the sign-extended byte at r+0x10; ret 4.
static u32 THISCALL guess4f4580(u8 *self, u32 a) {
  u8 *o = *(u8 **)(self + 0x9f);
  u32 r = vcall<u32>(o, 0x27c, a);
  return (u32)(s32)(s8)*(u8 *)(r + 0x10);
}
PCREG(4f4580, guess4f4580);
