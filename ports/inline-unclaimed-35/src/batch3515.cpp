#include "ff.h"
// batch3515.cpp - area 35 claim 15 (docs/20-unclaimed-35.md): five leaves in slice 14. Names: GC name map (naming only).
// Stubbed in the harness: 0x561020 (thiscall, no args); the objects' vtable slots +0xc and +4 (logged).

typedef u32(THISCALL *Slot2)(u8 *self, u32 a0, u32 a1);
typedef u32(THISCALL *Slot0)(u8 *self);

extern "C" void THISCALL ext_561020(u8 *self);

// 0x443c60, ZTreeGroup::RemoveGlobalBound(...) (high): the object at this + 4*a + 0x5d, slot +0xc with (c, 0) (the exe pushes 0, then c); ret 0xc.
static void THISCALL treeGroupRemoveGlobalBound(u8 *self, u32 a, u32 b, u32 c) {
  (void)b;
  u8 *o = *(u8 **)(self + a * 4 + 0x5d);
  ((Slot2)*(u32 *)(*(u32 *)o + 0xc))(o, c, 0);
}
PCREG(443c60, treeGroupRemoveGlobalBound);

// 0x43e620, ZHELPER::DispText(int) (high): bit 0x10 of this + 0x18 follows the argument (non-zero sets it).
static void THISCALL helperDispText(u8 *self, u32 a1) {
  if (a1)
    *(u32 *)(self + 0x18) |= 0x10u;
  else
    *(u32 *)(self + 0x18) &= ~0x10u;
}
PCREG(43e620, helperDispText);

// 0x4c2ba0, ZMusicControl::SetHistory(unsigned int) (medium): this + 0x1cb = old this + 0x1cf; this + 0x1cf = argument.
static void THISCALL musicSetHistory(u8 *self, u32 a1) {
  *(u32 *)(self + 0x1cb) = *(u32 *)(self + 0x1cf);
  *(u32 *)(self + 0x1cf) = a1;
}
PCREG(4c2ba0, musicSetHistory);

// 0x561160, CDifficultySetting::CDifficultySetting() (high): calls 0x561020, sets the vtable 0x6a63bc, returns this.
static u8 *THISCALL difficultySettingCtor(u8 *self) {
  ext_561020(self);
  *(u32 *)self = 0x6a63bc;
  return self;
}
PCREG(561160, difficultySettingCtor);

// 0x5379a0, ZDllSound::InitializeSoundGraph() (medium): tail-jumps to slot +4 of the object at this + 0x52fe, if non-null.
static void THISCALL dllSoundInitializeSoundGraph(u8 *self) {
  u8 *o = *(u8 **)(self + 0x52fe);
  if (o)
    ((Slot0)*(u32 *)(*(u32 *)o + 4))(o);
}
PCREG(5379a0, dllSoundInitializeSoundGraph);
