// batch4217.cpp - area 73 batch 17 (gap band, GUESS names): FUN_4f9f10, FUN_4fa330, FUN_4f6370, FUN_4f6e70.
#include "ff.h"

// Helpers (thiscall, no arguments; original code, hooked in the spec).
extern "C" void THISCALL ext_4ef130(u8 *self);
extern "C" void THISCALL ext_4f9bc0(u8 *self);

// 0x4f9f10 (GUESS FUN_4f9f10): when [this+0x70] == 0x20: [this+0x6c] &= ~2 and vtable slot +0x2ec(1); plain ret.
static void THISCALL guess4f9f10(u8 *self) {
  if (*(u32 *)(self + 0x70) == 0x20u) {
    *(u32 *)(self + 0x6c) &= ~2u;
    vcall<void>(self, 0x2ec, 1u);
  }
}
PCREG(4f9f10, guess4f9f10);

// 0x4fa330 (GUESS FUN_4fa330): ret 4 (one unused argument). When [this+0x6c] bit 1 is clear, vtable slot +0x2ec(1); returns false (al).
static bool THISCALL guess4fa330(u8 *self, u32 unused) {
  (void)unused;
  if (!(*(u8 *)(self + 0x6c) & 2))
    vcall<void>(self, 0x2ec, 1u);
  return false;
}
PCREG(4fa330, guess4fa330);

// 0x4f6370 (GUESS FUN_4f6370): helper 0x4ef130(this), then vtable slot +0xbc(1); plain ret.
static void THISCALL guess4f6370(u8 *self) {
  ext_4ef130(self);
  vcall<void>(self, 0xbc, 1u);
}
PCREG(4f6370, guess4f6370);

// 0x4f6e70 (GUESS FUN_4f6e70): helper 0x4f9bc0(this), then vtable slot +0xbc(1); plain ret.
static void THISCALL guess4f6e70(u8 *self) {
  ext_4f9bc0(self);
  vcall<void>(self, 0xbc, 1u);
}
PCREG(4f6e70, guess4f6e70);
