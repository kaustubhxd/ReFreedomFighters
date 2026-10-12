// batch3914.cpp - area 73 batch 14 (gap band, GUESS names): FUN_4f1510, FUN_4f4e10, FUN_4e1b20, FUN_4f9510, FUN_4f10f0.
#include "ff.h"

// 0x4e1590: thiscall, no arguments, returns eax (original code, hooked in the spec).
extern "C" u32 THISCALL ext_4e1590(u8 *self);

// 0x4f1510 (GUESS FUN_4f1510): stores the low byte of the argument at this+0x21; ret 4.
static void THISCALL guess4f1510(u8 *self, u32 a) {
  self[0x21] = (u8)a;
}
PCREG(4f1510, guess4f1510);

// 0x4f4e10 (GUESS FUN_4f4e10): stores the argument at this+0x60; ret 4.
static void THISCALL guess4f4e10(u8 *self, u32 a) {
  *(u32 *)(self + 0x60) = a;
}
PCREG(4f4e10, guess4f4e10);

// 0x4e1b20 (GUESS FUN_4e1b20): calls 0x4e1590(this), then this+8 += eax + 1; plain ret.
static void THISCALL guess4e1b20(u8 *self) {
  u32 r = ext_4e1590(self);
  *(u32 *)(self + 8) += r + 1;
}
PCREG(4e1b20, guess4e1b20);

// 0x4f9510 (GUESS FUN_4f9510): cdecl, returns [a1] - [a2] (the caller pops the arguments; plain ret).
static u32 __attribute__((cdecl)) guess4f9510(u32 *a1, u32 *a2) {
  return *a1 - *a2;
}
PCREG(4f9510, guess4f9510);

// 0x4f10f0 (GUESS FUN_4f10f0): stores the argument at this+0x9f; ret 4.
static void THISCALL guess4f10f0(u8 *self, u32 a) {
  *(u32 *)(self + 0x9f) = a;
}
PCREG(4f10f0, guess4f10f0);
