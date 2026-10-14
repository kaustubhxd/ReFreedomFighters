// batch751.cpp - unclaimed area 75 (docs/20-unclaimed-75.md), slice floor(addr/16) mod 20 == 13.
#include "ff.h"

extern "C" void THISCALL ext_45fa00(u8 *self, u32 a);   // original, thiscall, callee pops 4 (as in batch203)
extern "C" void THISCALL ext_5edd80(u8 *self, u32 a);   // original base ctor, thiscall, callee pops 4

// 0x524890, thiscall(x float) ret 4: x0 = (x == 0) ? [0x68ced0] : x (ordered equal only); [this+0xc] = 0x46c35000;
// [this+0x10] = 0x44fa0000; [this+0x14] = (x0 == 0 ordered) ? 0x3dcccccd : x0. Name GUESS (float-config setter).
static void THISCALL setFloatConfig_524890(u8 *self, float x) {
  float x0 = (x == 0.0f) ? *(float *)0x68ced0u : x;
  *(u32 *)(self + 0xc) = 0x46c35000u;
  *(u32 *)(self + 0x10) = 0x44fa0000u;
  if (x0 == 0.0f) *(u32 *)(self + 0x14) = 0x3dcccccdu;
  else *(float *)(self + 0x14) = x0;   // the asm's jp target stores xmm0 (x0) here
}
PCREG(524890, setFloatConfig_524890);

// 0x43e110, thiscall(a) ret 4: call the original 0x45fa00(this, a); then twice: if (byte [this+0x14] & 0xe) == 0, clear
// bit 0 of the dword at +0x14. Name GUESS (same shape as 0x43e170, which is batch203).
static void THISCALL callThenClearTwice_43e110(u8 *self, u32 a) {
  ext_45fa00(self, a);
  u32 v = *(u32 *)(self + 0x14);
  if ((v & 0xe) == 0) *(u32 *)(self + 0x14) = v & 0xfffffffeu;
  v = *(u32 *)(self + 0x14);
  if ((v & 0xe) == 0) *(u32 *)(self + 0x14) = v & 0xfffffffeu;
}
PCREG(43e110, callThenClearTwice_43e110);

// 0x5efd10, thiscall(): call the base ctor 0x5edd80(this, 3); [this] = vtable 0x6b81f8; [this+0x84] = 0; [this+0x88] = 1.0f;
// [this+0x8c] = 3.0f; [this+0x90] = 5.0f; [this+0x94] = 0; byte [this+0x98] = 1; returns this. Name GUESS (ctor).
static u8 *THISCALL ctorDefaults_5efd10(u8 *self) {
  ext_5edd80(self, 3u);
  *(u32 *)self = 0x6b81f8u;
  *(u32 *)(self + 0x84) = 0;
  *(u32 *)(self + 0x94) = 0;
  *(u32 *)(self + 0x88) = 0x3f800000u;
  *(u32 *)(self + 0x8c) = 0x40400000u;
  *(u32 *)(self + 0x90) = 0x40a00000u;
  self[0x98] = 1;
  return self;
}
PCREG(5efd10, ctorDefaults_5efd10);
