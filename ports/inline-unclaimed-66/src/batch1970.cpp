// batch1970.cpp - slice-5 batches 95 to 97 (GUESS names). Callees are GUESS stubs by address or vtable slots.
//   0x54dc10: THISCALL(this), no arguments; returns al. al = vtable +0xc of this; if al == 0: return 0; else vtable +0 and vtable +0x5c
//             of this (no arguments); [this+0x801c] = 1; return 1.
//   0x4c3150: THISCALL(this), no arguments, plain ret. a = [this+0x44]; if a: [this+0x48] = [[a+0x18]+0x80]; if byte [a+0x20]: 0x44c370(ECX = a)
//             (GUESS stub); if [this+0x48]: [[[this+0x44]+0x18]+0x7c] = [this+0x48].
//   0x575d50: THISCALL(this), no arguments; returns this. 0x573590(ECX = this) (GUESS stub); [this] = 0x6a9348; byte [this+0x20b] = 1;
//             [this+0x20d] = 0x1000100; [this+0x21d] = 0.
#include "ff.h"

extern "C" void THISCALL ext_44c370(u8 *self);  // THISCALL, no arguments (stub by address)
extern "C" void THISCALL ext_573590(u8 *self);  // THISCALL, no arguments (stub by address)

// 0x54dc10, GUESS FUN_0054dc10 (batch 95).
static u8 THISCALL gapFn54dc10(u8 *self) {
  u8 r = (u8)vcall<u32>(self, 0xc);
  if (!r) return 0;
  vcall<void>(self, 0x0);
  vcall<void>(self, 0x5c);
  *(u8 *)(self + 0x801c) = 1;
  return 1;
}
PCREG(54dc10, gapFn54dc10);

// 0x4c3150, GUESS FUN_004c3150 (batch 96).
static void THISCALL gapFn4c3150(u8 *self) {
  u8 *a = *(u8 **)(self + 0x44);
  if (a) {
    *(u32 *)(self + 0x48) = *(u32 *)(*(u8 **)(a + 0x18) + 0x80);
    if (*(u8 *)(a + 0x20)) ext_44c370(a);
    u32 v = *(u32 *)(self + 0x48);
    if (v) *(u32 *)(*(u8 **)(*(u8 **)(self + 0x44) + 0x18) + 0x7c) = v;
  }
}
PCREG(4c3150, gapFn4c3150);

// 0x575d50, GUESS FUN_00575d50 (batch 97).
static u8 *THISCALL gapCtor575d50(u8 *self) {
  ext_573590(self);
  *(u32 *)self = 0x6a9348;
  *(u8 *)(self + 0x20b) = 1;
  *(u32 *)(self + 0x20d) = 0x1000100;
  *(u32 *)(self + 0x21d) = 0;
  return self;
}
PCREG(575d50, gapCtor575d50);
