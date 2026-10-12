// batch2415.cpp - decomp area 24, batch 2415: small setters and one indexed getter.
#include "ff.h"

// 0x4850b0 ZPlayer::SetSoundSet(unsigned int), thiscall, ret 4.
static void THISCALL playerSetSoundSet(u8 *self, u32 v) {
  *(u32 *)(self + 0x60e) = v;
}
PCREG(4850b0, playerSetSoundSet);

// 0x59cbb0 (GUESS owner), thiscall, ret 4.
static void THISCALL setField12104(u8 *self, u32 v) {
  *(u32 *)(self + 0x12104) = v;
}
PCREG(59cbb0, setField12104);

// 0x54ba30 (unnamed), thiscall, ret 4. The low byte of the argument.
static void THISCALL setByteA27c(u8 *self, u8 v) {
  self[0xa27c] = v;
}
PCREG(54ba30, setByteA27c);

// 0x443070 ZTreeGroup::GetGlobalTreePtr(eGlobalTreeType) const, thiscall, ret 4.
static u32 THISCALL treeGroupGlobalTreePtr(u8 *self, u32 type) {
  return *(u32 *)(self + 0x5d + 4 * type);
}
PCREG(443070, treeGroupGlobalTreePtr);
