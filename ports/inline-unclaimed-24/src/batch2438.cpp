// batch2438.cpp - decomp area 24, batch 2438 (gap band 0x441000-0x461000).
#include "ff.h"

// 0x449300 ZLIGHT::EffectLight() const, thiscall: bit 1 of the dword at +0x18, in AL.
static u8 THISCALL lightEffectLight(u8 *self) {
  return (u8)((*(u32 *)(self + 0x18) >> 1) & 1u);
}
PCREG(449300, lightEffectLight);

// 0x454550 ZGATE::PFEnableGate(bool), thiscall, ret 4.
static void THISCALL gatePFEnableGate(u8 *self, u8 on) {
  self[0x60] = on;
}
PCREG(454550, gatePFEnableGate);

// 0x4451b0 ZROOM::SetRoomControl(unsigned int, unsigned int), thiscall, ret 8.
static void THISCALL roomSetRoomControl(u8 *self, u32 first, u32 second) {
  *(u32 *)(self + 0xac) = (*(u32 *)(self + 0xac) & ~second) | first;
}
PCREG(4451b0, roomSetRoomControl);

// 0x448f60 ZLIGHT::DisableParentBoundAdjust(), thiscall, AL.
static u8 THISCALL lightDisableParentBoundAdjust(u8 *self) {
  if (self[0x14] & 1)
    return 0;
  u8 b = self[0x18];
  return (u8)((u8)~(u8)(b >> 2) & 1u);
}
PCREG(448f60, lightDisableParentBoundAdjust);

// 0x4609b0 (GUESS constructor), thiscall, eax = this.
static u8 *THISCALL guessCtor4609b0(u8 *self) {
  *(u32 *)(self) = 0x685288u;
  *(float *)(self + 4) = -1.0f;
  *(u32 *)(self + 8) = 0x7e967699u;
  *(u32 *)(self + 0xc) = 0;
  *(u32 *)(self + 0x10) = 0;
  return self;
}
PCREG(4609b0, guessCtor4609b0);
